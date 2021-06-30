// Supported with union (c) 2018 Union team

#ifndef __ODOC_H__VER2__
#define __ODOC_H__VER2__

#include "zViewBase.h"

namespace Gothic_II_Classic {

  class oCDoc : public zCView {
  public:
    zSTRING levelName;
    float scalex;
    float scaley;
    float map_gameCoPerPixelx;
    float map_gameStartx;
    float map_gameCoPerPixely;
    float map_gameStarty;
    float pixelStartx;
    float pixelStarty;

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