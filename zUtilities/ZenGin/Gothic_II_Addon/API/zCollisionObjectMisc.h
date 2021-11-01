// Supported with union (c) 2018-2021 Union team

#ifndef __ZCOLLISION_OBJECT_MISC_H__VER3__
#define __ZCOLLISION_OBJECT_MISC_H__VER3__

#include "zRayCache.h"

namespace Gothic_II_Addon {

  // sizeof 8Ch
  class zCCollObjectBase : public zCCollisionObject {
  public:

    zCCollObjectBase() {}
    static float __fastcall S_CalcAdaptiveCollStepFromVisualBBox( zCVisual* )                                      zCall( 0x0054E9D0 );
    static void __fastcall S_CalcGeneric_CollNormal_ContactPoint( zCVob const*, zCVob const*, zCCollisionReport& ) zCall( 0x0054EA50 );
    static void __fastcall S_RegisterCollisionTestFuncs( zCCollisionDetector* )                                    zCall( 0x0054EC60 );
    virtual ~zCCollObjectBase()                                                                                    zCall( 0x0054D7A0 );
    virtual void __fastcall GetLargestBBox3DLocal( zTBBox3D& )                                                     zCall( 0x0054EBD0 );

    // user API
    #include "zCCollObjectBase.inl"
  };

  // sizeof 8Ch
  class zCCollObjectUndef : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectUndef )

    zCCollObjectUndef() {}
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x0054D600 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x0054D640 );
    virtual ~zCCollObjectUndef()                          zCall( 0x0054D670 );

    // user API
    #include "zCCollObjectUndef.inl"
  };

  // sizeof 8Ch
  class zCCollObjectPoint : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectPoint )

    zCCollObjectPoint() {}
    zVEC3 __fastcall GetCenterOffsetLocal() const                                                                    zCall( 0x0054DE90 );
    zVEC3 __fastcall GetCenterOffsetNew() const                                                                      zCall( 0x0054DF10 );
    void __fastcall SetUpVectorNew( zVEC3 const& )                                                                   zCall( 0x0054E070 );
    static zCCollisionObject* _CreateNewInstance()                                                                   zCall( 0x0054D890 );
    virtual zCCollisionObjectDef* GetCollObjClass() const                                                            zCall( 0x0054D8D0 );
    virtual ~zCCollObjectPoint()                                                                                     zCall( 0x0054D900 );
    virtual void __fastcall DetectCollisionsSelf( zCArray<zCCollisionObject*> const&, zCArray<zCCollisionReport*>& ) zCall( 0x0054E290 );
    virtual void __fastcall CollisionResponse( zCArray<zCCollisionReport*> const&, int& )                            zCall( 0x0054DCC0 );
    virtual void __fastcall GetLargestBBox3DLocal( zTBBox3D& )                                                       zCall( 0x0054DC20 );

    // user API
    #include "zCCollObjectPoint.inl"
  };

  // sizeof 8Ch
  class zCCollObjectProjectile : public zCCollObjectPoint {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectProjectile )

    zCCollObjectProjectile() {}
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x0054D950 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x0054D990 );
    virtual ~zCCollObjectProjectile()                     zCall( 0x0054D9C0 );

    // user API
    #include "zCCollObjectProjectile.inl"
  };

  // sizeof 8Ch
  class zCCollObjectComplex : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectComplex )

    zCCollObjectComplex() {}
    static zCCollisionObject* _CreateNewInstance()                                        zCall( 0x0054DA10 );
    virtual zCCollisionObjectDef* GetCollObjClass() const                                 zCall( 0x0054DA50 );
    virtual ~zCCollObjectComplex()                                                        zCall( 0x0054DA80 );
    virtual void __fastcall CollisionResponse( zCArray<zCCollisionReport*> const&, int& ) zCall( 0x0054E320 );
    virtual float __fastcall GetAdaptiveStepSize()                                        zCall( 0x0054E2A0 );

    // user API
    #include "zCCollObjectComplex.inl"
  };

  // sizeof 98h
  class zCCollObjectLevelPolys : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectLevelPolys )

    zCArray<zCPolygon*> m_aoPolyList; // sizeof 0Ch    offset 8Ch

    void zCCollObjectLevelPolys_OnInit()                  zCall( 0x0061ED80 );
    zCCollObjectLevelPolys()                              zInit( zCCollObjectLevelPolys_OnInit() );
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x0054D6C0 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x0054D710 );
    virtual ~zCCollObjectLevelPolys()                     zCall( 0x0054D740 );

    // user API
    #include "zCCollObjectLevelPolys.inl"
  };

  // sizeof 8Ch
  class zCCollObjectBoxPassThrough : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectBoxPassThrough )

    zCCollObjectBoxPassThrough() {}
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x0054DB90 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x0054DBD0 );
    virtual ~zCCollObjectBoxPassThrough()                 zCall( 0x0054DC10 );
    virtual int __fastcall SuppressCollisionResponse()    zCall( 0x0054DBE0 );

    // user API
    #include "zCCollObjectBoxPassThrough.inl"
  };

  // sizeof 8Ch
  class zCCollObjectBoxBlocker : public zCCollObjectBase {
  public:
    zCOLLISION_OBJECT_DECLARATION( zCCollObjectBoxBlocker )

    zCCollObjectBoxBlocker() {}
    static zCCollisionObject* _CreateNewInstance()        zCall( 0x0054DAD0 );
    virtual zCCollisionObjectDef* GetCollObjClass() const zCall( 0x0054DB10 );
    virtual ~zCCollObjectBoxBlocker()                     zCall( 0x0054DB40 );

    // user API
    #include "zCCollObjectBoxBlocker.inl"
  };

  // sizeof 13Ch
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

    // sizeof 10h
    struct zTConfig {
      float m_fMaxGroundAngleWalk;                       // sizeof 04h    offset 00h
      float m_fStepHeight;                               // sizeof 04h    offset 04h
      group {
        unsigned char m_bTreatWaterAsSolid          : 1; // sizeof 01h    offset bit
        unsigned char m_bDoWallSliding              : 1; // sizeof 01h    offset bit
        unsigned char m_bUseSpacingRays             : 1; // sizeof 01h    offset bit
        unsigned char m_bLiftSpacingRayStart        : 1; // sizeof 01h    offset bit
        unsigned char m_bFloorTooLowIsHardCollision : 1; // sizeof 01h    offset bit
        unsigned char m_eDoHeightCorrection         : 1; // sizeof 01h    offset bit
        unsigned char m_eDoHeightCorrectionSmooth   : 1; // sizeof 01h    offset bit
        zEConfigState m_eState                      : 4; // sizeof 04h    offset bit
      };

      zTConfig() {}

      // user API
      #include "zCCollObjectCharacter_zTConfig.inl"
    };

    // sizeof 20h
    struct zTSpatialState {
      float m_fFloorY;                     // sizeof 04h    offset 00h
      float m_fWaterY;                     // sizeof 04h    offset 04h
      float m_fCeilingY;                   // sizeof 04h    offset 08h
      float m_fLastFloorY;                 // sizeof 04h    offset 0Ch
      zCPolygon* m_poFloorPoly;            // sizeof 04h    offset 10h
      zCPolygon* m_poWaterPoly;            // sizeof 04h    offset 14h
      zCPolygon* m_poCeilingPoly;          // sizeof 04h    offset 18h
      group {
        unsigned char m_bFloorIsStair : 1; // sizeof 01h    offset bit
        unsigned char m_bFloorIsVob   : 1; // sizeof 01h    offset bit
        unsigned char m_bIsUninited   : 1; // sizeof 01h    offset bit
      };

      zTSpatialState() {}

      // user API
      #include "zCCollObjectCharacter_zTSpatialState.inl"
    };

    // sizeof 30h
    struct zTInterferenceReport {
      // sizeof 01h
      struct zTInterferenceReportDummy0 {
        unsigned char spacingRayFront     : 1; // sizeof 01h    offset bit
        unsigned char spacingRayBack      : 1; // sizeof 01h    offset bit
        unsigned char spacingRayLeft      : 1; // sizeof 01h    offset bit
        unsigned char spacingRayRight     : 1; // sizeof 01h    offset bit
        unsigned char spacingRayWallSlide : 1; // sizeof 01h    offset bit
      };

      // sizeof 01h
      struct zTInterferenceReportDummy1 {
        unsigned char lowCeiling        : 1; // sizeof 01h    offset bit
        unsigned char floorTooSteepUp   : 1; // sizeof 01h    offset bit
        unsigned char floorTooSteepDown : 1; // sizeof 01h    offset bit
        unsigned char floorTooHigh      : 1; // sizeof 01h    offset bit
        unsigned char floorTooLow       : 1; // sizeof 01h    offset bit
        unsigned char centerRayCollided : 1; // sizeof 01h    offset bit
        unsigned char blockingWallSlide : 1; // sizeof 01h    offset bit
      };

      zCPolygon* spacingRayFrontPoly;        // sizeof 04h    offset 00h
      zCVob* spacingRayFrontVob;             // sizeof 04h    offset 04h
      zCPolygon* spacingRayBackPoly;         // sizeof 04h    offset 08h
      zCVob* spacingRayBackVob;              // sizeof 04h    offset 0Ch
      zCPolygon* spacingRayLeftPoly;         // sizeof 04h    offset 10h
      zCVob* spacingRayLeftVob;              // sizeof 04h    offset 14h
      zCPolygon* spacingRayRightPoly;        // sizeof 04h    offset 18h
      zCVob* spacingRayRightVob;             // sizeof 04h    offset 1Ch
      zTInterferenceReportDummy0 correction; // sizeof 01h    offset 20h
      zTInterferenceReportDummy1 blocking;   // sizeof 01h    offset 21h
      zVEC3 collisionNormal;                 // sizeof 0Ch    offset 24h

      zTInterferenceReport() {}

      // user API
      #include "zCCollObjectCharacter_zTInterferenceReport.inl"
    };

    zCRayCache m_oUpRayCache;                   // sizeof 08h    offset 8Ch
    zCRayCache m_oDownRayCache;                 // sizeof 08h    offset 94h
    zCRayCache m_oFrontRayCache;                // sizeof 08h    offset 9Ch
    zCRayCache m_oBackRayCache;                 // sizeof 08h    offset A4h
    zCRayCache m_oLeftRayCache;                 // sizeof 08h    offset ACh
    zCRayCache m_oRightRayCache;                // sizeof 08h    offset B4h
    zCConvexPrimitive* m_poPrimitiveCC;         // sizeof 04h    offset BCh
    zTSpatialState m_oSpatialState;             // sizeof 20h    offset C0h
    float m_fFeetYLocal;                        // sizeof 04h    offset E0h
    float m_fHeadYLocal;                        // sizeof 04h    offset E4h
    float m_fWallSlideTimer;                    // sizeof 04h    offset E8h
    float m_fWallSlideRotDir;                   // sizeof 04h    offset ECh
    zVEC3 m_oWallSlideRotAxis;                  // sizeof 0Ch    offset F0h
    zTConfig m_oConfig;                         // sizeof 10h    offset FCh
    zTInterferenceReport m_oInterferenceReport; // sizeof 30h    offset 10Ch

    void zCCollObjectCharacter_OnInit()                                                                              zCall( 0x0054F730 );
    int __fastcall IsMoveInvalid( zVEC3 const&, zVEC3 const&, zVEC3&, zTSpatialState&, zVEC3& )                      zCall( 0x00511060 );
    zCCollObjectCharacter()                                                                                          zInit( zCCollObjectCharacter_OnInit() );
    void __fastcall GetFallbackTrafoCC( zMAT4 const&, zMAT4 const&, zVEC3 const&, int, zMAT4& ) const                zCall( 0x0054FAF0 );
    void __fastcall GetCollisionPoleYDims( float&, float& ) const                                                    zCall( 0x00550840 );
    int __fastcall CalcSlideVector( zVEC3 const&, zVEC3 const&, zVEC3&, zVEC3&, float& )                             zCall( 0x00550870 );
    void __fastcall DoWallSlidingLatentRotation( zMAT4& )                                                            zCall( 0x00550D50 );
    void __fastcall FindFloorWaterCeiling( zVEC3 const&, zTSpatialState& )                                           zCall( 0x00550E20 );
    void MarkSpatialStateAsUninited( int )                                                                           zCall( 0x00551100 );
    int __fastcall TestHardCollisions( zVEC3 const&, zVEC3 const&, zVEC3&, zTSpatialState&, zVEC3& )                 zCall( 0x00551150 );
    zVEC3 __fastcall GetSurfaceAlignScanOrigin( zVEC3 const& )                                                       zCall( 0x00552060 );
    int __fastcall TestSoftCollisions( zVEC3 const&, zVEC3 const&, zVEC3&, zVEC3& )                                  zCall( 0x00552180 );
    void __fastcall PrintDebugInfos()                                                                                zCall( 0x00553C60 );
    static zCCollisionObject* _CreateNewInstance()                                                                   zCall( 0x0054D7F0 );
    static zVEC3 __fastcall S_SlideCC( zVEC3 const&, float, zVEC3 const& )                                           zCall( 0x0054FF10 );
    static int __fastcall S_CalcAvgNormalVariance( zTTraceRayReport const(& )[4], zVEC3&, float& )                   zCall( 0x00551EC0 );
    virtual zCCollisionObjectDef* GetCollObjClass() const                                                            zCall( 0x0054F8E0 );
    virtual ~zCCollObjectCharacter()                                                                                 zCall( 0x0054F950 );
    virtual void __fastcall DetectCollisionsSelf( zCArray<zCCollisionObject*> const&, zCArray<zCCollisionReport*>& ) zCall( 0x00553230 );
    virtual void __fastcall CollisionResponse( zCArray<zCCollisionReport*> const&, int& )                            zCall( 0x005537A0 );
    virtual float __fastcall GetAdaptiveStepSize()                                                                   zCall( 0x00553C20 );
    virtual void __fastcall GetLargestBBox3DLocal( zTBBox3D& )                                                       zCall( 0x00553C00 );
    virtual zCConvexPrimitive* GetPrimitiveCC() const                                                                zCall( 0x0054FA10 );
    virtual int IsDead() const                                                                                       zCall( 0x0054F8F0 );
    virtual int DontLetHimComeNearer( zCVob const* ) const                                                           zCall( 0x0054F900 );
    virtual float TurnSpeed() const                                                                                  zCall( 0x0054F910 );
    virtual void PushAround( zVEC3 const& )                                                                          zCall( 0x0054F920 );

    // user API
    #include "zCCollObjectCharacter.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZCOLLISION_OBJECT_MISC_H__VER3__