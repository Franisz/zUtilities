// Supported with union (c) 2018 Union team

#ifndef __ZTEXTURE_H__VER0__
#define __ZTEXTURE_H__VER0__

namespace Gothic_I_Classic {
  const int zTEX_PAL_SIZE_BYTES = 768;
  const int zTEX_LOAD_FLAG_TILE = 1;
  const int zTEX_MAX_ANIS       = 3;

  enum zTTexScaleSize {
    zTEX_SCALE_SIZE_XY_ONE_LOWER,
    zTEX_SCALE_SIZE_X_ONE_LOWER,
    zTEX_SCALE_SIZE_REFERENCE,
    zTEX_SCALE_SIZE_Y_ONE_HIGHER,
    zTEX_SCALE_SIZE_XY_ONE_HIGHER_EVERY_SECOND,
    zTEX_SCALE_SIZE_Y_XY_ONE_HIGHER_EVERY_SECOND,
    zTEX_SCALE_SIZE_XY_ONE_HIGHER,
    zTEX_SCALE_SIZE_XY_MAX,
    zTEX_SCALE_SIZE_COUNT
  };

  enum zTTexScaleBPP {
    zTEX_SCALE_BPP_S3TC,
    zTEX_SCALE_BPP_REFERENCE,
    zTEX_SCALE_BPP_ONE_HIGHER,
    zTEX_SCALE_BPP_MAX
  };

  enum zTTexLockMode {
    zTEX_LOCK_READ  = 1,
    zTEX_LOCK_WRITE = 2
  };

  struct zTTexPalette {
    unsigned char r;
    unsigned char g;
    unsigned char b;

    zTTexPalette() {}

    // user API
    #include "zTTexPalette.inl"
  };

  class zCTextureInfo {
  public:
    zTRnd_TextureFormat texFormat;
    int sizeX;
    int sizeY;
    int numMipMap;
    int refSizeX;
    int refSizeY;
    zCOLOR averageColor;

    zCTextureInfo() { ZeroMemory( this, sizeof( zCTextureInfo ) ); }

    // user API
    #include "zCTextureInfo.inl"
  };

  class zCTextureFileFormat : public zCObject {
  public:
    zCLASS_DECLARATION( zCTextureFileFormat )

    zCTextureFileFormat() {}
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x005C62F0 );
    virtual ~zCTextureFileFormat()                                zCall( 0x005C6330 );
    virtual int LoadTexture( zSTRING const&, zCTextureExchange* ) zPureCall;
    virtual int LoadTexture( zFILE&, zCTextureExchange* )         zPureCall;
    virtual int SaveTexture( zSTRING const&, zCTextureExchange* ) zPureCall;
    virtual int SaveTexture( zFILE&, zCTextureExchange* )         zPureCall;
    virtual zSTRING const& GetFileExtension() const               zPureCall;
    virtual int CanSave() const                                   zPureCall;
    virtual int CanLoad() const                                   zPureCall;

    // user API
    #include "zCTextureFileFormat.inl"
  };

  class zCTextureFileFormatTGA : public zCTextureFileFormat {
  public:
    zCLASS_DECLARATION( zCTextureFileFormatTGA )

#pragma pack( push, 1 )
    struct zTTgaHeader {
    public:
      unsigned char IDLength;
      unsigned char CMapType;
      unsigned char ImgType;
      unsigned char CMapStartLo;
      unsigned char CMapStartHi;
      unsigned char CMapLengthLo;
      unsigned char CMapLengthHi;
      unsigned char CMapDepth;
      unsigned short XOffSet;
      unsigned short YOffSet;
      unsigned char WidthLo;
      unsigned char WidthHi;
      unsigned char HeightLo;
      unsigned char HeightHi;
      unsigned char PixelDepth;
      unsigned char ImageDescriptor;

      // user API
      #include "zCTextureFileFormatTGA_zTTgaHeader.inl"
    };
#pragma pack( pop )

    zTTgaHeader tgaHeader;
    zTRnd_TextureFormat texFormat;
    zCTextureInfo texInfo;
    unsigned char* palette;
    unsigned char* data;
    unsigned char* dataBase;
    int pitchXBytes;
    int tgaRLE;
    int tgaRLEflag;
    int tgaRLEcount;
    int tgaRLEsav[4];

    void zCTextureFileFormatTGA_OnInit()                                zCall( 0x005C61A0 );
    zCTextureFileFormatTGA()                                            zInit( zCTextureFileFormatTGA_OnInit() );
    int ReadTGAHeader( zFILE* )                                         zCall( 0x005C6390 );
    int ReadTGAColorMap( zFILE* )                                       zCall( 0x005C69C0 );
    int ReadTGARLEPixel( zFILE*, unsigned char*, int )                  zCall( 0x005C6F40 );
    int ReadTGASpan( zFILE*, unsigned char*, int, int )                 zCall( 0x005C71B0 );
    int ReadTGAData( zFILE* )                                           zCall( 0x005C72C0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005C5CE0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005C5E20 );
    virtual ~zCTextureFileFormatTGA()                                   zCall( 0x005C62D0 );
    virtual int LoadTexture( zSTRING const&, zCTextureExchange* )       zCall( 0x005C7690 );
    virtual int LoadTexture( zFILE&, zCTextureExchange* )               zCall( 0x005C7520 );
    virtual int SaveTexture( zSTRING const&, zCTextureExchange* )       zCall( 0x005C5E30 );
    virtual int SaveTexture( zFILE&, zCTextureExchange* )               zCall( 0x005C5E40 );
    virtual zSTRING const& GetFileExtension() const                     zCall( 0x005C6340 );
    virtual int CanSave() const                                         zCall( 0x005C5E50 );
    virtual int CanLoad() const                                         zCall( 0x005C5E60 );

    // user API
    #include "zCTextureFileFormatTGA.inl"
  };

  class zCTextureFileFormatInternal : public zCTextureFileFormat {
  public:
    zCLASS_DECLARATION( zCTextureFileFormatInternal )

    zCTextureInfo texInfo;
    int numHigherThanRef;
    int maxPixelDim;
    int showSpyMessages;

    void zCTextureFileFormatInternal_OnInit()                           zCall( 0x005C7890 );
    zCTextureFileFormatInternal()                                       zInit( zCTextureFileFormatInternal_OnInit() );
    int ReadHeader( zFILE& )                                            zCall( 0x005C7A30 );
    int ReadData( zFILE&, zCTextureExchange*, int )                     zCall( 0x005C7A90 );
    int WriteHeader( zFILE&, zCTextureExchange* )                       zCall( 0x005C7EC0 );
    int WriteData( zFILE&, zCTextureExchange* )                         zCall( 0x005C7F30 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005C6050 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005C6170 );
    virtual ~zCTextureFileFormatInternal()                              zCall( 0x005C79D0 );
    virtual int LoadTexture( zSTRING const&, zCTextureExchange* )       zCall( 0x005C7D90 );
    virtual int LoadTexture( zFILE&, zCTextureExchange* )               zCall( 0x005C7D10 );
    virtual int SaveTexture( zSTRING const&, zCTextureExchange* )       zCall( 0x005C8150 );
    virtual int SaveTexture( zFILE&, zCTextureExchange* )               zCall( 0x005C8090 );
    virtual zSTRING const& GetFileExtension() const                     zCall( 0x005C79E0 );
    virtual int CanSave() const                                         zCall( 0x005C6180 );
    virtual int CanLoad() const                                         zCall( 0x005C6190 );

    // user API
    #include "zCTextureFileFormatInternal.inl"
  };

  class zCTextureExchange {
  public:

    zCTextureExchange() {}
    int GetMemSizeBytes()                                                    zCall( 0x005CD220 );
    zVEC4 GetRGBAAtPtr( unsigned char*, zTTexPalette*, zTRnd_TextureFormat ) zCall( 0x005CD760 );
    static int CopyContents( zCTextureExchange*, zCTextureExchange* )        zCall( 0x005CD110 );
    virtual ~zCTextureExchange()                                             zCall( 0x005C8990 );
    virtual int Lock( int )                                                  zPureCall;
    virtual int Unlock()                                                     zPureCall;
    virtual int SetTextureInfo( zCTextureInfo const& )                       zPureCall;
    virtual void* GetPaletteBuffer()                                         zPureCall;
    virtual int GetTextureBuffer( int, void*&, int& )                        zPureCall;
    virtual zCTextureInfo GetTextureInfo()                                   zPureCall;
    virtual int CopyPaletteDataTo( void* )                                   zPureCall;
    virtual int CopyTextureDataTo( int, void*, int )                         zPureCall;
    virtual int HasAlpha()                                                   zPureCall;
    virtual zVEC4 GetRGBAAtTexel( float, float )                             zCall( 0x005CD2D0 );

    // user API
    #include "zCTextureExchange.inl"
  };

  class zCTextureConvert : public zCTextureExchange {
  public:

    zCTextureConvert() {}
    int LoadFromFileFormat( zSTRING const& )                  zCall( 0x005CA000 );
    int SaveToFileFormat( zSTRING const& )                    zCall( 0x005CA0E0 );
    int LoadFromFileFormat( zFILE&, zCTextureFileFormat* )    zCall( 0x005CA1C0 );
    int SaveToFileFormat( zFILE&, zCTextureFileFormat* )      zCall( 0x005CA1F0 );
    int SaveInternal( zFILE& )                                zCall( 0x005CA220 );
    int LoadInternal( zFILE& )                                zCall( 0x005CA2D0 );
    void ConvertToNewFormat( zTRnd_TextureFormat const& )     zCall( 0x005CA380 );
    void ConvertToNewSize( int, int )                         zCall( 0x005CA3B0 );
    void GenerateMipMaps()                                    zCall( 0x005CA4A0 );
    static int CalcNumMipMaps( unsigned long, unsigned long ) zCall( 0x005CA4F0 );
    static void CorrectAspectRatio( int&, int& )              zCall( 0x005CA520 );
    static void CorrectPow2( int&, int& )                     zCall( 0x005CA5A0 );

    // user API
    #include "zCTextureConvert.inl"
  };

  class zCTexture : public zCResource, public zCTextureExchange {
  public:
    zCLASS_DECLARATION( zCTexture )

    enum zTTexFileDesiredBPP {
      zTEX_FILE_DESIRED_BPP_S3TC,
      zTEX_FILE_DESIRED_BPP_8,
      zTEX_FILE_DESIRED_BPP_16,
      zTEX_FILE_DESIRED_BPP_32,
      zTEX_FILE_DESIRED_BPP_COUNT
    };

    zCTexture* nextAni[zTEX_MAX_ANIS];
    zCTexture* prevAni[zTEX_MAX_ANIS];
    int actAniFrame[zTEX_MAX_ANIS];
    int numAniFrames[zTEX_MAX_ANIS];
    group {
      unsigned char hasAlpha         : 1;
      unsigned char isAnimated       : 1;
      unsigned char changingRealtime : 1;
      unsigned char isTextureTile    : 1;
    };

    void zCTexture_OnInit()                                                                        zCall( 0x005C87E0 );
    zCTexture()                                                                                    zInit( zCTexture_OnInit() );
    void InitValues()                                                                              zCall( 0x005C88C0 );
    int IsLightmap() const                                                                         zCall( 0x005C89C0 );
    zCTexture* GetAniTexture()                                                                     zCall( 0x005C8A10 );
    void AddAniTex( int, zCTexture* )                                                              zCall( 0x005C8A70 );
    void PrecacheTexAniFrames( float )                                                             zCall( 0x005C8AB0 );
    void ForceConvertAndReloadTexture()                                                            zCall( 0x005CB1A0 );
    int LoadAndConvertInternal( zFILE& )                                                           zCall( 0x005CB4F0 );
    int SaveAndConvertInternal( zFILE& )                                                           zCall( 0x005CB890 );
    int CacheInNamed( zSTRING const* )                                                             zCall( 0x005CBA70 );
    int IsTextureTileBaseSlice() const                                                             zCall( 0x005CC470 );
    int CreateTextureTile( zCTextureExchange* )                                                    zCall( 0x005CC4A0 );
    void GetPixelSize( int&, int& )                                                                zCall( 0x005CCBD0 );
    static zCTexture* SearchName( zSTRING& )                                                       zCall( 0x005C89A0 );
    static zCTexture* Load( zSTRING&, int )                                                        zCall( 0x005C8AF0 );
    static zCTexture* LoadSingle( zSTRING&, int )                                                  zCall( 0x005C9730 );
    static void AutoDetectRendererTexScale()                                                       zCall( 0x005C98E0 );
    static void RefreshTexMaxSize( int )                                                           zCall( 0x005C9F70 );
    static int ConvertTexture( zSTRING const& )                                                    zCall( 0x005CAA20 );
    static zTRnd_TextureFormat CalcNextBestTexFormat( zTRnd_TextureFormat )                        zCall( 0x005CB270 );
    static void CalcDesiredBPP( zSTRING const*, zTTexFileDesiredBPP&, zTRnd_TextureFormat&, int& ) zCall( 0x005CB370 );
    static void ScanConvertTextures()                                                              zCall( 0x005CCF00 );
    /* for zCResource num : 11*/
    virtual zCClassDef* _GetClassDef() const                                                       zCall( 0x005C8850 );
    virtual ~zCTexture()                                                                           zCall( 0x005C88F0 );
    virtual int LoadResourceData()                                                                 zCall( 0x005CA5E0 );
    virtual int ReleaseResourceData()                                                              zCall( 0x005CA640 );
    virtual unsigned long GetResSizeBytes()                                                        zCall( 0x005CA6A0 );
    virtual void GetCacheConfig( unsigned long&, unsigned long& )                                  zCall( 0x005CA830 );
    virtual int GetChromaKeyingEnabled() const                                                     zCall( 0x005C8870 );
    virtual void SetChromaKeyingEnabled( int )                                                     zCall( 0x005C8880 );
    virtual void ReleaseData()                                                                     zPureCall;
    /* for zCTextureExchange num : 10*/
    virtual int Lock( int )                                                                        zPureCall;
    virtual int Unlock()                                                                           zPureCall;
    virtual int SetTextureInfo( zCTextureInfo const& )                                             zPureCall;
    virtual void* GetPaletteBuffer()                                                               zPureCall;
    virtual int GetTextureBuffer( int, void*&, int& )                                              zPureCall;
    virtual zCTextureInfo GetTextureInfo()                                                         zPureCall;
    virtual int CopyPaletteDataTo( void* )                                                         zPureCall;
    virtual int CopyTextureDataTo( int, void*, int )                                               zPureCall;
    virtual int HasAlpha()                                                                         zCall( 0x005C8860 );


    // static properties
    static zSTRING& zTEX_DEFAULT_TEXTURE_FILE;
    static zTTexScaleSize& s_texScaleSize;
    static zTTexScaleBPP& s_texScaleBPP;
    static unsigned long& s_texSupportedFormats;
    static char& s_useDefaultTex;
    static char& s_globalLoadTextures;
    static unsigned long& s_texMaxPixelSize;
    static zSTRING*& s_texDesiredBPPSuffix;
    static zTRnd_TextureFormat*& s_texDesiredBPPDefault;
    static float& s_texRefRAM;
    static zTTexFileDesiredBPP& s_texRefBPP;

    // user API
    #include "zCTexture.inl"
  };

  class zCLightMap : public zCObject {
  public:
    zCLASS_DECLARATION( zCLightMap )

    zVEC3 lightmapOrigin;
    zVEC3 lightmapUVUp;
    zVEC3 lightmapUVRight;
    zCTexture* tex;

    void zCLightMap_OnInit()                                                   zCall( 0x005CDD70 );
    zCLightMap()                                                               zInit( zCLightMap_OnInit() );
    void SetTexture( zCTexture* )                                              zCall( 0x005CDEA0 );
    void CalcLightmapOriginUpRight( zVEC3 const&, zVEC3 const&, zVEC3 const& ) zCall( 0x005CDEE0 );
    static zCObject* _CreateNewInstance()                                      zCall( 0x005CDC90 );
    virtual zCClassDef* _GetClassDef() const                                   zCall( 0x005CDD60 );
    virtual ~zCLightMap()                                                      zCall( 0x005CDE30 );

    // user API
    #include "zCLightMap.inl"
  };

  class zCTextureFileHandler : public zCScanDirFileHandler {
  public:

    zCTextureFileHandler() {}
    virtual ~zCTextureFileHandler()                                    zCall( 0x00424060 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zCall( 0x005CCC00 );

    // user API
    #include "zCTextureFileHandler.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZTEXTURE_H__VER0__