// Supported with union (c) 2018 Union team

#ifndef __ODOC_H__VER0__
#define __ODOC_H__VER0__

#include "zViewBase.h"
#include "zView.h"

namespace Gothic_I_Classic {

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