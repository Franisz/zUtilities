// Supported with union (c) 2018 Union team

#ifndef __ZSYS_INFO_H__VER0__
#define __ZSYS_INFO_H__VER0__

namespace Gothic_I_Classic {

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

    void zCSystemInfo_OnInit() zCall( 0x00467FE0 );
    zCSystemInfo()             zInit( zCSystemInfo_OnInit() );
    void AnalyseMemory()       zCall( 0x00468280 );
    void AnalyseCpu()          zCall( 0x004682B0 );
    void AnalyseOs()           zCall( 0x00468480 );
    void AnalyseGcard()        zCall( 0x004688B0 );
    zSTRING GetOsName()        zCall( 0x00469120 );
    virtual ~zCSystemInfo()    zCall( 0x004681A0 );
    virtual void AnalyseNow()  zCall( 0x004688D0 );

    // user API
    #include "zCSystemInfo.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZSYS_INFO_H__VER0__