// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_DIALOG_CHOICE_H__VER0__
#define __ZVIEW_DIALOG_CHOICE_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 10Ch
  class zCViewDialogChoice : public zCViewDialog {
  public:
    zCLASS_DECLARATION( zCViewDialogChoice )

    zCOLOR ColorSelected; // sizeof 04h    offset F8h
    zCOLOR ColorGrayed;   // sizeof 04h    offset FCh
    int ChoiceSelected;   // sizeof 04h    offset 100h
    int Choices;          // sizeof 04h    offset 104h
    int LineStart;        // sizeof 04h    offset 108h

    void zCViewDialogChoice_OnInit()                                    zCall( 0x00758920 );
    zCViewDialogChoice()                                                zInit( zCViewDialogChoice_OnInit() );
    void __fastcall ScrollUp()                                          zCall( 0x00758ED0 );
    void __fastcall ScrollDown()                                        zCall( 0x00758F10 );
    int __fastcall IsSelectedOutsideAbove()                             zCall( 0x00758F50 );
    int __fastcall IsSelectedOutsideBelow()                             zCall( 0x00758F70 );
    void __fastcall ShowSelected()                                      zCall( 0x00759000 );
    void __fastcall SelectPrevious()                                    zCall( 0x007590A0 );
    void __fastcall SelectNext()                                        zCall( 0x007591B0 );
    void __fastcall Select( int )                                       zCall( 0x007592C0 );
    zCViewText2* __fastcall GetSelection()                              zCall( 0x007593C0 );
    zSTRING __fastcall GetSelectedText()                                zCall( 0x007593D0 );
    void __fastcall HighlightSelected()                                 zCall( 0x007594A0 );
    void __fastcall AddChoice( zSTRING&, int )                          zCall( 0x00759590 );
    void __fastcall RemoveChoice( zSTRING& )                            zCall( 0x007597F0 );
    void __fastcall RemoveChoice( int )                                 zCall( 0x00759800 );
    void __fastcall RemoveAllChoices()                                  zCall( 0x00759810 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00758820 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00758910 );
    virtual ~zCViewDialogChoice()                                       zCall( 0x007589D0 );
    virtual void __fastcall BlitText()                                  zCall( 0x00758E70 );
    virtual void __fastcall StartSelection()                            zCall( 0x00758E00 );
    virtual void __fastcall StopSelection()                             zCall( 0x00758E40 );
    /* for zCViewBase num : 8*/
    /* for zCViewDialogChoice num : 1*/
    virtual int HandleEvent( int )                                      zCall( 0x00758A60 );

    // user API
    #include "zCViewDialogChoice.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZVIEW_DIALOG_CHOICE_H__VER0__