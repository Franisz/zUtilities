// Supported with union (c) 2018 Union team

#ifndef __ZTOOLS_H__VER3__
#define __ZTOOLS_H__VER3__

namespace Gothic_II_Addon {
  const int zRAND_MAX = RAND_MAX;
  const float _PI     = 3.14159265358979323846F;

  class zCTimer {
  public:
    float factorMotion;
    float frameTimeFloat;
    float totalTimeFloat;
    float frameTimeFloatSecs;
    float totalTimeFloatSecs;
    unsigned long lastTimer;
    unsigned long frameTime;
    unsigned long totalTime;
    unsigned long minFrameTime;
    unsigned long forcedMaxFrameTime;

    void zCTimer_OnInit()                    zCall( 0x005F9680 );
    zCTimer()                                zInit( zCTimer_OnInit() );
    void ResetTimer()                        zCall( 0x005F96B0 );
    void SetFrameTime( float )               zCall( 0x005F9800 );
    void SetMaxFPS( unsigned long )          zCall( 0x005F9890 );
    void LimitFPS( int )                     zCall( 0x005F9920 );
    void SetMotionFactor( float )            zCall( 0x006370B0 );
    static void S_SetMaxFPS( unsigned long ) zCall( 0x005F9870 );
    static unsigned long S_GetMaxFPS()       zCall( 0x005F9880 );
    static void FrameUpdate()                zCall( 0x005F98A0 );

    // static properties
    static unsigned long& s_forcedMaxFrameTime;

    // user API
    #include "zCTimer.inl"
  };

  class zCChecksum {
  public:
    unsigned long checksum;

    zCChecksum() {}
    void BeginChecksum()                                                                zCall( 0x005F9B50 );
    unsigned long EndChecksum()                                                         zCall( 0x005F9B60 );
    void CalcBufferChecksum( unsigned char*, unsigned long )                            zCall( 0x005F9B70 );
    void CalcFileChecksum( zFILE* )                                                     zCall( 0x005F9B90 );
    void CalcFileChecksum( zSTRING const& )                                             zCall( 0x005F9BF0 );
    static unsigned long GetBufferCRC32( unsigned char*, unsigned long, unsigned long ) zCall( 0x005F9A10 );

    // user API
    #include "zCChecksum.inl"
  };

  class zCChecksum16 {
  public:
    unsigned short checksum;

    zCChecksum16() {}
    void BeginChecksum()                                                                  zCall( 0x005F9DD0 );
    unsigned short EndChecksum()                                                          zCall( 0x005F9DE0 );
    void CalcBufferChecksum( unsigned char*, unsigned long )                              zCall( 0x005F9DF0 );
    static unsigned short GetBufferCRC16( unsigned char*, unsigned long, unsigned short ) zCall( 0x005F9C80 );

    // user API
    #include "zCChecksum16.inl"
  };

  class zCFPUControler {
  public:
    unsigned long savedControlWord;
    unsigned long defaultControlWord;

    void zCFPUControler_OnInit()          zCall( 0x005F9E70 );
    zCFPUControler()                      zInit( zCFPUControler_OnInit() );
    void SaveCurrentControlWord()         zCall( 0x005F9EB0 );
    void RestoreSavedControlWord()        zCall( 0x005F9ED0 );
    unsigned long GetCurrentControlWord() zCall( 0x005F9EE0 );
    void RestoreDefaultControlWord()      zCall( 0x005F9EF0 );
    void ComputeDefaultControlWord()      zCall( 0x005F9F00 );
    void SetControlWord( unsigned long )  zCall( 0x005F9F40 );
    void SetPrecision_24()                zCall( 0x005F9F60 );
    void SetPrecision_53()                zCall( 0x005F9F80 );
    void SetPrecision_64()                zCall( 0x005F9FA0 );
    void PrintStatus()                    zCall( 0x005F9FC0 );

    // user API
    #include "zCFPUControler.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZTOOLS_H__VER3__