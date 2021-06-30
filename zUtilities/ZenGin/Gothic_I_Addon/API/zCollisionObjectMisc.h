// Supported with union (c) 2018 Union team

#ifndef __ZCOLLISION_OBJECT_MISC_H__VER1__
#define __ZCOLLISION_OBJECT_MISC_H__VER1__

namespace Gothic_I_Addon {

  class zCCollObjectBase : public zCCollisionObject {
  public:

    zCCollObjectBase() {}
    static float __fastcall S_CalcAdaptiveCollStepFromVisualBBox( zCVisual* )                                      zCall( 0x00551730 );
    static void __fastcall S_CalcGeneric_CollNormal_ContactPoint( zCVob const*, zCVob const*, zCCollisionReport& ) zCall( 0x005517B0 );
    static void __fastcall S_RegisterCollisionTestFuncs( zCCollisionDetector* )                                    zCall( 0x00551A30 );
    virtual ~zCCollObjectBase()                                                                                    zCall( 0x00550580 );
    virtual void __fastcall GetLargestBBox3DLocal( zTBBox3D& )                                                     zCall( 0x005519A0 );

    // user API
    #include "zCCollObjectBase.inl"
  };

  class zCCollObjectUndef : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectUndef )

    zCCollObjectUndef() {}
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x005503E0 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x00550420 );
    virtual ~zCCollObjectUndef()                          zCall( 0x00550450 );

    // user API
    #include "zCCollObjectUndef.inl"
  };

  class zCCollObjectPoint : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectPoint )

    zCCollObjectPoint() {}
    zVEC3 __fastcall GetCenterOffsetLocal() const                                                                    zCall( 0x00550C90 );
    zVEC3 __fastcall GetCenterOffsetNew() const                                                                      zCall( 0x00550D20 );
    void __fastcall SetUpVectorNew( zVEC3 const& )                                                                   zCall( 0x00550F50 );
    static zCCollisionObject* _CreateNewInstance()                                                                   zCall( 0x00550680 );
    virtual zCCollisionObjectDef* GetCollObjClass() const                                                            zCall( 0x005506C0 );
    virtual ~zCCollObjectPoint()                                                                                     zCall( 0x005506F0 );
    virtual void __fastcall DetectCollisionsSelf( zCArray<zCCollisionObject*> const&, zCArray<zCCollisionReport*>& ) zCall( 0x00550FE0 );
    virtual void __fastcall CollisionResponse( zCArray<zCCollisionReport*> const&, int& )                            zCall( 0x00550AC0 );
    virtual void __fastcall GetLargestBBox3DLocal( zTBBox3D& )                                                       zCall( 0x00550A10 );

    // user API
    #include "zCCollObjectPoint.inl"
  };

  class zCCollObjectProjectile : public zCCollObjectPoint {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectProjectile )

    zCCollObjectProjectile() {}
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x00550740 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x00550780 );
    virtual ~zCCollObjectProjectile()                     zCall( 0x005507B0 );

    // user API
    #include "zCCollObjectProjectile.inl"
  };

  class zCCollObjectComplex : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectComplex )

    zCCollObjectComplex() {}
    static zCCollisionObject* _CreateNewInstance()                                        zCall( 0x00550800 );
    virtual zCCollisionObjectDef* GetCollObjClass() const                                 zCall( 0x00550840 );
    virtual ~zCCollObjectComplex()                                                        zCall( 0x00550870 );
    virtual void __fastcall CollisionResponse( zCArray<zCCollisionReport*> const&, int& ) zCall( 0x00551080 );
    virtual float __fastcall GetAdaptiveStepSize()                                        zCall( 0x00550FF0 );

    // user API
    #include "zCCollObjectComplex.inl"
  };

  class zCCollObjectLevelPolys : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectLevelPolys )

    zCArray<zCPolygon*> m_aoPolyList;

    void zCCollObjectLevelPolys_OnInit()                  zCall( 0x00612560 );
    zCCollObjectLevelPolys()                              zInit( zCCollObjectLevelPolys_OnInit() );
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x005504A0 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x005504F0 );
    virtual ~zCCollObjectLevelPolys()                     zCall( 0x00550520 );

    // user API
    #include "zCCollObjectLevelPolys.inl"
  };

  class zCCollObjectBoxPassThrough : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectBoxPassThrough )

    zCCollObjectBoxPassThrough() {}
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x00550980 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x005509C0 );
    virtual ~zCCollObjectBoxPassThrough()                 zCall( 0x00550A00 );
    virtual int __fastcall SuppressCollisionResponse()    zCall( 0x005509D0 );

    // user API
    #include "zCCollObjectBoxPassThrough.inl"
  };

  class zCCollObjectBoxBlocker : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectBoxBlocker )

    zCCollObjectBoxBlocker() {}
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x005508C0 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x00550900 );
    virtual ~zCCollObjectBoxBlocker()                     zCall( 0x00550930 );

    // user API
    #include "zCCollObjectBoxBlocker.inl"
  };

  class zCCollObjectCharacter : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectCharacter )

    enum zEConfigState {
      zCONFIG_STATE_STAND,
      zCONFIG_STATE_FLY,
      zCONFIG_STATE_SLIDE,
      zCONFIG_STATE_SWIM,
      zCONFIG_STATE_DIVE
    };

    struct zTConfig {
      float m_fMaxGroundAngleWalk;
      float m_fStepHeight;
      group {
        unsigned char m_bTreatWaterAsSolid          : 1;
        unsigned char m_bDoWallSliding              : 1;
        unsigned char m_bUseSpacingRays             : 1;
        unsigned char m_bLiftSpacingRayStart        : 1;
        unsigned char m_bFloorTooLowIsHardCollision : 1;
        unsigned char m_eDoHeightCorrection         : 1;
        unsigned char m_eDoHeightCorrectionSmooth   : 1;
        zEConfigState m_eState                      : 4;
      };

      zTConfig() {}

      // user API
      #include "zCCollObjectCharacter_zTConfig.inl"
    };

    struct zTSpatialState {
      float m_fFloorY;
      float m_fWaterY;
      float m_fCeilingY;
      float m_fLastFloorY;
      zCPolygon* m_poFloorPoly;
      zCPolygon* m_poWaterPoly;
      zCPolygon* m_poCeilingPoly;
      group {
        unsigned char m_bFloorIsStair : 1;
        unsigned char m_bFloorIsVob   : 1;
        unsigned char m_bIsUninited   : 1;
      };

      zTSpatialState() {}

      // user API
      #include "zCCollObjectCharacter_zTSpatialState.inl"
    };

    struct zTInterferenceReport {
      struct zTInterferenceReportDummy0 {
        unsigned char spacingRayFront     : 1;
        unsigned char spacingRayBack      : 1;
        unsigned char spacingRayLeft      : 1;
        unsigned char spacingRayRight     : 1;
        unsigned char spacingRayWallSlide : 1;
      };

      struct zTInterferenceReportDummy1 {
        unsigned char lowCeiling        : 1;
        unsigned char floorTooSteepUp   : 1;
        unsigned char floorTooSteepDown : 1;
        unsigned char floorTooHigh      : 1;
        unsigned char floorTooLow       : 1;
        unsigned char centerRayCollided : 1;
        unsigned char blockingWallSlide : 1;
      };

      zCPolygon* spacingRayFrontPoly;
      zCVob* spacingRayFrontVob;
      zCPolygon* spacingRayBackPoly;
      zCVob* spacingRayBackVob;
      zCPolygon* spacingRayLeftPoly;
      zCVob* spacingRayLeftVob;
      zCPolygon* spacingRayRightPoly;
      zCVob* spacingRayRightVob;
      zTInterferenceReportDummy0 correction;
      zTInterferenceReportDummy1 blocking;
      zVEC3 collisionNormal;

      zTInterferenceReport() {}

      // user API
      #include "zCCollObjectCharacter_zTInterferenceReport.inl"
    };

    zCRayCache m_oUpRayCache;
    zCRayCache m_oDownRayCache;
    zCRayCache m_oFrontRayCache;
    zCRayCache m_oBackRayCache;
    zCRayCache m_oLeftRayCache;
    zCRayCache m_oRightRayCache;
    zCConvexPrimitive* m_poPrimitiveCC;
    zTSpatialState m_oSpatialState;
    float m_fFeetYLocal;
    float m_fHeadYLocal;
    float m_fWallSlideTimer;
    float m_fWallSlideRotDir;
    zVEC3 m_oWallSlideRotAxis;
    zTConfig m_oConfig;
    zTInterferenceReport m_oInterferenceReport;

    void zCCollObjectCharacter_OnInit()                                                                              zCall( 0x005525D0 );
    int __fastcall IsMoveInvalid( zVEC3 const&, zVEC3 const&, zVEC3&, zTSpatialState&, zVEC3& )                      zCall( 0x00514CB0 );
    zCCollObjectCharacter()                                                                                          zInit( zCCollObjectCharacter_OnInit() );
    void __fastcall GetFallbackTrafoCC( zMAT4 const&, zMAT4 const&, zVEC3 const&, int, zMAT4& ) const                zCall( 0x005529A0 );
    void __fastcall GetCollisionPoleYDims( float&, float& ) const                                                    zCall( 0x005538D0 );
    int __fastcall CalcSlideVector( zVEC3 const&, zVEC3 const&, zVEC3&, zVEC3&, float& )                             zCall( 0x00553900 );
    void __fastcall DoWallSlidingLatentRotation( zMAT4& )                                                            zCall( 0x00553E40 );
    void __fastcall FindFloorWaterCeiling( zVEC3 const&, zTSpatialState& )                                           zCall( 0x00553F10 );
    void MarkSpatialStateAsUninited( int )                                                                           zCall( 0x005541F0 );
    int __fastcall TestHardCollisions( zVEC3 const&, zVEC3 const&, zVEC3&, zTSpatialState&, zVEC3& )                 zCall( 0x00554250 );
    zVEC3 __fastcall GetSurfaceAlignScanOrigin( zVEC3 const& )                                                       zCall( 0x005550B0 );
    int __fastcall TestSoftCollisions( zVEC3 const&, zVEC3 const&, zVEC3&, zVEC3& )                                  zCall( 0x005552E0 );
    void __fastcall PrintDebugInfos()                                                                                zCall( 0x00556EE0 );
    static zCCollisionObject* _CreateNewInstance()                                                                   zCall( 0x005505D0 );
    static zVEC3 __fastcall S_SlideCC( zVEC3 const&, float, zVEC3 const& )                                           zCall( 0x00552E80 );
    static int __fastcall S_CalcAvgNormalVariance( zTTraceRayReport const(& )[4], zVEC3&, float& )                   zCall( 0x00554F10 );
    virtual zCCollisionObjectDef* GetCollObjClass() const                                                            zCall( 0x00552780 );
    virtual ~zCCollObjectCharacter()                                                                                 zCall( 0x005527F0 );
    virtual void __fastcall DetectCollisionsSelf( zCArray<zCCollisionObject*> const&, zCArray<zCCollisionReport*>& ) zCall( 0x005564D0 );
    virtual void __fastcall CollisionResponse( zCArray<zCCollisionReport*> const&, int& )                            zCall( 0x00556920 );
    virtual float __fastcall GetAdaptiveStepSize()                                                                   zCall( 0x00556EA0 );
    virtual void __fastcall GetLargestBBox3DLocal( zTBBox3D& )                                                       zCall( 0x00556E80 );
    virtual zCConvexPrimitive* GetPrimitiveCC() const                                                                zCall( 0x005528B0 );
    virtual int IsDead() const                                                                                       zCall( 0x00552790 );
    virtual int DontLetHimComeNearer( zCVob const* ) const                                                           zCall( 0x005527A0 );
    virtual float TurnSpeed() const                                                                                  zCall( 0x005527B0 );
    virtual void PushAround( zVEC3 const& )                                                                          zCall( 0x005527C0 );

    // user API
    #include "zCCollObjectCharacter.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZCOLLISION_OBJECT_MISC_H__VER1__