// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    bool ShowGameTime, ShowMunitionAmount, ShowTargetProtection, ShowPickpocketIcon, UseTimeMultiplier;
    int KeyTimeMultiplier;
    Array<float> TimeMultipliers;
    int SaveReminder;
    int BoostTimeMultiplierKeyDetectMilliseconds;
    float BoostTimeMultiplierFactor;

    void PlayerStatus() {
      ShowGameTime = zoptions->ReadBool( PLUGIN_NAME, "ShowGameTime", false );
      ShowMunitionAmount = zoptions->ReadBool( PLUGIN_NAME, "ShowMunitionAmount", false );
      ShowTargetProtection = zoptions->ReadBool( PLUGIN_NAME, "ShowTargetProtection", true );
#if ENGINE >= Engine_G2
      ShowPickpocketIcon = zoptions->ReadBool( PLUGIN_NAME, "ShowPickpocketIcon", true );
#endif
      UseTimeMultiplier = zoptions->ReadBool( PLUGIN_NAME, "UseTimeMultiplier", false );
      KeyTimeMultiplier = GetEmulationKeyCode( zoptions->ReadString( PLUGIN_NAME, "KeyTimeMultiplier", "KEY_Z" ) );
      string MulString = A zoptions->ReadString( PLUGIN_NAME, "TimeMultipliers", "1.0|2.5" );

      Array<string> MulStrings = MulString.Split( "|" );
      TimeMultipliers.Clear();
      for ( int i = 0; i < MulStrings.GetNum(); i++ )
        TimeMultipliers.Insert( MulStrings[i].Shrink().ToReal32() );

      BoostTimeMultiplierKeyDetectMilliseconds = zoptions->ReadInt(PLUGIN_NAME, "BoostTimeMultiplierKeyDetectMilliseconds", 250);
      BoostTimeMultiplierFactor = zoptions->ReadReal(PLUGIN_NAME, "BoostTimeMultiplierFactor", 10.0f);

      SaveReminder = zoptions->ReadInt(PLUGIN_NAME, "SaveReminder", 5);
    }
  }

  class PlayerStatus {
  private:
    StatusBar* hpBar;
    StatusBar* manaBar;
    StatusBar* swimBar;
    int multiplierIndex = 0;
    int infoIcons = 0;
    bool keyTimeMultiplierPreviouslyPressed = false;
    bool keyTimeMultiplierToggled = false;
    std::chrono::high_resolution_clock::time_point lastSaveTime;
    std::chrono::high_resolution_clock::time_point keyTimeMultiplierPressedStartTime;

    void ShowGameTime();
    void ShowMunitionAmount();
    void ShowSaveReminder();
    void StatusBars();
    void FactorMotion();

  public:
    zCArray<oCInfo*> pickpocketInfos;
    zCArray<zSTRING> interStateFuncs;
    zCArray<zSTRING> stateFuncItems;
    oCItem* stateFuncItem;
    oCNpc* traderNpc;
    StatusBar* focusBar;
    bool CanPickpocketNpc( oCNpc* npc );
    void GetPickpocketInfos();
    bool CanChangeZtimer();
    bool KnowStateFunc( zCVob* vob );
    void TryAddStateFunc( zCVob* vob );
    void ResetTimeMultiplier();
    void ResetSaveReminder();
    void Clear();
    void Loop();
    void Archive( zCArchiver* ar );
    void Unarchive( zCArchiver* ar );
  };

  PlayerStatus playerStatus;
}