// Supported with union (c) 2018 Union team

#ifndef __ZNET_H__VER2__
#define __ZNET_H__VER2__

#include "zNet_Win32.h"
#include "zNetTypes.h"
#include "zNetSession.h"

namespace Gothic_II_Classic {
  const int zNET_FLAG_INIT    = 1;
  const int zNET_FLAG_CONNECT = 2;

  enum zTNetStreamReadMode {
    zNET_READ_BLOCK,
    zNET_READ_STREAM
  };

  struct zTNetStatistics {
    double bytes;
    double packets;

    zTNetStatistics() {}

    // user API
    #include "zTNetStatistics.inl"
  };

  class zCNetStatistics {
  public:
    zTNetStatistics sent;
    zTNetStatistics recv;
    zTNetStatistics lost_recv;
    zTNetStatistics lost_sent;
    double seconds;
    int started;
    time_t start_time;

    void zCNetStatistics_OnInit()    zCall( 0x004527C0 );
    zCNetStatistics()                zInit( zCNetStatistics_OnInit() );
    void AddLostRecv( unsigned int ) zCall( 0x00452840 );
    void AddLostSend( unsigned int ) zCall( 0x00452870 );
    void AddPacketSend( double )     zCall( 0x004528A0 );
    void AddPacketRecv( double )     zCall( 0x004528C0 );
    void Start()                     zCall( 0x004528E0 );
    void Stop()                      zCall( 0x00452A20 );
    void Print()                     zCall( 0x00452B30 );
    void Reset()                     zCall( 0x00454080 );
    double GetSeconds()              zCall( 0x00454090 );
    virtual ~zCNetStatistics()       zCall( 0x00452830 );

    // user API
    #include "zCNetStatistics.inl"
  };

  class zCNet {
  public:
    zCNetSession* session;
    bool enabled;
    zCNetStatistics statistics;
    int error;
    int sendCount;
    int recvCount;

    zCNet() {}
    void zCNet_OnInit( unsigned short )                                                            zCall( 0x0044FE30 );
    zCNet( unsigned short a0 )                                                                     zInit( zCNet_OnInit( a0 ));
    int NetReset()                                                                                 zCall( 0x00450010 );
    int NetReset( int )                                                                            zCall( 0x004501B0 );
    int StreamListen( int( __cdecl* )( void* ))                                                    zCall( 0x004501E0 );
    int Send( zCNetMessage*& )                                                                     zCall( 0x00450240 );
    unsigned long DGramWriteMessage( zCNetMessage*& )                                              zCall( 0x004503F0 );
    unsigned long DGramWriteToPlayer( zCNetMessage*, zCPlayerInfo* )                               zCall( 0x00450490 );
    unsigned long DGramWriteToGroup( zCNetMessage*, zCPlayerGroup* )                               zCall( 0x004508B0 );
    int DGramRead( zCNetMessage*& )                                                                zCall( 0x00450920 );
    unsigned long StreamRead( zCNetMessage*&, zCPlayerInfo* )                                      zCall( 0x004509F0 );
    unsigned long StreamReadFromPlayer( void*, unsigned long, zCPlayerInfo*, zTNetStreamReadMode ) zCall( 0x00450BD0 );
    unsigned long StreamWriteMessage( zCNetMessage*& )                                             zCall( 0x00450C40 );
    unsigned long StreamWriteToPlayer( void*, unsigned long, zCPlayerInfo* )                       zCall( 0x00450DF0 );
    unsigned long StreamWriteToGroup( void*, unsigned long, zCPlayerGroup* )                       zCall( 0x00450E20 );
    unsigned long StreamWriteFile( zCNetMessage*& )                                                zCall( 0x00450E90 );
    unsigned long StreamReadFile( zCNetMessage*, zCPlayerInfo* )                                   zCall( 0x00451350 );
    int MsgGetFromStream( zCPlayerInfo*, zCNetMessage*& )                                          zCall( 0x00451B80 );
    int MsgPut( zCNetMessage* )                                                                    zCall( 0x00451C80 );
    int MsgGet( zCNetMessage*&, unsigned char )                                                    zCall( 0x00451EE0 );
    int MsgSendFromQueue()                                                                         zCall( 0x00451F60 );
    int MsgRecvToQueue()                                                                           zCall( 0x00452010 );
    int HandleReceiving()                                                                          zCall( 0x00452060 );
    int HandleSending()                                                                            zCall( 0x004520D0 );
    void Handle()                                                                                  zCall( 0x00452300 );
    int StreamConnect( zCNetHost*& )                                                               zCall( 0x00452450 );
    int StreamDisconnect( zCNetHost*& )                                                            zCall( 0x00452480 );
    void LockQueues( int )                                                                         zCall( 0x004524B0 );
    int WaitForStreamMessage( zCPlayerInfo*, zCNetMessage*& )                                      zCall( 0x004524C0 );
    zTNetAddress* GetLocalAddress()                                                                zCall( 0x00452720 );
    void EnableNetwork( bool )                                                                     zCall( 0x00452730 );
    void ApplyTimestamp( zCNetMessage*, unsigned char )                                            zCall( 0x00452740 );
    int CheckTimestamp( zCNetMessage*, unsigned char )                                             zCall( 0x00452790 );
    virtual ~zCNet()                                                                               zCall( 0x0044FFB0 );

    // user API
    #include "zCNet.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZNET_H__VER2__