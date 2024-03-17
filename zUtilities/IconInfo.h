// Supported with union (c) 2020 Union team
// Union HEADER file

namespace GOTHIC_ENGINE {
  class IconInfo {
  private:
    int vx;
    int vy;
    int vsize;

    int px1;
    int px2;
    int py1;
    int py2;
    int psize;

    zCOLOR color;
    zSTRING texName;
    zSTRING text;

    void Draw();
    void DrawIcon();
    void PrintText();
    void RestoreViewport();

  public:
    IconInfo( int x, int y, int size, zCOLOR color, zSTRING texName, zSTRING text );
  };
}