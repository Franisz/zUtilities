// Supported with union (c) 2018 Union team

#ifndef __ZMUSIC__DM_H__VER0__
#define __ZMUSIC__DM_H__VER0__

#include "zMusic.h"
#include "zTools.h"

namespace Gothic_I_Classic {
  const int NUM_MOTIFS = 16;

  class zCMusicTheme_DM : public zCMusicTheme {
  public:
    void* seg;

    zCMusicTheme_DM() {}
    virtual ~zCMusicTheme_DM()   zCall( 0x004DA0D0 );
    virtual int IsActive() const zCall( 0x004DA240 );

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

    void zCMusicSys_DirectMusic_OnInit()                                                                     zCall( 0x004DA270 );
    zCMusicSys_DirectMusic()                                                                                 zInit( zCMusicSys_DirectMusic_OnInit() );
    virtual ~zCMusicSys_DirectMusic()                                                                        zCall( 0x004DB790 );
    virtual void PlayThemeByScript( zSTRING const&, int, int* )                                              zCall( 0x004DB850 );
    virtual zCMusicTheme* LoadThemeByScript( zSTRING const& )                                                zCall( 0x004DBA20 );
    virtual zCMusicTheme* LoadTheme( zSTRING const& )                                                        zCall( 0x004DBA10 );
    virtual void PlayTheme( zCMusicTheme*, float const&, zTMus_TransType const&, zTMus_TransSubType const& ) zCall( 0x004DC4E0 );
    virtual zCMusicTheme* GetActiveTheme()                                                                   zCall( 0x004DAED0 );
    virtual int PlayJingleByScript( zSTRING const& )                                                         zCall( 0x004DC750 );
    virtual void StopJingleByScript( zSTRING const& )                                                        zCall( 0x004DC880 );
    virtual zCMusicJingle* LoadJingleByScript( zSTRING const& )                                              zCall( 0x004DC890 );
    virtual zCMusicJingle* LoadJingle( zSTRING const& )                                                      zCall( 0x004DCA50 );
    virtual int PlayJingle( zCMusicJingle const*, float const&, zTMus_TransSubType const& )                  zCall( 0x004DCA60 );
    virtual void StopJingle( int const& )                                                                    zCall( 0x004DAEE0 );
    virtual int IsJingleActive( int const& )                                                                 zCall( 0x004DAEF0 );
    virtual void DoMusicUpdate()                                                                             zCall( 0x004DCBE0 );
    virtual void Mute()                                                                                      zCall( 0x004DCC20 );
    virtual void Stop()                                                                                      zCall( 0x004DCBF0 );
    virtual void SetVolume( float )                                                                          zCall( 0x004DCC80 );
    virtual float GetVolume() const                                                                          zCall( 0x004DAF00 );
    virtual int IsAvailable( zSTRING const& )                                                                zCall( 0x004DCCC0 );

    // user API
    #include "zCMusicSys_DirectMusic.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZMUSIC__DM_H__VER0__