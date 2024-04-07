// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	FocusStatusBar::FocusStatusBar() : StatusBar(ogame->focusBar)
	{
	}

	bool FocusStatusBar::Init() {
		protView = new zCView(0, 0, 8192, 8192);
		screen->InsertItem(protView);
		return true;
	}

	void FocusStatusBar::Clear() {
		__super::Clear();

		if (!bar) {
			return;
		}

		del(protView);
	}

	int FocusStatusBar::RenderProtectionIcon(oCNpc* npc, oEIndexDamage damageIndex, int offset) {
		const zSTRING texture = "ICON_PROTECTIONS"; // https://game-icons.net/1x1/lorc/cracked-shield.html

		auto bar = ogame->focusBar;
		int margin = protView->FontY() * 0.1f;
		int size = protView->FontY() * 0.75f;

		int startX = bar->vposx + bar->vsizex;
		int iconY = bar->vposy + bar->vsizey / 2 - size;

		int fontY = bar->vposy + bar->vsizey / 2 - protView->FontY() / 2;
		int protection = npc->GetProtectionByIndex(damageIndex);
		bool isImmune = protection < 0 || npc->HasFlag(NPC_FLAG_IMMORTAL);
		if (!Options::ShowCurrWeapProtOnly && protection <= 0) {
			return 0;
		}

		zSTRING protectionText = !isImmune ? zSTRING(protection) : "";
		bool textCenter = !Options::ShowCurrWeapProtOnly;
		zCOLOR color = isImmune ? Colors::Gray : Colors::GetColorByDamageIndex(damageIndex);
		if (ogame->hpBar)
		{
			color.alpha = ogame->hpBar->alpha;
		}

		auto icon = IconInfo(startX + offset + margin, iconY, size, color, texture, protectionText);

		return icon.GetSize() + margin;
	}

	void FocusStatusBar::TryShowProt(oCNpc* npc) {
		if (!Options::ShowTargetProtection)
			return;

		if (npc->attribute[NPC_ATR_HITPOINTS] <= 0)
			return;

		if (player->IsInFightMode_S(0) && (Options::ShowProtOnlyInFight || Options::ShowCurrWeapProtOnly))
			return;

		oCViewStatusBar* bar = ogame->focusBar;

		if (!bar)
			return;

		if (Options::ShowCurrWeapProtOnly) {
			int dmgIndex = player->GetActiveDamageIndex();
			if (!dmgIndex)
			{
				return;
			}

			RenderProtectionIcon(npc, (oEIndexDamage)dmgIndex, 0);
			return;
		}

		const int damageIndexes[] = {
				oEIndexDamage::oEDamageIndex_Edge,
				oEIndexDamage::oEDamageIndex_Blunt,
				oEIndexDamage::oEDamageIndex_Point,
				oEIndexDamage::oEDamageIndex_Fire,
				oEIndexDamage::oEDamageIndex_Magic,
				oEIndexDamage::oEDamageIndex_Fly,
				oEIndexDamage::oEDamageIndex_Fall
		};

		int offset = 0;
		for (auto damageIndex : damageIndexes) {
			offset += RenderProtectionIcon(npc, (oEIndexDamage)damageIndex, offset);
		}
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
		PrintValue(npc);
		TryShowProt(npc);
		return Options::ShowEnemyBarAboveHim;
	}

	bool FocusStatusBar::ShouldReverseValuePos() {
		return Options::ShowEnemyBarAboveHim;
	}

	void FocusStatusBar::Loop() {
		if (protView) {
			protView->ClrPrintwin();
		}

		if (valueView) {
			valueView->ClrPrintwin();
		}
	}
}