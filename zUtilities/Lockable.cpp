// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  int KnownLockCombination = 0;

  HOOK Hook_oCMobLockable_PickLock PATCH( &oCMobLockable::PickLock, &oCMobLockable::PickLock_Union );
  int oCMobLockable::PickLock_Union( oCNpc* npc, char key ) {
    if ( !Options::RememberLockCombination ) {
      int result = THISCALL( Hook_oCMobLockable_PickLock )(npc, key);
      return result;
    }

    // Restore largest known combination
    if ( pickLockNr < KnownLockCombination )
      pickLockNr = KnownLockCombination;

    int result = THISCALL( Hook_oCMobLockable_PickLock )(npc, key);

    // Update largest known combination
    if ( pickLockNr > KnownLockCombination )
      KnownLockCombination = pickLockNr;

    return result;
  }

  HOOK Hook_oCMobInter_StopInteraction PATCH( &oCMobInter::StopInteraction, &oCMobInter::StopInteraction_Union );
  void oCMobInter::StopInteraction_Union( oCNpc* npc ) {
    if ( npc != player || !Options::RememberLockCombination ) {
      THISCALL( Hook_oCMobInter_StopInteraction )(npc);
      return;
    }

    // Reset when leaving lockable
    if ( oCMobLockable* lockable = this->CastTo<oCMobLockable>() ) {
      KnownLockCombination = 0;
      lockable->pickLockNr = 0;
    }

    THISCALL( Hook_oCMobInter_StopInteraction )(npc);
  }
}