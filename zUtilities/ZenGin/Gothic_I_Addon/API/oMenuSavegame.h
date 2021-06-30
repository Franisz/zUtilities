// Supported with union (c) 2018 Union team

#ifndef __OMENU_SAVEGAME_H__VER1__
#define __OMENU_SAVEGAME_H__VER1__

#include "oMenu_Main.h"
#include "oSavegame.h"

namespace Gothic_I_Addon {

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
    void oCMenuSavegame_OnInit( zSTRING const&, oTMenuSavegameMode ) zCall( 0x0042F3B0 );
    oCMenuSavegame( zSTRING const& a0, oTMenuSavegameMode a1 )       zInit( oCMenuSavegame_OnInit( a0, a1 ));
    int GetMenuItemSlotNr( zCMenuItem* )                             zCall( 0x00430930 );
    void SetScreenshot( zCTextureConvert* )                          zCall( 0x00430AD0 );
    virtual int HandleEvent( int )                                   zCall( 0x0042F970 );
    virtual void Activate()                                          zCall( 0x0042F4F0 );
    virtual ~oCMenuSavegame()                                        zCall( 0x0042F440 );
    virtual void ScreenInit()                                        zCall( 0x0042F9D0 );
    virtual void ScreenDone()                                        zCall( 0x00430340 );
    virtual void HandleSlotChange( int )                             zCall( 0x0042F500 );
    virtual int GetSelectedSlot()                                    zCall( 0x00430AC0 );

    // user API
    #include "oCMenuSavegame.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OMENU_SAVEGAME_H__VER1__