// Supported with union (c) 2018-2021 Union team

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

    void TNpcAIState_OnInit() zCall( 0x006C4720 );
    TNpcAIState()             zInit( TNpcAIState_OnInit() );
    ~TNpcAIState()            zCall( 0x006C4760 );

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