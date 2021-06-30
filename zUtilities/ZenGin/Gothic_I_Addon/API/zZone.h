// Supported with union (c) 2018 Union team

#ifndef __ZZONE_H__VER1__
#define __ZZONE_H__VER1__

namespace Gothic_I_Addon {
  const int DIMENSION=3;

  class zCBBox3DSorterBase {
  public:

    class zTBoxSortHandle {
    public:
      zCBBox3DSorterBase* mySorter;
      zTBBox3D bbox3D;
      int indexBegin[DIMENSION];
      int indexEnd[DIMENSION];

      void zTBoxSortHandle_OnInit()   zCall( 0x00613670 );
      zTBoxSortHandle()               zInit( zTBoxSortHandle_OnInit() );
      virtual ~zTBoxSortHandle()      zCall( 0x0062CED0 );
      virtual void AddActive( void* ) zPureCall;
      virtual void DelActive( void* ) zPureCall;
      virtual void ClearActive()      zCall( 0x00613700 );

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

    void zCBBox3DSorterBase_OnInit()                           zCall( 0x0062CF20 );
    zCBBox3DSorterBase()                                       zInit( zCBBox3DSorterBase_OnInit() );
    void Clear()                                               zCall( 0x0062D140 );
    void AllocAbs( int )                                       zCall( 0x0062D1C0 );
    void Insert( void* )                                       zCall( 0x0062D250 );
    void Remove( void* )                                       zCall( 0x0062D3D0 );
    void GetActiveList( zTBBox3D const&, zTBoxSortHandle& )    zCall( 0x0062D4A0 );
    void UpdateActiveList( zTBBox3D const&, zTBoxSortHandle& ) zCall( 0x0062D7E0 );
    void InsertHandle( zTBoxSortHandle& )                      zCall( 0x0062DAD0 );
    void RemoveHandle( zTBoxSortHandle& )                      zCall( 0x0062DBD0 );
    void Sort()                                                zCall( 0x0062DC20 );
    void AdjustSorting( zCArraySort<zTNode*>&, int )           zCall( 0x0062DC60 );
    void Update( void* )                                       zCall( 0x0062DDE0 );
    static int ArrayCompare( void const*, void const* )        zCall( 0x0062D050 );
    virtual ~zCBBox3DSorterBase( void )                        zCall( 0x0062CFC0 );
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

    void zCZone_OnInit()                                                                               zCall( 0x0062DF40 );
    zCZone()                                                                                           zInit( zCZone_OnInit() );
    float GetCamPosWeight()                                                                            zCall( 0x0062E0B0 );
    void SetZoneVobFlags()                                                                             zCall( 0x0062E2F0 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x0062B500 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0062E310 );
    virtual ~zCZone( void )                                                                            zCall( 0x0062DFE0 );
    virtual void EndMovement( void )                                                                   zCall( 0x0062E090 );
    virtual void SetVisual( zCVisual* )                                                                zCall( 0x00629920 );
    virtual void SetVisual( zSTRING const& )                                                           zCall( 0x00629930 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                       zCall( 0x0062E050 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                                   zCall( 0x0062E070 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x0062B510 );
    virtual zCClassDef* GetZoneMotherClass( void ) const                                               zCall( 0x00629940 );
    virtual zCClassDef* GetDefaultZoneClass( void ) const                                              zCall( 0x0062B520 );
    virtual zSTRING GetDebugDescString( void )                                                         zCall( 0x0062E340 );

    // user API
    #include "zCZone.inl"
  };

  class zCZoneZFog : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneZFog )

    float fogRangeCenter;
    float innerRangePerc;
    zCOLOR fogColor;

    void zCZoneZFog_OnInit()                                                                           zCall( 0x0062E490 );
    zCZoneZFog()                                                                                       zInit( zCZoneZFog_OnInit() );
    float GetActiveRange( float )                                                                      zCall( 0x0062E5D0 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x0062C540 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x0062C630 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x0062E720 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0062E790 );
    virtual ~zCZoneZFog( void )                                                                        zCall( 0x0062E560 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x0062E630 );
    virtual zCClassDef* GetDefaultZoneClass( void ) const                                              zCall( 0x0062E620 );

    // user API
    #include "zCZoneZFog.inl"
  };

  class zCZoneZFogDefault : public zCZoneZFog {
  public:
    zCLASS_DECLARATION( zCZoneZFogDefault )

    zCZoneZFogDefault() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x0062C840 );
    virtual zCClassDef* _GetClassDef( void ) const                      zCall( 0x00629990 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0062E850 );
    virtual ~zCZoneZFogDefault( void )                                  zCall( 0x0062AD40 );
    virtual void ThisVobAddedToWorld( zCWorld* )                        zCall( 0x0062E820 );

    // user API
    #include "zCZoneZFogDefault.inl"
  };

  class zCZoneReverb : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneReverb )

    int reverbPresetNr;
    float reverbPresetWeight;
    float innerRangePerc;

    void zCZoneReverb_OnInit()                                                                         zCall( 0x00630F90 );
    zCZoneReverb()                                                                                     zInit( zCZoneReverb_OnInit() );
    float GetActiveWeight()                                                                            zCall( 0x00631260 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x0062B430 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x0062B550 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x006313D0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x00631650 );
    virtual ~zCZoneReverb( void )                                                                      zCall( 0x00631050 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x006312C0 );
    virtual zCClassDef* GetDefaultZoneClass( void ) const                                              zCall( 0x006312B0 );
    virtual zSTRING GetDebugDescString( void )                                                         zCall( 0x006310C0 );

    // user API
    #include "zCZoneReverb.inl"
  };

  class zCZoneReverbDefault : public zCZoneReverb {
  public:
    zCLASS_DECLARATION( zCZoneReverbDefault )

    zCZoneReverbDefault() {}
    static zCObject* _CreateNewInstance()                                                              zCall( 0x0062B760 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x0062B850 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x00631740 );
    virtual ~zCZoneReverbDefault( void )                                                               zCall( 0x0062B8A0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                       zCall( 0x00631700 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x0062B860 );

    // user API
    #include "zCZoneReverbDefault.inl"
  };

  class zCZoneMusic : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneMusic )

    zCZoneMusic() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x0062C1B0 );
    static int SetAutochange( int )                                     zCall( 0x00631800 );
    static void GetAutochange( int* )                                   zCall( 0x00631820 );
    virtual zCClassDef* _GetClassDef( void ) const                      zCall( 0x0062C290 );
    virtual ~zCZoneMusic( void )                                        zCall( 0x0062C2D0 );


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

    void zCZoneVobFarPlane_OnInit()                                                                    zCall( 0x0062E900 );
    zCZoneVobFarPlane()                                                                                zInit( zCZoneVobFarPlane_OnInit() );
    float GetActiveFarZ( float )                                                                       zCall( 0x0062EA20 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x0062BB10 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x0062BC00 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x0062EB70 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0062EBD0 );
    virtual ~zCZoneVobFarPlane( void )                                                                 zCall( 0x0062E9B0 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x0062EA80 );
    virtual zCClassDef* GetDefaultZoneClass( void ) const                                              zCall( 0x0062EA70 );

    // user API
    #include "zCZoneVobFarPlane.inl"
  };

  class zCZoneVobFarPlaneDefault : public zCZoneVobFarPlane {
  public:
    zCLASS_DECLARATION( zCZoneVobFarPlaneDefault )

    zCZoneVobFarPlaneDefault() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x0062BE10 );
    virtual zCClassDef* _GetClassDef( void ) const                      zCall( 0x0062BF00 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0062ECC0 );
    virtual ~zCZoneVobFarPlaneDefault( void )                           zCall( 0x0062BF40 );
    virtual void ThisVobAddedToWorld( zCWorld* )                        zCall( 0x0062EC70 );

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

    void zCVobSound_OnInit()                                                                           zCall( 0x0062ED80 );
    zCVobSound()                                                                                       zInit( zCVobSound_OnInit() );
    void SetSound( zSTRING const& )                                                                    zCall( 0x0062F530 );
    zCSoundFX* LoadSound( zSTRING const& )                                                             zCall( 0x0062F670 );
    void SetSoundVolume( float )                                                                       zCall( 0x0062F6C0 );
    void SetSoundRadius( float )                                                                       zCall( 0x0062F6D0 );
    float CalcObstruction()                                                                            zCall( 0x0062F750 );
    float CalcVolumeScale()                                                                            zCall( 0x0062F950 );
    void StartSound( int )                                                                             zCall( 0x0062FC40 );
    void StopSound()                                                                                   zCall( 0x0062FDD0 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x0062CB30 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x0062EFC0 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x0062FFD0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x00630140 );
    virtual ~zCVobSound( void )                                                                        zCall( 0x0062F000 );
    virtual void OnTrigger( zCVob*, zCVob* )                                                           zCall( 0x0062FF50 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                                         zCall( 0x0062FF70 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                                  zCall( 0x0062FFC0 );
    virtual void EndMovement( void )                                                                   zCall( 0x0062F4A0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                       zCall( 0x006305C0 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                                   zCall( 0x006305E0 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x006304E0 );
    virtual zSTRING GetDebugDescString( void )                                                         zCall( 0x0062F120 );
    virtual void DoSoundUpdate( float )                                                                zCall( 0x0062FE10 );

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

    void zCVobSoundDaytime_OnInit()                                     zCall( 0x00630640 );
    zCVobSoundDaytime()                                                 zInit( zCVobSoundDaytime_OnInit() );
    void ActivateSection( int )                                         zCall( 0x006309B0 );
    int CalcTimeFrac( float, float, float, float& )                     zCall( 0x00630A90 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0062CDC0 );
    virtual zCClassDef* _GetClassDef( void ) const                      zCall( 0x0062CEB0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00630E40 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00630EB0 );
    virtual ~zCVobSoundDaytime( void )                                  zCall( 0x006306D0 );
    virtual zCClassDef* GetZoneMotherClass( void ) const                zCall( 0x0062CEC0 );
    virtual zSTRING GetDebugDescString( void )                          zCall( 0x00630860 );
    virtual void DoSoundUpdate( float )                                 zCall( 0x00630B20 );

    // user API
    #include "zCVobSoundDaytime.inl"
  };

} // namespace Gothic_I_Addon

#include "zBVolume_Util.h"

#endif // __ZZONE_H__VER1__