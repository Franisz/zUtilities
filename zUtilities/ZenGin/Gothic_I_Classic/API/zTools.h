// Supported with union (c) 2018-2021 Union team

#ifndef __ZTOOLS_H__VER0__
#define __ZTOOLS_H__VER0__

namespace Gothic_I_Classic {
  const int zRAND_MAX = RAND_MAX;
  const float _PI     = 3.14159265358979323846f;

  // sizeof 1Ch
  class zCTimer {
  public:
    float factorMotion;         // sizeof 04h    offset 00h
    float frameTimeFloat;       // sizeof 04h    offset 04h
    float totalTimeFloat;       // sizeof 04h    offset 08h
    unsigned long lastTimer;    // sizeof 04h    offset 0Ch
    unsigned long frameTime;    // sizeof 04h    offset 10h
    unsigned long totalTime;    // sizeof 04h    offset 14h
    unsigned long minFrameTime; // sizeof 04h    offset 18h

    void zCTimer_OnInit()         zCall( 0x005CE520 );
    zCTimer()                     zInit( zCTimer_OnInit() );
    void ResetTimer()             zCall( 0x005CE550 );
    void SetFrameTime( float )    zCall( 0x005CE620 );
    void LimitFPS( int )          zCall( 0x005CE6E0 );
    void SetMotionFactor( float ) zCall( 0x00607640 );
    static void FrameUpdate()     zCall( 0x005CE670 );

    // user API
    #include "zCTimer.inl"
  };

  // sizeof 04h
  class zCChecksum {
  public:
    unsigned long checksum; // sizeof 04h    offset 00h

    zCChecksum() {}
    void BeginChecksum()                                                                zCall( 0x005CE850 );
    unsigned long EndChecksum()                                                         zCall( 0x005CE860 );
    void CalcBufferChecksum( unsigned char*, unsigned long )                            zCall( 0x005CE870 );
    void CalcFileChecksum( zFILE* )                                                     zCall( 0x005CE890 );
    void CalcFileChecksum( zSTRING const& )                                             zCall( 0x005CE900 );
    static unsigned long GetBufferCRC32( unsigned char*, unsigned long, unsigned long ) zCall( 0x005CE710 );

    // user API
    #include "zCChecksum.inl"
  };

  // sizeof 02h
  class zCChecksum16 {
  public:
    unsigned short checksum; // sizeof 02h    offset 00h

    zCChecksum16() {}
    void BeginChecksum()                                                                  zCall( 0x005CEAF0 );
    unsigned short EndChecksum()                                                          zCall( 0x005CEB00 );
    void CalcBufferChecksum( unsigned char*, unsigned long )                              zCall( 0x005CEB10 );
    static unsigned short GetBufferCRC16( unsigned char*, unsigned long, unsigned short ) zCall( 0x005CE9A0 );

    // user API
    #include "zCChecksum16.inl"
  };

  // sizeof 08h
  class zCFPUControler {
  public:
    unsigned long savedControlWord;   // sizeof 04h    offset 00h
    unsigned long defaultControlWord; // sizeof 04h    offset 04h

    void zCFPUControler_OnInit()          zCall( 0x005CEB90 );
    zCFPUControler()                      zInit( zCFPUControler_OnInit() );
    void SaveCurrentControlWord()         zCall( 0x005CEBD0 );
    void RestoreSavedControlWord()        zCall( 0x005CEBF0 );
    unsigned long GetCurrentControlWord() zCall( 0x005CEC00 );
    void RestoreDefaultControlWord()      zCall( 0x005CEC10 );
    void ComputeDefaultControlWord()      zCall( 0x005CEC20 );
    void SetControlWord( unsigned long )  zCall( 0x005CEC60 );
    void SetPrecision_24()                zCall( 0x005CEC80 );
    void SetPrecision_53()                zCall( 0x005CECA0 );
    void SetPrecision_64()                zCall( 0x005CECC0 );
    void PrintStatus()                    zCall( 0x005CECE0 );

    // user API
    #include "zCFPUControler.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZTOOLS_H__VER0__