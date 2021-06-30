// Supported with union (c) 2018 Union team

#ifndef __OMENU__MAIN_H__VER2__
#define __OMENU__MAIN_H__VER2__

#include "zMenu.h"

namespace Gothic_II_Classic {

  class oCMenu_ChgKeys : public zCMenu {
  public:

    oCMenu_ChgKeys() {}
    void oCMenu_ChgKeys_OnInit( zSTRING const& ) zCall( 0x00478E30 );
    oCMenu_ChgKeys( zSTRING const& a0 )          zInit( oCMenu_ChgKeys_OnInit( a0 ));
    void InitText()                              zCall( 0x00479AC0 );
    virtual int HandleEvent( int )               zCall( 0x00478E80 );
    virtual void Leave()                         zCall( 0x00479A10 );
    virtual ~oCMenu_ChgKeys()                    zCall( 0x00478E70 );
    virtual void ScreenInit()                    zCall( 0x004799F0 );
    virtual int ExecCommand( zSTRING const& )    zCall( 0x004790C0 );

    // user API
    #include "oCMenu_ChgKeys.inl"
  };

  class oCMenu_Main : public zCMenu {
  public:

    oCMenu_Main() {}
    void oCMenu_Main_OnInit( zSTRING const& ) zCall( 0x00478BF0 );
    oCMenu_Main( zSTRING const& a0 )          zInit( oCMenu_Main_OnInit( a0 ));
    virtual int HandleEvent( int )            zCall( 0x00478C50 );
    virtual ~oCMenu_Main()                    zCall( 0x0042E600 );
    virtual void ScreenInit()                 zCall( 0x00478C30 );
    virtual void ScreenDone()                 zCall( 0x00478C40 );

    // user API
    #include "oCMenu_Main.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OMENU__MAIN_H__VER2__