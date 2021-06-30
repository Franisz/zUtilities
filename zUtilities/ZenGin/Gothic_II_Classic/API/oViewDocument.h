// Supported with union (c) 2018 Union team

#ifndef __OVIEW_DOCUMENT_H__VER2__
#define __OVIEW_DOCUMENT_H__VER2__

namespace Gothic_II_Classic {

  class oCViewDocument : public zCViewDialog {
  public:
    int Pages;

    void oCViewDocument_OnInit( zSTRING& )                           zCall( 0x00771240 );
    void oCViewDocument_OnInit()                                     zCall( 0x007715F0 );
    oCViewDocument( zSTRING& a0 )                                    zInit( oCViewDocument_OnInit( a0 ));
    oCViewDocument()                                                 zInit( oCViewDocument_OnInit() );
    oCViewDocument* __fastcall GetPage( int )                        zCall( 0x00771640 );
    void __fastcall SetPages( int )                                  zCall( 0x00771670 );
    void __fastcall SetMargins( int, zCPosition&, zCPosition&, int ) zCall( 0x007717C0 );
    void __fastcall SetFont( int, zSTRING& )                         zCall( 0x00771AC0 );
    void __fastcall PrintLine( int, zSTRING& )                       zCall( 0x00771B80 );
    void __fastcall PrintLines( int, zSTRING& )                      zCall( 0x00771C40 );
    void __fastcall SetTexture( zSTRING&, int )                      zCall( 0x00771D00 );
    void __fastcall AlignPageToParent()                              zCall( 0x00771D70 );
    void __fastcall Center()                                         zCall( 0x00771F00 );
    void __fastcall SizeToContent()                                  zCall( 0x00771F70 );
    void __fastcall SizeToParent()                                   zCall( 0x00772020 );
    void __fastcall ScaleToParent()                                  zCall( 0x00772060 );
    /* for zCObject num : 16*/
    virtual ~oCViewDocument()                                        zCall( 0x00771620 );
    virtual oCViewDocument* __fastcall SetPage( int, zSTRING&, int ) zCall( 0x00771940 );
    /* for zCViewBase num : 9*/
    /* for oCViewDocument num : 1*/

    // user API
    #include "oCViewDocument.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OVIEW_DOCUMENT_H__VER2__