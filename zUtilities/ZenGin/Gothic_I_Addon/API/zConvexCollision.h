// Supported with union (c) 2018-2021 Union team

#ifndef __ZCONVEX_COLLISION_H__VER1__
#define __ZCONVEX_COLLISION_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 08h
  class zCCacheIndex {
  public:
    zCVob* voba; // sizeof 04h    offset 00h
    zCVob* vobb; // sizeof 04h    offset 04h

    zCCacheIndex() {}

    // user API
    #include "zCCacheIndex.inl"
  };

  // sizeof 10h
  class zCConvexCollisionCache {
  public:
    zMEMPOOL_DECLARATION( zCConvexCollisionCache, 0x008B9358 )

    zVEC3 planeNormal; // sizeof 0Ch    offset 00h
    int invert;        // sizeof 04h    offset 0Ch

    zCConvexCollisionCache() {}
    void zCConvexCollisionCache_OnInit( zCCacheIndex const& ) zCall( 0x00558050 );
    zCConvexCollisionCache( zCCacheIndex const& a0 )          zInit( zCConvexCollisionCache_OnInit( a0 ));

    // user API
    #include "zCConvexCollisionCache.inl"
  };

  // sizeof 1Ch
  class zCConvexPrimitive {
  public:
    zTBBox3D bbox3Dlocal; // sizeof 18h    offset 04h

    zCConvexPrimitive() {}
    void PointNearestToPlane( zVEC3&, zVEC3 const&, zMAT4 const&, zMAT3 const& ) const                                                                           zCall( 0x005571E0 );
    void Draw( zMAT4 const&, zCOLOR, zCCamera const* ) const                                                                                                     zCall( 0x005580A0 );
    static int CheckCollision( zCConvexPrimitive const*, zCConvexPrimitive const*, zMAT4 const&, zMAT4 const&, zCConvexCollisionCache*, zVEC3&, float&, zVEC3& ) zCall( 0x005572A0 );
    static float Distance( zCConvexPrimitive const*, zCConvexPrimitive const*, zMAT4 const&, zMAT4 const&, zVEC3 const&, zVEC3&, zVEC3& )                        zCall( 0x00557C90 );
    static zCConvexCollisionCache* GetCache( void const*, void const* )                                                                                          zCall( 0x00557EA0 );
    static void DrawLine( zVEC3 const&, zVEC3 const& )                                                                                                           zCall( 0x00558140 );
    static void DrawLineStrip( zVEC3 const& )                                                                                                                    zCall( 0x00558290 );
    virtual ~zCConvexPrimitive()                                                                                                                                 zCall( 0x00558770 );
    virtual void PointNearestToPlaneLocal( zVEC3 const&, zVEC3& ) const                                                                                          zPureCall;
    virtual void GetCenterLocal( zVEC3& ) const                                                                                                                  zCall( 0x005585B0 );
    virtual int PointIsInLocal( zVEC3 const& ) const                                                                                                             zPureCall;
    virtual int SymetrySphere() const                                                                                                                            zCall( 0x00558700 );
    virtual int SymetryRotation( zVEC3& ) const                                                                                                                  zCall( 0x00558710 );
    virtual void UpdateBBox()                                                                                                                                    zCall( 0x00558720 );
    virtual void DrawVirtual() const                                                                                                                             zCall( 0x00558360 );

    // user API
    #include "zCConvexPrimitive.inl"
  };

  // sizeof 1Ch
  class zCConvexPrimitiveUnitSphere : public zCConvexPrimitive {
  public:

    void zCConvexPrimitiveUnitSphere_OnInit()                           zCall( 0x00558560 );
    zCConvexPrimitiveUnitSphere()                                       zInit( zCConvexPrimitiveUnitSphere_OnInit() );
    virtual ~zCConvexPrimitiveUnitSphere()                              zCall( 0x005586F0 );
    virtual void PointNearestToPlaneLocal( zVEC3 const&, zVEC3& ) const zCall( 0x005585F0 );
    virtual int PointIsInLocal( zVEC3 const& ) const                    zCall( 0x005588E0 );
    virtual int SymetrySphere() const                                   zCall( 0x00558610 );
    virtual int SymetryRotation( zVEC3& ) const                         zCall( 0x00558620 );
    virtual void UpdateBBox()                                           zCall( 0x00558660 );
    virtual void DrawVirtual() const                                    zCall( 0x005587B0 );

    // static properties
    static zCConvexPrimitiveUnitSphere& s_unitSphere;

    // user API
    #include "zCConvexPrimitiveUnitSphere.inl"
  };

  // sizeof 38h
  class zCConvexPrimitiveScaleTrans : public zCConvexPrimitive {
  public:
    zVEC3 scale;                 // sizeof 0Ch    offset 1Ch
    zVEC3 translation;           // sizeof 0Ch    offset 28h
    zCConvexPrimitive* original; // sizeof 04h    offset 34h

    zCConvexPrimitiveScaleTrans() {}
    void zCConvexPrimitiveScaleTrans_OnInit( zCConvexPrimitive*, zVEC3 const&, zVEC3 const& ) zCall( 0x00558920 );
    zCConvexPrimitiveScaleTrans( zCConvexPrimitive* a0, zVEC3 const& a1, zVEC3 const& a2 )    zInit( zCConvexPrimitiveScaleTrans_OnInit( a0, a1, a2 ));
    virtual ~zCConvexPrimitiveScaleTrans()                                                    zCall( 0x005589D0 );
    virtual void PointNearestToPlaneLocal( zVEC3 const&, zVEC3& ) const                       zCall( 0x005589E0 );
    virtual void GetCenterLocal( zVEC3& ) const                                               zCall( 0x00558AE0 );
    virtual int PointIsInLocal( zVEC3 const& ) const                                          zCall( 0x00558A90 );
    virtual void UpdateBBox()                                                                 zCall( 0x00558B20 );
    virtual void DrawVirtual() const                                                          zCall( 0x00558B60 );

    // user API
    #include "zCConvexPrimitiveScaleTrans.inl"
  };

  // sizeof 3Ch
  class zCConvexPrimitiveEllipsoid : public zCConvexPrimitiveScaleTrans {
  public:
    int symetric; // sizeof 04h    offset 38h

    zCConvexPrimitiveEllipsoid() {}
    void zCConvexPrimitiveEllipsoid_OnInit( zTBBox3D const&, int ) zCall( 0x00558C10 );
    zCConvexPrimitiveEllipsoid( zTBBox3D const& a0, int a1 )       zInit( zCConvexPrimitiveEllipsoid_OnInit( a0, a1 ));
    void Snap()                                                    zCall( 0x00558E00 );
    virtual ~zCConvexPrimitiveEllipsoid()                          zCall( 0x00558DF0 );
    virtual int SymetryRotation( zVEC3& ) const                    zCall( 0x00558D80 );

    // user API
    #include "zCConvexPrimitiveEllipsoid.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZCONVEX_COLLISION_H__VER1__