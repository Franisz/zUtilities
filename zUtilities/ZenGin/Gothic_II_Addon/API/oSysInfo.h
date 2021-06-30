// Supported with union (c) 2018 Union team

#ifndef __OSYS_INFO_H__VER3__
#define __OSYS_INFO_H__VER3__

#include "zSysInfo.h"

namespace Gothic_II_Addon {

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