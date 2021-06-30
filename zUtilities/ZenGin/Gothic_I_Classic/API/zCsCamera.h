// Supported with union (c) 2018 Union team

#ifndef __ZCS_CAMERA_H__VER0__
#define __ZCS_CAMERA_H__VER0__

#include "zVob.h"
#include "zKbSplines.h"
#include "zEventMan.h"
#include "zAiCamera.h"
#include "zAiCamera_Movement.h"

namespace Gothic_I_Classic {
  const float zCS_KEYTIME_UNDEF       = -1;
  const float zCSCAM_DEFAULT_DURATION = 10;

  enum zTCamTrj_KeyMotionType {
    zCAMTRJ_KEY_MOTION_UNDEF,
    zCAMTRJ_KEY_MOTION_SMOOTH,
    zCAMTRJ_KEY_MOTION_LINEAR,
    zCAMTRJ_KEY_MOTION_STEP,
    zCAMTRJ_KEY_MOTION_SLOW,
    zCAMTRJ_KEY_MOTION_FAST,
    zCAMTRJ_KEY_MOTION_CUSTOM
  };

  enum zTCamTrj_KFType {
    KF_UNDEF,
    KF_TARGET,
    KF_CAM
  };

  class zCCamTrj_KeyFrame : public zCVob {
  public:
    zCLASS_DECLARATION( zCCamTrj_KeyFrame )

    float time;
    float angleRollDeg;
    float camFOVScale;
    zTCamTrj_KeyMotionType motionType;
    zTCamTrj_KeyMotionType motionTypeFOV;
    zTCamTrj_KeyMotionType motionTypeRoll;
    zTCamTrj_KeyMotionType motionTypeTimeScale;
    int timeIsFixed;
    float tension;
    float bias;
    float continuity;
    float timeScale;
    zMAT4 originalPose;
    zMAT4 actPose;
    int adjusted;
    zCCSCamera* cscam;
    zTCamTrj_KFType type;

    void zCCamTrj_KeyFrame_OnInit()                                     zCall( 0x004B4AC0 );
    zCCamTrj_KeyFrame()                                                 zInit( zCCamTrj_KeyFrame_OnInit() );
    void Changed()                                                      zCall( 0x004B5050 );
    static zCObject* _CreateNewInstance()                               zCall( 0x004BED90 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x004B4B90 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x004B4DC0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x004B4F10 );
    virtual ~zCCamTrj_KeyFrame()                                        zCall( 0x004B4BD0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                        zCall( 0x004B4C50 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                    zCall( 0x004B4C60 );

    // user API
    #include "zCCamTrj_KeyFrame.inl"
  };

  class zCCSCamera_EventMsg : public zCEventMessage {
  public:
    zCLASS_DECLARATION( zCCSCamera_EventMsg )

    enum zTCSCam_EvSubType {
      EV_NOTHING,
      EV_PLAY,
      EV_PAUSE,
      EV_RESUME,
      EV_STOP,
      EV_GOTO_KEY,
      EV_SET_DURATION,
      EV_SET_TO_TIME
    };

    int key;
    float time;
    int isDeleted;
    zTCamTrj_KFType kfType;

    void zCCSCamera_EventMsg_OnInit()                                        zCall( 0x004BD7A0 );
    void zCCSCamera_EventMsg_OnInit( zTCSCam_EvSubType )                     zCall( 0x004BD910 );
    zCCSCamera_EventMsg()                                                    zInit( zCCSCamera_EventMsg_OnInit() );
    zCCSCamera_EventMsg( zTCSCam_EvSubType a0 )                              zInit( zCCSCamera_EventMsg_OnInit( a0 ));
    static zCObject* _CreateNewInstance()                                    zCall( 0x004BE470 );
    virtual zCClassDef* _GetClassDef() const                                 zCall( 0x004BA670 );
    virtual void Archive( zCArchiver& )                                      zCall( 0x004BDA80 );
    virtual void Unarchive( zCArchiver& )                                    zCall( 0x004BDB10 );
    virtual ~zCCSCamera_EventMsg()                                           zCall( 0x004BDA70 );
    virtual int IsHighPriority()                                             zCall( 0x004BA6A0 );
    virtual int IsJob()                                                      zCall( 0x004BA680 );
    virtual void Delete()                                                    zCall( 0x004BA6C0 );
    virtual int IsDeleted()                                                  zCall( 0x004BA6B0 );
    virtual int MD_GetNumOfSubTypes()                                        zCall( 0x004BDBA0 );
    virtual zSTRING MD_GetSubTypeString( int )                               zCall( 0x004BDBB0 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()              zCall( 0x004BA6D0 );
    virtual float MD_GetMinTime()                                            zCall( 0x004BDDC0 );

    // user API
    #include "zCCSCamera_EventMsg.inl"
  };

  class zCCSCamera_EventMsgActivate : public zCEventMessage {
  public:
    zCLASS_DECLARATION( zCCSCamera_EventMsgActivate )

    enum zTCSCam_ActivateSubType {
      EV_DEACTIVATE,
      EV_SETCAMREFERENCE,
      EV_SETTARGETREFERENCE
    };

    zSTRING referenceName;
    int isDeleted;
    zCVob* referenceVob;

    zCCSCamera_EventMsgActivate() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x004BE7E0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00402090 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x004BDDE0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x004BDE10 );
    virtual ~zCCSCamera_EventMsgActivate()                              zCall( 0x004020F0 );
    virtual void Delete()                                               zCall( 0x004020B0 );
    virtual int IsDeleted()                                             zCall( 0x004020A0 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x004BDFA0 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x004BDFB0 );
    virtual zSTRING MD_GetVobRefName()                                  zCall( 0x004BE0D0 );
    virtual void MD_SetVobRefName( zSTRING const& )                     zCall( 0x004BE120 );
    virtual void MD_SetVobParam( zCVob* )                               zCall( 0x004BE260 );

    // user API
    #include "zCCSCamera_EventMsgActivate.inl"
  };

  class zCCSCamera : public zCVob {
  public:
    zCLASS_DECLARATION( zCCSCamera )

    enum zTCamTrj_FOR {
      zCAMTRJ_KEY_FOR_WORLD,
      zCAMTRJ_KEY_FOR_OBJECT
    };

    enum zTCamTrj_LoopMode {
      zCAMTRJ_LOOPMODE_NONE,
      zCAMTRJ_LOOPMODE_RESTART,
      zCAMTRJ_LOOPMODE_PINGPONG
    };

    zTCamTrj_FOR camKeysFOR;
    zTCamTrj_FOR targetKeysFOR;
    zTCamTrj_LoopMode loopMode;
    zTSplLerpMode splLerpMode;
    int ignoreFORVobRotCam;
    int ignoreFORVobRotTarget;
    int adaptToSurroundings;
    int easeToFirstKey;
    int easeFromLastKey;
    float totalTime;
    zSTRING autoCamFocusVobName;
    int autoCamPlayerMovable;
    int autoCamUntriggerOnLastKey;
    float autoCamUntriggerOnLastKeyDelay;
    zCVob* camKeysRefVob;
    zCVob* targetKeysRefVob;
    zCArray<zCEventMessage*> evMsgProcessList;
    zCArray<zCCamTrj_KeyFrame*>posKeys;
    zCArray<zCCamTrj_KeyFrame*>targetKeys;
    int paused;
    int hasBeenTriggered;
    int hasBeenUntriggered;
    int triggerQueued;
    zCVob* queuedVob;
    int keysPreProcessed;
    int started;
    int gotoTimeMode;
    int initialized;
    int easeToFirstKeyNotPossible;
    int easeFromLastKeyNotPossible;
    int autoCamPlayerMovable_BAK;
    int autoAdjustTime;
    float avgFPS;
    int avgFPSNumFrames;
    float actTimeCam;
    float csTime;
    float unTriggerDelayTime;
    zMAT4 trafoCStoWS;
    float lerpDirSign;
    float timeToReach;
    float timeToReachScale;
    zTCamTrj_KFType camFOVSetBy;
    zTCamTrj_KFType angleRollDegSetBy;
    zTCamTrj_KFType globalTimeScaleSetBy;
    int d_testCS;
    zCPose camRefVobPose;
    zCPose targetRefVobPose;
    zCKBSpline posSpl;
    zCKBSpline targetSpl;
    LerpFunc LerpFuncCam;
    LerpFunc LerpFuncTarget;
    zMAT4 initialPoseCamRefVob;
    zMAT4 initialPoseTargetRefVob;
    zVEC3 actTargetFocus;

    void zCCSCamera_OnInit()                                                                      zCall( 0x004B50D0 );
    zCCamTrj_KeyFrame* GetCamKey( int )                                                           zCall( 0x004AB9A0 );
    zCCamTrj_KeyFrame* GetTargetKey( int )                                                        zCall( 0x004AB9C0 );
    zCCSCamera()                                                                                  zInit( zCCSCamera_OnInit() );
    void InsertCamKey( zCCamTrj_KeyFrame* )                                                       zCall( 0x004B56C0 );
    void InsertCamKeyAtPos( zCCamTrj_KeyFrame*, int )                                             zCall( 0x004B57F0 );
    void RemoveCamKey( zCCamTrj_KeyFrame* )                                                       zCall( 0x004B5950 );
    void InsertTargetKey( zCCamTrj_KeyFrame* )                                                    zCall( 0x004B5A20 );
    void InsertTargetKeyAtPos( zCCamTrj_KeyFrame*, int )                                          zCall( 0x004B5B50 );
    void RemoveTargetKey( zCCamTrj_KeyFrame* )                                                    zCall( 0x004B5CB0 );
    void Refresh()                                                                                zCall( 0x004B5D80 );
    void Draw()                                                                                   zCall( 0x004B5EC0 );
    int EV_Play( zCCSCamera_EventMsg* )                                                           zCall( 0x004B7220 );
    int EV_Resume( zCCSCamera_EventMsg* )                                                         zCall( 0x004B76A0 );
    int EV_Pause( zCCSCamera_EventMsg* )                                                          zCall( 0x004B76D0 );
    int EV_Stop( zCCSCamera_EventMsg* )                                                           zCall( 0x004B7790 );
    int EV_GotoKey( zCCSCamera_EventMsg* )                                                        zCall( 0x004B7C00 );
    int EV_SetDuration( zCCSCamera_EventMsg* )                                                    zCall( 0x004B80D0 );
    int EV_SetTime( zCCSCamera_EventMsg* )                                                        zCall( 0x004B8110 );
    int EV_Deactivate( zCCSCamera_EventMsgActivate* )                                             zCall( 0x004B8130 );
    int EV_SetCamReference( zCCSCamera_EventMsgActivate* )                                        zCall( 0x004B81B0 );
    int EV_SetTargetReference( zCCSCamera_EventMsgActivate* )                                     zCall( 0x004B8250 );
    void DeleteEvMsgOfSubType( int )                                                              zCall( 0x004B82F0 );
    void RecalcTrajectories()                                                                     zCall( 0x004BA8D0 );
    int CheckAndResetAdjustedKeys()                                                               zCall( 0x004BAA10 );
    int CheckAndCorrectKey( int )                                                                 zCall( 0x004BAAD0 );
    int CheckAndCorrectPose( zMAT4& )                                                             zCall( 0x004BAB80 );
    void PreKFProcessing()                                                                        zCall( 0x004BAD60 );
    void PostKFProcessing()                                                                       zCall( 0x004BBC00 );
    void AutoSetKeyTimes( zCArray<zCCamTrj_KeyFrame*>& )                                          zCall( 0x004BBC30 );
    void Changed()                                                                                zCall( 0x004BC150 );
    void Initialize()                                                                             zCall( 0x004BC180 );
    void Reset()                                                                                  zCall( 0x004BCE80 );
    void CalcPrevNextActKeyOfTime( float const&, zCArray<zCCamTrj_KeyFrame*>&, int&, int&, int& ) zCall( 0x004BCF00 );
    int IsPointNearWall( zVEC3 const& )                                                           zCall( 0x004BCFF0 );
    zVEC3 GetPolyNearestPoint( zCPolygon*, zVEC3 const& ) const                                   zCall( 0x004BD190 );
    int AdjustCenterSphere( zVEC3&, zVEC3 const&, float )                                         zCall( 0x004BD570 );
    static zCVob* GetPlayerVob()                                                                  zCall( 0x004B50C0 );
    static void SetDrawEnabled( int )                                                             zCall( 0x004BE270 );
    static zCObject* _CreateNewInstance()                                                         zCall( 0x004BEB10 );
    virtual zCClassDef* _GetClassDef() const                                                      zCall( 0x004B5450 );
    virtual void Archive( zCArchiver& )                                                           zCall( 0x004B6710 );
    virtual void Unarchive( zCArchiver& )                                                         zCall( 0x004B6930 );
    virtual ~zCCSCamera()                                                                         zCall( 0x004B54A0 );
    virtual void OnTrigger( zCVob*, zCVob* )                                                      zCall( 0x004B9E20 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                                    zCall( 0x004BA6F0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                             zCall( 0x004B6F20 );
    virtual void OnTick()                                                                         zCall( 0x004B8390 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                  zCall( 0x004B6DA0 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                              zCall( 0x004B6DB0 );


    // static properties
    static int& playing;
    static int& draw;
    static int& evaluateAvgFPS;

    // user API
    #include "zCCSCamera.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZCS_CAMERA_H__VER0__