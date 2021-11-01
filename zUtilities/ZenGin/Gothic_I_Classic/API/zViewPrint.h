// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_PRINT_H__VER0__
#define __ZVIEW_PRINT_H__VER0__

namespace Gothic_I_Classic {

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

    void zCViewPrint_OnInit()                                                    zCall( 0x007566D0 );
    zCViewPrint()                                                                zInit( zCViewPrint_OnInit() );
    void __fastcall SizeHeightToContent( int )                                   zCall( 0x007568D0 );
    void __fastcall GetPixelBorder( zCPosition&, zCPosition& )                   zCall( 0x00756D10 );
    void __fastcall ClearText()                                                  zCall( 0x00756D70 );
    void __fastcall Print( zSTRING& )                                            zCall( 0x00756E00 );
    void __fastcall PrintLine( zSTRING& )                                        zCall( 0x00756EF0 );
    void __fastcall PrintLines( zSTRING& )                                       zCall( 0x007570D0 );
    void __fastcall AddText( zCViewText2* )                                      zCall( 0x00757460 );
    void __fastcall RemoveText( zCViewText2* )                                   zCall( 0x00757590 );
    void __fastcall RemoveAllTexts()                                             zCall( 0x007575F0 );
    static zCObject* _CreateNewInstance()                                        zCall( 0x00756640 );
    /* for zCObject num : 10*/
    virtual zCClassDef* _GetClassDef() const                                     zCall( 0x007567A0 );
    virtual ~zCViewPrint()                                                       zCall( 0x007567E0 );
    virtual void __fastcall Blit()                                               zCall( 0x00756970 );
    virtual void __fastcall BlitText()                                           zCall( 0x007569B0 );
    virtual void __fastcall BlitTextLine( zCViewText2* )                         zCall( 0x00756A60 );
    virtual void __fastcall BlitTextCharacters( zCViewText2*, zCFont*, zCOLOR& ) zCall( 0x00756B20 );
    /* for zCViewBase num : 8*/

    // user API
    #include "zCViewPrint.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZVIEW_PRINT_H__VER0__