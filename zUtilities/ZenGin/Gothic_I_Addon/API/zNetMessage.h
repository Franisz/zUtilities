// Supported with union (c) 2018 Union team

#ifndef __ZNET_MESSAGE_H__VER1__
#define __ZNET_MESSAGE_H__VER1__

#include "zNetTypes.h"
#include "zNetHost.h"
#include "zBuffer.h"
#include "zPlayerInfo.h"
#include "zPlayerGroup.h"

namespace Gothic_I_Addon {
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
    void zCNetMessage_OnInit( zTNetMessageHeader& )                 zCall( 0x0045DFB0 );
    void zCNetMessage_OnInit( unsigned long const&, unsigned long ) zCall( 0x0045E080 );
    void zCNetMessage_OnInit( zTNetPacket* )                        zCall( 0x0045E1C0 );
    zCNetMessage( zTNetMessageHeader& a0 )                          zInit( zCNetMessage_OnInit( a0 ));
    zCNetMessage( unsigned long const& a0, unsigned long a1 )       zInit( zCNetMessage_OnInit( a0, a1 ));
    void CopyFrom( zCNetMessage* )                                  zCall( 0x0045E170 );
    zCNetMessage( zTNetPacket* a0 )                                 zInit( zCNetMessage_OnInit( a0 ));
    void Init()                                                     zCall( 0x0045E380 );
    void Send()                                                     zCall( 0x0045E420 );
    void SetTimestamp( unsigned char )                              zCall( 0x0045E560 );
    unsigned char GetTimestamp()                                    zCall( 0x0045E580 );
    void SetTarget( zCPlayerInfo* )                                 zCall( 0x0045E590 );
    void SetTarget( zCPlayerGroup* )                                zCall( 0x0045E5C0 );
    void GetTarget( zCPlayerInfo*&, zCPlayerGroup*& )               zCall( 0x0045E5F0 );
    unsigned long Get( void*, unsigned long const& )                zCall( 0x0045E610 );
    void Add( void*, unsigned long )                                zCall( 0x0045E720 );
    void AddCursorPtr( unsigned long )                              zCall( 0x0045E840 );
    void Add( zSTRING const& )                                      zCall( 0x0045E850 );
    void Get( zSTRING& )                                            zCall( 0x0045E8B0 );
    int IsStream()                                                  zCall( 0x0045EA40 );
    void SetStream( int )                                           zCall( 0x0045EA50 );
    void SetFileMessage( zFILE*, zFILE* )                           zCall( 0x0045EA60 );
    zFILE* GetFile( zFILE*& )                                       zCall( 0x0045EB00 );
    int IsFileMessage()                                             zCall( 0x0045EB40 );
    int IsMultiMessage()                                            zCall( 0x0045EB60 );
    void LogMessage( zFILE*, zSTRING const& )                       zCall( 0x0045EB80 );
    void SetLog( int )                                              zCall( 0x0045EF00 );
    zTNetMessageHeader* GetHeader()                                 zCall( 0x0045EF10 );
    unsigned char GetHeaderSize()                                   zCall( 0x0045EF20 );
    zCBuffer* GetBuffer()                                           zCall( 0x0045EF30 );
    unsigned char* GetCursorPtr()                                   zCall( 0x0045EF40 );
    unsigned char* GetPtr()                                         zCall( 0x0045EF50 );
    unsigned char* GetDataPtr()                                     zCall( 0x0045EF60 );
    void ResetCursorPtr()                                           zCall( 0x0045EF70 );
    void SetMode( zTBufferMode )                                    zCall( 0x0045EF90 );
    unsigned long GetSize()                                         zCall( 0x0045EFA0 );
    unsigned long GetDataSize()                                     zCall( 0x0045EFB0 );
    unsigned long GetRestSize()                                     zCall( 0x0045EFC0 );
    unsigned long GetID()                                           zCall( 0x0045EFD0 );
    unsigned char GetSenderID()                                     zCall( 0x0045EFE0 );
    unsigned char GetFlags()                                        zCall( 0x0045EFF0 );
    bool HasError() const                                           zCall( 0x0045F000 );
    virtual ~zCNetMessage()                                         zCall( 0x0045E3A0 );

    // user API
    #include "zCNetMessage.inl"
  };

  class zCNetMessageQueue {
  public:
    zQUEUE<zCNetMessage> queue;

    void zCNetMessageQueue_OnInit() zCall( 0x00452280 );
    zCNetMessageQueue()             zInit( zCNetMessageQueue_OnInit() );
    ~zCNetMessageQueue()            zCall( 0x004522E0 );

    // user API
    #include "zCNetMessageQueue.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZNET_MESSAGE_H__VER1__