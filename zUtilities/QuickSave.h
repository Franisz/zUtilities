// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  class QuickSave {
  private:
    bool oldShowStatus = false;
    bool toggledShowStatus = false;

    int iMinSaveSlot;
    int iMaxSaveSlot;
    int iLastSaveSlot;
    int iLastSaveNumber;

    zSTRING sCantSave;
    zSTRING sCantLoad;
    zSTRING sNoSave;
    zSTRING sSaveName;

    void SetStringsByLanguage();
    int CanSave();
    int InInteraction();
    void CheckSave();
    void CheckLoad();
    void ToggleShowStatus();

  public:
    void ReadOptions();
    void QuickSaveLoop();
  };
}