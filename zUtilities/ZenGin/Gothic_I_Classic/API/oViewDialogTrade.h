// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_DIALOG_TRADE_H__VER0__
#define __OVIEW_DIALOG_TRADE_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 118h
  class oCViewDialogTrade : public zCViewDialog {
  public:
    zCLASS_DECLARATION( oCViewDialogTrade )

    typedef enum zETradeDialogSection {
      TRADE_SECTION_LEFT_INVENTORY,
      TRADE_SECTION_LEFT_CONTAINER,
      TRADE_SECTION_RIGHT_CONTAINER,
      TRADE_SECTION_RIGHT_INVENTORY,
      TRADE_SECTION_CHOICE
    } zTTradeSection;

    typedef enum zETradeDialogChoice {
      TRADE_CHOICE_ACCEPT,
      TRADE_CHOICE_RESET,
      TRADE_CHOICE_EXIT
    } zTTradeChoice;

    typedef enum zETradeCharacter {
      TRADE_CHARACTER_NPC,
      TRADE_CHARACTER_PLAYER
    } zTTradeNPC;

    oCViewDialogStealContainer* DlgInventoryNpc;   // sizeof 04h    offset F8h
    oCViewDialogItemContainer* DlgContainerNpc;    // sizeof 04h    offset FCh
    zCViewDialogChoice* DlgChoice;                 // sizeof 04h    offset 100h
    oCViewDialogItemContainer* DlgContainerPlayer; // sizeof 04h    offset 104h
    oCViewDialogInventory* DlgInventoryPlayer;     // sizeof 04h    offset 108h
    zTTradeSection SectionTrade;                   // sizeof 04h    offset 10Ch
    oCNpc* NpcLeft;                                // sizeof 04h    offset 110h
    oCNpc* NpcRight;                               // sizeof 04h    offset 114h

    void oCViewDialogTrade_OnInit()                                     zCall( 0x00728B50 );
    void UpdateViewSettings()                                           zCall( 0x00728990 );
    oCViewDialogTrade()                                                 zInit( oCViewDialogTrade_OnInit() );
    void __fastcall AllDialogsStop()                                    zCall( 0x00729300 );
    void __fastcall AllDialogsDisable()                                 zCall( 0x00729340 );
    void __fastcall TransferAccept()                                    zCall( 0x00729390 );
    void __fastcall TransferReset()                                     zCall( 0x007293F0 );
    void __fastcall SetNpcLeft( oCNpc* )                                zCall( 0x00729440 );
    void __fastcall SetNpcRight( oCNpc* )                               zCall( 0x00729580 );
    void __fastcall Update()                                            zCall( 0x00729FD0 );
    int __fastcall OnKeyEnter()                                         zCall( 0x00729FF0 );
    int __fastcall OnKeyEsc()                                           zCall( 0x0072A100 );
    int __fastcall OnKeyLeft( int )                                     zCall( 0x0072A180 );
    int __fastcall OnMoveLeft()                                         zCall( 0x0072A230 );
    int __fastcall OnTransferLeft( int )                                zCall( 0x0072A2B0 );
    int __fastcall OnKeyRight( int )                                    zCall( 0x0072A400 );
    int __fastcall OnMoveRight()                                        zCall( 0x0072A4B0 );
    int __fastcall OnTransferRight( int )                               zCall( 0x0072A530 );
    int __fastcall OnSectionPrevious()                                  zCall( 0x0072A680 );
    int __fastcall OnSectionNext()                                      zCall( 0x0072A6A0 );
    void __fastcall OnSection( zETradeDialogSection )                   zCall( 0x0072A6C0 );
    void __fastcall OnChoice( zETradeDialogChoice )                     zCall( 0x0072A7A0 );
    void __fastcall OnAccept()                                          zCall( 0x0072A870 );
    void __fastcall OnRecline()                                         zCall( 0x0072A9E0 );
    void __fastcall OnBack()                                            zCall( 0x0072AA40 );
    void __fastcall OnReset()                                           zCall( 0x0072AA50 );
    void __fastcall OnExit()                                            zCall( 0x0072AAB0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00728900 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00729190 );
    virtual ~oCViewDialogTrade()                                        zCall( 0x007291D0 );
    virtual void __fastcall StartSelection()                            zCall( 0x00729660 );
    /* for zCViewBase num : 8*/
    /* for oCViewDialogTrade num : 1*/
    virtual int HandleEvent( int )                                      zCall( 0x007299A0 );

    // user API
    #include "oCViewDialogTrade.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OVIEW_DIALOG_TRADE_H__VER0__