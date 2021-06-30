// Supported with union (c) 2018 Union team

#ifndef __ZINPUT__WIN32_H__VER1__
#define __ZINPUT__WIN32_H__VER1__

#include "zInput.h"

namespace Gothic_I_Addon {

  class zCInput_Win32 : public zCInput {
  public:
    zCTimer m_kbdTimer;
    float m_fKeyRepeatDelay;
    float m_fKeyRepeatTime;
    float m_fKeyRepeatTimeMod;
    float m_fKeyRepeatCounter;
    float m_fKeyRepeatCounterDelay;
    unsigned short m_iLastKey;

    zCInput_Win32() {}
    void zCInput_Win32_OnInit( HWND__** )               zCall( 0x004D7FB0 );
    void SetFocusWindow( HWND__* )                      zCall( 0x004D7FA0 );
    zCInput_Win32( HWND__** a0 )                        zInit( zCInput_Win32_OnInit( a0 ));
    void SetAutoRepeatDelayRate( float )                zCall( 0x004D8850 );
    float GetAutoRepeatDelayRate()                      zCall( 0x004D8870 );
    virtual ~zCInput_Win32()                            zCall( 0x004D81E0 );
    virtual float GetState( unsigned short )            zCall( 0x004D82A0 );
    virtual int SetState( unsigned short, int )         zCall( 0x004D8390 );
    virtual int GetToggled( unsigned short )            zCall( 0x004D85F0 );
    virtual void SetDeviceEnabled( zTInputDevice, int ) zCall( 0x004D86E0 );
    virtual int GetDeviceEnabled( zTInputDevice )       zCall( 0x004D8720 );
    virtual int GetDeviceConnected( zTInputDevice )     zCall( 0x004D8740 );
    virtual int KeyPressed( int )                       zCall( 0x004D8760 );
    virtual int KeyToggled( int )                       zCall( 0x004D8770 );
    virtual int AnyKeyPressed()                         zCall( 0x004D8790 );
    virtual void ResetRepeatKey( int )                  zCall( 0x004D8880 );
    virtual unsigned short GetKey( int, int )           zCall( 0x004D88C0 );
    virtual void SetKey( int, int )                     zCall( 0x004D8A20 );
    virtual char GetChar()                              zCall( 0x004D8A50 );
    virtual void ClearKeyBuffer()                       zCall( 0x004D8AF0 );
    virtual void GetMousePos( float&, float&, float& )  zCall( 0x004D8CF0 );
    virtual int GetMouseButtonPressedLeft()             zCall( 0x004D8D50 );
    virtual int GetMouseButtonPressedMid()              zCall( 0x004D8D60 );
    virtual int GetMouseButtonPressedRight()            zCall( 0x004D8D70 );
    virtual void SetMouseSensitivity( float, float )    zCall( 0x004D8D80 );
    virtual void GetMouseSensitivity( float&, float& )  zCall( 0x004D8DD0 );
    virtual void SetMouseFlipXY( int, int )             zCall( 0x004D8DF0 );
    virtual void GetMouseFlipXY( int&, int& )           zCall( 0x004D8E10 );
    virtual void ProcessInputEvents()                   zCall( 0x004D8CC0 );

    // user API
    #include "zCInput_Win32.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZINPUT__WIN32_H__VER1__