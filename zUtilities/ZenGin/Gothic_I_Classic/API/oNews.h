// Supported with union (c) 2018-2021 Union team

#ifndef __ONEWS_H__VER0__
#define __ONEWS_H__VER0__

namespace Gothic_I_Classic {
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

    void oCNews_OnInit()                                              zCall( 0x00688670 );
    void oCNews_OnInit( int, int, oCNpc*, oCNpc*, oCNpc*, int )       zCall( 0x00688830 );
    oCNews()                                                          zInit( oCNews_OnInit() );
    oCNews( int a0, int a1, oCNpc* a2, oCNpc* a3, oCNpc* a4, int a5 ) zInit( oCNews_OnInit( a0, a1, a2, a3, a4, a5 ));
    ~oCNews()                                                         zCall( 0x00688A30 );
    int GetID()                                                       zCall( 0x00688BA0 );
    int IsIdentical( int, oCNpc*, oCNpc* )                            zCall( 0x00688BB0 );
    void SetSpreadTime( float )                                       zCall( 0x00688BE0 );
    float GetSpreadTime()                                             zCall( 0x00688C10 );
    void SetGossip( int )                                             zCall( 0x00688C20 );
    int IsGossip()                                                    zCall( 0x00688C40 );
    int IsGuildVictim()                                               zCall( 0x00688C50 );
    void GetNewsData( int&, int&, oCNpc*&, oCNpc*&, oCNpc*& )         zCall( 0x00688C60 );
    static int GetRemainingNews()                                     zCall( 0x00688220 );
    static void CheckRemainingNews()                                  zCall( 0x00688230 );
    virtual void Archive( zCArchiver& )                               zCall( 0x00688D70 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x00688FD0 );

    // static properties
    static int& news_counter;

    // user API
    #include "oCNews.inl"
  };

  // sizeof 0Ch
  class oCNewsMemory {
  public:
    zCList<oCNews> iknow; // sizeof 08h    offset 04h

    void oCNewsMemory_OnInit()             zCall( 0x00687470 );
    oCNewsMemory()                         zInit( oCNewsMemory_OnInit() );
    ~oCNewsMemory()                        zCall( 0x00687490 );
    void Insert( oCNews* )                 zCall( 0x006875A0 );
    void Remove( oCNews* )                 zCall( 0x00687680 );
    oCNews* GetNews( int, oCNpc*, oCNpc* ) zCall( 0x00687700 );
    void CheckSpreadNews()                 zCall( 0x00687740 );
    int SearchNews( int, oCNpc*, oCNpc* )  zCall( 0x006877D0 );
    void ShowDebugInfos()                  zCall( 0x00687850 );
    oCNews* GetNewsByNumber( int )         zCall( 0x00687DE0 );
    void ClearNews()                       zCall( 0x00687E10 );
    int DeleteNewsByNumber( int )          zCall( 0x00687F20 );
    virtual void Archive( zCArchiver& )    zCall( 0x00687FC0 );
    virtual void Unarchive( zCArchiver& )  zCall( 0x00688040 );

    // user API
    #include "oCNewsMemory.inl"
  };

  // sizeof 58h
  class oCNewsManager {
  public:
    int called_BAssessAndMem;  // sizeof 04h    offset 00h
    int sentry;                // sizeof 04h    offset 04h
    int spreadList[MAX_ENTRY]; // sizeof 50h    offset 08h

    void oCNewsManager_OnInit()                              zCall( 0x00686B70 );
    oCNewsManager()                                          zInit( oCNewsManager_OnInit() );
    ~oCNewsManager()                                         zCall( 0x00686B90 );
    void CreateNews( int, int, oCNpc*, oCNpc*, oCNpc*, int ) zCall( 0x00686BA0 );
    void SpreadToGuild( int )                                zCall( 0x00686EB0 );
    int IsInSpreadList( int )                                zCall( 0x00686ED0 );
    void SpreadNews( oCNews* )                               zCall( 0x00686F00 );

    // user API
    #include "oCNewsManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ONEWS_H__VER0__