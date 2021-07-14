// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

#if ENGINE >= Engine_G2
  int FocusColor::GetAbsolutionLevel( oCNpc* slf ) {
    if ( (slf->npcType == 3 || slf->npcType == 4) && (slf->guild == 1 || slf->guild == 2 || slf->guild == 3) )
      if ( parser->GetSymbol( "ABSOLUTIONLEVEL_OldCamp" ) )
        return parser->GetSymbol( "ABSOLUTIONLEVEL_OldCamp" )->single_intdata;

    if ( slf->guild == 1 || slf->guild == 2 || slf->guild == 3 )
      if ( parser->GetSymbol( "ABSOLUTIONLEVEL_City" ) )
        return parser->GetSymbol( "ABSOLUTIONLEVEL_City" )->single_intdata;

    if ( slf->guild == 4 || slf->guild == 5 )
      if ( parser->GetSymbol( "ABSOLUTIONLEVEL_Monastery" ) )
        return parser->GetSymbol( "ABSOLUTIONLEVEL_Monastery" )->single_intdata;

    if ( slf->guild == 7 || slf->guild == 8 )
      if ( parser->GetSymbol( "ABSOLUTIONLEVEL_Monastery" ) )
        return parser->GetSymbol( "ABSOLUTIONLEVEL_Monastery" )->single_intdata;

    if ( slf->npcType == 5 || slf->npcType == 7 )
      if ( parser->GetSymbol( "ABSOLUTIONLEVEL_BL" ) )
        return parser->GetSymbol( "ABSOLUTIONLEVEL_BL" )->single_intdata;

    return 0;
  }
#endif

  zCOLOR FocusColor::NpcColor( oCNpc* focusNpc ) {

    if ( focusNpc->attribute[NPC_ATR_HITPOINTS] <= 0 ) {
      if ( !focusNpc->stealcontainer->contList.GetNumInList() )
        return zCOLOR( 175, 175, 175 );
      else
        return colDefault;
    }

#if ENGINE >= Engine_G2
    if ( focusNpc->IsHostile( player )
      || (focusNpc->enemy == player && focusNpc->IsAIState( parser->GetIndex( "ZS_Attack" ) ))
      && (focusNpc->aiscriptvars[9] == 13
        || focusNpc->aiscriptvars[9] == 14
        || focusNpc->aiscriptvars[9] == 15
        || focusNpc->aiscriptvars[9] == 17
        || focusNpc->aiscriptvars[9] == 18
        || focusNpc->aiscriptvars[9] == 19
        || focusNpc->aiscriptvars[1] == 4
        || focusNpc->aiscriptvars[52] == 1) ) {
      return zCOLOR( 255, 0, 0 );
    }

    if ( focusNpc->IsAngry( player ) || (focusNpc->enemy == player && focusNpc->IsAIState( parser->GetIndex( "ZS_Attack" ) )) )
      return zCOLOR( 255, 180, 0 );

    int day, hour, min;
    ogame->GetTime( day, hour, min );

    if ( focusNpc->aiscriptvars[1] != 0
      && !(focusNpc->aiscriptvars[1] <= 3 && focusNpc->aiscriptvars[2] < day - 2)
      && !(focusNpc->aiscriptvars[46] < GetAbsolutionLevel( focusNpc )) )
      return zCOLOR( 255, 180, 0 );

    if ( (focusNpc->IsFriendly( player ) || focusNpc->npcType == 2) && !focusNpc->IsAIState( parser->GetIndex( "ZS_ReactToDamage" ) ) )
      return zCOLOR( 0, 255, 0 );
#else
    if ( (focusNpc->IsHostile( player ) && focusNpc->GetPermAttitude( player ) == NPC_ATT_HOSTILE)
      || (focusNpc->enemy == player && focusNpc->aiscriptvars[35] && focusNpc->IsAIState( parser->GetIndex( "ZS_Attack" ) )) )
      return zCOLOR( 255, 0, 0 );

    if ( (focusNpc->IsAngry( player ) || focusNpc->enemy == player)
      && (focusNpc->IsAIState( parser->GetIndex( "ZS_Attack" ) ) || focusNpc->IsAIState( parser->GetIndex( "ZS_ReactToDamage" ) )) )
      return zCOLOR( 255, 180, 0 );

    if ( focusNpc->IsFriendly( player ) || focusNpc->npcType == 3 )
      return zCOLOR( 0, 255, 0 );
#endif

    //if ( focusNpc->IsNeutral( player ) ) 
    //  return colDefault;

    return colDefault;
  }

  zCOLOR FocusColor::ChestColor( oCMobContainer* focusContainer ) {

    oCMobLockable* focusLockable = focusContainer->CastTo<oCMobLockable>();

    if ( !focusLockable ) return colDefault;

    if ( focusLockable->locked && (focusLockable->keyInstance != "") )
      return zCOLOR( 255, 20, 20 );

    if ( focusLockable->locked )
      return zCOLOR( 255, 175, 0 );

    if ( focusContainer->containList.GetNumInList() )
      return zCOLOR( 0, 175, 0 );


    return zCOLOR( 175, 175, 175 );
  }

  zCOLOR FocusColor::DoorColor( oCMobDoor* focusDoor ) {

    oCMobLockable* focusLockable = focusDoor->CastTo<oCMobLockable>();

    if ( !focusLockable ) return colDefault;

    if ( focusLockable->locked && (focusLockable->keyInstance != "") )
      return zCOLOR( 255, 20, 20 );

    if ( focusLockable->locked )
      return zCOLOR( 255, 175, 0 );

    return colDefault;
  }

  zCOLOR FocusColor::CheckFocus() {
    zCVob* focusVob = player->GetFocusVob();

    if ( !focusVob ) return colDefault;

    if ( bColorChests )
      if ( oCMobContainer* focusContainer = focusVob->CastTo<oCMobContainer>() )
        return ChestColor( focusContainer );

    if ( bColorDoors )
      if ( oCMobDoor* focusDoor = focusVob->CastTo<oCMobDoor>() )
        return DoorColor( focusDoor );

    if ( bColorNpcs )
      if ( oCNpc* focusNpc = focusVob->CastTo<oCNpc>() )
        return NpcColor( focusNpc );

    return colDefault;
  }

  void FocusColor::FocusColorLoop() {
    if ( !bColorNpcs && !bColorChests && !bColorDoors ) return;

    screen->SetFontColor( CheckFocus() );
  }
}