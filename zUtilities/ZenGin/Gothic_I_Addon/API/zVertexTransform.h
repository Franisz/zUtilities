// Supported with union (c) 2018-2021 Union team

#ifndef __ZVERTEX_TRANSFORM_H__VER1__
#define __ZVERTEX_TRANSFORM_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 1Ch
  class zCVertexTransform {
  public:
    zMEMPOOL_VOLATILE_DECLARATION( zCVertexTransform )

    zCVertex* untransformed; // sizeof 04h    offset 00h
    zVEC3 vertCamSpace;      // sizeof 0Ch    offset 04h
    float vertCamSpaceZInv;  // sizeof 04h    offset 10h
    float vertScrX;          // sizeof 04h    offset 14h
    float vertScrY;          // sizeof 04h    offset 18h

    zCVertexTransform() {}

    // user API
    #include "zCVertexTransform.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZVERTEX_TRANSFORM_H__VER1__