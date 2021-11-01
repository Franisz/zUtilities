// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_PRINT__FONT_H__VER0__
#define __ZVIEW_PRINT__FONT_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 14h
  class zCViewFont {
  public:
    zTRnd_AlphaBlendFunc FuncAlphaBlend; // sizeof 04h    offset 00h
    zCFont* Font;                        // sizeof 04h    offset 04h
    zCOLOR Color;                        // sizeof 04h    offset 08h
    int Alpha;                           // sizeof 04h    offset 0Ch
    int EnabledBlend;                    // sizeof 04h    offset 10h

    void zCViewFont_OnInit( zCFont*, zCOLOR&, int, zTRnd_AlphaBlendFunc ) zCall( 0x00757F90 );
    void zCViewFont_OnInit( zCFont*, zCOLOR& )                            zCall( 0x00757FC0 );
    void zCViewFont_OnInit( zCFont* )                                     zCall( 0x00757FF0 );
    void zCViewFont_OnInit()                                              zCall( 0x00758030 );
    zCViewFont( zCFont* a0, zCOLOR& a1, int a2, zTRnd_AlphaBlendFunc a3 ) zInit( zCViewFont_OnInit( a0, a1, a2, a3 ));
    zCViewFont( zCFont* a0, zCOLOR& a1 )                                  zInit( zCViewFont_OnInit( a0, a1 ));
    zCViewFont( zCFont* a0 )                                              zInit( zCViewFont_OnInit( a0 ));
    zCViewFont()                                                          zInit( zCViewFont_OnInit() );
    ~zCViewFont()                                                         zCall( 0x00758070 );
    void __fastcall SetFont( zSTRING& )                                   zCall( 0x00758080 );

    // user API
    #include "zCViewFont.inl"
  };

  // sizeof 3Ch
  class zCViewText2 {
  public:
    int EnabledColor;    // sizeof 04h    offset 00h
    int EnabledTimer;    // sizeof 04h    offset 04h
    zPOS PixelPosition;  // sizeof 08h    offset 08h
    float Timer;         // sizeof 04h    offset 10h
    zSTRING Text;        // sizeof 14h    offset 14h
    zCViewFont ViewFont; // sizeof 14h    offset 28h

    zCViewText2() {}
    void zCViewText2_OnInit( zSTRING&, zCPosition&, zCOLOR&, float, zCFont*, int, zTRnd_AlphaBlendFunc )          zCall( 0x00757720 );
    void zCViewText2_OnInit( zSTRING&, zCPosition&, zCOLOR&, zCFont*, int, zTRnd_AlphaBlendFunc )                 zCall( 0x00757800 );
    void zCViewText2_OnInit( zSTRING&, zCPosition&, zCOLOR&, float, zCFont* )                                     zCall( 0x007578E0 );
    void zCViewText2_OnInit( zSTRING&, zCPosition&, zCOLOR&, zCFont* )                                            zCall( 0x007579D0 );
    void zCViewText2_OnInit( zSTRING&, zCPosition&, zCOLOR& )                                                     zCall( 0x00757AB0 );
    void zCViewText2_OnInit( zSTRING&, zCPosition&, float, zCFont* )                                              zCall( 0x00757B90 );
    void zCViewText2_OnInit( zSTRING&, zCPosition&, zCFont* )                                                     zCall( 0x00757C80 );
    void zCViewText2_OnInit( zSTRING&, zCPosition&, float )                                                       zCall( 0x00757D70 );
    void zCViewText2_OnInit( zSTRING&, zCPosition& )                                                              zCall( 0x00757E60 );
    zCViewText2( zSTRING& a0, zCPosition& a1, zCOLOR& a2, float a3, zCFont* a4, int a5, zTRnd_AlphaBlendFunc a6 ) zInit( zCViewText2_OnInit( a0, a1, a2, a3, a4, a5, a6 ));
    zCViewText2( zSTRING& a0, zCPosition& a1, zCOLOR& a2, zCFont* a3, int a4, zTRnd_AlphaBlendFunc a5 )           zInit( zCViewText2_OnInit( a0, a1, a2, a3, a4, a5 ));
    zCViewText2( zSTRING& a0, zCPosition& a1, zCOLOR& a2, float a3, zCFont* a4 )                                  zInit( zCViewText2_OnInit( a0, a1, a2, a3, a4 ));
    zCViewText2( zSTRING& a0, zCPosition& a1, zCOLOR& a2, zCFont* a3 )                                            zInit( zCViewText2_OnInit( a0, a1, a2, a3 ));
    zCViewText2( zSTRING& a0, zCPosition& a1, zCOLOR& a2 )                                                        zInit( zCViewText2_OnInit( a0, a1, a2 ));
    zCViewText2( zSTRING& a0, zCPosition& a1, float a2, zCFont* a3 )                                              zInit( zCViewText2_OnInit( a0, a1, a2, a3 ));
    zCViewText2( zSTRING& a0, zCPosition& a1, zCFont* a2 )                                                        zInit( zCViewText2_OnInit( a0, a1, a2 ));
    zCViewText2( zSTRING& a0, zCPosition& a1, float a2 )                                                          zInit( zCViewText2_OnInit( a0, a1, a2 ));
    zCViewText2( zSTRING& a0, zCPosition& a1 )                                                                    zInit( zCViewText2_OnInit( a0, a1 ));
    ~zCViewText2()                                                                                                zCall( 0x00757F40 );

    // user API
    #include "zCViewText2.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZVIEW_PRINT__FONT_H__VER0__