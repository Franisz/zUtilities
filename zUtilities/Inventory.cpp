// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  oCItem* lastActiveMunition;

  void HandleMunition( oCItem* weapon ) {
    if ( weapon == nullptr ) {
      if ( lastActiveMunition ) {
        lastActiveMunition->ClearFlag( ITM_FLAG_ACTIVE );
        lastActiveMunition = nullptr;
      }
      return;
    }

    player->inventory2.UnpackAllItems();
    oCItem* munition = player->IsInInv( weapon->munition, 1 );

    if ( !munition )
      return;

    if ( munition->HasFlag( ITM_FLAG_ACTIVE ) )
      return;

    munition->SetFlag( ITM_FLAG_ACTIVE );

    if ( lastActiveMunition )
      if ( lastActiveMunition != munition )
        lastActiveMunition->ClearFlag( ITM_FLAG_ACTIVE );

    lastActiveMunition = munition;
  }

  void HandleMunitionLoop() {
    if ( !Options::ActivateUsedMunition )
      return;

    if (!player->inventory2.IsOpen())
        return;

    if (lastActiveMunition) {
        if (player->inventory2.IsIn(lastActiveMunition, 1) == nullptr
            && player->GetLeftHand() != lastActiveMunition
            && player->GetRightHand() != lastActiveMunition) {
            lastActiveMunition = nullptr;
        }
    }

    if ( playerStatus.traderNpc ) {
      HandleMunition( nullptr );
      return;
    }

    oCItem* weapon = player->GetEquippedRangedWeapon();

    if ( !weapon ) weapon = player->GetWeapon();

    if ( !weapon || !weapon->HasFlag( ITM_CAT_FF ) || !weapon->munition ) {
      HandleMunition( nullptr );
      return;
    }

    if ( lastActiveMunition && weapon->munition == lastActiveMunition->instanz )
      return;

    HandleMunition( weapon );
  }

  HOOK Hook_oCInformationManager_OnTradeBegin PATCH( &oCInformationManager::OnTradeBegin, &oCInformationManager::OnTradeBegin_Union );
  void oCInformationManager::OnTradeBegin_Union() {
    THISCALL( Hook_oCInformationManager_OnTradeBegin )();
    playerStatus.traderNpc = Npc;
  }

  HOOK Hook_oCItemContainer_Close PATCH( &oCItemContainer::Close, &oCItemContainer::Close_Union );
  void oCItemContainer::Close_Union() {
    playerStatus.traderNpc = nullptr;
    THISCALL( Hook_oCItemContainer_Close )();
  }
}