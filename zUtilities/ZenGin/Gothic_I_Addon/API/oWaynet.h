// Supported with union (c) 2018-2021 Union team

#ifndef __OWAYNET_H__VER1__
#define __OWAYNET_H__VER1__

#include "zWaynet.h"

namespace Gothic_I_Addon {

  // sizeof 7Ch
  class oCWaypoint : public zCWaypoint {
  public:

    void oCWaypoint_OnInit()              zCall( 0x0070C570 );
    oCWaypoint()                          zInit( oCWaypoint_OnInit() );
    virtual ~oCWaypoint()                 zCall( 0x0070C5D0 );
    virtual int CanBeUsed( zCVob const* ) zCall( 0x0070C5E0 );

    // user API
    #include "oCWaypoint.inl"
  };

  // sizeof 28h
  class oCWay : public zCWay {
  public:
    oCMobLadder* ladder; // sizeof 04h    offset 20h
    oCMobDoor* door;     // sizeof 04h    offset 24h

    void oCWay_OnInit()                           zCall( 0x0070C650 );
    oCWay()                                       zInit( oCWay_OnInit() );
    oCMobLadder* GetLadder()                      zCall( 0x0070D070 );
    oCMobDoor* GetDoor()                          zCall( 0x0070D080 );
    virtual ~oCWay()                              zCall( 0x0070C690 );
    virtual void Init( zCWaypoint*, zCWaypoint* ) zCall( 0x0070C820 );
    virtual int CanBeUsed( zCVob const* )         zCall( 0x0070C730 );
    virtual int IsObjectOnWay( zCVob const* )     zCall( 0x0070D050 );

    // user API
    #include "oCWay.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OWAYNET_H__VER1__