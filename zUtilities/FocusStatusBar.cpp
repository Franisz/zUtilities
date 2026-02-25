// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	bool FocusStatusBar::IsDistanceWeaponDamageTypeOverwritten = false;

	FocusStatusBar::FocusStatusBar() : StatusBar(ogame->focusBar)
	{
		activeDamageIndexes.reserve(oEDamageIndex_MAX);
		activeStatuses.reserve(oEDamageIndex_MAX);
	}

	bool FocusStatusBar::Init() {
		return true;
	}

	void FocusStatusBar::Clear() {
		__super::Clear();

		if (!bar) {
			return;
		}

		del(protView);
	}

	int FocusStatusBar::GetHorizontalProtMargin() {
		return protView->FontY() * 0.1f + 30;
	}

	int FocusStatusBar::GetVerticalProtMargin() {
		return GetProtSize() + 85;
	}

	int FocusStatusBar::GetProtSize() {
		return protView->FontY() * 0.75f;
	}

	int FocusStatusBar::GetProtStartX(FocusStatusProtectionPlacement placement) {
		if (placement == FocusStatusProtectionPlacement::TOP) {
			return bar->vposx;
		}

		if (placement == FocusStatusProtectionPlacement::RIGHT) {
			return bar->vposx + bar->vsizex + protectionPlacementRightMargin;
		}

		return bar->vposx + bar->vsizex;
	}

	FocusStatusProtectionPlacement FocusStatusBar::GetProtPlacement(const std::vector<NpcProtectionStatus>& statuses)
	{
		auto count = statuses.size();
		if (count == 1) {
			return FocusStatusProtectionPlacement::CLOSE;
		}

		if (Options::TargetProtectionIconPosition == 0) {
			return FocusStatusProtectionPlacement::TOP;
		}

		if (count <= 0) {
			return FocusStatusProtectionPlacement::NONE;
		}

		return FocusStatusProtectionPlacement::RIGHT;
	}

	int FocusStatusBar::GetProtStartY(FocusStatusProtectionPlacement placement) {
		if (placement == FocusStatusProtectionPlacement::TOP) {
			return bar->vposy - GetHorizontalProtMargin() - GetProtSize() - bar->vsizey;
		}

		return bar->vposy + bar->vsizey / 2 - GetProtSize();
	}

	void FocusStatusBar::PrintValueOutside(zSTRING& str)
	{
		int offsetY = bar->vsizey / 2 + valueView->FontY();
		int x = bar->vposx + bar->vsizex / 2 - valueView->FontSize(str) / 2;

		int y = bar->vposy - offsetY + valueOffsetY;

		valueView->SetFontColor(zCOLOR(valueView->color.r, valueView->color.g, valueView->color.b, bar->alpha));
		valueView->Print(x, y, str);
	}

	void FocusStatusBar::MoveFocusBar(int x, int y, oCNpc* npc) {
		if (!Options::ShowEnemyBarAboveHim)
			return;

		if (!IsBarActive())
			return;

		zCCamera* cam = ogame->GetCamera();
		zVEC3 viewPos = cam->GetTransform(zTCamTrafoType::zCAM_TRAFO_VIEW) * npc->GetPositionWorld();
		int posx, posy;
		cam->Project(&viewPos, posx, posy);
		if (viewPos[VZ] <= cam->nearClipZ)
			return;

		x = x + screen->FontSize(npc->name[0]) / 2 - bar->vsizex / 2;
		if (x + bar->vsizex > 8192)
			x = 8192 - bar->vsizex;

		x = max(0, x);
		y = max(0, y - screen->FontY() * 1.75);

		bar->SetPos(x, y);
	}

	bool FocusStatusBar::NeedAdjustPosition(int x, int y, oCNpc* npc) {
		if (!bar || !npc || npc->attribute[NPC_ATR_HITPOINTS] <= 0)
			return false;

		valueOffsetY = 0;
		MoveFocusBar(x, y, npc);

		if (BuildProtectionModel(npc))
		{
			ProtectionLayout layout;
			BuildProtectionLayout(layout);

			if (layout.placement == FocusStatusProtectionPlacement::TOP)
			{
				valueOffsetY = layout.startY - bar->vposy;
			}

			RenderProtectionWithLayout(layout);
		}

		PrintValue();
		return Options::ShowEnemyBarAboveHim;
	}

	void FocusStatusBar::Loop() {
		if (protView) {
			protView->ClrPrintwin();
		}
		else {
			protView = new zCView(0, 0, 8192, 8192);
			screen->InsertItem(protView);
		}

		if (valueView) {
			valueView->ClrPrintwin();
		}
	}

	zSTRING FocusStatusBar::GetIconNameByDamageIndex(const oEIndexDamage& index) {
		switch (index)
		{
		case oEIndexDamage::oEDamageIndex_Edge:
			return zSTRING("DMGICON_EDGE"); // https://game-icons.net/1x1/lorc/ragged-wound.html
		case oEIndexDamage::oEDamageIndex_Blunt:
			return zSTRING("DMGICON_BLUNT"); // https://game-icons.net/1x1/lorc/cross-mark.html
		case oEIndexDamage::oEDamageIndex_Point:
			return zSTRING("DMGICON_POINT"); // https://game-icons.net/1x1/skoll/bullseye.html
		case oEIndexDamage::oEDamageIndex_Fire:
			return zSTRING("DMGICON_FIRE"); // https://game-icons.net/1x1/lorc/burning-embers.html
		case oEIndexDamage::oEDamageIndex_Magic:
			return zSTRING("DMGICON_MAGIC"); // https://game-icons.net/1x1/delapouite/polar-star.html
		case oEIndexDamage::oEDamageIndex_Fly:
			return zSTRING("DMGICON_FLY"); // https://game-icons.net/1x1/lorc/fluffy-trefoil.html
		case oEIndexDamage::oEDamageIndex_Fall:
			return zSTRING("DMGICON_FALL"); // https://game-icons.net/1x1/sbed/falling.html
		default:
			return zSTRING("DMGICON_UNKNOWN"); // https://game-icons.net/1x1/lorc/scar-wound.html
		}
	}

	void FocusStatusBar::RenderProtectionIconsClose(const ProtectionLayout& layout)
	{
		unsigned char alpha = ogame->hpBar ? ogame->hpBar->alpha : 255;
		auto data = BuildIconRenderData(activeStatuses[0], alpha);

		IconInfo(layout.startX + layout.margin, layout.startY, layout.size, data.color, data.texture, data.text);
	}

	void FocusStatusBar::RenderProtectionIconsTop(const ProtectionLayout& layout)
	{
		int currentX = layout.startX + bar->vsizex / 2 - layout.totalContentSize / 2;
		unsigned char alpha = ogame->hpBar ? ogame->hpBar->alpha : 255;

		for (const auto& status : activeStatuses)
		{
			auto data = BuildIconRenderData(status, alpha);

			auto icon = IconInfo(currentX, layout.startY, layout.size, data.color, data.texture, data.text);
			currentX += icon.GetSize() + layout.margin;
		}
	}

	void FocusStatusBar::RenderProtectionIconsRight(const ProtectionLayout& layout)
	{
		int currentY = layout.startY;
		unsigned char alpha = ogame->hpBar ? ogame->hpBar->alpha : 255;

		for (const auto& status : activeStatuses)
		{
			auto data = BuildIconRenderData(status, alpha);

			IconInfo(layout.startX, currentY, layout.size, data.color, data.texture, data.text);
			currentY += layout.size + layout.margin;
		}
	}

	bool FocusStatusBar::CanRenderProtectionStatus(oCNpc* npc, oEIndexDamage damageIndex) const
	{
		if (protectionModel.protectionMode != TargetProtectionMode::All)
			return true;

		if (Options::HideTargetProtectionZeroValues && npc->GetProtectionByIndex(damageIndex) == 0) {
			return false;
		}

		switch (damageIndex) {
		case oEDamageIndex_Fall:
			return !Options::HideTargetProtectionFallDamage;
		case oEDamageIndex_Fly:
			return !Options::HideTargetProtectionFlyDamage;
		case oEDamageIndex_Fire:
			return !Options::HideTargetProtectionFireDamage;
		default:
			return true;
		}
	}

	void FocusStatusBar::FillDamageIndexesBuffer()
	{
		activeDamageIndexes.clear();

		if (protectionModel.protectionMode == TargetProtectionMode::All) {
			activeDamageIndexes.assign(DamageMaskHelper::PROTECTION_DAMAGE_INDEXES.begin(),
				DamageMaskHelper::PROTECTION_DAMAGE_INDEXES.end());
			return;
		}

		DamageMask mask;
		mask.reset();

		if (protectionModel.isInFightMode) {
			BuildFightModeDamage(mask);
		}
		else {
			BuildNoFightModeDamage(mask);
		}

		DamageMaskHelper::BuildOrderedDamageIndexes(mask, activeDamageIndexes);
	}

	void FocusStatusBar::BuildFightModeDamage(DamageMask& mask)
	{
		// Check for active spell
		if (player->IsInFightMode_S(NPC_WEAPON_MAG)) {
			if (auto spell = player->mag_book->GetSelectedSpell()) {
				DamageMaskHelper::MarkIntDamageType(spell->damageType, mask);
				DamageMaskHelper::FixupSpellDamageMask(mask);
			}
			return;
		}

		// Check for active melee/distance(munition) weapon
		if (auto weapon = player->GetWeapon()) {
			if (DamageMaskHelper::ItemHasDistanceOrMunitionCategoryFlag(weapon)) {
				mask = Options::DistanceWeaponDamageType;
			}
			else {
				DamageMaskHelper::MarkWeaponDamage(weapon, mask);
			}
		}
		else {
			mask.set(oEDamageIndex_Blunt); // Fist damage
		}
	}

	void FocusStatusBar::BuildNoFightModeDamage(DamageMask& mask)
	{
		// Check for all selected spells
		if (player->mag_book) {
			auto& spells = player->mag_book->spells;
			for (int i = 0; i < spells.GetNum(); ++i) {
				DamageMaskHelper::MarkIntDamageType(spells[i]->damageType, mask);
			}
			DamageMaskHelper::FixupSpellDamageMask(mask);
		}

		// Check for melee weapon
		auto weapon = player->GetEquippedMeleeWeapon();
		if (weapon) {
			DamageMaskHelper::MarkWeaponDamage(weapon, mask);
		}
		else {
			mask.set(oEDamageIndex_Blunt); // Fist damage
		}

		// Check for distance weapon - munition
		weapon = player->GetEquippedRangedWeapon();
		if (weapon) {
			mask |= Options::DistanceWeaponDamageType;
		}
	}

	ProtectionIconRenderData FocusStatusBar::BuildIconRenderData(const NpcProtectionStatus& status, unsigned char alpha)
	{
		ProtectionIconRenderData data;

		data.text = status.immune ? IMMUNE_ABBREVIATION : zSTRING(status.value);

		data.texture = Options::TargetProtectionIconStyle
			? zSTRING("ICON_PROTECTIONS")
			: GetIconNameByDamageIndex(status.damageIndex);

		data.color = Colors::GetColorByDamageIndex(status.damageIndex);
		data.color.alpha = alpha;

		return data;
	}

	bool FocusStatusBar::BuildProtectionModel(oCNpc* npc)
	{
		protectionModel.isInFightMode = player->fmode != 0;
		protectionModel.protectionMode = protectionModel.isInFightMode
			? (TargetProtectionMode)Options::ShowTargetProtectionInFight
			: (TargetProtectionMode)Options::ShowTargetProtectionNoFight;

		if (protectionModel.protectionMode == TargetProtectionMode::Disabled)
			return false;

		activeStatuses.clear();

		if (npc->HasFlag(NPC_FLAG_IMMORTAL))
		{
			protectionModel.mode = ProtectionRenderMode::Immortal;
			return true;
		}

		FillDamageIndexesBuffer();

		for (auto& index : activeDamageIndexes) {
			if (CanRenderProtectionStatus(npc, index)) {
				NpcProtectionStatus status;
				status.value = npc->GetProtectionByIndex(index);
				status.damageIndex = index;
				status.immune = status.value < 0;
				activeStatuses.push_back(status);
			}
		}

		if (activeStatuses.empty()) return false;

		protectionModel.mode = ProtectionRenderMode::Normal;
		return true;
	}

	void FocusStatusBar::BuildProtectionLayout(ProtectionLayout& layout)
	{
		layout.size = GetProtSize();

		if (protectionModel.mode == ProtectionRenderMode::Immortal)
		{
			layout.placement = FocusStatusProtectionPlacement::CLOSE;
			layout.margin = GetHorizontalProtMargin();
			layout.totalContentSize = layout.size;

			layout.startX = GetProtStartX(layout.placement);
			layout.startY = GetProtStartY(layout.placement);
			return;
		}

		layout.placement = GetProtPlacement(activeStatuses);
		layout.margin = (layout.placement == FocusStatusProtectionPlacement::RIGHT)
			? GetVerticalProtMargin()
			: GetHorizontalProtMargin();

		layout.totalContentSize = 0;

		switch (layout.placement)
		{
			case FocusStatusProtectionPlacement::TOP:
			{
				const int iconSpacing = screen->FontY() * 0.1f;
				const int immuneStringSize = screen->FontSize(IMMUNE_ABBREVIATION);

				for (const auto& status : activeStatuses)
				{
					const int textSize = status.immune
						? immuneStringSize
						: screen->FontSize(zSTRING(status.value));

					layout.totalContentSize += layout.size + iconSpacing + textSize;
					layout.totalContentSize += layout.margin;
				}
				layout.totalContentSize -= layout.margin;
				break;
			}
			case FocusStatusProtectionPlacement::RIGHT:
			{
				layout.totalContentSize = activeStatuses.size() * (layout.size + layout.margin) - layout.margin;
				break;
			}
			case FocusStatusProtectionPlacement::CLOSE:
			{
				const int iconSpacing = screen->FontY() * 0.1f;
				const auto& status = activeStatuses.front();

				const int textSize = status.immune
					? screen->FontSize(zSTRING(IMMUNE_ABBREVIATION))
					: screen->FontSize(zSTRING(status.value));

				layout.totalContentSize = layout.size + iconSpacing + textSize;
				break;
			}
		}

		layout.startX = GetProtStartX(layout.placement);
		layout.startY = GetProtStartY(layout.placement);
	}

	void FocusStatusBar::RenderProtectionWithLayout(const ProtectionLayout& layout)
	{
		if (protectionModel.mode == ProtectionRenderMode::Immortal)
		{
			auto color = Colors::Gray;
			if (ogame->hpBar)
				color.alpha = ogame->hpBar->alpha;

			IconInfo(layout.startX + layout.margin, layout.startY, layout.size, color, crackedShieldTexture);
			return;
		}

		switch (layout.placement)
		{
		case FocusStatusProtectionPlacement::CLOSE:
			RenderProtectionIconsClose(layout);
			break;

		case FocusStatusProtectionPlacement::TOP:
			RenderProtectionIconsTop(layout);
			break;

		case FocusStatusProtectionPlacement::RIGHT:
			RenderProtectionIconsRight(layout);
			break;
		}
	}

	HOOK Ivk_OnDamage_Hit_DistanceWeapon PATCH(&oCNpc::OnDamage_Hit, &oCNpc::OnDamage_Hit_DistanceWeapon);
	void oCNpc::OnDamage_Hit_DistanceWeapon(oSDamageDescriptor& desc) {
		THISCALL(Ivk_OnDamage_Hit_DistanceWeapon)(desc);

		if (FocusStatusBar::IsDistanceWeaponDamageTypeOverwritten)
			return;

		if (desc.pNpcAttacker != player)
			return;

		if (!desc.pItemWeapon)
			return;

		if (!DamageMaskHelper::ItemHasDistanceOrMunitionCategoryFlag(desc.pItemWeapon))
			return;

		if (Options::DistanceWeaponDamageTypeFromIni != desc.enuModeDamage) {
			DamageMask tmp{};
			DamageMaskHelper::MarkIntDamageType(desc.enuModeDamage, tmp);
			Options::DistanceWeaponDamageType = tmp;
			Options::DistanceWeaponDamageTypeFromIni = desc.enuModeDamage;
			zoptions->WriteInt(PLUGIN_NAME, "DistanceWeaponDamageType", desc.enuModeDamage, 0);
		}
		FocusStatusBar::IsDistanceWeaponDamageTypeOverwritten = true;
	}

	HOOK Ivk_EquipItem_Union PATCH(&oCNpc::EquipItem, &oCNpc::EquipItem_Union);
	void oCNpc::EquipItem_Union(oCItem* item) {
		THISCALL(Ivk_EquipItem_Union)(item);

		if (this != player)
			return;

		if (!DamageMaskHelper::ItemHasDistanceOrMunitionCategoryFlag(item))
			return;

		FocusStatusBar::IsDistanceWeaponDamageTypeOverwritten = false;
	}
}