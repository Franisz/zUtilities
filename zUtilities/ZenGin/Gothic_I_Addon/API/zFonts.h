// Supported with union (c) 2018-2021 Union team

#ifndef __ZFONTS_H__VER1__
#define __ZFONTS_H__VER1__

namespace Gothic_I_Addon {
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
    void zCFont_OnInit( zSTRING const& )                   zCall( 0x007179D0 );
    int CacheIn()                                          zCall( 0x007176C0 );
    int LoadFontTexture( zSTRING const& )                  zCall( 0x00717700 );
    zCFont( zSTRING const& a0 )                            zInit( zCFont_OnInit( a0 ));
    ~zCFont()                                              zCall( 0x00717B60 );
    int LoadSource( zSTRING const& )                       zCall( 0x00717C00 );
    int SaveFontData()                                     zCall( 0x00717D50 );
    int LoadFontData()                                     zCall( 0x007181A0 );
    zSTRING GetFontName()                                  zCall( 0x007187C0 );
    int GetFontY()                                         zCall( 0x00718810 );
    int GetFontX( zSTRING const& )                         zCall( 0x00718820 );
    int GetWidth( char )                                   zCall( 0x00718860 );
    int GetLetterDistance()                                zCall( 0x00718880 );
    char MapToAscii( char )                                zCall( 0x00718890 );
    int GetSizex()                                         zCall( 0x00718930 );
    int GetSizey()                                         zCall( 0x00718960 );
    int GetPixel( int, int )                               zCall( 0x00718990 );
    int GetPixelAlpha( int, int )                          zCall( 0x007189F0 );
    int NextPixelX( int, int, int& )                       zCall( 0x00718A50 );
    int NextPixelY( int, int, int& )                       zCall( 0x00718AF0 );
    int NextPixelXAlpha( int, int, int& )                  zCall( 0x00718B90 );
    int NextPixelYAlpha( int, int, int& )                  zCall( 0x00718C30 );
    int NextPixelXCol( int, int, int )                     zCall( 0x00718CD0 );
    int NextPixelYCol( int, int, int )                     zCall( 0x00718D90 );
    int AnalyseLetters()                                   zCall( 0x00718E50 );
    int GetFontData( unsigned char, int&, zVEC2&, zVEC2& ) zCall( 0x007196D0 );
    zCTexture* GetFontTexture()                            zCall( 0x00719730 );

    // static properties
    static zCTextureConvert*& texConv;

    // user API
    #include "zCFont.inl"
  };

  // sizeof 0Ch
  class zCFontMan {
  public:
    zCArray<zCFont*> fontlist; // sizeof 0Ch    offset 00h

    void zCFontMan_OnInit()          zCall( 0x007171B0 );
    zCFontMan()                      zInit( zCFontMan_OnInit() );
    ~zCFontMan()                     zCall( 0x007171C0 );
    int SearchFont( zSTRING const& ) zCall( 0x007172A0 );
    int Load( zSTRING const& )       zCall( 0x007174A0 );
    int GetNumber()                  zCall( 0x00717690 );
    zCFont* GetFont( int )           zCall( 0x007176A0 );

    // user API
    #include "zCFontMan.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZFONTS_H__VER1__