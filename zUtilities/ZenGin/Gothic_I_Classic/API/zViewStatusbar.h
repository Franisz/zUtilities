// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_STATUSBAR_H__VER0__
#define __ZVIEW_STATUSBAR_H__VER0__

#include "zView.h"

namespace Gothic_I_Classic {

  // sizeof 110h
  class zCViewStatusBar : public zCView {
  public:
    float minLow;       // sizeof 04h    offset FCh
    float maxHigh;      // sizeof 04h    offset 100h
    float low;          // sizeof 04h    offset 104h
    float high;         // sizeof 04h    offset 108h
    float currentValue; // sizeof 04h    offset 10Ch

    void zCViewStatusBar_OnInit()                                  zCall( 0x0046A200 );
    void zCViewStatusBar_OnInit( int, int, int, int, zTviewID )    zCall( 0x0046A270 );
    zCViewStatusBar()                                              zInit( zCViewStatusBar_OnInit() );
    zCViewStatusBar( int a0, int a1, int a2, int a3, zTviewID a4 ) zInit( zCViewStatusBar_OnInit( a0, a1, a2, a3, a4 ));
    void Init()                                                    zCall( 0x0046A2D0 );
    /* for zCViewBase num : 14*/
    virtual ~zCViewStatusBar()                                     zCall( 0x0046A300 );
    virtual void SetMaxRange( float, float )                       zCall( 0x0046A320 );
    virtual void SetRange( float, float )                          zCall( 0x0046A3C0 );
    virtual void SetValue( float )                                 zCall( 0x0046A460 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCViewStatusBar.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZVIEW_STATUSBAR_H__VER0__