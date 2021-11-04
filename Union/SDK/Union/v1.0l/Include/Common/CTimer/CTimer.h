// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_TIMER_H__
#define __UNION_TIMER_H__

#ifdef force
#undef force
#endif
#define force(_Xv_) for (int32 _Cn_ = 0; _Cn_ < _Xv_; _Cn_++)

namespace Common {
  enum ETimerMode : byte
  {
    TM_LINEAR  = 1,
    TM_PRIMARY = 2,
    TM_EXACT   = 4
  };

  enum ETimerFlag : byte
  {
    TF_DEFAULT  = 0,
    TF_ACTIVE   = 1,
    TF_SUSPEND  = 2,
    TF_UNDELETE = 4
  };

  struct ASTAPI CController
  {
    CController(
      const int32& id,
      const int32& del,
      const int32& mod,
      const int32& flg
    );
    int32 lID;
    int32 lDelay;
    int32 lNext;
    int32 lStatus;
    int32 lMode;
    int32 lFlags;
    int32 lSusTime;
    class CTimer* lpChild;
    ~CController();
  };

  typedef CArrayOld <CController*> TEmitterList;
#define ticknone (-2)
#define tickonce (-1)

  typedef class ASTAPI CTimer
  {
    struct ASTAPI CFrame {
      uint32 ulPrevious;
      real32 fFrameTime;
      operator real32 () {
        return fFrameTime;
      };
    }
    frame;

    TEmitterList tEmitter;

  public:

    CTimer();
    void Attach();
    bool32 IsExist( const int32& );
    void Delete( const int32& );
    void Suspend( const int32&, const byte& );
    void Static( const int32&, const byte& );

    CTimer& operator [] ( const int32& id );
    bool32 operator () (
      const int32& id,
      const int32& delay = ticknone,
      const int32& mode  = TM_LINEAR,
      const int32& flags = TF_DEFAULT
      );

    static uint32 GetTime();
    ~CTimer();
  }
  TIMER, *PTIMER;
} // namespace Common

#endif // __UNION_TIMER_H__