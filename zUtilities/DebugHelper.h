// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  namespace Options {
    bool UsingDebugHelper = true;
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
    void InfoInter( oCMobInter* inter );
    void InfoItem( oCItem* item );
    void AddSeparator( zSTRING str = "" );
    void Print( zCView* view, zSTRING name, zSTRING value );
    void PrintInfo( zCVob* vob );

  public:
    void Clear();
    void DebugHelperLoop();
  };

  DebugHelper debugHelper;
}