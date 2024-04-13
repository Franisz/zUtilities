// Supported with union (c) 2020 Union team
// Union HEADER file

using namespace Union;

namespace GOTHIC_NAMESPACE
{
  class PlayerHelper
  {
  public:
    static bool IsBusy()
    {
      return IsInInfo() || OnPause() || player->inventory2.IsOpen();
    }

    static bool IsInInfo()
    {
      return !oCInformationManager::GetInformationManager().HasFinished();
    }

    static bool OnPause()
    {
      return ogame->IsOnPause();
    }

    static bool IsDead()
    {
      return player->attribute[NPC_ATR_HITPOINTS] <= 0;
    }

    static bool IsInCombat()
    {
      return !IsDead() && player->enemy != nullptr;
    }

    static int GetSysScale()
    {
      // TODO: Load it from SystemPack.
      return 1;
    }

    static bool IsConUp()
    {
      for (int i = 0; i < zCConsole::active_consoles.GetNumInList(); i++)
        if (zCConsole::active_consoles[i]->IsVisible())
          return true;

      return false;
    }

    static bool LeftInvOpen()
    {
      return player->inventory2.IsOpen() && player->inventory2.GetNextContainerLeft(&player->inventory2);
    }
  };
}