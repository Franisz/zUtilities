// Supported with union (c) 2018-2021 Union team

#ifndef __ZPOLY_POOL_H__VER0__
#define __ZPOLY_POOL_H__VER0__

#include "z3d.h"
#include "zVisual.h"

namespace Gothic_I_Classic {

  // sizeof 0Ch
  class zCVertexFeaturePool {
  public:
    GETSmallArrayNative<zCVertFeature>* Pool;     // sizeof 04h    offset 00h
    GETSmallArrayNative<zCVertFeature*>* PtrPool; // sizeof 04h    offset 04h
    int NumOfAllocatedVertexFeatures;             // sizeof 04h    offset 08h

    zCVertexFeaturePool() {}

    // user API
    #include "zCVertexFeaturePool.inl"
  };

  // sizeof 08h
  class zCPolygonPool {
  public:
    GETSmallArrayNative<zCPolygon>* Pool; // sizeof 04h    offset 00h
    int NumOfAllocatedPolygon;            // sizeof 04h    offset 04h

    zCPolygonPool() {}

    // user API
    #include "zCPolygonPool.inl"
  };

  // sizeof 0Ch
  class zCVertexPool {
  public:
    GETSmallArrayNative<zCVertex>* Pool;     // sizeof 04h    offset 00h
    GETSmallArrayNative<zCVertex*>* PtrPool; // sizeof 04h    offset 04h
    int NumOfAllocatedVertex;                // sizeof 04h    offset 08h

    zCVertexPool() {}

    // user API
    #include "zCVertexPool.inl"
  };

  // sizeof 14h
  class zCMeshPool {
  public:
    zCVertexPool* vertexPool;               // sizeof 04h    offset 00h
    zCPolygonPool* polygonPool;             // sizeof 04h    offset 04h
    zCVertexFeaturePool* vertexFeaturePool; // sizeof 04h    offset 08h
    int meshIndex;                          // sizeof 04h    offset 0Ch
    zCMesh* meshObject;                     // sizeof 04h    offset 10h

    zCMeshPool() {}

    // user API
    #include "zCMeshPool.inl"
  };

  // sizeof 08h
  class zCMeshesPool {
  public:
    int IsActive;                           // sizeof 04h    offset 00h
    GETSmallArrayNative<zCMeshPool*>* pool; // sizeof 04h    offset 04h

    zCMeshesPool() {}

    // user API
    #include "zCMeshesPool.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZPOLY_POOL_H__VER0__