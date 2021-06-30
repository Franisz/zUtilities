// Supported with union (c) 2018 Union team

#ifndef __ZNET_VOB_CONTROL_H__VER2__
#define __ZNET_VOB_CONTROL_H__VER2__

#include "zNetTypes.h"

namespace Gothic_II_Classic {
  const int zNET_VOBCTRL_TOLERANCE = 40000;

  class zCNetVobControl : public zCObject {
  public:
    zCLASS_DECLARATION( zCNetVobControl )

    zCVob* hostVob;
    zCPlayerInfo* ctrlPlayer;
    int isLocalChained;

    void zCNetVobControl_OnInit()                                                 zCall( 0x0045D5B0 );
    zCNetVobControl()                                                             zInit( zCNetVobControl_OnInit() );
    static zCObject* _CreateNewInstance()                                         zCall( 0x0045D430 );
    static int HandleNetMessage( zCNetMessage*, unsigned short const&, zCWorld* ) zCall( 0x0045DC60 );
    virtual zCClassDef* _GetClassDef() const                                      zCall( 0x0045D580 );
    virtual void Archive( zCArchiver& )                                           zCall( 0x0045EA20 );
    virtual void Unarchive( zCArchiver& )                                         zCall( 0x0045EB20 );
    virtual ~zCNetVobControl()                                                    zCall( 0x0045D6E0 );
    virtual void Init( zCVob* )                                                   zCall( 0x0045D700 );
    virtual int IsLocalChained()                                                  zCall( 0x0045D590 );
    virtual int IsLocalControlled()                                               zCall( 0x0045E9D0 );
    virtual int IsPlayerVob()                                                     zCall( 0x0045E9E0 );
    virtual void SetLocalChained( int )                                           zCall( 0x0045D5A0 );
    virtual void SetCtrlPlayer( zCPlayerInfo* )                                   zCall( 0x0045E5B0 );
    virtual void CopyCtrlState( zCVob* )                                          zCall( 0x0045E9F0 );
    virtual int Process()                                                         zCall( 0x0045D720 );
    virtual int HandOverToPlayer( zCPlayerInfo* )                                 zCall( 0x0045D7F0 );
    virtual zCNetMessage* CreateNetMessage( unsigned short const& )               zCall( 0x0045E170 );

    // user API
    #include "zCNetVobControl.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZNET_VOB_CONTROL_H__VER2__