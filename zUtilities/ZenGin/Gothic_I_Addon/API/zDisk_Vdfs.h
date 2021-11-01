// Supported with union (c) 2018-2021 Union team

#ifndef __ZDISK__VDFS_H__VER1__
#define __ZDISK__VDFS_H__VER1__

namespace Gothic_I_Addon {

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
    char read_buffer[10240];    // sizeof 2800h  offset 1C0h
    TVDFFINDDATA find_filedata; // sizeof 4Ch    offset 29C0h
    long vdfHandle;             // sizeof 04h    offset 2A0Ch
    long vdfResult;             // sizeof 04h    offset 2A10h
    bool vdfEOF;                // sizeof 01h    offset 2A14h
    long vdfFindHandle;         // sizeof 04h    offset 2A18h
    zSTRING vdfFindExt;         // sizeof 14h    offset 2A1Ch
    int error;                  // sizeof 04h    offset 2A30h

    void zFILE_VDFS_OnInit()                                      zCall( 0x0044A7A0 );
    void zFILE_VDFS_OnInit( zSTRING const& )                      zCall( 0x0044A9E0 );
    void Init( zSTRING const& )                                   zCall( 0x0044A770 );
    zFILE_VDFS()                                                  zInit( zFILE_VDFS_OnInit() );
    zFILE_VDFS( zSTRING const& a0 )                               zInit( zFILE_VDFS_OnInit( a0 ));
    int HandleError( zSTRING const&, zSTRING const&, int )        zCall( 0x0044ACD0 );
    static bool InitFileSystem()                                  zCall( 0x0044C920 );
    static bool DeinitFileSystem()                                zCall( 0x0044CD90 );
    static bool LockCriticalSection()                             zCall( 0x0044D120 );
    static bool UnlockCriticalSection()                           zCall( 0x0044D140 );
    virtual ~zFILE_VDFS()                                         zCall( 0x0044AA80 );
    virtual zSTRING GetFullPath()                                 zCall( 0x0044B740 );
    virtual zSTRING SetCurrentDir()                               zCall( 0x0044B4B0 );
    virtual int ChangeDir( bool )                                 zCall( 0x0044B8D0 );
    virtual int SearchFile( zSTRING const&, zSTRING const&, int ) zCall( 0x0044B8E0 );
    virtual bool FindFirst( zSTRING const& )                      zCall( 0x0044BDE0 );
    virtual bool FindNext()                                       zCall( 0x0044C0D0 );
    virtual bool IsOpened()                                       zCall( 0x0044ABA0 );
    virtual int Open( bool )                                      zCall( 0x0044ACE0 );
    virtual int Open( zSTRING const&, bool )                      zCall( 0x0044A8E0 );
    virtual bool Exists()                                         zCall( 0x0044ABD0 );
    virtual bool Exists( zSTRING const& )                         zCall( 0x0044A950 );
    virtual int Close()                                           zCall( 0x0044AFA0 );
    virtual int Reset()                                           zCall( 0x0044B000 );
    virtual void Append()                                         zCall( 0x0044B490 );
    virtual long Size()                                           zCall( 0x0044B010 );
    virtual long Pos()                                            zCall( 0x0044B430 );
    virtual int Seek( long )                                      zCall( 0x0044B090 );
    virtual bool Eof()                                            zCall( 0x0044B070 );
    virtual int GetStats( zFILE_STATS& )                          zCall( 0x0044BDD0 );
    virtual long Read( void*, long )                              zCall( 0x0044C780 );
    virtual int Read( char* )                                     zCall( 0x0044C430 );
    virtual int Read( zSTRING& )                                  zCall( 0x0044C600 );

    // static properties
    static bool& s_vdfsInitialized;
    static zCCriticalSection*& s_criticalSection;

    // user API
    #include "zFILE_VDFS.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZDISK__VDFS_H__VER1__