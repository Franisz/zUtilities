// Supported with union (c) 2018-2021 Union team

#ifndef __OGAME_MANAGER_H__VER2__
#define __OGAME_MANAGER_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 94h
  class CGameManager : public zCInputCallback {
  public:
    zTRnd_AlphaBlendFunc oldAlphaBlendFunc; // sizeof 04h    offset 04h
    HWND* sysContextHandle;                 // sizeof 04h    offset 08h
    oCGame* gameSession;                    // sizeof 04h    offset 0Ch
    oCGame* backLoop;                       // sizeof 04h    offset 10h
    int exitGame;                           // sizeof 04h    offset 14h
    int exitSession;                        // sizeof 04h    offset 18h
    int gameIdle;                           // sizeof 04h    offset 1Ch
    int lastWorldWasGame;                   // sizeof 04h    offset 20h
    oCSavegameManager* savegameManager;     // sizeof 04h    offset 24h
    zCArray<zSTRING> lastDatFileList;       // sizeof 0Ch    offset 28h
    zCArray<zSTRING> lastWorldList;         // sizeof 0Ch    offset 34h
    zSTRING backWorldRunning;               // sizeof 14h    offset 40h
    zSTRING backDatFileRunning;             // sizeof 14h    offset 54h
    zCView* vidScreen;                      // sizeof 04h    offset 68h
    zCView* initScreen;                     // sizeof 04h    offset 6Ch
    int introActive;                        // sizeof 04h    offset 70h
    int dontStartGame;                      // sizeof 04h    offset 74h
    oCBinkPlayer* videoPlayer;              // sizeof 04h    offset 78h
    int videoPlayInGame;                    // sizeof 04h    offset 7Ch
    zCMenu* menu_chgkeys;                   // sizeof 04h    offset 80h
    zCMenu* menu_chgkeys_ext;               // sizeof 04h    offset 84h
    oCMenuSavegame* menu_save_savegame;     // sizeof 04h    offset 88h
    oCMenuSavegame* menu_load_savegame;     // sizeof 04h    offset 8Ch
    int playTime;                           // sizeof 04h    offset 90h

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