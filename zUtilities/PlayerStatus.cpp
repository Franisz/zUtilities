// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  void PlayerStatus::ResetTimeMultiplier() {
    if ( !ztimer )
      return;

    ztimer->factorMotion = 1.0f;
  }

  void PlayerStatus::FactorMotion() {
    if ( !Options::UseTimeMultiplier )
      return;

    if ( !Options::TimeMultipliers.GetNum() || zcon->IsVisible() )
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

  void PlayerStatus::StatusBars() {
    if ( !hpBar )
      hpBar = new StatusBar( ogame->hpBar );

    if ( !manaBar )
      manaBar = new StatusBar( ogame->manaBar );

    if ( !focusBar )
      focusBar = new StatusBar( ogame->focusBar );

    hpBar->Loop();
    manaBar->Loop();
    focusBar->Loop();
  }

  void PlayerStatus::Loop() {
    if ( !ogame || !player )
      return;

    StatusBars();
    FactorMotion();
  }
}