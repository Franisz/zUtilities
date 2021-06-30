// Supported with union (c) 2018 Union team

#ifndef __ZFILE_CSV_H__VER3__
#define __ZFILE_CSV_H__VER3__

#include "zDisk.h"

namespace Gothic_II_Addon {

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

    void zCFileCSV_OnInit( zSTRING const& )                zCall( 0x0044E930 );
    void zCFileCSV_OnInit()                                zCall( 0x0044EAF0 );
    zCFileCSV( zSTRING const& a0 )                         zInit( zCFileCSV_OnInit( a0 ));
    zCFileCSV()                                            zInit( zCFileCSV_OnInit() );
    void InitCSV()                                         zCall( 0x0044EDF0 );
    void SetFormat( bool, zSTRING const&, zSTRING const& ) zCall( 0x0044EF10 );
    void AddNextField( zSTRING const& )                    zCall( 0x0044F050 );
    void AddNextHeader( zSTRING const& )                   zCall( 0x0044F1E0 );
    int WriteSet()                                         zCall( 0x0044F390 );
    zSTRING GetNextField( zSTRING const& )                 zCall( 0x0044F550 );
    int ReadSet()                                          zCall( 0x0044F980 );
    int ReadHeader()                                       zCall( 0x0044F9D0 );
    int WriteHeader()                                      zCall( 0x0044FBB0 );
    virtual ~zCFileCSV()                                   zCall( 0x0044EC90 );

    // user API
    #include "zCFileCSV.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZFILE_CSV_H__VER3__