// Supported with union (c) 2018-2021 Union team

#ifndef __ZRND_GLIDE_H__VER0__
#define __ZRND_GLIDE_H__VER0__

#include "zRenderer.h"
#include "zTexConvert.h"
#include "z3d.h"

namespace Gothic_I_Classic {
  const int GR_LOD_0          = GR_LOD_1+1;
  const float NEAREST_OOW     = 1.0F;
  const float MAX_ALPHA       = 255.0F;
  const float MAX_FRAG        = 10.0F;
  const unsigned long BACKGROUND_COL = 0xff;
  const int GR_MAXBUCKETS     = 256;
  const int GR_MAXALPHAPOLYS  = 5000;

  class zCTex_RndGlide : public zCTexture {
  public:
    int maxDetailTex;
    float scaleX;
    float scaleY;
    GrTexInfo infoCache;
    Gu3dfInfo infoSrc;
    unsigned long sizeMipsCurrent;
    zFILE* file;
    FxU32 addrTexHw;
    zCTex_RndGlide* next;
    unsigned long age;
    unsigned long importance;
    int locked;
    int lockedMode;
    zCTextureInfo infoTex;
    int alphaTex;
    int chromaTex;
    void* palette;

    zCTex_RndGlide() {}

    // static properties
    static zCList<zCTex_RndGlide>& texMem;
    static unsigned long& memAvail;
    static unsigned long& largestBlockAvail;
    static unsigned long& frameCounter;
    static FxU32& root;
    static unsigned long& sizeTexMemHw;
    static int& fragmented;
    static zCTex_RndGlide*& tmpTexture;

    // user API
    #include "zCTex_RndGlide.inl"
  };

  class zCRnd_Glide : public zCRenderer {
  public:
    typedef struct SCapability {
    public:
      int numTexPerPass;
      int totalFrameBufferMem;
      int totalTextureMem;
      int alphaBlendMulAvail;
      int alphaBlendAddAvail;
      int chromaAvail;
      int lfbAlphaBlendAvail;
      int lfbChromaAvail;

      SCapability() {}
    } TCapability;

    TCapability cap;
    GrHwConfiguration hwconfig;
    GrScreenResolution_t fullRes;
    GrScreenResolution_t actRes;
    float gamma;
    int rushBased;
    int fullScreenOnly;
    GrFog_t fog[GR_FOG_TABLE_SIZE];
    GrState lfbState;
    GrVertex p[4];
    GrVertex v[zMAX_POLY_CLIP_VERTS];
    GrLfbInfo_t frameBuf;
    unsigned char* colorBuf;
    int lfbLocked;
    float nearZ;
    float farZ;
    int fogType;
    zTRnd_ScreenMode scrMode;
    int fogEnabled;
    zCOLOR fogColor;
    int waitRetrace;
    int writeZBuffer;
    unsigned long maxTimeDefragPartial;
    float zBias;
    zTRnd_ZBufferCmp zBufCompareFunc;
    int lightMapBilerpFilter;
    int bilerpFilter;
    int wrapEnabled;
    zTRnd_Stats zTestStat;
    int pixelWriteEn;
    int polysRendered;
    int trisRendered;
    int lightMapsRendered;
    zTRnd_DeviceInfo deviceInfo;

    zCRnd_Glide() {}

    // user API
    #include "zCRnd_Glide.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZRND_GLIDE_H__VER0__