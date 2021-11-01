// Supported with union (c) 2018-2021 Union team

#ifndef __ZRAY_CACHE_H__VER1__
#define __ZRAY_CACHE_H__VER1__

namespace Gothic_I_Addon {

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
    void zCRayCacheElement_OnInit( zCBspLeaf const*, zCRayCacheElement** ) zCall( 0x005CA8D0 );
    zCRayCacheElement( zCBspLeaf const* a0, zCRayCacheElement** a1 )       zInit( zCRayCacheElement_OnInit( a0, a1 ));
    ~zCRayCacheElement()                                                   zCall( 0x005CA9A0 );
    void JumpBack( zCRayCacheElement** )                                   zCall( 0x005CAA70 );

    // user API
    #include "zCRayCacheElement.inl"
  };

  // sizeof 08h
  class zCRayCache {
  public:
    zCRayCacheElement* first; // sizeof 04h    offset 00h
    zCRayCache* next;         // sizeof 04h    offset 04h

    zCRayCache() {}
    char* Hit() const                                zCall( 0x005CAAA0 );
    zCArray<unsigned short>& HitList() const         zCall( 0x005CAAB0 );
    void StartTraceRay( zVEC3 const&, zVEC3 const& ) zCall( 0x005CAAF0 );
    void StopTraceRay()                              zCall( 0x005CAD60 );
    ~zCRayCache()                                    zCall( 0x005CAED0 );
    void NextNode( zCBspBase const* )                zCall( 0x005CAF60 );
    static float LastTraceRayEffort()                zCall( 0x005CAAC0 );
    static void NodeDeleted( zCBspLeaf* )            zCall( 0x005CB4F0 );

    // static properties
    static zCRayCacheElement*& s_current;
    static zVEC3& s_start;
    static zVEC3& s_stop;
    static zCRayCache*& s_anchor;

    // user API
    #include "zCRayCache.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZRAY_CACHE_H__VER1__