// Supported with union (c) 2018 Union team

#ifndef __ZTHREAD_H__VER0__
#define __ZTHREAD_H__VER0__

namespace Gothic_I_Classic {
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

    void zCThread_OnInit()                      zCall( 0x005CE010 );
    zCThread()                                  zInit( zCThread_OnInit() );
    void SleepThread( unsigned long )           zCall( 0x005CE280 );
    virtual ~zCThread()                         zCall( 0x005CE090 );
    virtual void BeginThread()                  zCall( 0x005CE0E0 );
    virtual void EndThread()                    zCall( 0x005CE1E0 );
    virtual int IsThreadRunning()               zCall( 0x005B5640 );
    virtual int SuspendThread()                 zCall( 0x005CE220 );
    virtual int ResumeThread()                  zCall( 0x005CE250 );
    virtual int GetTerminationRequested() const zCall( 0x005B5650 );
    virtual void SetTerminationRequested( int ) zCall( 0x005B5660 );
    virtual unsigned long ThreadProc()          zCall( 0x005CE1D0 );

    // user API
    #include "zCThread.inl"
  };

  class zCSyncObject {
  public:

    zCSyncObject() {}
    virtual ~zCSyncObject()           zCall( 0x005CE430 );
    virtual int Lock( unsigned long ) zPureCall;
    virtual int Unlock()              zPureCall;

    // user API
    #include "zCSyncObject.inl"
  };

  class zCCriticalSection : public zCSyncObject {
  public:
    CRITICAL_SECTION criticalSection;

    void zCCriticalSection_OnInit()   zCall( 0x005CE290 );
    zCCriticalSection()               zInit( zCCriticalSection_OnInit() );
    virtual ~zCCriticalSection()      zCall( 0x005CE2D0 );
    virtual int Lock( unsigned long ) zCall( 0x005CE310 );
    virtual int Unlock()              zCall( 0x005CE330 );

    // user API
    #include "zCCriticalSection.inl"
  };

  class zCMutex : public zCSyncObject {
  public:
    HANDLE mutex;

    void zCMutex_OnInit()             zCall( 0x005CE340 );
    zCMutex()                         zInit( zCMutex_OnInit() );
    virtual ~zCMutex()                zCall( 0x005CE460 );
    virtual int Lock( unsigned long ) zCall( 0x005CE490 );
    virtual int Unlock()              zCall( 0x005CE4B0 );

    // user API
    #include "zCMutex.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZTHREAD_H__VER0__