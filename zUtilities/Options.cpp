// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

#define pluginName "ZUTILITIES"

  int bColorNpcs, bColorChests, bColorDoors;

  void initOptions() {
    bColorNpcs = zoptions->ReadInt( pluginName, "bColorNpcs", TRUE );
    bColorChests = zoptions->ReadInt( pluginName, "bColorChests", TRUE );
    bColorDoors = zoptions->ReadInt( pluginName, "bColorDoors", TRUE );
  }

}