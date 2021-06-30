// Supported with union (c) 2018 Union team

#ifndef __OMUSIC_ZONE_H__VER1__
#define __OMUSIC_ZONE_H__VER1__

#include "zMusic_Dm.h"
#include "zZone.h"

namespace Gothic_I_Addon {

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

    void oCZoneMusic_OnInit()                                                                          zCall( 0x00745CA0 );
    oCZoneMusic()                                                                                      zInit( oCZoneMusic_OnInit() );
    void SetEnabled( int )                                                                             zCall( 0x00746800 );
    int IsEnabled() const                                                                              zCall( 0x00746810 );
    void SetPriority( int )                                                                            zCall( 0x00746820 );
    int GetPriority() const                                                                            zCall( 0x00746830 );
    void SetEllipsoid( int )                                                                           zCall( 0x00746840 );
    int IsEllipsoid() const                                                                            zCall( 0x00746850 );
    void SetReverb( float )                                                                            zCall( 0x00746860 );
    float GetReverb() const                                                                            zCall( 0x00746870 );
    void SetVolume( float )                                                                            zCall( 0x00746880 );
    float GetVolume() const                                                                            zCall( 0x00746890 );
    void SetLoop( int )                                                                                zCall( 0x007468A0 );
    int IsLoop() const                                                                                 zCall( 0x007468B0 );
    void SetDayEntranceDone( int )                                                                     zCall( 0x007468C0 );
    int IsDayEntranceDone() const                                                                      zCall( 0x007468D0 );
    void SetNightEntranceDone( int )                                                                   zCall( 0x007468E0 );
    int IsNightEntranceDone() const                                                                    zCall( 0x007468F0 );
    float GetCamPosWeightElps()                                                                        zCall( 0x00746B00 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x007458A0 );
    static void SetZonetime( int )                                                                     zCall( 0x00746900 );
    static void GetZonetime( int* )                                                                    zCall( 0x00746910 );
    static oCZoneMusicList* BuildTempZoneList( oCZoneMusicDefault*, zCArraySort<zCZone*> const& )      zCall( 0x00746D30 );
    static void ReleaseTempZoneList( oCZoneMusicList* )                                                zCall( 0x00746EA0 );
    static void SwitchInAndOutZones( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const& )        zCall( 0x00746EC0 );
    static oCZoneMusic* GetMusicZoneByName( oCZoneMusic*, zSTRING )                                    zCall( 0x00747380 );
    static void GetNewTheme( zSTRING* )                                                                zCall( 0x00747410 );
    static int PlayThemeVariation( zSTRING, int )                                                      zCall( 0x00747850 );
    static int IsDaytime()                                                                             zCall( 0x00747C80 );
    static oHEROSTATUS GetHerostatus()                                                                 zCall( 0x00747CA0 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x00745990 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x00746920 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x00746A10 );
    virtual ~oCZoneMusic()                                                                             zCall( 0x00745D30 );
    virtual void OnTrigger( zCVob* )                                                                   zCall( 0x007467E0 );
    virtual void OnUntrigger( zCVob* )                                                                 zCall( 0x007467F0 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x00745D40 );
    virtual zCClassDef* GetDefaultZoneClass() const                                                    zCall( 0x007467B0 );
    virtual zSTRING GetDebugDescString()                                                               zCall( 0x007467C0 );


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

    void oCZoneMusicDefault_OnInit()                                    zCall( 0x00747CB0 );
    oCZoneMusicDefault()                                                zInit( oCZoneMusicDefault_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00745BA0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00745C90 );
    virtual ~oCZoneMusicDefault()                                       zCall( 0x00747D40 );

    // user API
    #include "oCZoneMusicDefault.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OMUSIC_ZONE_H__VER1__