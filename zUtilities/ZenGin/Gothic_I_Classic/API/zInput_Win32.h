// Supported with union (c) 2018 Union team

#ifndef __ZINPUT__WIN32_H__VER0__
#define __ZINPUT__WIN32_H__VER0__

#include "zInput.h"
#include "zInput_Const.h"

namespace Gothic_I_Classic {

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
    void zCInput_Win32_OnInit( HWND__** )               zCall( 0x004C8170 );
    void SetFocusWindow( HWND__* )                      zCall( 0x004C8160 );
    zCInput_Win32( HWND__** a0 )                        zInit( zCInput_Win32_OnInit( a0 ));
    void SetAutoRepeatDelayRate( float )                zCall( 0x004C8830 );
    float GetAutoRepeatDelayRate()                      zCall( 0x004C8850 );
    virtual ~zCInput_Win32()                            zCall( 0x004C8250 );
    virtual float GetState( unsigned short )            zCall( 0x004C8310 );
    virtual int SetState( unsigned short, int )         zCall( 0x004C83E0 );
    virtual int GetToggled( unsigned short )            zCall( 0x004C8630 );
    virtual void SetDeviceEnabled( zTInputDevice, int ) zCall( 0x004C8710 );
    virtual int GetDeviceEnabled( zTInputDevice )       zCall( 0x004C8760 );
    virtual int GetDeviceConnected( zTInputDevice )     zCall( 0x004C8780 );
    virtual int KeyPressed( int )                       zCall( 0x004C87A0 );
    virtual int KeyToggled( int )                       zCall( 0x004C87B0 );
    virtual int AnyKeyPressed()                         zCall( 0x004C87D0 );
    virtual void ResetRepeatKey( int )                  zCall( 0x004C8860 );
    virtual unsigned short GetKey( int, int )           zCall( 0x004C88A0 );
    virtual void SetKey( int, int )                     zCall( 0x004C8A10 );
    virtual char GetChar()                              zCall( 0x004C8A40 );
    virtual void ClearKeyBuffer()                       zCall( 0x004C8AE0 );
    virtual void GetMousePos( float&, float&, float& )  zCall( 0x004C8BD0 );
    virtual int GetMouseButtonPressedLeft()             zCall( 0x004C8C30 );
    virtual int GetMouseButtonPressedMid()              zCall( 0x004C8C40 );
    virtual int GetMouseButtonPressedRight()            zCall( 0x004C8C50 );
    virtual void SetMouseSensitivity( float, float )    zCall( 0x004C8C60 );
    virtual void GetMouseSensitivity( float&, float& )  zCall( 0x004C8CB0 );
    virtual void SetMouseFlipXY( int, int )             zCall( 0x004C8CD0 );
    virtual void GetMouseFlipXY( int&, int& )           zCall( 0x004C8CF0 );
    virtual void ProcessInputEvents()                   zCall( 0x004C8BA0 );

    // user API
    #include "zCInput_Win32.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZINPUT__WIN32_H__VER0__