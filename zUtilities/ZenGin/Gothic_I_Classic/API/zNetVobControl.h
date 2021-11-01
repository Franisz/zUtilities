// Supported with union (c) 2018-2021 Union team

#ifndef __ZNET_VOB_CONTROL_H__VER0__
#define __ZNET_VOB_CONTROL_H__VER0__

#include "zNetTypes.h"

namespace Gothic_I_Classic {
  const int zNET_VOBCTRL_TOLERANCE = 40000;

  // sizeof 30h
  class zCNetVobControl : public zCObject {
  public:
    zCLASS_DECLARATION( zCNetVobControl )

    zCVob* hostVob;           // sizeof 04h    offset 24h
    zCPlayerInfo* ctrlPlayer; // sizeof 04h    offset 28h
    int isLocalChained;       // sizeof 04h    offset 2Ch

    void zCNetVobControl_OnInit()                                                 zCall( 0x00458A30 );
    zCNetVobControl()                                                             zInit( zCNetVobControl_OnInit() );
    static zCObject* _CreateNewInstance()                                         zCall( 0x004588A0 );
    static int HandleNetMessage( zCNetMessage*, unsigned short const&, zCWorld* ) zCall( 0x004590C0 );
    virtual zCClassDef* _GetClassDef() const                                      zCall( 0x00458A00 );
    virtual void Archive( zCArchiver& )                                           zCall( 0x00459E40 );
    virtual void Unarchive( zCArchiver& )                                         zCall( 0x00459F40 );
    virtual ~zCNetVobControl()                                                    zCall( 0x00458B60 );
    virtual void Init( zCVob* )                                                   zCall( 0x00458B80 );
    virtual int IsLocalChained()                                                  zCall( 0x00458A10 );
    virtual int IsLocalControlled()                                               zCall( 0x00459DF0 );
    virtual int IsPlayerVob()                                                     zCall( 0x00459E00 );
    virtual void SetLocalChained( int )                                           zCall( 0x00458A20 );
    virtual void SetCtrlPlayer( zCPlayerInfo* )                                   zCall( 0x004599D0 );
    virtual void CopyCtrlState( zCVob* )                                          zCall( 0x00459E10 );
    virtual int Process()                                                         zCall( 0x00458BA0 );
    virtual int HandOverToPlayer( zCPlayerInfo* )                                 zCall( 0x00458C70 );
    virtual zCNetMessage* CreateNetMessage( unsigned short const& )               zCall( 0x004595D0 );

    // user API
    #include "zCNetVobControl.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZNET_VOB_CONTROL_H__VER0__