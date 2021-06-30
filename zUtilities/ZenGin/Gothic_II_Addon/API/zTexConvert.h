// Supported with union (c) 2018 Union team

#ifndef __ZTEX_CONVERT_H__VER3__
#define __ZTEX_CONVERT_H__VER3__

#include "zRenderer.h"
#include "z3d.h"

namespace Gothic_II_Addon {

  struct RGBPIXEL {
  public:
    unsigned char b;
    unsigned g;
    unsigned r;
    unsigned a;
  };

  class zCTexConGeneric : public zCTextureConvert {
  public:
    zCTextureInfo texinfo;
    char* tempptr;
    char pal[256* 3];
    zCTextureFileFormatInternal* ffi;
    int alpha;
    zCOLOR average;
    zTTexLockMode lockMode;
    int modified;
    int detailTextureMode;

    void zCTexConGeneric_OnInit()                            zCall( 0x0065B740 );
    zCOLOR GetAverageColor()                                 zCall( 0x0065B6E0 );
    zCTexConGeneric()                                        zInit( zCTexConGeneric_OnInit() );
    virtual ~zCTexConGeneric()                               zCall( 0x0065B7D0 );
    virtual int Lock( int )                                  zCall( 0x0065B840 );
    virtual int Unlock()                                     zCall( 0x0065B860 );
    virtual int SetTextureInfo( zCTextureInfo const& )       zCall( 0x0065B1C0 );
    virtual void* GetPaletteBuffer()                         zCall( 0x0065B290 );
    virtual int GetTextureBuffer( int, void*&, int& )        zCall( 0x0065B2B0 );
    virtual zCTextureInfo GetTextureInfo()                   zCall( 0x0065B270 );
    virtual int CopyPaletteDataTo( void* )                   zCall( 0x0065B6B0 );
    virtual int CopyTextureDataTo( int, void*, int )         zCall( 0x0065B480 );
    virtual int HasAlpha()                                   zCall( 0x0065B6F0 );
    virtual int ConvertTextureFormat( zCTextureInfo const& ) zCall( 0x006598E0 );
    virtual void SetDetailTextureMode( int )                 zCall( 0x0065B7A0 );

    // user API
    #include "zCTexConGeneric.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZTEX_CONVERT_H__VER3__