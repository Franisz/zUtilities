// Supported with union (c) 2018-2021 Union team

#ifndef __OOBJ_FACTORY_H__VER1__
#define __OOBJ_FACTORY_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 24h
  class oCObjectFactory : public zCObjectFactory {
  public:
    zCLASS_DECLARATION( oCObjectFactory )

    oCObjectFactory() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x006FE020 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00428590 );
    virtual ~oCObjectFactory()                                          zCall( 0x00428750 );
    virtual zCEventManager* CreateEventManager( zCVob* )                zCall( 0x006FE170 );
    virtual zCCSManager* CreateCSManager()                              zCall( 0x006FE1E0 );
    virtual zCGameInfo* CreateGameInfo()                                zCall( 0x006FE250 );
    virtual zCPlayerInfo* CreatePlayerInfo()                            zCall( 0x006FE2C0 );
    virtual zCWorld* CreateWorld()                                      zCall( 0x006FE330 );
    virtual zCWaypoint* CreateWaypoint()                                zCall( 0x006FE5C0 );
    virtual zCWay* CreateWay()                                          zCall( 0x006FE630 );
    virtual oCNpc* CreateNpc( int )                                     zCall( 0x006FE3C0 );
    virtual oCItem* CreateItem( int )                                   zCall( 0x006FE4C0 );

    // user API
    #include "oCObjectFactory.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OOBJ_FACTORY_H__VER1__