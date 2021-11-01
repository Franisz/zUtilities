// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_STATUSBAR_H__VER3__
#define __ZVIEW_STATUSBAR_H__VER3__

namespace Gothic_II_Addon {

  // sizeof 118h
  class zCViewStatusBar : public zCView {
  public:
    float minLow;       // sizeof 04h    offset 100h
    float maxHigh;      // sizeof 04h    offset 104h
    float low;          // sizeof 04h    offset 108h
    float high;         // sizeof 04h    offset 10Ch
    float previewValue; // sizeof 04h    offset 110h
    float currentValue; // sizeof 04h    offset 114h

    void zCViewStatusBar_OnInit()                                  zCall( 0x0046F5A0 );
    void zCViewStatusBar_OnInit( int, int, int, int, zTviewID )    zCall( 0x0046F610 );
    zCViewStatusBar()                                              zInit( zCViewStatusBar_OnInit() );
    zCViewStatusBar( int a0, int a1, int a2, int a3, zTviewID a4 ) zInit( zCViewStatusBar_OnInit( a0, a1, a2, a3, a4 ));
    void Init()                                                    zCall( 0x0046F680 );
    /* for zCViewBase num : 16*/
    virtual ~zCViewStatusBar()                                     zCall( 0x0046F6B0 );
    virtual void SetMaxRange( float, float )                       zCall( 0x0046F6D0 );
    virtual void SetRange( float, float )                          zCall( 0x0046F770 );
    virtual void SetPreview( float )                               zCall( 0x0046F810 );
    virtual void SetValue( float )                                 zCall( 0x0046F860 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCViewStatusBar.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVIEW_STATUSBAR_H__VER3__