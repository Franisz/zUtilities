// Supported with union (c) 2018-2021 Union team

#ifndef __OLOG_MANAGER_H__VER0__
#define __OLOG_MANAGER_H__VER0__

namespace Gothic_I_Classic {

  // sizeof 14h
  class oCLogEntry {
  public:
    zSTRING m_strDescription; // sizeof 14h    offset 00h

    oCLogEntry() {}
    void Archive( zCArchiver& )   zCall( 0x0072EF50 );
    void Unarchive( zCArchiver& ) zCall( 0x0072EF70 );
    ~oCLogEntry()                 zCall( 0x0072F000 );

    // user API
    #include "oCLogEntry.inl"
  };

  // sizeof 24h
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

    zSTRING m_strDescription;        // sizeof 14h    offset 00h
    zELogSection m_enuSection;       // sizeof 04h    offset 14h
    zELogTopicStatus m_enuStatus;    // sizeof 04h    offset 18h
    zCList<oCLogEntry> m_lstEntries; // sizeof 08h    offset 1Ch

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

  // sizeof 08h
  class oCLogManager {
  public:
    zCList<oCLogTopic> m_lstTopics; // sizeof 08h    offset 00h

    void oCLogManager_OnInit( oCLogManager const& ) zCall( 0x0072E5A0 );
    void oCLogManager_OnInit()                      zCall( 0x0072E5C0 );

  private:
    oCLogManager& operator =( oCLogManager const& ) zCall( 0x0072E590 );
    oCLogManager( oCLogManager const& a0 )          zInit( oCLogManager_OnInit( a0 ));
    oCLogManager()                                  zInit( oCLogManager_OnInit() );

  public:
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