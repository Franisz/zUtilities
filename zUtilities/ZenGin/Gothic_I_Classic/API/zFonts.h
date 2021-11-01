// Supported with union (c) 2018-2021 Union team

#ifndef __ZFONTS_H__VER0__
#define __ZFONTS_H__VER0__

namespace Gothic_I_Classic {
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
    void zCFont_OnInit( zSTRING const& )                   zCall( 0x006DF500 );
    int CacheIn()                                          zCall( 0x006DF240 );
    int LoadFontTexture( zSTRING const& )                  zCall( 0x006DF280 );
    zCFont( zSTRING const& a0 )                            zInit( zCFont_OnInit( a0 ));
    ~zCFont()                                              zCall( 0x006DF6A0 );
    int LoadSource( zSTRING const& )                       zCall( 0x006DF730 );
    int SaveFontData()                                     zCall( 0x006DF880 );
    int LoadFontData()                                     zCall( 0x006DFC50 );
    zSTRING GetFontName()                                  zCall( 0x006E01C0 );
    int GetFontY()                                         zCall( 0x006E0200 );
    int GetFontX( zSTRING const& )                         zCall( 0x006E0210 );
    int GetWidth( char )                                   zCall( 0x006E0240 );
    int GetLetterDistance()                                zCall( 0x006E0250 );
    char MapToAscii( char )                                zCall( 0x006E0260 );
    int GetSizex()                                         zCall( 0x006E0300 );
    int GetSizey()                                         zCall( 0x006E0330 );
    int GetPixel( int, int )                               zCall( 0x006E0360 );
    int GetPixelAlpha( int, int )                          zCall( 0x006E03C0 );
    int NextPixelX( int, int, int& )                       zCall( 0x006E0420 );
    int NextPixelY( int, int, int& )                       zCall( 0x006E04C0 );
    int NextPixelXAlpha( int, int, int& )                  zCall( 0x006E0560 );
    int NextPixelYAlpha( int, int, int& )                  zCall( 0x006E0600 );
    int NextPixelXCol( int, int, int )                     zCall( 0x006E06A0 );
    int NextPixelYCol( int, int, int )                     zCall( 0x006E0760 );
    int AnalyseLetters()                                   zCall( 0x006E0820 );
    int GetFontData( unsigned char, int&, zVEC2&, zVEC2& ) zCall( 0x006E1070 );
    zCTexture* GetFontTexture()                            zCall( 0x006E10D0 );

    // static properties
    static zCTextureConvert*& texConv;

    // user API
    #include "zCFont.inl"
  };

  // sizeof 0Ch
  class zCFontMan {
  public:
    zCArray<zCFont*> fontlist; // sizeof 0Ch    offset 00h

    void zCFontMan_OnInit()          zCall( 0x006DEDA0 );
    zCFontMan()                      zInit( zCFontMan_OnInit() );
    ~zCFontMan()                     zCall( 0x006DEDB0 );
    int SearchFont( zSTRING const& ) zCall( 0x006DEE80 );
    int Load( zSTRING const& )       zCall( 0x006DF040 );
    int GetNumber()                  zCall( 0x006DF210 );
    zCFont* GetFont( int )           zCall( 0x006DF220 );

    // user API
    #include "zCFontMan.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZFONTS_H__VER0__