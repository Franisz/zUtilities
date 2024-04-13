// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    bool LabelItems, PutLabelBehind, LabelMissionItems;
    float LabelScale;

    void ItemLabel() {
      LabelItems = zoptions->ReadBool( PLUGIN_NAME, "LabelItems", true );
      LabelScale = zoptions->ReadReal( PLUGIN_NAME, "LabelScale", 1.25f );
      LabelMissionItems = zoptions->ReadBool( PLUGIN_NAME, "LabelMissionItems", false );
      PutLabelBehind = zoptions->ReadBool( PLUGIN_NAME, "PutLabelBehind", false );
    }
  }

  class ItemLabel {
  private:
    oCItem* item;

    zCOLOR color = zCOLOR( 255, 255, 255 );
    zSTRING texture = "UNKNOWN"; // https://game-icons.net/1x1/lorc/swap-bag.html

    void SetLabelParams();
    bool CanDrawLabel();

  public:
    ItemLabel( oCItem* item, zCViewBase* viewBase );
  };
}