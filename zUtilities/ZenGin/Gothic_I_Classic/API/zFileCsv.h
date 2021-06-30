// Supported with union (c) 2018 Union team

#ifndef __ZFILE_CSV_H__VER0__
#define __ZFILE_CSV_H__VER0__

#include "zDisk.h"

namespace Gothic_I_Classic {

  class zCFileCSV : public zFILE_FILE {
  public:
    zCArray<zSTRING> columnList;
    bool headerProcessed;
    zSTRING current_set;
    bool csvHasHeader;
    zSTRING csvFieldDelimiter;
    zSTRING csvFieldFrame;
    zSTRING csvCompleteDelimiter;
    int column;

    void zCFileCSV_OnInit( zSTRING const& )                zCall( 0x0044A1B0 );
    void zCFileCSV_OnInit()                                zCall( 0x0044A370 );
    zCFileCSV( zSTRING const& a0 )                         zInit( zCFileCSV_OnInit( a0 ));
    zCFileCSV()                                            zInit( zCFileCSV_OnInit() );
    void InitCSV()                                         zCall( 0x0044A670 );
    void SetFormat( bool, zSTRING const&, zSTRING const& ) zCall( 0x0044A790 );
    void AddNextField( zSTRING const& )                    zCall( 0x0044A8D0 );
    void AddNextHeader( zSTRING const& )                   zCall( 0x0044AA60 );
    int WriteSet()                                         zCall( 0x0044AC10 );
    zSTRING GetNextField( zSTRING const& )                 zCall( 0x0044ADD0 );
    int ReadSet()                                          zCall( 0x0044B200 );
    int ReadHeader()                                       zCall( 0x0044B250 );
    int WriteHeader()                                      zCall( 0x0044B430 );
    virtual ~zCFileCSV()                                   zCall( 0x0044A510 );

    // user API
    #include "zCFileCSV.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZFILE_CSV_H__VER0__