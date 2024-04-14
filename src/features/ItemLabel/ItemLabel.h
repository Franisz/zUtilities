// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_NAMESPACE
{

  class ItemLabel
  {
  private:
    oCItem *item;

    zCOLOR color = zCOLOR(255, 255, 255);
    zSTRING texture = "UNKNOWN"; // https://game-icons.net/1x1/lorc/swap-bag.html

    void SetLabelParams();
    bool CanDrawLabel();

  public:
    ItemLabel(oCItem *item, zCViewBase *viewBase);
  };
}