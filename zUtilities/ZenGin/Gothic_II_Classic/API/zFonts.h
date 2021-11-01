// Supported with union (c) 2018-2021 Union team

#ifndef __ZFONTS_H__VER2__
#define __ZFONTS_H__VER2__

namespace Gothic_II_Classic {
  const int zFONT_MAX_LETTER = 256;

  // sizeof 111Ch
  class zCFont {
  public:
    zSTRING name;                          // sizeof 14h    offset 00h
    int height;                            // sizeof 04h    offset 14h
    zCTexture* fontTex;                    // sizeof 04h    offset 18h
    unsigned char width[zFONT_MAX_LETTER]; // sizeof 100h   offset 1Ch
    zVEC2 fontuv1[zFONT_MAX_LETTER];       // sizeof 800h   offset 11Ch
    zVEC2 fontuv2[zFONT_MAX_LETTER];       // sizeof 800h   offset 91Ch

    zCFont() {}
    void zCFont_OnInit( zSTRING const& )                   zCall( 0x00728D40 );
    int CacheIn()                                          zCall( 0x00728A90 );
    int LoadFontTexture( zSTRING const& )                  zCall( 0x00728AD0 );
    zCFont( zSTRING const& a0 )                            zInit( zCFont_OnInit( a0 ));
    ~zCFont()                                              zCall( 0x00728EE0 );
    int LoadSource( zSTRING const& )                       zCall( 0x00728F70 );
    int SaveFontData()                                     zCall( 0x007290C0 );
    int LoadFontData()                                     zCall( 0x007294E0 );
    zSTRING GetFontName()                                  zCall( 0x00729A60 );
    int GetFontY()                                         zCall( 0x00729AA0 );
    int GetFontX( zSTRING const& )                         zCall( 0x00729AB0 );
    int GetWidth( char )                                   zCall( 0x00729AE0 );
    int GetLetterDistance()                                zCall( 0x00729AF0 );
    char MapToAscii( char )                                zCall( 0x00729B00 );
    int GetSizex()                                         zCall( 0x00729BA0 );
    int GetSizey()                                         zCall( 0x00729BD0 );
    int GetPixel( int, int )                               zCall( 0x00729C00 );
    int GetPixelAlpha( int, int )                          zCall( 0x00729D40 );
    int NextPixelX( int, int, int& )                       zCall( 0x00729E80 );
    int NextPixelY( int, int, int& )                       zCall( 0x00729EE0 );
    int NextPixelXAlpha( int, int, int& )                  zCall( 0x00729F40 );
    int NextPixelYAlpha( int, int, int& )                  zCall( 0x00729FA0 );
    int NextPixelXCol( int, int, int )                     zCall( 0x0072A000 );
    int NextPixelYCol( int, int, int )                     zCall( 0x0072A080 );
    int AnalyseLetters()                                   zCall( 0x0072A100 );
    int GetFontData( unsigned char, int&, zVEC2&, zVEC2& ) zCall( 0x0072A950 );
    zCTexture* GetFontTexture()                            zCall( 0x0072A9B0 );

    // static properties
    static zCTextureConvert*& texConv;

    // user API
    #include "zCFont.inl"
  };

  // sizeof 0Ch
  class zCFontMan {
  public:
    zCArray<zCFont*> fontlist; // sizeof 0Ch    offset 00h

    void zCFontMan_OnInit()          zCall( 0x007285F0 );
    zCFontMan()                      zInit( zCFontMan_OnInit() );
    ~zCFontMan()                     zCall( 0x00728600 );
    int SearchFont( zSTRING const& ) zCall( 0x007286D0 );
    int Load( zSTRING const& )       zCall( 0x00728890 );
    int GetNumber()                  zCall( 0x00728A60 );
    zCFont* GetFont( int )           zCall( 0x00728A70 );

    // user API
    #include "zCFontMan.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZFONTS_H__VER2__