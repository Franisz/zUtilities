// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	bool FocusStatusBar::IsDistanceWeaponDamageTypeOverwritten = false;

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
		auto count = npcHelper.GetProtectionStatusesVisibleCount(npc);
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

		auto statuses = npcHelper.GetProtectionVisibleStatuses(npc);
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
		auto& protectionText = status.immune ? IMMUNE_ABBREVIATION : zSTRING(status.value);
		auto color = Colors::GetColorByDamageIndex(status.damageIndex);

		if (ogame->hpBar)
		{
			color.alpha = ogame->hpBar->alpha;
		}

		const zSTRING texture = Options::TargetProtectionIconStyle
			? zSTRING("ICON_PROTECTIONS")
			: GetIconNameByDamageIndex(status.damageIndex);

		IconInfo(startX + margin, startY, size, color, texture, protectionText);
	}

	void FocusStatusBar::RenderProtectionIconsTop(int startX, int startY, int size, int margin, std::vector<NpcProtectionStatus>* statuses)
	{
		startX = startX + bar->vsizex / 2 - CalcProtRenderWidth((*statuses)) / 2;
		unsigned char alpha = 255;
		if (ogame->hpBar) alpha = ogame->hpBar->alpha;

		for (const auto& status : *statuses)
		{
			auto& protectionText = status.immune ? IMMUNE_ABBREVIATION : zSTRING(status.value);
			auto color = Colors::GetColorByDamageIndex(status.damageIndex);
			color.alpha = alpha;

			const zSTRING texture = Options::TargetProtectionIconStyle
				? zSTRING("ICON_PROTECTIONS")
				: GetIconNameByDamageIndex(status.damageIndex);

			auto icon = IconInfo(startX + margin, startY, size, color, texture, protectionText);
			startX += icon.GetSize() + 30; // +30 is an additional spacing to separate icons from each other and from the text
		}
	}

	void FocusStatusBar::RenderProtectionIconsRight(int startX, int startY, int size, int margin, std::vector<NpcProtectionStatus>* statuses)
	{
		unsigned char alpha = 255;
		if (ogame->hpBar) alpha = ogame->hpBar->alpha;

		for (const auto& status : *statuses)
		{
			auto& protectionText = status.immune ? IMMUNE_ABBREVIATION : zSTRING(status.value);
			auto color = Colors::GetColorByDamageIndex(status.damageIndex);
			color.alpha = alpha;

			const zSTRING texture = Options::TargetProtectionIconStyle
				? zSTRING("ICON_PROTECTIONS")
				: GetIconNameByDamageIndex(status.damageIndex);

			IconInfo(startX, startY, size, color, texture, protectionText);
			startY += screen->FontY() + 85; // +85 is an additional spacing between rendered icons in column
		}
	}
}