// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

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

		return bar->vposx + bar->vsizex;
	}

	FocusStatusProtectionPlacement FocusStatusBar::GetProtPlacement(oCNpc* npc)
	{
		auto count = npcHelper.GetProtectionStatusesVisibleCount(npc);
		if (count <= 0) {
			return FocusStatusProtectionPlacement::NONE;
		}

		if (count == 1) {
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

	void FocusStatusBar::PrintValueOutside(zSTRING str, oCNpc * npc)
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

	int FocusStatusBar::CalcProtRenderWidth(std::vector<NpcProtectionStatus> statuses) {
		int width = 0;
		int size = GetProtSize();
		int margin = GetProtMargin();
		auto statusCount = statuses.size();

		for (int i = 0; i < statusCount; i++)
		{
			auto status = statuses[i];
			if (status.immune && statusCount == 1)
			{
				width += size;
				continue;
			}

			width += size + screen->FontY() / 10 + screen->FontSize(zSTRING(status.value));

			if (i + 1 != statuses.size()) {
				width += margin;
			}
		}

		return width;
	}

	bool FocusStatusBar::TryShowProt(oCNpc* npc) {
		const zSTRING texture = "ICON_PROTECTIONS"; // https://game-icons.net/1x1/lorc/cracked-shield.html

		if (npc->attribute[NPC_ATR_HITPOINTS] <= 0)
			return false;

		if (!bar)
			return false;

		if (IsShowTargetProtectionDisabled())
			return false;

		auto statuses = npcHelper.GetProtectionVisibleStatuses(npc);
		auto statusCount = statuses.size();
		if (statusCount == 0) {
			return false;
		}

		auto placement = GetProtPlacement(npc);
		int margin = GetProtMargin();
		int size = GetProtSize();
		int startX = GetProtStartX(placement);
		int startY = GetProtStartY(placement);
		int offset = 0;

		if (placement == FocusStatusProtectionPlacement::TOP)
		{
			startX = startX + bar->vsizex / 2 - CalcProtRenderWidth(statuses) / 2 ;
		}

		for (int i = 0; i < statuses.size(); i++) {
			auto status = statuses[i];
			auto canRenderImmune = status.immune && statusCount == 1;

			auto protectionText = !canRenderImmune ? zSTRING(status.value) : "";
			auto color = canRenderImmune ? Colors::Gray : Colors::GetColorByDamageIndex(status.damageIndex);
			if (ogame->hpBar)
			{
				color.alpha = ogame->hpBar->alpha;
			}

			auto icon = IconInfo(startX + offset + margin, startY, size, color, texture, protectionText);
			offset += icon.GetSize();
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
}