// Supported with union (c) 2018-2021 Union team

#ifndef __OSPELL_H__VER0__
#define __OSPELL_H__VER0__

namespace Gothic_I_Classic {
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

  // sizeof B0h
  class oCSpell : public zCObject {
  public:
    zCLASS_DECLARATION( oCSpell )

    int keyNo;                         // sizeof 04h    offset 24h
    oCVisualFX* effect;                // sizeof 04h    offset 28h
    oCVisualFX* controlWarnFX;         // sizeof 04h    offset 2Ch
    zCVob* spellCaster;                // sizeof 04h    offset 30h
    oCNpc* spellCasterNpc;             // sizeof 04h    offset 34h
    zCVob* spellTarget;                // sizeof 04h    offset 38h
    oCNpc* spellTargetNpc;             // sizeof 04h    offset 3Ch
    oCNpc* saveNpc;                    // sizeof 04h    offset 40h
    float manaTimer;                   // sizeof 04h    offset 44h
    int manaInvested;                  // sizeof 04h    offset 48h
    int spellLevel;                    // sizeof 04h    offset 4Ch
    int spellStatus;                   // sizeof 04h    offset 50h
    int spellID;                       // sizeof 04h    offset 54h
    int spellInfo;                     // sizeof 04h    offset 58h
    int spellEnabled;                  // sizeof 04h    offset 5Ch
    int spellInitDone;                 // sizeof 04h    offset 60h
    int timerEffect;                   // sizeof 04h    offset 64h
    int canBeDeleted;                  // sizeof 04h    offset 68h
    float up;                          // sizeof 04h    offset 6Ch
    float hoverY;                      // sizeof 04h    offset 70h
    float hoverOld;                    // sizeof 04h    offset 74h
    float hoverDir;                    // sizeof 04h    offset 78h
    int spellEnergy;                   // sizeof 04h    offset 7Ch
    group {
      float manaInvestTime;            // sizeof 04h    offset 80h
      int damagePerLevel;              // sizeof 04h    offset 84h
      int damageType;                  // sizeof 04h    offset 88h
      int spellType;                   // sizeof 04h    offset 8Ch
      int canTurnDuringInvest;         // sizeof 04h    offset 90h
      int canChangeTargetDuringInvest; // sizeof 04h    offset 94h
      int isMultiEffect;               // sizeof 04h    offset 98h
      int targetCollectAlgo;           // sizeof 04h    offset 9Ch
      int targetCollectType;           // sizeof 04h    offset A0h
      int targetCollectRange;          // sizeof 04h    offset A4h
      int targetCollectAzi;            // sizeof 04h    offset A8h
      int targetCollectElev;           // sizeof 04h    offset ACh
    };

    void oCSpell_OnInit()                                                    zCall( 0x0047B840 );
    void oCSpell_OnInit( int )                                               zCall( 0x0047B9F0 );
    oCSpell()                                                                zInit( oCSpell_OnInit() );
    oCSpell( int a0 )                                                        zInit( oCSpell_OnInit( a0 ));
    void InitValues( int )                                                   zCall( 0x0047BC10 );
    zSTRING GetSpellInstanceName( int ) const                                zCall( 0x0047BD40 );
    oCVisualFX* CreateEffect()                                               zCall( 0x0047BED0 );
    void InitByScript( zSTRING const& )                                      zCall( 0x0047C1D0 );
    void SetEnabled( int )                                                   zCall( 0x0047C470 );
    int GetEnabled()                                                         zCall( 0x0047C5A0 );
    void Setup( zCVob*, zCVob* )                                             zCall( 0x0047C5B0 );
    int Invest()                                                             zCall( 0x0047CD40 );
    int Cast()                                                               zCall( 0x0047CFB0 );
    int Stop()                                                               zCall( 0x0047D120 );
    int Kill()                                                               zCall( 0x0047D290 );
    void Open()                                                              zCall( 0x0047D3F0 );
    void Close()                                                             zCall( 0x0047D4F0 );
    void Reset()                                                             zCall( 0x0047D650 );
    void StopTargetEffects( zCVob* )                                         zCall( 0x0047D790 );
    void CallScriptInvestedMana()                                            zCall( 0x0047D930 );
    int IsValidTarget( zCVob* )                                              zCall( 0x0047DD80 );
    zCVob* GetVob()                                                          zCall( 0x0047E170 );
    int GetSpellID()                                                         zCall( 0x0047E180 );
    int GetEnergyType()                                                      zCall( 0x0047E190 );
    int GetCategory()                                                        zCall( 0x0047E1A0 );
    zSTRING GetName()                                                        zCall( 0x0047E1B0 );
    int GetLevel()                                                           zCall( 0x0047E320 );
    int IsInvestSpell()                                                      zCall( 0x0047E340 );
    void SetInvestedMana( int )                                              zCall( 0x0047E370 );
    int GetSpellStatus()                                                     zCall( 0x0047E390 );
    int CanTurnDuringInvest()                                                zCall( 0x0047E3A0 );
    void SetReleaseStatus()                                                  zCall( 0x0047E3B0 );
    void SetSpellInfo( int )                                                 zCall( 0x0047E680 );
    void DoLogicInvestEffect()                                               zCall( 0x0047E690 );
    int CastSpecificSpell()                                                  zCall( 0x0047EC70 );
    void EndTimedEffect()                                                    zCall( 0x0047F330 );
    void DoTimedEffect()                                                     zCall( 0x0047F8F0 );
    int CanBeDeleted()                                                       zCall( 0x0047FB40 );
    int DeleteCaster()                                                       zCall( 0x0047FB50 );
    static int IsTargetTypeValid( zCVob*, int )                              zCall( 0x0047DBC0 );
    static zCObject* _CreateNewInstance()                                    zCall( 0x0047FD80 );
    virtual zCClassDef* _GetClassDef() const                                 zCall( 0x0047B9B0 );
    virtual void Archive( zCArchiver& )                                      zCall( 0x0047FB70 );
    virtual void Unarchive( zCArchiver& )                                    zCall( 0x0047FB80 );
    virtual ~oCSpell()                                                       zCall( 0x0047BB70 );

    // user API
    #include "oCSpell.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OSPELL_H__VER0__