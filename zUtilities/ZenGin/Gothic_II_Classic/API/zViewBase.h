// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_BASE_H__VER2__
#define __ZVIEW_BASE_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 04h
  class zCViewBase {
  public:

    void zCViewBase_OnInit()                                      zCall( 0x0079F8F0 );
    zCViewBase()                                                  zInit( zCViewBase_OnInit() );
    ~zCViewBase()                                                 zCall( 0x0079F980 );
    virtual int anx( int )                                        zCall( 0x0079F900 );
    virtual int any( int )                                        zCall( 0x0079F910 );
    virtual int nax( int )                                        zCall( 0x0079F920 );
    virtual int nay( int )                                        zCall( 0x0079F930 );
    virtual int ClipLine( int&, int&, int&, int& )                zCall( 0x0079F940 );
    virtual void Line( int, int, int, int, zCOLOR const& )        zCall( 0x0079F950 );
    virtual void __fastcall GetViewport( int&, int&, int&, int& ) zCall( 0x0079F960 );
    virtual void FillZBuffer()                                    zCall( 0x0079F990 );
    virtual int GetCode( int, int )                               zCall( 0x0079F970 );

    // static properties
    static const unsigned short& ViewVirtualWidth;
    static const unsigned short& ViewVirtualHeight;

    // user API
    #include "zCViewBase.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVIEW_BASE_H__VER2__