// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
	HealthStatusBar::HealthStatusBar() : StatusBar(ogame->hpBar)
	{
        restoreAttribute = NPC_ATR_HITPOINTSMAX;
	}

	bool HealthStatusBar::Init() {
        symbols.Insert("NAME_BONUS_HP_FULL"); // Full Heal
        symbols.Insert("NAME_BONUS_HP_PERC"); // Percentage Heal
        symbols.Insert("NAME_BONUS_HP"); // Flat Heal
        if (Options::StatusBarNames.GetNum() >= 1)
            name = Z Options::StatusBarNames[0];

        if (Options::HealthBarPos.GetNum() == 4)
            userPos = Options::HealthBarPos;

        return true;
	}
}