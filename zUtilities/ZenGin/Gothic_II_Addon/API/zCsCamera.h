// Supported with union (c) 2018-2021 Union team

#ifndef __ZCS_CAMERA_H__VER3__
#define __ZCS_CAMERA_H__VER3__

#include "zVob.h"
#include "zKbSplines.h"
#include "zEventMan.h"
#include "zAiCamera.h"
#include "zAiCamera_Movement.h"

namespace Gothic_II_Addon {
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

  // sizeof 1DCh
  class zCCamTrj_KeyFrame : public zCVob {
  public:
    zCLASS_DECLARATION( zCCamTrj_KeyFrame )

    float time;                                 // sizeof 04h    offset 120h
    float angleRollDeg;                         // sizeof 04h    offset 124h
    float camFOVScale;                          // sizeof 04h    offset 128h
    zTCamTrj_KeyMotionType motionType;          // sizeof 04h    offset 12Ch
    zTCamTrj_KeyMotionType motionTypeFOV;       // sizeof 04h    offset 130h
    zTCamTrj_KeyMotionType motionTypeRoll;      // sizeof 04h    offset 134h
    zTCamTrj_KeyMotionType motionTypeTimeScale; // sizeof 04h    offset 138h
    int timeIsFixed;                            // sizeof 04h    offset 13Ch
    float tension;                              // sizeof 04h    offset 140h
    float bias;                                 // sizeof 04h    offset 144h
    float continuity;                           // sizeof 04h    offset 148h
    float timeScale;                            // sizeof 04h    offset 14Ch
    zMAT4 originalPose;                         // sizeof 40h    offset 150h
    zMAT4 actPose;                              // sizeof 40h    offset 190h
    int adjusted;                               // sizeof 04h    offset 1D0h
    zCCSCamera* cscam;                          // sizeof 04h    offset 1D4h
    zTCamTrj_KFType type;                       // sizeof 04h    offset 1D8h

    void zCCamTrj_KeyFrame_OnInit()                  zCall( 0x004BDE00 );
    zCCamTrj_KeyFrame()                              zInit( zCCamTrj_KeyFrame_OnInit() );
    void Changed()                                   zCall( 0x004BE390 );
    static zCObject* _CreateNewInstance()            zCall( 0x004C8180 );
    virtual zCClassDef* _GetClassDef() const         zCall( 0x004BDED0 );
    virtual void Archive( zCArchiver& )              zCall( 0x004BE100 );
    virtual void Unarchive( zCArchiver& )            zCall( 0x004BE250 );
    virtual ~zCCamTrj_KeyFrame()                     zCall( 0x004BDF10 );
    virtual void ThisVobAddedToWorld( zCWorld* )     zCall( 0x004BDF90 );
    virtual void ThisVobRemovedFromWorld( zCWorld* ) zCall( 0x004BDFA0 );

    // user API
    #include "zCCamTrj_KeyFrame.inl"
  };

  // sizeof 3Ch
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

    int key;                // sizeof 04h    offset 2Ch
    float time;             // sizeof 04h    offset 30h
    int isDeleted;          // sizeof 04h    offset 34h
    zTCamTrj_KFType kfType; // sizeof 04h    offset 38h

    void zCCSCamera_EventMsg_OnInit()                           zCall( 0x004C6C00 );
    void zCCSCamera_EventMsg_OnInit( zTCSCam_EvSubType )        zCall( 0x004C6D70 );
    zCCSCamera_EventMsg()                                       zInit( zCCSCamera_EventMsg_OnInit() );
    zCCSCamera_EventMsg( zTCSCam_EvSubType a0 )                 zInit( zCCSCamera_EventMsg_OnInit( a0 ));
    static zCObject* _CreateNewInstance()                       zCall( 0x004C78D0 );
    virtual zCClassDef* _GetClassDef() const                    zCall( 0x004C3A40 );
    virtual void Archive( zCArchiver& )                         zCall( 0x004C6EE0 );
    virtual void Unarchive( zCArchiver& )                       zCall( 0x004C6F70 );
    virtual ~zCCSCamera_EventMsg()                              zCall( 0x004C6ED0 );
    virtual int IsHighPriority()                                zCall( 0x004C3A70 );
    virtual int IsJob()                                         zCall( 0x004C3A50 );
    virtual void Delete()                                       zCall( 0x004C3A90 );
    virtual int IsDeleted()                                     zCall( 0x004C3A80 );
    virtual int MD_GetNumOfSubTypes()                           zCall( 0x004C7000 );
    virtual zSTRING MD_GetSubTypeString( int )                  zCall( 0x004C7010 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior() zCall( 0x004C3AA0 );
    virtual float MD_GetMinTime()                               zCall( 0x004C7220 );

    // user API
    #include "zCCSCamera_EventMsg.inl"
  };

  // sizeof 48h
  class zCCSCamera_EventMsgActivate : public zCEventMessage {
  public:
    zCLASS_DECLARATION( zCCSCamera_EventMsgActivate )

    enum zTCSCam_ActivateSubType {
      EV_DEACTIVATE,
      EV_SETCAMREFERENCE,
      EV_SETTARGETREFERENCE
    };

    zSTRING referenceName; // sizeof 14h    offset 2Ch
    int isDeleted;         // sizeof 04h    offset 40h
    zCVob* referenceVob;   // sizeof 04h    offset 44h

    zCCSCamera_EventMsgActivate() {}
    void zCCSCamera_EventMsgActivate_OnInit( zTCSCam_ActivateSubType ) zCall( 0x004B4160 );
    zCCSCamera_EventMsgActivate( zTCSCam_ActivateSubType a0 )          zInit( zCCSCamera_EventMsgActivate_OnInit( a0 ));
    static zCObject* _CreateNewInstance()                              zCall( 0x004C7C00 );
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x004021E0 );
    virtual void Archive( zCArchiver& )                                zCall( 0x004C7240 );
    virtual void Unarchive( zCArchiver& )                              zCall( 0x004C7270 );
    virtual ~zCCSCamera_EventMsgActivate()                             zCall( 0x00402240 );
    virtual void Delete()                                              zCall( 0x00402200 );
    virtual int IsDeleted()                                            zCall( 0x004021F0 );
    virtual int MD_GetNumOfSubTypes()                                  zCall( 0x004C7400 );
    virtual zSTRING MD_GetSubTypeString( int )                         zCall( 0x004C7410 );
    virtual zSTRING MD_GetVobRefName()                                 zCall( 0x004C7530 );
    virtual void MD_SetVobRefName( zSTRING const& )                    zCall( 0x004C7580 );
    virtual void MD_SetVobParam( zCVob* )                              zCall( 0x004C76C0 );

    // user API
    #include "zCCSCamera_EventMsgActivate.inl"
  };

  // sizeof 14DCh
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

    zTCamTrj_FOR camKeysFOR;                   // sizeof 04h    offset 120h
    zTCamTrj_FOR targetKeysFOR;                // sizeof 04h    offset 124h
    zTCamTrj_LoopMode loopMode;                // sizeof 04h    offset 128h
    zTSplLerpMode splLerpMode;                 // sizeof 04h    offset 12Ch
    int ignoreFORVobRotCam;                    // sizeof 04h    offset 130h
    int ignoreFORVobRotTarget;                 // sizeof 04h    offset 134h
    int adaptToSurroundings;                   // sizeof 04h    offset 138h
    int easeToFirstKey;                        // sizeof 04h    offset 13Ch
    int easeFromLastKey;                       // sizeof 04h    offset 140h
    float totalTime;                           // sizeof 04h    offset 144h
    zSTRING autoCamFocusVobName;               // sizeof 14h    offset 148h
    int autoCamPlayerMovable;                  // sizeof 04h    offset 15Ch
    int autoCamUntriggerOnLastKey;             // sizeof 04h    offset 160h
    float autoCamUntriggerOnLastKeyDelay;      // sizeof 04h    offset 164h
    zCVob* camKeysRefVob;                      // sizeof 04h    offset 168h
    zCVob* targetKeysRefVob;                   // sizeof 04h    offset 16Ch
    zCArray<zCEventMessage*> evMsgProcessList; // sizeof 0Ch    offset 170h
    zCArray<zCCamTrj_KeyFrame*>posKeys;        // sizeof 0Ch    offset 17Ch
    zCArray<zCCamTrj_KeyFrame*>targetKeys;     // sizeof 0Ch    offset 188h
    int paused;                                // sizeof 04h    offset 194h
    int hasBeenTriggered;                      // sizeof 04h    offset 198h
    int hasBeenUntriggered;                    // sizeof 04h    offset 19Ch
    int triggerQueued;                         // sizeof 04h    offset 1A0h
    zCVob* queuedVob;                          // sizeof 04h    offset 1A4h
    int keysPreProcessed;                      // sizeof 04h    offset 1A8h
    int started;                               // sizeof 04h    offset 1ACh
    int gotoTimeMode;                          // sizeof 04h    offset 1B0h
    int initialized;                           // sizeof 04h    offset 1B4h
    int easeToFirstKeyNotPossible;             // sizeof 04h    offset 1B8h
    int easeFromLastKeyNotPossible;            // sizeof 04h    offset 1BCh
    int autoCamPlayerMovable_BAK;              // sizeof 04h    offset 1C0h
    int autoAdjustTime;                        // sizeof 04h    offset 1C4h
    float avgFPS;                              // sizeof 04h    offset 1C8h
    int avgFPSNumFrames;                       // sizeof 04h    offset 1CCh
    float actTimeCam;                          // sizeof 04h    offset 1D0h
    float csTime;                              // sizeof 04h    offset 1D4h
    float unTriggerDelayTime;                  // sizeof 04h    offset 1D8h
    zMAT4 trafoCStoWS;                         // sizeof 40h    offset 1DCh
    float lerpDirSign;                         // sizeof 04h    offset 21Ch
    float timeToReach;                         // sizeof 04h    offset 220h
    float timeToReachScale;                    // sizeof 04h    offset 224h
    zTCamTrj_KFType camFOVSetBy;               // sizeof 04h    offset 228h
    zTCamTrj_KFType angleRollDegSetBy;         // sizeof 04h    offset 22Ch
    zTCamTrj_KFType globalTimeScaleSetBy;      // sizeof 04h    offset 230h
    int d_testCS;                              // sizeof 04h    offset 234h
    zCPose camRefVobPose;                      // sizeof 8E4h   offset 238h
    zCPose targetRefVobPose;                   // sizeof 8E4h   offset B1Ch
    zCKBSpline posSpl;                         // sizeof 24h    offset 1400h
    zCKBSpline targetSpl;                      // sizeof 24h    offset 1424h
    LerpFunc LerpFuncCam;                      // sizeof 04h    offset 1448h
    LerpFunc LerpFuncTarget;                   // sizeof 04h    offset 144Ch
    zMAT4 initialPoseCamRefVob;                // sizeof 40h    offset 1450h
    zMAT4 initialPoseTargetRefVob;             // sizeof 40h    offset 1490h
    zVEC3 actTargetFocus;                      // sizeof 0Ch    offset 14D0h

    void zCCSCamera_OnInit()                                                                      zCall( 0x004BE410 );
    zCCamTrj_KeyFrame* GetCamKey( int )                                                           zCall( 0x004B4250 );
    zCCamTrj_KeyFrame* GetTargetKey( int )                                                        zCall( 0x004B4270 );
    zCCSCamera()                                                                                  zInit( zCCSCamera_OnInit() );
    void InsertCamKey( zCCamTrj_KeyFrame* )                                                       zCall( 0x004BE9F0 );
    void InsertCamKeyAtPos( zCCamTrj_KeyFrame*, int )                                             zCall( 0x004BEB20 );
    void RemoveCamKey( zCCamTrj_KeyFrame* )                                                       zCall( 0x004BEC70 );
    void InsertTargetKey( zCCamTrj_KeyFrame* )                                                    zCall( 0x004BED40 );
    void InsertTargetKeyAtPos( zCCamTrj_KeyFrame*, int )                                          zCall( 0x004BEE70 );
    void RemoveTargetKey( zCCamTrj_KeyFrame* )                                                    zCall( 0x004BEFC0 );
    void Refresh()                                                                                zCall( 0x004BF090 );
    void Draw()                                                                                   zCall( 0x004BF1D0 );
    int EV_Play( zCCSCamera_EventMsg* )                                                           zCall( 0x004C0480 );
    int EV_Resume( zCCSCamera_EventMsg* )                                                         zCall( 0x004C0930 );
    int EV_Pause( zCCSCamera_EventMsg* )                                                          zCall( 0x004C0960 );
    int EV_Stop( zCCSCamera_EventMsg* )                                                           zCall( 0x004C0A20 );
    int EV_GotoKey( zCCSCamera_EventMsg* )                                                        zCall( 0x004C0F20 );
    int EV_SetDuration( zCCSCamera_EventMsg* )                                                    zCall( 0x004C13D0 );
    int EV_SetTime( zCCSCamera_EventMsg* )                                                        zCall( 0x004C1410 );
    int EV_Deactivate( zCCSCamera_EventMsgActivate* )                                             zCall( 0x004C1430 );
    int EV_SetCamReference( zCCSCamera_EventMsgActivate* )                                        zCall( 0x004C14B0 );
    int EV_SetTargetReference( zCCSCamera_EventMsgActivate* )                                     zCall( 0x004C1550 );
    void DeleteEvMsgOfSubType( int )                                                              zCall( 0x004C15F0 );
    void RecalcTrajectories()                                                                     zCall( 0x004C3D40 );
    int CheckAndResetAdjustedKeys()                                                               zCall( 0x004C3E80 );
    int CheckAndCorrectKey( int )                                                                 zCall( 0x004C3F40 );
    int CheckAndCorrectPose( zMAT4& )                                                             zCall( 0x004C3FF0 );
    void PreKFProcessing()                                                                        zCall( 0x004C41D0 );
    void PostKFProcessing()                                                                       zCall( 0x004C4FF0 );
    void AutoSetKeyTimes( zCArray<zCCamTrj_KeyFrame*>& )                                          zCall( 0x004C5020 );
    void Changed()                                                                                zCall( 0x004C5510 );
    void Initialize()                                                                             zCall( 0x004C5540 );
    void Reset()                                                                                  zCall( 0x004C6190 );
    void CalcPrevNextActKeyOfTime( float const&, zCArray<zCCamTrj_KeyFrame*>&, int&, int&, int& ) zCall( 0x004C6210 );
    int IsPointNearWall( zVEC3 const& )                                                           zCall( 0x004C6300 );
    zVEC3 GetPolyNearestPoint( zCPolygon*, zVEC3 const& ) const                                   zCall( 0x004C64A0 );
    int AdjustCenterSphere( zVEC3&, zVEC3 const&, float )                                         zCall( 0x004C69D0 );
    static zCVob* GetPlayerVob()                                                                  zCall( 0x004BE400 );
    static void SetDrawEnabled( int )                                                             zCall( 0x004C76D0 );
    static zCObject* _CreateNewInstance()                                                         zCall( 0x004C7F10 );
    virtual zCClassDef* _GetClassDef() const                                                      zCall( 0x004BE790 );
    virtual void Archive( zCArchiver& )                                                           zCall( 0x004BF9A0 );
    virtual void Unarchive( zCArchiver& )                                                         zCall( 0x004BFBC0 );
    virtual ~zCCSCamera()                                                                         zCall( 0x004BE7E0 );
    virtual void OnTrigger( zCVob*, zCVob* )                                                      zCall( 0x004C3270 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                                    zCall( 0x004C3AC0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                             zCall( 0x004C0180 );
    virtual void OnTick()                                                                         zCall( 0x004C1690 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                  zCall( 0x004C0000 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                              zCall( 0x004C0010 );

    // static properties
    static int& playing;
    static int& draw;
    static int& evaluateAvgFPS;

    // user API
    #include "zCCSCamera.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZCS_CAMERA_H__VER3__