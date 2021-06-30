// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_PRINT__FONT_H__VER3__
#define __ZVIEW_PRINT__FONT_H__VER3__

namespace Gothic_II_Addon {

  class zCViewFont {
  public:
    zTRnd_AlphaBlendFunc FuncAlphaBlend;
    zCFont* Font;
    zCOLOR Color;
    int Alpha;
    int EnabledBlend;

    void zCViewFont_OnInit( zCFont*, zCOLOR&, int, zTRnd_AlphaBlendFunc ) zCall( 0x00694C40 );
    void zCViewFont_OnInit( zCFont*, zCOLOR& )                            zCall( 0x00694C70 );
    void zCViewFont_OnInit( zCFont* )                                     zCall( 0x00694CA0 );
    void zCViewFont_OnInit()                                              zCall( 0x00694CE0 );
    zCViewFont( zCFont* a0, zCOLOR& a1, int a2, zTRnd_AlphaBlendFunc a3 ) zInit( zCViewFont_OnInit( a0, a1, a2, a3 ));
    zCViewFont( zCFont* a0, zCOLOR& a1 )                                  zInit( zCViewFont_OnInit( a0, a1 ));
    zCViewFont( zCFont* a0 )                                              zInit( zCViewFont_OnInit( a0 ));
    zCViewFont()                                                          zInit( zCViewFont_OnInit() );
    ~zCViewFont()                                                         zCall( 0x00694D20 );
    void __fastcall SetFont( zSTRING& )                                   zCall( 0x00694D30 );

    // user API
    #include "zCViewFont.inl"
  };

  class zCViewText2 {
  public:
    int EnabledColor;
    int EnabledTimer;
    zPOS PixelPosition;
    float Timer;
    zSTRING Text;
    zCViewFont ViewFont;

    zCViewText2() {}
    void zCViewText2_OnInit( zSTRING&, zCPosition&, zCOLOR&, float, zCFont*, int, zTRnd_AlphaBlendFunc )          zCall( 0x006943D0 );
    void zCViewText2_OnInit( zSTRING&, zCPosition&, zCOLOR&, zCFont*, int, zTRnd_AlphaBlendFunc )                 zCall( 0x006944B0 );
    void zCViewText2_OnInit( zSTRING&, zCPosition&, zCOLOR&, float, zCFont* )                                     zCall( 0x00694590 );
    void zCViewText2_OnInit( zSTRING&, zCPosition&, zCOLOR&, zCFont* )                                            zCall( 0x00694680 );
    void zCViewText2_OnInit( zSTRING&, zCPosition&, zCOLOR& )                                                     zCall( 0x00694760 );
    void zCViewText2_OnInit( zSTRING&, zCPosition&, float, zCFont* )                                              zCall( 0x00694840 );
    void zCViewText2_OnInit( zSTRING&, zCPosition&, zCFont* )                                                     zCall( 0x00694930 );
    void zCViewText2_OnInit( zSTRING&, zCPosition&, float )                                                       zCall( 0x00694A20 );
    void zCViewText2_OnInit( zSTRING&, zCPosition& )                                                              zCall( 0x00694B10 );
    zCViewText2( zSTRING& a0, zCPosition& a1, zCOLOR& a2, float a3, zCFont* a4, int a5, zTRnd_AlphaBlendFunc a6 ) zInit( zCViewText2_OnInit( a0, a1, a2, a3, a4, a5, a6 ));
    zCViewText2( zSTRING& a0, zCPosition& a1, zCOLOR& a2, zCFont* a3, int a4, zTRnd_AlphaBlendFunc a5 )           zInit( zCViewText2_OnInit( a0, a1, a2, a3, a4, a5 ));
    zCViewText2( zSTRING& a0, zCPosition& a1, zCOLOR& a2, float a3, zCFont* a4 )                                  zInit( zCViewText2_OnInit( a0, a1, a2, a3, a4 ));
    zCViewText2( zSTRING& a0, zCPosition& a1, zCOLOR& a2, zCFont* a3 )                                            zInit( zCViewText2_OnInit( a0, a1, a2, a3 ));
    zCViewText2( zSTRING& a0, zCPosition& a1, zCOLOR& a2 )                                                        zInit( zCViewText2_OnInit( a0, a1, a2 ));
    zCViewText2( zSTRING& a0, zCPosition& a1, float a2, zCFont* a3 )                                              zInit( zCViewText2_OnInit( a0, a1, a2, a3 ));
    zCViewText2( zSTRING& a0, zCPosition& a1, zCFont* a2 )                                                        zInit( zCViewText2_OnInit( a0, a1, a2 ));
    zCViewText2( zSTRING& a0, zCPosition& a1, float a2 )                                                          zInit( zCViewText2_OnInit( a0, a1, a2 ));
    zCViewText2( zSTRING& a0, zCPosition& a1 )                                                                    zInit( zCViewText2_OnInit( a0, a1 ));
    ~zCViewText2()                                                                                                zCall( 0x00694BF0 );

    // user API
    #include "zCViewText2.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVIEW_PRINT__FONT_H__VER3__