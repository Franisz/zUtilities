// Supported with union (c) 2018 Union team

#ifndef __ZRAY_CACHE_H__VER0__
#define __ZRAY_CACHE_H__VER0__

namespace Gothic_I_Classic {

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
    void zCRayCacheElement_OnInit( zCBspLeaf const*, zCRayCacheElement** ) zCall( 0x005AD960 );
    zCRayCacheElement( zCBspLeaf const* a0, zCRayCacheElement** a1 )       zInit( zCRayCacheElement_OnInit( a0, a1 ));
    ~zCRayCacheElement()                                                   zCall( 0x005ADA30 );
    void JumpBack( zCRayCacheElement** )                                   zCall( 0x005ADB00 );

    // user API
    #include "zCRayCacheElement.inl"
  };

  class zCRayCache {
  public:
    zCRayCacheElement* first;
    zCRayCache* next;

    zCRayCache() {}
    char* Hit() const                                zCall( 0x005ADB30 );
    zCArray<unsigned short>& HitList() const         zCall( 0x005ADB40 );
    void StartTraceRay( zVEC3 const&, zVEC3 const& ) zCall( 0x005ADB80 );
    void StopTraceRay()                              zCall( 0x005ADE00 );
    ~zCRayCache()                                    zCall( 0x005ADF70 );
    void NextNode( zCBspBase const* )                zCall( 0x005AE010 );
    static float LastTraceRayEffort()                zCall( 0x005ADB50 );
    static void NodeDeleted( zCBspLeaf* )            zCall( 0x005AE550 );

    // static properties
    static zCRayCacheElement*& s_current;
    static zVEC3& s_start;
    static zVEC3& s_stop;
    static zCRayCache*& s_anchor;

    // user API
    #include "zCRayCache.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZRAY_CACHE_H__VER0__