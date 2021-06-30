// Supported with union (c) 2018 Union team

#ifndef __ZSND_MSS_H__VER3__
#define __ZSND_MSS_H__VER3__

#include "z3d.h"
#include "zDisk.h"
#include "zTools.h"
#include "zSound.h"
#include "zParser.h"

namespace Gothic_II_Addon {
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

    void zCDrvProperties_MSS_OnInit() zCall( 0x004EA080 );
    zCDrvProperties_MSS()             zInit( zCDrvProperties_MSS_OnInit() );
    ~zCDrvProperties_MSS()            zCall( 0x004EA110 );

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

    void zCActiveSnd_OnInit()                             zCall( 0x004F68F0 );
    zCActiveSnd()                                         zInit( zCActiveSnd_OnInit() );
    ~zCActiveSnd()                                        zCall( 0x004F6900 );
    void Release()                                        zCall( 0x004F6B30 );
    void Initialize()                                     zCall( 0x004F6BB0 );
    int CalcListenerPan()                                 zCall( 0x004F7AE0 );
    int CalcListenerVolume()                              zCall( 0x004F7AF0 );
    int RequestChannel()                                  zCall( 0x004F7BC0 );
    int RequestChannel3D()                                zCall( 0x004F7EA0 );
    float GetVolume()                                     zCall( 0x004F81D0 );
    int HasBeenUpdatedThisFrame()                         zCall( 0x004F9680 );
    void AutoCalcObstruction( int )                       zCall( 0x004F9830 );
    static int GetNextFreeHandle()                        zCall( 0x004F6980 );
    static zCActiveSnd* AllocNextFreeSnd()                zCall( 0x004F6990 );
    static int GetHandleIndex( int )                      zCall( 0x004F6C30 );
    static int GetHandleActive( int )                     zCall( 0x004F6D70 );
    static int GetSoundActive( zCActiveSnd* )             zCall( 0x004F6E70 );
    static int GetFrameActive( zCSndFrame* )              zCall( 0x004F6F00 );
    static zCActiveSnd* GetHandleSound( int )             zCall( 0x004F6F40 );
    static void AddSound( zCActiveSnd* )                  zCall( 0x004F6FF0 );
    static void RemoveSound( zCActiveSnd* )               zCall( 0x004F71A0 );
    static void RemoveSoundsByFrame( zCSndFrame* )        zCall( 0x004F7400 );
    static void RemoveSoundByVobSlot( zCVob const*, int ) zCall( 0x004F7440 );
    static void StopSoundsByFrame( zCSndFrame* )          zCall( 0x004F7490 );
    static void ResumeSoundsByFrame( zCSndFrame* )        zCall( 0x004F74F0 );
    static void UpdateSoundsByFrame( zCSndFrame* )        zCall( 0x004F7540 );
    static int GetNumActive()                             zCall( 0x004F7850 );
    static void NewFrame()                                zCall( 0x004F7860 );
    static void UpdateReverb( float )                     zCall( 0x004F7A80 );
    static int GetNum3DSamplesUsed()                      zCall( 0x004F7B40 );
    static int GetNumAmbientSamplesUsed()                 zCall( 0x004F7B80 );
    static void DebugInfo()                               zCall( 0x004F83D0 );
    static void InitPreAllocedData()                      zCall( 0x004F9490 );
    static void CleanupPreAllocedData()                   zCall( 0x004F95C0 );

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

    void zCSndChannel_OnInit() zCall( 0x004F96B0 );
    zCSndChannel()             zInit( zCSndChannel_OnInit() );
    ~zCSndChannel()            zCall( 0x004F96D0 );

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

    void zCSndFrame_OnInit()      zCall( 0x004F9A30 );
    zCSndFrame()                  zInit( zCSndFrame_OnInit() );
    ~zCSndFrame()                 zCall( 0x004F9BF0 );
    void CalcPitchOffset( float ) zCall( 0x004F9DC0 );
    int CalcPitchVariance()       zCall( 0x004F9E50 );
    void SetDefaultProperties()   zCall( 0x004F9EE0 );
    void CacheIn()                zCall( 0x004F9F90 );
    void CacheOut()               zCall( 0x004FA010 );

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

    void zCWaveData_OnInit()           zCall( 0x004F5D10 );
    void zCWaveData_OnInit( zSTRING& ) zCall( 0x004FB520 );
    zCWaveData()                       zInit( zCWaveData_OnInit() );
    zSTRING GetName()                  zCall( 0x004F5E70 );
    zCWaveData( zSTRING& a0 )          zInit( zCWaveData_OnInit( a0 ));
    ~zCWaveData()                      zCall( 0x004FB730 );
    void Init()                        zCall( 0x004FB8C0 );
    void CacheIn()                     zCall( 0x004FB9A0 );
    void CacheOut()                    zCall( 0x004FBF90 );
    int CheckForCorrectFormat( int )   zCall( 0x004FBFE0 );
    int Release()                      zCall( 0x004FC290 );
    int GetSize()                      zCall( 0x004FC2E0 );

    // user API
    #include "zCWaveData.inl"
  };

  class zCSndSys_MSS : public zCSoundSystem {
  public:
    zTSpeakerType speakerType;
    int globalReverbPreset;
    int m_bReverbEnabled;

    void zCSndSys_MSS_OnInit()                                                              zCall( 0x004EAAF0 );
    zCSndSys_MSS()                                                                          zInit( zCSndSys_MSS_OnInit() );
    void InitializeMSS()                                                                    zCall( 0x004EB830 );
    void* GetDigitalDriverHandle()                                                          zCall( 0x004EC700 );
    void SetNumAudioChannels( int )                                                         zCall( 0x004ED710 );
    int GetNumSoundsPlaying()                                                               zCall( 0x004ED770 );
    void RemoveAllActiveSounds()                                                            zCall( 0x004ED7A0 );
    void DisposeAllSampleHandles()                                                          zCall( 0x004ED7E0 );
    void MuteSFX()                                                                          zCall( 0x004ED930 );
    zCSoundFX* LoadMulti( zSTRING const&, int )                                             zCall( 0x004EE640 );
    zCSoundFX* LoadSingle( zSTRING const& )                                                 zCall( 0x004EF0E0 );
    int PlaySound3DAmbient( zCSoundFX*, zCVob*, int, zCSoundSystem::zTSound3DParams* )      zCall( 0x004F1B10 );
    void UpdateSoundPropsAmbient( zCActiveSnd*, zCSoundSystem::zTSound3DParams* )           zCall( 0x004F31F0 );
    float GetActiveVolume( int const& )                                                     zCall( 0x004F38A0 );
    int GetUsedSoundMem()                                                                   zCall( 0x004F4280 );
    int Start3DProvider( int )                                                              zCall( 0x004F43E0 );
    static int EvalFunc( zSTRING const&, zSTRING& )                                         zCall( 0x004EC710 );
    static void FrmCon_ParamChanged( zSTRING const& )                                       zCall( 0x004ED2C0 );
    static void SfxCon_ParamChanged( zSTRING const& )                                       zCall( 0x004ED5F0 );
    static void CloseProvider()                                                             zCall( 0x004ED600 );
    virtual ~zCSndSys_MSS()                                                                 zCall( 0x004EB570 );
    virtual zCSoundFX* LoadSoundFX( zSTRING const& )                                        zCall( 0x004ED960 );
    virtual zCSoundFX* LoadSoundFXScript( zSTRING const& )                                  zCall( 0x004EE120 );
    virtual zCParser* GetSFXParser()                                                        zCall( 0x004F4270 );
    virtual float GetPlayingTimeMSEC( zSTRING const& )                                      zCall( 0x004F40E0 );
    virtual void SetMasterVolume( float )                                                   zCall( 0x004ED8E0 );
    virtual float GetMasterVolume()                                                         zCall( 0x004ED730 );
    virtual int PlaySound( zCSoundFX*, int )                                                zCall( 0x004EF7B0 );
    virtual int PlaySound( zCSoundFX*, int, int, float, float )                             zCall( 0x004F0B70 );
    virtual int PlaySound3D( zCSoundFX*, zCVob*, int, zCSoundSystem::zTSound3DParams* )     zCall( 0x004F10F0 );
    virtual int PlaySound3D( zSTRING const&, zCVob*, int, zCSoundSystem::zTSound3DParams* ) zCall( 0x004F1060 );
    virtual void StopSound( int const& )                                                    zCall( 0x004F2300 );
    virtual void StopAllSounds()                                                            zCall( 0x004F23C0 );
    virtual int GetSound3DProps( int const&, zCSoundSystem::zTSound3DParams& )              zCall( 0x004F3780 );
    virtual int UpdateSound3D( int const&, zCSoundSystem::zTSound3DParams* )                zCall( 0x004F2410 );
    virtual void GetSoundProps( int const&, int&, float&, float& )                          zCall( 0x004F3580 );
    virtual void UpdateSoundProps( int const&, int, float, float )                          zCall( 0x004F3970 );
    virtual int IsSoundActive( int const& )                                                 zCall( 0x004F3FD0 );
    virtual void DoSoundUpdate()                                                            zCall( 0x004F3D60 );
    virtual void SetListener( zCVob* )                                                      zCall( 0x004ED880 );
    virtual void SetGlobalReverbPreset( int, float )                                        zCall( 0x004F4290 );
    virtual void SetReverbEnabled( int )                                                    zCall( 0x004F4350 );
    virtual int GetReverbEnabled()                                                          zCall( 0x004EB4F0 );
    virtual int GetNumProvider()                                                            zCall( 0x004F4380 );
    virtual zSTRING const* GetProviderName( int )                                           zCall( 0x004F43B0 );
    virtual int SetProvider( int )                                                          zCall( 0x004F43D0 );
    virtual void SetSpeakerType( zCSoundSystem::zTSpeakerType )                             zCall( 0x004F4B80 );
    virtual zCSoundSystem::zTSpeakerType GetSpeakerType()                                   zCall( 0x004EB500 );
    virtual void SetGlobalOcclusion( float )                                                zCall( 0x004F4B50 );
    virtual float GetCPULoad()                                                              zCall( 0x004F4B60 );

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

    void zCSndFX_MSS_OnInit()                      zCall( 0x004F4D10 );
    zCSndFX_MSS()                                  zInit( zCSndFX_MSS_OnInit() );
    void LoadChannel( int )                        zCall( 0x004F4F60 );
    void SetDefaultProperties()                    zCall( 0x004F5970 );
    int IsActive()                                 zCall( 0x004F62D0 );
    void CheckCanBeCachedOut()                     zCall( 0x004F6470 );
    void CacheInActFrame()                         zCall( 0x004F66F0 );
    void CacheOutActFrame()                        zCall( 0x004F6780 );
    void CacheInActChannel()                       zCall( 0x004F67D0 );
    void CacheOutActChannel()                      zCall( 0x004F6810 );
    void ChooseVariance()                          zCall( 0x004F6890 );
    static void NewFrame()                         zCall( 0x004F6520 );
    virtual ~zCSndFX_MSS()                         zCall( 0x004F4DA0 );
    virtual int LoadResourceData()                 zCall( 0x004F59C0 );
    virtual int ReleaseResourceData()              zCall( 0x004F5FE0 );
    virtual unsigned long GetResSizeBytes()        zCall( 0x004F63C0 );
    virtual int GetNumChannels() const             zCall( 0x004EE0A0 );
    virtual int GetNumChannelFrames( int ) const   zCall( 0x004EE0B0 );
    virtual void GetChannelFrame( int, int ) const zCall( 0x004F6660 );
    virtual void SetChannelFrame( int, int )       zCall( 0x004F6670 );
    virtual float GetPlayingTimeMSEC() const       zCall( 0x004F6370 );
    virtual float GetPan() const                   zCall( 0x004EE0C0 );
    virtual void SetPan( float )                   zCall( 0x004F5810 );
    virtual float GetVolume() const                zCall( 0x004EE0D0 );
    virtual void SetVolume( float )                zCall( 0x004F58F0 );
    virtual int GetFrequency() const               zCall( 0x004EE0E0 );
    virtual void SetFrequency( int )               zCall( 0x004F5760 );
    virtual void SetLooping( int )                 zCall( 0x004F6610 );
    virtual int IsLooping() const                  zCall( 0x004EE0F0 );
    virtual void SetIsFixed( int )                 zCall( 0x004EE100 );
    virtual int GetIsFixed() const                 zCall( 0x004EE110 );

    // user API
    #include "zCSndFX_MSS.inl"
  };

  class zCHandleManager {
  public:
    zCArray<void*>free3DSamples;
    zCArray<void*>freeSamples;

    void zCHandleManager_OnInit() zCall( 0x004EAA30 );
    ~zCHandleManager()            zCall( 0x004EA9D0 );
    zCHandleManager()             zInit( zCHandleManager_OnInit() );
    void* Alloc3DSample()         zCall( 0x004FC300 );
    void* AllocSample()           zCall( 0x004FC330 );
    void Free3DSample( void* )    zCall( 0x004FC370 );
    void FreeSample( void* )      zCall( 0x004FC440 );
    void DisposeAllSamples()      zCall( 0x004FC520 );

    // user API
    #include "zCHandleManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZSND_MSS_H__VER3__