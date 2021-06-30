// Supported with union (c) 2018 Union team

#ifndef __ZRESOURCE_H__VER3__
#define __ZRESOURCE_H__VER3__

#include "zThread.h"

namespace Gothic_II_Addon {
  const int zMAX_CACHE_IN_PRIO = 65535;

  enum zTResourceCacheState {
    zRES_FAILURE    = -1,
    zRES_CACHED_OUT = 0,
    zRES_QUEUED     = 1,
    zRES_LOADING    = 2,
    zRES_CACHED_IN  = 3
  };

  class zCResourceManager : public zCThread {
  public:
    class zCClassCache {
    public:
      zCClassDef* resClassDef;
      zCResource* resListHead;
      zCResource* resListTail;
      unsigned long numRes;
      int cacheSizeBytes;
      int cacheSizeMaxBytes;
      unsigned long cacheOutTimeMSec;

      void zCClassCache_OnInit()    zCall( 0x005DE360 );
      zCClassCache()                zInit( zCClassCache_OnInit() );
      ~zCClassCache()               zCall( 0x005DE380 );
      void InsertRes( zCResource* ) zCall( 0x005DE390 );
      void RemoveRes( zCResource* ) zCall( 0x005DE3F0 );
      void TouchRes( zCResource* )  zCall( 0x005DE460 );

      // user API
      #include "zCResourceManager_zCClassCache.inl"
    };

    zCArray<zCClassCache> classCacheList;
    zCResource* cacheInQueueHead;
    zCResource* cacheInQueueTail;
    unsigned long currentTimeStamp;
    int threadingEnabled;
    zCCriticalSection cacheInQueueGuard;
    int numQueued;
    int numResCachedInThisFrame;
    int showDebugInfo;
    float cacheInImmediatelyMsec;
    volatile int goToSuspend;

    void zCResourceManager_OnInit()                    zCall( 0x005DC8C0 );
    zCResourceManager()                                zInit( zCResourceManager_OnInit() );
    void PurgeCaches( zCClassDef* )                    zCall( 0x005DCA30 );
    void SetThreadingEnabled( int )                    zCall( 0x005DCC30 );
    int GetThreadingEnabled() const                    zCall( 0x005DCC40 );
    void InitClassCache()                              zCall( 0x005DCC50 );
    zCClassCache* GetClassCache( zCResource* )         zCall( 0x005DCEC0 );
    int GetClassCacheIndex( zCClassDef* )              zCall( 0x005DCF30 );
    void LoadResource( zCResource* )                   zCall( 0x005DCF60 );
    zTResourceCacheState CacheIn( zCResource*, float ) zCall( 0x005DD040 );
    void CacheOut( zCResource* )                       zCall( 0x005DD350 );
    void TouchTimeStamp( zCResource* )                 zCall( 0x005DD480 );
    void DoFrameActivity()                             zCall( 0x005DD4F0 );
    void Evict()                                       zCall( 0x005DD580 );
    zCResource* RemoveCacheInQueue( zCResource* )      zCall( 0x005DD760 );
    zCResource* GetNextCacheInQueue()                  zCall( 0x005DD7E0 );
    void InsertCacheInQueue( zCResource*, float )      zCall( 0x005DD7F0 );
    void LockCacheInQueue()                            zCall( 0x005DD8C0 );
    void UnlockCacheInQueue()                          zCall( 0x005DD8E0 );
    int WaitForCacheIn( zCResource* )                  zCall( 0x005DD900 );
    void QueueProcess_Start()                          zCall( 0x005DD960 );
    void QueueProcess_Suspend()                        zCall( 0x005DD990 );
    void QueueProcess_Resume()                         zCall( 0x005DD9A0 );
    void PrintStatusDebug()                            zCall( 0x005DD9D0 );
    void SetShowDebugInfo( int )                       zCall( 0x006370C0 );
    int GetShowDebugInfo() const                       zCall( 0x006370D0 );
    virtual ~zCResourceManager()                       zCall( 0x005DC9A0 );
    virtual unsigned long ThreadProc()                 zCall( 0x005DD640 );

    // user API
    #include "zCResourceManager.inl"
  };

  class zCResource : public zCObject {
  public:
    zCLASS_DECLARATION( zCResource )

    zCResource* nextRes;
    zCResource* prevRes;
    unsigned long timeStamp;
    zCCriticalSection stateChangeGuard;
    group {
      unsigned char cacheState       : 2;
      unsigned char cacheOutLock     : 1;
      unsigned char cacheClassIndex  : 8;
      unsigned char managedByResMan  : 1;
      unsigned short cacheInPriority : 16;
      unsigned char canBeCachedOut   : 1;
    };

    void zCResource_OnInit()                                      zCall( 0x005DC470 );
    zTResourceCacheState CacheIn( float )                         zCall( 0x005C4A50 );
    zCResource()                                                  zInit( zCResource_OnInit() );
    void SetCacheInPriority( float )                              zCall( 0x005DC6B0 );
    void CacheOut()                                               zCall( 0x005DC7F0 );
    void TouchTimeStamp()                                         zCall( 0x005DC810 );
    void TouchTimeStampLocal()                                    zCall( 0x005DC890 );
    void LockStateChange()                                        zCall( 0x005DC8A0 );
    void UnlockStateChange()                                      zCall( 0x005DC8B0 );
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x005DC610 );
    virtual ~zCResource()                                         zCall( 0x005DC650 );
    virtual int LoadResourceData()                                zCall( 0x005DC6E0 );
    virtual int ReleaseResourceData()                             zCall( 0x005DC7C0 );
    virtual unsigned long GetResSizeBytes()                       zCall( 0x005DC7D0 );
    virtual void GetCacheConfig( unsigned long&, unsigned long& ) zCall( 0x005DC7E0 );

    // user API
    #include "zCResource.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZRESOURCE_H__VER3__