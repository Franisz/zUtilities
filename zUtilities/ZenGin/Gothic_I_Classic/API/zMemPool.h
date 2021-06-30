// Supported with union (c) 2018 Union team

#ifndef __ZMEM_POOL_H__VER0__
#define __ZMEM_POOL_H__VER0__

namespace Gothic_I_Classic {

  typedef enum {
    zVOLATILE_OVERFLOW_FORBID,
    zVOLATILE_OVERFLOW_WRAP,
    zVOLATILE_OVERFLOW_RESIZE
  } zTVolatileOverflowMode;

  class zCMemPoolBlock {
  public:
    zCMemPoolBlock* next;
    void* data;

    zCMemPoolBlock() {}
    static void operator delete( void* ) zCall( 0x0054F310 );

    // user API
    #include "zCMemPoolBlock.inl"
  };

  class zCVolatileMemoryBase {
  public:
    size_t size;
    size_t num;
    size_t nextfree;
    size_t maxAllocated;
    int maxFill;
    zTVolatileOverflowMode overflowMode;
    int overflow;
    void* data;

    zCVolatileMemoryBase() {}
    void zCVolatileMemoryBase_OnInit( unsigned int, unsigned int, zTVolatileOverflowMode ) zCall( 0x0054ECC0 );
    void zCVolatileMemoryBase_OnInit( unsigned int, zTVolatileOverflowMode )               zCall( 0x0054ED30 );
    zCVolatileMemoryBase( unsigned int a0, unsigned int a1, zTVolatileOverflowMode a2 )    zInit( zCVolatileMemoryBase_OnInit( a0, a1, a2 ));
    zCVolatileMemoryBase( unsigned int a0, zTVolatileOverflowMode a1 )                     zInit( zCVolatileMemoryBase_OnInit( a0, a1 ));
    ~zCVolatileMemoryBase()                                                                zCall( 0x0054ED70 );
    void Init( unsigned int )                                                              zCall( 0x0054EDA0 );
    void* Alloc()                                                                          zCall( 0x0054EDD0 );
    unsigned int Mark()                                                                    zCall( 0x0054EF80 );
    void Restore( unsigned int )                                                           zCall( 0x0054EF90 );
    void MaxFillPercentage( int )                                                          zCall( 0x0054F050 );
    virtual void Destroyed( void* )                                                        zCall( 0x0054ED20 );

    // user API
    #include "zCVolatileMemoryBase.inl"
  };

  class zCMemPoolBase {
  public:
    size_t size;
    size_t blocksize;
    zCMemPoolBlock* blocks;
    void* freeList;
    size_t numFree;
    size_t preallocate;
    int forcePrealloc;

    zCMemPoolBase() {}
    void zCMemPoolBase_OnInit( unsigned int )                             zCall( 0x0054F060 );
    void zCMemPoolBase_OnInit( unsigned int, unsigned int, unsigned int ) zCall( 0x0054F090 );
    zCMemPoolBase( unsigned int a0 )                                      zInit( zCMemPoolBase_OnInit( a0 ));
    zCMemPoolBase( unsigned int a0, unsigned int a1, unsigned int a2 )    zInit( zCMemPoolBase_OnInit( a0, a1, a2 ));
    ~zCMemPoolBase()                                                      zCall( 0x0054F0D0 );
    void* Alloc()                                                         zCall( 0x0054F170 );
    void Free( void* )                                                    zCall( 0x0054F320 );
    void PreAlloc( unsigned int, int )                                    zCall( 0x0054F360 );
    void PoolAdd( void*, int, int )                                       zCall( 0x0054F570 );
    static void SetMemDebug( char const*, char const*, int )              zCall( 0x0054F6B0 );
    static void DisablePools( int )                                       zCall( 0x0054F6D0 );

    // static properties
    static const char*& s_className;
    static const char*& s_fileName;
    static int& s_line;
    static int& s_disablePools;

    // user API
    #include "zCMemPoolBase.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZMEM_POOL_H__VER0__