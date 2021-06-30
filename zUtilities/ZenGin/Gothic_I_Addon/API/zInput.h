// Supported with union (c) 2018 Union team

#ifndef __ZINPUT_H__VER1__
#define __ZINPUT_H__VER1__

namespace Gothic_I_Addon {

  enum zTInputDevice {
    zINPUT_UNDEF,
    zINPUT_KEYBOARD,
    zINPUT_MOUSE,
    zINPUT_JOYSTICK1,
    zINPUT_JOYSTICK2,
    zINPUT_JOYSTICK3,
    zINPUT_JOYSTICK4
  };

  struct zSKeyMapping {
    unsigned short logicalID;
    zCArray<unsigned short> controlValues;
    int set;

    zSKeyMapping() {}
    ~zSKeyMapping() zCall( 0x004D2860 );

    // user API
    #include "zSKeyMapping.inl"
  };

  struct zSCtrlValue {
    zSTRING name;
    unsigned short value;

    void zSCtrlValue_OnInit()                     zCall( 0x004D6FD0 );
    ~zSCtrlValue()                                zCall( 0x004D53D0 );
    zSCtrlValue& operator =( zSCtrlValue const& ) zCall( 0x004D6C70 );
    zSCtrlValue()                                 zInit( zSCtrlValue_OnInit() );

    // user API
    #include "zSCtrlValue.inl"
  };

  class zCInput {
  public:
    zCArraySort<zSKeyMapping*> mapList;

    void zCInput_OnInit()                                               zCall( 0x004D2130 );
    zCInput()                                                           zInit( zCInput_OnInit() );
    void Bind( unsigned short, zCArray<unsigned short> const& )         zCall( 0x004D2420 );
    void BindOption( zSTRING, unsigned short, zCArray<unsigned short> ) zCall( 0x004D2610 );
    void Unbind( unsigned short )                                       zCall( 0x004D2880 );
    int IsBinded( unsigned short, unsigned short )                      zCall( 0x004D29A0 );
    int IsBindedToggled( unsigned short, unsigned short )               zCall( 0x004D2AB0 );
    int GetBinding( unsigned short, zCArray<unsigned short>& )          zCall( 0x004D2AF0 );
    unsigned short GetFirstBindedLogicalKey( unsigned short )           zCall( 0x004D2C30 );
    void InitializeControlValues()                                      zCall( 0x004D2C90 );
    void BindKeys( int )                                                zCall( 0x004D5420 );
    static int CompareKeyMaps( void const*, void const* )               zCall( 0x004D2400 );
    static unsigned short GetControlValueByName( zSTRING const& )       zCall( 0x004D63A0 );
    static zSTRING GetNameByControlValue( unsigned short )              zCall( 0x004D6440 );
    virtual ~zCInput()                                                  zCall( 0x004D2360 );
    virtual float GetState( unsigned short )                            zCall( 0x004D2190 );
    virtual int SetState( unsigned short, int )                         zCall( 0x004D21A0 );
    virtual int GetToggled( unsigned short )                            zCall( 0x004D21B0 );
    virtual void SetDeviceEnabled( zTInputDevice, int )                 zCall( 0x004D21C0 );
    virtual int GetDeviceEnabled( zTInputDevice )                       zCall( 0x004D21D0 );
    virtual int GetDeviceConnected( zTInputDevice )                     zCall( 0x004D21E0 );
    virtual int KeyPressed( int )                                       zCall( 0x004D21F0 );
    virtual int KeyToggled( int )                                       zCall( 0x004D2200 );
    virtual int AnyKeyPressed()                                         zCall( 0x004D2210 );
    virtual void ResetRepeatKey( int )                                  zCall( 0x004D2220 );
    virtual unsigned short GetKey( int, int )                           zCall( 0x004D2230 );
    virtual void SetKey( int, int )                                     zCall( 0x004D2240 );
    virtual char GetChar()                                              zCall( 0x004D2250 );
    virtual void ClearKeyBuffer()                                       zCall( 0x004D2260 );
    virtual int GetNumJoysConnected()                                   zCall( 0x004D2270 );
    virtual void SetJoyDigitalEmu( int )                                zCall( 0x004D2280 );
    virtual void SetJoyEnabled( int )                                   zCall( 0x004D2290 );
    virtual float JoyState( int )                                       zCall( 0x004D22A0 );
    virtual float JoyState( int, int )                                  zCall( 0x004D22B0 );
    virtual void GetMousePos( float&, float&, float& )                  zCall( 0x004D22C0 );
    virtual int GetMouseButtonPressedLeft()                             zCall( 0x004D22D0 );
    virtual int GetMouseButtonPressedMid()                              zCall( 0x004D22E0 );
    virtual int GetMouseButtonPressedRight()                            zCall( 0x004D22F0 );
    virtual void SetMouseSensitivity( float, float )                    zCall( 0x004D2300 );
    virtual void GetMouseSensitivity( float&, float& )                  zCall( 0x004D2310 );
    virtual void SetMouseFlipXY( int, int )                             zCall( 0x004D2320 );
    virtual void GetMouseFlipXY( int&, int& )                           zCall( 0x004D2330 );
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

} // namespace Gothic_I_Addon

#endif // __ZINPUT_H__VER1__