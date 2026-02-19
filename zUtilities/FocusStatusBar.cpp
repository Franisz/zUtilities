// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	bool FocusStatusBar::IsDistanceWeaponDamageTypeOverwritten = false;

	const std::vector<oEIndexDamage> PROTECTION_DAMAGE_INDEXES = std::vector<oEIndexDamage>({
		oEIndexDamage::oEDamageIndex_Edge,
		oEIndexDamage::oEDamageIndex_Blunt,
		oEIndexDamage::oEDamageIndex_Point,
		oEIndexDamage::oEDamageIndex_Fire,
		oEIndexDamage::oEDamageIndex_Magic,
		oEIndexDamage::oEDamageIndex_Fly,
		oEIndexDamage::oEDamageIndex_Fall
		});


	inline static void MarkWeaponDamage(const oCItem* weapon, DamageMask& mask)
	{
		for (int i = 0; i < oEDamageIndex::oEDamageIndex_MAX; ++i) {
			if (weapon->damage[i] > 0) {
				mask.set(i);
			}
		}
	}

	inline static void MarkIntDamageType(const int& damageTypeMask, DamageMask& mask)
	{
		for (const auto& mapItem : DAMAGE_MAP) {
			if (damageTypeMask & mapItem.type) {
				mask.set(mapItem.index);
			}
		}
	}

	inline static void MarkMunitionDamage(const oCItem* weapon, DamageMask& mask)
	{
		const bool hasMunition = weapon->munition != 0;
		const bool isCrossbow = (weapon->flags & ITM_FLAG_CROSSBOW) != 0;

		const oCItem* leftHand = player->GetLeftHand()->CastTo<oCItem>();
		const oCItem* rightHand = player->GetRightHand()->CastTo<oCItem>();
		const oCItem* handItem = isCrossbow ? leftHand : rightHand;

		const int handInstanz =
			reinterpret_cast<int>(handItem)
			? handItem->instanz
			: 0;

		const bool useMunition =
			static_cast<bool>(
				hasMunition &
				(handItem != nullptr) &
				(handInstanz == weapon->munition)
				);

		const oCItem* damageSource = useMunition ? handItem : weapon;

		MarkWeaponDamage(damageSource, mask);
	}

	/* In G1 default damageType for spell is `oEDamageType_Blunt` so for summon/transformation etc. spells
	it's best to reset this flag in mask to hide incorrect protection icon.
	In G2 default damageType for spell is `oEDamageType_Magic` so it's left untouched.*/
	inline static void FixupSpellDamageMask(DamageMask& mask)
	{
#if ENGINE <= Engine_G1A
		mask.reset(oEDamageIndex_Blunt);
#endif
	}

	inline static bool ItemHasDistanceOrMunitionCategoryFlag(const oCItem* item) {
		return item->mainflag & (ITM_CAT_FF | ITM_CAT_MUN);
	}

	inline static std::vector<oEIndexDamage> BuildOrderedDamageIndexes(const DamageMask& mask)
	{
		std::vector<oEIndexDamage> result;
		result.reserve(PROTECTION_DAMAGE_INDEXES.size());

		for (auto index : PROTECTION_DAMAGE_INDEXES) {
			if (mask.test(index)) {
				result.push_back(index);
			}
		}
		return result;
	}

	FocusStatusBar::FocusStatusBar() : StatusBar(ogame->focusBar)
	{
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

	int FocusStatusBar::GetProtMargin() {
		return protView->FontY() * 0.1f;
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

	FocusStatusProtectionPlacement FocusStatusBar::GetProtPlacement(oCNpc* npc)
	{
		auto count = GetProtectionStatusesVisibleCount(npc);
		if (count <= 0) {
			return FocusStatusProtectionPlacement::NONE;
		}

		if (count == 1) {
			return FocusStatusProtectionPlacement::CLOSE;
		}

		if (Options::TargetProtectionIconPosition == 1) {
			return FocusStatusProtectionPlacement::RIGHT;
		}

		return FocusStatusProtectionPlacement::TOP;
	}

	int FocusStatusBar::GetProtStartY(FocusStatusProtectionPlacement placement) {
		if (placement == FocusStatusProtectionPlacement::TOP) {
			return bar->vposy - GetProtMargin() - GetProtSize() - bar->vsizey;
		}

		return bar->vposy + bar->vsizey / 2 - GetProtSize();
	}

	void FocusStatusBar::PrintValueOutside(zSTRING str, oCNpc* npc)
	{
		auto protPlacement = GetProtPlacement(npc);
		int offsetY = bar->vsizey / 2 + valueView->FontY();
		int x = bar->vposx + bar->vsizex / 2 - valueView->FontSize(str) / 2;
		int y = bar->vposy - offsetY;

		if (protPlacement == FocusStatusProtectionPlacement::TOP) {
			y = GetProtStartY(protPlacement) - offsetY;
		}

		valueView->SetFontColor(zCOLOR(valueView->color.r, valueView->color.g, valueView->color.b, bar->alpha));
		valueView->Print(x, y, str);
	}

	int FocusStatusBar::CalcProtRenderWidth(const std::vector<NpcProtectionStatus>& statuses) {
		int width = 0;
		int size = GetProtSize();
		int margin = GetProtMargin();
		auto statusCount = statuses.size();

		if (statusCount == 1) {
			return size;
		}

		for (int i = 0; i < statusCount; ++i)
		{
			const auto& status = statuses[i];

			int fontValue = (status.value < 0)
				? screen->FontSize(zSTRING(IMMUNE_ABBREVIATION))
				: screen->FontSize(zSTRING(status.value));

			width += size + screen->FontY() / 10 + fontValue;

			if (i + 1 < statusCount) {
				width += margin;
			}
		}

		return width;
	}

	bool FocusStatusBar::TryShowProt(oCNpc* npc) {
		if (npc->attribute[NPC_ATR_HITPOINTS] <= 0 || !bar || IsShowTargetProtectionDisabled())
			return false;

		auto statuses = GetProtectionVisibleStatuses(npc);
		if (statuses.empty()) {
			return false;
		}

		auto placement = GetProtPlacement(npc);
		int margin = GetProtMargin();
		int size = GetProtSize();
		int startX = GetProtStartX(placement);
		int startY = GetProtStartY(placement);

		if (npc->HasFlag(NPC_FLAG_IMMORTAL)) {
			auto color = Colors::Gray;
			if (ogame->hpBar)
			{
				color.alpha = ogame->hpBar->alpha;
			}
			IconInfo(startX + margin, startY, size, color, crackedShieldTexture);

			return true;
		}

		switch (placement)
		{
		case FocusStatusProtectionPlacement::CLOSE:
			RenderProtectionIconsClose(startX, startY, size, margin, statuses[0]);
			break;
		case FocusStatusProtectionPlacement::TOP:
			RenderProtectionIconsTop(startX, startY, size, margin, &statuses);
			break;
		case FocusStatusProtectionPlacement::RIGHT:
			RenderProtectionIconsRight(startX, startY, size, margin, &statuses);
			break;
		default:
			return false;
		}

		return true;
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

		MoveFocusBar(x, y, npc);
		TryShowProt(npc);
		PrintValue(npc);
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

	bool FocusStatusBar::IsShowTargetProtectionDisabled() {
		auto currentMode = player->IsInFightMode_S(NPC_WEAPON_NONE) ? Options::ShowTargetProtectionNoFight : Options::ShowTargetProtectionInFight;
		return currentMode == TargetProtectionMode::Disabled;
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

	void FocusStatusBar::RenderProtectionIconsClose(int startX, int startY, int size, int margin, const NpcProtectionStatus& status)
	{
		unsigned char alpha = ogame->hpBar ? ogame->hpBar->alpha : 255;
		auto data = BuildRenderData(status, alpha);

		IconInfo(startX + margin, startY, size, data.color, data.texture, data.text);
	}

	void FocusStatusBar::RenderProtectionIconsTop(int startX, int startY, int size, int margin, std::vector<NpcProtectionStatus>* statuses)
	{
		startX = startX + bar->vsizex / 2 - CalcProtRenderWidth((*statuses)) / 2;
		unsigned char alpha = ogame->hpBar ? ogame->hpBar->alpha : 255;

		for (const auto& status : *statuses)
		{
			auto data = BuildRenderData(status, alpha);

			auto icon = IconInfo(startX + margin, startY, size, data.color, data.texture, data.text);
			startX += icon.GetSize() + 30; // +30 is an additional spacing to separate icons from each other and from the text
		}
	}

	void FocusStatusBar::RenderProtectionIconsRight(int startX, int startY, int size, int margin, std::vector<NpcProtectionStatus>* statuses)
	{
		unsigned char alpha = ogame->hpBar ? ogame->hpBar->alpha : 255;

		for (const auto& status : *statuses)
		{
			auto data = BuildRenderData(status, alpha);

			IconInfo(startX, startY, size, data.color, data.texture, data.text);
			startY += screen->FontY() + 85; // +85 is an additional spacing between rendered icons in column
		}
	}

	bool FocusStatusBar::CanRenderProtectionStatus(oCNpc* npc, oEIndexDamage damageIndex)
	{
		auto protectionMode = player->IsInFightMode_S(NPC_WEAPON_NONE) ? Options::ShowTargetProtectionNoFight : Options::ShowTargetProtectionInFight;
		if (protectionMode != TargetProtectionMode::All) {
			return true;
		}

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

	std::vector<oEIndexDamage> FocusStatusBar::GetDamageIndexes()
	{
		bool isInFightMode = !player->IsInFightMode_S(NPC_WEAPON_NONE);
		auto protectionMode = isInFightMode
			? Options::ShowTargetProtectionInFight
			: Options::ShowTargetProtectionNoFight;

		if (protectionMode == TargetProtectionMode::All) {
			return PROTECTION_DAMAGE_INDEXES;
		}

		DamageMask mask;
		mask.reset();

		if (isInFightMode) {
			BuildFightModeDamage(mask);
		}
		else {
			BuildNoFightModeDamage(mask);
		}

		return BuildOrderedDamageIndexes(mask);
	}

	std::vector<NpcProtectionStatus> FocusStatusBar::GetProtectionVisibleStatuses(oCNpc* npc) {
		auto vec = std::vector<NpcProtectionStatus>();

		if (playerStatus.focusBar->IsShowTargetProtectionDisabled()) {
			return vec;
		}

		if (npc->HasFlag(NPC_FLAG_IMMORTAL))
		{
			NpcProtectionStatus status;
			vec.push_back(status);
			return vec;
		}

		auto damageIndexes = GetDamageIndexes();
		for (auto damageIndex : damageIndexes)
		{
			if (!CanRenderProtectionStatus(npc, damageIndex)) {
				continue;
			}

			NpcProtectionStatus status;
			status.value = npc->GetProtectionByIndex(damageIndex);
			status.damageIndex = damageIndex;
			status.immune = status.value < 0;
			vec.push_back(status);
		}

		return vec;
	}

	int FocusStatusBar::GetProtectionStatusesVisibleCount(oCNpc* npc) {
		if (playerStatus.focusBar->IsShowTargetProtectionDisabled()) {
			return 0;
		}

		if (npc->HasFlag(NPC_FLAG_IMMORTAL)) {
			return 1;
		}

		int count = 0;
		auto damageIndexes = GetDamageIndexes();
		for (auto damageIndex : damageIndexes)
		{
			if (!CanRenderProtectionStatus(npc, damageIndex)) {
				continue;
			}

			count++;
		}

		return count;
	}

	void FocusStatusBar::BuildFightModeDamage(DamageMask& mask)
	{
		// Check for active spell
		if (player->IsInFightMode_S(NPC_WEAPON_MAG)) {
			if (auto spell = player->mag_book->GetSelectedSpell()) {
				MarkIntDamageType(spell->damageType, mask);
				FixupSpellDamageMask(mask);
			}
			return;
		}

		// Check for active melee/distance(munition) weapon
		if (auto weapon = player->GetWeapon()) {
			if (ItemHasDistanceOrMunitionCategoryFlag(weapon)) {
				mask = Options::DistanceWeaponDamageType;
			}
			else {
				MarkWeaponDamage(weapon, mask);
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
				MarkIntDamageType(spells[i]->damageType, mask);
			}
			FixupSpellDamageMask(mask);
		}

		// Check for melee weapon
		auto weapon = player->GetEquippedMeleeWeapon();
		if (weapon) {
			MarkWeaponDamage(weapon, mask);
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

	ProtectionRenderData FocusStatusBar::BuildRenderData(const NpcProtectionStatus& status, unsigned char alpha)
	{
		ProtectionRenderData data;

		data.text = status.immune ? IMMUNE_ABBREVIATION : zSTRING(status.value);

		data.texture = Options::TargetProtectionIconStyle
			? zSTRING("ICON_PROTECTIONS")
			: GetIconNameByDamageIndex(status.damageIndex);

		data.color = Colors::GetColorByDamageIndex(status.damageIndex);
		data.color.alpha = alpha;

		return data;
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

		if (!ItemHasDistanceOrMunitionCategoryFlag(desc.pItemWeapon))
			return;

		if (Options::DistanceWeaponDamageTypeFromIni != desc.enuModeDamage) {
			DamageMask tmp{};
			MarkIntDamageType(desc.enuModeDamage, tmp);
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

		if (!ItemHasDistanceOrMunitionCategoryFlag(item))
			return;

		FocusStatusBar::IsDistanceWeaponDamageTypeOverwritten = false;
	}
}