// Supported with union (c) 2018 Union team

#ifndef __OVIEW_STATUSBAR_H__VER1__
#define __OVIEW_STATUSBAR_H__VER1__

#include "zViewStatusbar.h"

namespace Gothic_I_Addon {

  class oCViewStatusBar : public zCViewStatusBar {
  public:
    float scale;
    zCView* range_bar;
    zCView* preview_bar;
    zCView* value_bar;
    zSTRING texView;
    zSTRING texRange;
    zSTRING texPreview;
    zSTRING texValue;

    void oCViewStatusBar_OnInit()                                                      zCall( 0x0043E460 );
    void oCViewStatusBar_OnInit( int, int, int, int, zTviewID )                        zCall( 0x0043E5B0 );
    oCViewStatusBar()                                                                  zInit( oCViewStatusBar_OnInit() );
    oCViewStatusBar( int a0, int a1, int a2, int a3, zTviewID a4 )                     zInit( oCViewStatusBar_OnInit( a0, a1, a2, a3, a4 ));
    void Init( int, int, float )                                                       zCall( 0x0043E6C0 );
    void SetTextures( zSTRING const&, zSTRING const&, zSTRING const&, zSTRING const& ) zCall( 0x0043E8E0 );
    /* for zCViewBase num : 15*/
    virtual ~oCViewStatusBar()                                                         zCall( 0x0043EC10 );
    virtual void SetMaxRange( float, float )                                           zCall( 0x0043EDC0 );
    virtual void SetRange( float, float )                                              zCall( 0x0043EEE0 );
    virtual void SetPreview( float )                                                   zCall( 0x0043EFB0 );
    virtual void SetValue( float )                                                     zCall( 0x0043F020 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "oCViewStatusBar.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OVIEW_STATUSBAR_H__VER1__