// Supported with union (c) 2018 Union team

#ifndef __ZFILE3D_H__VER0__
#define __ZFILE3D_H__VER0__

namespace Gothic_I_Classic {

  class zCFile3DS {
  public:

    zCFile3DS() {}
    void Load3DS( zSTRING const&, zCMesh* ) zCall( 0x00546C00 );
    void Save3DS( zSTRING const&, zCMesh* ) zCall( 0x00548320 );

    // user API
    #include "zCFile3DS.inl"
  };

  class zCFileQuakeBSP {
  public:
    zFILE* file;

    void zCFileQuakeBSP_OnInit()                           zCall( 0x00549F40 );
    zCFileQuakeBSP()                                       zInit( zCFileQuakeBSP_OnInit() );
    ~zCFileQuakeBSP()                                      zCall( 0x00549F50 );
    void LoadQuakeBSP( zSTRING const&, zCMesh*, zCWorld* ) zCall( 0x00549F70 );

    // user API
    #include "zCFileQuakeBSP.inl"
  };

  class zCFileBIN {
  public:
    int lastStart;
    int nextStart;
    int externalFile;
    zFILE* file;

    void zCFileBIN_OnInit()               zCall( 0x00550AF0 );
    zCFileBIN()                           zInit( zCFileBIN_OnInit() );
    ~zCFileBIN()                          zCall( 0x00550B10 );
    void BinCreate( zSTRING const& )      zCall( 0x00550B90 );
    void BinClose()                       zCall( 0x00550BC0 );
    void BinStartChunk( unsigned short )  zCall( 0x0056CC80 );
    int BinWriteSrcFileStats( zSTRING& )  zCall( 0x0056CD20 );
    void BinEndChunk()                    zCall( 0x0056DA20 );
    void BinWriteString( zSTRING const& ) zCall( 0x0056DCC0 );
    int BinReadCompareSrcFileStats()      zCall( 0x00570240 );
    void BinSkipChunk()                   zCall( 0x005818B0 );
    void BinSetFile( zFILE* )             zCall( 0x005F89E0 );

    // user API
    #include "zCFileBIN.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZFILE3D_H__VER0__