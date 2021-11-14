// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    int RecoveryVisualization;

    void PlayerStatus() {
      RecoveryVisualization = zoptions->ReadInt( PLUGIN_NAME, "RecoveryVisualization", true );
    }
  }

  class PlayerStatus {
  private:
    StatusBar* hpBar;
    StatusBar* manaBar;

    void StatusBars();

  public:
    void Loop();
  };

  PlayerStatus playerStatus;
}