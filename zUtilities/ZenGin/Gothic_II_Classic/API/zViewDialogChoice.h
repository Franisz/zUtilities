// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_DIALOG_CHOICE_H__VER2__
#define __ZVIEW_DIALOG_CHOICE_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 10Ch
  class zCViewDialogChoice : public zCViewDialog {
  public:
    zCLASS_DECLARATION( zCViewDialogChoice )

    zCOLOR ColorSelected; // sizeof 04h    offset F8h
    zCOLOR ColorGrayed;   // sizeof 04h    offset FCh
    int ChoiceSelected;   // sizeof 04h    offset 100h
    int Choices;          // sizeof 04h    offset 104h
    int LineStart;        // sizeof 04h    offset 108h

    void zCViewDialogChoice_OnInit()           zCall( 0x007A57D0 );
    zCViewDialogChoice()                       zInit( zCViewDialogChoice_OnInit() );
    void __fastcall ScrollUp()                 zCall( 0x007A5DB0 );
    void __fastcall ScrollDown()               zCall( 0x007A5DF0 );
    int __fastcall IsSelectedOutsideAbove()    zCall( 0x007A5E30 );
    int __fastcall IsSelectedOutsideBelow()    zCall( 0x007A5E50 );
    void __fastcall ShowSelected()             zCall( 0x007A5EE0 );
    void __fastcall SelectPrevious()           zCall( 0x007A5F80 );
    void __fastcall SelectNext()               zCall( 0x007A6090 );
    void __fastcall Select( int )              zCall( 0x007A61A0 );
    zCViewText2* __fastcall GetSelection()     zCall( 0x007A62A0 );
    zSTRING __fastcall GetSelectedText()       zCall( 0x007A62B0 );
    void __fastcall HighlightSelected()        zCall( 0x007A6380 );
    void __fastcall AddChoice( zSTRING&, int ) zCall( 0x007A6470 );
    void __fastcall RemoveChoice( zSTRING& )   zCall( 0x007A6700 );
    void __fastcall RemoveChoice( int )        zCall( 0x007A6710 );
    void __fastcall RemoveAllChoices()         zCall( 0x007A6720 );
    static zCObject* _CreateNewInstance()      zCall( 0x007A56E0 );
    /* for zCObject num : 15*/
    virtual zCClassDef* _GetClassDef() const   zCall( 0x007A57C0 );
    virtual ~zCViewDialogChoice()              zCall( 0x007A5880 );
    virtual void __fastcall BlitText()         zCall( 0x007A5D40 );
    virtual void __fastcall StartSelection()   zCall( 0x007A5CD0 );
    virtual void __fastcall StopSelection()    zCall( 0x007A5D10 );
    /* for zCViewBase num : 9*/
    /* for zCViewDialogChoice num : 1*/
    virtual int HandleEvent( int )             zCall( 0x007A5910 );

    // user API
    #include "zCViewDialogChoice.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVIEW_DIALOG_CHOICE_H__VER2__