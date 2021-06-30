// Supported with union (c) 2018 Union team

#ifndef __ZTYPES3D_H__VER3__
#define __ZTYPES3D_H__VER3__

#include "zAlgebra.h"

namespace Gothic_II_Addon {
  const float float_MIN = -FLT_MAX;
  const float float_MAX =  FLT_MAX;

  static const zCOLOR& GFX_RED       = *(zCOLOR*)0x00AB39E0;
  static const zCOLOR& GFX_PALEGREEN = *(zCOLOR*)0x00AB39E4;
  static const zCOLOR& GFX_SKY       = *(zCOLOR*)0x00AB39E8;
  static const zCOLOR& GFX_BROWN     = *(zCOLOR*)0x00AB39F0;
  static const zCOLOR& GFX_DOCHRE    = *(zCOLOR*)0x00AB39F4;
  static const zCOLOR& GFX_GREEN     = *(zCOLOR*)0x00AB3DF8;
  static const zCOLOR& GFX_IVORY     = *(zCOLOR*)0x00AB3DFC;
  static const zCOLOR& GFX_YELLOW    = *(zCOLOR*)0x00AB3E00;
  static const zCOLOR& GFX_PINK      = *(zCOLOR*)0x00AB3E04;
  static const zCOLOR& GFX_ORCHID    = *(zCOLOR*)0x00AB3E08;
  static const zCOLOR& GFX_DGREEN    = *(zCOLOR*)0x00AB3E10;
  static const zCOLOR& GFX_OCHRE     = *(zCOLOR*)0x00AB3E14;
  static const zCOLOR& GFX_PURPLE    = *(zCOLOR*)0x00AB3E18;
  static const zCOLOR& GFX_ORANGE    = *(zCOLOR*)0x00AB3E1C;
  static const zCOLOR& GFX_BLACK     = *(zCOLOR*)0x00AB3E20;
  static const zCOLOR& GFX_BLUE      = *(zCOLOR*)0x00AB3E24;
  static const zCOLOR& GFX_DPINK     = *(zCOLOR*)0x00AB3E28;
  static const zCOLOR& GFX_AQUA      = *(zCOLOR*)0x00AB3E2C;
  static const zCOLOR& GFX_FLESH     = *(zCOLOR*)0x00AB3E30;
  static const zCOLOR& GFX_LPINK     = *(zCOLOR*)0x00AB3E34;
  static const zCOLOR& GFX_STEEL     = *(zCOLOR*)0x00AB3E38;
  static const zCOLOR& GFX_DBLUE     = *(zCOLOR*)0x00AB3E3C;
  static const zCOLOR& GFX_VIOLET    = *(zCOLOR*)0x00AB3E40;
  static const zCOLOR& GFX_DRED      = *(zCOLOR*)0x00AB3E44;
  static const zCOLOR& GFX_LBLUE     = *(zCOLOR*)0x00AB3E48;
  static const zCOLOR& GFX_WARMGREY  = *(zCOLOR*)0x00AB3E4C;
  static const zCOLOR& GFX_CYAN      = *(zCOLOR*)0x00AB3E50;
  static const zCOLOR& GFX_KHAKI     = *(zCOLOR*)0x00AB3E54;
  static const zCOLOR& GFX_INDIGO    = *(zCOLOR*)0x00AB3E58;
  static const zCOLOR& GFX_LYELLOW   = *(zCOLOR*)0x00AB3E5C;
  static const zCOLOR& GFX_COLDGREY  = *(zCOLOR*)0x00AB4060;
  static const zCOLOR& GFX_CARROT    = *(zCOLOR*)0x00AB4064;
  static const zCOLOR& GFX_GOLD      = *(zCOLOR*)0x00AB4068;
  static const zCOLOR& GFX_WHITE     = *(zCOLOR*)0x00AB4070;
  static const zCOLOR& GFX_GREY      = *(zCOLOR*)0x00AB4074;
  static const zCOLOR& GFX_MBLUE     = *(zCOLOR*)0x00AB4078;
  static const zCOLOR& GFX_MAGENTA   = *(zCOLOR*)0x00AB407C;
  static const zCOLOR& GFX_OLIVE     = *(zCOLOR*)0x00AB4080;
  static const zCOLOR& GFX_BEIGE     = *(zCOLOR*)0x00AB4084;
  static const zCOLOR& GFX_LGREY     = *(zCOLOR*)0x00AB4088;
  static const zCOLOR& GFX_DORANGE   = *(zCOLOR*)0x00AB408C;

  enum zTPlaneClass {
    zPLANE_INFRONT,
    zPLANE_BEHIND,
    zPLANE_ONPLANE,
    zPLANE_SPANNING
  };

  struct zCOLOR {
    union {
      group {
        unsigned char b;
        unsigned char g;
        unsigned char r;
        unsigned char alpha;
      };
      unsigned long dword;
    };

    zCOLOR() {}
    void zCOLOR_OnInit( int )                                                              zCall( 0x00401F20 );
    void zCOLOR_OnInit( unsigned char, unsigned char, unsigned char, unsigned char )       zCall( 0x0078AEF0 );
    zCOLOR( int a0 )                                                                       zInit( zCOLOR_OnInit( a0 ));
    void Reset()                                                                           zCall( 0x00572900 );
    zSTRING GetDescription() const                                                         zCall( 0x005FABA0 );
    void SetByDescription( zSTRING const& )                                                zCall( 0x005FAF10 );
    zSTRING GetDescriptionRGB() const                                                      zCall( 0x005FB190 );
    void SetRGB( unsigned char, unsigned char, unsigned char )                             zCall( 0x0062A740 );
    zCOLOR( unsigned char a0, unsigned char a1, unsigned char a2, unsigned char a3 = 255 ) zInit( zCOLOR_OnInit( a0, a1, a2, a3 ));

    // user API
    #include "zCOLOR.inl"
  };

  struct zTPlane {
    float distance;
    zVEC3 normal;

    zTPlane() {}
    int CalcSignbits() const                              zCall( 0x0054B1A0 );
    int ClassifyPointBSPBuild( zVEC3 const& ) const       zCall( 0x005FB440 );
    zSTRING Print() const                                 zCall( 0x005FB490 );
    void Calc( zVEC3 const&, zVEC3 const&, zVEC3 const& ) zCall( 0x005FB870 );
    void GetOriginUpRight( zVEC3&, zVEC3&, zVEC3& ) const zCall( 0x005FB950 );

    // user API
    #include "zTPlane.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZTYPES3D_H__VER3__