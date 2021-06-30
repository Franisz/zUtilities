// Supported with union (c) 2018 Union team

#ifndef __ZRAY_CACHE_H__VER3__
#define __ZRAY_CACHE_H__VER3__

#include "zPluecker.h"

namespace Gothic_II_Addon {

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
    void zCRayCacheElement_OnInit( zCBspLeaf const*, zCRayCacheElement** ) zCall( 0x005D2AB0 );
    zCRayCacheElement( zCBspLeaf const* a0, zCRayCacheElement** a1 )       zInit( zCRayCacheElement_OnInit( a0, a1 ));
    ~zCRayCacheElement()                                                   zCall( 0x005D2B60 );
    void JumpBack( zCRayCacheElement** )                                   zCall( 0x005D2C30 );

    // user API
    #include "zCRayCacheElement.inl"
  };

  class zCRayCache {
  public:
    zCRayCacheElement* first;
    zCRayCache* next;

    zCRayCache() {}
    char* Hit() const                                zCall( 0x005D2C60 );
    zCArray<unsigned short>& HitList() const         zCall( 0x005D2C70 );
    void StartTraceRay( zVEC3 const&, zVEC3 const& ) zCall( 0x005D2CB0 );
    void StopTraceRay()                              zCall( 0x005D2F90 );
    ~zCRayCache()                                    zCall( 0x005D3170 );
    void NextNode( zCBspBase const* )                zCall( 0x005D3210 );
    static float LastTraceRayEffort()                zCall( 0x005D2C80 );
    static void NodeDeleted( zCBspLeaf* )            zCall( 0x005D3800 );

    // static properties
    static zCRayCacheElement*& s_current;
    static zVEC3& s_start;
    static zVEC3& s_stop;
    static zCRayCache*& s_anchor;

    // user API
    #include "zCRayCache.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZRAY_CACHE_H__VER3__