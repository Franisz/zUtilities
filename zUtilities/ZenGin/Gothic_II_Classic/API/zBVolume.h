// Supported with union (c) 2018 Union team

#ifndef __ZBVOLUME_H__VER2__
#define __ZBVOLUME_H__VER2__

namespace Gothic_II_Classic {

  struct zTBSphere3D {
    zVEC3 center;
    float radius;

    zTBSphere3D() {}
    int IsIntersecting( zVEC3 const&, zVEC3 const& ) const zCall( 0x0053EF20 );
    int IsIntersecting( zTBSphere3D const& ) const         zCall( 0x0053F030 );
    int ClassifyPlane( zTPlane ) const                     zCall( 0x0053F0F0 );
    void Draw( zCOLOR const& ) const                       zCall( 0x0053F140 );

    // user API
    #include "zTBSphere3D.inl"
  };

  struct zTBBox2D {
    zVEC2 mins;
    zVEC2 maxs;

    void zTBBox2D_OnInit()                zCall( 0x005345F0 );
    zTBBox2D()                            zInit( zTBBox2D_OnInit() );
    int Classify( zTBBox2D const& ) const zCall( 0x005418F0 );
    void ClipToBBox2D( zTBBox2D const& )  zCall( 0x005419A0 );
    void Draw() const                     zCall( 0x005419F0 );

    // user API
    #include "zTBBox2D.inl"
  };

  struct zTBBox3D {
    zVEC3 mins;
    zVEC3 maxs;

    void zTBBox3D_OnInit( zTBBox3D const& )                                                    zCall( 0x0052C760 );
    void zTBBox3D_OnInit()                                                                     zCall( 0x0053BD40 );
    void AddPoint( zVEC3 const& )                                                              zCall( 0x00529E40 );
    zTBBox3D( zTBBox3D const& a0 )                                                             zInit( zTBBox3D_OnInit( a0 ));
    void Init()                                                                                zCall( 0x0053BD10 );
    zTBBox3D()                                                                                 zInit( zTBBox3D_OnInit() );
    void SetMaximumBox()                                                                       zCall( 0x0053F460 );
    float GetVolume() const                                                                    zCall( 0x0053F480 );
    void CalcGreaterBBox3D( zTBBox3D const& )                                                  zCall( 0x0053F4A0 );
    void ClipToBBox3D( zTBBox3D const& )                                                       zCall( 0x0053F500 );
    zSTRING GetDescription() const                                                             zCall( 0x0053F580 );
    void SetByDescription( zSTRING& )                                                          zCall( 0x0053FB90 );
    void Transform( zMAT4 const&, zTBBox3D& ) const                                            zCall( 0x0053FE60 );
    void UnTransform( zMAT4 const&, zTBBox3D& ) const                                          zCall( 0x0053FF70 );
    int IsIntersectingSweep( zVEC3 const&, zTBBox3D const&, float& ) const                     zCall( 0x005402C0 );
    int IsIntersectingSweep( zTBBox3D const&, zTBBox3D const&, zTBBox3D const&, float& ) const zCall( 0x00540460 );
    int IsTrivIn( zTBBox3D const& ) const                                                      zCall( 0x005404E0 );
    int IsTrivInLine( zVEC3 const&, zVEC3 const& ) const                                       zCall( 0x00540540 );
    int Classify( zTBBox3D const& ) const                                                      zCall( 0x00540620 );
    zVEC3 GetNearestPoint( zTPlane const* const ) const                                        zCall( 0x005406E0 );
    void Scale( float )                                                                        zCall( 0x005409D0 );
    void Scale( zVEC3 const& )                                                                 zCall( 0x00540A10 );
    float GetMinExtent() const                                                                 zCall( 0x00540A60 );
    zTBSphere3D GetSphere3D() const                                                            zCall( 0x00540AA0 );
    int TraceRay( zVEC3 const&, zVEC3 const&, zVEC3& ) const                                   zCall( 0x00540B20 );
    void Draw( zCOLOR const& ) const                                                           zCall( 0x00540CC0 );
    void GetCornerPoints( zVEC3* ) const                                                       zCall( 0x00541020 );
    float GetScreenSize() const                                                                zCall( 0x00541190 );
    zTPlaneClass ClassifyToPlane( zTPlane const& ) const                                       zCall( 0x005412B0 );
    zTPlaneClass ClassifyToPlane( zTPlane const&, int ) const                                  zCall( 0x005413A0 );
    int ClassifyToPlaneSides( zTPlane const& ) const                                           zCall( 0x005415C0 );
    int ClassifyToPlaneSides( zTPlane const&, int ) const                                      zCall( 0x00541690 );
    void SaveBIN( zCFileBIN& )                                                                 zCall( 0x005418B0 );
    void LoadBIN( zCFileBIN& )                                                                 zCall( 0x005418D0 );
    zVEC3 GetCenterFloor() const                                                               zCall( 0x00548E20 );
    zVEC3 GetCenter() const                                                                    zCall( 0x00549580 );
    void InitZero()                                                                            zCall( 0x0055A1B0 );
    int IsIntersecting( zTBSphere3D const& ) const                                             zCall( 0x005CE3B0 );
    int IsIntersecting( zTBBox3D const& ) const                                                zCall( 0x005FCB40 );

    // user API
    #include "zTBBox3D.inl"
  };

  struct zTBCylinder3D {
    zVEC3 center;
    float radius;
    float heightY;

    zTBCylinder3D() {}
    int IsIntersecting( zTBCylinder3D const& ) const zCall( 0x0053ED60 );
    void Draw( zCOLOR const& ) const                 zCall( 0x0053EDD0 );
    void SetByBBox3D( zTBBox3D )                     zCall( 0x0053EE80 );

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
    ~zCOBBox3D()                                                     zCall( 0x00541AC0 );
    void Draw( int, zCOLOR )                                         zCall( 0x00541B50 );
    void BuildOBB( int, zCPolygon**, int )                           zCall( 0x005427A0 );
    void BuildRec( int, zCPolygon**, int )                           zCall( 0x005431D0 );
    void BuildOBBTree( zCMesh*, int )                                zCall( 0x00543500 );
    void BuildOBBTree( int, zCPolygon**, int )                       zCall( 0x00543540 );
    int TestIntersectionOBB( zCOBBox3D const* ) const                zCall( 0x00543550 );
    int TestIntersectionTreeRec( zCOBBox3D const* ) const            zCall( 0x00543DF0 );
    int TestIntersectionTree( zCOBBox3D const*, zMAT4 const& ) const zCall( 0x00543ED0 );
    int TraceRay( zVEC3 const&, zVEC3 const&, zVEC3& ) const         zCall( 0x00543F00 );
    int CheckOBBPolyIntersection( zCPolygon*, zMAT4 const& ) const   zCall( 0x005440D0 );
    zTBBox3D GetBBox3D() const                                       zCall( 0x00544370 );
    void SetByBBox3D( zTBBox3D const& )                              zCall( 0x00544570 );
    void Transform( zMAT4 const& )                                   zCall( 0x00544670 );
    zCOBBox3D& operator =( zCOBBox3D const& )                        zCall( 0x005447D0 );
    void SaveBIN( zCFileBIN& )                                       zCall( 0x00544920 );
    void LoadBIN( zCFileBIN& )                                       zCall( 0x005449B0 );

    // static properties
    static zMAT4& trafoB2ToThis;

    // user API
    #include "zCOBBox3D.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZBVOLUME_H__VER2__