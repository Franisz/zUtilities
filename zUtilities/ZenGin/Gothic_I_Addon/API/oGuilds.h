// Supported with union (c) 2018-2021 Union team

#ifndef __OGUILDS_H__VER1__
#define __OGUILDS_H__VER1__

#include "zArchiver.h"

namespace Gothic_I_Addon {

  // sizeof 08h
  class oCGuilds {
  public:
    int size;                // sizeof 04h    offset 00h
    unsigned char* attitude; // sizeof 04h    offset 04h

    void oCGuilds_OnInit()                      zCall( 0x0068FBB0 );
    oCGuilds()                                  zInit( oCGuilds_OnInit() );
    ~oCGuilds()                                 zCall( 0x0068FCB0 );
    int GetAttitude( int, int )                 zCall( 0x0068FCD0 );
    void SetAttitude( int, int, unsigned char ) zCall( 0x0068FEE0 );
    void InitGuildTable( zSTRING const& )       zCall( 0x0068FF10 );
    zSTRING GetGuildName( int )                 zCall( 0x00690140 );
    void SaveGuildTable( zCArchiver& )          zCall( 0x00690310 );
    void LoadGuildTable( zCArchiver& )          zCall( 0x00690340 );

    // user API
    #include "oCGuilds.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OGUILDS_H__VER1__