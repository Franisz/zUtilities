// Supported with union (c) 2018 Union team

#ifndef __ZPLAYER_INFO_H__VER0__
#define __ZPLAYER_INFO_H__VER0__

#include "zBuffer.h"
#include "zNet_Win32.h"
#include "zGameInfo.h"

namespace Gothic_I_Classic {

  class zCPlayerInfo {
  public:
    zCVob* hostVob;
    zCNetHost* netHost;
    zCBuffer* scriptBuffer;
    zCWorldInfo* worldInfo;
    zSTRING name;
    unsigned long pingTime;
    unsigned long pingTimeStart;
    unsigned long pingLost;
    group {
      unsigned char id       : 8;
      int ready              : 1;
      int deactivated        : 1;
      unsigned long reserved : 22;
    };

    void zCPlayerInfo_OnInit()                          zCall( 0x004621D0 );
    zSTRING GetName() const                             zCall( 0x00454DF0 );
    zCPlayerInfo()                                      zInit( zCPlayerInfo_OnInit() );
    zCPlayerInfo* CreateDistinctPlayer()                zCall( 0x00462650 );
    unsigned char GetID() const                         zCall( 0x00462E60 );
    void PackToBuffer( zCBuffer& )                      zCall( 0x00462E90 );
    void SetActive()                                    zCall( 0x00462EB0 );
    int IsActive()                                      zCall( 0x00463120 );
    void StorePlayerVobAsScript()                       zCall( 0x00463140 );
    zCVob* CreatePlayerVobFromScript()                  zCall( 0x00463240 );
    zCBuffer* GetPlayerVobScript()                      zCall( 0x004632E0 );
    void SetPlayerVobScript( zCBuffer* )                zCall( 0x004632F0 );
    unsigned long SetPingStart()                        zCall( 0x00463450 );
    unsigned long SetPingEnd()                          zCall( 0x00463470 );
    static zCPlayerInfo* CreateFromBuffer( zCBuffer& )  zCall( 0x00462E70 );
    static zCPlayerInfo* GetActivePlayer()              zCall( 0x00462EA0 );
    virtual ~zCPlayerInfo()                             zCall( 0x00462370 );
    virtual void Init( zSTRING const&, zSTRING const& ) zCall( 0x00462A50 );
    virtual void Init( zSTRING const&, void* )          zCall( 0x004628A0 );
    virtual void SetName( zSTRING const& )              zCall( 0x004335A0 );
    virtual void SetPlayerVob( zCVob* )                 zCall( 0x004633B0 );
    virtual void Reset()                                zCall( 0x00463130 );
    virtual void Deactivate( int )                      zCall( 0x004633F0 );
    virtual int IsDeactivated() const                   zCall( 0x00463410 );
    virtual void SetReady( int )                        zCall( 0x00463420 );
    virtual int IsReady() const                         zCall( 0x00463440 );
    virtual void Pack( zCBuffer& )                      zCall( 0x00462BE0 );
    virtual void Unpack( zCBuffer& )                    zCall( 0x00462C80 );

    // static properties
    static zCArray<int>& free_ids;
    static unsigned char& next_id;
    static zCPlayerInfo*& activePlayer;

    // user API
    #include "zCPlayerInfo.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZPLAYER_INFO_H__VER0__