// Supported with union (c) 2018-2021 Union team

#ifndef __ZMUSIC__DM_H__VER1__
#define __ZMUSIC__DM_H__VER1__

#include "zMusic.h"

namespace Gothic_I_Addon {
  const int NUM_MOTIFS = 16;

  // sizeof 4Ch
  class zCMusicTheme_DM : public zCMusicTheme {
  public:
    void* seg; // sizeof 04h    offset 48h

    zCMusicTheme_DM() {}
    virtual ~zCMusicTheme_DM()   zCall( 0x004EB2B0 );
    virtual int IsActive() const zCall( 0x004EB460 );

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

    void zCMusicSys_DirectMusic_OnInit()                                                                     zCall( 0x004EB490 );
    zCMusicSys_DirectMusic()                                                                                 zInit( zCMusicSys_DirectMusic_OnInit() );
    virtual ~zCMusicSys_DirectMusic()                                                                        zCall( 0x004ECA80 );
    virtual void PlayThemeByScript( zSTRING const&, int, int* )                                              zCall( 0x004ECB40 );
    virtual zCMusicTheme* LoadThemeByScript( zSTRING const& )                                                zCall( 0x004ECD40 );
    virtual zCMusicTheme* LoadTheme( zSTRING const& )                                                        zCall( 0x004ECD30 );
    virtual void PlayTheme( zCMusicTheme*, float const&, zTMus_TransType const&, zTMus_TransSubType const& ) zCall( 0x004ED980 );
    virtual zCMusicTheme* GetActiveTheme()                                                                   zCall( 0x004EC060 );
    virtual int PlayJingleByScript( zSTRING const& )                                                         zCall( 0x004EDBF0 );
    virtual void StopJingleByScript( zSTRING const& )                                                        zCall( 0x004EDD40 );
    virtual zCMusicJingle* LoadJingleByScript( zSTRING const& )                                              zCall( 0x004EDD50 );
    virtual zCMusicJingle* LoadJingle( zSTRING const& )                                                      zCall( 0x004EDF40 );
    virtual int PlayJingle( zCMusicJingle const*, float const&, zTMus_TransSubType const& )                  zCall( 0x004EDF50 );
    virtual void StopJingle( int const& )                                                                    zCall( 0x004EC070 );
    virtual int IsJingleActive( int const& )                                                                 zCall( 0x004EC080 );
    virtual void DoMusicUpdate()                                                                             zCall( 0x004EE0E0 );
    virtual void Mute()                                                                                      zCall( 0x004EE120 );
    virtual void Stop()                                                                                      zCall( 0x004EE0F0 );
    virtual void SetVolume( float )                                                                          zCall( 0x004EE180 );
    virtual float GetVolume() const                                                                          zCall( 0x004EC090 );
    virtual int IsAvailable( zSTRING const& )                                                                zCall( 0x004EE1C0 );

    // user API
    #include "zCMusicSys_DirectMusic.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZMUSIC__DM_H__VER1__