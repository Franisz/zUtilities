// Supported with union (c) 2018-2021 Union team

#ifndef __ONEWS_H__VER3__
#define __ONEWS_H__VER3__

namespace Gothic_II_Addon {
  const int MAX_ENTRY = 20;

  typedef enum oENewsSpreadType {
    NEWS_DONT_SPREAD,
    NEWS_SPREAD_NPC_FRIENDLY_TOWARDS_VICTIM,
    NEWS_SPREAD_NPC_FRIENDLY_TOWARDS_WITNESS,
    NEWS_SPREAD_NPC_FRIENDLY_TOWARDS_OFFENDER,
    NEWS_SPREAD_NPC_SAME_GUILD_VICTIM
  } oTNewsSpreadType;

  // sizeof 64h
  class oCNews {
  public:
    int told;                    // sizeof 04h    offset 04h
    float spread_time;           // sizeof 04h    offset 08h
    oTNewsSpreadType spreadType; // sizeof 04h    offset 0Ch
    int news_id;                 // sizeof 04h    offset 10h
    int gossip;                  // sizeof 04h    offset 14h
    oCNpc* mNpcWitness;          // sizeof 04h    offset 18h
    oCNpc* mNpcOffender;         // sizeof 04h    offset 1Ch
    oCNpc* mNpcVictim;           // sizeof 04h    offset 20h
    zSTRING witnessName;         // sizeof 14h    offset 24h
    zSTRING offenderName;        // sizeof 14h    offset 38h
    zSTRING victimName;          // sizeof 14h    offset 4Ch
    int guildvictim;             // sizeof 04h    offset 60h

    void oCNews_OnInit()                                              zCall( 0x0072A830 );
    void oCNews_OnInit( int, int, oCNpc*, oCNpc*, oCNpc*, int )       zCall( 0x0072A9D0 );
    oCNews()                                                          zInit( oCNews_OnInit() );
    oCNews( int a0, int a1, oCNpc* a2, oCNpc* a3, oCNpc* a4, int a5 ) zInit( oCNews_OnInit( a0, a1, a2, a3, a4, a5 ));
    ~oCNews()                                                         zCall( 0x0072AC50 );
    int GetID()                                                       zCall( 0x0072ADC0 );
    int IsIdentical( int, oCNpc*, oCNpc* )                            zCall( 0x0072ADD0 );
    void SetSpreadTime( float )                                       zCall( 0x0072AE00 );
    float GetSpreadTime()                                             zCall( 0x0072AE30 );
    void SetGossip( int )                                             zCall( 0x0072AE40 );
    int IsGossip()                                                    zCall( 0x0072AE60 );
    int IsGuildVictim()                                               zCall( 0x0072AE70 );
    void GetNewsData( int&, int&, oCNpc*&, oCNpc*&, oCNpc*& )         zCall( 0x0072AE80 );
    static int GetRemainingNews()                                     zCall( 0x0072A370 );
    static void CheckRemainingNews()                                  zCall( 0x0072A380 );
    virtual void Archive( zCArchiver& )                               zCall( 0x0072AF90 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x0072B1F0 );

    // static properties
    static int& news_counter;

    // user API
    #include "oCNews.inl"
  };

  // sizeof 0Ch
  class oCNewsMemory {
  public:
    zCList<oCNews> iknow; // sizeof 08h    offset 04h

    void oCNewsMemory_OnInit()             zCall( 0x00729580 );
    oCNewsMemory()                         zInit( oCNewsMemory_OnInit() );
    ~oCNewsMemory()                        zCall( 0x007295A0 );
    void Insert( oCNews* )                 zCall( 0x007296B0 );
    void Remove( oCNews* )                 zCall( 0x00729790 );
    oCNews* GetNews( int, oCNpc*, oCNpc* ) zCall( 0x00729810 );
    void CheckSpreadNews()                 zCall( 0x00729850 );
    int SearchNews( int, oCNpc*, oCNpc* )  zCall( 0x007298E0 );
    void ShowDebugInfos()                  zCall( 0x00729960 );
    oCNews* GetNewsByNumber( int )         zCall( 0x00729F60 );
    void ClearNews()                       zCall( 0x00729F90 );
    int DeleteNewsByNumber( int )          zCall( 0x0072A0A0 );
    virtual void Archive( zCArchiver& )    zCall( 0x0072A140 );
    virtual void Unarchive( zCArchiver& )  zCall( 0x0072A1C0 );

    // user API
    #include "oCNewsMemory.inl"
  };

  // sizeof 58h
  class oCNewsManager {
  public:
    int called_BAssessAndMem;  // sizeof 04h    offset 00h
    int sentry;                // sizeof 04h    offset 04h
    int spreadList[MAX_ENTRY]; // sizeof 50h    offset 08h

    void oCNewsManager_OnInit()                              zCall( 0x00728C80 );
    oCNewsManager()                                          zInit( oCNewsManager_OnInit() );
    ~oCNewsManager()                                         zCall( 0x00728CA0 );
    void CreateNews( int, int, oCNpc*, oCNpc*, oCNpc*, int ) zCall( 0x00728CB0 );
    void SpreadToGuild( int )                                zCall( 0x00728FB0 );
    int IsInSpreadList( int )                                zCall( 0x00728FD0 );
    void SpreadNews( oCNews* )                               zCall( 0x00729000 );

    // user API
    #include "oCNewsManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ONEWS_H__VER3__