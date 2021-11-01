// Supported with union (c) 2018-2021 Union team

#ifndef __ZTEX_CONVERT_H__VER1__
#define __ZTEX_CONVERT_H__VER1__

#include "zRenderer.h"
#include "z3d.h"

namespace Gothic_I_Addon {

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

    void zCTexConGeneric_OnInit()                            zCall( 0x0075F640 );
    zCOLOR GetAverageColor()                                 zCall( 0x0075F5D0 );
    zCTexConGeneric()                                        zInit( zCTexConGeneric_OnInit() );
    virtual ~zCTexConGeneric()                               zCall( 0x0075F6D0 );
    virtual int Lock( int )                                  zCall( 0x0075F740 );
    virtual int Unlock()                                     zCall( 0x0075F760 );
    virtual int SetTextureInfo( zCTextureInfo const& )       zCall( 0x0075F010 );
    virtual void* GetPaletteBuffer()                         zCall( 0x0075F0F0 );
    virtual int GetTextureBuffer( int, void*&, int& )        zCall( 0x0075F110 );
    virtual zCTextureInfo GetTextureInfo()                   zCall( 0x0075F0D0 );
    virtual int CopyPaletteDataTo( void* )                   zCall( 0x0075F5A0 );
    virtual int CopyTextureDataTo( int, void*, int )         zCall( 0x0075F300 );
    virtual int HasAlpha()                                   zCall( 0x0075F5E0 );
    virtual int ConvertTextureFormat( zCTextureInfo const& ) zCall( 0x0075D770 );
    virtual void SetDetailTextureMode( int )                 zCall( 0x0075F6A0 );

    // user API
    #include "zCTexConGeneric.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZTEX_CONVERT_H__VER1__