// Supported with union (c) 2018-2021 Union team

#ifndef __ZRENDER_MANAGER_H__VER2__
#define __ZRENDER_MANAGER_H__VER2__

namespace Gothic_II_Classic {
  const int zRENDERMAN_NUM_SHADER        = 64;
  const int zRENDERMAN_NUM_SHADER_STAGES = zRENDERMAN_NUM_SHADER * 4;
  const int MAX_STAGES                   = 4;

  enum zTShaderWaveFunc {
    zSHD_FUNC_CONST,
    zSHD_FUNC_SIN,
    zSHD_FUNC_TRIANGLE,
    zSHD_FUNC_SQUARE,
    zSHD_FUNC_SAWTOOTH,
    zSHD_FUNC_INVERSESAWTOOTH,
    zSHD_FUNC_NOISE
  };

  enum zTShaderRGBGen {
    zSHD_RGBGEN_IDENTITY,
    zSHD_RGBGEN_VERTEX,
    zSHD_RGBGEN_FACTOR,
    zSHD_RGBGEN_WAVE
  };

  enum zTShaderAlphaGen {
    zSHD_ALPHAGEN_IDENTITY,
    zSHD_ALPHAGEN_VERTEX,
    zSHD_ALPHAGEN_FACTOR,
    zSHD_ALPHAGEN_DETAILFADE,
    zSHD_ALPHAGEN_FARFADE,
    zSHD_ALPHAGEN_WATER
  };

  enum zTShaderTCGen {
    zSHD_TCGEN_BASE,
    zSHD_TCGEN_LIGHTMAP,
    zSHD_TCGEN_ENVIRONMENT,
    zSHD_TCGEN_ENVIRONMENT_FLAT
  };

  enum zTShaderTCMod {
    zSHD_TCMOD_NONE,
    zSHD_TCMOD_SCROLL,
    zSHD_TCMOD_ENVIRONMENT,
    zSHD_TCMOD_ROTATE,
    zSHD_TCMOD_SCALE,
    zSHD_TCMOD_STRETCH,
    zSHD_TCMOD_TRANSFORM,
    zSHD_TCMOD_TURB
  };

  enum zTShaderDeformVertex {
    zSHD_DEFORMVERT_NONE,
    zSHD_DEFORMVERT_WAVE,
    zSHD_DEFORMVERT_NORMAL,
    zSHD_DEFORMVERT_BULGE,
    zSHD_DEFORMVERT_MOVE,
    zSHD_DEFORMVERT_AUTOSPRITE,
    zSHD_DEFORMVERT_AUTOSPRITE2
  };

  enum {
    LF_NOMIPMAP   = 0x01,
    LF_NOPICMIP   = 0x02,
    LF_CLAMP      = 0x04,
    LF_DETAIL     = 0x08,
    LF_LIGHTMAP   = 0x10,
    LF_HASTCMOD   = 0x20,
    LF_USENORMALS = 0x40,
    LF_MULTITEX   = 0x80
  };

  enum {
    SF_NOMIPMAP      = 0x01,
    SF_NOPICMIP      = 0x02,
    SF_POLYGONOFFSET = 0x04,
    SF_PORTAL        = 0x08,
    SF_HASLIGHTMAP   = 0x10,
    SF_HASCOLORS     = 0x20,
    SF_HASTCMOD      = 0x40,
    SF_USENORMALS    = 0x80,
    SF_MULTITEX      = 0x0100
  };

  enum zTShaderFXMode {
    zSHD_FX_NONE,
    zSHD_FX_BASETEX,
    zSHD_FX_LIGHTMAP,
    zSHD_FX_LIGHTMAP_DYN,
    zSHD_FX_DETAIL,
    zSHD_FX_MACRO,
    zSHD_FX_ENV,
    zSHD_FX_SPECULAR
  };

  // sizeof 2Ch
  class zCRenderManager {
  public:

    unsigned long frameCtr;                       // sizeof 04h    offset 00h
    zCArray<zCMaterial*> sceneMaterialList;       // sizeof 0Ch    offset 04h
    zCArray<zCPolygon*> sceneSimpleAlphaPolyList; // sizeof 0Ch    offset 10h
    int overrideAlphaValue;                       // sizeof 04h    offset 1Ch
    zTRnd_AlphaBlendFunc overrideAlphaBlendFunc;  // sizeof 04h    offset 20h
    int hintLightning;                            // sizeof 04h    offset 24h
    int rendererMaterialModified;                 // sizeof 04h    offset 28h

    void zCRenderManager_OnInit()                                                                                   zCall( 0x005D0810 );
    zCRenderManager()                                                                                               zInit( zCRenderManager_OnInit() );
    ~zCRenderManager()                                                                                              zCall( 0x005D0840 );
    void InitRenderManager()                                                                                        zCall( 0x005D0910 );
    void CleanupRenderManager()                                                                                     zCall( 0x005D0A20 );
    void __fastcall AddPolyAlphaSimple( zCPolygon* )                                                                zCall( 0x005D0C70 );
    void FlushSimpleAlphaPolys()                                                                                    zCall( 0x005D0D40 );
    void Flush()                                                                                                    zCall( 0x005D0E30 );
    void __fastcall SortMaterialPolys( zCMaterial* )                                                                zCall( 0x005D10F0 );
    void __fastcall BuildShader( zCMaterial*, zCTexture*, unsigned long, int, int, zCShader*& )                     zCall( 0x005D1110 );
    zCVertexBufferDyn2* __fastcall GetFreeDynVertexBuffer( zCShader* )                                              zCall( 0x005D1DA0 );
    void __fastcall SetRGBA( zCShaderStage* )                                                                       zCall( 0x005D1EB0 );
    void __fastcall SetStageColorOp( unsigned long, zTRnd_AlphaBlendFunc )                                          zCall( 0x005D1F90 );
    void __fastcall SetTextureStage0( zCShader*, unsigned long, zCVertexBuffer* )                                   zCall( 0x005D2010 );
    void __fastcall SetTextureTransform( zCShader*, unsigned long, unsigned long )                                  zCall( 0x005D2160 );
    void __fastcall SetAlphaFunc( zCShader*, unsigned long, unsigned long )                                         zCall( 0x005D2430 );
    void __fastcall DrawVertexBuffer( zCVertexBuffer*, int, int, unsigned short*, unsigned long, zCMaterial*, int ) zCall( 0x005D2570 );
    void __fastcall DrawVertexBuffer( zCVertexBuffer*, int, int, unsigned short*, unsigned long, zCShader* )        zCall( 0x005D25D0 );
    void __fastcall DrawVertexBufferSingleMaterial( zCArray<zCPolygon*> const&, zCShader* )                         zCall( 0x005D2930 );
    void __fastcall PackVB( zCArray<zCPolygon*> const&, zCShader* )                                                 zCall( 0x005D2940 );
    static zCShader* GetFreeShader()                                                                                zCall( 0x005D0A90 );
    static zCShaderStage* GetFreeShaderStage()                                                                      zCall( 0x005D0B80 );

    // static properties
    static zCShader*& s_shaderList;
    static zCShaderStage*& s_shaderStageList;
    static int& s_currentShader;
    static int& s_currentShaderStage;
    static int& s_useRendererTNL;
    static int& s_detailTexturesEnabled;
    static zCVertexBufferDyn2*& s_vertBufferDynTex1;
    static zCVertexBufferDyn2*& s_vertBufferDynTex2;
    static zCVertexBufferDyn2*& s_vertBufferDynTex2Normal;

    // user API
    #include "zCRenderManager.inl"
  };

  // sizeof 30h
  class zCShaderStage {
  public:
    zTShaderFXMode shaderFXMode;    // sizeof 04h    offset 00h
    zCTexture* texture;             // sizeof 04h    offset 04h
    zTRnd_AlphaBlendFunc alphaFunc; // sizeof 04h    offset 08h
    zCOLOR colorFactor;             // sizeof 04h    offset 0Ch
    zCOLOR avgTextureColor;         // sizeof 04h    offset 10h
    zTShaderAlphaGen alphaGen;      // sizeof 04h    offset 14h
    zTShaderRGBGen rgbGen;          // sizeof 04h    offset 18h
    zTShaderTCGen tcGen;            // sizeof 04h    offset 1Ch
    zTShaderTCMod tcMod;            // sizeof 04h    offset 20h
    float tcModParams[2];           // sizeof 08h    offset 24h
    int multiTextureNext;           // sizeof 04h    offset 2Ch

    void zCShaderStage_OnInit() zCall( 0x005D02F0 );
    zCShaderStage()             zInit( zCShaderStage_OnInit() );

    // user API
    #include "zCShaderStage.inl"
  };

  // sizeof 24h
  class zCShader {
  public:

    int numStages;                        // sizeof 04h    offset 00h
    zCShaderStage* stageList[MAX_STAGES]; // sizeof 10h    offset 04h
    int hasLightmap;                      // sizeof 04h    offset 14h
    int hasTcGenEnv;                      // sizeof 04h    offset 18h
    int inSector;                         // sizeof 04h    offset 1Ch
    int baseTexCachedIn;                  // sizeof 04h    offset 20h

    void zCShader_OnInit()                  zCall( 0x005D0290 );
    void Clear()                            zCall( 0x005C6E20 );
    zCShader()                              zInit( zCShader_OnInit() );
    ~zCShader()                             zCall( 0x005D02B0 );
    void InsertStage( int, zCShaderStage* ) zCall( 0x005D02C0 );

    // user API
    #include "zCShader.inl"
  };

  // sizeof 01h
  class zCMapDetailTexture {
  public:
    // sizeof 18h
    struct zTMapDetailTextureEntry {
      zSTRING detailTextureName; // sizeof 14h    offset 00h
      float detailTextureScale;  // sizeof 04h    offset 14h

      zTMapDetailTextureEntry() {}
      ~zTMapDetailTextureEntry() zCall( 0x005D4450 );

      // user API
      #include "zCMapDetailTexture_zTMapDetailTextureEntry.inl"
    };

    zCMapDetailTexture() {}
    static void S_Init()                                                           zCall( 0x005D4140 );
    static void S_Cleanup()                                                        zCall( 0x005D4520 );
    static zTMapDetailTextureEntry const* S_GetDetailTextureInfo( zSTRING const& ) zCall( 0x005D4530 );

    // user API
    #include "zCMapDetailTexture.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZRENDER_MANAGER_H__VER2__