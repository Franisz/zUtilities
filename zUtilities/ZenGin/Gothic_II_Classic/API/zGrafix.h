// Supported with union (c) 2018-2021 Union team

#ifndef __ZGRAFIX_H__VER2__
#define __ZGRAFIX_H__VER2__

#include "zTypes3d.h"
#include "zString.h"
#include "zDisk.h"

namespace Gothic_II_Classic {

  // sizeof 18h
  struct TGfx_Gfx {
  public:
    zSTRING* id;        // sizeof 04h    offset 00h
    int bpp;            // sizeof 04h    offset 04h
    int sx;             // sizeof 04h    offset 08h
    int sy;             // sizeof 04h    offset 0Ch
    int count;          // sizeof 04h    offset 10h
    unsigned char* scr; // sizeof 04h    offset 14h

    TGfx_Gfx() {}
  };

  // sizeof 08h
  class zCGfx {
  public:
    TGfx_Gfx* data; // sizeof 04h    offset 00h
    zCGfx* next;    // sizeof 04h    offset 04h

    zCGfx() {}
    void zCGfx_OnInit( zSTRING const& )                zCall( 0x0072AA70 );
    void zCGfx_OnInit( int, int )                      zCall( 0x0072AC30 );
    zCGfx( zSTRING const& a0 )                         zInit( zCGfx_OnInit( a0 ));
    zCGfx( int a0, int a1 )                            zInit( zCGfx_OnInit( a0, a1 ));
    ~zCGfx()                                           zCall( 0x0072AED0 );
    TGfx_Gfx* LoadRaw( zSTRING const&, int, int, int ) zCall( 0x0072B510 );
    unsigned char Readbyte( zFILE* )                   zCall( 0x0072B5B0 );
    TGfx_Gfx* LoadPcx( zSTRING const& )                zCall( 0x0072B620 );
    TGfx_Gfx* LoadTga( zSTRING const& )                zCall( 0x0072BAD0 );
    void SaveRaw( zSTRING const& )                     zCall( 0x0072CDB0 );
    void Save( zSTRING const& )                        zCall( 0x0072CE10 );
    TGfx_Gfx* LoadGfx( zSTRING const& )                zCall( 0x0072CFB0 );
    int GetSizex()                                     zCall( 0x0072D330 );
    int GetSizey()                                     zCall( 0x0072D340 );
    unsigned char* GetDataPtr()                        zCall( 0x0072D350 );
    int GetPixel( int, int )                           zCall( 0x0072D360 );
    static void Reload()                               zCall( 0x0072AF60 );

    // static properties
    static zCGfx*& Gfx_List;
    static int& gfxcount;

    // user API
    #include "zCGfx.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZGRAFIX_H__VER2__