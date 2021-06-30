// Supported with union (c) 2018 Union team

#ifndef __OGAME_MANAGER_H__VER1__
#define __OGAME_MANAGER_H__VER1__

namespace Gothic_I_Addon {

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

    void CGameManager_OnInit()                                      zCall( 0x004262E0 );
    CGameManager()                                                  zInit( CGameManager_OnInit() );
    void Tool_ConvertData()                                         zCall( 0x00426710 );
    void Init( HWND__*& )                                           zCall( 0x00426B20 );
    void Done()                                                     zCall( 0x00427310 );
    int ExitGame()                                                  zCall( 0x00427560 );
    void Run()                                                      zCall( 0x004275D0 );
    void InitScreen_Open()                                          zCall( 0x00427BB0 );
    void InitScreen_Menu()                                          zCall( 0x00427EA0 );
    void InitScreen_Close()                                         zCall( 0x00427FD0 );
    void InitSettings()                                             zCall( 0x004280E0 );
    void GameInit()                                                 zCall( 0x004282F0 );
    void GameDone()                                                 zCall( 0x004287D0 );
    void GameSessionReset()                                         zCall( 0x00428800 );
    void GameSessionInit()                                          zCall( 0x00428900 );
    void GameSessionDone()                                          zCall( 0x00428A80 );
    void ShowIntro()                                                zCall( 0x00428B90 );
    void ShowExtro()                                                zCall( 0x00428BA0 );
    void PreMenu()                                                  zCall( 0x00428BB0 );
    void PostMenu( zSTRING )                                        zCall( 0x00429130 );
    void ApplySomeSettings()                                        zCall( 0x004291E0 );
    int GetPlaytimeSeconds()                                        zCall( 0x0042A4A0 );
    void Menu( int )                                                zCall( 0x0042A4F0 );
    int HandleCancelKey( int )                                      zCall( 0x0042B9A0 );
    int MenuEnabled( int& )                                         zCall( 0x0042BDF0 );
    oCGame* GetGame()                                               zCall( 0x0042C0F0 );
    int IsIntroActive()                                             zCall( 0x0042C100 );
    void InsertMenuWorld( zSTRING&, zSTRING& )                      zCall( 0x0042C120 );
    void RemoveMenuWorld()                                          zCall( 0x0042C130 );
    int IsGameRunning()                                             zCall( 0x0042C140 );
    int IntroduceChapter()                                          zCall( 0x0042C160 );
    int IntroduceChapter( zSTRING, zSTRING, zSTRING, zSTRING, int ) zCall( 0x0042C6F0 );
    int PlayVideo( zSTRING, int )                                   zCall( 0x0042C8C0 );
    void ShowRealPlayTime()                                         zCall( 0x0042CAD0 );
    virtual int HandleEvent( int )                                  zCall( 0x0042C030 );
    virtual ~CGameManager()                                         zCall( 0x00426520 );

    // user API
    #include "CGameManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OGAME_MANAGER_H__VER1__