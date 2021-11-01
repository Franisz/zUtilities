// Supported with union (c) 2018-2021 Union team

#ifndef __ZRND_D3D_H__VER0__
#define __ZRND_D3D_H__VER0__

namespace Gothic_I_Classic {
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

    void zD3D_alphaPoly_OnInit() zCall( 0x00713CE0 );
    zD3D_alphaPoly()             zInit( zD3D_alphaPoly_OnInit() );
    virtual ~zD3D_alphaPoly()    zCall( 0x00713D00 );
    virtual void Draw( int )     zCall( 0x00718A20 );
    virtual int IsAlphaPoly()    zCall( 0x00713CF0 );

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

    void zCRnd_D3D_OnInit()                                                                    zCall( 0x00713260 );
    int XD3D_EnumerateModes()                                                                  zCall( 0x0070E4F0 );
    int XD3D_InitPerDX( long, int, int, int, int )                                             zCall( 0x0070E530 );
    int XD3D_InitPort( int, int, int, int, int )                                               zCall( 0x0070F250 );
    int XD3D_TestCapabilities()                                                                zCall( 0x00711780 );
    int XD3D_SetDevice( int, int, int, int, zTRnd_ScreenMode )                                 zCall( 0x00711F00 );
    void XD3D_ClearDevice()                                                                    zCall( 0x007123F0 );
    int XD3D_TextureRescue( zCTex_D3D* )                                                       zCall( 0x00712860 );
    int XD3D_TextureRebuild()                                                                  zCall( 0x00712A60 );
    int XD3D_CreateWin( int, int, int )                                                        zCall( 0x00712C80 );
    void XD3D_CloseWin()                                                                       zCall( 0x00713120 );
    zCRnd_D3D()                                                                                zInit( zCRnd_D3D_OnInit() );
    void EmergencyExit()                                                                       zCall( 0x00713FC0 );
    void XD3D_PolyDrawOnePassVertLight( zCPolygon* )                                           zCall( 0x00714DD0 );
    void XD3D_PolyDrawOnePassMultiTex( zCPolygon* )                                            zCall( 0x007154F0 );
    void XD3D_PolyDrawTwoPassTexture( zCPolygon* )                                             zCall( 0x00715BC0 );
    void XD3D_AlphaBlendPoly( zCPolygon*, zCMaterial* )                                        zCall( 0x00716320 );
    void XD3D_PolyDrawTwoPassLightMap( zCPolygon* )                                            zCall( 0x007166D0 );
    int XD3D_SetTexture( unsigned long, IDirectDrawSurface7* )                                 zCall( 0x00718150 );
    int XD3D_SetRenderState( _D3DRENDERSTATETYPE, unsigned long )                              zCall( 0x007185C0 );
    int XD3D_DrawVertexBufferWire( zCVertexBuffer*, int, int, unsigned short*, unsigned long ) zCall( 0x00719440 );
    int XD3D_DrawVertexBufferFlat( zCVertexBuffer*, int, int, unsigned short*, unsigned long ) zCall( 0x007195F0 );
    int SupportAlphaTesting()                                                                  zCall( 0x00719F80 );
    unsigned short GetTexturePortableBinaryVersion()                                           zCall( 0x0071A280 );
    int XD3D_SetMode( int, int, int )                                                          zCall( 0x0071FE30 );
    virtual ~zCRnd_D3D()                                                                       zCall( 0x00713D30 );
    virtual void BeginFrame()                                                                  zCall( 0x00716F60 );
    virtual void EndFrame()                                                                    zCall( 0x00717150 );
    virtual void FlushPolys()                                                                  zCall( 0x00716F50 );
    virtual void DrawPoly( zCPolygon* )                                                        zCall( 0x00714B60 );
    virtual void DrawLightmapList( zCPolygon**, int )                                          zCall( 0x00716860 );
    virtual void DrawLine( float, float, float, float, zCOLOR )                                zCall( 0x00716B00 );
    virtual void DrawLineZ( float, float, float, float, float, float, zCOLOR )                 zCall( 0x00716D20 );
    virtual void SetPixel( float, float, zCOLOR )                                              zCall( 0x00716920 );
    virtual void DrawPolySimple( zCTexture*, zTRndSimpleVertex*, int )                         zCall( 0x007143F0 );
    virtual void SetFog( int )                                                                 zCall( 0x00719B70 );
    virtual int GetFog() const                                                                 zCall( 0x00719C10 );
    virtual void SetFogColor( zCOLOR const& )                                                  zCall( 0x00719C20 );
    virtual zCOLOR GetFogColor() const                                                         zCall( 0x00719C50 );
    virtual void SetFogRange( float, float, int )                                              zCall( 0x00719C60 );
    virtual void GetFogRange( float&, float&, int& )                                           zCall( 0x00719CB0 );
    virtual zTRnd_PolyDrawMode GetPolyDrawMode() const                                         zCall( 0x00719CF0 );
    virtual void SetPolyDrawMode( zTRnd_PolyDrawMode const& )                                  zCall( 0x00719CE0 );
    virtual void SetTextureWrapEnabled( int )                                                  zCall( 0x00719D00 );
    virtual int GetTextureWrapEnabled() const                                                  zCall( 0x00719D10 );
    virtual void SetBilerpFilterEnabled( int )                                                 zCall( 0x00719D20 );
    virtual int GetBilerpFilterEnabled() const                                                 zCall( 0x00719DA0 );
    virtual void SetDitherEnabled( int )                                                       zCall( 0x00719DB0 );
    virtual int GetDitherEnabled() const                                                       zCall( 0x00719DC0 );
    virtual zTRnd_PolySortMode GetPolySortMode() const                                         zCall( 0x00719E20 );
    virtual void SetPolySortMode( zTRnd_PolySortMode const& )                                  zCall( 0x00719DD0 );
    virtual int GetZBufferWriteEnabled() const                                                 zCall( 0x00719E50 );
    virtual void SetZBufferWriteEnabled( int )                                                 zCall( 0x00719E30 );
    virtual zTRnd_ZBufferCmp GetZBufferCompare()                                               zCall( 0x00719EF0 );
    virtual void SetZBufferCompare( zTRnd_ZBufferCmp const& )                                  zCall( 0x00719E60 );
    virtual int GetPixelWriteEnabled() const                                                   zCall( 0x00719F10 );
    virtual void SetPixelWriteEnabled( int )                                                   zCall( 0x00719F00 );
    virtual void SetAlphaBlendSource( zTRnd_AlphaBlendSource const& )                          zCall( 0x00719F20 );
    virtual zTRnd_AlphaBlendSource GetAlphaBlendSource() const                                 zCall( 0x00719F30 );
    virtual void SetAlphaBlendFunc( zTRnd_AlphaBlendFunc const& )                              zCall( 0x00719F40 );
    virtual zTRnd_AlphaBlendFunc GetAlphaBlendFunc() const                                     zCall( 0x00719F50 );
    virtual float GetAlphaBlendFactor() const                                                  zCall( 0x00719F70 );
    virtual void SetAlphaBlendFactor( float const& )                                           zCall( 0x00719F60 );
    virtual void SetRenderMode( zTRnd_RenderMode )                                             zCall( 0x00719F90 );
    virtual zTRnd_RenderMode GetRenderMode() const                                             zCall( 0x0071A0F0 );
    virtual int HasCapability( zTRnd_Capability ) const                                        zCall( 0x0071A100 );
    virtual void GetGuardBandBorders( float&, float&, float&, float& )                         zCall( 0x0071A290 );
    virtual void ResetZTest()                                                                  zCall( 0x0071A260 );
    virtual int HasPassedZTest()                                                               zCall( 0x0071A270 );
    virtual zCTexture* CreateTexture()                                                         zCall( 0x0071AEE0 );
    virtual zCTextureConvert* CreateTextureConvert()                                           zCall( 0x0071B070 );
    virtual int GetTotalTextureMem()                                                           zCall( 0x0071AF70 );
    virtual int SupportsTextureFormat( zTRnd_TextureFormat )                                   zCall( 0x0071AF80 );
    virtual int SupportsTextureFormatHardware( zTRnd_TextureFormat )                           zCall( 0x0071B010 );
    virtual int GetMaxTextureSize()                                                            zCall( 0x0071B060 );
    virtual void GetStatistics( zTRnd_Stats& )                                                 zCall( 0x0071A300 );
    virtual void ResetStatistics()                                                             zCall( 0x0071A350 );
    virtual void Vid_Blit( int, tagRECT*, tagRECT* )                                           zCall( 0x0071EDA0 );
    virtual void Vid_Clear( zCOLOR&, int )                                                     zCall( 0x0071F550 );
    virtual int Vid_Lock( zTRndSurfaceDesc& )                                                  zCall( 0x0071F080 );
    virtual int Vid_Unlock()                                                                   zCall( 0x0071F130 );
    virtual int Vid_IsLocked()                                                                 zCall( 0x00713C60 );
    virtual int Vid_GetFrontBufferCopy( zCTextureConvert& )                                    zCall( 0x0071F170 );
    virtual int Vid_GetNumDevices()                                                            zCall( 0x0071F5D0 );
    virtual int Vid_GetActiveDeviceNr()                                                        zCall( 0x0071F5E0 );
    virtual int Vid_SetDevice( int )                                                           zCall( 0x0071F5F0 );
    virtual int Vid_GetDeviceInfo( zTRnd_DeviceInfo&, int )                                    zCall( 0x0071F8C0 );
    virtual int Vid_GetNumModes()                                                              zCall( 0x0071FA90 );
    virtual int Vid_GetModeInfo( zTRnd_VidModeInfo&, int )                                     zCall( 0x0071FAA0 );
    virtual int Vid_GetActiveModeNr()                                                          zCall( 0x0071FC60 );
    virtual int Vid_SetMode( int, HWND__** )                                                   zCall( 0x0071FC70 );
    virtual void Vid_SetScreenMode( zTRnd_ScreenMode )                                         zCall( 0x00720160 );
    virtual zTRnd_ScreenMode Vid_GetScreenMode()                                               zCall( 0x00720540 );
    virtual void Vid_SetGammaCorrection( float, float, float )                                 zCall( 0x00720550 );
    virtual float Vid_GetGammaCorrection()                                                     zCall( 0x00720AF0 );
    virtual void Vid_BeginLfbAccess()                                                          zCall( 0x00713C70 );
    virtual void Vid_EndLfbAccess()                                                            zCall( 0x00713C80 );
    virtual void Vid_SetLfbAlpha( int )                                                        zCall( 0x00713C90 );
    virtual void Vid_SetLfbAlphaFunc( zTRnd_AlphaBlendFunc const& )                            zCall( 0x00713CA0 );
    virtual int SetTransform( zTRnd_TrafoType, zMAT4 const& )                                  zCall( 0x00717160 );
    virtual int SetViewport( int, int, int, int )                                              zCall( 0x00717510 );
    virtual int SetLight( unsigned long, zCRenderLight* )                                      zCall( 0x00717580 );
    virtual int GetMaterial( zCRenderer::zTMaterial& )                                         zCall( 0x00718100 );
    virtual int SetMaterial( zCRenderer::zTMaterial const& )                                   zCall( 0x00718000 );
    virtual int SetTexture( unsigned long, zCTexture* )                                        zCall( 0x007181B0 );
    virtual int SetTextureStageState( unsigned long, zTRnd_TextureStageState, unsigned long )  zCall( 0x00718270 );
    virtual int SetAlphaBlendFuncImmed( zTRnd_AlphaBlendFunc )                                 zCall( 0x00718310 );
    virtual int SetRenderState( zTRnd_RenderStateType, unsigned long )                         zCall( 0x00718550 );
    virtual unsigned long GetRenderState( zTRnd_RenderStateType )                              zCall( 0x00718670 );
    virtual void AddAlphaSortObject( zCRndAlphaSortObject* )                                   zCall( 0x007186A0 );
    virtual void RenderAlphaSortList()                                                         zCall( 0x00718770 );
    virtual int DrawVertexBuffer( zCVertexBuffer*, int, int, unsigned short*, unsigned long )  zCall( 0x00719710 );
    virtual zCVertexBuffer* CreateVertexBuffer()                                               zCall( 0x00719AB0 );

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

    void zCSurfaceCache_D3D_OnInit()                         zCall( 0x0071A3A0 );
    zCSurfaceCache_D3D()                                     zInit( zCSurfaceCache_D3D_OnInit() );
    ~zCSurfaceCache_D3D()                                    zCall( 0x0071A3D0 );
    int CacheInSurface( IDirectDrawSurface7*, zCSlotIndex* ) zCall( 0x0071A3E0 );
    IDirectDrawSurface7* CacheOutSurface( zCSlotIndex* )     zCall( 0x0071A7F0 );
    void ClearCache()                                        zCall( 0x0071AB80 );
    void XSC_ClearSlot( zD3D_SlotHeader* )                   zCall( 0x0071AC80 );
    void XSC_KillLastSurfaceInSlot( zD3D_SlotHeader* )       zCall( 0x0071ADB0 );

    // static properties
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

    void zCDXTCCache_D3D_OnInit()                                          zCall( 0x0070D6C0 );
    zCDXTCCache_D3D()                                                      zInit( zCDXTCCache_D3D_OnInit() );
    ~zCDXTCCache_D3D()                                                     zCall( 0x0070D6F0 );
    IDirectDrawSurface7* Lock( int, int, int )                             zCall( 0x0070D700 );
    int Unlock( int, int, int, IDirectDrawSurface7* )                      zCall( 0x0070D800 );
    void ClearCache()                                                      zCall( 0x0070D930 );
    IDirectDrawSurface7* XDXTC_CreateSurface( int, int, int, zD3D_Entry* ) zCall( 0x0070DBA0 );

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

    void zCTex_D3D_OnInit()                            zCall( 0x0071B0E0 );
    zCTex_D3D()                                        zInit( zCTex_D3D_OnInit() );
    void GetPixelSize( int&, int& )                    zCall( 0x0071B840 );
    int XTEX_BuildSurfaces( int )                      zCall( 0x0071CB60 );
    void InsertTexture( int, int )                     zCall( 0x0071D7D0 );
    int PreloadTexture()                               zCall( 0x0071DA60 );
    int SetTexture( int )                              zCall( 0x0071DA90 );
    int RemoveTexture()                                zCall( 0x0071DC80 );
    int RescueTexture( zD3D_savedTexture* )            zCall( 0x0071DE00 );
    int RebuildTexture( zD3D_savedTexture* )           zCall( 0x0071DE40 );
    /* for zCResource num : 11*/
    virtual ~zCTex_D3D()                               zCall( 0x0071B1E0 );
    virtual void ReleaseData()                         zCall( 0x0071B240 );
    /* for zCTextureExchange num : 10*/
    virtual int Lock( int )                            zCall( 0x0071B350 );
    virtual int Unlock()                               zCall( 0x0071B3A0 );
    virtual int SetTextureInfo( zCTextureInfo const& ) zCall( 0x0071B670 );
    virtual void* GetPaletteBuffer()                   zCall( 0x0071BFA0 );
    virtual int GetTextureBuffer( int, void*&, int& )  zCall( 0x0071C0B0 );
    virtual zCTextureInfo GetTextureInfo()             zCall( 0x0071B620 );
    virtual int CopyPaletteDataTo( void* )             zCall( 0x0071BE90 );
    virtual int CopyTextureDataTo( int, void*, int )   zCall( 0x0071B950 );

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

    void zCVertexBuffer_D3D_OnInit()                                  zCall( 0x0071E310 );
    zCVertexBuffer_D3D()                                              zInit( zCVertexBuffer_D3D_OnInit() );
    virtual ~zCVertexBuffer_D3D()                                     zCall( 0x0071E4E0 );
    virtual int Create( unsigned long, unsigned long, unsigned long ) zCall( 0x0071E590 );
    virtual int Destroy()                                             zCall( 0x0071E730 );
    virtual int Lock( unsigned long )                                 zCall( 0x0071E800 );
    virtual int Unlock()                                              zCall( 0x0071EAF0 );
    virtual int IsLocked()                                            zCall( 0x0071E4A0 );
    virtual int Optimize()                                            zCall( 0x0071EB40 );
    virtual int SetPrimitiveType( zTVBufferPrimitiveType )            zCall( 0x0071EB90 );
    virtual zTVBufferPrimitiveType GetPrimitiveType()                 zCall( 0x0071EBB0 );
    virtual unsigned long GetVertexFormat()                           zCall( 0x0071EBC0 );
    virtual zTVBufferVertexType GetVertexType()                       zCall( 0x0071EBD0 );
    virtual int SetIndexList( zCArray<unsigned short> const& )        zCall( 0x0071ECB0 );
    virtual int SetIndexListSize( unsigned long )                     zCall( 0x0071EBE0 );
    virtual unsigned long GetIndexListSize()                          zCall( 0x0071EC80 );
    virtual unsigned short* GetIndexListPtr()                         zCall( 0x0071EC90 );

    // static properties
    static zCArray<zCVertexBuffer_D3D*>& xvb_vertexbufferList;

    // user API
    #include "zCVertexBuffer_D3D.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZRND_D3D_H__VER0__