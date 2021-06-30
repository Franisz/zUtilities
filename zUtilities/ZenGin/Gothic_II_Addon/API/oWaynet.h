// Supported with union (c) 2018 Union team

#ifndef __OWAYNET_H__VER3__
#define __OWAYNET_H__VER3__

#include "zWaynet.h"

namespace Gothic_II_Addon {

  class oCWaypoint : public zCWaypoint {
  public:

    void oCWaypoint_OnInit()              zCall( 0x0077DEF0 );
    oCWaypoint()                          zInit( oCWaypoint_OnInit() );
    virtual ~oCWaypoint()                 zCall( 0x0077DF50 );
    virtual int CanBeUsed( zCVob const* ) zCall( 0x0077DF60 );

    // user API
    #include "oCWaypoint.inl"
  };

  class oCWay : public zCWay {
  public:
    oCMobLadder* ladder;
    oCMobDoor* door;

    void oCWay_OnInit()                           zCall( 0x0077DFD0 );
    oCWay()                                       zInit( oCWay_OnInit() );
    oCMobLadder* GetLadder()                      zCall( 0x0077E8A0 );
    oCMobDoor* GetDoor()                          zCall( 0x0077E8B0 );
    virtual ~oCWay()                              zCall( 0x0077E010 );
    virtual void Init( zCWaypoint*, zCWaypoint* ) zCall( 0x0077E190 );
    virtual int CanBeUsed( zCVob const* )         zCall( 0x0077E0A0 );
    virtual int IsObjectOnWay( zCVob const* )     zCall( 0x0077E880 );

    // user API
    #include "oCWay.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OWAYNET_H__VER3__