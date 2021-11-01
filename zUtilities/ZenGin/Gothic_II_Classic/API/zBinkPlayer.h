// Supported with union (c) 2018-2021 Union team

#ifndef __ZBINK_PLAYER_H__VER2__
#define __ZBINK_PLAYER_H__VER2__

#include "zVideoPlayer.h"
#include "zRenderer.h"

namespace Gothic_II_Classic {

  // sizeof 80h
  class zCBinkPlayer : public zCVideoPlayer {
  public:
    void* mVideoHandle;   // sizeof 04h    offset 30h
    long mCopyMode;       // sizeof 04h    offset 34h
    short mXpos;          // sizeof 02h    offset 38h
    short mYpos;          // sizeof 02h    offset 3Ah
    int mDoBlit;          // sizeof 04h    offset 3Ch
    int mDoHandleEvents;  // sizeof 04h    offset 40h
    int mDoFullscreen;    // sizeof 04h    offset 44h
    zSTRING mBackTexture; // sizeof 14h    offset 48h
    zCView* mBackView;    // sizeof 04h    offset 5Ch
    RECT mSourceRect;     // sizeof 10h    offset 60h
    RECT mTargetRect;     // sizeof 10h    offset 70h

    void zCBinkPlayer_OnInit()               zCall( 0x0043D800 );
    zCBinkPlayer()                           zInit( zCBinkPlayer_OnInit() );
    long GetPixelFormat( zTRndSurfaceDesc& ) zCall( 0x00440160 );
    void SetFullscreen( int, zSTRING )       zCall( 0x00440330 );
    virtual ~zCBinkPlayer()                  zCall( 0x0043D950 );
    virtual int OpenVideo( zSTRING )         zCall( 0x0043DAC0 );
    virtual int CloseVideo()                 zCall( 0x0043E7C0 );
    virtual int PlayInit( int )              zCall( 0x0043EA50 );
    virtual int PlayFrame()                  zCall( 0x0043FF30 );
    virtual int PlayDeinit()                 zCall( 0x0043F6F0 );
    virtual int Pause()                      zCall( 0x004400E0 );
    virtual int Unpause()                    zCall( 0x00440100 );
    virtual int IsPlaying()                  zCall( 0x00440130 );
    virtual int ToggleSound()                zCall( 0x004402B0 );
    virtual float SetSoundVolume( float )    zCall( 0x00440300 );
    virtual int PlayGotoNextFrame()          zCall( 0x0043FEE0 );
    virtual int PlayWaitNextFrame()          zCall( 0x0043FEF0 );
    virtual int PlayHandleEvents()           zCall( 0x00440120 );

    // user API
    #include "zCBinkPlayer.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZBINK_PLAYER_H__VER2__