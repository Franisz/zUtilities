// Supported with union (c) 2018 Union team

#ifndef __ZTYPES3D_H__VER2__
#define __ZTYPES3D_H__VER2__

namespace Gothic_II_Classic {
  const float float_MIN = -FLT_MAX;
  const float float_MAX =  FLT_MAX;

  static const zCOLOR& GFX_RED       = *(zCOLOR*)0x00984528;
  static const zCOLOR& GFX_PALEGREEN = *(zCOLOR*)0x0098452C;
  static const zCOLOR& GFX_SKY       = *(zCOLOR*)0x00984530;
  static const zCOLOR& GFX_BROWN     = *(zCOLOR*)0x00984538;
  static const zCOLOR& GFX_DOCHRE    = *(zCOLOR*)0x0098453C;
  static const zCOLOR& GFX_GREEN     = *(zCOLOR*)0x00984940;
  static const zCOLOR& GFX_IVORY     = *(zCOLOR*)0x00984944;
  static const zCOLOR& GFX_YELLOW    = *(zCOLOR*)0x00984948;
  static const zCOLOR& GFX_PINK      = *(zCOLOR*)0x0098494C;
  static const zCOLOR& GFX_ORCHID    = *(zCOLOR*)0x00984950;
  static const zCOLOR& GFX_DGREEN    = *(zCOLOR*)0x00984958;
  static const zCOLOR& GFX_OCHRE     = *(zCOLOR*)0x0098495C;
  static const zCOLOR& GFX_PURPLE    = *(zCOLOR*)0x00984960;
  static const zCOLOR& GFX_ORANGE    = *(zCOLOR*)0x00984964;
  static const zCOLOR& GFX_BLACK     = *(zCOLOR*)0x00984968;
  static const zCOLOR& GFX_BLUE      = *(zCOLOR*)0x0098496C;
  static const zCOLOR& GFX_DPINK     = *(zCOLOR*)0x00984970;
  static const zCOLOR& GFX_AQUA      = *(zCOLOR*)0x00984974;
  static const zCOLOR& GFX_FLESH     = *(zCOLOR*)0x00984978;
  static const zCOLOR& GFX_LPINK     = *(zCOLOR*)0x0098497C;
  static const zCOLOR& GFX_STEEL     = *(zCOLOR*)0x00984980;
  static const zCOLOR& GFX_DBLUE     = *(zCOLOR*)0x00984984;
  static const zCOLOR& GFX_VIOLET    = *(zCOLOR*)0x00984988;
  static const zCOLOR& GFX_DRED      = *(zCOLOR*)0x0098498C;
  static const zCOLOR& GFX_LBLUE     = *(zCOLOR*)0x00984990;
  static const zCOLOR& GFX_WARMGREY  = *(zCOLOR*)0x00984994;
  static const zCOLOR& GFX_CYAN      = *(zCOLOR*)0x00984998;
  static const zCOLOR& GFX_KHAKI     = *(zCOLOR*)0x0098499C;
  static const zCOLOR& GFX_INDIGO    = *(zCOLOR*)0x009849A0;
  static const zCOLOR& GFX_LYELLOW   = *(zCOLOR*)0x009849A4;
  static const zCOLOR& GFX_COLDGREY  = *(zCOLOR*)0x00984BA8;
  static const zCOLOR& GFX_CARROT    = *(zCOLOR*)0x00984BAC;
  static const zCOLOR& GFX_GOLD      = *(zCOLOR*)0x00984BB0;
  static const zCOLOR& GFX_WHITE     = *(zCOLOR*)0x00984BB8;
  static const zCOLOR& GFX_GREY      = *(zCOLOR*)0x00984BBC;
  static const zCOLOR& GFX_MBLUE     = *(zCOLOR*)0x00984BC0;
  static const zCOLOR& GFX_MAGENTA   = *(zCOLOR*)0x00984BC4;
  static const zCOLOR& GFX_OLIVE     = *(zCOLOR*)0x00984BC8;
  static const zCOLOR& GFX_BEIGE     = *(zCOLOR*)0x00984BCC;
  static const zCOLOR& GFX_LGREY     = *(zCOLOR*)0x00984BD0;
  static const zCOLOR& GFX_DORANGE   = *(zCOLOR*)0x00984BD4;

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
    void zCOLOR_OnInit( unsigned char, unsigned char, unsigned char, unsigned char )       zCall( 0x0072B4B0 );
    zCOLOR( int a0 )                                                                       zInit( zCOLOR_OnInit( a0 ));
    void Reset()                                                                           zCall( 0x0056D650 );
    zSTRING GetDescription() const                                                         zCall( 0x005F3DB0 );
    void SetByDescription( zSTRING const& )                                                zCall( 0x005F4120 );
    zSTRING GetDescriptionRGB() const                                                      zCall( 0x005F43A0 );
    void SetRGB( unsigned char, unsigned char, unsigned char )						       zCall( 0x00622FC0 );
    zCOLOR( unsigned char a0, unsigned char a1, unsigned char a2, unsigned char a3 = 255 ) zInit( zCOLOR_OnInit( a0, a1, a2, a3 ));

    // user API
    #include "zCOLOR.inl"
  };

  struct zTPlane {
    float distance;
    zVEC3 normal;

    zTPlane() {}
    int CalcSignbits() const                              zCall( 0x00545F80 );
    int ClassifyPointBSPBuild( zVEC3 const& ) const       zCall( 0x005F4650 );
    zSTRING Print() const                                 zCall( 0x005F46A0 );
    void Calc( zVEC3 const&, zVEC3 const&, zVEC3 const& ) zCall( 0x005F4A80 );
    void GetOriginUpRight( zVEC3&, zVEC3&, zVEC3& ) const zCall( 0x005F4B60 );

    // user API
    #include "zTPlane.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZTYPES3D_H__VER2__