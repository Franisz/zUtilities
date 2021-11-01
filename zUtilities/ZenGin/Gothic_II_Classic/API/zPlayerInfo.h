// Supported with union (c) 2018-2021 Union team

#ifndef __ZPLAYER_INFO_H__VER2__
#define __ZPLAYER_INFO_H__VER2__

#include "zBuffer.h"
#include "zNet_Win32.h"
#include "zGameInfo.h"

namespace Gothic_II_Classic {

  // sizeof 3Ch
  class zCPlayerInfo {
  public:
    zCVob* hostVob;                // sizeof 04h    offset 04h
    zCNetHost* netHost;            // sizeof 04h    offset 08h
    zCBuffer* scriptBuffer;        // sizeof 04h    offset 0Ch
    zCWorldInfo* worldInfo;        // sizeof 04h    offset 10h
    zSTRING name;                  // sizeof 14h    offset 14h
    unsigned long pingTime;        // sizeof 04h    offset 28h
    unsigned long pingTimeStart;   // sizeof 04h    offset 2Ch
    unsigned long pingLost;        // sizeof 04h    offset 30h
    group {
      unsigned char id       : 8;  // sizeof 08h    offset bit
      int ready              : 1;  // sizeof 01h    offset bit
      int deactivated        : 1;  // sizeof 01h    offset bit
      unsigned long reserved : 22; // sizeof 16h    offset bit
    };

    void zCPlayerInfo_OnInit()                          zCall( 0x00466BF0 );
    zSTRING GetName() const                             zCall( 0x00459710 );
    zCPlayerInfo()                                      zInit( zCPlayerInfo_OnInit() );
    zCPlayerInfo* CreateDistinctPlayer()                zCall( 0x004670A0 );
    unsigned char GetID() const                         zCall( 0x004678D0 );
    void PackToBuffer( zCBuffer& )                      zCall( 0x00467900 );
    void SetActive()                                    zCall( 0x00467920 );
    int IsActive()                                      zCall( 0x00467BF0 );
    void StorePlayerVobAsScript()                       zCall( 0x00467C10 );
    zCVob* CreatePlayerVobFromScript()                  zCall( 0x00467D00 );
    zCBuffer* GetPlayerVobScript()                      zCall( 0x00467DA0 );
    void SetPlayerVobScript( zCBuffer* )                zCall( 0x00467DB0 );
    unsigned long SetPingStart()                        zCall( 0x00467F00 );
    unsigned long SetPingEnd()                          zCall( 0x00467F20 );
    static zCPlayerInfo* CreateFromBuffer( zCBuffer& )  zCall( 0x004678E0 );
    static zCPlayerInfo* GetActivePlayer()              zCall( 0x00467910 );
    virtual ~zCPlayerInfo()                             zCall( 0x00466D90 );
    virtual void Init( zSTRING const&, zSTRING const& ) zCall( 0x004674D0 );
    virtual void Init( zSTRING const&, void* )          zCall( 0x00467330 );
    virtual void SetName( zSTRING const& )              zCall( 0x00435F00 );
    virtual void SetPlayerVob( zCVob* )                 zCall( 0x00467E60 );
    virtual void Reset()                                zCall( 0x00467C00 );
    virtual void Deactivate( int )                      zCall( 0x00467EA0 );
    virtual int IsDeactivated() const                   zCall( 0x00467EC0 );
    virtual void SetReady( int )                        zCall( 0x00467ED0 );
    virtual int IsReady() const                         zCall( 0x00467EF0 );
    virtual void Pack( zCBuffer& )                      zCall( 0x00467650 );
    virtual void Unpack( zCBuffer& )                    zCall( 0x004676F0 );

    // static properties
    static zCArray<int>& free_ids;
    static unsigned char& next_id;
    static zCPlayerInfo*& activePlayer;

    // user API
    #include "zCPlayerInfo.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZPLAYER_INFO_H__VER2__