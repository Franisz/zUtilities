// Supported with union (c) 2018-2021 Union team

#ifndef __OHELP_H__VER0__
#define __OHELP_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 5Ch
  class oCHelp {
  public:
    zCView* win;  // sizeof 04h    offset 00h
    int dx;       // sizeof 04h    offset 04h
    int dy;       // sizeof 04h    offset 08h
    int sx;       // sizeof 04h    offset 0Ch
    int sy;       // sizeof 04h    offset 10h
    int x[4];     // sizeof 10h    offset 14h
    int y[4];     // sizeof 10h    offset 24h
    int index[4]; // sizeof 10h    offset 34h
    int led[2];   // sizeof 08h    offset 44h
    int ledx[2];  // sizeof 08h    offset 4Ch
    int ledy[2];  // sizeof 08h    offset 54h

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