// Supported with union (c) 2018 Union team

#ifndef __OMENU__MAIN_H__VER3__
#define __OMENU__MAIN_H__VER3__

#include "zMenu.h"

namespace Gothic_II_Addon {

  class oCMenu_ChgKeys : public zCMenu {
  public:

    oCMenu_ChgKeys() {}
    void oCMenu_ChgKeys_OnInit( zSTRING const& ) zCall( 0x0047A1D0 );
    oCMenu_ChgKeys( zSTRING const& a0 )          zInit( oCMenu_ChgKeys_OnInit( a0 ));
    void InitText()                              zCall( 0x0047AF30 );
    virtual int HandleEvent( int )               zCall( 0x0047A220 );
    virtual void Leave()                         zCall( 0x0047AE80 );
    virtual ~oCMenu_ChgKeys()                    zCall( 0x0047A210 );
    virtual void ScreenInit()                    zCall( 0x0047AE60 );
    virtual int ExecCommand( zSTRING const& )    zCall( 0x0047A460 );

    // user API
    #include "oCMenu_ChgKeys.inl"
  };

  class oCMenu_Main : public zCMenu {
  public:

    oCMenu_Main() {}
    void oCMenu_Main_OnInit( zSTRING const& ) zCall( 0x00479F90 );
    oCMenu_Main( zSTRING const& a0 )          zInit( oCMenu_Main_OnInit( a0 ));
    virtual int HandleEvent( int )            zCall( 0x00479FF0 );
    virtual ~oCMenu_Main()                    zCall( 0x0042E920 );
    virtual void ScreenInit()                 zCall( 0x00479FD0 );
    virtual void ScreenDone()                 zCall( 0x00479FE0 );

    // user API
    #include "oCMenu_Main.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OMENU__MAIN_H__VER3__