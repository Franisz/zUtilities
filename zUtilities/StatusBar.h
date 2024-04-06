// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    bool RecoveryVisualization, ShowEnemyBarAboveHim;
    int StatusBarValueMode;
    Array<string> StatusBarNames, HealthBarPos, ManaBarPos, SwimBarPos;

    void LoadStatusBarSettings() {
      RecoveryVisualization = zoptions->ReadBool( PLUGIN_NAME, "RecoveryVisualization", true );
      StatusBarValueMode = zoptions->ReadInt( PLUGIN_NAME, "StatusBarValueMode", 1 );
      ShowEnemyBarAboveHim = zoptions->ReadBool( PLUGIN_NAME, "ShowEnemyBarAboveHim", true );
      StatusBarNames = (A zoptions->ReadString( PLUGIN_NAME, "StatusBarNames", "" )).Split( "|" );
      HealthBarPos = (A zoptions->ReadString( PLUGIN_NAME, "HealthBarPos", "" )).Split( "|" );
      ManaBarPos = (A zoptions->ReadString( PLUGIN_NAME, "ManaBarPos", "" )).Split( "|" );
      SwimBarPos = (A zoptions->ReadString( PLUGIN_NAME, "SwimBarPos", "" )).Split( "|" );
    }
  }

  class StatusBar {
  private:

    zCView* predictView;
    zCView* focusView;

    int GetValueFromItem( oCItem* item, int atr );
    int GetRestoreValue();
    void DrawPrediction( int value );
    void PredictRestore();
    
    void ChangeBarPos();


  protected:
      zCView* valueView;
      oCViewStatusBar* bar;
      int restoreAttribute = -1;
      zCArray<zSTRING> symbols;
      zSTRING name;
      Array<string> userPos;
      void PrintValue(oCNpc* npc);
      bool IsBarActive();
      StatusBar(oCViewStatusBar* bar);
      virtual bool Init();
      virtual zSTRING GetBarValue();
      bool CanLoop();
      virtual bool ShouldReverseValuePos();

  public:
    enum ValueMode {
      Disabled,
      Above,
      PointToCenter,
      Inside
    };

    virtual void Loop();
    void Clear();
  };
}