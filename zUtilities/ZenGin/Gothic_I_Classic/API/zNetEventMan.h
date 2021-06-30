// Supported with union (c) 2018 Union team

#ifndef __ZNET_EVENT_MAN_H__VER0__
#define __ZNET_EVENT_MAN_H__VER0__

#include "zEventMan.h"
#include "zNetTypes.h"

namespace Gothic_I_Classic {

  class zCNetEventManager : public zCEventManager {
  public:
    zCLASS_DECLARATION( zCNetEventManager )

    zCNetVobControl* netVobCtrl;

    void zCNetEventManager_OnInit()                                        zCall( 0x00453380 );
    void zCNetEventManager_OnInit( zCVob* )                                zCall( 0x004533D0 );
    zCNetEventManager()                                                    zInit( zCNetEventManager_OnInit() );
    zCNetEventManager( zCVob* a0 )                                         zInit( zCNetEventManager_OnInit( a0 ));
    void Init()                                                            zCall( 0x00453400 );
    static zCObject* _CreateNewInstance()                                  zCall( 0x00452570 );
    static int HandleNetMessage( zCNetMessage*, unsigned short, zCWorld* ) zCall( 0x00452640 );
    virtual zCClassDef* _GetClassDef() const                               zCall( 0x00452630 );
    virtual void Archive( zCArchiver& )                                    zCall( 0x00454E40 );
    virtual void Unarchive( zCArchiver& )                                  zCall( 0x00454E70 );
    virtual ~zCNetEventManager()                                           zCall( 0x004533F0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                      zCall( 0x00453410 );
    virtual zCNetVobControl* GetNetVobControl( int )                       zCall( 0x00454EF0 );

    // user API
    #include "zCNetEventManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZNET_EVENT_MAN_H__VER0__