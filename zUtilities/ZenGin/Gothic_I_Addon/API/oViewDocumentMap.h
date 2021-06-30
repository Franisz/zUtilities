// Supported with union (c) 2018 Union team

#ifndef __OVIEW_DOCUMENT_MAP_H__VER1__
#define __OVIEW_DOCUMENT_MAP_H__VER1__

namespace Gothic_I_Addon {

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

    void oCViewDocumentMap_OnInit()                                  zCall( 0x00763270 );
    oCViewDocumentMap()                                              zInit( oCViewDocumentMap_OnInit() );
    void __fastcall UpdatePosition()                                 zCall( 0x00763590 );
    /* for zCObject num : 16*/
    virtual ~oCViewDocumentMap()                                     zCall( 0x007633E0 );
    virtual oCViewDocument* __fastcall SetPage( int, zSTRING&, int ) zCall( 0x00763490 );
    /* for zCViewBase num : 8*/
    /* for oCViewDocumentMap num : 1*/

    // user API
    #include "oCViewDocumentMap.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OVIEW_DOCUMENT_MAP_H__VER1__