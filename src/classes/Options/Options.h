// Supported with union (c) 2020 Union team
// Union HEADER file

#include <string>

namespace GOTHIC_NAMESPACE
{
  class ZUtilitiesOptions
  {
  private:
    void Misc();
    void QuickSave();
    void LogBook();
    void PlayerStatus();
    void StatusBar();
    void FocusColor();
    void ItemLabel();
    void DamagePopup();

  public:
    bool TrampleMeatbugs,
        CenterInvItems,
        RememberLockCombination,
        ActivateUsedMunition,
        AlternativeDialogueBoxes,
        LogBookColoring;
    zCOLOR *SelectedDialogueColor;
    int QuickSaveMode, UseBinarySave, KeyQuickSave, KeyQuickLoad, MinSaveSlot, MaxSaveSlot;
    zSTRING CantSave, CantLoad, NoSave, SaveName;
    bool ShowGameTime, ShowMunitionAmount, ShowTargetProtection, ShowPickpocketIcon, UseTimeMultiplier;
    int KeyTimeMultiplier;
    Union::Array<float> TimeMultipliers;
    int SaveReminder;
    bool RecoveryVisualization, ShowEnemyBarAboveHim;
    int StatusBarValueMode;
    Union::Array<Union::UnionStringA> StatusBarNames, HealthBarPos, ManaBarPos, SwimBarPos;
    bool ColorNpcs, ColorLockables, ColorItems, ColorInter;
    bool LabelItems, PutLabelBehind, LabelMissionItems;
    float LabelScale;
    bool DamagePopupShowIcons, DamagePopupColorDmgTypes, DamagePopupColorOnlyIcon;
    int DamagePopupMode;
    float DamagePopupScale;
    bool UsingDebugHelper = false;
    bool ShowTriggers = false;

    void ReadOptions();
    void AddTrivias();
  };

  std::unique_ptr<ZUtilitiesOptions> zUtilitiesOptions;
}