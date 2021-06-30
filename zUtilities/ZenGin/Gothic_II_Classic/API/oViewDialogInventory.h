// Supported with union (c) 2018 Union team

#ifndef __OVIEW_DIALOG_INVENTORY_H__VER2__
#define __OVIEW_DIALOG_INVENTORY_H__VER2__

namespace Gothic_II_Classic {

  class oCViewDialogInventory : public zCViewDialog {
  public:
    zCLASS_DECLARATION( oCViewDialogInventory )

    enum oEInventoryAlignment {
      oEInventoryAlignment_Left,
      oEInventoryAlignment_Right
    };

    oEInventoryAlignment oTInventoryAlignment;
    oEInventoryAlignment oTAlignmentInventory;
    oCNpcInventory* Inventory;
    oEInventoryAlignment Alignment;

    void oCViewDialogInventory_OnInit()                  zCall( 0x00773300 );
    oCViewDialogInventory()                              zInit( oCViewDialogInventory_OnInit() );
    void __fastcall SetInventory( oCNpcInventory* )      zCall( 0x007733B0 );
    void __fastcall SetAlignment( oEInventoryAlignment ) zCall( 0x007733E0 );
    oCItem* __fastcall GetSelectedItem()                 zCall( 0x007733F0 );
    int __fastcall GetSelectedItemCount()                zCall( 0x00773410 );
    oCItem* __fastcall RemoveSelectedItem()              zCall( 0x00773430 );
    void __fastcall InsertItem( oCItem* )                zCall( 0x007734C0 );
    int __fastcall CanHandleLeft()                       zCall( 0x007734E0 );
    int __fastcall CanHandleRight()                      zCall( 0x007734F0 );
    static zCObject* _CreateNewInstance()                zCall( 0x00773230 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const             zCall( 0x007732F0 );
    virtual ~oCViewDialogInventory()                     zCall( 0x00773370 );
    virtual void __fastcall Activate( int )              zCall( 0x00773390 );
    virtual void __fastcall StartSelection()             zCall( 0x00773550 );
    virtual void __fastcall StopSelection()              zCall( 0x007735B0 );
    /* for zCViewBase num : 9*/
    /* for oCViewDialogInventory num : 1*/
    virtual int HandleEvent( int )                       zCall( 0x00773500 );

    // user API
    #include "oCViewDialogInventory.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OVIEW_DIALOG_INVENTORY_H__VER2__