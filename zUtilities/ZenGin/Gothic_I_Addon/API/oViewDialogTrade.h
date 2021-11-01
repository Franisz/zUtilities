// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_DIALOG_TRADE_H__VER1__
#define __OVIEW_DIALOG_TRADE_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 11Ch
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
    short TransferCount;                           // sizeof 02h    offset 118h

    void oCViewDialogTrade_OnInit()                                     zCall( 0x00766910 );
    void UpdateViewSettings()                                           zCall( 0x00766750 );
    oCViewDialogTrade()                                                 zInit( oCViewDialogTrade_OnInit() );
    void __fastcall AllDialogsStop()                                    zCall( 0x007671A0 );
    void __fastcall AllDialogsDisable()                                 zCall( 0x007671E0 );
    void __fastcall TransferAccept()                                    zCall( 0x00767230 );
    void __fastcall TransferReset()                                     zCall( 0x00767290 );
    void __fastcall SetNpcLeft( oCNpc* )                                zCall( 0x007672E0 );
    void __fastcall SetNpcRight( oCNpc* )                               zCall( 0x00767420 );
    void __fastcall Update()                                            zCall( 0x00767EB0 );
    int __fastcall OnKeyEnter()                                         zCall( 0x00767ED0 );
    int __fastcall OnKeyEsc()                                           zCall( 0x00767FD0 );
    int __fastcall OnKeyLeft( int )                                     zCall( 0x00768050 );
    int __fastcall OnMoveLeft()                                         zCall( 0x00768130 );
    int __fastcall OnTransferLeft( int )                                zCall( 0x007681E0 );
    int __fastcall OnTransferLeft( short )                              zCall( 0x00768300 );
    int __fastcall OnKeyRight( int )                                    zCall( 0x007683E0 );
    int __fastcall OnMoveRight()                                        zCall( 0x007684C0 );
    int __fastcall OnTransferRight( int )                               zCall( 0x00768570 );
    int __fastcall OnTransferRight( short )                             zCall( 0x00768690 );
    int __fastcall OnSectionPrevious()                                  zCall( 0x00768770 );
    int __fastcall OnSectionNext()                                      zCall( 0x00768790 );
    void __fastcall OnSection( zETradeDialogSection )                   zCall( 0x007687B0 );
    void __fastcall OnChoice( zETradeDialogChoice )                     zCall( 0x00768890 );
    void __fastcall OnAccept()                                          zCall( 0x00768960 );
    void __fastcall OnRecline()                                         zCall( 0x00768AE0 );
    void __fastcall OnBack()                                            zCall( 0x00768B40 );
    void __fastcall OnReset()                                           zCall( 0x00768B50 );
    void __fastcall OnExit()                                            zCall( 0x00768BB0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x007666C0 );
    /* for zCObject num : 18*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00766FF0 );
    virtual ~oCViewDialogTrade()                                        zCall( 0x00767060 );
    virtual void __fastcall StartSelection()                            zCall( 0x00767500 );
    virtual short GetTransferCount()                                    zCall( 0x00767000 );
    virtual void SetTransferCount( short )                              zCall( 0x00767010 );
    virtual void IncTransferCount( short )                              zCall( 0x00767020 );
    /* for zCViewBase num : 8*/
    /* for oCViewDialogTrade num : 1*/
    virtual int HandleEvent( int )                                      zCall( 0x00767890 );

    // user API
    #include "oCViewDialogTrade.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OVIEW_DIALOG_TRADE_H__VER1__