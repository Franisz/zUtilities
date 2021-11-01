// Supported with union (c) 2018-2021 Union team

#ifndef __OINFO_H__VER2__
#define __OINFO_H__VER2__

namespace Gothic_II_Classic {
  const int INF_ANSWER_MAX = 6;

  enum {
    INF_ANSWER_DEFAULT,
    INF_ANSWER_HERO,
    INF_ANSWER_FIGHTER,
    INF_ANSWER_MAGE,
    INF_ANSWER_THIEF,
    INF_ANSWER_PSIONIC
  };

  // sizeof 18h
  class oCInfoChoice {
  public:
    zSTRING Text; // sizeof 14h    offset 00h
    int Function; // sizeof 04h    offset 14h

    oCInfoChoice() {}
    ~oCInfoChoice() zCall( 0x006A6370 );

    // user API
    #include "oCInfoChoice.inl"
  };

  // sizeof 5Ch
  class oCInfo {
  public:
#pragma pack( push, 1 )
    // sizeof 30h
    struct Tpd {
      int npc;             // sizeof 04h    offset 00h
      int nr;              // sizeof 04h    offset 04h
      int important;       // sizeof 04h    offset 08h
      int conditions;      // sizeof 04h    offset 0Ch
      int information;     // sizeof 04h    offset 10h
      zSTRING description; // sizeof 14h    offset 14h
      int trade;           // sizeof 04h    offset 28h
      int permanent;       // sizeof 04h    offset 2Ch

      Tpd() {}
      ~Tpd() zCall( 0x006A5A60 );

      // user API
      #include "oCInfo_Tpd.inl"
    };
#pragma pack( pop )

    oCInfo* next;                     // sizeof 04h    offset 04h
    zSTRING name;                     // sizeof 14h    offset 08h
    Tpd pd;                           // sizeof 30h    offset 1Ch
    int told;                         // sizeof 04h    offset 4Ch
    int instance;                     // sizeof 04h    offset 50h
    zCList<oCInfoChoice> listChoices; // sizeof 08h    offset 54h

    void oCInfo_OnInit()                  zCall( 0x006A5920 );
    oCInfo()                              zInit( oCInfo_OnInit() );
    ~oCInfo()                             zCall( 0x006A5990 );
    void SetInstance( int )               zCall( 0x006A5AB0 );
    int GetInstance()                     zCall( 0x006A5C50 );
    int DoCheck()                         zCall( 0x006A5C60 );
    int GetNpcID()                        zCall( 0x006A5E50 );
    int GetConditionFunc()                zCall( 0x006A5E60 );
    int WasTold()                         zCall( 0x006A5E70 );
    void SetTold( int )                   zCall( 0x006A5E80 );
    int GetDataSize()                     zCall( 0x006A5E90 );
    void* GetDataAdr()                    zCall( 0x006A5EA0 );
    zSTRING& GetText()                    zCall( 0x006A5EB0 );
    int InfoConditions()                  zCall( 0x006A5EC0 );
    void Info()                           zCall( 0x006A5EE0 );
    void AddChoice( zSTRING, int )        zCall( 0x006A6090 );
    void RemoveChoice( zSTRING )          zCall( 0x006A6190 );
    void RemoveAllChoices()               zCall( 0x006A62E0 );
    virtual void Archive( zCArchiver& )   zCall( 0x006A5F00 );
    virtual void Unarchive( zCArchiver& ) zCall( 0x006A5F40 );
    virtual void RestoreParserInstance()  zCall( 0x006A6070 );

    // user API
    #include "oCInfo.inl"
  };

  // sizeof 14h
  class oCInfoManager {
  public:
    zCListSort<oCInfo> infoList; // sizeof 0Ch    offset 04h
    zCParser* p;                 // sizeof 04h    offset 10h

    oCInfoManager() {}
    void oCInfoManager_OnInit( zCParser* )            zCall( 0x006A4960 );
    oCInfoManager( zCParser* a0 )                     zInit( oCInfoManager_OnInit( a0 ));
    ~oCInfoManager()                                  zCall( 0x006A4C90 );
    oCInfo* GetInformation( oCNpc*, oCNpc*, int )     zCall( 0x006A4D20 );
    oCInfo* GetInformation( int )                     zCall( 0x006A4E80 );
    int GetInfoCount( oCNpc*, oCNpc* )                zCall( 0x006A4EB0 );
    int GetInfoCountImportant( oCNpc*, oCNpc* )       zCall( 0x006A5010 );
    int GetInfoCountUnimportant( oCNpc*, oCNpc* )     zCall( 0x006A5170 );
    oCInfo* GetInfo( oCNpc*, oCNpc*, int )            zCall( 0x006A52D0 );
    oCInfo* GetInfoImportant( oCNpc*, oCNpc*, int )   zCall( 0x006A5430 );
    oCInfo* GetInfoUnimportant( oCNpc*, oCNpc*, int ) zCall( 0x006A55A0 );
    int InformationTold( int )                        zCall( 0x006A5710 );
    static int CompareInfos( oCInfo*, oCInfo* )       zCall( 0x006A4C60 );
    virtual void Archive( zCArchiver& )               zCall( 0x006A5750 );
    virtual void Unarchive( zCArchiver& )             zCall( 0x006A57B0 );
    virtual void RestoreParserInstances()             zCall( 0x006A5900 );

    // static properties
    static int& size_checked;

    // user API
    #include "oCInfoManager.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OINFO_H__VER2__