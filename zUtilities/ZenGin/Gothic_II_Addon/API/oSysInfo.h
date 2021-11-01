// Supported with union (c) 2018-2021 Union team

#ifndef __OSYS_INFO_H__VER3__
#define __OSYS_INFO_H__VER3__

#include "zSysInfo.h"

namespace Gothic_II_Addon {

  // sizeof A0h
  class oCSystemInfo : public zCSystemInfo {
  public:
    int scored;        // sizeof 04h    offset 6Ch
    float cpuLow;      // sizeof 04h    offset 70h
    float cpuHigh;     // sizeof 04h    offset 74h
    float memLow;      // sizeof 04h    offset 78h
    float memHigh;     // sizeof 04h    offset 7Ch
    float graMemLow;   // sizeof 04h    offset 80h
    float graMemHigh;  // sizeof 04h    offset 84h
    float scoreCpu;    // sizeof 04h    offset 88h
    float scoreMem;    // sizeof 04h    offset 8Ch
    float scoreGraMem; // sizeof 04h    offset 90h
    float scoreGra;    // sizeof 04h    offset 94h
    float scoreSnd;    // sizeof 04h    offset 98h
    float score;       // sizeof 04h    offset 9Ch

    void oCSystemInfo_OnInit()          zCall( 0x00439A50 );
    oCSystemInfo()                      zInit( oCSystemInfo_OnInit() );
    float GetGraphicsBonus()            zCall( 0x0043B1F0 );
    float GetSoundBonus()               zCall( 0x0043B330 );
    zSTRING GetScoreDescr( float )      zCall( 0x0043B340 );
    virtual ~oCSystemInfo()             zCall( 0x00439AE0 );
    virtual void AnalyseNow()           zCall( 0x00439AF0 );
    virtual void ScoreNow()             zCall( 0x0043A3F0 );
    virtual void ResetSettings( float ) zCall( 0x00439B00 );

    // user API
    #include "oCSystemInfo.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OSYS_INFO_H__VER3__