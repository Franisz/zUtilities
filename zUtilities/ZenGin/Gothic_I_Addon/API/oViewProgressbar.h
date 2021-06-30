// Supported with union (c) 2018 Union team

#ifndef __OVIEW_PROGRESSBAR_H__VER1__
#define __OVIEW_PROGRESSBAR_H__VER1__

#include "zViewProgressbar.h"

namespace Gothic_I_Addon {

  class oCViewGothicProgressBar : public zCViewProgressBar {
  public:
    int progressbar_sizex;

    oCViewGothicProgressBar() {}
    /* for zCViewBase num : 14*/
    virtual ~oCViewGothicProgressBar() zCall( 0x0065E920 );
    virtual void Init()                zCall( 0x0043E300 );
    virtual void HandleChange()        zCall( 0x0043E340 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "oCViewGothicProgressBar.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OVIEW_PROGRESSBAR_H__VER1__