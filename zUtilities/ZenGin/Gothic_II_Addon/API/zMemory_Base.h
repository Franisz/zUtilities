// Supported with union (c) 2018-2021 Union team

#ifndef __ZMEMORY__BASE_H__VER3__
#define __ZMEMORY__BASE_H__VER3__

namespace Gothic_II_Addon {

  enum zTMallocDumpHeapMode {
    zMALLOC_SORT_BY_BYTES_PER_LINE,
    zMALLOC_SORT_BY_BLOCKS_PER_LINE,
    zMALLOC_SORT_BY_CLASS,
    zMALLOC_SORT_BY_BLOCK_SIZE,
    zMALLOC_SORT_BY_FILE,
    zMALLOC_SORT_BY_TIME
  };

  enum zTMallocCheckPtrError {
    zMALLOC_CHECK_PTR_OK,
    zMALLOC_CHECK_PTR_INVALID_PTR,
    zMALLOC_CHECK_PTR_CORRUPTED_MEM,
    zMALLOC_CHECK_PTR_NOT_ACTIVATED,
    zMALLOC_CHECK_PTR_NULL_PTR
  };

  // sizeof 28h
  struct zTMallocStats {
    int numBlocks;                  // sizeof 04h    offset 00h
    int numBlocksPeak;              // sizeof 04h    offset 04h
    int numBytesAllocated;          // sizeof 04h    offset 08h
    int numBytesAllocatedPeak;      // sizeof 04h    offset 0Ch
    int numAllocs;                  // sizeof 04h    offset 10h
    int numFrees;                   // sizeof 04h    offset 14h
    __int64 numBytesAllocatedTotal; // sizeof 08h    offset 18h
    __int64 numBytesFreedTotal;     // sizeof 08h    offset 20h

    zTMallocStats() {}

    // user API
    #include "zTMallocStats.inl"
  };

  // sizeof 0Ch
  struct zTMallocProcessStats {
    unsigned long fixedMem; // sizeof 04h    offset 00h
    unsigned long freeMem;  // sizeof 04h    offset 04h
    unsigned long moveable; // sizeof 04h    offset 08h

    zTMallocProcessStats() {}

    // user API
    #include "zTMallocProcessStats.inl"
  };

  // sizeof 04h
  class zCMalloc {
  public:

    zCMalloc() {}
    virtual ~zCMalloc()                                                 zCall( 0x00565F00 );
    virtual void* Malloc( unsigned int )                                zPureCall;
    virtual void* Malloc( unsigned int, char const*, char const*, int ) zPureCall;
    virtual void* Realloc( void*, unsigned int )                        zPureCall;
    virtual void Free( void* )                                          zPureCall;
    virtual int GetStats( zTMallocStats& )                              zCall( 0x00565EB0 );
    virtual int GetProcessStats( zTMallocProcessStats& )                zCall( 0x00565EC0 );
    virtual int DumpHeap( zTMallocDumpHeapMode )                        zCall( 0x00565ED0 );
    virtual int CheckHeap()                                             zCall( 0x00565EE0 );
    virtual zTMallocCheckPtrError CheckPtr( void* )                     zCall( 0x00565EF0 );
    virtual int Init( int )                                             zPureCall;
    virtual int Shutdown()                                              zPureCall;

    // user API
    #include "zCMalloc.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZMEMORY__BASE_H__VER3__