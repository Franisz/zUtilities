// Supported with union (c) 2018-2021 Union team

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

  // sizeof 1F98h
  class zCMovementTracker {
  public:
    enum zTWayPoint {
      zWAYPOINT_PLAYER,
      zWAYPOINT_CAM,
      zWAYPOINT_HEAD,
      zWAYPOINT_HIP_LEFT,
      zWAYPOINT_HIP_RIGHT
    };

    unsigned long movement;                // sizeof 04h    offset 00h
    zCArray<zCPositionKey*>targetKFList;   // sizeof 0Ch    offset 04h
    float frameTime;                       // sizeof 04h    offset 10h
    zVEC3 sampledPlayerPos;                // sizeof 0Ch    offset 14h
    zVEC3 sampledPlayerPosRing;            // sizeof 0Ch    offset 20h
    zVEC3 playerPos;                       // sizeof 0Ch    offset 2Ch
    zVEC3 playerPosRing;                   // sizeof 0Ch    offset 38h
    zVEC3 POI_Player;                      // sizeof 0Ch    offset 44h
    zVEC3 camPos;                          // sizeof 0Ch    offset 50h
    zVEC3 camPosRing;                      // sizeof 0Ch    offset 5Ch
    zVEC3 oldSampledPlayerPosRing;         // sizeof 0Ch    offset 68h
    zVEC3 oldSampledPlayerPos;             // sizeof 0Ch    offset 74h
    zVEC3 offsetPos;                       // sizeof 0Ch    offset 80h
    zVEC3 playerFuturePos;                 // sizeof 0Ch    offset 8Ch
    float playerFuturePosDT;               // sizeof 04h    offset 98h
    int numPreSamplesPlayerPos;            // sizeof 04h    offset 9Ch
    int numSamplesCam;                     // sizeof 04h    offset A0h
    int numSamplesPlayer;                  // sizeof 04h    offset A4h
    zCPose rotPoseTargetFOR;               // sizeof 8E4h   offset A8h
    zCPose headPose;                       // sizeof 8E4h   offset 98Ch
    zCPose sampledPlayerPose;              // sizeof 8E4h   offset 1270h
    zVEC3 wayPointHead[NUM_WAYPOINTS];     // sizeof 24h    offset 1B54h
    zVEC3 wayPointHipLeft[NUM_WAYPOINTS];  // sizeof 24h    offset 1B78h
    zVEC3 wayPointHipRight[NUM_WAYPOINTS]; // sizeof 24h    offset 1B9Ch
    zVEC3 wayPointCam[NUM_WAYPOINTS];      // sizeof 24h    offset 1BC0h
    int actWayPointHead;                   // sizeof 04h    offset 1BE4h
    int actWayPointHipLeft;                // sizeof 04h    offset 1BE8h
    int actWayPointHipRight;               // sizeof 04h    offset 1BECh
    int actWayPointCam;                    // sizeof 04h    offset 1BF0h
    float wayTimeHead;                     // sizeof 04h    offset 1BF4h
    float wayTimeHipLeft;                  // sizeof 04h    offset 1BF8h
    float wayTimeHipRight;                 // sizeof 04h    offset 1BFCh
    float wayTimeCam;                      // sizeof 04h    offset 1C00h
    zVEC3 playerHead;                      // sizeof 0Ch    offset 1C04h
    zVEC3 playerHipLeft;                   // sizeof 0Ch    offset 1C10h
    zVEC3 playerHipRight;                  // sizeof 0Ch    offset 1C1Ch
    zVEC3 playerPosMovement;               // sizeof 0Ch    offset 1C28h
    zVEC3 playerPosMovementRing;           // sizeof 0Ch    offset 1C34h
    zVEC3 playerPosMovementLocal;          // sizeof 0Ch    offset 1C40h
    zVEC3 playerPosMovementLocalCam;       // sizeof 0Ch    offset 1C4Ch
    zVEC3 oldPlayerPosMovement;            // sizeof 0Ch    offset 1C58h
    zVEC3 oldPlayerPos;                    // sizeof 0Ch    offset 1C64h
    zVEC3 oldCamPos;                       // sizeof 0Ch    offset 1C70h
    float oldDistToPlayer;                 // sizeof 04h    offset 1C7Ch
    float inertiaTrans;                    // sizeof 04h    offset 1C80h
    float inertiaHead;                     // sizeof 04h    offset 1C84h
    float inertiaRotTargetFOR;             // sizeof 04h    offset 1C88h
    float inertiaTargetTrans;              // sizeof 04h    offset 1C8Ch
    float inertiaTargetRot;                // sizeof 04h    offset 1C90h
    float actAzi;                          // sizeof 04h    offset 1C94h
    float actElev;                         // sizeof 04h    offset 1C98h
    float distToPlayer;                    // sizeof 04h    offset 1C9Ch
    float playerVeloRange;                 // sizeof 04h    offset 1CA0h
    float oldAzi;                          // sizeof 04h    offset 1CA4h
    float oldElev;                         // sizeof 04h    offset 1CA8h
    zMAT4 trafoWStoTS;                     // sizeof 40h    offset 1CACh
    zMAT4 trafoTStoWS;                     // sizeof 40h    offset 1CECh
    zMAT4 trafoWStoCS;                     // sizeof 40h    offset 1D2Ch
    zMAT4 trafoCStoWS;                     // sizeof 40h    offset 1D6Ch
    zMAT4 oldTrafoWStoTS;                  // sizeof 40h    offset 1DACh
    zMAT4 oldTrafoWStoCS;                  // sizeof 40h    offset 1DECh
    zMAT4 oldTrafoRotOffsetWStoCS;         // sizeof 40h    offset 1E2Ch
    zMAT4 lastValidCamTrafo;               // sizeof 40h    offset 1E6Ch
    zCQuat startRot;                       // sizeof 10h    offset 1EACh
    zCQuat endRot;                         // sizeof 10h    offset 1EBCh
    zCQuat maxAziRot;                      // sizeof 10h    offset 1ECCh
    zCQuat minAziRot;                      // sizeof 10h    offset 1EDCh
    zCQuat idealRot;                       // sizeof 10h    offset 1EECh
    zCQuat idealRotTrans;                  // sizeof 10h    offset 1EFCh
    zCQuat actRot;                         // sizeof 10h    offset 1F0Ch
    zCQuat idealRotLocal;                  // sizeof 10h    offset 1F1Ch
    zMAT4 initialPoseRotFreeze;            // sizeof 40h    offset 1F2Ch
    float timeSamples;                     // sizeof 04h    offset 1F6Ch
    float standTimer;                      // sizeof 04h    offset 1F70h
    int standing;                          // sizeof 04h    offset 1F74h
    int rotate;                            // sizeof 04h    offset 1F78h
    int bMouseUsed;                        // sizeof 04h    offset 1F7Ch
    float playerAziSideSign;               // sizeof 04h    offset 1F80h
    float playerElevSideSign;              // sizeof 04h    offset 1F84h
    zCVob* target;                         // sizeof 04h    offset 1F88h
    zCVob* camVob;                         // sizeof 04h    offset 1F8Ch
    zCAICamera* camai;                     // sizeof 04h    offset 1F90h
    zCPathSearch* pathSearch;              // sizeof 04h    offset 1F94h

    void zCMovementTracker_OnInit()                                           zCall( 0x004B4520 );

  private:
    zCMovementTracker()                                                       zInit( zCMovementTracker_OnInit() );

  public:
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