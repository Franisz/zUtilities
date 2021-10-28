// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  int oCNpc::GetAivar( zSTRING aivar ) {
    auto sym = parser->GetSymbol( aivar );
    if ( !sym )
      return 0;

    return this->aiscriptvars[sym->single_intdata];
  }

  void FocusColor::InitData() {
    zCPar_Symbol* sym = nullptr;

    sym = parser->GetSymbol( "NPCTYPE_FRIEND" );
    TYPE_FRIEND = (sym) ? sym->single_intdata : Invalid;

    sym = parser->GetSymbol( "CRIME_MURDER" );
    CRIME_MURDER = (sym) ? sym->single_intdata : Invalid;
  }

  bool FocusColor::CanStealNow( oCItem* focusItem ) {
    int ZS_Clear = parser->GetIndex( "ZS_ClearRoom" );

#if ENGINE >= Engine_G2
    int ZS_Observe = parser->GetIndex( "ZS_ObservePlayer" );
#else
    int ZS_Observe = parser->GetIndex( "ZS_ObservePerson" );
#endif

    if ( !ZS_Observe || !ZS_Clear )
      return false;

    auto list = ogame->GetGameWorld()->voblist_npcs->GetNextInList();

    while ( list != nullptr ) {
      oCNpc* npc = list->GetData();
      list = list->GetNextInList();

      if ( npc->attribute[NPC_ATR_HITPOINTS] <= 0 || npc == player ) continue;

      if ( !npc->HasPerception( NPC_PERC_ASSESSTHEFT ) )
        continue;

      if ( !npc->IsInPerceptionRange( NPC_PERC_ASSESSTHEFT, (int)npc->GetDistanceToVob( *player ) ) )
        continue;

#if ENGINE < Engine_G2
      if ( npc->GetAivar( "AIV_ITEMSCHWEIN" ) && npc->HasVobDetected( player ) )
        return false;
#endif

      if ( ogame->GetGuilds()->GetAttitude( npc->guild, player->guild ) == NPC_ATT_FRIENDLY ) continue;
      if ( npc->IsFriendly( player ) || npc->npcType == TYPE_FRIEND ) continue;

      if ( !npc->HasVobDetected( player ) ) {
        if ( npc->IsAIState( ZS_Clear ) || npc->IsAIState( ZS_Observe ) )
          return false;

        continue;
      }

#if ENGINE < Engine_G2
      if ( !focusItem->owner && !focusItem->ownerGuild )
        continue;
#endif

      return false;
    }

    return true;
  }

#if ENGINE >= Engine_G2
  bool FocusColor::CanTakeFromRoom( oCItem* focusItem ) {
    oCPortalRoomManager* rooms = ogame->GetPortalRoomManager();

    if ( !rooms ) return true;

    const zSTRING* portalName = focusItem->GetSectorNameVobIsIn();

    if ( !portalName ) return true;

    int portalIndex = rooms->GetPortalRoomIndex( *portalName );

    if ( portalIndex == Invalid ) return true;

    oCPortalRoom* portalRoom = rooms->portals[portalIndex];

    if ( !portalRoom ) return true;

    int roomGuild = portalRoom->GetOwnerGuild();

    if ( !roomGuild ) return true;

    int att = ogame->GetGuilds()->GetAttitude( roomGuild, player->guild );

    if ( att == NPC_ATT_FRIENDLY ) return true;

    return false;
  }

  int FocusColor::GetAbsolutionLevel( oCNpc* slf ) {
    zCPar_Symbol* sym = nullptr;

    sym = parser->GetSymbol( "NPCTYPE_OCAMBIENT" );
    int TYPE_OCAMBIENT = (sym) ? sym->single_intdata : Invalid;

    sym = parser->GetSymbol( "NPCTYPE_OCMAIN" );
    int TYPE_OCMAIN = (sym) ? sym->single_intdata : Invalid;

    sym = parser->GetSymbol( "NPCTYPE_BL_AMBIENT" );
    int TYPE_BL_AMBIENT = (sym) ? sym->single_intdata : Invalid;

    sym = parser->GetSymbol( "NPCTYPE_BL_MAIN" );
    int TYPE_BL_MAIN = (sym) ? sym->single_intdata : Invalid;

    if ( (TYPE_OCAMBIENT && slf->npcType == TYPE_OCAMBIENT) || (TYPE_OCMAIN && slf->npcType == TYPE_OCMAIN) ) {
      if ( slf->guild == NPC_GIL_PALADIN || slf->guild == NPC_GIL_MILIZ || slf->guild == NPC_GIL_VOLK )
        if ( sym = parser->GetSymbol( "ABSOLUTIONLEVEL_OldCamp" ) )
          return sym->single_intdata;
    }
    else if ( slf->guild == NPC_GIL_PALADIN || slf->guild == NPC_GIL_MILIZ || slf->guild == NPC_GIL_VOLK ) {
      if ( sym = parser->GetSymbol( "ABSOLUTIONLEVEL_City" ) )
        return sym->single_intdata;
    }
    else if ( slf->guild == NPC_GIL_FEUERKREIS || slf->guild == NPC_GIL_NOVIZE ) {
      if ( sym = parser->GetSymbol( "ABSOLUTIONLEVEL_Monastery" ) )
        return sym->single_intdata;
    }
    else if ( slf->guild == NPC_GIL_BAUERN ) {
      if ( sym = parser->GetSymbol( "ABSOLUTIONLEVEL_Farm" ) )
        return sym->single_intdata;
    }
    else if ( (TYPE_BL_AMBIENT && slf->npcType == TYPE_BL_AMBIENT) || (TYPE_BL_MAIN && slf->npcType == TYPE_BL_MAIN) ) {
      if ( sym = parser->GetSymbol( "ABSOLUTIONLEVEL_BL" ) )
        return sym->single_intdata;
    }

    return 0;
  }

  bool FocusColor::HasReasonToKill( oCNpc* slf ) {
    if ( slf->GetAivar( "AIV_NpcSawPlayerCommit" ) == CRIME_MURDER ) return true;
    int AttackReason = slf->GetAivar( "AIV_ATTACKREASON" );
    if ( AttackReason == 13 ) return true;
    if ( AttackReason == 14 ) return true;
    if ( AttackReason == 15 ) return true;
    if ( AttackReason == 17 ) return true;
    if ( AttackReason == 18 ) return true;
    if ( AttackReason == 19 ) return true;
    if ( slf->GetAivar( "AIV_DropDeadAndKill" ) ) return true;

    return false;
  }
#endif

  zCOLOR FocusColor::NpcColor( oCNpc* focusNpc ) {
    if ( focusNpc->attribute[NPC_ATR_HITPOINTS] <= 0 ) {
      if ( !focusNpc->stealcontainer->contList.GetNumInList() )
        return zCOLOR( 175, 175, 175 );
      else
        return colDefault;
    }

    bool inAttack = focusNpc->IsAIState( parser->GetIndex( "ZS_Attack" ) );
    bool inReact = focusNpc->IsAIState( parser->GetIndex( "ZS_ReactToDamage" ) );

#if ENGINE >= Engine_G2
    if ( focusNpc->IsHostile( player ) && focusNpc->GetPermAttitude( player ) == NPC_ATT_HOSTILE
      || (focusNpc->enemy == player && inAttack && HasReasonToKill( focusNpc )) )
      return zCOLOR( 255, 0, 0 );

    if ( focusNpc->IsAngry( player ) || (focusNpc->enemy == player && inAttack) )
      return zCOLOR( 255, 180, 0 );

    int day, hour, min;
    ogame->GetTime( day, hour, min );

    if ( focusNpc->GetAivar( "AIV_NpcSawPlayerCommit" )
      && !(focusNpc->GetAivar( "AIV_NpcSawPlayerCommit" ) < CRIME_MURDER && focusNpc->GetAivar( "AIV_NpcSawPlayerCommitDay" ) < day - 2)
      && !(focusNpc->GetAivar( "AIV_CrimeAbsolutionLevel" ) < GetAbsolutionLevel( focusNpc )) )
      return zCOLOR( 255, 180, 0 );

    if ( (focusNpc->IsFriendly( player ) || focusNpc->npcType == TYPE_FRIEND) && !inReact )
      return zCOLOR( 0, 255, 0 );
#else
    if ( (focusNpc->IsHostile( player ) && focusNpc->GetPermAttitude( player ) == NPC_ATT_HOSTILE)
      || (focusNpc->enemy == player && inAttack && focusNpc->GetAivar( "AIV_ATTACKREASON" )) )
      return zCOLOR( 255, 0, 0 );

    if ( (focusNpc->IsAngry( player ) || focusNpc->enemy == player) && (inAttack || inReact) )
      return zCOLOR( 255, 180, 0 );

    if ( focusNpc->IsFriendly( player ) || focusNpc->npcType == TYPE_FRIEND )
      return zCOLOR( 0, 255, 0 );
#endif

    if ( ogame->GetGuilds()->GetAttitude( focusNpc->guild, player->guild ) == NPC_ATT_FRIENDLY && !inReact )
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

#if ENGINE >= Engine_G2
    if ( CanTakeFromRoom( focusItem ) )
      return colDefault;
#endif

    if ( CanStealNow( focusItem ) )
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

    InitData();

    screen->SetFontColor( CheckFocus() );
  }
}