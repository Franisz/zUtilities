// Supported with union (c) 2018 Union team

#ifndef __OVIEW_DOCUMENT_H__VER3__
#define __OVIEW_DOCUMENT_H__VER3__

namespace Gothic_II_Addon {

  class oCViewDocument : public zCViewDialog {
  public:
    int Pages;

    void oCViewDocument_OnInit( zSTRING& )                           zCall( 0x0068C2C0 );
    void oCViewDocument_OnInit()                                     zCall( 0x0068C620 );
    oCViewDocument( zSTRING& a0 )                                    zInit( oCViewDocument_OnInit( a0 ));
    oCViewDocument()                                                 zInit( oCViewDocument_OnInit() );
    oCViewDocument* __fastcall GetPage( int )                        zCall( 0x0068C670 );
    void __fastcall SetPages( int )                                  zCall( 0x0068C6A0 );
    void __fastcall SetMargins( int, zCPosition&, zCPosition&, int ) zCall( 0x0068C7F0 );
    void __fastcall SetFont( int, zSTRING& )                         zCall( 0x0068CAF0 );
    void __fastcall PrintLine( int, zSTRING& )                       zCall( 0x0068CBB0 );
    void __fastcall PrintLines( int, zSTRING& )                      zCall( 0x0068CC70 );
    void __fastcall SetTexture( zSTRING&, int )                      zCall( 0x0068CD30 );
    void __fastcall AlignPageToParent()                              zCall( 0x0068CDA0 );
    void __fastcall Center()                                         zCall( 0x0068CF30 );
    void __fastcall SizeToContent()                                  zCall( 0x0068CFA0 );
    void __fastcall SizeToParent()                                   zCall( 0x0068D050 );
    void __fastcall ScaleToParent()                                  zCall( 0x0068D090 );
    /* for zCObject num : 16*/
    virtual ~oCViewDocument()                                        zCall( 0x0068C650 );
    virtual oCViewDocument* __fastcall SetPage( int, zSTRING&, int ) zCall( 0x0068C970 );
    /* for zCViewBase num : 9*/
    /* for oCViewDocument num : 1*/

    // user API
    #include "oCViewDocument.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OVIEW_DOCUMENT_H__VER3__