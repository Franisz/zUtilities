// Supported with union (c) 2018-2021 Union team

#ifndef __OPLAYER_INFO_H__VER1__
#define __OPLAYER_INFO_H__VER1__

#include "zBuffer.h"
#include "zPlayerInfo.h"

namespace Gothic_I_Addon {
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

    void oCPlayerInfo_OnInit()                          zCall( 0x00437490 );
    oCPlayerInfo()                                      zInit( oCPlayerInfo_OnInit() );
    zSTRING GetInstanceName() const                     zCall( 0x00437790 );
    TPlayerInstance GetInstance() const                 zCall( 0x004377F0 );
    virtual ~oCPlayerInfo()                             zCall( 0x00437630 );
    virtual void Init( zSTRING const&, zSTRING const& ) zCall( 0x00437610 );
    virtual void Reset()                                zCall( 0x00437840 );
    virtual void Pack( zCBuffer& )                      zCall( 0x00437800 );
    virtual void Unpack( zCBuffer& )                    zCall( 0x00437820 );
    virtual void SetInstance( TPlayerInstance )         zCall( 0x00437640 );
    virtual void SetInstanceByName( zSTRING const& )    zCall( 0x00437650 );

    // user API
    #include "oCPlayerInfo.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OPLAYER_INFO_H__VER1__