// Supported with union (c) 2018 Union team

#ifndef __ZTYPES3D_H__VER1__
#define __ZTYPES3D_H__VER1__

namespace Gothic_I_Addon {
  const float float_MIN = -FLT_MAX;
  const float float_MAX =  FLT_MAX;

  static const zCOLOR& GFX_RED       = *(zCOLOR*)0x00924960;
  static const zCOLOR& GFX_PALEGREEN = *(zCOLOR*)0x00924964;
  static const zCOLOR& GFX_SKY       = *(zCOLOR*)0x00924968;
  static const zCOLOR& GFX_BROWN     = *(zCOLOR*)0x00924970;
  static const zCOLOR& GFX_DOCHRE    = *(zCOLOR*)0x00924974;
  static const zCOLOR& GFX_GREEN     = *(zCOLOR*)0x00924D78;
  static const zCOLOR& GFX_IVORY     = *(zCOLOR*)0x00924D7C;
  static const zCOLOR& GFX_YELLOW    = *(zCOLOR*)0x00924D80;
  static const zCOLOR& GFX_PINK      = *(zCOLOR*)0x00924D84;
  static const zCOLOR& GFX_ORCHID    = *(zCOLOR*)0x00924D88;
  static const zCOLOR& GFX_DGREEN    = *(zCOLOR*)0x00924D90;
  static const zCOLOR& GFX_OCHRE     = *(zCOLOR*)0x00924D94;
  static const zCOLOR& GFX_PURPLE    = *(zCOLOR*)0x00924D98;
  static const zCOLOR& GFX_ORANGE    = *(zCOLOR*)0x00924D9C;
  static const zCOLOR& GFX_BLACK     = *(zCOLOR*)0x00924DA0;
  static const zCOLOR& GFX_BLUE      = *(zCOLOR*)0x00924DA4;
  static const zCOLOR& GFX_DPINK     = *(zCOLOR*)0x00924DA8;
  static const zCOLOR& GFX_AQUA      = *(zCOLOR*)0x00924DAC;
  static const zCOLOR& GFX_FLESH     = *(zCOLOR*)0x00924DB0;
  static const zCOLOR& GFX_LPINK     = *(zCOLOR*)0x00924DB4;
  static const zCOLOR& GFX_STEEL     = *(zCOLOR*)0x00924DB8;
  static const zCOLOR& GFX_DBLUE     = *(zCOLOR*)0x00924DBC;
  static const zCOLOR& GFX_VIOLET    = *(zCOLOR*)0x00924DC0;
  static const zCOLOR& GFX_DRED      = *(zCOLOR*)0x00924DC4;
  static const zCOLOR& GFX_LBLUE     = *(zCOLOR*)0x00924DC8;
  static const zCOLOR& GFX_WARMGREY  = *(zCOLOR*)0x00924DCC;
  static const zCOLOR& GFX_CYAN      = *(zCOLOR*)0x00924DD0;
  static const zCOLOR& GFX_KHAKI     = *(zCOLOR*)0x00924DD4;
  static const zCOLOR& GFX_INDIGO    = *(zCOLOR*)0x00924DD8;
  static const zCOLOR& GFX_LYELLOW   = *(zCOLOR*)0x00924DDC;
  static const zCOLOR& GFX_COLDGREY  = *(zCOLOR*)0x00924FE0;
  static const zCOLOR& GFX_CARROT    = *(zCOLOR*)0x00924FE4;
  static const zCOLOR& GFX_GOLD      = *(zCOLOR*)0x00924FE8;
  static const zCOLOR& GFX_WHITE     = *(zCOLOR*)0x00924FF0;
  static const zCOLOR& GFX_GREY      = *(zCOLOR*)0x00924FF4;
  static const zCOLOR& GFX_MBLUE     = *(zCOLOR*)0x00924FF8;
  static const zCOLOR& GFX_MAGENTA   = *(zCOLOR*)0x00924FFC;
  static const zCOLOR& GFX_OLIVE     = *(zCOLOR*)0x00925000;
  static const zCOLOR& GFX_BEIGE     = *(zCOLOR*)0x00925004;
  static const zCOLOR& GFX_LGREY     = *(zCOLOR*)0x00925008;
  static const zCOLOR& GFX_DORANGE   = *(zCOLOR*)0x0092500C;

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
    void zCOLOR_OnInit( int )                                                              zCall( 0x004021F0 );
    void zCOLOR_OnInit( unsigned char, unsigned char, unsigned char, unsigned char )       zCall( 0x0071A280 );
    zCOLOR( int a0 )                                                                       zInit( zCOLOR_OnInit( a0 ));
    void Reset()                                                                           zCall( 0x00571AA0 );
    zVEC3 GetVEC3() const                                                                  zCall( 0x005B4050 );
    zSTRING GetDescription() const                                                         zCall( 0x005EE8C0 );
    void SetByDescription( zSTRING const& )                                                zCall( 0x005EEBC0 );
    zSTRING GetDescriptionRGB() const                                                      zCall( 0x005EEE90 );
    void SetRGB( unsigned char, unsigned char, unsigned char )                             zCall( 0x0061D320 );
    zCOLOR( unsigned char a0, unsigned char a1, unsigned char a2, unsigned char a3 = 255 ) zInit( zCOLOR_OnInit( a0, a1, a2, a3 ));

    // user API
    #include "zCOLOR.inl"
  };

  struct zTPlane {
    float distance;
    zVEC3 normal;

    zTPlane() {}
    int EqualTo( zTPlane const&, float ) const                        zCall( 0x005EF0F0 );
    int operator == ( zTPlane const& ) const                          zCall( 0x005EF150 );
    int Opposite( zTPlane const& ) const                              zCall( 0x005EF1A0 );
    int ClassifyPoint( zVEC3 const& ) const                           zCall( 0x005EF1E0 );
    int ClassifyPointBSPBuild( zVEC3 const& ) const                   zCall( 0x005EF230 );
    int CalcSignbits() const                                          zCall( 0x005EF280 );
    zSTRING Print() const                                             zCall( 0x005EF2E0 );
    int Intersection( zVEC3 const&, zVEC3 const&, zVEC3& ) const      zCall( 0x005EF650 );
    int IntersectionFront( zVEC3 const&, zVEC3 const&, zVEC3& ) const zCall( 0x005EF740 );
    void Calc( zVEC3 const&, zVEC3 const&, zVEC3 const& )             zCall( 0x005EF830 );
    void GetOriginUpRight( zVEC3&, zVEC3&, zVEC3& ) const             zCall( 0x005EF920 );

    // user API
    #include "zTPlane.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZTYPES3D_H__VER1__