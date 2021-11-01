// Supported with union (c) 2018-2021 Union team

#ifndef __ZDISK_H__VER2__
#define __ZDISK_H__VER2__

namespace Gothic_II_Classic {
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

  // sizeof 120h
  struct _finddata32i64_t_vc6 {
    unsigned  attrib;      // sizeof 04h    offset 00h
    long      time_create; // sizeof 04h    offset 04h
    long      time_access; // sizeof 04h    offset 08h
    long      time_write;  // sizeof 04h    offset 0Ch
    long long size;        // sizeof 08h    offset 10h
    char      name[260];   // sizeof 104h   offset 18h
  };

  // sizeof 10h
  class zDATE {
  public:
    unsigned int year;     // sizeof 04h    offset 00h
    unsigned short month;  // sizeof 02h    offset 04h
    unsigned short day;    // sizeof 02h    offset 06h
    unsigned short hour;   // sizeof 02h    offset 08h
    unsigned short minute; // sizeof 02h    offset 0Ah
    unsigned short second; // sizeof 02h    offset 0Ch

    zDATE() {}
    zDATE& operator =( long )          zCall( 0x00442230 );
    long ToTime_t()                    zCall( 0x00442280 );
    zSTRING ToString( zTDATE_CONVERT ) zCall( 0x004422D0 );

    // user API
    #include "zDATE.inl"
  };

  // sizeof 34h
  class zFILE_STATS {
  public:
    zDATE accessDate;  // sizeof 10h    offset 00h
    zDATE createDate;  // sizeof 10h    offset 10h
    zDATE modifyDate;  // sizeof 10h    offset 20h
    unsigned int size; // sizeof 04h    offset 30h

    zFILE_STATS() {}

    // user API
    #include "zFILE_STATS.inl"
  };

  // sizeof 28h
  class zFILE_INFO {
  public:
    zSTRING path; // sizeof 14h    offset 00h
    zSTRING name; // sizeof 14h    offset 14h

    zFILE_INFO() {}

    // user API
    #include "zFILE_INFO.inl"
  };

  // sizeof 10h
  class zFILE {
  public:
    bool write;       // sizeof 01h    offset 04h
    int buffering;    // sizeof 04h    offset 08h
    zCBuffer* buffer; // sizeof 04h    offset 0Ch

    void zFILE_OnInit()                                           zCall( 0x004428C0 );
    void zFILE_OnInit( zSTRING const& )                           zCall( 0x00442900 );
    zFILE()                                                       zInit( zFILE_OnInit() );
    zFILE( zSTRING const& a0 )                                    zInit( zFILE_OnInit( a0 ));
    static zSTRING SetRootDirectory( zSTRING )                    zCall( 0x00441C30 );
    static void DirectFileConvert( zSTRING& )                     zCall( 0x00441D60 );
    static void DirectFileAccess( bool )                          zCall( 0x00441F00 );
    static int LockDirScan()                                      zCall( 0x004420F0 );
    static int UnlockDirScan()                                    zCall( 0x00442110 );
    static void DirectFileAccess( bool, zSTRING& )                zCall( 0x00442130 );
    static zCBuffer* GetFreeBuffer()                              zCall( 0x00447910 );
    static void ReleaseBuffer( zCBuffer* )                        zCall( 0x00447C20 );
    static bool InitFileSystem()                                  zCall( 0x00447C60 );
    static bool DeinitFileSystem()                                zCall( 0x00447DB0 );
    virtual ~zFILE()                                              zCall( 0x00442920 );
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
    virtual long GetFreeDiskSpace()                               zCall( 0x004420E0 );
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

  // sizeof 1C0h
  class zFILE_FILE : public zFILE {
  public:
    zSTRING dir;                        // sizeof 14h    offset 10h
    zSTRING drive;                      // sizeof 14h    offset 24h
    zSTRING filename;                   // sizeof 14h    offset 38h
    zSTRING ext;                        // sizeof 14h    offset 4Ch
    zSTRING complete_path;              // sizeof 14h    offset 60h
    zSTRING complete_directory;         // sizeof 14h    offset 74h
    int error;                          // sizeof 04h    offset 88h
    FILE* file_handle;                  // sizeof 04h    offset 8Ch
    long file_mode;                     // sizeof 04h    offset 90h
    _finddata32i64_t_vc6 find_fileinfo; // sizeof 120h   offset 98h
    long find_handle;                   // sizeof 04h    offset 1B8h

    void zFILE_FILE_OnInit()                                      zCall( 0x004429A0 );
    void zFILE_FILE_OnInit( zSTRING const& )                      zCall( 0x00442E20 );
    int HandleError( zSTRING const&, zSTRING const&, int )        zCall( 0x00442440 );
    void Init( zSTRING const& )                                   zCall( 0x00442930 );
    zFILE_FILE()                                                  zInit( zFILE_FILE_OnInit() );
    zFILE_FILE( zSTRING const& a0 )                               zInit( zFILE_FILE_OnInit( a0 ));
    void SetCompletePath()                                        zCall( 0x00444D30 );
    zSTRING& SlashConvert( zSTRING& )                             zCall( 0x00445EC0 );
    static bool InitFileSystem()                                  zCall( 0x00447FB0 );
    static bool DeinitFileSystem()                                zCall( 0x00448020 );
    virtual ~zFILE_FILE()                                         zCall( 0x00442F50 );
    virtual void SetMode( long )                                  zCall( 0x00442B00 );
    virtual long GetMode()                                        zCall( 0x00442B10 );
    virtual void SetPath( zSTRING )                               zCall( 0x00444FA0 );
    virtual void SetDrive( zSTRING )                              zCall( 0x004454A0 );
    virtual void SetDir( zSTRING )                                zCall( 0x00445630 );
    virtual void SetFile( zSTRING )                               zCall( 0x00445BB0 );
    virtual void SetFilename( zSTRING )                           zCall( 0x00445890 );
    virtual void SetExt( zSTRING )                                zCall( 0x00445A20 );
    virtual _iobuf* GetFileHandle()                               zCall( 0x00442B20 );
    virtual zSTRING GetFullPath()                                 zCall( 0x00445D30 );
    virtual zSTRING GetPath()                                     zCall( 0x00442B30 );
    virtual zSTRING GetDirectoryPath()                            zCall( 0x00442B80 );
    virtual zSTRING GetDrive()                                    zCall( 0x00442BD0 );
    virtual zSTRING GetDir()                                      zCall( 0x00442C20 );
    virtual zSTRING GetFile()                                     zCall( 0x0043E6C0 );
    virtual zSTRING GetFilename()                                 zCall( 0x00442C70 );
    virtual zSTRING GetExt()                                      zCall( 0x0043E770 );
    virtual zSTRING SetCurrentDir()                               zCall( 0x00445FE0 );
    virtual int ChangeDir( bool )                                 zCall( 0x00446040 );
    virtual int SearchFile( zSTRING const&, zSTRING const&, int ) zCall( 0x00446490 );
    virtual bool FindFirst( zSTRING const& )                      zCall( 0x00446AD0 );
    virtual bool FindNext()                                       zCall( 0x004475E0 );
    virtual bool DirCreate()                                      zCall( 0x00446CC0 );
    virtual bool DirRemove()                                      zCall( 0x00446DD0 );
    virtual bool DirExists()                                      zCall( 0x00446ED0 );
    virtual bool FileMove( zSTRING, bool )                        zCall( 0x00446F90 );
    virtual bool FileMove( zFILE* )                               zCall( 0x00447230 );
    virtual bool FileCopy( zSTRING, bool )                        zCall( 0x004470A0 );
    virtual bool FileCopy( zFILE* )                               zCall( 0x00447360 );
    virtual bool FileDelete()                                     zCall( 0x004471B0 );
    virtual bool IsOpened()                                       zCall( 0x00442CC0 );
    virtual int Create()                                          zCall( 0x004433C0 );
    virtual int Create( zSTRING const& )                          zCall( 0x00442CD0 );
    virtual int Open( bool )                                      zCall( 0x00443660 );
    virtual int Open( zSTRING const&, bool )                      zCall( 0x00442D30 );
    virtual bool Exists()                                         zCall( 0x00443080 );
    virtual bool Exists( zSTRING const& )                         zCall( 0x00442DA0 );
    virtual int Close()                                           zCall( 0x004439E0 );
    virtual int Reset()                                           zCall( 0x00443C30 );
    virtual void Append()                                         zCall( 0x00443C40 );
    virtual long Size()                                           zCall( 0x00443270 );
    virtual long Pos()                                            zCall( 0x00443C70 );
    virtual int Seek( long )                                      zCall( 0x00443C80 );
    virtual bool Eof()                                            zCall( 0x00443C60 );
    virtual int GetStats( zFILE_STATS& )                          zCall( 0x00443100 );
    virtual int Write( char const* )                              zCall( 0x00443CA0 );
    virtual int Write( zSTRING const& )                           zCall( 0x00443DE0 );
    virtual long Write( void const*, long )                       zCall( 0x00443E00 );
    virtual long Read( void*, long )                              zCall( 0x00444270 );
    virtual int Read( char* )                                     zCall( 0x00444040 );
    virtual int Read( zSTRING& )                                  zCall( 0x00444080 );
    virtual int ReadChar( char& )                                 zCall( 0x00444020 );
    virtual zSTRING SeekText( zSTRING const& )                    zCall( 0x00444350 );
    virtual zSTRING ReadBlock( long, long )                       zCall( 0x004448B0 );
    virtual int UpdateBlock( zSTRING const&, long, long )         zCall( 0x00444980 );
    virtual long FlushBuffer()                                    zCall( 0x00443990 );
    virtual int ReadCodeline( zSTRING& )                          zCall( 0x00444500 );
    virtual int ReadLines( zSTRING&, long )                       zCall( 0x00444710 );
    virtual zSTRING DirStepInto( zSTRING )                        zCall( 0x00446290 );

    // user API
    #include "zFILE_FILE.inl"
  };

  // sizeof 08h
  class zPATH {
  public:
    enum zCOLLECT_MODE {
      CURRENT_ONLY,
      RECURSIVE
    };

    zFILE* path; // sizeof 04h    offset 04h

    void zPATH_OnInit()                                   zCall( 0x00447770 );
    void zPATH_OnInit( zSTRING )                          zCall( 0x00447880 );
    zPATH()                                               zInit( zPATH_OnInit() );
    zPATH( zSTRING a0 )                                   zInit( zPATH_OnInit( a0 ));
    zSTRING GetDirectoryPath()                            zCall( 0x004E6CF0 );
    zSTRING GetPath()                                     zCall( 0x004F92F0 );
    zSTRING GetFilename()                                 zCall( 0x00558870 );
    zSTRING GetExt()                                      zCall( 0x00558890 );
    zSTRING GetDir()                                      zCall( 0x00562CE0 );
    int SearchFile( zSTRING const&, zSTRING const&, int ) zCall( 0x00582D10 );
    zSTRING GetFile()                                     zCall( 0x00583F20 );
    zSTRING GetDrive()                                    zCall( 0x005A09B0 );
    virtual ~zPATH()                                      zCall( 0x0048B920 );

    // user API
    #include "zPATH.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZDISK_H__VER2__