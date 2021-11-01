// Supported with union (c) 2018-2021 Union team

#ifndef __ZTHREAD_H__VER0__
#define __ZTHREAD_H__VER0__

namespace Gothic_I_Classic {
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

  // sizeof 04h
  class zCSyncObject {
  public:

    zCSyncObject() {}
    virtual ~zCSyncObject()           zCall( 0x005CE430 );
    virtual int Lock( unsigned long ) zPureCall;
    virtual int Unlock()              zPureCall;

    // user API
    #include "zCSyncObject.inl"
  };

  // sizeof 1Ch
  class zCCriticalSection : public zCSyncObject {
  public:
    CRITICAL_SECTION criticalSection; // sizeof 18h    offset 04h

    void zCCriticalSection_OnInit()   zCall( 0x005CE290 );
    zCCriticalSection()               zInit( zCCriticalSection_OnInit() );
    virtual ~zCCriticalSection()      zCall( 0x005CE2D0 );
    virtual int Lock( unsigned long ) zCall( 0x005CE310 );
    virtual int Unlock()              zCall( 0x005CE330 );

    // user API
    #include "zCCriticalSection.inl"
  };

  // sizeof 08h
  class zCMutex : public zCSyncObject {
  public:
    HANDLE mutex; // sizeof 04h    offset 04h

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