// Supported with union (c) 2018-2021 Union team

#ifndef __ZWORLD_INFO_H__VER2__
#define __ZWORLD_INFO_H__VER2__

#include "zPlayerInfo.h"

namespace Gothic_II_Classic {

  // sizeof 28h
  class zCWorldInfo {
  public:
    int isRunning;                    // sizeof 04h    offset 04h
    zSTRING name;                     // sizeof 14h    offset 08h
    zCPlayerGroup* playerGroup_Level; // sizeof 04h    offset 1Ch
    zCList<zCPlayerInfo> historyList; // sizeof 08h    offset 20h

    zCWorldInfo() {}
    void zCWorldInfo_OnInit( zSTRING const& ) zCall( 0x0046ECB0 );
    zCWorldInfo( zSTRING const& a0 )          zInit( zCWorldInfo_OnInit( a0 ));
    zSTRING GetName()                         zCall( 0x0046EF00 );
    zCPlayerGroup* GetPlayerGroup()           zCall( 0x0046EF50 );
    int IsMember( zCPlayerInfo* )             zCall( 0x0046EF60 );
    zCPlayerInfo* GetLevelMaster()            zCall( 0x0046EF70 );
    void EnterWorld( zCPlayerInfo* )          zCall( 0x0046EFC0 );
    void LeaveWorld( zCPlayerInfo* )          zCall( 0x0046F050 );
    void ShowDebugInfo()                      zCall( 0x0046F090 );
    virtual ~zCWorldInfo()                    zCall( 0x0046EDE0 );

    // user API
    #include "zCWorldInfo.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZWORLD_INFO_H__VER2__