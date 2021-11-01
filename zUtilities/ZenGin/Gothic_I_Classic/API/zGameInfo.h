// Supported with union (c) 2018-2021 Union team

#ifndef __ZGAME_INFO_H__VER0__
#define __ZGAME_INFO_H__VER0__

#include "zBuffer.h"
#include "zVob.h"
#include "zNet_Win32.h"

namespace Gothic_I_Classic {
  const int zMAX_PLAYER          = 20;
  const int zPCK_GAMEINFO_INFO   = 1;
  const int zPCK_GAMEINFO_PLAYER = 2;
  const int zPCK_GAMEINFO_ALL    = 255;

  // sizeof 18h
  class zCGameInfo {
  public:
    zSTRING name; // sizeof 14h    offset 04h

    void zCGameInfo_OnInit()                                     zCall( 0x0044B6A0 );
    zCGameInfo()                                                 zInit( zCGameInfo_OnInit() );
    void PackToBuffer( zCBuffer&, unsigned char )                zCall( 0x0044B8F0 );
    int GetNumPlayers()                                          zCall( 0x0044B920 );
    static zCGameInfo* CreateFromBuffer( zCBuffer& )             zCall( 0x0044B900 );
    virtual ~zCGameInfo()                                        zCall( 0x0044B810 );
    virtual void Init()                                          zCall( 0x0044B860 );
    virtual void Reset()                                         zCall( 0x0044B870 );
    virtual void SetName( zSTRING const& )                       zCall( 0x00423470 );
    virtual zSTRING GetName() const                              zCall( 0x004235B0 );
    virtual int AddPlayer( zCPlayerInfo* )                       zCall( 0x0044B880 );
    virtual int RemPlayer( zCPlayerInfo* )                       zCall( 0x0044B890 );
    virtual zCPlayerInfo* GetPlayerByID( int )                   zCall( 0x0044B8A0 );
    virtual zCPlayerInfo* GetPlayerByVobID( unsigned long )      zCall( 0x0044B8B0 );
    virtual zCPlayerInfo* GetPlayerByNetAddress( zTNetAddress& ) zCall( 0x0044BBD0 );
    virtual void Pack( zCBuffer&, unsigned char )                zCall( 0x0044B940 );
    virtual void Unpack( zCBuffer& )                             zCall( 0x0044B9E0 );

    // user API
    #include "zCGameInfo.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZGAME_INFO_H__VER0__