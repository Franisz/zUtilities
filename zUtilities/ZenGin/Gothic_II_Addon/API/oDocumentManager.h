// Supported with union (c) 2018-2021 Union team

#ifndef __ODOCUMENT_MANAGER_H__VER3__
#define __ODOCUMENT_MANAGER_H__VER3__

namespace Gothic_II_Addon {

  // sizeof 0Ch
  class oCDocumentManager : public zCInputCallback {
  public:
    zCListSort<oCViewDocument>* ListDocuments; // sizeof 04h    offset 04h
    zCViewDialog* DlgDocumentMain;             // sizeof 04h    offset 08h

    void oCDocumentManager_OnInit( oCDocumentManager const& )             zCall( 0x0065EAA0 );
    void oCDocumentManager_OnInit()                                       zCall( 0x0065EAC0 );

  private:
    oCDocumentManager& operator =( oCDocumentManager const& )             zCall( 0x0065EA90 );
    oCDocumentManager( oCDocumentManager const& a0 )                      zInit( oCDocumentManager_OnInit( a0 ));
    oCDocumentManager()                                                   zInit( oCDocumentManager_OnInit() );

  public:
    ~oCDocumentManager()                                                  zCall( 0x0065EC50 );
    int __fastcall CreateDocument()                                       zCall( 0x0065ED20 );
    int __fastcall CreateMap()                                            zCall( 0x0065EEF0 );
    void __fastcall SetPages( int, int )                                  zCall( 0x0065F0C0 );
    void __fastcall SetPage( int, int, zSTRING&, int )                    zCall( 0x0065F100 );
    void __fastcall SetFont( int, int, zSTRING& )                         zCall( 0x0065F140 );
    void __fastcall SetMargins( int, int, zCPosition&, zCPosition&, int ) zCall( 0x0065F180 );
    void __fastcall SetLevel( int, zSTRING const& )                       zCall( 0x0065F1D0 );
    void __fastcall SetLevelCoords( int, int, int, int, int )             zCall( 0x0065F220 );
    void __fastcall PrintLine( int, int, zSTRING& )                       zCall( 0x0065F280 );
    void __fastcall PrintLines( int, int, zSTRING& )                      zCall( 0x0065F2C0 );
    void __fastcall Show( int )                                           zCall( 0x0065F300 );
    int __fastcall GetNextAvailableID()                                   zCall( 0x0065F3B0 );
    oCViewDocument* __fastcall GetDocumentView( int )                     zCall( 0x0065F3D0 );
    void __fastcall UpdateMap( int )                                      zCall( 0x0065F400 );
    static oCDocumentManager& GetDocumentManager()                        zCall( 0x0065EA40 );
    virtual int HandleEvent( int )                                        zCall( 0x0065F450 );

    // user API
    #include "oCDocumentManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ODOCUMENT_MANAGER_H__VER3__