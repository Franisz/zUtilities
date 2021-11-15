// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
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
  }
}