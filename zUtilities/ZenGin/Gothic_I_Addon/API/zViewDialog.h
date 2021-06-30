// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_DIALOG_H__VER1__
#define __ZVIEW_DIALOG_H__VER1__

namespace Gothic_I_Addon {

  class zCViewDialog : public zCViewPrint, public zCInputCallback {
  public:
    zCLASS_DECLARATION( zCViewDialog )

    int IsDone;
    int IsActivated;

    void zCViewDialog_OnInit()                                          zCall( 0x0079A9A0 );
    zCViewDialog()                                                      zInit( zCViewDialog_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x0079A7F0 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00762350 );
    virtual ~zCViewDialog()                                             zCall( 0x0079AAE0 );
    virtual int __fastcall IsActive()                                   zCall( 0x00762360 );
    virtual void __fastcall Activate( int )                             zCall( 0x00762370 );
    virtual int __fastcall HasFinished()                                zCall( 0x00762380 );
    virtual void __fastcall StartSelection()                            zCall( 0x00762390 );
    virtual void __fastcall StopSelection()                             zCall( 0x007623A0 );
    /* for zCViewBase num : 8*/
    /* for zCViewDialog num : 1*/

    // user API
    #include "zCViewDialog.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZVIEW_DIALOG_H__VER1__