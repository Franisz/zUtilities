// Supported with union (c) 2018 Union team

#ifndef __ZSCAN_DIR_H__VER2__
#define __ZSCAN_DIR_H__VER2__

#include "zDisk.h"

namespace Gothic_II_Classic {

  class zCScanDirFileHandler {
  public:
    zCArray<zSTRING> msgList;
    zCArray<zSTRING> extList;
    zSTRING name;

    void zCScanDirFileHandler_OnInit()                                 zCall( 0x00467FB0 );
    zCScanDirFileHandler()                                             zInit( zCScanDirFileHandler_OnInit() );
    int CanHandleFile( zSTRING& )                                      zCall( 0x004681B0 );
    int GetNumMessages()                                               zCall( 0x004683D0 );
    zSTRING GetMessageA( int )                                         zCall( 0x004683E0 );
    void RegisterFileType( zSTRING )                                   zCall( 0x00468570 );
    void AddMessage( zSTRING )                                         zCall( 0x004686D0 );
    void ClearMessages()                                               zCall( 0x00468830 );
    void SetName( zSTRING const& )                                     zCall( 0x00468860 );
    zSTRING& GetName()                                                 zCall( 0x004689A0 );
    virtual ~zCScanDirFileHandler()                                    zCall( 0x004680E0 );
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

    void zCScanDir_OnInit()                                                   zCall( 0x004689B0 );
    zCScanDir()                                                               zInit( zCScanDir_OnInit() );
    void ScanX()                                                              zCall( 0x00468BD0 );
    virtual ~zCScanDir()                                                      zCall( 0x004689F0 );
    virtual void RegisterFileHandler( zCScanDirFileHandler*, zSTRING const& ) zCall( 0x00468A80 );
    virtual void Scan( zSTRING const& )                                       zCall( 0x00469390 );

    // user API
    #include "zCScanDir.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZSCAN_DIR_H__VER2__