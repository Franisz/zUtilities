// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_BASE_H__VER1__
#define __ZVIEW_BASE_H__VER1__

namespace Gothic_I_Addon {

  class zCViewBase {
  public:

    void zCViewBase_OnInit()                                      zCall( 0x007952F0 );
    zCViewBase()                                                  zInit( zCViewBase_OnInit() );
    ~zCViewBase()                                                 zCall( 0x00795380 );
    virtual int anx( int )                                        zCall( 0x00795300 );
    virtual int any( int )                                        zCall( 0x00795310 );
    virtual int nax( int )                                        zCall( 0x00795320 );
    virtual int nay( int )                                        zCall( 0x00795330 );
    virtual int ClipLine( int&, int&, int&, int& )                zCall( 0x00795340 );
    virtual void Line( int, int, int, int, zCOLOR const& )        zCall( 0x00795350 );
    virtual void __fastcall GetViewport( int&, int&, int&, int& ) zCall( 0x00795360 );
    virtual int GetCode( int, int )                               zCall( 0x00795370 );

    // static properties
    static const unsigned short& ViewVirtualWidth;
    static const unsigned short& ViewVirtualHeight;

    // user API
    #include "zCViewBase.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZVIEW_BASE_H__VER1__