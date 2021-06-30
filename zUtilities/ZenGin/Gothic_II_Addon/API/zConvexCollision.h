// Supported with union (c) 2018 Union team

#ifndef __ZCONVEX_COLLISION_H__VER3__
#define __ZCONVEX_COLLISION_H__VER3__

namespace Gothic_II_Addon {

  class zCCacheIndex {
  public:
    zCVob* voba;
    zCVob* vobb;

    zCCacheIndex() {}

    // user API
    #include "zCCacheIndex.inl"
  };

  class zCConvexCollisionCache {
  public:
    zMEMPOOL_DECLARATION( zCConvexCollisionCache, 0x008D83D4 )

    zVEC3 planeNormal;
    int invert;

    zCConvexCollisionCache() {}
    void zCConvexCollisionCache_OnInit( zCCacheIndex const& ) zCall( 0x00554E20 );
    zCConvexCollisionCache( zCCacheIndex const& a0 )          zInit( zCConvexCollisionCache_OnInit( a0 ));

    // user API
    #include "zCConvexCollisionCache.inl"
  };

  class zCConvexPrimitive {
  public:
    zTBBox3D bbox3Dlocal;

    zCConvexPrimitive() {}
    void PointNearestToPlane( zVEC3&, zVEC3 const&, zMAT4 const&, zMAT3 const& ) const                                                                           zCall( 0x00553F60 );
    void Draw( zMAT4 const&, zCOLOR, zCCamera const* ) const                                                                                                     zCall( 0x00554E70 );
    static int CheckCollision( zCConvexPrimitive const*, zCConvexPrimitive const*, zMAT4 const&, zMAT4 const&, zCConvexCollisionCache*, zVEC3&, float&, zVEC3& ) zCall( 0x00554010 );
    static float Distance( zCConvexPrimitive const*, zCConvexPrimitive const*, zMAT4 const&, zMAT4 const&, zVEC3 const&, zVEC3&, zVEC3& )                        zCall( 0x00554A60 );
    static zCConvexCollisionCache* GetCache( void const*, void const* )                                                                                          zCall( 0x00554C20 );
    static void DrawLine( zVEC3 const&, zVEC3 const& )                                                                                                           zCall( 0x00554F50 );
    static void DrawLineStrip( zVEC3 const& )                                                                                                                    zCall( 0x00555090 );
    virtual ~zCConvexPrimitive()                                                                                                                                 zCall( 0x00555590 );
    virtual void PointNearestToPlaneLocal( zVEC3 const&, zVEC3& ) const                                                                                          zPureCall;
    virtual void GetCenterLocal( zVEC3& ) const                                                                                                                  zCall( 0x005553D0 );
    virtual int PointIsInLocal( zVEC3 const& ) const                                                                                                             zPureCall;
    virtual int SymetrySphere() const                                                                                                                            zCall( 0x00555520 );
    virtual int SymetryRotation( zVEC3& ) const                                                                                                                  zCall( 0x00555530 );
    virtual void UpdateBBox()                                                                                                                                    zCall( 0x00555540 );
    virtual void DrawVirtual() const                                                                                                                             zCall( 0x00555150 );

    // user API
    #include "zCConvexPrimitive.inl"
  };

  class zCConvexPrimitiveUnitSphere : public zCConvexPrimitive {
  public:

    void zCConvexPrimitiveUnitSphere_OnInit()                           zCall( 0x00555380 );
    zCConvexPrimitiveUnitSphere()                                       zInit( zCConvexPrimitiveUnitSphere_OnInit() );
    virtual ~zCConvexPrimitiveUnitSphere()                              zCall( 0x00555510 );
    virtual void PointNearestToPlaneLocal( zVEC3 const&, zVEC3& ) const zCall( 0x00555410 );
    virtual int PointIsInLocal( zVEC3 const& ) const                    zCall( 0x005556F0 );
    virtual int SymetrySphere() const                                   zCall( 0x00555430 );
    virtual int SymetryRotation( zVEC3& ) const                         zCall( 0x00555440 );
    virtual void UpdateBBox()                                           zCall( 0x00555480 );
    virtual void DrawVirtual() const                                    zCall( 0x005555D0 );

    // static properties
    static zCConvexPrimitiveUnitSphere& s_unitSphere;

    // user API
    #include "zCConvexPrimitiveUnitSphere.inl"
  };

  class zCConvexPrimitiveScaleTrans : public zCConvexPrimitive {
  public:
    zVEC3 scale;
    zVEC3 translation;
    zCConvexPrimitive* original;

    zCConvexPrimitiveScaleTrans() {}
    void zCConvexPrimitiveScaleTrans_OnInit( zCConvexPrimitive*, zVEC3 const&, zVEC3 const& ) zCall( 0x00555730 );
    zCConvexPrimitiveScaleTrans( zCConvexPrimitive* a0, zVEC3 const& a1, zVEC3 const& a2 )    zInit( zCConvexPrimitiveScaleTrans_OnInit( a0, a1, a2 ));
    virtual ~zCConvexPrimitiveScaleTrans()                                                    zCall( 0x005557E0 );
    virtual void PointNearestToPlaneLocal( zVEC3 const&, zVEC3& ) const                       zCall( 0x005557F0 );
    virtual void GetCenterLocal( zVEC3& ) const                                               zCall( 0x00555900 );
    virtual int PointIsInLocal( zVEC3 const& ) const                                          zCall( 0x005558B0 );
    virtual void UpdateBBox()                                                                 zCall( 0x00555940 );
    virtual void DrawVirtual() const                                                          zCall( 0x00555990 );

    // user API
    #include "zCConvexPrimitiveScaleTrans.inl"
  };

  class zCConvexPrimitiveEllipsoid : public zCConvexPrimitiveScaleTrans {
  public:
    int symetric;

    zCConvexPrimitiveEllipsoid() {}
    void zCConvexPrimitiveEllipsoid_OnInit( zTBBox3D const&, int ) zCall( 0x00555A40 );
    zCConvexPrimitiveEllipsoid( zTBBox3D const& a0, int a1 )       zInit( zCConvexPrimitiveEllipsoid_OnInit( a0, a1 ));
    void Snap()                                                    zCall( 0x00555C10 );
    virtual ~zCConvexPrimitiveEllipsoid()                          zCall( 0x00555C00 );
    virtual int SymetryRotation( zVEC3& ) const                    zCall( 0x00555B90 );

    // user API
    #include "zCConvexPrimitiveEllipsoid.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZCONVEX_COLLISION_H__VER3__