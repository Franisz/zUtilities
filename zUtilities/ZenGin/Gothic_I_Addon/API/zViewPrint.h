// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIEW_PRINT_H__VER1__
#define __ZVIEW_PRINT_H__VER1__

namespace Gothic_I_Addon {

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

    void zCViewPrint_OnInit()                                                    zCall( 0x00798B50 );
    zCViewPrint()                                                                zInit( zCViewPrint_OnInit() );
    void __fastcall SizeHeightToContent( int )                                   zCall( 0x00798D50 );
    void __fastcall GetPixelBorder( zCPosition&, zCPosition& )                   zCall( 0x007991A0 );
    void __fastcall ClearText()                                                  zCall( 0x00799200 );
    void __fastcall Print( zSTRING& )                                            zCall( 0x00799290 );
    void __fastcall PrintLine( zSTRING& )                                        zCall( 0x00799380 );
    void __fastcall PrintLines( zSTRING& )                                       zCall( 0x00799560 );
    void __fastcall AddText( zCViewText2* )                                      zCall( 0x00799950 );
    void __fastcall RemoveText( zCViewText2* )                                   zCall( 0x00799A80 );
    void __fastcall RemoveAllTexts()                                             zCall( 0x00799AE0 );
    static zCObject* _CreateNewInstance()                                        zCall( 0x00798AC0 );
    /* for zCObject num : 10*/
    virtual zCClassDef* _GetClassDef() const                                     zCall( 0x00798C20 );
    virtual ~zCViewPrint()                                                       zCall( 0x00798C60 );
    virtual void __fastcall Blit()                                               zCall( 0x00798DF0 );
    virtual void __fastcall BlitText()                                           zCall( 0x00798E30 );
    virtual void __fastcall BlitTextLine( zCViewText2* )                         zCall( 0x00798EE0 );
    virtual void __fastcall BlitTextCharacters( zCViewText2*, zCFont*, zCOLOR& ) zCall( 0x00798FB0 );
    /* for zCViewBase num : 8*/

    // user API
    #include "zCViewPrint.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZVIEW_PRINT_H__VER1__