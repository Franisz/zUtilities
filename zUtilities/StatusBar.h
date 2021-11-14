// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  class StatusBar {
  private:
    oCViewStatusBar* bar;
    zCView* predictView;
    int talent;
    int talentMax;
    zCArray<zSTRING> symbols;

    bool Init();
    int GetValueFromItem( oCItem* item );
    int GetHealValue();
    void Clear();
    void PredictHeal( int value );

  public:
    void Loop();
    StatusBar( oCViewStatusBar* bar );
  };
}