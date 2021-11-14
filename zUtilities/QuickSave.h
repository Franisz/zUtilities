// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    int UseQuickSave, MinSaveSlot, MaxSaveSlot;
    string CantSave, CantLoad, NoSave, SaveName;

    void QuickSave() {
      UseQuickSave = zoptions->ReadInt( PLUGIN_NAME, "UseQuickSave", true );

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
        break;
      case Lang_Eng:
        CantSave = "The game cannot be saved now!";
        CantLoad = "The game cannot be loaded now!";
        NoSave = "Such a save does not exist!";
        break;
      case Lang_Ger:
        CantSave = "Das Spiel kann jetzt nicht gespeichert werden!";
        CantLoad = "Das Spiel kann jetzt nicht geladen werden!";
        NoSave = "Ein solches Speichern gibt es nicht!";
        break;
      case Lang_Pol:
        CantSave = "Nie moїna teraz zapisaж rozgrywki!";
        CantLoad = "Nie moїna teraz wczytaж rozgrywki!";
        NoSave = "Taki zapis nie istnieje!";
        break;
      default:
        CantSave = "The game cannot be saved now!";
        CantLoad = "The game cannot be loaded now!";
        NoSave = "Such a save does not exist!";
        break;
      }

      CantSave = A zoptions->ReadString( PLUGIN_NAME, "CantSave", CantSave );
      CantLoad = A zoptions->ReadString( PLUGIN_NAME, "CantLoad", CantLoad );
      NoSave = A zoptions->ReadString( PLUGIN_NAME, "NoSave", NoSave );
      SaveName = A zoptions->ReadString( PLUGIN_NAME, "SaveName", "QuickSave" );
    }
  }

  class QuickSave {
  private:
    bool oldShowStatus = false;
    bool toggledShowStatus = false;

    int iLastSaveSlot;
    int iLastSaveNumber;

    void SetSaveSlotAndNr();
    int CanSave();
    int InInteraction();
    void CheckSave();
    void CheckLoad();
    void ToggleShowStatus();

  public:
    void Loop();
    QuickSave();
  };

  QuickSave* quickSave;
}