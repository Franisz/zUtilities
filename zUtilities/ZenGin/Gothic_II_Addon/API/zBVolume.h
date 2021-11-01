// Supported with union (c) 2018-2021 Union team

#ifndef __ZBVOLUME_H__VER3__
#define __ZBVOLUME_H__VER3__

namespace Gothic_II_Addon {

  // sizeof 10h
  struct zTBSphere3D {
    zVEC3 center; // sizeof 0Ch    offset 00h
    float radius; // sizeof 04h    offset 0Ch

    zTBSphere3D() {}
    int IsIntersecting( zVEC3 const&, zVEC3 const& ) const zCall( 0x00543FD0 );
    int IsIntersecting( zTBSphere3D const& ) const         zCall( 0x005440E0 );
    int ClassifyPlane( zTPlane ) const                     zCall( 0x005441A0 );
    void Draw( zCOLOR const& ) const                       zCall( 0x005441F0 );

    // user API
    #include "zTBSphere3D.inl"
  };

  // sizeof 10h
  struct zTBBox2D {
    zVEC2 mins; // sizeof 08h    offset 00h
    zVEC2 maxs; // sizeof 08h    offset 08h

    void zTBBox2D_OnInit()                zCall( 0x00537950 );
    zTBBox2D()                            zInit( zTBBox2D_OnInit() );
    int Classify( zTBBox2D const& ) const zCall( 0x00546B10 );
    void ClipToBBox2D( zTBBox2D const& )  zCall( 0x00546BC0 );
    void Draw() const                     zCall( 0x00546C10 );

    // user API
    #include "zTBBox2D.inl"
  };

  // sizeof 18h
  struct zTBBox3D {
    zVEC3 mins; // sizeof 0Ch    offset 00h
    zVEC3 maxs; // sizeof 0Ch    offset 0Ch

    void zTBBox3D_OnInit( zTBBox3D const& )                                                    zCall( 0x0052F6B0 );
    void zTBBox3D_OnInit()                                                                     zCall( 0x00540E50 );
    void AddPoint( zVEC3 const& )                                                              zCall( 0x0052CD90 );
    zTBBox3D( zTBBox3D const& a0 )                                                             zInit( zTBBox3D_OnInit( a0 ));
    void Init()                                                                                zCall( 0x0053AB70 );
    zTBBox3D()                                                                                 zInit( zTBBox3D_OnInit() );
    void SetMaximumBox()                                                                       zCall( 0x00544510 );
    float GetVolume() const                                                                    zCall( 0x00544530 );
    void CalcGreaterBBox3D( zTBBox3D const& )                                                  zCall( 0x00544550 );
    void ClipToBBox3D( zTBBox3D const& )                                                       zCall( 0x005445B0 );
    zSTRING GetDescription() const                                                             zCall( 0x00544630 );
    void SetByDescription( zSTRING& )                                                          zCall( 0x00544C40 );
    void Transform( zMAT4 const&, zTBBox3D& ) const                                            zCall( 0x00544F10 );
    void UnTransform( zMAT4 const&, zTBBox3D& ) const                                          zCall( 0x00545020 );
    int IsIntersecting( zVEC3 const&, zVEC3 const&, float&, float& ) const                     zCall( 0x00545370 );
    int IsIntersectingSweep( zVEC3 const&, zTBBox3D const&, float& ) const                     zCall( 0x005454E0 );
    int IsIntersectingSweep( zTBBox3D const&, zTBBox3D const&, zTBBox3D const&, float& ) const zCall( 0x00545680 );
    int IsTrivIn( zTBBox3D const& ) const                                                      zCall( 0x00545700 );
    int IsTrivInLine( zVEC3 const&, zVEC3 const& ) const                                       zCall( 0x00545760 );
    int Classify( zTBBox3D const& ) const                                                      zCall( 0x00545840 );
    zVEC3 GetNearestPoint( zTPlane const* const ) const                                        zCall( 0x00545900 );
    void Scale( float )                                                                        zCall( 0x00545BF0 );
    void Scale( zVEC3 const& )                                                                 zCall( 0x00545C30 );
    float GetMinExtent() const                                                                 zCall( 0x00545C80 );
    zTBSphere3D GetSphere3D() const                                                            zCall( 0x00545CC0 );
    int TraceRay( zVEC3 const&, zVEC3 const&, zVEC3& ) const                                   zCall( 0x00545D40 );
    void Draw( zCOLOR const& ) const                                                           zCall( 0x00545EE0 );
    void GetCornerPoints( zVEC3* ) const                                                       zCall( 0x00546240 );
    float GetScreenSize() const                                                                zCall( 0x005463B0 );
    zTPlaneClass ClassifyToPlane( zTPlane const& ) const                                       zCall( 0x005464D0 );
    zTPlaneClass ClassifyToPlane( zTPlane const&, int ) const                                  zCall( 0x005465C0 );
    int ClassifyToPlaneSides( zTPlane const& ) const                                           zCall( 0x005467E0 );
    int ClassifyToPlaneSides( zTPlane const&, int ) const                                      zCall( 0x005468B0 );
    void SaveBIN( zCFileBIN& )                                                                 zCall( 0x00546AD0 );
    void LoadBIN( zCFileBIN& )                                                                 zCall( 0x00546AF0 );
    zVEC3 GetCenterFloor() const                                                               zCall( 0x0054E040 );
    zVEC3 GetCenter() const                                                                    zCall( 0x0054E7A0 );
    void InitZero()                                                                            zCall( 0x0055F3D0 );
    int IsIntersecting( zTBSphere3D const& ) const                                             zCall( 0x005D4F70 );
    int IsIntersecting( zTBBox3D const& ) const                                                zCall( 0x006039C0 );

    // user API
    #include "zTBBox3D.inl"
  };

  // sizeof 14h
  struct zTBCylinder3D {
    zVEC3 center;  // sizeof 0Ch    offset 00h
    float radius;  // sizeof 04h    offset 0Ch
    float heightY; // sizeof 04h    offset 10h

    zTBCylinder3D() {}
    int IsIntersecting( zTBCylinder3D const& ) const zCall( 0x00543E10 );
    void Draw( zCOLOR const& ) const                 zCall( 0x00543E80 );
    void SetByBBox3D( zTBBox3D )                     zCall( 0x00543F30 );

    // user API
    #include "zTBCylinder3D.inl"
  };

  // sizeof 44h
  class zCOBBox3D {
  public:
    zVEC3 center;             // sizeof 0Ch    offset 00h
    zVEC3 axis[3];            // sizeof 24h    offset 0Ch
    zVEC3 extent;             // sizeof 0Ch    offset 30h
    zCList<zCOBBox3D> childs; // sizeof 08h    offset 3Ch

    zCOBBox3D() {}
    ~zCOBBox3D()                                                     zCall( 0x00546CE0 );
    void Draw( int, zCOLOR )                                         zCall( 0x00546D70 );
    void BuildOBB( int, zCPolygon**, int )                           zCall( 0x005479C0 );
    void BuildRec( int, zCPolygon**, int )                           zCall( 0x005483F0 );
    void BuildOBBTree( zCMesh*, int )                                zCall( 0x00548720 );
    void BuildOBBTree( int, zCPolygon**, int )                       zCall( 0x00548760 );
    int TestIntersectionOBB( zCOBBox3D const* ) const                zCall( 0x00548770 );
    int TestIntersectionTreeRec( zCOBBox3D const* ) const            zCall( 0x00549010 );
    int TestIntersectionTree( zCOBBox3D const*, zMAT4 const& ) const zCall( 0x005490F0 );
    int TraceRay( zVEC3 const&, zVEC3 const&, zVEC3& ) const         zCall( 0x00549120 );
    int CheckOBBPolyIntersection( zCPolygon*, zMAT4 const& ) const   zCall( 0x005492F0 );
    zTBBox3D GetBBox3D() const                                       zCall( 0x00549590 );
    void SetByBBox3D( zTBBox3D const& )                              zCall( 0x00549790 );
    void Transform( zMAT4 const& )                                   zCall( 0x00549890 );
    zCOBBox3D& operator =( zCOBBox3D const& )                        zCall( 0x005499F0 );
    void SaveBIN( zCFileBIN& )                                       zCall( 0x00549B40 );
    void LoadBIN( zCFileBIN& )                                       zCall( 0x00549BD0 );

    // static properties
    static zMAT4& trafoB2ToThis;

    // user API
    #include "zCOBBox3D.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZBVOLUME_H__VER3__