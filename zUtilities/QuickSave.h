// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  class QuickSave {
  private:

    int iMinSaveSlot;
    int iMaxSaveSlot;
    int iLastSaveSlot;
    int iLastSaveNumber;

    zSTRING sCantSave;
    zSTRING sCantLoad;
    zSTRING sNoSave;
    zSTRING sSaveName;

    int CanSave( PlayerHelper* playerHelper );
    int InInteraction( PlayerHelper* playerHelper );
    void Save( PlayerHelper* playerHelper );
    void Load( PlayerHelper* playerHelper );

  public:

    void ReadOptions();
    void SetStringsByLanguage();
    void QuickSaveLoop( PlayerHelper* playerHelper );

  };
}