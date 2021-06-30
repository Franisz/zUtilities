// Supported with union (c) 2018 Union team

#ifndef __ZSCAN_DIR_H__VER3__
#define __ZSCAN_DIR_H__VER3__

#include "zDisk.h"

namespace Gothic_II_Addon {

  class zCScanDirFileHandler {
  public:
    zCArray<zSTRING> msgList;
    zCArray<zSTRING> extList;
    zSTRING name;

    void zCScanDirFileHandler_OnInit()                                 zCall( 0x00468BE0 );
    zCScanDirFileHandler()                                             zInit( zCScanDirFileHandler_OnInit() );
    int CanHandleFile( zSTRING& )                                      zCall( 0x00468DE0 );
    int GetNumMessages()                                               zCall( 0x00469000 );
    zSTRING GetMessageA( int )                                         zCall( 0x00469010 );
    void RegisterFileType( zSTRING )                                   zCall( 0x004691A0 );
    void AddMessage( zSTRING )                                         zCall( 0x00469300 );
    void ClearMessages()                                               zCall( 0x00469460 );
    void SetName( zSTRING const& )                                     zCall( 0x00469490 );
    zSTRING& GetName()                                                 zCall( 0x004695D0 );
    virtual ~zCScanDirFileHandler()                                    zCall( 0x00468D10 );
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

    void zCScanDir_OnInit()                                                   zCall( 0x004695E0 );
    zCScanDir()                                                               zInit( zCScanDir_OnInit() );
    void ScanX()                                                              zCall( 0x00469800 );
    virtual ~zCScanDir()                                                      zCall( 0x00469620 );
    virtual void RegisterFileHandler( zCScanDirFileHandler*, zSTRING const& ) zCall( 0x004696B0 );
    virtual void Scan( zSTRING const& )                                       zCall( 0x00469FC0 );

    // user API
    #include "zCScanDir.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZSCAN_DIR_H__VER3__