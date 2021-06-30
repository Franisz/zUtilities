// Supported with union (c) 2018 Union team

#ifndef __ZMENU_H__VER3__
#define __ZMENU_H__VER3__

#include "zViews.h"
#include "zMenu_Item.h"
#include "zInput.h"

namespace Gothic_II_Addon {

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
    int eventOccured[MENU_EVENT_MAX];
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

    void zCMenu_OnInit()                                                            zCall( 0x004DA470 );
    void zCMenu_OnInit( zSTRING const& )                                            zCall( 0x004DA610 );
    zCMenu()                                                                        zInit( zCMenu_OnInit() );
    zCMenu( zSTRING const& a0 )                                                     zInit( zCMenu_OnInit( a0 ));
    void InitValues()                                                               zCall( 0x004DA950 );
    void Release()                                                                  zCall( 0x004DAB80 );
    void Register()                                                                 zCall( 0x004DAE00 );
    void Unregister()                                                               zCall( 0x004DB020 );
    int IsRegistered()                                                              zCall( 0x004DB0C0 );
    void ClearAllEvents()                                                           zCall( 0x004DB5A0 );
    void PreviousOption()                                                           zCall( 0x004DB5C0 );
    void NextOption()                                                               zCall( 0x004DB690 );
    void RestartMusicTheme()                                                        zCall( 0x004DB760 );
    void ForceSelAction( zTMenuItemSelAction, zSTRING const&, zCMenuItem* )         zCall( 0x004DBE20 );
    void UpdateWindowGeometry()                                                     zCall( 0x004DC070 );
    void PrintInformation( zSTRING )                                                zCall( 0x004DCD00 );
    zSTRING& GetBackWorld()                                                         zCall( 0x004DDD10 );
    zSTRING& GetBackDatFile()                                                       zCall( 0x004DDD50 );
    zCMenuItem* GetActiveItem()                                                     zCall( 0x004DDD80 );
    int GetNumberOfActiveItem()                                                     zCall( 0x004DDD90 );
    int SetActiveItem( zCMenuItem* )                                                zCall( 0x004DDE00 );
    zSTRING& GetName()                                                              zCall( 0x004DDF60 );
    void SetName( zSTRING const& )                                                  zCall( 0x004DDF70 );
    static int CompareNames( void const*, void const* )                             zCall( 0x004D9EA0 );
    static void CreateParser()                                                      zCall( 0x004D9F10 );
    static void Startup()                                                           zCall( 0x004D9F90 );
    static void Shutdown()                                                          zCall( 0x004DA380 );
    static void DefineExternal( zSTRING&, int( __cdecl* )(), int, int, ... )        zCall( 0x004DABB0 );
    static zCMenu* Create( zSTRING const& )                                         zCall( 0x004DABE0 );
    static zCParser* GetParser()                                                    zCall( 0x004DB130 );
    static zCMenu* GetByName( zSTRING const& )                                      zCall( 0x004DB140 );
    static zCMenu* GetActive()                                                      zCall( 0x004DDD60 );
    virtual int HandleEvent( int )                                                  zCall( 0x004DBB70 );
    virtual int HandleEnterItem( zCMenuItem* )                                      zCall( 0x004DE0D0 );
    virtual int HandleLeaveItem( zCMenuItem* )                                      zCall( 0x004DE0E0 );
    virtual int HandleActivateItem( zCMenuItem* )                                   zCall( 0x004DE0F0 );
    virtual int Run()                                                               zCall( 0x004DB9A0 );
    virtual void Enter()                                                            zCall( 0x004DB780 );
    virtual void Leave()                                                            zCall( 0x004DB910 );
    virtual void Render()                                                           zCall( 0x004DDC20 );
    virtual void RedrawItems()                                                      zCall( 0x004DCCD0 );
    virtual void HandleFrame( int )                                                 zCall( 0x004DC1C0 );
    virtual void Activate()                                                         zCall( 0x004DBFD0 );
    virtual ~zCMenu()                                                               zCall( 0x004DA750 );
    virtual void ScreenInit()                                                       zCall( 0x004DCDE0 );
    virtual void ScreenDone()                                                       zCall( 0x004DD9E0 );
    virtual int HandleAction()                                                      zCall( 0x004DC250 );
    virtual int HandleSelAction( zTMenuItemSelAction, zSTRING const&, zCMenuItem* ) zCall( 0x004DC430 );
    virtual void SetByScript( zSTRING const& )                                      zCall( 0x004DB320 );
    virtual int ExecCommand( zSTRING const& )                                       zCall( 0x004DCAC0 );

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

} // namespace Gothic_II_Addon

#endif // __ZMENU_H__VER3__