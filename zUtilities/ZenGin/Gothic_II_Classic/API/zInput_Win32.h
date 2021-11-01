// Supported with union (c) 2018-2021 Union team

#ifndef __ZINPUT__WIN32_H__VER2__
#define __ZINPUT__WIN32_H__VER2__

#include "zInput.h"
#include "zInput_Const.h"

namespace Gothic_II_Classic {

  // sizeof 58h
  class zCInput_Win32 : public zCInput {
  public:
    zCTimer m_kbdTimer;             // sizeof 28h    offset 14h
    float m_fKeyRepeatDelay;        // sizeof 04h    offset 3Ch
    float m_fKeyRepeatTime;         // sizeof 04h    offset 40h
    float m_fKeyRepeatTimeMod;      // sizeof 04h    offset 44h
    float m_fKeyRepeatCounter;      // sizeof 04h    offset 48h
    float m_fKeyRepeatCounterDelay; // sizeof 04h    offset 4Ch
    int m_bMouseIdle;               // sizeof 04h    offset 50h
    unsigned short m_iLastKey;      // sizeof 02h    offset 54h

    zCInput_Win32() {}
    void zCInput_Win32_OnInit( HWND__** )               zCall( 0x004D2450 );
    void SetFocusWindow( HWND__* )                      zCall( 0x004D2440 );
    zCInput_Win32( HWND__** a0 )                        zInit( zCInput_Win32_OnInit( a0 ));
    void SetAutoRepeatDelayRate( float, float )         zCall( 0x004D2D40 );
    float GetAutoRepeatDelayRate()                      zCall( 0x004D2D60 );
    virtual ~zCInput_Win32()                            zCall( 0x004D2710 );
    virtual float GetState( unsigned short )            zCall( 0x004D2770 );
    virtual int SetState( unsigned short, int )         zCall( 0x004D2840 );
    virtual int GetToggled( unsigned short )            zCall( 0x004D2A60 );
    virtual void SetDeviceEnabled( zTInputDevice, int ) zCall( 0x004D2B40 );
    virtual int GetDeviceEnabled( zTInputDevice )       zCall( 0x004D2BA0 );
    virtual int GetDeviceConnected( zTInputDevice )     zCall( 0x004D2BD0 );
    virtual int KeyPressed( int )                       zCall( 0x004D2C00 );
    virtual int KeyToggled( int )                       zCall( 0x004D2C10 );
    virtual int AnyKeyPressed()                         zCall( 0x004D2C30 );
    virtual void ResetRepeatKey( int )                  zCall( 0x004D2D70 );
    virtual unsigned short GetKey( int, int )           zCall( 0x004D2DB0 );
    virtual void SetKey( int, int )                     zCall( 0x004D2F10 );
    virtual unsigned char GetChar()                     zCall( 0x004D2F50 );
    virtual void ClearKeyBuffer()                       zCall( 0x004D3010 );
    virtual void GetMousePos( float&, float&, float& )  zCall( 0x004D3170 );
    virtual int GetMouseButtonPressedLeft()             zCall( 0x004D31D0 );
    virtual int GetMouseButtonPressedMid()              zCall( 0x004D31E0 );
    virtual int GetMouseButtonPressedRight()            zCall( 0x004D31F0 );
    virtual void SetMouseSensitivity( float, float )    zCall( 0x004D3200 );
    virtual void GetMouseSensitivity( float&, float& )  zCall( 0x004D3250 );
    virtual int GetMouseIdle() const                    zCall( 0x004D26E0 );
    virtual void SetMouseFlipXY( int, int )             zCall( 0x004D3270 );
    virtual void GetMouseFlipXY( int&, int& )           zCall( 0x004D3290 );
    virtual void ProcessInputEvents()                   zCall( 0x004D3140 );

    // user API
    #include "zCInput_Win32.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZINPUT__WIN32_H__VER2__