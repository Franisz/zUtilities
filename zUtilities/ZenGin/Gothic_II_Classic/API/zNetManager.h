// Supported with union (c) 2018 Union team

#ifndef __ZNET_MANAGER_H__VER2__
#define __ZNET_MANAGER_H__VER2__

#include "zNetTypes.h"
#include "zNetMessage.h"

namespace Gothic_II_Classic {

  class zCNetManager : public zCObject {
  public:
    zCLASS_DECLARATION( zCNetManager )

    zCTimer timer;
    unsigned long timer_count_ping;
    unsigned long timer_count_worldtime;

    void zCNetManager_OnInit()                                                                  zCall( 0x0045B1D0 );
    int Temp_HandleNetMessage( zCNetMessage*&, zCWorld* )                                       zCall( 0x0045B160 );
    zCNetManager()                                                                              zInit( zCNetManager_OnInit() );
    void SendPing()                                                                             zCall( 0x0045B610 );
    void SendPingReply( zCPlayerInfo* )                                                         zCall( 0x0045B680 );
    void SendWorldTime()                                                                        zCall( 0x0045B6C0 );
    static zCObject* _CreateNewInstance()                                                       zCall( 0x0045AFB0 );
    virtual zCClassDef* _GetClassDef() const                                                    zCall( 0x0045B150 );
    virtual ~zCNetManager()                                                                     zCall( 0x0045B380 );
    virtual void Process()                                                                      zCall( 0x0045B390 );
    virtual zCNetMessage* CreateNetMessage( unsigned short const&, zCObject* )                  zCall( 0x0045B580 );
    virtual int HandleNetMessage( zCNetMessage*, unsigned short const&, zCClassDef*, zCWorld* ) zCall( 0x0045B4C0 );
    virtual void ProcessMessages()                                                              zCall( 0x0045B440 );

    // user API
    #include "zCNetManager.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZNET_MANAGER_H__VER2__