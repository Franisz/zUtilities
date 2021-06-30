// Supported with union (c) 2018 Union team

#ifndef __ZMUSIC__DM_H__VER3__
#define __ZMUSIC__DM_H__VER3__

#include "zMusic.h"
#include "zTools.h"

namespace Gothic_II_Addon {
  const int NUM_MOTIFS = 16;

  class zCMusicTheme_DM : public zCMusicTheme {
  public:
    void* seg;

    zCMusicTheme_DM() {}
    virtual ~zCMusicTheme_DM()   zCall( 0x004E72B0 );
    virtual int IsActive() const zCall( 0x004E7420 );

    // user API
    #include "zCMusicTheme_DM.inl"
  };

  class zCMusicJingle_DM : public zCMusicJingle {
  public:

    zCMusicJingle_DM() {}

    // user API
    #include "zCMusicJingle_DM.inl"
  };

  class CMusDrvProperties {
  public:
    float volume;
    int bitResolution;
    int globalReverbEnabled;
    int sampleRate;
    int numChannels;
    int reverbBufferSize;
    unsigned char dScriptEnd;

    CMusDrvProperties() {}
  };

  class zCMusicSys_DirectMusic : public zCMusicSystem {
  public:
    CMusDrvProperties prefs;
    zCMusicTheme* actTheme;
    zCMusicTheme* defTheme;

    void zCMusicSys_DirectMusic_OnInit()                                                                     zCall( 0x004E7450 );
    zCMusicSys_DirectMusic()                                                                                 zInit( zCMusicSys_DirectMusic_OnInit() );
    virtual ~zCMusicSys_DirectMusic()                                                                        zCall( 0x004E89F0 );
    virtual void PlayThemeByScript( zSTRING const&, int, int* )                                              zCall( 0x004E8AB0 );
    virtual zCMusicTheme* LoadThemeByScript( zSTRING const& )                                                zCall( 0x004E8C80 );
    virtual zCMusicTheme* LoadTheme( zSTRING const& )                                                        zCall( 0x004E8C70 );
    virtual void PlayTheme( zCMusicTheme*, float const&, zTMus_TransType const&, zTMus_TransSubType const& ) zCall( 0x004E9820 );
    virtual zCMusicTheme* GetActiveTheme()                                                                   zCall( 0x004E8130 );
    virtual int PlayJingleByScript( zSTRING const& )                                                         zCall( 0x004E9A90 );
    virtual void StopJingleByScript( zSTRING const& )                                                        zCall( 0x004E9BC0 );
    virtual zCMusicJingle* LoadJingleByScript( zSTRING const& )                                              zCall( 0x004E9BD0 );
    virtual zCMusicJingle* LoadJingle( zSTRING const& )                                                      zCall( 0x004E9D80 );
    virtual int PlayJingle( zCMusicJingle const*, float const&, zTMus_TransSubType const& )                  zCall( 0x004E9D90 );
    virtual void StopJingle( int const& )                                                                    zCall( 0x004E8140 );
    virtual int IsJingleActive( int const& )                                                                 zCall( 0x004E8150 );
    virtual void DoMusicUpdate()                                                                             zCall( 0x004E9F10 );
    virtual void Mute()                                                                                      zCall( 0x004E9F40 );
    virtual void Stop()                                                                                      zCall( 0x004E9F20 );
    virtual void SetVolume( float )                                                                          zCall( 0x004E9FD0 );
    virtual float GetVolume() const                                                                          zCall( 0x004E8160 );
    virtual int IsAvailable( zSTRING const& )                                                                zCall( 0x004EA010 );

    // user API
    #include "zCMusicSys_DirectMusic.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZMUSIC__DM_H__VER3__