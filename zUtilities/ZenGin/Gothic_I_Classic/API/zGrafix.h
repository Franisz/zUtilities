// Supported with union (c) 2018-2021 Union team

#ifndef __ZGRAFIX_H__VER0__
#define __ZGRAFIX_H__VER0__

namespace Gothic_I_Classic {

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
    void zCGfx_OnInit( zSTRING const& )                zCall( 0x006E11A0 );
    void zCGfx_OnInit( int, int )                      zCall( 0x006E1370 );
    zCGfx( zSTRING const& a0 )                         zInit( zCGfx_OnInit( a0 ));
    zCGfx( int a0, int a1 )                            zInit( zCGfx_OnInit( a0, a1 ));
    ~zCGfx()                                           zCall( 0x006E15E0 );
    TGfx_Gfx* LoadRaw( zSTRING const&, int, int, int ) zCall( 0x006E1C20 );
    unsigned char Readbyte( zFILE* )                   zCall( 0x006E1CE0 );
    TGfx_Gfx* LoadPcx( zSTRING const& )                zCall( 0x006E1D50 );
    TGfx_Gfx* LoadTga( zSTRING const& )                zCall( 0x006E2240 );
    void SaveRaw( zSTRING const& )                     zCall( 0x006E35A0 );
    void Save( zSTRING const& )                        zCall( 0x006E3600 );
    TGfx_Gfx* LoadGfx( zSTRING const& )                zCall( 0x006E37A0 );
    int GetSizex()                                     zCall( 0x006E3B00 );
    int GetSizey()                                     zCall( 0x006E3B10 );
    unsigned char* GetDataPtr()                        zCall( 0x006E3B20 );
    int GetPixel( int, int )                           zCall( 0x006E3B30 );
    static void Reload()                               zCall( 0x006E1670 );

    // static properties
    static zCGfx*& Gfx_List;
    static int& gfxcount;

    // user API
    #include "zCGfx.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZGRAFIX_H__VER0__