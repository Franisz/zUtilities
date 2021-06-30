// Supported with union (c) 2018 Union team

#ifndef __ZAI_CAMERA__MOVEMENT_H__VER2__
#define __ZAI_CAMERA__MOVEMENT_H__VER2__

#include "zAiCamera.h"
#include "zAiCamera_Core.h"

namespace Gothic_II_Classic {
  const float PLAYER_FUTURE_POS_ADVANCE_TIME_SEC = 0.5F;
  const float SHOULDERCAM_AZI                    = 0;
  const float SHOULDERCAM_ELEV                   = 85;
  const float SHOULDERCAM_RANGE                  = 1.5F * 100;
  const float SHOULDERCAM_FOCUS_OFFSET_AT        = 200;
  const float SHOULDERCAM_FOCUS_OFFSET_UP        = 10;
  const int MAX_POS_SAMPLES_PLAYER               = 100;
  const int MAX_POS_SAMPLES_CAM                  = 100;
  const int MAX_POS_SAMPLES_FOCUS                = 100;
  const int NUM_MOV_SAMPLES_FOCUS                = 10;
  const int NUM_WAYPOINTS                        = 3;
  const float zWAYPOINT_SAMPLE_TIME              = 0.3F;
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

    void zCMovementTracker_OnInit()                                           zCall( 0x004B1FF0 );
    zCMovementTracker()                                                       zInit( zCMovementTracker_OnInit() );
    ~zCMovementTracker()                                                      zCall( 0x004B24F0 );
    float GetAzimuth()                                                        zCall( 0x004B2570 );
    float GetElevation()                                                      zCall( 0x004B2580 );
    float GetAzimuth( zVEC3 const& )                                          zCall( 0x004B2590 );
    float GetElevation( zVEC3 const& )                                        zCall( 0x004B2910 );
    float GetRange( zVEC3 const& )                                            zCall( 0x004B2B40 );
    void SetAzimuth( float const& )                                           zCall( 0x004B2B70 );
    void SetElevation( float const& )                                         zCall( 0x004B2BA0 );
    void SetRange( float const& )                                             zCall( 0x004B2BD0 );
    float GetRange()                                                          zCall( 0x004B2CA0 );
    zVEC3 ApplyAziToPoint( float const&, zVEC3 const& )                       zCall( 0x004B2CD0 );
    zVEC3 ApplyElevToPoint( float const&, zVEC3 const& )                      zCall( 0x004B2ED0 );
    zVEC3 ApplyRangeToPoint( float const&, zVEC3 const& )                     zCall( 0x004B3270 );
    zVEC3 GetRangePos( float const& )                                         zCall( 0x004B3330 );
    zVEC3 GetIdealRangePos()                                                  zCall( 0x004B33F0 );
    float GetDistToIdealRange()                                               zCall( 0x004B34B0 );
    int IsIdealOrientation()                                                  zCall( 0x004B35B0 );
    int IsIdealRange()                                                        zCall( 0x004B3620 );
    void UpdateCamPos( zVEC3 const& )                                         zCall( 0x004B3740 );
    void UpdatePlayerPos( zVEC3 const& )                                      zCall( 0x004B3800 );
    void SetCamPos( zVEC3 const& )                                            zCall( 0x004B3BD0 );
    void CalcPlayerPose()                                                     zCall( 0x004B3C20 );
    void CalcPlayerMovements()                                                zCall( 0x004B49C0 );
    void SetPlayerPos( zVEC3 const& )                                         zCall( 0x004B4CB0 );
    void ReceiveMsg( zTAICamMsg const& )                                      zCall( 0x004B4D30 );
    void ClearMessages()                                                      zCall( 0x004B4D40 );
    void AutoSetMessages()                                                    zCall( 0x004B4D50 );
    void UpdateMessages()                                                     zCall( 0x004B4E90 );
    void Update()                                                             zCall( 0x004B4EC0 );
    void CheckKeys()                                                          zCall( 0x004B52F0 );
    int CheckSpecialMoves()                                                   zCall( 0x004B5300 );
    zCQuat GetLocalRot( float const&, float const& )                          zCall( 0x004B55E0 );
    zMAT4 GetLocalRotEnd()                                                    zCall( 0x004B5760 );
    void RecalcRingPositions()                                                zCall( 0x004B5BE0 );
    zVEC3& GetLastValidWayPoint( zTWayPoint const& )                          zCall( 0x004B5C80 );
    void UpdateWayPoint( zTWayPoint const& )                                  zCall( 0x004B5E80 );
    void ResetWayPoints( zVEC3 const&, zTWayPoint const& )                    zCall( 0x004B6190 );
    void InterpolateTo( zSPathSearchResult const& )                           zCall( 0x004B6290 );
    void CalcPlayerSpline()                                                   zCall( 0x004B7880 );
    zMAT4& GetFirstPersonCamMat()                                             zCall( 0x004B7B10 );
    zMAT4& GetPanicCamMat()                                                   zCall( 0x004B7D20 );
    zMAT4& GetShoulderCamMat()                                                zCall( 0x004B7E10 );
    zVEC3& CalcAziElevRangeApprox( float const&, float const&, float const& ) zCall( 0x004B7F80 );
    void SetRotateEnabled( int )                                              zCall( 0x004B8380 );
    void SaveFrameStates()                                                    zCall( 0x004B8560 );
    void TargetChanged()                                                      zCall( 0x004B8990 );
    void CamVobChanged()                                                      zCall( 0x004B8AF0 );
    void UpdateSampledPlayerPos( zVEC3 const& )                               zCall( 0x004B8B80 );
    void SetSampledPlayerPos( zVEC3 const& )                                  zCall( 0x004B8D10 );
    zVEC3& GetPlayerFuturePos( float )                                        zCall( 0x004B8D50 );
    static zCMovementTracker* GetTracker()                                    zCall( 0x004B1FA0 );

    // user API
    #include "zCMovementTracker.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZAI_CAMERA__MOVEMENT_H__VER2__