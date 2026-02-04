// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    bool ShowGameTime, ShowMunitionAmount, ShowPickpocketIcon, UseTimeMultiplier;
    int ShowSystemTime, KeyTimeMultiplier, ShowTargetProtectionNoFight, ShowTargetProtectionInFight, TargetProtectionIconStyle;
    Array<float> TimeMultipliers;
    int SaveReminder, DistanceWeaponDamageTypeFromIni;
    DamageMask DistanceWeaponDamageType = DamageMask{ oEDamageType::oEDamageType_Point }; // Default type fallback

    void PlayerStatus() {
      ShowSystemTime = zoptions->ReadInt( PLUGIN_NAME, "ShowSystemTime", 0 );
      ShowGameTime = zoptions->ReadBool( PLUGIN_NAME, "ShowGameTime", false );
      ShowMunitionAmount = zoptions->ReadBool( PLUGIN_NAME, "ShowMunitionAmount", false );
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

      SaveReminder = zoptions->ReadInt(PLUGIN_NAME, "SaveReminder", 5);

      ShowTargetProtectionNoFight = zoptions->ReadInt(PLUGIN_NAME, "ShowTargetProtectionNoFight", TargetProtectionMode::AllButZeros);
      ShowTargetProtectionInFight = zoptions->ReadInt(PLUGIN_NAME, "ShowTargetProtectionInFight", TargetProtectionMode::CurrentWeapon);
      TargetProtectionIconStyle = zoptions->ReadInt(PLUGIN_NAME, "TargetProtectionIconStyle", 0);

	  // when value form ini is 0, do not override default to avoid showing nothing for distance weapons
	  if (DistanceWeaponDamageTypeFromIni = zoptions->ReadInt(PLUGIN_NAME, "DistanceWeaponDamageType", 0)) {
          for (const auto& entry : DAMAGE_MAP) {
              DistanceWeaponDamageType[entry.index] = (DistanceWeaponDamageTypeFromIni & entry.type) != 0;
          }
      }
    }
  }

  class PlayerStatus {
  private:
    HealthStatusBar* hpBar;
    ManaStatusBar* manaBar;
    SwimStatusBar* swimBar;
    int multiplierIndex = 0;
    int infoIcons = 0;
    std::chrono::high_resolution_clock::time_point lastSaveTime;

    void ShowSystemTime();
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
    FocusStatusBar* focusBar;
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