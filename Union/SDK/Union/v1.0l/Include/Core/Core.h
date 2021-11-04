// Supported with union (c) 2018-2021 Union team

#ifndef __UNION_CORE_H__
#define __UNION_CORE_H__

namespace UnionCore {
#define CORE_VERSION 100600
#undef GetSystemDirectory

  enum TEngineHash {
    Hash_G1    = 0x225BA11E,
    Hash_G1A   = 0xBCA27323,
    Hash_G2    = 0xA2EE682C,
    Hash_G2A   = 0x2BCD7E30,
    Hash_G1AL1 = 0x02648DED,
    Hash_G1AL2 = 0xAC7117A1
  };

  enum TEngineVersion {
    Engine_Unknown,
    Engine_G1,  // g1 classic 1.08
    Engine_G1A, // g1 siquel 1.12f
    Engine_G2,  // g2 classic 1.30
    Engine_G2A, // g2 notr 2.6
    Engine_Max
  };

  enum TSystemLangID {
    Lang_Other,
    Lang_Rus, // russian
    Lang_Eng, // english
    Lang_Ger, // german
    Lang_Deu = Lang_Ger,
    Lang_Pol, // polish
    Lang_Rou, // romanian
    Lang_Ita, // italian
    Lang_Cze, // czech
    Lang_Esp, // spanish
    Lang_Max
  };

  struct ASTAPI TVersion {
    union {
      struct {
        uint64 Micro : 8;
        uint64 Minor : 24;
        uint64 Major : 32;
      };
      uint64 ui64Version;
    };

    TVersion();
    TVersion( const uint32& major, const uint32& minor, const char& micro = 0 );
    CStringA ToString();
    operator uint64();
  };


  class ASTAPI CUnion {
  public:
    TVersion       mUnionVersion;
    TEngineVersion mEngineVersion;
    TSystemLangID  mSystemLanguage;
    COption        mUnionOption;
    COption        mGameOption;
    COption        mDefaultOption;
    COption        mSysPackOption;
    uint32         ulGothicHash;
    bool32         bUnionIsInit;

    CStringA sCmdLine;
    CStringA sGameIni;

    void LoadVdfs();
    void LoadOptions();
    void PreLoadPlugins();
    void PostLoadPlugins();
    void LoadGlossaries();
    void InitApp();

    void DefileLanguage();
    void DefineEngine();
    void ApplyHacks();
    void ApplyPatches();
    void InitCore();

  public:

    CUnion();
    void InitGlobal();

    TVersion        GetUnionVersion();
    TEngineVersion  GetEngineVersion();
    TSystemLangID   GetSystemLanguage();
    COption&        GetUnionOption();
    COption&        GetGameOption();
    COption&        GetDefaultOption();
    COption&        GetSysPackOption();
    uint32          GetGothicHash();
    bool32          UnionIsInit();
    const CStringA& GetGameDirectory();
    CStringA        GetSystemDirectory( bool full = true );

    CStringA GetCmdLine();
    CStringA GetGameIni();
    int      GetLastSaveSlot();

    bool     OptionReadBool  ( CStringA sec, CStringA val );
    byte     OptionReadByte  ( CStringA sec, CStringA val );
    int32    OptionReadInt   ( CStringA sec, CStringA val );
    real32   OptionReadFloat ( CStringA sec, CStringA val );
    CStringA OptionReadString( CStringA sec, CStringA val );

    void OptionWriteBool  ( CStringA sec, CStringA val, bool par );
    void OptionRWriteByte ( CStringA sec, CStringA val, byte par );
    void OptionWriteInt   ( CStringA sec, CStringA val, int32 par );
    void OptionWriteFloat ( CStringA sec, CStringA val, real32 par );
    void OptionWriteString( CStringA sec, CStringA val, CStringA par );

    bool32 OptionIsExists( CStringA sec, CStringA val );
    void DefineCRTVersion( uint32 major, uint32 minor, uint32 build, uint32 rbuild );

    static HMODULE __stdcall LoadLibraryA( LPSTR lpName );
    static HMODULE __stdcall LoadLibraryW( LPWSTR lpName );

    ~CUnion();
  };

  ASTAPI CUnion Union;


  struct TSaveLoadGameInfo {
    // None: -3
    // New game: -2
    // Current: -1
    // Quick: 0
    // Saved: 1-20
    int_t slotID;

    // If a load reason is a world changing,
    // than that parameter is TRUE
    bool_t changeLevel;

    // If a load reason is a world changing or a new game,
    // than that parameter has a world name.
    CStringA worldName;

    // If a load reason is a world changing,
    // than that parameter has a wayPoint name.
    CStringA wayPoint;

    // Save slot name by slot ID
    static string GetSaveSlotName( int_t id ) {
      if( id >  0 ) return "savegame" + A id;
      if( id == 0 ) return "quicksave";
      return "current";
    }
  };

  ASTAPI TSaveLoadGameInfo SaveLoadGameInfo;


  template <typename T>
  inline T ZenDef( T G1, T G1A, T G2, T G2A ) {
    switch( Union.GetEngineVersion() ) {
    case Engine_G1:  return G1;
    case Engine_G1A: return G1A;
    case Engine_G2:  return G2;
    case Engine_G2A: return G2A;
    };
    return None;
  };
} // namespace UnionCore


#include "CApplication\CApplication.h"
#include "CCallBack\CCallBack.h"
#include "CPlugin\CPlugin.h"
#include "CSplash\CSplash.h"
#include "CoreNames.h"

#endif // __UNION_CORE_H__