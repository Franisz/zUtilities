// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  void DebugHelper::InfoNpc( oCNpc* npc ) {
    Print( textView, "Instance", npc->GetInstanceName() + " (" + Z npc->instanz + ")" );
    Print( textView, "Name", npc->GetName( 0 ) );
    Print( textView, "Guild", npc->GetGuildName() + " (" + Z npc->GetGuild() + ")" );
    Print( sideView, "Level", Z npc->level );
    AddSeparator();
    Print( textView, "HP", Z npc->GetAttribute( NPC_ATR_HITPOINTS ) + "/" + Z npc->GetAttribute( NPC_ATR_HITPOINTSMAX ) );
#if ENGINE >= Engine_G2
    Print( sideView, "1H", Z npc->GetHitChance( NPC_HITCHANCE_1H ) );
#else
    Print( sideView, "1H", Z npc->GetTalentValue( NPC_HITCHANCE_1H ) );
#endif
    Print( textView, "MANA", Z npc->GetAttribute( NPC_ATR_MANA ) + "/" + Z npc->GetAttribute( NPC_ATR_MANAMAX ) );
#if ENGINE >= Engine_G2
    Print( sideView, "2H", Z npc->GetHitChance( NPC_HITCHANCE_2H ) );
#else
    Print( sideView, "2H", Z npc->GetTalentValue( NPC_HITCHANCE_2H ) );
#endif
    Print( textView, "STR", Z npc->GetAttribute( NPC_ATR_STRENGTH ) );
#if ENGINE >= Engine_G2
    Print( sideView, "BOW", Z npc->GetHitChance( NPC_HITCHANCE_BOW ) );
#else
    Print( sideView, "BOW", Z npc->GetTalentValue( NPC_HITCHANCE_BOW ) );
#endif
    Print( textView, "DEX", Z npc->GetAttribute( NPC_ATR_DEXTERITY ) );
#if ENGINE >= Engine_G2
    Print( sideView, "CBOW", Z npc->GetHitChance( NPC_HITCHANCE_CROSSBOW ) );
#else
    Print( sideView, "CBOW", Z npc->GetTalentValue( NPC_HITCHANCE_CROSSBOW ) );
#endif
    AddSeparator();
    Print( textView, "PROT_EDGE", Z npc->GetProtectionByIndex( oEDamageIndex_Edge ) );
    Print( textView, "PROT_BLUNT", Z npc->GetProtectionByIndex( oEDamageIndex_Blunt ) );
    Print( textView, "PROT_POINT", Z npc->GetProtectionByIndex( oEDamageIndex_Point ) );
    Print( textView, "PROT_FIRE", Z npc->GetProtectionByIndex( oEDamageIndex_Fire ) );
    Print( textView, "PROT_MAGIC", Z npc->GetProtectionByIndex( oEDamageIndex_Magic ) );
    Print( textView, "PROT_FLY", Z npc->GetProtectionByIndex( oEDamageIndex_Fly ) );
    Print( textView, "PROT_FALL", Z npc->GetProtectionByIndex( oEDamageIndex_Fall ) );
    AddSeparator();
    Print( textView, "Waypoint", npc->wpname );
    Print( textView, "Flags", Z npc->variousFlags );
    Print( sideView, "NpcType", Z npc->npcType );
    Print( textView, "Attitude", Z npc->GetAttitude( player ) );
    Print( sideView, "PermAttitude", Z npc->GetPermAttitude( player ) );
    Print( textView, "SensesRange", Z npc->senses_range );
    Print( sideView, "DistToPlayer", Z( int )npc->GetDistanceToVob( *player ) );
    Print( textView, "DetectedPlayer", Z npc->HasVobDetected( player ) );
    Print( sideView, "Voice", Z npc->voice );
    Print( textView, "AIState", Z npc->GetAIState() );
    Print( sideView, "DailyRoutine", Z npc->daily_routine );
    Print( textView, "FightMode", Z npc->fmode );
    Print( sideView, "FightTactic", Z npc->fighttactic );
    if ( npc->enemy != nullptr )
      Print( textView, "Enemy", npc->enemy->GetInstanceName() );

    if ( zCVisual* visual = npc->GetVisual() ) {
      AddSeparator( "Visual" );
      Print( textView, "VisualFile", visual->GetVisualName() );
      Print( textView, "BodyName", npc->GetVisualBody() );
      Print( textView, "HeadName", npc->GetVisualHead() );
#if ENGINE == Engine_G2A
      Print( textView, "EffectName", npc->effect );
#endif
      if ( oCItem* armor = npc->GetEquippedArmor() ) {
        AddSeparator( "Armor" );
        Print( textView, "VisualFile", armor->GetVisual()->GetVisualName() );
        Print( textView, "VisualChange", armor->GetVisualChange() );
#if ENGINE == Engine_G2A
        Print( textView, "EffectName", armor->GetEffectName() );
#endif
      }
    }
  }

  void DebugHelper::InfoItem( oCItem* item ) {
    Print( textView, "Instance", item->GetInstanceName() + " (" + Z item->instanz + ")" );
    Print( textView, "Name", Z item->name );
    Print( textView, "Description", Z item->GetDescription() );
    Print( textView, "Value", Z item->GetValue() );

    if ( item->HasFlag( ITM_CAT_ARMOR ) || item->HasFlag( ITM_CAT_NF ) || item->HasFlag( ITM_CAT_FF ) ) {
      AddSeparator();
      Print( textView, "PROT_EDGE", Z item->GetProtectionByIndex( oEDamageIndex_Edge ) );
      Print( sideView, "DAM_EDGE", Z item->GetDamageByIndex( oEDamageIndex_Edge ) );
      Print( textView, "PROT_BLUNT", Z item->GetProtectionByIndex( oEDamageIndex_Blunt ) );
      Print( sideView, "DAM_BLUNT", Z item->GetDamageByIndex( oEDamageIndex_Blunt ) );
      Print( textView, "PROT_POINT", Z item->GetProtectionByIndex( oEDamageIndex_Point ) );
      Print( sideView, "DAM_POINT", Z item->GetDamageByIndex( oEDamageIndex_Point ) );
      Print( textView, "PROT_FIRE", Z item->GetProtectionByIndex( oEDamageIndex_Fire ) );
      Print( sideView, "DAM_FIRE", Z item->GetDamageByIndex( oEDamageIndex_Fire ) );
      Print( textView, "PROT_MAGIC", Z item->GetProtectionByIndex( oEDamageIndex_Magic ) );
      Print( sideView, "DAM_MAGIC", Z item->GetDamageByIndex( oEDamageIndex_Magic ) );
      Print( textView, "PROT_FLY", Z item->GetProtectionByIndex( oEDamageIndex_Fly ) );
      Print( sideView, "DAM_FLY", Z item->GetDamageByIndex( oEDamageIndex_Fly ) );
      Print( textView, "PROT_FALL", Z item->GetProtectionByIndex( oEDamageIndex_Fall ) );
      Print( sideView, "DAM_FALL", Z item->GetDamageByIndex( oEDamageIndex_Fall ) );
      Print( textView, "TotalDamage", Z item->damageTotal );
    }
    else if ( item->spell ) {
      AddSeparator( "Spell" );
      Print( textView, "SpellID", Z item->spell );
      Print( sideView, "Circle", Z item->mag_circle );

      oCSpell* spl = new oCSpell( item->spell );
      Print( textView, "SpellName", spl->GetName() );
      spl->Release();
    }
    else
      AddSeparator();

    for ( int i = 0; i < ITM_COND_MAX; i++ ) {
      if ( !item->cond_atr[i] ) continue;
      Print( textView, "Cond" + Z i, Z item->cond_atr[i] + " (" + Z item->cond_value[i] + ")" );
    }

    Print( textView, "Mainflag", Z item->mainflag );
    Print( sideView, "Flags", Z item->flags );
    Print( textView, "Owner", Z item->owner );
    if ( item->ownerGuild )
      Print( textView, "OwnerGuild", ogame->GetGuilds()->GetGuildName( item->ownerGuild ) + " (" + Z item->ownerGuild + ")" );
    Print( textView, "SchemeName", Z item->GetSchemeName() );
    Print( sideView, "Material", Z item->GetSoundMaterial() );

    for ( int i = 0; i < ITM_STATE_MAX; i++ ) {
      if ( !item->onState[i] ) continue;
      Print( textView, "onState", Z item->onState[i] );
      break;
    }

    if ( zCVisual* visual = item->GetVisual() ) {
      AddSeparator( "Visual" );
      Print( textView, "VisualFile", visual->GetVisualName() );
      Print( textView, "VisualChange", item->GetVisualChange() );
#if ENGINE == Engine_G2A
      Print( textView, "EffectName", item->GetEffectName() );
#endif
    }
  }

  void DebugHelper::InfoMob( oCMOB* mob ) {
    Print( textView, "MobName", mob->name );
    Print( textView, "Name", mob->GetName() );
    Print( textView, "Owner", mob->ownerStr );
    Print( textView, "ScemeName", mob->GetScemeName() );

    if ( oCMobInter* inter = mob->CastTo<oCMobInter>() ) {
      AddSeparator( "Inter" );
      Print( textView, "UseItem", inter->useWithItem );
      Print( textView, "ConditionFuncName", inter->conditionFunc );
      Print( textView, "OnStateFuncName", inter->onStateFuncName );
    }

    if ( oCMobLockable* lockable = mob->CastTo<oCMobLockable>() ) {
      AddSeparator( "Lockable" );
      Print( textView, "KeyInstance", lockable->keyInstance );
      Print( textView, "LockString", lockable->pickLockStr );
      Print( textView, "Locked", Z lockable->locked );
    }

    if ( oCMobContainer* container = mob->CastTo<oCMobContainer>() )
      if ( auto list = container->containList.GetNextInList() ) {
        int itemCount = container->containList.GetNumInList();
        int printedItems = 0;

        AddSeparator( "Container" );
        while ( list != nullptr ) {
          Print( textView, list->GetData()->name, Z list->GetData()->amount );

          printedItems++;
          if ( itemCount > 5 && printedItems >= 5 ) {
            Print( textView, "", "And " + Z( itemCount - printedItems ) + " more..." );
            break;
          }

          list = list->GetNextInList();
        }
      }

    if ( zCVisual* visual = mob->GetVisual() ) {
      AddSeparator( "Visual" );
      Print( textView, "VisualFile", visual->GetVisualName() );
    }
  }

  void DebugHelper::AddSeparator( zSTRING str ) {
    if ( textLines > 0 )
      textLines++;

    if ( !str.Length() )
      return;

    textLines++;
    textView->Print( 0, textHeight * textLines, "--- " + str );
  }

  void DebugHelper::Print( zCView* view, zSTRING name, zSTRING value ) {
    if ( !value.Length() )
      value = "-";

    zSTRING text = (name.Length()) ? name + ": " + value : value;

    if ( view == textView )
      textLines++;

    view->Print( 0, textHeight * textLines, text );
  }

  bool DebugHelper::TryPrintInfo() {
    if ( player->inventory2.IsOpen() )
      if ( oCItem* item = player->inventory2.GetSelectedItem() ) {
        AddSeparator( item->_GetClassDef()->className );
        InfoItem( item );
        return true;
      }

    zCVob* vob = player->GetFocusVob();
    if ( !vob )
      return false;

    AddSeparator( vob->_GetClassDef()->className );

    if ( oCNpc* npc = vob->CastTo<oCNpc>() )
      InfoNpc( npc );
    else if ( oCItem* item = vob->CastTo<oCItem>() )
      InfoItem( item );
    else if ( oCMOB* mob = vob->CastTo<oCMOB>() )
      InfoMob( mob );

    return true;
  }

  void DebugHelper::Clear() {
    if ( mainView == nullptr ) return;

    mainView->RemoveItem( textView );
    mainView->RemoveItem( sideView );
    screen->RemoveItem( mainView );
    textView = nullptr;
    sideView = nullptr;
    mainView = nullptr;
  }

  void DebugHelper::Loop() {
    if ( !Options::UsingDebugHelper
      || ogame->pause_screen
      || zcon->IsVisible()
      || (edit_con && edit_con->IsVisible())
      || quickSave->isSaving
      || player->inventory2.GetNextContainerLeft( &player->inventory2 ) ) {
      Clear();
      return;
    }

    if ( mainView == nullptr ) {
      float sysScale;
      Union.GetSysPackOption().Read( sysScale, "INTERFACE", "Scale", 1.0f );
      int scaleBonus = 512 * sysScale;

      mainView = new zCView( 0, 1024 - scaleBonus, 2304 + scaleBonus, 7168 + scaleBonus );
      mainView->InsertBack( "BLACKBACK" );
      mainView->SetAlphaBlendFunc( zRND_ALPHA_FUNC_BLEND );
      mainView->SetTransparency( 150 );
      screen->InsertItem( mainView );

      textHeight = mainView->FontY();
      margin = textHeight;

      textView = new zCView( margin, 0, 8192 - margin, 8192 );
      sideView = new zCView( margin + 8192 * 0.6f, 0, 8192 - margin, 8192 );
      mainView->InsertItem( textView );
      mainView->InsertItem( sideView );
    }

    textView->ClrPrintwin();
    sideView->ClrPrintwin();
    textLines = 0;

    if ( TryPrintInfo() )
      return;

    Clear();
  }
}