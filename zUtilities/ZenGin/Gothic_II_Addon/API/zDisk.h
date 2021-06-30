// Supported with union (c) 2018 Union team

#ifndef __ZDISK_H__VER3__
#define __ZDISK_H__VER3__

namespace Gothic_II_Addon {
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
    zDATE& operator =( long )          zCall( 0x00442860 );
    long ToTime_t()                    zCall( 0x004428B0 );
    zSTRING ToString( zTDATE_CONVERT ) zCall( 0x00442900 );

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

    void zFILE_OnInit()                                           zCall( 0x00442EF0 );
    void zFILE_OnInit( zSTRING const& )                           zCall( 0x00442F30 );
    zFILE()                                                       zInit( zFILE_OnInit() );
    zFILE( zSTRING const& a0 )                                    zInit( zFILE_OnInit( a0 ));
    static zSTRING SetRootDirectory( zSTRING )                    zCall( 0x00442260 );
    static void DirectFileConvert( zSTRING& )                     zCall( 0x00442390 );
    static void DirectFileAccess( bool )                          zCall( 0x00442530 );
    static int LockDirScan()                                      zCall( 0x00442720 );
    static int UnlockDirScan()                                    zCall( 0x00442740 );
    static void DirectFileAccess( bool, zSTRING& )                zCall( 0x00442760 );
    static zCBuffer* GetFreeBuffer()                              zCall( 0x00447F40 );
    static void ReleaseBuffer( zCBuffer* )                        zCall( 0x00448250 );
    static bool InitFileSystem()                                  zCall( 0x00448290 );
    static bool DeinitFileSystem()                                zCall( 0x004483E0 );
    virtual ~zFILE()                                              zCall( 0x00442F50 );
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
    virtual long GetFreeDiskSpace()                               zCall( 0x00442710 );
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

    void zFILE_FILE_OnInit()                                      zCall( 0x00442FD0 );
    void zFILE_FILE_OnInit( zSTRING const& )                      zCall( 0x00443450 );
    int HandleError( zSTRING const&, zSTRING const&, int )        zCall( 0x00442A70 );
    void Init( zSTRING const& )                                   zCall( 0x00442F60 );
    zFILE_FILE()                                                  zInit( zFILE_FILE_OnInit() );
    zFILE_FILE( zSTRING const& a0 )                               zInit( zFILE_FILE_OnInit( a0 ));
    void SetCompletePath()                                        zCall( 0x00445360 );
    zSTRING& SlashConvert( zSTRING& )                             zCall( 0x004464F0 );
    static bool InitFileSystem()                                  zCall( 0x004485E0 );
    static bool DeinitFileSystem()                                zCall( 0x00448650 );
    virtual ~zFILE_FILE()                                         zCall( 0x00443580 );
    virtual void SetMode( long )                                  zCall( 0x00443130 );
    virtual long GetMode()                                        zCall( 0x00443140 );
    virtual void SetPath( zSTRING )                               zCall( 0x004455D0 );
    virtual void SetDrive( zSTRING )                              zCall( 0x00445AD0 );
    virtual void SetDir( zSTRING )                                zCall( 0x00445C60 );
    virtual void SetFile( zSTRING )                               zCall( 0x004461E0 );
    virtual void SetFilename( zSTRING )                           zCall( 0x00445EC0 );
    virtual void SetExt( zSTRING )                                zCall( 0x00446050 );
    virtual _iobuf* GetFileHandle()                               zCall( 0x00443150 );
    virtual zSTRING GetFullPath()                                 zCall( 0x00446360 );
    virtual zSTRING GetPath()                                     zCall( 0x00443160 );
    virtual zSTRING GetDirectoryPath()                            zCall( 0x004431B0 );
    virtual zSTRING GetDrive()                                    zCall( 0x00443200 );
    virtual zSTRING GetDir()                                      zCall( 0x00443250 );
    virtual zSTRING GetFile()                                     zCall( 0x0043ECF0 );
    virtual zSTRING GetFilename()                                 zCall( 0x004432A0 );
    virtual zSTRING GetExt()                                      zCall( 0x0043EDA0 );
    virtual zSTRING SetCurrentDir()                               zCall( 0x00446610 );
    virtual int ChangeDir( bool )                                 zCall( 0x00446670 );
    virtual int SearchFile( zSTRING const&, zSTRING const&, int ) zCall( 0x00446AC0 );
    virtual bool FindFirst( zSTRING const& )                      zCall( 0x00447100 );
    virtual bool FindNext()                                       zCall( 0x00447C10 );
    virtual bool DirCreate()                                      zCall( 0x004472F0 );
    virtual bool DirRemove()                                      zCall( 0x00447400 );
    virtual bool DirExists()                                      zCall( 0x00447500 );
    virtual bool FileMove( zSTRING, bool )                        zCall( 0x004475C0 );
    virtual bool FileMove( zFILE* )                               zCall( 0x00447860 );
    virtual bool FileCopy( zSTRING, bool )                        zCall( 0x004476D0 );
    virtual bool FileCopy( zFILE* )                               zCall( 0x00447990 );
    virtual bool FileDelete()                                     zCall( 0x004477E0 );
    virtual bool IsOpened()                                       zCall( 0x004432F0 );
    virtual int Create()                                          zCall( 0x004439F0 );
    virtual int Create( zSTRING const& )                          zCall( 0x00443300 );
    virtual int Open( bool )                                      zCall( 0x00443C90 );
    virtual int Open( zSTRING const&, bool )                      zCall( 0x00443360 );
    virtual bool Exists()                                         zCall( 0x004436B0 );
    virtual bool Exists( zSTRING const& )                         zCall( 0x004433D0 );
    virtual int Close()                                           zCall( 0x00444010 );
    virtual int Reset()                                           zCall( 0x00444260 );
    virtual void Append()                                         zCall( 0x00444270 );
    virtual long Size()                                           zCall( 0x004438A0 );
    virtual long Pos()                                            zCall( 0x004442A0 );
    virtual int Seek( long )                                      zCall( 0x004442B0 );
    virtual bool Eof()                                            zCall( 0x00444290 );
    virtual int GetStats( zFILE_STATS& )                          zCall( 0x00443730 );
    virtual int Write( char const* )                              zCall( 0x004442D0 );
    virtual int Write( zSTRING const& )                           zCall( 0x00444410 );
    virtual long Write( void const*, long )                       zCall( 0x00444430 );
    virtual long Read( void*, long )                              zCall( 0x004448A0 );
    virtual int Read( char* )                                     zCall( 0x00444670 );
    virtual int Read( zSTRING& )                                  zCall( 0x004446B0 );
    virtual int ReadChar( char& )                                 zCall( 0x00444650 );
    virtual zSTRING SeekText( zSTRING const& )                    zCall( 0x00444980 );
    virtual zSTRING ReadBlock( long, long )                       zCall( 0x00444EE0 );
    virtual int UpdateBlock( zSTRING const&, long, long )         zCall( 0x00444FB0 );
    virtual long FlushBuffer()                                    zCall( 0x00443FC0 );
    virtual int ReadCodeline( zSTRING& )                          zCall( 0x00444B30 );
    virtual int ReadLines( zSTRING&, long )                       zCall( 0x00444D40 );
    virtual zSTRING DirStepInto( zSTRING )                        zCall( 0x004468C0 );

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

    void zPATH_OnInit()                                   zCall( 0x00447DA0 );
    void zPATH_OnInit( zSTRING )                          zCall( 0x00447EB0 );
    zPATH()                                               zInit( zPATH_OnInit() );
    zPATH( zSTRING a0 )                                   zInit( zPATH_OnInit( a0 ));
    zSTRING GetDirectoryPath()                            zCall( 0x004E9800 );
    zSTRING GetPath()                                     zCall( 0x004FBF70 );
    zSTRING GetFilename()                                 zCall( 0x0055DA90 );
    zSTRING GetExt()                                      zCall( 0x0055DAB0 );
    zSTRING GetDir()                                      zCall( 0x00567F30 );
    int SearchFile( zSTRING const&, zSTRING const&, int ) zCall( 0x00588270 );
    zSTRING GetFile()                                     zCall( 0x00589480 );
    zSTRING GetDrive()                                    zCall( 0x005A5F10 );
    virtual ~zPATH()                                      zCall( 0x0048D290 );

    // user API
    #include "zPATH.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZDISK_H__VER3__