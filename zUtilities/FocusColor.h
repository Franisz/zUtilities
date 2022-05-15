// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    int ColorNpcs, ColorLockables, ColorItems, ColorInter;

    void FocusColor() {
      ColorNpcs = zoptions->ReadBool( PLUGIN_NAME, "ColorNpcs", true );
      ColorLockables = zoptions->ReadBool( PLUGIN_NAME, "ColorLockables", true );
      ColorItems = zoptions->ReadBool( PLUGIN_NAME, "ColorItems", true );
      ColorInter = zoptions->ReadBool( PLUGIN_NAME, "ColorInter", true );
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
    zSTRING GetName( zCVob* vob );
    zCOLOR GetFocusColor( zCVob* vob );
    zCOLOR LockableColor( oCMobLockable* lockable );
    zCOLOR InterColor( oCMobInter* inter );
    zCOLOR NpcColor( oCNpc* npc );
    zCOLOR ItemColor( oCItem* item );
    bool TryPrintFocus( int x, int y, zSTRING name, zCVob* vob );
    void TryAddIcons( int x, int y, zSTRING name, oCNpc* npc );

  public:
    bool CanPrintFocus( zCView* view, int x, int y, const zSTRING& text );
    void Clear();
    void Loop();
  };

  FocusColor focusColor;
}