// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_STATUSBAR_H__VER1__
#define __ZVIEW_STATUSBAR_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 114h
  class zCViewStatusBar : public zCView {
  public:
    float minLow;       // sizeof 04h    offset FCh
    float maxHigh;      // sizeof 04h    offset 100h
    float low;          // sizeof 04h    offset 104h
    float high;         // sizeof 04h    offset 108h
    float previewValue; // sizeof 04h    offset 10Ch
    float currentValue; // sizeof 04h    offset 110h

    void zCViewStatusBar_OnInit()                                  zCall( 0x00472370 );
    void zCViewStatusBar_OnInit( int, int, int, int, zTviewID )    zCall( 0x004723E0 );
    zCViewStatusBar()                                              zInit( zCViewStatusBar_OnInit() );
    zCViewStatusBar( int a0, int a1, int a2, int a3, zTviewID a4 ) zInit( zCViewStatusBar_OnInit( a0, a1, a2, a3, a4 ));
    void Init()                                                    zCall( 0x00472450 );
    /* for zCViewBase num : 15*/
    virtual ~zCViewStatusBar()                                     zCall( 0x00472480 );
    virtual void SetMaxRange( float, float )                       zCall( 0x004724A0 );
    virtual void SetRange( float, float )                          zCall( 0x00472540 );
    virtual void SetPreview( float )                               zCall( 0x004725E0 );
    virtual void SetValue( float )                                 zCall( 0x00472630 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCViewStatusBar.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZVIEW_STATUSBAR_H__VER1__