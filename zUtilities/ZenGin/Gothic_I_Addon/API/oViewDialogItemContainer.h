// Supported with union (c) 2018 Union team

#ifndef __OVIEW_DIALOG_ITEM_CONTAINER_H__VER1__
#define __OVIEW_DIALOG_ITEM_CONTAINER_H__VER1__

namespace Gothic_I_Addon {

  class oCViewDialogItemContainer : public zCViewDialog {
  public:
    zCLASS_DECLARATION( oCViewDialogItemContainer )

    enum oEItemContainerAlignment {
      oEItemContainerAlignment_Left,
      oEItemContainerAlignment_Right
    };

    oEItemContainerAlignment oTItemContainerAlignment;
    oEItemContainerAlignment oTAlignmentItemContainer;
    oCItemContainer* ItemContainer;
    oEItemContainerAlignment Alignment;
    unsigned long Value;
    float ValueMultiplier;

    void oCViewDialogItemContainer_OnInit()                             zCall( 0x00764D30 );
    oCViewDialogItemContainer()                                         zInit( oCViewDialogItemContainer_OnInit() );
    void __fastcall SetItemContainer( oCItemContainer* )                zCall( 0x00764DF0 );
    void __fastcall SetAlignment( oEItemContainerAlignment )            zCall( 0x00764E20 );
    oCItem* __fastcall GetSelectedItem()                                zCall( 0x00764E30 );
    int __fastcall GetSelectedItemCount()                               zCall( 0x00764E50 );
    oCItem* __fastcall RemoveSelectedItem()                             zCall( 0x00764E70 );
    void __fastcall InsertItem( oCItem* )                               zCall( 0x00764F50 );
    void __fastcall RemoveItem( oCItem* )                               zCall( 0x00764FD0 );
    void __fastcall TransferAllItemsTo( oCNpcInventory* )               zCall( 0x00765050 );
    void __fastcall UpdateValue()                                       zCall( 0x00765180 );
    int __fastcall CanHandleLeft()                                      zCall( 0x00765310 );
    int __fastcall CanHandleRight()                                     zCall( 0x00765320 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00764C40 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00764D20 );
    virtual ~oCViewDialogItemContainer()                                zCall( 0x00764DB0 );
    virtual void __fastcall Activate( int )                             zCall( 0x00764DD0 );
    virtual void __fastcall StartSelection()                            zCall( 0x00765380 );
    virtual void __fastcall StopSelection()                             zCall( 0x00765410 );
    /* for zCViewBase num : 8*/
    /* for oCViewDialogItemContainer num : 1*/
    virtual int HandleEvent( int )                                      zCall( 0x00765330 );

    // user API
    #include "oCViewDialogItemContainer.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OVIEW_DIALOG_ITEM_CONTAINER_H__VER1__