// Supported with union (c) 2018 Union team

#ifndef __OGUILDS_H__VER0__
#define __OGUILDS_H__VER0__

#include "zArchiver.h"

namespace Gothic_I_Classic {

  class oCGuilds {
  public:
    int size;
    unsigned char* attitude;

    void oCGuilds_OnInit()                      zCall( 0x00663050 );
    oCGuilds()                                  zInit( oCGuilds_OnInit() );
    ~oCGuilds()                                 zCall( 0x00663150 );
    int GetAttitude( int, int )                 zCall( 0x00663170 );
    void SetAttitude( int, int, unsigned char ) zCall( 0x00663340 );
    void InitGuildTable( zSTRING const& )       zCall( 0x00663370 );
    zSTRING GetGuildName( int )                 zCall( 0x00663580 );
    void SaveGuildTable( zCArchiver& )          zCall( 0x00663700 );
    void LoadGuildTable( zCArchiver& )          zCall( 0x00663730 );

    // user API
    #include "oCGuilds.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OGUILDS_H__VER0__