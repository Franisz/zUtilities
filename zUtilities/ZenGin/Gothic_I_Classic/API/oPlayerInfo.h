// Supported with union (c) 2018-2021 Union team

#ifndef __OPLAYER_INFO_H__VER0__
#define __OPLAYER_INFO_H__VER0__

#include "zBuffer.h"
#include "zPlayerInfo.h"

namespace Gothic_I_Classic {
  const int MAX_PLAYER_INSTANCES = 5;

  enum TPlayerInstance {
    PC_UNKNOWN,
    PC_HERO,
    PC_FIGHTER,
    PC_THIEF,
    PC_MAGE,
    PC_PSIONIC
  };

  // sizeof 40h
  class oCPlayerInfo : public zCPlayerInfo {
  public:
    TPlayerInstance instance; // sizeof 04h    offset 3Ch

    void oCPlayerInfo_OnInit()                          zCall( 0x00433580 );
    oCPlayerInfo()                                      zInit( oCPlayerInfo_OnInit() );
    zSTRING GetInstanceName() const                     zCall( 0x00433870 );
    TPlayerInstance GetInstance() const                 zCall( 0x004338C0 );
    virtual ~oCPlayerInfo()                             zCall( 0x00433710 );
    virtual void Init( zSTRING const&, zSTRING const& ) zCall( 0x00433700 );
    virtual void Reset()                                zCall( 0x00433910 );
    virtual void Pack( zCBuffer& )                      zCall( 0x004338D0 );
    virtual void Unpack( zCBuffer& )                    zCall( 0x004338F0 );
    virtual void SetInstance( TPlayerInstance )         zCall( 0x00433720 );
    virtual void SetInstanceByName( zSTRING const& )    zCall( 0x00433730 );

    // user API
    #include "oCPlayerInfo.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OPLAYER_INFO_H__VER0__