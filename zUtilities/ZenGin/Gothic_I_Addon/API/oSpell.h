// Supported with union (c) 2018 Union team

#ifndef __OSPELL_H__VER1__
#define __OSPELL_H__VER1__

namespace Gothic_I_Addon {
  const int SPL_LIGHT          = 0;
  const int SPL_FIREBALL       = 1;
  const int SPL_TRANSFORM      = 2;
  const int SPL_FEAR           = 3;
  const int SPL_HEAL           = 4;
  const int SPL_LIGHTNING      = 5;
  const int SPL_DEMON          = 6;
  const int SPL_SKELETON       = 7;
  const int SPL_FORGET         = 8;
  const int SPL_WINDFIST       = 9;
  const int SPL_TELEKINESIS    = 10;
  const int SPL_CHARM          = 11;
  const int SPL_SLEEP          = 12;
  const int SPL_PYROKINESIS    = 13;
  const int SPL_MASSDEATH      = 14;
  const int SPL_CONTROL        = 15;
  const int SPL_DESTROYUNDEAD  = 16;
  const int SPL_FIREBOLT       = 17;
  const int SPL_FIRESTORM      = 18;
  const int SPL_FIRERAIN       = 19;
  const int SPL_SPEED          = 20;
  const int SPL_TELEPORT1      = 21;
  const int SPL_TELEPORT2      = 22;
  const int SPL_TELEPORT3      = 23;
  const int SPL_TELEPORT4      = 24;
  const int SPL_TELEPORT5      = 25;
  const int SPL_TRF_BLOODFLY   = 26;
  const int SPL_TRF_BLOODHOUND = 27;
  const int SPL_TRF_CRAWLER    = 28;
  const int SPL_TRF_LURKER     = 29;
  const int SPL_TRF_MEATBUG    = 30;
  const int SPL_TRF_MOLERAT    = 31;
  const int SPL_TRF_ORCDOG     = 32;
  const int SPL_TRF_RAZOR      = 33;
  const int SPL_TRF_SCAVENGER  = 34;
  const int SPL_TRF_SCAVENGER2 = 35;
  const int SPL_TRF_SHADOWBEAST= 36;
  const int SPL_TRF_SNAPPER    = 37;
  const int SPL_TRF_WARAN      = 38;
  const int SPL_TRF_WOLF       = 39;
  const int SPL_CHAINLIGHTNING = 40;
  const int SPL_THUNDERBOLT    = 41;
  const int SPL_THUNDERBALL    = 42;
  const int SPL_ICECUBE        = 43;
  const int SPL_ICEWAVE        = 44;
  const int SPL_SUMMONGOLEM    = 45;
  const int SPL_ARMYOFDARKNESS = 46;
  const int SPL_STORMFIST      = 47;
  const int SPL_TELEKINESIS2   = 48;
  const int SPL_BREATHOFDEATH  = 49;
  const int SPL_SHRINK         = 50;
  const int SPL_UNDRESS        = 51;
  const int SPL_DANCE          = 52;
  const int SPL_BERZERK        = 53;
  const int SPL_NEW1           = 54;
  const int SPL_NEW2           = 55;
  const int SPL_NEW3           = 56;
  const int SPL_NEW4           = 57;
  const int SPL_NEW5           = 58;
  const int SPL_PSIONIC        = 303;
  const int SPL_MAX_SPELL      = 59;
  const int SPL_USED_SPELLS    = 0x000177FF;
  const int NUM_TARGET_TYPES   = 7;

  enum {
    SPL_STATUS_DONTINVEST,
    SPL_STATUS_CANINVEST,
    SPL_STATUS_CAST,
    SPL_STATUS_STOP,
    SPL_STATUS_NEXTLEVEL
  };

  enum {
    SPL_CAT_GOOD,
    SPL_CAT_NEUTRAL,
    SPL_CAT_BAD
  };

  enum {
    TARGET_COLLECT_NONE,
    TARGET_COLLECT_CASTER,
    TARGET_COLLECT_FOCUS,
    TARGET_COLLECT_ALL,
    TARGET_COLLECT_FOCUS_FALLBACK_NONE,
    TARGET_COLLECT_FOCUS_FALLBACK_CASTER,
    TARGET_COLLECT_ALL_FALLBACK_NONE,
    TARGET_COLLECT_ALL_FALLBACK_CASTER
  };

  enum {
    TARGET_FLAG_NONE,
    TARGET_FLAG_ALL,
    TARGET_FLAG_ITEMS,
    TARGET_FLAG_NPCS   = 4,
    TARGET_FLAG_ORCS   = 8,
    TARGET_FLAG_HUMANS = 16,
    TARGET_FLAG_UNDEAD = 32,
    TARGET_FLAG_LIVING = 64
  };

  class oCSpell : public zCObject {
  public:
    zCLASS_DECLARATION( oCSpell )

    int keyNo;
    oCVisualFX* effect;
    oCVisualFX* controlWarnFX;
    zCVob* spellCaster;
    oCNpc* spellCasterNpc;
    zCVob* spellTarget;
    oCNpc* spellTargetNpc;
    oCNpc* saveNpc;
    float manaTimer;
    int manaInvested;
    int spellLevel;
    int spellStatus;
    int spellID;
    int spellInfo;
    int spellEnabled;
    int spellInitDone;
    int timerEffect;
    int canBeDeleted;
    float up;
    float hoverY;
    float hoverOld;
    float hoverDir;
    int spellEnergy;
    group {
      float manaInvestTime;
      int damagePerLevel;
      int damageType;
      int spellType;
      int canTurnDuringInvest;
      int canChangeTargetDuringInvest;
      int isMultiEffect;
      int targetCollectAlgo;
      int targetCollectType;
      int targetCollectRange;
      int targetCollectAzi;
      int targetCollectElev;
    };

    void oCSpell_OnInit()                                                    zCall( 0x00485EC0 );
    void oCSpell_OnInit( int )                                               zCall( 0x00486070 );
    oCSpell()                                                                zInit( oCSpell_OnInit() );
    oCSpell( int a0 )                                                        zInit( oCSpell_OnInit( a0 ));
    void InitValues( int )                                                   zCall( 0x00486290 );
    zSTRING GetSpellInstanceName( int ) const                                zCall( 0x004863D0 );
    oCVisualFX* CreateEffect()                                               zCall( 0x004865E0 );
    void InitByScript( zSTRING const& )                                      zCall( 0x00486900 );
    void SetEnabled( int )                                                   zCall( 0x00486BE0 );
    int GetEnabled()                                                         zCall( 0x00486D30 );
    void Setup( zCVob*, zCVob* )                                             zCall( 0x00486D40 );
    int Invest()                                                             zCall( 0x00487520 );
    int Cast()                                                               zCall( 0x004877A0 );
    int Stop()                                                               zCall( 0x00487920 );
    int Kill()                                                               zCall( 0x00487AA0 );
    void Open()                                                              zCall( 0x00487C20 );
    void Close()                                                             zCall( 0x00487D30 );
    void Reset()                                                             zCall( 0x00487EA0 );
    void StopTargetEffects( zCVob* )                                         zCall( 0x00487FF0 );
    void CallScriptInvestedMana()                                            zCall( 0x004881D0 );
    int IsValidTarget( zCVob* )                                              zCall( 0x00488660 );
    zCVob* GetVob()                                                          zCall( 0x00488AA0 );
    int GetSpellID()                                                         zCall( 0x00488AB0 );
    int GetEnergyType()                                                      zCall( 0x00488AC0 );
    int GetCategory()                                                        zCall( 0x00488AD0 );
    zSTRING GetName()                                                        zCall( 0x00488AE0 );
    int GetLevel()                                                           zCall( 0x00488C90 );
    int IsInvestSpell()                                                      zCall( 0x00488CB0 );
    void SetInvestedMana( int )                                              zCall( 0x00488CE0 );
    int GetSpellStatus()                                                     zCall( 0x00488D00 );
    int CanTurnDuringInvest()                                                zCall( 0x00488D10 );
    void SetReleaseStatus()                                                  zCall( 0x00488D20 );
    void SetSpellInfo( int )                                                 zCall( 0x00489030 );
    void DoLogicInvestEffect()                                               zCall( 0x00489040 );
    int CastSpecificSpell()                                                  zCall( 0x004896B0 );
    void EndTimedEffect()                                                    zCall( 0x00489E60 );
    void DoTimedEffect()                                                     zCall( 0x0048A4B0 );
    int CanBeDeleted()                                                       zCall( 0x0048A740 );
    int DeleteCaster()                                                       zCall( 0x0048A750 );
    static int IsTargetTypeValid( zCVob*, int )                              zCall( 0x004884A0 );
    static zCObject* _CreateNewInstance()                                    zCall( 0x0048A990 );
    virtual zCClassDef* _GetClassDef() const                                 zCall( 0x00486030 );
    virtual void Archive( zCArchiver& )                                      zCall( 0x0048A770 );
    virtual void Unarchive( zCArchiver& )                                    zCall( 0x0048A780 );
    virtual ~oCSpell()                                                       zCall( 0x004861F0 );

    // user API
    #include "oCSpell.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OSPELL_H__VER1__