// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_DIALOG_CHOICE_H__VER3__
#define __ZVIEW_DIALOG_CHOICE_H__VER3__

namespace Gothic_II_Addon {

  class zCViewDialogChoice : public zCViewDialog {
  public:
    zCLASS_DECLARATION( zCViewDialogChoice )

    zCOLOR ColorSelected;
    zCOLOR ColorGrayed;
    int ChoiceSelected;
    int Choices;
    int LineStart;

    void zCViewDialogChoice_OnInit()           zCall( 0x0068EA60 );
    zCViewDialogChoice()                       zInit( zCViewDialogChoice_OnInit() );
    void __fastcall ScrollUp()                 zCall( 0x0068F050 );
    void __fastcall ScrollDown()               zCall( 0x0068F090 );
    int __fastcall IsSelectedOutsideAbove()    zCall( 0x0068F0D0 );
    int __fastcall IsSelectedOutsideBelow()    zCall( 0x0068F0F0 );
    void __fastcall ShowSelected()             zCall( 0x0068F180 );
    void __fastcall SelectPrevious()           zCall( 0x0068F220 );
    void __fastcall SelectNext()               zCall( 0x0068F330 );
    void __fastcall Select( int )              zCall( 0x0068F440 );
    zCViewText2* __fastcall GetSelection()     zCall( 0x0068F540 );
    zSTRING __fastcall GetSelectedText()       zCall( 0x0068F550 );
    void __fastcall HighlightSelected()        zCall( 0x0068F620 );
    void __fastcall AddChoice( zSTRING&, int ) zCall( 0x0068F710 );
    void __fastcall RemoveChoice( zSTRING& )   zCall( 0x0068F9A0 );
    void __fastcall RemoveChoice( int )        zCall( 0x0068F9B0 );
    void __fastcall RemoveAllChoices()         zCall( 0x0068F9C0 );
    static zCObject* _CreateNewInstance()      zCall( 0x0068E970 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const   zCall( 0x0068EA50 );
    virtual ~zCViewDialogChoice()              zCall( 0x0068EB10 );
    virtual void __fastcall BlitText()         zCall( 0x0068EFE0 );
    virtual void __fastcall StartSelection()   zCall( 0x0068EF70 );
    virtual void __fastcall StopSelection()    zCall( 0x0068EFB0 );
    /* for zCViewBase num : 9*/
    /* for zCViewDialogChoice num : 1*/
    virtual int HandleEvent( int )             zCall( 0x0068EBA0 );

    // user API
    #include "zCViewDialogChoice.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVIEW_DIALOG_CHOICE_H__VER3__