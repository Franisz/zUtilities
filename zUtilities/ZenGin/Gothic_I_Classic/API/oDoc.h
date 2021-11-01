// Supported with union (c) 2018-2021 Union team

#ifndef __ODOC_H__VER0__
#define __ODOC_H__VER0__

#include "zViewBase.h"
#include "zView.h"

namespace Gothic_I_Classic {

  // sizeof 130h
  class oCDoc : public zCView {
  public:
    zSTRING levelName;         // sizeof 14h    offset FCh
    float scalex;              // sizeof 04h    offset 110h
    float scaley;              // sizeof 04h    offset 114h
    float map_gameCoPerPixelx; // sizeof 04h    offset 118h
    float map_gameStartx;      // sizeof 04h    offset 11Ch
    float map_gameCoPerPixely; // sizeof 04h    offset 120h
    float map_gameStarty;      // sizeof 04h    offset 124h
    float pixelStartx;         // sizeof 04h    offset 128h
    float pixelStarty;         // sizeof 04h    offset 12Ch

    oCDoc() {}
    void oCDoc_OnInit( zSTRING const& )                                               zCall( 0x006343C0 );
    oCDoc( zSTRING const& a0 )                                                        zInit( oCDoc_OnInit( a0 ));
    void Show()                                                                       zCall( 0x00634760 );
    void MapInitCoordinates( float, float, float, float, float, float, float, float ) zCall( 0x006347A0 );
    void MapDrawCoordinates( float, float )                                           zCall( 0x00634800 );
    void SetLevelName( zSTRING const& )                                               zCall( 0x00634AE0 );
    /* for zCViewBase num : 11*/
    virtual ~oCDoc()                                                                  zCall( 0x00634670 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                                                    zCall( 0x00634770 );

    // static properties
    static zCView*& posView;

    // user API
    #include "oCDoc.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ODOC_H__VER0__