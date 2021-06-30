// Supported with union (c) 2018 Union team

#ifndef __ZCONVEX_COLLISION_H__VER2__
#define __ZCONVEX_COLLISION_H__VER2__

namespace Gothic_II_Classic {

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
    zMEMPOOL_DECLARATION( zCConvexCollisionCache, 0x008C9D54 )

    zVEC3 planeNormal;
    int invert;

    zCConvexCollisionCache() {}
    void zCConvexCollisionCache_OnInit( zCCacheIndex const& ) zCall( 0x0054FC00 );
    zCConvexCollisionCache( zCCacheIndex const& a0 )          zInit( zCConvexCollisionCache_OnInit( a0 ));

    // user API
    #include "zCConvexCollisionCache.inl"
  };

  class zCConvexPrimitive {
  public:
    zTBBox3D bbox3Dlocal;

    zCConvexPrimitive() {}
    void PointNearestToPlane( zVEC3&, zVEC3 const&, zMAT4 const&, zMAT3 const& ) const                                                                           zCall( 0x0054ED40 );
    void Draw( zMAT4 const&, zCOLOR, zCCamera const* ) const                                                                                                     zCall( 0x0054FC50 );
    static int CheckCollision( zCConvexPrimitive const*, zCConvexPrimitive const*, zMAT4 const&, zMAT4 const&, zCConvexCollisionCache*, zVEC3&, float&, zVEC3& ) zCall( 0x0054EDF0 );
    static float Distance( zCConvexPrimitive const*, zCConvexPrimitive const*, zMAT4 const&, zMAT4 const&, zVEC3 const&, zVEC3&, zVEC3& )                        zCall( 0x0054F840 );
    static zCConvexCollisionCache* GetCache( void const*, void const* )                                                                                          zCall( 0x0054FA00 );
    static void DrawLine( zVEC3 const&, zVEC3 const& )                                                                                                           zCall( 0x0054FD30 );
    static void DrawLineStrip( zVEC3 const& )                                                                                                                    zCall( 0x0054FE70 );
    virtual ~zCConvexPrimitive()                                                                                                                                 zCall( 0x00550370 );
    virtual void PointNearestToPlaneLocal( zVEC3 const&, zVEC3& ) const                                                                                          zPureCall;
    virtual void GetCenterLocal( zVEC3& ) const                                                                                                                  zCall( 0x005501B0 );
    virtual int PointIsInLocal( zVEC3 const& ) const                                                                                                             zPureCall;
    virtual int SymetrySphere() const                                                                                                                            zCall( 0x00550300 );
    virtual int SymetryRotation( zVEC3& ) const                                                                                                                  zCall( 0x00550310 );
    virtual void UpdateBBox()                                                                                                                                    zCall( 0x00550320 );
    virtual void DrawVirtual() const                                                                                                                             zCall( 0x0054FF30 );

    // user API
    #include "zCConvexPrimitive.inl"
  };

  class zCConvexPrimitiveUnitSphere : public zCConvexPrimitive {
  public:

    void zCConvexPrimitiveUnitSphere_OnInit()                           zCall( 0x00550160 );
    zCConvexPrimitiveUnitSphere()                                       zInit( zCConvexPrimitiveUnitSphere_OnInit() );
    virtual ~zCConvexPrimitiveUnitSphere()                              zCall( 0x005502F0 );
    virtual void PointNearestToPlaneLocal( zVEC3 const&, zVEC3& ) const zCall( 0x005501F0 );
    virtual int PointIsInLocal( zVEC3 const& ) const                    zCall( 0x005504D0 );
    virtual int SymetrySphere() const                                   zCall( 0x00550210 );
    virtual int SymetryRotation( zVEC3& ) const                         zCall( 0x00550220 );
    virtual void UpdateBBox()                                           zCall( 0x00550260 );
    virtual void DrawVirtual() const                                    zCall( 0x005503B0 );

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
    void zCConvexPrimitiveScaleTrans_OnInit( zCConvexPrimitive*, zVEC3 const&, zVEC3 const& ) zCall( 0x00550510 );
    zCConvexPrimitiveScaleTrans( zCConvexPrimitive* a0, zVEC3 const& a1, zVEC3 const& a2 )    zInit( zCConvexPrimitiveScaleTrans_OnInit( a0, a1, a2 ));
    virtual ~zCConvexPrimitiveScaleTrans()                                                    zCall( 0x005505C0 );
    virtual void PointNearestToPlaneLocal( zVEC3 const&, zVEC3& ) const                       zCall( 0x005505D0 );
    virtual void GetCenterLocal( zVEC3& ) const                                               zCall( 0x005506E0 );
    virtual int PointIsInLocal( zVEC3 const& ) const                                          zCall( 0x00550690 );
    virtual void UpdateBBox()                                                                 zCall( 0x00550720 );
    virtual void DrawVirtual() const                                                          zCall( 0x00550770 );

    // user API
    #include "zCConvexPrimitiveScaleTrans.inl"
  };

  class zCConvexPrimitiveEllipsoid : public zCConvexPrimitiveScaleTrans {
  public:
    int symetric;

    zCConvexPrimitiveEllipsoid() {}
    void zCConvexPrimitiveEllipsoid_OnInit( zTBBox3D const&, int ) zCall( 0x00550820 );
    zCConvexPrimitiveEllipsoid( zTBBox3D const& a0, int a1 )       zInit( zCConvexPrimitiveEllipsoid_OnInit( a0, a1 ));
    void Snap()                                                    zCall( 0x005509F0 );
    virtual ~zCConvexPrimitiveEllipsoid()                          zCall( 0x005509E0 );
    virtual int SymetryRotation( zVEC3& ) const                    zCall( 0x00550970 );

    // user API
    #include "zCConvexPrimitiveEllipsoid.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZCONVEX_COLLISION_H__VER2__