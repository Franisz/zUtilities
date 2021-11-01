// Supported with union (c) 2018-2021 Union team

#ifndef __ZWORLD_INFO_H__VER3__
#define __ZWORLD_INFO_H__VER3__

#include "zPlayerInfo.h"

namespace Gothic_II_Addon {

  // sizeof 28h
  class zCWorldInfo {
  public:
    int isRunning;                    // sizeof 04h    offset 04h
    zSTRING name;                     // sizeof 14h    offset 08h
    zCPlayerGroup* playerGroup_Level; // sizeof 04h    offset 1Ch
    zCList<zCPlayerInfo> historyList; // sizeof 08h    offset 20h

    zCWorldInfo() {}
    void zCWorldInfo_OnInit( zSTRING const& ) zCall( 0x0046F8E0 );
    zCWorldInfo( zSTRING const& a0 )          zInit( zCWorldInfo_OnInit( a0 ));
    zSTRING GetName()                         zCall( 0x0046FB30 );
    zCPlayerGroup* GetPlayerGroup()           zCall( 0x0046FB80 );
    int IsMember( zCPlayerInfo* )             zCall( 0x0046FB90 );
    zCPlayerInfo* GetLevelMaster()            zCall( 0x0046FBA0 );
    void EnterWorld( zCPlayerInfo* )          zCall( 0x0046FBF0 );
    void LeaveWorld( zCPlayerInfo* )          zCall( 0x0046FC80 );
    void ShowDebugInfo()                      zCall( 0x0046FCC0 );
    virtual ~zCWorldInfo()                    zCall( 0x0046FA10 );

    // user API
    #include "zCWorldInfo.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZWORLD_INFO_H__VER3__