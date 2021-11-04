// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    bool UsingDebugHelper = false;
  }

  class DebugHelper {
  private:
    zCView* mainView;
    zCView* textView;
    zCView* sideView;

    int textLines;
    int textHeight;
    int margin;

    void InfoNpc( oCNpc* npc );
    void InfoItem( oCItem* item );
    void InfoMob( oCMOB* mob );
    void AddSeparator( zSTRING str = "" );
    void Print( zCView* view, zSTRING name, zSTRING value );
    bool TryPrintInfo();

  public:
    void Clear();
    void DebugHelperLoop();
  };

  DebugHelper debugHelper;
}