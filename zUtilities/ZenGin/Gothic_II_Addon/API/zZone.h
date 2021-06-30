// Supported with union (c) 2018 Union team

#ifndef __ZZONE_H__VER3__
#define __ZZONE_H__VER3__

#include "zVob.h"
#include "zBVolume.h"

namespace Gothic_II_Addon {
  const int DIMENSION = 3;

  class zCBBox3DSorterBase {
    friend class zTNode;

  public:

    class zTNode {
    public:
      int isBegin;
      void* data;

      zTNode() {}

      // user API
      #include "zCBBox3DSorterBase_zTNode.inl"
    };

    class zTBoxSortHandle {
    public:
      zCBBox3DSorterBase* mySorter;
      zTBBox3D bbox3D;
      int indexBegin[DIMENSION];
      int indexEnd[DIMENSION];

      void zTBoxSortHandle_OnInit()   zCall( 0x0061FF80 );
      zTBoxSortHandle()               zInit( zTBoxSortHandle_OnInit() );
      virtual ~zTBoxSortHandle()      zCall( 0x00620020 );
      virtual void AddActive( void* ) zPureCall;
      virtual void DelActive( void* ) zPureCall;
      virtual void ClearActive()      zCall( 0x00620010 );

      // user API
      #include "zCBBox3DSorterBase_zTBoxSortHandle.inl"
    };

    zCArray<zTBoxSortHandle*> handles;
    zCArraySort<zTNode*> nodeList[DIMENSION];
    int sorted;

    void zCBBox3DSorterBase_OnInit()                           zCall( 0x0063B080 );
    zCBBox3DSorterBase()                                       zInit( zCBBox3DSorterBase_OnInit() );
    void Clear()                                               zCall( 0x0063B2B0 );
    void AllocAbs( int )                                       zCall( 0x0063B330 );
    void Insert( void* )                                       zCall( 0x0063B3B0 );
    void Remove( void* )                                       zCall( 0x0063B510 );
    void GetActiveList( zTBBox3D const&, zTBoxSortHandle& )    zCall( 0x0063B5D0 );
    void UpdateActiveList( zTBBox3D const&, zTBoxSortHandle& ) zCall( 0x0063B920 );
    void InsertHandle( zTBoxSortHandle& )                      zCall( 0x0063BC00 );
    void RemoveHandle( zTBoxSortHandle& )                      zCall( 0x0063BCE0 );
    void Sort()                                                zCall( 0x0063BD30 );
    void AdjustSorting( zCArraySort<zTNode*>&, int )           zCall( 0x0063BD70 );
    void Update( void* )                                       zCall( 0x0063BEF0 );
    static int ArrayCompare( void const*, void const* )        zCall( 0x0063B1B0 );
    virtual ~zCBBox3DSorterBase( void )                        zCall( 0x0063B120 );
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

    void zCZone_OnInit()                                                                               zCall( 0x0063C050 );
    zCZone()                                                                                           zInit( zCZone_OnInit() );
    float GetCamPosWeight()                                                                            zCall( 0x0063C1D0 );
    void SetZoneVobFlags()                                                                             zCall( 0x0063C390 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x00639740 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0063C3C0 );
    virtual ~zCZone( void )                                                                            zCall( 0x0063C0F0 );
    virtual void EndMovement( int )                                                                    zCall( 0x0063C1A0 );
    virtual void SetVisual( zSTRING const& )                                                           zCall( 0x00637160 );
    virtual void SetVisual( zCVisual* )                                                                zCall( 0x00637150 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                       zCall( 0x0063C160 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                                   zCall( 0x0063C180 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x00639750 );
    virtual zCClassDef* GetZoneMotherClass( void ) const                                               zCall( 0x00637170 );
    virtual zCClassDef* GetDefaultZoneClass( void ) const                                              zCall( 0x00639760 );
    virtual zSTRING GetDebugDescString( void )                                                         zCall( 0x0063C400 );

    // user API
    #include "zCZone.inl"
  };

  class zCZoneZFog : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneZFog )

    float fogRangeCenter;
    float innerRangePerc;
    zCOLOR fogColor;
    int bFadeOutSky;
    int bOverrideColor;

    void zCZoneZFog_OnInit()                                                                           zCall( 0x0063C5B0 );
    zCZoneZFog()                                                                                       zInit( zCZoneZFog_OnInit() );
    float GetActiveRange( float )                                                                      zCall( 0x0063C700 );
    float GetSkyFadeWeight()                                                                           zCall( 0x0063C750 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x0063A6F0 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x0063A7E0 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x0063CBB0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0063CC40 );
    virtual ~zCZoneZFog( void )                                                                        zCall( 0x0063C690 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x0063C7A0 );
    virtual zCClassDef* GetDefaultZoneClass( void ) const                                              zCall( 0x0063C790 );

    // user API
    #include "zCZoneZFog.inl"
  };

  class zCZoneZFogDefault : public zCZoneZFog {
  public:
    zCLASS_DECLARATION( zCZoneZFogDefault )

    zCZoneZFogDefault() {}
    static zCObject* _CreateNewInstance()          zCall( 0x0063A9E0 );
    virtual zCClassDef* _GetClassDef( void ) const zCall( 0x006371C0 );
    virtual void Unarchive( zCArchiver& )          zCall( 0x0063CD30 );
    virtual ~zCZoneZFogDefault( void )             zCall( 0x00638FD0 );
    virtual void ThisVobAddedToWorld( zCWorld* )   zCall( 0x0063CD00 );

    // user API
    #include "zCZoneZFogDefault.inl"
  };

  class zCZoneReverb : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneReverb )

    int reverbPresetNr;
    float reverbPresetWeight;
    float innerRangePerc;

    void zCZoneReverb_OnInit()                                                                         zCall( 0x0063F3C0 );
    zCZoneReverb()                                                                                     zInit( zCZoneReverb_OnInit() );
    float GetActiveWeight()                                                                            zCall( 0x0063F670 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x00639680 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x00639790 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x0063F7E0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0063FA50 );
    virtual ~zCZoneReverb( void )                                                                      zCall( 0x0063F480 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x0063F6D0 );
    virtual zCClassDef* GetDefaultZoneClass( void ) const                                              zCall( 0x0063F6C0 );
    virtual zSTRING GetDebugDescString( void )                                                         zCall( 0x0063F4F0 );

    // user API
    #include "zCZoneReverb.inl"
  };

  class zCZoneReverbDefault : public zCZoneReverb {
  public:
    zCLASS_DECLARATION( zCZoneReverbDefault )

    zCZoneReverbDefault() {}
    static zCObject* _CreateNewInstance()                                                              zCall( 0x00639990 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x00639A70 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0063FB40 );
    virtual ~zCZoneReverbDefault( void )                                                               zCall( 0x00639AC0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                       zCall( 0x0063FB00 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x00639A80 );

    // user API
    #include "zCZoneReverbDefault.inl"
  };

  class zCZoneMusic : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneMusic )

    zCZoneMusic() {}
    static zCObject* _CreateNewInstance()          zCall( 0x0063A380 );
    static int SetAutochange( int )                zCall( 0x0063FC10 );
    static void GetAutochange( int* )              zCall( 0x0063FC30 );
    virtual zCClassDef* _GetClassDef( void ) const zCall( 0x0063A450 );
    virtual ~zCZoneMusic( void )                   zCall( 0x0063A490 );

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

    void zCZoneVobFarPlane_OnInit()                                                                    zCall( 0x0063CE10 );
    zCZoneVobFarPlane()                                                                                zInit( zCZoneVobFarPlane_OnInit() );
    float GetActiveFarZ( float )                                                                       zCall( 0x0063CF40 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x00639D20 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x00639E00 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x0063D090 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0063D0F0 );
    virtual ~zCZoneVobFarPlane( void )                                                                 zCall( 0x0063CED0 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x0063CFA0 );
    virtual zCClassDef* GetDefaultZoneClass( void ) const                                              zCall( 0x0063CF90 );

    // user API
    #include "zCZoneVobFarPlane.inl"
  };

  class zCZoneVobFarPlaneDefault : public zCZoneVobFarPlane {
  public:
    zCLASS_DECLARATION( zCZoneVobFarPlaneDefault )

    zCZoneVobFarPlaneDefault() {}
    static zCObject* _CreateNewInstance()          zCall( 0x0063A000 );
    virtual zCClassDef* _GetClassDef( void ) const zCall( 0x0063A0E0 );
    virtual void Unarchive( zCArchiver& )          zCall( 0x0063D1E0 );
    virtual ~zCZoneVobFarPlaneDefault( void )      zCall( 0x0063A120 );
    virtual void ThisVobAddedToWorld( zCWorld* )   zCall( 0x0063D190 );

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

    void zCVobSound_OnInit()                                                                           zCall( 0x0063D2B0 );
    zCVobSound()                                                                                       zInit( zCVobSound_OnInit() );
    void SetSound( zSTRING const& )                                                                    zCall( 0x0063DA70 );
    zCSoundFX* LoadSound( zSTRING const& )                                                             zCall( 0x0063DBB0 );
    void SetSoundVolume( float )                                                                       zCall( 0x0063DBF0 );
    void SetSoundRadius( float )                                                                       zCall( 0x0063DC00 );
    float CalcObstruction()                                                                            zCall( 0x0063DC80 );
    float CalcVolumeScale()                                                                            zCall( 0x0063DDE0 );
    void StartSound( int )                                                                             zCall( 0x0063E040 );
    void StopSound()                                                                                   zCall( 0x0063E1D0 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x0063ACC0 );
    virtual zCClassDef* _GetClassDef( void ) const                                                     zCall( 0x0063D4F0 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x0063E3D0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0063E540 );
    virtual ~zCVobSound( void )                                                                        zCall( 0x0063D530 );
    virtual void OnTrigger( zCVob*, zCVob* )                                                           zCall( 0x0063E350 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                                         zCall( 0x0063E370 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                                  zCall( 0x0063E3C0 );
    virtual void EndMovement( int )                                                                    zCall( 0x0063D9D0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                       zCall( 0x0063E9B0 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                                   zCall( 0x0063E9D0 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x0063E8D0 );
    virtual zSTRING GetDebugDescString( void )                                                         zCall( 0x0063D640 );
    virtual void DoSoundUpdate( float )                                                                zCall( 0x0063E210 );

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

    void zCVobSoundDaytime_OnInit()                      zCall( 0x0063EA30 );
    zCVobSoundDaytime()                                  zInit( zCVobSoundDaytime_OnInit() );
    void ActivateSection( int )                          zCall( 0x0063EDE0 );
    int CalcTimeFrac( float, float, float, float& )      zCall( 0x0063EEC0 );
    static zCObject* _CreateNewInstance()                zCall( 0x0063AF30 );
    virtual zCClassDef* _GetClassDef( void ) const       zCall( 0x0063B010 );
    virtual void Archive( zCArchiver& )                  zCall( 0x0063F270 );
    virtual void Unarchive( zCArchiver& )                zCall( 0x0063F2E0 );
    virtual ~zCVobSoundDaytime( void )                   zCall( 0x0063EAC0 );
    virtual zCClassDef* GetZoneMotherClass( void ) const zCall( 0x0063B020 );
    virtual zSTRING GetDebugDescString( void )           zCall( 0x0063EC40 );
    virtual void DoSoundUpdate( float )                  zCall( 0x0063EF50 );

    // user API
    #include "zCVobSoundDaytime.inl"
  };

} // namespace Gothic_II_Addon

#include "zBVolume_Util.h"

#endif // __ZZONE_H__VER3__