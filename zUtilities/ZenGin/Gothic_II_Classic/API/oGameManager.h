// Supported with union (c) 2018 Union team

#ifndef __OGAME_MANAGER_H__VER2__
#define __OGAME_MANAGER_H__VER2__

namespace Gothic_II_Classic {

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

    void CGameManager_OnInit()                                      zCall( 0x004241B0 );
    CGameManager()                                                  zInit( CGameManager_OnInit() );
    void Tool_ConvertData()                                         zCall( 0x004245C0 );
    void Init( HWND__*& )                                           zCall( 0x00424940 );
    void Done()                                                     zCall( 0x004251A0 );
    int ExitGame()                                                  zCall( 0x00425440 );
    int ExitSession()                                               zCall( 0x00425450 );
    void Run()                                                      zCall( 0x004254F0 );
    void InitScreen_Open()                                          zCall( 0x00425C20 );
    void InitScreen_Menu()                                          zCall( 0x00425ED0 );
    void InitScreen_Close()                                         zCall( 0x00425FF0 );
    void InitSettings()                                             zCall( 0x004260F0 );
    void ShowSplashScreen()                                         zCall( 0x00426430 );
    void RemoveSplashScreen()                                       zCall( 0x00426470 );
    void GameInit()                                                 zCall( 0x00426490 );
    void GameDone()                                                 zCall( 0x004269B0 );
    void GameSessionReset()                                         zCall( 0x004269E0 );
    void GameSessionInit()                                          zCall( 0x00426AD0 );
    void GameSessionDone()                                          zCall( 0x00426C30 );
    void ShowIntro()                                                zCall( 0x00426D30 );
    void ShowExtro()                                                zCall( 0x00426D40 );
    void PreMenu()                                                  zCall( 0x00426D50 );
    void PostMenu( zSTRING )                                        zCall( 0x004272D0 );
    void ApplySomeSettings()                                        zCall( 0x00427370 );
    int GetPlaytimeSeconds()                                        zCall( 0x00428EF0 );
    void Menu( int )                                                zCall( 0x00428F40 );
    void Read_Savegame( int )                                       zCall( 0x00429D20 );
    void Write_Savegame( int )                                      zCall( 0x00429FB0 );
    int HandleCancelKey( int )                                      zCall( 0x0042A3E0 );
    int MenuEnabled( int& )                                         zCall( 0x0042A7D0 );
    oCGame* GetGame()                                               zCall( 0x0042AE90 );
    int IsIntroActive()                                             zCall( 0x0042AEA0 );
    void InsertMenuWorld( zSTRING&, zSTRING& )                      zCall( 0x0042AEC0 );
    void RemoveMenuWorld()                                          zCall( 0x0042AED0 );
    int IsGameRunning()                                             zCall( 0x0042AEE0 );
    int IntroduceChapter()                                          zCall( 0x0042AF00 );
    int IntroduceChapter( zSTRING, zSTRING, zSTRING, zSTRING, int ) zCall( 0x0042B4C0 );
    int PlayVideo( zSTRING )                                        zCall( 0x0042B620 );
    int PlayVideoEx( zSTRING, short, int )                          zCall( 0x0042B7F0 );
    void ShowRealPlayTime()                                         zCall( 0x0042BAC0 );
    virtual int HandleEvent( int )                                  zCall( 0x0042AA30 );
    virtual ~CGameManager()                                         zCall( 0x00424400 );

    // user API
    #include "CGameManager.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OGAME_MANAGER_H__VER2__