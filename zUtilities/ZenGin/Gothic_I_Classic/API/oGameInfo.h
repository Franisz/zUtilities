// Supported with union (c) 2018-2021 Union team

#ifndef __OGAME_INFO_H__VER0__
#define __OGAME_INFO_H__VER0__

#include "zGameInfo.h"

namespace Gothic_I_Classic {

  // sizeof 18h
  class oCGameInfo : public zCGameInfo {
  public:

    void oCGameInfo_OnInit()                      zCall( 0x00423450 );
    oCGameInfo()                                  zInit( oCGameInfo_OnInit() );
    virtual ~oCGameInfo()                         zCall( 0x00423620 );
    virtual void Init()                           zCall( 0x00423630 );
    virtual void Pack( zCBuffer&, unsigned char ) zCall( 0x004236F0 );
    virtual void Unpack( zCBuffer& )              zCall( 0x00423700 );

    // user API
    #include "oCGameInfo.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OGAME_INFO_H__VER0__