// Supported with union (c) 2018-2021 Union team

#ifndef __OSYS_INFO_H__VER1__
#define __OSYS_INFO_H__VER1__

#include "zSysInfo.h"

namespace Gothic_I_Addon {

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

    void oCSystemInfo_OnInit()          zCall( 0x0043A910 );
    oCSystemInfo()                      zInit( oCSystemInfo_OnInit() );
    float GetGraphicsBonus()            zCall( 0x0043C070 );
    float GetSoundBonus()               zCall( 0x0043C0D0 );
    zSTRING GetScoreDescr( float )      zCall( 0x0043C0E0 );
    virtual ~oCSystemInfo()             zCall( 0x0043A9A0 );
    virtual void AnalyseNow()           zCall( 0x0043A9B0 );
    virtual void ScoreNow()             zCall( 0x0043B2A0 );
    virtual void ResetSettings( float ) zCall( 0x0043A9C0 );

    // user API
    #include "oCSystemInfo.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OSYS_INFO_H__VER1__