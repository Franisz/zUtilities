// Supported with union (c) 2018-2021 Union team

#ifndef __ZINPUT__WIN32_H__VER3__
#define __ZINPUT__WIN32_H__VER3__

#include "zInput.h"

namespace Gothic_II_Addon {

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
    void zCInput_Win32_OnInit( HWND__** )               zCall( 0x004D4A10 );
    void SetFocusWindow( HWND__* )                      zCall( 0x004D4A00 );
    zCInput_Win32( HWND__** a0 )                        zInit( zCInput_Win32_OnInit( a0 ));
    void SetAutoRepeatDelayRate( float, float )         zCall( 0x004D5300 );
    float GetAutoRepeatDelayRate()                      zCall( 0x004D5320 );
    virtual ~zCInput_Win32()                            zCall( 0x004D4CD0 );
    virtual float GetState( unsigned short )            zCall( 0x004D4D30 );
    virtual int SetState( unsigned short, int )         zCall( 0x004D4E00 );
    virtual int GetToggled( unsigned short )            zCall( 0x004D5020 );
    virtual void SetDeviceEnabled( zTInputDevice, int ) zCall( 0x004D5100 );
    virtual int GetDeviceEnabled( zTInputDevice )       zCall( 0x004D5160 );
    virtual int GetDeviceConnected( zTInputDevice )     zCall( 0x004D5190 );
    virtual int KeyPressed( int )                       zCall( 0x004D51C0 );
    virtual int KeyToggled( int )                       zCall( 0x004D51D0 );
    virtual int AnyKeyPressed()                         zCall( 0x004D51F0 );
    virtual void ResetRepeatKey( int )                  zCall( 0x004D5330 );
    virtual unsigned short GetKey( int, int )           zCall( 0x004D5370 );
    virtual void SetKey( int, int )                     zCall( 0x004D54D0 );
    virtual unsigned char GetChar()                     zCall( 0x004D5510 );
    virtual void ClearKeyBuffer()                       zCall( 0x004D55D0 );
    virtual void GetMousePos( float&, float&, float& )  zCall( 0x004D5730 );
    virtual int GetMouseButtonPressedLeft()             zCall( 0x004D5790 );
    virtual int GetMouseButtonPressedMid()              zCall( 0x004D57A0 );
    virtual int GetMouseButtonPressedRight()            zCall( 0x004D57B0 );
    virtual void SetMouseSensitivity( float, float )    zCall( 0x004D57C0 );
    virtual void GetMouseSensitivity( float&, float& )  zCall( 0x004D5810 );
    virtual int GetMouseIdle() const                    zCall( 0x004D4CA0 );
    virtual void SetMouseFlipXY( int, int )             zCall( 0x004D5830 );
    virtual void GetMouseFlipXY( int&, int& )           zCall( 0x004D5850 );
    virtual void ProcessInputEvents()                   zCall( 0x004D5700 );

    // user API
    #include "zCInput_Win32.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZINPUT__WIN32_H__VER3__