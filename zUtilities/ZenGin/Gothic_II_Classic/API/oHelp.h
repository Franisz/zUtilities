// Supported with union (c) 2018 Union team

#ifndef __OHELP_H__VER2__
#define __OHELP_H__VER2__

namespace Gothic_II_Classic {

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

    void oCHelp_OnInit()  zCall( 0x006A3B40 );
    oCHelp()              zInit( oCHelp_OnInit() );
    ~oCHelp()             zCall( 0x006A42E0 );
    void CalcPos()        zCall( 0x006A4310 );
    void Toggle()         zCall( 0x006A43C0 );
    void Update()         zCall( 0x006A4570 );
    void Redraw( zCVob* ) zCall( 0x006A4580 );

    // user API
    #include "oCHelp.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OHELP_H__VER2__