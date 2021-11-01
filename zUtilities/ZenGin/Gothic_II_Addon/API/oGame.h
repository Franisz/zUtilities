// Supported with union (c) 2018-2021 Union team

#ifndef __OGAME_H__VER3__
#define __OGAME_H__VER3__

#include "z3d.h"
#include "zOption.h"
#include "zSession.h"
#include "oSavegame.h"

namespace Gothic_II_Addon {

  // sizeof 18Ch
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
      void Release()    zCall( 0x006C0280 );
      ~TObjectRoutine() zCall( 0x006C02A0 );

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
    int game_showranges;                              // sizeof 04h    offset BCh
    int drawWayBoxes;                                 // sizeof 04h    offset C0h
    int scriptStartup;                                // sizeof 04h    offset C4h
    int showFreePoints;                               // sizeof 04h    offset C8h
    oCNpc* showRoutineNpc;                            // sizeof 04h    offset CCh
    int loadNextLevel;                                // sizeof 04h    offset D0h
    zSTRING loadNextLevelName;                        // sizeof 14h    offset D4h
    zSTRING loadNextLevelStart;                       // sizeof 14h    offset E8h
    zVEC3 startpos;                                   // sizeof 0Ch    offset FCh
    oCGameInfo* gameInfo;                             // sizeof 04h    offset 108h
    zCVobLight* pl_light;                             // sizeof 04h    offset 10Ch
    float pl_lightval;                                // sizeof 04h    offset 110h
    oCWorldTimer* wldTimer;                           // sizeof 04h    offset 114h
    float timeStep;                                   // sizeof 04h    offset 118h
    int singleStep;                                   // sizeof 04h    offset 11Ch
    oCGuilds* guilds;                                 // sizeof 04h    offset 120h
    oCInfoManager* infoman;                           // sizeof 04h    offset 124h
    oCNewsManager* newsman;                           // sizeof 04h    offset 128h
    oCSVMManager* svmman;                             // sizeof 04h    offset 12Ch
    oCTradeManager* trademan;                         // sizeof 04h    offset 130h
    oCPortalRoomManager* portalman;                   // sizeof 04h    offset 134h
    oCSpawnManager* spawnman;                         // sizeof 04h    offset 138h
    float music_delay;                                // sizeof 04h    offset 13Ch
    oCNpc* watchnpc;                                  // sizeof 04h    offset 140h
    int m_bWorldEntered;                              // sizeof 04h    offset 144h
    float m_fEnterWorldTimer;                         // sizeof 04h    offset 148h
    int initial_hour;                                 // sizeof 04h    offset 14Ch
    int initial_minute;                               // sizeof 04h    offset 150h
    zCArray<zCVob*> debugInstances;                   // sizeof 0Ch    offset 154h
    int debugChannels;                                // sizeof 04h    offset 160h
    int debugAllInstances;                            // sizeof 04h    offset 164h
    int oldRoutineDay;                                // sizeof 04h    offset 168h
    zCListSort<TObjectRoutine> objRoutineList;        // sizeof 0Ch    offset 16Ch
    zCListSort<TObjectRoutine>* currentObjectRoutine; // sizeof 04h    offset 178h
    zCViewProgressBar* progressBar;                   // sizeof 04h    offset 17Ch
    zCArray<zCVisual*> visualList;                    // sizeof 0Ch    offset 180h

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