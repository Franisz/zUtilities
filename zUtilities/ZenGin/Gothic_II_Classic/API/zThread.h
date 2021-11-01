// Supported with union (c) 2018-2021 Union team

#ifndef __ZTHREAD_H__VER2__
#define __ZTHREAD_H__VER2__

namespace Gothic_II_Classic {
  const int float_OUT_INFINITE = INFINITE;

  // sizeof 18h
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

    HANDLE threadHandle;      // sizeof 04h    offset 04h
    unsigned int threadID;    // sizeof 04h    offset 08h
    int suspendCount;         // sizeof 04h    offset 0Ch
    int isThreadRunning;      // sizeof 04h    offset 10h
    int terminationRequested; // sizeof 04h    offset 14h

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

  // sizeof 04h
  class zCSyncObject {
  public:

    zCSyncObject() {}
    virtual ~zCSyncObject()           zCall( 0x005F2790 );
    virtual int Lock( unsigned long ) zPureCall;
    virtual int Unlock()              zPureCall;

    // user API
    #include "zCSyncObject.inl"
  };

  // sizeof 1Ch
  class zCCriticalSection : public zCSyncObject {
  public:
    CRITICAL_SECTION criticalSection; // sizeof 18h    offset 04h

    void zCCriticalSection_OnInit()   zCall( 0x005F25F0 );
    zCCriticalSection()               zInit( zCCriticalSection_OnInit() );
    virtual ~zCCriticalSection()      zCall( 0x005F2630 );
    virtual int Lock( unsigned long ) zCall( 0x005F2670 );
    virtual int Unlock()              zCall( 0x005F2690 );

    // user API
    #include "zCCriticalSection.inl"
  };

  // sizeof 08h
  class zCMutex : public zCSyncObject {
  public:
    HANDLE mutex; // sizeof 04h    offset 04h

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