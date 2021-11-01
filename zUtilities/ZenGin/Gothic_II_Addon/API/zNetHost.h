// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET_HOST_H__VER3__
#define __ZNET_HOST_H__VER3__

#include "zNet.h"
#include "zBuffer.h"

namespace Gothic_II_Addon {

  // sizeof 44h
  class zCNetHost {
  public:
    unsigned char id;            // sizeof 01h    offset 04h
    zSTRING hostName;            // sizeof 14h    offset 08h
    zTNetAddress hostStreamAddr; // sizeof 10h    offset 1Ch
    zTNetAddress hostPacketAddr; // sizeof 10h    offset 2Ch
    int valid;                   // sizeof 04h    offset 3Ch
    void* stream_handle;         // sizeof 04h    offset 40h

    zCNetHost() {}
    void zCNetHost_OnInit( void* )                  zCall( 0x0045A650 );
    void zCNetHost_OnInit( zSTRING const& )         zCall( 0x0045A810 );
    void zCNetHost_OnInit( zTNetAddress const& )    zCall( 0x0045A9A0 );
    zSTRING GetReadableAddr()                       zCall( 0x00450F80 );
    int InitHost( zSTRING const& )                  zCall( 0x0045A380 );
    zCNetHost( void* a0 )                           zInit( zCNetHost_OnInit( a0 ));
    zCNetHost( zSTRING const& a0 )                  zInit( zCNetHost_OnInit( a0 ));
    zCNetHost( zTNetAddress const& a0 )             zInit( zCNetHost_OnInit( a0 ));
    void Init()                                     zCall( 0x0045AB30 );
    int InitHostForBroadcast()                      zCall( 0x0045AC30 );
    void InitHostAddr( zTNetAddress* const )        zCall( 0x0045ADA0 );
    void Pack( zCBuffer& )                          zCall( 0x0045B010 );
    void Unpack( zCBuffer& )                        zCall( 0x0045B080 );
    void PackToBuffer( zCBuffer& )                  zCall( 0x0045B3C0 );
    int HasAddress( zTNetAddress* )                 zCall( 0x0045B3F0 );
    zSTRING GetHostname() const                     zCall( 0x00467210 );
    static zCNetHost* CreateFromBuffer( zCBuffer& ) zCall( 0x0045B210 );
    virtual ~zCNetHost()                            zCall( 0x0045AFC0 );

    // static properties
    static unsigned char& iter;
    static zCNetHost*& localhost;

    // user API
    #include "zCNetHost.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZNET_HOST_H__VER3__