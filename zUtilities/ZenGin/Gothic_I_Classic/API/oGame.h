// Supported with union (c) 2018-2021 Union team

#ifndef __OGAME_H__VER0__
#define __OGAME_H__VER0__

#include "z3d.h"
#include "zWorld.h"
#include "zView.h"
#include "zOption.h"
#include "zSession.h"
#include "oMusicZone.h"
#include "oSavegame.h"

namespace Gothic_I_Classic {

  // sizeof 180h
  class oCGame : public zCSession {
  public:
    typedef enum oEGameDialogView {
      GAME_VIEW_SCREEN,
      GAME_VIEW_CONVERSATION,
      GAME_VIEW_AMBIENT,
      GAME_VIEW_CINEMA,
      GAME_VIEW_CHOICE,
      GAME_VIEW_NOISE,
      GAME_VIEW_MAX
    } oTGameDialogView;

    // sizeof 24h
    struct TObjectRoutine {
    public:
      zSTRING objName; // sizeof 14h    offset 00h
      int stateNum;    // sizeof 04h    offset 14h
      int hour1;       // sizeof 04h    offset 18h
      int min1;        // sizeof 04h    offset 1Ch
      int type;        // sizeof 04h    offset 20h

      TObjectRoutine() {}
      void Release()    zCall( 0x00636100 );
      ~TObjectRoutine() zCall( 0x00636120 );

      // user API
      #include "oCGame_TObjectRoutine.inl"
    };

    float cliprange;                                  // sizeof 04h    offset 1Ch
    float fogrange;                                   // sizeof 04h    offset 20h
    int inScriptStartup;                              // sizeof 04h    offset 24h
    int inLoadSaveGame;                               // sizeof 04h    offset 28h
    int inLevelChange;                                // sizeof 04h    offset 2Ch
    zCView* array_view[GAME_VIEW_MAX];                // sizeof 18h    offset 30h
    int array_view_visible[GAME_VIEW_MAX];            // sizeof 18h    offset 48h
    int array_view_enabled[GAME_VIEW_MAX];            // sizeof 18h    offset 60h
    oCSavegameManager* savegameManager;               // sizeof 04h    offset 78h
    zCView* game_text;                                // sizeof 04h    offset 7Ch
    zCView* load_screen;                              // sizeof 04h    offset 80h
    zCView* save_screen;                              // sizeof 04h    offset 84h
    zCView* pause_screen;                             // sizeof 04h    offset 88h
    oCViewStatusBar* hpBar;                           // sizeof 04h    offset 8Ch
    oCViewStatusBar* swimBar;                         // sizeof 04h    offset 90h
    oCViewStatusBar* manaBar;                         // sizeof 04h    offset 94h
    oCViewStatusBar* focusBar;                        // sizeof 04h    offset 98h
    int showPlayerStatus;                             // sizeof 04h    offset 9Ch
    int game_drawall;                                 // sizeof 04h    offset A0h
    int game_frameinfo;                               // sizeof 04h    offset A4h
    int game_showaniinfo;                             // sizeof 04h    offset A8h
    int game_showwaynet;                              // sizeof 04h    offset ACh
    int game_testmode;                                // sizeof 04h    offset B0h
    int game_editwaynet;                              // sizeof 04h    offset B4h
    int game_showtime;                                // sizeof 04h    offset B8h
    int drawWayBoxes;                                 // sizeof 04h    offset BCh
    int scriptStartup;                                // sizeof 04h    offset C0h
    int showFreePoints;                               // sizeof 04h    offset C4h
    oCNpc* showRoutineNpc;                            // sizeof 04h    offset C8h
    int loadNextLevel;                                // sizeof 04h    offset CCh
    zSTRING loadNextLevelName;                        // sizeof 14h    offset D0h
    zSTRING loadNextLevelStart;                       // sizeof 14h    offset E4h
    zVEC3 startpos;                                   // sizeof 0Ch    offset F8h
    oCGameInfo* gameInfo;                             // sizeof 04h    offset 104h
    zCVobLight* pl_light;                             // sizeof 04h    offset 108h
    float pl_lightval;                                // sizeof 04h    offset 10Ch
    oCWorldTimer* wldTimer;                           // sizeof 04h    offset 110h
    float timeStep;                                   // sizeof 04h    offset 114h
    int singleStep;                                   // sizeof 04h    offset 118h
    oCGuilds* guilds;                                 // sizeof 04h    offset 11Ch
    oCInfoManager* infoman;                           // sizeof 04h    offset 120h
    oCNewsManager* newsman;                           // sizeof 04h    offset 124h
    oCSVMManager* svmman;                             // sizeof 04h    offset 128h
    oCTradeManager* trademan;                         // sizeof 04h    offset 12Ch
    oCPortalRoomManager* portalman;                   // sizeof 04h    offset 130h
    oCSpawnManager* spawnman;                         // sizeof 04h    offset 134h
    float music_delay;                                // sizeof 04h    offset 138h
    oCNpc* watchnpc;                                  // sizeof 04h    offset 13Ch
    int initial_hour;                                 // sizeof 04h    offset 140h
    int initial_minute;                               // sizeof 04h    offset 144h
    zCArray<zCVob*> debugInstances;                   // sizeof 0Ch    offset 148h
    int debugChannels;                                // sizeof 04h    offset 154h
    int debugAllInstances;                            // sizeof 04h    offset 158h
    int oldRoutineDay;                                // sizeof 04h    offset 15Ch
    zCListSort<TObjectRoutine> objRoutineList;        // sizeof 0Ch    offset 160h
    zCListSort<TObjectRoutine>* currentObjectRoutine; // sizeof 04h    offset 16Ch
    zCViewProgressBar* progressBar;                   // sizeof 04h    offset 170h
    zCArray<zCVisual*> visualList;                    // sizeof 0Ch    offset 174h

    void oCGame_OnInit()                                                         zCall( 0x006356A0 );
    oCGame()                                                                     zInit( oCGame_OnInit() );
    void SetCameraPosition()                                                     zCall( 0x00636470 );
    void UpdateViewSettings()                                                    zCall( 0x00636B50 );
    void CallScriptStartup()                                                     zCall( 0x00637C10 );
    void CallScriptInit()                                                        zCall( 0x00637E50 );
    oCNpc* GetSelfPlayerVob()                                                    zCall( 0x00638AB0 );
    oCWorldTimer* GetWorldTimer()                                                zCall( 0x00638AD0 );
    oCInfoManager* GetInfoManager()                                              zCall( 0x00638AE0 );
    oCNewsManager* GetNewsManager()                                              zCall( 0x00638AF0 );
    oCSVMManager* GetSVMManager()                                                zCall( 0x00638B00 );
    oCTradeManager* GetTradeManager()                                            zCall( 0x00638B10 );
    oCGuilds* GetGuilds()                                                        zCall( 0x00638B20 );
    oCPortalRoomManager* GetPortalRoomManager()                                  zCall( 0x00638B40 );
    oCSpawnManager* GetSpawnManager()                                            zCall( 0x00638B50 );
    oHEROSTATUS GetHeroStatus()                                                  zCall( 0x00638B60 );
    void SetShowNews( oCNpc* )                                                   zCall( 0x00638BA0 );
    void SetShowPlayerStatus( int )                                              zCall( 0x00638BE0 );
    int GetShowPlayerStatus()                                                    zCall( 0x00638C40 );
    void UpdateScreenResolution()                                                zCall( 0x00638C50 );
    void UpdatePlayerStatus()                                                    zCall( 0x00638F90 );
    void RemoveHelperVobs( zCTree<zCVob>* )                                      zCall( 0x00639730 );
    void CreateVobList( zCList<zCVob>&, zCTree<zCVob>*, zTVobType )              zCall( 0x006397F0 );
    void SetupPlayers( oCNpc*&, zSTRING const& )                                 zCall( 0x00639AC0 );
    oCNpc* RemovePlayerFromWorld()                                               zCall( 0x0063AB50 );
    void InsertPlayerIntoWorld( oCNpc*, zMAT4& )                                 zCall( 0x0063ABA0 );
    void PreSaveGameProcessing( int )                                            zCall( 0x0063AC50 );
    void PostSaveGameProcessing()                                                zCall( 0x0063ACF0 );
    void WriteSavegame( int, int )                                               zCall( 0x0063AD80 );
    int CheckObjectConsistency( int )                                            zCall( 0x0063B6D0 );
    void ClearGameState()                                                        zCall( 0x0063B9E0 );
    void InitNpcAttitudes()                                                      zCall( 0x0063BD00 );
    void RecurseCacheVobs( zCTree<zCVob>* )                                      zCall( 0x0063BD70 );
    void CacheVisualsIn()                                                        zCall( 0x0063BE00 );
    void CacheVisualsOut()                                                       zCall( 0x0063C000 );
    void LoadGame( int, zSTRING const& )                                         zCall( 0x0063C070 );
    void LoadSavegame( int, int )                                                zCall( 0x0063C2A0 );
    void ShowDebugInfos()                                                        zCall( 0x0063D940 );
    void DeleteNpcs( oCNpc*, oCNpc*, float )                                     zCall( 0x0063E300 );
    void LoadWorld_novt( int, zSTRING const& )                                   zCall( 0x0063E530 );
    int IsInWorld( zSTRING const& )                                              zCall( 0x0063FCF0 );
    void InsertObjectRoutine( int, zSTRING const&, int, int, int )               zCall( 0x0063FEE0 );
    void ResetObjectRoutineList()                                                zCall( 0x006400D0 );
    void ClearObjectRoutineList()                                                zCall( 0x006400F0 );
    void CheckObjectRoutines()                                                   zCall( 0x00640160 );
    void SetObjectRoutineTimeChange( int, int, int, int )                        zCall( 0x00640260 );
    void ToggleShowFreePoints()                                                  zCall( 0x006406E0 );
    void ShowFreePoints()                                                        zCall( 0x00640700 );
    void RefreshNpcs()                                                           zCall( 0x006409B0 );
    void DeleteTorches()                                                         zCall( 0x00640A00 );
    int IsDebuggingChannel( int )                                                zCall( 0x00648C60 );
    int IsDebuggingInstance( zCVob* )                                            zCall( 0x00648C80 );
    int IsDebuggingAllInstances()                                                zCall( 0x00648CC0 );
    int OpenView( oEGameDialogView )                                             zCall( 0x00648CD0 );
    int CloseView( oEGameDialogView )                                            zCall( 0x00648D00 );
    void DefineExternals_Ulfi( zCParser* )                                       zCall( 0x006495B0 );
    void SwitchCamToNextNpc()                                                    zCall( 0x0065EDD0 );
    int TestKeys( int )                                                          zCall( 0x00660000 );
    int IA_TestWay( int )                                                        zCall( 0x006626A0 );
    bool IsOnPause()                                                             zInit( return singleStep != 0 );
    static int Sort_Routine( TObjectRoutine*, TObjectRoutine* )                  zCall( 0x0063FEB0 );
    static int ConsoleEvalFunc( zSTRING const&, zSTRING& )                       zCall( 0x00641420 );
    virtual int HandleEvent( int )                                               zCall( 0x0065EEE0 );
    virtual ~oCGame()                                                            zCall( 0x00635D20 );
    virtual void Init()                                                          zCall( 0x00636F50 );
    virtual void Done()                                                          zCall( 0x00636C70 );
    virtual void Render()                                                        zCall( 0x0063DBE0 );
    virtual void RenderBlit()                                                    zCall( 0x0063FE90 );
    virtual void CamInit()                                                       zCall( 0x00636450 );
    virtual void CamInit( zCVob*, zCCamera* )                                    zCall( 0x00636460 );
    virtual void SaveWorld( zSTRING const&, zCWorld::zTWorldSaveMode, int, int ) zCall( 0x0063AA20 );
    virtual int LoadWorld( zSTRING const&, zCWorld::zTWorldLoadMode )            zCall( 0x0063A9D0 );
    virtual void SetTime( int, int, int )                                        zCall( 0x0063A910 );
    virtual void GetTime( int&, int&, int& )                                     zCall( 0x0063A9A0 );
    virtual void DesktopInit()                                                   zCall( 0x00636510 );
    virtual void EnterWorld( oCNpc*, int, zSTRING const& )                       zCall( 0x0063EAD0 );
    virtual void Pause()                                                         zCall( 0x0063DF50 );
    virtual void Unpause()                                                       zCall( 0x0063E1D0 );
    virtual void SetDrawWaynet( int )                                            zCall( 0x00635CB0 );
    virtual int GetDrawWaynet()                                                  zCall( 0x00635CC0 );
    virtual void RenderWaynet()                                                  zCall( 0x0063D900 );
    virtual void EnvironmentInit()                                               zCall( 0x0063A570 );
    virtual void SetRanges()                                                     zCall( 0x0063A220 );
    virtual void SetRangesByCommandLine()                                        zCall( 0x0063A270 );
    virtual zVEC3 GetStartPos()                                                  zCall( 0x00635CD0 );
    virtual void SetGameInfo( oCGameInfo* )                                      zCall( 0x00637BC0 );
    virtual int LoadParserFile( zSTRING const& )                                 zCall( 0x0063A710 );
    virtual void TriggerChangeLevel( zSTRING const&, zSTRING const& )            zCall( 0x0063D480 );
    virtual oCWorld* GetGameWorld()                                              zCall( 0x00638A90 );
    virtual oCGameInfo* GetGameInfo()                                            zCall( 0x00638B30 );
    virtual zCView* GetTextView()                                                zCall( 0x00638AC0 );
    virtual void OpenLoadscreen( bool, zSTRING )                                 zCall( 0x006384C0 );
    virtual void OpenSavescreen( bool )                                          zCall( 0x00638080 );
    virtual void CloseLoadscreen()                                               zCall( 0x00638A30 );
    virtual void CloseSavescreen()                                               zCall( 0x00638460 );
    virtual void ChangeLevel( zSTRING const&, zSTRING const& )                   zCall( 0x0063CD60 );
    virtual void LoadWorldStartup( zSTRING const& )                              zCall( 0x0063F190 );
    virtual void LoadWorldStat( zSTRING )                                        zCall( 0x0063F590 );
    virtual void LoadWorldDyn( zSTRING const& )                                  zCall( 0x0063F800 );
    virtual void InitWorldSavegame( int&, zSTRING& )                             zCall( 0x0063E910 );
    virtual int CheckIfSavegameExists( zSTRING const& )                          zCall( 0x0063D6D0 );
    virtual void CompileWorld()                                                  zCall( 0x0063EFD0 );
    virtual void WorldInit()                                                     zCall( 0x00636170 );
    virtual void NpcInit()                                                       zCall( 0x00636BF0 );
    virtual void NpcInit( zCTree<zCVob>* )                                       zCall( 0x00636C20 );
    virtual void SetAsPlayer( zSTRING const& )                                   zCall( 0x00639840 );

    // user API
    #include "oCGame.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OGAME_H__VER0__