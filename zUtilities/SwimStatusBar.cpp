// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
    SwimStatusBar::SwimStatusBar() : StatusBar(ogame->swimBar)
    {
    }

    bool SwimStatusBar::Init() {
        if (Options::StatusBarNames.GetNum() >= 3)
            name = Z Options::StatusBarNames[2];

        if (Options::SwimBarPos.GetNum() == 4)
            userPos = Options::SwimBarPos;

        return true;
    }

    zSTRING SwimStatusBar::GetBarValue() {
        return Z(int)(bar->currentValue / 100) + "/" + Z(int)(bar->maxHigh / 100);
    }
}