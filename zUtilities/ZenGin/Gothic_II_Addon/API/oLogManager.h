// Supported with union (c) 2018 Union team

#ifndef __OLOG_MANAGER_H__VER3__
#define __OLOG_MANAGER_H__VER3__

namespace Gothic_II_Addon {

  class oCLogEntry {
  public:
    zSTRING m_strDescription;

    oCLogEntry() {}
    void Archive( zCArchiver& )   zCall( 0x00663D10 );
    void Unarchive( zCArchiver& ) zCall( 0x00663D30 );
    ~oCLogEntry()                 zCall( 0x00663DF0 );

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
    ~oCLogTopic()                              zCall( 0x00663550 );
    void __fastcall AddEntry( zSTRING const& ) zCall( 0x00663870 );
    void __fastcall Archive( zCArchiver& )     zCall( 0x00663A80 );
    void __fastcall Unarchive( zCArchiver& )   zCall( 0x00663B40 );

    // statics
    static char**& ms_strSections;
    static char**& ms_strStati;

    // user API
    #include "oCLogTopic.inl"
  };

  class oCLogManager {
  public:
    zCList<oCLogTopic> m_lstTopics;

    void oCLogManager_OnInit( oCLogManager const& ) zCall( 0x006633D0 );
    void oCLogManager_OnInit()                      zCall( 0x006633F0 );
    oCLogManager& operator =( oCLogManager const& ) zCall( 0x006633C0 );
    oCLogManager( oCLogManager const& a0 )          zInit( oCLogManager_OnInit( a0 ));
    oCLogManager()                                  zInit( oCLogManager_OnInit() );
    ~oCLogManager()                                 zCall( 0x00663400 );
    void __fastcall Clear()                         zCall( 0x006634E0 );
    void __fastcall Archive( zCArchiver& )          zCall( 0x00663640 );
    void __fastcall Unarchive( zCArchiver& )        zCall( 0x006636B0 );
    static oCLogManager& GetLogManager()            zCall( 0x00663370 );

    // user API
    #include "oCLogManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OLOG_MANAGER_H__VER3__