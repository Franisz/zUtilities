// Supported with union (c) 2018-2021 Union team

#ifndef __ZFILE3D_H__VER3__
#define __ZFILE3D_H__VER3__

#include "z3d.h"
#include "zDisk.h"

namespace Gothic_II_Addon {

  // sizeof 01h
  class zCFile3DS {
  public:

    zCFile3DS() {}
    void Load3DS( zSTRING const&, zCMesh* ) zCall( 0x0055D660 );
    void Save3DS( zSTRING const&, zCMesh* ) zCall( 0x0055F010 );

    // user API
    #include "zCFile3DS.inl"
  };

  // sizeof 04h
  class zCFileQuakeBSP {
  public:
    zFILE* file; // sizeof 04h    offset 00h

    void zCFileQuakeBSP_OnInit()                           zCall( 0x00560BE0 );
    zCFileQuakeBSP()                                       zInit( zCFileQuakeBSP_OnInit() );
    ~zCFileQuakeBSP()                                      zCall( 0x00560BF0 );
    void LoadQuakeBSP( zSTRING const&, zCMesh*, zCWorld* ) zCall( 0x00560C10 );

    // user API
    #include "zCFileQuakeBSP.inl"
  };

  // sizeof 10h
  class zCFileBIN {
  public:
    int lastStart;    // sizeof 04h    offset 00h
    int nextStart;    // sizeof 04h    offset 04h
    int externalFile; // sizeof 04h    offset 08h
    zFILE* file;      // sizeof 04h    offset 0Ch

    void zCFileBIN_OnInit()               zCall( 0x00567F50 );
    zCFileBIN()                           zInit( zCFileBIN_OnInit() );
    ~zCFileBIN()                          zCall( 0x00567F70 );
    void BinCreate( zSTRING const& )      zCall( 0x00567FF0 );
    void BinClose()                       zCall( 0x00568020 );
    void BinStartChunk( unsigned short )  zCall( 0x0056FFE0 );
    void BinEndChunk()                    zCall( 0x00570080 );
    int BinWriteSrcFileStats( zSTRING& )  zCall( 0x005875A0 );
    void BinWriteString( zSTRING const& ) zCall( 0x005884C0 );
    int BinReadCompareSrcFileStats()      zCall( 0x0058A970 );
    void BinWriteFloat( float )           zCall( 0x0059D180 );
    void BinWriteInt( int )               zCall( 0x0059D1A0 );
    void BinSkipChunk()                   zCall( 0x0059DDA0 );
    void BinSetFile( zFILE* )             zCall( 0x006270B0 );

    // user API
    #include "zCFileBIN.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZFILE3D_H__VER3__