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
    zCView* focusView;
    zCOLOR colDefault = zCOLOR( 255, 255, 255 );
    bool vobOnScreen = false;

    int TYPE_FRIEND;
    int CRIME_MURDER;

    void InitData();
    int GetAbsolutionLevel( oCNpc* slf );
    bool HasReasonToKill( oCNpc* slf );
    bool CanStealNow( oCItem* item );
    bool CanTakeFromRoom( oCItem* item );
    zSTRING GetName( zCVob* focusVob );
    zCOLOR GetFocusColor( zCVob* focusVob );
    zCOLOR LockableColor( oCMobLockable* focusLockable );
    zCOLOR DoorColor( oCMobDoor* focusDoor );
    zCOLOR ChestColor( oCMobContainer* focusContainer );
    zCOLOR NpcColor( oCNpc* focusNpc );
    zCOLOR ItemColor( oCItem* focusItem );
    bool TryPrintFocus( int x, int y, zSTRING name, zCVob* vob );

  public:
    bool CanPrintFocus( zCView* view, int x, int y, const zSTRING& text );
    void Clear();
    void Loop();
  };

  FocusColor focusColor;
}