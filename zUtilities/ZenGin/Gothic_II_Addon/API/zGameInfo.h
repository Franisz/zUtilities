// Supported with union (c) 2018-2021 Union team

#ifndef __ZGAME_INFO_H__VER3__
#define __ZGAME_INFO_H__VER3__

#include "zBuffer.h"
#include "zVob.h"
#include "zNet_Win32.h"

namespace Gothic_II_Addon {
  const int zMAX_PLAYER          = 20;
  const int zPCK_GAMEINFO_INFO   = 1;
  const int zPCK_GAMEINFO_PLAYER = 2;
  const int zPCK_GAMEINFO_ALL    = 255;

  // sizeof 18h
  class zCGameInfo {
  public:
    zSTRING name; // sizeof 14h    offset 04h

    void zCGameInfo_OnInit()                                     zCall( 0x0044FE20 );
    zCGameInfo()                                                 zInit( zCGameInfo_OnInit() );
    void PackToBuffer( zCBuffer&, unsigned char )                zCall( 0x00450070 );
    int GetNumPlayers()                                          zCall( 0x004500A0 );
    static zCGameInfo* CreateFromBuffer( zCBuffer& )             zCall( 0x00450080 );
    virtual ~zCGameInfo()                                        zCall( 0x0044FF90 );
    virtual void Init()                                          zCall( 0x0044FFE0 );
    virtual void Reset()                                         zCall( 0x0044FFF0 );
    virtual void SetName( zSTRING const& )                       zCall( 0x00423E50 );
    virtual zSTRING GetName() const                              zCall( 0x00423F90 );
    virtual int AddPlayer( zCPlayerInfo* )                       zCall( 0x00450000 );
    virtual int RemPlayer( zCPlayerInfo* )                       zCall( 0x00450010 );
    virtual zCPlayerInfo* GetPlayerByID( int )                   zCall( 0x00450020 );
    virtual zCPlayerInfo* GetPlayerByVobID( unsigned long )      zCall( 0x00450030 );
    virtual zCPlayerInfo* GetPlayerByNetAddress( zTNetAddress& ) zCall( 0x00450350 );
    virtual void Pack( zCBuffer&, unsigned char )                zCall( 0x004500C0 );
    virtual void Unpack( zCBuffer& )                             zCall( 0x00450160 );

    // user API
    #include "zCGameInfo.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZGAME_INFO_H__VER3__