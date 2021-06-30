// Supported with union (c) 2018 Union team

#ifndef __ZDISK__VDFS_H__VER2__
#define __ZDISK__VDFS_H__VER2__

namespace Gothic_II_Classic {

  struct TVDFFINDDATA {
  public:
    char name[64];
    long size;
    long attr;
    long datetime;
  };

  class zFILE_VDFS : public zFILE_FILE {
  public:
    char read_buffer[1024* 10];
    TVDFFINDDATA find_filedata;
    long vdfHandle;
    long vdfResult;
    bool vdfEOF;
    long vdfFindHandle;
    zSTRING vdfFindExt;
    int error;

    void zFILE_VDFS_OnInit()                                      zCall( 0x004485B0 );
    void zFILE_VDFS_OnInit( zSTRING const& )                      zCall( 0x004487D0 );
    void Init( zSTRING const& )                                   zCall( 0x00448580 );
    zFILE_VDFS()                                                  zInit( zFILE_VDFS_OnInit() );
    zFILE_VDFS( zSTRING const& a0 )                               zInit( zFILE_VDFS_OnInit( a0 ));
    int HandleError( zSTRING const&, zSTRING const&, int )        zCall( 0x00448AB0 );
    static bool InitFileSystem()                                  zCall( 0x0044A700 );
    static bool DeinitFileSystem()                                zCall( 0x0044ACF0 );
    static bool LockCriticalSection()                             zCall( 0x0044B090 );
    static bool UnlockCriticalSection()                           zCall( 0x0044B0B0 );
    virtual ~zFILE_VDFS()                                         zCall( 0x00448870 );
    virtual zSTRING GetFullPath()                                 zCall( 0x004496C0 );
    virtual zSTRING SetCurrentDir()                               zCall( 0x00449470 );
    virtual int ChangeDir( bool )                                 zCall( 0x00449810 );
    virtual int SearchFile( zSTRING const&, zSTRING const&, int ) zCall( 0x00449820 );
    virtual bool FindFirst( zSTRING const& )                      zCall( 0x00449CA0 );
    virtual bool FindNext()                                       zCall( 0x00449F50 );
    virtual bool IsOpened()                                       zCall( 0x00448990 );
    virtual int Open( bool )                                      zCall( 0x00448AC0 );
    virtual int Open( zSTRING const&, bool )                      zCall( 0x004486E0 );
    virtual bool Exists()                                         zCall( 0x004489C0 );
    virtual bool Exists( zSTRING const& )                         zCall( 0x00448750 );
    virtual int Close()                                           zCall( 0x00448D40 );
    virtual int Reset()                                           zCall( 0x00448DA0 );
    virtual void Append()                                         zCall( 0x00449450 );
    virtual long Size()                                           zCall( 0x00448DB0 );
    virtual long Pos()                                            zCall( 0x004493F0 );
    virtual int Seek( long )                                      zCall( 0x00448E30 );
    virtual bool Eof()                                            zCall( 0x00448E10 );
    virtual int GetStats( zFILE_STATS& )                          zCall( 0x00449C90 );
    virtual long Read( void*, long )                              zCall( 0x0044A590 );
    virtual int Read( char* )                                     zCall( 0x0044A270 );
    virtual int Read( zSTRING& )                                  zCall( 0x0044A420 );
    virtual zSTRING SeekText( zSTRING const& )                    zCall( 0x00449210 );

    // static properties
    static bool& s_vdfsInitialized;
    static zCCriticalSection*& s_criticalSection;

    // user API
    #include "zFILE_VDFS.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZDISK__VDFS_H__VER2__