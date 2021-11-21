// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    int ShowGameTime, UseTimeMultiplier, KeyTimeMultiplier;
    Array<float> TimeMultipliers;

    void PlayerStatus() {
      ShowGameTime = zoptions->ReadInt( PLUGIN_NAME, "ShowGameTime", true );
      UseTimeMultiplier = zoptions->ReadInt( PLUGIN_NAME, "UseTimeMultiplier", true );
      KeyTimeMultiplier = GetEmulationKeyCode( zoptions->ReadString( PLUGIN_NAME, "KeyTimeMultiplier", "KEY_Z" ) );
      string MulString = A zoptions->ReadString( PLUGIN_NAME, "TimeMultipliers", "1.0|2.5" );

      Array<string> MulStrings = MulString.Split( "|" );
      for ( int i = 0; i < MulStrings.GetNum(); i++ )
        TimeMultipliers.Insert( MulStrings[i].Shrink().ToReal32() );
    }
  }

  class PlayerStatus {
  private:
    StatusBar* hpBar;
    StatusBar* manaBar;
    StatusBar* swimBar;
    int multiplierIndex = 0;

    void ShowGameTime();
    void StatusBars();
    void FactorMotion();

  public:
    oCNpc* traderNpc;
    StatusBar* focusBar;
    void ResetTimeMultiplier();
    void Clear();
    void Loop();
  };

  PlayerStatus playerStatus;
}