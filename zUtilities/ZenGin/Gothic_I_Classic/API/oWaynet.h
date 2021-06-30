// Supported with union (c) 2018 Union team

#ifndef __OWAYNET_H__VER0__
#define __OWAYNET_H__VER0__

#include "zWaynet.h"

namespace Gothic_I_Classic {

  class oCWaypoint : public zCWaypoint {
  public:

    void oCWaypoint_OnInit()              zCall( 0x006D4FC0 );
    oCWaypoint()                          zInit( oCWaypoint_OnInit() );
    virtual ~oCWaypoint()                 zCall( 0x006D5020 );
    virtual int CanBeUsed( zCVob const* ) zCall( 0x006D5030 );

    // user API
    #include "oCWaypoint.inl"
  };

  class oCWay : public zCWay {
  public:
    oCMobLadder* ladder;
    oCMobDoor* door;

    void oCWay_OnInit()                           zCall( 0x006D50A0 );
    oCWay()                                       zInit( oCWay_OnInit() );
    oCMobLadder* GetLadder()                      zCall( 0x006D5970 );
    oCMobDoor* GetDoor()                          zCall( 0x006D5980 );
    virtual ~oCWay()                              zCall( 0x006D50E0 );
    virtual void Init( zCWaypoint*, zCWaypoint* ) zCall( 0x006D5260 );
    virtual int CanBeUsed( zCVob const* )         zCall( 0x006D5170 );
    virtual int IsObjectOnWay( zCVob const* )     zCall( 0x006D5950 );

    // user API
    #include "oCWay.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OWAYNET_H__VER0__