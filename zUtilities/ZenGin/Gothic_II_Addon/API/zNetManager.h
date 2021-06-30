// Supported with union (c) 2018 Union team

#ifndef __ZNET_MANAGER_H__VER3__
#define __ZNET_MANAGER_H__VER3__

#include "zNetTypes.h"
#include "zNetMessage.h"
#include "zTools.h"

namespace Gothic_II_Addon {

  class zCNetManager : public zCObject {
  public:
    zCLASS_DECLARATION( zCNetManager )

    zCTimer timer;
    unsigned long timer_count_ping;
    unsigned long timer_count_worldtime;

    void zCNetManager_OnInit()                                                                  zCall( 0x0045B920 );
    int Temp_HandleNetMessage( zCNetMessage*&, zCWorld* )                                       zCall( 0x0045B8B0 );
    zCNetManager()                                                                              zInit( zCNetManager_OnInit() );
    void SendPing()                                                                             zCall( 0x0045BD60 );
    void SendPingReply( zCPlayerInfo* )                                                         zCall( 0x0045BDD0 );
    void SendWorldTime()                                                                        zCall( 0x0045BE10 );
    static zCObject* _CreateNewInstance()                                                       zCall( 0x0045B700 );
    virtual zCClassDef* _GetClassDef() const                                                    zCall( 0x0045B8A0 );
    virtual ~zCNetManager()                                                                     zCall( 0x0045BAD0 );
    virtual void Process()                                                                      zCall( 0x0045BAE0 );
    virtual zCNetMessage* CreateNetMessage( unsigned short const&, zCObject* )                  zCall( 0x0045BCD0 );
    virtual int HandleNetMessage( zCNetMessage*, unsigned short const&, zCClassDef*, zCWorld* ) zCall( 0x0045BC10 );
    virtual void ProcessMessages()                                                              zCall( 0x0045BB90 );

    // user API
    #include "zCNetManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZNET_MANAGER_H__VER3__