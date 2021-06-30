// Supported with union (c) 2018 Union team

#ifndef __ZSND_MSS_H__VER0__
#define __ZSND_MSS_H__VER0__

#include "z3d.h"
#include "zDisk.h"
#include "zTools.h"
#include "zSound.h"
#include "zParser.h"

namespace Gothic_I_Classic {
  const int MAX_PROVIDER = 20;

  class zCDrvProperties_MSS {
  public:
    float volume;
    int bitResolution;
    int sampleRate;
    int useStereo;
    int numSFXChannels;
    zSTRING use3dProvider;
    unsigned char dScriptEnd;
    PCMWAVEFORMAT waveFormat;
    long * providers[MAX_PROVIDER];
    zSTRING provNames[MAX_PROVIDER];
    int numProviders;

    void zCDrvProperties_MSS_OnInit() zCall( 0x004DCD30 );
    zCDrvProperties_MSS()             zInit( zCDrvProperties_MSS_OnInit() );
    ~zCDrvProperties_MSS()            zCall( 0x004DCDC0 );

    // user API
    #include "zCDrvProperties_MSS.inl"
  };

  class zCActiveSnd {
  public:
    int handle;
    void* sample;
    void* sample3D;
    unsigned long age;
    zCSoundSystem::zTLoopType loopType;
    float radius;
    float reverbLevel;
    float pitchOffset;
    float volWeight;
    float obstruction;
    group {
      unsigned char active    : 1;
      unsigned char looping   : 1;
      unsigned char isAmbient : 1;
      unsigned char is3D      : 1;
      unsigned char allocated : 1;
      unsigned char vobSlot   : 3;
    };
    unsigned char pan;
    unsigned char volume;
    unsigned short rate;
    int muteTime;
    int frameCtr;
    zVEC3 lastPos;
    float lastTime;
    zCVob* sourceVob;
    zCSndFrame* sourceFrm;
    zCSndFX_MSS* sourceSnd;

    void zCActiveSnd_OnInit()                             zCall( 0x004E8660 );
    zCActiveSnd()                                         zInit( zCActiveSnd_OnInit() );
    ~zCActiveSnd()                                        zCall( 0x004E8670 );
    void Release()                                        zCall( 0x004E8990 );
    void Initialize()                                     zCall( 0x004E8A10 );
    int CalcListenerPan()                                 zCall( 0x004E98E0 );
    int CalcListenerVolume()                              zCall( 0x004E98F0 );
    int RequestChannel()                                  zCall( 0x004E99C0 );
    int RequestChannel3D()                                zCall( 0x004E9C70 );
    float GetVolume()                                     zCall( 0x004E9F70 );
    int HasBeenUpdatedThisFrame()                         zCall( 0x004EB2C0 );
    static int GetNextFreeHandle()                        zCall( 0x004E86F0 );
    static zCActiveSnd* AllocNextFreeSnd()                zCall( 0x004E87C0 );
    static int GetHandleIndex( int )                      zCall( 0x004E8A80 );
    static int GetHandleActive( int )                     zCall( 0x004E8BC0 );
    static int GetSoundActive( zCActiveSnd* )             zCall( 0x004E8CC0 );
    static int GetFrameActive( zCSndFrame* )              zCall( 0x004E8D50 );
    static zCActiveSnd* GetHandleSound( int )             zCall( 0x004E8D90 );
    static void AddSound( zCActiveSnd* )                  zCall( 0x004E8E40 );
    static void RemoveSound( zCActiveSnd* )               zCall( 0x004E9010 );
    static void RemoveSoundsByFrame( zCSndFrame* )        zCall( 0x004E9280 );
    static void RemoveSoundByVobSlot( zCVob const*, int ) zCall( 0x004E92C0 );
    static void StopSoundsByFrame( zCSndFrame* )          zCall( 0x004E9310 );
    static void ResumeSoundsByFrame( zCSndFrame* )        zCall( 0x004E9370 );
    static void UpdateSoundsByFrame( zCSndFrame* )        zCall( 0x004E93C0 );
    static int GetNumActive()                             zCall( 0x004E96B0 );
    static void NewFrame()                                zCall( 0x004E96C0 );
    static int GetNum3DSamplesUsed()                      zCall( 0x004E9940 );
    static int GetNumAmbientSamplesUsed()                 zCall( 0x004E9980 );
    static void DebugInfo()                               zCall( 0x004EA150 );
    static void InitPreAllocedData()                      zCall( 0x004EB0A0 );
    static void CleanupPreAllocedData()                   zCall( 0x004EB200 );

    // static properties
    static zCArraySort<zCActiveSnd*>& activeSndList;
    static unsigned long& lastHandle;
    static int& maxChannels;
    static int& autoUpdate3D;
    static zCArray<zCActiveSnd*>& preAllocedSndList;
    static zCActiveSnd*& nextFreeSnd;

    // user API
    #include "zCActiveSnd.inl"
  };

  class zCSndChannel {
  public:
    int actFrame;
    int refCtr;
    int loaded;
    zCArray<zCSndFrame*> frameList;

    void zCSndChannel_OnInit() zCall( 0x004EB2F0 );
    zCSndChannel()             zInit( zCSndChannel_OnInit() );
    ~zCSndChannel()            zCall( 0x004EB310 );

    // user API
    #include "zCSndChannel.inl"
  };

  class zCSndFrame {
  public:
    zSTRING fileName;
    float pitchOffset;
    float pitchVariance;
    int defVolume;
    int looping;
    int loopStartOffset;
    int loopEndOffset;
    float reverbLevel;
    zSTRING pfxName;
    unsigned char dScriptEnd;
    zSTRING instance;
    int actVolume;
    int actRate;
    int actPan;
    zCWaveData* wav;

    void zCSndFrame_OnInit()      zCall( 0x004EB470 );
    zCSndFrame()                  zInit( zCSndFrame_OnInit() );
    ~zCSndFrame()                 zCall( 0x004EB630 );
    void CalcPitchOffset( float ) zCall( 0x004EB810 );
    int CalcPitchVariance()       zCall( 0x004EB8A0 );
    void SetDefaultProperties()   zCall( 0x004EB930 );
    void CacheIn()                zCall( 0x004EB9E0 );
    void CacheOut()               zCall( 0x004EBA60 );

    // user API
    #include "zCSndFrame.inl"
  };

  class zCWaveData {
  public:
    int size;
    void* memAddr;
    float msLength;
    void* info;
    zSTRING fileName;
    int refCtr;
    int cacheInCount;
    int adpcmCompressed;

    void zCWaveData_OnInit()           zCall( 0x004E7A80 );
    void zCWaveData_OnInit( zSTRING& ) zCall( 0x004ECEA0 );
    zCWaveData()                       zInit( zCWaveData_OnInit() );
    zSTRING GetName()                  zCall( 0x004E7BE0 );
    zCWaveData( zSTRING& a0 )          zInit( zCWaveData_OnInit( a0 ));
    ~zCWaveData()                      zCall( 0x004ED0B0 );
    void Init()                        zCall( 0x004ED240 );
    void CacheIn()                     zCall( 0x004ED320 );
    void CacheOut()                    zCall( 0x004ED940 );
    int CheckForCorrectFormat( int )   zCall( 0x004ED990 );
    int Release()                      zCall( 0x004EDC40 );
    int GetSize()                      zCall( 0x004EDC90 );

    // user API
    #include "zCWaveData.inl"
  };

  class zCSndSys_MSS : public zCSoundSystem {
  public:
    zTSpeakerType speakerType;
    int globalReverbPreset;
    int m_bReverbEnabled;

    void zCSndSys_MSS_OnInit()                                                              zCall( 0x004DD530 );
    zCSndSys_MSS()                                                                          zInit( zCSndSys_MSS_OnInit() );
    void InitializeMSS()                                                                    zCall( 0x004DE2B0 );
    void* GetDigitalDriverHandle()                                                          zCall( 0x004DF1A0 );
    void SetNumAudioChannels( int )                                                         zCall( 0x004E0110 );
    int GetNumSoundsPlaying()                                                               zCall( 0x004E0170 );
    void RemoveAllActiveSounds()                                                            zCall( 0x004E01A0 );
    void DisposeAllSampleHandles()                                                          zCall( 0x004E01E0 );
    void MuteSFX()                                                                          zCall( 0x004E0340 );
    zCSoundFX* LoadMulti( zSTRING const&, int )                                             zCall( 0x004E1050 );
    zCSoundFX* LoadSingle( zSTRING const& )                                                 zCall( 0x004E1A90 );
    int PlaySound3DAmbient( zCSoundFX*, zCVob*, int, zCSoundSystem::zTSound3DParams* )      zCall( 0x004E3FE0 );
    void UpdateSoundPropsAmbient( zCActiveSnd*, zCSoundSystem::zTSound3DParams* )           zCall( 0x004E53C0 );
    float GetActiveVolume( int const& )                                                     zCall( 0x004E5950 );
    int GetUsedSoundMem()                                                                   zCall( 0x004E6140 );
    int Start3DProvider( int )                                                              zCall( 0x004E6260 );
    static int EvalFunc( zSTRING const&, zSTRING& )                                         zCall( 0x004DF1B0 );
    static void FrmCon_ParamChanged( zSTRING const& )                                       zCall( 0x004DFCC0 );
    static void SfxCon_ParamChanged( zSTRING const& )                                       zCall( 0x004DFFF0 );
    static void CloseProvider()                                                             zCall( 0x004E0000 );
    virtual ~zCSndSys_MSS()                                                                 zCall( 0x004DDFF0 );
    virtual zCSoundFX* LoadSoundFX( zSTRING const& )                                        zCall( 0x004E0370 );
    virtual zCSoundFX* LoadSoundFXScript( zSTRING const& )                                  zCall( 0x004E0B50 );
    virtual zCParser* GetSFXParser()                                                        zCall( 0x004E6130 );
    virtual float GetPlayingTimeMSEC( zSTRING const& )                                      zCall( 0x004E5FA0 );
    virtual void SetMasterVolume( float )                                                   zCall( 0x004E02E0 );
    virtual float GetMasterVolume()                                                         zCall( 0x004E0130 );
    virtual int PlaySound( zCSoundFX*, int )                                                zCall( 0x004E2140 );
    virtual int PlaySound( zCSoundFX*, int, int, float, float )                             zCall( 0x004E3220 );
    virtual int PlaySound3D( zCSoundFX*, zCVob*, int, zCSoundSystem::zTSound3DParams* )     zCall( 0x004E37D0 );
    virtual int PlaySound3D( zSTRING const&, zCVob*, int, zCSoundSystem::zTSound3DParams* ) zCall( 0x004E3740 );
    virtual void StopSound( int const& )                                                    zCall( 0x004E4610 );
    virtual void StopAllSounds()                                                            zCall( 0x004E46D0 );
    virtual int GetSound3DProps( int const&, zCSoundSystem::zTSound3DParams& )              zCall( 0x004E5830 );
    virtual int UpdateSound3D( int const&, zCSoundSystem::zTSound3DParams* )                zCall( 0x004E4700 );
    virtual void GetSoundProps( int const&, int&, float&, float& )                          zCall( 0x004E5630 );
    virtual void UpdateSoundProps( int const&, int, float, float )                          zCall( 0x004E5A20 );
    virtual int IsSoundActive( int const& )                                                 zCall( 0x004E5E90 );
    virtual void DoSoundUpdate()                                                            zCall( 0x004E5C80 );
    virtual void SetListener( zCVob* )                                                      zCall( 0x004E0280 );
    virtual void SetGlobalReverbPreset( int, float )                                        zCall( 0x004E6150 );
    virtual void SetReverbEnabled( int )                                                    zCall( 0x004E61F0 );
    virtual int GetReverbEnabled()                                                          zCall( 0x004DDF70 );
    virtual int GetNumProvider()                                                            zCall( 0x004E6200 );
    virtual zSTRING const* GetProviderName( int )                                           zCall( 0x004E6230 );
    virtual int SetProvider( int )                                                          zCall( 0x004E6250 );
    virtual void SetSpeakerType( zCSoundSystem::zTSpeakerType )                             zCall( 0x004E69B0 );
    virtual zCSoundSystem::zTSpeakerType GetSpeakerType()                                   zCall( 0x004DDF80 );
    virtual void SetGlobalOcclusion( float )                                                zCall( 0x004E6980 );
    virtual float GetCPULoad()                                                              zCall( 0x004E6990 );

    // static properties
    static zCDrvProperties_MSS& prefs;

    // user API
    #include "zCSndSys_MSS.inl"
  };

  class zCSndFX_MSS : public zCSoundFX {
  public:
    float volume;
    float pan;
    int rate;
    int autoDelete;
    float startPlayTime;
    int actChannel;
    int actFrame;
    int actChannelFrame;
    zCArray<zCSndChannel*> channelList;

    void zCSndFX_MSS_OnInit()                      zCall( 0x004E6B10 );
    zCSndFX_MSS()                                  zInit( zCSndFX_MSS_OnInit() );
    void LoadChannel( int )                        zCall( 0x004E6D50 );
    void SetDefaultProperties()                    zCall( 0x004E76D0 );
    int IsActive()                                 zCall( 0x004E8040 );
    void CheckCanBeCachedOut()                     zCall( 0x004E81E0 );
    void CacheInActFrame()                         zCall( 0x004E8460 );
    void CacheOutActFrame()                        zCall( 0x004E84F0 );
    void CacheInActChannel()                       zCall( 0x004E8540 );
    void CacheOutActChannel()                      zCall( 0x004E8580 );
    void ChooseVariance()                          zCall( 0x004E8600 );
    static void NewFrame()                         zCall( 0x004E8290 );
    virtual ~zCSndFX_MSS()                         zCall( 0x004E6B90 );
    virtual int LoadResourceData()                 zCall( 0x004E7720 );
    virtual int ReleaseResourceData()              zCall( 0x004E7D50 );
    virtual unsigned long GetResSizeBytes()        zCall( 0x004E8130 );
    virtual int GetNumChannels() const             zCall( 0x004E0AF0 );
    virtual int GetNumChannelFrames( int ) const   zCall( 0x004E0B00 );
    virtual void GetChannelFrame( int, int ) const zCall( 0x004E83D0 );
    virtual void SetChannelFrame( int, int )       zCall( 0x004E83E0 );
    virtual float GetPlayingTimeMSEC() const       zCall( 0x004E80E0 );
    virtual float GetPan() const                   zCall( 0x004E0B10 );
    virtual void SetPan( float )                   zCall( 0x004E7580 );
    virtual float GetVolume() const                zCall( 0x004E0B20 );
    virtual void SetVolume( float )                zCall( 0x004E7650 );
    virtual int GetFrequency() const               zCall( 0x004E0B30 );
    virtual void SetFrequency( int )               zCall( 0x004E74D0 );
    virtual void SetLooping( int )                 zCall( 0x004E8380 );
    virtual int IsLooping() const                  zCall( 0x004E0B40 );

    // user API
    #include "zCSndFX_MSS.inl"
  };

  class zCHandleManager {
  public:
    zCArray<void*>free3DSamples;
    zCArray<void*>freeSamples;

    void zCHandleManager_OnInit() zCall( 0x004DD470 );
    ~zCHandleManager()            zCall( 0x004DD410 );
    zCHandleManager()             zInit( zCHandleManager_OnInit() );
    void* Alloc3DSample()         zCall( 0x004EDCB0 );
    void* AllocSample()           zCall( 0x004EDCE0 );
    void Free3DSample( void* )    zCall( 0x004EDD20 );
    void FreeSample( void* )      zCall( 0x004EDE10 );
    void DisposeAllSamples()      zCall( 0x004EDF00 );

    // user API
    #include "zCHandleManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZSND_MSS_H__VER0__