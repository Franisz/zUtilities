// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
#define PLUGIN_NAME "ZUTILITIES"
#define VERSION_NUMBER "0.25"
#define printWin(a) ogame->GetTextView()->Printwin(a)
#define del(x) { delete x; x = nullptr; }

  namespace Options {
    int TrampleMeatbugs, CenterInvItems, ActivateUsedMunition, AlternativeDialogueBoxes;
    void Misc() {
      TrampleMeatbugs = zoptions->ReadBool( PLUGIN_NAME, "TrampleMeatbugs", true );
      CenterInvItems = zoptions->ReadBool( PLUGIN_NAME, "CenterInvItems", true );
      ActivateUsedMunition = zoptions->ReadBool( PLUGIN_NAME, "ActivateUsedMunition", true );
      AlternativeDialogueBoxes = zoptions->ReadBool( PLUGIN_NAME, "AlternativeDialogueBoxes", false );
    }

    void AddTrivias() {
      const string nline = "\r\n; ";

      zoptions->AddTrivia( PLUGIN_NAME, "RecoveryVisualization", "... enables (1) or disables (0) visualization of healing that hovered in the inventory item gives" );
      zoptions->AddTrivia( PLUGIN_NAME, "StatusBarValueMode", "... specifies mode of showing status bar value, (0) - 'Disabled', (1) - 'Above', (2) - 'PointToCenter', (3) - 'Inside'" );
      zoptions->AddTrivia( PLUGIN_NAME, "ShowEnemyBarAboveHim", "... enables (1) or disables (0) showing enemy hp bar above his head" );
      zoptions->AddTrivia( PLUGIN_NAME, "StatusBarNames", "... defines text label for status bars like so: 'Health|Mana|Stamina', leave empty if text is unwanted" );
      zoptions->AddTrivia( PLUGIN_NAME, "HealthBarPos", "... defines position of health bar like so: 'x1|y1|x2|y2'" + nline + "... default position for scale 1 is: '43|7873|1122|8085' and for scale 0: '43|7964|811|8116'" + nline + "... leave empty to use default position" );
      zoptions->AddTrivia( PLUGIN_NAME, "ManaBarPos", "... defines position of mana bar like so: 'x1|y1|x2|y2'" + nline + "... default position for scale 1 is: '7053|7873|8132|8085' and for scale 0: '7381|7964|8149|8116'" + nline + "... leave empty to use default position" );
      zoptions->AddTrivia( PLUGIN_NAME, "SwimBarPos", "... defines position of swim bar like so: 'x1|y1|x2|y2'" + nline + "... default position for scale 1 is: '3556|7873|4635|8085' and for scale 0: '3712|7964|4480|8116'" + nline + "... leave empty to use default position" );

      zoptions->AddTrivia( PLUGIN_NAME, "ShowGameTime", "... enables (1) or disables (0) on screen display of in game time" );
      zoptions->AddTrivia( PLUGIN_NAME, "ShowMunitionAmount", "... enables (1) or disables (0) on screen display of currently used munition amount" );
#if ENGINE >= Engine_G2
      zoptions->AddTrivia( PLUGIN_NAME, "ShowPickpocketIcon", "... enables (1) or disables (0) coin icon next to the focused npc name when it can be pickpocketed" );
#endif
      zoptions->AddTrivia( PLUGIN_NAME, "UseTimeMultiplier", "... enables (1) or disables (0) time speed multiplier" );
      zoptions->AddTrivia( PLUGIN_NAME, "KeyTimeMultiplier", "... key for cycling time speed" );
      zoptions->AddTrivia( PLUGIN_NAME, "TimeMultipliers", "... defines time multipliers" );

      zoptions->AddTrivia( PLUGIN_NAME, "UseQuickSave", "... enables (1) or disables (0) QuickSaving with [F10] and QuickLoading with [F12]" );
      zoptions->AddTrivia( PLUGIN_NAME, "KeyQuickSave", "... key for QuickSave" );
      zoptions->AddTrivia( PLUGIN_NAME, "KeyQuickLoad", "... key for QuickLoad" );
      zoptions->AddTrivia( PLUGIN_NAME, "MinSaveSlot", "... defines min range of used save slots" );
      zoptions->AddTrivia( PLUGIN_NAME, "MaxSaveSlot", "... defines max range of used save slots" );
      zoptions->AddTrivia( PLUGIN_NAME, "CantSave", "... text appearing when game cannot be saved" );
      zoptions->AddTrivia( PLUGIN_NAME, "CantLoad", "... text appearing when game cannot be loaded" );
      zoptions->AddTrivia( PLUGIN_NAME, "NoSave", "... text appearing when something went wrong and incorrect save slot tried to be loaded" );
      zoptions->AddTrivia( PLUGIN_NAME, "SaveName", "... name used for quicksaves" );

      zoptions->AddTrivia( PLUGIN_NAME, "ColorNpcs", "... enables (1) or disables (0) coloring of focused npcs" );
      zoptions->AddTrivia( PLUGIN_NAME, "ColorLockables", "... enables (1) or disables (0) coloring of focused chests, doors and other lockables" );
      zoptions->AddTrivia( PLUGIN_NAME, "ColorItems", "... enables (1) or disables (0) coloring of focused items" );
      zoptions->AddTrivia( PLUGIN_NAME, "ColorInter", "... enables (1) or disables (0) coloring of interactive bookstands" );

      zoptions->AddTrivia( PLUGIN_NAME, "LabelItems", "... enables (1) or disables (0) inventory item labeling" );
      zoptions->AddTrivia( PLUGIN_NAME, "LabelScale", "... defines scale of the label" );
      zoptions->AddTrivia( PLUGIN_NAME, "LabelMissionItems", "... enables (1) or disables (0) labeling of item missions, this will overwrite previous label on any item with ITEM_MISSION flag" );
      zoptions->AddTrivia( PLUGIN_NAME, "PutLabelBehind", "... specifies if the label should be rendered behind the item" );

      zoptions->AddTrivia( PLUGIN_NAME, "DamagePopupMode", "... specifies DamagePopup mode, (0) - Disabled, (1) - 'Alter Damage', (2) - 'New World'" );
      zoptions->AddTrivia( PLUGIN_NAME, "DamagePopupScale", "... defines base scale of the popup" );
      zoptions->AddTrivia( PLUGIN_NAME, "DamagePopupShowIcons", "... enables (1) or disables (0) icons for the popup" );
      zoptions->AddTrivia( PLUGIN_NAME, "DamagePopupColorDmgTypes", "... enables (1) or disables (0) popup coloring by the damage type" );
      zoptions->AddTrivia( PLUGIN_NAME, "DamagePopupColorOnlyIcon", "... enables (1) or disables (0) coloring only the popup icon" );

      zoptions->AddTrivia( PLUGIN_NAME, "TrampleMeatbugs", "... enables (1) or disables (0) a way of killing meatbugs by stepping on them" );
      zoptions->AddTrivia( PLUGIN_NAME, "CenterInvItems", "... enables (1) or disables (0) inventory item rendering in the center of the screen instead of the item description box" );
      zoptions->AddTrivia( PLUGIN_NAME, "ActivateUsedMunition", "... enables (1) or disables (0) highlighting currently used ranged weapon munition in the inventory" );
      zoptions->AddTrivia( PLUGIN_NAME, "AlternativeDialogueBoxes", "... enables (1) or disables (0) alternative dialogue boxes style" );
    }
  }
}