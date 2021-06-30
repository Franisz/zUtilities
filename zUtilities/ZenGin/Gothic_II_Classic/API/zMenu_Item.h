// Supported with union (c) 2018 Union team

#ifndef __ZMENU__ITEM_H__VER2__
#define __ZMENU__ITEM_H__VER2__

#include "zOption.h"
#include "zViews.h"
#include "zVob.h"
#include "zMathTools.h"

namespace Gothic_II_Classic {
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

    void zCMenuItem_OnInit( zSTRING const& )            zCall( 0x004DC470 );
    void zCMenuItem_OnInit()                            zCall( 0x004DC680 );
    void Release()                                      zCall( 0x0047C150 );
    zCMenuItem* GetSelItem()                            zCall( 0x004DBDD0 );
    zCMenuItem( zSTRING const& a0 )                     zInit( zCMenuItem_OnInit( a0 ));
    zCMenuItem()                                        zInit( zCMenuItem_OnInit() );
    void Init()                                         zCall( 0x004DCA60 );
    void SetByScript( zSTRING& )                        zCall( 0x004DCDE0 );
    int GetDimX( int )                                  zCall( 0x004DD6E0 );
    int GetDimY( int )                                  zCall( 0x004DD7E0 );
    void InitView()                                     zCall( 0x004DD8D0 );
    void Close()                                        zCall( 0x004DDA60 );
    zTMenuItem GetType()                                zCall( 0x004DDAB0 );
    void SetName( zSTRING const& )                      zCall( 0x004DDB90 );
    zSTRING& GetName()                                  zCall( 0x004DDCD0 );
    void GetCoords( int&, int&, int&, int& )            zCall( 0x004DDCE0 );
    zTMenuItemSelAction GetSelActionType( int )         zCall( 0x004DDCF0 );
    zSTRING& GetSelActionString( int )                  zCall( 0x004DDD00 );
    void SetName( zSTRING& )                            zCall( 0x004DDD20 );
    void Register()                                     zCall( 0x004DDE80 );
    void Unregister()                                   zCall( 0x004DE030 );
    int IsRegistered()                                  zCall( 0x004DE160 );
    void UpdateSize()                                   zCall( 0x004DE850 );
    int GetEventFunc( zTMenuItemEvent )                 zCall( 0x004DF240 );
    void SetIsActive( int )                             zCall( 0x004DF250 );
    void SetIsSelectable( int )                         zCall( 0x004DF360 );
    int GetIsSelectable()                               zCall( 0x004DF3B0 );
    void SetIsDisabled( int )                           zCall( 0x004DF430 );
    int GetIsDisabled()                                 zCall( 0x004DF440 );
    void SetIsVisible( int )                            zCall( 0x004DF480 );
    int GetIsVisible()                                  zCall( 0x004DF490 );
    static int CompareNames( void const*, void const* ) zCall( 0x004DBA50 );
    static void Startup()                               zCall( 0x004DBAC0 );
    static void Shutdown()                              zCall( 0x004DBB30 );
    static zCMenuItem* GetByName( zSTRING const& )      zCall( 0x004DBC40 );
    static zCMenuItem* Create( zSTRING const& )         zCall( 0x004DBE10 );
    /* for zCViewBase num : 33*/
    virtual ~zCMenuItem()                               zCall( 0x004DC830 );
    virtual void DrawItems()                            zCall( 0x004DF070 );
    virtual void InitMenuItem()                         zCall( 0x004DD840 );
    virtual int ToggleValue( int, int )                 zCall( 0x004DDA80 );
    virtual int Run()                                   zCall( 0x004DEB40 );
    virtual zSTRING GetText( int )                      zCall( 0x004DDAC0 );
    virtual void SetText( zSTRING const&, int, int )    zCall( 0x004DE200 );
    virtual void SetText( zCArray<zSTRING>, int )       zCall( 0x004DE920 );
    virtual void SetMinValue( float )                   zCall( 0x004DC3D0 );
    virtual void SetMaxValue( float )                   zCall( 0x004DC3E0 );
    virtual void Enter()                                zCall( 0x004DEAE0 );
    virtual void Leave()                                zCall( 0x004DEAF0 );
    virtual void Draw()                                 zCall( 0x004DEF10 );
    virtual void DrawFront()                            zCall( 0x004DEF30 );
    virtual int Show()                                  zCall( 0x004DD9B0 );
    virtual int Hide()                                  zCall( 0x004DD9F0 );
    virtual int HasBeenCanceled()                       zCall( 0x004DC3F0 );
    virtual void Open()                                 zCall( 0x004DDA30 );
    virtual int Input( int, zSTRING& )                  zCall( 0x004DEBA0 );
    virtual void InsertInWin( zCView* )                 zCall( 0x004DD0E0 );
    virtual void RemoveFromWin()                        zCall( 0x004DD680 );
    virtual void UpdateContent()                        zCall( 0x004DF0A0 );
    virtual void UpdateFX()                             zCall( 0x004DF0B0 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                      zCall( 0x004DEB00 );

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
    void zCMenuItemInput_OnInit( zSTRING const& ) zCall( 0x004DF4D0 );
    zCMenuItemInput( zSTRING const& a0 )          zInit( zCMenuItemInput_OnInit( a0 ));
    void SetValue( zSTRING )                      zCall( 0x004DF730 );
    zSTRING GetValue()                            zCall( 0x004DF7B0 );
    /* for zCViewBase num : 33*/
    virtual ~zCMenuItemInput()                    zCall( 0x004DF680 );
    virtual void InitMenuItem()                   zCall( 0x004DF7D0 );
    virtual int Run()                             zCall( 0x004DF9B0 );
    virtual void Enter()                          zCall( 0x004DC400 );
    virtual void Leave()                          zCall( 0x004DC410 );
    virtual int HasBeenCanceled()                 zCall( 0x004DC430 );
    virtual void InsertInWin( zCView* )           zCall( 0x004DF980 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                zCall( 0x004DC420 );

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
    void zCMenuItemText_OnInit( zSTRING const& )     zCall( 0x004DFD20 );
    zCMenuItemText( zSTRING const& a0 )              zInit( zCMenuItemText_OnInit( a0 ));
    void FormatMultiline()                           zCall( 0x004DFEB0 );
    void DrawMultiline()                             zCall( 0x004E0230 );
    /* for zCViewBase num : 34*/
    virtual ~zCMenuItemText()                        zCall( 0x004DFDF0 );
    virtual void InitMenuItem()                      zCall( 0x004E0650 );
    virtual void SetText( zSTRING const&, int, int ) zCall( 0x004E0B40 );
    virtual void SetText( zCArray<zSTRING>, int )    zCall( 0x004E0E00 );
    virtual void DrawFront()                         zCall( 0x004DFE60 );
    virtual void SetEnum( zSTRING const& )           zCall( 0x004E0810 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                   zCall( 0x004E0990 );

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
    void zCMenuItemSlider_OnInit( zSTRING const& ) zCall( 0x004E0E60 );
    zCMenuItemSlider( zSTRING const& a0 )          zInit( zCMenuItemSlider_OnInit( a0 ));
    void SetValue( float )                         zCall( 0x004E15C0 );
    float GetValue()                               zCall( 0x004E1640 );
    /* for zCViewBase num : 34*/
    virtual ~zCMenuItemSlider()                    zCall( 0x004E0F00 );
    virtual void InitMenuItem()                    zCall( 0x004E12A0 );
    virtual int ToggleValue( int, int )            zCall( 0x004E0F20 );
    virtual void InsertInWin( zCView* )            zCall( 0x004E1360 );
    virtual void RemoveFromWin()                   zCall( 0x004E1530 );
    virtual void SetIsActive( int )                zCall( 0x004DC440 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                 zCall( 0x004DC460 );

    // user API
    #include "zCMenuItemSlider.inl"
  };

  class zCMenuItemButton : public zCMenuItem {
  public:
    zSTRING pic;
    int active;

    zCMenuItemButton() {}
    void zCMenuItemButton_OnInit( zSTRING const& ) zCall( 0x004E2920 );
    zCMenuItemButton( zSTRING const& a0 )          zInit( zCMenuItemButton_OnInit( a0 ));
    void Toggle()                                  zCall( 0x004E2D50 );
    /* for zCViewBase num : 33*/
    virtual ~zCMenuItemButton()                    zCall( 0x004E2AD0 );
    virtual void InitMenuItem()                    zCall( 0x004E2B80 );
    virtual int Run()                              zCall( 0x004E2F50 );
    virtual void InsertInWin( zCView* )            zCall( 0x004E31C0 );
    virtual void RemoveFromWin()                   zCall( 0x004E3200 );
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
    void zCMenuItemChoice_OnInit( zSTRING const& ) zCall( 0x004E1650 );
    zCMenuItemChoice( zSTRING const& a0 )          zInit( zCMenuItemChoice_OnInit( a0 ));
    int SetOptionByString( zSTRING )               zCall( 0x004E1960 );
    zSTRING GetStringByOption()                    zCall( 0x004E1DA0 );
    void Resize()                                  zCall( 0x004E2180 );
    int GetNumOptions()                            zCall( 0x004E24A0 );
    /* for zCViewBase num : 33*/
    virtual ~zCMenuItemChoice()                    zCall( 0x004E16B0 );
    virtual void InitMenuItem()                    zCall( 0x004E2800 );
    virtual int ToggleValue( int, int )            zCall( 0x004E16D0 );
    virtual zSTRING GetText( int )                 zCall( 0x004E2680 );
    virtual void Draw()                            zCall( 0x004E2250 );
    virtual void DrawFront()                       zCall( 0x004E2270 );
    virtual void InsertInWin( zCView* )            zCall( 0x004E1F30 );
    virtual void RemoveFromWin()                   zCall( 0x004E20F0 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "zCMenuItemChoice.inl"
  };

  struct zTMenuItemListElement {
    zSTRING title;
    zSTRING content;
    zCMenuItem* contentViewer;

    void zTMenuItemListElement_OnInit() zCall( 0x004E4810 );
    ~zTMenuItemListElement()            zCall( 0x0047B130 );
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
    void zCMenuItemList_OnInit( zSTRING const& ) zCall( 0x004E32C0 );
    zCMenuItemList( zSTRING const& a0 )          zInit( zCMenuItemList_OnInit( a0 ));
    void DeleteContent()                         zCall( 0x004E3510 );
    void InsertEnd( zTMenuItemListElement& )     zCall( 0x004E3560 );
    void InsertFront( zTMenuItemListElement& )   zCall( 0x004E3770 );
    void ShowContent()                           zCall( 0x004E4100 );
    void JumpToNextEntry()                       zCall( 0x004E42B0 );
    void JumpToPrevEntry()                       zCall( 0x004E42D0 );
    void JumpToTopEntry()                        zCall( 0x004E42F0 );
    void JumpToLastEntry()                       zCall( 0x004E4310 );
    /* for zCViewBase num : 33*/
    virtual ~zCMenuItemList()                    zCall( 0x004E3340 );
    virtual void InitMenuItem()                  zCall( 0x004E3470 );
    virtual int Run()                            zCall( 0x004E33E0 );
    virtual void Enter()                         zCall( 0x004E3B70 );
    virtual void Leave()                         zCall( 0x004E3B80 );
    virtual void DrawFront()                     zCall( 0x004E3BA0 );
    virtual int Show()                           zCall( 0x004E3480 );
    virtual int Hide()                           zCall( 0x004E34D0 );
    virtual void InsertInWin( zCView* )          zCall( 0x004E3960 );
    virtual void RemoveFromWin()                 zCall( 0x004E3AC0 );
    virtual void UpdateContent()                 zCall( 0x004E3B90 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )               zCall( 0x004E3EB0 );

    // user API
    #include "zCMenuItemList.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZMENU__ITEM_H__VER2__