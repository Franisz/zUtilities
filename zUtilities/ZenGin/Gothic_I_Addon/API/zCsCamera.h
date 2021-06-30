// Supported with union (c) 2018 Union team

#ifndef __ZCS_CAMERA_H__VER1__
#define __ZCS_CAMERA_H__VER1__

#include "zVob.h"
#include "zKbSplines.h"
#include "zEventMan.h"
#include "zAiCamera.h"
#include "zAiCamera_Movement.h"

namespace Gothic_I_Addon {
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

    void zCCamTrj_KeyFrame_OnInit()                                     zCall( 0x004C3CB0 );
    zCCamTrj_KeyFrame()                                                 zInit( zCCamTrj_KeyFrame_OnInit() );
    void Changed()                                                      zCall( 0x004C4240 );
    static zCObject* _CreateNewInstance()                               zCall( 0x004CE4A0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x004C3D80 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x004C3FB0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x004C4100 );
    virtual ~zCCamTrj_KeyFrame()                                        zCall( 0x004C3DC0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                        zCall( 0x004C3E40 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                    zCall( 0x004C3E50 );

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

    void zCCSCamera_EventMsg_OnInit()                                        zCall( 0x004CCE70 );
    void zCCSCamera_EventMsg_OnInit( zTCSCam_EvSubType )                     zCall( 0x004CCFE0 );
    zCCSCamera_EventMsg()                                                    zInit( zCCSCamera_EventMsg_OnInit() );
    zCCSCamera_EventMsg( zTCSCam_EvSubType a0 )                              zInit( zCCSCamera_EventMsg_OnInit( a0 ));
    static zCObject* _CreateNewInstance()                                    zCall( 0x004CDB60 );
    virtual zCClassDef* _GetClassDef() const                                 zCall( 0x004C99E0 );
    virtual void Archive( zCArchiver& )                                      zCall( 0x004CD150 );
    virtual void Unarchive( zCArchiver& )                                    zCall( 0x004CD1E0 );
    virtual ~zCCSCamera_EventMsg()                                           zCall( 0x004CD140 );
    virtual int IsHighPriority()                                             zCall( 0x004C9A10 );
    virtual int IsJob()                                                      zCall( 0x004C99F0 );
    virtual void Delete()                                                    zCall( 0x004C9A30 );
    virtual int IsDeleted()                                                  zCall( 0x004C9A20 );
    virtual int MD_GetNumOfSubTypes()                                        zCall( 0x004CD270 );
    virtual zSTRING MD_GetSubTypeString( int )                               zCall( 0x004CD280 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()              zCall( 0x004C9A40 );
    virtual float MD_GetMinTime()                                            zCall( 0x004CD490 );

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
    static zCObject* _CreateNewInstance()                               zCall( 0x004CDED0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x004024C0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x004CD4B0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x004CD4E0 );
    virtual ~zCCSCamera_EventMsgActivate()                              zCall( 0x00402520 );
    virtual void Delete()                                               zCall( 0x004024E0 );
    virtual int IsDeleted()                                             zCall( 0x004024D0 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x004CD670 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x004CD680 );
    virtual zSTRING MD_GetVobRefName()                                  zCall( 0x004CD7B0 );
    virtual void MD_SetVobRefName( zSTRING const& )                     zCall( 0x004CD800 );
    virtual void MD_SetVobParam( zCVob* )                               zCall( 0x004CD940 );

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

    void zCCSCamera_OnInit()                                                                      zCall( 0x004C42C0 );
    zCCamTrj_KeyFrame* GetCamKey( int )                                                           zCall( 0x004B9890 );
    zCCamTrj_KeyFrame* GetTargetKey( int )                                                        zCall( 0x004B98B0 );
    zCCSCamera()                                                                                  zInit( zCCSCamera_OnInit() );
    void InsertCamKey( zCCamTrj_KeyFrame* )                                                       zCall( 0x004C48B0 );
    void InsertCamKeyAtPos( zCCamTrj_KeyFrame*, int )                                             zCall( 0x004C49E0 );
    void RemoveCamKey( zCCamTrj_KeyFrame* )                                                       zCall( 0x004C4B40 );
    void InsertTargetKey( zCCamTrj_KeyFrame* )                                                    zCall( 0x004C4C10 );
    void InsertTargetKeyAtPos( zCCamTrj_KeyFrame*, int )                                          zCall( 0x004C4D40 );
    void RemoveTargetKey( zCCamTrj_KeyFrame* )                                                    zCall( 0x004C4EA0 );
    void Refresh()                                                                                zCall( 0x004C4F70 );
    void Draw()                                                                                   zCall( 0x004C50B0 );
    int EV_Play( zCCSCamera_EventMsg* )                                                           zCall( 0x004C6440 );
    int EV_Resume( zCCSCamera_EventMsg* )                                                         zCall( 0x004C68F0 );
    int EV_Pause( zCCSCamera_EventMsg* )                                                          zCall( 0x004C6920 );
    int EV_Stop( zCCSCamera_EventMsg* )                                                           zCall( 0x004C6A20 );
    int EV_GotoKey( zCCSCamera_EventMsg* )                                                        zCall( 0x004C6EC0 );
    int EV_SetDuration( zCCSCamera_EventMsg* )                                                    zCall( 0x004C73C0 );
    int EV_SetTime( zCCSCamera_EventMsg* )                                                        zCall( 0x004C7400 );
    int EV_Deactivate( zCCSCamera_EventMsgActivate* )                                             zCall( 0x004C7420 );
    int EV_SetCamReference( zCCSCamera_EventMsgActivate* )                                        zCall( 0x004C74A0 );
    int EV_SetTargetReference( zCCSCamera_EventMsgActivate* )                                     zCall( 0x004C7550 );
    void DeleteEvMsgOfSubType( int )                                                              zCall( 0x004C7600 );
    void RecalcTrajectories()                                                                     zCall( 0x004C9C80 );
    int CheckAndResetAdjustedKeys()                                                               zCall( 0x004C9DF0 );
    int CheckAndCorrectKey( int )                                                                 zCall( 0x004C9EE0 );
    int CheckAndCorrectPose( zMAT4& )                                                             zCall( 0x004C9FB0 );
    void PreKFProcessing()                                                                        zCall( 0x004CA250 );
    void PostKFProcessing()                                                                       zCall( 0x004CB0F0 );
    void AutoSetKeyTimes( zCArray<zCCamTrj_KeyFrame*>& )                                          zCall( 0x004CB120 );
    void Changed()                                                                                zCall( 0x004CB650 );
    void Initialize()                                                                             zCall( 0x004CB680 );
    void Reset()                                                                                  zCall( 0x004CC3D0 );
    void CalcPrevNextActKeyOfTime( float const&, zCArray<zCCamTrj_KeyFrame*>&, int&, int&, int& ) zCall( 0x004CC450 );
    int IsPointNearWall( zVEC3 const& )                                                           zCall( 0x004CC530 );
    zVEC3 GetPolyNearestPoint( zCPolygon*, zVEC3 const& ) const                                   zCall( 0x004CC740 );
    int AdjustCenterSphere( zVEC3&, zVEC3 const&, float )                                         zCall( 0x004CCBB0 );
    static zCVob* GetPlayerVob()                                                                  zCall( 0x004C42B0 );
    static void SetDrawEnabled( int )                                                             zCall( 0x004CD950 );
    static zCObject* _CreateNewInstance()                                                         zCall( 0x004CE210 );
    virtual zCClassDef* _GetClassDef() const                                                      zCall( 0x004C4640 );
    virtual void Archive( zCArchiver& )                                                           zCall( 0x004C5910 );
    virtual void Unarchive( zCArchiver& )                                                         zCall( 0x004C5B20 );
    virtual ~zCCSCamera()                                                                         zCall( 0x004C4690 );
    virtual void OnTrigger( zCVob*, zCVob* )                                                      zCall( 0x004C9170 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                                    zCall( 0x004C9A60 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                             zCall( 0x004C6120 );
    virtual void OnTick()                                                                         zCall( 0x004C76A0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                  zCall( 0x004C5F90 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                              zCall( 0x004C5FA0 );


    // static properties
    static int& playing;
    static int& draw;
    static int& evaluateAvgFPS;

    // user API
    #include "zCCSCamera.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZCS_CAMERA_H__VER1__