// Supported with union (c) 2018-2021 Union team

#ifndef __ZMUSIC_H__VER2__
#define __ZMUSIC_H__VER2__

namespace Gothic_II_Classic {
  const float zMUS_JINGLE_VOL_DEFAULT = -1;
  const float zMUS_THEME_VOL_DEFAULT  = -1;

  enum zTMus_TransType {
    zMUS_TR_DEFAULT,
    zMUS_TR_NONE,
    zMUS_TR_GROOVE,
    zMUS_TR_FILL,
    zMUS_TR_BREAK,
    zMUS_TR_INTRO,
    zMUS_TR_END,
    zMUS_TR_ENDANDINTRO
  };

  enum zTMus_TransSubType {
    zMUS_TRSUB_DEFAULT,
    zMUS_TRSUB_IMMEDIATE,
    zMUS_TRSUB_BEAT,
    zMUS_TRSUB_MEASURE
  };

  enum zTMus_EventType {
    zMUS_EVENT_THEME_CHG  = 1,
    zMUS_EVENT_BEAT       = 2,
    zMUS_EVENT_MEASURE    = 4,
    zMUS_EVENT_TRANSITION = 8
  };

  // sizeof 48h
  class zCMusicTheme {
  public:
    zSTRING fileName;             // sizeof 14h    offset 04h
    float vol;                    // sizeof 04h    offset 18h
    int loop;                     // sizeof 04h    offset 1Ch
    float reverbMix;              // sizeof 04h    offset 20h
    float reverbTime;             // sizeof 04h    offset 24h
    zTMus_TransType trType;       // sizeof 04h    offset 28h
    zTMus_TransSubType trSubType; // sizeof 04h    offset 2Ch
    unsigned char dScriptEnd;     // sizeof 01h    offset 30h
    zSTRING name;                 // sizeof 14h    offset 34h

    void zCMusicTheme_OnInit()   zCall( 0x004E5330 );
    zCMusicTheme()               zInit( zCMusicTheme_OnInit() );
    virtual ~zCMusicTheme()      zCall( 0x004E49F0 );
    virtual int IsActive() const zCall( 0x004E4A70 );

    // user API
    #include "zCMusicTheme.inl"
  };

  // sizeof 40h
  class zCMusicJingle {
  public:
    zSTRING fileName;             // sizeof 14h    offset 04h
    int loop;                     // sizeof 04h    offset 18h
    float vol;                    // sizeof 04h    offset 1Ch
    zTMus_TransSubType trSubType; // sizeof 04h    offset 20h
    unsigned char dScriptEnd;     // sizeof 01h    offset 24h
    int refCtr;                   // sizeof 04h    offset 28h
    zSTRING name;                 // sizeof 14h    offset 2Ch

    void zCMusicJingle_OnInit()     zCall( 0x004E5370 );
    zCMusicJingle()                 zInit( zCMusicJingle_OnInit() );
    virtual ~zCMusicJingle()        zCall( 0x004E53C0 );
    virtual zCMusicJingle* AddRef() zCall( 0x004E5440 );
    virtual int Release()           zCall( 0x004E5450 );
    virtual int IsPlaying() const   zCall( 0x004E5460 );
    virtual void StopPlaying()      zCall( 0x004E5470 );
    virtual void CacheIn()          zCall( 0x004E5480 );
    virtual void CacheOut()         zCall( 0x004E5490 );

    // user API
    #include "zCMusicJingle.inl"
  };

  // sizeof 0Ch
  class zCMusicSystem {
  public:
    float volume; // sizeof 04h    offset 04h
    float reverb; // sizeof 04h    offset 08h

    zCMusicSystem() {}
    static void DisableMusicSystem( int )                                                                    zCall( 0x004E4880 );
    virtual ~zCMusicSystem()                                                                                 zCall( 0x004E54C0 );
    virtual void PlayThemeByScript( zSTRING const&, int, int* )                                              zCall( 0x004E54D0 );
    virtual zCMusicTheme* LoadThemeByScript( zSTRING const& )                                                zCall( 0x004E54E0 );
    virtual zCMusicTheme* LoadTheme( zSTRING const& )                                                        zCall( 0x004E54F0 );
    virtual void PlayTheme( zCMusicTheme*, float const&, zTMus_TransType const&, zTMus_TransSubType const& ) zCall( 0x004E5500 );
    virtual zCMusicTheme* GetActiveTheme()                                                                   zCall( 0x004E5510 );
    virtual int PlayJingleByScript( zSTRING const& )                                                         zCall( 0x004E5520 );
    virtual void StopJingleByScript( zSTRING const& )                                                        zCall( 0x004E5530 );
    virtual zCMusicJingle* LoadJingleByScript( zSTRING const& )                                              zCall( 0x004E5540 );
    virtual zCMusicJingle* LoadJingle( zSTRING const& )                                                      zCall( 0x004E5550 );
    virtual int PlayJingle( zCMusicJingle const*, float const&, zTMus_TransSubType const& )                  zCall( 0x004E5560 );
    virtual void StopJingle( int const& )                                                                    zCall( 0x004E5570 );
    virtual int IsJingleActive( int const& )                                                                 zCall( 0x004E5580 );
    virtual void DoMusicUpdate()                                                                             zPureCall;
    virtual void AddEventCallBackFunc( zTMus_EventType const&, void( __cdecl* )( zTMus_EventType const& ))   zCall( 0x004E5590 );
    virtual void RemoveEventCallBackFunc( void( __cdecl* )( zTMus_EventType const& ))                        zCall( 0x004E55A0 );
    virtual void Mute()                                                                                      zCall( 0x004E55B0 );
    virtual void Stop()                                                                                      zCall( 0x004E55C0 );
    virtual void SetVolume( float )                                                                          zCall( 0x004E55D0 );
    virtual float GetVolume() const                                                                          zCall( 0x004E55E0 );
    virtual int IsAvailable( zSTRING const& )                                                                zCall( 0x004E55F0 );

    // static properties
    static int& s_musicSystemDisabled;

    // user API
    #include "zCMusicSystem.inl"
  };

  // sizeof 0Ch
  class zCMusicSys_Dummy : public zCMusicSystem {
  public:

    zCMusicSys_Dummy() {}
    virtual ~zCMusicSys_Dummy()                                 zCall( 0x00631850 );
    virtual zCMusicTheme* LoadThemeByScript( zSTRING const& )   zCall( 0x0062B4C0 );
    virtual zCMusicTheme* LoadTheme( zSTRING const& )           zCall( 0x0062B510 );
    virtual zCMusicJingle* LoadJingleByScript( zSTRING const& ) zCall( 0x0062B560 );
    virtual zCMusicJingle* LoadJingle( zSTRING const& )         zCall( 0x0062B5C0 );
    virtual void DoMusicUpdate()                                zCall( 0x0062B620 );

    // user API
    #include "zCMusicSys_Dummy.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZMUSIC_H__VER2__