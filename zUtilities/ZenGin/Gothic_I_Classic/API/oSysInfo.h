// Supported with union (c) 2018 Union team

#ifndef __OSYS_INFO_H__VER0__
#define __OSYS_INFO_H__VER0__

#include "zSysInfo.h"

namespace Gothic_I_Classic {

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

    void oCSystemInfo_OnInit()          zCall( 0x00436470 );
    oCSystemInfo()                      zInit( oCSystemInfo_OnInit() );
    float GetGraphicsBonus()            zCall( 0x004379D0 );
    float GetSoundBonus()               zCall( 0x00437A30 );
    zSTRING GetScoreDescr( float )      zCall( 0x00437A40 );
    virtual ~oCSystemInfo()             zCall( 0x00436500 );
    virtual void AnalyseNow()           zCall( 0x00436510 );
    virtual void ScoreNow()             zCall( 0x00436D70 );
    virtual void ResetSettings( float ) zCall( 0x00436520 );

    // user API
    #include "oCSystemInfo.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OSYS_INFO_H__VER0__