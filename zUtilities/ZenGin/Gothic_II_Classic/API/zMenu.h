// Supported with union (c) 2018-2021 Union team

#ifndef __ZMENU_H__VER2__
#define __ZMENU_H__VER2__

#include "zViews.h"
#include "zMenu_Item.h"
#include "zInput.h"

namespace Gothic_II_Classic {

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

  // sizeof CC4h
  class zCMenu : public zCInputCallback {
  public:
    enum zCMenuEnum2 {
      NONE,
      BACK,
      GO,
      FINISHED
    };

    zSTRING backPic;                    // sizeof 14h    offset 04h
    zSTRING backWorld;                  // sizeof 14h    offset 18h
    int posx;                           // sizeof 04h    offset 2Ch
    int posy;                           // sizeof 04h    offset 30h
    int dimx;                           // sizeof 04h    offset 34h
    int dimy;                           // sizeof 04h    offset 38h
    int alpha;                          // sizeof 04h    offset 3Ch
    zSTRING musicThemeName;             // sizeof 14h    offset 40h
    int eventTimerUpdateMSec;           // sizeof 04h    offset 54h
    zSTRING itemID[MAX_ITEMS];          // sizeof BB8h   offset 58h
    int flags;                          // sizeof 04h    offset C10h
    int defaultOutGame;                 // sizeof 04h    offset C14h
    int defaultInGame;                  // sizeof 04h    offset C18h
    zCViewWindow* m_pWindow;            // sizeof 04h    offset C1Ch
    zCViewWindow* m_pInnerWindow;       // sizeof 04h    offset C20h
    zCMenuEnum2 m_exitState;            // sizeof 04h    offset C24h
    zSTRING name;                       // sizeof 14h    offset C28h
    zCMusicTheme* m_musicTheme;         // sizeof 04h    offset C3Ch
    int m_mainSel;                      // sizeof 04h    offset C40h
    int m_screenInitDone;               // sizeof 04h    offset C44h
    int m_use_dimx;                     // sizeof 04h    offset C48h
    int m_use_dimy;                     // sizeof 04h    offset C4Ch
    int m_use_posx;                     // sizeof 04h    offset C50h
    int m_use_posy;                     // sizeof 04h    offset C54h
    zCView* m_pViewInfo;                // sizeof 04h    offset C58h
    zCVob* cursorVob;                   // sizeof 04h    offset C5Ch
    int eventOccured[MENU_EVENT_MAX];   // sizeof 24h    offset C60h
    int cursorEn;                       // sizeof 04h    offset C84h
    int noneSelectable;                 // sizeof 04h    offset C88h
    int registeredCPP;                  // sizeof 04h    offset C8Ch
    int updateTimer;                    // sizeof 04h    offset C90h
    float fxTimer;                      // sizeof 04h    offset C94h
    zTMenuItemSelAction forceSelAction; // sizeof 04h    offset C98h
    zSTRING forceSelAction_S;           // sizeof 14h    offset C9Ch
    zCMenuItem* forceSelActionItem;     // sizeof 04h    offset CB0h
    int forcedSelAction;                // sizeof 04h    offset CB4h
    zCArray<zCMenuItem*> m_listItems;   // sizeof 0Ch    offset CB8h

    void zCMenu_OnInit()                                                            zCall( 0x004D7DD0 );
    void zCMenu_OnInit( zSTRING const& )                                            zCall( 0x004D7F70 );
    zCMenu()                                                                        zInit( zCMenu_OnInit() );
    zCMenu( zSTRING const& a0 )                                                     zInit( zCMenu_OnInit( a0 ));
    void InitValues()                                                               zCall( 0x004D82B0 );
    void Release()                                                                  zCall( 0x004D84E0 );
    void Register()                                                                 zCall( 0x004D8760 );
    void Unregister()                                                               zCall( 0x004D8980 );
    int IsRegistered()                                                              zCall( 0x004D8A20 );
    void ClearAllEvents()                                                           zCall( 0x004D8F00 );
    void PreviousOption()                                                           zCall( 0x004D8F20 );
    void NextOption()                                                               zCall( 0x004D8FF0 );
    void RestartMusicTheme()                                                        zCall( 0x004D90C0 );
    void ForceSelAction( zTMenuItemSelAction, zSTRING const&, zCMenuItem* )         zCall( 0x004D9780 );
    void UpdateWindowGeometry()                                                     zCall( 0x004D99D0 );
    void PrintInformation( zSTRING )                                                zCall( 0x004DA660 );
    zSTRING& GetBackWorld()                                                         zCall( 0x004DB360 );
    zSTRING& GetBackDatFile()                                                       zCall( 0x004DB3A0 );
    zCMenuItem* GetActiveItem()                                                     zCall( 0x004DB3D0 );
    int GetNumberOfActiveItem()                                                     zCall( 0x004DB3E0 );
    int SetActiveItem( zCMenuItem* )                                                zCall( 0x004DB450 );
    zSTRING& GetName()                                                              zCall( 0x004DB5B0 );
    void SetName( zSTRING const& )                                                  zCall( 0x004DB5C0 );
    static int CompareNames( void const*, void const* )                             zCall( 0x004D78E0 );
    static void CreateParser()                                                      zCall( 0x004D7950 );
    static void Startup()                                                           zCall( 0x004D79D0 );
    static void Shutdown()                                                          zCall( 0x004D7CE0 );
    static void DefineExternal( zSTRING&, int( __cdecl* )(), int, int, ... )        zCall( 0x004D8510 );
    static zCMenu* Create( zSTRING const& )                                         zCall( 0x004D8540 );
    static zCParser* GetParser()                                                    zCall( 0x004D8A90 );
    static zCMenu* GetByName( zSTRING const& )                                      zCall( 0x004D8AA0 );
    static zCMenu* GetActive()                                                      zCall( 0x004DB3B0 );
    virtual int HandleEvent( int )                                                  zCall( 0x004D94D0 );
    virtual int HandleEnterItem( zCMenuItem* )                                      zCall( 0x004DB720 );
    virtual int HandleLeaveItem( zCMenuItem* )                                      zCall( 0x004DB730 );
    virtual int HandleActivateItem( zCMenuItem* )                                   zCall( 0x004DB740 );
    virtual int Run()                                                               zCall( 0x004D9300 );
    virtual void Enter()                                                            zCall( 0x004D90E0 );
    virtual void Leave()                                                            zCall( 0x004D9270 );
    virtual void Render()                                                           zCall( 0x004DB270 );
    virtual void RedrawItems()                                                      zCall( 0x004DA630 );
    virtual void HandleFrame( int )                                                 zCall( 0x004D9B20 );
    virtual void Activate()                                                         zCall( 0x004D9930 );
    virtual ~zCMenu()                                                               zCall( 0x004D80B0 );
    virtual void ScreenInit()                                                       zCall( 0x004DA740 );
    virtual void ScreenDone()                                                       zCall( 0x004DB030 );
    virtual int HandleAction()                                                      zCall( 0x004D9BB0 );
    virtual int HandleSelAction( zTMenuItemSelAction, zSTRING const&, zCMenuItem* ) zCall( 0x004D9D90 );
    virtual void SetByScript( zSTRING const& )                                      zCall( 0x004D8C80 );
    virtual int ExecCommand( zSTRING const& )                                       zCall( 0x004DA420 );

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

} // namespace Gothic_II_Classic

#endif // __ZMENU_H__VER2__