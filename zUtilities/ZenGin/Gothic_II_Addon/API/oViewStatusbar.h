// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_STATUSBAR_H__VER3__
#define __OVIEW_STATUSBAR_H__VER3__

#include "zViewStatusbar.h"

namespace Gothic_II_Addon {

  // sizeof 160h
  class oCViewStatusBar : public zCViewStatusBar {
  public:
    float scale;       // sizeof 04h    offset 118h
    zCView* range_bar; // sizeof 04h    offset 11Ch
    zCView* value_bar; // sizeof 04h    offset 120h
    zSTRING texView;   // sizeof 14h    offset 124h
    zSTRING texRange;  // sizeof 14h    offset 138h
    zSTRING texValue;  // sizeof 14h    offset 14Ch

    void oCViewStatusBar_OnInit()                                                      zCall( 0x0043D410 );
    void oCViewStatusBar_OnInit( int, int, int, int, zTviewID )                        zCall( 0x0043D540 );
    oCViewStatusBar()                                                                  zInit( oCViewStatusBar_OnInit() );
    oCViewStatusBar( int a0, int a1, int a2, int a3, zTviewID a4 )                     zInit( oCViewStatusBar_OnInit( a0, a1, a2, a3, a4 ));
    void Init( int, int, float )                                                       zCall( 0x0043D620 );
    void SetTextures( zSTRING const&, zSTRING const&, zSTRING const&, zSTRING const& ) zCall( 0x0043D7B0 );
    /* for zCViewBase num : 16*/
    virtual ~oCViewStatusBar()                                                         zCall( 0x0043DA50 );
    virtual void SetMaxRange( float, float )                                           zCall( 0x0043DBA0 );
    virtual void SetRange( float, float )                                              zCall( 0x0043DCB0 );
    virtual void SetPreview( float )                                                   zCall( 0x0043DD80 );
    virtual void SetValue( float )                                                     zCall( 0x0043DD90 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "oCViewStatusBar.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OVIEW_STATUSBAR_H__VER3__