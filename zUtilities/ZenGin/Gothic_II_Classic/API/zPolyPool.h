// Supported with union (c) 2018 Union team

#ifndef __ZPOLY_POOL_H__VER2__
#define __ZPOLY_POOL_H__VER2__

#include "z3d.h"
#include "zVisual.h"

namespace Gothic_II_Classic {

  class zCVertexFeaturePool {
  public:
    GETSmallArrayNative<zCVertFeature>* Pool;
    GETSmallArrayNative<zCVertFeature*>* PtrPool;
    int NumOfAllocatedVertexFeatures;

    zCVertexFeaturePool() {}

    // user API
    #include "zCVertexFeaturePool.inl"
  };

  class zCPolygonPool {
  public:
    GETSmallArrayNative<zCPolygon>* Pool;
    int NumOfAllocatedPolygon;

    zCPolygonPool() {}

    // user API
    #include "zCPolygonPool.inl"
  };

  class zCVertexPool {
  public:
    GETSmallArrayNative<zCVertex>* Pool;
    GETSmallArrayNative<zCVertex*>* PtrPool;
    int NumOfAllocatedVertex;

    zCVertexPool() {}

    // user API
    #include "zCVertexPool.inl"
  };

  class zCMeshPool {
  public:
    zCVertexPool* vertexPool;
    zCPolygonPool* polygonPool;
    zCVertexFeaturePool* vertexFeaturePool;
    int meshIndex;
    zCMesh* meshObject;

    zCMeshPool() {}

    // user API
    #include "zCMeshPool.inl"
  };

  class zCMeshesPool {
  public:
    int IsActive;
    GETSmallArrayNative<zCMeshPool*>* pool;

    zCMeshesPool() {}

    // user API
    #include "zCMeshesPool.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZPOLY_POOL_H__VER2__