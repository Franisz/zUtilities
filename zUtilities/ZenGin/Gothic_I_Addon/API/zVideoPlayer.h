// Supported with union (c) 2018 Union team

#ifndef __ZVIDEO_PLAYER_H__VER1__
#define __ZVIDEO_PLAYER_H__VER1__

namespace Gothic_I_Addon {

  class zCVideoPlayer {
  public:
    zSTRING mVideoFilename;
    int mLooping;
    int mPaused;
    int mPlaying;
    int mSoundOn;
    float mSoundVolume;
    float mScaleValue;

    void zCVideoPlayer_OnInit()           zCall( 0x00471260 );
    zSTRING GetVideoFilename()            zCall( 0x00440340 );
    zCVideoPlayer()                       zInit( zCVideoPlayer_OnInit() );
    int Play( int )                       zCall( 0x00471630 );
    virtual ~zCVideoPlayer()              zCall( 0x004712F0 );
    virtual int OpenVideo( zSTRING )      zCall( 0x00471350 );
    virtual int CloseVideo()              zCall( 0x00471510 );
    virtual int PlayInit( int )           zCall( 0x00471740 );
    virtual int PlayFrame()               zCall( 0x00471780 );
    virtual int PlayDeinit()              zCall( 0x00471790 );
    virtual int Pause()                   zCall( 0x004717A0 );
    virtual int Unpause()                 zCall( 0x004717C0 );
    virtual int Stop()                    zCall( 0x004717E0 );
    virtual int IsPlaying()               zCall( 0x004712A0 );
    virtual int ToggleSound()             zCall( 0x004712B0 );
    virtual float SetSoundVolume( float ) zCall( 0x004712C0 );
    virtual int PlayGotoNextFrame()       zCall( 0x00471760 );
    virtual int PlayWaitNextFrame()       zCall( 0x00471770 );

    // user API
    #include "zCVideoPlayer.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZVIDEO_PLAYER_H__VER1__