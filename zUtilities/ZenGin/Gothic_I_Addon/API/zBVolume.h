// Supported with union (c) 2018 Union team

#ifndef __ZBVOLUME_H__VER1__
#define __ZBVOLUME_H__VER1__

namespace Gothic_I_Addon {

  struct zTBSphere3D {
    zVEC3 center;
    float radius;

    zTBSphere3D() {}
    int IsIntersecting( zVEC3 const&, zVEC3 const& ) const zCall( 0x00546C10 );
    int ClassifyPlane( zTPlane ) const                     zCall( 0x00546D70 );
    void Draw( zCOLOR const& ) const                       zCall( 0x00546DC0 );

    // user API
    #include "zTBSphere3D.inl"
  };

  struct zTBBox2D {
    zVEC2 mins;
    zVEC2 maxs;

    void zTBBox2D_OnInit()                zCall( 0x0053A0F0 );
    zTBBox2D()                            zInit( zTBBox2D_OnInit() );
    int Classify( zTBBox2D const& ) const zCall( 0x00549610 );
    void ClipToBBox2D( zTBBox2D const& )  zCall( 0x005496C0 );
    void Draw() const                     zCall( 0x00549710 );

    // user API
    #include "zTBBox2D.inl"
  };

  struct zTBBox3D {
    zVEC3 mins;
    zVEC3 maxs;

    void zTBBox3D_OnInit( zTBBox3D const& )                                                    zCall( 0x00532B30 );
    void zTBBox3D_OnInit()                                                                     zCall( 0x00558D70 );
    void AddPoint( zVEC3 const& )                                                              zCall( 0x00530170 );
    zTBBox3D( zTBBox3D const& a0 )                                                             zInit( zTBBox3D_OnInit( a0 ));
    void Init()                                                                                zCall( 0x00547130 );
    void SetMaximumBox()                                                                       zCall( 0x00547150 );
    float GetVolume() const                                                                    zCall( 0x00547170 );
    void CalcGreaterBBox3D( zTBBox3D const& )                                                  zCall( 0x00547190 );
    void ClipToBBox3D( zTBBox3D const& )                                                       zCall( 0x005471F0 );
    zSTRING GetDescription() const                                                             zCall( 0x00547270 );
    void SetByDescription( zSTRING& )                                                          zCall( 0x005476A0 );
    void Transform( zMAT4 const&, zTBBox3D& ) const                                            zCall( 0x005479E0 );
    void UnTransform( zMAT4 const&, zTBBox3D& ) const                                          zCall( 0x00547AF0 );
    int IsIntersectingSweep( zVEC3 const&, zTBBox3D const&, float& ) const                     zCall( 0x00547ED0 );
    int IsIntersectingSweep( zTBBox3D const&, zTBBox3D const&, zTBBox3D const&, float& ) const zCall( 0x00548060 );
    int IsTrivIn( zTBBox3D const& ) const                                                      zCall( 0x005480F0 );
    int IsTrivInLine( zVEC3 const&, zVEC3 const& ) const                                       zCall( 0x00548150 );
    int Classify( zTBBox3D const& ) const                                                      zCall( 0x00548230 );
    zVEC3 GetNearestPoint( zTPlane const* const ) const                                        zCall( 0x005482F0 );
    void Scale( float )                                                                        zCall( 0x005485E0 );
    void Scale( zVEC3 const& )                                                                 zCall( 0x00548620 );
    float GetMinExtent() const                                                                 zCall( 0x00548670 );
    zTBSphere3D GetSphere3D() const                                                            zCall( 0x005486B0 );
    int TraceRay( zVEC3 const&, zVEC3 const&, zVEC3& ) const                                   zCall( 0x00548730 );
    void Draw( zCOLOR const& ) const                                                           zCall( 0x005488F0 );
    void GetCornerPoints( zVEC3* ) const                                                       zCall( 0x00548CC0 );
    float GetScreenSize() const                                                                zCall( 0x00548E30 );
    zTPlaneClass ClassifyToPlane( zTPlane const& ) const                                       zCall( 0x00548F50 );
    zTPlaneClass ClassifyToPlane( zTPlane const&, int ) const                                  zCall( 0x00549040 );
    int ClassifyToPlaneSides( zTPlane const& ) const                                           zCall( 0x005492A0 );
    int ClassifyToPlaneSides( zTPlane const&, int ) const                                      zCall( 0x00549370 );
    void SaveBIN( zCFileBIN& )                                                                 zCall( 0x005495D0 );
    void LoadBIN( zCFileBIN& )                                                                 zCall( 0x005495F0 );
    zVEC3 GetCenterFloor() const                                                               zCall( 0x00550F10 );
    zVEC3 GetCenter() const                                                                    zCall( 0x00551470 );
    zTBBox3D()                                                                                 zInit( zTBBox3D_OnInit() );
    void InitZero()                                                                            zCall( 0x005606F0 );
    int IsIntersecting( zTBBox3D const& ) const                                                zCall( 0x005F7A10 );

    // user API
    #include "zTBBox3D.inl"
  };

  struct zTBCylinder3D {
    zVEC3 center;
    float radius;
    float heightY;

    zTBCylinder3D() {}
    int IsIntersecting( zTBCylinder3D const& ) const zCall( 0x00546A40 );
    void Draw( zCOLOR const& ) const                 zCall( 0x00546AB0 );
    void SetByBBox3D( zTBBox3D )                     zCall( 0x00546B60 );

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
    ~zCOBBox3D()                                                     zCall( 0x005497E0 );
    void Draw( int, zCOLOR )                                         zCall( 0x00549870 );
    void BuildOBB( int, zCPolygon**, int )                           zCall( 0x0054A5F0 );
    void BuildRec( int, zCPolygon**, int )                           zCall( 0x0054B0F0 );
    void BuildOBBTree( zCMesh*, int )                                zCall( 0x0054B470 );
    void BuildOBBTree( int, zCPolygon**, int )                       zCall( 0x0054B4B0 );
    int TestIntersectionOBB( zCOBBox3D const* ) const                zCall( 0x0054B4E0 );
    int TestIntersectionTreeRec( zCOBBox3D const* ) const            zCall( 0x0054BDE0 );
    int TestIntersectionTree( zCOBBox3D const*, zMAT4 const& ) const zCall( 0x0054BEC0 );
    int TraceRay( zVEC3 const&, zVEC3 const&, zVEC3& ) const         zCall( 0x0054BEF0 );
    int CheckOBBPolyIntersection( zCPolygon*, zMAT4 const& ) const   zCall( 0x0054C150 );
    zTBBox3D GetBBox3D() const                                       zCall( 0x0054C470 );
    void SetByBBox3D( zTBBox3D const& )                              zCall( 0x0054C740 );
    void Transform( zMAT4 const& )                                   zCall( 0x0054C860 );
    zCOBBox3D& operator =( zCOBBox3D const& )                        zCall( 0x0054C9E0 );
    void SaveBIN( zCFileBIN& )                                       zCall( 0x0054CB50 );
    void LoadBIN( zCFileBIN& )                                       zCall( 0x0054CBD0 );

    // static properties
    static zMAT4& trafoB2ToThis;

    // user API
    #include "zCOBBox3D.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZBVOLUME_H__VER1__