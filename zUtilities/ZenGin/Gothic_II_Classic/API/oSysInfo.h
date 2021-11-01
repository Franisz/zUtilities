// Supported with union (c) 2018-2021 Union team

#ifndef __OSYS_INFO_H__VER2__
#define __OSYS_INFO_H__VER2__

#include "zSysInfo.h"

namespace Gothic_II_Classic {

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

    void oCSystemInfo_OnInit()          zCall( 0x00439420 );
    oCSystemInfo()                      zInit( oCSystemInfo_OnInit() );
    float GetGraphicsBonus()            zCall( 0x0043ABC0 );
    float GetSoundBonus()               zCall( 0x0043AD00 );
    zSTRING GetScoreDescr( float )      zCall( 0x0043AD10 );
    virtual ~oCSystemInfo()             zCall( 0x004394B0 );
    virtual void AnalyseNow()           zCall( 0x004394C0 );
    virtual void ScoreNow()             zCall( 0x00439DC0 );
    virtual void ResetSettings( float ) zCall( 0x004394D0 );

    // user API
    #include "oCSystemInfo.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OSYS_INFO_H__VER2__