// Supported with union (c) 2018 Union team

#ifndef __ZTYPES3D_H__VER0__
#define __ZTYPES3D_H__VER0__

namespace Gothic_I_Classic {
  const float float_MIN = -FLT_MAX;
  const float float_MAX =  FLT_MAX;
  
  static const zCOLOR& GFX_RED       = *(zCOLOR*)0x008DC728;
  static const zCOLOR& GFX_PALEGREEN = *(zCOLOR*)0x008DC72C;
  static const zCOLOR& GFX_SKY       = *(zCOLOR*)0x008DC730;
  static const zCOLOR& GFX_BROWN     = *(zCOLOR*)0x008DC738;
  static const zCOLOR& GFX_DOCHRE    = *(zCOLOR*)0x008DC73C;
  static const zCOLOR& GFX_GREEN     = *(zCOLOR*)0x008DCB40;
  static const zCOLOR& GFX_IVORY     = *(zCOLOR*)0x008DCB44;
  static const zCOLOR& GFX_YELLOW    = *(zCOLOR*)0x008DCB48;
  static const zCOLOR& GFX_PINK      = *(zCOLOR*)0x008DCB4C;
  static const zCOLOR& GFX_ORCHID    = *(zCOLOR*)0x008DCB50;
  static const zCOLOR& GFX_DGREEN    = *(zCOLOR*)0x008DCB58;
  static const zCOLOR& GFX_OCHRE     = *(zCOLOR*)0x008DCB5C;
  static const zCOLOR& GFX_PURPLE    = *(zCOLOR*)0x008DCB60;
  static const zCOLOR& GFX_ORANGE    = *(zCOLOR*)0x008DCB64;
  static const zCOLOR& GFX_BLACK     = *(zCOLOR*)0x008DCB68;
  static const zCOLOR& GFX_BLUE      = *(zCOLOR*)0x008DCB6C;
  static const zCOLOR& GFX_DPINK     = *(zCOLOR*)0x008DCB70;
  static const zCOLOR& GFX_AQUA      = *(zCOLOR*)0x008DCB74;
  static const zCOLOR& GFX_FLESH     = *(zCOLOR*)0x008DCB78;
  static const zCOLOR& GFX_LPINK     = *(zCOLOR*)0x008DCB7C;
  static const zCOLOR& GFX_STEEL     = *(zCOLOR*)0x008DCB80;
  static const zCOLOR& GFX_DBLUE     = *(zCOLOR*)0x008DCB84;
  static const zCOLOR& GFX_VIOLET    = *(zCOLOR*)0x008DCB88;
  static const zCOLOR& GFX_DRED      = *(zCOLOR*)0x008DCB8C;
  static const zCOLOR& GFX_LBLUE     = *(zCOLOR*)0x008DCB90;
  static const zCOLOR& GFX_WARMGREY  = *(zCOLOR*)0x008DCB94;
  static const zCOLOR& GFX_CYAN      = *(zCOLOR*)0x008DCB98;
  static const zCOLOR& GFX_KHAKI     = *(zCOLOR*)0x008DCB9C;
  static const zCOLOR& GFX_INDIGO    = *(zCOLOR*)0x008DCBA0;
  static const zCOLOR& GFX_LYELLOW   = *(zCOLOR*)0x008DCBA4;
  static const zCOLOR& GFX_COLDGREY  = *(zCOLOR*)0x008DCDA8;
  static const zCOLOR& GFX_CARROT    = *(zCOLOR*)0x008DCDAC;
  static const zCOLOR& GFX_GOLD      = *(zCOLOR*)0x008DCDB0;
  static const zCOLOR& GFX_WHITE     = *(zCOLOR*)0x008DCDB8;
  static const zCOLOR& GFX_GREY      = *(zCOLOR*)0x008DCDBC;
  static const zCOLOR& GFX_MBLUE     = *(zCOLOR*)0x008DCDC0;
  static const zCOLOR& GFX_MAGENTA   = *(zCOLOR*)0x008DCDC4;
  static const zCOLOR& GFX_OLIVE     = *(zCOLOR*)0x008DCDC8;
  static const zCOLOR& GFX_BEIGE     = *(zCOLOR*)0x008DCDCC;
  static const zCOLOR& GFX_LGREY     = *(zCOLOR*)0x008DCDD0;
  static const zCOLOR& GFX_DORANGE   = *(zCOLOR*)0x008DCDD4;

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
    void zCOLOR_OnInit( int )                                                              zCall( 0x00401DE0 );
    void zCOLOR_OnInit( unsigned char, unsigned char, unsigned char, unsigned char )       zCall( 0x006E1BC0 );
    zCOLOR( int a0 )                                                                       zInit( zCOLOR_OnInit( a0 ));
    void Reset()                                                                           zCall( 0x00559960 );
    zSTRING GetDescription() const                                                         zCall( 0x005CF9E0 );
    void SetByDescription( zSTRING const& )                                                zCall( 0x005CFC60 );
    zSTRING GetDescriptionRGB() const                                                      zCall( 0x005CFEE0 );
    void SetRGB( unsigned char, unsigned char, unsigned char )                             zCall( 0x005FBB40 );
    zCOLOR( unsigned char a0, unsigned char a1, unsigned char a2, unsigned char a3 = 255 ) zInit( zCOLOR_OnInit( a0, a1, a2, a3 ));

    // user API
    #include "zCOLOR.inl"
  };

  struct zTPlane {
    float distance;
    zVEC3 normal;

    zTPlane() {}
    int EqualTo( zTPlane const&, float ) const                        zCall( 0x005D00F0 );
    int operator == ( zTPlane const& ) const                          zCall( 0x005D0150 );
    int Opposite( zTPlane const& ) const                              zCall( 0x005D01A0 );
    int ClassifyPoint( zVEC3 const& ) const                           zCall( 0x005D01E0 );
    int ClassifyPointBSPBuild( zVEC3 const& ) const                   zCall( 0x005D0230 );
    int CalcSignbits() const                                          zCall( 0x005D0280 );
    zSTRING Print() const                                             zCall( 0x005D02E0 );
    int Intersection( zVEC3 const&, zVEC3 const&, zVEC3& ) const      zCall( 0x005D05C0 );
    int IntersectionFront( zVEC3 const&, zVEC3 const&, zVEC3& ) const zCall( 0x005D0690 );
    void Calc( zVEC3 const&, zVEC3 const&, zVEC3 const& )             zCall( 0x005D0770 );
    void GetOriginUpRight( zVEC3&, zVEC3&, zVEC3& ) const             zCall( 0x005D0850 );

    // user API
    #include "zTPlane.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZTYPES3D_H__VER0__