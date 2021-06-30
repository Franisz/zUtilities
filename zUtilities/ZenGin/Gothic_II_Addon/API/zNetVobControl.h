// Supported with union (c) 2018 Union team

#ifndef __ZNET_VOB_CONTROL_H__VER3__
#define __ZNET_VOB_CONTROL_H__VER3__

#include "zNetTypes.h"

namespace Gothic_II_Addon {
  const int zNET_VOBCTRL_TOLERANCE = 40000;

  class zCNetVobControl : public zCObject {
  public:
    zCLASS_DECLARATION( zCNetVobControl )

    zCVob* hostVob;
    zCPlayerInfo* ctrlPlayer;
    int isLocalChained;

    void zCNetVobControl_OnInit()                                                 zCall( 0x0045DD00 );
    zCNetVobControl()                                                             zInit( zCNetVobControl_OnInit() );
    static zCObject* _CreateNewInstance()                                         zCall( 0x0045DB80 );
    static int HandleNetMessage( zCNetMessage*, unsigned short const&, zCWorld* ) zCall( 0x0045E3B0 );
    virtual zCClassDef* _GetClassDef() const                                      zCall( 0x0045DCD0 );
    virtual void Archive( zCArchiver& )                                           zCall( 0x0045F170 );
    virtual void Unarchive( zCArchiver& )                                         zCall( 0x0045F270 );
    virtual ~zCNetVobControl()                                                    zCall( 0x0045DE30 );
    virtual void Init( zCVob* )                                                   zCall( 0x0045DE50 );
    virtual int IsLocalChained()                                                  zCall( 0x0045DCE0 );
    virtual int IsLocalControlled()                                               zCall( 0x0045F120 );
    virtual int IsPlayerVob()                                                     zCall( 0x0045F130 );
    virtual void SetLocalChained( int )                                           zCall( 0x0045DCF0 );
    virtual void SetCtrlPlayer( zCPlayerInfo* )                                   zCall( 0x0045ED00 );
    virtual void CopyCtrlState( zCVob* )                                          zCall( 0x0045F140 );
    virtual int Process()                                                         zCall( 0x0045DE70 );
    virtual int HandOverToPlayer( zCPlayerInfo* )                                 zCall( 0x0045DF40 );
    virtual zCNetMessage* CreateNetMessage( unsigned short const& )               zCall( 0x0045E8C0 );

    // user API
    #include "zCNetVobControl.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZNET_VOB_CONTROL_H__VER3__