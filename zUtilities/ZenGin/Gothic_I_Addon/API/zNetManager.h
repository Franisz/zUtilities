// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET_MANAGER_H__VER1__
#define __ZNET_MANAGER_H__VER1__

#include "zNetTypes.h"
#include "zNetMessage.h"

namespace Gothic_I_Addon {

  // sizeof 4Ch
  class zCNetManager : public zCObject {
  public:
    zCLASS_DECLARATION( zCNetManager )

    zCTimer timer;                       // sizeof 20h    offset 24h
    unsigned long timer_count_ping;      // sizeof 04h    offset 44h
    unsigned long timer_count_worldtime; // sizeof 04h    offset 48h

    void zCNetManager_OnInit()                                                                  zCall( 0x0045D810 );
    int Temp_HandleNetMessage( zCNetMessage*&, zCWorld* )                                       zCall( 0x0045D7A0 );
    zCNetManager()                                                                              zInit( zCNetManager_OnInit() );
    void SendPing()                                                                             zCall( 0x0045DC80 );
    void SendPingReply( zCPlayerInfo* )                                                         zCall( 0x0045DCF0 );
    void SendWorldTime()                                                                        zCall( 0x0045DD30 );
    static zCObject* _CreateNewInstance()                                                       zCall( 0x0045D610 );
    virtual zCClassDef* _GetClassDef() const                                                    zCall( 0x0045D790 );
    virtual ~zCNetManager()                                                                     zCall( 0x0045D9D0 );
    virtual void Process()                                                                      zCall( 0x0045D9E0 );
    virtual zCNetMessage* CreateNetMessage( unsigned short const&, zCObject* )                  zCall( 0x0045DBE0 );
    virtual int HandleNetMessage( zCNetMessage*, unsigned short const&, zCClassDef*, zCWorld* ) zCall( 0x0045DB20 );
    virtual void ProcessMessages()                                                              zCall( 0x0045DA90 );

    // user API
    #include "zCNetManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZNET_MANAGER_H__VER1__