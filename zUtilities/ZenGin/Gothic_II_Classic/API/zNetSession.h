// Supported with union (c) 2018 Union team

#ifndef __ZNET_SESSION_H__VER2__
#define __ZNET_SESSION_H__VER2__

#include "zNetHost.h"

namespace Gothic_II_Classic {

  class zCNetSession {
  public:
    unsigned short protocol;
    zTNetAddress listenPacketAddress;
    zTNetAddress listenStreamAddress;
    int valid;

    zCNetSession() {}
    void zCNetSession_OnInit( unsigned short ) zCall( 0x0045C9B0 );
    zCNetSession( unsigned short a0 )          zInit( zCNetSession_OnInit( a0 ));
    void Reset()                               zCall( 0x0045CA50 );
    virtual ~zCNetSession()                    zCall( 0x0045CA70 );

    // user API
    #include "zCNetSession.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZNET_SESSION_H__VER2__