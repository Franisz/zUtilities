// Supported with union (c) 2018-2021 Union team

#ifndef __ZBINK_PLAYER_H__VER1__
#define __ZBINK_PLAYER_H__VER1__

#include "zVideoPlayer.h"
#include "zRenderer.h"

namespace Gothic_I_Addon {

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

    void zCBinkPlayer_OnInit()               zCall( 0x0043F0C0 );
    zCBinkPlayer()                           zInit( zCBinkPlayer_OnInit() );
    long GetPixelFormat( zTRndSurfaceDesc& ) zCall( 0x00441AF0 );
    void SetFullscreen( int, zSTRING )       zCall( 0x00441D60 );
    virtual ~zCBinkPlayer()                  zCall( 0x0043F230 );
    virtual int OpenVideo( zSTRING )         zCall( 0x0043F3D0 );
    virtual int CloseVideo()                 zCall( 0x004400B0 );
    virtual int PlayInit( int )              zCall( 0x00440390 );
    virtual int PlayFrame()                  zCall( 0x004418B0 );
    virtual int PlayDeinit()                 zCall( 0x00440FB0 );
    virtual int Pause()                      zCall( 0x00441A70 );
    virtual int Unpause()                    zCall( 0x00441A90 );
    virtual int IsPlaying()                  zCall( 0x00441AC0 );
    virtual int ToggleSound()                zCall( 0x00441CE0 );
    virtual float SetSoundVolume( float )    zCall( 0x00441D30 );
    virtual int PlayGotoNextFrame()          zCall( 0x00441860 );
    virtual int PlayWaitNextFrame()          zCall( 0x00441870 );
    virtual int PlayHandleEvents()           zCall( 0x00441AB0 );

    // user API
    #include "zCBinkPlayer.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZBINK_PLAYER_H__VER1__