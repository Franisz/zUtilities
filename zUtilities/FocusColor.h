// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  class FocusColor {
  private:

    zCOLOR colDefault = zCOLOR( 255, 255, 255 );

    int GetAbsolutionLevel( oCNpc* slf );
    zCOLOR CheckFocus();
    zCOLOR DoorColor( oCMobDoor* focusDoor );
    zCOLOR ChestColor( oCMobContainer* focusContainer );
    zCOLOR NpcColor( oCNpc* focusNpc );

  public:

    void FocusColorLoop();

  };
}