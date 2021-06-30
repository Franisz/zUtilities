// Supported with union (c) 2018 Union team

#ifndef __ZAI_PLAYER_H__VER2__
#define __ZAI_PLAYER_H__VER2__

namespace Gothic_II_Classic {

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

    void zCAIPlayer_OnInit()                                          zCall( 0x00509810 );
    zCAIPlayer()                                                      zInit( zCAIPlayer_OnInit() );
    void RemoveEffects()                                              zCall( 0x00509BD0 );
    float GetJumpUpHeight()                                           zCall( 0x00509CC0 );
    void SetJumpUpForceByHeight( float )                              zCall( 0x00509D00 );
    void SetVob( zCVob* )                                             zCall( 0x00509D20 );
    void DoAutoRoll()                                                 zCall( 0x00509E80 );
    void ResetAutoRoll()                                              zCall( 0x0050A040 );
    void CalcModelAnisInPlace()                                       zCall( 0x0050A070 );
    void DoSurfaceAlignment()                                         zCall( 0x0050A0D0 );
    int IsSliding()                                                   zCall( 0x0050A6F0 );
    int CheckFloorSliding()                                           zCall( 0x0050A720 );
    void CheckPhysics()                                               zCall( 0x0050AE90 );
    void PropagateCollObjectStates( zTMovementState )                 zCall( 0x0050B3D0 );
    void CalcForceModelHalt()                                         zCall( 0x0050B5E0 );
    void CalcStateVars()                                              zCall( 0x0050B690 );
    void DoProceduralMovement()                                       zCall( 0x0050B910 );
    void Begin( zCVob* )                                              zCall( 0x0050B9A0 );
    void End()                                                        zCall( 0x0050BB40 );
    void UpdateEffects()                                              zCall( 0x0050BBE0 );
    zCQuadMark* GetBloodQuadMark()                                    zCall( 0x0050C770 );
    void SetBloodDefaultTexture( zSTRING const& )                     zCall( 0x0050C9D0 );
    void AddBlood( zVEC3 const&, zVEC3 const&, float, int, zSTRING* ) zCall( 0x0050CB10 );
    void AddWeaponTrailSegment( zVEC3 const&, zVEC3 const& )          zCall( 0x0050CBA0 );
    void CreateLedgeInfo()                                            zCall( 0x0050CED0 );
    zTLedgeInfo* GetLedgeInfo() const                                 zCall( 0x0050CEF0 );
    int GetFoundLedge() const                                         zCall( 0x0050CF30 );
    void ClearFoundLedge()                                            zCall( 0x0050CF50 );
    int DetectClimbUpLedge( zVEC3&, int )                             zCall( 0x0050CFC0 );
    void AlignModelToLedge( zSTRING const& )                          zCall( 0x0050E2A0 );
    zVEC3 GetHandPositionWorld() const                                zCall( 0x0050E3A0 );
    void AlignToFloor( float )                                        zCall( 0x0050E4F0 );
    float GetModelFloorWorld()                                        zCall( 0x0050E530 );
    int CheckEnoughSpaceMoveDir( zVEC3 const&, int )                  zCall( 0x0050E550 );
    int CheckEnoughSpaceMoveForward( int )                            zCall( 0x0050E930 );
    int CheckEnoughSpaceMoveBackward( int )                           zCall( 0x0050E970 );
    int CheckEnoughSpaceMoveRight( int )                              zCall( 0x0050E9C0 );
    int CheckEnoughSpaceMoveLeft( int )                               zCall( 0x0050EA00 );
    float GetProtoYHeight()                                           zCall( 0x0050EA50 );
    zVEC3 GetSurfaceAlignScanOrigin()                                 zCall( 0x0050EA70 );
    void DiveRotateX( float const& )                                  zCall( 0x0050EBA0 );
    void SetCDStat( int )                                             zCall( 0x0050ECF0 );
    void LandAndStartAni( zSTRING const& )                            zCall( 0x0050ED40 );
    void LandAndStartAni( zCModelAni* )                               zCall( 0x0050EDF0 );
    int CheckForceModelHalt( zSTRING const& )                         zCall( 0x0050EE50 );
    int CheckForceModelHalt( zCModelAni* )                            zCall( 0x0050EE90 );
    int ShouldCorrectFloorHeight()                                    zCall( 0x0050EED0 );
    void BeginStateSwitch()                                           zCall( 0x0050EEF0 );
    void SetPhysicsEnabled( int )                                     zCall( 0x0050EF70 );
    void StartPhysicsWithVel()                                        zCall( 0x0050EF80 );
    void Print( zSTRING const& ) const                                zCall( 0x0050F2B0 );
    void Line3D( zVEC3 const&, zVEC3 const&, int ) const              zCall( 0x0050F2C0 );
    void PrintScreen( int, int, zSTRING ) const                       zCall( 0x0050F2D0 );
    zCModel* GetModel() const                                         zCall( 0x0064CF90 );
    static zCObject* _CreateNewInstance()                             zCall( 0x005096C0 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x00509980 );
    virtual void Archive( zCArchiver& )                               zCall( 0x0050F090 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x0050F180 );
    virtual ~zCAIPlayer()                                             zCall( 0x005099C0 );
    virtual void DoAI( zCVob*, int& )                                 zCall( 0x0050BBD0 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )          zCall( 0x00509CB0 );
    virtual void StartStandAni()                                      zCall( 0x0050EFB0 );
    virtual void StartFallDownAni()                                   zCall( 0x0050EFD0 );

    // user API
    #include "zCAIPlayer.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZAI_PLAYER_H__VER2__