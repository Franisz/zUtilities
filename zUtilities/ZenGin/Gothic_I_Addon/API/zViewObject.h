// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_OBJECT_H__VER1__
#define __ZVIEW_OBJECT_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 08h
  typedef class zCPosition {
  public:
    long X; // sizeof 04h    offset 00h
    long Y; // sizeof 04h    offset 04h

    zCPosition() {}
    zCPosition& operator-= ( zCPosition& ) zCall( 0x00762DC0 );
    zCPosition& operator+= ( zCPosition& ) zCall( 0x00797A20 );
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

    void zCViewObject_OnInit()                                          zCall( 0x007971E0 );
    zCViewObject()                                                      zInit( zCViewObject_OnInit() );
    void __fastcall AddChild( zCViewObject* )                           zCall( 0x00797440 );
    void __fastcall AddChild( zCViewObject& )                           zCall( 0x00797460 );
    void __fastcall AddChildren( zCListSort<zCViewObject>& )            zCall( 0x00797480 );
    void __fastcall RemoveChild( zCViewObject* )                        zCall( 0x007974E0 );
    void __fastcall RemoveChild( zCViewObject& )                        zCall( 0x00797540 );
    void __fastcall RemoveAllChildren()                                 zCall( 0x007975A0 );
    zCViewObject const* __fastcall GetChild( unsigned long )            zCall( 0x00797670 );
    void __fastcall SetVirtualPosition( zCPosition& )                   zCall( 0x007976C0 );
    void __fastcall SetPixelPosition( zCPosition& )                     zCall( 0x00797770 );
    void __fastcall SetVirtualSize( zCPosition& )                       zCall( 0x00797840 );
    void __fastcall SetPixelSize( zCPosition& )                         zCall( 0x00797A40 );
    void __fastcall EvaluatePixelPosition( zCPosition& )                zCall( 0x00797C40 );
    void __fastcall EvaluatePixelSize( zCPosition& )                    zCall( 0x00797CA0 );
    void __fastcall UpdatePixelPosition()                               zCall( 0x00797D40 );
    void __fastcall UpdatePixelSize()                                   zCall( 0x00797DE0 );
    void __fastcall UpdatePixelPositionChildren()                       zCall( 0x00797ED0 );
    void __fastcall UpdatePixelSizeChildren()                           zCall( 0x00797F90 );
    void __fastcall UpdatePixelDimensionsChildren()                     zCall( 0x00798090 );
    zCPosition __fastcall ConvertPositionVirtualToPixel( zCPosition& )  zCall( 0x00798240 );
    zCPosition __fastcall ConvertSizeVirtualToPixel( zCPosition& )      zCall( 0x00798290 );
    zCPosition __fastcall ConvertPositionPixelToVirtual( zCPosition& )  zCall( 0x007982E0 );
    zCPosition __fastcall ConvertSizePixelToVirtual( zCPosition& )      zCall( 0x00798330 );
    zCPosition __fastcall ConvertToPixel( zCPosition& )                 zCall( 0x00798380 );
    zCPosition __fastcall ConvertToPixelLocal( zCPosition& )            zCall( 0x007983E0 );
    zCPosition __fastcall ConvertToVirtualLocal( zCPosition& )          zCall( 0x00798430 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00797150 );
    static int Compare( zCViewObject*, zCViewObject* )                  zCall( 0x007972D0 );
    /* for zCObject num : 4*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x007972C0 );
    virtual ~zCViewObject()                                             zCall( 0x00797310 );
    /* for zCViewBase num : 8*/
    virtual int anx( int )                                              zCall( 0x007984C0 );
    virtual int any( int )                                              zCall( 0x007984E0 );
    virtual int nax( int )                                              zCall( 0x00798480 );
    virtual int nay( int )                                              zCall( 0x007984A0 );
    virtual int ClipLine( int&, int&, int&, int& )                      zCall( 0x00798500 );
    virtual void Line( int, int, int, int, zCOLOR const& )              zCall( 0x007986B0 );
    virtual void __fastcall GetViewport( int&, int&, int&, int& )       zCall( 0x00797C10 );
    virtual int GetCode( int, int )                                     zCall( 0x00798760 );

    // user API
    #include "zCViewObject.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZVIEW_OBJECT_H__VER1__