// Supported with union (c) 2018-2021 Union team

#ifndef __OINFO_H__VER0__
#define __OINFO_H__VER0__

namespace Gothic_I_Classic {
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
    ~oCInfoChoice() zCall( 0x00665D50 );

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
      ~Tpd() zCall( 0x00665600 );

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

    void oCInfo_OnInit()                  zCall( 0x006654C0 );
    oCInfo()                              zInit( oCInfo_OnInit() );
    ~oCInfo()                             zCall( 0x00665530 );
    void SetInstance( int )               zCall( 0x00665650 );
    int GetInstance()                     zCall( 0x006657F0 );
    int DoCheck()                         zCall( 0x00665800 );
    int GetNpcID()                        zCall( 0x00665810 );
    int GetConditionFunc()                zCall( 0x00665820 );
    int WasTold()                         zCall( 0x00665830 );
    void SetTold( int )                   zCall( 0x00665840 );
    int GetDataSize()                     zCall( 0x00665850 );
    void* GetDataAdr()                    zCall( 0x00665860 );
    zSTRING& GetText()                    zCall( 0x00665870 );
    int InfoConditions()                  zCall( 0x00665880 );
    void Info()                           zCall( 0x006658A0 );
    void AddChoice( zSTRING, int )        zCall( 0x00665A50 );
    void RemoveChoice( zSTRING )          zCall( 0x00665B70 );
    void RemoveAllChoices()               zCall( 0x00665CC0 );
    virtual void Archive( zCArchiver& )   zCall( 0x006658C0 );
    virtual void Unarchive( zCArchiver& ) zCall( 0x00665900 );
    virtual void RestoreParserInstance()  zCall( 0x00665A30 );

    // user API
    #include "oCInfo.inl"
  };

  // sizeof 14h
  class oCInfoManager {
  public:
    zCListSort<oCInfo> infoList; // sizeof 0Ch    offset 04h
    zCParser* p;                 // sizeof 04h    offset 10h

    oCInfoManager() {}
    void oCInfoManager_OnInit( zCParser* )            zCall( 0x00664520 );
    oCInfoManager( zCParser* a0 )                     zInit( oCInfoManager_OnInit( a0 ));
    ~oCInfoManager()                                  zCall( 0x00664810 );
    oCInfo* GetInformation( oCNpc*, oCNpc*, int )     zCall( 0x006648A0 );
    oCInfo* GetInformation( int )                     zCall( 0x00664A00 );
    int GetInfoCount( oCNpc*, oCNpc* )                zCall( 0x00664A30 );
    int GetInfoCountImportant( oCNpc*, oCNpc* )       zCall( 0x00664B90 );
    int GetInfoCountUnimportant( oCNpc*, oCNpc* )     zCall( 0x00664CF0 );
    oCInfo* GetInfo( oCNpc*, oCNpc*, int )            zCall( 0x00664E50 );
    oCInfo* GetInfoImportant( oCNpc*, oCNpc*, int )   zCall( 0x00664FB0 );
    oCInfo* GetInfoUnimportant( oCNpc*, oCNpc*, int ) zCall( 0x00665120 );
    int InformationTold( int )                        zCall( 0x00665290 );
    static int CompareInfos( oCInfo*, oCInfo* )       zCall( 0x006647E0 );
    virtual void Archive( zCArchiver& )               zCall( 0x006652D0 );
    virtual void Unarchive( zCArchiver& )             zCall( 0x00665330 );
    virtual void RestoreParserInstances()             zCall( 0x006654A0 );

    // static properties
    static int& size_checked;

    // user API
    #include "oCInfoManager.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OINFO_H__VER0__