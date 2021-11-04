// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_TIMER_H__
#define __UNION_TIMER_H__

namespace Common {
  class ASTAPI TimerBlock {
    friend class Timer;

    uint StartTime;
    uint StartSuspendedTime;
    uint Index;
    bool Unused;
    bool Suspended;
  public:

    TimerBlock();
    TimerBlock( const uint& index );

    operator uint() const { return Index; }
    bool operator <  ( const uint& index ) const;
    bool operator >  ( const uint& index ) const;
    bool operator == ( const uint& index ) const;

    bool Await( const uint& delay = 100, const bool& firstCallIsWorking = false );
    uint AwaitExact( const uint& delay = 100, const bool& firstCallIsWorking = false );
    void Suspend( const bool& suspend );
    uint TimeHasPassed();
    TimerBlock& TimeAppend( const uint& delay );
    TimerBlock& ResetTime();
    void Delete();
  };

  class ASTAPI Timer {
    Array<TimerBlock> Blocks;
  public:

    TimerBlock& operator[]( const uint& index );
    TimerBlock& operator[]( const void* index );
    void ClearUnused();

    static uint GetTime();
  };
} // namespace Common

#endif // __UNION_TIMER_H__