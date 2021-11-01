// Supported with union (c) 2018-2021 Union team

#ifndef __ZPLAYER_INFO_H__VER1__
#define __ZPLAYER_INFO_H__VER1__

#include "zBuffer.h"
#include "zNet_Win32.h"
#include "zGameInfo.h"

namespace Gothic_I_Addon {

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

    void zCPlayerInfo_OnInit()                          zCall( 0x00469BC0 );
    zSTRING GetName() const                             zCall( 0x0045BC00 );
    zCPlayerInfo()                                      zInit( zCPlayerInfo_OnInit() );
    zCPlayerInfo* CreateDistinctPlayer()                zCall( 0x0046A090 );
    unsigned char GetID() const                         zCall( 0x0046A910 );
    void PackToBuffer( zCBuffer& )                      zCall( 0x0046A940 );
    void SetActive()                                    zCall( 0x0046A960 );
    int IsActive()                                      zCall( 0x0046AC20 );
    void StorePlayerVobAsScript()                       zCall( 0x0046AC40 );
    zCVob* CreatePlayerVobFromScript()                  zCall( 0x0046AD50 );
    zCBuffer* GetPlayerVobScript()                      zCall( 0x0046ADF0 );
    void SetPlayerVobScript( zCBuffer* )                zCall( 0x0046AE00 );
    unsigned long SetPingStart()                        zCall( 0x0046AF60 );
    unsigned long SetPingEnd()                          zCall( 0x0046AF80 );
    static zCPlayerInfo* CreateFromBuffer( zCBuffer& )  zCall( 0x0046A920 );
    static zCPlayerInfo* GetActivePlayer()              zCall( 0x0046A950 );
    virtual ~zCPlayerInfo()                             zCall( 0x00469D60 );
    virtual void Init( zSTRING const&, zSTRING const& ) zCall( 0x0046A4E0 );
    virtual void Init( zSTRING const&, void* )          zCall( 0x0046A330 );
    virtual void SetName( zSTRING const& )              zCall( 0x004374B0 );
    virtual void SetPlayerVob( zCVob* )                 zCall( 0x0046AEC0 );
    virtual void Reset()                                zCall( 0x0046AC30 );
    virtual void Deactivate( int )                      zCall( 0x0046AF00 );
    virtual int IsDeactivated() const                   zCall( 0x0046AF20 );
    virtual void SetReady( int )                        zCall( 0x0046AF30 );
    virtual int IsReady() const                         zCall( 0x0046AF50 );
    virtual void Pack( zCBuffer& )                      zCall( 0x0046A670 );
    virtual void Unpack( zCBuffer& )                    zCall( 0x0046A720 );

    // static properties
    static zCArray<int>& free_ids;
    static unsigned char& next_id;
    static zCPlayerInfo*& activePlayer;

    // user API
    #include "zCPlayerInfo.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZPLAYER_INFO_H__VER1__