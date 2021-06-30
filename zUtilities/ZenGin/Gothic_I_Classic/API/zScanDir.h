// Supported with union (c) 2018 Union team

#ifndef __ZSCAN_DIR_H__VER0__
#define __ZSCAN_DIR_H__VER0__

#include "zDisk.h"

namespace Gothic_I_Classic {

  class zCScanDirFileHandler {
  public:
    zCArray<zSTRING> msgList;
    zCArray<zSTRING> extList;
    zSTRING name;

    void zCScanDirFileHandler_OnInit()                                 zCall( 0x00463500 );
    zCScanDirFileHandler()                                             zInit( zCScanDirFileHandler_OnInit() );
    int CanHandleFile( zSTRING& )                                      zCall( 0x00463700 );
    int GetNumMessages()                                               zCall( 0x00463920 );
    zSTRING GetMessageA( int )                                         zCall( 0x00463930 );
    void RegisterFileType( zSTRING )                                   zCall( 0x00463AC0 );
    void AddMessage( zSTRING )                                         zCall( 0x00463C30 );
    void ClearMessages()                                               zCall( 0x00463DA0 );
    void SetName( zSTRING const& )                                     zCall( 0x00463DD0 );
    zSTRING& GetName()                                                 zCall( 0x00463F10 );
    virtual ~zCScanDirFileHandler()                                    zCall( 0x00463630 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zPureCall;

    // user API
    #include "zCScanDirFileHandler.inl"
  };

  class zCScanDir {
  public:
    zCList<zCScanDirFileHandler> cbList;
    int statFoundFiles;
    int statHandledFiles;
    int statTouchedFiles;

    void zCScanDir_OnInit()                                                   zCall( 0x00463F20 );
    zCScanDir()                                                               zInit( zCScanDir_OnInit() );
    void ScanX()                                                              zCall( 0x00464140 );
    virtual ~zCScanDir()                                                      zCall( 0x00463F60 );
    virtual void RegisterFileHandler( zCScanDirFileHandler*, zSTRING const& ) zCall( 0x00463FF0 );
    virtual void Scan( zSTRING const& )                                       zCall( 0x00464900 );

    // user API
    #include "zCScanDir.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZSCAN_DIR_H__VER0__