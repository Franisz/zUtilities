// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_DIALOG_ITEM_CONTAINER_H__VER0__
#define __OVIEW_DIALOG_ITEM_CONTAINER_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 110h
  class oCViewDialogItemContainer : public zCViewDialog {
  public:
    zCLASS_DECLARATION( oCViewDialogItemContainer )

    enum oEItemContainerAlignment {
      oEItemContainerAlignment_Left,
      oEItemContainerAlignment_Right
    };

    oEItemContainerAlignment oTItemContainerAlignment; // sizeof 04h    offset F8h
    oEItemContainerAlignment oTAlignmentItemContainer; // sizeof 04h    offset FCh
    oCItemContainer* ItemContainer;                    // sizeof 04h    offset 100h
    oEItemContainerAlignment Alignment;                // sizeof 04h    offset 104h
    unsigned long Value;                               // sizeof 04h    offset 108h
    float ValueMultiplier;                             // sizeof 04h    offset 10Ch

    void oCViewDialogItemContainer_OnInit()                             zCall( 0x007274A0 );
    oCViewDialogItemContainer()                                         zInit( oCViewDialogItemContainer_OnInit() );
    void __fastcall SetItemContainer( oCItemContainer* )                zCall( 0x00727560 );
    void __fastcall SetAlignment( oEItemContainerAlignment )            zCall( 0x00727590 );
    oCItem* __fastcall GetSelectedItem()                                zCall( 0x007275A0 );
    int __fastcall GetSelectedItemCount()                               zCall( 0x007275C0 );
    oCItem* __fastcall RemoveSelectedItem()                             zCall( 0x007275E0 );
    void __fastcall InsertItem( oCItem* )                               zCall( 0x007276C0 );
    void __fastcall RemoveItem( oCItem* )                               zCall( 0x00727740 );
    void __fastcall TransferAllItemsTo( oCNpcInventory* )               zCall( 0x007277D0 );
    void __fastcall UpdateValue()                                       zCall( 0x00727900 );
    int __fastcall CanHandleLeft()                                      zCall( 0x00727A90 );
    int __fastcall CanHandleRight()                                     zCall( 0x00727AA0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x007273B0 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00727490 );
    virtual ~oCViewDialogItemContainer()                                zCall( 0x00727520 );
    virtual void __fastcall Activate( int )                             zCall( 0x00727540 );
    virtual void __fastcall StartSelection()                            zCall( 0x00727B00 );
    virtual void __fastcall StopSelection()                             zCall( 0x00727B90 );
    /* for zCViewBase num : 8*/
    /* for oCViewDialogItemContainer num : 1*/
    virtual int HandleEvent( int )                                      zCall( 0x00727AB0 );

    // user API
    #include "oCViewDialogItemContainer.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OVIEW_DIALOG_ITEM_CONTAINER_H__VER0__