// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_BASE_H__VER0__
#define __ZVIEW_BASE_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 04h
  class zCViewBase {
  public:

    void zCViewBase_OnInit()                                      zCall( 0x00752E70 );
    zCViewBase()                                                  zInit( zCViewBase_OnInit() );
    ~zCViewBase()                                                 zCall( 0x00752F00 );
    virtual int anx( int )                                        zCall( 0x00752E80 );
    virtual int any( int )                                        zCall( 0x00752E90 );
    virtual int nax( int )                                        zCall( 0x00752EA0 );
    virtual int nay( int )                                        zCall( 0x00752EB0 );
    virtual int ClipLine( int&, int&, int&, int& )                zCall( 0x00752EC0 );
    virtual void Line( int, int, int, int, zCOLOR const& )        zCall( 0x00752ED0 );
    virtual void __fastcall GetViewport( int&, int&, int&, int& ) zCall( 0x00752EE0 );
    virtual int GetCode( int, int )                               zCall( 0x00752EF0 );

    // static properties
    static const unsigned short& ViewVirtualWidth;
    static const unsigned short& ViewVirtualHeight;

    // user API
    #include "zCViewBase.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZVIEW_BASE_H__VER0__