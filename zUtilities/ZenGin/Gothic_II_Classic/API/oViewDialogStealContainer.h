// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_DIALOG_STEAL_CONTAINER_H__VER2__
#define __OVIEW_DIALOG_STEAL_CONTAINER_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 110h
  class oCViewDialogStealContainer : public zCViewDialog {
  public:
    zCLASS_DECLARATION( oCViewDialogStealContainer )

    enum oEStealContainerAlignment {
      oEStealContainerAlignment_Left,
      oEStealContainerAlignment_Right
    };

    oEStealContainerAlignment oTStealContainerAlignment; // sizeof 04h    offset F8h
    oEStealContainerAlignment oTAlignmentStealContainer; // sizeof 04h    offset FCh
    oCStealContainer* StealContainer;                    // sizeof 04h    offset 100h
    oEStealContainerAlignment Alignment;                 // sizeof 04h    offset 104h
    unsigned long Value;                                 // sizeof 04h    offset 108h
    float ValueMultiplier;                               // sizeof 04h    offset 10Ch

    void oCViewDialogStealContainer_OnInit()                  zCall( 0x007745B0 );
    oCViewDialogStealContainer()                              zInit( oCViewDialogStealContainer_OnInit() );
    void __fastcall SetStealContainer( oCStealContainer* )    zCall( 0x00774670 );
    void __fastcall SetAlignment( oEStealContainerAlignment ) zCall( 0x007746A0 );
    oCItem* __fastcall GetSelectedItem()                      zCall( 0x007746B0 );
    int __fastcall GetSelectedItemCount()                     zCall( 0x007746D0 );
    oCItem* __fastcall RemoveSelectedItem()                   zCall( 0x007746F0 );
    void __fastcall InsertItem( oCItem* )                     zCall( 0x007747B0 );
    void __fastcall RemoveItem( oCItem* )                     zCall( 0x00774800 );
    void __fastcall TransferAllItemsTo( oCNpcInventory* )     zCall( 0x00774860 );
    void __fastcall UpdateValue()                             zCall( 0x00774960 );
    int __fastcall CanHandleLeft()                            zCall( 0x00774A00 );
    int __fastcall CanHandleRight()                           zCall( 0x00774A10 );
    static zCObject* _CreateNewInstance()                     zCall( 0x007744D0 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                  zCall( 0x007745A0 );
    virtual ~oCViewDialogStealContainer()                     zCall( 0x00774630 );
    virtual void __fastcall Activate( int )                   zCall( 0x00774650 );
    virtual void __fastcall StartSelection()                  zCall( 0x00774A70 );
    virtual void __fastcall StopSelection()                   zCall( 0x00774AD0 );
    /* for zCViewBase num : 9*/
    /* for oCViewDialogStealContainer num : 1*/
    virtual int HandleEvent( int )                            zCall( 0x00774A20 );

    // user API
    #include "oCViewDialogStealContainer.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OVIEW_DIALOG_STEAL_CONTAINER_H__VER2__