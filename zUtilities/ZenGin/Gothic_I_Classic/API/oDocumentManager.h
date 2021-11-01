// Supported with union (c) 2018-2021 Union team

#ifndef __ODOCUMENT_MANAGER_H__VER0__
#define __ODOCUMENT_MANAGER_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 0Ch
  class oCDocumentManager : public zCInputCallback {
  public:
    zCListSort<oCViewDocument>* ListDocuments; // sizeof 04h    offset 04h
    zCViewDialog* DlgDocumentMain;             // sizeof 04h    offset 08h

    void oCDocumentManager_OnInit( oCDocumentManager const& )             zCall( 0x00724230 );
    void oCDocumentManager_OnInit()                                       zCall( 0x00724250 );

  private:
    oCDocumentManager& operator =( oCDocumentManager const& )             zCall( 0x00724220 );
    oCDocumentManager( oCDocumentManager const& a0 )                      zInit( oCDocumentManager_OnInit( a0 ));
    oCDocumentManager()                                                   zInit( oCDocumentManager_OnInit() );

  public:
    ~oCDocumentManager()                                                  zCall( 0x00724400 );
    int __fastcall CreateDocument()                                       zCall( 0x007244D0 );
    int __fastcall CreateMap()                                            zCall( 0x007246D0 );
    void __fastcall SetPages( int, int )                                  zCall( 0x007248D0 );
    void __fastcall SetPage( int, int, zSTRING&, int )                    zCall( 0x00724910 );
    void __fastcall SetFont( int, int, zSTRING& )                         zCall( 0x00724950 );
    void __fastcall SetMargins( int, int, zCPosition&, zCPosition&, int ) zCall( 0x00724990 );
    void __fastcall SetLevel( int, zSTRING const& )                       zCall( 0x007249E0 );
    void __fastcall PrintLine( int, int, zSTRING& )                       zCall( 0x00724B60 );
    void __fastcall PrintLines( int, int, zSTRING& )                      zCall( 0x00724BA0 );
    void __fastcall Show( int )                                           zCall( 0x00724BE0 );
    int __fastcall GetNextAvailableID()                                   zCall( 0x00724C90 );
    oCViewDocument* __fastcall GetDocumentView( int )                     zCall( 0x00724CB0 );
    void __fastcall UpdateMap( int )                                      zCall( 0x00724CE0 );
    static oCDocumentManager& GetDocumentManager()                        zCall( 0x007241D0 );
    virtual int HandleEvent( int )                                        zCall( 0x00724D30 );

    // user API
    #include "oCDocumentManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ODOCUMENT_MANAGER_H__VER0__