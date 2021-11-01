// Supported with union (c) 2018-2021 Union team

#ifndef __ZSOUND_H__VER0__
#define __ZSOUND_H__VER0__

namespace Gothic_I_Classic {
  const int zSND_FREQ_DEFAULT         = -1;
  const float zSND_PAN_DEFAULT        = -2;
  const float zSND_PAN_LEFT           =-1.0F;
  const float zSND_PAN_CENTER         = 0.0F;
  const float zSND_PAN_RIGHT          = 1.0F;
  const float zSND_PAN_SURROUND       = 100.0F;
  const int zSND_SLOT_NONE            = 0;
  const int zSND_SLOT_MAX             = 8;
  const int zSND_CHANNEL_FRAME_RANDOM =-1;

  // sizeof 08h
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

    // sizeof 20h
    struct zTSound3DParams {
      float obstruction;   // sizeof 04h    offset 00h
      float volume;        // sizeof 04h    offset 04h
      float radius;        // sizeof 04h    offset 08h
      zTLoopType loopType; // sizeof 04h    offset 0Ch
      float coneAngleDeg;  // sizeof 04h    offset 10h
      float reverbLevel;   // sizeof 04h    offset 14h
      int isAmbient3D;     // sizeof 04h    offset 18h
      float pitchOffset;   // sizeof 04h    offset 1Ch

      zTSound3DParams() {}
      void SetDefaults() zCall( 0x005E6020 );

      // user API
      #include "zCSoundSystem_zTSound3DParams.inl"
    };

    float defaultRadius; // sizeof 04h    offset 04h

    zCSoundSystem() {}
    int GetNumReverbPresets()                                                zCall( 0x005C19F0 );
    zSTRING const* GetReverbPresetName( int )                                zCall( 0x005C1A00 );
    virtual ~zCSoundSystem()                                                 zCall( 0x004DDDD0 );
    virtual zCSoundFX* LoadSoundFX( zSTRING const& )                         zCall( 0x004DDDE0 );
    virtual zCSoundFX* LoadSoundFXScript( zSTRING const& )                   zCall( 0x004DDDF0 );
    virtual zCParser* GetSFXParser()                                         zCall( 0x004DDE00 );
    virtual float GetPlayingTimeMSEC( zSTRING const& )                       zCall( 0x004DDE10 );
    virtual void SetSound3DDefaultRadius( float )                            zCall( 0x004DDE20 );
    virtual float GetSound3DDefaultRadius() const                            zCall( 0x004DDE30 );
    virtual void SetMasterVolume( float )                                    zCall( 0x004DDE40 );
    virtual float GetMasterVolume()                                          zCall( 0x004DDE50 );
    virtual int PlaySound( zCSoundFX*, int )                                 zPureCall;
    virtual int PlaySound( zCSoundFX*, int, int, float, float )              zPureCall;
    virtual int PlaySound3D( zCSoundFX*, zCVob*, int, zTSound3DParams* )     zPureCall;
    virtual int PlaySound3D( zSTRING const&, zCVob*, int, zTSound3DParams* ) zPureCall;
    virtual void StopSound( int const& )                                     zCall( 0x004DDE60 );
    virtual void StopAllSounds()                                             zCall( 0x004DDE70 );
    virtual int GetSound3DProps( int const&, zTSound3DParams& )              zPureCall;
    virtual int UpdateSound3D( int const&, zTSound3DParams* )                zPureCall;
    virtual void GetSoundProps( int const&, int&, float&, float& )           zCall( 0x004DDE80 );
    virtual void UpdateSoundProps( int const&, int, float, float )           zCall( 0x004DDE90 );
    virtual int IsSoundActive( int const& )                                  zCall( 0x004DDEA0 );
    virtual void DoSoundUpdate()                                             zPureCall;
    virtual void SetListener( zCVob* )                                       zCall( 0x004DDEB0 );
    virtual void SetGlobalReverbPreset( int, float )                         zCall( 0x004DDEC0 );
    virtual void SetReverbEnabled( int )                                     zCall( 0x004DDED0 );
    virtual int GetReverbEnabled()                                           zCall( 0x004DDEE0 );
    virtual int GetNumProvider()                                             zCall( 0x004DDEF0 );
    virtual zSTRING const* GetProviderName( int )                            zCall( 0x004DDF00 );
    virtual int SetProvider( int )                                           zCall( 0x004DDF10 );
    virtual void SetSpeakerType( zTSpeakerType )                             zCall( 0x004DDF20 );
    virtual zTSpeakerType GetSpeakerType()                                   zCall( 0x004DDF30 );
    virtual void SetGlobalOcclusion( float )                                 zPureCall;
    virtual float GetCPULoad()                                               zCall( 0x004DDF40 );

    // user API
    #include "zCSoundSystem.inl"
  };

  // sizeof 54h
  class zCSoundFX : public zCResource {
  public:
    zCLASS_DECLARATION( zCSoundFX )

    void zCSoundFX_OnInit()                                             zCall( 0x004E09C0 );
    zCSoundFX()                                                         zInit( zCSoundFX_OnInit() );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x004E09B0 );
    virtual ~zCSoundFX()                                                zCall( 0x004E09E0 );
    virtual void GetCacheConfig( unsigned long&, unsigned long& )       zCall( 0x005C1A20 );
    virtual int GetNumChannels() const                                  zCall( 0x004E09F0 );
    virtual int GetNumChannelFrames( int ) const                        zCall( 0x004E0A00 );
    virtual void GetChannelFrame( int, int ) const                      zCall( 0x004E0A10 );
    virtual void SetChannelFrame( int, int )                            zCall( 0x004E0A20 );
    virtual float GetPlayingTimeMSEC() const                            zCall( 0x004E0A30 );
    virtual float GetPan() const                                        zCall( 0x004E0A40 );
    virtual void SetPan( float )                                        zCall( 0x004E0A50 );
    virtual float GetVolume() const                                     zCall( 0x004E0A60 );
    virtual void SetVolume( float )                                     zCall( 0x004E0A70 );
    virtual int GetFrequency() const                                    zCall( 0x004E0A80 );
    virtual void SetFrequency( int )                                    zCall( 0x004E0A90 );
    virtual void SetLooping( int )                                      zCall( 0x004E0AA0 );
    virtual int IsLooping() const                                       zCall( 0x004E0AB0 );

    // user API
    #include "zCSoundFX.inl"
  };

  // sizeof 54h
  class zCSoundFXDummy : public zCSoundFX {
  public:

    zCSoundFXDummy() {}
    virtual ~zCSoundFXDummy() zCall( 0x006037F0 );

    // user API
    #include "zCSoundFXDummy.inl"
  };

  // sizeof 08h
  class zCSoundSystemDummy : public zCSoundSystem {
  public:

    zCSoundSystemDummy() {}
    virtual ~zCSoundSystemDummy()                                                           zCall( 0x00608920 );
    virtual zCSoundFX* LoadSoundFX( zSTRING const& )                                        zCall( 0x00603740 );
    virtual int PlaySound( zCSoundFX*, int )                                                zCall( 0x00603800 );
    virtual int PlaySound( zCSoundFX*, int, int, float, float )                             zCall( 0x00603810 );
    virtual int PlaySound3D( zCSoundFX*, zCVob*, int, zCSoundSystem::zTSound3DParams* )     zCall( 0x00603830 );
    virtual int PlaySound3D( zSTRING const&, zCVob*, int, zCSoundSystem::zTSound3DParams* ) zCall( 0x00603840 );
    virtual int GetSound3DProps( int const&, zCSoundSystem::zTSound3DParams& )              zCall( 0x00603850 );
    virtual int UpdateSound3D( int const&, zCSoundSystem::zTSound3DParams* )                zCall( 0x00603860 );
    virtual void DoSoundUpdate()                                                            zCall( 0x00603730 );
    virtual void SetGlobalOcclusion( float )                                                zCall( 0x00603820 );

    // user API
    #include "zCSoundSystemDummy.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZSOUND_H__VER0__