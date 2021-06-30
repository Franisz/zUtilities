// Supported with union (c) 2018 Union team

#ifndef __OVIEW_PROGRESSBAR_H__VER3__
#define __OVIEW_PROGRESSBAR_H__VER3__

#include "zViewProgressbar.h"

namespace Gothic_II_Addon {

  class oCViewGothicProgressBar : public zCViewProgressBar {
  public:
    int progressbar_sizex;

    oCViewGothicProgressBar() {}
    /* for zCViewBase num : 15*/
    virtual ~oCViewGothicProgressBar() zCall( 0x006C2610 );
    virtual void Init()                zCall( 0x0043D2B0 );
    virtual void HandleChange()        zCall( 0x0043D2F0 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "oCViewGothicProgressBar.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OVIEW_PROGRESSBAR_H__VER3__