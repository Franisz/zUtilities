// Supported with union (c) 2018-2021 Union team

#ifndef __ZSCAN_DIR_H__VER2__
#define __ZSCAN_DIR_H__VER2__

#include "zDisk.h"

namespace Gothic_II_Classic {

  // sizeof 30h
  class zCScanDirFileHandler {
  public:
    zCArray<zSTRING> msgList; // sizeof 0Ch    offset 04h
    zCArray<zSTRING> extList; // sizeof 0Ch    offset 10h
    zSTRING name;             // sizeof 14h    offset 1Ch

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

  // sizeof 18h
  class zCScanDir {
  public:
    zCList<zCScanDirFileHandler> cbList; // sizeof 08h    offset 04h
    int statFoundFiles;                  // sizeof 04h    offset 0Ch
    int statHandledFiles;                // sizeof 04h    offset 10h
    int statTouchedFiles;                // sizeof 04h    offset 14h

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