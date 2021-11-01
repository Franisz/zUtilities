// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    int ColorNpcs, ColorChests, ColorDoors, ColorItems;

    void FocusColor() {
      ColorNpcs = zoptions->ReadInt( PLUGIN_NAME, "ColorNpcs", true );
      ColorChests = zoptions->ReadInt( PLUGIN_NAME, "ColorChests", true );
      ColorDoors = zoptions->ReadInt( PLUGIN_NAME, "ColorDoors", true );
      ColorItems = zoptions->ReadInt( PLUGIN_NAME, "ColorItems", true );
    }
  }

  class FocusColor {
  private:
    zCOLOR colDefault = zCOLOR( 255, 255, 255 );

    int TYPE_FRIEND;
    int CRIME_MURDER;

    void InitData();
    int GetAbsolutionLevel( oCNpc* slf );
    bool HasReasonToKill( oCNpc* slf );
    bool CanStealNow( oCItem* item );
    bool CanTakeFromRoom( oCItem* item );
    zCOLOR CheckFocus();
    zCOLOR DoorColor( oCMobDoor* focusDoor );
    zCOLOR ChestColor( oCMobContainer* focusContainer );
    zCOLOR NpcColor( oCNpc* focusNpc );
    zCOLOR ItemColor( oCItem* focusItem );

  public:
    void FocusColorLoop();
  };

  FocusColor focusColor;
}