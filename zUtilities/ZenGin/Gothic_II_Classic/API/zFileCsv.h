// Supported with union (c) 2018 Union team

#ifndef __ZFILE_CSV_H__VER2__
#define __ZFILE_CSV_H__VER2__

#include "zDisk.h"

namespace Gothic_II_Classic {

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

    void zCFileCSV_OnInit( zSTRING const& )                zCall( 0x0044E1E0 );
    void zCFileCSV_OnInit()                                zCall( 0x0044E3A0 );
    zCFileCSV( zSTRING const& a0 )                         zInit( zCFileCSV_OnInit( a0 ));
    zCFileCSV()                                            zInit( zCFileCSV_OnInit() );
    void InitCSV()                                         zCall( 0x0044E6A0 );
    void SetFormat( bool, zSTRING const&, zSTRING const& ) zCall( 0x0044E7C0 );
    void AddNextField( zSTRING const& )                    zCall( 0x0044E900 );
    void AddNextHeader( zSTRING const& )                   zCall( 0x0044EA90 );
    int WriteSet()                                         zCall( 0x0044EC40 );
    zSTRING GetNextField( zSTRING const& )                 zCall( 0x0044EE00 );
    int ReadSet()                                          zCall( 0x0044F230 );
    int ReadHeader()                                       zCall( 0x0044F280 );
    int WriteHeader()                                      zCall( 0x0044F460 );
    virtual ~zCFileCSV()                                   zCall( 0x0044E540 );

    // user API
    #include "zCFileCSV.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZFILE_CSV_H__VER2__