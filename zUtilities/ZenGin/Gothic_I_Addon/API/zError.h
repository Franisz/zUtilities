// Supported with union (c) 2018-2021 Union team

#ifndef __ZERROR_H__VER1__
#define __ZERROR_H__VER1__

namespace Gothic_I_Addon {
  const int zERR_NONE     = 0;
  const int zERR_NO       = 1;
  const int zERR_UNKNOWN  = 2;
  const int zERR_LV_NONE        = -1;
  const int zERR_LV_SECTION     = 1;
  const int zERR_LV_SUBSECTION  = 3;
  const int zERR_LV_LOADSECTION = 2;
  const int zERR_LV_LOADFILE1   = 3;
  const int zERR_LV_LOADFILE2   = 4;
  const int zERR_LV_LOADFILE3   = 5;
  const int zERR_LV_ROUTINE1    = 4;
  const int zERR_LV_ROUTINE2    = 5;
  const int zERR_LV_ROUTINE3    = 6;
  const int zERR_LV_NEWOBJECT   = 8;
  const int zERR_LV_FUNCENTER   = 9;
  const int zERR_LV_FUNCLEAVE   = 10;
  const int zERR_LV_DETAIL      = 10;
  const int zERR_LV_IMPORTANT   = 1;
  const int zERR_LV_DEFAULT     = 5;

  enum zERROR_TYPE {
    zERR_TYPE_OK,
    zERR_TYPE_INFO,
    zERR_TYPE_WARN,
    zERR_TYPE_FAULT,
    zERR_TYPE_FATAL
  };

  enum zERROR_LEVEL {
    zERR_OK,
    zERR_INFO,
    zERR_WARN,
    zERR_FAULT,
    zERR_FATAL
  };

  enum {
    zERR_TARGET_SPY  = 1 << 0,
    zERR_TARGET_FILE = 1 << 1
  };

  enum {
    zERR_BEGIN = 1 << 0,
    zERR_END   = 1 << 1
  };

  // sizeof 18h
  struct ASSERT_FAIL_INFO {
  public:
    char* HeaderText;   // sizeof 04h    offset 00h
    char* AssertText;   // sizeof 04h    offset 04h
    char* File;         // sizeof 04h    offset 08h
    unsigned long Line; // sizeof 04h    offset 0Ch
    char* Reason;       // sizeof 04h    offset 10h
    void* extInfo;      // sizeof 04h    offset 14h
  };

  // sizeof 3Ch
  class zERROR {
  public:
    void( *onexit )( );         // sizeof 04h    offset 04h
    zSTRING filter_authors;     // sizeof 14h    offset 08h
    unsigned int filter_flag;   // sizeof 04h    offset 1Ch
    signed char filter_level;   // sizeof 01h    offset 20h
    int target;                 // sizeof 04h    offset 24h
    int ack_type;               // sizeof 04h    offset 28h
    zFILE* log_file;            // sizeof 04h    offset 2Ch
    unsigned char indent_depth; // sizeof 01h    offset 30h
    HWND spyHandle;             // sizeof 04h    offset 34h
    zCMutex* spyMutex;          // sizeof 04h    offset 38h

    void zERROR_OnInit()                                                                          zCall( 0x0044D6D0 );
    zERROR()                                                                                      zInit( zERROR_OnInit() );
    void Init( zSTRING )                                                                          zCall( 0x0044D950 );
    void SendToSpy( zSTRING& )                                                                    zCall( 0x0044E210 );
    int Report( zERROR_LEVEL, int, zSTRING const&, signed char, unsigned int, int, char*, char* ) zCall( 0x0044E280 );
    int Report( zERROR_TYPE, int, zSTRING const&, signed char, unsigned int, int, char*, char* )  zCall( 0x0044E2B0 );
    void BlockBegin( char*, int )                                                                 zCall( 0x0044EB20 );
    void BlockEnd( char*, int )                                                                   zCall( 0x0044ED70 );
    void Separator( zSTRING )                                                                     zCall( 0x0044F160 );
    void ShowSpy( int )                                                                           zCall( 0x0044F3B0 );
    int Message( zSTRING const& )                                                                 zCall( 0x0044F510 );
    int Warning( zSTRING const& )                                                                 zCall( 0x0044F550 );
    int Fatal( zSTRING const& )                                                                   zCall( 0x0044F580 );
    int Fault( zSTRING const& )                                                                   zCall( 0x0044F5B0 );
    void SetFilterFlags( unsigned long )                                                          zCall( 0x0044F5E0 );
    void SetFilterAuthors( zSTRING )                                                              zCall( 0x0044F710 );
    void SetFilterLevel( int )                                                                    zCall( 0x0044F8F0 );
    void SetTarget( int )                                                                         zCall( 0x0044FA20 );
    zSTRING GetTargetDescription()                                                                zCall( 0x0044FCE0 );
    zSTRING GetFilterFlagDescription()                                                            zCall( 0x0044FF30 );
    zSTRING GetFilterAuthors()                                                                    zCall( 0x00450160 );
    bool SearchForSpy()                                                                           zCall( 0x004501B0 );
    int GetFilterLevel()                                                                          zCall( 0x00598B80 );
    virtual ~zERROR( void )                                                                       zCall( 0x0044DFF0 );

    // user API
    #include "zERROR.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZERROR_H__VER1__