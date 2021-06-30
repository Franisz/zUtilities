// Supported with union (c) 2018 Union team

#ifndef __OMENU_SAVEGAME_H__VER2__
#define __OMENU_SAVEGAME_H__VER2__

#include "oMenu_Main.h"
#include "oSavegame.h"

namespace Gothic_II_Classic {

  class oCMenuSavegame : public oCMenu_Main {
  public:
    enum oTMenuSavegameMode {
      SAVE,
      LOAD
    };

    oTMenuSavegameMode mode;
    oCSavegameManager* savegameManager;
    int m_selSlot;
    int m_selSlotItemIndex;
    zCTexture* m_thumbPic;
    zCMenuItem* m_item_PlayTime;
    zCMenuItem* m_item_DateTime;
    zCMenuItem* m_item_WorldName;
    zCMenuItem* m_item_GameTime;
    zCMenuItem* m_item_Thumbpic;
    zCView* m_item_Thumbpic2;

    oCMenuSavegame() {}
    void oCMenuSavegame_OnInit( zSTRING const&, oTMenuSavegameMode ) zCall( 0x0042E4D0 );
    oCMenuSavegame( zSTRING const& a0, oTMenuSavegameMode a1 )       zInit( oCMenuSavegame_OnInit( a0, a1 ));
    int GetMenuItemSlotNr( zCMenuItem* )                             zCall( 0x0042FC10 );
    void SetScreenshot( zCTextureConvert* )                          zCall( 0x0042FDE0 );
    virtual int HandleEvent( int )                                   zCall( 0x0042EE60 );
    virtual void Activate()                                          zCall( 0x0042E610 );
    virtual ~oCMenuSavegame()                                        zCall( 0x0042E560 );
    virtual void ScreenInit()                                        zCall( 0x0042EEC0 );
    virtual void ScreenDone()                                        zCall( 0x0042F710 );
    virtual void HandleSlotChange( int )                             zCall( 0x0042E620 );
    virtual int GetSelectedSlot()                                    zCall( 0x0042FDD0 );

    // user API
    #include "oCMenuSavegame.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OMENU_SAVEGAME_H__VER2__