// Supported with union (c) 2018 Union team

#ifndef __OMENU__MAIN_H__VER0__
#define __OMENU__MAIN_H__VER0__

#include "zMenu.h"

namespace Gothic_I_Classic {

  class oCMenu_ChgKeys : public zCMenu {
  public:

    oCMenu_ChgKeys() {}
    void oCMenu_ChgKeys_OnInit( zSTRING const& ) zCall( 0x00473400 );
    oCMenu_ChgKeys( zSTRING const& a0 )          zInit( oCMenu_ChgKeys_OnInit( a0 ));
    void InitText()                              zCall( 0x00474010 );
    virtual int HandleEvent( int )               zCall( 0x00473450 );
    virtual void Leave()                         zCall( 0x00473F60 );
    virtual ~oCMenu_ChgKeys()                    zCall( 0x00473440 );
    virtual void ScreenInit()                    zCall( 0x00473F40 );
    virtual int ExecCommand( zSTRING const& )    zCall( 0x00473690 );

    // user API
    #include "oCMenu_ChgKeys.inl"
  };

  class oCMenu_Main : public zCMenu {
  public:

    oCMenu_Main() {}
    void oCMenu_Main_OnInit( zSTRING const& ) zCall( 0x004731C0 );
    oCMenu_Main( zSTRING const& a0 )          zInit( oCMenu_Main_OnInit( a0 ));
    virtual int HandleEvent( int )            zCall( 0x00473220 );
    virtual ~oCMenu_Main()                    zCall( 0x0042C400 );
    virtual void ScreenInit()                 zCall( 0x00473200 );
    virtual void ScreenDone()                 zCall( 0x00473210 );

    // user API
    #include "oCMenu_Main.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OMENU__MAIN_H__VER0__