// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    bool UsingDebugHelper = false;
    bool ShowTriggers = false;
  }

  class DebugHelper {
  private:
    zCView* mainView;
    zCView* leftView;
    zCView* rightView;

    int textLinesLeft;
    int textLinesRight;
    int textHeight;
    int margin;

    void InfoNpc( oCNpc* npc );
    void InfoItem( oCItem* item );
    void InfoMob( oCMOB* mob );
    void AddSeparator( zCView* view, zSTRING str = "" );
    void Print( zCView* view, zSTRING name, zSTRING value );
    bool TryPrintInfo();
    void ShowTriggerBoxes();

  public:
    void Clear();
    void Loop();
  };

  DebugHelper debugHelper;
}