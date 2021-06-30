// Supported with union (c) 2018 Union team

#ifndef __ZNET_H__VER1__
#define __ZNET_H__VER1__

#include "zNet_Win32.h"
#include "zNetTypes.h"
#include "zNetSession.h"

namespace Gothic_I_Addon {
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

    void zCNetStatistics_OnInit()    zCall( 0x00454E20 );
    zCNetStatistics()                zInit( zCNetStatistics_OnInit() );
    void AddLostRecv( unsigned int ) zCall( 0x00454EA0 );
    void AddLostSend( unsigned int ) zCall( 0x00454ED0 );
    void AddPacketSend( double )     zCall( 0x00454F00 );
    void AddPacketRecv( double )     zCall( 0x00454F20 );
    void Start()                     zCall( 0x00454F40 );
    void Stop()                      zCall( 0x00455080 );
    void Print()                     zCall( 0x00455190 );
    void Reset()                     zCall( 0x00456510 );
    double GetSeconds()              zCall( 0x00456530 );
    virtual ~zCNetStatistics()       zCall( 0x00454E90 );

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
    void zCNet_OnInit( unsigned short )                                                            zCall( 0x00452380 );
    zCNet( unsigned short a0 )                                                                     zInit( zCNet_OnInit( a0 ));
    int NetReset()                                                                                 zCall( 0x00452580 );
    int NetReset( int )                                                                            zCall( 0x00452730 );
    int StreamListen( int( __cdecl* )( void* ))                                                    zCall( 0x00452760 );
    int Send( zCNetMessage*& )                                                                     zCall( 0x004527C0 );
    unsigned long DGramWriteMessage( zCNetMessage*& )                                              zCall( 0x00452970 );
    unsigned long DGramWriteToPlayer( zCNetMessage*, zCPlayerInfo* )                               zCall( 0x00452A10 );
    unsigned long DGramWriteToGroup( zCNetMessage*, zCPlayerGroup* )                               zCall( 0x00452E60 );
    int DGramRead( zCNetMessage*& )                                                                zCall( 0x00452ED0 );
    unsigned long StreamRead( zCNetMessage*&, zCPlayerInfo* )                                      zCall( 0x00452FB0 );
    unsigned long StreamReadFromPlayer( void*, unsigned long, zCPlayerInfo*, zTNetStreamReadMode ) zCall( 0x004531B0 );
    unsigned long StreamWriteMessage( zCNetMessage*& )                                             zCall( 0x00453210 );
    unsigned long StreamWriteToPlayer( void*, unsigned long, zCPlayerInfo* )                       zCall( 0x004533C0 );
    unsigned long StreamWriteToGroup( void*, unsigned long, zCPlayerGroup* )                       zCall( 0x004533F0 );
    unsigned long StreamWriteFile( zCNetMessage*& )                                                zCall( 0x00453460 );
    unsigned long StreamReadFile( zCNetMessage*, zCPlayerInfo* )                                   zCall( 0x00453910 );
    int MsgGetFromStream( zCPlayerInfo*, zCNetMessage*& )                                          zCall( 0x00454190 );
    int MsgPut( zCNetMessage* )                                                                    zCall( 0x004542B0 );
    int MsgGet( zCNetMessage*&, unsigned char )                                                    zCall( 0x00454510 );
    int MsgSendFromQueue()                                                                         zCall( 0x00454590 );
    int MsgRecvToQueue()                                                                           zCall( 0x00454640 );
    int HandleReceiving()                                                                          zCall( 0x00454690 );
    int HandleSending()                                                                            zCall( 0x00454700 );
    void Handle()                                                                                  zCall( 0x00454940 );
    int StreamConnect( zCNetHost*& )                                                               zCall( 0x00454A90 );
    int StreamDisconnect( zCNetHost*& )                                                            zCall( 0x00454AC0 );
    void LockQueues( int )                                                                         zCall( 0x00454AF0 );
    int WaitForStreamMessage( zCPlayerInfo*, zCNetMessage*& )                                      zCall( 0x00454B00 );
    zTNetAddress* GetLocalAddress()                                                                zCall( 0x00454D90 );
    void EnableNetwork( bool )                                                                     zCall( 0x00454DA0 );
    void ApplyTimestamp( zCNetMessage*, unsigned char )                                            zCall( 0x00454DB0 );
    int CheckTimestamp( zCNetMessage*, unsigned char )                                             zCall( 0x00454DF0 );
    virtual ~zCNet()                                                                               zCall( 0x00452520 );

    // user API
    #include "zCNet.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZNET_H__VER1__