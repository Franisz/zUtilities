// Supported with union (c) 2018-2021 Union team

#ifndef __ONPC_STATES_H__VER2__
#define __ONPC_STATES_H__VER2__

namespace Gothic_II_Classic {
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

    void TNpcAIState_OnInit() zCall( 0x0070C570 );
    TNpcAIState()             zInit( TNpcAIState_OnInit() );
    ~TNpcAIState()            zCall( 0x0070C5B0 );

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

    void oCNpc_States_OnInit()                                         zCall( 0x0070C600 );
    oCNpc_States()                                                     zInit( oCNpc_States_OnInit() );
    ~oCNpc_States()                                                    zCall( 0x0070C8A0 );
    void ClearParserReferences()                                       zCall( 0x0070CA30 );
    void SetOwner( oCNpc* )                                            zCall( 0x0070CAB0 );
    int GetState()                                                     zCall( 0x0070CAC0 );
    int IsInState( int )                                               zCall( 0x0070CAE0 );
    int IsScriptStateActive()                                          zCall( 0x0070CB20 );
    int GetStateTime()                                                 zCall( 0x0070CB40 );
    void SetStateTime( int )                                           zCall( 0x0070CB70 );
    void SetRoutine( oCRtnEntry*, oCRtnEntry* )                        zCall( 0x0070CB90 );
    int StartRtnState( int )                                           zCall( 0x0070CD80 );
    int ActivateRtnState( int )                                        zCall( 0x0070CDD0 );
    int StartAIState( zSTRING const&, int, int, float, int )           zCall( 0x0070D1A0 );
    int StartAIState( int, int, int, float, int )                      zCall( 0x0070D2E0 );
    int CanPlayerUseAIState( TNpcAIState const& )                      zCall( 0x0070DA60 );
    int CanPlayerUseAIState()                                          zCall( 0x0070DAB0 );
    int DoAIState()                                                    zCall( 0x0070DC40 );
    void ClearAIState()                                                zCall( 0x0070E180 );
    void EndCurrentState()                                             zCall( 0x0070E320 );
    int IsInRoutine()                                                  zCall( 0x0070E340 );
    int IsInCutscene()                                                 zCall( 0x0070E370 );
    void StartOutputUnit( int )                                        zCall( 0x0070E390 );
    void StartCutscene( zSTRING const&, zSTRING const& )               zCall( 0x0070E3B0 );
    void CloseCutscenes()                                              zCall( 0x0070E480 );
    void SetParserInstanceNpc( int, oCNpc* )                           zCall( 0x0070E590 );
    void SetParserInstanceItem( oCItem* )                              zCall( 0x0070E650 );
    void InitRoutine()                                                 zCall( 0x0070E6B0 );
    void ChangeRoutine( zSTRING const& )                               zCall( 0x0070E7F0 );
    void ChangeRoutine( int )                                          zCall( 0x0070EA00 );
    zSTRING GetRoutineName()                                           zCall( 0x0070EC20 );
    void BeginInsertOverlayRoutine()                                   zCall( 0x0070ECF0 );
    void StopInsertOverlayRoutine()                                    zCall( 0x0070ED60 );
    void RemoveOverlayEntry( oCRtnEntry* )                             zCall( 0x0070EE90 );
    void RemoveOverlay()                                               zCall( 0x0070EF00 );
    void InsertRoutine( int, int, int, int, int, zSTRING const&, int ) zCall( 0x0070EF40 );
    void InsertRoutineCS( zSTRING const&, zSTRING const& )             zCall( 0x0070F0A0 );
    int GetLastRoutineState()                                          zCall( 0x0070F330 );
    int GetLastState()                                                 zCall( 0x0070F350 );
    int IsAIStateDriven()                                              zCall( 0x0070F360 );
    void InitAIStateDriven( zVEC3 const& )                             zCall( 0x0070F380 );
    zVEC3 const& GetAIStatePosition()                                  zCall( 0x0070F530 );
    zSTRING GetStateInfo()                                             zCall( 0x0070F540 );
    zSTRING GetLastError()                                             zCall( 0x0070F8D0 );
    virtual void Archive( zCArchiver& )                                zCall( 0x0070F910 );
    virtual void Unarchive( zCArchiver& )                              zCall( 0x0070FA90 );
    virtual void PackState( zCBuffer& )                                zCall( 0x0070FFC0 );
    virtual void UnpackState( zCBuffer& )                              zCall( 0x00710000 );

    // user API
    #include "oCNpc_States.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ONPC_STATES_H__VER2__