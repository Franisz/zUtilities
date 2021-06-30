// Supported with union (c) 2018 Union team

#ifndef __ZGRAFIX_H__VER1__
#define __ZGRAFIX_H__VER1__

#include "zTypes3d.h"
#include "zString.h"
#include "zDisk.h"

namespace Gothic_I_Addon {

  struct TGfx_Gfx {
  public:
    zSTRING* id;
    int bpp;
    int sx;
    int sy;
    int count;
    unsigned char* scr;

    TGfx_Gfx() {}
  };

  class zCGfx {
  public:
    TGfx_Gfx* data;
    zCGfx* next;

    zCGfx() {}
    void zCGfx_OnInit( zSTRING const& )                zCall( 0x00719800 );
    void zCGfx_OnInit( int, int )                      zCall( 0x00719A20 );
    zCGfx( zSTRING const& a0 )                         zInit( zCGfx_OnInit( a0 ));
    zCGfx( int a0, int a1 )                            zInit( zCGfx_OnInit( a0, a1 ));
    ~zCGfx()                                           zCall( 0x00719CA0 );
    TGfx_Gfx* LoadRaw( zSTRING const&, int, int, int ) zCall( 0x0071A2E0 );
    unsigned char Readbyte( zFILE* )                   zCall( 0x0071A3A0 );
    TGfx_Gfx* LoadPcx( zSTRING const& )                zCall( 0x0071A410 );
    TGfx_Gfx* LoadTga( zSTRING const& )                zCall( 0x0071A950 );
    void SaveRaw( zSTRING const& )                     zCall( 0x0071BDE0 );
    void Save( zSTRING const& )                        zCall( 0x0071BE40 );
    TGfx_Gfx* LoadGfx( zSTRING const& )                zCall( 0x0071C000 );
    int GetSizex()                                     zCall( 0x0071C3D0 );
    int GetSizey()                                     zCall( 0x0071C3E0 );
    unsigned char* GetDataPtr()                        zCall( 0x0071C3F0 );
    int GetPixel( int, int )                           zCall( 0x0071C400 );
    static void Reload()                               zCall( 0x00719D30 );

    static zCGfx*& Gfx_List;
    static int& gfxcount;

    // user API
    #include "zCGfx.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZGRAFIX_H__VER1__