// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET_EVENT_MAN_H__VER3__
#define __ZNET_EVENT_MAN_H__VER3__

#include "zEventMan.h"
#include "zNetTypes.h"

namespace Gothic_II_Addon {

  // sizeof 44h
  class zCNetEventManager : public zCEventManager {
  public:
    zCLASS_DECLARATION( zCNetEventManager )

    zCNetVobControl* netVobCtrl; // sizeof 04h    offset 40h

    void zCNetEventManager_OnInit()                                        zCall( 0x004582F0 );
    void zCNetEventManager_OnInit( zCVob* )                                zCall( 0x00458340 );
    zCNetEventManager()                                                    zInit( zCNetEventManager_OnInit() );
    zCNetEventManager( zCVob* a0 )                                         zInit( zCNetEventManager_OnInit( a0 ));
    void Init()                                                            zCall( 0x00458370 );
    static zCObject* _CreateNewInstance()                                  zCall( 0x004573B0 );
    static int HandleNetMessage( zCNetMessage*, unsigned short, zCWorld* ) zCall( 0x00457470 );
    virtual zCClassDef* _GetClassDef() const                               zCall( 0x00457460 );
    virtual void Archive( zCArchiver& )                                    zCall( 0x00459EB0 );
    virtual void Unarchive( zCArchiver& )                                  zCall( 0x00459EE0 );
    virtual ~zCNetEventManager()                                           zCall( 0x00458360 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                      zCall( 0x00458380 );
    virtual zCNetVobControl* GetNetVobControl( int )                       zCall( 0x00459F60 );

    // user API
    #include "zCNetEventManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZNET_EVENT_MAN_H__VER3__