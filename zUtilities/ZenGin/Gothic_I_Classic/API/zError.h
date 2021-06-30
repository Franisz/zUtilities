// Supported with union (c) 2018 Union team

#ifndef __ZERROR_H__VER0__
#define __ZERROR_H__VER0__

namespace Gothic_I_Classic {

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

  struct ASSERT_FAIL_INFO {
  public:
    char* HeaderText;
    char* AssertText;
    char* File;
    unsigned long Line;
    char* Reason;
    void* extInfo;
  };

  class zERROR {
  public:
    void( *onexit )( );
    zSTRING filter_authors;
    unsigned int filter_flag;
    signed char filter_level;
    int target;
    int ack_type;
    zFILE* log_file;
    unsigned char indent_depth;
    HWND spyHandle;
    zCMutex* spyMutex;

    void zERROR_OnInit()                                                                          zCall( 0x004476B0 );
    zERROR()                                                                                      zInit( zERROR_OnInit() );
    void Init( zSTRING )                                                                          zCall( 0x00447920 );
    void SendToSpy( zSTRING& )                                                                    zCall( 0x004481D0 );
    int Report( zERROR_LEVEL, int, zSTRING const&, signed char, unsigned int, int, char*, char* ) zCall( 0x00448240 );
    int Report( zERROR_TYPE, int, zSTRING const&, signed char, unsigned int, int, char*, char* )  zCall( 0x00448250 );
    void BlockBegin( char*, int )                                                                 zCall( 0x00448990 );
    void BlockEnd( char*, int )                                                                   zCall( 0x00448BF0 );
    void Separator( zSTRING )                                                                     zCall( 0x00448F90 );
    void ShowSpy( int )                                                                           zCall( 0x004491A0 );
    int Message( zSTRING const& )                                                                 zCall( 0x004492F0 );
    int Warning( zSTRING const& )                                                                 zCall( 0x00449330 );
    int Fatal( zSTRING const& )                                                                   zCall( 0x00449360 );
    int Fault( zSTRING const& )                                                                   zCall( 0x00449390 );
    void SetFilterFlags( unsigned long )                                                          zCall( 0x004493C0 );
    void SetFilterAuthors( zSTRING )                                                              zCall( 0x004494E0 );
    void SetFilterLevel( int )                                                                    zCall( 0x00449680 );
    void SetTarget( int )                                                                         zCall( 0x004497B0 );
    zSTRING GetTargetDescription()                                                                zCall( 0x00449A40 );
    zSTRING GetFilterFlagDescription()                                                            zCall( 0x00449C60 );
    zSTRING GetFilterAuthors()                                                                    zCall( 0x00449E60 );
    bool SearchForSpy()                                                                           zCall( 0x00449EB0 );
    int GetFilterLevel()                                                                          zCall( 0x0057E350 );
    virtual ~zERROR( void )                                                                       zCall( 0x00447FD0 );

    // user API
    #include "zERROR.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZERROR_H__VER0__