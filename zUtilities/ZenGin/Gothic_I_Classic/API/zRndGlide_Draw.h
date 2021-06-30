// Supported with union (c) 2018 Union team

#ifndef __ZRND_GLIDE__DRAW_H__VER0__
#define __ZRND_GLIDE__DRAW_H__VER0__

namespace Gothic_I_Classic {

  struct zSRndGlide_AlphaPoly {
    int alpha;
    zTRnd_AlphaBlendFunc alpFunc;
    zTRnd_PolyDrawMode dMode;
    int numClipVert;
    float vertCamSpaceZInv[zMAX_POLY_CLIP_VERTS];
    float vertScrX[zMAX_POLY_CLIP_VERTS];
    float vertScrY[zMAX_POLY_CLIP_VERTS];
    float texu[zMAX_POLY_CLIP_VERTS];
    float texv[zMAX_POLY_CLIP_VERTS];
    float avgZ;
    zCOLOR lightDyn[zMAX_POLY_CLIP_VERTS];
    void* poly;
    zCMaterial* mat;
    zCTexture* tex;
    zCTexture* lightMap;
    int cCol;
    int ccEnabled;
    zSRndGlide_AlphaPoly* next;

    zSRndGlide_AlphaPoly() {}

    // user API
    #include "zSRndGlide_AlphaPoly.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZRND_GLIDE__DRAW_H__VER0__