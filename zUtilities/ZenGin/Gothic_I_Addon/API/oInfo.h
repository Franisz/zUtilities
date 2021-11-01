// Supported with union (c) 2018-2021 Union team

#ifndef __OINFO_H__VER1__
#define __OINFO_H__VER1__

namespace Gothic_I_Addon {
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
    ~oCInfoChoice() zCall( 0x006932A0 );

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
      ~Tpd() zCall( 0x00692900 );

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

    void oCInfo_OnInit()                  zCall( 0x006927A0 );
    oCInfo()                              zInit( oCInfo_OnInit() );
    ~oCInfo()                             zCall( 0x00692810 );
    void SetInstance( int )               zCall( 0x00692950 );
    int GetInstance()                     zCall( 0x00692AF0 );
    int DoCheck()                         zCall( 0x00692B00 );
    int GetNpcID()                        zCall( 0x00692D30 );
    int GetConditionFunc()                zCall( 0x00692D40 );
    int WasTold()                         zCall( 0x00692D50 );
    void SetTold( int )                   zCall( 0x00692D60 );
    int GetDataSize()                     zCall( 0x00692D70 );
    void* GetDataAdr()                    zCall( 0x00692D80 );
    zSTRING& GetText()                    zCall( 0x00692D90 );
    int InfoConditions()                  zCall( 0x00692DA0 );
    void Info()                           zCall( 0x00692DC0 );
    void AddChoice( zSTRING, int )        zCall( 0x00692F70 );
    void RemoveChoice( zSTRING )          zCall( 0x006930A0 );
    void RemoveAllChoices()               zCall( 0x00693220 );
    virtual void Archive( zCArchiver& )   zCall( 0x00692DE0 );
    virtual void Unarchive( zCArchiver& ) zCall( 0x00692E20 );
    virtual void RestoreParserInstance()  zCall( 0x00692F50 );

    // user API
    #include "oCInfo.inl"
  };

  // sizeof 14h
  class oCInfoManager {
  public:
    zCListSort<oCInfo> infoList; // sizeof 0Ch    offset 04h
    zCParser* p;                 // sizeof 04h    offset 10h

    oCInfoManager() {}
    void oCInfoManager_OnInit( zCParser* )            zCall( 0x00691730 );
    oCInfoManager( zCParser* a0 )                     zInit( oCInfoManager_OnInit( a0 ));
    ~oCInfoManager()                                  zCall( 0x00691A80 );
    oCInfo* GetInformation( oCNpc*, oCNpc*, int )     zCall( 0x00691B10 );
    oCInfo* GetInformation( int )                     zCall( 0x00691C80 );
    int GetInfoCount( oCNpc*, oCNpc* )                zCall( 0x00691CB0 );
    int GetInfoCountImportant( oCNpc*, oCNpc* )       zCall( 0x00691E20 );
    int GetInfoCountUnimportant( oCNpc*, oCNpc* )     zCall( 0x00691F90 );
    oCInfo* GetInfo( oCNpc*, oCNpc*, int )            zCall( 0x00692100 );
    oCInfo* GetInfoImportant( oCNpc*, oCNpc*, int )   zCall( 0x00692270 );
    oCInfo* GetInfoUnimportant( oCNpc*, oCNpc*, int ) zCall( 0x006923F0 );
    int InformationTold( int )                        zCall( 0x00692570 );
    static int CompareInfos( oCInfo*, oCInfo* )       zCall( 0x00691A50 );
    virtual void Archive( zCArchiver& )               zCall( 0x006925B0 );
    virtual void Unarchive( zCArchiver& )             zCall( 0x00692610 );
    virtual void RestoreParserInstances()             zCall( 0x00692780 );

    // static properties
    static int& size_checked;

    // user API
    #include "oCInfoManager.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OINFO_H__VER1__