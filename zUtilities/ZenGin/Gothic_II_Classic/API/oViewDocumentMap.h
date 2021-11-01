// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_DOCUMENT_MAP_H__VER2__
#define __OVIEW_DOCUMENT_MAP_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 220h
  class oCViewDocumentMap : public oCViewDocument {
  public:
    typedef enum zEHeading {
      HEADING_NORTH,
      HEADING_NORTHEAST,
      HEADING_EAST,
      HEADING_SOUTHEAST,
      HEADING_SOUTH,
      HEADING_SOUTHWEST,
      HEADING_WEST,
      HEADING_NORTHWEST
    } zTHeading;

    oCViewDocument ViewArrow;    // sizeof FCh    offset FCh
    oCViewDocument* ViewPageMap; // sizeof 04h    offset 1F8h
    zSTRING Level;               // sizeof 14h    offset 1FCh
    zVEC4 LevelCoords;           // sizeof 10h    offset 210h

    void oCViewDocumentMap_OnInit()                                  zCall( 0x00772310 );
    oCViewDocumentMap()                                              zInit( oCViewDocumentMap_OnInit() );
    void __fastcall SetLevel( zSTRING const& )                       zCall( 0x007725E0 );
    void __fastcall SetLevelCoords( int, int, int, int )             zCall( 0x00772740 );
    void __fastcall UpdatePosition()                                 zCall( 0x00772780 );
    /* for zCObject num : 16*/
    virtual ~oCViewDocumentMap()                                     zCall( 0x00772440 );
    virtual oCViewDocument* __fastcall SetPage( int, zSTRING&, int ) zCall( 0x007724F0 );
    /* for zCViewBase num : 9*/
    /* for oCViewDocumentMap num : 1*/

    // user API
    #include "oCViewDocumentMap.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OVIEW_DOCUMENT_MAP_H__VER2__