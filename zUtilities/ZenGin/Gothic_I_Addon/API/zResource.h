// Supported with union (c) 2018 Union team

#ifndef __ZRESOURCE_H__VER1__
#define __ZRESOURCE_H__VER1__

namespace Gothic_I_Addon {
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

      void zCClassCache_OnInit()    zCall( 0x005D4760 );
      zCClassCache()                zInit( zCClassCache_OnInit() );
      ~zCClassCache()               zCall( 0x005D4780 );
      void InsertRes( zCResource* ) zCall( 0x005D4790 );
      void RemoveRes( zCResource* ) zCall( 0x005D47F0 );
      void TouchRes( zCResource* )  zCall( 0x005D4860 );

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
    int goToSuspend;

    void zCResourceManager_OnInit()                    zCall( 0x005D2D00 );
    zCResourceManager()                                zInit( zCResourceManager_OnInit() );
    void PurgeCaches( zCClassDef* )                    zCall( 0x005D2E70 );
    void SetThreadingEnabled( int )                    zCall( 0x005D3000 );
    int GetThreadingEnabled() const                    zCall( 0x005D3010 );
    void InitClassCache()                              zCall( 0x005D3020 );
    zCClassCache* GetClassCache( zCResource* )         zCall( 0x005D32C0 );
    int GetClassCacheIndex( zCClassDef* )              zCall( 0x005D3330 );
    void LoadResource( zCResource* )                   zCall( 0x005D3360 );
    zTResourceCacheState CacheIn( zCResource*, float ) zCall( 0x005D3450 );
    void CacheOut( zCResource* )                       zCall( 0x005D3770 );
    void TouchTimeStamp( zCResource* )                 zCall( 0x005D38B0 );
    void DoFrameActivity()                             zCall( 0x005D3930 );
    void Evict()                                       zCall( 0x005D39C0 );
    zCResource* RemoveCacheInQueue( zCResource* )      zCall( 0x005D3BC0 );
    zCResource* GetNextCacheInQueue()                  zCall( 0x005D3C40 );
    void InsertCacheInQueue( zCResource*, float )      zCall( 0x005D3C50 );
    void LockCacheInQueue()                            zCall( 0x005D3D20 );
    void UnlockCacheInQueue()                          zCall( 0x005D3D40 );
    int WaitForCacheIn( zCResource* )                  zCall( 0x005D3D60 );
    void QueueProcess_Start()                          zCall( 0x005D3DC0 );
    void QueueProcess_Suspend()                        zCall( 0x005D3DF0 );
    void QueueProcess_Resume()                         zCall( 0x005D3E00 );
    void PrintStatusDebug()                            zCall( 0x005D3E40 );
    virtual ~zCResourceManager()                       zCall( 0x005D2DE0 );
    virtual unsigned long ThreadProc()                 zCall( 0x005D3A90 );

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
    };

    void zCResource_OnInit()                                      zCall( 0x005D28A0 );
    zCResource()                                                  zInit( zCResource_OnInit() );
    void SetCacheInPriority( float )                              zCall( 0x005D2AE0 );
    void CacheOut()                                               zCall( 0x005D2C20 );
    void TouchTimeStamp()                                         zCall( 0x005D2C40 );
    void TouchTimeStampLocal()                                    zCall( 0x005D2CD0 );
    void LockStateChange()                                        zCall( 0x005D2CE0 );
    void UnlockStateChange()                                      zCall( 0x005D2CF0 );
    zTResourceCacheState CacheIn( float )                         zCall( 0x007512E0 );
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x005D2A40 );
    virtual ~zCResource()                                         zCall( 0x005D2A80 );
    virtual int LoadResourceData()                                zCall( 0x005D2B10 );
    virtual int ReleaseResourceData()                             zCall( 0x005D2BF0 );
    virtual unsigned long GetResSizeBytes()                       zCall( 0x005D2C00 );
    virtual void GetCacheConfig( unsigned long&, unsigned long& ) zCall( 0x005D2C10 );

    // user API
    #include "zCResource.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZRESOURCE_H__VER1__