// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
#if ENGINE < Engine_G2
  HOOK Hook_zCAICamera_CheckKeys PATCH( &zCAICamera::CheckKeys, &zCAICamera::CheckKeys_Union );
  void zCAICamera::CheckKeys_Union() {
    if ( !Options::UseTimeMultiplier || ztimer->factorMotion == 1.0f ) {
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
    if ( !Options::UseTimeMultiplier || ztimer->factorMotion == 1.0f || Pressed( GAME_LEFT ) || Pressed( GAME_RIGHT ) ) {
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

  void PlayerStatus::FactorMotion() {
    if ( !Options::UseTimeMultiplier )
      return;

    if ( !Options::TimeMultipliers.GetNum() || playerHelper.IsConUp() )
      return;

    if ( playerHelper.IsDead() || !oCInformationManager::GetInformationManager().IsDone || ogame->IsOnPause() ) {
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

  void PlayerStatus::ShowGameTime() {
    if ( !Options::ShowGameTime && !Options::UseTimeMultiplier )
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
    new IconInfo( screen->FontY(), screen->FontY() * 2.5, color, texture, str );
  }

  void PlayerStatus::StatusBars() {
    if ( !hpBar )
      hpBar = new StatusBar( ogame->hpBar );

    if ( !manaBar )
      manaBar = new StatusBar( ogame->manaBar );

    if ( !focusBar )
      focusBar = new StatusBar( ogame->focusBar );

    if ( !swimBar )
      swimBar = new StatusBar( ogame->swimBar );

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

    if ( quickSave->isSaving ) {
      Clear();
      return;
    }

    debugHelper.Loop();
    focusColor.Loop();
    StatusBars();
    FactorMotion();
    ShowGameTime();
  }
}