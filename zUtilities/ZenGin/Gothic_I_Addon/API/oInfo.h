// Supported with union (c) 2018 Union team

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

  class oCInfoChoice {
  public:
    zSTRING Text;
    int Function;

    oCInfoChoice() {}
    ~oCInfoChoice() zCall( 0x006932A0 );

    // user API
    #include "oCInfoChoice.inl"
  };

  class oCInfo {
  public:
#pragma pack( push, 1 )
    struct Tpd {
      int npc;
      int nr;
      int important;
      int conditions;
      int information;
      zSTRING description;
      int trade;
      int permanent;

      Tpd() {}
      ~Tpd() zCall( 0x00692900 );

      // user API
      #include "oCInfo_Tpd.inl"
    };
#pragma pack( pop )

    oCInfo* next;
    zSTRING name;
    Tpd pd;
    int told;
    int instance;
    zCList<oCInfoChoice> listChoices;

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

  class oCInfoManager {
  public:
    zCListSort<oCInfo> infoList;
    zCParser* p;

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