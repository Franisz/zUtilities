// Supported with union (c) 2018-2021 Union team

#ifndef __ZRND_D3D_H__VER1__
#define __ZRND_D3D_H__VER1__

namespace Gothic_I_Addon {
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

  // sizeof 100h
  class zD3D_alphaPoly : public zCRndAlphaSortObject {
  public:

    // sizeof 1Ch
    struct zD3D_vertexFormat {
      D3DVALUE a_sx;    // sizeof 04h    offset 00h
      D3DVALUE a_sy;    // sizeof 04h    offset 04h
      D3DVALUE a_sz;    // sizeof 04h    offset 08h
      D3DVALUE a_rhw;   // sizeof 04h    offset 0Ch
      D3DCOLOR a_color; // sizeof 04h    offset 10h
      D3DVALUE a_tu;    // sizeof 04h    offset 14h
      D3DVALUE a_tv;    // sizeof 04h    offset 18h

      zD3D_vertexFormat() {}

      // user API
      #include "zD3D_alphaPoly_zD3D_vertexFormat.inl"
    };

    zTRnd_AlphaBlendFunc alphafunc;          // sizeof 04h    offset 0Ch
    zCTex_D3D* tex;                          // sizeof 04h    offset 10h
    int wrap;                                // sizeof 04h    offset 14h
    unsigned long zfunc;                     // sizeof 04h    offset 18h
    int numVert;                             // sizeof 04h    offset 1Ch
    zD3D_vertexFormat vertexList[zMAX_VERT]; // sizeof E0h    offset 20h

    void zD3D_alphaPoly_OnInit() zCall( 0x0074FA00 );
    zD3D_alphaPoly()             zInit( zD3D_alphaPoly_OnInit() );
    virtual ~zD3D_alphaPoly()    zCall( 0x0074FA20 );
    virtual void Draw( int )     zCall( 0x00754B20 );
    virtual int IsAlphaPoly()    zCall( 0x0074FA10 );

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

  // sizeof 80E58h
  class zCRnd_D3D : public zCRenderer {
  public:
    // sizeof 7Ch
    struct zD3D_Status {
      int modeNr;                      // sizeof 04h    offset 00h
      int devnum;                      // sizeof 04h    offset 04h
      int devmax;                      // sizeof 04h    offset 08h
      int texwrap;                     // sizeof 04h    offset 0Ch
      int filter;                      // sizeof 04h    offset 10h
      int dither;                      // sizeof 04h    offset 14h
      int fog;                         // sizeof 04h    offset 18h
      float nearZ;                     // sizeof 04h    offset 1Ch
      float farZ;                      // sizeof 04h    offset 20h
      zCOLOR fogColor;                 // sizeof 04h    offset 24h
      int fogMode;                     // sizeof 04h    offset 28h
      zTRnd_AlphaBlendFunc alphafunc;  // sizeof 04h    offset 2Ch
      zTRnd_AlphaBlendSource alphasrc; // sizeof 04h    offset 30h
      float alphafactor;               // sizeof 04h    offset 34h
      int zenable;                     // sizeof 04h    offset 38h
      int fenable;                     // sizeof 04h    offset 3Ch
      float zbias;                     // sizeof 04h    offset 40h
      zTRnd_ZBufferCmp zfunc;          // sizeof 04h    offset 44h
      int zwrite;                      // sizeof 04h    offset 48h
      unsigned long zd3dfunc;          // sizeof 04h    offset 4Ch
      DDPIXELFORMAT ddpf;              // sizeof 20h    offset 50h
      float gammavalue;                // sizeof 04h    offset 70h
      int palsupported;                // sizeof 04h    offset 74h
      zTRnd_RenderMode renderMode;     // sizeof 04h    offset 78h

      zD3D_Status() {}

      // user API
      #include "zCRnd_D3D_zD3D_Status.inl"
    };

    // sizeof 50h
    struct zD3D_Caps {
      unsigned long vidmemsize; // sizeof 04h    offset 00h
      unsigned long vidmemfree; // sizeof 04h    offset 04h
      unsigned long mintexsize; // sizeof 04h    offset 08h
      unsigned long maxtexsize; // sizeof 04h    offset 0Ch
      int window;               // sizeof 04h    offset 10h
      int gamma;                // sizeof 04h    offset 14h
      int multitexture;         // sizeof 04h    offset 18h
      int ztest;                // sizeof 04h    offset 1Ch
      int guardband;            // sizeof 04h    offset 20h
      float guardbandleft;      // sizeof 04h    offset 24h
      float guardbandright;     // sizeof 04h    offset 28h
      float guardbandtop;       // sizeof 04h    offset 2Ch
      float guardbandbottom;    // sizeof 04h    offset 30h
      int alphatest;            // sizeof 04h    offset 34h
      int num_stages;           // sizeof 04h    offset 38h
      int num_texstages;        // sizeof 04h    offset 3Ch
      int tnl;                  // sizeof 04h    offset 40h
      int tnl_hardware;         // sizeof 04h    offset 44h
      int tnl_maxlights;        // sizeof 04h    offset 48h
      int blendDiffuseAlpha;    // sizeof 04h    offset 4Ch

      zD3D_Caps() {}

      // user API
      #include "zCRnd_D3D_zD3D_Caps.inl"
    };

    unsigned long xd3d_actRenderState[MAXRENDERSTATES];                    // sizeof 280h   offset 34h
    unsigned long xd3d_actTexStageState[MAXTEXTURESTAGES][zRND_TSS_COUNT]; // sizeof 180h   offset 2B4h
    zD3D_Status xd3d_actStatus;                                            // sizeof 7Ch    offset 434h
    zD3D_Caps xd3d_Capabilities;                                           // sizeof 50h    offset 4B0h
    DDDEVICEIDENTIFIER2 xd3d_deviceIdentifier;                             // sizeof 430h   offset 500h
    unsigned int xd3d_numLightmapsUsedThisFrame;                           // sizeof 04h    offset 930h
    int xd3d_wBuffer;                                                      // sizeof 04h    offset 934h
    zTRnd_DepthBufferLevel xd3d_zwBufferLevel;                             // sizeof 04h    offset 938h
    int xd3d_alphaTest;                                                    // sizeof 04h    offset 93Ch
    int xd3d_alphaBlendImmed;                                              // sizeof 04h    offset 940h
    int xd3d_backlocked;                                                   // sizeof 04h    offset 944h
    IDirectDrawSurface7* xd3d_pfrontBuffer;                                // sizeof 04h    offset 948h
    IDirectDrawSurface7* xd3d_pbackBuffer;                                 // sizeof 04h    offset 94Ch
    IDirectDrawSurface7* xd3d_pzBuffer;                                    // sizeof 04h    offset 950h
    IDirectDrawClipper* xd3d_pclipper;                                     // sizeof 04h    offset 954h
    IDirectDrawGammaControl* xd3d_pgammacontrol;                           // sizeof 04h    offset 958h
    DDPIXELFORMAT xd3d_pixelformat;                                        // sizeof 20h    offset 95Ch
    int xd3d_deviceChange;                                                 // sizeof 04h    offset 97Ch
    zTRnd_ScreenMode xd3d_scrMode;                                         // sizeof 04h    offset 980h
    int xd3d_scrStatus;                                                    // sizeof 04h    offset 984h
    int xd3d_scrWidth;                                                     // sizeof 04h    offset 988h
    int xd3d_scrHeight;                                                    // sizeof 04h    offset 98Ch
    int xd3d_scrBpp;                                                       // sizeof 04h    offset 990h
    int xd3d_num;                                                          // sizeof 04h    offset 994h
    zTRnd_ScreenMode xd3d_mode;                                            // sizeof 04h    offset 998h
    int xd3d_x;                                                            // sizeof 04h    offset 99Ch
    int xd3d_y;                                                            // sizeof 04h    offset 9A0h
    int xd3d_bpp;                                                          // sizeof 04h    offset 9A4h
    float xd3d_zMAX_from_Engine;                                           // sizeof 04h    offset 9A8h
    float xd3d_zMIN_from_Engine;                                           // sizeof 04h    offset 9ACh
    float xd3d_scale_A;                                                    // sizeof 04h    offset 9B0h
    float xd3d_scale_B;                                                    // sizeof 04h    offset 9B4h
    float xd3d_scale_C;                                                    // sizeof 04h    offset 9B8h
    zCMaterial* xd3d_pactivematerial;                                      // sizeof 04h    offset 9BCh
    zTMaterial xd3d_actmaterial;                                           // sizeof 20h    offset 9C0h
    zTRnd_Stats xd3d_statistics;                                           // sizeof 24h    offset 9E0h
    HWND xd3d_newWinHandle;                                                // sizeof 04h    offset A04h
    HWND xd3d_winHandle;                                                   // sizeof 04h    offset A08h
    zTRnd_RenderMode xd3d_renderMode;                                      // sizeof 04h    offset A0Ch
    int xd3d_tryDevnum;                                                    // sizeof 04h    offset A10h
    int xd3d_inScene;                                                      // sizeof 04h    offset A14h
    int xd3d_disableFog;                                                   // sizeof 04h    offset A18h
    zD3D_alphaPoly xd3d_alphaPolyPool[MAXALPHAPOLYS];                      // sizeof 80000h offset A1Ch
    int xd3d_numAlphaPolys;                                                // sizeof 04h    offset 80A1Ch
    zCRndAlphaSortObject* xd3d_alphaSortBucket[MAXBUCKETS];                // sizeof 400h   offset 80A20h
    float xd3d_bucketSize;                                                 // sizeof 04h    offset 80E20h
    int xd3d_vbclipping;                                                   // sizeof 04h    offset 80E24h
    unsigned long xd3d_texturefactor;                                      // sizeof 04h    offset 80E28h
    zCTex_D3D* xd3d_ptexture[MAXTEXTURESTAGES];                            // sizeof 10h    offset 80E2Ch
    IDirectDrawSurface7* xd3d_pd3dtexture[MAXTEXTURESTAGES];               // sizeof 10h    offset 80E3Ch
    unsigned int xd3d_numTexturesUsedThisFrame;                            // sizeof 04h    offset 80E4Ch
    zD3D_savedTexture* xd3d_savedTexture;                                  // sizeof 04h    offset 80E50h

    void zCRnd_D3D_OnInit()                                                                    zCall( 0x0074EF30 );
    int XD3D_EnumerateModes()                                                                  zCall( 0x007497A0 );
    int XD3D_InitPerDX( long, int, int, int, int )                                             zCall( 0x007497E0 );
    int XD3D_InitPort( int, int, int, int, int )                                               zCall( 0x0074A690 );
    int XD3D_TestCapabilities()                                                                zCall( 0x0074D170 );
    int XD3D_SetDevice( int, int, int, int, zTRnd_ScreenMode )                                 zCall( 0x0074DA60 );
    void XD3D_ClearDevice()                                                                    zCall( 0x0074DFB0 );
    int XD3D_TextureRescue( zCTex_D3D* )                                                       zCall( 0x0074E450 );
    int XD3D_TextureRebuild()                                                                  zCall( 0x0074E680 );
    int XD3D_CreateWin( int, int, int )                                                        zCall( 0x0074E8D0 );
    void XD3D_CloseWin()                                                                       zCall( 0x0074EDF0 );
    zCRnd_D3D()                                                                                zInit( zCRnd_D3D_OnInit() );
    void EmergencyExit()                                                                       zCall( 0x0074FD20 );
    void XD3D_PolyDrawOnePassVertLight( zCPolygon* )                                           zCall( 0x00750BF0 );
    void XD3D_PolyDrawOnePassMultiTex( zCPolygon* )                                            zCall( 0x00751350 );
    void XD3D_PolyDrawTwoPassTexture( zCPolygon* )                                             zCall( 0x00751A70 );
    void XD3D_AlphaBlendPoly( zCPolygon*, zCMaterial* )                                        zCall( 0x00752230 );
    void XD3D_PolyDrawTwoPassLightMap( zCPolygon* )                                            zCall( 0x00752620 );
    int XD3D_SetTexture( unsigned long, IDirectDrawSurface7* )                                 zCall( 0x00754240 );
    int XD3D_SetRenderState( _D3DRENDERSTATETYPE, unsigned long )                              zCall( 0x007546B0 );
    int XD3D_DrawVertexBufferWire( zCVertexBuffer*, int, int, unsigned short*, unsigned long ) zCall( 0x007555E0 );
    int XD3D_DrawVertexBufferFlat( zCVertexBuffer*, int, int, unsigned short*, unsigned long ) zCall( 0x00755790 );
    int SupportAlphaTesting()                                                                  zCall( 0x00756170 );
    unsigned short GetTexturePortableBinaryVersion()                                           zCall( 0x00756470 );
    int XD3D_SetMode( int, int, int )                                                          zCall( 0x0075C6E0 );
    virtual ~zCRnd_D3D()                                                                       zCall( 0x0074FA50 );
    virtual void BeginFrame()                                                                  zCall( 0x00752ED0 );
    virtual void EndFrame()                                                                    zCall( 0x007530D0 );
    virtual void FlushPolys()                                                                  zCall( 0x00752EC0 );
    virtual void DrawPoly( zCPolygon* )                                                        zCall( 0x00750960 );
    virtual void DrawLightmapList( zCPolygon**, int )                                          zCall( 0x007527D0 );
    virtual void DrawLine( float, float, float, float, zCOLOR )                                zCall( 0x00752A70 );
    virtual void DrawLineZ( float, float, float, float, float, float, zCOLOR )                 zCall( 0x00752C90 );
    virtual void SetPixel( float, float, zCOLOR )                                              zCall( 0x00752890 );
    virtual void DrawPolySimple( zCTexture*, zTRndSimpleVertex*, int )                         zCall( 0x007501C0 );
    virtual void SetFog( int )                                                                 zCall( 0x00755D60 );
    virtual int GetFog() const                                                                 zCall( 0x00755DF0 );
    virtual void SetFogColor( zCOLOR const& )                                                  zCall( 0x00755E00 );
    virtual zCOLOR GetFogColor() const                                                         zCall( 0x00755E30 );
    virtual void SetFogRange( float, float, int )                                              zCall( 0x00755E40 );
    virtual void GetFogRange( float&, float&, int& )                                           zCall( 0x00755E90 );
    virtual zTRnd_PolyDrawMode GetPolyDrawMode() const                                         zCall( 0x00755ED0 );
    virtual void SetPolyDrawMode( zTRnd_PolyDrawMode const& )                                  zCall( 0x00755EC0 );
    virtual void SetTextureWrapEnabled( int )                                                  zCall( 0x00755EE0 );
    virtual int GetTextureWrapEnabled() const                                                  zCall( 0x00755EF0 );
    virtual void SetBilerpFilterEnabled( int )                                                 zCall( 0x00755F00 );
    virtual int GetBilerpFilterEnabled() const                                                 zCall( 0x00755F80 );
    virtual void SetDitherEnabled( int )                                                       zCall( 0x00755F90 );
    virtual int GetDitherEnabled() const                                                       zCall( 0x00755FA0 );
    virtual zTRnd_PolySortMode GetPolySortMode() const                                         zCall( 0x00756010 );
    virtual void SetPolySortMode( zTRnd_PolySortMode const& )                                  zCall( 0x00755FB0 );
    virtual int GetZBufferWriteEnabled() const                                                 zCall( 0x00756040 );
    virtual void SetZBufferWriteEnabled( int )                                                 zCall( 0x00756020 );
    virtual zTRnd_ZBufferCmp GetZBufferCompare()                                               zCall( 0x007560E0 );
    virtual void SetZBufferCompare( zTRnd_ZBufferCmp const& )                                  zCall( 0x00756050 );
    virtual int GetPixelWriteEnabled() const                                                   zCall( 0x00756100 );
    virtual void SetPixelWriteEnabled( int )                                                   zCall( 0x007560F0 );
    virtual void SetAlphaBlendSource( zTRnd_AlphaBlendSource const& )                          zCall( 0x00756110 );
    virtual zTRnd_AlphaBlendSource GetAlphaBlendSource() const                                 zCall( 0x00756120 );
    virtual void SetAlphaBlendFunc( zTRnd_AlphaBlendFunc const& )                              zCall( 0x00756130 );
    virtual zTRnd_AlphaBlendFunc GetAlphaBlendFunc() const                                     zCall( 0x00756140 );
    virtual float GetAlphaBlendFactor() const                                                  zCall( 0x00756160 );
    virtual void SetAlphaBlendFactor( float const& )                                           zCall( 0x00756150 );
    virtual void SetRenderMode( zTRnd_RenderMode )                                             zCall( 0x00756180 );
    virtual zTRnd_RenderMode GetRenderMode() const                                             zCall( 0x007562E0 );
    virtual int HasCapability( zTRnd_Capability ) const                                        zCall( 0x007562F0 );
    virtual void GetGuardBandBorders( float&, float&, float&, float& )                         zCall( 0x00756480 );
    virtual void ResetZTest()                                                                  zCall( 0x00756450 );
    virtual int HasPassedZTest()                                                               zCall( 0x00756460 );
    virtual zCTexture* CreateTexture()                                                         zCall( 0x00757200 );
    virtual zCTextureConvert* CreateTextureConvert()                                           zCall( 0x00757390 );
    virtual int GetTotalTextureMem()                                                           zCall( 0x00757290 );
    virtual int SupportsTextureFormat( zTRnd_TextureFormat )                                   zCall( 0x007572A0 );
    virtual int SupportsTextureFormatHardware( zTRnd_TextureFormat )                           zCall( 0x00757330 );
    virtual int GetMaxTextureSize()                                                            zCall( 0x00757380 );
    virtual void GetStatistics( zTRnd_Stats& )                                                 zCall( 0x007564F0 );
    virtual void ResetStatistics()                                                             zCall( 0x00756540 );
    virtual void Vid_Blit( int, tagRECT*, tagRECT* )                                           zCall( 0x0075B540 );
    virtual void Vid_Clear( zCOLOR&, int )                                                     zCall( 0x0075BD50 );
    virtual int Vid_Lock( zTRndSurfaceDesc& )                                                  zCall( 0x0075B840 );
    virtual int Vid_Unlock()                                                                   zCall( 0x0075B8F0 );
    virtual int Vid_IsLocked()                                                                 zCall( 0x0074F980 );
    virtual int Vid_GetFrontBufferCopy( zCTextureConvert& )                                    zCall( 0x0075B930 );
    virtual int Vid_GetNumDevices()                                                            zCall( 0x0075BDD0 );
    virtual int Vid_GetActiveDeviceNr()                                                        zCall( 0x0075BDE0 );
    virtual int Vid_SetDevice( int )                                                           zCall( 0x0075BDF0 );
    virtual int Vid_GetDeviceInfo( zTRnd_DeviceInfo&, int )                                    zCall( 0x0075C0F0 );
    virtual int Vid_GetNumModes()                                                              zCall( 0x0075C2F0 );
    virtual int Vid_GetModeInfo( zTRnd_VidModeInfo&, int )                                     zCall( 0x0075C300 );
    virtual int Vid_GetActiveModeNr()                                                          zCall( 0x0075C4F0 );
    virtual int Vid_SetMode( int, HWND__** )                                                   zCall( 0x0075C500 );
    virtual void Vid_SetScreenMode( zTRnd_ScreenMode )                                         zCall( 0x0075CA50 );
    virtual zTRnd_ScreenMode Vid_GetScreenMode()                                               zCall( 0x0075CE70 );
    virtual void Vid_SetGammaCorrection( float, float, float )                                 zCall( 0x0075CE80 );
    virtual float Vid_GetGammaCorrection()                                                     zCall( 0x0075D480 );
    virtual void Vid_BeginLfbAccess()                                                          zCall( 0x0074F990 );
    virtual void Vid_EndLfbAccess()                                                            zCall( 0x0074F9A0 );
    virtual void Vid_SetLfbAlpha( int )                                                        zCall( 0x0074F9B0 );
    virtual void Vid_SetLfbAlphaFunc( zTRnd_AlphaBlendFunc const& )                            zCall( 0x0074F9C0 );
    virtual int SetTransform( zTRnd_TrafoType, zMAT4 const& )                                  zCall( 0x007530E0 );
    virtual int SetViewport( int, int, int, int )                                              zCall( 0x00753530 );
    virtual int SetLight( unsigned long, zCRenderLight* )                                      zCall( 0x007535A0 );
    virtual int GetMaterial( zCRenderer::zTMaterial& )                                         zCall( 0x007541F0 );
    virtual int SetMaterial( zCRenderer::zTMaterial const& )                                   zCall( 0x007540F0 );
    virtual int SetTexture( unsigned long, zCTexture* )                                        zCall( 0x007542A0 );
    virtual int SetTextureStageState( unsigned long, zTRnd_TextureStageState, unsigned long )  zCall( 0x00754360 );
    virtual int SetAlphaBlendFuncImmed( zTRnd_AlphaBlendFunc )                                 zCall( 0x00754400 );
    virtual int SetRenderState( zTRnd_RenderStateType, unsigned long )                         zCall( 0x00754640 );
    virtual unsigned long GetRenderState( zTRnd_RenderStateType )                              zCall( 0x00754760 );
    virtual void AddAlphaSortObject( zCRndAlphaSortObject* )                                   zCall( 0x00754790 );
    virtual void RenderAlphaSortList()                                                         zCall( 0x00754860 );
    virtual int DrawVertexBuffer( zCVertexBuffer*, int, int, unsigned short*, unsigned long )  zCall( 0x007558C0 );
    virtual zCVertexBuffer* CreateVertexBuffer()                                               zCall( 0x00755CA0 );

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

  // sizeof 28804h
  class zCSurfaceCache_D3D {
  public:
    // sizeof 14h
    struct zCSlotIndex {
      int dynamic;     // sizeof 04h    offset 00h
      int pixelformat; // sizeof 04h    offset 04h
      int mipmaps;     // sizeof 04h    offset 08h
      int width;       // sizeof 04h    offset 0Ch
      int height;      // sizeof 04h    offset 10h

      zCSlotIndex() {}

      // user API
      #include "zCSurfaceCache_D3D_zCSlotIndex.inl"
    };

    // sizeof 0Ch
    struct zD3D_Entry {
      IDirectDrawSurface7* surface; // sizeof 04h    offset 00h
      unsigned long frameNumber;    // sizeof 04h    offset 04h
      zD3D_Entry* nextEntry;        // sizeof 04h    offset 08h

      zD3D_Entry() {}

      // user API
      #include "zCSurfaceCache_D3D_zD3D_Entry.inl"
    };

    // sizeof 08h
    struct zD3D_SlotHeader {
      zD3D_Entry* firstEntry; // sizeof 04h    offset 00h
      zD3D_Entry* lastEntry;  // sizeof 04h    offset 04h

      zD3D_SlotHeader() {}

      // user API
      #include "zCSurfaceCache_D3D_zD3D_SlotHeader.inl"
    };

    int xsc_cacheentryCounter;                  // sizeof 04h    offset 00h
    zD3D_SlotHeader xsc_slot[2][6][12][12][12]; // sizeof 28800h offset 04h

    void zCSurfaceCache_D3D_OnInit()                         zCall( 0x00756590 );
    zCSurfaceCache_D3D()                                     zInit( zCSurfaceCache_D3D_OnInit() );
    ~zCSurfaceCache_D3D()                                    zCall( 0x007565C0 );
    int CacheInSurface( IDirectDrawSurface7*, zCSlotIndex* ) zCall( 0x007565D0 );
    IDirectDrawSurface7* CacheOutSurface( zCSlotIndex* )     zCall( 0x00756A60 );
    void ClearCache()                                        zCall( 0x00756E80 );
    void XSC_ClearSlot( zD3D_SlotHeader* )                   zCall( 0x00756F80 );
    void XSC_KillLastSurfaceInSlot( zD3D_SlotHeader* )       zCall( 0x007570C0 );

    static zD3D_SlotHeader**& xsc_listofsurfaces;
    static int& xsc_listposition;

    // user API
    #include "zCSurfaceCache_D3D.inl"
  };

  // sizeof 904h
  class zCDXTCCache_D3D {
  public:
    // sizeof 0Ch
    struct zD3D_Entry {
      IDirectDrawSurface7* surface; // sizeof 04h    offset 00h
      int locked;                   // sizeof 04h    offset 04h
      zD3D_Entry* nextEntry;        // sizeof 04h    offset 08h

      zD3D_Entry() {}

      // user API
      #include "zCDXTCCache_D3D_zD3D_Entry.inl"
    };

    // sizeof 08h
    struct zD3D_SlotHeader {
      zD3D_Entry* firstEntry; // sizeof 04h    offset 00h
      zD3D_Entry* lastEntry;  // sizeof 04h    offset 04h

      zD3D_SlotHeader() {}

      // user API
      #include "zCDXTCCache_D3D_zD3D_SlotHeader.inl"
    };

    int xdxtc_cacheentryCounter;           // sizeof 04h    offset 00h
    zD3D_SlotHeader xdxtc_slot[2][12][12]; // sizeof 900h   offset 04h

    void zCDXTCCache_D3D_OnInit()                                          zCall( 0x00748810 );
    zCDXTCCache_D3D()                                                      zInit( zCDXTCCache_D3D_OnInit() );
    ~zCDXTCCache_D3D()                                                     zCall( 0x00748840 );
    IDirectDrawSurface7* Lock( int, int, int )                             zCall( 0x00748850 );
    int Unlock( int, int, int, IDirectDrawSurface7* )                      zCall( 0x00748950 );
    void ClearCache()                                                      zCall( 0x00748AB0 );
    IDirectDrawSurface7* XDXTC_CreateSurface( int, int, int, zD3D_Entry* ) zCall( 0x00748D50 );

    // user API
    #include "zCDXTCCache_D3D.inl"
  };

  // sizeof 0Ch
  struct zD3D_savedTexture {
    zCTex_D3D* texture;       // sizeof 04h    offset 00h
    zCTextureConvert* texCon; // sizeof 04h    offset 04h
    zD3D_savedTexture* next;  // sizeof 04h    offset 08h

    zD3D_savedTexture() {}

    // user API
    #include "zD3D_savedTexture.inl"
  };

  // sizeof 13Ch
  class zCTex_D3D : public zCTexture {
  public:
    unsigned int xtex_textureflag;                  // sizeof 04h    offset 8Ch
    group {
      int                         : 17;             // sizeof 11h    offset bit
      int xtex_decompress         : 1;              // sizeof 01h    offset bit
      int xtex_locked             : 1;              // sizeof 01h    offset bit
      int xtex_palsupport         : 1;              // sizeof 01h    offset bit
      unsigned int xtex_miplocked : 12;             // sizeof 0Ch    offset bit
    };
    zCTextureInfo xtex_texinfo;                     // sizeof 1Ch    offset 94h
    zCSurfaceCache_D3D::zCSlotIndex xtex_slotindex; // sizeof 14h    offset B0h
    unsigned char* xtex_pPalettePtr;                // sizeof 04h    offset C4h
    IDirectDrawPalette* xtex_pddpal;                // sizeof 04h    offset C8h
    int xtex_internalnumber;                        // sizeof 04h    offset CCh
    int xtex_alphaTex;                              // sizeof 04h    offset D0h
    IDirectDrawSurface7* xtex_pddtex[12];           // sizeof 30h    offset D4h
    IDirectDrawSurface7* xtex_pddtemporarytex[12];  // sizeof 30h    offset 104h
    unsigned long xtex_lastFrameUsed;               // sizeof 04h    offset 134h
    void* xtex_buffer;                              // sizeof 04h    offset 138h

    void zCTex_D3D_OnInit()                            zCall( 0x00757400 );
    zCTex_D3D()                                        zInit( zCTex_D3D_OnInit() );
    void GetPixelSize( int&, int& )                    zCall( 0x00757B80 );
    int XTEX_BuildSurfaces( int )                      zCall( 0x007590F0 );
    void InsertTexture( int, int )                     zCall( 0x00759E90 );
    int PreloadTexture()                               zCall( 0x0075A100 );
    int SetTexture( int )                              zCall( 0x0075A130 );
    int RemoveTexture()                                zCall( 0x0075A330 );
    int RescueTexture( zD3D_savedTexture* )            zCall( 0x0075A4D0 );
    int RebuildTexture( zD3D_savedTexture* )           zCall( 0x0075A520 );
    /* for zCResource num : 11*/
    virtual ~zCTex_D3D()                               zCall( 0x00757500 );
    virtual void ReleaseData()                         zCall( 0x00757560 );
    /* for zCTextureExchange num : 10*/
    virtual int Lock( int )                            zCall( 0x00757690 );
    virtual int Unlock()                               zCall( 0x007576E0 );
    virtual int SetTextureInfo( zCTextureInfo const& ) zCall( 0x007579B0 );
    virtual void* GetPaletteBuffer()                   zCall( 0x007583D0 );
    virtual int GetTextureBuffer( int, void*&, int& )  zCall( 0x00758510 );
    virtual zCTextureInfo GetTextureInfo()             zCall( 0x00757960 );
    virtual int CopyPaletteDataTo( void* )             zCall( 0x007582C0 );
    virtual int CopyTextureDataTo( int, void*, int )   zCall( 0x00757CB0 );

    // user API
    #include "zCTex_D3D.inl"
  };

  // sizeof 88h
  class zCVertexBuffer_D3D : public zCVertexBuffer {
  public:
    group {
      int                                      : 23; // sizeof 17h    offset bit
      unsigned char xvb_optimized              : 1;  // sizeof 01h    offset bit
      unsigned char xvb_locked                 : 1;  // sizeof 01h    offset bit
      zTVBufferVertexType xvb_vertexType       : 3;  // sizeof 03h    offset bit
      zTVBufferPrimitiveType xvb_primitiveType : 4;  // sizeof 04h    offset bit
    };
    unsigned long xvb_vertexFormat;                  // sizeof 04h    offset 74h
    IDirect3DVertexBuffer7* xvb_vertexBuffer;        // sizeof 04h    offset 78h
    zCArray<unsigned short> xvb_indexList;           // sizeof 0Ch    offset 7Ch

    void zCVertexBuffer_D3D_OnInit()                                  zCall( 0x0075AA40 );
    zCVertexBuffer_D3D()                                              zInit( zCVertexBuffer_D3D_OnInit() );
    virtual ~zCVertexBuffer_D3D()                                     zCall( 0x0075AC10 );
    virtual int Create( unsigned long, unsigned long, unsigned long ) zCall( 0x0075ACC0 );
    virtual int Destroy()                                             zCall( 0x0075AE60 );
    virtual int Lock( unsigned long )                                 zCall( 0x0075AF50 );
    virtual int Unlock()                                              zCall( 0x0075B290 );
    virtual int IsLocked()                                            zCall( 0x0075ABD0 );
    virtual int Optimize()                                            zCall( 0x0075B2E0 );
    virtual int SetPrimitiveType( zTVBufferPrimitiveType )            zCall( 0x0075B330 );
    virtual zTVBufferPrimitiveType GetPrimitiveType()                 zCall( 0x0075B350 );
    virtual unsigned long GetVertexFormat()                           zCall( 0x0075B360 );
    virtual zTVBufferVertexType GetVertexType()                       zCall( 0x0075B370 );
    virtual int SetIndexList( zCArray<unsigned short> const& )        zCall( 0x0075B450 );
    virtual int SetIndexListSize( unsigned long )                     zCall( 0x0075B380 );
    virtual unsigned long GetIndexListSize()                          zCall( 0x0075B420 );
    virtual unsigned short* GetIndexListPtr()                         zCall( 0x0075B430 );

    static zCArray<zCVertexBuffer_D3D*>& xvb_vertexbufferList;

    // user API
    #include "zCVertexBuffer_D3D.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZRND_D3D_H__VER1__