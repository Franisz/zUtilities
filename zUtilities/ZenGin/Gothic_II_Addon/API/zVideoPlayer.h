// Supported with union (c) 2018-2021 Union team

#ifndef __ZVIDEO_PLAYER_H__VER3__
#define __ZVIDEO_PLAYER_H__VER3__

namespace Gothic_II_Addon {

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

    void zCVideoPlayer_OnInit()           zCall( 0x0046E480 );
    zSTRING GetVideoFilename()            zCall( 0x0043F030 );
    zCVideoPlayer()                       zInit( zCVideoPlayer_OnInit() );
    int Play( int )                       zCall( 0x0046E7D0 );
    virtual ~zCVideoPlayer()              zCall( 0x0046E510 );
    virtual int OpenVideo( zSTRING )      zCall( 0x0046E560 );
    virtual int CloseVideo()              zCall( 0x0046E6D0 );
    virtual int PlayInit( int )           zCall( 0x0046E8E0 );
    virtual int PlayFrame()               zCall( 0x0046E920 );
    virtual int PlayDeinit()              zCall( 0x0046E930 );
    virtual int Pause()                   zCall( 0x0046E940 );
    virtual int Unpause()                 zCall( 0x0046E960 );
    virtual int Stop()                    zCall( 0x0046E980 );
    virtual int IsPlaying()               zCall( 0x0046E4C0 );
    virtual int ToggleSound()             zCall( 0x0046E4D0 );
    virtual float SetSoundVolume( float ) zCall( 0x0046E4E0 );
    virtual int PlayGotoNextFrame()       zCall( 0x0046E900 );
    virtual int PlayWaitNextFrame()       zCall( 0x0046E910 );

    // user API
    #include "zCVideoPlayer.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVIDEO_PLAYER_H__VER3__