// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  HOOK Ivk_Print_Union PATCH( &zCView::Print, &zCView::Print_Union );
  void zCView::Print_Union( int x, int y, const zSTRING& text ) {
    if ( focusColor.CanPrintFocus( this, x, y, text ) )
      return;

    THISCALL( Ivk_Print_Union )(x, y, text);
  }

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

  bool FocusColor::CanStealNow( oCItem* item ) {
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
      if ( npc->HasVobDetected( player ) && npc->GetAivar( "AIV_ITEMSCHWEIN" ) )
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
      if ( !item->owner && !item->ownerGuild )
        continue;
#endif

      return false;
    }

    return true;
  }

#if ENGINE >= Engine_G2
  bool FocusColor::CanTakeFromRoom( oCItem* item ) {
    oCPortalRoomManager* rooms = ogame->GetPortalRoomManager();

    if ( !rooms ) return true;

    const zSTRING* portalName = item->GetSectorNameVobIsIn();

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

  zCOLOR FocusColor::NpcColor( oCNpc* npc ) {
    if ( npc->attribute[NPC_ATR_HITPOINTS] <= 0 ) {
      if ( !npc->stealcontainer->contList.GetNumInList() )
        return zCOLOR( 175, 175, 175 );
      else
        return colDefault;
    }

    bool inAttack = npc->IsAIState( parser->GetIndex( "ZS_Attack" ) );
    bool inReact = npc->IsAIState( parser->GetIndex( "ZS_ReactToDamage" ) );

#if ENGINE >= Engine_G2
    if ( npc->IsHostile( player ) && npc->GetPermAttitude( player ) == NPC_ATT_HOSTILE
      || (npc->enemy == player && inAttack && HasReasonToKill( npc )) )
      return zCOLOR( 255, 0, 0 );

    if ( npc->IsAngry( player ) || (npc->enemy == player && inAttack) )
      return zCOLOR( 255, 180, 0 );

    int day, hour, min;
    ogame->GetTime( day, hour, min );

    if ( npc->GetAivar( "AIV_NpcSawPlayerCommit" )
      && !(npc->GetAivar( "AIV_NpcSawPlayerCommit" ) < CRIME_MURDER && npc->GetAivar( "AIV_NpcSawPlayerCommitDay" ) < day - 2)
      && !(npc->GetAivar( "AIV_CrimeAbsolutionLevel" ) < GetAbsolutionLevel( npc )) )
      return zCOLOR( 255, 180, 0 );
#else
    if ( (npc->IsHostile( player ) && npc->GetPermAttitude( player ) == NPC_ATT_HOSTILE)
      || (npc->enemy == player && inAttack && npc->GetAivar( "AIV_ATTACKREASON" )) )
      return zCOLOR( 255, 0, 0 );

    if ( (npc->IsAngry( player ) || npc->enemy == player) && (inAttack || inReact) )
      return zCOLOR( 255, 180, 0 );
#endif

    if ( inReact )
      return colDefault;

    if ( npc->GetAivar( "AIV_PARTYMEMBER" ) )
      return zCOLOR( 51, 235, 255 );

    if ( (npc->IsFriendly( player ) || npc->npcType == TYPE_FRIEND) )
      return zCOLOR( 0, 255, 0 );

    if ( ogame->GetGuilds()->GetAttitude( npc->guild, player->guild ) == NPC_ATT_FRIENDLY )
      return zCOLOR( 175, 255, 175 );

    return colDefault;
  }

  zCOLOR FocusColor::LockableColor( oCMobLockable* lockable ) {
    if ( lockable->locked )
      if ( lockable->keyInstance.Length() && lockable->pickLockStr.Length() )
        return zCOLOR( 255, 135, 150 );
      else if ( lockable->keyInstance.Length() )
        return zCOLOR( 255, 20, 20 );
      else if ( lockable->pickLockStr.Length() )
        return zCOLOR( 255, 175, 0 );
      else
        return zCOLOR( 175, 175, 175 );

    if ( oCMobContainer* container = lockable->CastTo<oCMobContainer>() )
      if ( container->containList.GetNumInList() )
        return zCOLOR( 30, 220, 30 );
      else
        return zCOLOR( 175, 175, 175 );

    return colDefault;
  }

  zCOLOR FocusColor::ItemColor( oCItem* item ) {
#if ENGINE >= Engine_G2
    if ( item->HasFlag( ITM_FLAG_DROPPED ) )
      return colDefault;
#endif

    if ( item->IsOwnedByNpc( player->GetInstance() ) )
      return colDefault;

    if ( item->IsOwnedByGuild( player->guild ) )
      return colDefault;

#if ENGINE >= Engine_G2
    if ( CanTakeFromRoom( item ) )
      return colDefault;
#endif

    if ( CanStealNow( item ) )
      return colDefault;

    return zCOLOR( 255, 200, 100 );
  }

  zCOLOR FocusColor::InterColor( oCMobInter* inter ) {
    if ( !inter->onStateFuncName.Length() )
      return colDefault;

    if ( inter->GetScemeName() != "BOOK" )
      return colDefault;

    if ( playerStatus.KnowStateFunc( inter ) )
      return colDefault;

    return zCOLOR( 30, 220, 30 );
  }

  zCOLOR FocusColor::GetFocusColor( zCVob* vob ) {
    if ( !TYPE_FRIEND || !CRIME_MURDER )
      InitData();

    if ( Options::ColorLockables )
      if ( oCMobLockable* lockable = vob->CastTo<oCMobLockable>() )
        return LockableColor( lockable );

    if ( Options::ColorNpcs )
      if ( oCNpc* npc = vob->CastTo<oCNpc>() )
        return NpcColor( npc );

    if ( Options::ColorItems )
      if ( oCItem* item = vob->CastTo<oCItem>() )
        return ItemColor( item );

    if ( Options::ColorInter )
      if ( oCMobInter* inter = vob->CastTo<oCMobInter>() )
        return InterColor( inter );

    return colDefault;
  }

  zSTRING FocusColor::GetName( zCVob* vob ) {
    if ( Options::ColorLockables )
      if ( oCMobLockable* lockable = vob->CastTo<oCMobLockable>() )
        return lockable->GetName();

    if ( Options::ColorNpcs )
      if ( oCNpc* npc = vob->CastTo<oCNpc>() )
        return npc->name[0];

    if ( Options::ColorItems )
      if ( oCItem* item = vob->CastTo<oCItem>() )
        return item->name;

    if ( Options::ColorInter )
      if ( oCMobInter* inter = vob->CastTo<oCMobInter>() )
        return inter->GetName();

    return "";
  }

  bool FocusColor::TryPrintFocus( int x, int y, zSTRING name, zCVob* vob ) {
    zCOLOR col = GetFocusColor( vob );
    if ( col.GetDescription() == colDefault.GetDescription() )
      col = screen->GetColor();

    if ( focusView == nullptr ) {
      focusView = new zCView( 0, 0, 8192, 8192 );
      screen->InsertItem( focusView );
    }
    else
      focusView->ClrPrintwin();

    if ( playerStatus.focusBar && playerStatus.focusBar->NeedAdjustPosition( x, y, vob->CastTo<oCNpc>() ) ) {
      x = ogame->focusBar->vposx + ogame->focusBar->vsizex / 2 - focusView->FontSize( name ) / 2;
      y = ogame->focusBar->vposy + ogame->focusBar->vsizey / 2 + focusView->FontY();
    }

    if ( ogame->hpBar )
      focusView->SetFontColor( zCOLOR( col.r, col.g, col.b, ogame->hpBar->alpha ) );
    else
      focusView->SetFontColor( col );

    focusView->Print( x, y, name );
    vobOnScreen = true;
    return true;
  }

  bool FocusColor::CanPrintFocus( zCView* view, int x, int y, const zSTRING& text ) {
    if ( !player || playerHelper.IsInInfo() || view == focusColor.focusView || focusColor.vobOnScreen )
      return false;

    zCVob* vob = player->GetFocusVob();
    if ( !vob ) return false;

    zSTRING name = GetName( vob );
    if ( text != name + "\n" && text != name )
      return false;

    return focusColor.TryPrintFocus( x, y, name, vob );
  }

  void FocusColor::Clear() {
    if ( focusView ) {
      focusView->ClrPrintwin();
      screen->RemoveItem( focusView );
      focusView = nullptr;
      vobOnScreen = false;
    }
  }

  void FocusColor::Loop() {
    if ( focusView )
      focusView->ClrPrintwin();

    vobOnScreen = false;

    zCVob* vob = player->GetFocusVob();
    if ( !vob || quickSave->IsBusy() || ogame->IsOnPause() ) {
      Clear();
      return;
    }
  }
}