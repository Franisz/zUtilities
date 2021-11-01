// Supported with union (c) 2018-2021 Union team

#ifndef __OGAME_H__VER2__
#define __OGAME_H__VER2__

#include "z3d.h"
#include "zOption.h"
#include "zSession.h"
#include "oSavegame.h"

namespace Gothic_II_Classic {

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
      void Release()    zCall( 0x006638F0 );
      ~TObjectRoutine() zCall( 0x00663910 );

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

    void oCGame_OnInit()                                                         zCall( 0x00662E80 );
    oCGame()                                                                     zInit( oCGame_OnInit() );
    void SetCameraPosition()                                                     zCall( 0x00663C50 );
    void UpdateViewSettings()                                                    zCall( 0x006642D0 );
    void CallScriptStartup()                                                     zCall( 0x00665170 );
    void CallScriptInit()                                                        zCall( 0x00665460 );
    oCNpc* GetSelfPlayerVob()                                                    zCall( 0x00666160 );
    oCWorldTimer* GetWorldTimer()                                                zCall( 0x00666180 );
    oCInfoManager* GetInfoManager()                                              zCall( 0x00666190 );
    oCNewsManager* GetNewsManager()                                              zCall( 0x006661A0 );
    oCSVMManager* GetSVMManager()                                                zCall( 0x006661B0 );
    oCTradeManager* GetTradeManager()                                            zCall( 0x006661C0 );
    oCGuilds* GetGuilds()                                                        zCall( 0x006661D0 );
    oCPortalRoomManager* GetPortalRoomManager()                                  zCall( 0x006661F0 );
    oCSpawnManager* GetSpawnManager()                                            zCall( 0x00666200 );
    oHEROSTATUS GetHeroStatus()                                                  zCall( 0x00666210 );
    void SetShowNews( oCNpc* )                                                   zCall( 0x00666250 );
    void SetShowPlayerStatus( int )                                              zCall( 0x00666290 );
    int GetShowPlayerStatus()                                                    zCall( 0x006662F0 );
    void UpdateScreenResolution()                                                zCall( 0x00666300 );
    void UpdatePlayerStatus()                                                    zCall( 0x00666640 );
    void RemoveHelperVobs( zCTree<zCVob>* )                                      zCall( 0x00666FD0 );
    void CreateVobList( zCList<zCVob>&, zCTree<zCVob>*, zTVobType )              zCall( 0x00667090 );
    void SetupPlayers( oCNpc*&, zSTRING const& )                                 zCall( 0x00667360 );
    oCNpc* RemovePlayerFromWorld()                                               zCall( 0x006683A0 );
    void InsertPlayerIntoWorld( oCNpc*, zMAT4& )                                 zCall( 0x006683F0 );
    void PreSaveGameProcessing( int )                                            zCall( 0x006684A0 );
    void PostSaveGameProcessing()                                                zCall( 0x00668540 );
    void WriteSavegame( int, int )                                               zCall( 0x006685D0 );
    int CheckObjectConsistency( int )                                            zCall( 0x00668F20 );
    void ClearGameState()                                                        zCall( 0x006692A0 );
    void InitNpcAttitudes()                                                      zCall( 0x006695A0 );
    void RecurseCacheVobs( zCTree<zCVob>* )                                      zCall( 0x00669610 );
    void CacheVisualsIn()                                                        zCall( 0x006696A0 );
    void CacheVisualsOut()                                                       zCall( 0x00669900 );
    void LoadGame( int, zSTRING const& )                                         zCall( 0x00669970 );
    void LoadSavegame( int, int )                                                zCall( 0x00669BA0 );
    void ShowDebugInfos()                                                        zCall( 0x0066B240 );
    void DeleteNpcs( oCNpc*, oCNpc*, float )                                     zCall( 0x0066C100 );
    void LoadWorld_novt( int, zSTRING const& )                                   zCall( 0x0066C330 );
    int IsInWorld( zSTRING const& )                                              zCall( 0x0066D9F0 );
    void InsertObjectRoutine( int, zSTRING const&, int, int, int )               zCall( 0x0066DBE0 );
    void ResetObjectRoutineList()                                                zCall( 0x0066DDA0 );
    void ClearObjectRoutineList()                                                zCall( 0x0066DDC0 );
    void CheckObjectRoutines()                                                   zCall( 0x0066DE30 );
    void SetObjectRoutineTimeChange( int, int, int, int )                        zCall( 0x0066DF30 );
    void ToggleShowFreePoints()                                                  zCall( 0x0066E4F0 );
    void ShowFreePoints()                                                        zCall( 0x0066E510 );
    void RefreshNpcs()                                                           zCall( 0x0066E870 );
    void DeleteTorches()                                                         zCall( 0x0066E8C0 );
    int IsDebuggingChannel( int )                                                zCall( 0x00676E10 );
    int IsDebuggingInstance( zCVob* )                                            zCall( 0x00676E30 );
    int IsDebuggingAllInstances()                                                zCall( 0x00676E70 );
    int OpenView( oEGameDialogView )                                             zCall( 0x00676E80 );
    int CloseView( oEGameDialogView )                                            zCall( 0x00676EB0 );
    void DefineExternals_Ulfi( zCParser* )                                       zCall( 0x00677A00 );
    void SwitchCamToNextNpc()                                                    zCall( 0x0069E870 );
    int TestKeys( int )                                                          zCall( 0x0069FAC0 );
    int IA_TestWay( int )                                                        zCall( 0x006A2650 );
    bool IsOnPause()                                                             zInit( return singleStep != 0 );
    static int Sort_Routine( TObjectRoutine*, TObjectRoutine* )                  zCall( 0x0066DBB0 );
    static int ConsoleEvalFunc( zSTRING const&, zSTRING& )                       zCall( 0x0066F320 );
    virtual int HandleEvent( int )                                               zCall( 0x0069E980 );
    virtual ~oCGame()                                                            zCall( 0x00663510 );
    virtual void Init()                                                          zCall( 0x006646D0 );
    virtual void Done()                                                          zCall( 0x006643F0 );
    virtual void Render()                                                        zCall( 0x0066B930 );
    virtual void RenderBlit()                                                    zCall( 0x0066DB90 );
    virtual void CamInit()                                                       zCall( 0x00663C30 );
    virtual void CamInit( zCVob*, zCCamera* )                                    zCall( 0x00663C40 );
    virtual void SaveWorld( zSTRING const&, zCWorld::zTWorldSaveMode, int, int ) zCall( 0x00668270 );
    virtual int LoadWorld( zSTRING const&, zCWorld::zTWorldLoadMode )            zCall( 0x00668220 );
    virtual void SetTime( int, int, int )                                        zCall( 0x00668160 );
    virtual void GetTime( int&, int&, int& )                                     zCall( 0x006681F0 );
    virtual void DesktopInit()                                                   zCall( 0x00663CF0 );
    virtual void EnterWorld( oCNpc*, int, zSTRING const& )                       zCall( 0x0066C970 );
    virtual void Pause( int = 1 )                                                zCall( 0x0066BD50 );
    virtual void Unpause()                                                       zCall( 0x0066BFD0 );
    virtual void SetDrawWaynet( int )                                            zCall( 0x006634A0 );
    virtual int GetDrawWaynet()                                                  zCall( 0x006634B0 );
    virtual void RenderWaynet()                                                  zCall( 0x0066B200 );
    virtual void EnvironmentInit()                                               zCall( 0x00667DE0 );
    virtual void SetRanges()                                                     zCall( 0x00667A90 );
    virtual void SetRangesByCommandLine()                                        zCall( 0x00667AE0 );
    virtual zVEC3 GetStartPos()                                                  zCall( 0x006634C0 );
    virtual void SetGameInfo( oCGameInfo* )                                      zCall( 0x00665120 );
    virtual int LoadParserFile( zSTRING const& )                                 zCall( 0x00667F60 );
    virtual void TriggerChangeLevel( zSTRING const&, zSTRING const& )            zCall( 0x0066AD80 );
    virtual oCWorld* GetGameWorld()                                              zCall( 0x00666130 );
    virtual oCGameInfo* GetGameInfo()                                            zCall( 0x006661E0 );
    virtual zCView* GetTextView()                                                zCall( 0x00666170 );
    virtual void OpenLoadscreen( bool, zSTRING )                                 zCall( 0x00665B90 );
    virtual void OpenSavescreen( bool )                                          zCall( 0x00665750 );
    virtual void CloseLoadscreen()                                               zCall( 0x006660D0 );
    virtual void CloseSavescreen()                                               zCall( 0x00665B30 );
    virtual void ChangeLevel( zSTRING const&, zSTRING const& )                   zCall( 0x0066A660 );
    virtual void LoadWorldStartup( zSTRING const& )                              zCall( 0x0066CE90 );
    virtual void LoadWorldStat( zSTRING )                                        zCall( 0x0066D290 );
    virtual void LoadWorldDyn( zSTRING const& )                                  zCall( 0x0066D500 );
    virtual void InitWorldSavegame( int&, zSTRING& )                             zCall( 0x0066C7B0 );
    virtual int CheckIfSavegameExists( zSTRING const& )                          zCall( 0x0066AFD0 );
    virtual void CompileWorld()                                                  zCall( 0x0066CCD0 );
    virtual void WorldInit()                                                     zCall( 0x00663960 );
    virtual void NpcInit()                                                       zCall( 0x00664370 );
    virtual void NpcInit( zCTree<zCVob>* )                                       zCall( 0x006643A0 );
    virtual void SetAsPlayer( zSTRING const& )                                   zCall( 0x006670E0 );

    // static properties
    static int& s_bUseOldControls;
    static float& s_fUseSpeechReverb;
    static int& s_bUseOnlineHelp;
    static int& s_bUsePotionKeys;
    static int& s_bUseQuickSave;

    // user API
    #include "oCGame.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OGAME_H__VER2__