// Supported with union (c) 2018 Union team

#ifndef __ZTOOLS_H__VER1__
#define __ZTOOLS_H__VER1__

namespace Gothic_I_Addon {
  const int zRAND_MAX = RAND_MAX;
  const float _PI     = 3.14159265358979323846f;

  class zCTimer {
  public:
    float factorMotion;
    float frameTimeFloat;
    float totalTimeFloat;
    unsigned long lastTimer;
    unsigned long frameTime;
    unsigned long totalTime;
    unsigned long minFrameTime;
    unsigned long FrameControlMaxVal;

    void zCTimer_OnInit()         zCall( 0x005ED2C0 );
    zCTimer()                     zInit( zCTimer_OnInit() );
    void ResetTimer()             zCall( 0x005ED2F0 );
    void SetFrameTime( float )    zCall( 0x005ED3C0 );
    void LimitFPS( int )          zCall( 0x005ED480 );
    void SetMotionFactor( float ) zCall( 0x00629910 );
    static void FrameUpdate()     zCall( 0x005ED410 );

    // user API
    #include "zCTimer.inl"
  };

  class zCChecksum {
  public:
    unsigned long checksum;

    zCChecksum() {}
    void BeginChecksum()                                                                zCall( 0x005ED5F0 );
    unsigned long EndChecksum()                                                         zCall( 0x005ED600 );
    void CalcBufferChecksum( unsigned char*, unsigned long )                            zCall( 0x005ED610 );
    void CalcFileChecksum( zFILE* )                                                     zCall( 0x005ED630 );
    void CalcFileChecksum( zSTRING const& )                                             zCall( 0x005ED6A0 );
    static unsigned long GetBufferCRC32( unsigned char*, unsigned long, unsigned long ) zCall( 0x005ED4B0 );

    // user API
    #include "zCChecksum.inl"
  };

  class zCChecksum16 {
  public:
    unsigned short checksum;

    zCChecksum16() {}
    void BeginChecksum()                                                                  zCall( 0x005ED8B0 );
    unsigned short EndChecksum()                                                          zCall( 0x005ED8C0 );
    void CalcBufferChecksum( unsigned char*, unsigned long )                              zCall( 0x005ED8D0 );
    static unsigned short GetBufferCRC16( unsigned char*, unsigned long, unsigned short ) zCall( 0x005ED740 );

    // user API
    #include "zCChecksum16.inl"
  };

  class zCFPUControler {
  public:
    unsigned long savedControlWord;
    unsigned long defaultControlWord;

    void zCFPUControler_OnInit()          zCall( 0x005ED950 );
    zCFPUControler()                      zInit( zCFPUControler_OnInit() );
    void SaveCurrentControlWord()         zCall( 0x005ED990 );
    void RestoreSavedControlWord()        zCall( 0x005ED9B0 );
    unsigned long GetCurrentControlWord() zCall( 0x005ED9C0 );
    void RestoreDefaultControlWord()      zCall( 0x005ED9D0 );
    void ComputeDefaultControlWord()      zCall( 0x005ED9E0 );
    void SetControlWord( unsigned long )  zCall( 0x005EDA20 );
    void SetPrecision_24()                zCall( 0x005EDA40 );
    void SetPrecision_53()                zCall( 0x005EDA60 );
    void SetPrecision_64()                zCall( 0x005EDA80 );
    void PrintStatus()                    zCall( 0x005EDAA0 );

    // user API
    #include "zCFPUControler.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZTOOLS_H__VER1__