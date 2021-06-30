// Supported with union (c) 2018 Union team

#ifndef __ONPC_STATES_H__VER0__
#define __ONPC_STATES_H__VER0__

namespace Gothic_I_Classic {
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

    void TNpcAIState_OnInit() zCall( 0x006C4720 );
    TNpcAIState()             zInit( TNpcAIState_OnInit() );
    ~TNpcAIState()            zCall( 0x006C4760 );

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

    void oCNpc_States_OnInit()                                         zCall( 0x006C47B0 );
    oCNpc_States()                                                     zInit( oCNpc_States_OnInit() );
    ~oCNpc_States()                                                    zCall( 0x006C4A50 );
    void ClearParserReferences()                                       zCall( 0x006C4BE0 );
    void SetOwner( oCNpc* )                                            zCall( 0x006C4C60 );
    int GetState()                                                     zCall( 0x006C4C70 );
    int IsInState( int )                                               zCall( 0x006C4C90 );
    int IsScriptStateActive()                                          zCall( 0x006C4CD0 );
    int GetStateTime()                                                 zCall( 0x006C4CF0 );
    void SetStateTime( int )                                           zCall( 0x006C4D20 );
    void SetRoutine( oCRtnEntry*, oCRtnEntry* )                        zCall( 0x006C4D40 );
    int StartRtnState( int )                                           zCall( 0x006C4F30 );
    int ActivateRtnState( int )                                        zCall( 0x006C4F80 );
    int StartAIState( zSTRING const&, int, int, float, int )           zCall( 0x006C5350 );
    int StartAIState( int, int, int, float, int )                      zCall( 0x006C5490 );
    int CanPlayerUseAIState()                                          zCall( 0x006C5AD0 );
    int DoAIState()                                                    zCall( 0x006C5C60 );
    void ClearAIState()                                                zCall( 0x006C61A0 );
    void EndCurrentState()                                             zCall( 0x006C6340 );
    int IsInRoutine()                                                  zCall( 0x006C6360 );
    int IsInCutscene()                                                 zCall( 0x006C6390 );
    void StartOutputUnit( int )                                        zCall( 0x006C63B0 );
    void StartCutscene( zSTRING const&, zSTRING const& )               zCall( 0x006C63D0 );
    void CloseCutscenes()                                              zCall( 0x006C64A0 );
    void SetParserInstanceNpc( int, oCNpc* )                           zCall( 0x006C65B0 );
    void SetParserInstanceItem( oCItem* )                              zCall( 0x006C6670 );
    void InitRoutine()                                                 zCall( 0x006C66D0 );
    void ChangeRoutine( zSTRING const& )                               zCall( 0x006C6810 );
    void ChangeRoutine( int )                                          zCall( 0x006C69F0 );
    zSTRING GetRoutineName()                                           zCall( 0x006C6C10 );
    void BeginInsertOverlayRoutine()                                   zCall( 0x006C6CE0 );
    void StopInsertOverlayRoutine()                                    zCall( 0x006C6D20 );
    void RemoveOverlayEntry( oCRtnEntry* )                             zCall( 0x006C6E60 );
    void RemoveOverlay()                                               zCall( 0x006C6ED0 );
    void InsertRoutine( int, int, int, int, int, zSTRING const&, int ) zCall( 0x006C6F10 );
    void InsertRoutineCS( zSTRING const&, zSTRING const& )             zCall( 0x006C7060 );
    int GetLastRoutineState()                                          zCall( 0x006C7300 );
    int GetLastState()                                                 zCall( 0x006C7320 );
    int IsAIStateDriven()                                              zCall( 0x006C7330 );
    void InitAIStateDriven( zVEC3 const& )                             zCall( 0x006C7350 );
    zVEC3 const& GetAIStatePosition()                                  zCall( 0x006C7500 );
    zSTRING GetStateInfo()                                             zCall( 0x006C7510 );
    zSTRING GetLastError()                                             zCall( 0x006C77D0 );
    virtual void Archive( zCArchiver& )                                zCall( 0x006C7810 );
    virtual void Unarchive( zCArchiver& )                              zCall( 0x006C7990 );
    virtual void PackState( zCBuffer& )                                zCall( 0x006C7EC0 );
    virtual void UnpackState( zCBuffer& )                              zCall( 0x006C7F00 );

    // user API
    #include "oCNpc_States.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ONPC_STATES_H__VER0__