// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    bool PrintQuickSaveLoadInfo;
    int QuickSaveMode, QuickLoadAfterGameStart, UseBinarySave, KeyQuickSave, KeyQuickLoad, MinSaveSlot, MaxSaveSlot;
    string CantSave, CantLoad, NoSave, SaveCompleted, LoadCompleted, SaveName;

    void QuickSave() {
      QuickSaveMode = zoptions->ReadInt( PLUGIN_NAME, "QuickSaveMode", 1 );
      PrintQuickSaveLoadInfo = zoptions->ReadBool( PLUGIN_NAME, "PrintQuickSaveLoadInfo", 0 );
      QuickLoadAfterGameStart = zoptions->ReadInt( PLUGIN_NAME, "QuickLoadAfterGameStart", 0 );

      KeyQuickSave = GetEmulationKeyCode( zoptions->ReadString( PLUGIN_NAME, "KeyQuickSave", "KEY_F10" ) );
      KeyQuickLoad = GetEmulationKeyCode( zoptions->ReadString( PLUGIN_NAME, "KeyQuickLoad", "KEY_F12" ) );

#if ENGINE >= Engine_G2
      MinSaveSlot = zoptions->ReadInt( PLUGIN_NAME, "MinSaveSlot", 15 );
      MaxSaveSlot = zoptions->ReadInt( PLUGIN_NAME, "MaxSaveSlot", 20 );
#else
      MinSaveSlot = zoptions->ReadInt( PLUGIN_NAME, "MinSaveSlot", 10 );
      MaxSaveSlot = zoptions->ReadInt( PLUGIN_NAME, "MaxSaveSlot", 15 );
#endif

      switch ( Union.GetSystemLanguage() )
      {
      case Lang_Rus:
        CantSave = "Игра не может быть сохранена сейчас!";
        CantLoad = "Игра не может быть загружена!";
        NoSave = "Такого сохранения не существует!";
        SaveCompleted = "Игра сохранена.";
        LoadCompleted = "Игра загружена.";
        break;
      case Lang_Ger:
        CantSave = "Das Spiel kann jetzt nicht gespeichert werden!";
        CantLoad = "Das Spiel kann jetzt nicht geladen werden!";
        NoSave = "Ein solches Speichern gibt es nicht!";
        SaveCompleted = "Spiel gespeichert.";
        LoadCompleted = "Spiel geladen.";
        break;
      case Lang_Pol:
        CantSave = "Nie moїna teraz zapisaж rozgrywki!";
        CantLoad = "Nie moїna teraz wczytaж rozgrywki!";
        NoSave = "Taki zapis nie istnieje!";
        SaveCompleted = "Gra zapisana.";
        LoadCompleted = "Gra wczytana.";
        break;
      default:
        CantSave = "The game cannot be saved now!";
        CantLoad = "The game cannot be loaded now!";
        NoSave = "Such a save does not exist!";
        SaveCompleted = "Game saved.";
        LoadCompleted = "Game loaded.";
        break;
      }

      CantSave = A zoptions->ReadString( PLUGIN_NAME, "CantSave", CantSave );
      CantLoad = A zoptions->ReadString( PLUGIN_NAME, "CantLoad", CantLoad );
      NoSave = A zoptions->ReadString( PLUGIN_NAME, "NoSave", NoSave );
      SaveCompleted = A zoptions->ReadString( PLUGIN_NAME, "SaveCompleted", SaveCompleted );
      LoadCompleted = A zoptions->ReadString( PLUGIN_NAME, "LoadCompleted", LoadCompleted );
      SaveName = A zoptions->ReadString( PLUGIN_NAME, "SaveName", "QuickSave" );
    }
  }

  class QuickSave {
  private:
    bool disabledStatus = false;

    int iLastSaveSlot;
    int iLastSaveNumber;

    void SetSaveSlotAndNr();
    int CanSave();
    int InInteraction();
    void CheckSave();
    void CheckLoad();
    void StartSaveLoad();
    void LoadFromMainMenu() const;

  public:
    enum QuickSaveMode {
      Disabled,
      Standard,
      Alternative
    };

    static bool KeepClosingMenus;
    bool saveEnd = false;
    bool isSaving = false;
    bool isLoading = false;
    void EndSaveLoad();
    bool IsBusy();
    void Loop();
    void MenuLoop();
    QuickSave();
  };

  QuickSave* quickSave;
}