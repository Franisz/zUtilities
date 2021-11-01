// Supported with union (c) 2018-2021 Union team

#ifndef __ZERROR_H__VER2__
#define __ZERROR_H__VER2__

namespace Gothic_II_Classic {
  const int zERR_NONE           = 0;
  const int zERR_NO             = 1;
  const int zERR_UNKNOWN        = 2;
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

    void zERROR_OnInit()                                                                          zCall( 0x0044B5F0 );
    zERROR()                                                                                      zInit( zERROR_OnInit() );
    void Init( zSTRING )                                                                          zCall( 0x0044B850 );
    void SendToSpy( zSTRING& )                                                                    zCall( 0x0044C100 );
    int Report( zERROR_LEVEL, int, zSTRING const&, signed char, unsigned int, int, char*, char* ) zCall( 0x0044C170 );
    int Report( zERROR_TYPE, int, zSTRING const&, signed char, unsigned int, int, char*, char* )  zCall( 0x0044C180 );
    void BlockBegin( char*, int )                                                                 zCall( 0x0044C910 );
    void BlockEnd( char*, int )                                                                   zCall( 0x0044CB40 );
    void Separator( zSTRING )                                                                     zCall( 0x0044CF60 );
    void ShowSpy( int )                                                                           zCall( 0x0044D170 );
    int Message( zSTRING const& )                                                                 zCall( 0x0044D2C0 );
    int Warning( zSTRING const& )                                                                 zCall( 0x0044D300 );
    int Fatal( zSTRING const& )                                                                   zCall( 0x0044D330 );
    int Fault( zSTRING const& )                                                                   zCall( 0x0044D360 );
    void SetFilterFlags( unsigned long )                                                          zCall( 0x0044D390 );
    void SetFilterAuthors( zSTRING )                                                              zCall( 0x0044D4B0 );
    void SetFilterLevel( int )                                                                    zCall( 0x0044D650 );
    void SetTarget( int )                                                                         zCall( 0x0044D800 );
    zSTRING GetTargetDescription()                                                                zCall( 0x0044DA80 );
    zSTRING GetFilterFlagDescription()                                                            zCall( 0x0044DCA0 );
    zSTRING GetFilterAuthors()                                                                    zCall( 0x0044DEA0 );
    bool SearchForSpy()                                                                           zCall( 0x0044DEF0 );
    int GetFilterLevel()                                                                          zCall( 0x00597BD0 );
    virtual ~zERROR()                                                                             zCall( 0x0044BF00 );

    // user API
    #include "zERROR.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZERROR_H__VER2__