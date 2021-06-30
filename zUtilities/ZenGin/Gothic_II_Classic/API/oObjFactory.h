// Supported with union (c) 2018 Union team

#ifndef __OOBJ_FACTORY_H__VER2__
#define __OOBJ_FACTORY_H__VER2__

namespace Gothic_II_Classic {

  class oCObjectFactory : public zCObjectFactory {
  public:
    zCLASS_DECLARATION( oCObjectFactory )

    oCObjectFactory() {}
    static zCObject* _CreateNewInstance()                zCall( 0x00710490 );
    virtual zCClassDef* _GetClassDef() const             zCall( 0x00426730 );
    virtual ~oCObjectFactory()                           zCall( 0x00426930 );
    virtual zCEventManager* CreateEventManager( zCVob* ) zCall( 0x007105B0 );
    virtual zCCSManager* CreateCSManager()               zCall( 0x00710610 );
    virtual zCGameInfo* CreateGameInfo()                 zCall( 0x00710670 );
    virtual zCPlayerInfo* CreatePlayerInfo()             zCall( 0x007106D0 );
    virtual zCWorld* CreateWorld()                       zCall( 0x00710730 );
    virtual zCWaypoint* CreateWaypoint()                 zCall( 0x00710930 );
    virtual zCWay* CreateWay()                           zCall( 0x00710990 );
    virtual oCNpc* CreateNpc( int )                      zCall( 0x007107B0 );
    virtual oCItem* CreateItem( int )                    zCall( 0x00710870 );

    // user API
    #include "oCObjectFactory.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OOBJ_FACTORY_H__VER2__