// Supported with union (c) 2018-2021 Union team

#ifndef __ZRESOURCE_H__VER2__
#define __ZRESOURCE_H__VER2__

namespace Gothic_II_Classic {
  const int zMAX_CACHE_IN_PRIO = 65535;

  enum zTResourceCacheState {
    zRES_FAILURE    = -1,
    zRES_CACHED_OUT = 0,
    zRES_QUEUED     = 1,
    zRES_LOADING    = 2,
    zRES_CACHED_IN  = 3
  };

  // sizeof 64h
  class zCResourceManager : public zCThread {
  public:
    // sizeof 1Ch
    class zCClassCache {
    public:
      zCClassDef* resClassDef;        // sizeof 04h    offset 00h
      zCResource* resListHead;        // sizeof 04h    offset 04h
      zCResource* resListTail;        // sizeof 04h    offset 08h
      unsigned long numRes;           // sizeof 04h    offset 0Ch
      int cacheSizeBytes;             // sizeof 04h    offset 10h
      int cacheSizeMaxBytes;          // sizeof 04h    offset 14h
      unsigned long cacheOutTimeMSec; // sizeof 04h    offset 18h

      void zCClassCache_OnInit()    zCall( 0x005D75A0 );
      zCClassCache()                zInit( zCClassCache_OnInit() );
      ~zCClassCache()               zCall( 0x005D75C0 );
      void InsertRes( zCResource* ) zCall( 0x005D75D0 );
      void RemoveRes( zCResource* ) zCall( 0x005D7630 );
      void TouchRes( zCResource* )  zCall( 0x005D76A0 );

      // user API
      #include "zCResourceManager_zCClassCache.inl"
    };

    zCArray<zCClassCache> classCacheList; // sizeof 0Ch    offset 18h
    zCResource* cacheInQueueHead;         // sizeof 04h    offset 24h
    zCResource* cacheInQueueTail;         // sizeof 04h    offset 28h
    unsigned long currentTimeStamp;       // sizeof 04h    offset 2Ch
    int threadingEnabled;                 // sizeof 04h    offset 30h
    zCCriticalSection cacheInQueueGuard;  // sizeof 1Ch    offset 34h
    int numQueued;                        // sizeof 04h    offset 50h
    int numResCachedInThisFrame;          // sizeof 04h    offset 54h
    int showDebugInfo;                    // sizeof 04h    offset 58h
    float cacheInImmediatelyMsec;         // sizeof 04h    offset 5Ch
    volatile int goToSuspend;             // sizeof 04h    offset 60h

    void zCResourceManager_OnInit()                    zCall( 0x005D5B00 );
    zCResourceManager()                                zInit( zCResourceManager_OnInit() );
    void PurgeCaches( zCClassDef* )                    zCall( 0x005D5C70 );
    void SetThreadingEnabled( int )                    zCall( 0x005D5E70 );
    int GetThreadingEnabled() const                    zCall( 0x005D5E80 );
    void InitClassCache()                              zCall( 0x005D5E90 );
    zCClassCache* GetClassCache( zCResource* )         zCall( 0x005D6100 );
    int GetClassCacheIndex( zCClassDef* )              zCall( 0x005D6170 );
    void LoadResource( zCResource* )                   zCall( 0x005D61A0 );
    zTResourceCacheState CacheIn( zCResource*, float ) zCall( 0x005D6280 );
    void CacheOut( zCResource* )                       zCall( 0x005D6590 );
    void TouchTimeStamp( zCResource* )                 zCall( 0x005D66C0 );
    void DoFrameActivity()                             zCall( 0x005D6730 );
    void Evict()                                       zCall( 0x005D67C0 );
    zCResource* RemoveCacheInQueue( zCResource* )      zCall( 0x005D69A0 );
    zCResource* GetNextCacheInQueue()                  zCall( 0x005D6A20 );
    void InsertCacheInQueue( zCResource*, float )      zCall( 0x005D6A30 );
    void LockCacheInQueue()                            zCall( 0x005D6B00 );
    void UnlockCacheInQueue()                          zCall( 0x005D6B20 );
    int WaitForCacheIn( zCResource* )                  zCall( 0x005D6B40 );
    void QueueProcess_Start()                          zCall( 0x005D6BA0 );
    void QueueProcess_Suspend()                        zCall( 0x005D6BD0 );
    void QueueProcess_Resume()                         zCall( 0x005D6BE0 );
    void PrintStatusDebug()                            zCall( 0x005D6C10 );
    void SetShowDebugInfo( int )                       zCall( 0x0062F8F0 );
    int GetShowDebugInfo() const                       zCall( 0x0062F900 );
    virtual ~zCResourceManager()                       zCall( 0x005D5BE0 );
    virtual unsigned long ThreadProc()                 zCall( 0x005D6880 );

    // user API
    #include "zCResourceManager.inl"
  };

  // sizeof 54h
  class zCResource : public zCObject {
  public:
    zCLASS_DECLARATION( zCResource )

    zCResource* nextRes;                   // sizeof 04h    offset 24h
    zCResource* prevRes;                   // sizeof 04h    offset 28h
    unsigned long timeStamp;               // sizeof 04h    offset 2Ch
    zCCriticalSection stateChangeGuard;    // sizeof 1Ch    offset 30h
    group {
      unsigned char cacheState       : 2;  // sizeof 02h    offset bit
      unsigned char cacheOutLock     : 1;  // sizeof 01h    offset bit
      unsigned char cacheClassIndex  : 8;  // sizeof 08h    offset bit
      unsigned char managedByResMan  : 1;  // sizeof 01h    offset bit
      unsigned short cacheInPriority : 16; // sizeof 10h    offset bit
      unsigned char canBeCachedOut   : 1;  // sizeof 01h    offset bit
    };

    void zCResource_OnInit()                                      zCall( 0x005D56B0 );
    zTResourceCacheState CacheIn( float )                         zCall( 0x005BEEE0 );
    zCResource()                                                  zInit( zCResource_OnInit() );
    void SetCacheInPriority( float )                              zCall( 0x005D58F0 );
    void CacheOut()                                               zCall( 0x005D5A30 );
    void TouchTimeStamp()                                         zCall( 0x005D5A50 );
    void TouchTimeStampLocal()                                    zCall( 0x005D5AD0 );
    void LockStateChange()                                        zCall( 0x005D5AE0 );
    void UnlockStateChange()                                      zCall( 0x005D5AF0 );
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x005D5850 );
    virtual ~zCResource()                                         zCall( 0x005D5890 );
    virtual int LoadResourceData()                                zCall( 0x005D5920 );
    virtual int ReleaseResourceData()                             zCall( 0x005D5A00 );
    virtual unsigned long GetResSizeBytes()                       zCall( 0x005D5A10 );
    virtual void GetCacheConfig( unsigned long&, unsigned long& ) zCall( 0x005D5A20 );

    // user API
    #include "zCResource.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZRESOURCE_H__VER2__