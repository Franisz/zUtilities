// Supported with union (c) 2018 Union team

#ifndef __OVIEW_DIALOG_STEAL_CONTAINER_H__VER3__
#define __OVIEW_DIALOG_STEAL_CONTAINER_H__VER3__

namespace Gothic_II_Addon {

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

    void oCViewDialogStealContainer_OnInit()                  zCall( 0x0068A300 );
    oCViewDialogStealContainer()                              zInit( oCViewDialogStealContainer_OnInit() );
    void __fastcall SetStealContainer( oCStealContainer* )    zCall( 0x0068A3C0 );
    void __fastcall SetAlignment( oEStealContainerAlignment ) zCall( 0x0068A3F0 );
    oCItem* __fastcall GetSelectedItem()                      zCall( 0x0068A400 );
    int __fastcall GetSelectedItemCount()                     zCall( 0x0068A420 );
    oCItem* __fastcall RemoveSelectedItem()                   zCall( 0x0068A440 );
    void __fastcall InsertItem( oCItem* )                     zCall( 0x0068A500 );
    void __fastcall RemoveItem( oCItem* )                     zCall( 0x0068A550 );
    void __fastcall TransferAllItemsTo( oCNpcInventory* )     zCall( 0x0068A5B0 );
    void __fastcall UpdateValue()                             zCall( 0x0068A6B0 );
    int __fastcall CanHandleLeft()                            zCall( 0x0068A750 );
    int __fastcall CanHandleRight()                           zCall( 0x0068A760 );
    static zCObject* _CreateNewInstance()                     zCall( 0x0068A220 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                  zCall( 0x0068A2F0 );
    virtual ~oCViewDialogStealContainer()                     zCall( 0x0068A380 );
    virtual void __fastcall Activate( int )                   zCall( 0x0068A3A0 );
    virtual void __fastcall StartSelection()                  zCall( 0x0068A7C0 );
    virtual void __fastcall StopSelection()                   zCall( 0x0068A820 );
    /* for zCViewBase num : 9*/
    /* for oCViewDialogStealContainer num : 1*/
    virtual int HandleEvent( int )                            zCall( 0x0068A770 );

    // user API
    #include "oCViewDialogStealContainer.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OVIEW_DIALOG_STEAL_CONTAINER_H__VER3__