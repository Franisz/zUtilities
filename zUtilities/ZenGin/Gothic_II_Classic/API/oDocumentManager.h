// Supported with union (c) 2018 Union team

#ifndef __ODOCUMENT_MANAGER_H__VER2__
#define __ODOCUMENT_MANAGER_H__VER2__

namespace Gothic_II_Classic {

  class oCDocumentManager : public zCInputCallback {
  public:
    zCListSort<oCViewDocument>* ListDocuments;
    zCViewDialog* DlgDocumentMain;

    void oCDocumentManager_OnInit( oCDocumentManager const& )             zCall( 0x00770550 );
    void oCDocumentManager_OnInit()                                       zCall( 0x00770570 );
    oCDocumentManager& operator =( oCDocumentManager const& )             zCall( 0x00770540 );
    oCDocumentManager( oCDocumentManager const& a0 )                      zInit( oCDocumentManager_OnInit( a0 ));
    oCDocumentManager()                                                   zInit( oCDocumentManager_OnInit() );
    ~oCDocumentManager()                                                  zCall( 0x00770700 );
    int __fastcall CreateDocument()                                       zCall( 0x007707D0 );
    int __fastcall CreateMap()                                            zCall( 0x007709A0 );
    void __fastcall SetPages( int, int )                                  zCall( 0x00770B70 );
    void __fastcall SetPage( int, int, zSTRING&, int )                    zCall( 0x00770BB0 );
    void __fastcall SetFont( int, int, zSTRING& )                         zCall( 0x00770BF0 );
    void __fastcall SetMargins( int, int, zCPosition&, zCPosition&, int ) zCall( 0x00770C30 );
    void __fastcall SetLevel( int, zSTRING const& )                       zCall( 0x00770C80 );
    void __fastcall SetLevelCoords( int, int, int, int, int )             zCall( 0x00770CD0 );
    void __fastcall PrintLine( int, int, zSTRING& )                       zCall( 0x00770D30 );
    void __fastcall PrintLines( int, int, zSTRING& )                      zCall( 0x00770D70 );
    void __fastcall Show( int )                                           zCall( 0x00770DB0 );
    int __fastcall GetNextAvailableID()                                   zCall( 0x00770E60 );
    oCViewDocument* __fastcall GetDocumentView( int )                     zCall( 0x00770E80 );
    void __fastcall UpdateMap( int )                                      zCall( 0x00770EB0 );
    static oCDocumentManager& GetDocumentManager()                        zCall( 0x007704F0 );
    virtual int HandleEvent( int )                                        zCall( 0x00770F00 );

    // user API
    #include "oCDocumentManager.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ODOCUMENT_MANAGER_H__VER2__