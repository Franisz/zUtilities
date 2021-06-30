// Supported with union (c) 2018 Union team

#ifndef __OHELP_H__VER0__
#define __OHELP_H__VER0__

namespace Gothic_I_Classic {

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

    void oCHelp_OnInit()  zCall( 0x00663790 );
    oCHelp()              zInit( oCHelp_OnInit() );
    ~oCHelp()             zCall( 0x00664080 );
    void CalcPos()        zCall( 0x006640B0 );
    void Toggle()         zCall( 0x00664160 );
    void Update()         zCall( 0x00664310 );
    void Redraw( zCVob* ) zCall( 0x00664320 );

    // user API
    #include "oCHelp.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OHELP_H__VER0__