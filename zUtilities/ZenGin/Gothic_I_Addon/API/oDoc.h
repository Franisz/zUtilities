// Supported with union (c) 2018 Union team

#ifndef __ODOC_H__VER1__
#define __ODOC_H__VER1__

#include "zViewBase.h"

namespace Gothic_I_Addon {

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
    void oCDoc_OnInit( zSTRING const& )                                               zCall( 0x0065A510 );
    oCDoc( zSTRING const& a0 )                                                        zInit( oCDoc_OnInit( a0 ));
    void Show()                                                                       zCall( 0x0065A8C0 );
    void MapInitCoordinates( float, float, float, float, float, float, float, float ) zCall( 0x0065A900 );
    void MapDrawCoordinates( float, float )                                           zCall( 0x0065A960 );
    void SetLevelName( zSTRING const& )                                               zCall( 0x0065AC70 );
    /* for zCViewBase num : 11*/
    virtual ~oCDoc()                                                                  zCall( 0x0065A7D0 );
    /* for zCInputCallback num : 1*/
    virtual int HandleEvent( int )                                                    zCall( 0x0065A8D0 );

    // static properties
    static zCView*& posView;

    // user API
    #include "oCDoc.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ODOC_H__VER1__