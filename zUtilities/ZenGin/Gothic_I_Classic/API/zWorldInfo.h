// Supported with union (c) 2018 Union team

#ifndef __ZWORLD_INFO_H__VER0__
#define __ZWORLD_INFO_H__VER0__

#include "zPlayerInfo.h"

namespace Gothic_I_Classic {

  class zCWorldInfo {
  public:
    int isRunning;
    zSTRING name;
    zCPlayerGroup* playerGroup_Level;
    zCList<zCPlayerInfo> historyList;

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