// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_OBJECT_H__VER3__
#define __ZVIEW_OBJECT_H__VER3__

namespace Gothic_II_Addon {

  // sizeof 08h
  typedef class zCPosition {
  public:
    long X; // sizeof 04h    offset 00h
    long Y; // sizeof 04h    offset 04h

    zCPosition() {}
    zCPosition& operator-= ( zCPosition& ) zCall( 0x0068C5C0 );
    zCPosition& operator+= ( zCPosition& ) zCall( 0x00692140 );
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

    void zCViewObject_OnInit()                                         zCall( 0x006918B0 );
    zCViewObject()                                                     zInit( zCViewObject_OnInit() );
    void __fastcall AddChild( zCViewObject* )                          zCall( 0x00691B00 );
    void __fastcall AddChild( zCViewObject& )                          zCall( 0x00691B20 );
    void __fastcall AddChildren( zCListSort<zCViewObject>& )           zCall( 0x00691B40 );
    void __fastcall RemoveChild( zCViewObject* )                       zCall( 0x00691BB0 );
    void __fastcall RemoveChild( zCViewObject& )                       zCall( 0x00691C30 );
    void __fastcall RemoveAllChildren()                                zCall( 0x00691CB0 );
    zCViewObject const* __fastcall GetChild( unsigned long )           zCall( 0x00691D80 );
    void __fastcall SetVirtualPosition( zCPosition& )                  zCall( 0x00691DE0 );
    void __fastcall SetPixelPosition( zCPosition& )                    zCall( 0x00691EA0 );
    void __fastcall SetVirtualSize( zCPosition& )                      zCall( 0x00691F60 );
    void __fastcall SetPixelSize( zCPosition& )                        zCall( 0x00692160 );
    void __fastcall EvaluatePixelPosition( zCPosition& )               zCall( 0x00692360 );
    void __fastcall EvaluatePixelSize( zCPosition& )                   zCall( 0x006923C0 );
    void __fastcall UpdatePixelPosition()                              zCall( 0x00692460 );
    void __fastcall UpdatePixelSize()                                  zCall( 0x00692510 );
    void __fastcall UpdatePixelPositionChildren()                      zCall( 0x00692600 );
    void __fastcall UpdatePixelSizeChildren()                          zCall( 0x006926C0 );
    void __fastcall UpdatePixelDimensionsChildren()                    zCall( 0x006927B0 );
    zCPosition __fastcall ConvertPositionVirtualToPixel( zCPosition& ) zCall( 0x00692950 );
    zCPosition __fastcall ConvertSizeVirtualToPixel( zCPosition& )     zCall( 0x00692990 );
    zCPosition __fastcall ConvertPositionPixelToVirtual( zCPosition& ) zCall( 0x006929D0 );
    zCPosition __fastcall ConvertSizePixelToVirtual( zCPosition& )     zCall( 0x00692A20 );
    zCPosition __fastcall ConvertToPixel( zCPosition& )                zCall( 0x00692A70 );
    zCPosition __fastcall ConvertToPixelLocal( zCPosition& )           zCall( 0x00692AD0 );
    zCPosition __fastcall ConvertToVirtualLocal( zCPosition& )         zCall( 0x00692B10 );
    static zCObject* _CreateNewInstance()                              zCall( 0x00691830 );
    static int Compare( zCViewObject*, zCViewObject* )                 zCall( 0x006919A0 );
    /* for zCObject num : 4*/
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x00691990 );
    virtual ~zCViewObject()                                            zCall( 0x006919E0 );
    /* for zCViewBase num : 9*/
    virtual int anx( int )                                             zCall( 0x00692BA0 );
    virtual int any( int )                                             zCall( 0x00692BC0 );
    virtual int nax( int )                                             zCall( 0x00692B60 );
    virtual int nay( int )                                             zCall( 0x00692B80 );
    virtual int ClipLine( int&, int&, int&, int& )                     zCall( 0x00692BE0 );
    virtual void Line( int, int, int, int, zCOLOR const& )             zCall( 0x00692D90 );
    virtual void __fastcall GetViewport( int&, int&, int&, int& )      zCall( 0x00692330 );
    virtual int GetCode( int, int )                                    zCall( 0x00692E40 );

    // user API
    #include "zCViewObject.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVIEW_OBJECT_H__VER3__