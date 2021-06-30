// Supported with union (c) 2018 Union team

#ifndef __ZWORLD_INFO_H__VER1__
#define __ZWORLD_INFO_H__VER1__

#include "zPlayerInfo.h"

namespace Gothic_I_Addon {

  class zCWorldInfo {
  public:
    int isRunning;
    zSTRING name;
    zCPlayerGroup* playerGroup_Level;
    zCList<zCPlayerInfo> historyList;

    zCWorldInfo() {}
    void zCWorldInfo_OnInit( zSTRING const& ) zCall( 0x004726B0 );
    zCWorldInfo( zSTRING const& a0 )          zInit( zCWorldInfo_OnInit( a0 ));
    zSTRING GetName()                         zCall( 0x00472940 );
    zCPlayerGroup* GetPlayerGroup()           zCall( 0x00472990 );
    int IsMember( zCPlayerInfo* )             zCall( 0x004729A0 );
    zCPlayerInfo* GetLevelMaster()            zCall( 0x004729B0 );
    void EnterWorld( zCPlayerInfo* )          zCall( 0x00472A00 );
    void LeaveWorld( zCPlayerInfo* )          zCall( 0x00472A90 );
    void ShowDebugInfo()                      zCall( 0x00472AD0 );
    virtual ~zCWorldInfo()                    zCall( 0x00472810 );

    // user API
    #include "zCWorldInfo.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZWORLD_INFO_H__VER1__