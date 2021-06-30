// Supported with union (c) 2018 Union team

#ifndef __OGUILDS_H__VER2__
#define __OGUILDS_H__VER2__

#include "zArchiver.h"

namespace Gothic_II_Classic {

  class oCGuilds {
  public:
    int size;
    unsigned char* attitude;

    void oCGuilds_OnInit()                      zCall( 0x006A31A0 );
    oCGuilds()                                  zInit( oCGuilds_OnInit() );
    ~oCGuilds()                                 zCall( 0x006A3290 );
    int GetAttitude( int, int )                 zCall( 0x006A32B0 );
    void SetAttitude( int, int, unsigned char ) zCall( 0x006A34E0 );
    void InitGuildTable( zSTRING const& )       zCall( 0x006A3510 );
    zSTRING GetGuildName( int )                 zCall( 0x006A3750 );
    void SaveGuildTable( zCArchiver& )          zCall( 0x006A38D0 );
    void LoadGuildTable( zCArchiver& )          zCall( 0x006A3900 );

    // user API
    #include "oCGuilds.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OGUILDS_H__VER2__