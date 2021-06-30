// Supported with union (c) 2018 Union team

#ifndef __ZBVOLUME_H__VER0__
#define __ZBVOLUME_H__VER0__

namespace Gothic_I_Classic {

  struct zTBSphere3D {
    zVEC3 center;
    float radius;

    zTBSphere3D() {}
    int IsIntersecting( zVEC3 const&, zVEC3 const& ) const zCall( 0x005303E0 );
    int ClassifyPlane( zTPlane ) const                     zCall( 0x005304F0 );
    void Draw( zCOLOR const& ) const                       zCall( 0x00530540 );

    // user API
    #include "zTBSphere3D.inl"
  };

  struct zTBBox2D {
    zVEC2 mins;
    zVEC2 maxs;

    void zTBBox2D_OnInit()                zCall( 0x00523DE0 );
    zTBBox2D()                            zInit( zTBBox2D_OnInit() );
    int Classify( zTBBox2D const& ) const zCall( 0x00532AC0 );
    void ClipToBBox2D( zTBBox2D const& )  zCall( 0x00532B70 );
    void Draw() const                     zCall( 0x00532BC0 );

    // user API
    #include "zTBBox2D.inl"
  };

  struct zTBBox3D {
    zVEC3 mins;
    zVEC3 maxs;

    void zTBBox3D_OnInit( zTBBox3D const& )                                                    zCall( 0x0051CDF0 );
    void zTBBox3D_OnInit()                                                                     zCall( 0x005487E0 );
    void AddPoint( zVEC3 const& )                                                              zCall( 0x0051A4B0 );
    zTBBox3D( zTBBox3D const& a0 )                                                             zInit( zTBBox3D_OnInit( a0 ));
    void Init()                                                                                zCall( 0x00530860 );
    void SetMaximumBox()                                                                       zCall( 0x00530880 );
    float GetVolume() const                                                                    zCall( 0x005308A0 );
    void CalcGreaterBBox3D( zTBBox3D const& )                                                  zCall( 0x005308C0 );
    void ClipToBBox3D( zTBBox3D const& )                                                       zCall( 0x00530920 );
    zSTRING GetDescription() const                                                             zCall( 0x005309A0 );
    void SetByDescription( zSTRING& )                                                          zCall( 0x00530D60 );
    void Transform( zMAT4 const&, zTBBox3D& ) const                                            zCall( 0x00531030 );
    void UnTransform( zMAT4 const&, zTBBox3D& ) const                                          zCall( 0x00531140 );
    int IsIntersectingSweep( zVEC3 const&, zTBBox3D const&, float& ) const                     zCall( 0x00531490 );
    int IsIntersectingSweep( zTBBox3D const&, zTBBox3D const&, zTBBox3D const&, float& ) const zCall( 0x00531630 );
    int IsTrivIn( zTBBox3D const& ) const                                                      zCall( 0x005316B0 );
    int IsTrivInLine( zVEC3 const&, zVEC3 const& ) const                                       zCall( 0x00531710 );
    int Classify( zTBBox3D const& ) const                                                      zCall( 0x005317F0 );
    zVEC3 GetNearestPoint( zTPlane const* const ) const                                        zCall( 0x005318B0 );
    void Scale( float )                                                                        zCall( 0x00531BA0 );
    void Scale( zVEC3 const& )                                                                 zCall( 0x00531BE0 );
    float GetMinExtent() const                                                                 zCall( 0x00531C30 );
    zTBSphere3D GetSphere3D() const                                                            zCall( 0x00531C70 );
    int TraceRay( zVEC3 const&, zVEC3 const&, zVEC3& ) const                                   zCall( 0x00531CF0 );
    void Draw( zCOLOR const& ) const                                                           zCall( 0x00531E90 );
    void GetCornerPoints( zVEC3* ) const                                                       zCall( 0x005321F0 );
    float GetScreenSize() const                                                                zCall( 0x00532360 );
    zTPlaneClass ClassifyToPlane( zTPlane const& ) const                                       zCall( 0x00532480 );
    zTPlaneClass ClassifyToPlane( zTPlane const&, int ) const                                  zCall( 0x00532570 );
    int ClassifyToPlaneSides( zTPlane const& ) const                                           zCall( 0x00532790 );
    int ClassifyToPlaneSides( zTPlane const&, int ) const                                      zCall( 0x00532860 );
    void SaveBIN( zCFileBIN& )                                                                 zCall( 0x00532A80 );
    void LoadBIN( zCFileBIN& )                                                                 zCall( 0x00532AA0 );
    zVEC3 GetCenterFloor() const                                                               zCall( 0x00539B90 );
    zVEC3 GetCenter() const                                                                    zCall( 0x0053A2A0 );
    void InitZero()                                                                            zCall( 0x005486F0 );
    zTBBox3D()                                                                                 zInit( zTBBox3D_OnInit() );
    int IsIntersecting( zTBBox3D const& ) const                                                zCall( 0x005D8320 );

    // user API
    #include "zTBBox3D.inl"
  };

  struct zTBCylinder3D {
    zVEC3 center;
    float radius;
    float heightY;

    zTBCylinder3D() {}
    int IsIntersecting( zTBCylinder3D const& ) const zCall( 0x00530220 );
    void Draw( zCOLOR const& ) const                 zCall( 0x00530290 );
    void SetByBBox3D( zTBBox3D )                     zCall( 0x00530340 );

    // user API
    #include "zTBCylinder3D.inl"
  };

  class zCOBBox3D {
  public:
    zVEC3 center;
    zVEC3 axis[3];
    zVEC3 extent;
    zCList<zCOBBox3D> childs;

    zCOBBox3D() {}
    ~zCOBBox3D()                                                     zCall( 0x00532C90 );
    void Draw( int, zCOLOR )                                         zCall( 0x00532D20 );
    void BuildOBB( int, zCPolygon**, int )                           zCall( 0x00533970 );
    void BuildRec( int, zCPolygon**, int )                           zCall( 0x005343B0 );
    void BuildOBBTree( zCMesh*, int )                                zCall( 0x005346F0 );
    void BuildOBBTree( int, zCPolygon**, int )                       zCall( 0x00534730 );
    int TestIntersectionOBB( zCOBBox3D const* ) const                zCall( 0x00534740 );
    int TestIntersectionTreeRec( zCOBBox3D const* ) const            zCall( 0x00534FF0 );
    int TestIntersectionTree( zCOBBox3D const*, zMAT4 const& ) const zCall( 0x005350D0 );
    int TraceRay( zVEC3 const&, zVEC3 const&, zVEC3& ) const         zCall( 0x00535100 );
    int CheckOBBPolyIntersection( zCPolygon*, zMAT4 const& ) const   zCall( 0x005352D0 );
    zTBBox3D GetBBox3D() const                                       zCall( 0x005355B0 );
    void SetByBBox3D( zTBBox3D const& )                              zCall( 0x005357B0 );
    void Transform( zMAT4 const& )                                   zCall( 0x005358B0 );
    zCOBBox3D& operator =( zCOBBox3D const& )                        zCall( 0x00535A10 );
    void SaveBIN( zCFileBIN& )                                       zCall( 0x00535B80 );
    void LoadBIN( zCFileBIN& )                                       zCall( 0x00535C10 );

    // static properties
    static zMAT4& trafoB2ToThis;

    // user API
    #include "zCOBBox3D.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZBVOLUME_H__VER0__