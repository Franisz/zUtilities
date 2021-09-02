// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  class FocusColor {
  private:

    zCOLOR colDefault = zCOLOR( 255, 255, 255 );

    int TYPE_FRIEND;

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
}