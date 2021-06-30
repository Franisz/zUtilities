// Supported with union (c) 2018 Union team

#ifndef __ZVOB_MISC_H__VER1__
#define __ZVOB_MISC_H__VER1__

namespace Gothic_I_Addon {
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
    static zCObject* _CreateNewInstance()                               zCall( 0x00601F30 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006020B0 );
    virtual ~zCEventCommon()                                            zCall( 0x00602110 );
    virtual int IsNetRelevant()                                         zCall( 0x006020D0 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x006020C0 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x00602860 );

    // user API
    #include "zCEventCommon.inl"
  };

  class zCTriggerBase : public zCVob {
  public:
    zCLASS_DECLARATION( zCTriggerBase )

    zSTRING triggerTarget;

    void zCTriggerBase_OnInit()                          zCall( 0x00602B90 );
    zCTriggerBase()                                      zInit( zCTriggerBase_OnInit() );
    virtual zCClassDef* _GetClassDef() const             zCall( 0x005FE4D0 );
    virtual void Archive( zCArchiver& )                  zCall( 0x00602EE0 );
    virtual void Unarchive( zCArchiver& )                zCall( 0x00602F10 );
    virtual ~zCTriggerBase()                             zCall( 0x005FED70 );
    virtual void OnTrigger( zCVob*, zCVob* )             zCall( 0x00602DA0 );
    virtual void OnUntrigger( zCVob*, zCVob* )           zCall( 0x00602E40 );
    virtual void OnTouch( zCVob* )                       zCall( 0x00602C60 );
    virtual void OnUntouch( zCVob* )                     zCall( 0x00602D00 );
    virtual zSTRING const* GetTriggerTarget( int ) const zCall( 0x00404940 );

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

    void zCTrigger_OnInit()                                             zCall( 0x00602F40 );
    zSTRING GetTriggerTarget() const                                    zCall( 0x00405060 );
    zCTrigger()                                                         zInit( zCTrigger_OnInit() );
    void ClearStateInternals()                                          zCall( 0x00603170 );
    void TriggerTargetPost()                                            zCall( 0x00603550 );
    void ActivateTrigger( zCVob* )                                      zCall( 0x00603580 );
    void DeactivateTrigger( zCVob* )                                    zCall( 0x00603660 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005FF6A0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00603130 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00603890 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00603B00 );
    virtual ~zCTrigger()                                                zCall( 0x006031D0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x00603690 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x006036B0 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x006036F0 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x00603710 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )   zCall( 0x00603750 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x00603790 );
    virtual void OnTimer()                                              zCall( 0x00603800 );
    virtual void TriggerTarget( zCVob* )                                zCall( 0x006033F0 );
    virtual void UntriggerTarget( zCVob* )                              zCall( 0x006034A0 );
    virtual int CanBeActivatedNow( zCVob* )                             zCall( 0x006032D0 );

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
    static zCObject* _CreateNewInstance()                               zCall( 0x00602320 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006024A0 );
    virtual ~zCEventMover()                                             zCall( 0x00602500 );
    virtual int IsNetRelevant()                                         zCall( 0x006024C0 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x006024B0 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x006029E0 );

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

    void zCMover_OnInit()                                               zCall( 0x00603DC0 );
    zCMover()                                                           zInit( zCMover_OnInit() );
    void ClearStateInternals()                                          zCall( 0x00603FE0 );
    void UpdateInternals()                                              zCall( 0x00604360 );
    void AdvanceKeyframe_KF()                                           zCall( 0x006044D0 );
    void SetToKeyframe_KF( float )                                      zCall( 0x00604500 );
    void InterpolateKeyframes_KF()                                      zCall( 0x006049D0 );
    void AdvanceMover()                                                 zCall( 0x00604F30 );
    void SetToKeyframe( float, float )                                  zCall( 0x00605220 );
    void InvertMovement()                                               zCall( 0x00605540 );
    void StartMovingSound()                                             zCall( 0x006057F0 );
    void MoveToKeyframe( int )                                          zCall( 0x00605860 );
    void DoOpen()                                                       zCall( 0x006058D0 );
    void FinishedOpening()                                              zCall( 0x00605980 );
    void DoClose()                                                      zCall( 0x00605A00 );
    void FinishedClosing()                                              zCall( 0x00605AC0 );
    void Unlock( zCVob* )                                               zCall( 0x00605B10 );
    void Lock( zCVob* )                                                 zCall( 0x00605CF0 );
    int IsKeyToThisMover( zCVob* )                                      zCall( 0x00605ED0 );
    void TriggerMover( zCVob* )                                         zCall( 0x00605F60 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005FFD90 );
    static zTMov_Keyframe GetKeyframe( zCVob* )                         zCall( 0x006043E0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00603FA0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00606BB0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00606E70 );
    virtual ~zCMover()                                                  zCall( 0x006040A0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x00606440 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x00606540 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x00606710 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )   zCall( 0x006067D0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x00606820 );
    virtual void OnTick()                                               zCall( 0x00606340 );
    virtual void PostLoad()                                             zCall( 0x00606BA0 );
    virtual int CanThisCollideWith( zCVob* )                            zCall( 0x006042F0 );
    virtual void SetVisual( zCVisual* )                                 zCall( 0x006055E0 );

    // user API
    #include "zCMover.inl"
  };

  class zCTriggerTeleport : public zCTrigger {
  public:
    zCLASS_DECLARATION( zCTriggerTeleport )

    zSTRING teleportSoundName;
    zCSoundFX* teleportSound;

    void zCTriggerTeleport_OnInit()                                     zCall( 0x00607500 );
    zCTriggerTeleport()                                                 zInit( zCTriggerTeleport_OnInit() );
    void DoTeleport( zCVob* )                                           zCall( 0x00607830 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00600020 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006001C0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00607A70 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00607AA0 );
    virtual ~zCTriggerTeleport()                                        zCall( 0x006076B0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x00607A50 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x00607A60 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x00607A40 );

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

    void zCTriggerList_OnInit()                                         zCall( 0x00607EE0 );
    zCTriggerList()                                                     zInit( zCTriggerList_OnInit() );
    void Init()                                                         zCall( 0x006081A0 );
    void TriggerActTarget( zCVob* )                                     zCall( 0x006082D0 );
    int ProcessActTarget( zCVob* )                                      zCall( 0x006083A0 );
    void FinishActivation()                                             zCall( 0x00608440 );
    void DoTriggering( zCVob* )                                         zCall( 0x00608550 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005FF930 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005FFB80 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00608860 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00608B20 );
    virtual ~zCTriggerList()                                            zCall( 0x00608080 );
    virtual void OnTimer()                                              zCall( 0x006084B0 );
    virtual zSTRING const* GetTriggerTarget( int ) const                zCall( 0x006082B0 );
    virtual void TriggerTarget( zCVob* )                                zCall( 0x00608820 );
    virtual void UntriggerTarget( zCVob* )                              zCall( 0x00608840 );

    // user API
    #include "zCTriggerList.inl"
  };

  class zCEffect : public zCVob {
  public:
    zCLASS_DECLARATION( zCEffect )

    zCEffect() {}
    virtual zCClassDef* _GetClassDef() const zCall( 0x0048D570 );
    virtual ~zCEffect()                      zCall( 0x0048D840 );

    // user API
    #include "zCEffect.inl"
  };

  class zCEarthquake : public zCEffect {
  public:
    zCLASS_DECLARATION( zCEarthquake )

    float radiusSquare;
    float timeMSec;
    zVEC3 amplitude;

    void zCEarthquake_OnInit()                                          zCall( 0x00607260 );
    zCEarthquake()                                                      zInit( zCEarthquake_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x006005D0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006006B0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00607410 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00607490 );
    virtual ~zCEarthquake()                                             zCall( 0x00607340 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x00607350 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x006073B0 );

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

    void zCPFXControler_OnInit()                                        zCall( 0x00607B10 );
    zCPFXControler()                                                    zInit( zCPFXControler_OnInit() );
    zCParticleFX* GetPFX()                                              zCall( 0x00607BF0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x006008C0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006009A0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00607D20 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00607D80 );
    virtual ~zCPFXControler()                                           zCall( 0x00607B90 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x00607C70 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x00607CF0 );
    virtual void PostLoad()                                             zCall( 0x00607C50 );

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

    void zCTouchDamage_OnInit()                                         zCall( 0x00608E20 );
    zCTouchDamage()                                                     zInit( zCTouchDamage_OnInit() );
    void ProcessToucher( zCVob* )                                       zCall( 0x006091B0 );
    int TestCollType( zCVob* )                                          zCall( 0x006092C0 );
    void FireDamageMessage( zCVob* )                                    zCall( 0x00609540 );
    void SetVobProperties()                                             zCall( 0x00609830 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00600BB0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00600CD0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00609630 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00609700 );
    virtual ~zCTouchDamage()                                            zCall( 0x00608F00 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x00608F10 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x00609040 );
    virtual void OnTimer()                                              zCall( 0x00609060 );
    virtual void SetVisual( zCVisual* )                                 zCall( 0x006097E0 );
    virtual char const* GetDamageTypeArcEnum( unsigned long )           zCall( 0x006097C0 );

    // user API
    #include "zCTouchDamage.inl"
  };

  class zCVobStair : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobStair )

    zCVobStair() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x005FDEF0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005FDF90 );
    virtual ~zCVobStair()                                               zCall( 0x005FDFD0 );

    // user API
    #include "zCVobStair.inl"
  };

  class zCTouchAnimate : public zCEffect {
  public:
    zCLASS_DECLARATION( zCTouchAnimate )

    zSTRING touchSoundName;
    zCSoundFX* touchSound;

    void zCTouchAnimate_OnInit()                                        zCall( 0x00609870 );
    zCTouchAnimate()                                                    zInit( zCTouchAnimate_OnInit() );
    int IsTouching( zCVob* )                                            zCall( 0x00609D60 );
    void StartAni()                                                     zCall( 0x00609E30 );
    void StopAni()                                                      zCall( 0x0060A0B0 );
    int IsAniActive()                                                   zCall( 0x0060A0F0 );
    void SetVobProperties()                                             zCall( 0x0060A200 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00600EE0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00601000 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0060A130 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0060A140 );
    virtual ~zCTouchAnimate()                                           zCall( 0x00609950 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x00609A10 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x00609B70 );
    virtual void OnTick()                                               zCall( 0x00609B90 );
    virtual void SetVisual( zCVisual* )                                 zCall( 0x0060A1B0 );
    virtual zSTRING GetSoundName()                                      zCall( 0x00609FA0 );

    // user API
    #include "zCTouchAnimate.inl"
  };

  class zCTouchAnimateSound : public zCTouchAnimate {
  public:
    zCLASS_DECLARATION( zCTouchAnimateSound )

    zSTRING touchSoundName;

    void zCTouchAnimateSound_OnInit()                                   zCall( 0x0060A240 );
    zCTouchAnimateSound()                                               zInit( zCTouchAnimateSound_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00601210 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006013E0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0060A4D0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0060A500 );
    virtual ~zCTouchAnimateSound()                                      zCall( 0x0060A3D0 );
    virtual zSTRING GetSoundName()                                      zCall( 0x0060A590 );

    // user API
    #include "zCTouchAnimateSound.inl"
  };

  class zCVobAnimate : public zCEffect {
  public:
    zCLASS_DECLARATION( zCVobAnimate )

    char startOn;
    char isRunning;

    void zCVobAnimate_OnInit()                                          zCall( 0x0060A5E0 );
    zCVobAnimate()                                                      zInit( zCVobAnimate_OnInit() );
    void StartAni()                                                     zCall( 0x0060A700 );
    void StopAni()                                                      zCall( 0x0060A740 );
    static zCObject* _CreateNewInstance()                               zCall( 0x006015F0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006016D0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0060A7B0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0060A800 );
    virtual ~zCVobAnimate()                                             zCall( 0x0060A680 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x0060A750 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x0060A7A0 );
    virtual void SetVisual( zCVisual* )                                 zCall( 0x0060A690 );

    // user API
    #include "zCVobAnimate.inl"
  };

  class zCVobLensFlare : public zCEffect {
  public:
    zCLASS_DECLARATION( zCVobLensFlare )

    zCLensFlareFX* lensFlareFX;

    void zCVobLensFlare_OnInit()                                        zCall( 0x0060A8B0 );
    zCVobLensFlare()                                                    zInit( zCVobLensFlare_OnInit() );
    void SetLensFlareFXByName( zSTRING const& )                         zCall( 0x0060A990 );
    static zCObject* _CreateNewInstance()                               zCall( 0x006018E0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006019C0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0060A9E0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0060AAE0 );
    virtual ~zCVobLensFlare()                                           zCall( 0x0060A950 );
    virtual int __fastcall Render( zTRenderContext& )                   zCall( 0x0060A970 );

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
    void zCEventScreenFX_OnInit( zTEventScreenFXSubType, float, zCOLOR, float ) zCall( 0x0060ABD0 );
    zCEventScreenFX( zTEventScreenFXSubType a0, float a1, zCOLOR a2, float a3 ) zInit( zCEventScreenFX_OnInit( a0, a1, a2, a3 ));
    void Clear()                                                                zCall( 0x0060AC70 );
    static zCObject* _CreateNewInstance()                                       zCall( 0x00602710 );
    virtual zCClassDef* _GetClassDef() const                                    zCall( 0x00602800 );
    virtual void Archive( zCArchiver& )                                         zCall( 0x0060AF40 );
    virtual void Unarchive( zCArchiver& )                                       zCall( 0x0060AF90 );
    virtual ~zCEventScreenFX()                                                  zCall( 0x00602850 );
    virtual int MD_GetNumOfSubTypes()                                           zCall( 0x00602810 );
    virtual zSTRING MD_GetSubTypeString( int )                                  zCall( 0x0060ACA0 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()                 zCall( 0x0060AE90 );
    virtual float MD_GetMinTime()                                               zCall( 0x0060AEB0 );
    virtual void Pack( zCBuffer&, zCEventManager* )                             zCall( 0x0060AEC0 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                           zCall( 0x0060AF00 );

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

      zTScreenFXSet() {}

      // user API
      #include "zCVobScreenFX_zTScreenFXSet.inl"
    };

    zTScreenFXSet blend;
    zTScreenFXSet cinema;
    zTScreenFXSet fovMorph;
    zVEC2 fovSaved;
    zVEC2 fovSavedFirst;

    void zCVobScreenFX_OnInit()                                         zCall( 0x0060AFE0 );
    zCVobScreenFX()                                                     zInit( zCVobScreenFX_OnInit() );
    void StartEffect( float, zCOLOR, int, zTScreenFXSet& )              zCall( 0x0060B300 );
    zCOLOR CalcEffectColor( zTScreenFXSet& )                            zCall( 0x0060B390 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00601BD0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00601D20 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0060B6E0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0060B770 );
    virtual ~zCVobScreenFX()                                            zCall( 0x0060B0E0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x0060B0F0 );
    virtual void OnTick()                                               zCall( 0x0060B410 );

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

    void zCMessageFilter_OnInit()                                       zCall( 0x0060B810 );
    zCMessageFilter()                                                   zInit( zCMessageFilter_OnInit() );
    void ProcessMessage( zTMessageType, zCVob* )                        zCall( 0x0060B950 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005FE7D0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005FE8F0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0060BD20 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0060BD80 );
    virtual ~zCMessageFilter()                                          zCall( 0x0060B8F0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x0060BCE0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x0060BD00 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005FE900 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x005FE910 );

    // user API
    #include "zCMessageFilter.inl"
  };

  class zCTriggerUntouch : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCTriggerUntouch )

    zCTriggerUntouch() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x005FE3E0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005FE500 );
    virtual ~zCTriggerUntouch()                                         zCall( 0x005FE570 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x005FE520 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x005FE530 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005FE510 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x0060BE00 );

    // user API
    #include "zCTriggerUntouch.inl"
  };

  class zCTriggerWorldStart : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCTriggerWorldStart )

    char fireOnlyFirstTime;
    char hasFired;

    void zCTriggerWorldStart_OnInit()                                   zCall( 0x0060D630 );
    zCTriggerWorldStart()                                               zInit( zCTriggerWorldStart_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x005FF340 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005FF460 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0060D7B0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0060D810 );
    virtual ~zCTriggerWorldStart()                                      zCall( 0x0060D710 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x0060D790 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x005FF490 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005FF470 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x005FF480 );
    virtual void PostLoad()                                             zCall( 0x0060D770 );

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

    void zCCodeMaster_OnInit()                                          zCall( 0x0060BEE0 );
    zCCodeMaster()                                                      zInit( zCCodeMaster_OnInit() );
    void Init()                                                         zCall( 0x0060C240 );
    void Reset()                                                        zCall( 0x0060C3C0 );
    void FireTriggerSuccess( zCVob* )                                   zCall( 0x0060C410 );
    void FireTriggerFailure( zCVob* )                                   zCall( 0x0060C4F0 );
    int GetSlaveNr( zCVob* )                                            zCall( 0x0060C5D0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005FEB20 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005FED40 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0060C9F0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0060CD40 );
    virtual ~zCCodeMaster()                                             zCall( 0x0060C0D0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x0060C680 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x0060C880 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005FED60 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x005FED50 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x0060C980 );
    virtual zSTRING const* GetTriggerTarget( int ) const                zCall( 0x0060D070 );

    // user API
    #include "zCCodeMaster.inl"
  };

  class zCMoverControler : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCMoverControler )

    zCEventMover::zTEventMoverSubType moverMessage;
    int gotoFixedKeyframe;

    void zCMoverControler_OnInit()                                      zCall( 0x0060D0A0 );
    zCMoverControler()                                                  zInit( zCMoverControler_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x005FEFD0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005FF100 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0060D320 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0060D5D0 );
    virtual ~zCMoverControler()                                         zCall( 0x0060D190 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x0060D1F0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x005FF110 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005FF130 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x005FF120 );

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

} // namespace Gothic_I_Addon

#endif // __ZVOB_MISC_H__VER1__