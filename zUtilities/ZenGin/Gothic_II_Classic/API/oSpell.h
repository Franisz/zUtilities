// Supported with union (c) 2018 Union team

#ifndef __OSPELL_H__VER2__
#define __OSPELL_H__VER2__

namespace Gothic_II_Classic {
  const int SPL_PALLIGHT             = 0;
  const int SPL_PALLIGHTHEAL         = 1;
  const int SPL_PALHOLYBOLT          = 2;
  const int SPL_PALMEDIUMHEAL        = 3;
  const int SPL_PALREPELEVIL         = 4;
  const int SPL_PALFULLHEAL          = 5;
  const int SPL_PALDESTROYEVIL       = 6;
  const int SPL_PALTELEPORTSECRET    = 7;
  const int SPL_TELEPORTSEAPORT      = 8;
  const int SPL_TELEPORTMONASTERY    = 9;
  const int SPL_TELEPORTFARM         = 10;
  const int SPL_TELEPORTXARDAS       = 11;
  const int SPL_TELEPORTPASSNW       = 12;
  const int SPL_TELEPORTPASSOW       = 13;
  const int SPL_TELEPORTOC           = 14;
  const int SPL_TELEPORT_1           = 15;
  const int SPL_TELEPORT_2           = 16;
  const int SPL_TELEPORT_3           = 17;
  const int SPL_LIGHT                = 18;
  const int SPL_FIREBOLT             = 19;
  const int SPL_ICEBOLT              = 20;
  const int SPL_LIGHTHEAL            = 21;
  const int SPL_SUMMONGOBLINSKELETON = 22;
  const int SPL_INSTANTFIREBALL      = 23;
  const int SPL_ZAP                  = 24;
  const int SPL_SUMMONWOLF           = 25;
  const int SPL_WINDFIST             = 26;
  const int SPL_SLEEP                = 27;
  const int SPL_MEDIUMHEAL           = 28;
  const int SPL_LIGHTNINGFLASH       = 29;
  const int SPL_CHARGEFIREBALL       = 30;
  const int SPL_SUMMONSKELETON       = 31;
  const int SPL_FEAR                 = 32;
  const int SPL_ICECUBE              = 33;
  const int SPL_THUNDERBALL          = 34;
  const int SPL_SUMMONGOLEM          = 35;
  const int SPL_DESTROYUNDEAD        = 36;
  const int SPL_PYROKINESIS          = 37;
  const int SPL_FIRESTORM            = 38;
  const int SPL_ICEWAVE              = 39;
  const int SPL_SUMMONDEMON          = 40;
  const int SPL_FULLHEAL             = 41;
  const int SPL_FIRERAIN             = 42;
  const int SPL_BREATHOFDEATH        = 43;
  const int SPL_MASSDEATH            = 44;
  const int SPL_ARMYOFDARKNESS       = 45;
  const int SPL_SHRINK               = 46;
  const int SPL_TRFSHEEP             = 47;
  const int SPL_TRFSCAVENGER         = 48;
  const int SPL_TRFGIANTRAT          = 49;
  const int SPL_TRFGIANTBUG          = 50;
  const int SPL_TRFWOLF              = 51;
  const int SPL_TRFWARAN             = 52;
  const int SPL_TRFSNAPPER           = 53;
  const int SPL_TRFWARG              = 54;
  const int SPL_TRFFIREWARAN         = 55;
  const int SPL_TRFLURKER            = 56;
  const int SPL_TRFSHADOWBEAST       = 57;
  const int SPL_TRFDRAGONSNAPPER     = 58;
  const int SPL_CHARM                = 59;
  const int SPL_RESERVED_1           = 60;
  const int SPL_RESERVED_2           = 61;
  const int SPL_RESERVED_3           = 62;
  const int SPL_RESERVED_4           = 63;
  const int SPL_RESERVED_5           = 64;
  const int SPL_RESERVED_6           = 65;
  const int SPL_RESERVED_7           = 66;
  const int SPL_RESERVED_8           = 67;
  const int SPL_MAX_SPELL            = 68;
  const int NUM_TARGET_TYPES         = 7;

  enum {
    SPL_STATUS_DONTINVEST  = 0,
    SPL_STATUS_CANINVEST   = 1,
    SPL_STATUS_CAST        = 2,
    SPL_STATUS_STOP        = 3,
    SPL_STATUS_NEXTLEVEL   = 4,
    SPL_STATUS_FORCEINVEST = 1 << 16
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

    void oCSpell_OnInit()                       zCall( 0x00482610 );
    void oCSpell_OnInit( int )                  zCall( 0x004827C0 );
    oCSpell()                                   zInit( oCSpell_OnInit() );
    oCSpell( int a0 )                           zInit( oCSpell_OnInit( a0 ));
    void InitValues( int )                      zCall( 0x004829E0 );
    zSTRING GetSpellInstanceName( int ) const   zCall( 0x00482B10 );
    oCVisualFX* CreateEffect()                  zCall( 0x00482CA0 );
    void InitByScript( zSTRING const& )         zCall( 0x00482EF0 );
    void SetEnabled( int )                      zCall( 0x00483190 );
    int GetEnabled()                            zCall( 0x004832C0 );
    void Setup( zCVob*, zCVob*, int )           zCall( 0x004832D0 );
    int Invest()                                zCall( 0x00483A70 );
    int Cast()                                  zCall( 0x00483D00 );
    int Stop()                                  zCall( 0x00483EB0 );
    int Kill()                                  zCall( 0x004840A0 );
    void Open()                                 zCall( 0x00484280 );
    void Close()                                zCall( 0x00484380 );
    void Reset()                                zCall( 0x004844E0 );
    void StopTargetEffects( zCVob* )            zCall( 0x00484620 );
    void CallScriptInvestedMana()               zCall( 0x00484710 );
    int IsValidTarget( zCVob* )                 zCall( 0x00484BB0 );
    zCVob* GetVob()                             zCall( 0x00484E50 );
    int GetSpellID()                            zCall( 0x00484E60 );
    int GetEnergyType()                         zCall( 0x00484E70 );
    int GetCategory()                           zCall( 0x00484E80 );
    zSTRING GetName()                           zCall( 0x00484E90 );
    int GetLevel()                              zCall( 0x00485000 );
    int IsInvestSpell()                         zCall( 0x00485010 );
    void SetInvestedMana( int )                 zCall( 0x00485020 );
    int GetSpellStatus()                        zCall( 0x00485040 );
    void SetReleaseStatus()                     zCall( 0x00485050 );
    void SetSpellInfo( int )                    zCall( 0x00485320 );
    void DoLogicInvestEffect()                  zCall( 0x00485330 );
    int CastSpecificSpell()                     zCall( 0x00485340 );
    void EndTimedEffect()                       zCall( 0x004857F0 );
    void DoTimedEffect()                        zCall( 0x00485C60 );
    int CanBeDeleted()                          zCall( 0x00485CF0 );
    int DeleteCaster()                          zCall( 0x00485D00 );
    static int IsTargetTypeValid( zCVob*, int ) zCall( 0x004849A0 );
    static zCObject* _CreateNewInstance()       zCall( 0x00485F30 );
    virtual zCClassDef* _GetClassDef() const    zCall( 0x00482780 );
    virtual void Archive( zCArchiver& )         zCall( 0x00485D20 );
    virtual void Unarchive( zCArchiver& )       zCall( 0x00485D30 );
    virtual ~oCSpell()                          zCall( 0x00482940 );

    // user API
    #include "oCSpell.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OSPELL_H__VER2__