// Supported with union (c) 2018 Union team

#ifndef __OLOG_MANAGER_H__VER0__
#define __OLOG_MANAGER_H__VER0__

namespace Gothic_I_Classic {

  class oCLogEntry {
  public:
    zSTRING m_strDescription;

    oCLogEntry() {}
    void Archive( zCArchiver& )   zCall( 0x0072EF50 );
    void Unarchive( zCArchiver& ) zCall( 0x0072EF70 );
    ~oCLogEntry()                 zCall( 0x0072F000 );

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
    ~oCLogTopic()                              zCall( 0x0072E720 );
    void __fastcall AddEntry( zSTRING const& ) zCall( 0x0072EA60 );
    void __fastcall Archive( zCArchiver& )     zCall( 0x0072ECA0 );
    void __fastcall Unarchive( zCArchiver& )   zCall( 0x0072ED60 );

    // statics
    static char**& ms_strSections;
    static char**& ms_strStati;

    // user API
    #include "oCLogTopic.inl"
  };

  class oCLogManager {
  public:
    zCList<oCLogTopic> m_lstTopics;

    void oCLogManager_OnInit( oCLogManager const& ) zCall( 0x0072E5A0 );
    void oCLogManager_OnInit()                      zCall( 0x0072E5C0 );
    oCLogManager& operator =( oCLogManager const& ) zCall( 0x0072E590 );
    oCLogManager( oCLogManager const& a0 )          zInit( oCLogManager_OnInit( a0 ));
    oCLogManager()                                  zInit( oCLogManager_OnInit() );
    ~oCLogManager()                                 zCall( 0x0072E5D0 );
    void __fastcall Clear()                         zCall( 0x0072E6B0 );
    void __fastcall Archive( zCArchiver& )          zCall( 0x0072E810 );
    void __fastcall Unarchive( zCArchiver& )        zCall( 0x0072E880 );
    static oCLogManager& GetLogManager()            zCall( 0x0072E540 );

    // user API
    #include "oCLogManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OLOG_MANAGER_H__VER0__