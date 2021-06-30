// Supported with union (c) 2018 Union team

#ifndef __ZRND_D3D_H__VER3__
#define __ZRND_D3D_H__VER3__

#include "zMaterial.h"
#include "zRenderer.h"
#include "z3d.h"
#include "zVideo_Win32.h"
#include "zTexConvert.h"
#include "zVertexBuffer.h"

namespace Gothic_II_Addon {
  const unsigned int MAXBUCKETS       = 256;
  const unsigned int MAXALPHAPOLYS    = 2048;
  const unsigned int MAXTEXTURESTAGES = 4;
  const unsigned int MAXRENDERSTATES  = 160;
  const int zMAX_VERT                 = 8;

  enum zTRnd_DepthBufferLevel {
    zRND_W32_BUFFER,
    zRND_W24_BUFFER,
    zRND_W16_BUFFER,
    zRND_Z32_BUFFER,
    zRND_Z24_BUFFER,
    zRND_Z16_BUFFER,
    zRND_UNKNOWN_BUFFER
  };

  class zD3D_alphaPoly : public zCRndAlphaSortObject {
  public:

    struct zD3D_vertexFormat {
      D3DVALUE a_sx;
      D3DVALUE a_sy;
      D3DVALUE a_sz;
      D3DVALUE a_rhw;
      D3DCOLOR a_color;
      D3DVALUE a_tu;
      D3DVALUE a_tv;

      zD3D_vertexFormat() {}

      // user API
      #include "zD3D_alphaPoly_zD3D_vertexFormat.inl"
    };

    zTRnd_AlphaBlendFunc alphafunc;
    zCTex_D3D* tex;
    int wrap;
    unsigned long zfunc;
    int numVert;
    int zBias;
    zD3D_vertexFormat vertexList[zMAX_VERT];

    void zD3D_alphaPoly_OnInit() zCall( 0x0064A520 );
    zD3D_alphaPoly()             zInit( zD3D_alphaPoly_OnInit() );
    virtual ~zD3D_alphaPoly()    zCall( 0x0064A540 );
    virtual void Draw( int )     zCall( 0x00650CF0 );
    virtual int IsAlphaPoly()    zCall( 0x0064A530 );

    // static properties
    static zCVertexBufferDyn*& vertexbufferdyn;
    static zCVertexBuffer*& vertexbuffer;
    static int& locked;
    static unsigned long& startvertex;
    static unsigned long& actvertex;
    static int& numberofvertices;
    static int& actnov;

    // user API
    #include "zD3D_alphaPoly.inl"
  };

  class zCRnd_D3D : public zCRenderer {
  public:
    struct zD3D_Status {
      int modeNr;
      int devnum;
      int devmax;
      int texwrap;
      int filter;
      int dither;
      int fog;
      float nearZ;
      float farZ;
      zCOLOR fogColor;
      int fogMode;
      zTRnd_AlphaBlendFunc alphafunc;
      zTRnd_AlphaBlendSource alphasrc;
      float alphafactor;
      int zenable;
      int fenable;
      zTRnd_ZBufferCmp zfunc;
      int zwrite;
      int zbias;
      unsigned long zd3dfunc;
      DDPIXELFORMAT ddpf;
      float gammavalue;
      int palsupported;
      zTRnd_RenderMode renderMode;

      zD3D_Status() {}

      // user API
      #include "zCRnd_D3D_zD3D_Status.inl"
    };

    struct zD3D_Caps {
      unsigned long vidmemsize;
      unsigned long vidmemfree;
      unsigned long mintexsize;
      unsigned long maxtexsize;
      int window;
      int gamma;
      int multitexture;
      int ztest;
      int guardband;
      float guardbandleft;
      float guardbandright;
      float guardbandtop;
      float guardbandbottom;
      int alphatest;
      int num_stages;
      int num_texstages;
      int tnl;
      int tnl_hardware;
      int tnl_maxlights;
      int blendDiffuseAlpha;
      int hasStencil;

      zD3D_Caps() {}

      // user API
      #include "zCRnd_D3D_zD3D_Caps.inl"
    };

    int fogType;
    unsigned long xd3d_actRenderState[MAXRENDERSTATES];
    unsigned long xd3d_actTexStageState[MAXTEXTURESTAGES][zRND_TSS_COUNT];
    zD3D_Status xd3d_actStatus;
    zD3D_Caps xd3d_Capabilities;
    DDDEVICEIDENTIFIER2 xd3d_deviceIdentifier;
    unsigned int xd3d_numLightmapsUsedThisFrame;
    int xd3d_wBuffer;
    zTRnd_DepthBufferLevel xd3d_zwBufferLevel;
    int xd3d_alphaTest;
    int xd3d_alphaBlendImmed;
    int xd3d_backlocked;
    IDirectDrawSurface7* xd3d_pfrontBuffer;
    IDirectDrawSurface7* xd3d_pbackBuffer;
    IDirectDrawSurface7* xd3d_pzBuffer;
    IDirectDrawClipper* xd3d_pclipper;
    IDirectDrawGammaControl* xd3d_pgammacontrol;
    DDPIXELFORMAT xd3d_pixelformat;
    int xd3d_deviceChange;
    zTRnd_ScreenMode xd3d_scrMode;
    int xd3d_scrStatus;
    int xd3d_scrWidth;
    int xd3d_scrHeight;
    int xd3d_scrBpp;
    int xd3d_num;
    zTRnd_ScreenMode xd3d_mode;
    int xd3d_x;
    int xd3d_y;
    int xd3d_bpp;
    float xd3d_zMAX_from_Engine;
    float xd3d_zMIN_from_Engine;
    float xd3d_scale_A;
    float xd3d_scale_B;
    float xd3d_scale_C;
    zCMaterial* xd3d_pactivematerial;
    zTMaterial xd3d_actmaterial;
    zTRnd_Stats xd3d_statistics;
    HWND xd3d_newWinHandle;
    HWND xd3d_winHandle;
    zTRnd_RenderMode xd3d_renderMode;
    int xd3d_tryDevnum;
    int xd3d_inScene;
    int xd3d_disableFog;
    int xd3d_enableRadialFog;
    zD3D_alphaPoly xd3d_alphaPolyPool[MAXALPHAPOLYS];
    int xd3d_numAlphaPolys;
    zCRndAlphaSortObject* xd3d_alphaSortBucket[MAXBUCKETS];
    float xd3d_bucketSize;
    unsigned long alphaReference;
    int xd3d_vbclipping;
    unsigned long xd3d_texturefactor;
    int m_bAlphaLimitReached;
    int m_bSurfaceLost;
    zCTex_D3D* xd3d_ptexture[MAXTEXTURESTAGES];
    IDirectDrawSurface7* xd3d_pd3dtexture[MAXTEXTURESTAGES];
    unsigned int xd3d_numTexturesUsedThisFrame;
    zD3D_savedTexture* xd3d_savedTexture;
    int m_bCacheAlphaPolys;
    int m_bAnisotropicFilter;
    int m_bMustFlushOnAmbientColor;
    zD3D_alphaPoly* immediateAlphaPolyRoot;
    zD3D_alphaPoly* immediateAlphaPolyParent;

    void zCRnd_D3D_OnInit()                                                                    zCall( 0x00649800 );
    int XD3D_EnumerateModes()                                                                  zCall( 0x00643EE0 );
    int XD3D_InitPerDX( long, int, int, int, int )                                             zCall( 0x00643F20 );
    int XD3D_SetRenderState( _D3DRENDERSTATETYPE, unsigned long )                              zCall( 0x00644EF0 );
    int XD3D_InitPort( int, int, int, int, int )                                               zCall( 0x00645150 );
    int XD3D_TestCapabilities()                                                                zCall( 0x00647BB0 );
    int XD3D_SetDevice( int, int, int, int, zTRnd_ScreenMode )                                 zCall( 0x00648330 );
    void XD3D_ClearDevice()                                                                    zCall( 0x00648820 );
    int XD3D_TextureRescue( zCTex_D3D* )                                                       zCall( 0x00648D10 );
    int XD3D_TextureRebuild()                                                                  zCall( 0x00648F00 );
    int XD3D_CreateWin( int, int, int )                                                        zCall( 0x00649150 );
    void XD3D_CloseWin()                                                                       zCall( 0x006496C0 );
    zCRnd_D3D()                                                                                zInit( zCRnd_D3D_OnInit() );
    void EmergencyExit()                                                                       zCall( 0x0064A800 );
    void XD3D_PolyDrawOnePassVertLight( zCPolygon* )                                           zCall( 0x0064B470 );
    void XD3D_PolyDrawOnePassMultiTex( zCPolygon* )                                            zCall( 0x0064BA50 );
    void XD3D_PolyDrawTwoPassTexture( zCPolygon* )                                             zCall( 0x0064C110 );
    void XD3D_AlphaTestPoly( zCPolygon* )                                                      zCall( 0x0064C840 );
    void XD3D_AlphaBlendPoly( zCPolygon*, zCMaterial* )                                        zCall( 0x0064C960 );
    void XD3D_PolyDrawTwoPassLightMap( zCPolygon* )                                            zCall( 0x0064D4E0 );
    int XD3D_SetTexture( unsigned long, IDirectDrawSurface7* )                                 zCall( 0x00650500 );
    int XD3D_DrawVertexBufferWire( zCVertexBuffer*, int, int, unsigned short*, unsigned long ) zCall( 0x00651720 );
    int XD3D_DrawVertexBufferFlat( zCVertexBuffer*, int, int, unsigned short*, unsigned long ) zCall( 0x006518D0 );
    void SetFogType( int )                                                                     zCall( 0x006520E0 );
    int SupportAlphaTesting()                                                                  zCall( 0x00652650 );
    unsigned short GetTexturePortableBinaryVersion()                                           zCall( 0x00652A30 );
    int XD3D_SetMode( int, int, int )                                                          zCall( 0x00658850 );
    virtual ~zCRnd_D3D()                                                                       zCall( 0x0064A570 );
    virtual void BeginFrame()                                                                  zCall( 0x0064DD20 );
    virtual void EndFrame()                                                                    zCall( 0x0064DF20 );
    virtual void FlushPolys()                                                                  zCall( 0x0064DD10 );
    virtual void DrawPoly( zCPolygon* )                                                        zCall( 0x0064B260 );
    virtual void DrawLightmapList( zCPolygon**, int )                                          zCall( 0x0064D660 );
    virtual void DrawLine( float, float, float, float, zCOLOR )                                zCall( 0x0064D8E0 );
    virtual void DrawLineZ( float, float, float, float, float, float, zCOLOR )                 zCall( 0x0064DB00 );
    virtual void SetPixel( float, float, zCOLOR )                                              zCall( 0x0064D720 );
    virtual void DrawPolySimple( zCTexture*, zTRndSimpleVertex*, int )                         zCall( 0x0064AC30 );
    virtual void SetFog( int )                                                                 zCall( 0x00651E80 );
    virtual int GetFog() const                                                                 zCall( 0x00652070 );
    virtual void SetRadialFog( int )                                                           zCall( 0x00652010 );
    virtual int GetRadialFog() const                                                           zCall( 0x0064A400 );
    virtual void SetFogColor( zCOLOR const& )                                                  zCall( 0x00652080 );
    virtual zCOLOR GetFogColor() const                                                         zCall( 0x006521D0 );
    virtual void SetFogRange( float, float, int )                                              zCall( 0x006521E0 );
    virtual void GetFogRange( float&, float&, int& )                                           zCall( 0x006522D0 );
    virtual zTRnd_PolyDrawMode GetPolyDrawMode() const                                         zCall( 0x00652310 );
    virtual void SetPolyDrawMode( zTRnd_PolyDrawMode const& )                                  zCall( 0x00652300 );
    virtual int GetSurfaceLost() const                                                         zCall( 0x0064A470 );
    virtual void SetSurfaceLost( int )                                                         zCall( 0x0064A480 );
    virtual int GetSyncOnAmbientCol() const                                                    zCall( 0x0064A490 );
    virtual void SetSyncOnAmbientCol( int )                                                    zCall( 0x0064A4A0 );
    virtual void SetTextureWrapEnabled( int )                                                  zCall( 0x00652320 );
    virtual int GetTextureWrapEnabled() const                                                  zCall( 0x00652330 );
    virtual void SetBilerpFilterEnabled( int )                                                 zCall( 0x00652340 );
    virtual int GetBilerpFilterEnabled() const                                                 zCall( 0x006523D0 );
    virtual void SetDitherEnabled( int )                                                       zCall( 0x006523E0 );
    virtual int GetDitherEnabled() const                                                       zCall( 0x006523F0 );
    virtual zTRnd_PolySortMode GetPolySortMode() const                                         zCall( 0x006524D0 );
    virtual void SetPolySortMode( zTRnd_PolySortMode const& )                                  zCall( 0x00652400 );
    virtual int GetZBufferWriteEnabled() const                                                 zCall( 0x00652520 );
    virtual void SetZBufferWriteEnabled( int )                                                 zCall( 0x006524E0 );
    virtual void SetZBias( int )                                                               zCall( 0x006529E0 );
    virtual int GetZBias() const                                                               zCall( 0x006529D0 );
    virtual zTRnd_ZBufferCmp GetZBufferCompare()                                               zCall( 0x006525C0 );
    virtual void SetZBufferCompare( zTRnd_ZBufferCmp const& )                                  zCall( 0x00652530 );
    virtual int GetPixelWriteEnabled() const                                                   zCall( 0x006525E0 );
    virtual void SetPixelWriteEnabled( int )                                                   zCall( 0x006525D0 );
    virtual void SetAlphaBlendSource( zTRnd_AlphaBlendSource const& )                          zCall( 0x006525F0 );
    virtual zTRnd_AlphaBlendSource GetAlphaBlendSource() const                                 zCall( 0x00652600 );
    virtual void SetAlphaBlendFunc( zTRnd_AlphaBlendFunc const& )                              zCall( 0x00652610 );
    virtual zTRnd_AlphaBlendFunc GetAlphaBlendFunc() const                                     zCall( 0x00652620 );
    virtual float GetAlphaBlendFactor() const                                                  zCall( 0x00652640 );
    virtual void SetAlphaBlendFactor( float const& )                                           zCall( 0x00652630 );
    virtual void SetAlphaReference( unsigned long )                                            zCall( 0x0064A420 );
    virtual unsigned long GetAlphaReference() const                                            zCall( 0x0064A430 );
    virtual int GetCacheAlphaPolys() const                                                     zCall( 0x0064A450 );
    virtual void SetCacheAlphaPolys( int )                                                     zCall( 0x0064A460 );
    virtual int GetAlphaLimitReached() const                                                   zCall( 0x0064A440 );
    virtual void AddAlphaPoly( zCPolygon const* )                                              zCall( 0x0064CD60 );
    virtual void FlushAlphaPolys()                                                             zCall( 0x0064D400 );
    virtual void SetRenderMode( zTRnd_RenderMode )                                             zCall( 0x00652660 );
    virtual zTRnd_RenderMode GetRenderMode() const                                             zCall( 0x00652840 );
    virtual int HasCapability( zTRnd_Capability ) const                                        zCall( 0x00652850 );
    virtual void GetGuardBandBorders( float&, float&, float&, float& )                         zCall( 0x00652A40 );
    virtual void ResetZTest()                                                                  zCall( 0x006529B0 );
    virtual int HasPassedZTest()                                                               zCall( 0x006529C0 );
    virtual zCTexture* CreateTexture()                                                         zCall( 0x00653650 );
    virtual zCTextureConvert* CreateTextureConvert()                                           zCall( 0x006537D0 );
    virtual int GetTotalTextureMem()                                                           zCall( 0x006536D0 );
    virtual int SupportsTextureFormat( zTRnd_TextureFormat )                                   zCall( 0x006536E0 );
    virtual int SupportsTextureFormatHardware( zTRnd_TextureFormat )                           zCall( 0x00653770 );
    virtual int GetMaxTextureSize()                                                            zCall( 0x006537C0 );
    virtual void GetStatistics( zTRnd_Stats& )                                                 zCall( 0x00652AB0 );
    virtual void ResetStatistics()                                                             zCall( 0x00652B00 );
    virtual void Vid_Blit( int, tagRECT*, tagRECT* )                                           zCall( 0x00657670 );
    virtual void Vid_Clear( zCOLOR&, int )                                                     zCall( 0x00657E20 );
    virtual int Vid_Lock( zTRndSurfaceDesc& )                                                  zCall( 0x00657950 );
    virtual int Vid_Unlock()                                                                   zCall( 0x00657A00 );
    virtual int Vid_IsLocked()                                                                 zCall( 0x0064A4B0 );
    virtual int Vid_GetFrontBufferCopy( zCTextureConvert& )                                    zCall( 0x00657A40 );
    virtual int Vid_GetNumDevices()                                                            zCall( 0x00657EA0 );
    virtual int Vid_GetActiveDeviceNr()                                                        zCall( 0x00657EB0 );
    virtual int Vid_SetDevice( int )                                                           zCall( 0x00657EC0 );
    virtual int Vid_GetDeviceInfo( zTRnd_DeviceInfo&, int )                                    zCall( 0x00658190 );
    virtual int Vid_GetNumModes()                                                              zCall( 0x006583B0 );
    virtual int Vid_GetModeInfo( zTRnd_VidModeInfo&, int )                                     zCall( 0x006583C0 );
    virtual int Vid_GetActiveModeNr()                                                          zCall( 0x00658600 );
    virtual int Vid_SetMode( int, HWND__** )                                                   zCall( 0x00658610 );
    virtual void Vid_SetScreenMode( zTRnd_ScreenMode )                                         zCall( 0x00658BA0 );
    virtual zTRnd_ScreenMode Vid_GetScreenMode()                                               zCall( 0x00658FB0 );
    virtual void Vid_SetGammaCorrection( float, float, float )                                 zCall( 0x00658FC0 );
    virtual float Vid_GetGammaCorrection()                                                     zCall( 0x00659610 );
    virtual void Vid_BeginLfbAccess()                                                          zCall( 0x00651D90 );
    virtual void Vid_EndLfbAccess()                                                            zCall( 0x0064A4C0 );
    virtual void Vid_SetLfbAlpha( int )                                                        zCall( 0x0064A4D0 );
    virtual void Vid_SetLfbAlphaFunc( zTRnd_AlphaBlendFunc const& )                            zCall( 0x0064A4E0 );
    virtual int SetTransform( zTRnd_TrafoType, zMAT4 const& )                                  zCall( 0x0064ED50 );
    virtual int SetViewport( int, int, int, int )                                              zCall( 0x0064F100 );
    virtual int SetLight( unsigned long, zCRenderLight* )                                      zCall( 0x0064F700 );
    virtual int GetMaterial( zCRenderer::zTMaterial& )                                         zCall( 0x006504B0 );
    virtual int SetMaterial( zCRenderer::zTMaterial const& )                                   zCall( 0x006503B0 );
    virtual int SetTexture( unsigned long, zCTexture* )                                        zCall( 0x00650560 );
    virtual int SetTextureStageState( unsigned long, zTRnd_TextureStageState, unsigned long )  zCall( 0x00650630 );
    virtual int SetAlphaBlendFuncImmed( zTRnd_AlphaBlendFunc )                                 zCall( 0x006506D0 );
    virtual int SetRenderState( zTRnd_RenderStateType, unsigned long )                         zCall( 0x006508F0 );
    virtual unsigned long GetRenderState( zTRnd_RenderStateType )                              zCall( 0x00650960 );
    virtual void AddAlphaSortObject( zCRndAlphaSortObject* )                                   zCall( 0x00650990 );
    virtual void RenderAlphaSortList()                                                         zCall( 0x00650A60 );
    virtual int DrawVertexBuffer( zCVertexBuffer*, int, int, unsigned short*, unsigned long )  zCall( 0x006519F0 );
    virtual zCVertexBuffer* CreateVertexBuffer()                                               zCall( 0x00651DD0 );

    // static properties
    static struct ID3DXContext*& xd3d_pd3dx;
    static IDirectDraw7*& xd3d_pdd7;
    static IDirect3D7*& xd3d_pd3d7;
    static IDirect3DDevice7*& xd3d_pd3dDevice7;
    static unsigned long& xd3d_actFrameNumber;
    static int& xd3d_dd7inuse;
    static int& xd3d_palsupp;

    // user API
    #include "zCRnd_D3D.inl"
  };

  class zCSurfaceCache_D3D {
  public:
    struct zCSlotIndex {
      int dynamic;
      int pixelformat;
      int mipmaps;
      int width;
      int height;

      zCSlotIndex() {}

      // user API
      #include "zCSurfaceCache_D3D_zCSlotIndex.inl"
    };

    struct zD3D_Entry {
      IDirectDrawSurface7* surface;
      unsigned long frameNumber;
      zD3D_Entry* nextEntry;

      zD3D_Entry() {}

      // user API
      #include "zCSurfaceCache_D3D_zD3D_Entry.inl"
    };

    struct zD3D_SlotHeader {
      zD3D_Entry* firstEntry;
      zD3D_Entry* lastEntry;

      zD3D_SlotHeader() {}

      // user API
      #include "zCSurfaceCache_D3D_zD3D_SlotHeader.inl"
    };

    int xsc_cacheentryCounter;
    zD3D_SlotHeader xsc_slot[2][6][12][12][12];

    void zCSurfaceCache_D3D_OnInit()                         zCall( 0x00652B50 );
    zCSurfaceCache_D3D()                                     zInit( zCSurfaceCache_D3D_OnInit() );
    ~zCSurfaceCache_D3D()                                    zCall( 0x00652B80 );
    int CacheInSurface( IDirectDrawSurface7*, zCSlotIndex* ) zCall( 0x00652B90 );
    IDirectDrawSurface7* CacheOutSurface( zCSlotIndex* )     zCall( 0x00652F40 );
    void ClearCache()                                        zCall( 0x006532D0 );
    void XSC_ClearSlot( zD3D_SlotHeader* )                   zCall( 0x006533D0 );
    void XSC_KillLastSurfaceInSlot( zD3D_SlotHeader* )       zCall( 0x00653500 );
    static void ResetSurfaceList()                           zCall( 0x00647760 );

    // static properties
    static zCSurfaceCache_D3D::zD3D_SlotHeader**& xsc_listofsurfaces;
    static int& xsc_listposition;

    // user API
    #include "zCSurfaceCache_D3D.inl"
  };

  class zCDXTCCache_D3D {
  public:
    struct zD3D_Entry {
      IDirectDrawSurface7* surface;
      int locked;
      zD3D_Entry* nextEntry;

      zD3D_Entry() {}

      // user API
      #include "zCDXTCCache_D3D_zD3D_Entry.inl"
    };

    struct zD3D_SlotHeader {
      zD3D_Entry* firstEntry;
      zD3D_Entry* lastEntry;

      zD3D_SlotHeader() {}

      // user API
      #include "zCDXTCCache_D3D_zD3D_SlotHeader.inl"
    };

    int xdxtc_cacheentryCounter;
    zD3D_SlotHeader xdxtc_slot[2][12][12];

    void zCDXTCCache_D3D_OnInit()                                          zCall( 0x00642F10 );
    zCDXTCCache_D3D()                                                      zInit( zCDXTCCache_D3D_OnInit() );
    ~zCDXTCCache_D3D()                                                     zCall( 0x00642F40 );
    IDirectDrawSurface7* Lock( int, int, int )                             zCall( 0x00642F50 );
    int Unlock( int, int, int, IDirectDrawSurface7* )                      zCall( 0x00643040 );
    void ClearCache()                                                      zCall( 0x00643170 );
    IDirectDrawSurface7* XDXTC_CreateSurface( int, int, int, zD3D_Entry* ) zCall( 0x00643470 );

    // user API
    #include "zCDXTCCache_D3D.inl"
  };

  struct zD3D_savedTexture {
    zCTex_D3D* texture;
    zCTextureConvert* texCon;
    zD3D_savedTexture* next;

    zD3D_savedTexture() {}

    // user API
    #include "zD3D_savedTexture.inl"
  };

  class zCTex_D3D : public zCTexture {
  public:
    unsigned int xtex_textureflag;
    group {
      int                         : 17;
      int xtex_decompress         : 1;
      int xtex_locked             : 1;
      int xtex_palsupport         : 1;
      unsigned int xtex_miplocked : 12;
    };
    zCTextureInfo xtex_texinfo;
    zCSurfaceCache_D3D::zCSlotIndex xtex_slotindex;
    unsigned char* xtex_pPalettePtr;
    IDirectDrawPalette* xtex_pddpal;
    int xtex_internalnumber;
    int xtex_alphaTex;
    IDirectDrawSurface7* xtex_pddtex[12];
    IDirectDrawSurface7* xtex_pddtemporarytex[12];
    unsigned long xtex_lastFrameUsed;
    void* xtex_buffer;

    void zCTex_D3D_OnInit()                            zCall( 0x00653830 );
    zCTex_D3D()                                        zInit( zCTex_D3D_OnInit() );
    void GetPixelSize( int&, int& )                    zCall( 0x00653F90 );
    int XTEX_BuildSurfaces( int )                      zCall( 0x006552A0 );
    void InsertTexture( int, int )                     zCall( 0x00656120 );
    int PreloadTexture()                               zCall( 0x00656370 );
    int SetTexture( int )                              zCall( 0x006563A0 );
    int RemoveTexture()                                zCall( 0x00656590 );
    int RescueTexture( zD3D_savedTexture* )            zCall( 0x00656710 );
    int RebuildTexture( zD3D_savedTexture* )           zCall( 0x00656750 );
    /* for zCResource num : 11*/
    virtual ~zCTex_D3D()                               zCall( 0x00653930 );
    virtual void ReleaseData()                         zCall( 0x00653990 );
    /* for zCTextureExchange num : 10*/
    virtual int Lock( int )                            zCall( 0x00653AA0 );
    virtual int Unlock()                               zCall( 0x00653AF0 );
    virtual int SetTextureInfo( zCTextureInfo const& ) zCall( 0x00653DC0 );
    virtual void* GetPaletteBuffer()                   zCall( 0x006546F0 );
    virtual int GetTextureBuffer( int, void*&, int& )  zCall( 0x006547F0 );
    virtual zCTextureInfo GetTextureInfo()             zCall( 0x00653D70 );
    virtual int CopyPaletteDataTo( void* )             zCall( 0x006545E0 );
    virtual int CopyTextureDataTo( int, void*, int )   zCall( 0x006540A0 );

    // user API
    #include "zCTex_D3D.inl"
  };

  class zCVertexBuffer_D3D : public zCVertexBuffer {
  public:
    group {
      int                                      : 23;
      unsigned char xvb_optimized              : 1;
      unsigned char xvb_locked                 : 1;
      zTVBufferVertexType xvb_vertexType       : 3;
      zTVBufferPrimitiveType xvb_primitiveType : 4;
    };
    unsigned long xvb_vertexFormat;
    IDirect3DVertexBuffer7* xvb_vertexBuffer;
    zCArray<unsigned short> xvb_indexList;

    void zCVertexBuffer_D3D_OnInit()                                  zCall( 0x00656C10 );
    zCVertexBuffer_D3D()                                              zInit( zCVertexBuffer_D3D_OnInit() );
    virtual ~zCVertexBuffer_D3D()                                     zCall( 0x00656DC0 );
    virtual int Create( unsigned long, unsigned long, unsigned long ) zCall( 0x00656E70 );
    virtual int Destroy()                                             zCall( 0x00657010 );
    virtual int Lock( unsigned long )                                 zCall( 0x006570E0 );
    virtual int Unlock()                                              zCall( 0x006573E0 );
    virtual int IsLocked()                                            zCall( 0x00656D80 );
    virtual int Optimize()                                            zCall( 0x00657430 );
    virtual int SetPrimitiveType( zTVBufferPrimitiveType )            zCall( 0x00657480 );
    virtual zTVBufferPrimitiveType GetPrimitiveType()                 zCall( 0x006574A0 );
    virtual unsigned long GetVertexFormat()                           zCall( 0x006574B0 );
    virtual zTVBufferVertexType GetVertexType()                       zCall( 0x006574C0 );
    virtual int SetIndexList( zCArray<unsigned short> const& )        zCall( 0x00657590 );
    virtual int SetIndexListSize( unsigned long )                     zCall( 0x006574D0 );
    virtual unsigned long GetIndexListSize()                          zCall( 0x00657560 );
    virtual unsigned short* GetIndexListPtr()                         zCall( 0x00657570 );

    // static properties
    static zCArray<zCVertexBuffer_D3D*>& xvb_vertexbufferList;

    // user API
    #include "zCVertexBuffer_D3D.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZRND_D3D_H__VER3__