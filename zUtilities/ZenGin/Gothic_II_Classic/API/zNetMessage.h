// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET_MESSAGE_H__VER2__
#define __ZNET_MESSAGE_H__VER2__

#include "zNetTypes.h"
#include "zNetHost.h"
#include "zBuffer.h"
#include "zPlayerInfo.h"
#include "zPlayerGroup.h"

namespace Gothic_II_Classic {
  const unsigned char zNET_MSGFLAG_FILE     = 1 << 0;
  const unsigned char zNET_MSGFLAG_LOG      = 1 << 1;
  const unsigned char zNET_MSGFLAG_MULTIMSG = 1 << 2;
  const unsigned char zNET_MAX_SENDERIDS    = 255;

#pragma pack( push, 4 )
  // sizeof 10h
  struct zTNetMessageHeader {
    unsigned long id;        // sizeof 04h    offset 00h
    unsigned char senderID;  // sizeof 01h    offset 04h
    unsigned long datasize;  // sizeof 04h    offset 08h
    unsigned char timestamp; // sizeof 01h    offset 0Ch
    unsigned char flags;     // sizeof 01h    offset 0Dh

    zTNetMessageHeader() {}

    // user API
    #include "zTNetMessageHeader.inl"
  };
#pragma pack( pop )

  // sizeof 1Ch
  class zCNetMessage {
  public:
    zCBuffer* buffer;           // sizeof 04h    offset 04h
    int isStream;               // sizeof 04h    offset 08h
    zFILE* file;                // sizeof 04h    offset 0Ch
    zFILE* remote_file;         // sizeof 04h    offset 10h
    zCPlayerInfo* targetPlayer; // sizeof 04h    offset 14h
    zCPlayerGroup* targetGroup; // sizeof 04h    offset 18h

    zCNetMessage() {}
    void zCNetMessage_OnInit( zTNetMessageHeader& )                 zCall( 0x0045B920 );
    void zCNetMessage_OnInit( unsigned long const&, unsigned long ) zCall( 0x0045B9F0 );
    void zCNetMessage_OnInit( zTNetPacket* )                        zCall( 0x0045BB20 );
    zCNetMessage( zTNetMessageHeader& a0 )                          zInit( zCNetMessage_OnInit( a0 ));
    zCNetMessage( unsigned long const& a0, unsigned long a1 )       zInit( zCNetMessage_OnInit( a0, a1 ));
    void CopyFrom( zCNetMessage* )                                  zCall( 0x0045BAD0 );
    zCNetMessage( zTNetPacket* a0 )                                 zInit( zCNetMessage_OnInit( a0 ));
    void Init()                                                     zCall( 0x0045BCB0 );
    void Send()                                                     zCall( 0x0045BD50 );
    void SetTimestamp( unsigned char )                              zCall( 0x0045BE80 );
    unsigned char GetTimestamp()                                    zCall( 0x0045BEA0 );
    void SetTarget( zCPlayerInfo* )                                 zCall( 0x0045BEB0 );
    void SetTarget( zCPlayerGroup* )                                zCall( 0x0045BEE0 );
    void GetTarget( zCPlayerInfo*&, zCPlayerGroup*& )               zCall( 0x0045BF10 );
    unsigned long Get( void*, unsigned long const& )                zCall( 0x0045BF30 );
    void Add( void*, unsigned long )                                zCall( 0x0045C030 );
    void AddCursorPtr( unsigned long )                              zCall( 0x0045C140 );
    void Add( zSTRING const& )                                      zCall( 0x0045C150 );
    void Get( zSTRING& )                                            zCall( 0x0045C1B0 );
    int IsStream()                                                  zCall( 0x0045C330 );
    void SetStream( int )                                           zCall( 0x0045C340 );
    void SetFileMessage( zFILE*, zFILE* )                           zCall( 0x0045C350 );
    zFILE* GetFile( zFILE*& )                                       zCall( 0x0045C3E0 );
    int IsFileMessage()                                             zCall( 0x0045C420 );
    int IsMultiMessage()                                            zCall( 0x0045C440 );
    void LogMessage( zFILE*, zSTRING const& )                       zCall( 0x0045C460 );
    void SetLog( int )                                              zCall( 0x0045C810 );
    zTNetMessageHeader* GetHeader()                                 zCall( 0x0045C820 );
    unsigned char GetHeaderSize()                                   zCall( 0x0045C830 );
    zCBuffer* GetBuffer()                                           zCall( 0x0045C840 );
    unsigned char* GetCursorPtr()                                   zCall( 0x0045C850 );
    unsigned char* GetPtr()                                         zCall( 0x0045C860 );
    unsigned char* GetDataPtr()                                     zCall( 0x0045C870 );
    void ResetCursorPtr()                                           zCall( 0x0045C880 );
    void SetMode( zTBufferMode )                                    zCall( 0x0045C8A0 );
    unsigned long GetSize()                                         zCall( 0x0045C8B0 );
    unsigned long GetDataSize()                                     zCall( 0x0045C8C0 );
    unsigned long GetRestSize()                                     zCall( 0x0045C8D0 );
    unsigned long GetID()                                           zCall( 0x0045C8E0 );
    unsigned char GetSenderID()                                     zCall( 0x0045C8F0 );
    unsigned char GetFlags()                                        zCall( 0x0045C900 );
    bool HasError() const                                           zCall( 0x0045C910 );
    virtual ~zCNetMessage()                                         zCall( 0x0045BCD0 );

    // user API
    #include "zCNetMessage.inl"
  };

  // sizeof 0Ch
  class zCNetMessageQueue {
  public:
    zQUEUE<zCNetMessage> queue; // sizeof 0Ch    offset 00h

    void zCNetMessageQueue_OnInit() zCall( 0x0044FD40 );
    zCNetMessageQueue()             zInit( zCNetMessageQueue_OnInit() );
    ~zCNetMessageQueue()            zCall( 0x0044FD90 );

    // user API
    #include "zCNetMessageQueue.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZNET_MESSAGE_H__VER2__