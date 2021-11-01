// Supported with union (c) 2018-2021 Union team

#ifndef __ZMUSIC__DM_H__VER2__
#define __ZMUSIC__DM_H__VER2__

#include "zMusic.h"

namespace Gothic_II_Classic {
  const int NUM_MOTIFS = 16;

  // sizeof 4Ch
  class zCMusicTheme_DM : public zCMusicTheme {
  public:
    void* seg; // sizeof 04h    offset 48h

    zCMusicTheme_DM() {}
    virtual ~zCMusicTheme_DM()   zCall( 0x004E4930 );
    virtual int IsActive() const zCall( 0x004E4AA0 );

    // user API
    #include "zCMusicTheme_DM.inl"
  };

  // sizeof 40h
  class zCMusicJingle_DM : public zCMusicJingle {
  public:

    zCMusicJingle_DM() {}

    // user API
    #include "zCMusicJingle_DM.inl"
  };

  // sizeof 1Ch
  class CMusDrvProperties {
  public:
    float volume;             // sizeof 04h    offset 00h
    int bitResolution;        // sizeof 04h    offset 04h
    int globalReverbEnabled;  // sizeof 04h    offset 08h
    int sampleRate;           // sizeof 04h    offset 0Ch
    int numChannels;          // sizeof 04h    offset 10h
    int reverbBufferSize;     // sizeof 04h    offset 14h
    unsigned char dScriptEnd; // sizeof 01h    offset 18h

    CMusDrvProperties() {}
  };

  // sizeof 30h
  class zCMusicSys_DirectMusic : public zCMusicSystem {
  public:
    CMusDrvProperties prefs; // sizeof 1Ch    offset 0Ch
    zCMusicTheme* actTheme;  // sizeof 04h    offset 28h
    zCMusicTheme* defTheme;  // sizeof 04h    offset 2Ch

    void zCMusicSys_DirectMusic_OnInit()                                                                     zCall( 0x004E4AD0 );
    zCMusicSys_DirectMusic()                                                                                 zInit( zCMusicSys_DirectMusic_OnInit() );
    virtual ~zCMusicSys_DirectMusic()                                                                        zCall( 0x004E5EE0 );
    virtual void PlayThemeByScript( zSTRING const&, int, int* )                                              zCall( 0x004E5FA0 );
    virtual zCMusicTheme* LoadThemeByScript( zSTRING const& )                                                zCall( 0x004E6170 );
    virtual zCMusicTheme* LoadTheme( zSTRING const& )                                                        zCall( 0x004E6160 );
    virtual void PlayTheme( zCMusicTheme*, float const&, zTMus_TransType const&, zTMus_TransSubType const& ) zCall( 0x004E6D10 );
    virtual zCMusicTheme* GetActiveTheme()                                                                   zCall( 0x004E5620 );
    virtual int PlayJingleByScript( zSTRING const& )                                                         zCall( 0x004E6F80 );
    virtual void StopJingleByScript( zSTRING const& )                                                        zCall( 0x004E70B0 );
    virtual zCMusicJingle* LoadJingleByScript( zSTRING const& )                                              zCall( 0x004E70C0 );
    virtual zCMusicJingle* LoadJingle( zSTRING const& )                                                      zCall( 0x004E7270 );
    virtual int PlayJingle( zCMusicJingle const*, float const&, zTMus_TransSubType const& )                  zCall( 0x004E7280 );
    virtual void StopJingle( int const& )                                                                    zCall( 0x004E5630 );
    virtual int IsJingleActive( int const& )                                                                 zCall( 0x004E5640 );
    virtual void DoMusicUpdate()                                                                             zCall( 0x004E7400 );
    virtual void Mute()                                                                                      zCall( 0x004E7430 );
    virtual void Stop()                                                                                      zCall( 0x004E7410 );
    virtual void SetVolume( float )                                                                          zCall( 0x004E74C0 );
    virtual float GetVolume() const                                                                          zCall( 0x004E5650 );
    virtual int IsAvailable( zSTRING const& )                                                                zCall( 0x004E7500 );

    // user API
    #include "zCMusicSys_DirectMusic.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZMUSIC__DM_H__VER2__