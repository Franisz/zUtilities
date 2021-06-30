// Supported with union (c) 2018 Union team

#ifndef __ZMENU__ITEM_H__VER3__
#define __ZMENU__ITEM_H__VER3__

#include "zOption.h"
#include "zViews.h"
#include "zVob.h"
#include "zMathTools.h"

namespace Gothic_II_Addon {
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
    MENU_EVENT_UNDEF,
    MENU_EVENT_EXECUTE,
    MENU_EVENT_CHANGED,
    MENU_EVENT_LEAVE,
    MENU_EVENT_TIMER,
    MENU_EVENT_CLOSE,
    MENU_EVENT_INIT,
    MENU_EVENT_SEL_PREV,
    MENU_EVENT_SEL_NEXT,
    MENU_EVENT_MAX
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
    zSTRING m_parHideIfOptionSectionSet;
    zSTRING m_parHideIfOptionSet;
    int m_parHideOnValue;
    int m_iRefCtr;
    zCView* m_pInnerWindow;
    zCFont* m_pFont;
    zCFont* m_pFontHi;
    zCFont* m_pFontSel;
    zCFont* m_pFontDis;
    int m_bViewInitialized;
    int m_bLeaveItem;
    int m_bVisible;
    int m_bDontRender;
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

    void zCMenuItem_OnInit( zSTRING const& )            zCall( 0x004DEE20 );
    void zCMenuItem_OnInit()                            zCall( 0x004DF030 );
    void Release()                                      zCall( 0x0047D620 );
    zCMenuItem* GetSelItem()                            zCall( 0x004DE780 );
    zCMenuItem( zSTRING const& a0 )                     zInit( zCMenuItem_OnInit( a0 ));
    zCMenuItem()                                        zInit( zCMenuItem_OnInit() );
    void Init()                                         zCall( 0x004DF410 );
    void SetByScript( zSTRING& )                        zCall( 0x004DF790 );
    int GetDimX( int )                                  zCall( 0x004E0090 );
    int GetDimY( int )                                  zCall( 0x004E0190 );
    void InitView()                                     zCall( 0x004E0280 );
    void Close()                                        zCall( 0x004E0410 );
    zTMenuItem GetType()                                zCall( 0x004E0460 );
    void SetName( zSTRING const& )                      zCall( 0x004E0540 );
    zSTRING& GetName()                                  zCall( 0x004E0680 );
    void GetCoords( int&, int&, int&, int& )            zCall( 0x004E0690 );
    zTMenuItemSelAction GetSelActionType( int )         zCall( 0x004E06A0 );
    zSTRING& GetSelActionString( int )                  zCall( 0x004E06B0 );
    void SetName( zSTRING& )                            zCall( 0x004E06D0 );
    void Register()                                     zCall( 0x004E0830 );
    void Unregister()                                   zCall( 0x004E09E0 );
    int IsRegistered()                                  zCall( 0x004E0B10 );
    void UpdateSize()                                   zCall( 0x004E1200 );
    int GetEventFunc( zTMenuItemEvent )                 zCall( 0x004E1BF0 );
    void SetIsActive( int )                             zCall( 0x004E1C00 );
    void SetIsSelectable( int )                         zCall( 0x004E1D10 );
    int GetIsSelectable()                               zCall( 0x004E1D60 );
    void SetIsDisabled( int )                           zCall( 0x004E1DE0 );
    int GetIsDisabled()                                 zCall( 0x004E1DF0 );
    void SetIsVisible( int )                            zCall( 0x004E1E30 );
    int GetIsVisible()                                  zCall( 0x004E1E40 );
    static int CompareNames( void const*, void const* ) zCall( 0x004DE400 );
    static void Startup()                               zCall( 0x004DE470 );
    static void Shutdown()                              zCall( 0x004DE4E0 );
    static zCMenuItem* GetByName( zSTRING const& )      zCall( 0x004DE5F0 );
    static zCMenuItem* Create( zSTRING const& )         zCall( 0x004DE7C0 );
    /* for zCViewBase num : 33*/
    virtual ~zCMenuItem()                               zCall( 0x004DF1E0 );
    virtual void DrawItems()                            zCall( 0x004E1A20 );
    virtual void InitMenuItem()                         zCall( 0x004E01F0 );
    virtual int ToggleValue( int, int )                 zCall( 0x004E0430 );
    virtual int Run()                                   zCall( 0x004E14F0 );
    virtual zSTRING GetText( int )                      zCall( 0x004E0470 );
    virtual void SetText( zSTRING const&, int, int )    zCall( 0x004E0BB0 );
    virtual void SetText( zCArray<zSTRING>, int )       zCall( 0x004E12D0 );
    virtual void SetMinValue( float )                   zCall( 0x004DED80 );
    virtual void SetMaxValue( float )                   zCall( 0x004DED90 );
    virtual void Enter()                                zCall( 0x004E1490 );
    virtual void Leave()                                zCall( 0x004E14A0 );
    virtual void Draw()                                 zCall( 0x004E18C0 );
    virtual void DrawFront()                            zCall( 0x004E18E0 );
    virtual int Show()                                  zCall( 0x004E0360 );
    virtual int Hide()                                  zCall( 0x004E03A0 );
    virtual int HasBeenCanceled()                       zCall( 0x004DEDA0 );
    virtual void Open()                                 zCall( 0x004E03E0 );
    virtual int Input( int, zSTRING& )                  zCall( 0x004E1550 );
    virtual void InsertInWin( zCView* )                 zCall( 0x004DFA90 );
    virtual void RemoveFromWin()                        zCall( 0x004E0030 );
    virtual void UpdateContent()                        zCall( 0x004E1A50 );
    virtual void UpdateFX()                             zCall( 0x004E1A60 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                      zCall( 0x004E14B0 );

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
    void zCMenuItemInput_OnInit( zSTRING const& ) zCall( 0x004E1E80 );
    zCMenuItemInput( zSTRING const& a0 )          zInit( zCMenuItemInput_OnInit( a0 ));
    void SetValue( zSTRING )                      zCall( 0x004E20E0 );
    zSTRING GetValue()                            zCall( 0x004E2160 );
    /* for zCViewBase num : 33*/
    virtual ~zCMenuItemInput()                    zCall( 0x004E2030 );
    virtual void InitMenuItem()                   zCall( 0x004E2180 );
    virtual int Run()                             zCall( 0x004E2360 );
    virtual void Enter()                          zCall( 0x004DEDB0 );
    virtual void Leave()                          zCall( 0x004DEDC0 );
    virtual int HasBeenCanceled()                 zCall( 0x004DEDE0 );
    virtual void InsertInWin( zCView* )           zCall( 0x004E2330 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                zCall( 0x004DEDD0 );

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
    void zCMenuItemText_OnInit( zSTRING const& )     zCall( 0x004E26D0 );
    zCMenuItemText( zSTRING const& a0 )              zInit( zCMenuItemText_OnInit( a0 ));
    void FormatMultiline()                           zCall( 0x004E2860 );
    void DrawMultiline()                             zCall( 0x004E2BE0 );
    /* for zCViewBase num : 34*/
    virtual ~zCMenuItemText()                        zCall( 0x004E27A0 );
    virtual void InitMenuItem()                      zCall( 0x004E3000 );
    virtual void SetText( zSTRING const&, int, int ) zCall( 0x004E34F0 );
    virtual void SetText( zCArray<zSTRING>, int )    zCall( 0x004E37B0 );
    virtual void DrawFront()                         zCall( 0x004E2810 );
    virtual void SetEnum( zSTRING const& )           zCall( 0x004E31C0 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                   zCall( 0x004E3340 );

    // user API
    #include "zCMenuItemText.inl"
  };

  class zCMenuItemSlider : public zCMenuItem {
  public:
    zCViewWindow* slider;
    int slideStep;
    float sliderValue;
    int sliderDimX;
    int sliderPos;

    zCMenuItemSlider() {}
    void zCMenuItemSlider_OnInit( zSTRING const& ) zCall( 0x004E3810 );
    zCMenuItemSlider( zSTRING const& a0 )          zInit( zCMenuItemSlider_OnInit( a0 ));
    void SetValue( float )                         zCall( 0x004E3F70 );
    float GetValue()                               zCall( 0x004E3FF0 );
    /* for zCViewBase num : 34*/
    virtual ~zCMenuItemSlider()                    zCall( 0x004E38B0 );
    virtual void InitMenuItem()                    zCall( 0x004E3C50 );
    virtual int ToggleValue( int, int )            zCall( 0x004E38D0 );
    virtual void InsertInWin( zCView* )            zCall( 0x004E3D10 );
    virtual void RemoveFromWin()                   zCall( 0x004E3EE0 );
    virtual void SetIsActive( int )                zCall( 0x004DEDF0 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                 zCall( 0x004DEE10 );

    // user API
    #include "zCMenuItemSlider.inl"
  };

  class zCMenuItemButton : public zCMenuItem {
  public:
    zSTRING pic;
    int active;

    zCMenuItemButton() {}
    void zCMenuItemButton_OnInit( zSTRING const& ) zCall( 0x004E52D0 );
    zCMenuItemButton( zSTRING const& a0 )          zInit( zCMenuItemButton_OnInit( a0 ));
    void Toggle()                                  zCall( 0x004E5700 );
    /* for zCViewBase num : 33*/
    virtual ~zCMenuItemButton()                    zCall( 0x004E5480 );
    virtual void InitMenuItem()                    zCall( 0x004E5530 );
    virtual int Run()                              zCall( 0x004E5900 );
    virtual void InsertInWin( zCView* )            zCall( 0x004E5B70 );
    virtual void RemoveFromWin()                   zCall( 0x004E5BB0 );
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
    void zCMenuItemChoice_OnInit( zSTRING const& ) zCall( 0x004E4000 );
    zCMenuItemChoice( zSTRING const& a0 )          zInit( zCMenuItemChoice_OnInit( a0 ));
    int SetOptionByString( zSTRING )               zCall( 0x004E4310 );
    zSTRING GetStringByOption()                    zCall( 0x004E4750 );
    void Resize()                                  zCall( 0x004E4B30 );
    int GetNumOptions()                            zCall( 0x004E4E50 );
    /* for zCViewBase num : 33*/
    virtual ~zCMenuItemChoice()                    zCall( 0x004E4060 );
    virtual void InitMenuItem()                    zCall( 0x004E51B0 );
    virtual int ToggleValue( int, int )            zCall( 0x004E4080 );
    virtual zSTRING GetText( int )                 zCall( 0x004E5030 );
    virtual void Draw()                            zCall( 0x004E4C00 );
    virtual void DrawFront()                       zCall( 0x004E4C20 );
    virtual void InsertInWin( zCView* )            zCall( 0x004E48E0 );
    virtual void RemoveFromWin()                   zCall( 0x004E4AA0 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCMenuItemChoice.inl"
  };

  struct zTMenuItemListElement {
    zSTRING title;
    zSTRING content;
    zCMenuItem* contentViewer;

    void zTMenuItemListElement_OnInit() zCall( 0x004E71C0 );
    ~zTMenuItemListElement()            zCall( 0x0047C600 );
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
    void zCMenuItemList_OnInit( zSTRING const& ) zCall( 0x004E5C70 );
    zCMenuItemList( zSTRING const& a0 )          zInit( zCMenuItemList_OnInit( a0 ));
    void DeleteContent()                         zCall( 0x004E5EC0 );
    void InsertEnd( zTMenuItemListElement& )     zCall( 0x004E5F10 );
    void InsertFront( zTMenuItemListElement& )   zCall( 0x004E6120 );
    void ShowContent()                           zCall( 0x004E6AB0 );
    void JumpToNextEntry()                       zCall( 0x004E6C60 );
    void JumpToPrevEntry()                       zCall( 0x004E6C80 );
    void JumpToTopEntry()                        zCall( 0x004E6CA0 );
    void JumpToLastEntry()                       zCall( 0x004E6CC0 );
    /* for zCViewBase num : 33*/
    virtual ~zCMenuItemList()                    zCall( 0x004E5CF0 );
    virtual void InitMenuItem()                  zCall( 0x004E5E20 );
    virtual int Run()                            zCall( 0x004E5D90 );
    virtual void Enter()                         zCall( 0x004E6520 );
    virtual void Leave()                         zCall( 0x004E6530 );
    virtual void DrawFront()                     zCall( 0x004E6550 );
    virtual int Show()                           zCall( 0x004E5E30 );
    virtual int Hide()                           zCall( 0x004E5E80 );
    virtual void InsertInWin( zCView* )          zCall( 0x004E6310 );
    virtual void RemoveFromWin()                 zCall( 0x004E6470 );
    virtual void UpdateContent()                 zCall( 0x004E6540 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )               zCall( 0x004E6860 );

    // user API
    #include "zCMenuItemList.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZMENU__ITEM_H__VER3__