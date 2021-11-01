// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_DOCUMENT_H__VER0__
#define __OVIEW_DOCUMENT_H__VER0__

namespace Gothic_I_Classic {

  // sizeof FCh
  class oCViewDocument : public zCViewDialog {
  public:
    int Pages; // sizeof 04h    offset F8h

    void oCViewDocument_OnInit( zSTRING& )                           zCall( 0x00724E90 );
    void oCViewDocument_OnInit()                                     zCall( 0x00725160 );
    oCViewDocument( zSTRING& a0 )                                    zInit( oCViewDocument_OnInit( a0 ));
    oCViewDocument()                                                 zInit( oCViewDocument_OnInit() );
    oCViewDocument* __fastcall GetPage( int )                        zCall( 0x007251B0 );
    void __fastcall SetPages( int )                                  zCall( 0x007251E0 );
    void __fastcall SetMargins( int, zCPosition&, zCPosition&, int ) zCall( 0x00725340 );
    void __fastcall SetFont( int, zSTRING& )                         zCall( 0x007256B0 );
    void __fastcall PrintLine( int, zSTRING& )                       zCall( 0x00725770 );
    void __fastcall PrintLines( int, zSTRING& )                      zCall( 0x00725830 );
    void __fastcall SetTexture( zSTRING&, int )                      zCall( 0x007258F0 );
    void __fastcall AlignPageToParent()                              zCall( 0x007259A0 );
    void __fastcall Center()                                         zCall( 0x00725B50 );
    void __fastcall SizeToContent()                                  zCall( 0x00725BC0 );
    void __fastcall SizeToParent()                                   zCall( 0x00725C10 );
    void __fastcall ScaleToParent()                                  zCall( 0x00725C50 );
    /* for zCObject num : 16*/
    virtual ~oCViewDocument()                                        zCall( 0x00725190 );
    virtual oCViewDocument* __fastcall SetPage( int, zSTRING&, int ) zCall( 0x007254C0 );
    /* for zCViewBase num : 8*/
    /* for oCViewDocument num : 1*/

    // user API
    #include "oCViewDocument.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OVIEW_DOCUMENT_H__VER0__