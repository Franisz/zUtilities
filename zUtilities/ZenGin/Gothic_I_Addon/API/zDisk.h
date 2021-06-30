// Supported with union (c) 2018 Union team

#ifndef __ZDISK_H__VER1__
#define __ZDISK_H__VER1__

namespace Gothic_I_Addon {
  const int zFILE_MAX_OPEN = 6;

  enum PATH_ERROR_ID {
    zERR_PATH_UNKNOWN = 5000,
    zERR_PATH_CHANGEDIR,
    zERR_PATH_MAKEDIR,
    zERR_PATH_NOTFOUND,
    zERR_PATHDLG_OK,
    zERR_PATHDLG_CANCEL,
    zERR_PATHDLG_ERROR
  };

  enum DSK_ERROR_ID {
    zERR_DSK_UNKNOWN = 5100,
    zERR_DSK_SHARE,
    zERR_DSK_EXISTS,
    zERR_DSK_INVAL,
    zERR_DSK_HANDLE,
    zERR_DSK_TOOMANY,
    zERR_DSK_NOFILE,
    zERR_DSK_EXEC,
    zERR_DSK_FULL,
    zERR_DSK_MOVE,
    zERR_DSK_NEWFILE
  };

  enum zTDATE_CONVERT {
    zDATE_ALL,
    zDATE_DATE,
    zDATE_TIME
  };

  struct _finddata32i64_t_vc6 {
    unsigned  attrib;
    long      time_create;
    long      time_access;
    long      time_write;
    long long size;
    char      name[260];
  };

  class zDATE {
  public:
    unsigned int year;
    unsigned short month;
    unsigned short day;
    unsigned short hour;
    unsigned short minute;
    unsigned short second;

    zDATE() {}
    zDATE& operator =( long )          zCall( 0x00443CB0 );
    long ToTime_t()                    zCall( 0x00443D00 );
    zSTRING ToString( zTDATE_CONVERT ) zCall( 0x00443D50 );

    // user API
    #include "zDATE.inl"
  };

  class zFILE_STATS {
  public:
    zDATE accessDate;
    zDATE createDate;
    zDATE modifyDate;
    unsigned int size;

    zFILE_STATS() {}

    // user API
    #include "zFILE_STATS.inl"
  };

  class zFILE_INFO {
  public:
    zSTRING path;
    zSTRING name;

    zFILE_INFO() {}

    // user API
    #include "zFILE_INFO.inl"
  };

  class zFILE {
  public:
    bool write;
    int buffering;
    zCBuffer* buffer;

    void zFILE_OnInit()                                           zCall( 0x004443D0 );
    void zFILE_OnInit( zSTRING const& )                           zCall( 0x00444410 );
    zFILE()                                                       zInit( zFILE_OnInit() );
    zFILE( zSTRING const& a0 )                                    zInit( zFILE_OnInit( a0 ));
    static zSTRING SetRootDirectory( zSTRING )                    zCall( 0x00443640 );
    static void DirectFileConvert( zSTRING& )                     zCall( 0x00443780 );
    static void DirectFileAccess( bool )                          zCall( 0x00443920 );
    static int LockDirScan()                                      zCall( 0x00443B30 );
    static int UnlockDirScan()                                    zCall( 0x00443B50 );
    static void DirectFileAccess( bool, zSTRING& )                zCall( 0x00443B70 );
    static zCBuffer* GetFreeBuffer()                              zCall( 0x00449B10 );
    static void ReleaseBuffer( zCBuffer* )                        zCall( 0x00449E00 );
    static bool InitFileSystem()                                  zCall( 0x00449E30 );
    static bool DeinitFileSystem()                                zCall( 0x00449F90 );
    virtual ~zFILE()                                              zCall( 0x00444430 );
    virtual void SetMode( long )                                  zPureCall;
    virtual long GetMode()                                        zPureCall;
    virtual void SetPath( zSTRING )                               zPureCall;
    virtual void SetDrive( zSTRING )                              zPureCall;
    virtual void SetDir( zSTRING )                                zPureCall;
    virtual void SetFile( zSTRING )                               zPureCall;
    virtual void SetFilename( zSTRING )                           zPureCall;
    virtual void SetExt( zSTRING )                                zPureCall;
    virtual _iobuf* GetFileHandle()                               zPureCall;
    virtual zSTRING GetFullPath()                                 zPureCall;
    virtual zSTRING GetPath()                                     zPureCall;
    virtual zSTRING GetDirectoryPath()                            zPureCall;
    virtual zSTRING GetDrive()                                    zPureCall;
    virtual zSTRING GetDir()                                      zPureCall;
    virtual zSTRING GetFile()                                     zPureCall;
    virtual zSTRING GetFilename()                                 zPureCall;
    virtual zSTRING GetExt()                                      zPureCall;
    virtual zSTRING SetCurrentDir()                               zPureCall;
    virtual int ChangeDir( bool )                                 zPureCall;
    virtual int SearchFile( zSTRING const&, zSTRING const&, int ) zPureCall;
    virtual bool FindFirst( zSTRING const& )                      zPureCall;
    virtual bool FindNext()                                       zPureCall;
    virtual bool DirCreate()                                      zPureCall;
    virtual bool DirRemove()                                      zPureCall;
    virtual bool DirExists()                                      zPureCall;
    virtual bool FileMove( zSTRING, bool )                        zPureCall;
    virtual bool FileMove( zFILE* )                               zPureCall;
    virtual bool FileCopy( zSTRING, bool )                        zPureCall;
    virtual bool FileCopy( zFILE* )                               zPureCall;
    virtual bool FileDelete()                                     zPureCall;
    virtual bool IsOpened()                                       zPureCall;
    virtual int Create()                                          zPureCall;
    virtual int Create( zSTRING const& )                          zPureCall;
    virtual int Open( bool )                                      zPureCall;
    virtual int Open( zSTRING const&, bool )                      zPureCall;
    virtual bool Exists()                                         zPureCall;
    virtual bool Exists( zSTRING const& )                         zPureCall;
    virtual int Close()                                           zPureCall;
    virtual int Reset()                                           zPureCall;
    virtual void Append()                                         zPureCall;
    virtual long Size()                                           zPureCall;
    virtual long Pos()                                            zPureCall;
    virtual int Seek( long )                                      zPureCall;
    virtual bool Eof()                                            zPureCall;
    virtual int GetStats( zFILE_STATS& )                          zPureCall;
    virtual int Write( char const* )                              zPureCall;
    virtual int Write( zSTRING const& )                           zPureCall;
    virtual long Write( void const*, long )                       zPureCall;
    virtual long Read( void*, long )                              zPureCall;
    virtual int Read( char* )                                     zPureCall;
    virtual int Read( zSTRING& )                                  zPureCall;
    virtual int ReadChar( char& )                                 zPureCall;
    virtual zSTRING SeekText( zSTRING const& )                    zPureCall;
    virtual zSTRING ReadBlock( long, long )                       zPureCall;
    virtual int UpdateBlock( zSTRING const&, long, long )         zPureCall;
    virtual long GetFreeDiskSpace()                               zCall( 0x00443B20 );
    virtual long FlushBuffer()                                    zPureCall;

    // static properties
    static int& s_numFilesOpen;
    static int& s_maxFilesOpen;
    static zCCriticalSection*& s_dirscanCiticalSection;
    static zFILE*& s_virtPath;
    static zSTRING& s_virtPathString;
    static zSTRING& s_physPathString;
    static zSTRING& s_rootDirString;
    static bool& s_initialized;
    static zCBuffer**& bufferList;
    static int*& bufferFlag;

    // user API
    #include "zFILE.inl"
  };

  class zFILE_FILE : public zFILE {
  public:
    zSTRING dir;
    zSTRING drive;
    zSTRING filename;
    zSTRING ext;
    zSTRING complete_path;
    zSTRING complete_directory;
    int error;
    FILE* file_handle;
    long file_mode;
    _finddata32i64_t_vc6 find_fileinfo;
    long find_handle;

    void zFILE_FILE_OnInit()                                      zCall( 0x004444B0 );
    void zFILE_FILE_OnInit( zSTRING const& )                      zCall( 0x00444950 );
    int HandleError( zSTRING const&, zSTRING const&, int )        zCall( 0x00443F00 );
    void Init( zSTRING const& )                                   zCall( 0x00444440 );
    zFILE_FILE()                                                  zInit( zFILE_FILE_OnInit() );
    zFILE_FILE( zSTRING const& a0 )                               zInit( zFILE_FILE_OnInit( a0 ));
    void SetCompletePath()                                        zCall( 0x00446B70 );
    zSTRING& SlashConvert( zSTRING& )                             zCall( 0x00447EB0 );
    static bool InitFileSystem()                                  zCall( 0x0044A130 );
    static bool DeinitFileSystem()                                zCall( 0x0044A1B0 );
    virtual ~zFILE_FILE()                                         zCall( 0x00444A80 );
    virtual void SetMode( long )                                  zCall( 0x00444610 );
    virtual long GetMode()                                        zCall( 0x00444620 );
    virtual void SetPath( zSTRING )                               zCall( 0x00446E20 );
    virtual void SetDrive( zSTRING )                              zCall( 0x004473B0 );
    virtual void SetDir( zSTRING )                                zCall( 0x00447550 );
    virtual void SetFile( zSTRING )                               zCall( 0x00447B20 );
    virtual void SetFilename( zSTRING )                           zCall( 0x004477E0 );
    virtual void SetExt( zSTRING )                                zCall( 0x00447980 );
    virtual _iobuf* GetFileHandle()                               zCall( 0x00444630 );
    virtual zSTRING GetFullPath()                                 zCall( 0x00447CF0 );
    virtual zSTRING GetPath()                                     zCall( 0x00444640 );
    virtual zSTRING GetDirectoryPath()                            zCall( 0x00444690 );
    virtual zSTRING GetDrive()                                    zCall( 0x004446E0 );
    virtual zSTRING GetDir()                                      zCall( 0x00444730 );
    virtual zSTRING GetFile()                                     zCall( 0x0043FFB0 );
    virtual zSTRING GetFilename()                                 zCall( 0x00444780 );
    virtual zSTRING GetExt()                                      zCall( 0x00440060 );
    virtual zSTRING SetCurrentDir()                               zCall( 0x00447FD0 );
    virtual int ChangeDir( bool )                                 zCall( 0x00448040 );
    virtual int SearchFile( zSTRING const&, zSTRING const&, int ) zCall( 0x00448520 );
    virtual bool FindFirst( zSTRING const& )                      zCall( 0x00448C00 );
    virtual bool FindNext()                                       zCall( 0x004497B0 );
    virtual bool DirCreate()                                      zCall( 0x00448E10 );
    virtual bool DirRemove()                                      zCall( 0x00448F30 );
    virtual bool DirExists()                                      zCall( 0x00449050 );
    virtual bool FileMove( zSTRING, bool )                        zCall( 0x00449130 );
    virtual bool FileMove( zFILE* )                               zCall( 0x00449450 );
    virtual bool FileCopy( zSTRING, bool )                        zCall( 0x00449270 );
    virtual bool FileCopy( zFILE* )                               zCall( 0x004495A0 );
    virtual bool FileDelete()                                     zCall( 0x004493B0 );
    virtual bool IsOpened()                                       zCall( 0x004447D0 );
    virtual int Create()                                          zCall( 0x00444FC0 );
    virtual int Create( zSTRING const& )                          zCall( 0x004447E0 );
    virtual int Open( bool )                                      zCall( 0x00445290 );
    virtual int Open( zSTRING const&, bool )                      zCall( 0x00444850 );
    virtual bool Exists()                                         zCall( 0x00444C00 );
    virtual bool Exists( zSTRING const& )                         zCall( 0x004448C0 );
    virtual int Close()                                           zCall( 0x004456A0 );
    virtual int Reset()                                           zCall( 0x00445910 );
    virtual void Append()                                         zCall( 0x00445920 );
    virtual long Size()                                           zCall( 0x00444E40 );
    virtual long Pos()                                            zCall( 0x00445950 );
    virtual int Seek( long )                                      zCall( 0x00445960 );
    virtual bool Eof()                                            zCall( 0x00445940 );
    virtual int GetStats( zFILE_STATS& )                          zCall( 0x00444CA0 );
    virtual int Write( char const* )                              zCall( 0x00445980 );
    virtual int Write( zSTRING const& )                           zCall( 0x00445AE0 );
    virtual long Write( void const*, long )                       zCall( 0x00445B00 );
    virtual long Read( void*, long )                              zCall( 0x00445F90 );
    virtual int Read( char* )                                     zCall( 0x00445D50 );
    virtual int Read( zSTRING& )                                  zCall( 0x00445D90 );
    virtual int ReadChar( char& )                                 zCall( 0x00445D30 );
    virtual zSTRING SeekText( zSTRING const& )                    zCall( 0x00446080 );
    virtual zSTRING ReadBlock( long, long )                       zCall( 0x00446690 );
    virtual int UpdateBlock( zSTRING const&, long, long )         zCall( 0x00446790 );
    virtual long FlushBuffer()                                    zCall( 0x00445650 );
    virtual int ReadCodeline( zSTRING& )                          zCall( 0x00446280 );
    virtual int ReadLines( zSTRING&, long )                       zCall( 0x004464E0 );
    virtual zSTRING DirStepInto( zSTRING )                        zCall( 0x004482E0 );

    // user API
    #include "zFILE_FILE.inl"
  };

  class zPATH {
  public:
    enum zCOLLECT_MODE {
      CURRENT_ONLY,
      RECURSIVE
    };

    zFILE* path;

    void zPATH_OnInit()                                   zCall( 0x00449960 );
    void zPATH_OnInit( zSTRING )                          zCall( 0x00449A70 );
    zPATH()                                               zInit( zPATH_OnInit() );
    zPATH( zSTRING a0 )                                   zInit( zPATH_OnInit( a0 ));
    zSTRING GetDirectoryPath()                            zCall( 0x004ED960 );
    zSTRING GetPath()                                     zCall( 0x005000A0 );
    zSTRING GetFilename()                                 zCall( 0x0055EE90 );
    zSTRING GetExt()                                      zCall( 0x0055EEB0 );
    zSTRING GetDir()                                      zCall( 0x00569160 );
    int SearchFile( zSTRING const&, zSTRING const&, int ) zCall( 0x00586D30 );
    zSTRING GetFile()                                     zCall( 0x00588050 );
    zSTRING GetDrive()                                    zCall( 0x005A1440 );
    virtual ~zPATH()                                      zCall( 0x00490750 );

    // user API
    #include "zPATH.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZDISK_H__VER1__