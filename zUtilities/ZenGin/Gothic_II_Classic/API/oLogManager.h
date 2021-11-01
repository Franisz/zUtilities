// Supported with union (c) 2018-2021 Union team

#ifndef __OLOG_MANAGER_H__VER2__
#define __OLOG_MANAGER_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 14h
  class oCLogEntry {
  public:
    zSTRING m_strDescription; // sizeof 14h    offset 00h

    oCLogEntry() {}
    void Archive( zCArchiver& )   zCall( 0x0077AAD0 );
    void Unarchive( zCArchiver& ) zCall( 0x0077AAF0 );
    ~oCLogEntry()                 zCall( 0x0077AB80 );

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
    ~oCLogTopic()                              zCall( 0x0077A310 );
    void __fastcall AddEntry( zSTRING const& ) zCall( 0x0077A630 );
    void __fastcall Archive( zCArchiver& )     zCall( 0x0077A840 );
    void __fastcall Unarchive( zCArchiver& )   zCall( 0x0077A900 );

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

    void oCLogManager_OnInit( oCLogManager const& ) zCall( 0x0077A190 );
    void oCLogManager_OnInit()                      zCall( 0x0077A1B0 );

  private:
    oCLogManager& operator =( oCLogManager const& ) zCall( 0x0077A180 );
    oCLogManager( oCLogManager const& a0 )          zInit( oCLogManager_OnInit( a0 ));
    oCLogManager()                                  zInit( oCLogManager_OnInit() );

  public:
    ~oCLogManager()                                 zCall( 0x0077A1C0 );
    void __fastcall Clear()                         zCall( 0x0077A2A0 );
    void __fastcall Archive( zCArchiver& )          zCall( 0x0077A400 );
    void __fastcall Unarchive( zCArchiver& )        zCall( 0x0077A470 );
    static oCLogManager& GetLogManager()            zCall( 0x0077A130 );

    // user API
    #include "oCLogManager.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OLOG_MANAGER_H__VER2__