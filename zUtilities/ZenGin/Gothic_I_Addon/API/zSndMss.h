// Supported with union (c) 2018 Union team

#ifndef __ZSND_MSS_H__VER1__
#define __ZSND_MSS_H__VER1__

#include "z3d.h"
#include "zDisk.h"
#include "zSound.h"
#include "zParser.h"

namespace Gothic_I_Addon {
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

    void zCDrvProperties_MSS_OnInit() zCall( 0x004EE230 );
    zCDrvProperties_MSS()             zInit( zCDrvProperties_MSS_OnInit() );
    ~zCDrvProperties_MSS()            zCall( 0x004EE2C0 );

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

    void zCActiveSnd_OnInit()                             zCall( 0x004FA840 );
    zCActiveSnd()                                         zInit( zCActiveSnd_OnInit() );
    ~zCActiveSnd()                                        zCall( 0x004FA850 );
    void Release()                                        zCall( 0x004FABA0 );
    void Initialize()                                     zCall( 0x004FAC20 );
    int CalcListenerPan()                                 zCall( 0x004FBBF0 );
    int CalcListenerVolume()                              zCall( 0x004FBC00 );
    int RequestChannel()                                  zCall( 0x004FBCC0 );
    int RequestChannel3D()                                zCall( 0x004FBFA0 );
    float GetVolume()                                     zCall( 0x004FC2C0 );
    int HasBeenUpdatedThisFrame()                         zCall( 0x004FD800 );
    static int GetNextFreeHandle()                        zCall( 0x004FA8D0 );
    static zCActiveSnd* AllocNextFreeSnd()                zCall( 0x004FA9C0 );
    static int GetHandleIndex( int )                      zCall( 0x004FAC90 );
    static int GetHandleActive( int )                     zCall( 0x004FADF0 );
    static int GetSoundActive( zCActiveSnd* )             zCall( 0x004FAF10 );
    static int GetFrameActive( zCSndFrame* )              zCall( 0x004FAFB0 );
    static zCActiveSnd* GetHandleSound( int )             zCall( 0x004FAFF0 );
    static void AddSound( zCActiveSnd* )                  zCall( 0x004FB0C0 );
    static void RemoveSound( zCActiveSnd* )               zCall( 0x004FB290 );
    static void RemoveSoundsByFrame( zCSndFrame* )        zCall( 0x004FB540 );
    static void RemoveSoundByVobSlot( zCVob const*, int ) zCall( 0x004FB580 );
    static void StopSoundsByFrame( zCSndFrame* )          zCall( 0x004FB5E0 );
    static void ResumeSoundsByFrame( zCSndFrame* )        zCall( 0x004FB640 );
    static void UpdateSoundsByFrame( zCSndFrame* )        zCall( 0x004FB690 );
    static int GetNumActive()                             zCall( 0x004FB9C0 );
    static void NewFrame()                                zCall( 0x004FB9D0 );
    static int GetNum3DSamplesUsed()                      zCall( 0x004FBC60 );
    static int GetNumAmbientSamplesUsed()                 zCall( 0x004FBC90 );
    static void DebugInfo()                               zCall( 0x004FC560 );
    static void InitPreAllocedData()                      zCall( 0x004FD5E0 );
    static void CleanupPreAllocedData()                   zCall( 0x004FD730 );

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

    void zCSndChannel_OnInit() zCall( 0x004FD830 );
    zCSndChannel()             zInit( zCSndChannel_OnInit() );
    ~zCSndChannel()            zCall( 0x004FD850 );

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

    void zCSndFrame_OnInit()      zCall( 0x004FD9B0 );
    zCSndFrame()                  zInit( zCSndFrame_OnInit() );
    ~zCSndFrame()                 zCall( 0x004FDB60 );
    void CalcPitchOffset( float ) zCall( 0x004FDD70 );
    int CalcPitchVariance()       zCall( 0x004FDE00 );
    void SetDefaultProperties()   zCall( 0x004FDE90 );
    void CacheIn()                zCall( 0x004FDF40 );
    void CacheOut()               zCall( 0x004FDFC0 );

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

    void zCWaveData_OnInit()           zCall( 0x004F9C50 );
    void zCWaveData_OnInit( zSTRING& ) zCall( 0x004FF570 );
    zCWaveData()                       zInit( zCWaveData_OnInit() );
    zSTRING GetName()                  zCall( 0x004F9DB0 );
    zCWaveData( zSTRING& a0 )          zInit( zCWaveData_OnInit( a0 ));
    ~zCWaveData()                      zCall( 0x004FF770 );
    void Init()                        zCall( 0x004FF920 );
    void CacheIn()                     zCall( 0x004FFA00 );
    void CacheOut()                    zCall( 0x005000C0 );
    int CheckForCorrectFormat( int )   zCall( 0x00500110 );
    int Release()                      zCall( 0x00500410 );
    int GetSize()                      zCall( 0x00500460 );

    // user API
    #include "zCWaveData.inl"
  };

  class zCSndSys_MSS : public zCSoundSystem {
  public:
    zTSpeakerType speakerType;
    int globalReverbPreset;
    int m_bReverbEnabled;

    void zCSndSys_MSS_OnInit()                                                              zCall( 0x004EEA70 );
    zCSndSys_MSS()                                                                          zInit( zCSndSys_MSS_OnInit() );
    void InitializeMSS()                                                                    zCall( 0x004EF780 );
    void* GetDigitalDriverHandle()                                                          zCall( 0x004F0830 );
    void SetNumAudioChannels( int )                                                         zCall( 0x004F19D0 );
    int GetNumSoundsPlaying()                                                               zCall( 0x004F1A30 );
    void RemoveAllActiveSounds()                                                            zCall( 0x004F1A60 );
    void DisposeAllSampleHandles()                                                          zCall( 0x004F1A90 );
    void MuteSFX()                                                                          zCall( 0x004F1C20 );
    zCSoundFX* LoadMulti( zSTRING const&, int )                                             zCall( 0x004F2AC0 );
    zCSoundFX* LoadSingle( zSTRING const& )                                                 zCall( 0x004F3680 );
    int PlaySound3DAmbient( zCSoundFX*, zCVob*, int, zCSoundSystem::zTSound3DParams* )      zCall( 0x004F5EC0 );
    void UpdateSoundPropsAmbient( zCActiveSnd*, zCSoundSystem::zTSound3DParams* )           zCall( 0x004F73D0 );
    float GetActiveVolume( int const& )                                                     zCall( 0x004F79A0 );
    int GetUsedSoundMem()                                                                   zCall( 0x004F8230 );
    int Start3DProvider( int )                                                              zCall( 0x004F8360 );
    static int EvalFunc( zSTRING const&, zSTRING& )                                         zCall( 0x004F0840 );
    static void FrmCon_ParamChanged( zSTRING const& )                                       zCall( 0x004F1550 );
    static void SfxCon_ParamChanged( zSTRING const& )                                       zCall( 0x004F18A0 );
    static void CloseProvider()                                                             zCall( 0x004F18B0 );
    virtual ~zCSndSys_MSS()                                                                 zCall( 0x004EF4A0 );
    virtual zCSoundFX* LoadSoundFX( zSTRING const& )                                        zCall( 0x004F1C70 );
    virtual zCSoundFX* LoadSoundFXScript( zSTRING const& )                                  zCall( 0x004F2510 );
    virtual zCParser* GetSFXParser()                                                        zCall( 0x004F8220 );
    virtual float GetPlayingTimeMSEC( zSTRING const& )                                      zCall( 0x004F8060 );
    virtual void SetMasterVolume( float )                                                   zCall( 0x004F1BB0 );
    virtual float GetMasterVolume()                                                         zCall( 0x004F19F0 );
    virtual int PlaySound( zCSoundFX*, int )                                                zCall( 0x004F3DE0 );
    virtual int PlaySound( zCSoundFX*, int, int, float, float )                             zCall( 0x004F5040 );
    virtual int PlaySound3D( zCSoundFX*, zCVob*, int, zCSoundSystem::zTSound3DParams* )     zCall( 0x004F5640 );
    virtual int PlaySound3D( zSTRING const&, zCVob*, int, zCSoundSystem::zTSound3DParams* ) zCall( 0x004F55B0 );
    virtual void StopSound( int const& )                                                    zCall( 0x004F6510 );
    virtual void StopAllSounds()                                                            zCall( 0x004F65F0 );
    virtual int GetSound3DProps( int const&, zCSoundSystem::zTSound3DParams& )              zCall( 0x004F7880 );
    virtual int UpdateSound3D( int const&, zCSoundSystem::zTSound3DParams* )                zCall( 0x004F6620 );
    virtual void GetSoundProps( int const&, int&, float&, float& )                          zCall( 0x004F7660 );
    virtual void UpdateSoundProps( int const&, int, float, float )                          zCall( 0x004F7A90 );
    virtual int IsSoundActive( int const& )                                                 zCall( 0x004F7F30 );
    virtual void DoSoundUpdate()                                                            zCall( 0x004F7D20 );
    virtual void SetListener( zCVob* )                                                      zCall( 0x004F1B40 );
    virtual void SetGlobalReverbPreset( int, float )                                        zCall( 0x004F8240 );
    virtual void SetReverbEnabled( int )                                                    zCall( 0x004F82F0 );
    virtual int GetReverbEnabled()                                                          zCall( 0x004EF420 );
    virtual int GetNumProvider()                                                            zCall( 0x004F8300 );
    virtual zSTRING const* GetProviderName( int )                                           zCall( 0x004F8330 );
    virtual int SetProvider( int )                                                          zCall( 0x004F8350 );
    virtual void SetSpeakerType( zCSoundSystem::zTSpeakerType )                             zCall( 0x004F8A80 );
    virtual zCSoundSystem::zTSpeakerType GetSpeakerType()                                   zCall( 0x004EF430 );
    virtual void SetGlobalOcclusion( float )                                                zCall( 0x004F8A50 );
    virtual float GetCPULoad()                                                              zCall( 0x004F8A60 );

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

    void zCSndFX_MSS_OnInit()                      zCall( 0x004F8BE0 );
    zCSndFX_MSS()                                  zInit( zCSndFX_MSS_OnInit() );
    void LoadChannel( int )                        zCall( 0x004F8E20 );
    void SetDefaultProperties()                    zCall( 0x004F9870 );
    int IsActive()                                 zCall( 0x004FA220 );
    void CheckCanBeCachedOut()                     zCall( 0x004FA3C0 );
    void CacheInActFrame()                         zCall( 0x004FA640 );
    void CacheOutActFrame()                        zCall( 0x004FA6D0 );
    void CacheInActChannel()                       zCall( 0x004FA720 );
    void CacheOutActChannel()                      zCall( 0x004FA760 );
    void ChooseVariance()                          zCall( 0x004FA7E0 );
    static void NewFrame()                         zCall( 0x004FA470 );
    virtual ~zCSndFX_MSS()                         zCall( 0x004F8C60 );
    virtual int LoadResourceData()                 zCall( 0x004F98C0 );
    virtual int ReleaseResourceData()              zCall( 0x004F9F20 );
    virtual unsigned long GetResSizeBytes()        zCall( 0x004FA310 );
    virtual int GetNumChannels() const             zCall( 0x004F24B0 );
    virtual int GetNumChannelFrames( int ) const   zCall( 0x004F24C0 );
    virtual void GetChannelFrame( int, int ) const zCall( 0x004FA5B0 );
    virtual void SetChannelFrame( int, int )       zCall( 0x004FA5C0 );
    virtual float GetPlayingTimeMSEC() const       zCall( 0x004FA2C0 );
    virtual float GetPan() const                   zCall( 0x004F24D0 );
    virtual void SetPan( float )                   zCall( 0x004F9710 );
    virtual float GetVolume() const                zCall( 0x004F24E0 );
    virtual void SetVolume( float )                zCall( 0x004F97F0 );
    virtual int GetFrequency() const               zCall( 0x004F24F0 );
    virtual void SetFrequency( int )               zCall( 0x004F9670 );
    virtual void SetLooping( int )                 zCall( 0x004FA560 );
    virtual int IsLooping() const                  zCall( 0x004F2500 );

    // user API
    #include "zCSndFX_MSS.inl"
  };

  class zCHandleManager {
  public:
    zCArray<void*>free3DSamples;
    zCArray<void*>freeSamples;

    void zCHandleManager_OnInit() zCall( 0x004EE9B0 );
    ~zCHandleManager()            zCall( 0x004EE950 );
    zCHandleManager()             zInit( zCHandleManager_OnInit() );
    void* Alloc3DSample()         zCall( 0x00500480 );
    void* AllocSample()           zCall( 0x005004B0 );
    void Free3DSample( void* )    zCall( 0x005004F0 );
    void FreeSample( void* )      zCall( 0x005005E0 );
    void DisposeAllSamples()      zCall( 0x005006E0 );

    // user API
    #include "zCHandleManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZSND_MSS_H__VER1__