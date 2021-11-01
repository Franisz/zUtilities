// Supported with union (c) 2018-2021 Union team

#ifndef __ZWORLD_INFO_H__VER0__
#define __ZWORLD_INFO_H__VER0__

#include "zPlayerInfo.h"

namespace Gothic_I_Classic {

  // sizeof 28h
  class zCWorldInfo {
  public:
    int isRunning;                    // sizeof 04h    offset 04h
    zSTRING name;                     // sizeof 14h    offset 08h
    zCPlayerGroup* playerGroup_Level; // sizeof 04h    offset 1Ch
    zCList<zCPlayerInfo> historyList; // sizeof 08h    offset 20h

    zCWorldInfo() {}
    void zCWorldInfo_OnInit( zSTRING const& ) zCall( 0x0046A4E0 );
    zCWorldInfo( zSTRING const& a0 )          zInit( zCWorldInfo_OnInit( a0 ));
    zSTRING GetName()                         zCall( 0x0046A740 );
    zCPlayerGroup* GetPlayerGroup()           zCall( 0x0046A790 );
    int IsMember( zCPlayerInfo* )             zCall( 0x0046A7A0 );
    zCPlayerInfo* GetLevelMaster()            zCall( 0x0046A7B0 );
    void EnterWorld( zCPlayerInfo* )          zCall( 0x0046A800 );
    void LeaveWorld( zCPlayerInfo* )          zCall( 0x0046A890 );
    void ShowDebugInfo()                      zCall( 0x0046A8D0 );
    virtual ~zCWorldInfo()                    zCall( 0x0046A620 );

    // user API
    #include "zCWorldInfo.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZWORLD_INFO_H__VER0__