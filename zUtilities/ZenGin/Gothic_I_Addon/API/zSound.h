// Supported with union (c) 2018 Union team

#ifndef __ZSOUND_H__VER1__
#define __ZSOUND_H__VER1__

namespace Gothic_I_Addon {
  const int zSND_FREQ_DEFAULT         = -1;
  const float zSND_PAN_DEFAULT        = -2;
  const float zSND_PAN_LEFT           =-1.0F;
  const float zSND_PAN_CENTER         = 0.0F;
  const float zSND_PAN_RIGHT          = 1.0F;
  const float zSND_PAN_SURROUND       = 100.0F;
  const int zSND_SLOT_NONE            = 0;
  const int zSND_SLOT_MAX             = 8;
  const int zSND_CHANNEL_FRAME_RANDOM =-1;

  class zCSoundSystem {
  public:
    enum zTLoopType {
      zSND_LOOPING_DEFAULT,
      zSND_LOOPING_ENABLED,
      zSND_LOOPING_DISABLED
    };

    enum zTSpeakerType {
      zSPEAKER_TYPE_2_SPEAKER,
      zSPEAKER_TYPE_HEADPHONE,
      zSPEAKER_TYPE_SURROUND,
      zSPEAKER_TYPE_4_SPEAKER
    };

    struct zTSound3DParams {
      float obstruction;
      float volume;
      float radius;
      zTLoopType loopType;
      float coneAngleDeg;
      float reverbLevel;
      int isAmbient3D;
      float pitchOffset;

      zTSound3DParams() {}
      void SetDefaults() zCall( 0x00606310 );

      // user API
      #include "zCSoundSystem_zTSound3DParams.inl"
    };

    float defaultRadius;

    zCSoundSystem() {}
    int GetNumReverbPresets()                                                zCall( 0x005DF950 );
    zSTRING const* GetReverbPresetName( int )                                zCall( 0x005DF960 );
    virtual ~zCSoundSystem()                                                 zCall( 0x004EF280 );
    virtual zCSoundFX* LoadSoundFX( zSTRING const& )                         zCall( 0x004EF290 );
    virtual zCSoundFX* LoadSoundFXScript( zSTRING const& )                   zCall( 0x004EF2A0 );
    virtual zCParser* GetSFXParser()                                         zCall( 0x004EF2B0 );
    virtual float GetPlayingTimeMSEC( zSTRING const& )                       zCall( 0x004EF2C0 );
    virtual void SetSound3DDefaultRadius( float )                            zCall( 0x004EF2D0 );
    virtual float GetSound3DDefaultRadius() const                            zCall( 0x004EF2E0 );
    virtual void SetMasterVolume( float )                                    zCall( 0x004EF2F0 );
    virtual float GetMasterVolume()                                          zCall( 0x004EF300 );
    virtual int PlaySound( zCSoundFX*, int )                                 zPureCall;
    virtual int PlaySound( zCSoundFX*, int, int, float, float )              zPureCall;
    virtual int PlaySound3D( zCSoundFX*, zCVob*, int, zTSound3DParams* )     zPureCall;
    virtual int PlaySound3D( zSTRING const&, zCVob*, int, zTSound3DParams* ) zPureCall;
    virtual void StopSound( int const& )                                     zCall( 0x004EF310 );
    virtual void StopAllSounds()                                             zCall( 0x004EF320 );
    virtual int GetSound3DProps( int const&, zTSound3DParams& )              zPureCall;
    virtual int UpdateSound3D( int const&, zTSound3DParams* )                zPureCall;
    virtual void GetSoundProps( int const&, int&, float&, float& )           zCall( 0x004EF330 );
    virtual void UpdateSoundProps( int const&, int, float, float )           zCall( 0x004EF340 );
    virtual int IsSoundActive( int const& )                                  zCall( 0x004EF350 );
    virtual void DoSoundUpdate()                                             zPureCall;
    virtual void SetListener( zCVob* )                                       zCall( 0x004EF360 );
    virtual void SetGlobalReverbPreset( int, float )                         zCall( 0x004EF370 );
    virtual void SetReverbEnabled( int )                                     zCall( 0x004EF380 );
    virtual int GetReverbEnabled()                                           zCall( 0x004EF390 );
    virtual int GetNumProvider()                                             zCall( 0x004EF3A0 );
    virtual zSTRING const* GetProviderName( int )                            zCall( 0x004EF3B0 );
    virtual int SetProvider( int )                                           zCall( 0x004EF3C0 );
    virtual void SetSpeakerType( zTSpeakerType )                             zCall( 0x004EF3D0 );
    virtual zTSpeakerType GetSpeakerType()                                   zCall( 0x004EF3E0 );
    virtual void SetGlobalOcclusion( float )                                 zPureCall;
    virtual float GetCPULoad()                                               zCall( 0x004EF3F0 );

    // user API
    #include "zCSoundSystem.inl"
  };

  class zCSoundFX : public zCResource {
  public:
    zCLASS_DECLARATION( zCSoundFX )

    void zCSoundFX_OnInit()                                             zCall( 0x004F2380 );
    zCSoundFX()                                                         zInit( zCSoundFX_OnInit() );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x004F2370 );
    virtual ~zCSoundFX()                                                zCall( 0x004F23A0 );
    virtual void GetCacheConfig( unsigned long&, unsigned long& )       zCall( 0x005DF980 );
    virtual int GetNumChannels() const                                  zCall( 0x004F23B0 );
    virtual int GetNumChannelFrames( int ) const                        zCall( 0x004F23C0 );
    virtual void GetChannelFrame( int, int ) const                      zCall( 0x004F23D0 );
    virtual void SetChannelFrame( int, int )                            zCall( 0x004F23E0 );
    virtual float GetPlayingTimeMSEC() const                            zCall( 0x004F23F0 );
    virtual float GetPan() const                                        zCall( 0x004F2400 );
    virtual void SetPan( float )                                        zCall( 0x004F2410 );
    virtual float GetVolume() const                                     zCall( 0x004F2420 );
    virtual void SetVolume( float )                                     zCall( 0x004F2430 );
    virtual int GetFrequency() const                                    zCall( 0x004F2440 );
    virtual void SetFrequency( int )                                    zCall( 0x004F2450 );
    virtual void SetLooping( int )                                      zCall( 0x004F2460 );
    virtual int IsLooping() const                                       zCall( 0x004F2470 );

    // user API
    #include "zCSoundFX.inl"
  };

  class zCSoundFXDummy : public zCSoundFX {
  public:

    zCSoundFXDummy() {}
    virtual ~zCSoundFXDummy() zCall( 0x00625830 );

    // user API
    #include "zCSoundFXDummy.inl"
  };

  class zCSoundSystemDummy : public zCSoundSystem {
  public:

    zCSoundSystemDummy() {}
    virtual ~zCSoundSystemDummy()                                                           zCall( 0x0062ADA0 );
    virtual zCSoundFX* LoadSoundFX( zSTRING const& )                                        zCall( 0x00625780 );
    virtual int PlaySound( zCSoundFX*, int )                                                zCall( 0x00625840 );
    virtual int PlaySound( zCSoundFX*, int, int, float, float )                             zCall( 0x00625850 );
    virtual int PlaySound3D( zCSoundFX*, zCVob*, int, zCSoundSystem::zTSound3DParams* )     zCall( 0x00625870 );
    virtual int PlaySound3D( zSTRING const&, zCVob*, int, zCSoundSystem::zTSound3DParams* ) zCall( 0x00625880 );
    virtual int GetSound3DProps( int const&, zCSoundSystem::zTSound3DParams& )              zCall( 0x00625890 );
    virtual int UpdateSound3D( int const&, zCSoundSystem::zTSound3DParams* )                zCall( 0x006258A0 );
    virtual void DoSoundUpdate()                                                            zCall( 0x00625770 );
    virtual void SetGlobalOcclusion( float )                                                zCall( 0x00625860 );

    // user API
    #include "zCSoundSystemDummy.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZSOUND_H__VER1__