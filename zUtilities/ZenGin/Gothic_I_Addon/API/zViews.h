// Supported with union (c) 2018 Union team

#ifndef __ZVIEWS_H__VER1__
#define __ZVIEWS_H__VER1__

namespace Gothic_I_Addon {

  class zCViewWindow : public zCView {
  public:

    zCViewWindow() {}
    void zCViewWindow_OnInit( int, int, int, int, zTviewID )    zCall( 0x00505970 );
    zCViewWindow( int a0, int a1, int a2, int a3, zTviewID a4 ) zInit( zCViewWindow_OnInit( a0, a1, a2, a3, a4 ));
    /* for zCViewBase num : 11*/
    virtual ~zCViewWindow()                                     zCall( 0x00505A10 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCViewWindow.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZVIEWS_H__VER1__