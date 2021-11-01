// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET_VOB_CONTROL_H__VER1__
#define __ZNET_VOB_CONTROL_H__VER1__

#include "zNetTypes.h"

namespace Gothic_I_Addon {
  const int zNET_VOBCTRL_TOLERANCE = 40000;

  // sizeof 30h
  class zCNetVobControl : public zCObject {
  public:
    zCLASS_DECLARATION( zCNetVobControl )

    zCVob* hostVob;           // sizeof 04h    offset 24h
    zCPlayerInfo* ctrlPlayer; // sizeof 04h    offset 28h
    int isLocalChained;       // sizeof 04h    offset 2Ch

    void zCNetVobControl_OnInit()                                                 zCall( 0x0045FBB0 );
    zCNetVobControl()                                                             zInit( zCNetVobControl_OnInit() );
    static zCObject* _CreateNewInstance()                                         zCall( 0x0045FA20 );
    static int HandleNetMessage( zCNetMessage*, unsigned short const&, zCWorld* ) zCall( 0x004602D0 );
    virtual zCClassDef* _GetClassDef() const                                      zCall( 0x0045FB80 );
    virtual void Archive( zCArchiver& )                                           zCall( 0x004611D0 );
    virtual void Unarchive( zCArchiver& )                                         zCall( 0x004612D0 );
    virtual ~zCNetVobControl()                                                    zCall( 0x0045FCE0 );
    virtual void Init( zCVob* )                                                   zCall( 0x0045FD00 );
    virtual int IsLocalChained()                                                  zCall( 0x0045FB90 );
    virtual int IsLocalControlled()                                               zCall( 0x00461180 );
    virtual int IsPlayerVob()                                                     zCall( 0x00461190 );
    virtual void SetLocalChained( int )                                           zCall( 0x0045FBA0 );
    virtual void SetCtrlPlayer( zCPlayerInfo* )                                   zCall( 0x00460CE0 );
    virtual void CopyCtrlState( zCVob* )                                          zCall( 0x004611A0 );
    virtual int Process()                                                         zCall( 0x0045FD20 );
    virtual int HandOverToPlayer( zCPlayerInfo* )                                 zCall( 0x0045FDE0 );
    virtual zCNetMessage* CreateNetMessage( unsigned short const& )               zCall( 0x00460870 );

    // user API
    #include "zCNetVobControl.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZNET_VOB_CONTROL_H__VER1__