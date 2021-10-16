// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  class ItemLabel {
  private:

    oCItem* item;
    int condAtr;

    zCOLOR color = zCOLOR( 255, 255, 255 );
    zSTRING texture = "UNKNOWN"; // https://game-icons.net/1x1/lorc/swap-bag.html

    void SetLabelParams();

  public:

    ItemLabel( oCItem* item, zCViewBase* viewBase );

  };
}