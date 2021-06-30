// Supported with union (c) 2018 Union team

#ifndef __ZNET_H__VER3__
#define __ZNET_H__VER3__

#include "zNet_Win32.h"
#include "zNetTypes.h"
#include "zNetSession.h"
#include "zTools.h"

namespace Gothic_II_Addon {
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

    void zCNetStatistics_OnInit()    zCall( 0x00452F10 );
    zCNetStatistics()                zInit( zCNetStatistics_OnInit() );
    void AddLostRecv( unsigned int ) zCall( 0x00452F90 );
    void AddLostSend( unsigned int ) zCall( 0x00452FC0 );
    void AddPacketSend( double )     zCall( 0x00452FF0 );
    void AddPacketRecv( double )     zCall( 0x00453010 );
    void Start()                     zCall( 0x00453030 );
    void Stop()                      zCall( 0x00453170 );
    void Print()                     zCall( 0x00453280 );
    void Reset()                     zCall( 0x004547D0 );
    double GetSeconds()              zCall( 0x004547E0 );
    virtual ~zCNetStatistics()       zCall( 0x00452F80 );

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
    void zCNet_OnInit( unsigned short )                                                            zCall( 0x00450580 );
    zCNet( unsigned short a0 )                                                                     zInit( zCNet_OnInit( a0 ));
    int NetReset()                                                                                 zCall( 0x00450760 );
    int NetReset( int )                                                                            zCall( 0x00450900 );
    int StreamListen( int( __cdecl* )( void* ))                                                    zCall( 0x00450930 );
    int Send( zCNetMessage*& )                                                                     zCall( 0x00450990 );
    unsigned long DGramWriteMessage( zCNetMessage*& )                                              zCall( 0x00450B40 );
    unsigned long DGramWriteToPlayer( zCNetMessage*, zCPlayerInfo* )                               zCall( 0x00450BE0 );
    unsigned long DGramWriteToGroup( zCNetMessage*, zCPlayerGroup* )                               zCall( 0x00451000 );
    int DGramRead( zCNetMessage*& )                                                                zCall( 0x00451070 );
    unsigned long StreamRead( zCNetMessage*&, zCPlayerInfo* )                                      zCall( 0x00451140 );
    unsigned long StreamReadFromPlayer( void*, unsigned long, zCPlayerInfo*, zTNetStreamReadMode ) zCall( 0x00451320 );
    unsigned long StreamWriteMessage( zCNetMessage*& )                                             zCall( 0x00451390 );
    unsigned long StreamWriteToPlayer( void*, unsigned long, zCPlayerInfo* )                       zCall( 0x00451540 );
    unsigned long StreamWriteToGroup( void*, unsigned long, zCPlayerGroup* )                       zCall( 0x00451570 );
    unsigned long StreamWriteFile( zCNetMessage*& )                                                zCall( 0x004515E0 );
    unsigned long StreamReadFile( zCNetMessage*, zCPlayerInfo* )                                   zCall( 0x00451AA0 );
    int MsgGetFromStream( zCPlayerInfo*, zCNetMessage*& )                                          zCall( 0x004522D0 );
    int MsgPut( zCNetMessage* )                                                                    zCall( 0x004523D0 );
    int MsgGet( zCNetMessage*&, unsigned char )                                                    zCall( 0x00452630 );
    int MsgSendFromQueue()                                                                         zCall( 0x004526B0 );
    int MsgRecvToQueue()                                                                           zCall( 0x00452760 );
    int HandleReceiving()                                                                          zCall( 0x004527B0 );
    int HandleSending()                                                                            zCall( 0x00452820 );
    void Handle()                                                                                  zCall( 0x00452A50 );
    int StreamConnect( zCNetHost*& )                                                               zCall( 0x00452BA0 );
    int StreamDisconnect( zCNetHost*& )                                                            zCall( 0x00452BD0 );
    void LockQueues( int )                                                                         zCall( 0x00452C00 );
    int WaitForStreamMessage( zCPlayerInfo*, zCNetMessage*& )                                      zCall( 0x00452C10 );
    zTNetAddress* GetLocalAddress()                                                                zCall( 0x00452E70 );
    void EnableNetwork( bool )                                                                     zCall( 0x00452E80 );
    void ApplyTimestamp( zCNetMessage*, unsigned char )                                            zCall( 0x00452E90 );
    int CheckTimestamp( zCNetMessage*, unsigned char )                                             zCall( 0x00452EE0 );
    virtual ~zCNet()                                                                               zCall( 0x00450700 );

    // user API
    #include "zCNet.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZNET_H__VER3__