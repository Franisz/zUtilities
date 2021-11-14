// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {
  void PlayerStatus::StatusBars() {
    if ( !Options::RecoveryVisualization )
      return;

    if ( !hpBar )
      hpBar = new StatusBar( ogame->hpBar );

    if ( !manaBar )
      manaBar = new StatusBar( ogame->manaBar );

    hpBar->Loop();
    manaBar->Loop();
  }

  void PlayerStatus::Loop() {
    if ( !ogame || !player )
      return;

    StatusBars();
  }
}