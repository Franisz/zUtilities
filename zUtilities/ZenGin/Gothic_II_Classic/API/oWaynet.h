// Supported with union (c) 2018-2021 Union team

#ifndef __OWAYNET_H__VER2__
#define __OWAYNET_H__VER2__

#include "zWaynet.h"

namespace Gothic_II_Classic {

  // sizeof 7Ch
  class oCWaypoint : public zCWaypoint {
  public:

    void oCWaypoint_OnInit()              zCall( 0x0071E4B0 );
    oCWaypoint()                          zInit( oCWaypoint_OnInit() );
    virtual ~oCWaypoint()                 zCall( 0x0071E510 );
    virtual int CanBeUsed( zCVob const* ) zCall( 0x0071E520 );

    // user API
    #include "oCWaypoint.inl"
  };

  // sizeof 28h
  class oCWay : public zCWay {
  public:
    oCMobLadder* ladder; // sizeof 04h    offset 20h
    oCMobDoor* door;     // sizeof 04h    offset 24h

    void oCWay_OnInit()                           zCall( 0x0071E590 );
    oCWay()                                       zInit( oCWay_OnInit() );
    oCMobLadder* GetLadder()                      zCall( 0x0071EE60 );
    oCMobDoor* GetDoor()                          zCall( 0x0071EE70 );
    virtual ~oCWay()                              zCall( 0x0071E5D0 );
    virtual void Init( zCWaypoint*, zCWaypoint* ) zCall( 0x0071E750 );
    virtual int CanBeUsed( zCVob const* )         zCall( 0x0071E660 );
    virtual int IsObjectOnWay( zCVob const* )     zCall( 0x0071EE40 );

    // user API
    #include "oCWay.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OWAYNET_H__VER2__