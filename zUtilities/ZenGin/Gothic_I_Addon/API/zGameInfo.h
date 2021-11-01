// Supported with union (c) 2018-2021 Union team

#ifndef __ZGAME_INFO_H__VER1__
#define __ZGAME_INFO_H__VER1__

#include "zBuffer.h"
#include "zVob.h"
#include "zNet_Win32.h"

namespace Gothic_I_Addon {
  const int zMAX_PLAYER          = 20;
  const int zPCK_GAMEINFO_INFO   = 1;
  const int zPCK_GAMEINFO_PLAYER = 2;
  const int zPCK_GAMEINFO_ALL    = 255;

  // sizeof 18h
  class zCGameInfo {
  public:
    zSTRING name; // sizeof 14h    offset 04h

    void zCGameInfo_OnInit()                                     zCall( 0x00451BD0 );
    zCGameInfo()                                                 zInit( zCGameInfo_OnInit() );
    void PackToBuffer( zCBuffer&, unsigned char )                zCall( 0x00451E70 );
    int GetNumPlayers()                                          zCall( 0x00451EB0 );
    static zCGameInfo* CreateFromBuffer( zCBuffer& )             zCall( 0x00451E90 );
    virtual ~zCGameInfo()                                        zCall( 0x00451D50 );
    virtual void Init()                                          zCall( 0x00451DB0 );
    virtual void Reset()                                         zCall( 0x00451DC0 );
    virtual void SetName( zSTRING const& )                       zCall( 0x00425BB0 );
    virtual zSTRING GetName() const                              zCall( 0x00425CF0 );
    virtual int AddPlayer( zCPlayerInfo* )                       zCall( 0x00451DD0 );
    virtual int RemPlayer( zCPlayerInfo* )                       zCall( 0x00451DF0 );
    virtual zCPlayerInfo* GetPlayerByID( int )                   zCall( 0x00451E10 );
    virtual zCPlayerInfo* GetPlayerByVobID( unsigned long )      zCall( 0x00451E30 );
    virtual zCPlayerInfo* GetPlayerByNetAddress( zTNetAddress& ) zCall( 0x00452150 );
    virtual void Pack( zCBuffer&, unsigned char )                zCall( 0x00451ED0 );
    virtual void Unpack( zCBuffer& )                             zCall( 0x00451F60 );

    // user API
    #include "zCGameInfo.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZGAME_INFO_H__VER1__