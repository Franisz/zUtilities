// Supported with union (c) 2018 Union team

#ifndef __OGAME_MANAGER_H__VER3__
#define __OGAME_MANAGER_H__VER3__

namespace Gothic_II_Addon {

  class CGameManager : public zCInputCallback {
  public:
    zTRnd_AlphaBlendFunc oldAlphaBlendFunc;
    HWND* sysContextHandle;
    oCGame* gameSession;
    oCGame* backLoop;
    int exitGame;
    int exitSession;
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
    zCMenu* menu_chgkeys_ext;
    oCMenuSavegame* menu_save_savegame;
    oCMenuSavegame* menu_load_savegame;
    int playTime;

    void CGameManager_OnInit()                                      zCall( 0x004244E0 );
    CGameManager()                                                  zInit( CGameManager_OnInit() );
    void Tool_ConvertData()                                         zCall( 0x004248F0 );
    void Init( HWND__*& )                                           zCall( 0x00424C70 );
    void Done()                                                     zCall( 0x004254E0 );
    int ExitGame()                                                  zCall( 0x00425780 );
    int ExitSession()                                               zCall( 0x00425790 );
    void Run()                                                      zCall( 0x00425830 );
    void InitScreen_Open()                                          zCall( 0x00425F60 );
    void InitScreen_Menu()                                          zCall( 0x00426210 );
    void InitScreen_Close()                                         zCall( 0x00426330 );
    void InitSettings()                                             zCall( 0x00426430 );
    void ShowSplashScreen()                                         zCall( 0x00426770 );
    void RemoveSplashScreen()                                       zCall( 0x004267B0 );
    void GameInit()                                                 zCall( 0x004267D0 );
    void GameDone()                                                 zCall( 0x00426CF0 );
    void GameSessionReset()                                         zCall( 0x00426D20 );
    void GameSessionInit()                                          zCall( 0x00426E10 );
    void GameSessionDone()                                          zCall( 0x00426F70 );
    void ShowIntro()                                                zCall( 0x00427070 );
    void ShowExtro()                                                zCall( 0x00427080 );
    void PreMenu()                                                  zCall( 0x00427090 );
    void PostMenu( zSTRING )                                        zCall( 0x00427610 );
    void ApplySomeSettings()                                        zCall( 0x004276B0 );
    int GetPlaytimeSeconds()                                        zCall( 0x00429280 );
    void Menu( int )                                                zCall( 0x004292D0 );
    void Read_Savegame( int )                                       zCall( 0x0042A040 );
    void Write_Savegame( int )                                      zCall( 0x0042A2D0 );
    int HandleCancelKey( int )                                      zCall( 0x0042A700 );
    int MenuEnabled( int& )                                         zCall( 0x0042AAF0 );
    oCGame* GetGame()                                               zCall( 0x0042B1B0 );
    int IsIntroActive()                                             zCall( 0x0042B1C0 );
    void InsertMenuWorld( zSTRING&, zSTRING& )                      zCall( 0x0042B1E0 );
    void RemoveMenuWorld()                                          zCall( 0x0042B1F0 );
    int IsGameRunning()                                             zCall( 0x0042B200 );
    int IntroduceChapter()                                          zCall( 0x0042B220 );
    int IntroduceChapter( zSTRING, zSTRING, zSTRING, zSTRING, int ) zCall( 0x0042B7E0 );
    int PlayVideo( zSTRING )                                        zCall( 0x0042B940 );
    int PlayVideoEx( zSTRING, short, int )                          zCall( 0x0042BB10 );
    void ShowRealPlayTime()                                         zCall( 0x0042BDE0 );
    virtual int HandleEvent( int )                                  zCall( 0x0042AD50 );
    virtual ~CGameManager()                                         zCall( 0x00424730 );

    // user API
    #include "CGameManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OGAME_MANAGER_H__VER3__