// Supported with union (c) 2018-2021 Union team

#ifndef __OMUSIC_ZONE_H__VER3__
#define __OMUSIC_ZONE_H__VER3__

#include "zZone.h"
#include "zMusic_Dm.h"

namespace Gothic_II_Addon {

  enum oHEROSTATUS {
    oHERO_STATUS_STD,
    oHERO_STATUS_THR,
    oHERO_STATUS_FGT
  };

  // sizeof 08h
  struct oCZoneMusicList {
    oCZoneMusic* entry;    // sizeof 04h    offset 00h
    oCZoneMusicList* next; // sizeof 04h    offset 04h

    oCZoneMusicList() {}

    // user API
    #include "oCZoneMusicList.inl"
  };

  // sizeof 148h
  class oCZoneMusic : public zCZoneMusic {
  public:
    zCLASS_DECLARATION( oCZoneMusic )

    int enabled;           // sizeof 04h    offset 124h
    int local_enabled;     // sizeof 04h    offset 128h
    int priority;          // sizeof 04h    offset 12Ch
    int ellipsoid;         // sizeof 04h    offset 130h
    float reverbLevel;     // sizeof 04h    offset 134h
    float volumeLevel;     // sizeof 04h    offset 138h
    int loop;              // sizeof 04h    offset 13Ch
    int dayEntranceDone;   // sizeof 04h    offset 140h
    int nightEntranceDone; // sizeof 04h    offset 144h

    void oCZoneMusic_OnInit()                                                                          zCall( 0x006404C0 );
    oCZoneMusic()                                                                                      zInit( oCZoneMusic_OnInit() );
    void SetEnabled( int )                                                                             zCall( 0x00641080 );
    int IsEnabled() const                                                                              zCall( 0x00641090 );
    void SetPriority( int )                                                                            zCall( 0x006410A0 );
    int GetPriority() const                                                                            zCall( 0x006410B0 );
    void SetEllipsoid( int )                                                                           zCall( 0x006410C0 );
    int IsEllipsoid() const                                                                            zCall( 0x006410D0 );
    void SetReverb( float )                                                                            zCall( 0x006410E0 );
    float GetReverb() const                                                                            zCall( 0x006410F0 );
    void SetVolume( float )                                                                            zCall( 0x00641100 );
    float GetVolume() const                                                                            zCall( 0x00641110 );
    void SetLoop( int )                                                                                zCall( 0x00641120 );
    int IsLoop() const                                                                                 zCall( 0x00641130 );
    void SetDayEntranceDone( int )                                                                     zCall( 0x00641140 );
    int IsDayEntranceDone() const                                                                      zCall( 0x00641150 );
    void SetNightEntranceDone( int )                                                                   zCall( 0x00641160 );
    int IsNightEntranceDone() const                                                                    zCall( 0x00641170 );
    float GetCamPosWeightElps()                                                                        zCall( 0x00641380 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x006400F0 );
    static void SetZonetime( int )                                                                     zCall( 0x00641180 );
    static void GetZonetime( int* )                                                                    zCall( 0x00641190 );
    static oCZoneMusicList* BuildTempZoneList( oCZoneMusicDefault*, zCArraySort<zCZone*> const& )      zCall( 0x00641530 );
    static void ReleaseTempZoneList( oCZoneMusicList* )                                                zCall( 0x00641660 );
    static void SwitchInAndOutZones( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const& )        zCall( 0x00641690 );
    static oCZoneMusic* GetMusicZoneByName( oCZoneMusic*, zSTRING )                                    zCall( 0x00641B10 );
    static void GetNewTheme( zSTRING* )                                                                zCall( 0x00641BA0 );
    static int PlayThemeVariation( zSTRING, int )                                                      zCall( 0x00641F90 );
    static int IsDaytime()                                                                             zCall( 0x00642400 );
    static oHEROSTATUS GetHerostatus()                                                                 zCall( 0x00642420 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x006401D0 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x006411A0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x00641290 );
    virtual ~oCZoneMusic()                                                                             zCall( 0x00640550 );
    virtual void OnTrigger( zCVob* )                                                                   zCall( 0x00641060 );
    virtual void OnUntrigger( zCVob* )                                                                 zCall( 0x00641070 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x00640560 );
    virtual zCClassDef* GetDefaultZoneClass() const                                                    zCall( 0x00641030 );
    virtual zSTRING GetDebugDescString()                                                               zCall( 0x00641040 );

    static long& s_lastzonechange;
    static int& s_zonetime;
    static int& s_daytime;
    static oHEROSTATUS& s_herostatus;
    static oCZoneMusic*& s_musiczone;
    static oCZoneMusic*& s_oldmusiczone;

    // user API
    #include "oCZoneMusic.inl"
  };

  // sizeof 148h
  class oCZoneMusicDefault : public oCZoneMusic {
  public:
    zCLASS_DECLARATION( oCZoneMusicDefault )

    void oCZoneMusicDefault_OnInit()         zCall( 0x00642430 );
    oCZoneMusicDefault()                     zInit( oCZoneMusicDefault_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x006403D0 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x006404B0 );
    virtual ~oCZoneMusicDefault()            zCall( 0x006424C0 );

    // user API
    #include "oCZoneMusicDefault.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OMUSIC_ZONE_H__VER3__