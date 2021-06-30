// Supported with union (c) 2018 Union team

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
    zD3D_vertexFormat vertexList[zMAX_VERT];

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
      float zbias;
      zTRnd_ZBufferCmp zfunc;
      int zwrite;
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

      zD3D_Caps() {}

      // user API
      #include "zCRnd_D3D_zD3D_Caps.inl"
    };

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
    zD3D_alphaPoly xd3d_alphaPolyPool[MAXALPHAPOLYS];
    int xd3d_numAlphaPolys;
    zCRndAlphaSortObject* xd3d_alphaSortBucket[MAXBUCKETS];
    float xd3d_bucketSize;
    int xd3d_vbclipping;
    unsigned long xd3d_texturefactor;
    zCTex_D3D* xd3d_ptexture[MAXTEXTURESTAGES];
    IDirectDrawSurface7* xd3d_pd3dtexture[MAXTEXTURESTAGES];
    unsigned int xd3d_numTexturesUsedThisFrame;
    zD3D_savedTexture* xd3d_savedTexture;

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