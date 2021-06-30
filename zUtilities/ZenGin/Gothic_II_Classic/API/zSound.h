// Supported with union (c) 2018 Union team

#ifndef __ZSOUND_H__VER2__
#define __ZSOUND_H__VER2__

namespace Gothic_II_Classic {
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
      zSPEAKER_TYPE_4_SPEAKER,
      zSPEAKER_TYPE_51_SPEAKER,
      zSPEAKER_TYPE_71_SPEAKER,
      zMaxSpeakerType
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
      void SetDefaults() zCall( 0x0060B890 );

      // user API
      #include "zCSoundSystem_zTSound3DParams.inl"
    };

    float defaultRadius;

    zCSoundSystem() {}
    int GetNumReverbPresets()                                                zCall( 0x005E52B0 );
    zSTRING const* GetReverbPresetName( int )                                zCall( 0x005E52C0 );
    virtual ~zCSoundSystem()                                                 zCall( 0x004E86D0 );
    virtual zCSoundFX* LoadSoundFX( zSTRING const& )                         zCall( 0x004E86E0 );
    virtual zCSoundFX* LoadSoundFXScript( zSTRING const& )                   zCall( 0x004E86F0 );
    virtual zCParser* GetSFXParser()                                         zCall( 0x004E8700 );
    virtual float GetPlayingTimeMSEC( zSTRING const& )                       zCall( 0x004E8710 );
    virtual void SetSound3DDefaultRadius( float )                            zCall( 0x004E8720 );
    virtual float GetSound3DDefaultRadius() const                            zCall( 0x004E8730 );
    virtual void SetMasterVolume( float )                                    zCall( 0x004E8740 );
    virtual float GetMasterVolume()                                          zCall( 0x004E8750 );
    virtual int PlaySound( zCSoundFX*, int )                                 zPureCall;
    virtual int PlaySound( zCSoundFX*, int, int, float, float )              zPureCall;
    virtual int PlaySound3D( zCSoundFX*, zCVob*, int, zTSound3DParams* )     zPureCall;
    virtual int PlaySound3D( zSTRING const&, zCVob*, int, zTSound3DParams* ) zPureCall;
    virtual void StopSound( int const& )                                     zCall( 0x004E8760 );
    virtual void StopAllSounds()                                             zCall( 0x004E8770 );
    virtual int GetSound3DProps( int const&, zTSound3DParams& )              zPureCall;
    virtual int UpdateSound3D( int const&, zTSound3DParams* )                zPureCall;
    virtual void GetSoundProps( int const&, int&, float&, float& )           zCall( 0x004E8780 );
    virtual void UpdateSoundProps( int const&, int, float, float )           zCall( 0x004E8790 );
    virtual int IsSoundActive( int const& )                                  zCall( 0x004E87A0 );
    virtual void DoSoundUpdate()                                             zPureCall;
    virtual void SetListener( zCVob* )                                       zCall( 0x004E87B0 );
    virtual void SetGlobalReverbPreset( int, float )                         zCall( 0x004E87C0 );
    virtual void SetReverbEnabled( int )                                     zCall( 0x004E87D0 );
    virtual int GetReverbEnabled()                                           zCall( 0x004E87E0 );
    virtual int GetNumProvider()                                             zCall( 0x004E87F0 );
    virtual zSTRING const* GetProviderName( int )                            zCall( 0x004E8800 );
    virtual int SetProvider( int )                                           zCall( 0x004E8810 );
    virtual void SetSpeakerType( zTSpeakerType )                             zCall( 0x004E8820 );
    virtual zTSpeakerType GetSpeakerType()                                   zCall( 0x004E8830 );
    virtual void SetGlobalOcclusion( float )                                 zPureCall;
    virtual float GetCPULoad()                                               zCall( 0x004E8840 );

    // user API
    #include "zCSoundSystem.inl"
  };

  class zCSoundFX : public zCResource {
  public:
    zCLASS_DECLARATION( zCSoundFX )

    void zCSoundFX_OnInit()                                       zCall( 0x004EB2D0 );
    zCSoundFX()                                                   zInit( zCSoundFX_OnInit() );
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x004EB2C0 );
    virtual ~zCSoundFX()                                          zCall( 0x004EB2F0 );
    virtual void GetCacheConfig( unsigned long&, unsigned long& ) zCall( 0x005E52E0 );
    virtual int GetNumChannels() const                            zCall( 0x004EB300 );
    virtual int GetNumChannelFrames( int ) const                  zCall( 0x004EB310 );
    virtual void GetChannelFrame( int, int ) const                zCall( 0x004EB320 );
    virtual void SetChannelFrame( int, int )                      zCall( 0x004EB330 );
    virtual float GetPlayingTimeMSEC() const                      zCall( 0x004EB340 );
    virtual float GetPan() const                                  zCall( 0x004EB350 );
    virtual void SetPan( float )                                  zCall( 0x004EB360 );
    virtual float GetVolume() const                               zCall( 0x004EB370 );
    virtual void SetVolume( float )                               zCall( 0x004EB380 );
    virtual int GetFrequency() const                              zCall( 0x004EB390 );
    virtual void SetFrequency( int )                              zCall( 0x004EB3A0 );
    virtual void SetLooping( int )                                zCall( 0x004EB3B0 );
    virtual int IsLooping() const                                 zCall( 0x004EB3C0 );
    virtual void SetIsFixed( int )                                zCall( 0x004EB3D0 );
    virtual int GetIsFixed() const                                zCall( 0x004EB3E0 );

    // user API
    #include "zCSoundFX.inl"
  };

  class zCSoundFXDummy : public zCSoundFX {
  public:

    zCSoundFXDummy() {}
    virtual ~zCSoundFXDummy() zCall( 0x0062B380 );

    // user API
    #include "zCSoundFXDummy.inl"
  };

  class zCSoundSystemDummy : public zCSoundSystem {
  public:

    zCSoundSystemDummy() {}
    virtual ~zCSoundSystemDummy()                                                           zCall( 0x00631860 );
    virtual zCSoundFX* LoadSoundFX( zSTRING const& )                                        zCall( 0x0062B2F0 );
    virtual int PlaySound( zCSoundFX*, int )                                                zCall( 0x0062B390 );
    virtual int PlaySound( zCSoundFX*, int, int, float, float )                             zCall( 0x0062B3A0 );
    virtual int PlaySound3D( zCSoundFX*, zCVob*, int, zCSoundSystem::zTSound3DParams* )     zCall( 0x0062B3C0 );
    virtual int PlaySound3D( zSTRING const&, zCVob*, int, zCSoundSystem::zTSound3DParams* ) zCall( 0x0062B3D0 );
    virtual int GetSound3DProps( int const&, zCSoundSystem::zTSound3DParams& )              zCall( 0x0062B3E0 );
    virtual int UpdateSound3D( int const&, zCSoundSystem::zTSound3DParams* )                zCall( 0x0062B3F0 );
    virtual void DoSoundUpdate()                                                            zCall( 0x0062B2E0 );
    virtual void SetGlobalOcclusion( float )                                                zCall( 0x0062B3B0 );

    // user API
    #include "zCSoundSystemDummy.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZSOUND_H__VER2__