// Supported with union (c) 2018 Union team

#ifndef __ZVERTEX_TRANSFORM_H__VER2__
#define __ZVERTEX_TRANSFORM_H__VER2__

namespace Gothic_II_Classic {

  class zCVertexTransform {
  public:
    zMEMPOOL_VOLATILE_DECLARATION( zCVertexTransform )

    zCVertex* untransformed;
    zVEC3 vertCamSpace;
    float vertCamSpaceZInv;
    float vertScrX;
    float vertScrY;

    zCVertexTransform() {}

    // user API
    #include "zCVertexTransform.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVERTEX_TRANSFORM_H__VER2__