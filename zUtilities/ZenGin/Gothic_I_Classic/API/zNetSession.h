// Supported with union (c) 2018 Union team

#ifndef __ZNET_SESSION_H__VER0__
#define __ZNET_SESSION_H__VER0__

#include "zNetHost.h"

namespace Gothic_I_Classic {

  class zCNetSession {
  public:
    unsigned short protocol;
    zTNetAddress listenPacketAddress;
    zTNetAddress listenStreamAddress;
    int valid;

    zCNetSession() {}
    void zCNetSession_OnInit( unsigned short ) zCall( 0x00457FE0 );
    zCNetSession( unsigned short a0 )          zInit( zCNetSession_OnInit( a0 ));
    void Reset()                               zCall( 0x00458080 );
    virtual ~zCNetSession()                    zCall( 0x004580A0 );

    // user API
    #include "zCNetSession.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZNET_SESSION_H__VER0__