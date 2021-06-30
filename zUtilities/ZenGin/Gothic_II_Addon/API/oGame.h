// Supported with union (c) 2018 Union team

#ifndef __OGAME_H__VER3__
#define __OGAME_H__VER3__

#include "z3d.h"
#include "zOption.h"
#include "zSession.h"
#include "oSavegame.h"

namespace Gothic_II_Addon {

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
      void Release()    zCall( 0x006C0280 );
      ~TObjectRoutine() zCall( 0x006C02A0 );

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
    int game_showranges;
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
    int m_bWorldEntered;
    float m_fEnterWorldTimer;
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

    void oCGame_OnInit()                                                         zCall( 0x006BF810 );
    oCGame()                                                                     zInit( oCGame_OnInit() );
    void SetCameraPosition()                                                     zCall( 0x006C05E0 );
    void UpdateViewSettings()                                                    zCall( 0x006C0C60 );
    void CallScriptStartup()                                                     zCall( 0x006C1C70 );
    void CallScriptInit()                                                        zCall( 0x006C1F60 );
    oCNpc* GetSelfPlayerVob()                                                    zCall( 0x006C2C60 );
    oCWorldTimer* GetWorldTimer()                                                zCall( 0x006C2C80 );
    oCInfoManager* GetInfoManager()                                              zCall( 0x006C2C90 );
    oCNewsManager* GetNewsManager()                                              zCall( 0x006C2CA0 );
    oCSVMManager* GetSVMManager()                                                zCall( 0x006C2CB0 );
    oCTradeManager* GetTradeManager()                                            zCall( 0x006C2CC0 );
    oCGuilds* GetGuilds()                                                        zCall( 0x006C2CD0 );
    oCPortalRoomManager* GetPortalRoomManager()                                  zCall( 0x006C2CF0 );
    oCSpawnManager* GetSpawnManager()                                            zCall( 0x006C2D00 );
    oHEROSTATUS GetHeroStatus()                                                  zCall( 0x006C2D10 );
    void SetShowNews( oCNpc* )                                                   zCall( 0x006C2D50 );
    void SetShowPlayerStatus( int )                                              zCall( 0x006C2D90 );
    int GetShowPlayerStatus()                                                    zCall( 0x006C2DF0 );
    void UpdateScreenResolution()                                                zCall( 0x006C2E00 );
    void UpdatePlayerStatus()                                                    zCall( 0x006C3140 );
    void RemoveHelperVobs( zCTree<zCVob>* )                                      zCall( 0x006C3C10 );
    void CreateVobList( zCList<zCVob>&, zCTree<zCVob>*, zTVobType )              zCall( 0x006C3CD0 );
    void SetupPlayers( oCNpc*&, zSTRING const& )                                 zCall( 0x006C3FA0 );
    oCNpc* RemovePlayerFromWorld()                                               zCall( 0x006C5020 );
    void InsertPlayerIntoWorld( oCNpc*, zMAT4& )                                 zCall( 0x006C5070 );
    void PreSaveGameProcessing( int )                                            zCall( 0x006C5120 );
    void PostSaveGameProcessing()                                                zCall( 0x006C51C0 );
    void WriteSavegame( int, int )                                               zCall( 0x006C5250 );
    int CheckObjectConsistency( int )                                            zCall( 0x006C5B50 );
    void ClearGameState()                                                        zCall( 0x006C5ED0 );
    void InitNpcAttitudes()                                                      zCall( 0x006C61D0 );
    void RecurseCacheVobs( zCTree<zCVob>* )                                      zCall( 0x006C6240 );
    void CacheVisualsIn()                                                        zCall( 0x006C62D0 );
    void CacheVisualsOut()                                                       zCall( 0x006C6530 );
    void LoadGame( int, zSTRING const& )                                         zCall( 0x006C65A0 );
    void LoadSavegame( int, int )                                                zCall( 0x006C67D0 );
    void ShowDebugInfos()                                                        zCall( 0x006C7FB0 );
    void DeleteNpcs( oCNpc*, oCNpc*, float )                                     zCall( 0x006C8E80 );
    void LoadWorld_novt( int, zSTRING const& )                                   zCall( 0x006C90B0 );
    int IsInWorld( zSTRING const& )                                              zCall( 0x006CA770 );
    void InsertObjectRoutine( int, zSTRING const&, int, int, int )               zCall( 0x006CA960 );
    void ResetObjectRoutineList()                                                zCall( 0x006CAB20 );
    void ClearObjectRoutineList()                                                zCall( 0x006CAB40 );
    void CheckObjectRoutines()                                                   zCall( 0x006CABB0 );
    void SetObjectRoutineTimeChange( int, int, int, int )                        zCall( 0x006CACB0 );
    void ToggleShowFreePoints()                                                  zCall( 0x006CB270 );
    void ShowFreePoints()                                                        zCall( 0x006CB290 );
    void RefreshNpcs()                                                           zCall( 0x006CB5F0 );
    void DeleteTorches()                                                         zCall( 0x006CB640 );
    int IsDebuggingChannel( int )                                                zCall( 0x006D3B90 );
    int IsDebuggingInstance( zCVob* )                                            zCall( 0x006D3BB0 );
    int IsDebuggingAllInstances()                                                zCall( 0x006D3BF0 );
    int OpenView( oEGameDialogView )                                             zCall( 0x006D3C00 );
    int CloseView( oEGameDialogView )                                            zCall( 0x006D3C30 );
    void DefineExternals_Ulfi( zCParser* )                                       zCall( 0x006D4780 );
    void SwitchCamToNextNpc()                                                    zCall( 0x006FBF40 );
    int TestKeys( int )                                                          zCall( 0x006FD560 );
    int IA_TestWay( int )                                                        zCall( 0x007000E0 );
    bool IsOnPause()                                                             zInit( return singleStep != 0 );
    static int Sort_Routine( TObjectRoutine*, TObjectRoutine* )                  zCall( 0x006CA930 );
    static int ConsoleEvalFunc( zSTRING const&, zSTRING& )                       zCall( 0x006CC0A0 );
    virtual int HandleEvent( int )                                               zCall( 0x006FC170 );
    virtual ~oCGame()                                                            zCall( 0x006BFEA0 );
    virtual void Init()                                                          zCall( 0x006C1060 );
    virtual void Done()                                                          zCall( 0x006C0D80 );
    virtual void Render()                                                        zCall( 0x006C86A0 );
    virtual void RenderBlit()                                                    zCall( 0x006CA910 );
    virtual void CamInit()                                                       zCall( 0x006C05C0 );
    virtual void CamInit( zCVob*, zCCamera* )                                    zCall( 0x006C05D0 );
    virtual void SaveWorld( zSTRING const&, zCWorld::zTWorldSaveMode, int, int ) zCall( 0x006C4EF0 );
    virtual int LoadWorld( zSTRING const&, zCWorld::zTWorldLoadMode )            zCall( 0x006C4EA0 );
    virtual void SetTime( int, int, int )                                        zCall( 0x006C4DE0 );
    virtual void GetTime( int&, int&, int& )                                     zCall( 0x006C4E70 );
    virtual void DesktopInit()                                                   zCall( 0x006C0680 );
    virtual void EnterWorld( oCNpc*, int, zSTRING const& )                       zCall( 0x006C96F0 );
    virtual void Pause( int = 1 )                                                zCall( 0x006C8AD0 );
    virtual void Unpause()                                                       zCall( 0x006C8D50 );
    virtual void SetDrawWaynet( int )                                            zCall( 0x006BFE30 );
    virtual int GetDrawWaynet()                                                  zCall( 0x006BFE40 );
    virtual void RenderWaynet()                                                  zCall( 0x006C7F70 );
    virtual void EnvironmentInit()                                               zCall( 0x006C4A60 );
    virtual void SetRanges()                                                     zCall( 0x006C4710 );
    virtual void SetRangesByCommandLine()                                        zCall( 0x006C4760 );
    virtual zVEC3 GetStartPos()                                                  zCall( 0x006BFE50 );
    virtual void SetGameInfo( oCGameInfo* )                                      zCall( 0x006C1C20 );
    virtual int LoadParserFile( zSTRING const& )                                 zCall( 0x006C4BE0 );
    virtual void TriggerChangeLevel( zSTRING const&, zSTRING const& )            zCall( 0x006C7AF0 );
    virtual oCWorld* GetGameWorld()                                              zCall( 0x006C2C30 );
    virtual oCGameInfo* GetGameInfo()                                            zCall( 0x006C2CE0 );
    virtual zCView* GetTextView()                                                zCall( 0x006C2C70 );
    virtual void OpenLoadscreen( bool, zSTRING )                                 zCall( 0x006C2690 );
    virtual void OpenSavescreen( bool )                                          zCall( 0x006C2250 );
    virtual void CloseLoadscreen()                                               zCall( 0x006C2BD0 );
    virtual void CloseSavescreen()                                               zCall( 0x006C2630 );
    virtual void ChangeLevel( zSTRING const&, zSTRING const& )                   zCall( 0x006C7290 );
    virtual void LoadWorldStartup( zSTRING const& )                              zCall( 0x006C9C10 );
    virtual void LoadWorldStat( zSTRING )                                        zCall( 0x006CA010 );
    virtual void LoadWorldDyn( zSTRING const& )                                  zCall( 0x006CA280 );
    virtual void InitWorldSavegame( int&, zSTRING& )                             zCall( 0x006C9530 );
    virtual int CheckIfSavegameExists( zSTRING const& )                          zCall( 0x006C7D40 );
    virtual void CompileWorld()                                                  zCall( 0x006C9A50 );
    virtual void WorldInit()                                                     zCall( 0x006C02F0 );
    virtual void NpcInit()                                                       zCall( 0x006C0D00 );
    virtual void NpcInit( zCTree<zCVob>* )                                       zCall( 0x006C0D30 );
    virtual void SetAsPlayer( zSTRING const& )                                   zCall( 0x006C3D20 );

    // static properties
    static int& s_bUseOldControls;
    static float& s_fUseSpeechReverb;
    static int& s_bUseOnlineHelp;
    static int& s_bUsePotionKeys;
    static int& s_bUseQuickSave;

    // user API
    #include "oCGame.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OGAME_H__VER3__