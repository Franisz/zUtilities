// Supported with union (c) 2018 Union team

#ifndef __ZMEMORY__WIN32_H__VER3__
#define __ZMEMORY__WIN32_H__VER3__

#include "zMemory_Base.h"

namespace Gothic_II_Addon {

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

} // namespace Gothic_II_Addon

#endif // __ZMEMORY__WIN32_H__VER3__