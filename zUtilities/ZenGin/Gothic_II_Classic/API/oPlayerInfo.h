// Supported with union (c) 2018 Union team

#ifndef __OPLAYER_INFO_H__VER2__
#define __OPLAYER_INFO_H__VER2__

#include "zBuffer.h"
#include "zPlayerInfo.h"

namespace Gothic_II_Classic {
  const int MAX_PLAYER_INSTANCES = 5;

  enum TPlayerInstance {
    PC_UNKNOWN,
    PC_HERO,
    PC_FIGHTER,
    PC_THIEF,
    PC_MAGE,
    PC_PSIONIC
  };

  class oCPlayerInfo : public zCPlayerInfo {
  public:
    TPlayerInstance instance;

    void oCPlayerInfo_OnInit()                          zCall( 0x00435EE0 );
    oCPlayerInfo()                                      zInit( oCPlayerInfo_OnInit() );
    zSTRING GetInstanceName() const                     zCall( 0x004361D0 );
    TPlayerInstance GetInstance() const                 zCall( 0x00436220 );
    virtual ~oCPlayerInfo()                             zCall( 0x00436070 );
    virtual void Init( zSTRING const&, zSTRING const& ) zCall( 0x00436060 );
    virtual void Reset()                                zCall( 0x00436270 );
    virtual void Pack( zCBuffer& )                      zCall( 0x00436230 );
    virtual void Unpack( zCBuffer& )                    zCall( 0x00436250 );
    virtual void SetInstance( TPlayerInstance )         zCall( 0x00436080 );
    virtual void SetInstanceByName( zSTRING const& )    zCall( 0x00436090 );

    // user API
    #include "oCPlayerInfo.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OPLAYER_INFO_H__VER2__