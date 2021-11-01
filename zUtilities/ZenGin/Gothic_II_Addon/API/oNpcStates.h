// Supported with union (c) 2018-2021 Union team

#ifndef __ONPC_STATES_H__VER3__
#define __ONPC_STATES_H__VER3__

namespace Gothic_II_Addon {
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

  // sizeof 3Ch
  struct TNpcAIState {
  public:
    int index;         // sizeof 04h    offset 00h
    int loop;          // sizeof 04h    offset 04h
    int end;           // sizeof 04h    offset 08h
    int timeBehaviour; // sizeof 04h    offset 0Ch
    float restTime;    // sizeof 04h    offset 10h
    int phase;         // sizeof 04h    offset 14h
    int valid;         // sizeof 04h    offset 18h
    zSTRING name;      // sizeof 14h    offset 1Ch
    float stateTime;   // sizeof 04h    offset 30h
    int prgIndex;      // sizeof 04h    offset 34h
    int isRtnState;    // sizeof 04h    offset 38h

    void TNpcAIState_OnInit() zCall( 0x0076BAD0 );
    TNpcAIState()             zInit( TNpcAIState_OnInit() );
    ~TNpcAIState()            zCall( 0x0076BB10 );

    // user API
    #include "TNpcAIState.inl"
  };

  // sizeof E0h
  class oCNpc_States {
  public:
    zSTRING name;           // sizeof 14h    offset 04h
    oCNpc* npc;             // sizeof 04h    offset 18h
    TNpcAIState curState;   // sizeof 3Ch    offset 1Ch
    TNpcAIState nextState;  // sizeof 3Ch    offset 58h
    int lastAIState;        // sizeof 04h    offset 94h
    int hasRoutine;         // sizeof 04h    offset 98h
    int rtnChanged;         // sizeof 04h    offset 9Ch
    oCRtnEntry* rtnBefore;  // sizeof 04h    offset A0h
    oCRtnEntry* rtnNow;     // sizeof 04h    offset A4h
    zCRoute* rtnRoute;      // sizeof 04h    offset A8h
    int rtnOverlay;         // sizeof 04h    offset ACh
    int rtnOverlayCount;    // sizeof 04h    offset B0h
    int walkmode_routine;   // sizeof 04h    offset B4h
    int weaponmode_routine; // sizeof 04h    offset B8h
    int startNewRoutine;    // sizeof 04h    offset BCh
    int aiStateDriven;      // sizeof 04h    offset C0h
    zVEC3 aiStatePosition;  // sizeof 0Ch    offset C4h
    oCNpc* parOther;        // sizeof 04h    offset D0h
    oCNpc* parVictim;       // sizeof 04h    offset D4h
    oCItem* parItem;        // sizeof 04h    offset D8h
    int rntChangeCount;     // sizeof 04h    offset DCh

    void oCNpc_States_OnInit()                                         zCall( 0x0076BB60 );
    oCNpc_States()                                                     zInit( oCNpc_States_OnInit() );
    ~oCNpc_States()                                                    zCall( 0x0076BE00 );
    void ClearParserReferences()                                       zCall( 0x0076BF90 );
    void SetOwner( oCNpc* )                                            zCall( 0x0076C010 );
    int GetState()                                                     zCall( 0x0076C020 );
    int IsInState( int )                                               zCall( 0x0076C040 );
    int IsScriptStateActive()                                          zCall( 0x0076C080 );
    int GetStateTime()                                                 zCall( 0x0076C0A0 );
    void SetStateTime( int )                                           zCall( 0x0076C0D0 );
    void SetRoutine( oCRtnEntry*, oCRtnEntry* )                        zCall( 0x0076C0F0 );
    int StartRtnState( int )                                           zCall( 0x0076C2E0 );
    int ActivateRtnState( int )                                        zCall( 0x0076C330 );
    int StartAIState( zSTRING const&, int, int, float, int )           zCall( 0x0076C700 );
    int StartAIState( int, int, int, float, int )                      zCall( 0x0076C840 );
    int CanPlayerUseAIState( TNpcAIState const& )                      zCall( 0x0076CFC0 );
    int CanPlayerUseAIState()                                          zCall( 0x0076D010 );
    int DoAIState()                                                    zCall( 0x0076D1A0 );
    void ClearAIState()                                                zCall( 0x0076D6E0 );
    void EndCurrentState()                                             zCall( 0x0076D880 );
    int IsInRoutine()                                                  zCall( 0x0076D8A0 );
    int IsInCutscene()                                                 zCall( 0x0076D8D0 );
    void StartOutputUnit( int )                                        zCall( 0x0076D8F0 );
    void StartCutscene( zSTRING const&, zSTRING const& )               zCall( 0x0076D910 );
    void CloseCutscenes()                                              zCall( 0x0076D9E0 );
    void SetParserInstanceNpc( int, oCNpc* )                           zCall( 0x0076DAF0 );
    void SetParserInstanceItem( oCItem* )                              zCall( 0x0076DBB0 );
    void InitRoutine()                                                 zCall( 0x0076DC10 );
    void ChangeRoutine( zSTRING const& )                               zCall( 0x0076DD50 );
    void ChangeRoutine( int )                                          zCall( 0x0076DF60 );
    zSTRING GetRoutineName()                                           zCall( 0x0076E180 );
    void BeginInsertOverlayRoutine()                                   zCall( 0x0076E250 );
    void StopInsertOverlayRoutine()                                    zCall( 0x0076E2C0 );
    void RemoveOverlayEntry( oCRtnEntry* )                             zCall( 0x0076E3F0 );
    void RemoveOverlay()                                               zCall( 0x0076E460 );
    void InsertRoutine( int, int, int, int, int, zSTRING const&, int ) zCall( 0x0076E4A0 );
    void InsertRoutineCS( zSTRING const&, zSTRING const& )             zCall( 0x0076E600 );
    int GetLastRoutineState()                                          zCall( 0x0076E890 );
    int GetLastState()                                                 zCall( 0x0076E8B0 );
    int IsAIStateDriven()                                              zCall( 0x0076E8C0 );
    void InitAIStateDriven( zVEC3 const& )                             zCall( 0x0076E8E0 );
    zVEC3 const& GetAIStatePosition()                                  zCall( 0x0076EA90 );
    zSTRING GetStateInfo()                                             zCall( 0x0076EAA0 );
    zSTRING GetLastError()                                             zCall( 0x0076EE30 );
    virtual void Archive( zCArchiver& )                                zCall( 0x0076EE70 );
    virtual void Unarchive( zCArchiver& )                              zCall( 0x0076EFF0 );
    virtual void PackState( zCBuffer& )                                zCall( 0x0076F530 );
    virtual void UnpackState( zCBuffer& )                              zCall( 0x0076F570 );

    // user API
    #include "oCNpc_States.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ONPC_STATES_H__VER3__