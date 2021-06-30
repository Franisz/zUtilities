// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_PROGRESSBAR_H__VER0__
#define __ZVIEW_PROGRESSBAR_H__VER0__

#include "zView.h"

namespace Gothic_I_Classic {

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
    void zCViewProgressBar_OnInit( int, int, int, int, zTviewID )    zCall( 0x004696F0 );
    zCViewProgressBar( int a0, int a1, int a2, int a3, zTviewID a4 ) zInit( zCViewProgressBar_OnInit( a0, a1, a2, a3, a4 ));
    float CalcPercentOf( float, float, float )                       zCall( 0x00469BC0 );
    void SetPercent( int, zSTRING )                                  zCall( 0x00469BE0 );
    void SetRange( int, int )                                        zCall( 0x00469F70 );
    void ResetRange()                                                zCall( 0x0046A050 );
    /* for zCViewBase num : 14*/
    virtual ~zCViewProgressBar()                                     zCall( 0x00469900 );
    virtual void Init()                                              zCall( 0x00469A60 );
    virtual void HandleChange()                                      zCall( 0x00469E40 );
    virtual void Draw()                                              zCall( 0x00469F30 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCViewProgressBar.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZVIEW_PROGRESSBAR_H__VER0__