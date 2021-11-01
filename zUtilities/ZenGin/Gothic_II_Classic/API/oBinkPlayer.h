// Supported with union (c) 2018-2021 Union team

#ifndef __OBINK_PLAYER_H__VER2__
#define __OBINK_PLAYER_H__VER2__

#include "zBinkPlayer.h"
#include "zRenderer.h"

namespace Gothic_II_Classic {

  // sizeof 88h
  class oCBinkPlayer : public zCBinkPlayer {
  public:
    int extendedKeys;          // sizeof 04h    offset 80h
    int disallowInputHandling; // sizeof 04h    offset 84h

    void oCBinkPlayer_OnInit()       zCall( 0x004228A0 );
    oCBinkPlayer()                   zInit( oCBinkPlayer_OnInit() );
    virtual ~oCBinkPlayer()          zCall( 0x004228E0 );
    virtual int OpenVideo( zSTRING ) zCall( 0x00423450 );
    virtual int PlayInit( int )      zCall( 0x004228F0 );
    virtual int PlayFrame()          zCall( 0x00422960 );
    virtual int PlayDeinit()         zCall( 0x00422950 );
    virtual int PlayHandleEvents()   zCall( 0x00422970 );

    // user API
    #include "oCBinkPlayer.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OBINK_PLAYER_H__VER2__