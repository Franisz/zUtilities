// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_DIALOG_CHOICE_H__VER1__
#define __ZVIEW_DIALOG_CHOICE_H__VER1__

namespace Gothic_I_Addon {

  class zCViewDialogChoice : public zCViewDialog {
  public:
    zCLASS_DECLARATION( zCViewDialogChoice )

    zCOLOR ColorSelected;
    zCOLOR ColorGrayed;
    int ChoiceSelected;
    int Choices;
    int LineStart;

    void zCViewDialogChoice_OnInit()                                    zCall( 0x0079AE80 );
    zCViewDialogChoice()                                                zInit( zCViewDialogChoice_OnInit() );
    void __fastcall ScrollUp()                                          zCall( 0x0079B490 );
    void __fastcall ScrollDown()                                        zCall( 0x0079B4D0 );
    int __fastcall IsSelectedOutsideAbove()                             zCall( 0x0079B510 );
    int __fastcall IsSelectedOutsideBelow()                             zCall( 0x0079B530 );
    void __fastcall ShowSelected()                                      zCall( 0x0079B5C0 );
    void __fastcall SelectPrevious()                                    zCall( 0x0079B660 );
    void __fastcall SelectNext()                                        zCall( 0x0079B760 );
    void __fastcall Select( int )                                       zCall( 0x0079B870 );
    zCViewText2* __fastcall GetSelection()                              zCall( 0x0079B970 );
    zSTRING __fastcall GetSelectedText()                                zCall( 0x0079B980 );
    void __fastcall HighlightSelected()                                 zCall( 0x0079BA50 );
    void __fastcall AddChoice( zSTRING&, int )                          zCall( 0x0079BB30 );
    void __fastcall RemoveChoice( zSTRING& )                            zCall( 0x0079BDA0 );
    void __fastcall RemoveChoice( int )                                 zCall( 0x0079BDB0 );
    void __fastcall RemoveAllChoices()                                  zCall( 0x0079BDC0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0079AD80 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0079AE70 );
    virtual ~zCViewDialogChoice()                                       zCall( 0x0079AF30 );
    virtual void __fastcall BlitText()                                  zCall( 0x0079B430 );
    virtual void __fastcall StartSelection()                            zCall( 0x0079B3C0 );
    virtual void __fastcall StopSelection()                             zCall( 0x0079B400 );
    /* for zCViewBase num : 8*/
    /* for zCViewDialogChoice num : 1*/
    virtual int HandleEvent( int )                                      zCall( 0x0079AFC0 );

    // user API
    #include "zCViewDialogChoice.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZVIEW_DIALOG_CHOICE_H__VER1__