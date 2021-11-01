// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET_H__VER0__
#define __ZNET_H__VER0__

#include "zNet_Win32.h"
#include "zNetTypes.h"
#include "zNetSession.h"
#include "zTools.h"

namespace Gothic_I_Classic {
  const int zNET_FLAG_INIT    = 1;
  const int zNET_FLAG_CONNECT = 2;

  enum zTNetStreamReadMode {
    zNET_READ_BLOCK,
    zNET_READ_STREAM
  };

  // sizeof 10h
  struct zTNetStatistics {
    double bytes;   // sizeof 08h    offset 00h
    double packets; // sizeof 08h    offset 08h

    zTNetStatistics() {}

    // user API
    #include "zTNetStatistics.inl"
  };

  // sizeof 60h
  class zCNetStatistics {
  public:
    zTNetStatistics sent;      // sizeof 10h    offset 08h
    zTNetStatistics recv;      // sizeof 10h    offset 18h
    zTNetStatistics lost_recv; // sizeof 10h    offset 28h
    zTNetStatistics lost_sent; // sizeof 10h    offset 38h
    double seconds;            // sizeof 08h    offset 48h
    int started;               // sizeof 04h    offset 50h
    time_t start_time;         // sizeof 08h    offset 58h

    void zCNetStatistics_OnInit()    zCall( 0x0044E6F0 );
    zCNetStatistics()                zInit( zCNetStatistics_OnInit() );
    void AddLostRecv( unsigned int ) zCall( 0x0044E770 );
    void AddLostSend( unsigned int ) zCall( 0x0044E7A0 );
    void AddPacketSend( double )     zCall( 0x0044E7D0 );
    void AddPacketRecv( double )     zCall( 0x0044E7F0 );
    void Start()                     zCall( 0x0044E810 );
    void Stop()                      zCall( 0x0044E950 );
    void Print()                     zCall( 0x0044EA60 );
    void Reset()                     zCall( 0x0044FC00 );
    double GetSeconds()              zCall( 0x0044FC10 );
    virtual ~zCNetStatistics()       zCall( 0x0044E760 );

    // user API
    #include "zCNetStatistics.inl"
  };

  // sizeof 80h
  class zCNet {
  public:
    zCNetSession* session;      // sizeof 04h    offset 08h
    bool enabled;               // sizeof 01h    offset 0Ch
    zCNetStatistics statistics; // sizeof 60h    offset 10h
    int error;                  // sizeof 04h    offset 70h
    int sendCount;              // sizeof 04h    offset 74h
    int recvCount;              // sizeof 04h    offset 78h

    zCNet() {}
    void zCNet_OnInit( unsigned short )                                                            zCall( 0x0044BE10 );
    zCNet( unsigned short a0 )                                                                     zInit( zCNet_OnInit( a0 ));
    int NetReset()                                                                                 zCall( 0x0044BFF0 );
    int NetReset( int )                                                                            zCall( 0x0044C190 );
    int StreamListen( int( __cdecl* )( void* ))                                                    zCall( 0x0044C1C0 );
    int Send( zCNetMessage*& )                                                                     zCall( 0x0044C220 );
    unsigned long DGramWriteMessage( zCNetMessage*& )                                              zCall( 0x0044C3D0 );
    unsigned long DGramWriteToPlayer( zCNetMessage*, zCPlayerInfo* )                               zCall( 0x0044C470 );
    unsigned long DGramWriteToGroup( zCNetMessage*, zCPlayerGroup* )                               zCall( 0x0044C860 );
    int DGramRead( zCNetMessage*& )                                                                zCall( 0x0044C8D0 );
    unsigned long StreamRead( zCNetMessage*&, zCPlayerInfo* )                                      zCall( 0x0044C9B0 );
    unsigned long StreamReadFromPlayer( void*, unsigned long, zCPlayerInfo*, zTNetStreamReadMode ) zCall( 0x0044CBA0 );
    unsigned long StreamWriteMessage( zCNetMessage*& )                                             zCall( 0x0044CC10 );
    unsigned long StreamWriteToPlayer( void*, unsigned long, zCPlayerInfo* )                       zCall( 0x0044CDC0 );
    unsigned long StreamWriteToGroup( void*, unsigned long, zCPlayerGroup* )                       zCall( 0x0044CDF0 );
    unsigned long StreamWriteFile( zCNetMessage*& )                                                zCall( 0x0044CE60 );
    unsigned long StreamReadFile( zCNetMessage*, zCPlayerInfo* )                                   zCall( 0x0044D2D0 );
    int MsgGetFromStream( zCPlayerInfo*, zCNetMessage*& )                                          zCall( 0x0044DAB0 );
    int MsgPut( zCNetMessage* )                                                                    zCall( 0x0044DBB0 );
    int MsgGet( zCNetMessage*&, unsigned char )                                                    zCall( 0x0044DE10 );
    int MsgSendFromQueue()                                                                         zCall( 0x0044DE90 );
    int MsgRecvToQueue()                                                                           zCall( 0x0044DF40 );
    int HandleReceiving()                                                                          zCall( 0x0044DF90 );
    int HandleSending()                                                                            zCall( 0x0044E000 );
    void Handle()                                                                                  zCall( 0x0044E230 );
    int StreamConnect( zCNetHost*& )                                                               zCall( 0x0044E380 );
    int StreamDisconnect( zCNetHost*& )                                                            zCall( 0x0044E3B0 );
    void LockQueues( int )                                                                         zCall( 0x0044E3E0 );
    int WaitForStreamMessage( zCPlayerInfo*, zCNetMessage*& )                                      zCall( 0x0044E3F0 );
    zTNetAddress* GetLocalAddress()                                                                zCall( 0x0044E650 );
    void EnableNetwork( bool )                                                                     zCall( 0x0044E660 );
    void ApplyTimestamp( zCNetMessage*, unsigned char )                                            zCall( 0x0044E670 );
    int CheckTimestamp( zCNetMessage*, unsigned char )                                             zCall( 0x0044E6C0 );
    virtual ~zCNet()                                                                               zCall( 0x0044BF90 );

    // user API
    #include "zCNet.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZNET_H__VER0__