// Supported with union (c) 2018 Union team

#ifndef __ZSYS_INFO_H__VER2__
#define __ZSYS_INFO_H__VER2__

namespace Gothic_II_Classic {

  class zCSystemInfo {
  public:
    enum zTOperatingSystem {
      OS_UNKNOWN,
      OS_WINDOWS_3_1,
      OS_WINDOWS_95,
      OS_WINDOWS_98,
      OS_WINDOWS_98ME,
      OS_WINDOWS_NT,
      OS_WINDOWS_2000,
      OS_OTHER
    };

    enum zTCpuType {
      CPU_UNKNOWN,
      CPU_INTEL_PENTIUM_I,
      CPU_INTEL_PENTIUM_II,
      CPU_INTEL_PENTIUM_III,
      CPU_INTEL_PENTIUM_IV,
      CPU_AMD_K6,
      CPU_AMD_ATHLON,
      CPU_OTHER
    };

    zTOperatingSystem osType;
    zSTRING osName;
    zSTRING osServicePack;
    zTCpuType cpuType;
    zSTRING cpuID;
    unsigned long cpuSpeed;
    unsigned long memSize;
    unsigned long memAvailable;
    zSTRING graName;
    unsigned long graMemSize;

    void zCSystemInfo_OnInit() zCall( 0x0046C580 );
    zCSystemInfo()             zInit( zCSystemInfo_OnInit() );
    void AnalyseMemory()       zCall( 0x0046C820 );
    void AnalyseCpu()          zCall( 0x0046C850 );
    void AnalyseOs()           zCall( 0x0046CA20 );
    void AnalyseGcard()        zCall( 0x0046CE50 );
    zSTRING GetOsName()        zCall( 0x0046D7D0 );
    virtual ~zCSystemInfo()    zCall( 0x0046C740 );
    virtual void AnalyseNow()  zCall( 0x0046CE70 );

    // user API
    #include "zCSystemInfo.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZSYS_INFO_H__VER2__