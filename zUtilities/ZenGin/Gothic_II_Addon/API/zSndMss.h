// Supported with union (c) 2018-2021 Union team

#ifndef __ZSND_MSS_H__VER3__
#define __ZSND_MSS_H__VER3__

#include "z3d.h"
#include "zDisk.h"
#include "zTools.h"
#include "zSound.h"
#include "zParser.h"

namespace Gothic_II_Addon {
  const int MAX_PROVIDER = 20;

  // sizeof 220h
  class zCDrvProperties_MSS {
  public:
    float volume;                    // sizeof 04h    offset 00h
    int bitResolution;               // sizeof 04h    offset 04h
    int sampleRate;                  // sizeof 04h    offset 08h
    int useStereo;                   // sizeof 04h    offset 0Ch
    int numSFXChannels;              // sizeof 04h    offset 10h
    zSTRING use3dProvider;           // sizeof 14h    offset 14h
    unsigned char dScriptEnd;        // sizeof 01h    offset 28h
    PCMWAVEFORMAT waveFormat;        // sizeof 10h    offset 29h
    long * providers[MAX_PROVIDER];  // sizeof 50h    offset 3Ch
    zSTRING provNames[MAX_PROVIDER]; // sizeof 190h   offset 8Ch
    int numProviders;                // sizeof 04h    offset 21Ch

    void zCDrvProperties_MSS_OnInit() zCall( 0x004EA080 );
    zCDrvProperties_MSS()             zInit( zCDrvProperties_MSS_OnInit() );
    ~zCDrvProperties_MSS()            zCall( 0x004EA110 );

    // user API
    #include "zCDrvProperties_MSS.inl"
  };

  // sizeof 60h
  class zCActiveSnd {
  public:
    int handle;                         // sizeof 04h    offset 00h
    void* sample;                       // sizeof 04h    offset 04h
    void* sample3D;                     // sizeof 04h    offset 08h
    unsigned long age;                  // sizeof 04h    offset 0Ch
    zCSoundSystem::zTLoopType loopType; // sizeof 04h    offset 10h
    float radius;                       // sizeof 04h    offset 14h
    float reverbLevel;                  // sizeof 04h    offset 18h
    float pitchOffset;                  // sizeof 04h    offset 1Ch
    float volWeight;                    // sizeof 04h    offset 20h
    float obstruction;                  // sizeof 04h    offset 24h
    float obstructionToGo;              // sizeof 04h    offset 28h
    float volumeToGo;                   // sizeof 04h    offset 2Ch
    int autoObstructTimer;              // sizeof 04h    offset 30h
    group {
      unsigned char active    : 1;      // sizeof 01h    offset bit
      unsigned char looping   : 1;      // sizeof 01h    offset bit
      unsigned char isAmbient : 1;      // sizeof 01h    offset bit
      unsigned char is3D      : 1;      // sizeof 01h    offset bit
      unsigned char allocated : 1;      // sizeof 01h    offset bit
      unsigned char vobSlot   : 3;      // sizeof 03h    offset bit
    };
    unsigned char pan;                  // sizeof 01h    offset 35h
    unsigned char volume;               // sizeof 01h    offset 36h
    unsigned short rate;                // sizeof 02h    offset 38h
    int muteTime;                       // sizeof 04h    offset 3Ch
    int frameCtr;                       // sizeof 04h    offset 40h
    zVEC3 lastPos;                      // sizeof 0Ch    offset 44h
    float lastTime;                     // sizeof 04h    offset 50h
    zCVob* sourceVob;                   // sizeof 04h    offset 54h
    zCSndFrame* sourceFrm;              // sizeof 04h    offset 58h
    zCSndFX_MSS* sourceSnd;             // sizeof 04h    offset 5Ch

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

  // sizeof 18h
  class zCSndChannel {
  public:
    int actFrame;                   // sizeof 04h    offset 00h
    int refCtr;                     // sizeof 04h    offset 04h
    int loaded;                     // sizeof 04h    offset 08h
    zCArray<zCSndFrame*> frameList; // sizeof 0Ch    offset 0Ch

    void zCSndChannel_OnInit() zCall( 0x004F96B0 );
    zCSndChannel()             zInit( zCSndChannel_OnInit() );
    ~zCSndChannel()            zCall( 0x004F96D0 );

    // user API
    #include "zCSndChannel.inl"
  };

  // sizeof 6Ch
  class zCSndFrame {
  public:
    zSTRING fileName;         // sizeof 14h    offset 00h
    float pitchOffset;        // sizeof 04h    offset 14h
    float pitchVariance;      // sizeof 04h    offset 18h
    int defVolume;            // sizeof 04h    offset 1Ch
    int looping;              // sizeof 04h    offset 20h
    int loopStartOffset;      // sizeof 04h    offset 24h
    int loopEndOffset;        // sizeof 04h    offset 28h
    float reverbLevel;        // sizeof 04h    offset 2Ch
    zSTRING pfxName;          // sizeof 14h    offset 30h
    unsigned char dScriptEnd; // sizeof 01h    offset 44h
    zSTRING instance;         // sizeof 14h    offset 48h
    int actVolume;            // sizeof 04h    offset 5Ch
    int actRate;              // sizeof 04h    offset 60h
    int actPan;               // sizeof 04h    offset 64h
    zCWaveData* wav;          // sizeof 04h    offset 68h

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

  // sizeof 30h
  class zCWaveData {
  public:
    int size;            // sizeof 04h    offset 00h
    void* memAddr;       // sizeof 04h    offset 04h
    float msLength;      // sizeof 04h    offset 08h
    void* info;          // sizeof 04h    offset 0Ch
    zSTRING fileName;    // sizeof 14h    offset 10h
    int refCtr;          // sizeof 04h    offset 24h
    int cacheInCount;    // sizeof 04h    offset 28h
    int adpcmCompressed; // sizeof 04h    offset 2Ch

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

  // sizeof 14h
  class zCSndSys_MSS : public zCSoundSystem {
  public:
    zTSpeakerType speakerType; // sizeof 04h    offset 08h
    int globalReverbPreset;    // sizeof 04h    offset 0Ch
    int m_bReverbEnabled;      // sizeof 04h    offset 10h

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

  // sizeof 84h
  class zCSndFX_MSS : public zCSoundFX {
  public:
    float volume;                       // sizeof 04h    offset 54h
    float pan;                          // sizeof 04h    offset 58h
    int rate;                           // sizeof 04h    offset 5Ch
    int autoDelete;                     // sizeof 04h    offset 60h
    float startPlayTime;                // sizeof 04h    offset 64h
    int m_bIsFixed;                     // sizeof 04h    offset 68h
    int actChannel;                     // sizeof 04h    offset 6Ch
    int actFrame;                       // sizeof 04h    offset 70h
    int actChannelFrame;                // sizeof 04h    offset 74h
    zCArray<zCSndChannel*> channelList; // sizeof 0Ch    offset 78h

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

  // sizeof 18h
  class zCHandleManager {
  public:
    zCArray<void*>free3DSamples; // sizeof 0Ch    offset 00h
    zCArray<void*>freeSamples;   // sizeof 0Ch    offset 0Ch

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