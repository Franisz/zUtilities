// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

#if ENGINE >= Engine_G2
  int getAbsolutionLevel( oCNpc* slf ) {
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

  bool npcColor() {
    oCNpc* focusNpc = player->GetFocusNpc();

    if ( !focusNpc ) return false;

    if ( focusNpc->attribute[NPC_ATR_HITPOINTS] <= 0 ) {
      if ( !focusNpc->stealcontainer->contList.GetNumInList() )
        screen->SetFontColor( zCOLOR( 175, 175, 175 ) );
      else
        screen->SetFontColor( zCOLOR( 255, 255, 255 ) );
      return true;
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
      screen->SetFontColor( zCOLOR( 255, 0, 0 ) );
      return true;
    }

    if ( focusNpc->IsAngry( player ) || (focusNpc->enemy == player && focusNpc->IsAIState( parser->GetIndex( "ZS_Attack" ) )) ) {
      screen->SetFontColor( zCOLOR( 255, 180, 0 ) );
      return true;
    }

    int day, hour, min;
    ogame->GetTime( day, hour, min );

    if ( focusNpc->aiscriptvars[1] != 0
      && !(focusNpc->aiscriptvars[1] <= 3 && focusNpc->aiscriptvars[2] < day - 2)
      && !(focusNpc->aiscriptvars[46] < getAbsolutionLevel( focusNpc )) ) {
      screen->SetFontColor( zCOLOR( 255, 180, 0 ) );
      return true;
    }

    if ( (focusNpc->IsFriendly( player ) || focusNpc->npcType == 2) && !focusNpc->IsAIState( parser->GetIndex( "ZS_ReactToDamage" ) ) ) {
      screen->SetFontColor( zCOLOR( 0, 255, 0 ) );
      return true;
    }
#else
    if ( (focusNpc->IsHostile( player ) && focusNpc->GetPermAttitude( player ) == NPC_ATT_HOSTILE)
      || (focusNpc->enemy == player && focusNpc->aiscriptvars[35] && focusNpc->IsAIState( parser->GetIndex( "ZS_Attack" ) )) ) {
      screen->SetFontColor( zCOLOR( 255, 0, 0 ) );
      return true;
    }

    if ( (focusNpc->IsAngry( player ) || focusNpc->enemy == player)
      && (focusNpc->IsAIState( parser->GetIndex( "ZS_Attack" ) ) || focusNpc->IsAIState( parser->GetIndex( "ZS_ReactToDamage" ) )) ) {
      screen->SetFontColor( zCOLOR( 255, 180, 0 ) );
      return true;
    }

    if ( focusNpc->IsFriendly( player ) || focusNpc->npcType == 3 ) {
      screen->SetFontColor( zCOLOR( 0, 255, 0 ) );
      return true;
    }
#endif

    if ( focusNpc->IsNeutral( player ) ) {
      screen->SetFontColor( zCOLOR( 255, 255, 255 ) );
      return true;
    }

    return false;
  }

  bool chestColor() {
    zCVob* focusVob = player->GetFocusVob();

    if ( !focusVob ) return false;

    oCMobLockable* focusLockable = focusVob->CastTo<oCMobLockable>();
    oCMobContainer* focusContainer = focusVob->CastTo<oCMobContainer>();

    if ( !focusLockable || !focusContainer ) return false;

    if ( focusLockable->locked && (focusLockable->keyInstance != "") ) {
      screen->SetFontColor( zCOLOR( 255, 20, 20 ) );
      return true;
    }

    if ( focusLockable->locked ) {
      screen->SetFontColor( zCOLOR( 255, 175, 0 ) );
      return true;
    }

    if ( focusContainer->containList.GetNumInList() ) {
      screen->SetFontColor( zCOLOR( 0, 175, 0 ) );
      return true;
    }

    screen->SetFontColor( zCOLOR( 175, 175, 175 ) );
    return true;
  }

  bool doorColor() {
    zCVob* focusVob = player->GetFocusVob();

    if ( !focusVob ) return false;

    oCMobLockable* focusLockable = focusVob->CastTo<oCMobLockable>();
    oCMobDoor* focusDoor = focusVob->CastTo<oCMobDoor>();

    if ( !focusLockable || !focusDoor ) return false;

    if ( focusLockable->locked && (focusLockable->keyInstance != "") ) {
      screen->SetFontColor( zCOLOR( 255, 20, 20 ) );
      return true;
    }

    if ( focusLockable->locked ) {
      screen->SetFontColor( zCOLOR( 255, 175, 0 ) );
      return true;
    }

    screen->SetFontColor( zCOLOR( 255, 255, 255 ) );
    return true;
  }

  void updateFocusColor() {
    if ( !bColorNpcs && !bColorChests && !bColorDoors ) return;

    if ( npcColor() && bColorNpcs ) return;

    if ( chestColor() && bColorChests ) return;

    if ( doorColor() && bColorDoors ) return;

    screen->SetFontColor( zCOLOR( 255, 255, 255 ) );
  }
}