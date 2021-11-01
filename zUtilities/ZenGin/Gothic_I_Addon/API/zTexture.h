// Supported with union (c) 2018-2021 Union team

#ifndef __ZTEXTURE_H__VER1__
#define __ZTEXTURE_H__VER1__

namespace Gothic_I_Addon {
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

  // sizeof 03h
  struct zTTexPalette {
    unsigned char r; // sizeof 01h    offset 00h
    unsigned char g; // sizeof 01h    offset 01h
    unsigned char b; // sizeof 01h    offset 02h

    zTTexPalette() {}

    // user API
    #include "zTTexPalette.inl"
  };

  // sizeof 1Ch
  class zCTextureInfo {
  public:
    zTRnd_TextureFormat texFormat; // sizeof 04h    offset 00h
    int sizeX;                     // sizeof 04h    offset 04h
    int sizeY;                     // sizeof 04h    offset 08h
    int numMipMap;                 // sizeof 04h    offset 0Ch
    int refSizeX;                  // sizeof 04h    offset 10h
    int refSizeY;                  // sizeof 04h    offset 14h
    zCOLOR averageColor;           // sizeof 04h    offset 18h

    zCTextureInfo() { ZeroMemory( this, sizeof( zCTextureInfo ) ); }

    // user API
    #include "zCTextureInfo.inl"
  };

  // sizeof 24h
  class zCTextureFileFormat : public zCObject {
  public:
    zCLASS_DECLARATION( zCTextureFileFormat )

    zCTextureFileFormat() {}
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x005E4720 );
    virtual ~zCTextureFileFormat()                                zCall( 0x005E4760 );
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

  // sizeof 84h
  class zCTextureFileFormatTGA : public zCTextureFileFormat {
  public:
    zCLASS_DECLARATION( zCTextureFileFormatTGA )

#pragma pack( push, 1 )
    // sizeof 12h
    struct zTTgaHeader {
    public:
      unsigned char IDLength;        // sizeof 01h    offset 00h
      unsigned char CMapType;        // sizeof 01h    offset 01h
      unsigned char ImgType;         // sizeof 01h    offset 02h
      unsigned char CMapStartLo;     // sizeof 01h    offset 03h
      unsigned char CMapStartHi;     // sizeof 01h    offset 04h
      unsigned char CMapLengthLo;    // sizeof 01h    offset 05h
      unsigned char CMapLengthHi;    // sizeof 01h    offset 06h
      unsigned char CMapDepth;       // sizeof 01h    offset 07h
      unsigned short XOffSet;        // sizeof 02h    offset 08h
      unsigned short YOffSet;        // sizeof 02h    offset 0Ah
      unsigned char WidthLo;         // sizeof 01h    offset 0Ch
      unsigned char WidthHi;         // sizeof 01h    offset 0Dh
      unsigned char HeightLo;        // sizeof 01h    offset 0Eh
      unsigned char HeightHi;        // sizeof 01h    offset 0Fh
      unsigned char PixelDepth;      // sizeof 01h    offset 10h
      unsigned char ImageDescriptor; // sizeof 01h    offset 11h

      // user API
      #include "zCTextureFileFormatTGA_zTTgaHeader.inl"
    };
#pragma pack( pop )

    zTTgaHeader tgaHeader;         // sizeof 12h    offset 24h
    zTRnd_TextureFormat texFormat; // sizeof 04h    offset 38h
    zCTextureInfo texInfo;         // sizeof 1Ch    offset 3Ch
    unsigned char* palette;        // sizeof 04h    offset 58h
    unsigned char* data;           // sizeof 04h    offset 5Ch
    unsigned char* dataBase;       // sizeof 04h    offset 60h
    int pitchXBytes;               // sizeof 04h    offset 64h
    int tgaRLE;                    // sizeof 04h    offset 68h
    int tgaRLEflag;                // sizeof 04h    offset 6Ch
    int tgaRLEcount;               // sizeof 04h    offset 70h
    int tgaRLEsav[4];              // sizeof 10h    offset 74h

    void zCTextureFileFormatTGA_OnInit()                                zCall( 0x005E45C0 );
    zCTextureFileFormatTGA()                                            zInit( zCTextureFileFormatTGA_OnInit() );
    int ReadTGAHeader( zFILE* )                                         zCall( 0x005E47C0 );
    int ReadTGAColorMap( zFILE* )                                       zCall( 0x005E4F00 );
    int ReadTGARLEPixel( zFILE*, unsigned char*, int )                  zCall( 0x005E55C0 );
    int ReadTGASpan( zFILE*, unsigned char*, int, int )                 zCall( 0x005E58C0 );
    int ReadTGAData( zFILE* )                                           zCall( 0x005E5A00 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005E40E0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E4220 );
    virtual ~zCTextureFileFormatTGA()                                   zCall( 0x005E4700 );
    virtual int LoadTexture( zSTRING const&, zCTextureExchange* )       zCall( 0x005E5E10 );
    virtual int LoadTexture( zFILE&, zCTextureExchange* )               zCall( 0x005E5C90 );
    virtual int SaveTexture( zSTRING const&, zCTextureExchange* )       zCall( 0x005E4230 );
    virtual int SaveTexture( zFILE&, zCTextureExchange* )               zCall( 0x005E4240 );
    virtual zSTRING const& GetFileExtension() const                     zCall( 0x005E4770 );
    virtual int CanSave() const                                         zCall( 0x005E4250 );
    virtual int CanLoad() const                                         zCall( 0x005E4260 );

    // user API
    #include "zCTextureFileFormatTGA.inl"
  };

  // sizeof 4Ch
  class zCTextureFileFormatInternal : public zCTextureFileFormat {
  public:
    zCLASS_DECLARATION( zCTextureFileFormatInternal )

    zCTextureInfo texInfo; // sizeof 1Ch    offset 24h
    int numHigherThanRef;  // sizeof 04h    offset 40h
    int maxPixelDim;       // sizeof 04h    offset 44h
    int showSpyMessages;   // sizeof 04h    offset 48h

    void zCTextureFileFormatInternal_OnInit()                           zCall( 0x005E6070 );
    zCTextureFileFormatInternal()                                       zInit( zCTextureFileFormatInternal_OnInit() );
    int ReadHeader( zFILE& )                                            zCall( 0x005E6210 );
    int ReadData( zFILE&, zCTextureExchange*, int )                     zCall( 0x005E6270 );
    int WriteHeader( zFILE&, zCTextureExchange* )                       zCall( 0x005E66C0 );
    int WriteData( zFILE&, zCTextureExchange* )                         zCall( 0x005E6730 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005E4470 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005E4590 );
    virtual ~zCTextureFileFormatInternal()                              zCall( 0x005E61B0 );
    virtual int LoadTexture( zSTRING const&, zCTextureExchange* )       zCall( 0x005E6560 );
    virtual int LoadTexture( zFILE&, zCTextureExchange* )               zCall( 0x005E64E0 );
    virtual int SaveTexture( zSTRING const&, zCTextureExchange* )       zCall( 0x005E6940 );
    virtual int SaveTexture( zFILE&, zCTextureExchange* )               zCall( 0x005E6880 );
    virtual zSTRING const& GetFileExtension() const                     zCall( 0x005E61C0 );
    virtual int CanSave() const                                         zCall( 0x005E45A0 );
    virtual int CanLoad() const                                         zCall( 0x005E45B0 );

    // user API
    #include "zCTextureFileFormatInternal.inl"
  };

  // sizeof 04h
  class zCTextureExchange {
  public:

    zCTextureExchange() {}
    int GetMemSizeBytes()                                                    zCall( 0x005EBE10 );
    zVEC4 GetRGBAAtPtr( unsigned char*, zTTexPalette*, zTRnd_TextureFormat ) zCall( 0x005EC350 );
    static int CopyContents( zCTextureExchange*, zCTextureExchange* )        zCall( 0x005EBD00 );
    virtual ~zCTextureExchange()                                             zCall( 0x005E7270 );
    virtual int Lock( int )                                                  zPureCall;
    virtual int Unlock()                                                     zPureCall;
    virtual int SetTextureInfo( zCTextureInfo const& )                       zPureCall;
    virtual void* GetPaletteBuffer()                                         zPureCall;
    virtual int GetTextureBuffer( int, void*&, int& )                        zPureCall;
    virtual zCTextureInfo GetTextureInfo()                                   zPureCall;
    virtual int CopyPaletteDataTo( void* )                                   zPureCall;
    virtual int CopyTextureDataTo( int, void*, int )                         zPureCall;
    virtual int HasAlpha()                                                   zPureCall;
    virtual zVEC4 GetRGBAAtTexel( float, float )                             zCall( 0x005EBEC0 );

    // user API
    #include "zCTextureExchange.inl"
  };

  // sizeof 04h
  class zCTextureConvert : public zCTextureExchange {
  public:

    zCTextureConvert() {}
    int LoadFromFileFormat( zSTRING const& )                  zCall( 0x005E8A30 );
    int SaveToFileFormat( zSTRING const& )                    zCall( 0x005E8B10 );
    int LoadFromFileFormat( zFILE&, zCTextureFileFormat* )    zCall( 0x005E8BF0 );
    int SaveToFileFormat( zFILE&, zCTextureFileFormat* )      zCall( 0x005E8C20 );
    int SaveInternal( zFILE& )                                zCall( 0x005E8C50 );
    int LoadInternal( zFILE& )                                zCall( 0x005E8D00 );
    void ConvertToNewFormat( zTRnd_TextureFormat const& )     zCall( 0x005E8DB0 );
    void ConvertToNewSize( int, int )                         zCall( 0x005E8DF0 );
    void GenerateMipMaps()                                    zCall( 0x005E8EE0 );
    static int CalcNumMipMaps( unsigned long, unsigned long ) zCall( 0x005E8F40 );
    static void CorrectAspectRatio( int&, int& )              zCall( 0x005E8F70 );
    static void CorrectPow2( int&, int& )                     zCall( 0x005E8FF0 );

    // user API
    #include "zCTextureConvert.inl"
  };

  // sizeof 8Ch
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

    zCTexture* nextAni[zTEX_MAX_ANIS];    // sizeof 0Ch    offset 58h
    zCTexture* prevAni[zTEX_MAX_ANIS];    // sizeof 0Ch    offset 64h
    int actAniFrame[zTEX_MAX_ANIS];       // sizeof 0Ch    offset 70h
    int numAniFrames[zTEX_MAX_ANIS];      // sizeof 0Ch    offset 7Ch
    group {
      unsigned char hasAlpha         : 1; // sizeof 01h    offset bit
      unsigned char isAnimated       : 1; // sizeof 01h    offset bit
      unsigned char changingRealtime : 1; // sizeof 01h    offset bit
      unsigned char isTextureTile    : 1; // sizeof 01h    offset bit
    };

    void zCTexture_OnInit()                                                                        zCall( 0x005E70B0 );
    zCTexture()                                                                                    zInit( zCTexture_OnInit() );
    void InitValues()                                                                              zCall( 0x005E7190 );
    int IsLightmap() const                                                                         zCall( 0x005E72A0 );
    zCTexture* GetAniTexture()                                                                     zCall( 0x005E72F0 );
    void AddAniTex( int, zCTexture* )                                                              zCall( 0x005E7340 );
    void PrecacheTexAniFrames( float )                                                             zCall( 0x005E7370 );
    void ForceConvertAndReloadTexture()                                                            zCall( 0x005E9B60 );
    int LoadAndConvertInternal( zFILE& )                                                           zCall( 0x005E9EE0 );
    int SaveAndConvertInternal( zFILE& )                                                           zCall( 0x005EA2E0 );
    int CacheInNamed( zSTRING const* )                                                             zCall( 0x005EA4D0 );
    int IsTextureTileBaseSlice() const                                                             zCall( 0x005EB040 );
    int CreateTextureTile( zCTextureExchange* )                                                    zCall( 0x005EB070 );
    void GetPixelSize( int&, int& )                                                                zCall( 0x005EB740 );
    static zCTexture* SearchName( zSTRING& )                                                       zCall( 0x005E7280 );
    static zCTexture* Load( zSTRING&, int )                                                        zCall( 0x005E73B0 );
    static zCTexture* LoadSingle( zSTRING&, int )                                                  zCall( 0x005E8060 );
    static void AutoDetectRendererTexScale()                                                       zCall( 0x005E8230 );
    static void RefreshTexMaxSize( int )                                                           zCall( 0x005E89A0 );
    static int ConvertTexture( zSTRING const& )                                                    zCall( 0x005E9340 );
    static zTRnd_TextureFormat CalcNextBestTexFormat( zTRnd_TextureFormat )                        zCall( 0x005E9C30 );
    static void CalcDesiredBPP( zSTRING const*, zTTexFileDesiredBPP&, zTRnd_TextureFormat&, int& ) zCall( 0x005E9D60 );
    static void ScanConvertTextures()                                                              zCall( 0x005EBAD0 );
    /* for zCResource num : 11*/
    virtual zCClassDef* _GetClassDef() const                                                       zCall( 0x005E7120 );
    virtual ~zCTexture()                                                                           zCall( 0x005E71C0 );
    virtual int LoadResourceData()                                                                 zCall( 0x005E9020 );
    virtual int ReleaseResourceData()                                                              zCall( 0x005E9080 );
    virtual unsigned long GetResSizeBytes()                                                        zCall( 0x005E90F0 );
    virtual void GetCacheConfig( unsigned long&, unsigned long& )                                  zCall( 0x005E9120 );
    virtual int GetChromaKeyingEnabled() const                                                     zCall( 0x005E7140 );
    virtual void SetChromaKeyingEnabled( int )                                                     zCall( 0x005E7150 );
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
    virtual int HasAlpha()                                                                         zCall( 0x005E7130 );


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

  // sizeof 4Ch
  class zCLightMap : public zCObject {
  public:
    zCLASS_DECLARATION( zCLightMap )

    zVEC3 lightmapOrigin;  // sizeof 0Ch    offset 24h
    zVEC3 lightmapUVUp;    // sizeof 0Ch    offset 30h
    zVEC3 lightmapUVRight; // sizeof 0Ch    offset 3Ch
    zCTexture* tex;        // sizeof 04h    offset 48h

    void zCLightMap_OnInit()                                                   zCall( 0x005ECA60 );
    zCLightMap()                                                               zInit( zCLightMap_OnInit() );
    void SetTexture( zCTexture* )                                              zCall( 0x005ECB90 );
    void CalcLightmapOriginUpRight( zVEC3 const&, zVEC3 const&, zVEC3 const& ) zCall( 0x005ECBE0 );
    static zCObject* _CreateNewInstance()                                      zCall( 0x005EC970 );
    virtual zCClassDef* _GetClassDef() const                                   zCall( 0x005ECA50 );
    virtual ~zCLightMap()                                                      zCall( 0x005ECB20 );

    // user API
    #include "zCLightMap.inl"
  };

  // sizeof 30h
  class zCTextureFileHandler : public zCScanDirFileHandler {
  public:

    zCTextureFileHandler() {}
    virtual ~zCTextureFileHandler()                                    zCall( 0x00426AC0 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zCall( 0x005EB780 );

    // user API
    #include "zCTextureFileHandler.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZTEXTURE_H__VER1__