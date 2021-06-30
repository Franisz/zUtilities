// Supported with union (c) 2018 Union team

#ifndef __ZRAY_CACHE_H__VER1__
#define __ZRAY_CACHE_H__VER1__

namespace Gothic_I_Addon {

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
    void zCRayCacheElement_OnInit( zCBspLeaf const*, zCRayCacheElement** ) zCall( 0x005CA8D0 );
    zCRayCacheElement( zCBspLeaf const* a0, zCRayCacheElement** a1 )       zInit( zCRayCacheElement_OnInit( a0, a1 ));
    ~zCRayCacheElement()                                                   zCall( 0x005CA9A0 );
    void JumpBack( zCRayCacheElement** )                                   zCall( 0x005CAA70 );

    // user API
    #include "zCRayCacheElement.inl"
  };

  class zCRayCache {
  public:
    zCRayCacheElement* first;
    zCRayCache* next;

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