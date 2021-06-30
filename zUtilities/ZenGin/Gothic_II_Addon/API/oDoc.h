// Supported with union (c) 2018 Union team

#ifndef __ODOC_H__VER3__
#define __ODOC_H__VER3__

#include "zViewBase.h"

namespace Gothic_II_Addon {

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
    void oCDoc_OnInit( zSTRING const& )                                               zCall( 0x006BDF80 );
    oCDoc( zSTRING const& a0 )                                                        zInit( oCDoc_OnInit( a0 ));
    void Show()                                                                       zCall( 0x006BE320 );
    void MapInitCoordinates( float, float, float, float, float, float, float, float ) zCall( 0x006BE360 );
    void MapDrawCoordinates( float, float )                                           zCall( 0x006BE3C0 );
    void SetLevelName( zSTRING const& )                                               zCall( 0x006BE690 );
    /* for zCViewBase num : 12*/
    virtual ~oCDoc()                                                                  zCall( 0x006BE230 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                                                    zCall( 0x006BE330 );

    // static properties
    static zCView*& posView;

    // user API
    #include "oCDoc.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ODOC_H__VER3__