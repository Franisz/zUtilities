// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_BASE_H__VER3__
#define __ZVIEW_BASE_H__VER3__

namespace Gothic_II_Addon {

  class zCViewBase {
  public:

    void zCViewBase_OnInit()                                      zCall( 0x0068DEE0 );
    zCViewBase()                                                  zInit( zCViewBase_OnInit() );
    ~zCViewBase()                                                 zCall( 0x0068DF70 );
    virtual int anx( int )                                        zCall( 0x0068DEF0 );
    virtual int any( int )                                        zCall( 0x0068DF00 );
    virtual int nax( int )                                        zCall( 0x0068DF10 );
    virtual int nay( int )                                        zCall( 0x0068DF20 );
    virtual int ClipLine( int&, int&, int&, int& )                zCall( 0x0068DF30 );
    virtual void Line( int, int, int, int, zCOLOR const& )        zCall( 0x0068DF40 );
    virtual void __fastcall GetViewport( int&, int&, int&, int& ) zCall( 0x0068DF50 );
    virtual void FillZBuffer()                                    zCall( 0x0068DF80 );
    virtual int GetCode( int, int )                               zCall( 0x0068DF60 );

    // static properties
    static const unsigned short& ViewVirtualWidth;
    static const unsigned short& ViewVirtualHeight;

    // user API
    #include "zCViewBase.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVIEW_BASE_H__VER3__