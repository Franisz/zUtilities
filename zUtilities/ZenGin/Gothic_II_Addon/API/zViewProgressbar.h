// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_PROGRESSBAR_H__VER3__
#define __ZVIEW_PROGRESSBAR_H__VER3__

namespace Gothic_II_Addon {

  // sizeof 0Ch
  struct zTProgressRange {
    int iteration; // sizeof 04h    offset 00h
    float min;     // sizeof 04h    offset 04h
    float max;     // sizeof 04h    offset 08h

    zTProgressRange() {}

    // user API
    #include "zTProgressRange.inl"
  };

  // sizeof 130h
  class zCViewProgressBar : public zCView {
  public:
    zCView* bar;                       // sizeof 04h    offset 100h
    int minStep;                       // sizeof 04h    offset 104h
    int percent;                       // sizeof 04h    offset 108h
    zSTRING text;                      // sizeof 14h    offset 10Ch
    time_t start_time;                 // sizeof 08h    offset 120h
    zCList<zTProgressRange> rangeList; // sizeof 08h    offset 128h

    zCViewProgressBar() {}
    void zCViewProgressBar_OnInit( int, int, int, int, zTviewID )    zCall( 0x0046E9D0 );
    zCViewProgressBar( int a0, int a1, int a2, int a3, zTviewID a4 ) zInit( zCViewProgressBar_OnInit( a0, a1, a2, a3, a4 ));
    float CalcPercentOf( float, float, float )                       zCall( 0x0046EEA0 );
    void SetPercent( int, zSTRING )                                  zCall( 0x0046EEC0 );
    void SetRange( int, int )                                        zCall( 0x0046F340 );
    void ResetRange()                                                zCall( 0x0046F400 );
    /* for zCViewBase num : 15*/
    virtual ~zCViewProgressBar()                                     zCall( 0x0046EBE0 );
    virtual void Init()                                              zCall( 0x0046ED40 );
    virtual void HandleChange()                                      zCall( 0x0046F190 );
    virtual void Draw()                                              zCall( 0x0046F300 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCViewProgressBar.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVIEW_PROGRESSBAR_H__VER3__