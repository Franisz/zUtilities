// Supported with union (c) 2018-2021 Union team

#ifndef __ZRAY_CACHE_H__VER3__
#define __ZRAY_CACHE_H__VER3__

#include "zPluecker.h"

namespace Gothic_II_Addon {

  // sizeof 38h
  class zCRayCacheElement {
  public:
    zCPluecker last_cast_ray;         // sizeof 18h    offset 00h
    zCBspLeaf* leaf;                  // sizeof 04h    offset 18h
    float* updatePolys;               // sizeof 04h    offset 1Ch
    float min_updatePolys;            // sizeof 04h    offset 20h
    char* hit;                        // sizeof 04h    offset 24h
    zCArray<unsigned short> hit_list; // sizeof 0Ch    offset 28h
    zCRayCacheElement* next;          // sizeof 04h    offset 34h

    zCRayCacheElement() {}
    void zCRayCacheElement_OnInit( zCBspLeaf const*, zCRayCacheElement** ) zCall( 0x005D2AB0 );
    zCRayCacheElement( zCBspLeaf const* a0, zCRayCacheElement** a1 )       zInit( zCRayCacheElement_OnInit( a0, a1 ));
    ~zCRayCacheElement()                                                   zCall( 0x005D2B60 );
    void JumpBack( zCRayCacheElement** )                                   zCall( 0x005D2C30 );

    // user API
    #include "zCRayCacheElement.inl"
  };

  // sizeof 08h
  class zCRayCache {
  public:
    zCRayCacheElement* first; // sizeof 04h    offset 00h
    zCRayCache* next;         // sizeof 04h    offset 04h

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