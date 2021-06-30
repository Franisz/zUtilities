// Supported with union (c) 2018 Union team

#ifndef __OSYS_INFO_H__VER1__
#define __OSYS_INFO_H__VER1__

#include "zSysInfo.h"

namespace Gothic_I_Addon {

  class oCSystemInfo : public zCSystemInfo {
  public:
    int scored;
    float cpuLow;
    float cpuHigh;
    float memLow;
    float memHigh;
    float graMemLow;
    float graMemHigh;
    float scoreCpu;
    float scoreMem;
    float scoreGraMem;
    float scoreGra;
    float scoreSnd;
    float score;

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