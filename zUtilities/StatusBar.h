// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    int RecoveryVisualization, StatusBarValueMode;

    void StatusBar() {
      RecoveryVisualization = zoptions->ReadInt( PLUGIN_NAME, "RecoveryVisualization", true );
      StatusBarValueMode = zoptions->ReadInt( PLUGIN_NAME, "StatusBarValueMode", 1 );
    }
  }

  class StatusBar {
  private:
    oCViewStatusBar* bar;
    zCView* valueView;
    zCView* predictView;
    int talent;
    int talentMax;
    zCArray<zSTRING> symbols;

    bool Init();
    bool IsBarActive();
    int GetValueFromItem( oCItem* item );
    int GetHealValue();
    void DrawPrediction( int value );
    void PredictHeal();
    void PrintValue();

  public:
    enum ValueMode {
      Disabled,
      Inside,
      Above
    };

    void Loop();
    StatusBar( oCViewStatusBar* bar );
  };
}