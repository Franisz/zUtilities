// Supported with union (c) 2018-2021 Union team

#ifndef __OBINK_PLAYER_H__VER0__
#define __OBINK_PLAYER_H__VER0__

#include "zBinkPlayer.h"
#include "zRenderer.h"

namespace Gothic_I_Classic {

  // sizeof 88h
  class oCBinkPlayer : public zCBinkPlayer {
  public:
    int extendedKeys;          // sizeof 04h    offset 80h
    int disallowInputHandling; // sizeof 04h    offset 84h

    void oCBinkPlayer_OnInit()       zCall( 0x00422300 );
    oCBinkPlayer()                   zInit( oCBinkPlayer_OnInit() );
    virtual ~oCBinkPlayer()          zCall( 0x00422340 );
    virtual int OpenVideo( zSTRING ) zCall( 0x00422DA0 );
    virtual int PlayInit( int )      zCall( 0x00422350 );
    virtual int PlayFrame()          zCall( 0x004223C0 );
    virtual int PlayDeinit()         zCall( 0x004223B0 );
    virtual int PlayHandleEvents()   zCall( 0x004223D0 );

    // user API
    #include "oCBinkPlayer.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OBINK_PLAYER_H__VER0__