// Supported with union (c) 2018 Union team

#ifndef __ZNET_SESSION_H__VER3__
#define __ZNET_SESSION_H__VER3__

#include "zNetHost.h"

namespace Gothic_II_Addon {

  class zCNetSession {
  public:
    unsigned short protocol;
    zTNetAddress listenPacketAddress;
    zTNetAddress listenStreamAddress;
    int valid;

    zCNetSession() {}
    void zCNetSession_OnInit( unsigned short ) zCall( 0x0045D100 );
    zCNetSession( unsigned short a0 )          zInit( zCNetSession_OnInit( a0 ));
    void Reset()                               zCall( 0x0045D1A0 );
    virtual ~zCNetSession()                    zCall( 0x0045D1C0 );

    // user API
    #include "zCNetSession.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZNET_SESSION_H__VER3__