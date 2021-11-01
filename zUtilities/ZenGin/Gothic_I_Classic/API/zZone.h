// Supported with union (c) 2018-2021 Union team

#ifndef __ZZONE_H__VER0__
#define __ZZONE_H__VER0__

namespace Gothic_I_Classic {
  const int DIMENSION=3;

  // sizeof 44h
  class zCBBox3DSorterBase {
  public:

    // sizeof 38h
    class zTBoxSortHandle {
    public:
      zCBBox3DSorterBase* mySorter; // sizeof 04h    offset 04h
      zTBBox3D bbox3D;              // sizeof 18h    offset 08h
      int indexBegin[DIMENSION];    // sizeof 0Ch    offset 20h
      int indexEnd[DIMENSION];      // sizeof 0Ch    offset 2Ch

      void zTBoxSortHandle_OnInit()   zCall( 0x005F28A0 );
      zTBoxSortHandle()               zInit( zTBoxSortHandle_OnInit() );
      virtual ~zTBoxSortHandle()      zCall( 0x0060A9B0 );
      virtual void AddActive( void* ) zPureCall;
      virtual void DelActive( void* ) zPureCall;
      virtual void ClearActive()      zCall( 0x005F2930 );

      // user API
      #include "zCBBox3DSorterBase_zTBoxSortHandle.inl"
    };

    // sizeof 08h
    class zTNode {
    public:
      int isBegin; // sizeof 04h    offset 00h
      void* data;  // sizeof 04h    offset 04h

      zTNode() {}

      // user API
      #include "zCBBox3DSorterBase_zTNode.inl"
    };

    zCArray<zTBoxSortHandle*> handles;        // sizeof 0Ch    offset 04h
    zCArraySort<zTNode*> nodeList[DIMENSION]; // sizeof 30h    offset 10h
    int sorted;                               // sizeof 04h    offset 40h

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

  // sizeof 104h
  class zCZone : public zCVob {
  public:
    zCLASS_DECLARATION( zCZone )

    zCWorld* world; // sizeof 04h    offset 100h

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

  // sizeof 110h
  class zCZoneZFog : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneZFog )

    float fogRangeCenter; // sizeof 04h    offset 104h
    float innerRangePerc; // sizeof 04h    offset 108h
    zCOLOR fogColor;      // sizeof 04h    offset 10Ch

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

  // sizeof 110h
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

  // sizeof 110h
  class zCZoneReverb : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneReverb )

    int reverbPresetNr;       // sizeof 04h    offset 104h
    float reverbPresetWeight; // sizeof 04h    offset 108h
    float innerRangePerc;     // sizeof 04h    offset 10Ch

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

  // sizeof 110h
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

  // sizeof 104h
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

  // sizeof 10Ch
  class zCZoneVobFarPlane : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneVobFarPlane )

    float vobFarZ;        // sizeof 04h    offset 104h
    float innerRangePerc; // sizeof 04h    offset 108h

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

  // sizeof 10Ch
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

  // sizeof 14Ch
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

    zSTRING soundName;                       // sizeof 14h    offset 104h
    float soundRadius;                       // sizeof 04h    offset 118h
    zTSoundMode soundMode;                   // sizeof 04h    offset 11Ch
    group {
      unsigned char soundStartOn        : 1; // sizeof 01h    offset bit
      unsigned char soundIsRunning      : 1; // sizeof 01h    offset bit
      unsigned char soundIsAmbient3D    : 1; // sizeof 01h    offset bit
      unsigned char soundHasObstruction : 1; // sizeof 01h    offset bit
      unsigned char soundVolType        : 1; // sizeof 01h    offset bit
      unsigned char soundAllowedToRun   : 1; // sizeof 01h    offset bit
      unsigned char soundAutoStart      : 1; // sizeof 01h    offset bit
    };
    float soundRandDelay;                    // sizeof 04h    offset 124h
    float soundRandDelayVar;                 // sizeof 04h    offset 128h
    float soundVolume;                       // sizeof 04h    offset 12Ch
    float soundConeAngle;                    // sizeof 04h    offset 130h
    zCSoundFX* sfx;                          // sizeof 04h    offset 134h
    int sfxHandle;                           // sizeof 04h    offset 138h
    float soundRandTimer;                    // sizeof 04h    offset 13Ch
    float obstruction0;                      // sizeof 04h    offset 140h
    float obstruction1;                      // sizeof 04h    offset 144h
    float obstructionFrameTime;              // sizeof 04h    offset 148h

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

  // sizeof 170h
  class zCVobSoundDaytime : public zCVobSound {
  public:
    zCLASS_DECLARATION( zCVobSoundDaytime )

    float soundStartTime; // sizeof 04h    offset 14Ch
    float soundEndTime;   // sizeof 04h    offset 150h
    zSTRING soundName2;   // sizeof 14h    offset 154h
    zCSoundFX* sfx2;      // sizeof 04h    offset 168h
    int activeSection;    // sizeof 04h    offset 16Ch

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