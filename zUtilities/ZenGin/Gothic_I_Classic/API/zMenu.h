// Supported with union (c) 2018 Union team

#ifndef __ZMENU_H__VER0__
#define __ZMENU_H__VER0__

#include "zViews.h"
#include "zMenu_Item.h"
#include "zInput.h"

namespace Gothic_I_Classic {

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
    int eventOccured[EVENT_MAX];
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

    void zCMenu_OnInit()                                                            zCall( 0x004CD850 );
    void zCMenu_OnInit( zSTRING const& )                                            zCall( 0x004CD9F0 );
    zCMenu()                                                                        zInit( zCMenu_OnInit() );
    zCMenu( zSTRING const& a0 )                                                     zInit( zCMenu_OnInit( a0 ));
    void InitValues()                                                               zCall( 0x004CDD30 );
    void Release()                                                                  zCall( 0x004CDF60 );
    void Register()                                                                 zCall( 0x004CE1F0 );
    void Unregister()                                                               zCall( 0x004CE420 );
    int IsRegistered()                                                              zCall( 0x004CE4C0 );
    void ClearAllEvents()                                                           zCall( 0x004CE9B0 );
    void PreviousOption()                                                           zCall( 0x004CE9D0 );
    void NextOption()                                                               zCall( 0x004CEAA0 );
    void RestartMusicTheme()                                                        zCall( 0x004CEB70 );
    void ForceSelAction( zTMenuItemSelAction, zSTRING const&, zCMenuItem* )         zCall( 0x004CF150 );
    void UpdateWindowGeometry()                                                     zCall( 0x004CF320 );
    void PrintInformation( zSTRING )                                                zCall( 0x004CFE50 );
    zSTRING& GetBackWorld()                                                         zCall( 0x004D0E80 );
    zSTRING& GetBackDatFile()                                                       zCall( 0x004D0EC0 );
    zCMenuItem* GetActiveItem()                                                     zCall( 0x004D0EF0 );
    int GetNumberOfActiveItem()                                                     zCall( 0x004D0F00 );
    int SetActiveItem( zCMenuItem* )                                                zCall( 0x004D0F70 );
    zSTRING& GetName()                                                              zCall( 0x004D10D0 );
    void SetName( zSTRING const& )                                                  zCall( 0x004D10E0 );
    static int CompareNames( void const*, void const* )                             zCall( 0x004CD2B0 );
    static void CreateParser()                                                      zCall( 0x004CD320 );
    static void Startup()                                                           zCall( 0x004CD3B0 );
    static void Shutdown()                                                          zCall( 0x004CD760 );
    static void DefineExternal( zSTRING&, int( __cdecl* )(), int, int, ... )        zCall( 0x004CDF90 );
    static zCMenu* Create( zSTRING const& )                                         zCall( 0x004CDFC0 );
    static zCParser* GetParser()                                                    zCall( 0x004CE530 );
    static zCMenu* GetByName( zSTRING const& )                                      zCall( 0x004CE540 );
    static zCMenu* GetActive()                                                      zCall( 0x004D0ED0 );
    virtual int HandleEvent( int )                                                  zCall( 0x004CEE10 );
    virtual int HandleEnterItem( zCMenuItem* )                                      zCall( 0x004D1240 );
    virtual int HandleLeaveItem( zCMenuItem* )                                      zCall( 0x004D1250 );
    virtual int HandleActivateItem( zCMenuItem* )                                   zCall( 0x004D1260 );
    virtual int Run()                                                               zCall( 0x004CEC30 );
    virtual void Enter()                                                            zCall( 0x004CEB90 );
    virtual void Leave()                                                            zCall( 0x004CEBF0 );
    virtual void Render()                                                           zCall( 0x004D0DA0 );
    virtual void RedrawItems()                                                      zCall( 0x004CFE20 );
    virtual void HandleFrame( int )                                                 zCall( 0x004CF470 );
    virtual void Activate()                                                         zCall( 0x004CF300 );
    virtual ~zCMenu()                                                               zCall( 0x004CDB30 );
    virtual void ScreenInit()                                                       zCall( 0x004CFF30 );
    virtual void ScreenDone()                                                       zCall( 0x004D0B60 );
    virtual int HandleAction()                                                      zCall( 0x004CF500 );
    virtual int HandleSelAction( zTMenuItemSelAction, zSTRING const&, zCMenuItem* ) zCall( 0x004CF6E0 );
    virtual void SetByScript( zSTRING const& )                                      zCall( 0x004CE720 );
    virtual int ExecCommand( zSTRING const& )                                       zCall( 0x004CFC10 );

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

} // namespace Gothic_I_Classic

#endif // __ZMENU_H__VER0__