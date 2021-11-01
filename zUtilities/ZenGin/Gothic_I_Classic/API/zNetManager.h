// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET_MANAGER_H__VER0__
#define __ZNET_MANAGER_H__VER0__

#include "zNetTypes.h"
#include "zNetMessage.h"
#include "zTools.h"

namespace Gothic_I_Classic {

  // sizeof 48h
  class zCNetManager : public zCObject {
  public:
    zCLASS_DECLARATION( zCNetManager )

    zCTimer timer;                       // sizeof 1Ch    offset 24h
    unsigned long timer_count_ping;      // sizeof 04h    offset 40h
    unsigned long timer_count_worldtime; // sizeof 04h    offset 44h

    void zCNetManager_OnInit()                                                                  zCall( 0x00456870 );
    int Temp_HandleNetMessage( zCNetMessage*&, zCWorld* )                                       zCall( 0x00456800 );
    zCNetManager()                                                                              zInit( zCNetManager_OnInit() );
    void SendPing()                                                                             zCall( 0x00456CC0 );
    void SendPingReply( zCPlayerInfo* )                                                         zCall( 0x00456D30 );
    void SendWorldTime()                                                                        zCall( 0x00456D70 );
    static zCObject* _CreateNewInstance()                                                       zCall( 0x00456670 );
    virtual zCClassDef* _GetClassDef() const                                                    zCall( 0x004567F0 );
    virtual ~zCNetManager()                                                                     zCall( 0x00456A20 );
    virtual void Process()                                                                      zCall( 0x00456A30 );
    virtual zCNetMessage* CreateNetMessage( unsigned short const&, zCObject* )                  zCall( 0x00456C20 );
    virtual int HandleNetMessage( zCNetMessage*, unsigned short const&, zCClassDef*, zCWorld* ) zCall( 0x00456B60 );
    virtual void ProcessMessages()                                                              zCall( 0x00456AE0 );

    // user API
    #include "zCNetManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZNET_MANAGER_H__VER0__