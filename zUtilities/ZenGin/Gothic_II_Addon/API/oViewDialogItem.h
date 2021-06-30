// Supported with union (c) 2018 Union team

#ifndef __OVIEW_DIALOG_ITEM_H__VER3__
#define __OVIEW_DIALOG_ITEM_H__VER3__

namespace Gothic_II_Addon {

  class oCViewDialogItem : public zCViewDialog {
  public:
    zCLASS_DECLARATION( oCViewDialogItem )

    oCItem* Item;

    void oCViewDialogItem_OnInit()           zCall( 0x00689610 );
    oCViewDialogItem()                       zInit( oCViewDialogItem_OnInit() );
    void __fastcall SetItem( oCItem* )       zCall( 0x00689700 );
    static zCObject* _CreateNewInstance()    zCall( 0x00689520 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const zCall( 0x00689600 );
    virtual ~oCViewDialogItem()              zCall( 0x00689670 );
    virtual void __fastcall Blit()           zCall( 0x00689740 );
    /* for zCViewBase num : 9*/
    /* for oCViewDialogItem num : 1*/

    // user API
    #include "oCViewDialogItem.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OVIEW_DIALOG_ITEM_H__VER3__