// Supported with union (c) 2018 Union team

#ifndef __OGAME_H__VER1__
#define __OGAME_H__VER1__

#include "z3d.h"
#include "zWorld.h"
#include "zOption.h"
#include "zSession.h"
#include "oMusicZone.h"
#include "oSavegame.h"

namespace Gothic_I_Addon {

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

    struct TObjectRoutine {
    public:
      zSTRING objName;
      int stateNum;
      int hour1;
      int min1;
      int type;

      TObjectRoutine() {}
      void Release()    zCall( 0x0065C5C0 );
      ~TObjectRoutine() zCall( 0x0065C5E0 );

      // user API
      #include "oCGame_TObjectRoutine.inl"
    };

    float cliprange;
    float fogrange;
    int inScriptStartup;
    int inLoadSaveGame;
    int inLevelChange;
    zCView* array_view[GAME_VIEW_MAX];
    int array_view_visible[GAME_VIEW_MAX];
    int array_view_enabled[GAME_VIEW_MAX];
    oCSavegameManager* savegameManager;
    zCView* game_text;
    zCView* load_screen;
    zCView* save_screen;
    zCView* pause_screen;
    oCViewStatusBar* hpBar;
    oCViewStatusBar* swimBar;
    oCViewStatusBar* manaBar;
    oCViewStatusBar* focusBar;
    int showPlayerStatus;
    int game_drawall;
    int game_frameinfo;
    int game_showaniinfo;
    int game_showwaynet;
    int game_testmode;
    int game_editwaynet;
    int game_showtime;
    int drawWayBoxes;
    int scriptStartup;
    int showFreePoints;
    oCNpc* showRoutineNpc;
    int loadNextLevel;
    zSTRING loadNextLevelName;
    zSTRING loadNextLevelStart;
    zVEC3 startpos;
    oCGameInfo* gameInfo;
    zCVobLight* pl_light;
    float pl_lightval;
    oCWorldTimer* wldTimer;
    float timeStep;
    int singleStep;
    oCGuilds* guilds;
    oCInfoManager* infoman;
    oCNewsManager* newsman;
    oCSVMManager* svmman;
    oCTradeManager* trademan;
    oCPortalRoomManager* portalman;
    oCSpawnManager* spawnman;
    float music_delay;
    oCNpc* watchnpc;
    int initial_hour;
    int initial_minute;
    zCArray<zCVob*> debugInstances;
    int debugChannels;
    int debugAllInstances;
    int oldRoutineDay;
    zCListSort<TObjectRoutine> objRoutineList;
    zCListSort<TObjectRoutine>* currentObjectRoutine;
    zCViewProgressBar* progressBar;
    zCArray<zCVisual*> visualList;

    void oCGame_OnInit()                                                         zCall( 0x0065BAE0 );
    oCGame()                                                                     zInit( oCGame_OnInit() );
    void SetCameraPosition()                                                     zCall( 0x0065C980 );
    void UpdateViewSettings()                                                    zCall( 0x0065D090 );
    void CallScriptStartup()                                                     zCall( 0x0065E050 );
    void CallScriptInit()                                                        zCall( 0x0065E2C0 );
    oCNpc* GetSelfPlayerVob()                                                    zCall( 0x0065F000 );
    oCWorldTimer* GetWorldTimer()                                                zCall( 0x0065F020 );
    oCInfoManager* GetInfoManager()                                              zCall( 0x0065F030 );
    oCNewsManager* GetNewsManager()                                              zCall( 0x0065F040 );
    oCSVMManager* GetSVMManager()                                                zCall( 0x0065F050 );
    oCTradeManager* GetTradeManager()                                            zCall( 0x0065F060 );
    oCGuilds* GetGuilds()                                                        zCall( 0x0065F070 );
    oCPortalRoomManager* GetPortalRoomManager()                                  zCall( 0x0065F090 );
    oCSpawnManager* GetSpawnManager()                                            zCall( 0x0065F0A0 );
    oHEROSTATUS GetHeroStatus()                                                  zCall( 0x0065F0B0 );
    void SetShowNews( oCNpc* )                                                   zCall( 0x0065F0F0 );
    void SetShowPlayerStatus( int )                                              zCall( 0x0065F130 );
    int GetShowPlayerStatus()                                                    zCall( 0x0065F190 );
    void UpdateScreenResolution()                                                zCall( 0x0065F1A0 );
    void UpdatePlayerStatus()                                                    zCall( 0x0065F4E0 );
    void RemoveHelperVobs( zCTree<zCVob>* )                                      zCall( 0x0065FEE0 );
    void CreateVobList( zCList<zCVob>&, zCTree<zCVob>*, zTVobType )              zCall( 0x0065FFA0 );
    void SetupPlayers( oCNpc*&, zSTRING const& )                                 zCall( 0x006602C0 );
    oCNpc* RemovePlayerFromWorld()                                               zCall( 0x00661440 );
    void InsertPlayerIntoWorld( oCNpc*, zMAT4& )                                 zCall( 0x00661490 );
    void PreSaveGameProcessing( int )                                            zCall( 0x00661550 );
    void PostSaveGameProcessing()                                                zCall( 0x006615F0 );
    void WriteSavegame( int, int )                                               zCall( 0x00661680 );
    int CheckObjectConsistency( int )                                            zCall( 0x006620F0 );
    void ClearGameState()                                                        zCall( 0x00662460 );
    void InitNpcAttitudes()                                                      zCall( 0x006627A0 );
    void RecurseCacheVobs( zCTree<zCVob>* )                                      zCall( 0x00662810 );
    void CacheVisualsIn()                                                        zCall( 0x006628A0 );
    void CacheVisualsOut()                                                       zCall( 0x00662AB0 );
    void LoadGame( int, zSTRING const& )                                         zCall( 0x00662B20 );
    void LoadSavegame( int, int )                                                zCall( 0x00662D60 );
    void ShowDebugInfos()                                                        zCall( 0x00664610 );
    void DeleteNpcs( oCNpc*, oCNpc*, float )                                     zCall( 0x006650C0 );
    void LoadWorld_novt( int, zSTRING const& )                                   zCall( 0x00665330 );
    int IsInWorld( zSTRING const& )                                              zCall( 0x00666D00 );
    void InsertObjectRoutine( int, zSTRING const&, int, int, int )               zCall( 0x00666F10 );
    void ResetObjectRoutineList()                                                zCall( 0x006670F0 );
    void ClearObjectRoutineList()                                                zCall( 0x00667110 );
    void CheckObjectRoutines()                                                   zCall( 0x00667180 );
    void SetObjectRoutineTimeChange( int, int, int, int )                        zCall( 0x00667280 );
    void ToggleShowFreePoints()                                                  zCall( 0x00667790 );
    void ShowFreePoints()                                                        zCall( 0x006677B0 );
    void RefreshNpcs()                                                           zCall( 0x00667A70 );
    void DeleteTorches()                                                         zCall( 0x00667AC0 );
    int IsDebuggingChannel( int )                                                zCall( 0x00670980 );
    int IsDebuggingInstance( zCVob* )                                            zCall( 0x006709A0 );
    int IsDebuggingAllInstances()                                                zCall( 0x006709E0 );
    int OpenView( oEGameDialogView )                                             zCall( 0x006709F0 );
    int CloseView( oEGameDialogView )                                            zCall( 0x00670A20 );
    void DefineExternals_Ulfi( zCParser* )                                       zCall( 0x006715F0 );
    void SwitchCamToNextNpc()                                                    zCall( 0x0068A1F0 );
    int TestKeys( int )                                                          zCall( 0x0068C290 );
    int IA_TestWay( int )                                                        zCall( 0x0068EE90 );
    bool IsOnPause()                                                             zInit( return singleStep != 0 );
    static int Sort_Routine( TObjectRoutine*, TObjectRoutine* )                  zCall( 0x00666EE0 );
    static int ConsoleEvalFunc( zSTRING const&, zSTRING& )                       zCall( 0x006685C0 );
    virtual int HandleEvent( int )                                               zCall( 0x0068A300 );
    virtual ~oCGame()                                                            zCall( 0x0065C1E0 );
    virtual void Init()                                                          zCall( 0x0065D480 );
    virtual void Done()                                                          zCall( 0x0065D1A0 );
    virtual void Render()                                                        zCall( 0x006648F0 );
    virtual void RenderBlit()                                                    zCall( 0x00666EC0 );
    virtual void CamInit()                                                       zCall( 0x0065C950 );
    virtual void CamInit( zCVob*, zCCamera* )                                    zCall( 0x0065C960 );
    virtual void SaveWorld( zSTRING const&, zCWorld::zTWorldSaveMode, int, int ) zCall( 0x00661300 );
    virtual int LoadWorld( zSTRING const&, zCWorld::zTWorldLoadMode )            zCall( 0x006612B0 );
    virtual void SetTime( int, int, int )                                        zCall( 0x006611F0 );
    virtual void GetTime( int&, int&, int& )                                     zCall( 0x00661280 );
    virtual void DesktopInit()                                                   zCall( 0x0065CA20 );
    virtual void EnterWorld( oCNpc*, int, zSTRING const& )                       zCall( 0x00665950 );
    virtual void Pause()                                                         zCall( 0x00664CD0 );
    virtual void Unpause()                                                       zCall( 0x00664F80 );
    virtual void SetDrawWaynet( int )                                            zCall( 0x0065C170 );
    virtual int GetDrawWaynet()                                                  zCall( 0x0065C180 );
    virtual void RenderWaynet()                                                  zCall( 0x006645D0 );
    virtual void EnvironmentInit()                                               zCall( 0x00660E00 );
    virtual void SetRanges()                                                     zCall( 0x00660A60 );
    virtual void SetRangesByCommandLine()                                        zCall( 0x00660AB0 );
    virtual zVEC3 GetStartPos()                                                  zCall( 0x0065C190 );
    virtual void SetGameInfo( oCGameInfo* )                                      zCall( 0x0065E000 );
    virtual int LoadParserFile( zSTRING const& )                                 zCall( 0x00660FA0 );
    virtual void TriggerChangeLevel( zSTRING const&, zSTRING const& )            zCall( 0x00664100 );
    virtual oCWorld* GetGameWorld()                                              zCall( 0x0065EFE0 );
    virtual oCGameInfo* GetGameInfo()                                            zCall( 0x0065F080 );
    virtual zCView* GetTextView()                                                zCall( 0x0065F010 );
    virtual void OpenLoadscreen( bool, zSTRING )                                 zCall( 0x0065E9A0 );
    virtual void OpenSavescreen( bool )                                          zCall( 0x0065E530 );
    virtual void CloseLoadscreen()                                               zCall( 0x0065EF80 );
    virtual void CloseSavescreen()                                               zCall( 0x0065E940 );
    virtual void ChangeLevel( zSTRING const&, zSTRING const& )                   zCall( 0x00663950 );
    virtual void LoadWorldStartup( zSTRING const& )                              zCall( 0x00666080 );
    virtual void LoadWorldStat( zSTRING )                                        zCall( 0x006664E0 );
    virtual void LoadWorldDyn( zSTRING const& )                                  zCall( 0x00666790 );
    virtual void InitWorldSavegame( int&, zSTRING& )                             zCall( 0x00665790 );
    virtual int CheckIfSavegameExists( zSTRING const& )                          zCall( 0x00664350 );
    virtual void CompileWorld()                                                  zCall( 0x00665E90 );
    virtual void WorldInit()                                                     zCall( 0x0065C630 );
    virtual void NpcInit()                                                       zCall( 0x0065D130 );
    virtual void NpcInit( zCTree<zCVob>* )                                       zCall( 0x0065D160 );
    virtual void SetAsPlayer( zSTRING const& )                                   zCall( 0x0065FFF0 );

    // user API
    #include "oCGame.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OGAME_H__VER1__