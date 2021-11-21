// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    int RecoveryVisualization, StatusBarValueMode, ShowEnemyBarAboveHim;
    Array<string> StatusBarNames;

    void StatusBar() {
      RecoveryVisualization = zoptions->ReadInt( PLUGIN_NAME, "RecoveryVisualization", true );
      StatusBarValueMode = zoptions->ReadInt( PLUGIN_NAME, "StatusBarValueMode", 1 );
      ShowEnemyBarAboveHim = zoptions->ReadInt( PLUGIN_NAME, "ShowEnemyBarAboveHim", true );
      StatusBarNames = (A zoptions->ReadString( PLUGIN_NAME, "StatusBarNames", "" )).Split( "|" );
    }
  }

  class StatusBar {
  private:
    oCViewStatusBar* bar;
    zCView* valueView;
    zCView* predictView;
    zCView* focusView;
    zCArray<zSTRING> symbols;
    zSTRING name;

    bool Init();
    bool IsBarActive();
    int GetValueFromItem( oCItem* item );
    int GetHealValue();
    void DrawPrediction( int value );
    void PredictHeal();
    void PrintValue( oCNpc* npc );
    void MoveFocusBar( int x, int y, oCNpc* npc );

  public:
    enum ValueMode {
      Disabled,
      Above,
      PointToCenter,
      Inside
    };

    bool NeedAdjustPosition( int x, int y, oCNpc* npc );
    void Loop();
    void Clear();
    StatusBar( oCViewStatusBar* bar );
  };
}