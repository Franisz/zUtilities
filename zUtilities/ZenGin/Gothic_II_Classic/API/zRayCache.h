// Supported with union (c) 2018 Union team

#ifndef __ZRAY_CACHE_H__VER2__
#define __ZRAY_CACHE_H__VER2__

namespace Gothic_II_Classic {

  class zCRayCacheElement {
  public:
    zCPluecker last_cast_ray;
    zCBspLeaf* leaf;
    float* updatePolys;
    float min_updatePolys;
    char* hit;
    zCArray<unsigned short> hit_list;
    zCRayCacheElement* next;

    zCRayCacheElement() {}
    void zCRayCacheElement_OnInit( zCBspLeaf const*, zCRayCacheElement** ) zCall( 0x005CBF00 );
    zCRayCacheElement( zCBspLeaf const* a0, zCRayCacheElement** a1 )       zInit( zCRayCacheElement_OnInit( a0, a1 ));
    ~zCRayCacheElement()                                                   zCall( 0x005CBFB0 );
    void JumpBack( zCRayCacheElement** )                                   zCall( 0x005CC080 );

    // user API
    #include "zCRayCacheElement.inl"
  };

  class zCRayCache {
  public:
    zCRayCacheElement* first;
    zCRayCache* next;

    zCRayCache() {}
    char* Hit() const                                zCall( 0x005CC0B0 );
    zCArray<unsigned short>& HitList() const         zCall( 0x005CC0C0 );
    void StartTraceRay( zVEC3 const&, zVEC3 const& ) zCall( 0x005CC100 );
    void StopTraceRay()                              zCall( 0x005CC3E0 );
    ~zCRayCache()                                    zCall( 0x005CC5C0 );
    void NextNode( zCBspBase const* )                zCall( 0x005CC660 );
    static float LastTraceRayEffort()                zCall( 0x005CC0D0 );
    static void NodeDeleted( zCBspLeaf* )            zCall( 0x005CCC50 );

    // static properties
    static zCRayCacheElement*& s_current;
    static zVEC3& s_start;
    static zVEC3& s_stop;
    static zCRayCache*& s_anchor;

    // user API
    #include "zCRayCache.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZRAY_CACHE_H__VER2__