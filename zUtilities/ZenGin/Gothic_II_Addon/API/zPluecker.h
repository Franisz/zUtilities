// Supported with union (c) 2018 Union team

#ifndef __ZPLUECKER_H__VER3__
#define __ZPLUECKER_H__VER3__

namespace Gothic_II_Addon {

  class zCPluecker {
  public:
    float dir[3];
    float pos[3];

    void zCPluecker_OnInit( zVEC3 const&, zVEC3 const& ) zCall( 0x005B6B00 );
    void zCPluecker_OnInit()                             zCall( 0x005B6B50 );
    zCPluecker( zVEC3 const& a0, zVEC3 const& a1 )       zInit( zCPluecker_OnInit( a0, a1 ));
    zCPluecker()                                         zInit( zCPluecker_OnInit() );
    float Length2() const                                zCall( 0x005B6B70 );
    void Normalize()                                     zCall( 0x005B6BA0 );
    zCPluecker& operator-= ( zCPluecker const& )         zCall( 0x005D37D0 );

    // user API
    #include "zCPluecker.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZPLUECKER_H__VER3__