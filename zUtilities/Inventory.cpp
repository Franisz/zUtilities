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

    if ( !player->inventory2.IsOpen() )
      return;

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
}