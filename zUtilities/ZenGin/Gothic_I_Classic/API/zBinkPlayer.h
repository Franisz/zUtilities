// Supported with union (c) 2018 Union team

#ifndef __ZBINK_PLAYER_H__VER0__
#define __ZBINK_PLAYER_H__VER0__

#include "zVideoPlayer.h"
#include "zRenderer.h"

namespace Gothic_I_Classic {

  class zCBinkPlayer : public zCVideoPlayer {
  public:
    void* mVideoHandle;
    long mCopyMode;
    short mXpos;
    short mYpos;
    int mDoBlit;
    int mDoHandleEvents;
    int mDoFullscreen;
    zSTRING mBackTexture;
    zCView* mBackView;
    RECT mSourceRect;
    RECT mTargetRect;

    void zCBinkPlayer_OnInit()               zCall( 0x0043A3A0 );
    zCBinkPlayer()                           zInit( zCBinkPlayer_OnInit() );
    long GetPixelFormat( zTRndSurfaceDesc& ) zCall( 0x0043C9E0 );
    void SetFullscreen( int, zSTRING )       zCall( 0x0043CBB0 );
    virtual ~zCBinkPlayer()                  zCall( 0x0043A4F0 );
    virtual int OpenVideo( zSTRING )         zCall( 0x0043A660 );
    virtual int CloseVideo()                 zCall( 0x0043B1D0 );
    virtual int PlayInit( int )              zCall( 0x0043B460 );
    virtual int PlayFrame()                  zCall( 0x0043C7B0 );
    virtual int PlayDeinit()                 zCall( 0x0043BFB0 );
    virtual int Pause()                      zCall( 0x0043C960 );
    virtual int Unpause()                    zCall( 0x0043C980 );
    virtual int IsPlaying()                  zCall( 0x0043C9B0 );
    virtual int ToggleSound()                zCall( 0x0043CB30 );
    virtual float SetSoundVolume( float )    zCall( 0x0043CB80 );
    virtual int PlayGotoNextFrame()          zCall( 0x0043C760 );
    virtual int PlayWaitNextFrame()          zCall( 0x0043C770 );
    virtual int PlayHandleEvents()           zCall( 0x0043C9A0 );

    // user API
    #include "zCBinkPlayer.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZBINK_PLAYER_H__VER0__