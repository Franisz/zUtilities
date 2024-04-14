// Supported with union (c) 2020 Union team
// Union HEADER file

#include <chrono>

namespace GOTHIC_NAMESPACE
{
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