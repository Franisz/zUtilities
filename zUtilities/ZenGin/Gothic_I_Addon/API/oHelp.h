// Supported with union (c) 2018 Union team

#ifndef __OHELP_H__VER1__
#define __OHELP_H__VER1__

namespace Gothic_I_Addon {

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

    void oCHelp_OnInit()  zCall( 0x00690640 );
    oCHelp()              zInit( oCHelp_OnInit() );
    ~oCHelp()             zCall( 0x00690FD0 );
    void CalcPos()        zCall( 0x00691000 );
    void Toggle()         zCall( 0x006910B0 );
    void Update()         zCall( 0x00691270 );
    void Redraw( zCVob* ) zCall( 0x00691280 );

    // user API
    #include "oCHelp.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OHELP_H__VER1__