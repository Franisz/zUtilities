// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_DIALOG_ITEM_H__VER0__
#define __OVIEW_DIALOG_ITEM_H__VER0__

namespace Gothic_I_Classic {

  // sizeof FCh
  class oCViewDialogItem : public zCViewDialog {
  public:
    zCLASS_DECLARATION( oCViewDialogItem )

    oCItem* Item; // sizeof 04h    offset F8h

    void oCViewDialogItem_OnInit()                                      zCall( 0x00727050 );
    oCViewDialogItem()                                                  zInit( oCViewDialogItem_OnInit() );
    void __fastcall SetItem( oCItem* )                                  zCall( 0x00727140 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00726F80 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00727040 );
    virtual ~oCViewDialogItem()                                         zCall( 0x007270B0 );
    virtual void __fastcall Blit()                                      zCall( 0x00727180 );
    /* for zCViewBase num : 8*/
    /* for oCViewDialogItem num : 1*/

    // user API
    #include "oCViewDialogItem.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OVIEW_DIALOG_ITEM_H__VER0__