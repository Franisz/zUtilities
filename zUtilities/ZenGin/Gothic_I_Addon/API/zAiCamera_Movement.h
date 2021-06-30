// Supported with union (c) 2018 Union team

#ifndef __ZAI_CAMERA__MOVEMENT_H__VER1__
#define __ZAI_CAMERA__MOVEMENT_H__VER1__

#include "zAiCamera.h"
#include "zAiCamera_Core.h"

namespace Gothic_I_Addon {
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

    void zCMovementTracker_OnInit()                                           zCall( 0x004B9AD0 );
    zCMovementTracker()                                                       zInit( zCMovementTracker_OnInit() );
    ~zCMovementTracker()                                                      zCall( 0x004B9FD0 );
    float GetAzimuth()                                                        zCall( 0x004BA050 );
    float GetElevation()                                                      zCall( 0x004BA060 );
    float GetAzimuth( zVEC3 const& )                                          zCall( 0x004BA070 );
    float GetElevation( zVEC3 const& )                                        zCall( 0x004BA3F0 );
    float GetRange( zVEC3 const& )                                            zCall( 0x004BA6F0 );
    void SetAzimuth( float const& )                                           zCall( 0x004BA720 );
    void SetElevation( float const& )                                         zCall( 0x004BA750 );
    void SetRange( float const& )                                             zCall( 0x004BA780 );
    float GetRange()                                                          zCall( 0x004BA860 );
    zVEC3 ApplyAziToPoint( float const&, zVEC3 const& )                       zCall( 0x004BA890 );
    zVEC3 ApplyElevToPoint( float const&, zVEC3 const& )                      zCall( 0x004BAB30 );
    zVEC3 ApplyRangeToPoint( float const&, zVEC3 const& )                     zCall( 0x004BAF20 );
    zVEC3 GetRangePos( float const& )                                         zCall( 0x004BB000 );
    zVEC3 GetIdealRangePos()                                                  zCall( 0x004BB0C0 );
    float GetDistToIdealRange()                                               zCall( 0x004BB1A0 );
    int IsIdealOrientation()                                                  zCall( 0x004BB2C0 );
    int IsIdealRange()                                                        zCall( 0x004BB330 );
    void UpdateCamPos( zVEC3 const& )                                         zCall( 0x004BB460 );
    void UpdatePlayerPos( zVEC3 const& )                                      zCall( 0x004BB530 );
    void SetCamPos( zVEC3 const& )                                            zCall( 0x004BB8F0 );
    void CalcPlayerPose()                                                     zCall( 0x004BB940 );
    void CalcPlayerMovements()                                                zCall( 0x004BC820 );
    void SetPlayerPos( zVEC3 const& )                                         zCall( 0x004BCB40 );
    void ReceiveMsg( zTAICamMsg const& )                                      zCall( 0x004BCBC0 );
    void ClearMessages()                                                      zCall( 0x004BCBD0 );
    void AutoSetMessages()                                                    zCall( 0x004BCBE0 );
    void UpdateMessages()                                                     zCall( 0x004BCDE0 );
    void Update()                                                             zCall( 0x004BCE10 );
    void CheckKeys()                                                          zCall( 0x004BD260 );
    int CheckSpecialMoves()                                                   zCall( 0x004BD270 );
    zCQuat GetLocalRot( float const&, float const& )                          zCall( 0x004BD5C0 );
    zMAT4 GetLocalRotEnd()                                                    zCall( 0x004BD7B0 );
    void RecalcRingPositions()                                                zCall( 0x004BDC20 );
    zVEC3& GetLastValidWayPoint( zTWayPoint const& )                          zCall( 0x004BDCC0 );
    void UpdateWayPoint( zTWayPoint const& )                                  zCall( 0x004BDEC0 );
    void ResetWayPoints( zVEC3 const&, zTWayPoint const& )                    zCall( 0x004BE220 );
    void InterpolateTo( zSPathSearchResult const& )                           zCall( 0x004BE310 );
    void CalcPlayerSpline()                                                   zCall( 0x004BF8B0 );
    zVEC3 GetPlayerAtVector()                                                 zCall( 0x004BFB80 );
    zMAT4& GetFirstPersonCamMat()                                             zCall( 0x004BFBC0 );
    zMAT4& GetPanicCamMat()                                                   zCall( 0x004BFE20 );
    zMAT4& GetShoulderCamMat()                                                zCall( 0x004BFF80 );
    zVEC3& CalcAziElevRangeApprox( float const&, float const&, float const& ) zCall( 0x004C0160 );
    void SetRotateEnabled( int )                                              zCall( 0x004C05E0 );
    void SaveFrameStates()                                                    zCall( 0x004C0750 );
    void TargetChanged()                                                      zCall( 0x004C0B20 );
    void CamVobChanged()                                                      zCall( 0x004C0C90 );
    void UpdateSampledPlayerPos( zVEC3 const& )                               zCall( 0x004C0D20 );
    void SetSampledPlayerPos( zVEC3 const& )                                  zCall( 0x004C0E10 );
    zVEC3& GetPlayerFuturePos( float )                                        zCall( 0x004C0E50 );
    static zCMovementTracker* GetTracker()                                    zCall( 0x004B9A80 );

    // user API
    #include "zCMovementTracker.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZAI_CAMERA__MOVEMENT_H__VER1__