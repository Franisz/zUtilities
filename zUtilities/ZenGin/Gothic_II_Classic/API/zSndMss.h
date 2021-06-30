// Supported with union (c) 2018 Union team

#ifndef __ZSND_MSS_H__VER2__
#define __ZSND_MSS_H__VER2__

#include "z3d.h"
#include "zDisk.h"
#include "zSound.h"
#include "zParser.h"

namespace Gothic_II_Classic {
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

    void zCDrvProperties_MSS_OnInit() zCall( 0x004E7570 );
    zCDrvProperties_MSS()             zInit( zCDrvProperties_MSS_OnInit() );
    ~zCDrvProperties_MSS()            zCall( 0x004E7600 );

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
    float obstructionToGo;
    float volumeToGo;
    int autoObstructTimer;
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

    void zCActiveSnd_OnInit()                             zCall( 0x004F3C70 );
    zCActiveSnd()                                         zInit( zCActiveSnd_OnInit() );
    ~zCActiveSnd()                                        zCall( 0x004F3C80 );
    void Release()                                        zCall( 0x004F3EB0 );
    void Initialize()                                     zCall( 0x004F3F30 );
    int CalcListenerPan()                                 zCall( 0x004F4E60 );
    int CalcListenerVolume()                              zCall( 0x004F4E70 );
    int RequestChannel()                                  zCall( 0x004F4F40 );
    int RequestChannel3D()                                zCall( 0x004F5220 );
    float GetVolume()                                     zCall( 0x004F5550 );
    int HasBeenUpdatedThisFrame()                         zCall( 0x004F6A00 );
    void AutoCalcObstruction( int )                       zCall( 0x004F6BB0 );
    static int GetNextFreeHandle()                        zCall( 0x004F3D00 );
    static zCActiveSnd* AllocNextFreeSnd()                zCall( 0x004F3D10 );
    static int GetHandleIndex( int )                      zCall( 0x004F3FB0 );
    static int GetHandleActive( int )                     zCall( 0x004F40F0 );
    static int GetSoundActive( zCActiveSnd* )             zCall( 0x004F41F0 );
    static int GetFrameActive( zCSndFrame* )              zCall( 0x004F4280 );
    static zCActiveSnd* GetHandleSound( int )             zCall( 0x004F42C0 );
    static void AddSound( zCActiveSnd* )                  zCall( 0x004F4370 );
    static void RemoveSound( zCActiveSnd* )               zCall( 0x004F4520 );
    static void RemoveSoundsByFrame( zCSndFrame* )        zCall( 0x004F4780 );
    static void RemoveSoundByVobSlot( zCVob const*, int ) zCall( 0x004F47C0 );
    static void StopSoundsByFrame( zCSndFrame* )          zCall( 0x004F4810 );
    static void ResumeSoundsByFrame( zCSndFrame* )        zCall( 0x004F4870 );
    static void UpdateSoundsByFrame( zCSndFrame* )        zCall( 0x004F48C0 );
    static int GetNumActive()                             zCall( 0x004F4BD0 );
    static void NewFrame()                                zCall( 0x004F4BE0 );
    static void UpdateReverb( float )                     zCall( 0x004F4E00 );
    static int GetNum3DSamplesUsed()                      zCall( 0x004F4EC0 );
    static int GetNumAmbientSamplesUsed()                 zCall( 0x004F4F00 );
    static void DebugInfo()                               zCall( 0x004F5750 );
    static void InitPreAllocedData()                      zCall( 0x004F6810 );
    static void CleanupPreAllocedData()                   zCall( 0x004F6940 );

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

    void zCSndChannel_OnInit() zCall( 0x004F6A30 );
    zCSndChannel()             zInit( zCSndChannel_OnInit() );
    ~zCSndChannel()            zCall( 0x004F6A50 );

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

    void zCSndFrame_OnInit()      zCall( 0x004F6DB0 );
    zCSndFrame()                  zInit( zCSndFrame_OnInit() );
    ~zCSndFrame()                 zCall( 0x004F6F70 );
    void CalcPitchOffset( float ) zCall( 0x004F7140 );
    int CalcPitchVariance()       zCall( 0x004F71D0 );
    void SetDefaultProperties()   zCall( 0x004F7260 );
    void CacheIn()                zCall( 0x004F7310 );
    void CacheOut()               zCall( 0x004F7390 );

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

    void zCWaveData_OnInit()           zCall( 0x004F3090 );
    void zCWaveData_OnInit( zSTRING& ) zCall( 0x004F88A0 );
    zCWaveData()                       zInit( zCWaveData_OnInit() );
    zSTRING GetName()                  zCall( 0x004F31F0 );
    zCWaveData( zSTRING& a0 )          zInit( zCWaveData_OnInit( a0 ));
    ~zCWaveData()                      zCall( 0x004F8AB0 );
    void Init()                        zCall( 0x004F8C40 );
    void CacheIn()                     zCall( 0x004F8D20 );
    void CacheOut()                    zCall( 0x004F9310 );
    int CheckForCorrectFormat( int )   zCall( 0x004F9360 );
    int Release()                      zCall( 0x004F9610 );
    int GetSize()                      zCall( 0x004F9660 );

    // user API
    #include "zCWaveData.inl"
  };

  class zCSndSys_MSS : public zCSoundSystem {
  public:
    zTSpeakerType speakerType;
    int globalReverbPreset;
    int m_bReverbEnabled;

    void zCSndSys_MSS_OnInit()                                                              zCall( 0x004E8010 );
    zCSndSys_MSS()                                                                          zInit( zCSndSys_MSS_OnInit() );
    void InitializeMSS()                                                                    zCall( 0x004E8BB0 );
    void* GetDigitalDriverHandle()                                                          zCall( 0x004E9A80 );
    void SetNumAudioChannels( int )                                                         zCall( 0x004EAA90 );
    int GetNumSoundsPlaying()                                                               zCall( 0x004EAAF0 );
    void RemoveAllActiveSounds()                                                            zCall( 0x004EAB20 );
    void DisposeAllSampleHandles()                                                          zCall( 0x004EAB60 );
    void MuteSFX()                                                                          zCall( 0x004EACB0 );
    zCSoundFX* LoadMulti( zSTRING const&, int )                                             zCall( 0x004EB9C0 );
    zCSoundFX* LoadSingle( zSTRING const& )                                                 zCall( 0x004EC460 );
    int PlaySound3DAmbient( zCSoundFX*, zCVob*, int, zCSoundSystem::zTSound3DParams* )      zCall( 0x004EEE90 );
    void UpdateSoundPropsAmbient( zCActiveSnd*, zCSoundSystem::zTSound3DParams* )           zCall( 0x004F0570 );
    float GetActiveVolume( int const& )                                                     zCall( 0x004F0C20 );
    int GetUsedSoundMem()                                                                   zCall( 0x004F1600 );
    int Start3DProvider( int )                                                              zCall( 0x004F1760 );
    static int EvalFunc( zSTRING const&, zSTRING& )                                         zCall( 0x004E9A90 );
    static void FrmCon_ParamChanged( zSTRING const& )                                       zCall( 0x004EA640 );
    static void SfxCon_ParamChanged( zSTRING const& )                                       zCall( 0x004EA970 );
    static void CloseProvider()                                                             zCall( 0x004EA980 );
    virtual ~zCSndSys_MSS()                                                                 zCall( 0x004E88F0 );
    virtual zCSoundFX* LoadSoundFX( zSTRING const& )                                        zCall( 0x004EACE0 );
    virtual zCSoundFX* LoadSoundFXScript( zSTRING const& )                                  zCall( 0x004EB4A0 );
    virtual zCParser* GetSFXParser()                                                        zCall( 0x004F15F0 );
    virtual float GetPlayingTimeMSEC( zSTRING const& )                                      zCall( 0x004F1460 );
    virtual void SetMasterVolume( float )                                                   zCall( 0x004EAC60 );
    virtual float GetMasterVolume()                                                         zCall( 0x004EAAB0 );
    virtual int PlaySound( zCSoundFX*, int )                                                zCall( 0x004ECB30 );
    virtual int PlaySound( zCSoundFX*, int, int, float, float )                             zCall( 0x004EDEF0 );
    virtual int PlaySound3D( zCSoundFX*, zCVob*, int, zCSoundSystem::zTSound3DParams* )     zCall( 0x004EE470 );
    virtual int PlaySound3D( zSTRING const&, zCVob*, int, zCSoundSystem::zTSound3DParams* ) zCall( 0x004EE3E0 );
    virtual void StopSound( int const& )                                                    zCall( 0x004EF680 );
    virtual void StopAllSounds()                                                            zCall( 0x004EF740 );
    virtual int GetSound3DProps( int const&, zCSoundSystem::zTSound3DParams& )              zCall( 0x004F0B00 );
    virtual int UpdateSound3D( int const&, zCSoundSystem::zTSound3DParams* )                zCall( 0x004EF790 );
    virtual void GetSoundProps( int const&, int&, float&, float& )                          zCall( 0x004F0900 );
    virtual void UpdateSoundProps( int const&, int, float, float )                          zCall( 0x004F0CF0 );
    virtual int IsSoundActive( int const& )                                                 zCall( 0x004F1350 );
    virtual void DoSoundUpdate()                                                            zCall( 0x004F10E0 );
    virtual void SetListener( zCVob* )                                                      zCall( 0x004EAC00 );
    virtual void SetGlobalReverbPreset( int, float )                                        zCall( 0x004F1610 );
    virtual void SetReverbEnabled( int )                                                    zCall( 0x004F16D0 );
    virtual int GetReverbEnabled()                                                          zCall( 0x004E8870 );
    virtual int GetNumProvider()                                                            zCall( 0x004F1700 );
    virtual zSTRING const* GetProviderName( int )                                           zCall( 0x004F1730 );
    virtual int SetProvider( int )                                                          zCall( 0x004F1750 );
    virtual void SetSpeakerType( zCSoundSystem::zTSpeakerType )                             zCall( 0x004F1F00 );
    virtual zCSoundSystem::zTSpeakerType GetSpeakerType()                                   zCall( 0x004E8880 );
    virtual void SetGlobalOcclusion( float )                                                zCall( 0x004F1ED0 );
    virtual float GetCPULoad()                                                              zCall( 0x004F1EE0 );

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
    int m_bIsFixed;
    int actChannel;
    int actFrame;
    int actChannelFrame;
    zCArray<zCSndChannel*> channelList;

    void zCSndFX_MSS_OnInit()                      zCall( 0x004F2090 );
    zCSndFX_MSS()                                  zInit( zCSndFX_MSS_OnInit() );
    void LoadChannel( int )                        zCall( 0x004F22E0 );
    void SetDefaultProperties()                    zCall( 0x004F2CF0 );
    int IsActive()                                 zCall( 0x004F3650 );
    void CheckCanBeCachedOut()                     zCall( 0x004F37F0 );
    void CacheInActFrame()                         zCall( 0x004F3A70 );
    void CacheOutActFrame()                        zCall( 0x004F3B00 );
    void CacheInActChannel()                       zCall( 0x004F3B50 );
    void CacheOutActChannel()                      zCall( 0x004F3B90 );
    void ChooseVariance()                          zCall( 0x004F3C10 );
    static void NewFrame()                         zCall( 0x004F38A0 );
    virtual ~zCSndFX_MSS()                         zCall( 0x004F2120 );
    virtual int LoadResourceData()                 zCall( 0x004F2D40 );
    virtual int ReleaseResourceData()              zCall( 0x004F3360 );
    virtual unsigned long GetResSizeBytes()        zCall( 0x004F3740 );
    virtual int GetNumChannels() const             zCall( 0x004EB420 );
    virtual int GetNumChannelFrames( int ) const   zCall( 0x004EB430 );
    virtual void GetChannelFrame( int, int ) const zCall( 0x004F39E0 );
    virtual void SetChannelFrame( int, int )       zCall( 0x004F39F0 );
    virtual float GetPlayingTimeMSEC() const       zCall( 0x004F36F0 );
    virtual float GetPan() const                   zCall( 0x004EB440 );
    virtual void SetPan( float )                   zCall( 0x004F2B90 );
    virtual float GetVolume() const                zCall( 0x004EB450 );
    virtual void SetVolume( float )                zCall( 0x004F2C70 );
    virtual int GetFrequency() const               zCall( 0x004EB460 );
    virtual void SetFrequency( int )               zCall( 0x004F2AE0 );
    virtual void SetLooping( int )                 zCall( 0x004F3990 );
    virtual int IsLooping() const                  zCall( 0x004EB470 );
    virtual void SetIsFixed( int )                 zCall( 0x004EB480 );
    virtual int GetIsFixed() const                 zCall( 0x004EB490 );

    // user API
    #include "zCSndFX_MSS.inl"
  };

  class zCHandleManager {
  public:
    zCArray<void*>free3DSamples;
    zCArray<void*>freeSamples;

    void zCHandleManager_OnInit() zCall( 0x004E7F50 );
    ~zCHandleManager()            zCall( 0x004E7EF0 );
    zCHandleManager()             zInit( zCHandleManager_OnInit() );
    void* Alloc3DSample()         zCall( 0x004F9680 );
    void* AllocSample()           zCall( 0x004F96B0 );
    void Free3DSample( void* )    zCall( 0x004F96F0 );
    void FreeSample( void* )      zCall( 0x004F97C0 );
    void DisposeAllSamples()      zCall( 0x004F98A0 );

    // user API
    #include "zCHandleManager.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZSND_MSS_H__VER2__