// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_STATUSBAR_H__VER2__
#define __ZVIEW_STATUSBAR_H__VER2__

namespace Gothic_II_Classic {

  class zCViewStatusBar : public zCView {
  public:
    float minLow;
    float maxHigh;
    float low;
    float high;
    float previewValue;
    float currentValue;

    void zCViewStatusBar_OnInit()                                  zCall( 0x0046E970 );
    void zCViewStatusBar_OnInit( int, int, int, int, zTviewID )    zCall( 0x0046E9E0 );
    zCViewStatusBar()                                              zInit( zCViewStatusBar_OnInit() );
    zCViewStatusBar( int a0, int a1, int a2, int a3, zTviewID a4 ) zInit( zCViewStatusBar_OnInit( a0, a1, a2, a3, a4 ));
    void Init()                                                    zCall( 0x0046EA50 );
    /* for zCViewBase num : 16*/
    virtual ~zCViewStatusBar()                                     zCall( 0x0046EA80 );
    virtual void SetMaxRange( float, float )                       zCall( 0x0046EAA0 );
    virtual void SetRange( float, float )                          zCall( 0x0046EB40 );
    virtual void SetPreview( float )                               zCall( 0x0046EBE0 );
    virtual void SetValue( float )                                 zCall( 0x0046EC30 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCViewStatusBar.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVIEW_STATUSBAR_H__VER2__