// Supported with union (c) 2018 Union team

#ifndef __ZZONE_H__VER0__
#define __ZZONE_H__VER0__

namespace Gothic_I_Classic {
  const int DIMENSION=3;

  class zCBBox3DSorterBase {
  public:

    class zTBoxSortHandle {
    public:
      zCBBox3DSorterBase* mySorter;
      zTBBox3D bbox3D;
      int indexBegin[DIMENSION];
      int indexEnd[DIMENSION];

      void zTBoxSortHandle_OnInit()   zCall( 0x005F28A0 );
      zTBoxSortHandle()               zInit( zTBoxSortHandle_OnInit() );
      virtual ~zTBoxSortHandle()      zCall( 0x0060A9B0 );
      virtual void AddActive( void* ) zPureCall;
      virtual void DelActive( void* ) zPureCall;
      virtual void ClearActive()      zCall( 0x005F2930 );

      // user API
      #include "zCBBox3DSorterBase_zTBoxSortHandle.inl"
    };

    class zTNode {
    public:
      int isBegin;
      void* data;

      zTNode() {}

      // user API
      #include "zCBBox3DSorterBase_zTNode.inl"
    };

    zCArray<zTBoxSortHandle*> handles;
    zCArraySort<zTNode*> nodeList[DIMENSION];
    int sorted;

    void zCBBox3DSorterBase_OnInit()                           zCall( 0x0060AA00 );
    zCBBox3DSorterBase()                                       zInit( zCBBox3DSorterBase_OnInit() );
    void Clear()                                               zCall( 0x0060AC30 );
    void AllocAbs( int )                                       zCall( 0x0060ACB0 );
    void Insert( void* )                                       zCall( 0x0060AD40 );
    void Remove( void* )                                       zCall( 0x0060AEC0 );
    void GetActiveList( zTBBox3D const&, zTBoxSortHandle& )    zCall( 0x0060AF80 );
    void UpdateActiveList( zTBBox3D const&, zTBoxSortHandle& ) zCall( 0x0060B2D0 );
    void InsertHandle( zTBoxSortHandle& )                      zCall( 0x0060B5B0 );
    void RemoveHandle( zTBoxSortHandle& )                      zCall( 0x0060B6B0 );
    void Sort()                                                zCall( 0x0060B700 );
    void AdjustSorting( zCArraySort<zTNode*>&, int )           zCall( 0x0060B740 );
    void Update( void* )                                       zCall( 0x0060B8C0 );
    static int ArrayCompare( void const*, void const* )        zCall( 0x0060AB30 );
    virtual ~zCBBox3DSorterBase( void )                        zCall( 0x0060AAA0 );
    virtual const zTBBox3D& GetBBox( const zTNode* )           zPureCall;

    static zCBBox3DSorterBase*& s_currentSorter;
    static int& s_currentDimension;

    // user API
    #include "zCBBox3DSorterBase.inl"
  };

  class zCZone : public zCVob {
  public:
    zCLASS_DECLARATION( zCZone )

    zCWorld* world;

    void zCZone_OnInit()                                                                               zCall( 0x0060BA20 );
    zCZone()                                                                                           zInit( zCZone_OnInit() );
    float GetCamPosWeight()                                                                            zCall( 0x0060BB90 );
    void SetZoneVobFlags()                                                                             zCall( 0x0060BD50 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x00609030 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0060BD80 );
    virtual ~zCZone( void )                                                                            zCall( 0x0060BAC0 );
    virtual void EndMovement( void )                                                                   zCall( 0x0060BB70 );
    virtual void SetVisual( zCVisual* )                                                                zCall( 0x00607670 );
    virtual void SetVisual( zSTRING const& )                                                           zCall( 0x00607680 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                       zCall( 0x0060BB30 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                                   zCall( 0x0060BB50 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x00609040 );
    virtual zCClassDef* GetZoneMotherClass( void ) const                                               zCall( 0x00607690 );
    virtual zCClassDef* GetDefaultZoneClass( void ) const                                              zCall( 0x00609050 );
    virtual zSTRING GetDebugDescString( void )                                                         zCall( 0x0060BDC0 );

    // user API
    #include "zCZone.inl"
  };

  class zCZoneZFog : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneZFog )

    float fogRangeCenter;
    float innerRangePerc;
    zCOLOR fogColor;

    void zCZoneZFog_OnInit()                                                                           zCall( 0x0060BEF0 );
    zCZoneZFog()                                                                                       zInit( zCZoneZFog_OnInit() );
    float GetActiveRange( float )                                                                      zCall( 0x0060C030 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x0060A030 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x0060A130 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x0060C180 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0060C1F0 );
    virtual ~zCZoneZFog( void )                                                                        zCall( 0x0060BFC0 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x0060C090 );
    virtual zCClassDef* GetDefaultZoneClass( void ) const                                              zCall( 0x0060C080 );

    // user API
    #include "zCZoneZFog.inl"
  };

  class zCZoneZFogDefault : public zCZoneZFog {
  public:
    zCLASS_DECLARATION( zCZoneZFogDefault )

    zCZoneZFogDefault() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x0060A330 );
    virtual zCClassDef* _GetClassDef( void ) const                      zCall( 0x006076E0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0060C2C0 );
    virtual ~zCZoneZFogDefault( void )                                  zCall( 0x006088C0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                        zCall( 0x0060C290 );

    // user API
    #include "zCZoneZFogDefault.inl"
  };

  class zCZoneReverb : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneReverb )

    int reverbPresetNr;
    float reverbPresetWeight;
    float innerRangePerc;

    void zCZoneReverb_OnInit()                                                                         zCall( 0x0060E820 );
    zCZoneReverb()                                                                                     zInit( zCZoneReverb_OnInit() );
    float GetActiveWeight()                                                                            zCall( 0x0060EAD0 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x00608F60 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x00609080 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x0060EC40 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0060EEB0 );
    virtual ~zCZoneReverb( void )                                                                      zCall( 0x0060E8E0 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x0060EB30 );
    virtual zCClassDef* GetDefaultZoneClass( void ) const                                              zCall( 0x0060EB20 );
    virtual zSTRING GetDebugDescString( void )                                                         zCall( 0x0060E950 );

    // user API
    #include "zCZoneReverb.inl"
  };

  class zCZoneReverbDefault : public zCZoneReverb {
  public:
    zCLASS_DECLARATION( zCZoneReverbDefault )

    zCZoneReverbDefault() {}
    static zCObject* _CreateNewInstance()                                                              zCall( 0x00609280 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x00609370 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0060EFA0 );
    virtual ~zCZoneReverbDefault( void )                                                               zCall( 0x006093C0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                       zCall( 0x0060EF60 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x00609380 );

    // user API
    #include "zCZoneReverbDefault.inl"
  };

  class zCZoneMusic : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneMusic )

    zCZoneMusic() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x00609CA0 );
    static int SetAutochange( int )                                     zCall( 0x0060F070 );
    static void GetAutochange( int* )                                   zCall( 0x0060F090 );
    virtual zCClassDef* _GetClassDef( void ) const                      zCall( 0x00609D90 );
    virtual ~zCZoneMusic( void )                                        zCall( 0x00609DD0 );


    static int& s_autochange;
    static int& s_canruleautochange;

    // user API
    #include "zCZoneMusic.inl"
  };

  class zCZoneVobFarPlane : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneVobFarPlane )

    float vobFarZ;
    float innerRangePerc;

    void zCZoneVobFarPlane_OnInit()                                                                    zCall( 0x0060C380 );
    zCZoneVobFarPlane()                                                                                zInit( zCZoneVobFarPlane_OnInit() );
    float GetActiveFarZ( float )                                                                       zCall( 0x0060C4B0 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x00609620 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x00609710 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x0060C600 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0060C660 );
    virtual ~zCZoneVobFarPlane( void )                                                                 zCall( 0x0060C440 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x0060C510 );
    virtual zCClassDef* GetDefaultZoneClass( void ) const                                              zCall( 0x0060C500 );

    // user API
    #include "zCZoneVobFarPlane.inl"
  };

  class zCZoneVobFarPlaneDefault : public zCZoneVobFarPlane {
  public:
    zCLASS_DECLARATION( zCZoneVobFarPlaneDefault )

    zCZoneVobFarPlaneDefault() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x00609910 );
    virtual zCClassDef* _GetClassDef( void ) const                      zCall( 0x00609A00 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0060C750 );
    virtual ~zCZoneVobFarPlaneDefault( void )                           zCall( 0x00609A40 );
    virtual void ThisVobAddedToWorld( zCWorld* )                        zCall( 0x0060C700 );

    // user API
    #include "zCZoneVobFarPlaneDefault.inl"
  };

  class zCVobSound : public zCZone {
  public:
    zCLASS_DECLARATION( zCVobSound )

    enum zTSoundVolType {
      SV_SPHERE = 0,
      SV_ELLIPSOID
    };

    enum zTSoundMode {
      SM_LOOPING,
      SM_ONCE,
      SM_RANDOM
    };

    zSTRING soundName;
    float soundRadius;
    zTSoundMode soundMode;
    group {
      unsigned char soundStartOn        : 1;
      unsigned char soundIsRunning      : 1;
      unsigned char soundIsAmbient3D    : 1;
      unsigned char soundHasObstruction : 1;
      unsigned char soundVolType        : 1;
      unsigned char soundAllowedToRun   : 1;
      unsigned char soundAutoStart      : 1;
    };
    float soundRandDelay;
    float soundRandDelayVar;
    float soundVolume;
    float soundConeAngle;
    zCSoundFX* sfx;
    int sfxHandle;
    float soundRandTimer;
    float obstruction0;
    float obstruction1;
    float obstructionFrameTime;

    void zCVobSound_OnInit()                                                                           zCall( 0x0060C820 );
    zCVobSound()                                                                                       zInit( zCVobSound_OnInit() );
    void SetSound( zSTRING const& )                                                                    zCall( 0x0060CF50 );
    zCSoundFX* LoadSound( zSTRING const& )                                                             zCall( 0x0060D090 );
    void SetSoundVolume( float )                                                                       zCall( 0x0060D0D0 );
    void SetSoundRadius( float )                                                                       zCall( 0x0060D0E0 );
    float CalcObstruction()                                                                            zCall( 0x0060D160 );
    float CalcVolumeScale()                                                                            zCall( 0x0060D2C0 );
    void StartSound( int )                                                                             zCall( 0x0060D520 );
    void StopSound()                                                                                   zCall( 0x0060D6B0 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x0060A620 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x0060CA60 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x0060D8B0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0060DA20 );
    virtual ~zCVobSound( void )                                                                        zCall( 0x0060CAA0 );
    virtual void OnTrigger( zCVob*, zCVob* )                                                           zCall( 0x0060D830 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                                         zCall( 0x0060D850 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                                  zCall( 0x0060D8A0 );
    virtual void EndMovement( void )                                                                   zCall( 0x0060CEC0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                       zCall( 0x0060DE90 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                                   zCall( 0x0060DEB0 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x0060DDB0 );
    virtual zSTRING GetDebugDescString( void )                                                         zCall( 0x0060CBB0 );
    virtual void DoSoundUpdate( float )                                                                zCall( 0x0060D6F0 );

    // user API
    #include "zCVobSound.inl"
  };

  class zCVobSoundDaytime : public zCVobSound {
  public:
    zCLASS_DECLARATION( zCVobSoundDaytime )

    float soundStartTime;
    float soundEndTime;
    zSTRING soundName2;
    zCSoundFX* sfx2;
    int activeSection;

    void zCVobSoundDaytime_OnInit()                                     zCall( 0x0060DF10 );
    zCVobSoundDaytime()                                                 zInit( zCVobSoundDaytime_OnInit() );
    void ActivateSection( int )                                         zCall( 0x0060E240 );
    int CalcTimeFrac( float, float, float, float& )                     zCall( 0x0060E320 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0060A8A0 );
    virtual zCClassDef* _GetClassDef( void ) const                      zCall( 0x0060A990 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0060E6D0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0060E740 );
    virtual ~zCVobSoundDaytime( void )                                  zCall( 0x0060DFA0 );
    virtual zCClassDef* GetZoneMotherClass( void ) const                zCall( 0x0060A9A0 );
    virtual zSTRING GetDebugDescString( void )                          zCall( 0x0060E120 );
    virtual void DoSoundUpdate( float )                                 zCall( 0x0060E3B0 );

    // user API
    #include "zCVobSoundDaytime.inl"
  };

} // namespace Gothic_I_Classic

#include "zBVolume_Util.h"

#endif // __ZZONE_H__VER0__