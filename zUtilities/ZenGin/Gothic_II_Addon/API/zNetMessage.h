// Supported with union (c) 2018 Union team

#ifndef __ZNET_MESSAGE_H__VER3__
#define __ZNET_MESSAGE_H__VER3__

#include "zNetTypes.h"
#include "zNetHost.h"
#include "zBuffer.h"
#include "zPlayerInfo.h"
#include "zPlayerGroup.h"

namespace Gothic_II_Addon {
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
    void zCNetMessage_OnInit( zTNetMessageHeader& )                 zCall( 0x0045C070 );
    void zCNetMessage_OnInit( unsigned long const&, unsigned long ) zCall( 0x0045C140 );
    void zCNetMessage_OnInit( zTNetPacket* )                        zCall( 0x0045C270 );
    zCNetMessage( zTNetMessageHeader& a0 )                          zInit( zCNetMessage_OnInit( a0 ));
    zCNetMessage( unsigned long const& a0, unsigned long a1 )       zInit( zCNetMessage_OnInit( a0, a1 ));
    void CopyFrom( zCNetMessage* )                                  zCall( 0x0045C220 );
    zCNetMessage( zTNetPacket* a0 )                                 zInit( zCNetMessage_OnInit( a0 ));
    void Init()                                                     zCall( 0x0045C400 );
    void Send()                                                     zCall( 0x0045C4A0 );
    void SetTimestamp( unsigned char )                              zCall( 0x0045C5D0 );
    unsigned char GetTimestamp()                                    zCall( 0x0045C5F0 );
    void SetTarget( zCPlayerInfo* )                                 zCall( 0x0045C600 );
    void SetTarget( zCPlayerGroup* )                                zCall( 0x0045C630 );
    void GetTarget( zCPlayerInfo*&, zCPlayerGroup*& )               zCall( 0x0045C660 );
    unsigned long Get( void*, unsigned long const& )                zCall( 0x0045C680 );
    void Add( void*, unsigned long )                                zCall( 0x0045C780 );
    void AddCursorPtr( unsigned long )                              zCall( 0x0045C890 );
    void Add( zSTRING const& )                                      zCall( 0x0045C8A0 );
    void Get( zSTRING& )                                            zCall( 0x0045C900 );
    int IsStream()                                                  zCall( 0x0045CA80 );
    void SetStream( int )                                           zCall( 0x0045CA90 );
    void SetFileMessage( zFILE*, zFILE* )                           zCall( 0x0045CAA0 );
    zFILE* GetFile( zFILE*& )                                       zCall( 0x0045CB30 );
    int IsFileMessage()                                             zCall( 0x0045CB70 );
    int IsMultiMessage()                                            zCall( 0x0045CB90 );
    void LogMessage( zFILE*, zSTRING const& )                       zCall( 0x0045CBB0 );
    void SetLog( int )                                              zCall( 0x0045CF60 );
    zTNetMessageHeader* GetHeader()                                 zCall( 0x0045CF70 );
    unsigned char GetHeaderSize()                                   zCall( 0x0045CF80 );
    zCBuffer* GetBuffer()                                           zCall( 0x0045CF90 );
    unsigned char* GetCursorPtr()                                   zCall( 0x0045CFA0 );
    unsigned char* GetPtr()                                         zCall( 0x0045CFB0 );
    unsigned char* GetDataPtr()                                     zCall( 0x0045CFC0 );
    void ResetCursorPtr()                                           zCall( 0x0045CFD0 );
    void SetMode( zTBufferMode )                                    zCall( 0x0045CFF0 );
    unsigned long GetSize()                                         zCall( 0x0045D000 );
    unsigned long GetDataSize()                                     zCall( 0x0045D010 );
    unsigned long GetRestSize()                                     zCall( 0x0045D020 );
    unsigned long GetID()                                           zCall( 0x0045D030 );
    unsigned char GetSenderID()                                     zCall( 0x0045D040 );
    unsigned char GetFlags()                                        zCall( 0x0045D050 );
    bool HasError() const                                           zCall( 0x0045D060 );
    virtual ~zCNetMessage()                                         zCall( 0x0045C420 );

    // user API
    #include "zCNetMessage.inl"
  };

  class zCNetMessageQueue {
  public:
    zQUEUE<zCNetMessage> queue;

    void zCNetMessageQueue_OnInit() zCall( 0x00450490 );
    zCNetMessageQueue()             zInit( zCNetMessageQueue_OnInit() );
    ~zCNetMessageQueue()            zCall( 0x004504E0 );

    // user API
    #include "zCNetMessageQueue.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZNET_MESSAGE_H__VER3__