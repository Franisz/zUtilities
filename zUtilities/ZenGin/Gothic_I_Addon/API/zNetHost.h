// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET_HOST_H__VER1__
#define __ZNET_HOST_H__VER1__

#include "zNet.h"
#include "zBuffer.h"

namespace Gothic_I_Addon {

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
    void zCNetHost_OnInit( void* )                  zCall( 0x0045C4C0 );
    void zCNetHost_OnInit( zSTRING const& )         zCall( 0x0045C680 );
    void zCNetHost_OnInit( zTNetAddress const& )    zCall( 0x0045C810 );
    zSTRING GetReadableAddr()                       zCall( 0x00452DE0 );
    int InitHost( zSTRING const& )                  zCall( 0x0045C160 );
    zCNetHost( void* a0 )                           zInit( zCNetHost_OnInit( a0 ));
    zCNetHost( zSTRING const& a0 )                  zInit( zCNetHost_OnInit( a0 ));
    zCNetHost( zTNetAddress const& a0 )             zInit( zCNetHost_OnInit( a0 ));
    void Init()                                     zCall( 0x0045C9A0 );
    int InitHostForBroadcast()                      zCall( 0x0045CAA0 );
    void InitHostAddr( zTNetAddress* const )        zCall( 0x0045CC40 );
    void Pack( zCBuffer& )                          zCall( 0x0045CEF0 );
    void Unpack( zCBuffer& )                        zCall( 0x0045CF60 );
    void PackToBuffer( zCBuffer& )                  zCall( 0x0045D2B0 );
    int HasAddress( zTNetAddress* )                 zCall( 0x0045D2E0 );
    zSTRING GetHostname() const                     zCall( 0x004695C0 );
    static zCNetHost* CreateFromBuffer( zCBuffer& ) zCall( 0x0045D0F0 );
    virtual ~zCNetHost()                            zCall( 0x0045CE90 );

    // static properties
    static unsigned char& iter;
    static zCNetHost*& localhost;

    // user API
    #include "zCNetHost.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZNET_HOST_H__VER1__