// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    int RecoveryVisualization, StatusBarValueMode, ShowEnemyBarAboveHim;

    void StatusBar() {
      RecoveryVisualization = zoptions->ReadInt( PLUGIN_NAME, "RecoveryVisualization", true );
      StatusBarValueMode = zoptions->ReadInt( PLUGIN_NAME, "StatusBarValueMode", 1 );
      ShowEnemyBarAboveHim = zoptions->ReadInt( PLUGIN_NAME, "ShowEnemyBarAboveHim", true );
    }
  }

  class StatusBar {
  private:
    oCViewStatusBar* bar;
    zCView* valueView;
    zCView* predictView;
    zCView* focusView;
    int talent;
    int talentMax;
    zCArray<zSTRING> symbols;

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
      Inside
    };

    bool NeedAdjustPosition( int x, int y, oCNpc* npc );
    void Loop();
    void Clear();
    StatusBar( oCViewStatusBar* bar );
  };
}