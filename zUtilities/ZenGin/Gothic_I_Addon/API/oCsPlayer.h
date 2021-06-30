// Supported with union (c) 2018 Union team

#ifndef __OCS_PLAYER_H__VER1__
#define __OCS_PLAYER_H__VER1__

#include "zCCsPlayer.h"

namespace Gothic_I_Addon {

  class oCCSPlayer : public zCCSPlayer {
  public:
    zCLASS_DECLARATION( oCCSPlayer )

    void oCCSPlayer_OnInit()                                            zCall( 0x00403E70 );
    oCCSPlayer()                                                        zInit( oCCSPlayer_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00403DE0 );
    /* for zCObject num : 21*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00403E60 );
    virtual ~oCCSPlayer()                                               zCall( 0x00403EC0 );
    virtual void ProcessCutscene( zCCSCutsceneContext*, zVEC3 const& )  zCall( 0x00403EE0 );
    /* for zCCSDebugger num : 7*/

    // user API
    #include "oCCSPlayer.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OCS_PLAYER_H__VER1__