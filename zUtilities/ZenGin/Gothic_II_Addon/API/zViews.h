// Supported with union (c) 2018 Union team

#ifndef __ZVIEWS_H__VER3__
#define __ZVIEWS_H__VER3__

namespace Gothic_II_Addon {

  class zCViewWindow : public zCView {
  public:

    zCViewWindow() {}
    void zCViewWindow_OnInit( int, int, int, int, zTviewID )    zCall( 0x00501500 );
    zCViewWindow( int a0, int a1, int a2, int a3, zTviewID a4 ) zInit( zCViewWindow_OnInit( a0, a1, a2, a3, a4 ));
    /* for zCViewBase num : 12*/
    virtual ~zCViewWindow()                                     zCall( 0x005015A0 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCViewWindow.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVIEWS_H__VER3__