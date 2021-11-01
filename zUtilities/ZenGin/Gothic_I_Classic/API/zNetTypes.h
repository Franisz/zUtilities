// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET_TYPES_H__VER0__
#define __ZNET_TYPES_H__VER0__

#include "zNet_Win32.h"
#include "zDisk.h"

namespace Gothic_I_Classic {
  const int zNET_MAX_TYPES                      = 10;
  const int zNET_MAX_HOSTS                      = 5;
  const int zNET_MAX_HOSTID                     = 255;
  const int zNET_MAX_GROUPS                     = 20;
  const int zNET_MAX_PRIORITY                   = 4;
  const int zNET_MAX_STREAMSIZE                 = 20480;
  const int zNET_FAULT_ID                       = 255;
  const int zNET_LOCALHOST_ID                   = 0;
  const unsigned short int zNET_PORT_UDP_LISTEN = 7207;
  const unsigned short int zNET_PORT_TCP_LISTEN = 7208;
  const unsigned short int zNET_PORT_IPX_LISTEN = 0;
  const unsigned short int zNET_PORT_SPX_LISTEN = 0;
  const int zNETID_EVENT                        = 1000;
  const int zNETID_EVENT_END                    = 1999;
  const int zNETID_VOBCTRL                      = 2000;
  const int zNETID_VOBCTRL_END                  = 2999;
  const int NET_TARGET_ALL                      = 0;

  enum {
    zERR_NET_NO_NET = 6001,
    zERR_NET_NO_INIT,
    zERR_NET_NO_PROVIDER,
    zERR_NET_NO_MESSAGE,
    zERR_NET_RECV,
    zERR_NET_SEND,
    zERR_NET_READ,
    zERR_NET_MISC,
    zERR_NET_CONNECT,
    zERR_NET_NO_HOST,
    zERR_NET_NO_VOB,
    zERR_NET_NO_AIC,
    zERR_NET_NO_VISUAL,
    zERR_NET_DENIED
  };

  enum TNetMessage {
    SEND,
    RECV
  };

  enum TNetPort {
    NET_SERVICE_PORT,
    NET_DGRAM_PORT,
    NET_STREAM_PORT
  };

  enum TNetState {
    NET_NONE,
    NET_DISCONNECTED,
    NET_CONNECTED
  };

  enum TNetMode {
    NET_SINGLEPLAYER,
    NET_MULTIPLAYER
  };

} // namespace Gothic_I_Classic

#endif // __ZNET_TYPES_H__VER0__