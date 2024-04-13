// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_NAMESPACE
{
  namespace Options
  {
    bool RecoveryVisualization, ShowEnemyBarAboveHim;
    int StatusBarValueMode;
    Union::Array<Union::UnionStringA> StatusBarNames, HealthBarPos, ManaBarPos, SwimBarPos;

    void StatusBar()
    {
      RecoveryVisualization = zoptions->ReadBool(PLUGIN_NAME, "RecoveryVisualization", true);
      StatusBarValueMode = zoptions->ReadInt(PLUGIN_NAME, "StatusBarValueMode", 1);
      ShowEnemyBarAboveHim = zoptions->ReadBool(PLUGIN_NAME, "ShowEnemyBarAboveHim", true);
      StatusBarNames = Union::StringANSI(zoptions->ReadString(PLUGIN_NAME, "StatusBarNames", "")).Split("|");
      HealthBarPos = Union::StringANSI(zoptions->ReadString(PLUGIN_NAME, "HealthBarPos", "")).Split("|");
      ManaBarPos = Union::StringANSI(zoptions->ReadString(PLUGIN_NAME, "ManaBarPos", "")).Split("|");
      SwimBarPos = Union::StringANSI(zoptions->ReadString(PLUGIN_NAME, "SwimBarPos", "")).Split("|");
    }
  }

  class StatusBar
  {
  private:
    oCViewStatusBar *bar;
    zCView *valueView;
    zCView *predictView;
    zCView *focusView;
    zCArray<zSTRING> symbols;
    zSTRING name;
    Union::Array<Union::UnionStringA> userPos;

    bool Init();
    bool IsBarActive();
    int GetValueFromItem(oCItem *item, int atr);
    int GetHealValue();
    void DrawPrediction(int value);
    void PredictHeal();
    void PrintValue(oCNpc *npc);
    void MoveFocusBar(int x, int y, oCNpc *npc);
    void ChangeBarPos();

  public:
    enum ValueMode
    {
      Disabled,
      Above,
      PointToCenter,
      Inside
    };

    bool NeedAdjustPosition(int x, int y, oCNpc *npc);
    void Loop();
    void Clear();
    StatusBar(oCViewStatusBar *bar);
  };
}