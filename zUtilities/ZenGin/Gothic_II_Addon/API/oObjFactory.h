// Supported with union (c) 2018-2021 Union team

#ifndef __OOBJ_FACTORY_H__VER3__
#define __OOBJ_FACTORY_H__VER3__

#include "zWaynet.h"

namespace Gothic_II_Addon {

  // sizeof 24h
  class oCObjectFactory : public zCObjectFactory {
  public:
    zCLASS_DECLARATION( oCObjectFactory )

    oCObjectFactory() {}
    static zCObject* _CreateNewInstance()                zCall( 0x0076FA00 );
    virtual zCClassDef* _GetClassDef() const             zCall( 0x00426A70 );
    virtual ~oCObjectFactory()                           zCall( 0x00426C70 );
    virtual zCEventManager* CreateEventManager( zCVob* ) zCall( 0x0076FB20 );
    virtual zCCSManager* CreateCSManager()               zCall( 0x0076FB80 );
    virtual zCGameInfo* CreateGameInfo()                 zCall( 0x0076FBE0 );
    virtual zCPlayerInfo* CreatePlayerInfo()             zCall( 0x0076FC40 );
    virtual zCWorld* CreateWorld()                       zCall( 0x0076FCA0 );
    virtual zCWaypoint* CreateWaypoint()                 zCall( 0x0076FEA0 );
    virtual zCWay* CreateWay()                           zCall( 0x0076FF00 );
    virtual oCNpc* CreateNpc( int )                      zCall( 0x0076FD20 );
    virtual oCItem* CreateItem( int )                    zCall( 0x0076FDE0 );

    // user API
    #include "oCObjectFactory.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OOBJ_FACTORY_H__VER3__