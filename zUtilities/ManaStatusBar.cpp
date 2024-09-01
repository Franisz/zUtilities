// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
    ManaStatusBar::ManaStatusBar() : StatusBar(ogame->manaBar)
    {
        restoreAttribute = NPC_ATR_MANAMAX;
    }

    bool ManaStatusBar::Init() {
        symbols.Insert("NAME_BONUS_MANA_FULL"); // Full Heal
        symbols.Insert("NAME_BONUS_MANA_PERC"); // Percentage Heal
        symbols.Insert("NAME_BONUS_MANA"); // Flat Heal
        if (Options::StatusBarNames.GetNum() >= 2)
            name = Z Options::StatusBarNames[1];

        if (Options::ManaBarPos.GetNum() == 4)
            userPos = Options::ManaBarPos;

        return true;
    }
}