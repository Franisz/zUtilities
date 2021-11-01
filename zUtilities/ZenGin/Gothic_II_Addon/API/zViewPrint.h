// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_PRINT_H__VER3__
#define __ZVIEW_PRINT_H__VER3__

namespace Gothic_II_Addon {

  // sizeof ECh
  class zCViewPrint : public zCViewFX {
  public:
    zCLASS_DECLARATION( zCViewPrint )

    typedef enum zEViewAlignment {
      VIEW_ALIGN_NONE,
      VIEW_ALIGN_MAX,
      VIEW_ALIGN_MIN,
      VIEW_ALIGN_CENTER
    } zTViewAlign;

    zCArray<zCViewText2*> ListTextLines; // sizeof 0Ch    offset ACh
    zCViewFont ViewFont;                 // sizeof 14h    offset B8h
    zPOS PositionCursor;                 // sizeof 08h    offset CCh
    zPOS OffsetTextPixel;                // sizeof 08h    offset D4h
    zPOS SizeMargin[2];                  // sizeof 10h    offset DCh

    void zCViewPrint_OnInit()                                                    zCall( 0x00693200 );
    zCViewPrint()                                                                zInit( zCViewPrint_OnInit() );
    void __fastcall SizeHeightToContent( int )                                   zCall( 0x00693400 );
    void __fastcall GetPixelBorder( zCPosition&, zCPosition& )                   zCall( 0x00693880 );
    void __fastcall ClearText()                                                  zCall( 0x006938E0 );
    void __fastcall Print( zSTRING& )                                            zCall( 0x00693970 );
    void __fastcall PrintLine( zSTRING& )                                        zCall( 0x00693A50 );
    void __fastcall PrintLines( zSTRING& )                                       zCall( 0x00693C00 );
    void __fastcall AddText( zCViewText2* )                                      zCall( 0x00694070 );
    void __fastcall RemoveText( zCViewText2* )                                   zCall( 0x00694180 );
    void __fastcall RemoveAllTexts()                                             zCall( 0x006941E0 );
    static zCObject* _CreateNewInstance()                                        zCall( 0x00693180 );
    /* for zCObject num : 10*/
    virtual zCClassDef* _GetClassDef() const                                     zCall( 0x006932D0 );
    virtual ~zCViewPrint()                                                       zCall( 0x00693310 );
    virtual void __fastcall Blit()                                               zCall( 0x006934A0 );
    virtual void __fastcall BlitText()                                           zCall( 0x006934E0 );
    virtual void __fastcall BlitTextLine( zCViewText2* )                         zCall( 0x00693590 );
    virtual void __fastcall BlitTextCharacters( zCViewText2*, zCFont*, zCOLOR& ) zCall( 0x00693650 );
    /* for zCViewBase num : 9*/

    // user API
    #include "zCViewPrint.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVIEW_PRINT_H__VER3__