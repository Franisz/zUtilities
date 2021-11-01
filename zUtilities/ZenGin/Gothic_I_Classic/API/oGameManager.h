// Supported with union (c) 2018-2021 Union team

#ifndef __OGAME_MANAGER_H__VER0__
#define __OGAME_MANAGER_H__VER0__

#include "zView.h"

namespace Gothic_I_Classic {

  // sizeof 8Ch
  class CGameManager : public zCInputCallback {
  public:
    zTRnd_AlphaBlendFunc oldAlphaBlendFunc; // sizeof 04h    offset 04h
    HWND* sysContextHandle;                 // sizeof 04h    offset 08h
    oCGame* gameSession;                    // sizeof 04h    offset 0Ch
    oCGame* backLoop;                       // sizeof 04h    offset 10h
    int exitGame;                           // sizeof 04h    offset 14h
    int gameIdle;                           // sizeof 04h    offset 18h
    int lastWorldWasGame;                   // sizeof 04h    offset 1Ch
    oCSavegameManager* savegameManager;     // sizeof 04h    offset 20h
    zCArray<zSTRING> lastDatFileList;       // sizeof 0Ch    offset 24h
    zCArray<zSTRING> lastWorldList;         // sizeof 0Ch    offset 30h
    zSTRING backWorldRunning;               // sizeof 14h    offset 3Ch
    zSTRING backDatFileRunning;             // sizeof 14h    offset 50h
    zCView* vidScreen;                      // sizeof 04h    offset 64h
    zCView* initScreen;                     // sizeof 04h    offset 68h
    int introActive;                        // sizeof 04h    offset 6Ch
    int dontStartGame;                      // sizeof 04h    offset 70h
    oCBinkPlayer* videoPlayer;              // sizeof 04h    offset 74h
    int videoPlayInGame;                    // sizeof 04h    offset 78h
    zCMenu* menu_chgkeys;                   // sizeof 04h    offset 7Ch
    oCMenuSavegame* menu_save_savegame;     // sizeof 04h    offset 80h
    oCMenuSavegame* menu_load_savegame;     // sizeof 04h    offset 84h
    int playTime;                           // sizeof 04h    offset 88h

    void CGameManager_OnInit()                                      zCall( 0x004238F0 );
    CGameManager()                                                  zInit( CGameManager_OnInit() );
    void Tool_ConvertData()                                         zCall( 0x00423D00 );
    void Init( HWND__*& )                                           zCall( 0x004240C0 );
    void Done()                                                     zCall( 0x00424850 );
    int ExitGame()                                                  zCall( 0x00424A80 );
    void Run()                                                      zCall( 0x00424AF0 );
    void InitScreen_Open()                                          zCall( 0x00425070 );
    void InitScreen_Menu()                                          zCall( 0x00425330 );
    void InitScreen_Close()                                         zCall( 0x00425450 );
    void InitSettings()                                             zCall( 0x00425550 );
    void ShowSplashScreen()                                         zCall( 0x00425760 );
    void RemoveSplashScreen()                                       zCall( 0x004258E0 );
    void GameInit()                                                 zCall( 0x00425900 );
    void GameDone()                                                 zCall( 0x00425E10 );
    void GameSessionReset()                                         zCall( 0x00425E40 );
    void GameSessionInit()                                          zCall( 0x00425F30 );
    void GameSessionDone()                                          zCall( 0x004260A0 );
    void ShowIntro()                                                zCall( 0x004261A0 );
    void ShowExtro()                                                zCall( 0x004261B0 );
    void PreMenu()                                                  zCall( 0x004261C0 );
    void PostMenu( zSTRING )                                        zCall( 0x00426720 );
    void ApplySomeSettings()                                        zCall( 0x004267C0 );
    int GetPlaytimeSeconds()                                        zCall( 0x004279A0 );
    void Menu( int )                                                zCall( 0x004279F0 );
    void Write_Savegame( int )                                      zCall( 0x00428790 );
    void Read_Savegame( int )                                       zCall( 0x00428B50 );
    int HandleCancelKey( int )                                      zCall( 0x00428D50 );
    int MenuEnabled( int& )                                         zCall( 0x00429140 );
    oCGame* GetGame()                                               zCall( 0x00429520 );
    int IsIntroActive()                                             zCall( 0x00429530 );
    void InsertMenuWorld( zSTRING&, zSTRING& )                      zCall( 0x00429550 );
    void RemoveMenuWorld()                                          zCall( 0x00429560 );
    int IsGameRunning()                                             zCall( 0x00429570 );
    int IntroduceChapter()                                          zCall( 0x00429590 );
    int IntroduceChapter( zSTRING, zSTRING, zSTRING, zSTRING, int ) zCall( 0x00429A20 );
    int PlayVideo( zSTRING, int )                                   zCall( 0x00429B80 );
    void ShowRealPlayTime()                                         zCall( 0x00429D50 );
    virtual int HandleEvent( int )                                  zCall( 0x004293C0 );
    virtual ~CGameManager()                                         zCall( 0x00423B40 );

    // user API
    #include "CGameManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OGAME_MANAGER_H__VER0__