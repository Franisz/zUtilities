// Supported with union (c) 2018-2021 Union team

#ifndef __ZINPUT_H__VER2__
#define __ZINPUT_H__VER2__

#include "zInput_Const.h"

namespace Gothic_II_Classic {

  enum zTInputDevice {
    zINPUT_UNDEF,
    zINPUT_KEYBOARD,
    zINPUT_MOUSE,
    zINPUT_JOYSTICK1,
    zINPUT_JOYSTICK2,
    zINPUT_JOYSTICK3,
    zINPUT_JOYSTICK4
  };

  // sizeof 14h
  struct zSKeyMapping {
    unsigned short logicalID;              // sizeof 02h    offset 00h
    zCArray<unsigned short> controlValues; // sizeof 0Ch    offset 04h
    int set;                               // sizeof 04h    offset 10h

    zSKeyMapping() {}
    ~zSKeyMapping() zCall( 0x004C9CD0 );

    // user API
    #include "zSKeyMapping.inl"
  };

  // sizeof 18h
  struct zSCtrlValue {
    zSTRING name;         // sizeof 14h    offset 00h
    unsigned short value; // sizeof 02h    offset 14h

    void zSCtrlValue_OnInit() zCall( 0x004CFAE0 );
    ~zSCtrlValue()            zCall( 0x004CD650 );
    zSCtrlValue()             zInit( zSCtrlValue_OnInit() );

    // user API
    #include "zSCtrlValue.inl"
  };

  // sizeof 14h
  class zCInput {
  public:
    zCArraySort<zSKeyMapping*> mapList; // sizeof 10h    offset 04h

    void zCInput_OnInit()                                               zCall( 0x004C95F0 );
    zCInput()                                                           zInit( zCInput_OnInit() );
    void Bind( unsigned short, zCArray<unsigned short> const& )         zCall( 0x004C98F0 );
    void BindOption( zSTRING, unsigned short, zCArray<unsigned short> ) zCall( 0x004C9AB0 );
    void Unbind( unsigned short )                                       zCall( 0x004C9CF0 );
    int IsBinded( unsigned short, unsigned short )                      zCall( 0x004C9E00 );
    int IsBindedToggled( unsigned short, unsigned short )               zCall( 0x004C9F00 );
    int GetBinding( unsigned short, zCArray<unsigned short>& )          zCall( 0x004C9F40 );
    unsigned short GetFirstBindedLogicalKey( unsigned short )           zCall( 0x004CA060 );
    void InitializeControlValues()                                      zCall( 0x004CA0D0 );
    void BindKeys( int )                                                zCall( 0x004CD890 );
    static int CompareKeyMaps( void const*, void const* )               zCall( 0x004C98D0 );
    static unsigned short GetControlValueByName( zSTRING const& )       zCall( 0x004CF060 );
    static zSTRING GetNameByControlValue( unsigned short )              zCall( 0x004CF110 );
    virtual ~zCInput()                                                  zCall( 0x004C9830 );
    virtual float GetState( unsigned short )                            zCall( 0x004C9650 );
    virtual int SetState( unsigned short, int )                         zCall( 0x004C9660 );
    virtual int GetToggled( unsigned short )                            zCall( 0x004C9670 );
    virtual void SetDeviceEnabled( zTInputDevice, int )                 zCall( 0x004C9680 );
    virtual int GetDeviceEnabled( zTInputDevice )                       zCall( 0x004C9690 );
    virtual int GetDeviceConnected( zTInputDevice )                     zCall( 0x004C96A0 );
    virtual int KeyPressed( int )                                       zCall( 0x004C96B0 );
    virtual int KeyToggled( int )                                       zCall( 0x004C96C0 );
    virtual int AnyKeyPressed()                                         zCall( 0x004C96D0 );
    virtual void ResetRepeatKey( int )                                  zCall( 0x004C96E0 );
    virtual unsigned short GetKey( int, int )                           zCall( 0x004C96F0 );
    virtual void SetKey( int, int )                                     zCall( 0x004C9700 );
    virtual unsigned char GetChar()                                     zCall( 0x004C9710 );
    virtual void ClearKeyBuffer()                                       zCall( 0x004C9720 );
    virtual int GetNumJoysConnected()                                   zCall( 0x004C9730 );
    virtual void SetJoyDigitalEmu( int )                                zCall( 0x004C9740 );
    virtual void SetJoyEnabled( int )                                   zCall( 0x004C9750 );
    virtual float JoyState( int )                                       zCall( 0x004C9760 );
    virtual float JoyState( int, int )                                  zCall( 0x004C9770 );
    virtual void GetMousePos( float&, float&, float& )                  zCall( 0x004C9780 );
    virtual int GetMouseButtonPressedLeft()                             zCall( 0x004C9790 );
    virtual int GetMouseButtonPressedMid()                              zCall( 0x004C97A0 );
    virtual int GetMouseButtonPressedRight()                            zCall( 0x004C97B0 );
    virtual void SetMouseSensitivity( float, float )                    zCall( 0x004C97C0 );
    virtual void GetMouseSensitivity( float&, float& )                  zCall( 0x004C97D0 );
    virtual int GetMouseIdle() const                                    zCall( 0x004C97E0 );
    virtual void SetMouseFlipXY( int, int )                             zCall( 0x004C97F0 );
    virtual void GetMouseFlipXY( int&, int& )                           zCall( 0x004C9800 );
    virtual void ProcessInputEvents()                                   zPureCall;

    // other
    bool GetMouseButtonToggledLeft() {
      static bool pressed = false;
      if( !pressed ) {
        if( GetMouseButtonPressedLeft() ) {
          pressed = true;
          return true;
        }
      }
      else {
        if( !GetMouseButtonPressedLeft() )
          pressed = false;
      }

      return false;
    }

    bool GetMouseButtonToggledMid() {
      static bool pressed = false;
      if( !pressed ) {
        if( GetMouseButtonPressedMid() ) {
          pressed = true;
          return true;
        }
      }
      else {
        if( !GetMouseButtonPressedMid() )
          pressed = false;
      }

      return false;
    }

    bool GetMouseButtonToggledRight() {
      static bool pressed = false;
      if( !pressed ) {
        if( GetMouseButtonPressedRight() ) {
          pressed = true;
          return true;
        }
      }
      else {
        if( !GetMouseButtonPressedRight() )
          pressed = false;
      }

      return false;
    }

    // static properties
    static zCArray<zSCtrlValue>& values;

    // user API
    #include "zCInput.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZINPUT_H__VER2__