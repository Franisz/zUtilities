// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET__WIN32_H__VER2__
#define __ZNET__WIN32_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 10h
  struct zTNetAddress {
    unsigned short Protocol; // sizeof 02h    offset 00h
    union {
      // sizeof 08h
      struct zTNetAddressDummy0 {
        unsigned short Port; // sizeof 02h    offset 00h
        unsigned long IP;    // sizeof 04h    offset 04h
      };

      // sizeof 08h
      struct zTNetAddressDummy1 {
        unsigned char Net[4];  // sizeof 04h    offset 00h
        unsigned char Node[6]; // sizeof 06h    offset 04h
        unsigned short Socket; // sizeof 02h    offset 0Ah
      };

      zTNetAddressDummy0 INET;
      zTNetAddressDummy1 IPX;
    };

    zTNetAddress() {}

    // user API
    #include "zTNetAddress.inl"
  };

  // sizeof 08h
  struct zTNetBufferInfo {
    int inPackets; // sizeof 04h    offset 00h
    int inBytes;   // sizeof 04h    offset 04h

    zTNetBufferInfo() {}

    // user API
    #include "zTNetBufferInfo.inl"
  };

  // sizeof 18h
  struct zTNetPacket {
    zTNetAddress From;       // sizeof 10h    offset 00h
    unsigned long timestamp; // sizeof 04h    offset 10h
    unsigned long size;      // sizeof 04h    offset 14h
    unsigned char Data[];    // sizeof 04h    offset 18h

    zTNetPacket() {}

    // user API
    #include "zTNetPacket.inl"
  };

  // sizeof 10h
  struct zTNetTimeout {
    unsigned long getHostAddress; // sizeof 04h    offset 00h
    unsigned long getHostName;    // sizeof 04h    offset 04h
    unsigned long getService;     // sizeof 04h    offset 08h
    unsigned long Connect;        // sizeof 04h    offset 0Ch

    zTNetTimeout() {}

    // user API
    #include "zTNetTimeout.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZNET__WIN32_H__VER2__