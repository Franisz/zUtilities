// Supported with union (c) 2018-2021 Union team

#ifndef __ZDISK__VDFS_H__VER3__
#define __ZDISK__VDFS_H__VER3__

#include "zDisk.h"

namespace Gothic_II_Addon {

  // sizeof 4Ch
  struct TVDFFINDDATA {
  public:
    char name[64]; // sizeof 40h    offset 00h
    long size;     // sizeof 04h    offset 40h
    long attr;     // sizeof 04h    offset 44h
    long datetime; // sizeof 04h    offset 48h
  };

  // sizeof 2A38h
  class zFILE_VDFS : public zFILE_FILE {
  public:
    char read_buffer[1024* 10]; // sizeof 2800h  offset 1C0h
    TVDFFINDDATA find_filedata; // sizeof 4Ch    offset 29C0h
    long vdfHandle;             // sizeof 04h    offset 2A0Ch
    long vdfResult;             // sizeof 04h    offset 2A10h
    bool vdfEOF;                // sizeof 01h    offset 2A14h
    long vdfFindHandle;         // sizeof 04h    offset 2A18h
    zSTRING vdfFindExt;         // sizeof 14h    offset 2A1Ch
    int error;                  // sizeof 04h    offset 2A30h

    void zFILE_VDFS_OnInit()                                      zCall( 0x00448BF0 );
    void zFILE_VDFS_OnInit( zSTRING const& )                      zCall( 0x00448E20 );
    void Init( zSTRING const& )                                   zCall( 0x00448BB0 );
    zFILE_VDFS()                                                  zInit( zFILE_VDFS_OnInit() );
    zFILE_VDFS( zSTRING const& a0 )                               zInit( zFILE_VDFS_OnInit( a0 ));
    int HandleError( zSTRING const&, zSTRING const&, int )        zCall( 0x00449110 );
    static bool InitFileSystem()                                  zCall( 0x0044AD60 );
    static bool DeinitFileSystem()                                zCall( 0x0044B440 );
    static bool LockCriticalSection()                             zCall( 0x0044B7E0 );
    static bool UnlockCriticalSection()                           zCall( 0x0044B800 );
    virtual ~zFILE_VDFS()                                         zCall( 0x00448ED0 );
    virtual zSTRING GetFullPath()                                 zCall( 0x00449D20 );
    virtual zSTRING SetCurrentDir()                               zCall( 0x00449AD0 );
    virtual int ChangeDir( bool )                                 zCall( 0x00449E70 );
    virtual int SearchFile( zSTRING const&, zSTRING const&, int ) zCall( 0x00449E80 );
    virtual bool FindFirst( zSTRING const& )                      zCall( 0x0044A300 );
    virtual bool FindNext()                                       zCall( 0x0044A5B0 );
    virtual bool IsOpened()                                       zCall( 0x00448FF0 );
    virtual int Open( bool )                                      zCall( 0x00449120 );
    virtual int Open( zSTRING const&, bool )                      zCall( 0x00448D30 );
    virtual bool Exists()                                         zCall( 0x00449020 );
    virtual bool Exists( zSTRING const& )                         zCall( 0x00448DA0 );
    virtual int Close()                                           zCall( 0x004493A0 );
    virtual int Reset()                                           zCall( 0x00449400 );
    virtual void Append()                                         zCall( 0x00449AB0 );
    virtual long Size()                                           zCall( 0x00449410 );
    virtual long Pos()                                            zCall( 0x00449A50 );
    virtual int Seek( long )                                      zCall( 0x00449490 );
    virtual bool Eof()                                            zCall( 0x00449470 );
    virtual int GetStats( zFILE_STATS& )                          zCall( 0x0044A2F0 );
    virtual long Read( void*, long )                              zCall( 0x0044ABF0 );
    virtual int Read( char* )                                     zCall( 0x0044A8D0 );
    virtual int Read( zSTRING& )                                  zCall( 0x0044AA80 );
    virtual zSTRING SeekText( zSTRING const& )                    zCall( 0x00449870 );

    // static properties
    static bool& s_vdfsInitialized;
    static bool& s_physical_first;
    static zCCriticalSection*& s_criticalSection;

    // user API
    #include "zFILE_VDFS.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZDISK__VDFS_H__VER3__