// Supported with union (c) 2018 Union team

#ifndef __OVIEW_DIALOG_TRADE_H__VER3__
#define __OVIEW_DIALOG_TRADE_H__VER3__

namespace Gothic_II_Addon {

  class oCViewDialogTrade : public zCViewDialog {
  public:
    zCLASS_DECLARATION( oCViewDialogTrade )

    typedef enum zETradeDialogSection {
      TRADE_SECTION_LEFT_INVENTORY,
      TRADE_SECTION_RIGHT_INVENTORY
    } zTTradeSection;

    oCViewDialogStealContainer* DlgInventoryNpc;
    oCViewDialogInventory* DlgInventoryPlayer;
    zTTradeSection SectionTrade;
    oCNpc* NpcLeft;
    oCNpc* NpcRight;
    short TransferCount;

    void oCViewDialogTrade_OnInit()                   zCall( 0x0068ADB0 );
    void UpdateViewSettings()                         zCall( 0x0068AD10 );
    oCViewDialogTrade()                               zInit( oCViewDialogTrade_OnInit() );
    void __fastcall AllDialogsStop()                  zCall( 0x0068B140 );
    void __fastcall AllDialogsDisable()               zCall( 0x0068B160 );
    void __fastcall SetNpcLeft( oCNpc* )              zCall( 0x0068B180 );
    void __fastcall SetNpcRight( oCNpc* )             zCall( 0x0068B290 );
    void __fastcall Update()                          zCall( 0x0068B750 );
    int __fastcall OnKeyEnter()                       zCall( 0x0068B770 );
    int __fastcall OnKeyEsc()                         zCall( 0x0068B780 );
    int __fastcall OnMoveLeft()                       zCall( 0x0068B790 );
    int __fastcall OnTransferLeft( short )            zCall( 0x0068B840 );
    int __fastcall OnMoveRight()                      zCall( 0x0068BA60 );
    int __fastcall OnTransferRight( short )           zCall( 0x0068BB10 );
    int __fastcall OnSectionPrevious()                zCall( 0x0068BEA0 );
    int __fastcall OnSectionNext()                    zCall( 0x0068BF20 );
    void __fastcall OnSection( zETradeDialogSection ) zCall( 0x0068BFA0 );
    void __fastcall OnExit()                          zCall( 0x0068C000 );
    static zCObject* _CreateNewInstance()             zCall( 0x0068ACB0 );
    /* for zCObject num : 18*/
    virtual zCClassDef* _GetClassDef() const          zCall( 0x0068B010 );
    virtual ~oCViewDialogTrade()                      zCall( 0x0068B080 );
    virtual void __fastcall StartSelection()          zCall( 0x0068B340 );
    virtual short GetTransferCount()                  zCall( 0x0068B020 );
    virtual void SetTransferCount( short )            zCall( 0x0068B030 );
    virtual void IncTransferCount( short )            zCall( 0x0068B040 );
    /* for zCViewBase num : 9*/
    /* for oCViewDialogTrade num : 1*/
    virtual int HandleEvent( int )                    zCall( 0x0068B3E0 );

    // user API
    #include "oCViewDialogTrade.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OVIEW_DIALOG_TRADE_H__VER3__