// Supported with union (c) 2018 Union team

#ifndef __OSYS_INFO_H__VER2__
#define __OSYS_INFO_H__VER2__

#include "zSysInfo.h"

namespace Gothic_II_Classic {

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