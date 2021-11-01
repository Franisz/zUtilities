// Supported with union (c) 2018-2021 Union team

#ifndef __OMENU__HELP_H__VER2__
#define __OMENU__HELP_H__VER2__

#include "zMenu.h"

namespace Gothic_II_Classic {

  // sizeof 40h
  struct oSMenuKey {
    zSTRING name;         // sizeof 14h    offset 00h
    zSTRING internalName; // sizeof 14h    offset 14h
    zSTRING desc;         // sizeof 14h    offset 28h
    unsigned short key;   // sizeof 02h    offset 3Ch

    oSMenuKey() {}

    // user API
    #include "oSMenuKey.inl"
  };

  // sizeof CD0h
  class oCMenu_Help : public zCMenu {
  public:
    zCArray<oSMenuKey> keys; // sizeof 0Ch    offset CC4h

    oCMenu_Help() {}

    // user API
    #include "oCMenu_Help.inl"
  };

  // sizeof 04h
  class oCHelpScreen {
  public:
    oCMenu_Help* help; // sizeof 04h    offset 00h

    oCHelpScreen() {}

    // user API
    #include "oCHelpScreen.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OMENU__HELP_H__VER2__