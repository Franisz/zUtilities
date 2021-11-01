// Supported with union (c) 2018-2021 Union team

#ifndef __ZRENDERER_H__VER0__
#define __ZRENDERER_H__VER0__

namespace Gothic_I_Classic {
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

  // sizeof 4Ch
  class zCRenderLight {
  public:
    zTRenderLightType lightType; // sizeof 04h    offset 00h
    zVEC3 colorDiffuse;          // sizeof 0Ch    offset 04h
    zVEC3 position;              // sizeof 0Ch    offset 10h
    zVEC3 direction;             // sizeof 0Ch    offset 1Ch
    float range;                 // sizeof 04h    offset 28h
    float rangeInv;              // sizeof 04h    offset 2Ch
    zVEC3 positionLS;            // sizeof 0Ch    offset 30h
    zVEC3 directionLS;           // sizeof 0Ch    offset 3Ch
    float dir_approxFalloff;     // sizeof 04h    offset 48h

    void zCRenderLight_OnInit() zCall( 0x00560A00 );
    zCRenderLight()             zInit( zCRenderLight_OnInit() );

    // user API
    #include "zCRenderLight.inl"
  };

  // sizeof 0Ch
  class zCRndAlphaSortObject {
  public:
    zCRndAlphaSortObject* nextSortObject; // sizeof 04h    offset 04h
    float zvalue;                         // sizeof 04h    offset 08h

    zCRndAlphaSortObject() {}
    virtual ~zCRndAlphaSortObject() zCall( 0x00517E00 );
    virtual void Draw( int )        zPureCall;
    virtual int IsAlphaPoly()       zCall( 0x00517D80 );

    // user API
    #include "zCRndAlphaSortObject.inl"
  };

  // sizeof 24h
  struct zTRnd_TexFormatInfo {
    float bytesPerPixel; // sizeof 04h    offset 00h
    int rPos;            // sizeof 04h    offset 04h
    int gPos;            // sizeof 04h    offset 08h
    int bPos;            // sizeof 04h    offset 0Ch
    int aPos;            // sizeof 04h    offset 10h
    int rSize;           // sizeof 04h    offset 14h
    int gSize;           // sizeof 04h    offset 18h
    int bSize;           // sizeof 04h    offset 1Ch
    int aSize;           // sizeof 04h    offset 20h

    zTRnd_TexFormatInfo() {}

    // user API
    #include "zTRnd_TexFormatInfo.inl"
  };

  // sizeof 14h
  struct zTRnd_DeviceInfo {
    zSTRING deviceName; // sizeof 14h    offset 00h

    zTRnd_DeviceInfo() {}
    ~zTRnd_DeviceInfo() zCall( 0x004266D0 );

    // user API
    #include "zTRnd_DeviceInfo.inl"
  };

  // sizeof 10h
  struct zTRnd_VidModeInfo {
    int xdim;           // sizeof 04h    offset 00h
    int ydim;           // sizeof 04h    offset 04h
    int bpp;            // sizeof 04h    offset 08h
    int fullscreenOnly; // sizeof 04h    offset 0Ch

    zTRnd_VidModeInfo() {}

    // user API
    #include "zTRnd_VidModeInfo.inl"
  };

  // sizeof 24h
  struct zTRnd_Stats {
    int texMemUsed;          // sizeof 04h    offset 00h
    int texMemFetched;       // sizeof 04h    offset 04h
    int numTexturesFetched;  // sizeof 04h    offset 08h
    int numTexturesUsed;     // sizeof 04h    offset 0Ch
    int numLightmapsUsed;    // sizeof 04h    offset 10h
    int numPolysRendered;    // sizeof 04h    offset 14h
    int numTrisRendered;     // sizeof 04h    offset 18h
    int numAlphaPolys;       // sizeof 04h    offset 1Ch
    int numAlphaPolyBatches; // sizeof 04h    offset 20h

    zTRnd_Stats() {}

    // user API
    #include "zTRnd_Stats.inl"
  };

  // sizeof 18h
  struct zTRndSimpleVertex {
    zVEC2 pos;    // sizeof 08h    offset 00h
    float z;      // sizeof 04h    offset 08h
    zVEC2 uv;     // sizeof 08h    offset 0Ch
    zCOLOR color; // sizeof 04h    offset 14h

    void zTRndSimpleVertex_OnInit() zCall( 0x005AF340 );
    zTRndSimpleVertex()             zInit( zTRndSimpleVertex_OnInit() );

    // user API
    #include "zTRndSimpleVertex.inl"
  };

  // sizeof 20h
  struct zTRndSurfaceDesc {
    void* pSurface;            // sizeof 04h    offset 00h
    unsigned long bytePitch;   // sizeof 04h    offset 04h
    unsigned long pixelWidth;  // sizeof 04h    offset 08h
    unsigned long pixelHeight; // sizeof 04h    offset 0Ch
    unsigned long bitRGBCount; // sizeof 04h    offset 10h
    unsigned long bitRMask;    // sizeof 04h    offset 14h
    unsigned long bitGMask;    // sizeof 04h    offset 18h
    unsigned long bitBMask;    // sizeof 04h    offset 1Ch

    zTRndSurfaceDesc() {}

    // user API
    #include "zTRndSurfaceDesc.inl"
  };

  // sizeof 34h
  class zCRenderer {
  public:
    // sizeof 20h
    struct zTMaterial {
      zVEC4 diffuseRGBA; // sizeof 10h    offset 00h
      zVEC4 ambientRGBA; // sizeof 10h    offset 10h

      zTMaterial() {}

      // user API
      #include "zCRenderer_zTMaterial.inl"
    };

    zTRnd_PolySortMode polySortMode; // sizeof 04h    offset 04h
    zTRnd_PolyDrawMode polyDrawMode; // sizeof 04h    offset 08h
    int vid_xdim;                    // sizeof 04h    offset 0Ch
    int vid_ydim;                    // sizeof 04h    offset 10h
    int vid_bpp;                     // sizeof 04h    offset 14h
    int vid_pitch;                   // sizeof 04h    offset 18h
    int vid_rpos;                    // sizeof 04h    offset 1Ch
    int vid_gpos;                    // sizeof 04h    offset 20h
    int vid_bpos;                    // sizeof 04h    offset 24h
    int vid_rsize;                   // sizeof 04h    offset 28h
    int vid_gsize;                   // sizeof 04h    offset 2Ch
    int vid_bsize;                   // sizeof 04h    offset 30h

    zCRenderer() {}
    zTRnd_AlphaBlendFunc AlphaBlendFuncStringToType( zSTRING const& ) const                            zCall( 0x005AE600 );
    zSTRING AlphaBlendFuncTypeToString( zTRnd_AlphaBlendFunc ) const                                   zCall( 0x005AE6F0 );
    int Vid_SetMode_novt( int, int, int, HWND__** )                                                    zCall( 0x005AE970 );
    zTRnd_TexFormatInfo GetTexFormatInfo( zTRnd_TextureFormat ) const                                  zCall( 0x005AEA10 );
    void DrawTile( zCTexture*, zVEC2 const&, zVEC2 const&, float, zVEC2 const&, zVEC2 const&, zCOLOR ) zCall( 0x005AEA40 );
    virtual ~zCRenderer()                                                                              zCall( 0x007138F0 );
    virtual void BeginFrame()                                                                          zPureCall;
    virtual void EndFrame()                                                                            zPureCall;
    virtual void FlushPolys()                                                                          zPureCall;
    virtual void DrawPoly( zCPolygon* )                                                                zPureCall;
    virtual void DrawLightmapList( zCPolygon**, int )                                                  zCall( 0x00713900 );
    virtual void DrawLine( float, float, float, float, zCOLOR )                                        zPureCall;
    virtual void DrawLineZ( float, float, float, float, float, float, zCOLOR )                         zCall( 0x00713910 );
    virtual void SetPixel( float, float, zCOLOR )                                                      zPureCall;
    virtual void DrawPolySimple( zCTexture*, zTRndSimpleVertex*, int )                                 zCall( 0x00713920 );
    virtual void SetFog( int )                                                                         zPureCall;
    virtual int GetFog() const                                                                         zCall( 0x00713930 );
    virtual void SetFogColor( zCOLOR const& )                                                          zPureCall;
    virtual zCOLOR GetFogColor() const                                                                 zCall( 0x00713940 );
    virtual void SetFogRange( float, float, int )                                                      zPureCall;
    virtual void GetFogRange( float&, float&, int& )                                                   zCall( 0x00713970 );
    virtual zTRnd_PolyDrawMode GetPolyDrawMode() const                                                 zCall( 0x00713980 );
    virtual void SetPolyDrawMode( zTRnd_PolyDrawMode const& )                                          zCall( 0x00713990 );
    virtual void SetTextureWrapEnabled( int )                                                          zCall( 0x007139A0 );
    virtual int GetTextureWrapEnabled() const                                                          zCall( 0x007139B0 );
    virtual void SetBilerpFilterEnabled( int )                                                         zPureCall;
    virtual int GetBilerpFilterEnabled() const                                                         zPureCall;
    virtual void SetDitherEnabled( int )                                                               zCall( 0x007139C0 );
    virtual int GetDitherEnabled() const                                                               zCall( 0x007139D0 );
    virtual zTRnd_PolySortMode GetPolySortMode() const                                                 zCall( 0x007139E0 );
    virtual void SetPolySortMode( zTRnd_PolySortMode const& )                                          zCall( 0x007139F0 );
    virtual int GetZBufferWriteEnabled() const                                                         zCall( 0x00713A00 );
    virtual void SetZBufferWriteEnabled( int )                                                         zCall( 0x00713A10 );
    virtual zTRnd_ZBufferCmp GetZBufferCompare()                                                       zCall( 0x00713A20 );
    virtual void SetZBufferCompare( zTRnd_ZBufferCmp const& )                                          zCall( 0x00713A30 );
    virtual int GetPixelWriteEnabled() const                                                           zCall( 0x00713A40 );
    virtual void SetPixelWriteEnabled( int )                                                           zCall( 0x00713A50 );
    virtual void SetAlphaBlendSource( zTRnd_AlphaBlendSource const& )                                  zCall( 0x00713A60 );
    virtual zTRnd_AlphaBlendSource GetAlphaBlendSource() const                                         zCall( 0x00713A70 );
    virtual void SetAlphaBlendFunc( zTRnd_AlphaBlendFunc const& )                                      zCall( 0x00713A80 );
    virtual zTRnd_AlphaBlendFunc GetAlphaBlendFunc() const                                             zCall( 0x00713A90 );
    virtual float GetAlphaBlendFactor() const                                                          zCall( 0x00713AA0 );
    virtual void SetAlphaBlendFactor( float const& )                                                   zCall( 0x00713AB0 );
    virtual int GetCacheAlphaPolys() const                                                             zCall( 0x00713AC0 );
    virtual void SetCacheAlphaPolys( int )                                                             zCall( 0x00713AD0 );
    virtual void SetRenderMode( zTRnd_RenderMode )                                                     zCall( 0x00713AE0 );
    virtual zTRnd_RenderMode GetRenderMode() const                                                     zCall( 0x00713AF0 );
    virtual int HasCapability( zTRnd_Capability ) const                                                zCall( 0x00713B00 );
    virtual void GetGuardBandBorders( float&, float&, float&, float& )                                 zCall( 0x00713B10 );
    virtual void ResetZTest()                                                                          zCall( 0x00713B20 );
    virtual int HasPassedZTest()                                                                       zCall( 0x00713B30 );
    virtual zCTexture* CreateTexture()                                                                 zPureCall;
    virtual zCTextureConvert* CreateTextureConvert()                                                   zCall( 0x00713B40 );
    virtual int GetTotalTextureMem()                                                                   zPureCall;
    virtual int SupportsTextureFormat( zTRnd_TextureFormat )                                           zCall( 0x00713B50 );
    virtual int SupportsTextureFormatHardware( zTRnd_TextureFormat )                                   zCall( 0x00713B60 );
    virtual int GetMaxTextureSize()                                                                    zCall( 0x00713B70 );
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
    virtual int SetTransform( zTRnd_TrafoType, zMAT4 const& )                                          zCall( 0x00713B80 );
    virtual int SetViewport( int, int, int, int )                                                      zCall( 0x00713B90 );
    virtual int SetLight( unsigned long, zCRenderLight* )                                              zCall( 0x00713BA0 );
    virtual int GetMaterial( zTMaterial& )                                                             zCall( 0x00713BB0 );
    virtual int SetMaterial( zTMaterial const& )                                                       zCall( 0x00713BC0 );
    virtual int SetTexture( unsigned long, zCTexture* )                                                zCall( 0x00713BD0 );
    virtual int SetTextureStageState( unsigned long, zTRnd_TextureStageState, unsigned long )          zCall( 0x00713BE0 );
    virtual int SetAlphaBlendFuncImmed( zTRnd_AlphaBlendFunc )                                         zCall( 0x00713BF0 );
    virtual int SetRenderState( zTRnd_RenderStateType, unsigned long )                                 zCall( 0x00713C00 );
    virtual unsigned long GetRenderState( zTRnd_RenderStateType )                                      zCall( 0x00713C10 );
    virtual void AddAlphaSortObject( zCRndAlphaSortObject* )                                           zCall( 0x00713C20 );
    virtual void RenderAlphaSortList()                                                                 zCall( 0x00713C30 );
    virtual int DrawVertexBuffer( zCVertexBuffer*, int, int, unsigned short*, unsigned long )          zPureCall;
    virtual zCVertexBuffer* CreateVertexBuffer()                                                       zPureCall;

    // user API
    #include "zCRenderer.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZRENDERER_H__VER0__