// Supported with union (c) 2018 Union team

#ifndef __ZFILE3D_H__VER1__
#define __ZFILE3D_H__VER1__

namespace Gothic_I_Addon {

  class zCFile3DS {
  public:

    zCFile3DS() {}
    void Load3DS( zSTRING const&, zCMesh* ) zCall( 0x0055EAB0 );
    void Save3DS( zSTRING const&, zCMesh* ) zCall( 0x005602F0 );

    // user API
    #include "zCFile3DS.inl"
  };

  class zCFileQuakeBSP {
  public:
    zFILE* file;

    void zCFileQuakeBSP_OnInit()                           zCall( 0x00561F40 );
    zCFileQuakeBSP()                                       zInit( zCFileQuakeBSP_OnInit() );
    ~zCFileQuakeBSP()                                      zCall( 0x00561F50 );
    void LoadQuakeBSP( zSTRING const&, zCMesh*, zCWorld* ) zCall( 0x00561F70 );

    // user API
    #include "zCFileQuakeBSP.inl"
  };

  class zCFileBIN {
  public:
    int lastStart;
    int nextStart;
    int externalFile;
    zFILE* file;

    void zCFileBIN_OnInit()               zCall( 0x00569180 );
    zCFileBIN()                           zInit( zCFileBIN_OnInit() );
    ~zCFileBIN()                          zCall( 0x005691A0 );
    void BinCreate( zSTRING const& )      zCall( 0x00569220 );
    void BinClose()                       zCall( 0x00569250 );
    void BinStartChunk( unsigned short )  zCall( 0x00585E70 );
    int BinWriteSrcFileStats( zSTRING& )  zCall( 0x00585F10 );
    void BinEndChunk()                    zCall( 0x00586D50 );
    void BinWriteString( zSTRING const& ) zCall( 0x00587000 );
    int BinReadCompareSrcFileStats()      zCall( 0x005896D0 );
    void BinSkipChunk()                   zCall( 0x0059C330 );
    void BinSetFile( zFILE* )             zCall( 0x00619EA0 );

    // user API
    #include "zCFileBIN.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZFILE3D_H__VER1__