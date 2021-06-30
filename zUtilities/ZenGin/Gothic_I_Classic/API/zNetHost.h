// Supported with union (c) 2018 Union team

#ifndef __ZNET_HOST_H__VER0__
#define __ZNET_HOST_H__VER0__

#include "zNet.h"
#include "zBuffer.h"

namespace Gothic_I_Classic {

  class zCNetHost {
  public:
    unsigned char id;
    zSTRING hostName;
    zTNetAddress hostStreamAddr;
    zTNetAddress hostPacketAddr;
    int valid;
    void* stream_handle;

    zCNetHost() {}
    void zCNetHost_OnInit( void* )                  zCall( 0x004555B0 );
    void zCNetHost_OnInit( zSTRING const& )         zCall( 0x00455770 );
    void zCNetHost_OnInit( zTNetAddress const& )    zCall( 0x00455900 );
    zSTRING GetReadableAddr()                       zCall( 0x0044C7E0 );
    int InitHost( zSTRING const& )                  zCall( 0x004552E0 );
    zCNetHost( void* a0 )                           zInit( zCNetHost_OnInit( a0 ));
    zCNetHost( zSTRING const& a0 )                  zInit( zCNetHost_OnInit( a0 ));
    zCNetHost( zTNetAddress const& a0 )             zInit( zCNetHost_OnInit( a0 ));
    void Init()                                     zCall( 0x00455A90 );
    int InitHostForBroadcast()                      zCall( 0x00455B90 );
    void InitHostAddr( zTNetAddress* const )        zCall( 0x00455D00 );
    void Pack( zCBuffer& )                          zCall( 0x00455F70 );
    void Unpack( zCBuffer& )                        zCall( 0x00455FE0 );
    void PackToBuffer( zCBuffer& )                  zCall( 0x00456330 );
    int HasAddress( zTNetAddress* )                 zCall( 0x00456360 );
    zSTRING GetHostname() const                     zCall( 0x00461BA0 );
    static zCNetHost* CreateFromBuffer( zCBuffer& ) zCall( 0x00456170 );
    virtual ~zCNetHost()                            zCall( 0x00455F20 );

    // static properties
    static unsigned char& iter;
    static zCNetHost*& localhost;

    // user API
    #include "zCNetHost.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZNET_HOST_H__VER0__