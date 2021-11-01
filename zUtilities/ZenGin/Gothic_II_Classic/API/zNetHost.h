// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET_HOST_H__VER2__
#define __ZNET_HOST_H__VER2__

#include "zNet.h"
#include "zBuffer.h"

namespace Gothic_II_Classic {

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
    void zCNetHost_OnInit( void* )                  zCall( 0x00459F00 );
    void zCNetHost_OnInit( zSTRING const& )         zCall( 0x0045A0C0 );
    void zCNetHost_OnInit( zTNetAddress const& )    zCall( 0x0045A250 );
    zSTRING GetReadableAddr()                       zCall( 0x00450830 );
    int InitHost( zSTRING const& )                  zCall( 0x00459C30 );
    zCNetHost( void* a0 )                           zInit( zCNetHost_OnInit( a0 ));
    zCNetHost( zSTRING const& a0 )                  zInit( zCNetHost_OnInit( a0 ));
    zCNetHost( zTNetAddress const& a0 )             zInit( zCNetHost_OnInit( a0 ));
    void Init()                                     zCall( 0x0045A3E0 );
    int InitHostForBroadcast()                      zCall( 0x0045A4E0 );
    void InitHostAddr( zTNetAddress* const )        zCall( 0x0045A650 );
    void Pack( zCBuffer& )                          zCall( 0x0045A8C0 );
    void Unpack( zCBuffer& )                        zCall( 0x0045A930 );
    void PackToBuffer( zCBuffer& )                  zCall( 0x0045AC70 );
    int HasAddress( zTNetAddress* )                 zCall( 0x0045ACA0 );
    zSTRING GetHostname() const                     zCall( 0x004665E0 );
    static zCNetHost* CreateFromBuffer( zCBuffer& ) zCall( 0x0045AAC0 );
    virtual ~zCNetHost()                            zCall( 0x0045A870 );

    // static properties
    static unsigned char& iter;
    static zCNetHost*& localhost;

    // user API
    #include "zCNetHost.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZNET_HOST_H__VER2__