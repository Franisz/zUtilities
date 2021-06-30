// Supported with union (c) 2018 Union team

#ifndef __OGAME_MANAGER_H__VER0__
#define __OGAME_MANAGER_H__VER0__

#include "zView.h"

namespace Gothic_I_Classic {

  class CGameManager : public zCInputCallback {
  public:
    zTRnd_AlphaBlendFunc oldAlphaBlendFunc;
    HWND* sysContextHandle;
    oCGame* gameSession;
    oCGame* backLoop;
    int exitGame;
    int gameIdle;
    int lastWorldWasGame;
    oCSavegameManager* savegameManager;
    zCArray<zSTRING> lastDatFileList;
    zCArray<zSTRING> lastWorldList;
    zSTRING backWorldRunning;
    zSTRING backDatFileRunning;
    zCView* vidScreen;
    zCView* initScreen;
    int introActive;
    int dontStartGame;
    oCBinkPlayer* videoPlayer;
    int videoPlayInGame;
    zCMenu* menu_chgkeys;
    oCMenuSavegame* menu_save_savegame;
    oCMenuSavegame* menu_load_savegame;
    int playTime;

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