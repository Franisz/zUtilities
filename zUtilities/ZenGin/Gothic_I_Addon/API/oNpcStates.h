// Supported with union (c) 2018 Union team

#ifndef __ONPC_STATES_H__VER1__
#define __ONPC_STATES_H__VER1__

namespace Gothic_I_Addon {
  const int NPC_AISTATE_PRG_MAX = 7;

  enum {
    AITIME_NO,
    AITIME_ONCE,
    AITIME_TIMED
  };

  enum {
    NPC_AISTATE_ANSWER      = -2,
    NPC_AISTATE_DEAD        = -3,
    NPC_AISTATE_UNCONSCIOUS = -4,
    NPC_AISTATE_FADEAWAY    = -5,
    NPC_AISTATE_FOLLOW      = -6
  };

  struct TNpcAIState {
  public:
    int index;
    int loop;
    int end;
    int timeBehaviour;
    float restTime;
    int phase;
    int valid;
    zSTRING name;
    float stateTime;
    int prgIndex;
    int isRtnState;

    void TNpcAIState_OnInit() zCall( 0x006F9E20 );
    TNpcAIState()             zInit( TNpcAIState_OnInit() );
    ~TNpcAIState()            zCall( 0x006F9E60 );

    // user API
    #include "TNpcAIState.inl"
  };

  class oCNpc_States {
  public:
    zSTRING name;
    oCNpc* npc;
    TNpcAIState curState;
    TNpcAIState nextState;
    int lastAIState;
    int hasRoutine;
    int rtnChanged;
    oCRtnEntry* rtnBefore;
    oCRtnEntry* rtnNow;
    zCRoute* rtnRoute;
    int rtnOverlay;
    int rtnOverlayCount;
    int walkmode_routine;
    int weaponmode_routine;
    int startNewRoutine;
    int aiStateDriven;
    zVEC3 aiStatePosition;
    oCNpc* parOther;
    oCNpc* parVictim;
    oCItem* parItem;
    int rntChangeCount;

    void oCNpc_States_OnInit()                                         zCall( 0x006F9EB0 );
    oCNpc_States()                                                     zInit( oCNpc_States_OnInit() );
    ~oCNpc_States()                                                    zCall( 0x006FA160 );
    void ClearParserReferences()                                       zCall( 0x006FA310 );
    void SetOwner( oCNpc* )                                            zCall( 0x006FA390 );
    int GetState()                                                     zCall( 0x006FA3A0 );
    int IsInState( int )                                               zCall( 0x006FA3C0 );
    int IsScriptStateActive()                                          zCall( 0x006FA400 );
    int GetStateTime()                                                 zCall( 0x006FA420 );
    void SetStateTime( int )                                           zCall( 0x006FA450 );
    void SetRoutine( oCRtnEntry*, oCRtnEntry* )                        zCall( 0x006FA470 );
    int StartRtnState( int )                                           zCall( 0x006FA690 );
    int ActivateRtnState( int )                                        zCall( 0x006FA6E0 );
    int StartAIState( zSTRING const&, int, int, float, int )           zCall( 0x006FAAD0 );
    int StartAIState( int, int, int, float, int )                      zCall( 0x006FAC30 );
    int CanPlayerUseAIState()                                          zCall( 0x006FB400 );
    int DoAIState()                                                    zCall( 0x006FB5B0 );
    void ClearAIState()                                                zCall( 0x006FBB00 );
    void EndCurrentState()                                             zCall( 0x006FBCA0 );
    int IsInRoutine()                                                  zCall( 0x006FBCC0 );
    int IsInCutscene()                                                 zCall( 0x006FBCF0 );
    void StartOutputUnit( int )                                        zCall( 0x006FBD10 );
    void StartCutscene( zSTRING const&, zSTRING const& )               zCall( 0x006FBD30 );
    void CloseCutscenes()                                              zCall( 0x006FBE10 );
    void SetParserInstanceNpc( int, oCNpc* )                           zCall( 0x006FBF30 );
    void SetParserInstanceItem( oCItem* )                              zCall( 0x006FC000 );
    void InitRoutine()                                                 zCall( 0x006FC070 );
    void ChangeRoutine( zSTRING const& )                               zCall( 0x006FC1C0 );
    void ChangeRoutine( int )                                          zCall( 0x006FC3D0 );
    zSTRING GetRoutineName()                                           zCall( 0x006FC620 );
    void BeginInsertOverlayRoutine()                                   zCall( 0x006FC6F0 );
    void StopInsertOverlayRoutine()                                    zCall( 0x006FC760 );
    void RemoveOverlayEntry( oCRtnEntry* )                             zCall( 0x006FC8B0 );
    void RemoveOverlay()                                               zCall( 0x006FC960 );
    void InsertRoutine( int, int, int, int, int, zSTRING const&, int ) zCall( 0x006FC9A0 );
    void InsertRoutineCS( zSTRING const&, zSTRING const& )             zCall( 0x006FCAF0 );
    int GetLastRoutineState()                                          zCall( 0x006FCD90 );
    int GetLastState()                                                 zCall( 0x006FCDB0 );
    int IsAIStateDriven()                                              zCall( 0x006FCDC0 );
    void InitAIStateDriven( zVEC3 const& )                             zCall( 0x006FCDE0 );
    zVEC3 const& GetAIStatePosition()                                  zCall( 0x006FCF90 );
    zSTRING GetStateInfo()                                             zCall( 0x006FCFA0 );
    zSTRING GetLastError()                                             zCall( 0x006FD2F0 );
    virtual void Archive( zCArchiver& )                                zCall( 0x006FD340 );
    virtual void Unarchive( zCArchiver& )                              zCall( 0x006FD4C0 );
    virtual void PackState( zCBuffer& )                                zCall( 0x006FDA70 );
    virtual void UnpackState( zCBuffer& )                              zCall( 0x006FDAB0 );

    // user API
    #include "oCNpc_States.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ONPC_STATES_H__VER1__