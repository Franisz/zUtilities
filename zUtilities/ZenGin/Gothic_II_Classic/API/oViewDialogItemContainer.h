// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_DIALOG_ITEM_CONTAINER_H__VER2__
#define __OVIEW_DIALOG_ITEM_CONTAINER_H__VER2__

namespace Gothic_II_Classic {

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

    void oCViewDialogItemContainer_OnInit()                  zCall( 0x00773D00 );
    oCViewDialogItemContainer()                              zInit( oCViewDialogItemContainer_OnInit() );
    void __fastcall SetItemContainer( oCItemContainer* )     zCall( 0x00773DC0 );
    void __fastcall SetAlignment( oEItemContainerAlignment ) zCall( 0x00773DF0 );
    oCItem* __fastcall GetSelectedItem()                     zCall( 0x00773E00 );
    int __fastcall GetSelectedItemCount()                    zCall( 0x00773E20 );
    oCItem* __fastcall RemoveSelectedItem()                  zCall( 0x00773E40 );
    void __fastcall InsertItem( oCItem* )                    zCall( 0x00773EB0 );
    void __fastcall RemoveItem( oCItem* )                    zCall( 0x00773ED0 );
    void __fastcall TransferAllItemsTo( oCNpcInventory* )    zCall( 0x00773EF0 );
    void __fastcall UpdateValue()                            zCall( 0x00773FC0 );
    int __fastcall CanHandleLeft()                           zCall( 0x00773FD0 );
    int __fastcall CanHandleRight()                          zCall( 0x00773FE0 );
    static zCObject* _CreateNewInstance()                    zCall( 0x00773C20 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                 zCall( 0x00773CF0 );
    virtual ~oCViewDialogItemContainer()                     zCall( 0x00773D80 );
    virtual void __fastcall Activate( int )                  zCall( 0x00773DA0 );
    virtual void __fastcall StartSelection()                 zCall( 0x00774040 );
    virtual void __fastcall StopSelection()                  zCall( 0x007740A0 );
    /* for zCViewBase num : 9*/
    /* for oCViewDialogItemContainer num : 1*/
    virtual int HandleEvent( int )                           zCall( 0x00773FF0 );

    // user API
    #include "oCViewDialogItemContainer.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OVIEW_DIALOG_ITEM_CONTAINER_H__VER2__