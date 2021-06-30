// Supported with union (c) 2018 Union team

#ifndef __ZNET_SESSION_H__VER1__
#define __ZNET_SESSION_H__VER1__

#include "zNetHost.h"

namespace Gothic_I_Addon {

  class zCNetSession {
  public:
    unsigned short protocol;
    zTNetAddress listenPacketAddress;
    zTNetAddress listenStreamAddress;
    int valid;

    zCNetSession() {}
    void zCNetSession_OnInit( unsigned short ) zCall( 0x0045F0A0 );
    zCNetSession( unsigned short a0 )          zInit( zCNetSession_OnInit( a0 ));
    void Reset()                               zCall( 0x0045F140 );
    virtual ~zCNetSession()                    zCall( 0x0045F160 );

    // user API
    #include "zCNetSession.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZNET_SESSION_H__VER1__