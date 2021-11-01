// Supported with union (c) 2018-2021 Union team

#ifndef __ZRND_GLIDE__DRAW_H__VER0__
#define __ZRND_GLIDE__DRAW_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 420h
  struct zSRndGlide_AlphaPoly {
    int alpha;                                    // sizeof 04h    offset 00h
    zTRnd_AlphaBlendFunc alpFunc;                 // sizeof 04h    offset 04h
    zTRnd_PolyDrawMode dMode;                     // sizeof 04h    offset 08h
    int numClipVert;                              // sizeof 04h    offset 0Ch
    float vertCamSpaceZInv[zMAX_POLY_CLIP_VERTS]; // sizeof A8h    offset 10h
    float vertScrX[zMAX_POLY_CLIP_VERTS];         // sizeof A8h    offset B8h
    float vertScrY[zMAX_POLY_CLIP_VERTS];         // sizeof A8h    offset 160h
    float texu[zMAX_POLY_CLIP_VERTS];             // sizeof A8h    offset 208h
    float texv[zMAX_POLY_CLIP_VERTS];             // sizeof A8h    offset 2B0h
    float avgZ;                                   // sizeof 04h    offset 358h
    zCOLOR lightDyn[zMAX_POLY_CLIP_VERTS];        // sizeof A8h    offset 35Ch
    void* poly;                                   // sizeof 04h    offset 404h
    zCMaterial* mat;                              // sizeof 04h    offset 408h
    zCTexture* tex;                               // sizeof 04h    offset 40Ch
    zCTexture* lightMap;                          // sizeof 04h    offset 410h
    int cCol;                                     // sizeof 04h    offset 414h
    int ccEnabled;                                // sizeof 04h    offset 418h
    zSRndGlide_AlphaPoly* next;                   // sizeof 04h    offset 41Ch

    zSRndGlide_AlphaPoly() {}

    // user API
    #include "zSRndGlide_AlphaPoly.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZRND_GLIDE__DRAW_H__VER0__