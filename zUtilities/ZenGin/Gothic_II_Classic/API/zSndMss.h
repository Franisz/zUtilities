// Supported with union (c) 2018-2021 Union team

#ifndef __ZSND_MSS_H__VER2__
#define __ZSND_MSS_H__VER2__

#include "z3d.h"
#include "zDisk.h"
#include "zSound.h"
#include "zParser.h"

namespace Gothic_II_Classic {
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

    void zCDrvProperties_MSS_OnInit() zCall( 0x004E7570 );
    zCDrvProperties_MSS()             zInit( zCDrvProperties_MSS_OnInit() );
    ~zCDrvProperties_MSS()            zCall( 0x004E7600 );

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

  // sizeof 18h
  class zCSndChannel {
  public:
    int actFrame;                   // sizeof 04h    offset 00h
    int refCtr;                     // sizeof 04h    offset 04h
    int loaded;                     // sizeof 04h    offset 08h
    zCArray<zCSndFrame*> frameList; // sizeof 0Ch    offset 0Ch

    void zCSndChannel_OnInit() zCall( 0x004F6A30 );
    zCSndChannel()             zInit( zCSndChannel_OnInit() );
    ~zCSndChannel()            zCall( 0x004F6A50 );

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

  // sizeof 14h
  class zCSndSys_MSS : public zCSoundSystem {
  public:
    zTSpeakerType speakerType; // sizeof 04h    offset 08h
    int globalReverbPreset;    // sizeof 04h    offset 0Ch
    int m_bReverbEnabled;      // sizeof 04h    offset 10h

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

  // sizeof 18h
  class zCHandleManager {
  public:
    zCArray<void*>free3DSamples; // sizeof 0Ch    offset 00h
    zCArray<void*>freeSamples;   // sizeof 0Ch    offset 0Ch

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