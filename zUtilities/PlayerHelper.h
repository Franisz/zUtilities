// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {

#define playerIsDead player->attribute[NPC_ATR_HITPOINTS] <= 0
#define invIsOpen player->inventory2.IsOpen()	

  class PlayerHelper
  {
  public:
    bool isSaving = false;

    bool IsBusy() {
      return IsInInfo() || OnPause() || invIsOpen;
    }

    bool IsInInfo() {
      return !oCInformationManager::GetInformationManager().HasFinished();
    }

    bool OnPause() {
      return ogame->IsOnPause();
    }

    bool IsSaving() {
      return isSaving;
    }

    bool IsInCombat() {
      if ( playerIsDead )
        return false;

      if ( player->enemy )
        return true;

      return false;
    }
  };

}