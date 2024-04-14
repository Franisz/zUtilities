// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_NAMESPACE
{

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