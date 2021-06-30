// Supported with union (c) 2018 Union team

#ifndef __ZCS_CAMERA_H__VER2__
#define __ZCS_CAMERA_H__VER2__

#include "zVob.h"
#include "zKbSplines.h"
#include "zEventMan.h"
#include "zAiCamera.h"
#include "zAiCamera_Movement.h"

namespace Gothic_II_Classic {
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

    void zCCamTrj_KeyFrame_OnInit()                  zCall( 0x004BB890 );
    zCCamTrj_KeyFrame()                              zInit( zCCamTrj_KeyFrame_OnInit() );
    void Changed()                                   zCall( 0x004BBE20 );
    static zCObject* _CreateNewInstance()            zCall( 0x004C5C10 );
    virtual zCClassDef* _GetClassDef() const         zCall( 0x004BB960 );
    virtual void Archive( zCArchiver& )              zCall( 0x004BBB90 );
    virtual void Unarchive( zCArchiver& )            zCall( 0x004BBCE0 );
    virtual ~zCCamTrj_KeyFrame()                     zCall( 0x004BB9A0 );
    virtual void ThisVobAddedToWorld( zCWorld* )     zCall( 0x004BBA20 );
    virtual void ThisVobRemovedFromWorld( zCWorld* ) zCall( 0x004BBA30 );

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

    void zCCSCamera_EventMsg_OnInit()                           zCall( 0x004C4690 );
    void zCCSCamera_EventMsg_OnInit( zTCSCam_EvSubType )        zCall( 0x004C4800 );
    zCCSCamera_EventMsg()                                       zInit( zCCSCamera_EventMsg_OnInit() );
    zCCSCamera_EventMsg( zTCSCam_EvSubType a0 )                 zInit( zCCSCamera_EventMsg_OnInit( a0 ));
    static zCObject* _CreateNewInstance()                       zCall( 0x004C5360 );
    virtual zCClassDef* _GetClassDef() const                    zCall( 0x004C14D0 );
    virtual void Archive( zCArchiver& )                         zCall( 0x004C4970 );
    virtual void Unarchive( zCArchiver& )                       zCall( 0x004C4A00 );
    virtual ~zCCSCamera_EventMsg()                              zCall( 0x004C4960 );
    virtual int IsHighPriority()                                zCall( 0x004C1500 );
    virtual int IsJob()                                         zCall( 0x004C14E0 );
    virtual void Delete()                                       zCall( 0x004C1520 );
    virtual int IsDeleted()                                     zCall( 0x004C1510 );
    virtual int MD_GetNumOfSubTypes()                           zCall( 0x004C4A90 );
    virtual zSTRING MD_GetSubTypeString( int )                  zCall( 0x004C4AA0 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior() zCall( 0x004C1530 );
    virtual float MD_GetMinTime()                               zCall( 0x004C4CB0 );

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
    void zCCSCamera_EventMsgActivate_OnInit( zTCSCam_ActivateSubType ) zCall( 0x004B1C30 );
    zCCSCamera_EventMsgActivate( zTCSCam_ActivateSubType a0 )          zInit( zCCSCamera_EventMsgActivate_OnInit( a0 ));
    static zCObject* _CreateNewInstance()                              zCall( 0x004C5690 );
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x004021E0 );
    virtual void Archive( zCArchiver& )                                zCall( 0x004C4CD0 );
    virtual void Unarchive( zCArchiver& )                              zCall( 0x004C4D00 );
    virtual ~zCCSCamera_EventMsgActivate()                             zCall( 0x00402240 );
    virtual void Delete()                                              zCall( 0x00402200 );
    virtual int IsDeleted()                                            zCall( 0x004021F0 );
    virtual int MD_GetNumOfSubTypes()                                  zCall( 0x004C4E90 );
    virtual zSTRING MD_GetSubTypeString( int )                         zCall( 0x004C4EA0 );
    virtual zSTRING MD_GetVobRefName()                                 zCall( 0x004C4FC0 );
    virtual void MD_SetVobRefName( zSTRING const& )                    zCall( 0x004C5010 );
    virtual void MD_SetVobParam( zCVob* )                              zCall( 0x004C5150 );

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

    void zCCSCamera_OnInit()                                                                      zCall( 0x004BBEA0 );
    zCCamTrj_KeyFrame* GetCamKey( int )                                                           zCall( 0x004B1D20 );
    zCCamTrj_KeyFrame* GetTargetKey( int )                                                        zCall( 0x004B1D40 );
    zCCSCamera()                                                                                  zInit( zCCSCamera_OnInit() );
    void InsertCamKey( zCCamTrj_KeyFrame* )                                                       zCall( 0x004BC480 );
    void InsertCamKeyAtPos( zCCamTrj_KeyFrame*, int )                                             zCall( 0x004BC5B0 );
    void RemoveCamKey( zCCamTrj_KeyFrame* )                                                       zCall( 0x004BC700 );
    void InsertTargetKey( zCCamTrj_KeyFrame* )                                                    zCall( 0x004BC7D0 );
    void InsertTargetKeyAtPos( zCCamTrj_KeyFrame*, int )                                          zCall( 0x004BC900 );
    void RemoveTargetKey( zCCamTrj_KeyFrame* )                                                    zCall( 0x004BCA50 );
    void Refresh()                                                                                zCall( 0x004BCB20 );
    void Draw()                                                                                   zCall( 0x004BCC60 );
    int EV_Play( zCCSCamera_EventMsg* )                                                           zCall( 0x004BDF10 );
    int EV_Resume( zCCSCamera_EventMsg* )                                                         zCall( 0x004BE3C0 );
    int EV_Pause( zCCSCamera_EventMsg* )                                                          zCall( 0x004BE3F0 );
    int EV_Stop( zCCSCamera_EventMsg* )                                                           zCall( 0x004BE4B0 );
    int EV_GotoKey( zCCSCamera_EventMsg* )                                                        zCall( 0x004BE9B0 );
    int EV_SetDuration( zCCSCamera_EventMsg* )                                                    zCall( 0x004BEE60 );
    int EV_SetTime( zCCSCamera_EventMsg* )                                                        zCall( 0x004BEEA0 );
    int EV_Deactivate( zCCSCamera_EventMsgActivate* )                                             zCall( 0x004BEEC0 );
    int EV_SetCamReference( zCCSCamera_EventMsgActivate* )                                        zCall( 0x004BEF40 );
    int EV_SetTargetReference( zCCSCamera_EventMsgActivate* )                                     zCall( 0x004BEFE0 );
    void DeleteEvMsgOfSubType( int )                                                              zCall( 0x004BF080 );
    void RecalcTrajectories()                                                                     zCall( 0x004C17D0 );
    int CheckAndResetAdjustedKeys()                                                               zCall( 0x004C1910 );
    int CheckAndCorrectKey( int )                                                                 zCall( 0x004C19D0 );
    int CheckAndCorrectPose( zMAT4& )                                                             zCall( 0x004C1A80 );
    void PreKFProcessing()                                                                        zCall( 0x004C1C60 );
    void PostKFProcessing()                                                                       zCall( 0x004C2A80 );
    void AutoSetKeyTimes( zCArray<zCCamTrj_KeyFrame*>& )                                          zCall( 0x004C2AB0 );
    void Changed()                                                                                zCall( 0x004C2FA0 );
    void Initialize()                                                                             zCall( 0x004C2FD0 );
    void Reset()                                                                                  zCall( 0x004C3C20 );
    void CalcPrevNextActKeyOfTime( float const&, zCArray<zCCamTrj_KeyFrame*>&, int&, int&, int& ) zCall( 0x004C3CA0 );
    int IsPointNearWall( zVEC3 const& )                                                           zCall( 0x004C3D90 );
    zVEC3 GetPolyNearestPoint( zCPolygon*, zVEC3 const& ) const                                   zCall( 0x004C3F30 );
    int AdjustCenterSphere( zVEC3&, zVEC3 const&, float )                                         zCall( 0x004C4460 );
    static zCVob* GetPlayerVob()                                                                  zCall( 0x004BBE90 );
    static void SetDrawEnabled( int )                                                             zCall( 0x004C5160 );
    static zCObject* _CreateNewInstance()                                                         zCall( 0x004C59A0 );
    virtual zCClassDef* _GetClassDef() const                                                      zCall( 0x004BC220 );
    virtual void Archive( zCArchiver& )                                                           zCall( 0x004BD430 );
    virtual void Unarchive( zCArchiver& )                                                         zCall( 0x004BD650 );
    virtual ~zCCSCamera()                                                                         zCall( 0x004BC270 );
    virtual void OnTrigger( zCVob*, zCVob* )                                                      zCall( 0x004C0D00 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                                    zCall( 0x004C1550 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                             zCall( 0x004BDC10 );
    virtual void OnTick()                                                                         zCall( 0x004BF120 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                  zCall( 0x004BDA90 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                              zCall( 0x004BDAA0 );

    // static properties
    static int& playing;
    static int& draw;
    static int& evaluateAvgFPS;

    // user API
    #include "zCCSCamera.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZCS_CAMERA_H__VER2__