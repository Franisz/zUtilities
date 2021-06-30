// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_PROGRESSBAR_H__VER1__
#define __ZVIEW_PROGRESSBAR_H__VER1__

namespace Gothic_I_Addon {

  struct zTProgressRange {
    int iteration;
    float min;
    float max;

    zTProgressRange() {}

    // user API
    #include "zTProgressRange.inl"
  };

  class zCViewProgressBar : public zCView {
  public:
    zCView* bar;
    int minStep;
    int percent;
    zSTRING text;
    time_t start_time;
    zCList<zTProgressRange> rangeList;

    zCViewProgressBar() {}
    void zCViewProgressBar_OnInit( int, int, int, int, zTviewID )    zCall( 0x00471830 );
    zCViewProgressBar( int a0, int a1, int a2, int a3, zTviewID a4 ) zInit( zCViewProgressBar_OnInit( a0, a1, a2, a3, a4 ));
    float CalcPercentOf( float, float, float )                       zCall( 0x00471CF0 );
    void SetPercent( int, zSTRING )                                  zCall( 0x00471D10 );
    void SetRange( int, int )                                        zCall( 0x004720F0 );
    void ResetRange()                                                zCall( 0x004721C0 );
    /* for zCViewBase num : 14*/
    virtual ~zCViewProgressBar()                                     zCall( 0x00471A40 );
    virtual void Init()                                              zCall( 0x00471BA0 );
    virtual void HandleChange()                                      zCall( 0x00471FB0 );
    virtual void Draw()                                              zCall( 0x004720B0 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCViewProgressBar.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZVIEW_PROGRESSBAR_H__VER1__