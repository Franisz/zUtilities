// Supported with union (c) 2018-2021 Union team

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

  // sizeof 408h
  class zCMenuItem : public zCView {
  public:
    zSTRING m_parFontName;                       // sizeof 14h    offset 100h
    zSTRING m_parText[MAX_USERSTRINGS];          // sizeof C8h    offset 114h
    zSTRING m_parBackPic;                        // sizeof 14h    offset 1DCh
    zSTRING m_parAlphaMode;                      // sizeof 14h    offset 1F0h
    int m_parAlpha;                              // sizeof 04h    offset 204h
    int m_parType;                               // sizeof 04h    offset 208h
    int m_parOnSelAction[MAX_SEL_ACTIONS];       // sizeof 14h    offset 20Ch
    zSTRING m_parOnSelAction_S[MAX_SEL_ACTIONS]; // sizeof 64h    offset 220h
    zSTRING m_parOnChgSetOption;                 // sizeof 14h    offset 284h
    zSTRING m_parOnChgSetOptionSection;          // sizeof 14h    offset 298h
    int m_parOnEventAction[MAX_EVENTS];          // sizeof 28h    offset 2ACh
    int m_parPosX;                               // sizeof 04h    offset 2D4h
    int m_parPosY;                               // sizeof 04h    offset 2D8h
    int m_parDimX;                               // sizeof 04h    offset 2DCh
    int m_parDimY;                               // sizeof 04h    offset 2E0h
    float m_parSizeStartScale;                   // sizeof 04h    offset 2E4h
    int m_parItemFlags;                          // sizeof 04h    offset 2E8h
    float m_parOpenDelayTime;                    // sizeof 04h    offset 2ECh
    float m_parOpenDuration;                     // sizeof 04h    offset 2F0h
    float m_parUserFloat[MAX_USERVARS];          // sizeof 10h    offset 2F4h
    zSTRING m_parUserString[MAX_USERVARS];       // sizeof 50h    offset 304h
    int m_parFrameSizeX;                         // sizeof 04h    offset 354h
    int m_parFrameSizeY;                         // sizeof 04h    offset 358h
    zSTRING m_parHideIfOptionSectionSet;         // sizeof 14h    offset 35Ch
    zSTRING m_parHideIfOptionSet;                // sizeof 14h    offset 370h
    int m_parHideOnValue;                        // sizeof 04h    offset 384h
    int m_iRefCtr;                               // sizeof 04h    offset 388h
    zCView* m_pInnerWindow;                      // sizeof 04h    offset 38Ch
    zCFont* m_pFont;                             // sizeof 04h    offset 390h
    zCFont* m_pFontHi;                           // sizeof 04h    offset 394h
    zCFont* m_pFontSel;                          // sizeof 04h    offset 398h
    zCFont* m_pFontDis;                          // sizeof 04h    offset 39Ch
    int m_bViewInitialized;                      // sizeof 04h    offset 3A0h
    int m_bLeaveItem;                            // sizeof 04h    offset 3A4h
    int m_bVisible;                              // sizeof 04h    offset 3A8h
    int m_bDontRender;                           // sizeof 04h    offset 3ACh
    zCArray<zSTRING>m_listLines;                 // sizeof 0Ch    offset 3B0h
    zSTRING id;                                  // sizeof 14h    offset 3BCh
    int inserted;                                // sizeof 04h    offset 3D0h
    int changed;                                 // sizeof 04h    offset 3D4h
    int active;                                  // sizeof 04h    offset 3D8h
    int open;                                    // sizeof 04h    offset 3DCh
    int close;                                   // sizeof 04h    offset 3E0h
    int opened;                                  // sizeof 04h    offset 3E4h
    int closed;                                  // sizeof 04h    offset 3E8h
    int disabled;                                // sizeof 04h    offset 3ECh
    zCView* orgWin;                              // sizeof 04h    offset 3F0h
    float fxTimer;                               // sizeof 04h    offset 3F4h
    float openDelayTimer;                        // sizeof 04h    offset 3F8h
    float activeTimer;                           // sizeof 04h    offset 3FCh
    int registeredCPP;                           // sizeof 04h    offset 400h
    int firstTimeInserted;                       // sizeof 04h    offset 404h

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

  // sizeof 424h
  class zCMenuItemInput : public zCMenuItem {
  public:
    zSTRING value;         // sizeof 14h    offset 408h
    unsigned short curPos; // sizeof 02h    offset 41Ch
    int canceled;          // sizeof 04h    offset 420h

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

  // sizeof 434h
  class zCMenuItemText : public zCMenuItem {
  public:
    enum zCMenuItemTextEnum3 {
      MODE_SIMPLE,
      MODE_ENUM,
      MODE_MULTILINE
    };

    zCMenuItemTextEnum3 m_mode; // sizeof 04h    offset 408h
    zSTRING m_fullText;         // sizeof 14h    offset 40Ch
    int m_numOptions;           // sizeof 04h    offset 420h
    int m_topLine;              // sizeof 04h    offset 424h
    int m_viewLines;            // sizeof 04h    offset 428h
    int m_numLines;             // sizeof 04h    offset 42Ch
    int m_unformated;           // sizeof 04h    offset 430h

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

  // sizeof 41Ch
  class zCMenuItemSlider : public zCMenuItem {
  public:
    zCViewWindow* slider; // sizeof 04h    offset 408h
    int slideStep;        // sizeof 04h    offset 40Ch
    float sliderValue;    // sizeof 04h    offset 410h
    int sliderDimX;       // sizeof 04h    offset 414h
    int sliderPos;        // sizeof 04h    offset 418h

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

  // sizeof 420h
  class zCMenuItemButton : public zCMenuItem {
  public:
    zSTRING pic; // sizeof 14h    offset 408h
    int active;  // sizeof 04h    offset 41Ch

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

  // sizeof 418h
  class zCMenuItemChoice : public zCMenuItem {
  public:
    zCView* winCursor; // sizeof 04h    offset 408h
    int option;        // sizeof 04h    offset 40Ch
    int optionStart;   // sizeof 04h    offset 410h
    int curStep;       // sizeof 04h    offset 414h

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

  // sizeof 2Ch
  struct zTMenuItemListElement {
    zSTRING title;             // sizeof 14h    offset 00h
    zSTRING content;           // sizeof 14h    offset 14h
    zCMenuItem* contentViewer; // sizeof 04h    offset 28h

    void zTMenuItemListElement_OnInit() zCall( 0x004E4810 );
    ~zTMenuItemListElement()            zCall( 0x0047B130 );
    zTMenuItemListElement()             zInit( zTMenuItemListElement_OnInit() );

    // user API
    #include "zTMenuItemListElement.inl"
  };

  // sizeof 428h
  class zCMenuItemList : public zCMenuItem {
  public:
    zCArray<zTMenuItemListElement> m_list; // sizeof 0Ch    offset 408h
    int m_cur_element;                     // sizeof 04h    offset 414h
    int m_top_element;                     // sizeof 04h    offset 418h
    zCView* m_pInnerWindow2;               // sizeof 04h    offset 41Ch
    zCView* m_pViewArrowUp;                // sizeof 04h    offset 420h
    zCView* m_pViewArrowDn;                // sizeof 04h    offset 424h

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