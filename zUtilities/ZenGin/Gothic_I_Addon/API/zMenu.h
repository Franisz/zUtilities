// Supported with union (c) 2018 Union team

#ifndef __ZMENU_H__VER1__
#define __ZMENU_H__VER1__

#include "zViews.h"
#include "zMenu_Item.h"
#include "zInput.h"

namespace Gothic_I_Addon {

  enum zTMenuFlags {
    MN_UNDEF,
    MN_OVERTOP,
    MN_EXCLUSIVE,
    MN_NO_ANI        = 4,
    MN_DONTSCALE_DIM = 8,
    MN_DONTSCALE_POS = 16,
    MN_ALIGN_CENTER  = 32,
    MN_SHOW_INFO     = 64
  };

  class zCMenu : public zCInputCallback {
  public:
    enum zCMenuEnum2 {
      NONE,
      BACK,
      GO,
      FINISHED
    };

    zSTRING backPic;
    zSTRING backWorld;
    int posx;
    int posy;
    int dimx;
    int dimy;
    int alpha;
    zSTRING musicThemeName;
    int eventTimerUpdateMSec;
    zSTRING itemID[MAX_ITEMS];
    int flags;
    int defaultOutGame;
    int defaultInGame;
    zCViewWindow* m_pWindow;
    zCViewWindow* m_pInnerWindow;
    zCMenuEnum2 m_exitState;
    zSTRING name;
    zCMusicTheme* m_musicTheme;
    int m_mainSel;
    int m_screenInitDone;
    int m_use_dimx;
    int m_use_dimy;
    int m_use_posx;
    int m_use_posy;
    zCView* m_pViewInfo;
    zCVob* cursorVob;
    int eventOccured[IT_EVENT_MAX];
    int cursorEn;
    int noneSelectable;
    int registeredCPP;
    int updateTimer;
    float fxTimer;
    zTMenuItemSelAction forceSelAction;
    zSTRING forceSelAction_S;
    zCMenuItem* forceSelActionItem;
    int forcedSelAction;
    zCArray<zCMenuItem*> m_listItems;

    void zCMenu_OnInit()                                                            zCall( 0x004DDF60 );
    void zCMenu_OnInit( zSTRING const& )                                            zCall( 0x004DE130 );
    zCMenu()                                                                        zInit( zCMenu_OnInit() );
    zCMenu( zSTRING const& a0 )                                                     zInit( zCMenu_OnInit( a0 ));
    void InitValues()                                                               zCall( 0x004DE4B0 );
    void Release()                                                                  zCall( 0x004DE700 );
    void Register()                                                                 zCall( 0x004DE9E0 );
    void Unregister()                                                               zCall( 0x004DEC30 );
    int IsRegistered()                                                              zCall( 0x004DECF0 );
    void ClearAllEvents()                                                           zCall( 0x004DF240 );
    void PreviousOption()                                                           zCall( 0x004DF260 );
    void NextOption()                                                               zCall( 0x004DF330 );
    void RestartMusicTheme()                                                        zCall( 0x004DF400 );
    void ForceSelAction( zTMenuItemSelAction, zSTRING const&, zCMenuItem* )         zCall( 0x004DF9F0 );
    void UpdateWindowGeometry()                                                     zCall( 0x004DFBB0 );
    void PrintInformation( zSTRING )                                                zCall( 0x004E07A0 );
    zSTRING& GetBackWorld()                                                         zCall( 0x004E15C0 );
    zSTRING& GetBackDatFile()                                                       zCall( 0x004E1600 );
    zCMenuItem* GetActiveItem()                                                     zCall( 0x004E1630 );
    int GetNumberOfActiveItem()                                                     zCall( 0x004E1640 );
    int SetActiveItem( zCMenuItem* )                                                zCall( 0x004E16B0 );
    zSTRING& GetName()                                                              zCall( 0x004E1810 );
    void SetName( zSTRING const& )                                                  zCall( 0x004E1820 );
    static int CompareNames( void const*, void const* )                             zCall( 0x004DDA20 );
    static void CreateParser()                                                      zCall( 0x004DDA90 );
    static void Startup()                                                           zCall( 0x004DDB20 );
    static void Shutdown()                                                          zCall( 0x004DDE70 );
    static void DefineExternal( zSTRING&, int( __cdecl* )(), int, int, ... )        zCall( 0x004DE730 );
    static zCMenu* Create( zSTRING const& )                                         zCall( 0x004DE760 );
    static zCParser* GetParser()                                                    zCall( 0x004DED80 );
    static zCMenu* GetByName( zSTRING const& )                                      zCall( 0x004DED90 );
    static zCMenu* GetActive()                                                      zCall( 0x004E1610 );
    virtual int HandleEvent( int )                                                  zCall( 0x004DF6A0 );
    virtual int HandleEnterItem( zCMenuItem* )                                      zCall( 0x004E1980 );
    virtual int HandleLeaveItem( zCMenuItem* )                                      zCall( 0x004E1990 );
    virtual int HandleActivateItem( zCMenuItem* )                                   zCall( 0x004E19A0 );
    virtual int Run()                                                               zCall( 0x004DF4C0 );
    virtual void Enter()                                                            zCall( 0x004DF420 );
    virtual void Leave()                                                            zCall( 0x004DF480 );
    virtual void Render()                                                           zCall( 0x004E14E0 );
    virtual void RedrawItems()                                                      zCall( 0x004E0770 );
    virtual void HandleFrame( int )                                                 zCall( 0x004DFD00 );
    virtual void Activate()                                                         zCall( 0x004DFB90 );
    virtual ~zCMenu()                                                               zCall( 0x004DE270 );
    virtual void ScreenInit()                                                       zCall( 0x004E08E0 );
    virtual void ScreenDone()                                                       zCall( 0x004E1280 );
    virtual int HandleAction()                                                      zCall( 0x004DFD90 );
    virtual int HandleSelAction( zTMenuItemSelAction, zSTRING const&, zCMenuItem* ) zCall( 0x004DFF70 );
    virtual void SetByScript( zSTRING const& )                                      zCall( 0x004DEFC0 );
    virtual int ExecCommand( zSTRING const& )                                       zCall( 0x004E0510 );

    // static properties
    static zCParser*& menuParser;
    static zCTimer*& timer;
    static zCArraySort<zCMenu*>& menuList;
    static zCArray<zCMenu*>& activeList;
    static zCSoundFX*& browseSnd;
    static zCSoundFX*& selectSnd;
    static zCSoundFX*& escSnd;
    static zCVob*& soundSourceVob;
    static zCWorld*& world;
    static zCCamera*& camera;
    static int& inGameMenu;

    // user API
    #include "zCMenu.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZMENU_H__VER1__