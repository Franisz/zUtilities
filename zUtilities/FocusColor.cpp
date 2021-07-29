// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

  bool FocusColor::CanTakeFromRoom( oCItem* focusItem ) {
    oCPortalRoomManager* rooms = ogame->GetPortalRoomManager();

    if ( !rooms ) return TRUE;

    const zSTRING* portalName = focusItem->GetSectorNameVobIsIn();

    if ( !portalName ) return TRUE;

    int portalIndex = rooms->GetPortalRoomIndex( *portalName );

    if ( portalIndex == Invalid ) return TRUE;

    oCPortalRoom* portalRoom = rooms->portals[portalIndex];

    if ( !portalRoom ) return TRUE;

    int roomGuild = portalRoom->GetOwnerGuild();

    if ( !roomGuild ) return TRUE;

    int att = ogame->GetGuilds()->GetAttitude( roomGuild, player->guild );

    if ( att == NPC_ATT_FRIENDLY ) return TRUE;

    return FALSE;
  }

#if ENGINE >= Engine_G2
  int FocusColor::GetAbsolutionLevel( oCNpc* slf ) {
    zCPar_Symbol* sym = nullptr;

    if ( (slf->npcType == 3 || slf->npcType == 4) && (slf->guild == 1 || slf->guild == 2 || slf->guild == 3) )
      if ( sym = parser->GetSymbol( "ABSOLUTIONLEVEL_OldCamp" ) )
        return sym->single_intdata;

    if ( slf->guild == 1 || slf->guild == 2 || slf->guild == 3 )
      if ( sym = parser->GetSymbol( "ABSOLUTIONLEVEL_City" ) )
        return sym->single_intdata;

    if ( slf->guild == 4 || slf->guild == 5 )
      if ( sym = parser->GetSymbol( "ABSOLUTIONLEVEL_Monastery" ) )
        return sym->single_intdata;

    if ( slf->guild == 7 || slf->guild == 8 )
      if ( sym = parser->GetSymbol( "ABSOLUTIONLEVEL_Monastery" ) )
        return sym->single_intdata;

    if ( slf->npcType == 5 || slf->npcType == 7 )
      if ( sym = parser->GetSymbol( "ABSOLUTIONLEVEL_BL" ) )
        return sym->single_intdata;

    return 0;
  }

  bool FocusColor::HasReasonToKill( oCNpc* slf ) {
    if ( slf->aiscriptvars[1] == 4 ) return TRUE;
    if ( slf->aiscriptvars[9] == 13 ) return TRUE;
    if ( slf->aiscriptvars[9] == 14 ) return TRUE;
    if ( slf->aiscriptvars[9] == 15 ) return TRUE;
    if ( slf->aiscriptvars[9] == 17 ) return TRUE;
    if ( slf->aiscriptvars[9] == 18 ) return TRUE;
    if ( slf->aiscriptvars[9] == 19 ) return TRUE;
    if ( slf->aiscriptvars[52] == 1 ) return TRUE;

    return FALSE;
  }
#endif

  zCOLOR FocusColor::NpcColor( oCNpc* focusNpc ) {

    if ( focusNpc->attribute[NPC_ATR_HITPOINTS] <= 0 ) {
      if ( !focusNpc->stealcontainer->contList.GetNumInList() )
        return zCOLOR( 175, 175, 175 );
      else
        return colDefault;
    }

    bool attacking = focusNpc->IsAIState( parser->GetIndex( "ZS_Attack" ) );
    bool reacting = focusNpc->IsAIState( parser->GetIndex( "ZS_ReactToDamage" ) );

#if ENGINE >= Engine_G2
    if ( focusNpc->IsHostile( player ) && focusNpc->GetPermAttitude( player ) == NPC_ATT_HOSTILE
      || (focusNpc->enemy == player && attacking && HasReasonToKill( focusNpc )) )
      return zCOLOR( 255, 0, 0 );

    if ( focusNpc->IsAngry( player ) || (focusNpc->enemy == player && attacking) )
      return zCOLOR( 255, 180, 0 );

    int day, hour, min;
    ogame->GetTime( day, hour, min );

    if ( focusNpc->aiscriptvars[1] != 0
      && !(focusNpc->aiscriptvars[1] <= 3 && focusNpc->aiscriptvars[2] < day - 2)
      && !(focusNpc->aiscriptvars[46] < GetAbsolutionLevel( focusNpc )) )
      return zCOLOR( 255, 180, 0 );

    if ( (focusNpc->IsFriendly( player ) || focusNpc->npcType == 2) && !reacting )
      return zCOLOR( 0, 255, 0 );
#else
    if ( (focusNpc->IsHostile( player ) && focusNpc->GetPermAttitude( player ) == NPC_ATT_HOSTILE)
      || (focusNpc->enemy == player && attacking && focusNpc->aiscriptvars[35]) )
      return zCOLOR( 255, 0, 0 );

    if ( (focusNpc->IsAngry( player ) || focusNpc->enemy == player) && (attacking || reacting) )
      return zCOLOR( 255, 180, 0 );

    if ( focusNpc->IsFriendly( player ) || focusNpc->npcType == 3 )
      return zCOLOR( 0, 255, 0 );
#endif

    if ( ogame->GetGuilds()->GetAttitude( focusNpc->guild, player->guild ) == NPC_ATT_FRIENDLY && !reacting )
      return zCOLOR( 175, 255, 175 );

    return colDefault;
  }

  zCOLOR FocusColor::ChestColor( oCMobContainer* focusContainer ) {
    if ( focusContainer->locked )
      if ( focusContainer->keyInstance != "" )
        return zCOLOR( 255, 20, 20 );
      else
        return zCOLOR( 255, 175, 0 );

    if ( focusContainer->containList.GetNumInList() )
      return zCOLOR( 0, 175, 0 );

    return zCOLOR( 175, 175, 175 );
  }

  zCOLOR FocusColor::DoorColor( oCMobDoor* focusDoor ) {
    if ( focusDoor->locked )
      if ( focusDoor->keyInstance != "" )
        return zCOLOR( 255, 20, 20 );
      else
        return zCOLOR( 255, 175, 0 );

    return colDefault;
  }

  zCOLOR FocusColor::ItemColor( oCItem* focusItem ) {
#if ENGINE >= Engine_G2
    if ( focusItem->HasFlag( ITM_FLAG_DROPPED ) )
      return colDefault;
#endif

    if ( focusItem->IsOwnedByNpc( player->GetInstance() ) )
      return colDefault;

    if ( focusItem->IsOwnedByGuild( player->guild ) )
      return colDefault;

    // If room has GIL_PUBLIC this doesn't really matter
    if ( CanTakeFromRoom( focusItem ) )
      return colDefault;

    return zCOLOR( 255, 200, 100 );
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

    if ( bColorItems )
      if ( oCItem* focusItem = focusVob->CastTo<oCItem>() )
        return ItemColor( focusItem );

    return colDefault;
  }

  void FocusColor::FocusColorLoop() {
    if ( !bColorNpcs && !bColorChests && !bColorDoors && !bColorItems )
      return;

    screen->SetFontColor( CheckFocus() );
  }
}