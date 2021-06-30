// Supported with union (c) 2018 Union team

#ifndef __OVIEW_DIALOG_ITEM_CONTAINER_H__VER3__
#define __OVIEW_DIALOG_ITEM_CONTAINER_H__VER3__

namespace Gothic_II_Addon {

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

    void oCViewDialogItemContainer_OnInit()                  zCall( 0x00689A50 );
    oCViewDialogItemContainer()                              zInit( oCViewDialogItemContainer_OnInit() );
    void __fastcall SetItemContainer( oCItemContainer* )     zCall( 0x00689B10 );
    void __fastcall SetAlignment( oEItemContainerAlignment ) zCall( 0x00689B40 );
    oCItem* __fastcall GetSelectedItem()                     zCall( 0x00689B50 );
    int __fastcall GetSelectedItemCount()                    zCall( 0x00689B70 );
    oCItem* __fastcall RemoveSelectedItem()                  zCall( 0x00689B90 );
    void __fastcall InsertItem( oCItem* )                    zCall( 0x00689C00 );
    void __fastcall RemoveItem( oCItem* )                    zCall( 0x00689C20 );
    void __fastcall TransferAllItemsTo( oCNpcInventory* )    zCall( 0x00689C40 );
    void __fastcall UpdateValue()                            zCall( 0x00689D10 );
    int __fastcall CanHandleLeft()                           zCall( 0x00689D20 );
    int __fastcall CanHandleRight()                          zCall( 0x00689D30 );
    static zCObject* _CreateNewInstance()                    zCall( 0x00689970 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                 zCall( 0x00689A40 );
    virtual ~oCViewDialogItemContainer()                     zCall( 0x00689AD0 );
    virtual void __fastcall Activate( int )                  zCall( 0x00689AF0 );
    virtual void __fastcall StartSelection()                 zCall( 0x00689D90 );
    virtual void __fastcall StopSelection()                  zCall( 0x00689DF0 );
    /* for zCViewBase num : 9*/
    /* for oCViewDialogItemContainer num : 1*/
    virtual int HandleEvent( int )                           zCall( 0x00689D40 );

    // user API
    #include "oCViewDialogItemContainer.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OVIEW_DIALOG_ITEM_CONTAINER_H__VER3__