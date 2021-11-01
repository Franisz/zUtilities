// Supported with union (c) 2018-2021 Union team

#ifndef __ZTEX_CONVERT_H__VER2__
#define __ZTEX_CONVERT_H__VER2__

#include "zRenderer.h"
#include "z3d.h"

namespace Gothic_II_Classic {

  // sizeof 10h
  struct RGBPIXEL {
  public:
    unsigned char b; // sizeof 01h    offset 00h
    unsigned g;      // sizeof 04h    offset 04h
    unsigned r;      // sizeof 04h    offset 08h
    unsigned a;      // sizeof 04h    offset 0Ch
  };

  // sizeof 33Ch
  class zCTexConGeneric : public zCTextureConvert {
  public:
    zCTextureInfo texinfo;            // sizeof 1Ch    offset 04h
    char* tempptr;                    // sizeof 04h    offset 20h
    char pal[256* 3];                 // sizeof 300h   offset 24h
    zCTextureFileFormatInternal* ffi; // sizeof 04h    offset 324h
    int alpha;                        // sizeof 04h    offset 328h
    zCOLOR average;                   // sizeof 04h    offset 32Ch
    zTTexLockMode lockMode;           // sizeof 04h    offset 330h
    int modified;                     // sizeof 04h    offset 334h
    int detailTextureMode;            // sizeof 04h    offset 338h

    void zCTexConGeneric_OnInit()                            zCall( 0x0076EC10 );
    zCOLOR GetAverageColor()                                 zCall( 0x0076EBB0 );
    zCTexConGeneric()                                        zInit( zCTexConGeneric_OnInit() );
    virtual ~zCTexConGeneric()                               zCall( 0x0076ECA0 );
    virtual int Lock( int )                                  zCall( 0x0076ED10 );
    virtual int Unlock()                                     zCall( 0x0076ED30 );
    virtual int SetTextureInfo( zCTextureInfo const& )       zCall( 0x0076E690 );
    virtual void* GetPaletteBuffer()                         zCall( 0x0076E760 );
    virtual int GetTextureBuffer( int, void*&, int& )        zCall( 0x0076E780 );
    virtual zCTextureInfo GetTextureInfo()                   zCall( 0x0076E740 );
    virtual int CopyPaletteDataTo( void* )                   zCall( 0x0076EB80 );
    virtual int CopyTextureDataTo( int, void*, int )         zCall( 0x0076E950 );
    virtual int HasAlpha()                                   zCall( 0x0076EBC0 );
    virtual int ConvertTextureFormat( zCTextureInfo const& ) zCall( 0x0076CDB0 );
    virtual void SetDetailTextureMode( int )                 zCall( 0x0076EC70 );

    // user API
    #include "zCTexConGeneric.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZTEX_CONVERT_H__VER2__