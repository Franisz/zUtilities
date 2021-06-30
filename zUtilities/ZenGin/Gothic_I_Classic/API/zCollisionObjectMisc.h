// Supported with union (c) 2018 Union team

#ifndef __ZCOLLISION_OBJECT_MISC_H__VER0__
#define __ZCOLLISION_OBJECT_MISC_H__VER0__

namespace Gothic_I_Classic {

  class zCCollObjectBase : public zCCollisionObject {
  public:

    zCCollObjectBase() {}
    static float __fastcall S_CalcAdaptiveCollStepFromVisualBBox( zCVisual* )                                      zCall( 0x0053A4D0 );
    static void __fastcall S_CalcGeneric_CollNormal_ContactPoint( zCVob const*, zCVob const*, zCCollisionReport& ) zCall( 0x0053A550 );
    static void __fastcall S_RegisterCollisionTestFuncs( zCCollisionDetector* )                                    zCall( 0x0053A760 );
    virtual ~zCCollObjectBase()                                                                                    zCall( 0x005392E0 );
    virtual void __fastcall GetLargestBBox3DLocal( zTBBox3D& )                                                     zCall( 0x0053A6D0 );

    // user API
    #include "zCCollObjectBase.inl"
  };

  class zCCollObjectUndef : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectUndef )

    zCCollObjectUndef() {}
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x00539140 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x00539180 );
    virtual ~zCCollObjectUndef()                          zCall( 0x005391B0 );

    // user API
    #include "zCCollObjectUndef.inl"
  };

  class zCCollObjectPoint : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectPoint )

    zCCollObjectPoint() {}
    zVEC3 __fastcall GetCenterOffsetLocal() const                                                                    zCall( 0x005399E0 );
    zVEC3 __fastcall GetCenterOffsetNew() const                                                                      zCall( 0x00539A60 );
    void __fastcall SetUpVectorNew( zVEC3 const& )                                                                   zCall( 0x00539BC0 );
    static zCCollisionObject* _CreateNewInstance()                                                                   zCall( 0x005393E0 );
    virtual zCCollisionObjectDef* GetCollObjClass() const                                                            zCall( 0x00539420 );
    virtual ~zCCollObjectPoint()                                                                                     zCall( 0x00539450 );
    virtual void __fastcall DetectCollisionsSelf( zCArray<zCCollisionObject*> const&, zCArray<zCCollisionReport*>& ) zCall( 0x00539DE0 );
    virtual void __fastcall CollisionResponse( zCArray<zCCollisionReport*> const&, int& )                            zCall( 0x00539810 );
    virtual void __fastcall GetLargestBBox3DLocal( zTBBox3D& )                                                       zCall( 0x00539770 );

    // user API
    #include "zCCollObjectPoint.inl"
  };

  class zCCollObjectProjectile : public zCCollObjectPoint {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectProjectile )

    zCCollObjectProjectile() {}
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x005394A0 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x005394E0 );
    virtual ~zCCollObjectProjectile()                     zCall( 0x00539510 );

    // user API
    #include "zCCollObjectProjectile.inl"
  };

  class zCCollObjectComplex : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectComplex )

    zCCollObjectComplex() {}
    static zCCollisionObject* _CreateNewInstance()                                        zCall( 0x00539560 );
    virtual zCCollisionObjectDef* GetCollObjClass() const                                 zCall( 0x005395A0 );
    virtual ~zCCollObjectComplex()                                                        zCall( 0x005395D0 );
    virtual void __fastcall CollisionResponse( zCArray<zCCollisionReport*> const&, int& ) zCall( 0x00539E70 );
    virtual float __fastcall GetAdaptiveStepSize()                                        zCall( 0x00539DF0 );

    // user API
    #include "zCCollObjectComplex.inl"
  };

  class zCCollObjectLevelPolys : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectLevelPolys )

    zCArray<zCPolygon*> m_aoPolyList;

    void zCCollObjectLevelPolys_OnInit()                  zCall( 0x005F1800 );
    zCCollObjectLevelPolys()                              zInit( zCCollObjectLevelPolys_OnInit() );
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x00539200 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x00539250 );
    virtual ~zCCollObjectLevelPolys()                     zCall( 0x00539280 );

    // user API
    #include "zCCollObjectLevelPolys.inl"
  };

  class zCCollObjectBoxPassThrough : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectBoxPassThrough )

    zCCollObjectBoxPassThrough() {}
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x005396E0 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x00539720 );
    virtual ~zCCollObjectBoxPassThrough()                 zCall( 0x00539760 );
    virtual int __fastcall SuppressCollisionResponse()    zCall( 0x00539730 );

    // user API
    #include "zCCollObjectBoxPassThrough.inl"
  };

  class zCCollObjectBoxBlocker : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectBoxBlocker )

    zCCollObjectBoxBlocker() {}
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x00539620 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x00539660 );
    virtual ~zCCollObjectBoxBlocker()                     zCall( 0x00539690 );

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

    void zCCollObjectCharacter_OnInit()                                                                              zCall( 0x0053B230 );
    int __fastcall IsMoveInvalid( zVEC3 const&, zVEC3 const&, zVEC3&, zTSpatialState&, zVEC3& )                      zCall( 0x00501500 );
    zCCollObjectCharacter()                                                                                          zInit( zCCollObjectCharacter_OnInit() );
    void __fastcall GetFallbackTrafoCC( zMAT4 const&, zMAT4 const&, zVEC3 const&, int, zMAT4& ) const                zCall( 0x0053B600 );
    void __fastcall GetCollisionPoleYDims( float&, float& ) const                                                    zCall( 0x0053C350 );
    int __fastcall CalcSlideVector( zVEC3 const&, zVEC3 const&, zVEC3&, zVEC3&, float& )                             zCall( 0x0053C380 );
    void __fastcall DoWallSlidingLatentRotation( zMAT4& )                                                            zCall( 0x0053C860 );
    void __fastcall FindFloorWaterCeiling( zVEC3 const&, zTSpatialState& )                                           zCall( 0x0053C930 );
    void MarkSpatialStateAsUninited( int )                                                                           zCall( 0x0053CC10 );
    int __fastcall TestHardCollisions( zVEC3 const&, zVEC3 const&, zVEC3&, zTSpatialState&, zVEC3& )                 zCall( 0x0053CC60 );
    zVEC3 __fastcall GetSurfaceAlignScanOrigin( zVEC3 const& )                                                       zCall( 0x0053D940 );
    int __fastcall TestSoftCollisions( zVEC3 const&, zVEC3 const&, zVEC3&, zVEC3& )                                  zCall( 0x0053DA60 );
    void __fastcall PrintDebugInfos()                                                                                zCall( 0x0053F510 );
    static zCCollisionObject* _CreateNewInstance()                                                                   zCall( 0x00539330 );
    static zVEC3 __fastcall S_SlideCC( zVEC3 const&, float, zVEC3 const& )                                           zCall( 0x0053BA20 );
    static int __fastcall S_CalcAvgNormalVariance( zTTraceRayReport const(& )[4], zVEC3&, float& )                   zCall( 0x0053D7A0 );
    virtual zCCollisionObjectDef* GetCollObjClass() const                                                            zCall( 0x0053B3E0 );
    virtual ~zCCollObjectCharacter()                                                                                 zCall( 0x0053B450 );
    virtual void __fastcall DetectCollisionsSelf( zCArray<zCCollisionObject*> const&, zCArray<zCCollisionReport*>& ) zCall( 0x0053EB00 );
    virtual void __fastcall CollisionResponse( zCArray<zCCollisionReport*> const&, int& )                            zCall( 0x0053F060 );
    virtual float __fastcall GetAdaptiveStepSize()                                                                   zCall( 0x0053F4D0 );
    virtual void __fastcall GetLargestBBox3DLocal( zTBBox3D& )                                                       zCall( 0x0053F4B0 );
    virtual zCConvexPrimitive* GetPrimitiveCC() const                                                                zCall( 0x0053B510 );
    virtual int IsDead() const                                                                                       zCall( 0x0053B3F0 );
    virtual int DontLetHimComeNearer( zCVob const* ) const                                                           zCall( 0x0053B400 );
    virtual float TurnSpeed() const                                                                                  zCall( 0x0053B410 );
    virtual void PushAround( zVEC3 const& )                                                                          zCall( 0x0053B420 );

    // user API
    #include "zCCollObjectCharacter.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZCOLLISION_OBJECT_MISC_H__VER0__