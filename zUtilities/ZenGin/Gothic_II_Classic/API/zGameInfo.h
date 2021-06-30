// Supported with union (c) 2018 Union team

#ifndef __ZGAME_INFO_H__VER2__
#define __ZGAME_INFO_H__VER2__

#include "zBuffer.h"
#include "zVob.h"
#include "zNet_Win32.h"

namespace Gothic_II_Classic {
  const int zMAX_PLAYER          = 20;
  const int zPCK_GAMEINFO_INFO   = 1;
  const int zPCK_GAMEINFO_PLAYER = 2;
  const int zPCK_GAMEINFO_ALL    = 255;

  class zCGameInfo {
  public:
    zSTRING name;

    void zCGameInfo_OnInit()                                     zCall( 0x0044F6D0 );
    zCGameInfo()                                                 zInit( zCGameInfo_OnInit() );
    void PackToBuffer( zCBuffer&, unsigned char )                zCall( 0x0044F920 );
    int GetNumPlayers()                                          zCall( 0x0044F950 );
    static zCGameInfo* CreateFromBuffer( zCBuffer& )             zCall( 0x0044F930 );
    virtual ~zCGameInfo()                                        zCall( 0x0044F840 );
    virtual void Init()                                          zCall( 0x0044F890 );
    virtual void Reset()                                         zCall( 0x0044F8A0 );
    virtual void SetName( zSTRING const& )                       zCall( 0x00423B20 );
    virtual zSTRING GetName() const                              zCall( 0x00423C60 );
    virtual int AddPlayer( zCPlayerInfo* )                       zCall( 0x0044F8B0 );
    virtual int RemPlayer( zCPlayerInfo* )                       zCall( 0x0044F8C0 );
    virtual zCPlayerInfo* GetPlayerByID( int )                   zCall( 0x0044F8D0 );
    virtual zCPlayerInfo* GetPlayerByVobID( unsigned long )      zCall( 0x0044F8E0 );
    virtual zCPlayerInfo* GetPlayerByNetAddress( zTNetAddress& ) zCall( 0x0044FC00 );
    virtual void Pack( zCBuffer&, unsigned char )                zCall( 0x0044F970 );
    virtual void Unpack( zCBuffer& )                             zCall( 0x0044FA10 );

    // user API
    #include "zCGameInfo.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZGAME_INFO_H__VER2__