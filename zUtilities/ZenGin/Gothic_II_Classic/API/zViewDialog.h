// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_DIALOG_H__VER2__
#define __ZVIEW_DIALOG_H__VER2__

namespace Gothic_II_Classic {

  class zCViewDialog : public zCViewPrint, public zCInputCallback {
  public:
    zCLASS_DECLARATION( zCViewDialog )

    int IsDone;
    int IsActivated;

    void zCViewDialog_OnInit()               zCall( 0x007A5310 );
    zCViewDialog()                           zInit( zCViewDialog_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x007A51C0 );
    /* for zCViewDialog num : 1*/
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const zCall( 0x00771560 );
    virtual ~zCViewDialog()                  zCall( 0x007A5450 );
    virtual int __fastcall IsActive()        zCall( 0x00771570 );
    virtual void __fastcall Activate( int )  zCall( 0x00771580 );
    virtual int __fastcall HasFinished()     zCall( 0x00771590 );
    virtual void __fastcall StartSelection() zCall( 0x007715A0 );
    virtual void __fastcall StopSelection()  zCall( 0x007715B0 );
    /* for zCViewBase num : 9*/

    // user API
    #include "zCViewDialog.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVIEW_DIALOG_H__VER2__