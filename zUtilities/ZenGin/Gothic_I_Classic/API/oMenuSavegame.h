// Supported with union (c) 2018-2021 Union team

#ifndef __OMENU_SAVEGAME_H__VER0__
#define __OMENU_SAVEGAME_H__VER0__

#include "oMenu_Main.h"
#include "oSavegame.h"

namespace Gothic_I_Classic {

  // sizeof CF0h
  class oCMenuSavegame : public oCMenu_Main {
  public:
    enum oTMenuSavegameMode {
      SAVE,
      LOAD
    };

    oTMenuSavegameMode mode;            // sizeof 04h    offset CC4h
    oCSavegameManager* savegameManager; // sizeof 04h    offset CC8h
    int m_selSlot;                      // sizeof 04h    offset CCCh
    int m_selSlotItemIndex;             // sizeof 04h    offset CD0h
    zCTexture* m_thumbPic;              // sizeof 04h    offset CD4h
    zCMenuItem* m_item_PlayTime;        // sizeof 04h    offset CD8h
    zCMenuItem* m_item_DateTime;        // sizeof 04h    offset CDCh
    zCMenuItem* m_item_WorldName;       // sizeof 04h    offset CE0h
    zCMenuItem* m_item_GameTime;        // sizeof 04h    offset CE4h
    zCMenuItem* m_item_Thumbpic;        // sizeof 04h    offset CE8h
    zCView* m_item_Thumbpic2;           // sizeof 04h    offset CECh

    oCMenuSavegame() {}
    void oCMenuSavegame_OnInit( zSTRING const&, oTMenuSavegameMode ) zCall( 0x0042C2D0 );
    oCMenuSavegame( zSTRING const& a0, oTMenuSavegameMode a1 )       zInit( oCMenuSavegame_OnInit( a0, a1 ));
    int GetMenuItemSlotNr( zCMenuItem* )                             zCall( 0x0042D6E0 );
    void SetScreenshot( zCTextureConvert* )                          zCall( 0x0042D850 );
    virtual int HandleEvent( int )                                   zCall( 0x0042C830 );
    virtual void Activate()                                          zCall( 0x0042C410 );
    virtual ~oCMenuSavegame()                                        zCall( 0x0042C360 );
    virtual void ScreenInit()                                        zCall( 0x0042C890 );
    virtual void ScreenDone()                                        zCall( 0x0042D170 );
    virtual void HandleSlotChange( int )                             zCall( 0x0042C420 );
    virtual int GetSelectedSlot()                                    zCall( 0x0042D840 );

    // user API
    #include "oCMenuSavegame.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OMENU_SAVEGAME_H__VER0__