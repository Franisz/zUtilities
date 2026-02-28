// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	bool FocusStatusBar::IsDistanceWeaponDamageTypeOverwritten = false;

	const oEIndexDamage FocusStatusBar::ProtectionDamageOrderedIndexes[ProtectionCount] = {
	oEDamageIndex_Edge,
	oEDamageIndex_Blunt,
	oEDamageIndex_Point,
	oEDamageIndex_Fire,
	oEDamageIndex_Magic,
	oEDamageIndex_Fly,
	oEDamageIndex_Fall
	};

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

	FocusStatusBar::FocusStatusBar() : StatusBar(ogame->focusBar)
	{
		iconCache[oEDamageIndex_Barrier] = "DMGICON_BARRIER";
		iconCache[oEDamageIndex_Blunt] = "DMGICON_BLUNT";     // https://game-icons.net/1x1/lorc/cross-mark.html
		iconCache[oEDamageIndex_Edge] = "DMGICON_EDGE";       // https://game-icons.net/1x1/lorc/ragged-wound.html
		iconCache[oEDamageIndex_Fire] = "DMGICON_FIRE";       // https://game-icons.net/1x1/lorc/burning-embers.html
		iconCache[oEDamageIndex_Fly] = "DMGICON_FLY";         // https://game-icons.net/1x1/lorc/fluffy-trefoil.html
		iconCache[oEDamageIndex_Magic] = "DMGICON_MAGIC";     // https://game-icons.net/1x1/delapouite/polar-star.html
		iconCache[oEDamageIndex_Point] = "DMGICON_POINT";     // https://game-icons.net/1x1/skoll/bullseye.html
		iconCache[oEDamageIndex_Fall] = "DMGICON_FALL";       // https://game-icons.net/1x1/sbed/falling.html
		iconCache[oEDamageIndex_MAX] = "DMGICON_UNKNOWN";     // https://game-icons.net/1x1/lorc/scar-wound.html
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

	bool FocusStatusBar::BuildProtectionModel(oCNpc* npc)
	{
		activeStatusesCount = 0;
		protectionModel.isInFightMode = player->fmode != 0;
		protectionModel.targetProtectionMode = protectionModel.isInFightMode
			? (TargetProtectionMode)Options::ShowTargetProtectionInFight
			: (TargetProtectionMode)Options::ShowTargetProtectionNoFight;

		if (protectionModel.targetProtectionMode == TargetProtectionMode::Disabled)
			return false;

		if (npc->HasFlag(NPC_FLAG_IMMORTAL))
		{
			protectionModel.renderMode = ProtectionRenderMode::Immortal;
			return true;
		}

		FillDamageIndexesBuffer();

		for (int i = 0; i < activeDamageIndexesCount; ++i) {
			oEIndexDamage index = activeDamageIndexes[i];

			if (CanRenderProtectionStatus(npc, index)) {
				NpcProtectionStatus& status = activeStatuses[activeStatusesCount++];
				status.value = npc->GetProtectionByIndex(index);
				status.damageIndex = index;
				status.immune = status.value < 0;
			}
		}
		protectionModel.renderMode = ProtectionRenderMode::Normal;

		return activeStatusesCount > 0;
	}

	void FocusStatusBar::FillDamageIndexesBuffer()
	{
		activeDamageIndexesCount = 0;

		if (protectionModel.targetProtectionMode == TargetProtectionMode::All) {
			for (int i = 0; i < ProtectionCount; ++i)
			{
				activeDamageIndexes[activeDamageIndexesCount++] = ProtectionDamageOrderedIndexes[i];
			}
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

		for (int i = 0; i < oEDamageIndex_MAX; i++) {
			if (mask.test(i)) {
				activeDamageIndexes[activeDamageIndexesCount++] = (oEIndexDamage)i;
			}
		}
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

	void FocusStatusBar::BuildProtectionLayout(ProtectionLayout& layout)
	{
		layout.fontY = protView->FontY();
		layout.iconSize = layout.fontY * 0.75f;

		if (protectionModel.renderMode == ProtectionRenderMode::Immortal) {
			layout.placement = FocusStatusProtectionPlacement::CLOSE;
			layout.margin = GetHorizontalProtMargin(layout.fontY);
			layout.totalContentSize = layout.iconSize;
			layout.startX = bar->vposx + bar->vsizex;
			layout.startY = bar->vposy + bar->vsizey / 2 - layout.iconSize;
			return;
		}

		layout.placement = GetProtectionPlacement();
		switch (layout.placement)
		{
		case FocusStatusProtectionPlacement::TOP:
		{
			layout.margin = GetHorizontalProtMargin(layout.fontY);

			const int iconSpacing = layout.fontY * 0.1f;
			const int immuneStringSize = screen->FontSize(ImmuneAbbreviation);

			for (int i = 0; i < activeStatusesCount; ++i)
			{
				const int textSize = activeStatuses[i].immune
					? immuneStringSize
					: screen->FontSize(zSTRING(activeStatuses[i].value));

				layout.totalContentSize += layout.iconSize + iconSpacing + textSize + layout.margin;
			}
			layout.totalContentSize -= layout.margin;
			layout.startX = bar->vposx;
			layout.startY = bar->vposy - layout.margin - layout.iconSize - bar->vsizey;
			break;
		}
		case FocusStatusProtectionPlacement::RIGHT:
		{
			layout.margin = GetVerticalProtMargin(layout.fontY);
			layout.totalContentSize = activeStatusesCount * (layout.iconSize + layout.margin) - layout.margin;
			layout.startX = bar->vposx + bar->vsizex + ProtectionPlacementRightMargin;
			layout.startY = bar->vposy + bar->vsizey / 2 - layout.iconSize;
			break;
		}
		case FocusStatusProtectionPlacement::CLOSE:
		{
			layout.margin = GetHorizontalProtMargin(layout.fontY);
			const int iconSpacing = layout.fontY * 0.1f;

			const int textSize = activeStatuses[0].immune
				? screen->FontSize(ImmuneAbbreviation)
				: screen->FontSize(zSTRING(activeStatuses[0].value));

			layout.totalContentSize = layout.iconSize + iconSpacing + textSize;
			layout.startX = bar->vposx + bar->vsizex;
			layout.startY = bar->vposy + bar->vsizey / 2 - layout.iconSize;
			break;
		}
		}
	}

	FocusStatusProtectionPlacement FocusStatusBar::GetProtectionPlacement() const
	{
		if (activeStatusesCount == 1) {
			return FocusStatusProtectionPlacement::CLOSE;
		}

		if (Options::TargetProtectionIconPosition == 0) {
			return FocusStatusProtectionPlacement::TOP;
		}

		if (activeStatusesCount <= 0) {
			return FocusStatusProtectionPlacement::NONE;
		}

		return FocusStatusProtectionPlacement::RIGHT;
	}

	int FocusStatusBar::GetHorizontalProtMargin(int fontY) const {
		return fontY * 0.1f + 30;
	}

	int FocusStatusBar::GetVerticalProtMargin(int fontY) const {
		return fontY + 85;
	}

	void FocusStatusBar::RenderProtectionWithLayout(const ProtectionLayout& layout)
	{
		if (protectionModel.renderMode == ProtectionRenderMode::Immortal)
		{
			auto color = Colors::Gray;
			if (ogame->hpBar)
				color.alpha = ogame->hpBar->alpha;

			IconInfo(layout.startX + layout.margin, layout.startY, layout.iconSize, color, CrackedShieldTexture);
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

	bool FocusStatusBar::CanRenderProtectionStatus(oCNpc* npc, oEIndexDamage damageIndex) const
	{
		if (protectionModel.targetProtectionMode != TargetProtectionMode::All)
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

	void FocusStatusBar::RenderProtectionIconsClose(const ProtectionLayout& layout)
	{
		unsigned char alpha = ogame->hpBar ? ogame->hpBar->alpha : 255;
		auto data = BuildIconRenderData(activeStatuses[0], alpha);

		IconInfo(layout.startX + layout.margin, layout.startY, layout.iconSize, data.color, data.texture, data.text);
	}

	void FocusStatusBar::RenderProtectionIconsRight(const ProtectionLayout& layout)
	{
		int currentY = layout.startY;
		unsigned char alpha = ogame->hpBar ? ogame->hpBar->alpha : 255;

		for (int i = 0; i < activeStatusesCount; ++i)
		{
			auto data = BuildIconRenderData(activeStatuses[i], alpha);

			IconInfo(layout.startX, currentY, layout.iconSize, data.color, data.texture, data.text);
			currentY += layout.iconSize + layout.margin;
		}
	}

	void FocusStatusBar::RenderProtectionIconsTop(const ProtectionLayout& layout)
	{
		int currentX = layout.startX + bar->vsizex / 2 - layout.totalContentSize / 2;
		unsigned char alpha = ogame->hpBar ? ogame->hpBar->alpha : 255;

		for (int i = 0; i < activeStatusesCount; ++i)
		{
			auto data = BuildIconRenderData(activeStatuses[i], alpha);

			auto icon = IconInfo(currentX, layout.startY, layout.iconSize, data.color, data.texture, data.text);
			currentX += icon.GetSize() + layout.margin;
		}
	}

	ProtectionIconRenderData FocusStatusBar::BuildIconRenderData(const NpcProtectionStatus& status, unsigned char alpha)
	{
		ProtectionIconRenderData data;

		data.text = status.immune ? ImmuneAbbreviation : zSTRING(status.value);

		data.texture = Options::TargetProtectionIconStyle
			? CrackedShieldTexture
			: GetIconNameByDamageIndex(status.damageIndex);

		data.color = Colors::GetColorByDamageIndex(status.damageIndex);
		data.color.alpha = alpha;

		return data;
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

	void FocusStatusBar::PrintValueOutside(zSTRING& str)
	{
		int offsetY = bar->vsizey / 2 + valueView->FontY();
		int x = bar->vposx + bar->vsizex / 2 - valueView->FontSize(str) / 2;

		int y = bar->vposy - offsetY + valueOffsetY;

		valueView->SetFontColor(zCOLOR(valueView->color.r, valueView->color.g, valueView->color.b, bar->alpha));
		valueView->Print(x, y, str);
	}

	const zSTRING& FocusStatusBar::GetIconNameByDamageIndex(const oEIndexDamage& index)
	{
		if (index < 0 || index >= oEDamageIndex_MAX)
			return iconCache[oEDamageIndex_MAX]; // fallback

		return iconCache[index];
	}
}