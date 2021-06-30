// Supported with union (c) 2018 Union team

#ifndef __ZZONE_H__VER2__
#define __ZZONE_H__VER2__

namespace Gothic_II_Classic {
  const int DIMENSION=3;

  class zCBBox3DSorterBase {
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

      void zTBoxSortHandle_OnInit()   zCall( 0x00618830 );
      zTBoxSortHandle()               zInit( zTBoxSortHandle_OnInit() );
      virtual ~zTBoxSortHandle()      zCall( 0x00633860 );
      virtual void AddActive( void* ) zPureCall;
      virtual void DelActive( void* ) zPureCall;
      virtual void ClearActive()      zCall( 0x006188C0 );

      // user API
      #include "zCBBox3DSorterBase_zTBoxSortHandle.inl"
    };

    zCArray<zTBoxSortHandle*> handles;
    zCArraySort<zTNode*> nodeList[DIMENSION];
    int sorted;

    void zCBBox3DSorterBase_OnInit()                           zCall( 0x006338B0 );
    zCBBox3DSorterBase()                                       zInit( zCBBox3DSorterBase_OnInit() );
    void Clear()                                               zCall( 0x00633AE0 );
    void AllocAbs( int )                                       zCall( 0x00633B60 );
    void Insert( void* )                                       zCall( 0x00633BE0 );
    void Remove( void* )                                       zCall( 0x00633D40 );
    void GetActiveList( zTBBox3D const&, zTBoxSortHandle& )    zCall( 0x00633E00 );
    void UpdateActiveList( zTBBox3D const&, zTBoxSortHandle& ) zCall( 0x00634150 );
    void InsertHandle( zTBoxSortHandle& )                      zCall( 0x00634430 );
    void RemoveHandle( zTBoxSortHandle& )                      zCall( 0x00634510 );
    void Sort()                                                zCall( 0x00634560 );
    void AdjustSorting( zCArraySort<zTNode*>&, int )           zCall( 0x006345A0 );
    void Update( void* )                                       zCall( 0x00634720 );
    static int ArrayCompare( void const*, void const* )        zCall( 0x006339E0 );
    virtual ~zCBBox3DSorterBase()                              zCall( 0x00633950 );
    virtual const zTBBox3D& GetBBox( const zTNode* )           zPureCall;

    // static properties
    static zCBBox3DSorterBase*& s_currentSorter;
    static int& s_currentDimension;

    // user API
    #include "zCBBox3DSorterBase.inl"
  };

  class zCZone : public zCVob {
  public:
    zCLASS_DECLARATION( zCZone )

    zCWorld* world;

    void zCZone_OnInit()                                                                               zCall( 0x00634880 );
    zCZone()                                                                                           zInit( zCZone_OnInit() );
    float GetCamPosWeight()                                                                            zCall( 0x006349F0 );
    void SetZoneVobFlags()                                                                             zCall( 0x00634BB0 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x00631F70 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x00634BE0 );
    virtual ~zCZone()                                                                                  zCall( 0x00634920 );
    virtual void EndMovement()                                                                         zCall( 0x006349D0 );
    virtual void SetVisual( zCVisual* )                                                                zCall( 0x0062F970 );
    virtual void SetVisual( zSTRING const& )                                                           zCall( 0x0062F980 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                       zCall( 0x00634990 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                                   zCall( 0x006349B0 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x00631F80 );
    virtual zCClassDef* GetZoneMotherClass() const                                                     zCall( 0x0062F990 );
    virtual zCClassDef* GetDefaultZoneClass() const                                                    zCall( 0x00631F90 );
    virtual zSTRING GetDebugDescString()                                                               zCall( 0x00634C20 );

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

    void zCZoneZFog_OnInit()                                                                           zCall( 0x00634DD0 );
    zCZoneZFog()                                                                                       zInit( zCZoneZFog_OnInit() );
    float GetActiveRange( float )                                                                      zCall( 0x00634F20 );
    float GetSkyFadeWeight()                                                                           zCall( 0x00634F70 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x00632F20 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x00633010 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x006353D0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x00635460 );
    virtual ~zCZoneZFog()                                                                              zCall( 0x00634EB0 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x00634FC0 );
    virtual zCClassDef* GetDefaultZoneClass() const                                                    zCall( 0x00634FB0 );

    // user API
    #include "zCZoneZFog.inl"
  };

  class zCZoneZFogDefault : public zCZoneZFog {
  public:
    zCLASS_DECLARATION( zCZoneZFogDefault )

    zCZoneZFogDefault() {}
    static zCObject* _CreateNewInstance()        zCall( 0x00633210 );
    virtual zCClassDef* _GetClassDef() const     zCall( 0x0062F9E0 );
    virtual void Unarchive( zCArchiver& )        zCall( 0x00635550 );
    virtual ~zCZoneZFogDefault()                 zCall( 0x00631800 );
    virtual void ThisVobAddedToWorld( zCWorld* ) zCall( 0x00635520 );

    // user API
    #include "zCZoneZFogDefault.inl"
  };

  class zCZoneReverb : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneReverb )

    int reverbPresetNr;
    float reverbPresetWeight;
    float innerRangePerc;

    void zCZoneReverb_OnInit()                                                                         zCall( 0x00637BD0 );
    zCZoneReverb()                                                                                     zInit( zCZoneReverb_OnInit() );
    float GetActiveWeight()                                                                            zCall( 0x00637E80 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x00631EB0 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x00631FC0 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x00637FF0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x00638260 );
    virtual ~zCZoneReverb()                                                                            zCall( 0x00637C90 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x00637EE0 );
    virtual zCClassDef* GetDefaultZoneClass() const                                                    zCall( 0x00637ED0 );
    virtual zSTRING GetDebugDescString()                                                               zCall( 0x00637D00 );

    // user API
    #include "zCZoneReverb.inl"
  };

  class zCZoneReverbDefault : public zCZoneReverb {
  public:
    zCLASS_DECLARATION( zCZoneReverbDefault )

    zCZoneReverbDefault() {}
    static zCObject* _CreateNewInstance()                                                              zCall( 0x006321C0 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x006322A0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x00638350 );
    virtual ~zCZoneReverbDefault()                                                                     zCall( 0x006322F0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                       zCall( 0x00638310 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x006322B0 );

    // user API
    #include "zCZoneReverbDefault.inl"
  };

  class zCZoneMusic : public zCZone {
  public:
    zCLASS_DECLARATION( zCZoneMusic )

    zCZoneMusic() {}
    static zCObject* _CreateNewInstance()    zCall( 0x00632BB0 );
    static int SetAutochange( int )          zCall( 0x00638420 );
    static void GetAutochange( int* )        zCall( 0x00638440 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00632C80 );
    virtual ~zCZoneMusic()                   zCall( 0x00632CC0 );

    // static properties
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

    void zCZoneVobFarPlane_OnInit()                                                                    zCall( 0x00635630 );
    zCZoneVobFarPlane()                                                                                zInit( zCZoneVobFarPlane_OnInit() );
    float GetActiveFarZ( float )                                                                       zCall( 0x00635760 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x00632550 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x00632630 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x006358B0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x00635910 );
    virtual ~zCZoneVobFarPlane()                                                                       zCall( 0x006356F0 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x006357C0 );
    virtual zCClassDef* GetDefaultZoneClass() const                                                    zCall( 0x006357B0 );

    // user API
    #include "zCZoneVobFarPlane.inl"
  };

  class zCZoneVobFarPlaneDefault : public zCZoneVobFarPlane {
  public:
    zCLASS_DECLARATION( zCZoneVobFarPlaneDefault )

    zCZoneVobFarPlaneDefault() {}
    static zCObject* _CreateNewInstance()        zCall( 0x00632830 );
    virtual zCClassDef* _GetClassDef() const     zCall( 0x00632910 );
    virtual void Unarchive( zCArchiver& )        zCall( 0x00635A00 );
    virtual ~zCZoneVobFarPlaneDefault()          zCall( 0x00632950 );
    virtual void ThisVobAddedToWorld( zCWorld* ) zCall( 0x006359B0 );

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

    void zCVobSound_OnInit()                                                                           zCall( 0x00635AD0 );
    zCVobSound()                                                                                       zInit( zCVobSound_OnInit() );
    void SetSound( zSTRING const& )                                                                    zCall( 0x00636280 );
    zCSoundFX* LoadSound( zSTRING const& )                                                             zCall( 0x006363C0 );
    void SetSoundVolume( float )                                                                       zCall( 0x00636400 );
    void SetSoundRadius( float )                                                                       zCall( 0x00636410 );
    float CalcObstruction()                                                                            zCall( 0x00636490 );
    float CalcVolumeScale()                                                                            zCall( 0x006365F0 );
    void StartSound( int )                                                                             zCall( 0x00636850 );
    void StopSound()                                                                                   zCall( 0x006369E0 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x006334F0 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x00635D10 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x00636BE0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x00636D50 );
    virtual ~zCVobSound()                                                                              zCall( 0x00635D50 );
    virtual void OnTrigger( zCVob*, zCVob* )                                                           zCall( 0x00636B60 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                                         zCall( 0x00636B80 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                                  zCall( 0x00636BD0 );
    virtual void EndMovement()                                                                         zCall( 0x006361F0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                       zCall( 0x006371C0 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                                   zCall( 0x006371E0 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x006370E0 );
    virtual zSTRING GetDebugDescString()                                                               zCall( 0x00635E60 );
    virtual void DoSoundUpdate( float )                                                                zCall( 0x00636A20 );

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

    void zCVobSoundDaytime_OnInit()                 zCall( 0x00637240 );
    zCVobSoundDaytime()                             zInit( zCVobSoundDaytime_OnInit() );
    void ActivateSection( int )                     zCall( 0x006375F0 );
    int CalcTimeFrac( float, float, float, float& ) zCall( 0x006376D0 );
    static zCObject* _CreateNewInstance()           zCall( 0x00633760 );
    virtual zCClassDef* _GetClassDef() const        zCall( 0x00633840 );
    virtual void Archive( zCArchiver& )             zCall( 0x00637A80 );
    virtual void Unarchive( zCArchiver& )           zCall( 0x00637AF0 );
    virtual ~zCVobSoundDaytime()                    zCall( 0x006372D0 );
    virtual zCClassDef* GetZoneMotherClass() const  zCall( 0x00633850 );
    virtual zSTRING GetDebugDescString()            zCall( 0x00637450 );
    virtual void DoSoundUpdate( float )             zCall( 0x00637760 );

    // user API
    #include "zCVobSoundDaytime.inl"
  };

} // namespace Gothic_II_Classic

#include "zBVolume_Util.h"

#endif // __ZZONE_H__VER2__