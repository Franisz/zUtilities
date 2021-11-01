// Supported with union (c) 2018-2021 Union team

#ifndef __ZPLAYER_INFO_H__VER3__
#define __ZPLAYER_INFO_H__VER3__

#include "zBuffer.h"
#include "zNet_Win32.h"
#include "zGameInfo.h"

namespace Gothic_II_Addon {

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

    void zCPlayerInfo_OnInit()                          zCall( 0x00467820 );
    zSTRING GetName() const                             zCall( 0x00459E60 );
    zCPlayerInfo()                                      zInit( zCPlayerInfo_OnInit() );
    zCPlayerInfo* CreateDistinctPlayer()                zCall( 0x00467CD0 );
    unsigned char GetID() const                         zCall( 0x00468500 );
    void PackToBuffer( zCBuffer& )                      zCall( 0x00468530 );
    void SetActive()                                    zCall( 0x00468550 );
    int IsActive()                                      zCall( 0x00468820 );
    void StorePlayerVobAsScript()                       zCall( 0x00468840 );
    zCVob* CreatePlayerVobFromScript()                  zCall( 0x00468930 );
    zCBuffer* GetPlayerVobScript()                      zCall( 0x004689D0 );
    void SetPlayerVobScript( zCBuffer* )                zCall( 0x004689E0 );
    unsigned long SetPingStart()                        zCall( 0x00468B30 );
    unsigned long SetPingEnd()                          zCall( 0x00468B50 );
    static zCPlayerInfo* CreateFromBuffer( zCBuffer& )  zCall( 0x00468510 );
    static zCPlayerInfo* GetActivePlayer()              zCall( 0x00468540 );
    virtual ~zCPlayerInfo()                             zCall( 0x004679C0 );
    virtual void Init( zSTRING const&, zSTRING const& ) zCall( 0x00468100 );
    virtual void Init( zSTRING const&, void* )          zCall( 0x00467F60 );
    virtual void SetName( zSTRING const& )              zCall( 0x00436400 );
    virtual void SetPlayerVob( zCVob* )                 zCall( 0x00468A90 );
    virtual void Reset()                                zCall( 0x00468830 );
    virtual void Deactivate( int )                      zCall( 0x00468AD0 );
    virtual int IsDeactivated() const                   zCall( 0x00468AF0 );
    virtual void SetReady( int )                        zCall( 0x00468B00 );
    virtual int IsReady() const                         zCall( 0x00468B20 );
    virtual void Pack( zCBuffer& )                      zCall( 0x00468280 );
    virtual void Unpack( zCBuffer& )                    zCall( 0x00468320 );

    // static properties
    static zCArray<int>& free_ids;
    static unsigned char& next_id;
    static zCPlayerInfo*& activePlayer;

    // user API
    #include "zCPlayerInfo.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZPLAYER_INFO_H__VER3__