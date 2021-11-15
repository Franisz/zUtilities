// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
#define PLUGIN_NAME "ZUTILITIES"
#define VERSION_NUMBER "0.17"
#define printWin(a) ogame->GetTextView()->Printwin(a)

  namespace Options {
    int TrampleMeatbugs, CenterInvItems, ActivateUsedMunition;
    void Misc() {
      TrampleMeatbugs = zoptions->ReadInt( PLUGIN_NAME, "TrampleMeatbugs", true );
      CenterInvItems = zoptions->ReadInt( PLUGIN_NAME, "CenterInvItems", true );
      ActivateUsedMunition = zoptions->ReadInt( PLUGIN_NAME, "ActivateUsedMunition", true );
    }

    void AddTrivias() {
      zoptions->AddTrivia( PLUGIN_NAME, "RecoveryVisualization", "... enables (1) or disables (0) visualization of healing that hovered in the inventory item gives" );
      zoptions->AddTrivia( PLUGIN_NAME, "StatusBarValueMode", "... specifies mode of showing hp / mana bar value, (0) - Disabled, (1) - 'Inside', (2) - 'Above'" );
      zoptions->AddTrivia( PLUGIN_NAME, "ShowEnemyBarAboveHim", "... enables (1) or disables (0) showing enemy hp bar above his head" );

      zoptions->AddTrivia( PLUGIN_NAME, "UseQuickSave", "... enables (1) or disables (0) QuickSaving with [F10] and QuickLoading with [F12]" );
      zoptions->AddTrivia( PLUGIN_NAME, "KeyQuickSave", "... key for QuickSave" );
      zoptions->AddTrivia( PLUGIN_NAME, "KeyQuickLoad", "... key for QuickLoad" );
      zoptions->AddTrivia( PLUGIN_NAME, "MinSaveSlot", "... defines min range of used save slots" );
      zoptions->AddTrivia( PLUGIN_NAME, "MaxSaveSlot", "... defines max range of used save slots" );
      zoptions->AddTrivia( PLUGIN_NAME, "CantSave", "... text appearing when game cannot be saved" );
      zoptions->AddTrivia( PLUGIN_NAME, "CantLoad", "... text appearing when game cannot be loaded" );
      zoptions->AddTrivia( PLUGIN_NAME, "NoSave", "... text appearing when something went wrong and incorrect save slot tried to be loaded" );
      zoptions->AddTrivia( PLUGIN_NAME, "SaveName", "... name used for quicksaves" );

      zoptions->AddTrivia( PLUGIN_NAME, "ColorNpcs", "... enables (1) or disables (0) coloring of focused Npcs" );
      zoptions->AddTrivia( PLUGIN_NAME, "ColorChests", "... enables (1) or disables (0) coloring of focused Chests" );
      zoptions->AddTrivia( PLUGIN_NAME, "ColorDoors", "... enables (1) or disables (0) coloring of focused Doors" );
      zoptions->AddTrivia( PLUGIN_NAME, "ColorItems", "... enables (1) or disables (0) coloring of focused Items" );

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
    }
  }

  void zCOption::AddTrivia( const string sectionName, const string entryName, string trivia ) {
    zCOption* const& option = this;
    zCOptionSection* section = option->GetSectionByName( sectionName, true );

    if ( !section ) return;

    zCOptionEntry* entry = option->GetEntryByName( section, entryName, true );

    if ( !entry ) return;

    zCOptionEntry* triviaEntry = new zCOptionEntry{ "", (A"; " + trivia + "\r\n\n") };

    int nextPos = section->entryList.Search( entry ) + 1;

    if ( nextPos > section->entryList.GetNumInList() - 1 ) {
      section->entryList.InsertEnd( triviaEntry );
      return;
    }

    zSTRING nextLine = section->entryList[nextPos]->varValue;

    if ( nextLine.StartWith( "; " + trivia ) )
      return;

    if ( nextLine.StartWith( "; " ) ) {
      section->entryList[nextPos] = triviaEntry;
      return;
    }

    section->entryList.InsertAtPos( triviaEntry, nextPos );
  }
}