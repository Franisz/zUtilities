// Supported with union (c) 2018-2021 Union team

#ifndef __ZZONE_H__VER3__
#define __ZZONE_H__VER3__

#include "zVob.h"
#include "zBVolume.h"

namespace Gothic_II_Addon {
  const int DIMENSION = 3;

  // sizeof 44h
  class zCBBox3DSorterBase {
    friend class zTNode;

  public:

    // sizeof 08h
    class zTNode {
    public:
      int isBegin; // sizeof 04h    offset 00h
      void* data;  // sizeof 04h    offset 04h

      zTNode() {}

      // user API
      #include "zCBBox3DSorterBase_zTNode.inl"
    };

    // sizeof 38h
    class zTBoxSortHandle {
    public:
      zCBBox3DSorterBase* mySorter; // sizeof 04h    offset 04h
      zTBBox3D bbox3D;              // sizeof 18h    offset 08h
      int indexBegin[DIMENSION];    // sizeof 0Ch    offset 20h
      int indexEnd[DIMENSION];      // sizeof 0Ch    offset 2Ch

      void zTBoxSortHandle_OnInit()   zCall( 0x0061FF80 );
      zTBoxSortHandle()               zInit( zTBoxSortHandle_OnInit() );
      virtual ~zTBoxSortHandle()      zCall( 0x00620020 );
      virtual void AddActive( void* ) zPureCall;
      virtual void DelActive( void* ) zPureCall;
      virtual void ClearActive()      zCall( 0x00620010 );

      // user API
      #include "zCBBox3DSorterBase_zTBoxSortHandle.inl"
    };

    zCArray<zTBoxSortHandle*> handles;        // sizeof 0Ch    offset 04h
    zCArraySort<zTNode*> nodeList[DIMENSION]; // sizeof 30h    offset 10h
    int sorted;                               // sizeof 04h    offset 40h

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

  // sizeof 124h
  class zCZone : public zCVob {
  public:
    zCLASS_DECLARATION( zCZone )

    zCWorld* world; // sizeof 04h    offset 120h

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

  // sizeof 138h
  class zCZoneZFog : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneZFog )

    float fogRangeCenter; // sizeof 04h    offset 124h
    float innerRangePerc; // sizeof 04h    offset 128h
    zCOLOR fogColor;      // sizeof 04h    offset 12Ch
    int bFadeOutSky;      // sizeof 04h    offset 130h
    int bOverrideColor;   // sizeof 04h    offset 134h

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

  // sizeof 138h
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

  // sizeof 130h
  class zCZoneReverb : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneReverb )

    int reverbPresetNr;       // sizeof 04h    offset 124h
    float reverbPresetWeight; // sizeof 04h    offset 128h
    float innerRangePerc;     // sizeof 04h    offset 12Ch

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

  // sizeof 130h
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

  // sizeof 124h
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

  // sizeof 12Ch
  class zCZoneVobFarPlane : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneVobFarPlane )

    float vobFarZ;        // sizeof 04h    offset 124h
    float innerRangePerc; // sizeof 04h    offset 128h

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

  // sizeof 12Ch
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

  // sizeof 16Ch
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

    zSTRING soundName;                       // sizeof 14h    offset 124h
    float soundRadius;                       // sizeof 04h    offset 138h
    zTSoundMode soundMode;                   // sizeof 04h    offset 13Ch
    group {
      unsigned char soundStartOn        : 1; // sizeof 01h    offset bit
      unsigned char soundIsRunning      : 1; // sizeof 01h    offset bit
      unsigned char soundIsAmbient3D    : 1; // sizeof 01h    offset bit
      unsigned char soundHasObstruction : 1; // sizeof 01h    offset bit
      unsigned char soundVolType        : 1; // sizeof 01h    offset bit
      unsigned char soundAllowedToRun   : 1; // sizeof 01h    offset bit
      unsigned char soundAutoStart      : 1; // sizeof 01h    offset bit
    };
    float soundRandDelay;                    // sizeof 04h    offset 144h
    float soundRandDelayVar;                 // sizeof 04h    offset 148h
    float soundVolume;                       // sizeof 04h    offset 14Ch
    float soundConeAngle;                    // sizeof 04h    offset 150h
    zCSoundFX* sfx;                          // sizeof 04h    offset 154h
    int sfxHandle;                           // sizeof 04h    offset 158h
    float soundRandTimer;                    // sizeof 04h    offset 15Ch
    float obstruction0;                      // sizeof 04h    offset 160h
    float obstruction1;                      // sizeof 04h    offset 164h
    float obstructionFrameTime;              // sizeof 04h    offset 168h

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

  // sizeof 190h
  class zCVobSoundDaytime : public zCVobSound {
  public:
    zCLASS_DECLARATION( zCVobSoundDaytime )

    float soundStartTime; // sizeof 04h    offset 16Ch
    float soundEndTime;   // sizeof 04h    offset 170h
    zSTRING soundName2;   // sizeof 14h    offset 174h
    zCSoundFX* sfx2;      // sizeof 04h    offset 188h
    int activeSection;    // sizeof 04h    offset 18Ch

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