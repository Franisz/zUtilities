// Supported with union (c) 2018 Union team

#ifndef __OVIEW_DIALOG_INVENTORY_H__VER1__
#define __OVIEW_DIALOG_INVENTORY_H__VER1__

namespace Gothic_I_Addon {

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

    void oCViewDialogInventory_OnInit()                                 zCall( 0x00764230 );
    oCViewDialogInventory()                                             zInit( oCViewDialogInventory_OnInit() );
    void __fastcall SetInventory( oCNpcInventory* )                     zCall( 0x00764320 );
    void __fastcall SetAlignment( oEInventoryAlignment )                zCall( 0x00764350 );
    oCItem* __fastcall GetSelectedItem()                                zCall( 0x00764360 );
    int __fastcall GetSelectedItemCount()                               zCall( 0x00764380 );
    oCItem* __fastcall RemoveSelectedItem()                             zCall( 0x007643A0 );
    void __fastcall InsertItem( oCItem* )                               zCall( 0x00764430 );
    int __fastcall CanHandleLeft()                                      zCall( 0x00764450 );
    int __fastcall CanHandleRight()                                     zCall( 0x00764480 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00764150 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00764220 );
    virtual ~oCViewDialogInventory()                                    zCall( 0x007642A0 );
    virtual void __fastcall Activate( int )                             zCall( 0x007642C0 );
    virtual void __fastcall StartSelection()                            zCall( 0x00764500 );
    virtual void __fastcall StopSelection()                             zCall( 0x00764580 );
    /* for zCViewBase num : 8*/
    /* for oCViewDialogInventory num : 1*/
    virtual int HandleEvent( int )                                      zCall( 0x007644B0 );

    // user API
    #include "oCViewDialogInventory.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OVIEW_DIALOG_INVENTORY_H__VER1__