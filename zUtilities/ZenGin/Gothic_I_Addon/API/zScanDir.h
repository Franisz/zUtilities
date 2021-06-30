// Supported with union (c) 2018 Union team

#ifndef __ZSCAN_DIR_H__VER1__
#define __ZSCAN_DIR_H__VER1__

#include "zDisk.h"

namespace Gothic_I_Addon {

  class zCScanDirFileHandler {
  public:
    zCArray<zSTRING> msgList;
    zCArray<zSTRING> extList;
    zSTRING name;

    void zCScanDirFileHandler_OnInit()                                 zCall( 0x0046B010 );
    zCScanDirFileHandler()                                             zInit( zCScanDirFileHandler_OnInit() );
    int CanHandleFile( zSTRING& )                                      zCall( 0x0046B220 );
    int GetNumMessages()                                               zCall( 0x0046B460 );
    zSTRING GetMessageA( int )                                         zCall( 0x0046B470 );
    void RegisterFileType( zSTRING )                                   zCall( 0x0046B620 );
    void AddMessage( zSTRING )                                         zCall( 0x0046B7B0 );
    void ClearMessages()                                               zCall( 0x0046B940 );
    void SetName( zSTRING const& )                                     zCall( 0x0046B970 );
    zSTRING& GetName()                                                 zCall( 0x0046BAB0 );
    virtual ~zCScanDirFileHandler()                                    zCall( 0x0046B140 );
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

    void zCScanDir_OnInit()                                                   zCall( 0x0046BAC0 );
    zCScanDir()                                                               zInit( zCScanDir_OnInit() );
    void ScanX()                                                              zCall( 0x0046BCD0 );
    virtual ~zCScanDir()                                                      zCall( 0x0046BB00 );
    virtual void RegisterFileHandler( zCScanDirFileHandler*, zSTRING const& ) zCall( 0x0046BB90 );
    virtual void Scan( zSTRING const& )                                       zCall( 0x0046C520 );

    // user API
    #include "zCScanDir.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZSCAN_DIR_H__VER1__