// Supported with union (c) 2018-2021 Union team

#ifndef __ZMUSIC_H__VER1__
#define __ZMUSIC_H__VER1__

namespace Gothic_I_Addon {
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

    void zCMusicTheme_OnInit()   zCall( 0x004EBD50 );
    zCMusicTheme()               zInit( zCMusicTheme_OnInit() );
    virtual ~zCMusicTheme()      zCall( 0x004EB390 );
    virtual int IsActive() const zCall( 0x004EB430 );

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

    void zCMusicJingle_OnInit()     zCall( 0x004EBD90 );
    zCMusicJingle()                 zInit( zCMusicJingle_OnInit() );
    virtual ~zCMusicJingle()        zCall( 0x004EBDE0 );
    virtual zCMusicJingle* AddRef() zCall( 0x004EBE80 );
    virtual int Release()           zCall( 0x004EBE90 );
    virtual int IsPlaying() const   zCall( 0x004EBEA0 );
    virtual void StopPlaying()      zCall( 0x004EBEB0 );
    virtual void CacheIn()          zCall( 0x004EBEC0 );
    virtual void CacheOut()         zCall( 0x004EBED0 );

    // user API
    #include "zCMusicJingle.inl"
  };

  // sizeof 0Ch
  class zCMusicSystem {
  public:
    float volume; // sizeof 04h    offset 04h
    float reverb; // sizeof 04h    offset 08h

    zCMusicSystem() {}
    static void DisableMusicSystem( int )                                                                    zCall( 0x004EB200 );
    virtual ~zCMusicSystem()                                                                                 zCall( 0x004EBF00 );
    virtual void PlayThemeByScript( zSTRING const&, int, int* )                                              zCall( 0x004EBF10 );
    virtual zCMusicTheme* LoadThemeByScript( zSTRING const& )                                                zCall( 0x004EBF20 );
    virtual zCMusicTheme* LoadTheme( zSTRING const& )                                                        zCall( 0x004EBF30 );
    virtual void PlayTheme( zCMusicTheme*, float const&, zTMus_TransType const&, zTMus_TransSubType const& ) zCall( 0x004EBF40 );
    virtual zCMusicTheme* GetActiveTheme()                                                                   zCall( 0x004EBF50 );
    virtual int PlayJingleByScript( zSTRING const& )                                                         zCall( 0x004EBF60 );
    virtual void StopJingleByScript( zSTRING const& )                                                        zCall( 0x004EBF70 );
    virtual zCMusicJingle* LoadJingleByScript( zSTRING const& )                                              zCall( 0x004EBF80 );
    virtual zCMusicJingle* LoadJingle( zSTRING const& )                                                      zCall( 0x004EBF90 );
    virtual int PlayJingle( zCMusicJingle const*, float const&, zTMus_TransSubType const& )                  zCall( 0x004EBFA0 );
    virtual void StopJingle( int const& )                                                                    zCall( 0x004EBFB0 );
    virtual int IsJingleActive( int const& )                                                                 zCall( 0x004EBFC0 );
    virtual void DoMusicUpdate()                                                                             zPureCall;
    virtual void AddEventCallBackFunc( zTMus_EventType const&, void( __cdecl* )( zTMus_EventType const& ))   zCall( 0x004EBFD0 );
    virtual void RemoveEventCallBackFunc( void( __cdecl* )( zTMus_EventType const& ))                        zCall( 0x004EBFE0 );
    virtual void Mute()                                                                                      zCall( 0x004EBFF0 );
    virtual void Stop()                                                                                      zCall( 0x004EC000 );
    virtual void SetVolume( float )                                                                          zCall( 0x004EC010 );
    virtual float GetVolume() const                                                                          zCall( 0x004EC020 );
    virtual int IsAvailable( zSTRING const& )                                                                zCall( 0x004EC030 );

    // static properties
    static int& s_musicSystemDisabled;

    // user API
    #include "zCMusicSystem.inl"
  };

  // sizeof 0Ch
  class zCMusicSys_Dummy : public zCMusicSystem {
  public:

    zCMusicSys_Dummy() {}
    virtual ~zCMusicSys_Dummy()                                 zCall( 0x0062AD90 );
    virtual zCMusicTheme* LoadThemeByScript( zSTRING const& )   zCall( 0x00625980 );
    virtual zCMusicTheme* LoadTheme( zSTRING const& )           zCall( 0x006259E0 );
    virtual zCMusicJingle* LoadJingleByScript( zSTRING const& ) zCall( 0x00625A40 );
    virtual zCMusicJingle* LoadJingle( zSTRING const& )         zCall( 0x00625AB0 );
    virtual void DoMusicUpdate()                                zCall( 0x00625B20 );

    // user API
    #include "zCMusicSys_Dummy.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZMUSIC_H__VER1__