// Supported with union (c) 2018 Union team

#ifndef __ZMUSIC_H__VER0__
#define __ZMUSIC_H__VER0__

namespace Gothic_I_Classic {
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

  class zCMusicTheme {
  public:
    zSTRING fileName;
    float vol;
    int loop;
    float reverbMix;
    float reverbTime;
    zTMus_TransType trType;
    zTMus_TransSubType trSubType;
    unsigned char dScriptEnd;
    zSTRING name;

    void zCMusicTheme_OnInit()   zCall( 0x004DABE0 );
    zCMusicTheme()               zInit( zCMusicTheme_OnInit() );
    virtual ~zCMusicTheme()      zCall( 0x004DA190 );
    virtual int IsActive() const zCall( 0x004DA210 );

    // user API
    #include "zCMusicTheme.inl"
  };

  class zCMusicJingle {
  public:
    zSTRING fileName;
    int loop;
    float vol;
    zTMus_TransSubType trSubType;
    unsigned char dScriptEnd;
    int refCtr;
    zSTRING name;

    void zCMusicJingle_OnInit()     zCall( 0x004DAC20 );
    zCMusicJingle()                 zInit( zCMusicJingle_OnInit() );
    virtual ~zCMusicJingle()        zCall( 0x004DAC70 );
    virtual zCMusicJingle* AddRef() zCall( 0x004DACF0 );
    virtual int Release()           zCall( 0x004DAD00 );
    virtual int IsPlaying() const   zCall( 0x004DAD10 );
    virtual void StopPlaying()      zCall( 0x004DAD20 );
    virtual void CacheIn()          zCall( 0x004DAD30 );
    virtual void CacheOut()         zCall( 0x004DAD40 );

    // user API
    #include "zCMusicJingle.inl"
  };

  class zCMusicSystem {
  public:
    float volume;
    float reverb;

    zCMusicSystem() {}
    static void DisableMusicSystem( int )                                                                    zCall( 0x004DA050 );
    virtual ~zCMusicSystem()                                                                                 zCall( 0x004DAD70 );
    virtual void PlayThemeByScript( zSTRING const&, int, int* )                                              zCall( 0x004DAD80 );
    virtual zCMusicTheme* LoadThemeByScript( zSTRING const& )                                                zCall( 0x004DAD90 );
    virtual zCMusicTheme* LoadTheme( zSTRING const& )                                                        zCall( 0x004DADA0 );
    virtual void PlayTheme( zCMusicTheme*, float const&, zTMus_TransType const&, zTMus_TransSubType const& ) zCall( 0x004DADB0 );
    virtual zCMusicTheme* GetActiveTheme()                                                                   zCall( 0x004DADC0 );
    virtual int PlayJingleByScript( zSTRING const& )                                                         zCall( 0x004DADD0 );
    virtual void StopJingleByScript( zSTRING const& )                                                        zCall( 0x004DADE0 );
    virtual zCMusicJingle* LoadJingleByScript( zSTRING const& )                                              zCall( 0x004DADF0 );
    virtual zCMusicJingle* LoadJingle( zSTRING const& )                                                      zCall( 0x004DAE00 );
    virtual int PlayJingle( zCMusicJingle const*, float const&, zTMus_TransSubType const& )                  zCall( 0x004DAE10 );
    virtual void StopJingle( int const& )                                                                    zCall( 0x004DAE20 );
    virtual int IsJingleActive( int const& )                                                                 zCall( 0x004DAE30 );
    virtual void DoMusicUpdate()                                                                             zPureCall;
    virtual void AddEventCallBackFunc( zTMus_EventType const&, void( __cdecl* )( zTMus_EventType const& ))   zCall( 0x004DAE40 );
    virtual void RemoveEventCallBackFunc( void( __cdecl* )( zTMus_EventType const& ))                        zCall( 0x004DAE50 );
    virtual void Mute()                                                                                      zCall( 0x004DAE60 );
    virtual void Stop()                                                                                      zCall( 0x004DAE70 );
    virtual void SetVolume( float )                                                                          zCall( 0x004DAE80 );
    virtual float GetVolume() const                                                                          zCall( 0x004DAE90 );
    virtual int IsAvailable( zSTRING const& )                                                                zCall( 0x004DAEA0 );

    // static properties
    static int& s_musicSystemDisabled;

    // user API
    #include "zCMusicSystem.inl"
  };

  class zCMusicSys_Dummy : public zCMusicSystem {
  public:

    zCMusicSys_Dummy() {}
    virtual ~zCMusicSys_Dummy()                                 zCall( 0x00608910 );
    virtual zCMusicTheme* LoadThemeByScript( zSTRING const& )   zCall( 0x00603930 );
    virtual zCMusicTheme* LoadTheme( zSTRING const& )           zCall( 0x00603990 );
    virtual zCMusicJingle* LoadJingleByScript( zSTRING const& ) zCall( 0x006039F0 );
    virtual zCMusicJingle* LoadJingle( zSTRING const& )         zCall( 0x00603A60 );
    virtual void DoMusicUpdate()                                zCall( 0x00603AD0 );

    // user API
    #include "zCMusicSys_Dummy.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZMUSIC_H__VER0__