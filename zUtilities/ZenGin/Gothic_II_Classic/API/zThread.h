// Supported with union (c) 2018 Union team

#ifndef __ZTHREAD_H__VER2__
#define __ZTHREAD_H__VER2__

namespace Gothic_II_Classic {
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

    void zCThread_OnInit()                      zCall( 0x005F2370 );
    zCThread()                                  zInit( zCThread_OnInit() );
    void SleepThread( unsigned long )           zCall( 0x005F25E0 );
    virtual ~zCThread()                         zCall( 0x005F23F0 );
    virtual void BeginThread()                  zCall( 0x005F2440 );
    virtual void EndThread()                    zCall( 0x005F2540 );
    virtual int IsThreadRunning()               zCall( 0x005D5B90 );
    virtual int SuspendThread()                 zCall( 0x005F2580 );
    virtual int ResumeThread()                  zCall( 0x005F25B0 );
    virtual int GetTerminationRequested() const zCall( 0x005D5BA0 );
    virtual void SetTerminationRequested( int ) zCall( 0x005D5BB0 );
    virtual unsigned long ThreadProc()          zCall( 0x005F2530 );

    // user API
    #include "zCThread.inl"
  };

  class zCSyncObject {
  public:

    zCSyncObject() {}
    virtual ~zCSyncObject()           zCall( 0x005F2790 );
    virtual int Lock( unsigned long ) zPureCall;
    virtual int Unlock()              zPureCall;

    // user API
    #include "zCSyncObject.inl"
  };

  class zCCriticalSection : public zCSyncObject {
  public:
    CRITICAL_SECTION criticalSection;

    void zCCriticalSection_OnInit()   zCall( 0x005F25F0 );
    zCCriticalSection()               zInit( zCCriticalSection_OnInit() );
    virtual ~zCCriticalSection()      zCall( 0x005F2630 );
    virtual int Lock( unsigned long ) zCall( 0x005F2670 );
    virtual int Unlock()              zCall( 0x005F2690 );

    // user API
    #include "zCCriticalSection.inl"
  };

  class zCMutex : public zCSyncObject {
  public:
    HANDLE mutex;

    void zCMutex_OnInit()             zCall( 0x005F26A0 );
    zCMutex()                         zInit( zCMutex_OnInit() );
    virtual ~zCMutex()                zCall( 0x005F27C0 );
    virtual int Lock( unsigned long ) zCall( 0x005F27F0 );
    virtual int Unlock()              zCall( 0x005F2810 );

    // user API
    #include "zCMutex.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZTHREAD_H__VER2__