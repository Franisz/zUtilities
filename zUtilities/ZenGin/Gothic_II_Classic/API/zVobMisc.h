// Supported with union (c) 2018 Union team

#ifndef __ZVOB_MISC_H__VER2__
#define __ZVOB_MISC_H__VER2__

namespace Gothic_II_Classic {
  const int MAX_TARGETS = 6;
  const int MAX_SLAVES  = 6;

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

  class zCTriggerBase : public zCVob {
  public:
    zCLASS_DECLARATION( zCTriggerBase )

    zSTRING triggerTarget;

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

  class zCTrigger : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCTrigger )

    struct zCTriggerDummy0 {
      unsigned char reactToOnTrigger : 1;
      unsigned char reactToOnTouch   : 1;
      unsigned char reactToOnDamage  : 1;
      unsigned char respondToObject  : 1;
      unsigned char respondToPC      : 1;
      unsigned char respondToNPC     : 1;
    };

    zCTriggerDummy0 filterFlags;
    zSTRING respondToVobName;
    short numCanBeActivated;
    float retriggerWaitSec;
    float damageThreshold;
    float fireDelaySec;
    float nextTimeTriggerable;
    zCVob* savedOtherVob;
    short countCanBeActivated;

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

    int gotoFixedKeyframe;

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

    struct zTMov_Keyframe {
      zVEC3 pos;
      zCQuat quat;

      zTMov_Keyframe() {}

      // user API
      #include "zCMover_zTMov_Keyframe.inl"
    };

    zCArray<zTMov_Keyframe> keyframeList;
    zVEC3 actKeyPosDelta;
    float actKeyframeF;
    int actKeyframe;
    int nextKeyframe;
    float moveSpeedUnit;
    float advanceDir;
    zTMoverState moverState;
    int numTriggerEvents;
    float stayOpenTimeDest;
    zCModel* model;
    int soundMovingHandle;
    zCSoundFX* sfxMoving;
    float moveSpeed;
    float stayOpenTimeSec;
    float touchBlockerDamage;
    char moverLocked;
    char autoLinkEnabled;
    char autoRotate;
    zTMoverAniType moverAniType;
    zTMoverBehavior moverBehavior;
    zTTouchBehavior touchBehavior;
    zTPosLerpType posLerpType;
    zTSpeedType speedType;
    zSTRING soundOpenStart;
    zSTRING soundOpenEnd;
    zSTRING soundMoving;
    zSTRING soundCloseStart;
    zSTRING soundCloseEnd;
    zSTRING soundLock;
    zSTRING soundUnlock;
    zSTRING soundUseLocked;

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

  class zCTriggerTeleport : public zCTrigger {
  public:
    zCLASS_DECLARATION( zCTriggerTeleport )

    zSTRING teleportSoundName;
    zCSoundFX* teleportSound;

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

  class zCTriggerList : public zCTrigger {
  public:
    zCLASS_DECLARATION( zCTriggerList )

    enum zTListProcess {
      LP_ALL,
      LP_NEXT_ONE,
      LP_RAND_ONE
    };

    zSTRING triggerTargetList[MAX_TARGETS];
    float fireDelayList[MAX_TARGETS];
    zTListProcess listProcess;
    int actTarget;
    int sendOnTrigger;

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

  class zCEffect : public zCVob {
  public:
    zCLASS_DECLARATION( zCEffect )

    zCEffect() {}
    virtual zCClassDef* _GetClassDef() const zCall( 0x00488780 );
    virtual ~zCEffect()                      zCall( 0x00488A40 );

    // user API
    #include "zCEffect.inl"
  };

  class zCEarthquake : public zCEffect {
  public:
    zCLASS_DECLARATION( zCEarthquake )

    float radiusSquare;
    float timeMSec;
    zVEC3 amplitude;

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

  class zCPFXControler : public zCEffect {
  public:
    zCLASS_DECLARATION( zCPFXControler )

    zSTRING pfxName;
    group {
      unsigned char killVobWhenDone : 1;
      unsigned char pfxStartOn      : 1;
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

  class zCTouchDamage : public zCEffect {
  public:
    zCLASS_DECLARATION( zCTouchDamage )

    enum zTDamageCollType {
      CT_NONE,
      CT_BOX,
      CT_POINT
    };

    float damage;
    int damageType;
    float damageRepeatDelaySec;
    float damageVolDownScale;
    zTDamageCollType damageCollType;

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

  class zCTouchAnimate : public zCEffect {
  public:
    zCLASS_DECLARATION( zCTouchAnimate )

    zSTRING touchSoundName;
    zCSoundFX* touchSound;

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

  class zCTouchAnimateSound : public zCTouchAnimate {
  public:
    zCLASS_DECLARATION( zCTouchAnimateSound )

    zSTRING touchSoundName;

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

  class zCVobAnimate : public zCEffect {
  public:
    zCLASS_DECLARATION( zCVobAnimate )

    char startOn;
    char isRunning;

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

  class zCVobLensFlare : public zCEffect {
  public:
    zCLASS_DECLARATION( zCVobLensFlare )

    zCLensFlareFX* lensFlareFX;

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

    float duration;
    zCOLOR color;
    float fovDeg;

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

  class zCVobScreenFX : public zCEffect {
  public:
    zCLASS_DECLARATION( zCVobScreenFX )

    struct zTScreenFXSet {
      float weight;
      float velo;
      zCOLOR color;
      float fovDeg;
      int visible;
      zSTRING texName;
      float texAniFPS;
      zTRnd_AlphaBlendFunc blendFunc;

      zTScreenFXSet() {}
      ~zTScreenFXSet() zCall( 0x00610570 );

      // user API
      #include "zCVobScreenFX_zTScreenFXSet.inl"
    };

    zTScreenFXSet blend;
    zTScreenFXSet cinema;
    zTScreenFXSet fovMorph;
    zVEC2 fovSaved;
    zVEC2 fovSavedFirst;

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
      unsigned char sendWhenTriggered   : 4;
      unsigned char sendWhenUntriggered : 4;
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

  class zCTriggerWorldStart : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCTriggerWorldStart )

    char fireOnlyFirstTime;
    char hasFired;

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

  class zCCodeMaster : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCCodeMaster )

    struct zCCodeMasterDummy0 {
      unsigned char orderRelevant       : 1;
      unsigned char untriggerCancels    : 1;
      unsigned char firstFalseIsFailure : 1;
    };

    zSTRING slaveVobNameList[MAX_SLAVES];
    zSTRING triggerTargetFailure;
    zCCodeMasterDummy0 flags;
    zCVob* slaveTriggeredList[MAX_SLAVES];
    int numSlavesTriggered;

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

  class zCMoverControler : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCMoverControler )

    zCEventMover::zTEventMoverSubType moverMessage;
    int gotoFixedKeyframe;

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

  class zCVobChar : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobChar )

    zCVobChar() {}

    // user API
    #include "zCVobChar.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVOB_MISC_H__VER2__