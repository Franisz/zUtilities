// Supported with union (c) 2018 Union team

#ifndef __ZNET__WIN32_H__VER2__
#define __ZNET__WIN32_H__VER2__

namespace Gothic_II_Classic {

  struct zTNetAddress {
    unsigned short Protocol;
    union {
      struct zTNetAddressDummy0 {
        unsigned short Port;
        unsigned long IP;
      };

      struct zTNetAddressDummy1 {
        unsigned char Net[4];
        unsigned char Node[6];
        unsigned short Socket;
      };

      zTNetAddressDummy0 INET;
      zTNetAddressDummy1 IPX;
    };

    zTNetAddress() {}

    // user API
    #include "zTNetAddress.inl"
  };

  struct zTNetBufferInfo {
    int inPackets;
    int inBytes;

    zTNetBufferInfo() {}

    // user API
    #include "zTNetBufferInfo.inl"
  };

  struct zTNetPacket {
    zTNetAddress From;
    unsigned long timestamp;
    unsigned long size;
    unsigned char Data[];

    zTNetPacket() {}

    // user API
    #include "zTNetPacket.inl"
  };

  struct zTNetTimeout {
    unsigned long getHostAddress;
    unsigned long getHostName;
    unsigned long getService;
    unsigned long Connect;

    zTNetTimeout() {}

    // user API
    #include "zTNetTimeout.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZNET__WIN32_H__VER2__