// Supported with union (c) 2020 Union team
// Union HEADER file

#include <chrono>

namespace GOTHIC_NAMESPACE
{
  namespace Options
  {
    bool ShowGameTime, ShowMunitionAmount, ShowTargetProtection, ShowPickpocketIcon, UseTimeMultiplier;
    int KeyTimeMultiplier;
    Union::Array<float> TimeMultipliers;
    int SaveReminder;

    void PlayerStatus()
    {
      ShowGameTime = zoptions->ReadBool(PLUGIN_NAME, "ShowGameTime", false);
      ShowMunitionAmount = zoptions->ReadBool(PLUGIN_NAME, "ShowMunitionAmount", false);
      ShowTargetProtection = zoptions->ReadBool(PLUGIN_NAME, "ShowTargetProtection", true);
#if ENGINE >= Engine_G2
      ShowPickpocketIcon = zoptions->ReadBool(PLUGIN_NAME, "ShowPickpocketIcon", true);
#endif
      UseTimeMultiplier = zoptions->ReadBool(PLUGIN_NAME, "UseTimeMultiplier", false);
      KeyTimeMultiplier = GetEmulationKeyCode(zoptions->ReadString(PLUGIN_NAME, "KeyTimeMultiplier", "KEY_Z"));
      auto MulString = zoptions->ReadString(PLUGIN_NAME, "TimeMultipliers", "1.0|2.5");

      auto MulStrings = Union::StringANSI(MulString).Split("|");
      TimeMultipliers.Clear();
      for (int i = 0; i < MulStrings.GetCount(); i++)
      {
        MulStrings[i].ShrinkToFit();
        TimeMultipliers.Insert(MulStrings[i].ConvertToDouble());
      }
      SaveReminder = zoptions->ReadInt(PLUGIN_NAME, "SaveReminder", 5);
    }
  }

  class PlayerStatus
  {
  private:
    StatusBar *hpBar = {};
    StatusBar *manaBar = {};
    StatusBar *swimBar = {};
    int multiplierIndex = 0;
    int infoIcons = 0;
    std::chrono::high_resolution_clock::time_point lastSaveTime = {};

    void ShowGameTime();
    void ShowMunitionAmount();
    void ShowSaveReminder();
    void StatusBars();
    void FactorMotion();

  public:
    zCArray<oCInfo *> pickpocketInfos;
    zCArray<zSTRING> interStateFuncs;
    zCArray<zSTRING> stateFuncItems;
    oCItem *stateFuncItem;
    oCNpc *traderNpc;
    StatusBar *focusBar;
    bool CanPickpocketNpc(oCNpc *npc);
    void GetPickpocketInfos();
    bool CanChangeZtimer();
    bool KnowStateFunc(zCVob *vob);
    void TryAddStateFunc(zCVob *vob);
    void ResetTimeMultiplier();
    void ResetSaveReminder();
    void Clear();
    void Loop();
    void Archive(zCArchiver *ar);
    void Unarchive(zCArchiver *ar);
  };

  std::unique_ptr<PlayerStatus> playerStatus;
}