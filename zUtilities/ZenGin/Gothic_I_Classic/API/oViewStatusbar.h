// Supported with union (c) 2018 Union team

#ifndef __OVIEW_STATUSBAR_H__VER0__
#define __OVIEW_STATUSBAR_H__VER0__

#include "zViewStatusbar.h"

namespace Gothic_I_Classic {

  class oCViewStatusBar : public zCViewStatusBar {
  public:
    float scale;
    zCView* range_bar;
    zCView* value_bar;
    zSTRING texView;
    zSTRING texRange;
    zSTRING texValue;

    void oCViewStatusBar_OnInit()                                      zCall( 0x00439990 );
    void oCViewStatusBar_OnInit( int, int, int, int, zTviewID )        zCall( 0x00439AC0 );
    oCViewStatusBar()                                                  zInit( oCViewStatusBar_OnInit() );
    oCViewStatusBar( int a0, int a1, int a2, int a3, zTviewID a4 )     zInit( oCViewStatusBar_OnInit( a0, a1, a2, a3, a4 ));
    void Init( int, int, float )                                       zCall( 0x00439BA0 );
    void SetTextures( zSTRING const&, zSTRING const&, zSTRING const& ) zCall( 0x00439D40 );
    /* for zCViewBase num : 14*/
    virtual ~oCViewStatusBar()                                         zCall( 0x00439FE0 );
    virtual void SetMaxRange( float, float )                           zCall( 0x0043A130 );
    virtual void SetRange( float, float )                              zCall( 0x0043A240 );
    virtual void SetValue( float )                                     zCall( 0x0043A300 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "oCViewStatusBar.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OVIEW_STATUSBAR_H__VER0__