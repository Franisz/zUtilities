// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_THREAD_H__
#define __UNION_THREAD_H__

namespace Common {
	typedef void* HPROC;

  enum {
    THREAD_TO_BACKGROUND   =  0x00010000,
    THREAD_FROM_BACKGROUND =  0x00020000,
    THREAD_IDLE            = -15,
    THREAD_LOW             = -2,
    THREAD_NORMAL_LOW      = -1,
    THREAD_NORMAL          =  0,
    THREAD_NORMAL_HIGH     =  1,
    THREAD_HIGH            =  2,
    THREAD_CRITICAL        =  15
  };



  class Thread {
  protected:
    HPROC Function;
    ulong ID;
    HANDLE Handle;

  public:
    Thread();
    Thread( HPROC function );
    void Init( HPROC function );
    ulong Detach( void* argument = Null );
    ulong DetachSuspended( void* argument = Null );
    void Break();
    void Suspend();
    void Resume();
    void SetPriority( int priority );
    int GetPriority();
    int WaitForEnd( const int& milliseconds = INFINITE ) const;
    HPROC GetFunction();
    ulong GetID();
    HANDLE GetHandle();
    static int WaitForEnd( const Array<Thread> threads, const int& milliseconds = INFINITE );
    ~Thread();
  };

  inline Thread::Thread() {
    Init( Null );
  }

  inline Thread::Thread( HPROC function ) {
    Init( function );
  }

  inline void Thread::Init( HPROC function ) {
    Function = function;
    ID = Invalid;
    Handle = Null;
  }

  inline ulong Thread::Detach( void* argument ) {
    Handle = CreateThread( Null, 0, (LPTHREAD_START_ROUTINE)Function, argument, 0, &ID );
    return ID;
  }

  inline ulong Thread::DetachSuspended( void* argument ) {
    Handle = CreateThread( Null, 0, (LPTHREAD_START_ROUTINE)Function, argument, CREATE_SUSPENDED, &ID );
    return ID;
  }

  inline void Thread::Break() {
    TerminateThread( Handle, 0 );
  }

  inline void Thread::Suspend() {
    SuspendThread( Handle );
  }

  inline void Thread::Resume() {
    ulong result = ResumeThread( Handle ) > 0;
    if( result > 0 )
      while( ResumeThread( Handle ) > 0 );
  }

  inline void Thread::SetPriority( int priority ) {
    SetThreadPriority( Handle, priority );
  }

  inline int Thread::GetPriority() {
    return GetThreadPriority( Handle );
  }

  inline int Thread::WaitForEnd( const int& milliseconds ) const {
    return WaitForSingleObject( Handle, milliseconds );
  }

  inline HPROC Thread::GetFunction() {
    return Function;
  }

  inline ulong Thread::GetID() {
    return ID;
  }

  inline HANDLE Thread::GetHandle() {
    return Handle;
  }

  inline int Thread::WaitForEnd( const Array<Thread> threads, const int& milliseconds ) {
    for( uint i = 0; i < threads.GetNum(); i++ ) {
      int result = threads[i].WaitForEnd( milliseconds );
      if( result != WAIT_OBJECT_0 )
        return result;
    }

    return WAIT_OBJECT_0;
  }

  inline Thread::~Thread() {
    // pass
  }




  class Event {
    HANDLE Handle;
  public:

    Event( const int& initalState = True );
    bool_t Open();
    bool_t Close();
    bool_t Wait( const int& milliseconds = INFINITE );
    bool_t IsOpen() const;
    HANDLE GetHandle();
    ~Event();
  };

  inline Event::Event( const int& initalState ) {
    Handle = CreateEvent( Null, True, initalState, Null );
    if( Handle == Null )
      throw std::exception( "Can not create Event object." );
  }

  inline bool_t Event::Open() {
    return ResetEvent( Handle );
  }

  inline bool_t Event::Close() {
    return SetEvent( Handle );
  }

  inline bool_t Event::Wait( const int& milliseconds ) {
    return WaitForSingleObject( Handle, milliseconds );
  }

  inline bool_t Event::IsOpen() const {
    return WaitForSingleObject( Handle, 0 ) == WAIT_TIMEOUT;
  }

  inline HANDLE Event::GetHandle() {
    return Handle;
  }

  inline Event::~Event() {
    CloseHandle( Handle );
  }



  class Semaphore {
    HANDLE Handle;
  public:

    Semaphore( const int& size );
    bool_t Enter();
    bool_t Leave();
    ~Semaphore();
  };

  inline Semaphore::Semaphore( const int& size ) {
    Handle = CreateSemaphore( Null, size, size, Null );
    if( Handle == Null )
      throw std::exception( "Can not create Semaphore object." );
  }

  inline bool_t Semaphore::Enter() {
    return WaitForSingleObject( Handle, INFINITE );
  }

  inline  bool_t Semaphore::Leave() {
    return ReleaseSemaphore( Handle, 1, 0 );
  }

  inline Semaphore::~Semaphore() {
    CloseHandle( Handle );
  }



  class ThreadLocker {
    CRITICAL_SECTION CriticalSection;

  public:
    ThreadLocker();
    void Enter();
    void Leave();
    bool IsLocked();
    ~ThreadLocker();
  };

  inline ThreadLocker::ThreadLocker() {
    InitializeCriticalSection( &CriticalSection );
  };

  inline void ThreadLocker::Enter() {
    EnterCriticalSection( &CriticalSection );
  };

  inline void ThreadLocker::Leave() {
    LeaveCriticalSection( &CriticalSection );
  };

  inline bool ThreadLocker::IsLocked() {
    return TryEnterCriticalSection( &CriticalSection ) ? true : false;
  }

  inline ThreadLocker::~ThreadLocker() {
    DeleteCriticalSection( &CriticalSection );
  };
} // namespace Common

#endif // __UNION_THREAD_H__