// Supported with union (c) 2018-2021 Union team

#ifndef __OVIEW_DOCUMENT_MAP_H__VER0__
#define __OVIEW_DOCUMENT_MAP_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 210h
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

    void oCViewDocumentMap_OnInit()                                  zCall( 0x00725D20 );
    oCViewDocumentMap()                                              zInit( oCViewDocumentMap_OnInit() );
    void __fastcall UpdatePosition()                                 zCall( 0x00726030 );
    /* for zCObject num : 16*/
    virtual ~oCViewDocumentMap()                                     zCall( 0x00725E90 );
    virtual oCViewDocument* __fastcall SetPage( int, zSTRING&, int ) zCall( 0x00725F40 );
    /* for zCViewBase num : 8*/
    /* for oCViewDocumentMap num : 1*/

    // user API
    #include "oCViewDocumentMap.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OVIEW_DOCUMENT_MAP_H__VER0__