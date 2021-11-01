// Supported with union (c) 2018-2021 Union team

#ifndef __ZFILE_CSV_H__VER1__
#define __ZFILE_CSV_H__VER1__

#include "zDisk.h"

namespace Gothic_I_Addon {

  // sizeof 228h
  class zCFileCSV : public zFILE_FILE {
  public:
    zCArray<zSTRING> columnList;  // sizeof 0Ch    offset 1C0h
    bool headerProcessed;         // sizeof 01h    offset 1CCh
    zSTRING current_set;          // sizeof 14h    offset 1D0h
    bool csvHasHeader;            // sizeof 01h    offset 1E4h
    zSTRING csvFieldDelimiter;    // sizeof 14h    offset 1E8h
    zSTRING csvFieldFrame;        // sizeof 14h    offset 1FCh
    zSTRING csvCompleteDelimiter; // sizeof 14h    offset 210h
    int column;                   // sizeof 04h    offset 224h

    void zCFileCSV_OnInit( zSTRING const& )                zCall( 0x004504C0 );
    void zCFileCSV_OnInit()                                zCall( 0x004506D0 );
    zCFileCSV( zSTRING const& a0 )                         zInit( zCFileCSV_OnInit( a0 ));
    zCFileCSV()                                            zInit( zCFileCSV_OnInit() );
    void InitCSV()                                         zCall( 0x00450A20 );
    void SetFormat( bool, zSTRING const&, zSTRING const& ) zCall( 0x00450B80 );
    void AddNextField( zSTRING const& )                    zCall( 0x00450CD0 );
    void AddNextHeader( zSTRING const& )                   zCall( 0x00450EA0 );
    int WriteSet()                                         zCall( 0x00451080 );
    zSTRING GetNextField( zSTRING const& )                 zCall( 0x00451250 );
    int ReadSet()                                          zCall( 0x00451700 );
    int ReadHeader()                                       zCall( 0x00451750 );
    int WriteHeader()                                      zCall( 0x00451960 );
    virtual ~zCFileCSV()                                   zCall( 0x004508B0 );

    // user API
    #include "zCFileCSV.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZFILE_CSV_H__VER1__