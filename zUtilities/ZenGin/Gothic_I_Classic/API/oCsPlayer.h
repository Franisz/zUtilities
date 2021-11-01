// Supported with union (c) 2018-2021 Union team

#ifndef __OCS_PLAYER_H__VER0__
#define __OCS_PLAYER_H__VER0__

#include "zCCsPlayer.h"

namespace Gothic_I_Classic {

  // sizeof 68h
  class oCCSPlayer : public zCCSPlayer {
  public:
    zCLASS_DECLARATION( oCCSPlayer )

    void oCCSPlayer_OnInit()                                            zCall( 0x00403750 );
    oCCSPlayer()                                                        zInit( oCCSPlayer_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x004036C0 );
    /* for zCObject num : 21*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00403740 );
    virtual ~oCCSPlayer()                                               zCall( 0x004037A0 );
    virtual void ProcessCutscene( zCCSCutsceneContext*, zVEC3 const& )  zCall( 0x004037C0 );
    /* for zCCSDebugger num : 7*/

    // user API
    #include "oCCSPlayer.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OCS_PLAYER_H__VER0__