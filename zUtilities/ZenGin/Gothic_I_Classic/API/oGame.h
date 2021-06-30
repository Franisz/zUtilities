// Supported with union (c) 2018 Union team

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
      void Release()    zCall( 0x00636100 );
      ~TObjectRoutine() zCall( 0x00636120 );

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