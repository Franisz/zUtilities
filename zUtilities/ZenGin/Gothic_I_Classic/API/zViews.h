// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEWS_H__VER0__
#define __ZVIEWS_H__VER0__

#include "zView.h"

namespace Gothic_I_Classic {

  // sizeof FCh
  class zCViewWindow : public zCView {
  public:

    zCViewWindow() {}
    void zCViewWindow_OnInit( int, int, int, int, zTviewID )    zCall( 0x004F2FC0 );
    zCViewWindow( int a0, int a1, int a2, int a3, zTviewID a4 ) zInit( zCViewWindow_OnInit( a0, a1, a2, a3, a4 ));
    /* for zCViewBase num : 11*/
    virtual ~zCViewWindow()                                     zCall( 0x004F3060 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCViewWindow.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZVIEWS_H__VER0__