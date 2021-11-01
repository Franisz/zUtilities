// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_DOCUMENT_H__VER1__
#define __OVIEW_DOCUMENT_H__VER1__

namespace Gothic_I_Addon {

  // sizeof FCh
  class oCViewDocument : public zCViewDialog {
  public:
    int Pages; // sizeof 04h    offset F8h

    void oCViewDocument_OnInit( zSTRING& )                           zCall( 0x00762080 );
    void oCViewDocument_OnInit()                                     zCall( 0x007623E0 );
    oCViewDocument( zSTRING& a0 )                                    zInit( oCViewDocument_OnInit( a0 ));
    oCViewDocument()                                                 zInit( oCViewDocument_OnInit() );
    oCViewDocument* __fastcall GetPage( int )                        zCall( 0x00762430 );
    void __fastcall SetPages( int )                                  zCall( 0x00762460 );
    void __fastcall SetMargins( int, zCPosition&, zCPosition&, int ) zCall( 0x007625F0 );
    void __fastcall SetFont( int, zSTRING& )                         zCall( 0x00762960 );
    void __fastcall PrintLine( int, zSTRING& )                       zCall( 0x00762A20 );
    void __fastcall PrintLines( int, zSTRING& )                      zCall( 0x00762AD0 );
    void __fastcall SetTexture( zSTRING&, int )                      zCall( 0x00762B80 );
    void __fastcall AlignPageToParent()                              zCall( 0x00762C30 );
    void __fastcall Center()                                         zCall( 0x00762DE0 );
    void __fastcall SizeToContent()                                  zCall( 0x00762E50 );
    void __fastcall SizeToParent()                                   zCall( 0x00762EA0 );
    void __fastcall ScaleToParent()                                  zCall( 0x00762EF0 );
    /* for zCObject num : 16*/
    virtual ~oCViewDocument()                                        zCall( 0x00762410 );
    virtual oCViewDocument* __fastcall SetPage( int, zSTRING&, int ) zCall( 0x00762760 );
    /* for zCViewBase num : 8*/
    /* for oCViewDocument num : 1*/

    // user API
    #include "oCViewDocument.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OVIEW_DOCUMENT_H__VER1__