// Supported with union (c) 2018 Union team

#ifndef __OHELP_H__VER3__
#define __OHELP_H__VER3__

namespace Gothic_II_Addon {

  class oCHelp {
  public:
    zCView* win;
    int dx;
    int dy;
    int sx;
    int sy;
    int x[4];
    int y[4];
    int index[4];
    int led[2];
    int ledx[2];
    int ledy[2];

    void oCHelp_OnInit()  zCall( 0x007015D0 );
    oCHelp()              zInit( oCHelp_OnInit() );
    ~oCHelp()             zCall( 0x00701D70 );
    void CalcPos()        zCall( 0x00701DA0 );
    void Toggle()         zCall( 0x00701E50 );
    void Update()         zCall( 0x00702000 );
    void Redraw( zCVob* ) zCall( 0x00702010 );

    // user API
    #include "oCHelp.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OHELP_H__VER3__