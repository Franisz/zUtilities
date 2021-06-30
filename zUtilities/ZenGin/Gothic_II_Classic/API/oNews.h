// Supported with union (c) 2018 Union team

#ifndef __ONEWS_H__VER2__
#define __ONEWS_H__VER2__

namespace Gothic_II_Classic {
  const int MAX_ENTRY = 20;

  typedef enum oENewsSpreadType {
    NEWS_DONT_SPREAD,
    NEWS_SPREAD_NPC_FRIENDLY_TOWARDS_VICTIM,
    NEWS_SPREAD_NPC_FRIENDLY_TOWARDS_WITNESS,
    NEWS_SPREAD_NPC_FRIENDLY_TOWARDS_OFFENDER,
    NEWS_SPREAD_NPC_SAME_GUILD_VICTIM
  } oTNewsSpreadType;

  class oCNews {
  public:
    int told;
    float spread_time;
    oTNewsSpreadType spreadType;
    int news_id;
    int gossip;
    oCNpc* mNpcWitness;
    oCNpc* mNpcOffender;
    oCNpc* mNpcVictim;
    zSTRING witnessName;
    zSTRING offenderName;
    zSTRING victimName;
    int guildvictim;

    void oCNews_OnInit()                                              zCall( 0x006CC7A0 );
    void oCNews_OnInit( int, int, oCNpc*, oCNpc*, oCNpc*, int )       zCall( 0x006CC940 );
    oCNews()                                                          zInit( oCNews_OnInit() );
    oCNews( int a0, int a1, oCNpc* a2, oCNpc* a3, oCNpc* a4, int a5 ) zInit( oCNews_OnInit( a0, a1, a2, a3, a4, a5 ));
    ~oCNews()                                                         zCall( 0x006CCBC0 );
    int GetID()                                                       zCall( 0x006CCD30 );
    int IsIdentical( int, oCNpc*, oCNpc* )                            zCall( 0x006CCD40 );
    void SetSpreadTime( float )                                       zCall( 0x006CCD70 );
    float GetSpreadTime()                                             zCall( 0x006CCDA0 );
    void SetGossip( int )                                             zCall( 0x006CCDB0 );
    int IsGossip()                                                    zCall( 0x006CCDD0 );
    int IsGuildVictim()                                               zCall( 0x006CCDE0 );
    void GetNewsData( int&, int&, oCNpc*&, oCNpc*&, oCNpc*& )         zCall( 0x006CCDF0 );
    static int GetRemainingNews()                                     zCall( 0x006CC2E0 );
    static void CheckRemainingNews()                                  zCall( 0x006CC2F0 );
    virtual void Archive( zCArchiver& )                               zCall( 0x006CCF00 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x006CD160 );

    // static properties
    static int& news_counter;

    // user API
    #include "oCNews.inl"
  };

  class oCNewsMemory {
  public:
    zCList<oCNews> iknow;

    void oCNewsMemory_OnInit()             zCall( 0x006CB4F0 );
    oCNewsMemory()                         zInit( oCNewsMemory_OnInit() );
    ~oCNewsMemory()                        zCall( 0x006CB510 );
    void Insert( oCNews* )                 zCall( 0x006CB620 );
    void Remove( oCNews* )                 zCall( 0x006CB700 );
    oCNews* GetNews( int, oCNpc*, oCNpc* ) zCall( 0x006CB780 );
    void CheckSpreadNews()                 zCall( 0x006CB7C0 );
    int SearchNews( int, oCNpc*, oCNpc* )  zCall( 0x006CB850 );
    void ShowDebugInfos()                  zCall( 0x006CB8D0 );
    oCNews* GetNewsByNumber( int )         zCall( 0x006CBED0 );
    void ClearNews()                       zCall( 0x006CBF00 );
    int DeleteNewsByNumber( int )          zCall( 0x006CC010 );
    virtual void Archive( zCArchiver& )    zCall( 0x006CC0B0 );
    virtual void Unarchive( zCArchiver& )  zCall( 0x006CC130 );

    // user API
    #include "oCNewsMemory.inl"
  };

  class oCNewsManager {
  public:
    int called_BAssessAndMem;
    int sentry;
    int spreadList[MAX_ENTRY];

    void oCNewsManager_OnInit()                              zCall( 0x006CABF0 );
    oCNewsManager()                                          zInit( oCNewsManager_OnInit() );
    ~oCNewsManager()                                         zCall( 0x006CAC10 );
    void CreateNews( int, int, oCNpc*, oCNpc*, oCNpc*, int ) zCall( 0x006CAC20 );
    void SpreadToGuild( int )                                zCall( 0x006CAF20 );
    int IsInSpreadList( int )                                zCall( 0x006CAF40 );
    void SpreadNews( oCNews* )                               zCall( 0x006CAF70 );

    // user API
    #include "oCNewsManager.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ONEWS_H__VER2__