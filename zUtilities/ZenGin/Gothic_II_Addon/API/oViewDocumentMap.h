// Supported with union (c) 2018 Union team

#ifndef __OVIEW_DOCUMENT_MAP_H__VER3__
#define __OVIEW_DOCUMENT_MAP_H__VER3__

namespace Gothic_II_Addon {

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

    oCViewDocument ViewArrow;
    oCViewDocument* ViewPageMap;
    zSTRING Level;
    zVEC4 LevelCoords;

    void oCViewDocumentMap_OnInit()                                  zCall( 0x0068D340 );
    oCViewDocumentMap()                                              zInit( oCViewDocumentMap_OnInit() );
    void __fastcall SetLevel( zSTRING const& )                       zCall( 0x0068D610 );
    void __fastcall SetLevelCoords( int, int, int, int )             zCall( 0x0068D770 );
    void __fastcall UpdatePosition()                                 zCall( 0x0068D7B0 );
    /* for zCObject num : 16*/
    virtual ~oCViewDocumentMap()                                     zCall( 0x0068D470 );
    virtual oCViewDocument* __fastcall SetPage( int, zSTRING&, int ) zCall( 0x0068D520 );
    /* for zCViewBase num : 9*/
    /* for oCViewDocumentMap num : 1*/

    // user API
    #include "oCViewDocumentMap.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OVIEW_DOCUMENT_MAP_H__VER3__