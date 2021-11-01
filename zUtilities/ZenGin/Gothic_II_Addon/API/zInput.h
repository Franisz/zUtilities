// Supported with union (c) 2018-2021 Union team

#ifndef __ZINPUT_H__VER3__
#define __ZINPUT_H__VER3__

namespace Gothic_II_Addon {

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
    ~zSKeyMapping() zCall( 0x004CC240 );

    // user API
    #include "zSKeyMapping.inl"
  };

  // sizeof 18h
  struct zSCtrlValue {
    zSTRING name;         // sizeof 14h    offset 00h
    unsigned short value; // sizeof 02h    offset 14h

    void zSCtrlValue_OnInit() zCall( 0x004D20A0 );
    ~zSCtrlValue()            zCall( 0x004CFBB0 );
    zSCtrlValue()             zInit( zSCtrlValue_OnInit() );

    // user API
    #include "zSCtrlValue.inl"
  };

  // sizeof 14h
  class zCInput {
  public:
    zCArraySort<zSKeyMapping*> mapList; // sizeof 10h    offset 04h

    void zCInput_OnInit()                                               zCall( 0x004CBB60 );
    zCInput()                                                           zInit( zCInput_OnInit() );
    void Bind( unsigned short, zCArray<unsigned short> const& )         zCall( 0x004CBE60 );
    void BindOption( zSTRING, unsigned short, zCArray<unsigned short> ) zCall( 0x004CC020 );
    void Unbind( unsigned short )                                       zCall( 0x004CC260 );
    int IsBinded( unsigned short, unsigned short )                      zCall( 0x004CC370 );
    int IsBindedToggled( unsigned short, unsigned short )               zCall( 0x004CC470 );
    int GetBinding( unsigned short, zCArray<unsigned short>& )          zCall( 0x004CC4B0 );
    unsigned short GetFirstBindedLogicalKey( unsigned short )           zCall( 0x004CC5D0 );
    void InitializeControlValues()                                      zCall( 0x004CC640 );
    void BindKeys( int )                                                zCall( 0x004CFE00 );
    static int CompareKeyMaps( void const*, void const* )               zCall( 0x004CBE40 );
    static unsigned short GetControlValueByName( zSTRING const& )       zCall( 0x004D15D0 );
    static zSTRING GetNameByControlValue( unsigned short )              zCall( 0x004D1680 );
    virtual ~zCInput()                                                  zCall( 0x004CBDA0 );
    virtual float GetState( unsigned short )                            zCall( 0x004CBBC0 );
    virtual int SetState( unsigned short, int )                         zCall( 0x004CBBD0 );
    virtual int GetToggled( unsigned short )                            zCall( 0x004CBBE0 );
    virtual void SetDeviceEnabled( zTInputDevice, int )                 zCall( 0x004CBBF0 );
    virtual int GetDeviceEnabled( zTInputDevice )                       zCall( 0x004CBC00 );
    virtual int GetDeviceConnected( zTInputDevice )                     zCall( 0x004CBC10 );
    virtual int KeyPressed( int )                                       zCall( 0x004CBC20 );
    virtual int KeyToggled( int )                                       zCall( 0x004CBC30 );
    virtual int AnyKeyPressed()                                         zCall( 0x004CBC40 );
    virtual void ResetRepeatKey( int )                                  zCall( 0x004CBC50 );
    virtual unsigned short GetKey( int, int )                           zCall( 0x004CBC60 );
    virtual void SetKey( int, int )                                     zCall( 0x004CBC70 );
    virtual unsigned char GetChar()                                     zCall( 0x004CBC80 );
    virtual void ClearKeyBuffer()                                       zCall( 0x004CBC90 );
    virtual int GetNumJoysConnected()                                   zCall( 0x004CBCA0 );
    virtual void SetJoyDigitalEmu( int )                                zCall( 0x004CBCB0 );
    virtual void SetJoyEnabled( int )                                   zCall( 0x004CBCC0 );
    virtual float JoyState( int )                                       zCall( 0x004CBCD0 );
    virtual float JoyState( int, int )                                  zCall( 0x004CBCE0 );
    virtual void GetMousePos( float&, float&, float& )                  zCall( 0x004CBCF0 );
    virtual int GetMouseButtonPressedLeft()                             zCall( 0x004CBD00 );
    virtual int GetMouseButtonPressedMid()                              zCall( 0x004CBD10 );
    virtual int GetMouseButtonPressedRight()                            zCall( 0x004CBD20 );
    virtual void SetMouseSensitivity( float, float )                    zCall( 0x004CBD30 );
    virtual void GetMouseSensitivity( float&, float& )                  zCall( 0x004CBD40 );
    virtual int GetMouseIdle() const                                    zCall( 0x004CBD50 );
    virtual void SetMouseFlipXY( int, int )                             zCall( 0x004CBD60 );
    virtual void GetMouseFlipXY( int&, int& )                           zCall( 0x004CBD70 );
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

} // namespace Gothic_II_Addon

#endif // __ZINPUT_H__VER3__