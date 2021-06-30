// Supported with union (c) 2018 Union team

#ifndef __OVIEW_DIALOG_TRADE_H__VER2__
#define __OVIEW_DIALOG_TRADE_H__VER2__

namespace Gothic_II_Classic {

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

    void oCViewDialogTrade_OnInit()                   zCall( 0x00775080 );
    void UpdateViewSettings()                         zCall( 0x00774FE0 );
    oCViewDialogTrade()                               zInit( oCViewDialogTrade_OnInit() );
    void __fastcall AllDialogsStop()                  zCall( 0x00775410 );
    void __fastcall AllDialogsDisable()               zCall( 0x00775430 );
    void __fastcall SetNpcLeft( oCNpc* )              zCall( 0x00775450 );
    void __fastcall SetNpcRight( oCNpc* )             zCall( 0x00775560 );
    void __fastcall Update()                          zCall( 0x00775A20 );
    int __fastcall OnKeyEnter()                       zCall( 0x00775A40 );
    int __fastcall OnKeyEsc()                         zCall( 0x00775A50 );
    int __fastcall OnMoveLeft()                       zCall( 0x00775A60 );
    int __fastcall OnTransferLeft( short )            zCall( 0x00775B10 );
    int __fastcall OnMoveRight()                      zCall( 0x00775D30 );
    int __fastcall OnTransferRight( short )           zCall( 0x00775DE0 );
    int __fastcall OnSectionPrevious()                zCall( 0x00776170 );
    int __fastcall OnSectionNext()                    zCall( 0x007761F0 );
    void __fastcall OnSection( zETradeDialogSection ) zCall( 0x00776270 );
    void __fastcall OnExit()                          zCall( 0x007762D0 );
    static zCObject* _CreateNewInstance()             zCall( 0x00774F60 );
    /* for zCObject num : 18*/
    virtual zCClassDef* _GetClassDef() const          zCall( 0x007752E0 );
    virtual ~oCViewDialogTrade()                      zCall( 0x00775350 );
    virtual void __fastcall StartSelection()          zCall( 0x00775610 );
    virtual short GetTransferCount()                  zCall( 0x007752F0 );
    virtual void SetTransferCount( short )            zCall( 0x00775300 );
    virtual void IncTransferCount( short )            zCall( 0x00775310 );
    /* for zCViewBase num : 9*/
    /* for oCViewDialogTrade num : 1*/
    virtual int HandleEvent( int )                    zCall( 0x007756B0 );

    // user API
    #include "oCViewDialogTrade.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OVIEW_DIALOG_TRADE_H__VER2__