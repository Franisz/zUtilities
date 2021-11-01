// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEWS_H__VER2__
#define __ZVIEWS_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 100h
  class zCViewWindow : public zCView {
  public:

    zCViewWindow() {}
    void zCViewWindow_OnInit( int, int, int, int, zTviewID )    zCall( 0x004FE880 );
    zCViewWindow( int a0, int a1, int a2, int a3, zTviewID a4 ) zInit( zCViewWindow_OnInit( a0, a1, a2, a3, a4 ));
    /* for zCViewBase num : 12*/
    virtual ~zCViewWindow()                                     zCall( 0x004FE920 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCViewWindow.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVIEWS_H__VER2__