// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	const int PROTECTION_DAMAGE_INDEXES[] = {
		oEIndexDamage::oEDamageIndex_Edge,
		oEIndexDamage::oEDamageIndex_Blunt,
		oEIndexDamage::oEDamageIndex_Point,
		oEIndexDamage::oEDamageIndex_Fire,
		oEIndexDamage::oEDamageIndex_Magic,
		oEIndexDamage::oEDamageIndex_Fly,
		oEIndexDamage::oEDamageIndex_Fall
	};

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

	int FocusStatusBar::GetProtStartX() {
		if (Options::ShowCurrWeapProtOnly) {
			return bar->vposx + bar->vsizex;
		}

		return bar->vposx;
	}

	int FocusStatusBar::GetProtStartY() {
		if (Options::ShowCurrWeapProtOnly) {
			return bar->vposy + bar->vsizey / 2 - GetProtSize();
		}

		return bar->vposy - GetProtMargin() - GetProtSize() - bar->vsizey;
	}

	int FocusStatusBar::RenderProtectionIcon(oCNpc* npc, oEIndexDamage damageIndex, int offset) {
		const zSTRING texture = "ICON_PROTECTIONS"; // https://game-icons.net/1x1/lorc/cracked-shield.html

		int margin = GetProtMargin();
		int size = GetProtSize();
		int startX = GetProtStartX();
		int iconY = GetProtStartY();

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

	void FocusStatusBar::PrintValueOutside(zSTRING str, oCNpc * npc)
	{
		int offsetY = bar->vsizey / 2 + valueView->FontY();
		int x = bar->vposx + bar->vsizex / 2 - valueView->FontSize(str) / 2;
		int y = bar->vposy - offsetY;

		if (protRendered && !Options::ShowCurrWeapProtOnly) {
			y = GetProtStartY() - offsetY;
		}

		valueView->SetFontColor(zCOLOR(valueView->color.r, valueView->color.g, valueView->color.b, bar->alpha));
		valueView->Print(x, y, str);
	}

	bool FocusStatusBar::TryShowProt(oCNpc* npc) {
		if (!Options::ShowTargetProtection)
			return false;

		if (npc->attribute[NPC_ATR_HITPOINTS] <= 0)
			return false;

		if (player->IsInFightMode_S(0) && (Options::ShowProtOnlyInFight || Options::ShowCurrWeapProtOnly))
			return false;

		if (!bar)
			return false;

		if (Options::ShowCurrWeapProtOnly) {
			int dmgIndex = player->GetActiveDamageIndex();
			if (!dmgIndex)
			{
				return false;
			}

			return RenderProtectionIcon(npc, (oEIndexDamage)dmgIndex, 0) > 0;
		}

		int offset = 0;
		for (auto damageIndex : PROTECTION_DAMAGE_INDEXES) {
			offset += RenderProtectionIcon(npc, (oEIndexDamage)damageIndex, offset);
		}

		return offset > 0;
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
		protRendered = TryShowProt(npc);
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
}