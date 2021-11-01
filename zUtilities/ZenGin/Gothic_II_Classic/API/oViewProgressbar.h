// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_PROGRESSBAR_H__VER2__
#define __OVIEW_PROGRESSBAR_H__VER2__

#include "zViewProgressbar.h"

namespace Gothic_II_Classic {

  // sizeof 138h
  class oCViewGothicProgressBar : public zCViewProgressBar {
  public:
    int progressbar_sizex; // sizeof 04h    offset 130h

    oCViewGothicProgressBar() {}
    /* for zCViewBase num : 15*/
    virtual ~oCViewGothicProgressBar() zCall( 0x00665B10 );
    virtual void Init()                zCall( 0x0043CC80 );
    virtual void HandleChange()        zCall( 0x0043CCC0 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "oCViewGothicProgressBar.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OVIEW_PROGRESSBAR_H__VER2__