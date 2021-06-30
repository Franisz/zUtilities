// Supported with union (c) 2018 Union team

#ifndef __ZMOVING_H__VER0__
#define __ZMOVING_H__VER0__

#include "z3d.h"
#include "zOption.h"
#include "zVob.h"

namespace Gothic_I_Classic {
  const int DEF_NUM_SAMPLES=256;

  class zCMoveRecorder {
  public:

    enum {
      MOR_IDLE,
      MOR_PLAYBACK,
      MOR_RECORD
    };

    struct zTMOR_Sample {
      zMAT4 trafoObjToWorld;

      zTMOR_Sample() {}

      // user API
      #include "zCMoveRecorder_zTMOR_Sample.inl"
    };

    zSTRING name;
    zCVob* vob;
    zCArray<zTMOR_Sample> samples;
    int state;
    int ctr;
    int looping;
    float startTime;

    zCMoveRecorder() {}

    // user API
    #include "zCMoveRecorder.inl"
  };

  class CMov_Movement {
  public:
    unsigned long oldtime;
    unsigned long now;
    double time_corr;
    zCVob* vob;
    double force_x;
    double force_y;
    double force_z;
    double force_rot;
    double xspeed;
    double yspeed;
    double zspeed;
    double rotspeed;

    CMov_Movement() {}
    void CMov_Movement_OnInit( zCVob* ) zCall( 0x005885C0 );
    CMov_Movement( zCVob* a0 )          zInit( CMov_Movement_OnInit( a0 ));
    void IncreaseSpeed( double )        zCall( 0x00588600 );
    void Movement()                     zCall( 0x00588690 );
  };

} // namespace Gothic_I_Classic

#endif // __ZMOVING_H__VER0__