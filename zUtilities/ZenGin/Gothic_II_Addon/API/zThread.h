// Supported with union (c) 2018 Union team

#ifndef __ZTHREAD_H__VER3__
#define __ZTHREAD_H__VER3__

namespace Gothic_II_Addon {
  const int float_OUT_INFINITE = INFINITE;

  class zCThread {
  public:
    enum zTThread_Prio {
      zTHREAD_PRIORITY_TIME_CRITICAL = THREAD_PRIORITY_TIME_CRITICAL,
      zTHREAD_PRIORITY_HIGHEST       = THREAD_PRIORITY_HIGHEST,
      zTHREAD_PRIORITY_ABOVE_NORMAL  = THREAD_PRIORITY_ABOVE_NORMAL,
      zTHREAD_PRIORITY_NORMAL        = THREAD_PRIORITY_NORMAL,
      zTHREAD_PRIORITY_BELOW_NORMAL  = THREAD_PRIORITY_BELOW_NORMAL,
      zTHREAD_PRIORITY_LOWEST        = THREAD_PRIORITY_LOWEST,
      zTHREAD_PRIORITY_IDLE          = THREAD_PRIORITY_IDLE
    };

    HANDLE threadHandle;
    unsigned int threadID;
    int suspendCount;
    int isThreadRunning;
    int terminationRequested;

    void zCThread_OnInit()                      zCall( 0x005F9160 );
    zCThread()                                  zInit( zCThread_OnInit() );
    void SleepThread( unsigned long )           zCall( 0x005F93D0 );
    virtual ~zCThread()                         zCall( 0x005F91E0 );
    virtual void BeginThread()                  zCall( 0x005F9230 );
    virtual void EndThread()                    zCall( 0x005F9330 );
    virtual int IsThreadRunning()               zCall( 0x005DC950 );
    virtual int SuspendThread()                 zCall( 0x005F9370 );
    virtual int ResumeThread()                  zCall( 0x005F93A0 );
    virtual int GetTerminationRequested() const zCall( 0x005DC960 );
    virtual void SetTerminationRequested( int ) zCall( 0x005DC970 );
    virtual unsigned long ThreadProc()          zCall( 0x005F9320 );

    // user API
    #include "zCThread.inl"
  };

  class zCSyncObject {
  public:

    zCSyncObject() {}
    virtual ~zCSyncObject()           zCall( 0x005F9580 );
    virtual int Lock( unsigned long ) zPureCall;
    virtual int Unlock()              zPureCall;

    // user API
    #include "zCSyncObject.inl"
  };

  class zCCriticalSection : public zCSyncObject {
  public:
    CRITICAL_SECTION criticalSection;

    void zCCriticalSection_OnInit()   zCall( 0x005F93E0 );
    zCCriticalSection()               zInit( zCCriticalSection_OnInit() );
    virtual ~zCCriticalSection()      zCall( 0x005F9420 );
    virtual int Lock( unsigned long ) zCall( 0x005F9460 );
    virtual int Unlock()              zCall( 0x005F9480 );

    // user API
    #include "zCCriticalSection.inl"
  };

  class zCMutex : public zCSyncObject {
  public:
    HANDLE mutex;

    void zCMutex_OnInit()             zCall( 0x005F9490 );
    zCMutex()                         zInit( zCMutex_OnInit() );
    virtual ~zCMutex()                zCall( 0x005F95B0 );
    virtual int Lock( unsigned long ) zCall( 0x005F95E0 );
    virtual int Unlock()              zCall( 0x005F9600 );

    // user API
    #include "zCMutex.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZTHREAD_H__VER3__