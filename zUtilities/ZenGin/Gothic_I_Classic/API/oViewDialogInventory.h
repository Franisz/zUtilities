// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_DIALOG_INVENTORY_H__VER0__
#define __OVIEW_DIALOG_INVENTORY_H__VER0__

namespace Gothic_I_Classic {

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

    void oCViewDialogInventory_OnInit()                                 zCall( 0x007269E0 );
    oCViewDialogInventory()                                             zInit( oCViewDialogInventory_OnInit() );
    void __fastcall SetInventory( oCNpcInventory* )                     zCall( 0x00726AD0 );
    void __fastcall SetAlignment( oEInventoryAlignment )                zCall( 0x00726B00 );
    oCItem* __fastcall GetSelectedItem()                                zCall( 0x00726B10 );
    int __fastcall GetSelectedItemCount()                               zCall( 0x00726B30 );
    oCItem* __fastcall RemoveSelectedItem()                             zCall( 0x00726B50 );
    void __fastcall InsertItem( oCItem* )                               zCall( 0x00726BE0 );
    int __fastcall CanHandleLeft()                                      zCall( 0x00726C00 );
    int __fastcall CanHandleRight()                                     zCall( 0x00726C30 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00726900 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x007269D0 );
    virtual ~oCViewDialogInventory()                                    zCall( 0x00726A50 );
    virtual void __fastcall Activate( int )                             zCall( 0x00726A70 );
    virtual void __fastcall StartSelection()                            zCall( 0x00726CB0 );
    virtual void __fastcall StopSelection()                             zCall( 0x00726D30 );
    /* for zCViewBase num : 8*/
    /* for oCViewDialogInventory num : 1*/
    virtual int HandleEvent( int )                                      zCall( 0x00726C60 );

    // user API
    #include "oCViewDialogInventory.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OVIEW_DIALOG_INVENTORY_H__VER0__