// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_NAMESPACE
{
  namespace Options
  {
    int QuickSaveMode, UseBinarySave, KeyQuickSave, KeyQuickLoad, MinSaveSlot, MaxSaveSlot;
    zSTRING CantSave, CantLoad, NoSave, SaveName;

    void QuickSave()
    {
      QuickSaveMode = zoptions->ReadInt(PLUGIN_NAME, "QuickSaveMode", 1);

      KeyQuickSave = GetEmulationKeyCode(zoptions->ReadString(PLUGIN_NAME, "KeyQuickSave", "KEY_F10"));
      KeyQuickLoad = GetEmulationKeyCode(zoptions->ReadString(PLUGIN_NAME, "KeyQuickLoad", "KEY_F12"));

#if ENGINE >= Engine_G2
      MinSaveSlot = zoptions->ReadInt(PLUGIN_NAME, "MinSaveSlot", 15);
      MaxSaveSlot = zoptions->ReadInt(PLUGIN_NAME, "MaxSaveSlot", 20);
#else
      MinSaveSlot = zoptions->ReadInt(PLUGIN_NAME, "MinSaveSlot", 10);
      MaxSaveSlot = zoptions->ReadInt(PLUGIN_NAME, "MaxSaveSlot", 15);
#endif

      switch (Union::Locale::GetUserLocale().Language)
      {
      case Union::LANGUAGE::RUSSIAN:
        CantSave = "���� �� ����� ���� ��������� ������!";
        CantLoad = "���� �� ����� ���� ���������!";
        NoSave = "������ ���������� �� ����������!";
        break;
      case Union::LANGUAGE::GERMAN:
        CantSave = "Das Spiel kann jetzt nicht gespeichert werden!";
        CantLoad = "Das Spiel kann jetzt nicht geladen werden!";
        NoSave = "Ein solches Speichern gibt es nicht!";
        break;
      case Union::LANGUAGE::POLISH:
        CantSave = "Nie mo�na teraz zapisa� rozgrywki!";
        CantLoad = "Nie mo�na teraz wczyta� rozgrywki!";
        NoSave = "Taki zapis nie istnieje!";
        break;
      default:
        CantSave = "The game cannot be saved now!";
        CantLoad = "The game cannot be loaded now!";
        NoSave = "Such a save does not exist!";
        break;
      }

      CantSave = zoptions->ReadString(PLUGIN_NAME, "CantSave", CantSave);
      CantLoad = zoptions->ReadString(PLUGIN_NAME, "CantLoad", CantLoad);
      NoSave = zoptions->ReadString(PLUGIN_NAME, "NoSave", NoSave);
      SaveName = zoptions->ReadString(PLUGIN_NAME, "SaveName", "QuickSave");
    }
  }

  class QuickSave
  {
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

  public:
    enum QuickSaveMode
    {
      Disabled,
      Standard,
      Alternative
    };

    bool saveEnd = false;
    bool isSaving = false;
    bool isLoading = false;
    void EndSaveLoad();
    bool IsBusy();
    void Loop();
    QuickSave();
  };

  std::unique_ptr<QuickSave> quickSave;
}