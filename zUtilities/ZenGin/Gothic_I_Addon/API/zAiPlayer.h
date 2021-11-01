// Supported with union (c) 2018-2021 Union team

#ifndef __ZAI_PLAYER_H__VER1__
#define __ZAI_PLAYER_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 118h
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

    // sizeof 40h
    struct zTConfig {
      float zMV_MIN_SPACE_MOVE_FORWARD;  // sizeof 04h    offset 00h
      float zMV_DETECT_CHASM_SCAN_AT;    // sizeof 04h    offset 04h
      float zMV_STEP_HEIGHT;             // sizeof 04h    offset 08h
      float zMV_JUMP_UP_MIN_CEIL;        // sizeof 04h    offset 0Ch
      float zMV_WATER_DEPTH_KNEE;        // sizeof 04h    offset 10h
      float zMV_WATER_DEPTH_CHEST;       // sizeof 04h    offset 14h
      float zMV_YMAX_SWIM_CLIMB_OUT;     // sizeof 04h    offset 18h
      float zMV_FORCE_JUMP_UP;           // sizeof 04h    offset 1Ch
      float zMV_YMAX_JUMPLOW;            // sizeof 04h    offset 20h
      float zMV_YMAX_JUMPMID;            // sizeof 04h    offset 24h
      float zMV_MAX_GROUND_ANGLE_WALK;   // sizeof 04h    offset 28h
      float zMV_MAX_GROUND_ANGLE_SLIDE;  // sizeof 04h    offset 2Ch
      float zMV_MAX_GROUND_ANGLE_SLIDE2; // sizeof 04h    offset 30h
      float zMV_DCUL_WALL_HEADING_ANGLE; // sizeof 04h    offset 34h
      float zMV_DCUL_WALL_HORIZ_ANGLE;   // sizeof 04h    offset 38h
      float zMV_DCUL_GROUND_ANGLE;       // sizeof 04h    offset 3Ch

      zTConfig() {}

      // user API
      #include "zCAIPlayer_zTConfig.inl"
    };

    // sizeof 28h
    struct zTLedgeInfo {
      zVEC3 point;          // sizeof 0Ch    offset 00h
      zVEC3 normal;         // sizeof 0Ch    offset 0Ch
      zVEC3 cont;           // sizeof 0Ch    offset 18h
      float maxMoveForward; // sizeof 04h    offset 24h

      zTLedgeInfo() {}

      // user API
      #include "zCAIPlayer_zTLedgeInfo.inl"
    };

    // sizeof 08h
    struct zTBloodVobTrack {
      zCVob* bloodVob; // sizeof 04h    offset 00h
      float alpha;     // sizeof 04h    offset 04h

      zTBloodVobTrack() {}

      // user API
      #include "zCAIPlayer_zTBloodVobTrack.inl"
    };

    zTConfig config;                                                  // sizeof 40h    offset 24h
    zCVob* vob;                                                       // sizeof 04h    offset 64h
    zCModel* model;                                                   // sizeof 04h    offset 68h
    zCWorld* world;                                                   // sizeof 04h    offset 6Ch
    zVEC3 centerPos;                                                  // sizeof 0Ch    offset 70h
    float feetY;                                                      // sizeof 04h    offset 7Ch
    float headY;                                                      // sizeof 04h    offset 80h
    float aboveFloor;                                                 // sizeof 04h    offset 84h
    int waterLevel;                                                   // sizeof 04h    offset 88h
    float velocityLen2;                                               // sizeof 04h    offset 8Ch
    zVEC3 velocity;                                                   // sizeof 0Ch    offset 90h
    float fallDownDistanceY;                                          // sizeof 04h    offset 9Ch
    float fallDownStartY;                                             // sizeof 04h    offset A0h
    zVEC3 slidePolyNormal;                                            // sizeof 0Ch    offset A4h
    float checkWaterCollBodyLen;                                      // sizeof 04h    offset B0h
    zCModelNodeInst* modelHeadNode;                                   // sizeof 04h    offset B4h
#pragma pack( push, 1 )
    group {
      unsigned char zMV_DO_SURFACE_ALIGN                         : 2; // sizeof 02h    offset bit
      unsigned char zMV_DO_DETECT_WALK_STOP_CHASM                : 1; // sizeof 01h    offset bit
      unsigned char zMV_DO_WALL_SLIDING                          : 1; // sizeof 01h    offset bit
      unsigned char zMV_DO_HEIGHT_CORRECTION                     : 1; // sizeof 01h    offset bit
      unsigned char cdStatOriginal                               : 1; // sizeof 01h    offset bit
      unsigned char cdStat                                       : 1; // sizeof 01h    offset bit
      unsigned char startFXModelLandDust                         : 1; // sizeof 01h    offset bit
      unsigned char forceModelHalt                               : 1; // sizeof 01h    offset bit
      unsigned char autoRollEnabled                              : 1; // sizeof 01h    offset bit
      unsigned char modelAnisInPlace                             : 1; // sizeof 01h    offset bit
      zTMovementState oldState                                   : 3; // sizeof 03h    offset bit
      zTMovementState state                                      : 3; // sizeof 03h    offset bit
      unsigned char oldWaterLevel                                : 2; // sizeof 02h    offset bit
      zCCollObjectCharacter::zEConfigState m_eCollObjectState    : 4; // sizeof 04h    offset bit
      zCCollObjectCharacter::zEConfigState m_eCollObjectStateOld : 4; // sizeof 04h    offset bit
    };
#pragma pack( pop )
    zCArray<zTBloodVobTrack> bloodVobList;                            // sizeof 0Ch    offset C4h
    float bleedingPerc;                                               // sizeof 04h    offset D0h
    zVEC3 bleedingLastPos;                                            // sizeof 0Ch    offset D4h
    float bleedingNextDist;                                           // sizeof 04h    offset E0h
    zCVob* weaponTrailVob;                                            // sizeof 04h    offset E4h
    zCVob* waterRingVob;                                              // sizeof 04h    offset E8h
    float waterRingTimer;                                             // sizeof 04h    offset ECh
    float autoRollPos;                                                // sizeof 04h    offset F0h
    float autoRollPosDest;                                            // sizeof 04h    offset F4h
    float autoRollSpeed;                                              // sizeof 04h    offset F8h
    float autoRollMaxAngle;                                           // sizeof 04h    offset FCh
    unsigned char dummyLastVar;                                       // sizeof 01h    offset 100h
    zSTRING bloodDefaultTexName;                                      // sizeof 14h    offset 104h

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