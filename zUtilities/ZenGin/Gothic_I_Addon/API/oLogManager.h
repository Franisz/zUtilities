// Supported with union (c) 2018 Union team

#ifndef __OLOG_MANAGER_H__VER1__
#define __OLOG_MANAGER_H__VER1__

namespace Gothic_I_Addon {

  class oCLogEntry {
  public:
    zSTRING m_strDescription;

    oCLogEntry() {}
    void Archive( zCArchiver& )   zCall( 0x0076D5D0 );
    void Unarchive( zCArchiver& ) zCall( 0x0076D5F0 );
    ~oCLogEntry()                 zCall( 0x0076D680 );

    // user API
    #include "oCLogEntry.inl"
  };

  class oCLogTopic {
  public:
    enum zELogTopicStatus {
      zELogTopicStatus_Free,
      zELogTopicStatus_Running,
      zELogTopicStatus_Success,
      zELogTopicStatus_Failure,
      zELogTopicStatus_Obsolete
    };

    enum zELogSection {
      zELogSection_Missions,
      zELogSection_Notes,
      zELogSection_All
    };

    zSTRING m_strDescription;
    zELogSection m_enuSection;
    zELogTopicStatus m_enuStatus;
    zCList<oCLogEntry> m_lstEntries;

    oCLogTopic() {}
    ~oCLogTopic()                              zCall( 0x0076CD50 );
    void __fastcall AddEntry( zSTRING const& ) zCall( 0x0076D0B0 );
    void __fastcall Archive( zCArchiver& )     zCall( 0x0076D300 );
    void __fastcall Unarchive( zCArchiver& )   zCall( 0x0076D3C0 );

    // statics
    static char**& ms_strSections;
    static char**& ms_strStati;

    // user API
    #include "oCLogTopic.inl"
  };

  class oCLogManager {
  public:
    zCList<oCLogTopic> m_lstTopics;

    void oCLogManager_OnInit( oCLogManager const& ) zCall( 0x0076CBD0 );
    void oCLogManager_OnInit()                      zCall( 0x0076CBF0 );
    oCLogManager& operator =( oCLogManager const& ) zCall( 0x0076CBC0 );
    oCLogManager( oCLogManager const& a0 )          zInit( oCLogManager_OnInit( a0 ));
    oCLogManager()                                  zInit( oCLogManager_OnInit() );
    ~oCLogManager()                                 zCall( 0x0076CC00 );
    void __fastcall Clear()                         zCall( 0x0076CCE0 );
    void __fastcall Archive( zCArchiver& )          zCall( 0x0076CE50 );
    void __fastcall Unarchive( zCArchiver& )        zCall( 0x0076CEB0 );
    static oCLogManager& GetLogManager()            zCall( 0x0076CB70 );

    // user API
    #include "oCLogManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OLOG_MANAGER_H__VER1__