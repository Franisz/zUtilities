// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_DIALOG_H__VER3__
#define __ZVIEW_DIALOG_H__VER3__

namespace Gothic_II_Addon {

  class zCViewDialog : public zCViewPrint, public zCInputCallback {
  public:
    zCLASS_DECLARATION( zCViewDialog )

    int IsDone;
    int IsActivated;

    void zCViewDialog_OnInit()               zCall( 0x0068E5A0 );
    zCViewDialog()                           zInit( zCViewDialog_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x0068E450 );
    /* for zCViewDialog num : 1*/
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const zCall( 0x0068C5E0 );
    virtual ~zCViewDialog()                  zCall( 0x0068E6E0 );
    virtual int __fastcall IsActive()        zCall( 0x00688FD0 );
    virtual void __fastcall Activate( int )  zCall( 0x006895B0 );
    virtual int __fastcall HasFinished()     zCall( 0x00688FE0 );
    virtual void __fastcall StartSelection() zCall( 0x006895C0 );
    virtual void __fastcall StopSelection()  zCall( 0x006895D0 );
    /* for zCViewBase num : 9*/

    // user API
    #include "zCViewDialog.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVIEW_DIALOG_H__VER3__