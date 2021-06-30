// Supported with union (c) 2018 Union team

#ifndef __OVIEW_DIALOG_ITEM_H__VER1__
#define __OVIEW_DIALOG_ITEM_H__VER1__

namespace Gothic_I_Addon {

  class oCViewDialogItem : public zCViewDialog {
  public:
    zCLASS_DECLARATION( oCViewDialogItem )

    oCItem* Item;

    void oCViewDialogItem_OnInit()                                      zCall( 0x007648B0 );
    oCViewDialogItem()                                                  zInit( oCViewDialogItem_OnInit() );
    void __fastcall SetItem( oCItem* )                                  zCall( 0x007649B0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x007647E0 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x007648A0 );
    virtual ~oCViewDialogItem()                                         zCall( 0x00764910 );
    virtual void __fastcall Blit()                                      zCall( 0x00764A00 );
    /* for zCViewBase num : 8*/
    /* for oCViewDialogItem num : 1*/

    // user API
    #include "oCViewDialogItem.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OVIEW_DIALOG_ITEM_H__VER1__