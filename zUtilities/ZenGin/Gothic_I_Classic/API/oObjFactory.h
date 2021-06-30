// Supported with union (c) 2018 Union team

#ifndef __OOBJ_FACTORY_H__VER0__
#define __OOBJ_FACTORY_H__VER0__

namespace Gothic_I_Classic {

  class oCObjectFactory : public zCObjectFactory {
  public:
    zCLASS_DECLARATION( oCObjectFactory )

    oCObjectFactory() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x006C81B0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00425BD0 );
    virtual ~oCObjectFactory()                                          zCall( 0x00425D90 );
    virtual zCEventManager* CreateEventManager( zCVob* )                zCall( 0x006C8310 );
    virtual zCCSManager* CreateCSManager()                              zCall( 0x006C8380 );
    virtual zCGameInfo* CreateGameInfo()                                zCall( 0x006C83F0 );
    virtual zCPlayerInfo* CreatePlayerInfo()                            zCall( 0x006C8460 );
    virtual zCWorld* CreateWorld()                                      zCall( 0x006C84D0 );
    virtual zCWaypoint* CreateWaypoint()                                zCall( 0x006C8760 );
    virtual zCWay* CreateWay()                                          zCall( 0x006C87D0 );
    virtual oCNpc* CreateNpc( int )                                     zCall( 0x006C8560 );
    virtual oCItem* CreateItem( int )                                   zCall( 0x006C8660 );

    // user API
    #include "oCObjectFactory.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OOBJ_FACTORY_H__VER0__