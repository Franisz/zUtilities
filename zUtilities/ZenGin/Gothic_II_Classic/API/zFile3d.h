// Supported with union (c) 2018-2021 Union team

#ifndef __ZFILE3D_H__VER2__
#define __ZFILE3D_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 01h
  class zCFile3DS {
  public:

    zCFile3DS() {}
    void Load3DS( zSTRING const&, zCMesh* ) zCall( 0x00558440 );
    void Save3DS( zSTRING const&, zCMesh* ) zCall( 0x00559DF0 );

    // user API
    #include "zCFile3DS.inl"
  };

  // sizeof 04h
  class zCFileQuakeBSP {
  public:
    zFILE* file; // sizeof 04h    offset 00h

    void zCFileQuakeBSP_OnInit()                           zCall( 0x0055B9C0 );
    zCFileQuakeBSP()                                       zInit( zCFileQuakeBSP_OnInit() );
    ~zCFileQuakeBSP()                                      zCall( 0x0055B9D0 );
    void LoadQuakeBSP( zSTRING const&, zCMesh*, zCWorld* ) zCall( 0x0055B9F0 );

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

    void zCFileBIN_OnInit()               zCall( 0x00562D00 );
    zCFileBIN()                           zInit( zCFileBIN_OnInit() );
    ~zCFileBIN()                          zCall( 0x00562D20 );
    void BinCreate( zSTRING const& )      zCall( 0x00562DA0 );
    void BinClose()                       zCall( 0x00562DD0 );
    void BinStartChunk( unsigned short )  zCall( 0x0056AD50 );
    void BinEndChunk()                    zCall( 0x0056ADF0 );
    int BinWriteSrcFileStats( zSTRING& )  zCall( 0x00582040 );
    void BinWriteString( zSTRING const& ) zCall( 0x00582F60 );
    int BinReadCompareSrcFileStats()      zCall( 0x00585410 );
    void BinWriteFloat( float )           zCall( 0x00597C20 );
    void BinWriteInt( int )               zCall( 0x00597C40 );
    void BinSkipChunk()                   zCall( 0x00598840 );
    void BinSetFile( zFILE* )             zCall( 0x0061F920 );

    // user API
    #include "zCFileBIN.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZFILE3D_H__VER2__