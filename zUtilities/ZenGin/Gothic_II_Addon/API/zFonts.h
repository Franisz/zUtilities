// Supported with union (c) 2018 Union team

#ifndef __ZFONTS_H__VER3__
#define __ZFONTS_H__VER3__

namespace Gothic_II_Addon {
  const int zFONT_MAX_LETTER = 256;

  class zCFont {
  public:
    zSTRING name;
    int height;
    zCTexture* fontTex;
    unsigned char width[zFONT_MAX_LETTER];
    zVEC2 fontuv1[zFONT_MAX_LETTER];
    zVEC2 fontuv2[zFONT_MAX_LETTER];

    zCFont() {}
    void zCFont_OnInit( zSTRING const& )                   zCall( 0x00788780 );
    int CacheIn()                                          zCall( 0x007884D0 );
    int LoadFontTexture( zSTRING const& )                  zCall( 0x00788510 );
    zCFont( zSTRING const& a0 )                            zInit( zCFont_OnInit( a0 ));
    ~zCFont()                                              zCall( 0x00788920 );
    int LoadSource( zSTRING const& )                       zCall( 0x007889B0 );
    int SaveFontData()                                     zCall( 0x00788B00 );
    int LoadFontData()                                     zCall( 0x00788F20 );
    zSTRING GetFontName()                                  zCall( 0x007894A0 );
    int GetFontY()                                         zCall( 0x007894E0 );
    int GetFontX( zSTRING const& )                         zCall( 0x007894F0 );
    int GetWidth( char )                                   zCall( 0x00789520 );
    int GetLetterDistance()                                zCall( 0x00789530 );
    char MapToAscii( char )                                zCall( 0x00789540 );
    int GetSizex()                                         zCall( 0x007895E0 );
    int GetSizey()                                         zCall( 0x00789610 );
    int GetPixel( int, int )                               zCall( 0x00789640 );
    int GetPixelAlpha( int, int )                          zCall( 0x00789780 );
    int NextPixelX( int, int, int& )                       zCall( 0x007898C0 );
    int NextPixelY( int, int, int& )                       zCall( 0x00789920 );
    int NextPixelXAlpha( int, int, int& )                  zCall( 0x00789980 );
    int NextPixelYAlpha( int, int, int& )                  zCall( 0x007899E0 );
    int NextPixelXCol( int, int, int )                     zCall( 0x00789A40 );
    int NextPixelYCol( int, int, int )                     zCall( 0x00789AC0 );
    int AnalyseLetters()                                   zCall( 0x00789B40 );
    int GetFontData( unsigned char, int&, zVEC2&, zVEC2& ) zCall( 0x0078A390 );
    zCTexture* GetFontTexture()                            zCall( 0x0078A3F0 );

    // static properties
    static zCTextureConvert*& texConv;

    // user API
    #include "zCFont.inl"
  };

  class zCFontMan {
  public:
    zCArray<zCFont*> fontlist;

    void zCFontMan_OnInit()          zCall( 0x00788030 );
    zCFontMan()                      zInit( zCFontMan_OnInit() );
    ~zCFontMan()                     zCall( 0x00788040 );
    int SearchFont( zSTRING const& ) zCall( 0x00788110 );
    int Load( zSTRING const& )       zCall( 0x007882D0 );
    int GetNumber()                  zCall( 0x007884A0 );
    zCFont* GetFont( int )           zCall( 0x007884B0 );

    // user API
    #include "zCFontMan.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZFONTS_H__VER3__