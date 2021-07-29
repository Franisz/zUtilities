// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

#define pluginName "ZUTILITIES"
#define printWin(a) ogame->GetTextView()->Printwin(a);

  int bColorNpcs, bColorChests, bColorDoors, bColorItems, bUseQuickSave, bTrampleMeatbugs;

  void initOptions() {
    bColorNpcs = zoptions->ReadInt( pluginName, "bColorNpcs", TRUE );
    bColorChests = zoptions->ReadInt( pluginName, "bColorChests", TRUE );
    bColorDoors = zoptions->ReadInt( pluginName, "bColorDoors", TRUE );
    bColorItems = zoptions->ReadInt( pluginName, "bColorItems", TRUE );
    bUseQuickSave = zoptions->ReadInt( pluginName, "bUseQuickSave", TRUE );
    bTrampleMeatbugs = zoptions->ReadInt( pluginName, "bTrampleMeatbugs", TRUE );
  }

}