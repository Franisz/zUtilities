// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_DIALOG_STEAL_CONTAINER_H__VER0__
#define __OVIEW_DIALOG_STEAL_CONTAINER_H__VER0__

namespace Gothic_I_Classic {

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

    void oCViewDialogStealContainer_OnInit()                            zCall( 0x00727ED0 );
    oCViewDialogStealContainer()                                        zInit( oCViewDialogStealContainer_OnInit() );
    void __fastcall SetStealContainer( oCStealContainer* )              zCall( 0x00727F90 );
    void __fastcall SetAlignment( oEStealContainerAlignment )           zCall( 0x00727FC0 );
    oCItem* __fastcall GetSelectedItem()                                zCall( 0x00727FD0 );
    int __fastcall GetSelectedItemCount()                               zCall( 0x00727FF0 );
    oCItem* __fastcall RemoveSelectedItem()                             zCall( 0x00728010 );
    void __fastcall InsertItem( oCItem* )                               zCall( 0x00728130 );
    void __fastcall RemoveItem( oCItem* )                               zCall( 0x007281F0 );
    void __fastcall TransferAllItemsTo( oCNpcInventory* )               zCall( 0x007282B0 );
    void __fastcall UpdateValue()                                       zCall( 0x00728420 );
    int __fastcall CanHandleLeft()                                      zCall( 0x007285C0 );
    int __fastcall CanHandleRight()                                     zCall( 0x007285D0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00727DE0 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00727EC0 );
    virtual ~oCViewDialogStealContainer()                               zCall( 0x00727F50 );
    virtual void __fastcall Activate( int )                             zCall( 0x00727F70 );
    virtual void __fastcall StartSelection()                            zCall( 0x00728630 );
    virtual void __fastcall StopSelection()                             zCall( 0x007286B0 );
    /* for zCViewBase num : 8*/
    /* for oCViewDialogStealContainer num : 1*/
    virtual int HandleEvent( int )                                      zCall( 0x007285E0 );

    // user API
    #include "oCViewDialogStealContainer.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OVIEW_DIALOG_STEAL_CONTAINER_H__VER0__