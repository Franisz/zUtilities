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
    int CanSave( PlayerHelper* playerHelper );
    int InInteraction( PlayerHelper* playerHelper );
    void CheckSave( PlayerHelper* playerHelper );
    void CheckLoad( PlayerHelper* playerHelper );
    void ToggleShowStatus();

  public:
    void ReadOptions();
    void QuickSaveLoop( PlayerHelper* playerHelper );
  };
}