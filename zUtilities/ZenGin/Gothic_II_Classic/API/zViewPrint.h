// Supported with union (c) 2018 Union team

#ifndef __ZVIEW_PRINT_H__VER2__
#define __ZVIEW_PRINT_H__VER2__

namespace Gothic_II_Classic {

  class zCViewPrint : public zCViewFX {
  public:
    zCLASS_DECLARATION( zCViewPrint )

    typedef enum zEViewAlignment {
      VIEW_ALIGN_NONE,
      VIEW_ALIGN_MAX,
      VIEW_ALIGN_MIN,
      VIEW_ALIGN_CENTER
    } zTViewAlign;

    zCArray<zCViewText2*> ListTextLines;
    zCViewFont ViewFont;
    zPOS PositionCursor;
    zPOS OffsetTextPixel;
    zPOS SizeMargin[2];

    void zCViewPrint_OnInit()                                                    zCall( 0x007A3450 );
    zCViewPrint()                                                                zInit( zCViewPrint_OnInit() );
    void __fastcall SizeHeightToContent( int )                                   zCall( 0x007A3650 );
    void __fastcall GetPixelBorder( zCPosition&, zCPosition& )                   zCall( 0x007A3AD0 );
    void __fastcall ClearText()                                                  zCall( 0x007A3B30 );
    void __fastcall Print( zSTRING& )                                            zCall( 0x007A3BC0 );
    void __fastcall PrintLine( zSTRING& )                                        zCall( 0x007A3CA0 );
    void __fastcall PrintLines( zSTRING& )                                       zCall( 0x007A3E50 );
    void __fastcall AddText( zCViewText2* )                                      zCall( 0x007A42C0 );
    void __fastcall RemoveText( zCViewText2* )                                   zCall( 0x007A43D0 );
    void __fastcall RemoveAllTexts()                                             zCall( 0x007A4430 );
    static zCObject* _CreateNewInstance()                                        zCall( 0x007A33D0 );
    /* for zCObject num : 10*/
    virtual zCClassDef* _GetClassDef() const                                     zCall( 0x007A3520 );
    virtual ~zCViewPrint()                                                       zCall( 0x007A3560 );
    virtual void __fastcall Blit()                                               zCall( 0x007A36F0 );
    virtual void __fastcall BlitText()                                           zCall( 0x007A3730 );
    virtual void __fastcall BlitTextLine( zCViewText2* )                         zCall( 0x007A37E0 );
    virtual void __fastcall BlitTextCharacters( zCViewText2*, zCFont*, zCOLOR& ) zCall( 0x007A38A0 );
    /* for zCViewBase num : 9*/

    // user API
    #include "zCViewPrint.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVIEW_PRINT_H__VER2__