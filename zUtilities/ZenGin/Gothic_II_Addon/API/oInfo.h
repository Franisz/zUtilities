// Supported with union (c) 2018-2021 Union team

#ifndef __OINFO_H__VER3__
#define __OINFO_H__VER3__

namespace Gothic_II_Addon {
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
    ~oCInfoChoice() zCall( 0x00703E00 );

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
      ~Tpd() zCall( 0x007034F0 );

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

    void oCInfo_OnInit()                  zCall( 0x007033B0 );
    oCInfo()                              zInit( oCInfo_OnInit() );
    ~oCInfo()                             zCall( 0x00703420 );
    void SetInstance( int )               zCall( 0x00703540 );
    int GetInstance()                     zCall( 0x007036E0 );
    int DoCheck()                         zCall( 0x007036F0 );
    int GetNpcID()                        zCall( 0x007038E0 );
    int GetConditionFunc()                zCall( 0x007038F0 );
    int WasTold()                         zCall( 0x00703900 );
    void SetTold( int )                   zCall( 0x00703910 );
    int GetDataSize()                     zCall( 0x00703920 );
    void* GetDataAdr()                    zCall( 0x00703930 );
    zSTRING& GetText()                    zCall( 0x00703940 );
    int InfoConditions()                  zCall( 0x00703950 );
    void Info()                           zCall( 0x00703970 );
    void AddChoice( zSTRING, int )        zCall( 0x00703B20 );
    void RemoveChoice( zSTRING )          zCall( 0x00703C20 );
    void RemoveAllChoices()               zCall( 0x00703D70 );
    virtual void Archive( zCArchiver& )   zCall( 0x00703990 );
    virtual void Unarchive( zCArchiver& ) zCall( 0x007039D0 );
    virtual void RestoreParserInstance()  zCall( 0x00703B00 );

    // user API
    #include "oCInfo.inl"
  };

  // sizeof 14h
  class oCInfoManager {
  public:
    zCListSort<oCInfo> infoList; // sizeof 0Ch    offset 04h
    zCParser* p;                 // sizeof 04h    offset 10h

    oCInfoManager() {}
    void oCInfoManager_OnInit( zCParser* )            zCall( 0x007023F0 );
    oCInfoManager( zCParser* a0 )                     zInit( oCInfoManager_OnInit( a0 ));
    ~oCInfoManager()                                  zCall( 0x00702720 );
    oCInfo* GetInformation( oCNpc*, oCNpc*, int )     zCall( 0x007027B0 );
    oCInfo* GetInformation( int )                     zCall( 0x00702910 );
    int GetInfoCount( oCNpc*, oCNpc* )                zCall( 0x00702940 );
    int GetInfoCountImportant( oCNpc*, oCNpc* )       zCall( 0x00702AA0 );
    int GetInfoCountUnimportant( oCNpc*, oCNpc* )     zCall( 0x00702C00 );
    oCInfo* GetInfo( oCNpc*, oCNpc*, int )            zCall( 0x00702D60 );
    oCInfo* GetInfoImportant( oCNpc*, oCNpc*, int )   zCall( 0x00702EC0 );
    oCInfo* GetInfoUnimportant( oCNpc*, oCNpc*, int ) zCall( 0x00703030 );
    int InformationTold( int )                        zCall( 0x007031A0 );
    static int CompareInfos( oCInfo*, oCInfo* )       zCall( 0x007026F0 );
    virtual void Archive( zCArchiver& )               zCall( 0x007031E0 );
    virtual void Unarchive( zCArchiver& )             zCall( 0x00703240 );
    virtual void RestoreParserInstances()             zCall( 0x00703390 );

    // static properties
    static int& size_checked;

    // user API
    #include "oCInfoManager.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OINFO_H__VER3__