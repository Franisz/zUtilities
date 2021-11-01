// Supported with union (c) 2018-2021 Union team

#ifndef __ZVOB_MISC_H__VER3__
#define __ZVOB_MISC_H__VER3__

#include "zVob.h"

namespace Gothic_II_Addon {
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
    static zCObject* _CreateNewInstance()      zCall( 0x0060EF70 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x0060F0C0 );
    virtual ~zCEventCommon()                   zCall( 0x0060F120 );
    virtual int IsNetRelevant()                zCall( 0x0060F0E0 );
    virtual int MD_GetNumOfSubTypes()          zCall( 0x0060F0D0 );
    virtual zSTRING MD_GetSubTypeString( int ) zCall( 0x0060F7E0 );

    // user API
    #include "zCEventCommon.inl"
  };

  // sizeof 134h
  class zCTriggerBase : public zCVob {
  public:
    zCLASS_DECLARATION( zCTriggerBase )

    zSTRING triggerTarget; // sizeof 14h    offset 120h

    void zCTriggerBase_OnInit()                          zCall( 0x0060FAF0 );
    zCTriggerBase()                                      zInit( zCTriggerBase_OnInit() );
    virtual zCClassDef* _GetClassDef() const             zCall( 0x0060B8D0 );
    virtual void Archive( zCArchiver& )                  zCall( 0x0060FE40 );
    virtual void Unarchive( zCArchiver& )                zCall( 0x0060FE70 );
    virtual ~zCTriggerBase()                             zCall( 0x0060C110 );
    virtual void OnTrigger( zCVob*, zCVob* )             zCall( 0x0060FD00 );
    virtual void OnUntrigger( zCVob*, zCVob* )           zCall( 0x0060FDA0 );
    virtual void OnTouch( zCVob* )                       zCall( 0x0060FBC0 );
    virtual void OnUntouch( zCVob* )                     zCall( 0x0060FC60 );
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

    void zCTrigger_OnInit()                                           zCall( 0x0060FEA0 );
    zSTRING GetTriggerTarget() const                                  zCall( 0x004049A0 );
    zCTrigger()                                                       zInit( zCTrigger_OnInit() );
    void ClearStateInternals()                                        zCall( 0x006100D0 );
    void TriggerTargetPost()                                          zCall( 0x006104A0 );
    void ActivateTrigger( zCVob* )                                    zCall( 0x006104D0 );
    void DeactivateTrigger( zCVob* )                                  zCall( 0x006105B0 );
    static zCObject* _CreateNewInstance()                             zCall( 0x0060C9E0 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x00610090 );
    virtual void Archive( zCArchiver& )                               zCall( 0x006107E0 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x00610A60 );
    virtual ~zCTrigger()                                              zCall( 0x00610120 );
    virtual void OnTrigger( zCVob*, zCVob* )                          zCall( 0x006105E0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                        zCall( 0x00610600 );
    virtual void OnTouch( zCVob* )                                    zCall( 0x00610640 );
    virtual void OnUntouch( zCVob* )                                  zCall( 0x00610660 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& ) zCall( 0x006106A0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                 zCall( 0x006106E0 );
    virtual void OnTimer()                                            zCall( 0x00610750 );
    virtual void TriggerTarget( zCVob* )                              zCall( 0x00610340 );
    virtual void UntriggerTarget( zCVob* )                            zCall( 0x006103F0 );
    virtual int CanBeActivatedNow( zCVob* )                           zCall( 0x00610220 );

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
    static zCObject* _CreateNewInstance()      zCall( 0x0060F310 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x0060F460 );
    virtual ~zCEventMover()                    zCall( 0x0060F4C0 );
    virtual int IsNetRelevant()                zCall( 0x0060F480 );
    virtual int MD_GetNumOfSubTypes()          zCall( 0x0060F470 );
    virtual zSTRING MD_GetSubTypeString( int ) zCall( 0x0060F940 );

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

    void zCMover_OnInit()                                             zCall( 0x00610D20 );
    zCMover()                                                         zInit( zCMover_OnInit() );
    void ClearStateInternals()                                        zCall( 0x00610F40 );
    void UpdateInternals()                                            zCall( 0x00611270 );
    void AdvanceKeyframe_KF()                                         zCall( 0x006113D0 );
    void SetToKeyframe_KF( float )                                    zCall( 0x00611400 );
    void InterpolateKeyframes_KF()                                    zCall( 0x00611900 );
    void AdvanceMover()                                               zCall( 0x00611D90 );
    void SetToKeyframe( float, float )                                zCall( 0x00612090 );
    void InvertMovement()                                             zCall( 0x00612300 );
    void StartMovingSound()                                           zCall( 0x00612560 );
    void MoveToKeyframe( int )                                        zCall( 0x006125D0 );
    void DoOpen()                                                     zCall( 0x00612640 );
    void FinishedOpening()                                            zCall( 0x006126F0 );
    void DoClose()                                                    zCall( 0x00612770 );
    void FinishedClosing()                                            zCall( 0x00612830 );
    void Unlock( zCVob* )                                             zCall( 0x00612880 );
    void Lock( zCVob* )                                               zCall( 0x00612A50 );
    int IsKeyToThisMover( zCVob* )                                    zCall( 0x00612C20 );
    void TriggerMover( zCVob* )                                       zCall( 0x00612CB0 );
    static zCObject* _CreateNewInstance()                             zCall( 0x0060D080 );
    static zTMov_Keyframe GetKeyframe( zCVob* )                       zCall( 0x006112F0 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x00610F00 );
    virtual void Archive( zCArchiver& )                               zCall( 0x006137E0 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x00613AA0 );
    virtual ~zCMover()                                                zCall( 0x00611000 );
    virtual void OnTrigger( zCVob*, zCVob* )                          zCall( 0x00613080 );
    virtual void OnUntrigger( zCVob*, zCVob* )                        zCall( 0x00613170 );
    virtual void OnTouch( zCVob* )                                    zCall( 0x00613340 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& ) zCall( 0x00613400 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                 zCall( 0x00613450 );
    virtual void OnTick()                                             zCall( 0x00612F80 );
    virtual void PostLoad()                                           zCall( 0x006137D0 );
    virtual int CanThisCollideWith( zCVob* )                          zCall( 0x006111F0 );
    virtual void SetVisual( zCVisual* )                               zCall( 0x006123A0 );

    // user API
    #include "zCMover.inl"
  };

  // sizeof 180h
  class zCTriggerTeleport : public zCTrigger {
  public:
    zCLASS_DECLARATION( zCTriggerTeleport )

    zSTRING teleportSoundName; // sizeof 14h    offset 168h
    zCSoundFX* teleportSound;  // sizeof 04h    offset 17Ch

    void zCTriggerTeleport_OnInit()            zCall( 0x00614120 );
    zCTriggerTeleport()                        zInit( zCTriggerTeleport_OnInit() );
    void DoTeleport( zCVob* )                  zCall( 0x00614440 );
    static zCObject* _CreateNewInstance()      zCall( 0x0060D2F0 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x0060D470 );
    virtual void Archive( zCArchiver& )        zCall( 0x006146C0 );
    virtual void Unarchive( zCArchiver& )      zCall( 0x006146F0 );
    virtual ~zCTriggerTeleport()               zCall( 0x006142D0 );
    virtual void OnTrigger( zCVob*, zCVob* )   zCall( 0x006146A0 );
    virtual void OnUntrigger( zCVob*, zCVob* ) zCall( 0x006146B0 );
    virtual void OnTouch( zCVob* )             zCall( 0x00614690 );

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

    void zCTriggerList_OnInit()                          zCall( 0x00614B50 );
    zCTriggerList()                                      zInit( zCTriggerList_OnInit() );
    void Init()                                          zCall( 0x00614E00 );
    void TriggerActTarget( zCVob* )                      zCall( 0x00614F30 );
    int ProcessActTarget( zCVob* )                       zCall( 0x00615000 );
    void FinishActivation()                              zCall( 0x00615090 );
    void DoTriggering( zCVob* )                          zCall( 0x00615190 );
    static zCObject* _CreateNewInstance()                zCall( 0x0060CC50 );
    virtual zCClassDef* _GetClassDef() const             zCall( 0x0060CE80 );
    virtual void Archive( zCArchiver& )                  zCall( 0x00615490 );
    virtual void Unarchive( zCArchiver& )                zCall( 0x00615770 );
    virtual ~zCTriggerList()                             zCall( 0x00614CF0 );
    virtual void OnTimer()                               zCall( 0x00615100 );
    virtual zSTRING const* GetTriggerTarget( int ) const zCall( 0x00614F10 );
    virtual void TriggerTarget( zCVob* )                 zCall( 0x00615460 );
    virtual void UntriggerTarget( zCVob* )               zCall( 0x00615470 );

    // user API
    #include "zCTriggerList.inl"
  };

  // sizeof 120h
  class zCEffect : public zCVob {
  public:
    zCLASS_DECLARATION( zCEffect )

    zCEffect() {}
    virtual zCClassDef* _GetClassDef() const zCall( 0x00489F40 );
    virtual ~zCEffect()                      zCall( 0x0048A220 );

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

    void zCEarthquake_OnInit()                 zCall( 0x00613EA0 );
    zCEarthquake()                             zInit( zCEarthquake_OnInit() );
    static zCObject* _CreateNewInstance()      zCall( 0x0060D850 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x0060D920 );
    virtual void Archive( zCArchiver& )        zCall( 0x00614030 );
    virtual void Unarchive( zCArchiver& )      zCall( 0x006140B0 );
    virtual ~zCEarthquake()                    zCall( 0x00613F80 );
    virtual void OnTrigger( zCVob*, zCVob* )   zCall( 0x00613F90 );
    virtual void OnUntrigger( zCVob*, zCVob* ) zCall( 0x00613FE0 );

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

    void zCPFXControler_OnInit()               zCall( 0x00614760 );
    zCPFXControler()                           zInit( zCPFXControler_OnInit() );
    zCParticleFX* GetPFX()                     zCall( 0x00614840 );
    static zCObject* _CreateNewInstance()      zCall( 0x0060DB20 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x0060DBF0 );
    virtual void Archive( zCArchiver& )        zCall( 0x00614990 );
    virtual void Unarchive( zCArchiver& )      zCall( 0x006149F0 );
    virtual ~zCPFXControler()                  zCall( 0x006147E0 );
    virtual void OnTrigger( zCVob*, zCVob* )   zCall( 0x006148D0 );
    virtual void OnUntrigger( zCVob*, zCVob* ) zCall( 0x00614960 );
    virtual void PostLoad()                    zCall( 0x006148B0 );

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

    void zCTouchDamage_OnInit()                               zCall( 0x00615A80 );
    zCTouchDamage()                                           zInit( zCTouchDamage_OnInit() );
    void ProcessToucher( zCVob* )                             zCall( 0x00615D70 );
    int TestCollType( zCVob* )                                zCall( 0x00615E10 );
    void FireDamageMessage( zCVob* )                          zCall( 0x00616070 );
    void SetVobProperties()                                   zCall( 0x00616300 );
    static zCObject* _CreateNewInstance()                     zCall( 0x0060DDF0 );
    virtual zCClassDef* _GetClassDef() const                  zCall( 0x0060DEF0 );
    virtual void Archive( zCArchiver& )                       zCall( 0x00616100 );
    virtual void Unarchive( zCArchiver& )                     zCall( 0x006161D0 );
    virtual ~zCTouchDamage()                                  zCall( 0x00615B60 );
    virtual void OnTouch( zCVob* )                            zCall( 0x00615B70 );
    virtual void OnUntouch( zCVob* )                          zCall( 0x00615C50 );
    virtual void OnTimer()                                    zCall( 0x00615C70 );
    virtual void SetVisual( zCVisual* )                       zCall( 0x006162B0 );
    virtual char const* GetDamageTypeArcEnum( unsigned long ) zCall( 0x00616290 );

    // user API
    #include "zCTouchDamage.inl"
  };

  // sizeof 120h
  class zCVobStair : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobStair )

    zCVobStair() {}
    static zCObject* _CreateNewInstance()    zCall( 0x0060B350 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x0060B3D0 );
    virtual ~zCVobStair()                    zCall( 0x0060B410 );

    // user API
    #include "zCVobStair.inl"
  };

  // sizeof 138h
  class zCTouchAnimate : public zCEffect {
  public:
    zCLASS_DECLARATION( zCTouchAnimate )

    zSTRING touchSoundName; // sizeof 14h    offset 120h
    zCSoundFX* touchSound;  // sizeof 04h    offset 134h

    void zCTouchAnimate_OnInit()             zCall( 0x00616340 );
    zCTouchAnimate()                         zInit( zCTouchAnimate_OnInit() );
    int IsTouching( zCVob* )                 zCall( 0x006167F0 );
    void StartAni()                          zCall( 0x006168C0 );
    void StopAni()                           zCall( 0x00616B30 );
    int IsAniActive()                        zCall( 0x00616B70 );
    void SetVobProperties()                  zCall( 0x00616C80 );
    static zCObject* _CreateNewInstance()    zCall( 0x0060E0F0 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x0060E1F0 );
    virtual void Archive( zCArchiver& )      zCall( 0x00616BB0 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00616BC0 );
    virtual ~zCTouchAnimate()                zCall( 0x00616420 );
    virtual void OnTouch( zCVob* )           zCall( 0x006164E0 );
    virtual void OnUntouch( zCVob* )         zCall( 0x00616600 );
    virtual void OnTick()                    zCall( 0x00616620 );
    virtual void SetVisual( zCVisual* )      zCall( 0x00616C30 );
    virtual zSTRING GetSoundName()           zCall( 0x00616A20 );

    // user API
    #include "zCTouchAnimate.inl"
  };

  // sizeof 14Ch
  class zCTouchAnimateSound : public zCTouchAnimate {
  public:
    zCLASS_DECLARATION( zCTouchAnimateSound )

    zSTRING touchSoundName; // sizeof 14h    offset 138h

    void zCTouchAnimateSound_OnInit()        zCall( 0x00616CC0 );
    zCTouchAnimateSound()                    zInit( zCTouchAnimateSound_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x0060E3F0 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x0060E5A0 );
    virtual void Archive( zCArchiver& )      zCall( 0x00616F60 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00616F90 );
    virtual ~zCTouchAnimateSound()           zCall( 0x00616E60 );
    virtual zSTRING GetSoundName()           zCall( 0x00617020 );

    // user API
    #include "zCTouchAnimateSound.inl"
  };

  // sizeof 124h
  class zCVobAnimate : public zCEffect {
  public:
    zCLASS_DECLARATION( zCVobAnimate )

    char startOn;   // sizeof 01h    offset 120h
    char isRunning; // sizeof 01h    offset 121h

    void zCVobAnimate_OnInit()                 zCall( 0x00617070 );
    zCVobAnimate()                             zInit( zCVobAnimate_OnInit() );
    void StartAni()                            zCall( 0x006171A0 );
    void StopAni()                             zCall( 0x006171E0 );
    static zCObject* _CreateNewInstance()      zCall( 0x0060E7A0 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x0060E860 );
    virtual void Archive( zCArchiver& )        zCall( 0x00617250 );
    virtual void Unarchive( zCArchiver& )      zCall( 0x006172A0 );
    virtual ~zCVobAnimate()                    zCall( 0x00617120 );
    virtual void OnTrigger( zCVob*, zCVob* )   zCall( 0x006171F0 );
    virtual void OnUntrigger( zCVob*, zCVob* ) zCall( 0x00617240 );
    virtual void SetVisual( zCVisual* )        zCall( 0x00617130 );

    // user API
    #include "zCVobAnimate.inl"
  };

  // sizeof 124h
  class zCVobLensFlare : public zCEffect {
  public:
    zCLASS_DECLARATION( zCVobLensFlare )

    zCLensFlareFX* lensFlareFX; // sizeof 04h    offset 120h

    void zCVobLensFlare_OnInit()                      zCall( 0x00617350 );
    zCVobLensFlare()                                  zInit( zCVobLensFlare_OnInit() );
    void SetLensFlareFXByName( zSTRING const& )       zCall( 0x00617430 );
    static zCObject* _CreateNewInstance()             zCall( 0x0060EA60 );
    virtual zCClassDef* _GetClassDef() const          zCall( 0x0060EB30 );
    virtual void Archive( zCArchiver& )               zCall( 0x00617480 );
    virtual void Unarchive( zCArchiver& )             zCall( 0x00617570 );
    virtual ~zCVobLensFlare()                         zCall( 0x006173F0 );
    virtual int __fastcall Render( zTRenderContext& ) zCall( 0x00617410 );

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
    void zCEventScreenFX_OnInit( zTEventScreenFXSubType, float, zCOLOR, float ) zCall( 0x00617650 );
    zCEventScreenFX( zTEventScreenFXSubType a0, float a1, zCOLOR a2, float a3 ) zInit( zCEventScreenFX_OnInit( a0, a1, a2, a3 ));
    void Clear()                                                                zCall( 0x006176F0 );
    static zCObject* _CreateNewInstance()                                       zCall( 0x0060F6B0 );
    virtual zCClassDef* _GetClassDef() const                                    zCall( 0x0060F780 );
    virtual void Archive( zCArchiver& )                                         zCall( 0x006179C0 );
    virtual void Unarchive( zCArchiver& )                                       zCall( 0x00617A10 );
    virtual ~zCEventScreenFX()                                                  zCall( 0x0060F7D0 );
    virtual int MD_GetNumOfSubTypes()                                           zCall( 0x0060F790 );
    virtual zSTRING MD_GetSubTypeString( int )                                  zCall( 0x00617720 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()                 zCall( 0x00617910 );
    virtual float MD_GetMinTime()                                               zCall( 0x00617930 );
    virtual void Pack( zCBuffer&, zCEventManager* )                             zCall( 0x00617940 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                           zCall( 0x00617980 );

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
      ~zTScreenFXSet() zCall( 0x00617C30 );

      // user API
      #include "zCVobScreenFX_zTScreenFXSet.inl"
    };

    zTScreenFXSet blend;    // sizeof 30h    offset 120h
    zTScreenFXSet cinema;   // sizeof 30h    offset 150h
    zTScreenFXSet fovMorph; // sizeof 30h    offset 180h
    zVEC2 fovSaved;         // sizeof 08h    offset 1B0h
    zVEC2 fovSavedFirst;    // sizeof 08h    offset 1B8h

    void zCVobScreenFX_OnInit()                            zCall( 0x00617A60 );
    zCVobScreenFX()                                        zInit( zCVobScreenFX_OnInit() );
    void StartEffect( float, zCOLOR, int, zTScreenFXSet& ) zCall( 0x00617F50 );
    zCOLOR CalcEffectColor( zTScreenFXSet& )               zCall( 0x00617FE0 );
    static zCObject* _CreateNewInstance()                  zCall( 0x0060ED30 );
    virtual zCClassDef* _GetClassDef() const               zCall( 0x00617BF0 );
    virtual void Archive( zCArchiver& )                    zCall( 0x006183B0 );
    virtual void Unarchive( zCArchiver& )                  zCall( 0x00618440 );
    virtual ~zCVobScreenFX()                               zCall( 0x00617C80 );
    virtual void OnMessage( zCEventMessage*, zCVob* )      zCall( 0x00617D60 );
    virtual void OnTick()                                  zCall( 0x00618070 );

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

    void zCMessageFilter_OnInit()                zCall( 0x006184E0 );
    zCMessageFilter()                            zInit( zCMessageFilter_OnInit() );
    void ProcessMessage( zTMessageType, zCVob* ) zCall( 0x00618620 );
    static zCObject* _CreateNewInstance()        zCall( 0x0060BBC0 );
    virtual zCClassDef* _GetClassDef() const     zCall( 0x0060BCC0 );
    virtual void Archive( zCArchiver& )          zCall( 0x00618970 );
    virtual void Unarchive( zCArchiver& )        zCall( 0x006189D0 );
    virtual ~zCMessageFilter()                   zCall( 0x006185C0 );
    virtual void OnTrigger( zCVob*, zCVob* )     zCall( 0x00618930 );
    virtual void OnUntrigger( zCVob*, zCVob* )   zCall( 0x00618950 );
    virtual void OnTouch( zCVob* )               zCall( 0x0060BCD0 );
    virtual void OnUntouch( zCVob* )             zCall( 0x0060BCE0 );

    // user API
    #include "zCMessageFilter.inl"
  };

  // sizeof 134h
  class zCTriggerUntouch : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCTriggerUntouch )

    zCTriggerUntouch() {}
    static zCObject* _CreateNewInstance()      zCall( 0x0060B7F0 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x0060B900 );
    virtual ~zCTriggerUntouch()                zCall( 0x0060B970 );
    virtual void OnTrigger( zCVob*, zCVob* )   zCall( 0x0060B920 );
    virtual void OnUntrigger( zCVob*, zCVob* ) zCall( 0x0060B930 );
    virtual void OnTouch( zCVob* )             zCall( 0x0060B910 );
    virtual void OnUntouch( zCVob* )           zCall( 0x00618A50 );

    // user API
    #include "zCTriggerUntouch.inl"
  };

  // sizeof 138h
  class zCTriggerWorldStart : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCTriggerWorldStart )

    char fireOnlyFirstTime; // sizeof 01h    offset 134h
    char hasFired;          // sizeof 01h    offset 135h

    void zCTriggerWorldStart_OnInit()          zCall( 0x0061A3A0 );
    zCTriggerWorldStart()                      zInit( zCTriggerWorldStart_OnInit() );
    static zCObject* _CreateNewInstance()      zCall( 0x0060C6A0 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x0060C7B0 );
    virtual void Archive( zCArchiver& )        zCall( 0x0061A530 );
    virtual void Unarchive( zCArchiver& )      zCall( 0x0061A590 );
    virtual ~zCTriggerWorldStart()             zCall( 0x0061A480 );
    virtual void OnTrigger( zCVob*, zCVob* )   zCall( 0x0061A510 );
    virtual void OnUntrigger( zCVob*, zCVob* ) zCall( 0x0060C7E0 );
    virtual void OnTouch( zCVob* )             zCall( 0x0060C7C0 );
    virtual void OnUntouch( zCVob* )           zCall( 0x0060C7D0 );
    virtual void PostLoad()                    zCall( 0x0061A4E0 );

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

    void zCCodeMaster_OnInit()                           zCall( 0x00618B80 );
    zCCodeMaster()                                       zInit( zCCodeMaster_OnInit() );
    void Init()                                          zCall( 0x00618EC0 );
    void Reset()                                         zCall( 0x00619040 );
    void FireTriggerSuccess( zCVob* )                    zCall( 0x00619090 );
    void FireTriggerFailure( zCVob* )                    zCall( 0x00619170 );
    int GetSlaveNr( zCVob* )                             zCall( 0x00619250 );
    static zCObject* _CreateNewInstance()                zCall( 0x0060BEE0 );
    virtual zCClassDef* _GetClassDef() const             zCall( 0x0060C0E0 );
    virtual void Archive( zCArchiver& )                  zCall( 0x00619670 );
    virtual void Unarchive( zCArchiver& )                zCall( 0x00619A80 );
    virtual ~zCCodeMaster()                              zCall( 0x00618D60 );
    virtual void OnTrigger( zCVob*, zCVob* )             zCall( 0x00619300 );
    virtual void OnUntrigger( zCVob*, zCVob* )           zCall( 0x00619500 );
    virtual void OnTouch( zCVob* )                       zCall( 0x0060C100 );
    virtual void OnUntouch( zCVob* )                     zCall( 0x0060C0F0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )    zCall( 0x00619600 );
    virtual zSTRING const* GetTriggerTarget( int ) const zCall( 0x00619E40 );

    // user API
    #include "zCCodeMaster.inl"
  };

  // sizeof 13Ch
  class zCMoverControler : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCMoverControler )

    zCEventMover::zTEventMoverSubType moverMessage; // sizeof 04h    offset 134h
    int gotoFixedKeyframe;                          // sizeof 04h    offset 138h

    void zCMoverControler_OnInit()             zCall( 0x00619E70 );
    zCMoverControler()                         zInit( zCMoverControler_OnInit() );
    static zCObject* _CreateNewInstance()      zCall( 0x0060C360 );
    virtual zCClassDef* _GetClassDef() const   zCall( 0x0060C470 );
    virtual void Archive( zCArchiver& )        zCall( 0x0061A0D0 );
    virtual void Unarchive( zCArchiver& )      zCall( 0x0061A340 );
    virtual ~zCMoverControler()                zCall( 0x00619F60 );
    virtual void OnTrigger( zCVob*, zCVob* )   zCall( 0x00619FC0 );
    virtual void OnUntrigger( zCVob*, zCVob* ) zCall( 0x0060C480 );
    virtual void OnTouch( zCVob* )             zCall( 0x0060C4A0 );
    virtual void OnUntouch( zCVob* )           zCall( 0x0060C490 );

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

} // namespace Gothic_II_Addon

#endif // __ZVOB_MISC_H__VER3__