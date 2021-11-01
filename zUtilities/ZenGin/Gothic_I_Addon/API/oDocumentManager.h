// Supported with union (c) 2018-2021 Union team

#ifndef __ODOCUMENT_MANAGER_H__VER1__
#define __ODOCUMENT_MANAGER_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 0Ch
  class oCDocumentManager : public zCInputCallback {
  public:
    zCListSort<oCViewDocument>* ListDocuments; // sizeof 04h    offset 04h
    zCViewDialog* DlgDocumentMain;             // sizeof 04h    offset 08h

    void oCDocumentManager_OnInit( oCDocumentManager const& )             zCall( 0x00761170 );
    void oCDocumentManager_OnInit()                                       zCall( 0x00761190 );

  private:
    oCDocumentManager& operator =( oCDocumentManager const& )             zCall( 0x00761160 );
    oCDocumentManager( oCDocumentManager const& a0 )                      zInit( oCDocumentManager_OnInit( a0 ));
    oCDocumentManager()                                                   zInit( oCDocumentManager_OnInit() );

  public:
    ~oCDocumentManager()                                                  zCall( 0x00761350 );
    int __fastcall CreateDocument()                                       zCall( 0x00761420 );
    int __fastcall CreateMap()                                            zCall( 0x00761630 );
    void __fastcall SetPages( int, int )                                  zCall( 0x00761840 );
    void __fastcall SetPage( int, int, zSTRING&, int )                    zCall( 0x00761870 );
    void __fastcall SetFont( int, int, zSTRING& )                         zCall( 0x007618B0 );
    void __fastcall SetMargins( int, int, zCPosition&, zCPosition&, int ) zCall( 0x007618F0 );
    void __fastcall SetLevel( int, zSTRING const& )                       zCall( 0x00761930 );
    void __fastcall PrintLine( int, int, zSTRING& )                       zCall( 0x00761AB0 );
    void __fastcall PrintLines( int, int, zSTRING& )                      zCall( 0x00761AF0 );
    void __fastcall Show( int )                                           zCall( 0x00761B30 );
    int __fastcall GetNextAvailableID()                                   zCall( 0x00761BF0 );
    oCViewDocument* __fastcall GetDocumentView( int )                     zCall( 0x00761C10 );
    void __fastcall UpdateMap( int )                                      zCall( 0x00761C30 );
    static oCDocumentManager& GetDocumentManager()                        zCall( 0x00761110 );
    virtual int HandleEvent( int )                                        zCall( 0x00761C80 );

    // user API
    #include "oCDocumentManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ODOCUMENT_MANAGER_H__VER1__