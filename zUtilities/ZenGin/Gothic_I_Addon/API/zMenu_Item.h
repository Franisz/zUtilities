// Supported with union (c) 2018 Union team

#ifndef __ZMENU__ITEM_H__VER1__
#define __ZMENU__ITEM_H__VER1__

#include "zOption.h"
#include "zViews.h"
#include "zVob.h"
#include "zMathTools.h"

namespace Gothic_I_Addon {
  const int MAX_ITEMS       = 150;
  const int MAX_EVENTS      = 10;
  const int MAX_SEL_ACTIONS = 5;
  const int MAX_USERVARS    = 4;
  const int MAX_USERSTRINGS = 10;

  enum zTMenuItem {
    MENU_ITEM_UNDEF,
    MENU_ITEM_TEXT,
    MENU_ITEM_SLIDER,
    MENU_ITEM_INPUT,
    MENU_ITEM_CURSOR,
    MENU_ITEM_CHOICEBOX,
    MENU_ITEM_BUTTON,
    MENU_ITEM_LISTBOX
  };

  enum zTMenuItemFlags {
    IT_UNDEF,
    IT_CHROMAKEYED,
    IT_TRANSPARENT,
    IT_SELECTABLE    = 4,
    IT_MOVEABLE      = 8,
    IT_TXT_CENTER    = 16,
    IT_DISABLED      = 32,
    IT_FADE          = 64,
    IT_EFFECTS_NEXT  = 128,
    IT_ONLY_OUT_GAME = 256,
    IT_ONLY_IN_GAME  = 512,
    IT_PERF_OPTION   = 1024,
    IT_MULTILINE     = 2048,
    IT_NEEDS_APPLY   = 4096,
    IT_NEEDS_RESTART = 8192,
    IT_EXTENDED_MENU = 16384
  };

  enum zTMenuItemEvent {
    IT_EVENT_UNDEF,
    IT_EVENT_EXECUTE,
    IT_EVENT_CHANGED,
    IT_EVENT_LEAVE,
    IT_EVENT_TIMER,
    IT_EVENT_CLOSE,
    IT_EVENT_INIT,
    IT_EVENT_SEL_PREV,
    IT_EVENT_SEL_NEXT,
    IT_EVENT_MAX
  };

  enum zTMenuItemSelAction {
    SEL_ACTION_UNDEF,
    SEL_ACTION_BACK,
    SEL_ACTION_STARTMENU,
    SEL_ACTION_STARTITEM,
    SEL_ACTION_CLOSE,
    SEL_ACTION_CONCOMMANDS,
    SEL_ACTION_PLAY_SOUND,
    SEL_ACTION_EXECCOMMANDS
  };

  class zCMenuItem : public zCView {
  public:
    zSTRING m_parFontName;
    zSTRING m_parText[MAX_USERSTRINGS];
    zSTRING m_parBackPic;
    zSTRING m_parAlphaMode;
    int m_parAlpha;
    int m_parType;
    int m_parOnSelAction[MAX_SEL_ACTIONS];
    zSTRING m_parOnSelAction_S[MAX_SEL_ACTIONS];
    zSTRING m_parOnChgSetOption;
    zSTRING m_parOnChgSetOptionSection;
    int m_parOnEventAction[MAX_EVENTS];
    int m_parPosX;
    int m_parPosY;
    int m_parDimX;
    int m_parDimY;
    float m_parSizeStartScale;
    int m_parItemFlags;
    float m_parOpenDelayTime;
    float m_parOpenDuration;
    float m_parUserFloat[MAX_USERVARS];
    zSTRING m_parUserString[MAX_USERVARS];
    int m_parFrameSizeX;
    int m_parFrameSizeY;
    int m_iRefCtr;
    zCView* m_pInnerWindow;
    zCFont* m_pFont;
    zCFont* m_pFontHi;
    zCFont* m_pFontSel;
    zCFont* m_pFontDis;
    int m_bViewInitialized;
    int m_bLeaveItem;
    int m_bVisible;
    zCArray<zSTRING>m_listLines;
    zSTRING id;
    int inserted;
    int changed;
    int active;
    int open;
    int close;
    int opened;
    int closed;
    int disabled;
    zCView* orgWin;
    float fxTimer;
    float openDelayTimer;
    float activeTimer;
    int registeredCPP;
    int firstTimeInserted;

    void zCMenuItem_OnInit( zSTRING const& )            zCall( 0x004E27F0 );
    void zCMenuItem_OnInit()                            zCall( 0x004E29C0 );
    zCMenuItem* GetSelItem()                            zCall( 0x004E2120 );
    zCMenuItem( zSTRING const& a0 )                     zInit( zCMenuItem_OnInit( a0 ));
    zCMenuItem()                                        zInit( zCMenuItem_OnInit() );
    void Init()                                         zCall( 0x004E2D90 );
    void SetByScript( zSTRING& )                        zCall( 0x004E30E0 );
    int GetDimX( int )                                  zCall( 0x004E3A70 );
    int GetDimY( int )                                  zCall( 0x004E3B90 );
    void InitView()                                     zCall( 0x004E3C80 );
    void Close()                                        zCall( 0x004E3E20 );
    zTMenuItem GetType()                                zCall( 0x004E3E70 );
    void SetName( zSTRING const& )                      zCall( 0x004E3F50 );
    zSTRING& GetName()                                  zCall( 0x004E4090 );
    void GetCoords( int&, int&, int&, int& )            zCall( 0x004E40A0 );
    zTMenuItemSelAction GetSelActionType( int )         zCall( 0x004E40C0 );
    zSTRING& GetSelActionString( int )                  zCall( 0x004E40D0 );
    void SetName( zSTRING& )                            zCall( 0x004E40F0 );
    void Register()                                     zCall( 0x004E4250 );
    void Unregister()                                   zCall( 0x004E4430 );
    int IsRegistered()                                  zCall( 0x004E45A0 );
    void UpdateSize()                                   zCall( 0x004E4D30 );
    int GetEventFunc( zTMenuItemEvent )                 zCall( 0x004E5780 );
    void SetIsActive( int )                             zCall( 0x004E5790 );
    void SetIsSelectable( int )                         zCall( 0x004E58B0 );
    int GetIsSelectable()                               zCall( 0x004E5900 );
    void SetIsDisabled( int )                           zCall( 0x004E5970 );
    int GetIsDisabled()                                 zCall( 0x004E5980 );
    void SetIsVisible( int )                            zCall( 0x004E59C0 );
    int GetIsVisible()                                  zCall( 0x004E59D0 );
    static int CompareNames( void const*, void const* ) zCall( 0x004E1D00 );
    static void Startup()                               zCall( 0x004E1D70 );
    static void Shutdown()                              zCall( 0x004E1DF0 );
    static zCMenuItem* GetByName( zSTRING const& )      zCall( 0x004E1F30 );
    static zCMenuItem* Create( zSTRING const& )         zCall( 0x004E2160 );
    /* for zCViewBase num : 32*/
    virtual ~zCMenuItem()                               zCall( 0x004E2B40 );
    virtual void DrawItems()                            zCall( 0x004E55C0 );
    virtual void InitMenuItem()                         zCall( 0x004E3BF0 );
    virtual int ToggleValue( int, int )                 zCall( 0x004E3E40 );
    virtual int Run()                                   zCall( 0x004E5030 );
    virtual zSTRING GetText( int )                      zCall( 0x004E3E80 );
    virtual void SetText( zSTRING const&, int, int )    zCall( 0x004E4660 );
    virtual void SetText( zCArray<zSTRING>, int )       zCall( 0x004E4E00 );
    virtual void SetMinValue( float )                   zCall( 0x004E2750 );
    virtual void SetMaxValue( float )                   zCall( 0x004E2760 );
    virtual void Enter()                                zCall( 0x004E4FD0 );
    virtual void Leave()                                zCall( 0x004E4FE0 );
    virtual void Draw()                                 zCall( 0x004E5440 );
    virtual void DrawFront()                            zCall( 0x004E5460 );
    virtual int Show()                                  zCall( 0x004E3D70 );
    virtual int Hide()                                  zCall( 0x004E3DB0 );
    virtual int HasBeenCanceled()                       zCall( 0x004E2770 );
    virtual void Open()                                 zCall( 0x004E3DF0 );
    virtual int Input( int, zSTRING& )                  zCall( 0x004E5090 );
    virtual void InsertInWin( zCView* )                 zCall( 0x004E3410 );
    virtual void RemoveFromWin()                        zCall( 0x004E3A10 );
    virtual void UpdateContent()                        zCall( 0x004E55E0 );
    virtual void UpdateFX()                             zCall( 0x004E55F0 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                      zCall( 0x004E4FF0 );

    // static properties
    static zCArraySort<zCMenuItem*>& itemList;
    static zCMenuItem*& tmp;

    // user API
    #include "zCMenuItem.inl"
  };

  class zCMenuItemInput : public zCMenuItem {
  public:
    zSTRING value;
    unsigned short curPos;
    int canceled;

    zCMenuItemInput() {}
    void zCMenuItemInput_OnInit( zSTRING const& ) zCall( 0x004E5A10 );
    zCMenuItemInput( zSTRING const& a0 )          zInit( zCMenuItemInput_OnInit( a0 ));
    void SetValue( zSTRING )                      zCall( 0x004E5C70 );
    zSTRING GetValue()                            zCall( 0x004E5CF0 );
    /* for zCViewBase num : 32*/
    virtual ~zCMenuItemInput()                    zCall( 0x004E5BC0 );
    virtual void InitMenuItem()                   zCall( 0x004E5D10 );
    virtual int Run()                             zCall( 0x004E5F20 );
    virtual void Enter()                          zCall( 0x004E2780 );
    virtual void Leave()                          zCall( 0x004E2790 );
    virtual int HasBeenCanceled()                 zCall( 0x004E27B0 );
    virtual void InsertInWin( zCView* )           zCall( 0x004E5EF0 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                zCall( 0x004E27A0 );

    // user API
    #include "zCMenuItemInput.inl"
  };

  class zCMenuItemText : public zCMenuItem {
  public:
    enum zCMenuItemTextEnum3 {
      MODE_SIMPLE,
      MODE_ENUM,
      MODE_MULTILINE
    };

    zCMenuItemTextEnum3 m_mode;
    zSTRING m_fullText;
    int m_numOptions;
    int m_topLine;
    int m_viewLines;
    int m_numLines;
    int m_unformated;

    zCMenuItemText() {}
    void zCMenuItemText_OnInit( zSTRING const& )     zCall( 0x004E62D0 );
    zCMenuItemText( zSTRING const& a0 )              zInit( zCMenuItemText_OnInit( a0 ));
    void FormatMultiline()                           zCall( 0x004E6450 );
    void DrawMultiline()                             zCall( 0x004E6850 );
    /* for zCViewBase num : 33*/
    virtual ~zCMenuItemText()                        zCall( 0x004E63A0 );
    virtual void InitMenuItem()                      zCall( 0x004E6C20 );
    virtual void SetText( zSTRING const&, int, int ) zCall( 0x004E7170 );
    virtual void SetText( zCArray<zSTRING>, int )    zCall( 0x004E7470 );
    virtual void DrawFront()                         zCall( 0x004E6410 );
    virtual void SetEnum( zSTRING const& )           zCall( 0x004E6E10 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                   zCall( 0x004E6FB0 );

    // user API
    #include "zCMenuItemText.inl"
  };

  class zCMenuItemSlider : public zCMenuItem {
  public:
    zCViewWindow* slider;
    int slideStep;
    float sliderValue;
    int sliderDimX;

    zCMenuItemSlider() {}
    void zCMenuItemSlider_OnInit( zSTRING const& ) zCall( 0x004E74D0 );
    zCMenuItemSlider( zSTRING const& a0 )          zInit( zCMenuItemSlider_OnInit( a0 ));
    void SetValue( float )                         zCall( 0x004E7C10 );
    float GetValue()                               zCall( 0x004E7CF0 );
    /* for zCViewBase num : 33*/
    virtual ~zCMenuItemSlider()                    zCall( 0x004E7570 );
    virtual void InitMenuItem()                    zCall( 0x004E78A0 );
    virtual int ToggleValue( int, int )            zCall( 0x004E7590 );
    virtual void InsertInWin( zCView* )            zCall( 0x004E7950 );
    virtual void RemoveFromWin()                   zCall( 0x004E7B80 );
    virtual void SetIsActive( int )                zCall( 0x004E27C0 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                 zCall( 0x004E27E0 );

    // user API
    #include "zCMenuItemSlider.inl"
  };

  class zCMenuItemButton : public zCMenuItem {
  public:
    zSTRING pic;
    int active;

    zCMenuItemButton() {}
    void zCMenuItemButton_OnInit( zSTRING const& ) zCall( 0x004E9080 );
    zCMenuItemButton( zSTRING const& a0 )          zInit( zCMenuItemButton_OnInit( a0 ));
    void Toggle()                                  zCall( 0x004E9540 );
    /* for zCViewBase num : 32*/
    virtual ~zCMenuItemButton()                    zCall( 0x004E9230 );
    virtual void InitMenuItem()                    zCall( 0x004E92E0 );
    virtual int Run()                              zCall( 0x004E97C0 );
    virtual void InsertInWin( zCView* )            zCall( 0x004E9A30 );
    virtual void RemoveFromWin()                   zCall( 0x004E9A70 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCMenuItemButton.inl"
  };

  class zCMenuItemChoice : public zCMenuItem {
  public:
    zCView* winCursor;
    int option;
    int optionStart;
    int curStep;

    zCMenuItemChoice() {}
    void zCMenuItemChoice_OnInit( zSTRING const& ) zCall( 0x004E7D00 );
    zCMenuItemChoice( zSTRING const& a0 )          zInit( zCMenuItemChoice_OnInit( a0 ));
    int SetOptionByString( zSTRING )               zCall( 0x004E7FA0 );
    zSTRING GetStringByOption()                    zCall( 0x004E8400 );
    void Resize()                                  zCall( 0x004E8830 );
    int GetNumOptions()                            zCall( 0x004E8B90 );
    /* for zCViewBase num : 32*/
    virtual ~zCMenuItemChoice()                    zCall( 0x004E7D60 );
    virtual void InitMenuItem()                    zCall( 0x004E8F60 );
    virtual int ToggleValue( int, int )            zCall( 0x004E7D80 );
    virtual zSTRING GetText( int )                 zCall( 0x004E8DA0 );
    virtual void Draw()                            zCall( 0x004E8900 );
    virtual void DrawFront()                       zCall( 0x004E8920 );
    virtual void InsertInWin( zCView* )            zCall( 0x004E85D0 );
    virtual void RemoveFromWin()                   zCall( 0x004E87A0 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCMenuItemChoice.inl"
  };

  struct zTMenuItemListElement {
    zSTRING title;
    zSTRING content;
    zCMenuItem* contentViewer;

    void zTMenuItemListElement_OnInit() zCall( 0x004EB190 );
    ~zTMenuItemListElement()            zCall( 0x0047ECC0 );
    zTMenuItemListElement()             zInit( zTMenuItemListElement_OnInit() );

    // user API
    #include "zTMenuItemListElement.inl"
  };

  class zCMenuItemList : public zCMenuItem {
  public:
    zCArray<zTMenuItemListElement> m_list;
    int m_cur_element;
    int m_top_element;
    zCView* m_pInnerWindow2;
    zCView* m_pViewArrowUp;
    zCView* m_pViewArrowDn;

    zCMenuItemList() {}
    void zCMenuItemList_OnInit( zSTRING const& ) zCall( 0x004E9B30 );
    zCMenuItemList( zSTRING const& a0 )          zInit( zCMenuItemList_OnInit( a0 ));
    void DeleteContent()                         zCall( 0x004E9D90 );
    void InsertEnd( zTMenuItemListElement& )     zCall( 0x004E9DE0 );
    void InsertFront( zTMenuItemListElement& )   zCall( 0x004EA000 );
    void ShowContent()                           zCall( 0x004EA9F0 );
    void JumpToNextEntry()                       zCall( 0x004EABD0 );
    void JumpToPrevEntry()                       zCall( 0x004EABF0 );
    void JumpToTopEntry()                        zCall( 0x004EAC10 );
    void JumpToLastEntry()                       zCall( 0x004EAC30 );
    /* for zCViewBase num : 32*/
    virtual ~zCMenuItemList()                    zCall( 0x004E9BB0 );
    virtual void InitMenuItem()                  zCall( 0x004E9CF0 );
    virtual int Run()                            zCall( 0x004E9C50 );
    virtual void Enter()                         zCall( 0x004EA420 );
    virtual void Leave()                         zCall( 0x004EA430 );
    virtual void DrawFront()                     zCall( 0x004EA450 );
    virtual int Show()                           zCall( 0x004E9D00 );
    virtual int Hide()                           zCall( 0x004E9D50 );
    virtual void InsertInWin( zCView* )          zCall( 0x004EA1F0 );
    virtual void RemoveFromWin()                 zCall( 0x004EA370 );
    virtual void UpdateContent()                 zCall( 0x004EA440 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )               zCall( 0x004EA7A0 );

    // user API
    #include "zCMenuItemList.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZMENU__ITEM_H__VER1__