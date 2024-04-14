// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_NAMESPACE
{
  class StatusBar
  {
  private:
    oCViewStatusBar *bar;
    zCView *valueView = {};
    zCView *predictView = {};
    zCView *focusView = {};
    zCArray<zSTRING> symbols = {};
    zSTRING name = {};
    Union::Array<Union::UnionStringA> userPos = {};

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