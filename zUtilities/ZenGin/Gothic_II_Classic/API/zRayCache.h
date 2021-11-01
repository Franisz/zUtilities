// Supported with union (c) 2018-2021 Union team

#ifndef __ZRAY_CACHE_H__VER2__
#define __ZRAY_CACHE_H__VER2__

namespace Gothic_II_Classic {

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
    void zCRayCacheElement_OnInit( zCBspLeaf const*, zCRayCacheElement** ) zCall( 0x005CBF00 );
    zCRayCacheElement( zCBspLeaf const* a0, zCRayCacheElement** a1 )       zInit( zCRayCacheElement_OnInit( a0, a1 ));
    ~zCRayCacheElement()                                                   zCall( 0x005CBFB0 );
    void JumpBack( zCRayCacheElement** )                                   zCall( 0x005CC080 );

    // user API
    #include "zCRayCacheElement.inl"
  };

  // sizeof 08h
  class zCRayCache {
  public:
    zCRayCacheElement* first; // sizeof 04h    offset 00h
    zCRayCache* next;         // sizeof 04h    offset 04h

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