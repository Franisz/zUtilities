// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
#if ENGINE >= Engine_G2
  std::vector<oCVisualFX*> vfxs;
  HOOK Ivk_InitEffect_Union PATCH( &oCVisualFX::InitEffect, &oCVisualFX::InitEffect_Union );
  void oCVisualFX::InitEffect_Union() {

    if ( visName_S.Search( ".SLW", 1 ) == -1 )
    {
      THISCALL( Ivk_InitEffect_Union )();
      return;
    }
    
    vfxs.push_back( this );
    playerStatus.ResetTimeMultiplier();

    THISCALL( Ivk_InitEffect_Union )();
  }

  HOOK Ivk_EndEffect_Union PATCH(&oCVisualFX::EndEffect, &oCVisualFX::EndEffect_Union);
  void oCVisualFX::EndEffect_Union( const int kill ) {
    if ( visName_S.Search( ".SLW", 1 ) == -1 )
    {
      THISCALL( Ivk_EndEffect_Union )( kill );
      return;
    }

    auto it = std::find( vfxs.begin(), vfxs.end(), this );
    if (it != vfxs.end())
    {
      vfxs.erase( std::remove( vfxs.begin(), vfxs.end(), this ), vfxs.end() );
    }

    THISCALL( Ivk_EndEffect_Union )( kill );
  }
#endif

  bool PlayerStatus::CanChangeZtimer()
  {
#if ENGINE >= Engine_G2
    return vfxs.empty();
#endif
    return true;
  }


  HOOK Ivk_CallOnStateFunc_Union PATCH( &oCMobInter::CallOnStateFunc, &oCMobInter::CallOnStateFunc_Union );
  void oCMobInter::CallOnStateFunc_Union( oCNpc* npc, int a1 ) {
    THISCALL( Ivk_CallOnStateFunc_Union )(npc, a1);

    if ( npc == player )
      playerStatus.TryAddStateFunc( this );
  }

  HOOK Ivk_GetStateEffectFunc_Union PATCH( &oCItem::GetStateEffectFunc, &oCItem::GetStateEffectFunc_Union );
  int oCItem::GetStateEffectFunc_Union( int a1 ) {
    int result = THISCALL( Ivk_GetStateEffectFunc_Union )(a1);
    playerStatus.stateFuncItem = (a1 == 0) ? this : nullptr;
    return result;
  }

  HOOK Ivk_EV_UseItemToState_Union PATCH( &oCNpc::EV_UseItemToState, &oCNpc::EV_UseItemToState_Union );
  int oCNpc::EV_UseItemToState_Union( oCMsgManipulate* msg ) {
    int result = THISCALL( Ivk_EV_UseItemToState_Union )(msg);

    if ( this == player && msg && msg->targetVob && playerStatus.stateFuncItem && playerStatus.stateFuncItem == msg->targetVob ) {
      playerStatus.TryAddStateFunc( msg->targetVob );
      playerStatus.stateFuncItem = nullptr;
    }

    return result;
  }

  void PlayerStatus::GetPickpocketInfos() {
    auto list = ogame->GetInfoManager()->infoList.next;
    while ( list ) {
      auto info = list->data;
      list = list->next;

      // Whenever the icon will visible or not is based on the npc dialogue including PICKPOCKET word which seems to be used consistently in mods as well.
      if ( !info->name.HasWordI( "pickpocket" ) && !info->name.HasWordI( "_steal" ) && !info->name.HasWordI( "pickme" ) )
        continue;      
      
      if ( info->name.HasWordI( "_DOIT" ) || info->name.HasWordI( "_TRY" ) )
        continue;

      // To avoid targeting possible dialogues related to pickpocketing quests or teach options.
      if ( parser->GetIndex( info->name + "_DOIT" ) == Invalid && parser->GetIndex( info->name + "_TRY" ) == Invalid )
        continue;

      if ( !pickpocketInfos.IsInList( info ) )
        pickpocketInfos.Insert( info );
    }
  }

  bool PlayerStatus::CanPickpocketNpc( oCNpc* npc ) {
    //auto sym = parser->GetSymbol( "NPC_TALENT_PICKPOCKET" );
    //if ( !sym )
    //  return false;

    //if ( !player->GetTalentSkill( sym->single_intdata ) )
    //  return false;

    //if ( npc->GetAivar( "AIV_PLAYERHASPICKEDMYPOCKET" ) )
    //  return false;

    if ( npc->attribute[NPC_ATR_HITPOINTS] <= 0 )
      return false;

    for ( int i = 0; i < pickpocketInfos.GetNumInList(); i++ ) {
      auto info = pickpocketInfos[i];

      if ( info->GetNpcID() != npc->GetInstance() )
        continue;

      parser->SetInstance( "SELF", npc );
      parser->SetInstance( "OTHER", player );

      return info->InfoConditions();
    }

    return false;
  }

  bool PlayerStatus::KnowStateFunc( zCVob* vob ) {
    if ( !vob )
      return false;

    if ( oCItem* item = vob->CastTo<oCItem>() ) {
      if ( stateFuncItems.IsInList( item->GetInstanceName() ) )
        return true;

      int index = item->GetStateFunc();
      if ( index == Invalid )
        return true;

      for ( int i = 0; i < interStateFuncs.GetNumInList(); i++ ) {
        int idx = parser->GetIndex( interStateFuncs[i] + "_s1" );
        if ( idx == index )
          return true;
      }
    }
    else if ( oCMobInter* inter = vob->CastTo<oCMobInter>() ) {
      if ( interStateFuncs.IsInList( inter->onStateFuncName ) )
        return true;

      int index = parser->GetIndex( inter->onStateFuncName + "_s1" );
      if ( index == Invalid )
        return true;

      for ( int i = 0; i < stateFuncItems.GetNumInList(); i++ ) {
        oCItem* itm = new oCItem( stateFuncItems[i], 1 );
        if ( !itm ) continue;
        int idx = itm->GetStateFunc();
        itm->Release();
        if ( idx == index )
          return true;
      }
    }

    return false;
  }

  void PlayerStatus::TryAddStateFunc( zCVob* vob ) {
    if ( !vob )
      return;

    if ( KnowStateFunc( vob ) )
      return;

    if ( oCItem* item = vob->CastTo<oCItem>() )
      stateFuncItems.Insert( item->GetInstanceName() );
    else if ( oCMobInter* inter = vob->CastTo<oCMobInter>() )
      interStateFuncs.Insert( inter->onStateFuncName );
  }

  void PlayerStatus::Archive( zCArchiver* ar ) {
    ar->WriteInt( "interStateFuncsCount", interStateFuncs.GetNum() );
    for ( int i = 0; i < interStateFuncs.GetNum(); i++ )
      ar->WriteString( "interStateFuncs", interStateFuncs[i] );

    ar->WriteInt( "stateFuncItemsCount", stateFuncItems.GetNum() );
    for ( int i = 0; i < stateFuncItems.GetNum(); i++ )
      ar->WriteString( "stateFuncItems", stateFuncItems[i] );
  }

  void PlayerStatus::Unarchive( zCArchiver* ar ) {
    interStateFuncs.EmptyList();
    stateFuncItems.EmptyList();

    if ( !ar )
      return;

    int interStateFuncsCount = ar->ReadIntSafe( "interStateFuncsCount" );
    for ( int i = 0; i < interStateFuncsCount; i++ )
      interStateFuncs.Insert( ar->ReadString( "interStateFuncs" ) );

    int stateFuncItemsCount = ar->ReadIntSafe( "stateFuncItemsCount" );
    for ( int i = 0; i < stateFuncItemsCount; i++ )
      stateFuncItems.Insert( ar->ReadString( "stateFuncItems" ) );
  }

#if ENGINE < Engine_G2
  HOOK Hook_zCAICamera_CheckKeys PATCH( &zCAICamera::CheckKeys, &zCAICamera::CheckKeys_Union );
  void zCAICamera::CheckKeys_Union() {
    if ( !Options::UseTimeMultiplier || ztimer->factorMotion == 1.0f || !playerStatus.CanChangeZtimer() ) {
      THISCALL( Hook_zCAICamera_CheckKeys )();
      return;
    }

    float frameTimeOld = ztimer->frameTimeFloat;
    float motionFactorOld = ztimer->factorMotion;
    ztimer->frameTimeFloat = frameTimeOld / motionFactorOld;
    ztimer->factorMotion = 1.0f;
    THISCALL( Hook_zCAICamera_CheckKeys )();
    ztimer->frameTimeFloat = frameTimeOld;
    ztimer->factorMotion = motionFactorOld;
  }

  HOOK Hook_oCAIHuman_PC_Turnings PATCH( &oCAIHuman::PC_Turnings, &oCAIHuman::PC_Turnings_Union );
  void oCAIHuman::PC_Turnings_Union( int forceRotation ) {
    if ( !Options::UseTimeMultiplier || ztimer->factorMotion == 1.0f || Pressed( GAME_LEFT ) || Pressed( GAME_RIGHT ) || !playerStatus.CanChangeZtimer() ) {
      THISCALL( Hook_oCAIHuman_PC_Turnings )(forceRotation);
      return;
    }

    float frameTimeOld = ztimer->frameTimeFloat;
    float motionFactorOld = ztimer->factorMotion;
    ztimer->frameTimeFloat = frameTimeOld / motionFactorOld;
    ztimer->factorMotion = 1.0f;
    THISCALL( Hook_oCAIHuman_PC_Turnings )(forceRotation);
    ztimer->frameTimeFloat = frameTimeOld;
    ztimer->factorMotion = motionFactorOld;
  };
#endif

  void PlayerStatus::ResetTimeMultiplier() {
    if ( !ztimer )
      return;

    ztimer->factorMotion = 1.0f;
  }

  void PlayerStatus::ResetSaveReminder() {
    if (SaveLoadGameInfo.changeLevel)
    {
      return;
    }

    lastSaveTime = std::chrono::high_resolution_clock::now();
  }

  void PlayerStatus::FactorMotion() {
    if ( !Options::UseTimeMultiplier )
      return;

    if ( !Options::TimeMultipliers.GetNum() || playerHelper.IsConUp() )
      return;

    if ( !CanChangeZtimer() )
      return;

    if ( playerHelper.IsDead() || playerHelper.IsInInfo() || ogame->IsOnPause() ) {
      if ( ztimer->factorMotion != 1.0f )
        ztimer->factorMotion = 1.0f;
      return;
    }

    if ( !zinput->KeyToggled( Options::KeyTimeMultiplier ) ) {
      if ( ztimer->factorMotion != Options::TimeMultipliers[multiplierIndex] )
        ztimer->factorMotion = Options::TimeMultipliers[multiplierIndex];
      return;
    }

    multiplierIndex++;
    if ( multiplierIndex < 0 || multiplierIndex >= Options::TimeMultipliers.GetNum() )
      multiplierIndex = 0;

    ztimer->factorMotion = Options::TimeMultipliers[multiplierIndex];
  }

  void PlayerStatus::ShowSystemTime() {
      if ( !Options::ShowSystemTime )
          return;

      if ( playerHelper.LeftInvOpen() || playerHelper.IsConUp() || !ogame->GetShowPlayerStatus() || !ogame->hpBar )
          return;

      zSTRING str = "";
      zCOLOR color = GFX_WHITE;
      tm timeStructure;

      time_t currentTime = time( NULL );
      localtime_s( &timeStructure, &currentTime );

      str = ( timeStructure.tm_hour < 10 ? "0" : "" ) + Z timeStructure.tm_hour + ":"
          + ( timeStructure.tm_min < 10 ? "0" : "" ) + Z timeStructure.tm_min;

      if ( Options::ShowSystemTime > 1 )
          str = str + ":" + ( timeStructure.tm_sec < 10 ? "0" : "" ) + Z timeStructure.tm_sec;

      zSTRING texture = "ICON_WATCH"; // https://game-icons.net/1x1/delapouite/watch.html

      infoIcons++;
      color.alpha = ogame->hpBar->alpha;
      IconInfo icon = IconInfo( screen->FontY(), screen->FontY() * 2.5 * infoIcons, screen->FontY() * 0.9f, color, texture, str );
  }

  void PlayerStatus::ShowGameTime() {
    if ( !Options::ShowGameTime && !Options::UseTimeMultiplier )
      return;

    if ( playerHelper.LeftInvOpen() || playerHelper.IsConUp() || !ogame->GetShowPlayerStatus() || !ogame->hpBar )
      return;

    zSTRING str = "";
    zCOLOR color = zCOLOR( 255, 255, 255 );

    if ( Options::ShowGameTime ) {
      int day, hour, min;
      ogame->GetTime( day, hour, min );
      str = (min > 9) ? Z hour + ":" + Z min : Z hour + ":0" + Z min;
    }

    if ( Options::UseTimeMultiplier && ztimer->factorMotion != 1.0f ) {
      color = zCOLOR( 255, 0, 0 );
      if ( str.Length() ) str = str + " ";
      str = str + "x" + Z ztimer->factorMotion;
    }

    if ( !str.Length() )
      return;

    zSTRING texture = "ICON_CLOCK"; // https://game-icons.net/1x1/lorc/empty-hourglass.html

    infoIcons++;
    color.alpha = ogame->hpBar->alpha;
    IconInfo icon = IconInfo( screen->FontY(), screen->FontY() * 2.5 * infoIcons, screen->FontY() * 0.9f, color, texture, str );
  }

  void PlayerStatus::ShowMunitionAmount() {
    if ( !Options::ShowMunitionAmount )
      return;

    if ( playerHelper.LeftInvOpen() || playerHelper.IsConUp() || !ogame->GetShowPlayerStatus() || !ogame->hpBar )
      return;

    oCItem* weapon = player->GetEquippedRangedWeapon();

    if ( !weapon ) weapon = player->GetWeapon();

    if ( !weapon || !weapon->HasFlag( ITM_CAT_FF ) || weapon->munition <= 0 )
      return;

    int amount = 0;
    zCOLOR color = zCOLOR( 255, 255, 255 );

    player->inventory2.UnpackAllItems();
    if ( oCItem* munition = player->IsInInv( weapon->munition, 1 ) )
      amount += munition->amount;

    if ( oCItem* munition = player->GetHandMunition() )
      amount += munition->instanz == weapon->munition;

    if ( amount == 0 )
      color = zCOLOR( 255, 0, 0 );
    else if ( amount < 10 )
      color = zCOLOR( 231, 76, 60 );
    else if ( amount < 25 )
      color = zCOLOR( 255, 175, 0 );
    else if ( amount < 50 )
      color = zCOLOR( 255, 218, 121 );

    zSTRING texture = (weapon->HasFlag( ITM_FLAG_BOW )) ? "LABEL_MUN_BOW" : "LABEL_MUN_CROSSBOW";

    infoIcons++;
    color.alpha = ogame->hpBar->alpha;
    IconInfo icon = IconInfo( screen->FontY(), screen->FontY() * 2.5 * infoIcons, screen->FontY() * 0.9f, color, texture, Z amount );
  }

  void PlayerStatus::ShowSaveReminder() {
    if (
      Options::SaveReminder == Invalid
      || !ogame
      || !player
      || playerHelper.IsBusy()
      || quickSave->IsBusy()
      || playerHelper.IsDead()
      || playerHelper.IsConUp()
      || !ogame->GetShowPlayerStatus()
      || !ogame->game_drawall
      )
    {
      return;
    }

    auto ElapsedTime = std::chrono::high_resolution_clock::now() - lastSaveTime;
    auto ElapsedMins = std::chrono::duration_cast<std::chrono::minutes>(ElapsedTime);
    auto ElapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(ElapsedTime - ElapsedMins);
    if ( ElapsedTime >= static_cast<std::chrono::minutes>( Options::SaveReminder ) )
    {
      zSTRING str = ( ElapsedMins.count() < 10 ? "0" : "" ) + Z ElapsedMins.count() + ":" + ( ElapsedSeconds.count() < 10 ? "0" : "" ) + Z static_cast<int>( ElapsedSeconds.count() );

      zSTRING texture = "ICON_SAVE"; // https://game-icons.net/1x1/lorc/disc.html

      infoIcons++;
      IconInfo icon = IconInfo(screen->FontY(), screen->FontY() * 2.5 * infoIcons, screen->FontY() * 0.9f, GFX_RED, texture, str);
    }
  }

  void PlayerStatus::StatusBars() {
   if ( !hpBar )
   {
       hpBar = new HealthStatusBar();
       hpBar->Init();
   }

    if ( !manaBar )
    {
        manaBar = new ManaStatusBar();
        manaBar->Init();
    }

    if ( !focusBar )
    {
        focusBar = new FocusStatusBar();
        focusBar->Init();
    }

    if ( !swimBar )
    {
        swimBar = new SwimStatusBar();
        swimBar->Init();
    }

    hpBar->Loop();
    manaBar->Loop();
    focusBar->Loop();
    swimBar->Loop();
  }

  void PlayerStatus::Clear() {
    focusColor.Clear();
    debugHelper.Clear();

    if ( hpBar )
      hpBar->Clear();

    if ( manaBar )
      manaBar->Clear();

    if ( focusBar )
      focusBar->Clear();

    if ( swimBar )
      swimBar->Clear();
  }

  void PlayerStatus::Loop() {
    if ( !ogame || !player )
      return;

    if ( quickSave->IsBusy() ) {
      Clear();
      return;
    }

    infoIcons = 0;

    debugHelper.Loop();
    focusColor.Loop();
    StatusBars();
    FactorMotion();
    ShowSystemTime();
    ShowGameTime();
    ShowMunitionAmount();
    ShowSaveReminder();
    HandleMunitionLoop();
    RenderSelectedItem();
  }
}