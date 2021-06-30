// Supported with union (c) 2018 Union team

#ifndef __OVIEW_DIALOG_STEAL_CONTAINER_H__VER1__
#define __OVIEW_DIALOG_STEAL_CONTAINER_H__VER1__

namespace Gothic_I_Addon {

  class oCViewDialogStealContainer : public zCViewDialog {
  public:
    zCLASS_DECLARATION( oCViewDialogStealContainer )

    enum oEStealContainerAlignment {
      oEStealContainerAlignment_Left,
      oEStealContainerAlignment_Right
    };

    oEStealContainerAlignment oTStealContainerAlignment;
    oEStealContainerAlignment oTAlignmentStealContainer;
    oCStealContainer* StealContainer;
    oEStealContainerAlignment Alignment;
    unsigned long Value;
    float ValueMultiplier;

    void oCViewDialogStealContainer_OnInit()                            zCall( 0x00765A00 );
    oCViewDialogStealContainer()                                        zInit( oCViewDialogStealContainer_OnInit() );
    void __fastcall SetStealContainer( oCStealContainer* )              zCall( 0x00765AC0 );
    void __fastcall SetAlignment( oEStealContainerAlignment )           zCall( 0x00765AF0 );
    oCItem* __fastcall GetSelectedItem()                                zCall( 0x00765B00 );
    int __fastcall GetSelectedItemCount()                               zCall( 0x00765B20 );
    oCItem* __fastcall RemoveSelectedItem()                             zCall( 0x00765B40 );
    void __fastcall InsertItem( oCItem* )                               zCall( 0x00765C60 );
    void __fastcall RemoveItem( oCItem* )                               zCall( 0x00765D10 );
    void __fastcall TransferAllItemsTo( oCNpcInventory* )               zCall( 0x00765DC0 );
    void __fastcall UpdateValue()                                       zCall( 0x00765F30 );
    int __fastcall CanHandleLeft()                                      zCall( 0x007660D0 );
    int __fastcall CanHandleRight()                                     zCall( 0x007660E0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00765910 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x007659F0 );
    virtual ~oCViewDialogStealContainer()                               zCall( 0x00765A80 );
    virtual void __fastcall Activate( int )                             zCall( 0x00765AA0 );
    virtual void __fastcall StartSelection()                            zCall( 0x00766140 );
    virtual void __fastcall StopSelection()                             zCall( 0x007661C0 );
    /* for zCViewBase num : 8*/
    /* for oCViewDialogStealContainer num : 1*/
    virtual int HandleEvent( int )                                      zCall( 0x007660F0 );

    // user API
    #include "oCViewDialogStealContainer.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OVIEW_DIALOG_STEAL_CONTAINER_H__VER1__