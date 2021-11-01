// Supported with union (c) 2018-2021 Union team

#ifndef __ZVOB_MISC_H__VER2__
#define __ZVOB_MISC_H__VER2__

namespace Gothic_II_Classic {
  const int MAX_TARGETS = 6;
  const int MAX_SLAVES  = 6;

  // sizeof 2Ch
  class zCEventCommon : public zCEventMessage {
  public:
    zCLASS_DECLARATION( zCEventCommon )

    enum zTEventCommonSubType {
      zEVENT_ENABLE,
      zEVENT_DISABLE,
      zEVENT_TOGGLE_ENABLED,
      zEVENT_RESET,
      zEVENT_MISC_NUM_SUBTYPES
    };

    zCEventCommon() {}
    static zCObject* _CreateNewInstance()      zCall( 0x006078B0 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x00607A00 );
    virtual ~zCEventCommon()                   zCall( 0x00607A60 );
    virtual int IsNetRelevant()                zCall( 0x00607A20 );
    virtual int MD_GetNumOfSubTypes()          zCall( 0x00607A10 );
    virtual zSTRING MD_GetSubTypeString( int ) zCall( 0x00608120 );

    // user API
    #include "zCEventCommon.inl"
  };

  // sizeof 134h
  class zCTriggerBase : public zCVob {
  public:
    zCLASS_DECLARATION( zCTriggerBase )

    zSTRING triggerTarget; // sizeof 14h    offset 120h

    void zCTriggerBase_OnInit()                          zCall( 0x00608430 );
    zCTriggerBase()                                      zInit( zCTriggerBase_OnInit() );
    virtual zCClassDef* _GetClassDef() const             zCall( 0x00604210 );
    virtual void Archive( zCArchiver& )                  zCall( 0x00608780 );
    virtual void Unarchive( zCArchiver& )                zCall( 0x006087B0 );
    virtual ~zCTriggerBase()                             zCall( 0x00604A50 );
    virtual void OnTrigger( zCVob*, zCVob* )             zCall( 0x00608640 );
    virtual void OnUntrigger( zCVob*, zCVob* )           zCall( 0x006086E0 );
    virtual void OnTouch( zCVob* )                       zCall( 0x00608500 );
    virtual void OnUntouch( zCVob* )                     zCall( 0x006085A0 );
    virtual zSTRING const* GetTriggerTarget( int ) const zCall( 0x004042F0 );

    // user API
    #include "zCTriggerBase.inl"
  };

  // sizeof 168h
  class zCTrigger : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCTrigger )

    // sizeof 01h
    struct zCTriggerDummy0 {
      unsigned char reactToOnTrigger : 1; // sizeof 01h    offset bit
      unsigned char reactToOnTouch   : 1; // sizeof 01h    offset bit
      unsigned char reactToOnDamage  : 1; // sizeof 01h    offset bit
      unsigned char respondToObject  : 1; // sizeof 01h    offset bit
      unsigned char respondToPC      : 1; // sizeof 01h    offset bit
      unsigned char respondToNPC     : 1; // sizeof 01h    offset bit
    };

    zCTriggerDummy0 filterFlags; // sizeof 01h    offset 134h
    zSTRING respondToVobName;    // sizeof 14h    offset 138h
    short numCanBeActivated;     // sizeof 02h    offset 14Ch
    float retriggerWaitSec;      // sizeof 04h    offset 150h
    float damageThreshold;       // sizeof 04h    offset 154h
    float fireDelaySec;          // sizeof 04h    offset 158h
    float nextTimeTriggerable;   // sizeof 04h    offset 15Ch
    zCVob* savedOtherVob;        // sizeof 04h    offset 160h
    short countCanBeActivated;   // sizeof 02h    offset 164h

    void zCTrigger_OnInit()                                           zCall( 0x006087E0 );
    zSTRING GetTriggerTarget() const                                  zCall( 0x004049A0 );
    zCTrigger()                                                       zInit( zCTrigger_OnInit() );
    void ClearStateInternals()                                        zCall( 0x00608A10 );
    void TriggerTargetPost()                                          zCall( 0x00608DE0 );
    void ActivateTrigger( zCVob* )                                    zCall( 0x00608E10 );
    void DeactivateTrigger( zCVob* )                                  zCall( 0x00608EF0 );
    static zCObject* _CreateNewInstance()                             zCall( 0x00605320 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x006089D0 );
    virtual void Archive( zCArchiver& )                               zCall( 0x00609120 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x006093A0 );
    virtual ~zCTrigger()                                              zCall( 0x00608A60 );
    virtual void OnTrigger( zCVob*, zCVob* )                          zCall( 0x00608F20 );
    virtual void OnUntrigger( zCVob*, zCVob* )                        zCall( 0x00608F40 );
    virtual void OnTouch( zCVob* )                                    zCall( 0x00608F80 );
    virtual void OnUntouch( zCVob* )                                  zCall( 0x00608FA0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& ) zCall( 0x00608FE0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                 zCall( 0x00609020 );
    virtual void OnTimer()                                            zCall( 0x00609090 );
    virtual void TriggerTarget( zCVob* )                              zCall( 0x00608C80 );
    virtual void UntriggerTarget( zCVob* )                            zCall( 0x00608D30 );
    virtual int CanBeActivatedNow( zCVob* )                           zCall( 0x00608B60 );

    // user API
    #include "zCTrigger.inl"
  };

  // sizeof 30h
  class zCEventMover : public zCEventMessage {
  public:
    zCLASS_DECLARATION( zCEventMover )

    enum zTEventMoverSubType {
      zEVENT_GOTO_KEY_FIXED_DIRECTLY,
      zEVENT_GOTO_KEY_FIXED_ORDER,
      zEVENT_GOTO_KEY_NEXT,
      zEVENT_GOTO_KEY_PREV,
      zEVENT_MISC_NUM_SUBTYPES
    };

    int gotoFixedKeyframe; // sizeof 04h    offset 2Ch

    zCEventMover() {}
    static zCObject* _CreateNewInstance()      zCall( 0x00607C50 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x00607DA0 );
    virtual ~zCEventMover()                    zCall( 0x00607E00 );
    virtual int IsNetRelevant()                zCall( 0x00607DC0 );
    virtual int MD_GetNumOfSubTypes()          zCall( 0x00607DB0 );
    virtual zSTRING MD_GetSubTypeString( int ) zCall( 0x00608280 );

    // user API
    #include "zCEventMover.inl"
  };

  // sizeof 270h
  class zCMover : public zCTrigger {
  public:
    zCLASS_DECLARATION( zCMover )

    enum zTMoverState {
      MOVER_STATE_OPEN,
      MOVER_STATE_OPENING,
      MOVER_STATE_CLOSED,
      MOVER_STATE_CLOSING
    };

    enum zTMoverAniType {
      MA_KEYFRAME,
      MA_MODEL_ANI,
      MA_WAYPOINT
    };

    enum zTMoverBehavior {
      MB_2STATE_TOGGLE,
      MB_2STATE_TRIGGER_CONTROL,
      MB_2STATE_OPEN_TIMED,
      MB_NSTATE_LOOP,
      MB_NSTATE_SINGLE_KEYS
    };

    enum zTTouchBehavior {
      TB_TOGGLE,
      TB_WAIT
    };

    enum zTPosLerpType {
      PL_LINEAR,
      PL_CURVE
    };

    enum zTSpeedType {
      ST_CONST,
      ST_SLOW_START_END,
      ST_SLOW_START,
      ST_SLOW_END,
      ST_SEG_SLOW_START_END,
      ST_SEG_SLOW_START,
      ST_SEG_SLOW_END
    };

    // sizeof 1Ch
    struct zTMov_Keyframe {
      zVEC3 pos;   // sizeof 0Ch    offset 00h
      zCQuat quat; // sizeof 10h    offset 0Ch

      zTMov_Keyframe() {}

      // user API
      #include "zCMover_zTMov_Keyframe.inl"
    };

    zCArray<zTMov_Keyframe> keyframeList; // sizeof 0Ch    offset 168h
    zVEC3 actKeyPosDelta;                 // sizeof 0Ch    offset 174h
    float actKeyframeF;                   // sizeof 04h    offset 180h
    int actKeyframe;                      // sizeof 04h    offset 184h
    int nextKeyframe;                     // sizeof 04h    offset 188h
    float moveSpeedUnit;                  // sizeof 04h    offset 18Ch
    float advanceDir;                     // sizeof 04h    offset 190h
    zTMoverState moverState;              // sizeof 04h    offset 194h
    int numTriggerEvents;                 // sizeof 04h    offset 198h
    float stayOpenTimeDest;               // sizeof 04h    offset 19Ch
    zCModel* model;                       // sizeof 04h    offset 1A0h
    int soundMovingHandle;                // sizeof 04h    offset 1A4h
    zCSoundFX* sfxMoving;                 // sizeof 04h    offset 1A8h
    float moveSpeed;                      // sizeof 04h    offset 1ACh
    float stayOpenTimeSec;                // sizeof 04h    offset 1B0h
    float touchBlockerDamage;             // sizeof 04h    offset 1B4h
    char moverLocked;                     // sizeof 01h    offset 1B8h
    char autoLinkEnabled;                 // sizeof 01h    offset 1B9h
    char autoRotate;                      // sizeof 01h    offset 1BAh
    zTMoverAniType moverAniType;          // sizeof 04h    offset 1BCh
    zTMoverBehavior moverBehavior;        // sizeof 04h    offset 1C0h
    zTTouchBehavior touchBehavior;        // sizeof 04h    offset 1C4h
    zTPosLerpType posLerpType;            // sizeof 04h    offset 1C8h
    zTSpeedType speedType;                // sizeof 04h    offset 1CCh
    zSTRING soundOpenStart;               // sizeof 14h    offset 1D0h
    zSTRING soundOpenEnd;                 // sizeof 14h    offset 1E4h
    zSTRING soundMoving;                  // sizeof 14h    offset 1F8h
    zSTRING soundCloseStart;              // sizeof 14h    offset 20Ch
    zSTRING soundCloseEnd;                // sizeof 14h    offset 220h
    zSTRING soundLock;                    // sizeof 14h    offset 234h
    zSTRING soundUnlock;                  // sizeof 14h    offset 248h
    zSTRING soundUseLocked;               // sizeof 14h    offset 25Ch

    void zCMover_OnInit()                                             zCall( 0x00609660 );
    zCMover()                                                         zInit( zCMover_OnInit() );
    void ClearStateInternals()                                        zCall( 0x00609880 );
    void UpdateInternals()                                            zCall( 0x00609BB0 );
    void AdvanceKeyframe_KF()                                         zCall( 0x00609D10 );
    void SetToKeyframe_KF( float )                                    zCall( 0x00609D40 );
    void InterpolateKeyframes_KF()                                    zCall( 0x0060A240 );
    void AdvanceMover()                                               zCall( 0x0060A6D0 );
    void SetToKeyframe( float, float )                                zCall( 0x0060A9D0 );
    void InvertMovement()                                             zCall( 0x0060AC40 );
    void StartMovingSound()                                           zCall( 0x0060AEA0 );
    void MoveToKeyframe( int )                                        zCall( 0x0060AF10 );
    void DoOpen()                                                     zCall( 0x0060AF80 );
    void FinishedOpening()                                            zCall( 0x0060B030 );
    void DoClose()                                                    zCall( 0x0060B0B0 );
    void FinishedClosing()                                            zCall( 0x0060B170 );
    void Unlock( zCVob* )                                             zCall( 0x0060B1C0 );
    void Lock( zCVob* )                                               zCall( 0x0060B390 );
    int IsKeyToThisMover( zCVob* )                                    zCall( 0x0060B560 );
    void TriggerMover( zCVob* )                                       zCall( 0x0060B5F0 );
    static zCObject* _CreateNewInstance()                             zCall( 0x006059C0 );
    static zTMov_Keyframe GetKeyframe( zCVob* )                       zCall( 0x00609C30 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x00609840 );
    virtual void Archive( zCArchiver& )                               zCall( 0x0060C120 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x0060C3E0 );
    virtual ~zCMover()                                                zCall( 0x00609940 );
    virtual void OnTrigger( zCVob*, zCVob* )                          zCall( 0x0060B9C0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                        zCall( 0x0060BAB0 );
    virtual void OnTouch( zCVob* )                                    zCall( 0x0060BC80 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& ) zCall( 0x0060BD40 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                 zCall( 0x0060BD90 );
    virtual void OnTick()                                             zCall( 0x0060B8C0 );
    virtual void PostLoad()                                           zCall( 0x0060C110 );
    virtual int CanThisCollideWith( zCVob* )                          zCall( 0x00609B30 );
    virtual void SetVisual( zCVisual* )                               zCall( 0x0060ACE0 );

    // user API
    #include "zCMover.inl"
  };

  // sizeof 180h
  class zCTriggerTeleport : public zCTrigger {
  public:
    zCLASS_DECLARATION( zCTriggerTeleport )

    zSTRING teleportSoundName; // sizeof 14h    offset 168h
    zCSoundFX* teleportSound;  // sizeof 04h    offset 17Ch

    void zCTriggerTeleport_OnInit()            zCall( 0x0060CA60 );
    zCTriggerTeleport()                        zInit( zCTriggerTeleport_OnInit() );
    void DoTeleport( zCVob* )                  zCall( 0x0060CD80 );
    static zCObject* _CreateNewInstance()      zCall( 0x00605C30 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x00605DB0 );
    virtual void Archive( zCArchiver& )        zCall( 0x0060D000 );
    virtual void Unarchive( zCArchiver& )      zCall( 0x0060D030 );
    virtual ~zCTriggerTeleport()               zCall( 0x0060CC10 );
    virtual void OnTrigger( zCVob*, zCVob* )   zCall( 0x0060CFE0 );
    virtual void OnUntrigger( zCVob*, zCVob* ) zCall( 0x0060CFF0 );
    virtual void OnTouch( zCVob* )             zCall( 0x0060CFD0 );

    // user API
    #include "zCTriggerTeleport.inl"
  };

  // sizeof 204h
  class zCTriggerList : public zCTrigger {
  public:
    zCLASS_DECLARATION( zCTriggerList )

    enum zTListProcess {
      LP_ALL,
      LP_NEXT_ONE,
      LP_RAND_ONE
    };

    zSTRING triggerTargetList[MAX_TARGETS]; // sizeof 78h    offset 168h
    float fireDelayList[MAX_TARGETS];       // sizeof 18h    offset 1E0h
    zTListProcess listProcess;              // sizeof 04h    offset 1F8h
    int actTarget;                          // sizeof 04h    offset 1FCh
    int sendOnTrigger;                      // sizeof 04h    offset 200h

    void zCTriggerList_OnInit()                          zCall( 0x0060D490 );
    zCTriggerList()                                      zInit( zCTriggerList_OnInit() );
    void Init()                                          zCall( 0x0060D740 );
    void TriggerActTarget( zCVob* )                      zCall( 0x0060D870 );
    int ProcessActTarget( zCVob* )                       zCall( 0x0060D940 );
    void FinishActivation()                              zCall( 0x0060D9D0 );
    void DoTriggering( zCVob* )                          zCall( 0x0060DAD0 );
    static zCObject* _CreateNewInstance()                zCall( 0x00605590 );
    virtual zCClassDef* _GetClassDef() const             zCall( 0x006057C0 );
    virtual void Archive( zCArchiver& )                  zCall( 0x0060DDD0 );
    virtual void Unarchive( zCArchiver& )                zCall( 0x0060E0B0 );
    virtual ~zCTriggerList()                             zCall( 0x0060D630 );
    virtual void OnTimer()                               zCall( 0x0060DA40 );
    virtual zSTRING const* GetTriggerTarget( int ) const zCall( 0x0060D850 );
    virtual void TriggerTarget( zCVob* )                 zCall( 0x0060DDA0 );
    virtual void UntriggerTarget( zCVob* )               zCall( 0x0060DDB0 );

    // user API
    #include "zCTriggerList.inl"
  };

  // sizeof 120h
  class zCEffect : public zCVob {
  public:
    zCLASS_DECLARATION( zCEffect )

    zCEffect() {}
    virtual zCClassDef* _GetClassDef() const zCall( 0x00488780 );
    virtual ~zCEffect()                      zCall( 0x00488A40 );

    // user API
    #include "zCEffect.inl"
  };

  // sizeof 134h
  class zCEarthquake : public zCEffect {
  public:
    zCLASS_DECLARATION( zCEarthquake )

    float radiusSquare; // sizeof 04h    offset 120h
    float timeMSec;     // sizeof 04h    offset 124h
    zVEC3 amplitude;    // sizeof 0Ch    offset 128h

    void zCEarthquake_OnInit()                 zCall( 0x0060C7E0 );
    zCEarthquake()                             zInit( zCEarthquake_OnInit() );
    static zCObject* _CreateNewInstance()      zCall( 0x00606190 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x00606260 );
    virtual void Archive( zCArchiver& )        zCall( 0x0060C970 );
    virtual void Unarchive( zCArchiver& )      zCall( 0x0060C9F0 );
    virtual ~zCEarthquake()                    zCall( 0x0060C8C0 );
    virtual void OnTrigger( zCVob*, zCVob* )   zCall( 0x0060C8D0 );
    virtual void OnUntrigger( zCVob*, zCVob* ) zCall( 0x0060C920 );

    // user API
    #include "zCEarthquake.inl"
  };

  // sizeof 138h
  class zCPFXControler : public zCEffect {
  public:
    zCLASS_DECLARATION( zCPFXControler )

    zSTRING pfxName;                     // sizeof 14h    offset 120h
    group {
      unsigned char killVobWhenDone : 1; // sizeof 01h    offset bit
      unsigned char pfxStartOn      : 1; // sizeof 01h    offset bit
    };

    void zCPFXControler_OnInit()               zCall( 0x0060D0A0 );
    zCPFXControler()                           zInit( zCPFXControler_OnInit() );
    zCParticleFX* GetPFX()                     zCall( 0x0060D180 );
    static zCObject* _CreateNewInstance()      zCall( 0x00606460 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x00606530 );
    virtual void Archive( zCArchiver& )        zCall( 0x0060D2D0 );
    virtual void Unarchive( zCArchiver& )      zCall( 0x0060D330 );
    virtual ~zCPFXControler()                  zCall( 0x0060D120 );
    virtual void OnTrigger( zCVob*, zCVob* )   zCall( 0x0060D210 );
    virtual void OnUntrigger( zCVob*, zCVob* ) zCall( 0x0060D2A0 );
    virtual void PostLoad()                    zCall( 0x0060D1F0 );

    // user API
    #include "zCPFXControler.inl"
  };

  // sizeof 134h
  class zCTouchDamage : public zCEffect {
  public:
    zCLASS_DECLARATION( zCTouchDamage )

    enum zTDamageCollType {
      CT_NONE,
      CT_BOX,
      CT_POINT
    };

    float damage;                    // sizeof 04h    offset 120h
    int damageType;                  // sizeof 04h    offset 124h
    float damageRepeatDelaySec;      // sizeof 04h    offset 128h
    float damageVolDownScale;        // sizeof 04h    offset 12Ch
    zTDamageCollType damageCollType; // sizeof 04h    offset 130h

    void zCTouchDamage_OnInit()                               zCall( 0x0060E3C0 );
    zCTouchDamage()                                           zInit( zCTouchDamage_OnInit() );
    void ProcessToucher( zCVob* )                             zCall( 0x0060E6B0 );
    int TestCollType( zCVob* )                                zCall( 0x0060E750 );
    void FireDamageMessage( zCVob* )                          zCall( 0x0060E9B0 );
    void SetVobProperties()                                   zCall( 0x0060EC40 );
    static zCObject* _CreateNewInstance()                     zCall( 0x00606730 );
    virtual zCClassDef* _GetClassDef() const                  zCall( 0x00606830 );
    virtual void Archive( zCArchiver& )                       zCall( 0x0060EA40 );
    virtual void Unarchive( zCArchiver& )                     zCall( 0x0060EB10 );
    virtual ~zCTouchDamage()                                  zCall( 0x0060E4A0 );
    virtual void OnTouch( zCVob* )                            zCall( 0x0060E4B0 );
    virtual void OnUntouch( zCVob* )                          zCall( 0x0060E590 );
    virtual void OnTimer()                                    zCall( 0x0060E5B0 );
    virtual void SetVisual( zCVisual* )                       zCall( 0x0060EBF0 );
    virtual char const* GetDamageTypeArcEnum( unsigned long ) zCall( 0x0060EBD0 );

    // user API
    #include "zCTouchDamage.inl"
  };

  // sizeof 120h
  class zCVobStair : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobStair )

    zCVobStair() {}
    static zCObject* _CreateNewInstance()    zCall( 0x00603C90 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00603D10 );
    virtual ~zCVobStair()                    zCall( 0x00603D50 );

    // user API
    #include "zCVobStair.inl"
  };

  // sizeof 138h
  class zCTouchAnimate : public zCEffect {
  public:
    zCLASS_DECLARATION( zCTouchAnimate )

    zSTRING touchSoundName; // sizeof 14h    offset 120h
    zCSoundFX* touchSound;  // sizeof 04h    offset 134h

    void zCTouchAnimate_OnInit()             zCall( 0x0060EC80 );
    zCTouchAnimate()                         zInit( zCTouchAnimate_OnInit() );
    int IsTouching( zCVob* )                 zCall( 0x0060F130 );
    void StartAni()                          zCall( 0x0060F200 );
    void StopAni()                           zCall( 0x0060F470 );
    int IsAniActive()                        zCall( 0x0060F4B0 );
    void SetVobProperties()                  zCall( 0x0060F5C0 );
    static zCObject* _CreateNewInstance()    zCall( 0x00606A30 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00606B30 );
    virtual void Archive( zCArchiver& )      zCall( 0x0060F4F0 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x0060F500 );
    virtual ~zCTouchAnimate()                zCall( 0x0060ED60 );
    virtual void OnTouch( zCVob* )           zCall( 0x0060EE20 );
    virtual void OnUntouch( zCVob* )         zCall( 0x0060EF40 );
    virtual void OnTick()                    zCall( 0x0060EF60 );
    virtual void SetVisual( zCVisual* )      zCall( 0x0060F570 );
    virtual zSTRING GetSoundName()           zCall( 0x0060F360 );

    // user API
    #include "zCTouchAnimate.inl"
  };

  // sizeof 14Ch
  class zCTouchAnimateSound : public zCTouchAnimate {
  public:
    zCLASS_DECLARATION( zCTouchAnimateSound )

    zSTRING touchSoundName; // sizeof 14h    offset 138h

    void zCTouchAnimateSound_OnInit()        zCall( 0x0060F600 );
    zCTouchAnimateSound()                    zInit( zCTouchAnimateSound_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x00606D30 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00606EE0 );
    virtual void Archive( zCArchiver& )      zCall( 0x0060F8A0 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x0060F8D0 );
    virtual ~zCTouchAnimateSound()           zCall( 0x0060F7A0 );
    virtual zSTRING GetSoundName()           zCall( 0x0060F960 );

    // user API
    #include "zCTouchAnimateSound.inl"
  };

  // sizeof 124h
  class zCVobAnimate : public zCEffect {
  public:
    zCLASS_DECLARATION( zCVobAnimate )

    char startOn;   // sizeof 01h    offset 120h
    char isRunning; // sizeof 01h    offset 121h

    void zCVobAnimate_OnInit()                 zCall( 0x0060F9B0 );
    zCVobAnimate()                             zInit( zCVobAnimate_OnInit() );
    void StartAni()                            zCall( 0x0060FAE0 );
    void StopAni()                             zCall( 0x0060FB20 );
    static zCObject* _CreateNewInstance()      zCall( 0x006070E0 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x006071A0 );
    virtual void Archive( zCArchiver& )        zCall( 0x0060FB90 );
    virtual void Unarchive( zCArchiver& )      zCall( 0x0060FBE0 );
    virtual ~zCVobAnimate()                    zCall( 0x0060FA60 );
    virtual void OnTrigger( zCVob*, zCVob* )   zCall( 0x0060FB30 );
    virtual void OnUntrigger( zCVob*, zCVob* ) zCall( 0x0060FB80 );
    virtual void SetVisual( zCVisual* )        zCall( 0x0060FA70 );

    // user API
    #include "zCVobAnimate.inl"
  };

  // sizeof 124h
  class zCVobLensFlare : public zCEffect {
  public:
    zCLASS_DECLARATION( zCVobLensFlare )

    zCLensFlareFX* lensFlareFX; // sizeof 04h    offset 120h

    void zCVobLensFlare_OnInit()                      zCall( 0x0060FC90 );
    zCVobLensFlare()                                  zInit( zCVobLensFlare_OnInit() );
    void SetLensFlareFXByName( zSTRING const& )       zCall( 0x0060FD70 );
    static zCObject* _CreateNewInstance()             zCall( 0x006073A0 );
    virtual zCClassDef* _GetClassDef() const          zCall( 0x00607470 );
    virtual void Archive( zCArchiver& )               zCall( 0x0060FDC0 );
    virtual void Unarchive( zCArchiver& )             zCall( 0x0060FEB0 );
    virtual ~zCVobLensFlare()                         zCall( 0x0060FD30 );
    virtual int __fastcall Render( zTRenderContext& ) zCall( 0x0060FD50 );

    // user API
    #include "zCVobLensFlare.inl"
  };

  // sizeof 38h
  class zCEventScreenFX : public zCEventMessage {
  public:
    zCLASS_DECLARATION( zCEventScreenFX )

    enum zTEventScreenFXSubType {
      zEVENT_BLEND_FADEIN,
      zEVENT_BLEND_FADEOUT,
      zEVENT_CINEMA_FADEIN,
      zEVENT_CINEMA_FADEOUT,
      zEVENT_FOV_MORPH,
      zEVENT_SCREENFX_COUNT
    };

    float duration; // sizeof 04h    offset 2Ch
    zCOLOR color;   // sizeof 04h    offset 30h
    float fovDeg;   // sizeof 04h    offset 34h

    zCEventScreenFX() {}
    void zCEventScreenFX_OnInit( zTEventScreenFXSubType, float, zCOLOR, float ) zCall( 0x0060FF90 );
    zCEventScreenFX( zTEventScreenFXSubType a0, float a1, zCOLOR a2, float a3 ) zInit( zCEventScreenFX_OnInit( a0, a1, a2, a3 ));
    void Clear()                                                                zCall( 0x00610030 );
    static zCObject* _CreateNewInstance()                                       zCall( 0x00607FF0 );
    virtual zCClassDef* _GetClassDef() const                                    zCall( 0x006080C0 );
    virtual void Archive( zCArchiver& )                                         zCall( 0x00610300 );
    virtual void Unarchive( zCArchiver& )                                       zCall( 0x00610350 );
    virtual ~zCEventScreenFX()                                                  zCall( 0x00608110 );
    virtual int MD_GetNumOfSubTypes()                                           zCall( 0x006080D0 );
    virtual zSTRING MD_GetSubTypeString( int )                                  zCall( 0x00610060 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()                 zCall( 0x00610250 );
    virtual float MD_GetMinTime()                                               zCall( 0x00610270 );
    virtual void Pack( zCBuffer&, zCEventManager* )                             zCall( 0x00610280 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                           zCall( 0x006102C0 );

    // user API
    #include "zCEventScreenFX.inl"
  };

  // sizeof 1C0h
  class zCVobScreenFX : public zCEffect {
  public:
    zCLASS_DECLARATION( zCVobScreenFX )

    // sizeof 30h
    struct zTScreenFXSet {
      float weight;                   // sizeof 04h    offset 00h
      float velo;                     // sizeof 04h    offset 04h
      zCOLOR color;                   // sizeof 04h    offset 08h
      float fovDeg;                   // sizeof 04h    offset 0Ch
      int visible;                    // sizeof 04h    offset 10h
      zSTRING texName;                // sizeof 14h    offset 14h
      float texAniFPS;                // sizeof 04h    offset 28h
      zTRnd_AlphaBlendFunc blendFunc; // sizeof 04h    offset 2Ch

      zTScreenFXSet() {}
      ~zTScreenFXSet() zCall( 0x00610570 );

      // user API
      #include "zCVobScreenFX_zTScreenFXSet.inl"
    };

    zTScreenFXSet blend;    // sizeof 30h    offset 120h
    zTScreenFXSet cinema;   // sizeof 30h    offset 150h
    zTScreenFXSet fovMorph; // sizeof 30h    offset 180h
    zVEC2 fovSaved;         // sizeof 08h    offset 1B0h
    zVEC2 fovSavedFirst;    // sizeof 08h    offset 1B8h

    void zCVobScreenFX_OnInit()                            zCall( 0x006103A0 );
    zCVobScreenFX()                                        zInit( zCVobScreenFX_OnInit() );
    void StartEffect( float, zCOLOR, int, zTScreenFXSet& ) zCall( 0x00610890 );
    zCOLOR CalcEffectColor( zTScreenFXSet& )               zCall( 0x00610920 );
    static zCObject* _CreateNewInstance()                  zCall( 0x00607670 );
    virtual zCClassDef* _GetClassDef() const               zCall( 0x00610530 );
    virtual void Archive( zCArchiver& )                    zCall( 0x00610CF0 );
    virtual void Unarchive( zCArchiver& )                  zCall( 0x00610D80 );
    virtual ~zCVobScreenFX()                               zCall( 0x006105C0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )      zCall( 0x006106A0 );
    virtual void OnTick()                                  zCall( 0x006109B0 );

    // user API
    #include "zCVobScreenFX.inl"
  };

  // sizeof 138h
  class zCMessageFilter : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCMessageFilter )

    enum zTMessageType {
      MT_NONE,
      MT_TRIGGER,
      MT_UNTRIGGER,
      MT_ENABLE,
      MT_DISABLE,
      MT_TOGGLE_ENABLED,
      MT_RESET
    };

    group {
      unsigned char sendWhenTriggered   : 4; // sizeof 04h    offset bit
      unsigned char sendWhenUntriggered : 4; // sizeof 04h    offset bit
    };

    void zCMessageFilter_OnInit()                zCall( 0x00610E20 );
    zCMessageFilter()                            zInit( zCMessageFilter_OnInit() );
    void ProcessMessage( zTMessageType, zCVob* ) zCall( 0x00610F60 );
    static zCObject* _CreateNewInstance()        zCall( 0x00604500 );
    virtual zCClassDef* _GetClassDef() const     zCall( 0x00604600 );
    virtual void Archive( zCArchiver& )          zCall( 0x006112B0 );
    virtual void Unarchive( zCArchiver& )        zCall( 0x00611310 );
    virtual ~zCMessageFilter()                   zCall( 0x00610F00 );
    virtual void OnTrigger( zCVob*, zCVob* )     zCall( 0x00611270 );
    virtual void OnUntrigger( zCVob*, zCVob* )   zCall( 0x00611290 );
    virtual void OnTouch( zCVob* )               zCall( 0x00604610 );
    virtual void OnUntouch( zCVob* )             zCall( 0x00604620 );

    // user API
    #include "zCMessageFilter.inl"
  };

  // sizeof 134h
  class zCTriggerUntouch : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCTriggerUntouch )

    zCTriggerUntouch() {}
    static zCObject* _CreateNewInstance()      zCall( 0x00604130 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x00604240 );
    virtual ~zCTriggerUntouch()                zCall( 0x006042B0 );
    virtual void OnTrigger( zCVob*, zCVob* )   zCall( 0x00604260 );
    virtual void OnUntrigger( zCVob*, zCVob* ) zCall( 0x00604270 );
    virtual void OnTouch( zCVob* )             zCall( 0x00604250 );
    virtual void OnUntouch( zCVob* )           zCall( 0x00611390 );

    // user API
    #include "zCTriggerUntouch.inl"
  };

  // sizeof 138h
  class zCTriggerWorldStart : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCTriggerWorldStart )

    char fireOnlyFirstTime; // sizeof 01h    offset 134h
    char hasFired;          // sizeof 01h    offset 135h

    void zCTriggerWorldStart_OnInit()          zCall( 0x00612CE0 );
    zCTriggerWorldStart()                      zInit( zCTriggerWorldStart_OnInit() );
    static zCObject* _CreateNewInstance()      zCall( 0x00604FE0 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x006050F0 );
    virtual void Archive( zCArchiver& )        zCall( 0x00612E70 );
    virtual void Unarchive( zCArchiver& )      zCall( 0x00612ED0 );
    virtual ~zCTriggerWorldStart()             zCall( 0x00612DC0 );
    virtual void OnTrigger( zCVob*, zCVob* )   zCall( 0x00612E50 );
    virtual void OnUntrigger( zCVob*, zCVob* ) zCall( 0x00605120 );
    virtual void OnTouch( zCVob* )             zCall( 0x00605100 );
    virtual void OnUntouch( zCVob* )           zCall( 0x00605110 );
    virtual void PostLoad()                    zCall( 0x00612E20 );

    // user API
    #include "zCTriggerWorldStart.inl"
  };

  // sizeof 1E0h
  class zCCodeMaster : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCCodeMaster )

    // sizeof 01h
    struct zCCodeMasterDummy0 {
      unsigned char orderRelevant       : 1; // sizeof 01h    offset bit
      unsigned char untriggerCancels    : 1; // sizeof 01h    offset bit
      unsigned char firstFalseIsFailure : 1; // sizeof 01h    offset bit
    };

    zSTRING slaveVobNameList[MAX_SLAVES];  // sizeof 78h    offset 134h
    zSTRING triggerTargetFailure;          // sizeof 14h    offset 1ACh
    zCCodeMasterDummy0 flags;              // sizeof 01h    offset 1C0h
    zCVob* slaveTriggeredList[MAX_SLAVES]; // sizeof 18h    offset 1C4h
    int numSlavesTriggered;                // sizeof 04h    offset 1DCh

    void zCCodeMaster_OnInit()                           zCall( 0x006114C0 );
    zCCodeMaster()                                       zInit( zCCodeMaster_OnInit() );
    void Init()                                          zCall( 0x00611800 );
    void Reset()                                         zCall( 0x00611980 );
    void FireTriggerSuccess( zCVob* )                    zCall( 0x006119D0 );
    void FireTriggerFailure( zCVob* )                    zCall( 0x00611AB0 );
    int GetSlaveNr( zCVob* )                             zCall( 0x00611B90 );
    static zCObject* _CreateNewInstance()                zCall( 0x00604820 );
    virtual zCClassDef* _GetClassDef() const             zCall( 0x00604A20 );
    virtual void Archive( zCArchiver& )                  zCall( 0x00611FB0 );
    virtual void Unarchive( zCArchiver& )                zCall( 0x006123C0 );
    virtual ~zCCodeMaster()                              zCall( 0x006116A0 );
    virtual void OnTrigger( zCVob*, zCVob* )             zCall( 0x00611C40 );
    virtual void OnUntrigger( zCVob*, zCVob* )           zCall( 0x00611E40 );
    virtual void OnTouch( zCVob* )                       zCall( 0x00604A40 );
    virtual void OnUntouch( zCVob* )                     zCall( 0x00604A30 );
    virtual void OnMessage( zCEventMessage*, zCVob* )    zCall( 0x00611F40 );
    virtual zSTRING const* GetTriggerTarget( int ) const zCall( 0x00612780 );

    // user API
    #include "zCCodeMaster.inl"
  };

  // sizeof 13Ch
  class zCMoverControler : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCMoverControler )

    zCEventMover::zTEventMoverSubType moverMessage; // sizeof 04h    offset 134h
    int gotoFixedKeyframe;                          // sizeof 04h    offset 138h

    void zCMoverControler_OnInit()             zCall( 0x006127B0 );
    zCMoverControler()                         zInit( zCMoverControler_OnInit() );
    static zCObject* _CreateNewInstance()      zCall( 0x00604CA0 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x00604DB0 );
    virtual void Archive( zCArchiver& )        zCall( 0x00612A10 );
    virtual void Unarchive( zCArchiver& )      zCall( 0x00612C80 );
    virtual ~zCMoverControler()                zCall( 0x006128A0 );
    virtual void OnTrigger( zCVob*, zCVob* )   zCall( 0x00612900 );
    virtual void OnUntrigger( zCVob*, zCVob* ) zCall( 0x00604DC0 );
    virtual void OnTouch( zCVob* )             zCall( 0x00604DE0 );
    virtual void OnUntouch( zCVob* )           zCall( 0x00604DD0 );

    // user API
    #include "zCMoverControler.inl"
  };

  // sizeof 120h
  class zCVobChar : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobChar )

    zCVobChar() {}

    // user API
    #include "zCVobChar.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVOB_MISC_H__VER2__