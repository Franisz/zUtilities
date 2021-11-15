// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  class PlayerStatus {
  private:
    StatusBar* hpBar;
    StatusBar* manaBar;

    void ShowBarsValue();
    void StatusBars();

  public:
    StatusBar* focusBar;
    void Loop();
  };

  PlayerStatus playerStatus;
}