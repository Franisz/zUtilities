// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_OBJECT_H__VER0__
#define __ZVIEW_OBJECT_H__VER0__

namespace Gothic_I_Classic {

  typedef class zCPosition {
  public:
    long X;
    long Y;

    zCPosition() {}
    zCPosition& operator-= ( zCPosition& ) zCall( 0x00725B30 );
    zCPosition& operator+= ( zCPosition& ) zCall( 0x007555F0 );
  } zPOS;

  class zCViewObject : public zCObject, public zCViewBase {
  public:
    zCLASS_DECLARATION( zCViewObject )

    zPOS VirtualPosition;
    zPOS VirtualSize;
    zPOS PixelPosition;
    zPOS PixelSize;
    unsigned long ID;
    zCViewObject* ViewParent;
    zCListSort<zCViewObject> ListChildren;

    void zCViewObject_OnInit()                                          zCall( 0x00754D60 );
    zCViewObject()                                                      zInit( zCViewObject_OnInit() );
    void __fastcall AddChild( zCViewObject* )                           zCall( 0x00754FB0 );
    void __fastcall AddChild( zCViewObject& )                           zCall( 0x00754FD0 );
    void __fastcall AddChildren( zCListSort<zCViewObject>& )            zCall( 0x00754FF0 );
    void __fastcall RemoveChild( zCViewObject* )                        zCall( 0x00755060 );
    void __fastcall RemoveChild( zCViewObject& )                        zCall( 0x007550E0 );
    void __fastcall RemoveAllChildren()                                 zCall( 0x00755160 );
    zCViewObject const* __fastcall GetChild( unsigned long )            zCall( 0x00755230 );
    void __fastcall SetVirtualPosition( zCPosition& )                   zCall( 0x00755290 );
    void __fastcall SetPixelPosition( zCPosition& )                     zCall( 0x00755350 );
    void __fastcall SetVirtualSize( zCPosition& )                       zCall( 0x00755410 );
    void __fastcall SetPixelSize( zCPosition& )                         zCall( 0x00755610 );
    void __fastcall EvaluatePixelPosition( zCPosition& )                zCall( 0x00755810 );
    void __fastcall EvaluatePixelSize( zCPosition& )                    zCall( 0x00755870 );
    void __fastcall UpdatePixelPosition()                               zCall( 0x00755910 );
    void __fastcall UpdatePixelSize()                                   zCall( 0x007559C0 );
    void __fastcall UpdatePixelPositionChildren()                       zCall( 0x00755AB0 );
    void __fastcall UpdatePixelSizeChildren()                           zCall( 0x00755B70 );
    void __fastcall UpdatePixelDimensionsChildren()                     zCall( 0x00755C60 );
    zCPosition __fastcall ConvertPositionVirtualToPixel( zCPosition& )  zCall( 0x00755E00 );
    zCPosition __fastcall ConvertSizeVirtualToPixel( zCPosition& )      zCall( 0x00755E40 );
    zCPosition __fastcall ConvertPositionPixelToVirtual( zCPosition& )  zCall( 0x00755E80 );
    zCPosition __fastcall ConvertSizePixelToVirtual( zCPosition& )      zCall( 0x00755ED0 );
    zCPosition __fastcall ConvertToPixel( zCPosition& )                 zCall( 0x00755F20 );
    zCPosition __fastcall ConvertToPixelLocal( zCPosition& )            zCall( 0x00755F80 );
    zCPosition __fastcall ConvertToVirtualLocal( zCPosition& )          zCall( 0x00755FC0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00754CD0 );
    static int Compare( zCViewObject*, zCViewObject* )                  zCall( 0x00754E50 );
    /* for zCObject num : 4*/
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00754E40 );
    virtual ~zCViewObject()                                             zCall( 0x00754E90 );
    /* for zCViewBase num : 8*/
    virtual int anx( int )                                              zCall( 0x00756050 );
    virtual int any( int )                                              zCall( 0x00756070 );
    virtual int nax( int )                                              zCall( 0x00756010 );
    virtual int nay( int )                                              zCall( 0x00756030 );
    virtual int ClipLine( int&, int&, int&, int& )                      zCall( 0x00756090 );
    virtual void Line( int, int, int, int, zCOLOR const& )              zCall( 0x00756240 );
    virtual void __fastcall GetViewport( int&, int&, int&, int& )       zCall( 0x007557E0 );
    virtual int GetCode( int, int )                                     zCall( 0x007562F0 );

    // user API
    #include "zCViewObject.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZVIEW_OBJECT_H__VER0__