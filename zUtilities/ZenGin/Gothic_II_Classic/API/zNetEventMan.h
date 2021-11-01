// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET_EVENT_MAN_H__VER2__
#define __ZNET_EVENT_MAN_H__VER2__

#include "zEventMan.h"
#include "zNetTypes.h"

namespace Gothic_II_Classic {

  // sizeof 44h
  class zCNetEventManager : public zCEventManager {
  public:
    zCLASS_DECLARATION( zCNetEventManager )

    zCNetVobControl* netVobCtrl; // sizeof 04h    offset 40h

    void zCNetEventManager_OnInit()                                        zCall( 0x00457BA0 );
    void zCNetEventManager_OnInit( zCVob* )                                zCall( 0x00457BF0 );
    zCNetEventManager()                                                    zInit( zCNetEventManager_OnInit() );
    zCNetEventManager( zCVob* a0 )                                         zInit( zCNetEventManager_OnInit( a0 ));
    void Init()                                                            zCall( 0x00457C20 );
    static zCObject* _CreateNewInstance()                                  zCall( 0x00456C60 );
    static int HandleNetMessage( zCNetMessage*, unsigned short, zCWorld* ) zCall( 0x00456D20 );
    virtual zCClassDef* _GetClassDef() const                               zCall( 0x00456D10 );
    virtual void Archive( zCArchiver& )                                    zCall( 0x00459760 );
    virtual void Unarchive( zCArchiver& )                                  zCall( 0x00459790 );
    virtual ~zCNetEventManager()                                           zCall( 0x00457C10 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                      zCall( 0x00457C30 );
    virtual zCNetVobControl* GetNetVobControl( int )                       zCall( 0x00459810 );

    // user API
    #include "zCNetEventManager.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZNET_EVENT_MAN_H__VER2__