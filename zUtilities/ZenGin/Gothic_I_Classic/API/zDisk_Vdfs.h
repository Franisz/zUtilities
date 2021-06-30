// Supported with union (c) 2018 Union team

#ifndef __ZDISK__VDFS_H__VER0__
#define __ZDISK__VDFS_H__VER0__

namespace Gothic_I_Classic {

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

    void zFILE_VDFS_OnInit()                                      zCall( 0x00444B60 );
    void zFILE_VDFS_OnInit( zSTRING const& )                      zCall( 0x00444D90 );
    void Init( zSTRING const& )                                   zCall( 0x00444B20 );
    zFILE_VDFS()                                                  zInit( zFILE_VDFS_OnInit() );
    zFILE_VDFS( zSTRING const& a0 )                               zInit( zFILE_VDFS_OnInit( a0 ));
    int HandleError( zSTRING const&, zSTRING const&, int )        zCall( 0x00445080 );
    static bool InitFileSystem()                                  zCall( 0x00446A30 );
    static bool DeinitFileSystem()                                zCall( 0x00446E80 );
    static bool LockCriticalSection()                             zCall( 0x004471C0 );
    static bool UnlockCriticalSection()                           zCall( 0x004471E0 );
    virtual ~zFILE_VDFS()                                         zCall( 0x00444E40 );
    virtual zSTRING GetFullPath()                                 zCall( 0x004459F0 );
    virtual zSTRING SetCurrentDir()                               zCall( 0x004457A0 );
    virtual int ChangeDir( bool )                                 zCall( 0x00445B40 );
    virtual int SearchFile( zSTRING const&, zSTRING const&, int ) zCall( 0x00445B50 );
    virtual bool FindFirst( zSTRING const& )                      zCall( 0x00445FD0 );
    virtual bool FindNext()                                       zCall( 0x00446280 );
    virtual bool IsOpened()                                       zCall( 0x00444F60 );
    virtual int Open( bool )                                      zCall( 0x00445090 );
    virtual int Open( zSTRING const&, bool )                      zCall( 0x00444CA0 );
    virtual bool Exists()                                         zCall( 0x00444F90 );
    virtual bool Exists( zSTRING const& )                         zCall( 0x00444D10 );
    virtual int Close()                                           zCall( 0x00445310 );
    virtual int Reset()                                           zCall( 0x00445370 );
    virtual void Append()                                         zCall( 0x00445780 );
    virtual long Size()                                           zCall( 0x00445380 );
    virtual long Pos()                                            zCall( 0x00445720 );
    virtual int Seek( long )                                      zCall( 0x00445400 );
    virtual bool Eof()                                            zCall( 0x004453E0 );
    virtual int GetStats( zFILE_STATS& )                          zCall( 0x00445FC0 );
    virtual long Read( void*, long )                              zCall( 0x004468C0 );
    virtual int Read( char* )                                     zCall( 0x004465A0 );
    virtual int Read( zSTRING& )                                  zCall( 0x00446750 );

    // static properties
    static bool& s_physical_first;
    static bool& s_vdfsInitialized;
    static zCCriticalSection*& s_criticalSection;

    // user API
    #include "zFILE_VDFS.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZDISK__VDFS_H__VER0__