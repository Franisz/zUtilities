// Supported with union (c) 2018 Union team

#ifndef __ZNET_MESSAGE_H__VER0__
#define __ZNET_MESSAGE_H__VER0__

#include "zNetTypes.h"
#include "zNetHost.h"
#include "zBuffer.h"
#include "zPlayerInfo.h"
#include "zPlayerGroup.h"

namespace Gothic_I_Classic {
  const unsigned char zNET_MSGFLAG_FILE     = 1 << 0;
  const unsigned char zNET_MSGFLAG_LOG      = 1 << 1;
  const unsigned char zNET_MSGFLAG_MULTIMSG = 1 << 2;
  const unsigned char zNET_MAX_SENDERIDS    = 255;

#pragma pack( push, 4 )
  struct zTNetMessageHeader {
    unsigned long id;
    unsigned char senderID;
    unsigned long datasize;
    unsigned char timestamp;
    unsigned char flags;

    zTNetMessageHeader() {}

    // user API
    #include "zTNetMessageHeader.inl"
  };
#pragma pack( pop )

  class zCNetMessage {
  public:
    zCBuffer* buffer;
    int isStream;
    zFILE* file;
    zFILE* remote_file;
    zCPlayerInfo* targetPlayer;
    zCPlayerGroup* targetGroup;

    zCNetMessage() {}
    void zCNetMessage_OnInit( zTNetMessageHeader& )                 zCall( 0x00456FD0 );
    void zCNetMessage_OnInit( unsigned long const&, unsigned long ) zCall( 0x004570A0 );
    void zCNetMessage_OnInit( zTNetPacket* )                        zCall( 0x004571E0 );
    zCNetMessage( zTNetMessageHeader& a0 )                          zInit( zCNetMessage_OnInit( a0 ));
    zCNetMessage( unsigned long const& a0, unsigned long a1 )       zInit( zCNetMessage_OnInit( a0, a1 ));
    void CopyFrom( zCNetMessage* )                                  zCall( 0x00457190 );
    zCNetMessage( zTNetPacket* a0 )                                 zInit( zCNetMessage_OnInit( a0 ));
    void Init()                                                     zCall( 0x00457380 );
    void Send()                                                     zCall( 0x00457420 );
    void SetTimestamp( unsigned char )                              zCall( 0x00457550 );
    unsigned char GetTimestamp()                                    zCall( 0x00457570 );
    void SetTarget( zCPlayerInfo* )                                 zCall( 0x00457580 );
    void SetTarget( zCPlayerGroup* )                                zCall( 0x004575B0 );
    void GetTarget( zCPlayerInfo*&, zCPlayerGroup*& )               zCall( 0x004575E0 );
    unsigned long Get( void*, unsigned long const& )                zCall( 0x00457600 );
    void Add( void*, unsigned long )                                zCall( 0x00457700 );
    void AddCursorPtr( unsigned long )                              zCall( 0x00457810 );
    void Add( zSTRING const& )                                      zCall( 0x00457820 );
    void Get( zSTRING& )                                            zCall( 0x00457880 );
    int IsStream()                                                  zCall( 0x00457A00 );
    void SetStream( int )                                           zCall( 0x00457A10 );
    void SetFileMessage( zFILE*, zFILE* )                           zCall( 0x00457A20 );
    zFILE* GetFile( zFILE*& )                                       zCall( 0x00457AB0 );
    int IsFileMessage()                                             zCall( 0x00457AF0 );
    int IsMultiMessage()                                            zCall( 0x00457B10 );
    void LogMessage( zFILE*, zSTRING const& )                       zCall( 0x00457B30 );
    void SetLog( int )                                              zCall( 0x00457E40 );
    zTNetMessageHeader* GetHeader()                                 zCall( 0x00457E50 );
    unsigned char GetHeaderSize()                                   zCall( 0x00457E60 );
    zCBuffer* GetBuffer()                                           zCall( 0x00457E70 );
    unsigned char* GetCursorPtr()                                   zCall( 0x00457E80 );
    unsigned char* GetPtr()                                         zCall( 0x00457E90 );
    unsigned char* GetDataPtr()                                     zCall( 0x00457EA0 );
    void ResetCursorPtr()                                           zCall( 0x00457EB0 );
    void SetMode( zTBufferMode )                                    zCall( 0x00457ED0 );
    unsigned long GetSize()                                         zCall( 0x00457EE0 );
    unsigned long GetDataSize()                                     zCall( 0x00457EF0 );
    unsigned long GetRestSize()                                     zCall( 0x00457F00 );
    unsigned long GetID()                                           zCall( 0x00457F10 );
    unsigned char GetSenderID()                                     zCall( 0x00457F20 );
    unsigned char GetFlags()                                        zCall( 0x00457F30 );
    bool HasError() const                                           zCall( 0x00457F40 );
    virtual ~zCNetMessage()                                         zCall( 0x004573A0 );

    // user API
    #include "zCNetMessage.inl"
  };

  class zCNetMessageQueue {
  public:
    zQUEUE<zCNetMessage> queue;

    void zCNetMessageQueue_OnInit() zCall( 0x0044BD10 );
    zCNetMessageQueue()             zInit( zCNetMessageQueue_OnInit() );
    ~zCNetMessageQueue()            zCall( 0x0044BD70 );

    // user API
    #include "zCNetMessageQueue.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZNET_MESSAGE_H__VER0__