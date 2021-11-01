// Supported with union (c) 2018-2021 Union team

#ifndef __OCS_MANAGER_H__VER1__
#define __OCS_MANAGER_H__VER1__

#include "zCCsManager.h"

namespace Gothic_I_Addon {

  // sizeof 70h
  class oCCSManager : public zCCSManager {
  public:
    zCLASS_DECLARATION( oCCSManager )

    void oCCSManager_OnInit()                                           zCall( 0x004016F0 );
    oCCSManager()                                                       zInit( oCCSManager_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00401630 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x004025B0 );
    virtual ~oCCSManager()                                              zCall( 0x00402650 );
    virtual zCEventMessage* CreateMessage( int )                        zCall( 0x00402730 );
    virtual zCEventMessage* CreateOuMessage()                           zCall( 0x00402720 );
    virtual zCCSPlayer* CreateCutscenePlayer( zCWorld* )                zCall( 0x00402660 );
    virtual zCCSProps* CreateProperties()                               zCall( 0x00402FB0 );

    // user API
    #include "oCCSManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OCS_MANAGER_H__VER1__