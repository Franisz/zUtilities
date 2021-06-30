// Supported with union (c) 2018 Union team

#ifndef __OMUSIC_ZONE_H__VER2__
#define __OMUSIC_ZONE_H__VER2__

#include "zZone.h"
#include "zMusic_Dm.h"

namespace Gothic_II_Classic {

  enum oHEROSTATUS {
    oHERO_STATUS_STD,
    oHERO_STATUS_THR,
    oHERO_STATUS_FGT
  };

  struct oCZoneMusicList {
    oCZoneMusic* entry;
    oCZoneMusicList* next;

    oCZoneMusicList() {}

    // user API
    #include "oCZoneMusicList.inl"
  };

  class oCZoneMusic : public zCZoneMusic {
  public:
    zCLASS_DECLARATION( oCZoneMusic )

    int enabled;
    int local_enabled;
    int priority;
    int ellipsoid;
    float reverbLevel;
    float volumeLevel;
    int loop;
    int dayEntranceDone;
    int nightEntranceDone;

    void oCZoneMusic_OnInit()                                                                          zCall( 0x00754F20 );
    oCZoneMusic()                                                                                      zInit( oCZoneMusic_OnInit() );
    void SetEnabled( int )                                                                             zCall( 0x00755AE0 );
    int IsEnabled() const                                                                              zCall( 0x00755AF0 );
    void SetPriority( int )                                                                            zCall( 0x00755B00 );
    int GetPriority() const                                                                            zCall( 0x00755B10 );
    void SetEllipsoid( int )                                                                           zCall( 0x00755B20 );
    int IsEllipsoid() const                                                                            zCall( 0x00755B30 );
    void SetReverb( float )                                                                            zCall( 0x00755B40 );
    float GetReverb() const                                                                            zCall( 0x00755B50 );
    void SetVolume( float )                                                                            zCall( 0x00755B60 );
    float GetVolume() const                                                                            zCall( 0x00755B70 );
    void SetLoop( int )                                                                                zCall( 0x00755B80 );
    int IsLoop() const                                                                                 zCall( 0x00755B90 );
    void SetDayEntranceDone( int )                                                                     zCall( 0x00755BA0 );
    int IsDayEntranceDone() const                                                                      zCall( 0x00755BB0 );
    void SetNightEntranceDone( int )                                                                   zCall( 0x00755BC0 );
    int IsNightEntranceDone() const                                                                    zCall( 0x00755BD0 );
    float GetCamPosWeightElps()                                                                        zCall( 0x00755DE0 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x00754B50 );
    static void SetZonetime( int )                                                                     zCall( 0x00755BE0 );
    static void GetZonetime( int* )                                                                    zCall( 0x00755BF0 );
    static oCZoneMusicList* BuildTempZoneList( oCZoneMusicDefault*, zCArraySort<zCZone*> const& )      zCall( 0x00755F90 );
    static void ReleaseTempZoneList( oCZoneMusicList* )                                                zCall( 0x007560C0 );
    static void SwitchInAndOutZones( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const& )        zCall( 0x007560F0 );
    static oCZoneMusic* GetMusicZoneByName( oCZoneMusic*, zSTRING )                                    zCall( 0x00756570 );
    static void GetNewTheme( zSTRING* )                                                                zCall( 0x00756600 );
    static int PlayThemeVariation( zSTRING, int )                                                      zCall( 0x007569F0 );
    static int IsDaytime()                                                                             zCall( 0x00756E60 );
    static oHEROSTATUS GetHerostatus()                                                                 zCall( 0x00756E80 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x00754C30 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x00755C00 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x00755CF0 );
    virtual ~oCZoneMusic()                                                                             zCall( 0x00754FB0 );
    virtual void OnTrigger( zCVob* )                                                                   zCall( 0x00755AC0 );
    virtual void OnUntrigger( zCVob* )                                                                 zCall( 0x00755AD0 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x00754FC0 );
    virtual zCClassDef* GetDefaultZoneClass() const                                                    zCall( 0x00755A90 );
    virtual zSTRING GetDebugDescString()                                                               zCall( 0x00755AA0 );

    // static properties
    static long& s_lastzonechange;
    static int& s_zonetime;
    static int& s_daytime;
    static oHEROSTATUS& s_herostatus;
    static oCZoneMusic*& s_musiczone;
    static oCZoneMusic*& s_oldmusiczone;

    // user API
    #include "oCZoneMusic.inl"
  };

  class oCZoneMusicDefault : public oCZoneMusic {
  public:
    zCLASS_DECLARATION( oCZoneMusicDefault )

    void oCZoneMusicDefault_OnInit()         zCall( 0x00756E90 );
    oCZoneMusicDefault()                     zInit( oCZoneMusicDefault_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x00754E30 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00754F10 );
    virtual ~oCZoneMusicDefault()            zCall( 0x00756F20 );

    // user API
    #include "oCZoneMusicDefault.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OMUSIC_ZONE_H__VER2__