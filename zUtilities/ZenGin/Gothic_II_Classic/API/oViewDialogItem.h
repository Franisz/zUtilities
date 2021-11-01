// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_DIALOG_ITEM_H__VER2__
#define __OVIEW_DIALOG_ITEM_H__VER2__

namespace Gothic_II_Classic {

  // sizeof FCh
  class oCViewDialogItem : public zCViewDialog {
  public:
    zCLASS_DECLARATION( oCViewDialogItem )

    oCItem* Item; // sizeof 04h    offset F8h

    void oCViewDialogItem_OnInit()           zCall( 0x007738C0 );
    oCViewDialogItem()                       zInit( oCViewDialogItem_OnInit() );
    void __fastcall SetItem( oCItem* )       zCall( 0x007739B0 );
    static zCObject* _CreateNewInstance()    zCall( 0x00773800 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const zCall( 0x007738B0 );
    virtual ~oCViewDialogItem()              zCall( 0x00773920 );
    virtual void __fastcall Blit()           zCall( 0x007739F0 );
    /* for zCViewBase num : 9*/
    /* for oCViewDialogItem num : 1*/

    // user API
    #include "oCViewDialogItem.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OVIEW_DIALOG_ITEM_H__VER2__