// Supported with union (c) 2018-2021 Union team

#ifndef __OMUSIC_ZONE_H__VER0__
#define __OMUSIC_ZONE_H__VER0__

#include "zMusic_Dm.h"
#include "zZone.h"

namespace Gothic_I_Classic {

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

  // sizeof 128h
  class oCZoneMusic : public zCZoneMusic {
  public:
    zCLASS_DECLARATION( oCZoneMusic )

    int enabled;           // sizeof 04h    offset 104h
    int local_enabled;     // sizeof 04h    offset 108h
    int priority;          // sizeof 04h    offset 10Ch
    int ellipsoid;         // sizeof 04h    offset 110h
    float reverbLevel;     // sizeof 04h    offset 114h
    float volumeLevel;     // sizeof 04h    offset 118h
    int loop;              // sizeof 04h    offset 11Ch
    int dayEntranceDone;   // sizeof 04h    offset 120h
    int nightEntranceDone; // sizeof 04h    offset 124h

    void oCZoneMusic_OnInit()                                                                          zCall( 0x0070ADE0 );
    oCZoneMusic()                                                                                      zInit( oCZoneMusic_OnInit() );
    void SetEnabled( int )                                                                             zCall( 0x0070B880 );
    int IsEnabled() const                                                                              zCall( 0x0070B890 );
    void SetPriority( int )                                                                            zCall( 0x0070B8A0 );
    int GetPriority() const                                                                            zCall( 0x0070B8B0 );
    void SetEllipsoid( int )                                                                           zCall( 0x0070B8C0 );
    int IsEllipsoid() const                                                                            zCall( 0x0070B8D0 );
    void SetReverb( float )                                                                            zCall( 0x0070B8E0 );
    float GetReverb() const                                                                            zCall( 0x0070B8F0 );
    void SetVolume( float )                                                                            zCall( 0x0070B900 );
    float GetVolume() const                                                                            zCall( 0x0070B910 );
    void SetLoop( int )                                                                                zCall( 0x0070B920 );
    int IsLoop() const                                                                                 zCall( 0x0070B930 );
    void SetDayEntranceDone( int )                                                                     zCall( 0x0070B940 );
    int IsDayEntranceDone() const                                                                      zCall( 0x0070B950 );
    void SetNightEntranceDone( int )                                                                   zCall( 0x0070B960 );
    int IsNightEntranceDone() const                                                                    zCall( 0x0070B970 );
    float GetCamPosWeightElps()                                                                        zCall( 0x0070BB80 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x0070A9F0 );
    static void SetZonetime( int )                                                                     zCall( 0x0070B980 );
    static void GetZonetime( int* )                                                                    zCall( 0x0070B990 );
    static oCZoneMusicList* BuildTempZoneList( oCZoneMusicDefault*, zCArraySort<zCZone*> const& )      zCall( 0x0070BD30 );
    static void ReleaseTempZoneList( oCZoneMusicList* )                                                zCall( 0x0070BEA0 );
    static void SwitchInAndOutZones( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const& )        zCall( 0x0070BED0 );
    static oCZoneMusic* GetMusicZoneByName( oCZoneMusic*, zSTRING )                                    zCall( 0x0070C350 );
    static void GetNewTheme( zSTRING* )                                                                zCall( 0x0070C3E0 );
    static int PlayThemeVariation( zSTRING, int )                                                      zCall( 0x0070C7D0 );
    static int IsDaytime()                                                                             zCall( 0x0070CB70 );
    static oHEROSTATUS GetHerostatus()                                                                 zCall( 0x0070CB90 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x0070AAE0 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x0070B9A0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x0070BA90 );
    virtual ~oCZoneMusic()                                                                             zCall( 0x0070AE70 );
    virtual void OnTrigger( zCVob* )                                                                   zCall( 0x0070B860 );
    virtual void OnUntrigger( zCVob* )                                                                 zCall( 0x0070B870 );
    virtual void ProcessZoneList( zCArraySort<zCZone*> const&, zCArraySort<zCZone*> const&, zCWorld* ) zCall( 0x0070AE80 );
    virtual zCClassDef* GetDefaultZoneClass() const                                                    zCall( 0x0070B830 );
    virtual zSTRING GetDebugDescString()                                                               zCall( 0x0070B840 );


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

  // sizeof 128h
  class oCZoneMusicDefault : public oCZoneMusic {
  public:
    zCLASS_DECLARATION( oCZoneMusicDefault )

    void oCZoneMusicDefault_OnInit()                                    zCall( 0x0070CBA0 );
    oCZoneMusicDefault()                                                zInit( oCZoneMusicDefault_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x0070ACE0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0070ADD0 );
    virtual ~oCZoneMusicDefault()                                       zCall( 0x0070CC30 );

    // user API
    #include "oCZoneMusicDefault.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OMUSIC_ZONE_H__VER0__