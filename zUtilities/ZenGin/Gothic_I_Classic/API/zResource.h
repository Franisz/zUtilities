// Supported with union (c) 2018-2021 Union team

#ifndef __ZRESOURCE_H__VER0__
#define __ZRESOURCE_H__VER0__

namespace Gothic_I_Classic {
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

      void zCClassCache_OnInit()    zCall( 0x005B6E10 );
      zCClassCache()                zInit( zCClassCache_OnInit() );
      ~zCClassCache()               zCall( 0x005B6E30 );
      void InsertRes( zCResource* ) zCall( 0x005B6E40 );
      void RemoveRes( zCResource* ) zCall( 0x005B6EA0 );
      void TouchRes( zCResource* )  zCall( 0x005B6F10 );

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
    int goToSuspend;                      // sizeof 04h    offset 60h

    void zCResourceManager_OnInit()                    zCall( 0x005B55B0 );
    zCResourceManager()                                zInit( zCResourceManager_OnInit() );
    void PurgeCaches( zCClassDef* )                    zCall( 0x005B5720 );
    void SetThreadingEnabled( int )                    zCall( 0x005B58A0 );
    int GetThreadingEnabled() const                    zCall( 0x005B58B0 );
    void InitClassCache()                              zCall( 0x005B58C0 );
    zCClassCache* GetClassCache( zCResource* )         zCall( 0x005B5B30 );
    int GetClassCacheIndex( zCClassDef* )              zCall( 0x005B5BA0 );
    void LoadResource( zCResource* )                   zCall( 0x005B5BD0 );
    zTResourceCacheState CacheIn( zCResource*, float ) zCall( 0x005B5CB0 );
    void CacheOut( zCResource* )                       zCall( 0x005B5FB0 );
    void TouchTimeStamp( zCResource* )                 zCall( 0x005B60E0 );
    void DoFrameActivity()                             zCall( 0x005B6150 );
    void Evict()                                       zCall( 0x005B61E0 );
    zCResource* RemoveCacheInQueue( zCResource* )      zCall( 0x005B63C0 );
    zCResource* GetNextCacheInQueue()                  zCall( 0x005B6440 );
    void InsertCacheInQueue( zCResource*, float )      zCall( 0x005B6450 );
    void LockCacheInQueue()                            zCall( 0x005B6520 );
    void UnlockCacheInQueue()                          zCall( 0x005B6540 );
    int WaitForCacheIn( zCResource* )                  zCall( 0x005B6560 );
    void QueueProcess_Start()                          zCall( 0x005B65C0 );
    void QueueProcess_Suspend()                        zCall( 0x005B65F0 );
    void QueueProcess_Resume()                         zCall( 0x005B6600 );
    void PrintStatusDebug()                            zCall( 0x005B6630 );
    virtual ~zCResourceManager()                       zCall( 0x005B5690 );
    virtual unsigned long ThreadProc()                 zCall( 0x005B62A0 );

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
    };

    void zCResource_OnInit()                                      zCall( 0x005B5160 );
    zCResource()                                                  zInit( zCResource_OnInit() );
    void SetCacheInPriority( float )                              zCall( 0x005B53A0 );
    void CacheOut()                                               zCall( 0x005B54E0 );
    void TouchTimeStamp()                                         zCall( 0x005B5500 );
    void TouchTimeStampLocal()                                    zCall( 0x005B5580 );
    void LockStateChange()                                        zCall( 0x005B5590 );
    void UnlockStateChange()                                      zCall( 0x005B55A0 );
    zTResourceCacheState CacheIn( float )                         zCall( 0x00715480 );
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x005B5300 );
    virtual ~zCResource()                                         zCall( 0x005B5340 );
    virtual int LoadResourceData()                                zCall( 0x005B53D0 );
    virtual int ReleaseResourceData()                             zCall( 0x005B54B0 );
    virtual unsigned long GetResSizeBytes()                       zCall( 0x005B54C0 );
    virtual void GetCacheConfig( unsigned long&, unsigned long& ) zCall( 0x005B54D0 );

    // user API
    #include "zCResource.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZRESOURCE_H__VER0__