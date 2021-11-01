// Supported with union (c) 2018-2021 Union team

#ifndef __ZPLUECKER_H__VER1__
#define __ZPLUECKER_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 18h
  class zCPluecker {
  public:
    float dir[3]; // sizeof 0Ch    offset 00h
    float pos[3]; // sizeof 0Ch    offset 0Ch

    void zCPluecker_OnInit( zVEC3 const&, zVEC3 const& ) zCall( 0x005B16A0 );
    void zCPluecker_OnInit()                             zCall( 0x005B16F0 );
    zCPluecker( zVEC3 const& a0, zVEC3 const& a1 )       zInit( zCPluecker_OnInit( a0, a1 ));
    zCPluecker()                                         zInit( zCPluecker_OnInit() );
    float Length2() const                                zCall( 0x005B1710 );
    void Normalize()                                     zCall( 0x005B1740 );

    // user API
    #include "zCPluecker.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZPLUECKER_H__VER1__