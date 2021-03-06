// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  class PlayerHelper {
  public:
    bool IsBusy() {
      return IsInInfo() || OnPause() || player->inventory2.IsOpen();
    }

    bool IsInInfo() {
      return !oCInformationManager::GetInformationManager().HasFinished();
    }

    bool OnPause() {
      return ogame->IsOnPause();
    }

    bool IsDead() {
      return player->attribute[NPC_ATR_HITPOINTS] <= 0;
    }

    bool IsInCombat() {
      return !IsDead() && player->enemy != nullptr;
    }

    int GetSysScale() {
      float scale;
      Union.GetSysPackOption().Read( scale, "INTERFACE", "Scale", 1.0f );
      return (int)scale;
    }

    bool IsConUp() {
      for ( int i = 0; i < zCConsole::active_consoles.GetNumInList(); i++ )
        if ( zCConsole::active_consoles[i]->IsVisible() )
          return true;

      return false;
    }

    bool LeftInvOpen() {
      return player->inventory2.IsOpen() && player->inventory2.GetNextContainerLeft( &player->inventory2 );
    }
  };

  PlayerHelper playerHelper;
}