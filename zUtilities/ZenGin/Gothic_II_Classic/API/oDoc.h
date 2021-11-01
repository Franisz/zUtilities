// Supported with union (c) 2018-2021 Union team

#ifndef __ODOC_H__VER2__
#define __ODOC_H__VER2__

#include "zViewBase.h"

namespace Gothic_II_Classic {

  // sizeof 134h
  class oCDoc : public zCView {
  public:
    zSTRING levelName;         // sizeof 14h    offset 100h
    float scalex;              // sizeof 04h    offset 114h
    float scaley;              // sizeof 04h    offset 118h
    float map_gameCoPerPixelx; // sizeof 04h    offset 11Ch
    float map_gameStartx;      // sizeof 04h    offset 120h
    float map_gameCoPerPixely; // sizeof 04h    offset 124h
    float map_gameStarty;      // sizeof 04h    offset 128h
    float pixelStartx;         // sizeof 04h    offset 12Ch
    float pixelStarty;         // sizeof 04h    offset 130h

    oCDoc() {}
    void oCDoc_OnInit( zSTRING const& )                                               zCall( 0x006615F0 );
    oCDoc( zSTRING const& a0 )                                                        zInit( oCDoc_OnInit( a0 ));
    void Show()                                                                       zCall( 0x00661990 );
    void MapInitCoordinates( float, float, float, float, float, float, float, float ) zCall( 0x006619D0 );
    void MapDrawCoordinates( float, float )                                           zCall( 0x00661A30 );
    void SetLevelName( zSTRING const& )                                               zCall( 0x00661D00 );
    /* for zCViewBase num : 12*/
    virtual ~oCDoc()                                                                  zCall( 0x006618A0 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                                                    zCall( 0x006619A0 );

    // static properties
    static zCView*& posView;

    // user API
    #include "oCDoc.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ODOC_H__VER2__