// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_OBJECT_H__VER2__
#define __ZVIEW_OBJECT_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 08h
  typedef class zCPosition {
  public:
    long X; // sizeof 04h    offset 00h
    long Y; // sizeof 04h    offset 04h

    zCPosition() {}
    zCPosition& operator-= ( zCPosition& ) zCall( 0x00771540 );
    zCPosition& operator+= ( zCPosition& ) zCall( 0x007A2390 );
  } zPOS;

  // sizeof 5Ch
  class zCViewObject : public zCObject, public zCViewBase {
  public:
    zCLASS_DECLARATION( zCViewObject )

    zPOS VirtualPosition;                  // sizeof 08h    offset 28h
    zPOS VirtualSize;                      // sizeof 08h    offset 30h
    zPOS PixelPosition;                    // sizeof 08h    offset 38h
    zPOS PixelSize;                        // sizeof 08h    offset 40h
    unsigned long ID;                      // sizeof 04h    offset 48h
    zCViewObject* ViewParent;              // sizeof 04h    offset 4Ch
    zCListSort<zCViewObject> ListChildren; // sizeof 0Ch    offset 50h

    void zCViewObject_OnInit()                                         zCall( 0x007A1B00 );
    zCViewObject()                                                     zInit( zCViewObject_OnInit() );
    void __fastcall AddChild( zCViewObject* )                          zCall( 0x007A1D50 );
    void __fastcall AddChild( zCViewObject& )                          zCall( 0x007A1D70 );
    void __fastcall AddChildren( zCListSort<zCViewObject>& )           zCall( 0x007A1D90 );
    void __fastcall RemoveChild( zCViewObject* )                       zCall( 0x007A1E00 );
    void __fastcall RemoveChild( zCViewObject& )                       zCall( 0x007A1E80 );
    void __fastcall RemoveAllChildren()                                zCall( 0x007A1F00 );
    zCViewObject const* __fastcall GetChild( unsigned long )           zCall( 0x007A1FD0 );
    void __fastcall SetVirtualPosition( zCPosition& )                  zCall( 0x007A2030 );
    void __fastcall SetPixelPosition( zCPosition& )                    zCall( 0x007A20F0 );
    void __fastcall SetVirtualSize( zCPosition& )                      zCall( 0x007A21B0 );
    void __fastcall SetPixelSize( zCPosition& )                        zCall( 0x007A23B0 );
    void __fastcall EvaluatePixelPosition( zCPosition& )               zCall( 0x007A25B0 );
    void __fastcall EvaluatePixelSize( zCPosition& )                   zCall( 0x007A2610 );
    void __fastcall UpdatePixelPosition()                              zCall( 0x007A26B0 );
    void __fastcall UpdatePixelSize()                                  zCall( 0x007A2760 );
    void __fastcall UpdatePixelPositionChildren()                      zCall( 0x007A2850 );
    void __fastcall UpdatePixelSizeChildren()                          zCall( 0x007A2910 );
    void __fastcall UpdatePixelDimensionsChildren()                    zCall( 0x007A2A00 );
    zCPosition __fastcall ConvertPositionVirtualToPixel( zCPosition& ) zCall( 0x007A2BA0 );
    zCPosition __fastcall ConvertSizeVirtualToPixel( zCPosition& )     zCall( 0x007A2BE0 );
    zCPosition __fastcall ConvertPositionPixelToVirtual( zCPosition& ) zCall( 0x007A2C20 );
    zCPosition __fastcall ConvertSizePixelToVirtual( zCPosition& )     zCall( 0x007A2C70 );
    zCPosition __fastcall ConvertToPixel( zCPosition& )                zCall( 0x007A2CC0 );
    zCPosition __fastcall ConvertToPixelLocal( zCPosition& )           zCall( 0x007A2D20 );
    zCPosition __fastcall ConvertToVirtualLocal( zCPosition& )         zCall( 0x007A2D60 );
    static zCObject* _CreateNewInstance()                              zCall( 0x007A1A80 );
    static int Compare( zCViewObject*, zCViewObject* )                 zCall( 0x007A1BF0 );
    /* for zCObject num : 4*/
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x007A1BE0 );
    virtual ~zCViewObject()                                            zCall( 0x007A1C30 );
    /* for zCViewBase num : 9*/
    virtual int anx( int )                                             zCall( 0x007A2DF0 );
    virtual int any( int )                                             zCall( 0x007A2E10 );
    virtual int nax( int )                                             zCall( 0x007A2DB0 );
    virtual int nay( int )                                             zCall( 0x007A2DD0 );
    virtual int ClipLine( int&, int&, int&, int& )                     zCall( 0x007A2E30 );
    virtual void Line( int, int, int, int, zCOLOR const& )             zCall( 0x007A2FE0 );
    virtual void __fastcall GetViewport( int&, int&, int&, int& )      zCall( 0x007A2580 );
    virtual int GetCode( int, int )                                    zCall( 0x007A3090 );

    // user API
    #include "zCViewObject.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVIEW_OBJECT_H__VER2__