// Supported with union (c) 2018 Union team

#ifndef __ZAI_CAMERA__MOVEMENT_H__VER3__
#define __ZAI_CAMERA__MOVEMENT_H__VER3__

#include "zAiCamera.h"
#include "zAiCamera_Core.h"

namespace Gothic_II_Addon {
  const float PLAYER_FUTURE_POS_ADVANCE_TIME_SEC = 0.5f;
  const float SHOULDERCAM_AZI                    = 0;
  const float SHOULDERCAM_ELEV                   = 85;
  const float SHOULDERCAM_RANGE                  = 1.5f * 100;
  const float SHOULDERCAM_FOCUS_OFFSET_AT        = 200;
  const float SHOULDERCAM_FOCUS_OFFSET_UP        = 10;
  const int MAX_POS_SAMPLES_PLAYER               = 100;
  const int MAX_POS_SAMPLES_CAM                  = 100;
  const int MAX_POS_SAMPLES_FOCUS                = 100;
  const int NUM_MOV_SAMPLES_FOCUS                = 10;
  const int NUM_WAYPOINTS                        = 3;
  const float zWAYPOINT_SAMPLE_TIME              = 0.3f;
  const int NUM_ROT_SAMPLES                      = 20;

  enum zTAICamMsg {
    zPLAYER_MOVED_FORWARD  = 1 << 1,
    zPLAYER_MOVED_BACKWARD = 1 << 2,
    zPLAYER_MOVED_LEFT     = 1 << 3,
    zPLAYER_MOVED_RIGHT    = 1 << 4,
    zPLAYER_MOVED_UP       = 1 << 5,
    zPLAYER_MOVED_DOWN     = 1 << 6,
    zPLAYER_ROTATED_LEFT   = 1 << 7,
    zPLAYER_ROTATED_RIGHT  = 1 << 8,
    zPLAYER_ROTATED_UP     = 1 << 9,
    zPLAYER_ROTATED_DOWN   = 1 << 10,
    zPLAYER_MOVED          = 1 << 11,
    zPLAYER_STAND          = 1 << 12,
    zPLAYER_ROTATED        = 1 << 13,
    zPLAYER_ROT_NONE       = 1 << 14,
    zPLAYER_BEAMED         = 1 << 15
  };

  class zCMovementTracker {
  public:
    enum zTWayPoint {
      zWAYPOINT_PLAYER,
      zWAYPOINT_CAM,
      zWAYPOINT_HEAD,
      zWAYPOINT_HIP_LEFT,
      zWAYPOINT_HIP_RIGHT
    };

    unsigned long movement;
    zCArray<zCPositionKey*>targetKFList;
    float frameTime;
    zVEC3 sampledPlayerPos;
    zVEC3 sampledPlayerPosRing;
    zVEC3 playerPos;
    zVEC3 playerPosRing;
    zVEC3 POI_Player;
    zVEC3 camPos;
    zVEC3 camPosRing;
    zVEC3 oldSampledPlayerPosRing;
    zVEC3 oldSampledPlayerPos;
    zVEC3 offsetPos;
    zVEC3 playerFuturePos;
    float playerFuturePosDT;
    int numPreSamplesPlayerPos;
    int numSamplesCam;
    int numSamplesPlayer;
    zCPose rotPoseTargetFOR;
    zCPose headPose;
    zCPose sampledPlayerPose;
    zVEC3 wayPointHead[NUM_WAYPOINTS];
    zVEC3 wayPointHipLeft[NUM_WAYPOINTS];
    zVEC3 wayPointHipRight[NUM_WAYPOINTS];
    zVEC3 wayPointCam[NUM_WAYPOINTS];
    int actWayPointHead;
    int actWayPointHipLeft;
    int actWayPointHipRight;
    int actWayPointCam;
    float wayTimeHead;
    float wayTimeHipLeft;
    float wayTimeHipRight;
    float wayTimeCam;
    zVEC3 playerHead;
    zVEC3 playerHipLeft;
    zVEC3 playerHipRight;
    zVEC3 playerPosMovement;
    zVEC3 playerPosMovementRing;
    zVEC3 playerPosMovementLocal;
    zVEC3 playerPosMovementLocalCam;
    zVEC3 oldPlayerPosMovement;
    zVEC3 oldPlayerPos;
    zVEC3 oldCamPos;
    float oldDistToPlayer;
    float inertiaTrans;
    float inertiaHead;
    float inertiaRotTargetFOR;
    float inertiaTargetTrans;
    float inertiaTargetRot;
    float actAzi;
    float actElev;
    float distToPlayer;
    float playerVeloRange;
    float oldAzi;
    float oldElev;
    zMAT4 trafoWStoTS;
    zMAT4 trafoTStoWS;
    zMAT4 trafoWStoCS;
    zMAT4 trafoCStoWS;
    zMAT4 oldTrafoWStoTS;
    zMAT4 oldTrafoWStoCS;
    zMAT4 oldTrafoRotOffsetWStoCS;
    zMAT4 lastValidCamTrafo;
    zCQuat startRot;
    zCQuat endRot;
    zCQuat maxAziRot;
    zCQuat minAziRot;
    zCQuat idealRot;
    zCQuat idealRotTrans;
    zCQuat actRot;
    zCQuat idealRotLocal;
    zMAT4 initialPoseRotFreeze;
    float timeSamples;
    float standTimer;
    int standing;
    int rotate;
    int bMouseUsed;
    float playerAziSideSign;
    float playerElevSideSign;
    zCVob* target;
    zCVob* camVob;
    zCAICamera* camai;
    zCPathSearch* pathSearch;

    void zCMovementTracker_OnInit()                                           zCall( 0x004B4520 );
    zCMovementTracker()                                                       zInit( zCMovementTracker_OnInit() );
    ~zCMovementTracker()                                                      zCall( 0x004B4A20 );
    float GetAzimuth()                                                        zCall( 0x004B4AA0 );
    float GetElevation()                                                      zCall( 0x004B4AB0 );
    float GetAzimuth( zVEC3 const& )                                          zCall( 0x004B4AC0 );
    float GetElevation( zVEC3 const& )                                        zCall( 0x004B4E40 );
    float GetRange( zVEC3 const& )                                            zCall( 0x004B5070 );
    void SetAzimuth( float const& )                                           zCall( 0x004B50A0 );
    void SetElevation( float const& )                                         zCall( 0x004B50D0 );
    void SetRange( float const& )                                             zCall( 0x004B5100 );
    float GetRange()                                                          zCall( 0x004B51D0 );
    zVEC3 ApplyAziToPoint( float const&, zVEC3 const& )                       zCall( 0x004B5200 );
    zVEC3 ApplyElevToPoint( float const&, zVEC3 const& )                      zCall( 0x004B5400 );
    zVEC3 ApplyRangeToPoint( float const&, zVEC3 const& )                     zCall( 0x004B57A0 );
    zVEC3 GetRangePos( float const& )                                         zCall( 0x004B5860 );
    zVEC3 GetIdealRangePos()                                                  zCall( 0x004B5920 );
    float GetDistToIdealRange()                                               zCall( 0x004B59E0 );
    int IsIdealOrientation()                                                  zCall( 0x004B5AE0 );
    int IsIdealRange()                                                        zCall( 0x004B5B50 );
    void UpdateCamPos( zVEC3 const& )                                         zCall( 0x004B5C70 );
    void UpdatePlayerPos( zVEC3 const& )                                      zCall( 0x004B5D30 );
    void SetCamPos( zVEC3 const& )                                            zCall( 0x004B6100 );
    void CalcPlayerPose()                                                     zCall( 0x004B6150 );
    void CalcPlayerMovements()                                                zCall( 0x004B6EF0 );
    void SetPlayerPos( zVEC3 const& )                                         zCall( 0x004B71E0 );
    void ReceiveMsg( zTAICamMsg const& )                                      zCall( 0x004B7260 );
    void ClearMessages()                                                      zCall( 0x004B7270 );
    void AutoSetMessages()                                                    zCall( 0x004B7280 );
    void UpdateMessages()                                                     zCall( 0x004B73C0 );
    void Update()                                                             zCall( 0x004B73F0 );
    void CheckKeys()                                                          zCall( 0x004B7820 );
    int CheckSpecialMoves()                                                   zCall( 0x004B7830 );
    zCQuat GetLocalRot( float const&, float const& )                          zCall( 0x004B7B10 );
    zMAT4 GetLocalRotEnd()                                                    zCall( 0x004B7C90 );
    void RecalcRingPositions()                                                zCall( 0x004B8110 );
    zVEC3& GetLastValidWayPoint( zTWayPoint const& )                          zCall( 0x004B81B0 );
    void UpdateWayPoint( zTWayPoint const& )                                  zCall( 0x004B83B0 );
    void ResetWayPoints( zVEC3 const&, zTWayPoint const& )                    zCall( 0x004B86C0 );
    void InterpolateTo( zSPathSearchResult const& )                           zCall( 0x004B87C0 );
    void CalcPlayerSpline()                                                   zCall( 0x004B9DF0 );
    zMAT4& GetFirstPersonCamMat()                                             zCall( 0x004BA080 );
    zMAT4& GetPanicCamMat()                                                   zCall( 0x004BA290 );
    zMAT4& GetShoulderCamMat()                                                zCall( 0x004BA380 );
    zVEC3& CalcAziElevRangeApprox( float const&, float const&, float const& ) zCall( 0x004BA4F0 );
    void SetRotateEnabled( int )                                              zCall( 0x004BA8F0 );
    void SaveFrameStates()                                                    zCall( 0x004BAAD0 );
    void TargetChanged()                                                      zCall( 0x004BAF00 );
    void CamVobChanged()                                                      zCall( 0x004BB060 );
    void UpdateSampledPlayerPos( zVEC3 const& )                               zCall( 0x004BB0F0 );
    void SetSampledPlayerPos( zVEC3 const& )                                  zCall( 0x004BB280 );
    zVEC3& GetPlayerFuturePos( float )                                        zCall( 0x004BB2C0 );
    static zCMovementTracker* GetTracker()                                    zCall( 0x004B44D0 );

    // user API
    #include "zCMovementTracker.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZAI_CAMERA__MOVEMENT_H__VER3__