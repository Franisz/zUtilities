// Supported with union (c) 2018 Union team

#ifndef __OVIEW_STATUSBAR_H__VER2__
#define __OVIEW_STATUSBAR_H__VER2__

#include "zViewStatusbar.h"

namespace Gothic_II_Classic {

  class oCViewStatusBar : public zCViewStatusBar {
  public:
    float scale;
    zCView* range_bar;
    zCView* value_bar;
    zSTRING texView;
    zSTRING texRange;
    zSTRING texValue;

    void oCViewStatusBar_OnInit()                                                      zCall( 0x0043CDE0 );
    void oCViewStatusBar_OnInit( int, int, int, int, zTviewID )                        zCall( 0x0043CF10 );
    oCViewStatusBar()                                                                  zInit( oCViewStatusBar_OnInit() );
    oCViewStatusBar( int a0, int a1, int a2, int a3, zTviewID a4 )                     zInit( oCViewStatusBar_OnInit( a0, a1, a2, a3, a4 ));
    void Init( int, int, float )                                                       zCall( 0x0043CFF0 );
    void SetTextures( zSTRING const&, zSTRING const&, zSTRING const&, zSTRING const& ) zCall( 0x0043D180 );
    /* for zCViewBase num : 16*/
    virtual ~oCViewStatusBar()                                                         zCall( 0x0043D420 );
    virtual void SetMaxRange( float, float )                                           zCall( 0x0043D570 );
    virtual void SetRange( float, float )                                              zCall( 0x0043D680 );
    virtual void SetPreview( float )                                                   zCall( 0x0043D750 );
    virtual void SetValue( float )                                                     zCall( 0x0043D760 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "oCViewStatusBar.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OVIEW_STATUSBAR_H__VER2__