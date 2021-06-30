// Supported with union (c) 2018 Union team

#ifndef __ZAI_PLAYER_H__VER3__
#define __ZAI_PLAYER_H__VER3__

#include "z3d.h"
#include "zAi.h"
#include "zSound.h"
#include "zRayCache.h"
#include "zCollisionDetector.h"
#include "zCollisionObject.h"
#include "zCollisionObjectMisc.h"

namespace Gothic_II_Addon {

  class zCAIPlayer : public zCAIBase {
  public:
    zCLASS_DECLARATION( zCAIPlayer )

    enum zTSurfaceAlignMode {
      zMV_SURFACE_ALIGN_NONE,
      zMV_SURFACE_ALIGN_NORMAL,
      zMV_SURFACE_ALIGN_HIGH
    };

    enum zTMovementState {
      zMV_STATE_STAND,
      zMV_STATE_FLY,
      zMV_STATE_SWIM,
      zMV_STATE_DIVE
    };

    struct zTConfig {
      float zMV_MIN_SPACE_MOVE_FORWARD;
      float zMV_DETECT_CHASM_SCAN_AT;
      float zMV_STEP_HEIGHT;
      float zMV_JUMP_UP_MIN_CEIL;
      float zMV_WATER_DEPTH_KNEE;
      float zMV_WATER_DEPTH_CHEST;
      float zMV_YMAX_SWIM_CLIMB_OUT;
      float zMV_FORCE_JUMP_UP;
      float zMV_YMAX_JUMPLOW;
      float zMV_YMAX_JUMPMID;
      float zMV_MAX_GROUND_ANGLE_WALK;
      float zMV_MAX_GROUND_ANGLE_SLIDE;
      float zMV_MAX_GROUND_ANGLE_SLIDE2;
      float zMV_DCUL_WALL_HEADING_ANGLE;
      float zMV_DCUL_WALL_HORIZ_ANGLE;
      float zMV_DCUL_GROUND_ANGLE;

      zTConfig() {}

      // user API
      #include "zCAIPlayer_zTConfig.inl"
    };

    struct zTLedgeInfo {
      zVEC3 point;
      zVEC3 normal;
      zVEC3 cont;
      float maxMoveForward;

      zTLedgeInfo() {}

      // user API
      #include "zCAIPlayer_zTLedgeInfo.inl"
    };

    struct zTBloodVobTrack {
      zCVob* bloodVob;
      float alpha;

      zTBloodVobTrack() {}

      // user API
      #include "zCAIPlayer_zTBloodVobTrack.inl"
    };

    zTConfig config;
    zCVob* vob;
    zCModel* model;
    zCWorld* world;
    zVEC3 centerPos;
    float feetY;
    float headY;
    float aboveFloor;
    int waterLevel;
    float velocityLen2;
    zVEC3 velocity;
    float fallDownDistanceY;
    float fallDownStartY;
    zVEC3 slidePolyNormal;
    float checkWaterCollBodyLen;
    zCModelNodeInst* modelHeadNode;
#pragma pack( push, 1 )
    group {
      unsigned char zMV_DO_SURFACE_ALIGN                         : 2;
      unsigned char zMV_DO_DETECT_WALK_STOP_CHASM                : 1;
      unsigned char zMV_DO_WALL_SLIDING                          : 1;
      unsigned char zMV_DO_HEIGHT_CORRECTION                     : 1;
      unsigned char cdStatOriginal                               : 1;
      unsigned char cdStat                                       : 1;
      unsigned char startFXModelLandDust                         : 1;
      unsigned char forceModelHalt                               : 1;
      unsigned char autoRollEnabled                              : 1;
      unsigned char modelAnisInPlace                             : 1;
      zTMovementState oldState                                   : 3;
      zTMovementState state                                      : 3;
      unsigned char oldWaterLevel                                : 2;
      zCCollObjectCharacter::zEConfigState m_eCollObjectState    : 4;
      zCCollObjectCharacter::zEConfigState m_eCollObjectStateOld : 4;
    };
#pragma pack( pop )
    zCArray<zTBloodVobTrack> bloodVobList;
    float bleedingPerc;
    zVEC3 bleedingLastPos;
    float bleedingNextDist;
    zCVob* weaponTrailVob;
    zCVob* waterRingVob;
    float waterRingTimer;
    float autoRollPos;
    float autoRollPosDest;
    float autoRollSpeed;
    float autoRollMaxAngle;
    unsigned char dummyLastVar;
    zSTRING bloodDefaultTexName;

    void zCAIPlayer_OnInit()                                          zCall( 0x0050C5C0 );
    zCAIPlayer()                                                      zInit( zCAIPlayer_OnInit() );
    void RemoveEffects()                                              zCall( 0x0050C980 );
    float GetJumpUpHeight()                                           zCall( 0x0050CA70 );
    void SetJumpUpForceByHeight( float )                              zCall( 0x0050CAB0 );
    void SetVob( zCVob* )                                             zCall( 0x0050CAD0 );
    void DoAutoRoll()                                                 zCall( 0x0050CC30 );
    void ResetAutoRoll()                                              zCall( 0x0050CDF0 );
    void CalcModelAnisInPlace()                                       zCall( 0x0050CE20 );
    void DoSurfaceAlignment()                                         zCall( 0x0050CE80 );
    int IsSliding()                                                   zCall( 0x0050D4A0 );
    int CheckFloorSliding()                                           zCall( 0x0050D4D0 );
    void CheckPhysics()                                               zCall( 0x0050DC40 );
    void PropagateCollObjectStates( zTMovementState )                 zCall( 0x0050E180 );
    void CalcForceModelHalt()                                         zCall( 0x0050E390 );
    void CalcStateVars()                                              zCall( 0x0050E440 );
    void DoProceduralMovement()                                       zCall( 0x0050E6C0 );
    void Begin( zCVob* )                                              zCall( 0x0050E750 );
    void End()                                                        zCall( 0x0050E8F0 );
    void UpdateEffects()                                              zCall( 0x0050E990 );
    zCQuadMark* GetBloodQuadMark()                                    zCall( 0x0050F520 );
    void SetBloodDefaultTexture( zSTRING const& )                     zCall( 0x0050F780 );
    void AddBlood( zVEC3 const&, zVEC3 const&, float, int, zSTRING* ) zCall( 0x0050F8C0 );
    void AddWeaponTrailSegment( zVEC3 const&, zVEC3 const& )          zCall( 0x0050F950 );
    void CreateLedgeInfo()                                            zCall( 0x0050FCA0 );
    zTLedgeInfo* GetLedgeInfo() const                                 zCall( 0x0050FCC0 );
    int GetFoundLedge() const                                         zCall( 0x0050FD00 );
    void ClearFoundLedge()                                            zCall( 0x0050FD20 );
    int DetectClimbUpLedge( zVEC3&, int )                             zCall( 0x0050FD90 );
    void AlignModelToLedge( zSTRING const& )                          zCall( 0x00511070 );
    zVEC3 GetHandPositionWorld() const                                zCall( 0x00511170 );
    void AlignToFloor( float )                                        zCall( 0x005112C0 );
    float GetModelFloorWorld()                                        zCall( 0x00511300 );
    int CheckEnoughSpaceMoveDir( zVEC3 const&, int )                  zCall( 0x00511320 );
    int CheckEnoughSpaceMoveForward( int )                            zCall( 0x00511700 );
    int CheckEnoughSpaceMoveBackward( int )                           zCall( 0x00511740 );
    int CheckEnoughSpaceMoveRight( int )                              zCall( 0x00511790 );
    int CheckEnoughSpaceMoveLeft( int )                               zCall( 0x005117D0 );
    float GetProtoYHeight()                                           zCall( 0x00511820 );
    zVEC3 GetSurfaceAlignScanOrigin()                                 zCall( 0x00511840 );
    void DiveRotateX( float const& )                                  zCall( 0x00511970 );
    void SetCDStat( int )                                             zCall( 0x00511AC0 );
    void LandAndStartAni( zSTRING const& )                            zCall( 0x00511B10 );
    void LandAndStartAni( zCModelAni* )                               zCall( 0x00511BC0 );
    int CheckForceModelHalt( zSTRING const& )                         zCall( 0x00511C20 );
    int CheckForceModelHalt( zCModelAni* )                            zCall( 0x00511C60 );
    int ShouldCorrectFloorHeight()                                    zCall( 0x00511CA0 );
    void BeginStateSwitch()                                           zCall( 0x00511CC0 );
    void SetPhysicsEnabled( int )                                     zCall( 0x00511D40 );
    void StartPhysicsWithVel()                                        zCall( 0x00511D50 );
    void Print( zSTRING const& ) const                                zCall( 0x00512080 );
    void Line3D( zVEC3 const&, zVEC3 const&, int ) const              zCall( 0x00512090 );
    void PrintScreen( int, int, zSTRING ) const                       zCall( 0x005120A0 );
    zCModel* GetModel() const                                         zCall( 0x006A9810 );
    static zCObject* _CreateNewInstance()                             zCall( 0x0050C470 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x0050C730 );
    virtual void Archive( zCArchiver& )                               zCall( 0x00511E60 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x00511F50 );
    virtual ~zCAIPlayer()                                             zCall( 0x0050C770 );
    virtual void DoAI( zCVob*, int& )                                 zCall( 0x0050E980 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )          zCall( 0x0050CA60 );
    virtual void StartStandAni()                                      zCall( 0x00511D80 );
    virtual void StartFallDownAni()                                   zCall( 0x00511DA0 );

    // static properties
    static int& s_bShowWeaponTrails;

    // user API
    #include "zCAIPlayer.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZAI_PLAYER_H__VER3__