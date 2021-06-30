// Supported with union (c) 2018 Union team

#ifndef __ZTEX_CONVERT_H__VER1__
#define __ZTEX_CONVERT_H__VER1__

#include "zRenderer.h"
#include "z3d.h"

namespace Gothic_I_Addon {

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