// Supported with union (c) 2018-2021 Union team

#ifndef __OGUILDS_H__VER3__
#define __OGUILDS_H__VER3__

#include "zArchiver.h"

namespace Gothic_II_Addon {

  // sizeof 08h
  class oCGuilds {
  public:
    int size;                // sizeof 04h    offset 00h
    unsigned char* attitude; // sizeof 04h    offset 04h

    void oCGuilds_OnInit()                      zCall( 0x00700C30 );
    oCGuilds()                                  zInit( oCGuilds_OnInit() );
    ~oCGuilds()                                 zCall( 0x00700D20 );
    int GetAttitude( int, int )                 zCall( 0x00700D40 );
    void SetAttitude( int, int, unsigned char ) zCall( 0x00700F70 );
    void InitGuildTable( zSTRING const& )       zCall( 0x00700FA0 );
    zSTRING GetGuildName( int )                 zCall( 0x007011E0 );
    void SaveGuildTable( zCArchiver& )          zCall( 0x00701360 );
    void LoadGuildTable( zCArchiver& )          zCall( 0x00701390 );

    // user API
    #include "oCGuilds.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OGUILDS_H__VER3__