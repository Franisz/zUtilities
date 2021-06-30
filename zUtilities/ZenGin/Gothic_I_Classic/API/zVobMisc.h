// Supported with union (c) 2018 Union team

#ifndef __ZVOB_MISC_H__VER0__
#define __ZVOB_MISC_H__VER0__

namespace Gothic_I_Classic {
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
    static zCObject* _CreateNewInstance()                               zCall( 0x005E2060 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E21F0 );
    virtual ~zCEventCommon()                                            zCall( 0x005E2250 );
    virtual int IsNetRelevant()                                         zCall( 0x005E2210 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x005E2200 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x005E2970 );

    // user API
    #include "zCEventCommon.inl"
  };

  class zCTriggerBase : public zCVob {
  public:
    zCLASS_DECLARATION( zCTriggerBase )

    zSTRING triggerTarget;

    void zCTriggerBase_OnInit()                          zCall( 0x005E2C80 );
    zCTriggerBase()                                      zInit( zCTriggerBase_OnInit() );
    virtual zCClassDef* _GetClassDef() const             zCall( 0x005DE760 );
    virtual void Archive( zCArchiver& )                  zCall( 0x005E2FD0 );
    virtual void Unarchive( zCArchiver& )                zCall( 0x005E3000 );
    virtual ~zCTriggerBase()                             zCall( 0x005DEFD0 );
    virtual void OnTrigger( zCVob*, zCVob* )             zCall( 0x005E2E90 );
    virtual void OnUntrigger( zCVob*, zCVob* )           zCall( 0x005E2F30 );
    virtual void OnTouch( zCVob* )                       zCall( 0x005E2D50 );
    virtual void OnUntouch( zCVob* )                     zCall( 0x005E2DF0 );
    virtual zSTRING const* GetTriggerTarget( int ) const zCall( 0x004041B0 );

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

    void zCTrigger_OnInit()                                             zCall( 0x005E3030 );
    zSTRING GetTriggerTarget() const                                    zCall( 0x00404860 );
    zCTrigger()                                                         zInit( zCTrigger_OnInit() );
    void ClearStateInternals()                                          zCall( 0x005E3260 );
    void TriggerTargetPost()                                            zCall( 0x005E3630 );
    void ActivateTrigger( zCVob* )                                      zCall( 0x005E3660 );
    void DeactivateTrigger( zCVob* )                                    zCall( 0x005E3740 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005DF8C0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E3220 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005E3970 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005E3BE0 );
    virtual ~zCTrigger()                                                zCall( 0x005E32B0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x005E3770 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x005E3790 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005E37D0 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x005E37F0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )   zCall( 0x005E3830 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x005E3870 );
    virtual void OnTimer()                                              zCall( 0x005E38E0 );
    virtual void TriggerTarget( zCVob* )                                zCall( 0x005E34D0 );
    virtual void UntriggerTarget( zCVob* )                              zCall( 0x005E3580 );
    virtual int CanBeActivatedNow( zCVob* )                             zCall( 0x005E33B0 );

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
    static zCObject* _CreateNewInstance()                               zCall( 0x005E2440 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E25D0 );
    virtual ~zCEventMover()                                             zCall( 0x005E2630 );
    virtual int IsNetRelevant()                                         zCall( 0x005E25F0 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x005E25E0 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x005E2AD0 );

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

    void zCMover_OnInit()                                               zCall( 0x005E3E90 );
    zCMover()                                                           zInit( zCMover_OnInit() );
    void ClearStateInternals()                                          zCall( 0x005E40B0 );
    void UpdateInternals()                                              zCall( 0x005E43D0 );
    void AdvanceKeyframe_KF()                                           zCall( 0x005E4530 );
    void SetToKeyframe_KF( float )                                      zCall( 0x005E4560 );
    void InterpolateKeyframes_KF()                                      zCall( 0x005E4A60 );
    void AdvanceMover()                                                 zCall( 0x005E4E80 );
    void SetToKeyframe( float, float )                                  zCall( 0x005E5160 );
    void InvertMovement()                                               zCall( 0x005E53D0 );
    void StartMovingSound()                                             zCall( 0x005E5630 );
    void MoveToKeyframe( int )                                          zCall( 0x005E56A0 );
    void DoOpen()                                                       zCall( 0x005E5710 );
    void FinishedOpening()                                              zCall( 0x005E57C0 );
    void DoClose()                                                      zCall( 0x005E5840 );
    void FinishedClosing()                                              zCall( 0x005E5900 );
    void Unlock( zCVob* )                                               zCall( 0x005E5950 );
    void Lock( zCVob* )                                                 zCall( 0x005E5B20 );
    int IsKeyToThisMover( zCVob* )                                      zCall( 0x005E5CF0 );
    void TriggerMover( zCVob* )                                         zCall( 0x005E5D80 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005DFF90 );
    static zTMov_Keyframe GetKeyframe( zCVob* )                         zCall( 0x005E4450 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E4070 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005E68B0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005E6B60 );
    virtual ~zCMover()                                                  zCall( 0x005E4170 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x005E6150 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x005E6240 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005E6410 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )   zCall( 0x005E64D0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x005E6520 );
    virtual void OnTick()                                               zCall( 0x005E6050 );
    virtual void PostLoad()                                             zCall( 0x005E68A0 );
    virtual int CanThisCollideWith( zCVob* )                            zCall( 0x005E4360 );
    virtual void SetVisual( zCVisual* )                                 zCall( 0x005E5470 );

    // user API
    #include "zCMover.inl"
  };

  class zCTriggerTeleport : public zCTrigger {
  public:
    zCLASS_DECLARATION( zCTriggerTeleport )

    zSTRING teleportSoundName;
    zCSoundFX* teleportSound;

    void zCTriggerTeleport_OnInit()                                     zCall( 0x005E71B0 );
    zCTriggerTeleport()                                                 zInit( zCTriggerTeleport_OnInit() );
    void DoTeleport( zCVob* )                                           zCall( 0x005E74D0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005E0210 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E03B0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005E76E0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005E7710 );
    virtual ~zCTriggerTeleport()                                        zCall( 0x005E7360 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x005E76C0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x005E76D0 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005E76B0 );

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

    void zCTriggerList_OnInit()                                         zCall( 0x005E7B50 );
    zCTriggerList()                                                     zInit( zCTriggerList_OnInit() );
    void Init()                                                         zCall( 0x005E7E00 );
    void TriggerActTarget( zCVob* )                                     zCall( 0x005E7F30 );
    int ProcessActTarget( zCVob* )                                      zCall( 0x005E8000 );
    void FinishActivation()                                             zCall( 0x005E8090 );
    void DoTriggering( zCVob* )                                         zCall( 0x005E8190 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005DFB40 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005DFD90 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005E8480 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005E8710 );
    virtual ~zCTriggerList()                                            zCall( 0x005E7CF0 );
    virtual void OnTimer()                                              zCall( 0x005E8100 );
    virtual zSTRING const* GetTriggerTarget( int ) const                zCall( 0x005E7F10 );
    virtual void TriggerTarget( zCVob* )                                zCall( 0x005E8450 );
    virtual void UntriggerTarget( zCVob* )                              zCall( 0x005E8460 );

    // user API
    #include "zCTriggerList.inl"
  };

  class zCEffect : public zCVob {
  public:
    zCLASS_DECLARATION( zCEffect )

    zCEffect() {}
    virtual zCClassDef* _GetClassDef() const zCall( 0x00482510 );
    virtual ~zCEffect()                      zCall( 0x004827E0 );

    // user API
    #include "zCEffect.inl"
  };

  class zCEarthquake : public zCEffect {
  public:
    zCLASS_DECLARATION( zCEarthquake )

    float radiusSquare;
    float timeMSec;
    zVEC3 amplitude;

    void zCEarthquake_OnInit()                                          zCall( 0x005E6F30 );
    zCEarthquake()                                                      zInit( zCEarthquake_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x005E0790 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E0870 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005E70C0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005E7140 );
    virtual ~zCEarthquake()                                             zCall( 0x005E7010 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x005E7020 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x005E7070 );

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

    void zCPFXControler_OnInit()                                        zCall( 0x005E7780 );
    zCPFXControler()                                                    zInit( zCPFXControler_OnInit() );
    zCParticleFX* GetPFX()                                              zCall( 0x005E7860 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005E0A70 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E0B50 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005E7990 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005E79F0 );
    virtual ~zCPFXControler()                                           zCall( 0x005E7800 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x005E78E0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x005E7960 );
    virtual void PostLoad()                                             zCall( 0x005E78C0 );

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

    void zCTouchDamage_OnInit()                                         zCall( 0x005E89D0 );
    zCTouchDamage()                                                     zInit( zCTouchDamage_OnInit() );
    void ProcessToucher( zCVob* )                                       zCall( 0x005E8CC0 );
    int TestCollType( zCVob* )                                          zCall( 0x005E8D60 );
    void FireDamageMessage( zCVob* )                                    zCall( 0x005E8FC0 );
    void SetVobProperties()                                             zCall( 0x005E9250 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005E0D50 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E0E70 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005E9050 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005E9120 );
    virtual ~zCTouchDamage()                                            zCall( 0x005E8AB0 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005E8AC0 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x005E8BA0 );
    virtual void OnTimer()                                              zCall( 0x005E8BC0 );
    virtual void SetVisual( zCVisual* )                                 zCall( 0x005E9200 );
    virtual char const* GetDamageTypeArcEnum( unsigned long )           zCall( 0x005E91E0 );

    // user API
    #include "zCTouchDamage.inl"
  };

  class zCVobStair : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobStair )

    zCVobStair() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x005DE1B0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005DE250 );
    virtual ~zCVobStair()                                               zCall( 0x005DE290 );

    // user API
    #include "zCVobStair.inl"
  };

  class zCTouchAnimate : public zCEffect {
  public:
    zCLASS_DECLARATION( zCTouchAnimate )

    zSTRING touchSoundName;
    zCSoundFX* touchSound;

    void zCTouchAnimate_OnInit()                                        zCall( 0x005E9290 );
    zCTouchAnimate()                                                    zInit( zCTouchAnimate_OnInit() );
    int IsTouching( zCVob* )                                            zCall( 0x005E9740 );
    void StartAni()                                                     zCall( 0x005E9810 );
    void StopAni()                                                      zCall( 0x005E9A80 );
    int IsAniActive()                                                   zCall( 0x005E9AC0 );
    void SetVobProperties()                                             zCall( 0x005E9BD0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005E1070 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E1190 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005E9B00 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005E9B10 );
    virtual ~zCTouchAnimate()                                           zCall( 0x005E9370 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005E9430 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x005E9550 );
    virtual void OnTick()                                               zCall( 0x005E9570 );
    virtual void SetVisual( zCVisual* )                                 zCall( 0x005E9B80 );
    virtual zSTRING GetSoundName()                                      zCall( 0x005E9970 );

    // user API
    #include "zCTouchAnimate.inl"
  };

  class zCTouchAnimateSound : public zCTouchAnimate {
  public:
    zCLASS_DECLARATION( zCTouchAnimateSound )

    zSTRING touchSoundName;

    void zCTouchAnimateSound_OnInit()                                   zCall( 0x005E9C10 );
    zCTouchAnimateSound()                                               zInit( zCTouchAnimateSound_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x005E1390 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E1560 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005E9EB0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005E9EE0 );
    virtual ~zCTouchAnimateSound()                                      zCall( 0x005E9DB0 );
    virtual zSTRING GetSoundName()                                      zCall( 0x005E9F70 );

    // user API
    #include "zCTouchAnimateSound.inl"
  };

  class zCVobAnimate : public zCEffect {
  public:
    zCLASS_DECLARATION( zCVobAnimate )

    char startOn;
    char isRunning;

    void zCVobAnimate_OnInit()                                          zCall( 0x005E9FC0 );
    zCVobAnimate()                                                      zInit( zCVobAnimate_OnInit() );
    void StartAni()                                                     zCall( 0x005EA0F0 );
    void StopAni()                                                      zCall( 0x005EA130 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005E1760 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E1840 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005EA1A0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005EA1F0 );
    virtual ~zCVobAnimate()                                             zCall( 0x005EA070 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x005EA140 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x005EA190 );
    virtual void SetVisual( zCVisual* )                                 zCall( 0x005EA080 );

    // user API
    #include "zCVobAnimate.inl"
  };

  class zCVobLensFlare : public zCEffect {
  public:
    zCLASS_DECLARATION( zCVobLensFlare )

    zCLensFlareFX* lensFlareFX;

    void zCVobLensFlare_OnInit()                                        zCall( 0x005EA2A0 );
    zCVobLensFlare()                                                    zInit( zCVobLensFlare_OnInit() );
    void SetLensFlareFXByName( zSTRING const& )                         zCall( 0x005EA380 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005E1A40 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E1B20 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005EA3D0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005EA4C0 );
    virtual ~zCVobLensFlare()                                           zCall( 0x005EA340 );
    virtual int __fastcall Render( zTRenderContext& )                   zCall( 0x005EA360 );

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
    void zCEventScreenFX_OnInit( zTEventScreenFXSubType, float, zCOLOR, float ) zCall( 0x005EA5A0 );
    zCEventScreenFX( zTEventScreenFXSubType a0, float a1, zCOLOR a2, float a3 ) zInit( zCEventScreenFX_OnInit( a0, a1, a2, a3 ));
    void Clear()                                                                zCall( 0x005EA640 );
    static zCObject* _CreateNewInstance()                                       zCall( 0x005E2820 );
    virtual zCClassDef* _GetClassDef() const                                    zCall( 0x005E2910 );
    virtual void Archive( zCArchiver& )                                         zCall( 0x005EA910 );
    virtual void Unarchive( zCArchiver& )                                       zCall( 0x005EA960 );
    virtual ~zCEventScreenFX()                                                  zCall( 0x005E2960 );
    virtual int MD_GetNumOfSubTypes()                                           zCall( 0x005E2920 );
    virtual zSTRING MD_GetSubTypeString( int )                                  zCall( 0x005EA670 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()                 zCall( 0x005EA860 );
    virtual float MD_GetMinTime()                                               zCall( 0x005EA880 );
    virtual void Pack( zCBuffer&, zCEventManager* )                             zCall( 0x005EA890 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                           zCall( 0x005EA8D0 );

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

    void zCVobScreenFX_OnInit()                                         zCall( 0x005EA9B0 );
    zCVobScreenFX()                                                     zInit( zCVobScreenFX_OnInit() );
    void StartEffect( float, zCOLOR, int, zTScreenFXSet& )              zCall( 0x005EACB0 );
    zCOLOR CalcEffectColor( zTScreenFXSet& )                            zCall( 0x005EAD40 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005E1D20 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E1E70 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005EB0B0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005EB140 );
    virtual ~zCVobScreenFX()                                            zCall( 0x005EAAB0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x005EAAC0 );
    virtual void OnTick()                                               zCall( 0x005EADC0 );

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

    void zCMessageFilter_OnInit()                                       zCall( 0x005EB1E0 );
    zCMessageFilter()                                                   zInit( zCMessageFilter_OnInit() );
    void ProcessMessage( zTMessageType, zCVob* )                        zCall( 0x005EB320 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005DEA50 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005DEB70 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005EB700 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005EB760 );
    virtual ~zCMessageFilter()                                          zCall( 0x005EB2C0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x005EB6C0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x005EB6E0 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005DEB80 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x005DEB90 );

    // user API
    #include "zCMessageFilter.inl"
  };

  class zCTriggerUntouch : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCTriggerUntouch )

    zCTriggerUntouch() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x005DE670 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005DE790 );
    virtual ~zCTriggerUntouch()                                         zCall( 0x005DE800 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x005DE7B0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x005DE7C0 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005DE7A0 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x005EB7E0 );

    // user API
    #include "zCTriggerUntouch.inl"
  };

  class zCTriggerWorldStart : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCTriggerWorldStart )

    char fireOnlyFirstTime;
    char hasFired;

    void zCTriggerWorldStart_OnInit()                                   zCall( 0x005ECF70 );
    zCTriggerWorldStart()                                               zInit( zCTriggerWorldStart_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x005DF570 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005DF690 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005ED0F0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005ED150 );
    virtual ~zCTriggerWorldStart()                                      zCall( 0x005ED050 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x005ED0D0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x005DF6C0 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005DF6A0 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x005DF6B0 );
    virtual void PostLoad()                                             zCall( 0x005ED0B0 );

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

    void zCCodeMaster_OnInit()                                          zCall( 0x005EB8C0 );
    zCCodeMaster()                                                      zInit( zCCodeMaster_OnInit() );
    void Init()                                                         zCall( 0x005EBC00 );
    void Reset()                                                        zCall( 0x005EBD80 );
    void FireTriggerSuccess( zCVob* )                                   zCall( 0x005EBDD0 );
    void FireTriggerFailure( zCVob* )                                   zCall( 0x005EBEB0 );
    int GetSlaveNr( zCVob* )                                            zCall( 0x005EBF90 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005DED90 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005DEFA0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005EC3B0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005EC6D0 );
    virtual ~zCCodeMaster()                                             zCall( 0x005EBAA0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x005EC040 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x005EC240 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005DEFC0 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x005DEFB0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x005EC340 );
    virtual zSTRING const* GetTriggerTarget( int ) const                zCall( 0x005EC9D0 );

    // user API
    #include "zCCodeMaster.inl"
  };

  class zCMoverControler : public zCTriggerBase {
  public:
    zCLASS_DECLARATION( zCMoverControler )

    zCEventMover::zTEventMoverSubType moverMessage;
    int gotoFixedKeyframe;

    void zCMoverControler_OnInit()                                      zCall( 0x005ECA00 );
    zCMoverControler()                                                  zInit( zCMoverControler_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x005DF220 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005DF340 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005ECC80 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005ECF10 );
    virtual ~zCMoverControler()                                         zCall( 0x005ECAF0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x005ECB50 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x005DF350 );
    virtual void OnTouch( zCVob* )                                      zCall( 0x005DF370 );
    virtual void OnUntouch( zCVob* )                                    zCall( 0x005DF360 );

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

} // namespace Gothic_I_Classic

#endif // __ZVOB_MISC_H__VER0__