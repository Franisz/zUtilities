// Supported with union (c) 2018 Union team

#ifndef __ZAI_PLAYER_H__VER1__
#define __ZAI_PLAYER_H__VER1__

namespace Gothic_I_Addon {

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

    void zCAIPlayer_OnInit()                                            zCall( 0x0050FCB0 );
    zCAIPlayer()                                                        zInit( zCAIPlayer_OnInit() );
    void RemoveEffects()                                                zCall( 0x00510090 );
    float GetJumpUpHeight()                                             zCall( 0x00510190 );
    void SetJumpUpForceByHeight( float )                                zCall( 0x005101D0 );
    void SetVob( zCVob* )                                               zCall( 0x005101F0 );
    void DoAutoRoll()                                                   zCall( 0x00510360 );
    void ResetAutoRoll()                                                zCall( 0x005104E0 );
    void CalcModelAnisInPlace()                                         zCall( 0x00510510 );
    void DoSurfaceAlignment()                                           zCall( 0x00510570 );
    int IsSliding()                                                     zCall( 0x00510D60 );
    int CheckFloorSliding()                                             zCall( 0x00510D90 );
    void CheckPhysics()                                                 zCall( 0x00511520 );
    void PropagateCollObjectStates( zTMovementState )                   zCall( 0x00511A70 );
    void CalcForceModelHalt()                                           zCall( 0x00511C70 );
    void CalcStateVars()                                                zCall( 0x00511D30 );
    void DoProceduralMovement()                                         zCall( 0x00511FD0 );
    void Begin( zCVob* )                                                zCall( 0x00512090 );
    void End()                                                          zCall( 0x00512210 );
    void UpdateEffects()                                                zCall( 0x005122B0 );
    zCQuadMark* GetBloodQuadMark()                                      zCall( 0x00512FF0 );
    void SetBloodDefaultTexture( zSTRING const& )                       zCall( 0x005132C0 );
    void AddBlood( zVEC3 const&, zVEC3 const&, float, int, zSTRING* )   zCall( 0x00513400 );
    void AddWeaponTrailSegment( zVEC3 const&, zVEC3 const& )            zCall( 0x00513490 );
    void CreateLedgeInfo()                                              zCall( 0x00513710 );
    zTLedgeInfo* GetLedgeInfo() const                                   zCall( 0x00513730 );
    int GetFoundLedge() const                                           zCall( 0x00513770 );
    void ClearFoundLedge()                                              zCall( 0x00513790 );
    int DetectClimbUpLedge( zVEC3&, int )                               zCall( 0x00513800 );
    void AlignModelToLedge( zSTRING const& )                            zCall( 0x00514CD0 );
    zVEC3 GetHandPositionWorld() const                                  zCall( 0x00514DE0 );
    void AlignToFloor( float )                                          zCall( 0x00514F70 );
    float GetModelFloorWorld()                                          zCall( 0x00514FB0 );
    int CheckEnoughSpaceMoveDir( zVEC3 const&, int )                    zCall( 0x00515000 );
    int CheckEnoughSpaceMoveForward( int )                              zCall( 0x00515500 );
    int CheckEnoughSpaceMoveBackward( int )                             zCall( 0x00515550 );
    int CheckEnoughSpaceMoveRight( int )                                zCall( 0x005155B0 );
    int CheckEnoughSpaceMoveLeft( int )                                 zCall( 0x00515600 );
    float GetProtoYHeight()                                             zCall( 0x00515660 );
    zVEC3 GetSurfaceAlignScanOrigin()                                   zCall( 0x00515680 );
    void DiveRotateX( float const& )                                    zCall( 0x00515880 );
    void SetCDStat( int )                                               zCall( 0x005159F0 );
    void LandAndStartAni( zSTRING const& )                              zCall( 0x00515A30 );
    void LandAndStartAni( zCModelAni* )                                 zCall( 0x00515AE0 );
    int CheckForceModelHalt( zSTRING const& )                           zCall( 0x00515B40 );
    int CheckForceModelHalt( zCModelAni* )                              zCall( 0x00515B80 );
    int ShouldCorrectFloorHeight()                                      zCall( 0x00515BC0 );
    void BeginStateSwitch()                                             zCall( 0x00515BE0 );
    void SetPhysicsEnabled( int )                                       zCall( 0x00515C60 );
    void StartPhysicsWithVel()                                          zCall( 0x00515C70 );
    void Print( zSTRING const& ) const                                  zCall( 0x00515FA0 );
    void Line3D( zVEC3 const&, zVEC3 const&, int ) const                zCall( 0x00515FB0 );
    void PrintScreen( int, int, zSTRING ) const                         zCall( 0x00515FC0 );
    zCModel* GetModel() const                                           zCall( 0x00645740 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0050FB50 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0050FE40 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00515D80 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00515E70 );
    virtual ~zCAIPlayer()                                               zCall( 0x0050FE80 );
    virtual void DoAI( zCVob*, int& )                                   zCall( 0x005122A0 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )            zCall( 0x00510180 );
    virtual void StartStandAni()                                        zCall( 0x00515CA0 );
    virtual void StartFallDownAni()                                     zCall( 0x00515CC0 );

    // user API
    #include "zCAIPlayer.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZAI_PLAYER_H__VER1__