// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_DIALOG_INVENTORY_H__VER3__
#define __OVIEW_DIALOG_INVENTORY_H__VER3__

namespace Gothic_II_Addon {

  // sizeof 108h
  class oCViewDialogInventory : public zCViewDialog {
  public:
    zCLASS_DECLARATION( oCViewDialogInventory )

    enum oEInventoryAlignment {
      oEInventoryAlignment_Left,
      oEInventoryAlignment_Right
    };

    oEInventoryAlignment oTInventoryAlignment; // sizeof 04h    offset F8h
    oEInventoryAlignment oTAlignmentInventory; // sizeof 04h    offset FCh
    oCNpcInventory* Inventory;                 // sizeof 04h    offset 100h
    oEInventoryAlignment Alignment;            // sizeof 04h    offset 104h

    void oCViewDialogInventory_OnInit()                  zCall( 0x00689020 );
    oCViewDialogInventory()                              zInit( oCViewDialogInventory_OnInit() );
    void __fastcall SetInventory( oCNpcInventory* )      zCall( 0x006890D0 );
    void __fastcall SetAlignment( oEInventoryAlignment ) zCall( 0x00689100 );
    oCItem* __fastcall GetSelectedItem()                 zCall( 0x00689110 );
    int __fastcall GetSelectedItemCount()                zCall( 0x00689130 );
    oCItem* __fastcall RemoveSelectedItem()              zCall( 0x00689150 );
    void __fastcall InsertItem( oCItem* )                zCall( 0x006891E0 );
    int __fastcall CanHandleLeft()                       zCall( 0x00689200 );
    int __fastcall CanHandleRight()                      zCall( 0x00689210 );
    static zCObject* _CreateNewInstance()                zCall( 0x00688F30 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const             zCall( 0x00689010 );
    virtual ~oCViewDialogInventory()                     zCall( 0x00689090 );
    virtual void __fastcall Activate( int )              zCall( 0x006890B0 );
    virtual void __fastcall StartSelection()             zCall( 0x00689270 );
    virtual void __fastcall StopSelection()              zCall( 0x006892D0 );
    /* for zCViewBase num : 9*/
    /* for oCViewDialogInventory num : 1*/
    virtual int HandleEvent( int )                       zCall( 0x00689220 );

    // user API
    #include "oCViewDialogInventory.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OVIEW_DIALOG_INVENTORY_H__VER3__