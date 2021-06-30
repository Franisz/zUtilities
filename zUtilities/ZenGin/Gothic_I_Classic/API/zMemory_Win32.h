// Supported with union (c) 2018 Union team

#ifndef __ZMEMORY__WIN32_H__VER0__
#define __ZMEMORY__WIN32_H__VER0__

namespace Gothic_I_Classic {

  class zCMallocWin32Debug : public zCMalloc {
  public:
    unsigned int RuntimeLine;
    unsigned int RuntimeMemSize;
    unsigned int RuntimeBlocks;
    unsigned int RuntimeResultBlock;
    unsigned int RuntimeResultMemSize;
    char RuntimeFilename[400];
    char RuntimeName[400];
    char Buffer[400];
    int ShowNoFilename;
    int ShowNoName;

    zCMallocWin32Debug() {}

    // user API
    #include "zCMallocWin32Debug.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZMEMORY__WIN32_H__VER0__