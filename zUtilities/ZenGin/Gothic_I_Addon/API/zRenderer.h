// Supported with union (c) 2018 Union team

#ifndef __ZRENDERER_H__VER1__
#define __ZRENDERER_H__VER1__

namespace Gothic_I_Addon {
  const int zRND_FOG_FALLOFF_LINEAR = 0;

  enum zTRnd_PolySortMode {
    zRND_SORT_NONE,
    zRND_SORT_ZBUFFER
  };

  enum zTRnd_ZBufferCmp {
    zRND_ZBUFFER_CMP_ALWAYS,
    zRND_ZBUFFER_CMP_NEVER,
    zRND_ZBUFFER_CMP_LESS,
    zRND_ZBUFFER_CMP_LESS_EQUAL
  };

  enum zTRnd_PolyDrawMode {
    zRND_DRAW_MATERIAL,
    zRND_DRAW_MATERIAL_WIRE,
    zRND_DRAW_FLAT,
    zRND_DRAW_WIRE
  };

  enum zTRnd_AlphaBlendSource {
    zRND_ALPHA_SOURCE_MATERIAL,
    zRND_ALPHA_SOURCE_CONSTANT
  };

  enum zTRnd_AlphaBlendFunc {
    zRND_ALPHA_FUNC_MAT_DEFAULT,
    zRND_ALPHA_FUNC_NONE,
    zRND_ALPHA_FUNC_BLEND,
    zRND_ALPHA_FUNC_ADD,
    zRND_ALPHA_FUNC_SUB,
    zRND_ALPHA_FUNC_MUL,
    zRND_ALPHA_FUNC_MUL2,
    zRND_ALPHA_FUNC_TEST
  };

  enum zTRnd_Capability {
    zRND_CAP_GUARD_BAND,
    zRND_CAP_ALPHATEST,
    zRND_CAP_MAX_BLEND_STAGES,
    zRND_CAP_MAX_BLEND_STAGE_TEXTURES,
    zRND_CAP_DIFFUSE_LAST_BLEND_STAGE_ONLY,
    zRND_CAP_TNL,
    zRND_CAP_TNL_HARDWARE,
    zRND_CAP_TNL_MAXLIGHTS,
    zRND_CAP_DEPTH_BUFFER_PREC,
    zRND_CAP_BLENDDIFFUSEALPHA
  };

  enum zTRnd_RenderMode {
    zRND_MODE_1_PASS_VERT_LIGHT,
    zRND_MODE_1_PASS_MULTITEXTURE,
    zRND_MODE_2_PASS_TEXTURE,
    zRND_MODE_2_PASS_LIGHTMAP,
    zRND_MODE_DYN_POLYS_VERT_LIGHT
  };

  enum zTRnd_ScreenMode {
    zRND_SCRMODE_FULLSCREEN,
    zRND_SCRMODE_WINDOWED,
    zRND_SCRMODE_HIDE
  };

  enum zTRnd_ClearTarget {
    zRND_CLEAR_FRAMEBUFFER = 1,
    zRND_CLEAR_ZBUFFER     = 2,
    zRND_CLEAR_ALL         = zRND_CLEAR_FRAMEBUFFER | zRND_CLEAR_ZBUFFER
  };

  enum zTRnd_RenderStateType {
    zRND_RENDERSTATE_CLIPPING,
    zRND_RENDERSTATE_TEXTUREFACTOR,
    zRND_RENDERSTATE_COUNT
  };

  enum zTRnd_TextureFormat {
    zRND_TEX_FORMAT_ARGB_8888,
    zRND_TEX_FORMAT_ABGR_8888,
    zRND_TEX_FORMAT_RGBA_8888,
    zRND_TEX_FORMAT_BGRA_8888,
    zRND_TEX_FORMAT_RGB_888,
    zRND_TEX_FORMAT_BGR_888,
    zRND_TEX_FORMAT_ARGB_4444,
    zRND_TEX_FORMAT_ARGB_1555,
    zRND_TEX_FORMAT_RGB_565,
    zRND_TEX_FORMAT_PAL_8,
    zRND_TEX_FORMAT_DXT1,
    zRND_TEX_FORMAT_DXT2,
    zRND_TEX_FORMAT_DXT3,
    zRND_TEX_FORMAT_DXT4,
    zRND_TEX_FORMAT_DXT5,
    zRND_TEX_FORMAT_COUNT
  };

  enum zTRnd_TextureStageState {
    zRND_TSS_COLOROP,
    zRND_TSS_COLORARG1,
    zRND_TSS_COLORARG2,
    zRND_TSS_ALPHAOP,
    zRND_TSS_ALPHAARG1,
    zRND_TSS_ALPHAARG2,
    zRND_TSS_BUMPENVMAT00,
    zRND_TSS_BUMPENVMAT01,
    zRND_TSS_BUMPENVMAT10,
    zRND_TSS_BUMPENVMAT11,
    zRND_TSS_TEXCOORDINDEX,
    zRND_TSS_ADDRESS,
    zRND_TSS_ADDRESSU,
    zRND_TSS_ADDRESSV,
    zRND_TSS_BORDERCOLOR,
    zRND_TSS_MAGFILTER,
    zRND_TSS_MINFILTER,
    zRND_TSS_MIPFILTER,
    zRND_TSS_MIPMAPLODBIAS,
    zRND_TSS_MAXMIPLEVEL,
    zRND_TSS_MAXANISOTROPY,
    zRND_TSS_BUMPENVLSCALE,
    zRND_TSS_BUMPENVLOFFSET,
    zRND_TSS_TEXTURETRANSFORMFLAGS,
    zRND_TSS_COUNT
  };

  enum zTRnd_TextureStageOp {
    zRND_TOP_DISABLE,
    zRND_TOP_SELECTARG1,
    zRND_TOP_SELECTARG2,
    zRND_TOP_MODULATE,
    zRND_TOP_MODULATE2X,
    zRND_TOP_MODULATE4X,
    zRND_TOP_ADD,
    zRND_TOP_ADDSIGNED,
    zRND_TOP_ADDSIGNED2X,
    zRND_TOP_SUBTRACT,
    zRND_TOP_ADDSMOOTH,
    zRND_TOP_BLENDDIFFUSEALPHA,
    zRND_TOP_BLENDTEXTUREALPHA,
    zRND_TOP_BLENDFACTORALPHA,
    zRND_TOP_BLENDTEXTUREALPHAPM,
    zRND_TOP_BLENDCURRENTALPHA,
    zRND_TOP_PREMODULATE,
    zRND_TOP_MODULATEALPHA_ADDCOLOR,
    zRND_TOP_MODULATECOLOR_ADDALPHA,
    zRND_TOP_MODULATEINVALPHA_ADDCOLOR,
    zRND_TOP_MODULATEINVCOLOR_ADDALPHA,
    zRND_TOP_BUMPENVMAP,
    zRND_TOP_BUMPENVMAPLUMINANCE,
    zRND_TOP_DOTPRODUCT3,
    zRND_TOP_COUNT
  };

  enum zTRnd_TextureStageArg {
    zRND_TA_CURRENT,
    zRND_TA_DIFFUSE,
    zRND_TA_SELECTMASK,
    zRND_TA_TEXTURE,
    zRND_TA_TFACTOR,
    zRND_TA_SPECULAR
  };

  enum zTRnd_TextureStageTexCoord {
    zRND_TSS_TCI_PASSTHRU,
    zRND_TSS_TCI_CAMERASPACENORMAL           = 65536,
    zRND_TSS_TCI_CAMERASPACEPOSITION         = 131072,
    zRND_TSS_TCI_CAMERASPACEREFLECTIONVECTOR = 196608
  };

  enum zTRnd_TextureStageTexTransformFlags {
    zRND_TTF_DISABLE,
    zRND_TTF_COUNT1,
    zRND_TTF_COUNT2,
    zRND_TTF_COUNT3,
    zRND_TTF_COUNT4
  };

  enum zTRnd_TrafoType {
    zRND_TRAFO_VIEW,
    zRND_TRAFO_PROJECTION,
    zRND_TRAFO_TEXTURE0,
    zRND_TRAFO_TEXTURE1,
    zRND_TRAFO_TEXTURE2,
    zRND_TRAFO_TEXTURE3
  };

  enum zTRenderLightType {
    zLIGHT_TYPE_POINT = 1,
    zLIGHT_TYPE_SPOT,
    zLIGHT_TYPE_DIR,
    zLIGHT_TYPE_AMBIENT
  };

  class zCRenderLight {
  public:
    zTRenderLightType lightType;
    zVEC3 colorDiffuse;
    zVEC3 position;
    zVEC3 direction;
    float range;
    float rangeInv;
    zVEC3 positionLS;
    zVEC3 directionLS;
    float dir_approxFalloff;

    void zCRenderLight_OnInit() zCall( 0x00578E60 );
    zCRenderLight()             zInit( zCRenderLight_OnInit() );

    // user API
    #include "zCRenderLight.inl"
  };

  class zCRndAlphaSortObject {
  public:
    zCRndAlphaSortObject* nextSortObject;
    float zvalue;

    zCRndAlphaSortObject() {}
    virtual ~zCRndAlphaSortObject() zCall( 0x0052D810 );
    virtual void Draw( int )        zPureCall;
    virtual int IsAlphaPoly()       zCall( 0x0052D790 );

    // user API
    #include "zCRndAlphaSortObject.inl"
  };

  struct zTRnd_TexFormatInfo {
    float bytesPerPixel;
    int rPos;
    int gPos;
    int bPos;
    int aPos;
    int rSize;
    int gSize;
    int bSize;
    int aSize;

    zTRnd_TexFormatInfo() {}

    // user API
    #include "zTRnd_TexFormatInfo.inl"
  };

  struct zTRnd_DeviceInfo {
    zSTRING deviceName;

    zTRnd_DeviceInfo() {}
    ~zTRnd_DeviceInfo() zCall( 0x004290E0 );

    // user API
    #include "zTRnd_DeviceInfo.inl"
  };

  struct zTRnd_VidModeInfo {
    int xdim;
    int ydim;
    int bpp;
    int fullscreenOnly;

    zTRnd_VidModeInfo() {}

    // user API
    #include "zTRnd_VidModeInfo.inl"
  };

  struct zTRnd_Stats {
    int texMemUsed;
    int texMemFetched;
    int numTexturesFetched;
    int numTexturesUsed;
    int numLightmapsUsed;
    int numPolysRendered;
    int numTrisRendered;
    int numAlphaPolys;
    int numAlphaPolyBatches;

    zTRnd_Stats() {}

    // user API
    #include "zTRnd_Stats.inl"
  };

  struct zTRndSimpleVertex {
    zVEC2 pos;
    float z;
    zVEC2 uv;
    zCOLOR color;

    void zTRndSimpleVertex_OnInit() zCall( 0x005CC250 );
    zTRndSimpleVertex()             zInit( zTRndSimpleVertex_OnInit() );

    // user API
    #include "zTRndSimpleVertex.inl"
  };

  struct zTRndSurfaceDesc {
    void* pSurface;
    unsigned long bytePitch;
    unsigned long pixelWidth;
    unsigned long pixelHeight;
    unsigned long bitRGBCount;
    unsigned long bitRMask;
    unsigned long bitGMask;
    unsigned long bitBMask;

    zTRndSurfaceDesc() {}

    // user API
    #include "zTRndSurfaceDesc.inl"
  };

  class zCRenderer {
  public:
    struct zTMaterial {
      zVEC4 diffuseRGBA;
      zVEC4 ambientRGBA;

      zTMaterial() {}

      // user API
      #include "zCRenderer_zTMaterial.inl"
    };

    zTRnd_PolySortMode polySortMode;
    zTRnd_PolyDrawMode polyDrawMode;
    int vid_xdim;
    int vid_ydim;
    int vid_bpp;
    int vid_pitch;
    int vid_rpos;
    int vid_gpos;
    int vid_bpos;
    int vid_rsize;
    int vid_gsize;
    int vid_bsize;

    zCRenderer() {}
    zTRnd_AlphaBlendFunc AlphaBlendFuncStringToType( zSTRING const& ) const                            zCall( 0x005CB5A0 );
    zSTRING AlphaBlendFuncTypeToString( zTRnd_AlphaBlendFunc ) const                                   zCall( 0x005CB690 );
    int Vid_SetMode_novt( int, int, int, HWND__** )                                                    zCall( 0x005CB910 );
    zTRnd_TexFormatInfo GetTexFormatInfo( zTRnd_TextureFormat ) const                                  zCall( 0x005CB9B0 );
    void DrawTile( zCTexture*, zVEC2 const&, zVEC2 const&, float, zVEC2 const&, zVEC2 const&, zCOLOR ) zCall( 0x005CB9E0 );
    virtual ~zCRenderer()                                                                              zCall( 0x0074F610 );
    virtual void BeginFrame()                                                                          zPureCall;
    virtual void EndFrame()                                                                            zPureCall;
    virtual void FlushPolys()                                                                          zPureCall;
    virtual void DrawPoly( zCPolygon* )                                                                zPureCall;
    virtual void DrawLightmapList( zCPolygon**, int )                                                  zCall( 0x0074F620 );
    virtual void DrawLine( float, float, float, float, zCOLOR )                                        zPureCall;
    virtual void DrawLineZ( float, float, float, float, float, float, zCOLOR )                         zCall( 0x0074F630 );
    virtual void SetPixel( float, float, zCOLOR )                                                      zPureCall;
    virtual void DrawPolySimple( zCTexture*, zTRndSimpleVertex*, int )                                 zCall( 0x0074F640 );
    virtual void SetFog( int )                                                                         zPureCall;
    virtual int GetFog() const                                                                         zCall( 0x0074F650 );
    virtual void SetFogColor( zCOLOR const& )                                                          zPureCall;
    virtual zCOLOR GetFogColor() const                                                                 zCall( 0x0074F660 );
    virtual void SetFogRange( float, float, int )                                                      zPureCall;
    virtual void GetFogRange( float&, float&, int& )                                                   zCall( 0x0074F690 );
    virtual zTRnd_PolyDrawMode GetPolyDrawMode() const                                                 zCall( 0x0074F6A0 );
    virtual void SetPolyDrawMode( zTRnd_PolyDrawMode const& )                                          zCall( 0x0074F6B0 );
    virtual void SetTextureWrapEnabled( int )                                                          zCall( 0x0074F6C0 );
    virtual int GetTextureWrapEnabled() const                                                          zCall( 0x0074F6D0 );
    virtual void SetBilerpFilterEnabled( int )                                                         zPureCall;
    virtual int GetBilerpFilterEnabled() const                                                         zPureCall;
    virtual void SetDitherEnabled( int )                                                               zCall( 0x0074F6E0 );
    virtual int GetDitherEnabled() const                                                               zCall( 0x0074F6F0 );
    virtual zTRnd_PolySortMode GetPolySortMode() const                                                 zCall( 0x0074F700 );
    virtual void SetPolySortMode( zTRnd_PolySortMode const& )                                          zCall( 0x0074F710 );
    virtual int GetZBufferWriteEnabled() const                                                         zCall( 0x0074F720 );
    virtual void SetZBufferWriteEnabled( int )                                                         zCall( 0x0074F730 );
    virtual zTRnd_ZBufferCmp GetZBufferCompare()                                                       zCall( 0x0074F740 );
    virtual void SetZBufferCompare( zTRnd_ZBufferCmp const& )                                          zCall( 0x0074F750 );
    virtual int GetPixelWriteEnabled() const                                                           zCall( 0x0074F760 );
    virtual void SetPixelWriteEnabled( int )                                                           zCall( 0x0074F770 );
    virtual void SetAlphaBlendSource( zTRnd_AlphaBlendSource const& )                                  zCall( 0x0074F780 );
    virtual zTRnd_AlphaBlendSource GetAlphaBlendSource() const                                         zCall( 0x0074F790 );
    virtual void SetAlphaBlendFunc( zTRnd_AlphaBlendFunc const& )                                      zCall( 0x0074F7A0 );
    virtual zTRnd_AlphaBlendFunc GetAlphaBlendFunc() const                                             zCall( 0x0074F7B0 );
    virtual float GetAlphaBlendFactor() const                                                          zCall( 0x0074F7C0 );
    virtual void SetAlphaBlendFactor( float const& )                                                   zCall( 0x0074F7D0 );
    virtual int GetCacheAlphaPolys() const                                                             zCall( 0x0074F7E0 );
    virtual void SetCacheAlphaPolys( int )                                                             zCall( 0x0074F7F0 );
    virtual void SetRenderMode( zTRnd_RenderMode )                                                     zCall( 0x0074F800 );
    virtual zTRnd_RenderMode GetRenderMode() const                                                     zCall( 0x0074F810 );
    virtual int HasCapability( zTRnd_Capability ) const                                                zCall( 0x0074F820 );
    virtual void GetGuardBandBorders( float&, float&, float&, float& )                                 zCall( 0x0074F830 );
    virtual void ResetZTest()                                                                          zCall( 0x0074F840 );
    virtual int HasPassedZTest()                                                                       zCall( 0x0074F850 );
    virtual zCTexture* CreateTexture()                                                                 zPureCall;
    virtual zCTextureConvert* CreateTextureConvert()                                                   zCall( 0x0074F860 );
    virtual int GetTotalTextureMem()                                                                   zPureCall;
    virtual int SupportsTextureFormat( zTRnd_TextureFormat )                                           zCall( 0x0074F870 );
    virtual int SupportsTextureFormatHardware( zTRnd_TextureFormat )                                   zCall( 0x0074F880 );
    virtual int GetMaxTextureSize()                                                                    zCall( 0x0074F890 );
    virtual void GetStatistics( zTRnd_Stats& )                                                         zPureCall;
    virtual void ResetStatistics()                                                                     zPureCall;
    virtual void Vid_Blit( int, tagRECT*, tagRECT* )                                                   zPureCall;
    virtual void Vid_Clear( zCOLOR&, int )                                                             zPureCall;
    virtual int Vid_Lock( zTRndSurfaceDesc& )                                                          zPureCall;
    virtual int Vid_Unlock()                                                                           zPureCall;
    virtual int Vid_IsLocked()                                                                         zPureCall;
    virtual int Vid_GetFrontBufferCopy( zCTextureConvert& )                                            zPureCall;
    virtual int Vid_GetNumDevices()                                                                    zPureCall;
    virtual int Vid_GetActiveDeviceNr()                                                                zPureCall;
    virtual int Vid_SetDevice( int )                                                                   zPureCall;
    virtual int Vid_GetDeviceInfo( zTRnd_DeviceInfo&, int )                                            zPureCall;
    virtual int Vid_GetNumModes()                                                                      zPureCall;
    virtual int Vid_GetModeInfo( zTRnd_VidModeInfo&, int )                                             zPureCall;
    virtual int Vid_GetActiveModeNr()                                                                  zPureCall;
    virtual int Vid_SetMode( int, HWND__** )                                                           zPureCall;
    virtual void Vid_SetScreenMode( zTRnd_ScreenMode )                                                 zPureCall;
    virtual zTRnd_ScreenMode Vid_GetScreenMode()                                                       zPureCall;
    virtual void Vid_SetGammaCorrection( float, float, float )                                         zPureCall;
    virtual float Vid_GetGammaCorrection()                                                             zPureCall;
    virtual void Vid_BeginLfbAccess()                                                                  zPureCall;
    virtual void Vid_EndLfbAccess()                                                                    zPureCall;
    virtual void Vid_SetLfbAlpha( int )                                                                zPureCall;
    virtual void Vid_SetLfbAlphaFunc( zTRnd_AlphaBlendFunc const& )                                    zPureCall;
    virtual int SetTransform( zTRnd_TrafoType, zMAT4 const& )                                          zCall( 0x0074F8A0 );
    virtual int SetViewport( int, int, int, int )                                                      zCall( 0x0074F8B0 );
    virtual int SetLight( unsigned long, zCRenderLight* )                                              zCall( 0x0074F8C0 );
    virtual int GetMaterial( zTMaterial& )                                                             zCall( 0x0074F8D0 );
    virtual int SetMaterial( zTMaterial const& )                                                       zCall( 0x0074F8E0 );
    virtual int SetTexture( unsigned long, zCTexture* )                                                zCall( 0x0074F8F0 );
    virtual int SetTextureStageState( unsigned long, zTRnd_TextureStageState, unsigned long )          zCall( 0x0074F900 );
    virtual int SetAlphaBlendFuncImmed( zTRnd_AlphaBlendFunc )                                         zCall( 0x0074F910 );
    virtual int SetRenderState( zTRnd_RenderStateType, unsigned long )                                 zCall( 0x0074F920 );
    virtual unsigned long GetRenderState( zTRnd_RenderStateType )                                      zCall( 0x0074F930 );
    virtual void AddAlphaSortObject( zCRndAlphaSortObject* )                                           zCall( 0x0074F940 );
    virtual void RenderAlphaSortList()                                                                 zCall( 0x0074F950 );
    virtual int DrawVertexBuffer( zCVertexBuffer*, int, int, unsigned short*, unsigned long )          zPureCall;
    virtual zCVertexBuffer* CreateVertexBuffer()                                                       zPureCall;

    // user API
    #include "zCRenderer.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZRENDERER_H__VER1__