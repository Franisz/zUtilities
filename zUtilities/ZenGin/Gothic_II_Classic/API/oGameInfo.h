// Supported with union (c) 2018-2021 Union team

#ifndef __OGAME_INFO_H__VER2__
#define __OGAME_INFO_H__VER2__

#include "zGameInfo.h"

namespace Gothic_II_Classic {

  // sizeof 18h
  class oCGameInfo : public zCGameInfo {
  public:

    void oCGameInfo_OnInit()                      zCall( 0x00423B00 );
    oCGameInfo()                                  zInit( oCGameInfo_OnInit() );
    virtual ~oCGameInfo()                         zCall( 0x00423CD0 );
    virtual void Init()                           zCall( 0x00423CE0 );
    virtual void Pack( zCBuffer&, unsigned char ) zCall( 0x00423DA0 );
    virtual void Unpack( zCBuffer& )              zCall( 0x00423DB0 );

    // user API
    #include "oCGameInfo.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OGAME_INFO_H__VER2__