// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIDEO_PLAYER_H__VER0__
#define __ZVIDEO_PLAYER_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 30h
  class zCVideoPlayer {
  public:
    zSTRING mVideoFilename; // sizeof 14h    offset 04h
    int mLooping;           // sizeof 04h    offset 18h
    int mPaused;            // sizeof 04h    offset 1Ch
    int mPlaying;           // sizeof 04h    offset 20h
    int mSoundOn;           // sizeof 04h    offset 24h
    float mSoundVolume;     // sizeof 04h    offset 28h
    float mScaleValue;      // sizeof 04h    offset 2Ch

    void zCVideoPlayer_OnInit()           zCall( 0x004691A0 );
    zSTRING GetVideoFilename()            zCall( 0x0043B410 );
    zCVideoPlayer()                       zInit( zCVideoPlayer_OnInit() );
    int Play( int )                       zCall( 0x004694F0 );
    virtual ~zCVideoPlayer()              zCall( 0x00469230 );
    virtual int OpenVideo( zSTRING )      zCall( 0x00469280 );
    virtual int CloseVideo()              zCall( 0x004693F0 );
    virtual int PlayInit( int )           zCall( 0x00469600 );
    virtual int PlayFrame()               zCall( 0x00469640 );
    virtual int PlayDeinit()              zCall( 0x00469650 );
    virtual int Pause()                   zCall( 0x00469660 );
    virtual int Unpause()                 zCall( 0x00469680 );
    virtual int Stop()                    zCall( 0x004696A0 );
    virtual int IsPlaying()               zCall( 0x004691E0 );
    virtual int ToggleSound()             zCall( 0x004691F0 );
    virtual float SetSoundVolume( float ) zCall( 0x00469200 );
    virtual int PlayGotoNextFrame()       zCall( 0x00469620 );
    virtual int PlayWaitNextFrame()       zCall( 0x00469630 );

    // user API
    #include "zCVideoPlayer.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZVIDEO_PLAYER_H__VER0__