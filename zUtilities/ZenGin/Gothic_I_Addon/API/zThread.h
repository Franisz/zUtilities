// Supported with union (c) 2018-2021 Union team

#ifndef __ZTHREAD_H__VER1__
#define __ZTHREAD_H__VER1__

namespace Gothic_I_Addon {
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

    void zCThread_OnInit()                      zCall( 0x005ECD30 );
    zCThread()                                  zInit( zCThread_OnInit() );
    void SleepThread( unsigned long )           zCall( 0x005ECFD0 );
    virtual ~zCThread()                         zCall( 0x005ECDB0 );
    virtual void BeginThread()                  zCall( 0x005ECE00 );
    virtual void EndThread()                    zCall( 0x005ECF30 );
    virtual int IsThreadRunning()               zCall( 0x005D2D90 );
    virtual int SuspendThread()                 zCall( 0x005ECF70 );
    virtual int ResumeThread()                  zCall( 0x005ECFA0 );
    virtual int GetTerminationRequested() const zCall( 0x005D2DA0 );
    virtual void SetTerminationRequested( int ) zCall( 0x005D2DB0 );
    virtual unsigned long ThreadProc()          zCall( 0x005ECF20 );

    // user API
    #include "zCThread.inl"
  };

  // sizeof 04h
  class zCSyncObject {
  public:

    zCSyncObject() {}
    virtual ~zCSyncObject()           zCall( 0x005ED1C0 );
    virtual int Lock( unsigned long ) zPureCall;
    virtual int Unlock()              zPureCall;

    // user API
    #include "zCSyncObject.inl"
  };

  // sizeof 1Ch
  class zCCriticalSection : public zCSyncObject {
  public:
    CRITICAL_SECTION criticalSection; // sizeof 18h    offset 04h

    void zCCriticalSection_OnInit()   zCall( 0x005ECFE0 );
    zCCriticalSection()               zInit( zCCriticalSection_OnInit() );
    virtual ~zCCriticalSection()      zCall( 0x005ED020 );
    virtual int Lock( unsigned long ) zCall( 0x005ED060 );
    virtual int Unlock()              zCall( 0x005ED080 );

    // user API
    #include "zCCriticalSection.inl"
  };

  // sizeof 08h
  class zCMutex : public zCSyncObject {
  public:
    HANDLE mutex; // sizeof 04h    offset 04h

    void zCMutex_OnInit()             zCall( 0x005ED090 );
    zCMutex()                         zInit( zCMutex_OnInit() );
    virtual ~zCMutex()                zCall( 0x005ED1F0 );
    virtual int Lock( unsigned long ) zCall( 0x005ED220 );
    virtual int Unlock()              zCall( 0x005ED240 );

    // user API
    #include "zCMutex.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZTHREAD_H__VER1__