// Supported with union (c) 2018 Union team

#ifndef __ZTEX_CONVERT_H__VER2__
#define __ZTEX_CONVERT_H__VER2__

#include "zRenderer.h"
#include "z3d.h"

namespace Gothic_II_Classic {

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