// Supported with union (c) 2018 Union team

#ifndef __ONPC_H__VER3__
#define __ONPC_H__VER3__

#include "zDisk.h"
#include "z3d.h"
#include "zModel.h"
#include "zSoundMan.h"
#include "oItem.h"
#include "oVob.h"
#include "oNews.h"
#include "oNpcStates.h"
#include "oInventory.h"
#include "oCsPlayer.h"
#include "oMagFrontier.h"
#include "oAiHuman.h"

namespace Gothic_II_Addon {
  static const int NPC_ATR_HITPOINTS                     = 0;
  static const int NPC_ATR_HITPOINTSMAX                  = 1;
  static const int NPC_ATR_MANA                          = 2;
  static const int NPC_ATR_MANAMAX                       = 3;
  static const int NPC_ATR_STRENGTH                      = 4;
  static const int NPC_ATR_DEXTERITY                     = 5;
  static const int NPC_ATR_REGENERATEHP                  = 6;
  static const int NPC_ATR_REGENERATEMANA                = 7;
  static const int NPC_ATR_MAX                           = 8;
  static const int NPC_TAL_FIGHT_USED                    = 0x00000FFF;
  static const int NPC_TAL_FIGHT_MAX                     = 12;
  static const int NPC_TAL_USED                          = 0x0000024D;
  static const int NPC_TAL_MAX                           = 17;
  static const int NPC_HITCHANCE_1H                      = 1;
  static const int NPC_HITCHANCE_2H                      = 2;
  static const int NPC_HITCHANCE_BOW                     = 3;
  static const int NPC_HITCHANCE_CROSSBOW                = 4;
  static const int NPC_HITCHANCE_MAX                     = 5;
  static const char* PLAYER_STEAL_NPC_IS_AWARE           = "PLAYER_STEAL_NPC_IS_AWARE";
  static const char* PLAYER_STEAL_NO_TALENT              = "PLAYER_STEAL_NO_TALENT";
  static const char* PLAYER_STEAL_NOT_IN_RANGE           = "PLAYER_STEAL_NOT_IN_RANGE";
  static const char* PLAYER_STEAL_NPC_IS_EMPTY           = "PLAYER_STEAL_NPC_IS_EMPTY";
  static const char* PLAYER_MOB_MISSING_KEY              = "PLAYER_MOB_MISSING_KEY";
  static const char* PLAYER_MOB_MISSING_LOCKPICK         = "PLAYER_MOB_MISSING_LOCKPICK";
  static const char* PLAYER_MOB_MISSING_KEY_OR_LOCKPICK  = "PLAYER_MOB_MISSING_KEY_OR_LOCKPICK";
  static const char* PLAYER_MOB_NEVER_OPEN               = "PLAYER_MOB_NEVER_OPEN";
  static const char* PLAYER_MOB_TOO_FAR_AWAY             = "PLAYER_MOB_TOO_FAR_AWAY";
  static const char* PLAYER_MOB_WRONG_SIDE               = "PLAYER_MOB_WRONG_SIDE";
  static const char* PLAYER_MOB_MISSING_ITEM             = "PLAYER_MOB_MISSING_ITEM";
  static const char* PLAYER_MOB_ANOTHER_IS_USING         = "PLAYER_MOB_ANOTHER_IS_USING";
  static const char* PLAYER_PLUNDER_IS_EMPTY             = "PLAYER_PLUNDER_IS_EMPTY";
  static const char* PLAYER_RANGED_NO_AMMO               = "PLAYER_RANGED_NO_AMMO";
  static const char* NPC_NODE_RIGHTHAND                  = "ZS_RIGHTHAND";
  static const char* NPC_NODE_LEFTHAND                   = "ZS_LEFTHAND";
  static const char* NPC_NODE_SWORD                      = "ZS_SWORD";
  static const char* NPC_NODE_LONGSWORD                  = "ZS_LONGSWORD";
  static const char* NPC_NODE_BOW                        = "ZS_BOW";
  static const char* NPC_NODE_CROSSBOW                   = "ZS_CROSSBOW";
  static const char* NPC_NODE_SHIELD                     = "ZS_SHIELD";
  static const char* NPC_NODE_HELMET                     = "ZS_HELMET";
  static const char* NPC_NODE_JAWS                       = "ZS_JAWS";
  static const char* NPC_NODE_TORSO                      = "ZS_TORSO";
  static const char* NPC_NODE_LEFTARM                    = "ZS_LEFTARM";
  static const int NPC_FLAG_NFOCUS                       = 1<<18;
  static const int BS_STAND                              = 0;
  static const int BS_WALK                               = 1;
  static const int BS_SNEAK                              = 2;
  static const int BS_RUN                                = 3;
  static const int BS_SPRINT                             = 4;
  static const int BS_SWIM                               = 5;
  static const int BS_CRAWL                              = 6;
  static const int BS_DIVE                               = 7;
  static const int BS_JUMP                               = 8;
  static const int BS_CLIMB                              = 9;
  static const int BS_FALL                               = 10;
  static const int BS_SIT                                = 11;
  static const int BS_LIE                                = 12;
  static const int BS_INVENTORY                          = 13;
  static const int BS_ITEMINTERACT                       = 14;
  static const int BS_MOBINTERACT                        = 15;
  static const int BS_MOBINTERACT_INTERRUPT              = 16;
  static const int BS_TAKEITEM                           = 17;
  static const int BS_DROPITEM                           = 18;
  static const int BS_THROWITEM                          = 19;
  static const int BS_PICKPOCKET                         = 20;
  static const int BS_STUMBLE                            = 21;
  static const int BS_UNCONSCIOUS                        = 22;
  static const int BS_DEAD                               = 23;
  static const int BS_AIMNEAR                            = 24;
  static const int BS_AIMFAR                             = 25;
  static const int BS_HIT                                = 26;
  static const int BS_PARADE                             = 27;
  static const int BS_CASTING                            = 28;
  static const int BS_PETRIFIED                          = 29;
  static const int BS_CONTROLLING                        = 30;
  static const int BS_MAX                                = 31;
  static const int BS_MOD_HIDDEN                         = 128;
  static const int BS_MOD_DRUNK                          = 256;
  static const int BS_MOD_NUTS                           = 512;
  static const int BS_MOD_BURNING                        = 1024;
  static const int BS_MOD_CONTROLLED                     = 2048;
  static const int BS_MOD_TRANSFORMED                    = 4096;
  static const int BS_MOD_CONTROLLING                    = 8192;
  static const int BS_FLAG_INTERRUPTABLE                 = 32768;
  static const int BS_FLAG_FREEHANDS                     = 65536;
  static const int BS_ONLY_STATE                         = BS_MOD_HIDDEN - 1;
  static const int BS_MOD_ACTIVE                         = BS_MOD_HIDDEN | BS_MOD_DRUNK | BS_MOD_NUTS | BS_MOD_BURNING | BS_MOD_CONTROLLED | BS_MOD_TRANSFORMED | BS_MOD_CONTROLLING;
  static const int NPC_ATT_MAX                           = 4;
  static const int NPC_NAME_MAX                          = 5;
  static const int NPC_MIS_MAX                           = 5;
  static const int NPC_FLAG_FRIENDS                      = 1 << 0;
  static const int NPC_FLAG_IMMORTAL                     = 1 << 1;
  static const int NPC_FLAG_GHOST                        = 1 << 2;
  static const int NPC_FLAG_PROTECTED                    = 1 << 10;
  static const int NPC_SENSE_SEE                         = 1 << 0;
  static const int NPC_SENSE_HEAR                        = 1 << 1;
  static const int NPC_SENSE_SMELL                       = 1 << 2;
  static const float NPC_TURNVELOCITY                    = 150.0f;
  static const int NPC_GIL_NONE                          = 0;
  static const int NPC_GIL_PALADIN                       = 1;
  static const int NPC_GIL_MILIZ                         = 2;
  static const int NPC_GIL_VOLK                          = 3;
  static const int NPC_GIL_FEUERKREIS                    = 4;
  static const int NPC_GIL_NOVIZE                        = 5;
  static const int NPC_GIL_DRACHENJAEGER                 = 6;
  static const int NPC_GIL_SOELDNER                      = 7;
  static const int NPC_GIL_BAUERN                        = 8;
  static const int NPC_GIL_BANDIT                        = 9;
  static const int NPC_GIL_PRISONER                      = 10;
  static const int NPC_GIL_DEMENTOR                      = 11;
  static const int NPC_GIL_OUTLANDER                     = 12;
  static const int NPC_GIL_PIRAT                         = 13;
  static const int NPC_GIL_WASSERKREIS                   = 14;
  static const int NPC_GIL_PUBLIC                        = 15;
  static const int NPC_GIL_HUMANS                        = 16;
  static const int NPC_GIL_MEATBUG                       = 17;
  static const int NPC_GIL_SHEEP                         = 18;
  static const int NPC_GIL_GOBBO                         = 19;
  static const int NPC_GIL_GOBBO_SKELETON                = 20;
  static const int NPC_GIL_SUMMONED_GOBBO_SKELETON       = 21;
  static const int NPC_GIL_SCAVANGER                     = 22;
  static const int NPC_GIL_GIANT_RAT                     = 23;
  static const int NPC_GIL_GIANT_BUG                     = 24;
  static const int NPC_GIL_BLOODFLY                      = 25;
  static const int NPC_GIL_WARAN                         = 26;
  static const int NPC_GIL_WOLF                          = 27;
  static const int NPC_GIL_SUMMONED_WOLF                 = 28;
  static const int NPC_GIL_MINECRAWLER                   = 29;
  static const int NPC_GIL_LURKER                        = 30;
  static const int NPC_GIL_SKELETON                      = 31;
  static const int NPC_GIL_SUMMONED_SKELETON             = 32;
  static const int NPC_GIL_SKELETON_MAGE                 = 33;
  static const int NPC_GIL_ZOMBIE                        = 34;
  static const int NPC_GIL_SNAPPER                       = 35;
  static const int NPC_GIL_SHADOWBEAST                   = 36;
  static const int NPC_GIL_SHADOWBEAST_SKELETON          = 37;
  static const int NPC_GIL_HARPY                         = 38;
  static const int NPC_GIL_STONEGOLEM                    = 39;
  static const int NPC_GIL_FIREGOLEM                     = 40;
  static const int NPC_GIL_ICEGOLEM                      = 41;
  static const int NPC_GIL_SUMMONED_GOLEM                = 42;
  static const int NPC_GIL_DEMON                         = 43;
  static const int NPC_GIL_SUMMONED_DEMON                = 44;
  static const int NPC_GIL_TROLL                         = 45;
  static const int NPC_GIL_SWAMPSHARK                    = 46;
  static const int NPC_GIL_DRAGON                        = 47;
  static const int NPC_GIL_MOLERAT                       = 48;
  static const int NPC_GIL_ALLIGATOR                     = 49;
  static const int NPC_GIL_SWAMPGOLEM                    = 50;
  static const int NPC_GIL_STONEGUARDIAN                 = 51;
  static const int NPC_GIL_GARGOYLE                      = 52;
  static const int NPC_GIL_EMPTY_A                       = 53;
  static const int NPC_GIL_SUMMONED_GUARDIAN             = 54;
  static const int NPC_GIL_SUMMONED_ZOMBIE               = 55;
  static const int NPC_GIL_EMPTY_B                       = 56;
  static const int NPC_GIL_EMPTY_C                       = 57;
  static const int NPC_GIL_ORCS                          = 58;
  static const int NPC_GIL_ORC                           = 59;
  static const int NPC_GIL_FRIENDLYORC                   = 60;
  static const int NPC_GIL_UNDEADORC                     = 61;
  static const int NPC_GIL_DRACONIAN                     = 62;
  static const int NPC_GIL_EMPTYORC1                     = 63;
  static const int NPC_GIL_EMPTYORC2                     = 64;
  static const int NPC_GIL_EMPTYORC3                     = 65;
  static const int NPC_GIL_MAX                           = 66;
  static const int FA_MAX_SITUATIONS                     = 19;
  static const int FA_MAX_ENTRY                          = 6;

  enum {
    NPC_GAME_NORMAL,
    NPC_GAME_PLUNDER,
    NPC_GAME_STEAL
  };

  enum {
    BS_INT_OVERRIDE_NONE,
    BS_INT_OVERRIDE_ALL,
    BS_INT_OVERRIDE_STUMBLE_ONLY
  };

  enum {
    NPC_ATT_HOSTILE,
    NPC_ATT_ANGRY,
    NPC_ATT_NEUTRAL,
    NPC_ATT_FRIENDLY
  };

  enum {
    NPC_WEAPON_NONE,
    NPC_WEAPON_FIST,
    NPC_WEAPON_DAG,
    NPC_WEAPON_1HS,
    NPC_WEAPON_2HS,
    NPC_WEAPON_BOW,
    NPC_WEAPON_CBOW,
    NPC_WEAPON_MAG,
    NPC_WEAPON_MAX
  };

  enum {
    NPC_PERC_ASSESSPLAYER = 1,
    NPC_PERC_ASSESSENEMY,
    NPC_PERC_ASSESSFIGHTER,
    NPC_PERC_ASSESSBODY,
    NPC_PERC_ASSESSITEM,
    NPC_PERC_ASSESSMURDER,
    NPC_PERC_ASSESSDEFEAT,
    NPC_PERC_ASSESSDAMAGE,
    NPC_PERC_ASSESSOTHERSDAMAGE,
    NPC_PERC_ASSESSTHREAT,
    NPC_PERC_ASSESSREMOVEWEAPON,
    NPC_PERC_OBSERVEINTRUDER,
    NPC_PERC_ASSESSFIGHTSOUND,
    NPC_PERC_ASSESSQUIETSOUND,
    NPC_PERC_ASSESSWARN,
    NPC_PERC_CATCHTHIEF,
    NPC_PERC_ASSESSTHEFT,
    NPC_PERC_ASSESSCALL,
    NPC_PERC_ASSESSTALK,
    NPC_PERC_ASSESSGIVENITEM,
    NPC_PERC_ASSESSFAKEGUILD,
    NPC_PERC_MOVEMOB,
    NPC_PERC_MOVENPC,
    NPC_PERC_DRAWWEAPON,
    NPC_PERC_OBSERVESUSPECT,
    NPC_PERC_NPCCOMMAND,
    NPC_PERC_ASSESSMAGIC,
    NPC_PERC_ASSESSSTOPMAGIC,
    NPC_PERC_ASSESSCASTER,
    NPC_PERC_ASSESSSURPRISE,
    NPC_PERC_ASSESSENTERROOM,
    NPC_PERC_ASSESSUSEMOB,
    NPC_PERC_MAX
  };

  enum {
    NPCTYPE_AMBIENT,
    NPCTYPE_MAIN,
    NPCTYPE_GUARD,
    NPCTYPE_FRIEND,
    NPCTYPE_MINE_AMBIENT,
    NPCTYPE_MINE_GUARD,
    NPCTYPE_OW_AMBIENT,
    NPCTYPE_OW_GUARD
  };

  class oCNpcTalent : public zCObject {
  public:
    zCLASS_DECLARATION( oCNpcTalent )

    enum oTEnumNpcTalent {
      NPC_TAL_UNKNOWN,
      NPC_TAL_1H,
      NPC_TAL_2H,
      NPC_TAL_BOW,
      NPC_TAL_CROSSBOW,
      NPC_TAL_PICKLOCK,
      NPC_TAL_PICKPOCKET,
      NPC_TAL_MAGE,
      NPC_TAL_SNEAK,
      NPC_TAL_REGENERATE,
      NPC_TAL_FIREMASTER,
      NPC_TAL_ACROBAT,
      NPC_TALENT_PICKPOCKET,
      NPC_TAL_SMITH,
      NPC_TAL_RUNES,
      NPC_TAL_ALCHEMY,
      NPC_TAL_TAKEANIMALTROPHY,
      NPC_TAL_A,
      NPC_TAL_B,
      NPC_TAL_C,
      NPC_TAL_D,
      NPC_TAL_E,
      NPC_TAL_MAX
    };

    oTEnumNpcTalent m_talent;
    int m_skill;
    int m_value;

    void oCNpcTalent_OnInit()                              zCall( 0x0072C4C0 );
    oCNpcTalent()                                          zInit( oCNpcTalent_OnInit() );
    static zCObject* _CreateNewInstance()                  zCall( 0x0072C330 );
    static void CreateTalentList( zCArray<oCNpcTalent*>* ) zCall( 0x0072C670 );
    virtual zCClassDef* _GetClassDef() const               zCall( 0x0072C4B0 );
    virtual void Archive( zCArchiver& )                    zCall( 0x0072C7B0 );
    virtual void Unarchive( zCArchiver& )                  zCall( 0x0072C7F0 );
    virtual ~oCNpcTalent()                                 zCall( 0x0072C660 );

    // user API
    #include "oCNpcTalent.inl"
  };

  struct TNpcSlot {
  public:
    zSTRING name;
    int inInventory;
    int tmpLevel;
    zSTRING itemName;
    oCVob* vob;
    int wasVobTreeWhenInserted : 1;

    void TNpcSlot_OnInit() zCall( 0x0072E330 );
    void SetVob( oCVob* )  zCall( 0x0072C860 );
    void ClearVob()        zCall( 0x0072C910 );
    TNpcSlot()             zInit( TNpcSlot_OnInit() );
    ~TNpcSlot()            zCall( 0x0072ED90 );

    // user API
    #include "TNpcSlot.inl"
  };

  struct TNpcPerc {
  public:
    int percID;
    int percFunc;

    TNpcPerc() {}

    // user API
    #include "TNpcPerc.inl"
  };

  class oCNpc : public oCVob {
  public:
    zCLASS_DECLARATION( oCNpc )

    enum oEBloodMode {
      oEBloodMode_None,
      oEBloodMode_Particles,
      oEBloodMode_Decals,
      oEBloodMode_Trails,
      oEBloodMode_Amplification
    };

    typedef enum oEFightAction {
      NPC_FIGHTMOVE_NOTINITIALISED,
      NPC_FIGHTMOVE_RUN,
      NPC_FIGHTMOVE_RUNBACK,
      NPC_FIGHTMOVE_JUMPBACK,
      NPC_FIGHTMOVE_TURN,
      NPC_FIGHTMOVE_STRAFE,
      NPC_FIGHTMOVE_ATTACK,
      NPC_FIGHTMOVE_SIDEATTACK,
      NPC_FIGHTMOVE_FRONTATTACK,
      NPC_FIGHTMOVE_TRIPLEATTACK,
      NPC_FIGHTMOVE_WHIRLATTACK,
      NPC_FIGHTMOVE_MASTERATTACK,
      NPC_FIGHTMOVE_PREHIT,
      NPC_FIGHTMOVE_COMBOZONE,
      NPC_FIGHTMOVE_POSTHIT,
      NPC_FIGHTMOVE_TURNTOHIT,
      NPC_FIGHTMOVE_STORMPREHIT,
      NPC_FIGHTMOVE_PARADE,
      NPC_FIGHTMOVE_STANDUP,
      NPC_FIGHTMOVE_WAIT,
      NPC_FIGHTMOVE_ONGROUND,
      NPC_FIGHTMOVE_STUMBLE,
      NPC_FIGHTMOVE_SKIP,
      NPC_FIGHTMOVE_WAIT_LONG,
      NPC_FIGHTMOVE_WAIT_EXT,
      NPC_FIGHTMOVE_MAX
    } TFAction;

    typedef enum oEFlagsDamageDescriptor {
      oEDamageDescFlag_Attacker        = 1,
      oEDamageDescFlag_Npc             = 2,
      oEDamageDescFlag_Inflictor       = 4,
      oEDamageDescFlag_Weapon          = 8,
      oEDamageDescFlag_VisualFX        = 16,
      oEDamageDescFlag_SpellID         = 32,
      oEDamageDescFlag_SpellLevel      = 64,
      oEDamageDescFlag_DamageType      = 128,
      oEDamageDescFlag_WeaponType      = 256,
      oEDamageDescFlag_Damage          = 512,
      oEDamageDescFlag_HitLocation     = 1024,
      oEDamageDescFlag_FlyDirection    = 2048,
      oEDamageDescFlag_OverlayActivate = 4096,
      oEDamageDescFlag_OverlayInterval = 8192,
      oEDamageDescFlag_OverlayDuration = 16384,
      oEDamageDescFlag_OverlayDamage   = 32768,
      oEDamageDescFlag_ForceDWORD      = 0xffffffff
    } oEDescDamageFlags, oEFlagsDamageDesc;

    typedef struct oSActionBlock {
    public:
      int ownaction[FA_MAX_ENTRY];
      int max;

      oSActionBlock() {}
      void InitBlock( zCParser*, int, int ) zCall( 0x0067C170 );
      int GetOwnAction( int )               zCall( 0x0067C390 );
    } oSActionBlock;

    typedef struct oSFightAI {
    public:
      oSActionBlock myactions[FA_MAX_SITUATIONS];

      oSFightAI() {}
      void Init( zCParser*, int ) zCall( 0x0067C3C0 );
      int GetOwnAction( int )     zCall( 0x0067C3F0 );
    } oCNpc::oSFightAI;

    typedef struct oSDamageDescriptor {
    public:
      unsigned long dwFieldsValid;
      zCVob* pVobAttacker;
      oCNpc* pNpcAttacker;
      zCVob* pVobHit;
      oCVisualFX* pFXHit;
      oCItem* pItemWeapon;
      unsigned long nSpellID;
      unsigned long nSpellCat;
      unsigned long nSpellLevel;
      unsigned long enuModeDamage;
      unsigned long enuModeWeapon;
      unsigned long aryDamage[oEDamageIndex_MAX];
      float fDamageTotal;
      float fDamageMultiplier;
      zVEC3 vecLocationHit;
      zVEC3 vecDirectionFly;
      zSTRING strVisualFX;
      float fTimeDuration;
      float fTimeInterval;
      float fDamagePerInterval;
      int bDamageDontKill;
      group {
        unsigned long bOnce          : 1;
        unsigned long bFinished      : 1;
        unsigned long bIsDead        : 1;
        unsigned long bIsUnconscious : 1;
        unsigned long lReserved      : 28;
      };
      float fAzimuth;
      float fElevation;
      float fTimeCurrent;
      float fDamageReal;
      float fDamageEffective;
      unsigned long aryDamageEffective[oEDamageIndex_MAX];
      zCVob* pVobParticleFX;
      zCParticleFX* pParticleFX;
      oCVisualFX* pVisualFX;

      oSDamageDescriptor() {}
      void oSDamageDescriptor_OnInit( oSDamageDescriptor const& ) zCall( 0x00664250 );
      ~oSDamageDescriptor()                                       zCall( 0x004962F0 );
      void Release()                                              zCall( 0x00664170 );
      void SetVisualFX( oCVisualFX* )                             zCall( 0x006641C0 );
      void SetFXHit( oCVisualFX* )                                zCall( 0x00664210 );
      oSDamageDescriptor( oSDamageDescriptor const& a0 )          zInit( oSDamageDescriptor_OnInit( a0 ));
      oSDamageDescriptor& operator =( oSDamageDescriptor const& ) zCall( 0x00664310 );
    } oSDescDamage;

    struct oSDirectionInfo {
      zVEC3 checkDirection;
      unsigned char checkForChasm       : 1;
      unsigned char checkForSmallObject : 1;
      unsigned char checkIfClimbable    : 1;

      oSDirectionInfo() {}

      // user API
      #include "oCNpc_oSDirectionInfo.inl"
    };

    struct oTRobustTrace {
      group {
        unsigned char stand                : 1;
        unsigned char dirChoosed           : 1;
        unsigned char exactPosition        : 1;
        unsigned char targetReached        : 1;
        unsigned char standIfTargetReached : 1;
        unsigned char waiting              : 1;
        unsigned char isObstVobSmall       : 1;
        unsigned char targetVisible        : 1;
        unsigned char useChasmChecks       : 1;
      };
      zVEC3 targetPos;
      zCVob* targetVob;
      zCVob* obstVob;
      float targetDist;
      float lastTargetDist;
      float maxTargetDist;
      float dirTurn;
      float timer;
      zVEC3 dirFirst;
      float dirLastAngle;
      zCArray<oSDirectionInfo*> lastDirections;
      int frameCtr;
      zVEC3 targetPosArray[5];
      int targetPosCounter;
      int targetPosIndex;
      float checkVisibilityTime;
      float positionUpdateTime;
      float failurePossibility;

      oTRobustTrace() {}
      ~oTRobustTrace() zCall( 0x0072E3D0 );

      // user API
      #include "oCNpc_oTRobustTrace.inl"
    };

    class TActiveInfo {
    public:
      int modified           : 1;
      int putTorchBackInHand : 1;
      int changeTorchAni     : 1;
      int changeTorchAniTo   : 1;

      TActiveInfo() {}
      void TActiveInfo_OnInit( oCNpc const* ) zCall( 0x0072C960 );
      TActiveInfo( oCNpc const* a0 )          zInit( TActiveInfo_OnInit( a0 ));
      ~TActiveInfo()                          zCall( 0x0072C970 );

      // user API
      #include "oCNpc_TActiveInfo.inl"
    };

    class oCNpcTimedOverlay {
    public:
      zSTRING mdsOverlayName;
      float timer;

      oCNpcTimedOverlay() {}
      zSTRING GetMdsName() zCall( 0x0073E8D0 );
      ~oCNpcTimedOverlay() zCall( 0x0073E930 );
      int Process()        zCall( 0x0075F4A0 );

      // user API
      #include "oCNpc_oCNpcTimedOverlay.inl"
    };

    group {
      int idx;
      zSTRING name[5];
      zSTRING slot;
      zSTRING effect;
      int npcType;
      int variousFlags;
      int attribute[NPC_ATR_MAX];
      int hitChance[NPC_HITCHANCE_MAX];
      int protection[oEDamageIndex_MAX];
      int damage[oEDamageIndex_MAX];
      int damagetype;
      int guild;
      int level;
      int mission[NPC_MIS_MAX];
      int fighttactic;
      int fmode;
      int voice;
      int voicePitch;
      int mass;
      int daily_routine;
      int startAIState;
      zSTRING spawnPoint;
      int spawnDelay;
      int senses;
      int senses_range;
      int aiscriptvars[100];
      zSTRING wpname;
      unsigned long experience_points;
      unsigned long experience_points_next_level;
      unsigned long learn_points;
      int bodyStateInterruptableOverride;
      int noFocus;
      int parserEnd;
    };
    int bloodEnabled;
    int bloodDistance;
    int bloodAmount;
    int bloodFlow;
    zSTRING bloodEmitter;
    zSTRING bloodTexture;
    int didHit;
    int didParade;
    int didShoot;
    int hasLockedEnemy;
    int isDefending;
    int wasAiming;
    TFAction lastAction;
    oCNpc* enemy;
    float speedTurn;
    int foundFleePoint;
    int reachedFleePoint;
    zVEC3 vecFlee;
    zVEC3 posFlee;
    zCWaypoint* waypointFlee;
    oTRobustTrace rbt;
    zCList<oCNpcTimedOverlay> timedOverlays;
    zCArray<oCNpcTalent*> talents;
    int spellMana;
    oCMagFrontier magFrontier;
    oCNpc_States state;
    oCNpcInventory inventory2;
    oCItemContainer* trader;
    oCNpc* tradeNpc;
    float rangeToPlayer;
    zCArray<int> listOfVoiceHandles;
    int voiceIndex;
    zCArray<oCVisualFX*> effectList;
    int showaidebug          : 1;
    int showNews             : 1;
    int csAllowedAsRole      : 1;
    int isSummoned           : 1;
    int respawnOn            : 1;
    int movlock              : 1;
    int drunk                : 1;
    int mad                  : 1;
    int overlay_wounded      : 1;
    int inOnDamage           : 1;
    int autoremoveweapon     : 1;
    int openinventory        : 1;
    int askroutine           : 1;
    int spawnInRange         : 1;
    int body_TexVarNr        : 16;
    int body_TexColorNr      : 16;
    int head_TexVarNr        : 16;
    int teeth_TexVarNr       : 16;
    int guildTrue            : 8;
    int drunk_heal           : 8;
    int mad_heal             : 8;
    int spells               : 8;
    int bodyState            : 19;
    int m_bAniMessageRunning : 1;
    int instanz;
    zSTRING mds_name;
    zSTRING body_visualName;
    zSTRING head_visualName;
    zVEC3 model_scale;
    float model_fatness;
    int namenr;
    float hpHeal;
    float manaHeal;
    float swimtime;
    float divetime;
    float divectr;
    zCVob* fireVob;
    int fireDamage;
    float fireDamageTimer;
    int attitude;
    int tmp_attitude;
    float attTimer;
    int knowsPlayer;
    TNpcPerc percList[NPC_PERC_MAX];
    int percActive;
    float percActiveTime;
    float percActiveDelta;
    int overrideFallDownHeight;
    float fallDownHeight;
    int fallDownDamage;
    oCMag_Book* mag_book;
    zCList<oCSpell> activeSpells;
    int lastHitSpellID;
    int lastHitSpellCat;
    zCArray<zSTRING> activeOverlays;
    oCAskBox* askbox;
    int askYes;
    int askNo;
    float canTalk;
    oCNpc* talkOther;
    oCInfo* info;
    oCNews* news;
    oCMission* curMission;
    oCNewsMemory knownNews;
    zCVob* carry_vob;
    oCMobInter* interactMob;
    oCItem* interactItem;
    int interactItemCurrentState;
    int interactItemTargetState;
    int script_aiprio;
    int old_script_state;
    oCAIHuman* human_ai;
    oCAniCtrl_Human* anictrl;
    zCRoute* route;
    float damageMul;
    oCNpcMessage* csg;
    oCNpcMessage* lastLookMsg;
    oCNpcMessage* lastPointMsg;
    zCArray<zCVob*> vobList;
    float vobcheck_time;
    float pickvobdelay;
    zCVob* focus_vob;
    zCArray<TNpcSlot*> invSlot;
    zCArray<TNpcSlot*> tmpSlotList;
    float fadeAwayTime;
    float respawnTime;
    float selfDist;
    int fightRangeBase;
    int fightRangeFist;
    int fightRangeG;
    float fight_waitTime;
    int fight_waitForAniEnd;
    float fight_lastStrafeFrame;
    int soundType;
    zCVob* soundVob;
    zVEC3 soundPosition;
    zCPlayerGroup* playerGroup;

    void oCNpc_OnInit()                                                                          zCall( 0x0082DF20 );
    void InitDamage()                                                                            zCall( 0x00664490 );
    int EV_DamageOnce( oCMsgDamage* )                                                            zCall( 0x00664660 );
    int EV_DamagePerFrame( oCMsgDamage* )                                                        zCall( 0x006649A0 );
    void OnDamage_Hit( oSDamageDescriptor& )                                                     zCall( 0x00666610 );
    void OnDamage_Condition( oSDamageDescriptor& )                                               zCall( 0x0066CF30 );
    void OnDamage_Script( oSDamageDescriptor& )                                                  zCall( 0x0066E220 );
    void OnDamage_Effects( oSDamageDescriptor& )                                                 zCall( 0x0066EAF0 );
    void OnDamage_Effects_Start( oSDamageDescriptor& )                                           zCall( 0x0066EE40 );
    void OnDamage_Effects_End( oSDamageDescriptor& )                                             zCall( 0x00674300 );
    void OnDamage_Anim( oSDamageDescriptor& )                                                    zCall( 0x00675BD0 );
    void OnDamage_Sound( oSDamageDescriptor& )                                                   zCall( 0x0067A8A0 );
    void OnDamage_Events( oSDamageDescriptor& )                                                  zCall( 0x0067ABE0 );
    void OnDamage_State( oSDamageDescriptor& )                                                   zCall( 0x0067B7E0 );
    int HasFlag( unsigned long, unsigned long )                                                  zCall( 0x0067BD20 );
    int IsNpcBetweenMeAndTarget( zCVob* )                                                        zCall( 0x0067C7D0 );
    int IsInDoubleFightRange( zCVob*, float& )                                                   zCall( 0x0067C9A0 );
    int IsInFightRange( zCVob*, float& )                                                         zCall( 0x0067CB60 );
    int GetFightRange()                                                                          zCall( 0x0067CD80 );
    void SetFightRangeBase( int )                                                                zCall( 0x0067CDB0 );
    int GetFightRangeBase()                                                                      zCall( 0x0067CDC0 );
    int GetFightRangeDynamic()                                                                   zCall( 0x0067CDD0 );
    int GetFightRangeFist()                                                                      zCall( 0x0067CDF0 );
    int GetFightRangeG()                                                                         zCall( 0x0067CE00 );
    void SetFightRangeFist( int )                                                                zCall( 0x0067CE10 );
    void SetFightRangeG( int )                                                                   zCall( 0x0067CE20 );
    int GetFightActionFromTable( int )                                                           zCall( 0x0067CE30 );
    int GetCurrentFightMove()                                                                    zCall( 0x0067CE70 );
    int FindNextFightAction()                                                                    zCall( 0x0067D680 );
    int ThinkNextFightAction()                                                                   zCall( 0x0067E350 );
    int FightAttackMelee( int )                                                                  zCall( 0x0067EEC0 );
    int FightAttackBow()                                                                         zCall( 0x0067F700 );
    int EV_AttackBow( oCMsgAttack* )                                                             zCall( 0x0067F7E0 );
    int FightAttackMagic()                                                                       zCall( 0x0067FA60 );
    int EV_AttackMagic( oCMsgAttack* )                                                           zCall( 0x0067FB10 );
    int EV_CastSpell( oCMsgMagic* )                                                              zCall( 0x0067FB20 );
    void CheckRunningFightAnis()                                                                 zCall( 0x0067FE10 );
    void GotoFightPosition()                                                                     zCall( 0x0067FFC0 );
    void Fighting()                                                                              zCall( 0x006800B0 );
    oCItem* GetSpellItem( int )                                                                  zCall( 0x00680270 );
    int ReadySpell( int, int )                                                                   zCall( 0x006802E0 );
    int UnreadySpell()                                                                           zCall( 0x00680480 );
    int HasRangedWeaponAndAmmo()                                                                 zCall( 0x00680510 );
    int CanDrawWeapon()                                                                          zCall( 0x006805C0 );
    int CanDive()                                                                                zCall( 0x00680900 );
    int CanSwim()                                                                                zCall( 0x00680930 );
    float GetClimbRange()                                                                        zCall( 0x00680960 );
    float GetTurnSpeed()                                                                         zCall( 0x00680970 );
    float GetJumpRange()                                                                         zCall( 0x00680990 );
    int RbtChooseChasmAction( zVEC3 const&, zVEC3 const& )                                       zCall( 0x006809A0 );
    int CanGo( float, zVEC3& )                                                                   zCall( 0x00680B30 );
    float GetAngle( zCVob* )                                                                     zCall( 0x006811C0 );
    void GetAngles( zVEC3&, float&, float& )                                                     zCall( 0x006812B0 );
    void GetAngles( zCVob*, float&, float& )                                                     zCall( 0x00681680 );
    float GetDistanceToPos2( zVEC3&, int )                                                       zCall( 0x006816C0 );
    float GetFallDownHeight()                                                                    zCall( 0x00681790 );
    zCVob* GetRbtObstacleVob()                                                                   zCall( 0x006817B0 );
    zVEC3 GetVecNormalFromBBox( zCVob*, zVEC3& )                                                 zCall( 0x006817C0 );
    void SetFallDownDamage( int )                                                                zCall( 0x00681D50 );
    void SetFallDownHeight( float )                                                              zCall( 0x00681D60 );
    void SetRoute( zCRoute* )                                                                    zCall( 0x00681D70 );
    void CreateFallDamage( float )                                                               zCall( 0x00681DA0 );
    void Fleeing()                                                                               zCall( 0x006820C0 );
    int ThinkNextFleeAction()                                                                    zCall( 0x006820D0 );
    void Follow()                                                                                zCall( 0x006824C0 );
    void StandUp( int, int )                                                                     zCall( 0x00682B40 );
    float Turn( zVEC3& )                                                                         zCall( 0x00683000 );
    float Turning( zVEC3& )                                                                      zCall( 0x00683120 );
    void AI_Flee( oCNpc* )                                                                       zCall( 0x00683210 );
    void AI_Follow( oCNpc* )                                                                     zCall( 0x00683220 );
    int EV_AlignToFP( oCMsgMovement* )                                                           zCall( 0x00683230 );
    int EV_CanSeeNpc( oCMsgMovement* )                                                           zCall( 0x00683480 );
    int EV_GoRoute( oCMsgMovement* )                                                             zCall( 0x006834D0 );
    int EV_Jump( oCMsgMovement* )                                                                zCall( 0x00683C20 );
    int EV_RobustTrace( oCMsgMovement* )                                                         zCall( 0x00683C80 );
    int EV_StandUp( oCMsgMovement* )                                                             zCall( 0x00683CE0 );
    int EV_Strafe( oCMsgMovement* )                                                              zCall( 0x00683DE0 );
    int EV_WhirlAround( oCMsgMovement* )                                                         zCall( 0x00684BF0 );
    int EV_Dodge( oCMsgMovement* )                                                               zCall( 0x00685290 );
    int EV_GotoPos( oCMsgMovement* )                                                             zCall( 0x006854C0 );
    int EV_GotoVob( oCMsgMovement* )                                                             zCall( 0x00685580 );
    int EV_GotoFP( oCMsgMovement* )                                                              zCall( 0x00685700 );
    int EV_SetWalkMode( oCMsgMovement* )                                                         zCall( 0x006859F0 );
    int EV_Turn( oCMsgMovement* )                                                                zCall( 0x00685DE0 );
    int EV_TurnAway( oCMsgMovement* )                                                            zCall( 0x00685EC0 );
    int EV_TurnToPos( oCMsgMovement* )                                                           zCall( 0x00686070 );
    int EV_TurnToVob( oCMsgMovement* )                                                           zCall( 0x00686160 );
    void ForceRotation( float )                                                                  zCall( 0x006863F0 );
    int RbtCheckForSolution( zVEC3, zVEC3 )                                                      zCall( 0x00686430 );
    void RbtReset()                                                                              zCall( 0x00686560 );
    void RbtInit( zVEC3&, zCVob* )                                                               zCall( 0x00686670 );
    void RbtUpdate( zVEC3&, zCVob* )                                                             zCall( 0x00686690 );
    int RbtMoveToExactPosition()                                                                 zCall( 0x00686880 );
    int RobustTrace()                                                                            zCall( 0x00686960 );
    float RbtCalcTurnDirection( zVEC3 const&, float, int )                                       zCall( 0x00686CA0 );
    int RbtIsObjectObstacle( zCVob*, zVEC3 const&, zVEC3 const&, zVEC3& )                        zCall( 0x00687080 );
    int RbtGetObstacle( zVEC3 const&, zVEC3 const&, zCVob*&, zVEC3& )                            zCall( 0x006872E0 );
    int RbtGetSmallObstacle( zVEC3 const&, zCVob*&, zVEC3& )                                     zCall( 0x00687490 );
    int RbtAvoidObstacles()                                                                      zCall( 0x006875E0 );
    int RbtIsDirectionValid( zVEC3 const& )                                                      zCall( 0x00687C80 );
    oSDirectionInfo* RbtInsertDirection( zVEC3 )                                                 zCall( 0x00687D00 );
    int RbtCheckLastDirection( float )                                                           zCall( 0x00687F60 );
    int RbtCheckIfTargetVisible()                                                                zCall( 0x00688240 );
    int RbtGotoFollowPosition()                                                                  zCall( 0x00688450 );
    int CanStrafe( int, int )                                                                    zCall( 0x00688670 );
    int CanJumpBack( int )                                                                       zCall( 0x006888D0 );
    void SetWalkStopChasm( int )                                                                 zCall( 0x00688A70 );
    int GetWalkStopChasm()                                                                       zCall( 0x00688AB0 );
    int IsWaitingForAnswer()                                                                     zCall( 0x006BC730 );
    int SetCurrentAnswer( int, int, oCNpc* )                                                     zCall( 0x006BC780 );
    int EV_Ask( oCMsgConversation* )                                                             zCall( 0x006BCCA0 );
    int EV_WaitForQuestion( oCMsgConversation* )                                                 zCall( 0x006BCD20 );
    int CanTalk()                                                                                zCall( 0x006BCEF0 );
    void SetCanTalk( int )                                                                       zCall( 0x006BCF10 );
    void SetTalkingWith( oCNpc*, int )                                                           zCall( 0x006BCF30 );
    oCNpc* GetTalkingWith()                                                                      zCall( 0x006BCF60 );
    void StartTalkingWith( oCNpc* )                                                              zCall( 0x006BCF70 );
    void StopTalkingWith()                                                                       zCall( 0x006BCF90 );
    zCEventMessage* GetTalkingWithMessage( oCNpc* )                                              zCall( 0x006BCFB0 );
    int CanBeTalkedTo()                                                                          zCall( 0x006BD060 );
    void StopRunningOU()                                                                         zCall( 0x006BD240 );
    int AssessGivenItem( oCItem*, oCNpc* )                                                       zCall( 0x006BD3B0 );
    oCNpc* GetTradeNpc()                                                                         zCall( 0x006BD550 );
    void SetTradeNpc( oCNpc* )                                                                   zCall( 0x006BD560 );
    oCItem* GetTradeItem()                                                                       zCall( 0x006BD570 );
    void OpenTradeContainer( oCItem*, oCNpc*, int )                                              zCall( 0x006BD590 );
    void CloseTradeContainer()                                                                   zCall( 0x006BD770 );
    void OpenTradeOffer( oCNpc* )                                                                zCall( 0x006BD820 );
    int CheckItemReactModule( oCNpc*, oCItem* )                                                  zCall( 0x006BD940 );
    void ExchangeTradeModules( oCNpc* )                                                          zCall( 0x006BDAC0 );
    zSTRING GetBloodTexture()                                                                    zCall( 0x006D38B0 );
    TActiveInfo const* GetActiveInfo() const                                                     zCall( 0x0072C9B0 );
    TActiveInfo* GetActiveInfoWritable() const                                                   zCall( 0x0072C9D0 );
    void Shrink()                                                                                zCall( 0x0072CA20 );
    void UnShrink()                                                                              zCall( 0x0072CBA0 );
    void AvoidShrink( int )                                                                      zCall( 0x0072D250 );
    int ApplyOverlay( zSTRING const& )                                                           zCall( 0x0072D2C0 );
    void RemoveOverlay( zSTRING const& )                                                         zCall( 0x0072D5C0 );
    void SetModelScale( zVEC3 const& )                                                           zCall( 0x0072D7B0 );
    void SetFatness( float )                                                                     zCall( 0x0072D8A0 );
    oCNpc()                                                                                      zInit( oCNpc_OnInit() );
    void CleanUp()                                                                               zCall( 0x0072E410 );
    void DeleteHumanAI()                                                                         zCall( 0x0072F650 );
    zSTRING GetGuildName()                                                                       zCall( 0x0072F690 );
    zSTRING GetName( int )                                                                       zCall( 0x0072F820 );
    int IsHostile( oCNpc* )                                                                      zCall( 0x0072F870 );
    int IsFriendly( oCNpc* )                                                                     zCall( 0x0072F900 );
    int IsNeutral( oCNpc* )                                                                      zCall( 0x0072F990 );
    int IsAngry( oCNpc* )                                                                        zCall( 0x0072FA20 );
    int GetAttitude( oCNpc* )                                                                    zCall( 0x0072FAB0 );
    int GetPermAttitude( oCNpc* )                                                                zCall( 0x0072FB30 );
    void SetAttitude( int )                                                                      zCall( 0x0072FB80 );
    void SetTmpAttitude( int )                                                                   zCall( 0x0072FBD0 );
    int GetProtectionByIndex( oEIndexDamage )                                                    zCall( 0x0072FC20 );
    int GetProtectionByType( oETypeDamage )                                                      zCall( 0x0072FC30 );
    int GetProtectionByMode( unsigned long )                                                     zCall( 0x0072FCD0 );
    int GetFullProtection()                                                                      zCall( 0x0072FD60 );
    void SetProtectionByIndex( oEIndexDamage, int )                                              zCall( 0x0072FD80 );
    int GetDamageByIndex( oEIndexDamage )                                                        zCall( 0x0072FDA0 );
    int GetDamageByType( oETypeDamage )                                                          zCall( 0x0072FDB0 );
    int GetDamageByMode( unsigned long )                                                         zCall( 0x0072FE50 );
    int GetFullDamage()                                                                          zCall( 0x0072FEE0 );
    void SetDamages( int* )                                                                      zCall( 0x0072FF00 );
    int GetAttribute( int )                                                                      zCall( 0x0072FF20 );
    int GetHitChance( int )                                                                      zCall( 0x0072FF30 );
    void SetHitChance( int, int )                                                                zCall( 0x0072FF40 );
    void ChangeAttribute( int, int )                                                             zCall( 0x0072FF60 );
    void SetAttribute( int, int )                                                                zCall( 0x0072FFF0 );
    int GetOverlay( zSTRING& )                                                                   zCall( 0x00730010 );
    void CheckModelOverlays()                                                                    zCall( 0x007301D0 );
    void SetToMad( float )                                                                       zCall( 0x007303F0 );
    void HealFromMad()                                                                           zCall( 0x00730530 );
    void SetToDrunk( float )                                                                     zCall( 0x00730650 );
    void HealFromDrunk()                                                                         zCall( 0x00730660 );
    void CheckAngryTime()                                                                        zCall( 0x00730670 );
    int CanRecruitSC()                                                                           zCall( 0x00730720 );
    int IsDisguised()                                                                            zCall( 0x00730730 );
    int GetGuild()                                                                               zCall( 0x00730750 );
    void SetGuild( int )                                                                         zCall( 0x00730760 );
    int GetTrueGuild()                                                                           zCall( 0x00730770 );
    void SetTrueGuild( int )                                                                     zCall( 0x00730780 );
    int GetCamp()                                                                                zCall( 0x00730790 );
    int IsGuildFriendly( int )                                                                   zCall( 0x007307A0 );
    int GetGuildAttitude( int )                                                                  zCall( 0x007307D0 );
    void CreateItems( int, int )                                                                 zCall( 0x00730800 );
    void SetFlag( int )                                                                          zCall( 0x007309C0 );
    int HasFlag( int )                                                                           zCall( 0x007309E0 );
    oCNpcTalent* GetTalent( int, int )                                                           zCall( 0x00730A00 );
    void SetTalentValue( int, int )                                                              zCall( 0x00730BE0 );
    int GetTalentValue( int )                                                                    zCall( 0x00730DC0 );
    void SetTalentSkill( int, int )                                                              zCall( 0x00730F60 );
    int GetTalentSkill( int )                                                                    zCall( 0x007317F0 );
    int HasTalent( int, int )                                                                    zCall( 0x00731990 );
    int CanUse( oCItem* )                                                                        zCall( 0x007319B0 );
    void DisplayCannotUse()                                                                      zCall( 0x00731CB0 );
    void CheckAllCanUse()                                                                        zCall( 0x00731DE0 );
    oCVob* GetSlotVob( zSTRING const& )                                                          zCall( 0x00731EF0 );
    oCItem* GetSlotItem( zSTRING const& )                                                        zCall( 0x00731F90 );
    oCItem* GetItem( int, int )                                                                  zCall( 0x00732030 );
    oCNpc* GetSlotNpc( zSTRING const& )                                                          zCall( 0x00732050 );
    void AddItemEffects( oCItem* )                                                               zCall( 0x007320F0 );
    void RemoveItemEffects( oCItem* )                                                            zCall( 0x00732270 );
    void EquipItem( oCItem* )                                                                    zCall( 0x007323C0 );
    void UnequipItem( oCItem* )                                                                  zCall( 0x007326C0 );
    int GetCutsceneDistance()                                                                    zCall( 0x007329A0 );
    void SetCSEnabled( int )                                                                     zCall( 0x007329F0 );
    void SetFocusVob( zCVob* )                                                                   zCall( 0x00732B60 );
    zCVob* GetFocusVob()                                                                         zCall( 0x00732BB0 );
    void ClearFocusVob()                                                                         zCall( 0x00732BC0 );
    oCNpc* GetFocusNpc()                                                                         zCall( 0x00732BF0 );
    oCNpc* GetNearestFightNpcLeft()                                                              zCall( 0x00732C20 );
    oCNpc* GetNearestFightNpcRight()                                                             zCall( 0x00732DB0 );
    int FocusCheckBBox( zCVob const*, int, int, float, float& )                                  zCall( 0x00732F40 );
    int FocusCheck( zCVob const*, int, int, float, float& )                                      zCall( 0x007331C0 );
    void ToggleFocusVob( int )                                                                   zCall( 0x007335B0 );
    void CollectFocusVob( int )                                                                  zCall( 0x00733A10 );
    void GetNearestValidVob( float )                                                             zCall( 0x007344F0 );
    void GetNearestVob( float )                                                                  zCall( 0x00734860 );
    oCAniCtrl_Human* GetAnictrl()                                                                zCall( 0x00734B40 );
    void ResetToHumanAI()                                                                        zCall( 0x00734B50 );
    void SetEnemy( oCNpc* )                                                                      zCall( 0x00734BC0 );
    oCNpc* GetNextEnemy()                                                                        zCall( 0x00734E30 );
    int IsConditionValid()                                                                       zCall( 0x00735130 );
    int IsInFightFocus( zCVob* )                                                                 zCall( 0x00735290 );
    oCItem* HasEquippedStolenItem( oCNpc* )                                                      zCall( 0x00735300 );
    void Burn( int, float )                                                                      zCall( 0x00735520 );
    void StopBurn()                                                                              zCall( 0x007357A0 );
    void Interrupt( int, int )                                                                   zCall( 0x00735AB0 );
    int GetWeaponDamage( oCItem* )                                                               zCall( 0x00735E30 );
    int GetBluntDamage( oCItem* )                                                                zCall( 0x00735E80 );
    void DropUnconscious( float, oCNpc* )                                                        zCall( 0x00735EB0 );
    void CheckUnconscious()                                                                      zCall( 0x00736230 );
    zSTRING GetInterruptPrefix()                                                                 zCall( 0x00736680 );
    void CompleteHeal()                                                                          zCall( 0x00736720 );
    int IsDead()                                                                                 zCall( 0x00736740 );
    int IsUnconscious()                                                                          zCall( 0x00736750 );
    void StartFadeAway()                                                                         zCall( 0x00736D40 );
    int IsFadingAway()                                                                           zCall( 0x00736E30 );
    int FadeAway()                                                                               zCall( 0x00736E40 );
    int BeamTo( zSTRING const& )                                                                 zCall( 0x00736EE0 );
    void DropInventory()                                                                         zCall( 0x00737350 );
    int HasInHand( int )                                                                         zCall( 0x00737360 );
    int HasInHand( zCVob* )                                                                      zCall( 0x007374B0 );
    void DropAllInHand()                                                                         zCall( 0x007375E0 );
    oCItem* GetWeapon()                                                                          zCall( 0x007377A0 );
    oCItem* GetEquippedMeleeWeapon()                                                             zCall( 0x00737930 );
    oCItem* GetEquippedRangedWeapon()                                                            zCall( 0x00737A40 );
    oCItem* GetEquippedArmor()                                                                   zCall( 0x00737B50 );
    int IsSameHeight( zCVob* )                                                                   zCall( 0x00737BE0 );
    void TurnToEnemy()                                                                           zCall( 0x00737CD0 );
    int ShieldEquipped()                                                                         zCall( 0x00737E50 );
    int GetWeaponDamage()                                                                        zCall( 0x00737F20 );
    void SetMovLock( int )                                                                       zCall( 0x007380B0 );
    int IsMovLock()                                                                              zCall( 0x007380E0 );
    void SetHead()                                                                               zCall( 0x007380F0 );
    void SetAdditionalVisuals( zSTRING&, int, int, zSTRING&, int, int, int )                     zCall( 0x00738350 );
    void InitModel()                                                                             zCall( 0x00738480 );
    zCModel* GetModel()                                                                          zCall( 0x00738720 );
    zSTRING GetVisualBody()                                                                      zCall( 0x007387C0 );
    zSTRING GetVisualHead()                                                                      zCall( 0x00738810 );
    int StartFaceAni( zSTRING const&, float, float )                                             zCall( 0x00738860 );
    int StartStdFaceAni( int )                                                                   zCall( 0x00738960 );
    int StopFaceAni( zSTRING const& )                                                            zCall( 0x00738B50 );
    int GetWeaponMode()                                                                          zCall( 0x00738C40 );
    void SetWeaponMode2_novt( zSTRING const& )                                                   zCall( 0x00738C60 );
    int GetNextWeaponMode( int, int, int )                                                       zCall( 0x00739A30 );
    void Equip( oCItem* )                                                                        zCall( 0x00739C90 );
    void EquipWeapon( oCItem* )                                                                  zCall( 0x0073A030 );
    void EquipFarWeapon( oCItem* )                                                               zCall( 0x0073A310 );
    void EquipArmor( oCItem* )                                                                   zCall( 0x0073A490 );
    void SetToFightMode( oCItem*, int )                                                          zCall( 0x0073A740 );
    void SetToFistMode()                                                                         zCall( 0x0073A940 );
    void Activate( int, int )                                                                    zCall( 0x0073AB40 );
    oCVob* GetRightHand()                                                                        zCall( 0x0073AB50 );
    oCVob* GetLeftHand()                                                                         zCall( 0x0073ABE0 );
    void DropVob( oCVob*, zVEC3& )                                                               zCall( 0x0073AC70 );
    void SetCarryVob( zCVob* )                                                                   zCall( 0x0073AE00 );
    zCVob* GetCarryVob()                                                                         zCall( 0x0073B0B0 );
    void SetLeftHand( oCVob* )                                                                   zCall( 0x0073B0C0 );
    void SetRightHand( oCVob* )                                                                  zCall( 0x0073B1C0 );
    int HasTorch()                                                                               zCall( 0x0073B2C0 );
    void ExchangeTorch()                                                                         zCall( 0x0073B400 );
    void SetTorchAni( int, int )                                                                 zCall( 0x0073B410 );
    void CheckSetTorchAni()                                                                      zCall( 0x0073B6D0 );
    void CheckPutbackTorch()                                                                     zCall( 0x0073B940 );
    int UseItem( oCItem* )                                                                       zCall( 0x0073BC10 );
    float GetThrowSpeed( float, float )                                                          zCall( 0x0073C230 );
    int HasArrowInHand()                                                                         zCall( 0x0073C260 );
    int HasArrowInInv()                                                                          zCall( 0x0073C3B0 );
    int HasBoltInInv()                                                                           zCall( 0x0073C4A0 );
    int HasBoltInHand()                                                                          zCall( 0x0073C590 );
    int IsMunitionAvailable( oCItem* )                                                           zCall( 0x0073C6E0 );
    void GetTalentInfo( int, zSTRING&, zSTRING&, zSTRING& )                                      zCall( 0x0073C860 );
    void GetSpellInfo( int, zSTRING&, zSTRING& )                                                 zCall( 0x0073CA90 );
    void GetAttribInfo( int, zSTRING&, zSTRING& )                                                zCall( 0x0073CC80 );
    void CreateSpell( int )                                                                      zCall( 0x0073CE20 );
    void LearnSpell( int )                                                                       zCall( 0x0073CE80 );
    int HasSpell( int )                                                                          zCall( 0x0073CEC0 );
    void DestroySpell( int )                                                                     zCall( 0x0073CEE0 );
    void SetActiveSpellInfo( int )                                                               zCall( 0x0073CF20 );
    int GetActiveSpellNr()                                                                       zCall( 0x0073CF60 );
    int GetActiveSpellCategory()                                                                 zCall( 0x0073CFA0 );
    int GetActiveSpellLevel()                                                                    zCall( 0x0073CFE0 );
    int GetActiveSpellIsScroll()                                                                 zCall( 0x0073D020 );
    void InsertActiveSpell( oCSpell* )                                                           zCall( 0x0073D070 );
    void RemoveActiveSpell( oCSpell* )                                                           zCall( 0x0073D090 );
    void RemoveActiveSpell( int )                                                                zCall( 0x0073D120 );
    int DoActiveSpells()                                                                         zCall( 0x0073D1D0 );
    void KillActiveSpells()                                                                      zCall( 0x0073D2B0 );
    oCSpell* IsSpellActive( int )                                                                zCall( 0x0073D340 );
    int HasMagic()                                                                               zCall( 0x0073D380 );
    int GetNumberOfSpells()                                                                      zCall( 0x0073D3B0 );
    void CopyTransformSpellInvariantValuesTo( oCNpc* )                                           zCall( 0x0073D3D0 );
    void OpenScreen_Help()                                                                       zCall( 0x0073D5B0 );
    void OpenScreen_Log()                                                                        zCall( 0x0073D5C0 );
    void OpenScreen_Map( int )                                                                   zCall( 0x0073D8D0 );
    void OpenScreen_Status()                                                                     zCall( 0x0073D980 );
    int IsVoiceActive()                                                                          zCall( 0x0073E350 );
    void StopAllVoices()                                                                         zCall( 0x0073E360 );
    int UpdateNextVoice()                                                                        zCall( 0x0073E3C0 );
    void DoSpellBook()                                                                           zCall( 0x0073E980 );
    void OpenSpellBook( int )                                                                    zCall( 0x0073E990 );
    void CloseSpellBook( int )                                                                   zCall( 0x0073E9E0 );
    oCMag_Book* GetSpellBook()                                                                   zCall( 0x0073EA00 );
    int HasSenseHear()                                                                           zCall( 0x0073ED20 );
    int HasSenseSee()                                                                            zCall( 0x0073ED30 );
    int HasSenseSmell()                                                                          zCall( 0x0073ED40 );
    void SetSenses( int )                                                                        zCall( 0x0073ED50 );
    void PrintStateCallDebug( zSTRING const&, int, int )                                         zCall( 0x0073ED60 );
    int GetOldScriptState()                                                                      zCall( 0x0073EFD0 );
    int GetAIState()                                                                             zCall( 0x0073EFE0 );
    int GetAIStateTime()                                                                         zCall( 0x0073EFF0 );
    int IsAIState( int )                                                                         zCall( 0x0073F000 );
    void ShowState( int, int )                                                                   zCall( 0x0073F010 );
    int IsNear( oCNpc* )                                                                         zCall( 0x0073FCC0 );
    oCItem* DetectItem( int, int )                                                               zCall( 0x0073FD40 );
    oCNpc* DetectPlayer()                                                                        zCall( 0x0073FE00 );
    oCMobInter* FindMobInter( zSTRING const& )                                                   zCall( 0x0073FE70 );
    zCVobSpot* FindSpot( zSTRING const&, int, float )                                            zCall( 0x007400E0 );
    void ForceVobDetection( zCVob* )                                                             zCall( 0x00740470 );
    int HasVobDetected( zCVob* )                                                                 zCall( 0x007405B0 );
    int CheckForOwner( zCVob* )                                                                  zCall( 0x007405F0 );
    void AI_ForceDetection()                                                                     zCall( 0x00740730 );
    int CanSense( zCVob* )                                                                       zCall( 0x00740740 );
    void DetectWitnesses( oCNpc*, int )                                                          zCall( 0x007407E0 );
    oCNpc* FindNpc( int, int, int, int )                                                         zCall( 0x00740A80 );
    oCNpc* FindNpcEx( int, int, int, int, int, int )                                             zCall( 0x00740B80 );
    oCNpc* FindNpcExAtt( int, int, int, int, int, int, int )                                     zCall( 0x00740E00 );
    int GetComrades()                                                                            zCall( 0x007410B0 );
    int AreWeStronger( oCNpc* )                                                                  zCall( 0x007412E0 );
    oCNpc* IsEnemyBehindFriend( oCNpc* )                                                         zCall( 0x00741600 );
    int InMobInteraction( zSTRING const&, int )                                                  zCall( 0x00741800 );
    int FreeLineOfSight( zCVob* )                                                                zCall( 0x007418E0 );
    int FreeLineOfSight( zVEC3&, zCVob* )                                                        zCall( 0x00741940 );
    int FreeLineOfSight_WP( zVEC3&, zCVob* )                                                     zCall( 0x00741AA0 );
    int CanSee( zCVob*, int )                                                                    zCall( 0x00741C10 );
    void SetSwimDiveTime( float, float )                                                         zCall( 0x00741F70 );
    void GetSwimDiveTime( float&, float&, float& )                                               zCall( 0x00741FA0 );
    void Regenerate()                                                                            zCall( 0x00741FD0 );
    void RefreshNpc()                                                                            zCall( 0x00742110 );
    void RenderNpc( zCView* )                                                                    zCall( 0x00742370 );
    void SetKnowsPlayer( int )                                                                   zCall( 0x007425D0 );
    int KnowsPlayer( oCNpc* )                                                                    zCall( 0x007425E0 );
    int KnowsPlayer( int )                                                                       zCall( 0x007425F0 );
    int HasMunitionInHand( oCItem* )                                                             zCall( 0x00744040 );
    void Pack( zCBuffer& )                                                                       zCall( 0x007455B0 );
    void Unpack( zCBuffer& )                                                                     zCall( 0x00745640 );
    int IsInFightMode_S( int )                                                                   zCall( 0x007456E0 );
    int IsAiming_S( oCNpc* )                                                                     zCall( 0x00745760 );
    void ClearEM()                                                                               zCall( 0x00746400 );
    void PreSaveGameProcessing()                                                                 zCall( 0x00748880 );
    void PostSaveGameProcessing()                                                                zCall( 0x00748B90 );
    oCItem* IdentifyMushroom( oCItem* )                                                          zCall( 0x00748DF0 );
    void IdentifyAllMushrooms()                                                                  zCall( 0x00748FE0 );
    int HasMissionItem()                                                                         zCall( 0x00749110 );
    oCItem* IsInInv( oCItem*, int )                                                              zCall( 0x00749160 );
    oCItem* GetFromInv( int, int )                                                               zCall( 0x00749180 );
    oCItem* IsInInv( int, int )                                                                  zCall( 0x007491E0 );
    oCItem* IsInInv( zSTRING const&, int )                                                       zCall( 0x00749200 );
    int CanCarry( oCItem* )                                                                      zCall( 0x00749220 );
    oCItem* PutInInv( oCItem* )                                                                  zCall( 0x00749350 );
    oCItem* PutInInv( int, int )                                                                 zCall( 0x007494C0 );
    oCItem* PutInInv( zSTRING const&, int )                                                      zCall( 0x00749570 );
    oCItem* RemoveFromInv( oCItem*, int )                                                        zCall( 0x007495A0 );
    oCItem* RemoveFromInv( int, int )                                                            zCall( 0x007495F0 );
    oCItem* RemoveFromInv( zSTRING const&, int )                                                 zCall( 0x00749640 );
    int IsSlotFree( zSTRING const& )                                                             zCall( 0x00749690 );
    int IsSlotFree( TNpcSlot* )                                                                  zCall( 0x00749760 );
    void SetToSlotPosition( zCVob*, zSTRING const& )                                             zCall( 0x00749780 );
    void CreateInvSlot( zSTRING const& )                                                         zCall( 0x00749800 );
    void DeleteInvSlot( zSTRING const& )                                                         zCall( 0x007499E0 );
    TNpcSlot* GetInvSlot( zSTRING const& )                                                       zCall( 0x00749AE0 );
    TNpcSlot* GetInvSlot( zCVob* )                                                               zCall( 0x00749BA0 );
    int IsInvSlotAvailable( zSTRING const& )                                                     zCall( 0x00749BE0 );
    void PutInSlot( zSTRING const&, oCVob*, int )                                                zCall( 0x00749CB0 );
    void PutInSlot( TNpcSlot*, oCVob*, int )                                                     zCall( 0x00749D80 );
    void RemoveFromAllSlots( int )                                                               zCall( 0x0074A230 );
    oCVob* RemoveFromSlot( zSTRING const&, int, int )                                            zCall( 0x0074A270 );
    oCVob* RemoveFromSlot( TNpcSlot*, int, int )                                                 zCall( 0x0074A340 );
    oCVob* DropFromSlot( zSTRING const& )                                                        zCall( 0x0074A590 );
    oCVob* DropFromSlot( TNpcSlot* )                                                             zCall( 0x0074A660 );
    void UpdateSlots()                                                                           zCall( 0x0074A9D0 );
    void SetInteractMob( oCMobInter* )                                                           zCall( 0x0074AB00 );
    oCMobInter* GetInteractMob()                                                                 zCall( 0x0074ACA0 );
    void SetInteractItem( oCItem* )                                                              zCall( 0x0074ACC0 );
    int EV_DrawWeapon( oCMsgWeapon* )                                                            zCall( 0x0074CC10 );
    int EV_DrawWeapon1( oCMsgWeapon* )                                                           zCall( 0x0074D2E0 );
    int EV_DrawWeapon2( oCMsgWeapon* )                                                           zCall( 0x0074D580 );
    int EV_RemoveWeapon( oCMsgWeapon* )                                                          zCall( 0x0074DB20 );
    int EV_RemoveWeapon1( oCMsgWeapon* )                                                         zCall( 0x0074E4B0 );
    int EV_RemoveWeapon2( oCMsgWeapon* )                                                         zCall( 0x0074E630 );
    int EV_ChooseWeapon( oCMsgWeapon* )                                                          zCall( 0x0074E980 );
    int EV_ForceRemoveWeapon( oCMsgWeapon* )                                                     zCall( 0x0074EC40 );
    int EV_EquipBestWeapon( oCMsgWeapon* )                                                       zCall( 0x0074EF10 );
    void EquipBestWeapon( int )                                                                  zCall( 0x0074EF30 );
    int EV_EquipBestArmor( oCMsgWeapon* )                                                        zCall( 0x0074F020 );
    void EquipBestArmor()                                                                        zCall( 0x0074F0B0 );
    int EV_UnequipWeapons( oCMsgWeapon* )                                                        zCall( 0x0074F130 );
    int EV_UnequipArmor( oCMsgWeapon* )                                                          zCall( 0x0074F2F0 );
    int EV_EquipArmor( oCMsgWeapon* )                                                            zCall( 0x0074F3A0 );
    int EV_AttackForward( oCMsgAttack* )                                                         zCall( 0x0074F400 );
    int EV_AttackLeft( oCMsgAttack* )                                                            zCall( 0x00750160 );
    int EV_AttackRight( oCMsgAttack* )                                                           zCall( 0x00750D00 );
    int EV_AttackRun( oCMsgAttack* )                                                             zCall( 0x007517D0 );
    int EV_AttackFinish( oCMsgAttack* )                                                          zCall( 0x00751AF0 );
    int EV_Parade( oCMsgAttack* )                                                                zCall( 0x007522D0 );
    int InitAim( oCMsgAttack*, oCNpc**, int*, int*, int )                                        zCall( 0x007529A0 );
    int TransitionAim( int, int )                                                                zCall( 0x00752B30 );
    int InterpolateAim( oCNpc* )                                                                 zCall( 0x00752CC0 );
    int FinalizeAim( int, int )                                                                  zCall( 0x00752E00 );
    int EV_StopAim( oCMsgAttack* )                                                               zCall( 0x00752F20 );
    int EV_AimAt( oCMsgAttack* )                                                                 zCall( 0x00752F40 );
    int EV_ShootAt( oCMsgAttack* )                                                               zCall( 0x00753010 );
    int EV_Defend( oCMsgAttack* )                                                                zCall( 0x00753190 );
    int EV_Drink( oCMsgUseItem* )                                                                zCall( 0x007531C0 );
    int EV_TakeVob( oCMsgManipulate* )                                                           zCall( 0x007534E0 );
    int EV_DropVob( oCMsgManipulate* )                                                           zCall( 0x007538C0 );
    int EV_ThrowVob( oCMsgManipulate* )                                                          zCall( 0x00753BB0 );
    int EV_Exchange( oCMsgManipulate* )                                                          zCall( 0x00753E30 );
    int EV_DropMob( oCMsgManipulate* )                                                           zCall( 0x00754130 );
    int EV_TakeMob( oCMsgManipulate* )                                                           zCall( 0x007541F0 );
    int EV_UseMob( oCMsgManipulate* )                                                            zCall( 0x00754290 );
    int EV_UseMobWithItem( oCMsgManipulate* )                                                    zCall( 0x00754490 );
    int EV_InsertInteractItem( oCMsgManipulate* )                                                zCall( 0x007544E0 );
    int EV_ExchangeInteractItem( oCMsgManipulate* )                                              zCall( 0x007546F0 );
    int EV_RemoveInteractItem( oCMsgManipulate* )                                                zCall( 0x00754880 );
    int EV_CreateInteractItem( oCMsgManipulate* )                                                zCall( 0x00754890 );
    int EV_DestroyInteractItem( oCMsgManipulate* )                                               zCall( 0x00754B40 );
    zCModelAni* InteractItemGetAni( zSTRING const&, int, int )                                   zCall( 0x00754D10 );
    int EV_PlaceInteractItem( oCMsgManipulate* )                                                 zCall( 0x00755020 );
    int GetInteractItemMaxState( zSTRING const& )                                                zCall( 0x00755150 );
    int InteractItemIsInState( zSTRING const&, int )                                             zCall( 0x00755360 );
    int EV_EquipItem( oCMsgManipulate* )                                                         zCall( 0x00755580 );
    int EV_UseItem( oCMsgManipulate* )                                                           zCall( 0x00755620 );
    int EV_UseItemToState( oCMsgManipulate* )                                                    zCall( 0x007558F0 );
    void CallScript( zSTRING const& )                                                            zCall( 0x007561D0 );
    void CallScript( int )                                                                       zCall( 0x00756200 );
    int EV_CallScript( oCMsgManipulate* )                                                        zCall( 0x00756220 );
    int EV_Unconscious( oCMsgState* )                                                            zCall( 0x00756390 );
    int EV_DoState( oCMsgState* )                                                                zCall( 0x00756600 );
    int EV_Wait( oCMsgState* )                                                                   zCall( 0x00756820 );
    int ApplyTimedOverlayMds( zSTRING const&, float )                                            zCall( 0x00756890 );
    int EV_OutputSVM_Overlay( oCMsgConversation* )                                               zCall( 0x00756A60 );
    int EV_OutputSVM( oCMsgConversation* )                                                       zCall( 0x007571F0 );
    int EV_Output( oCMsgConversation* )                                                          zCall( 0x007576F0 );
    int EV_PlayAni( oCMsgConversation* )                                                         zCall( 0x00757AB0 );
    int EV_PlayAniFace( oCMsgConversation* )                                                     zCall( 0x00757CE0 );
    int StartDialogAni()                                                                         zCall( 0x00757DE0 );
    int EV_PlayAniSound( oCMsgConversation* )                                                    zCall( 0x00758050 );
    int ActivateDialogCam( float )                                                               zCall( 0x00758130 );
    int DeactivateDialogCam()                                                                    zCall( 0x00758360 );
    int EV_PlaySound( oCMsgConversation* )                                                       zCall( 0x007584F0 );
    int EV_SndPlay( oCMsgConversation* )                                                         zCall( 0x007590A0 );
    int EV_PrintScreen( oCMsgConversation* )                                                     zCall( 0x00759270 );
    void AddEffect( zSTRING const&, zCVob const* )                                               zCall( 0x00759530 );
    void RemoveEffect( zSTRING const& )                                                          zCall( 0x007597D0 );
    int EV_StartFX( oCMsgConversation* )                                                         zCall( 0x007598F0 );
    int EV_StopFX( oCMsgConversation* )                                                          zCall( 0x00759910 );
    int EV_LookAt( oCMsgConversation* )                                                          zCall( 0x00759A40 );
    int EV_StopLookAt( oCMsgConversation* )                                                      zCall( 0x00759E80 );
    int EV_PointAt( oCMsgConversation* )                                                         zCall( 0x00759F40 );
    int EV_StopPointAt( oCMsgConversation* )                                                     zCall( 0x0075A0E0 );
    int EV_QuickLook( oCMsgConversation* )                                                       zCall( 0x0075A130 );
    int EV_Cutscene( oCMsgConversation* )                                                        zCall( 0x0075A3C0 );
    int EV_WaitTillEnd( oCMsgConversation* )                                                     zCall( 0x0075A5B0 );
    int EV_StopProcessInfos( oCMsgConversation* )                                                zCall( 0x0075A660 );
    int EV_ProcessInfos( oCMsgConversation* )                                                    zCall( 0x0075A680 );
    int AssessPlayer_S( oCNpc* )                                                                 zCall( 0x0075A740 );
    int AssessEnemy_S( oCNpc* )                                                                  zCall( 0x0075A940 );
    int AssessFighter_S( oCNpc* )                                                                zCall( 0x0075AB40 );
    int AssessBody_S( oCNpc* )                                                                   zCall( 0x0075AD40 );
    int AssessItem_S( oCItem* )                                                                  zCall( 0x0075AF40 );
    void SetNpcsToState( int, int )                                                              zCall( 0x0075B140 );
    void StopCutscenes()                                                                         zCall( 0x0075B210 );
    void CreatePassivePerception( int, zCVob*, zCVob* )                                          zCall( 0x0075B270 );
    int AssessMurder_S( oCNpc* )                                                                 zCall( 0x0075C040 );
    int AssessThreat_S( oCNpc* )                                                                 zCall( 0x0075C060 );
    int AssessDefeat_S( oCNpc* )                                                                 zCall( 0x0075C260 );
    int AssessDamage_S( oCNpc*, int )                                                            zCall( 0x0075C280 );
    int AssessOthersDamage_S( oCNpc*, oCNpc*, int )                                              zCall( 0x0075C420 );
    int AssessRemoveWeapon_S( oCNpc* )                                                           zCall( 0x0075C440 );
    int ObserveIntruder_S()                                                                      zCall( 0x0075C460 );
    int AssessWarn_S( oCNpc* )                                                                   zCall( 0x0075C510 );
    int CatchThief_S( oCNpc* )                                                                   zCall( 0x0075C530 );
    int AssessTheft_S( oCNpc* )                                                                  zCall( 0x0075C6D0 );
    int AssessCall_S( oCNpc* )                                                                   zCall( 0x0075C6F0 );
    int AssessTalk_S( oCNpc* )                                                                   zCall( 0x0075C890 );
    int AssessGivenItem_S( oCNpc*, oCItem* )                                                     zCall( 0x0075CA30 );
    int AssessMagic_S( oCNpc*, int )                                                             zCall( 0x0075CC30 );
    int AssessStopMagic_S( oCNpc*, int )                                                         zCall( 0x0075CF30 );
    int AssessCaster_S( oCSpell* )                                                               zCall( 0x0075D200 );
    int AssessFakeGuild_S()                                                                      zCall( 0x0075D220 );
    int MoveMob_S( oCMOB* )                                                                      zCall( 0x0075D250 );
    int AssessUseMob_S( oCMobInter* )                                                            zCall( 0x0075D300 );
    int MoveNpc_S( oCNpc* )                                                                      zCall( 0x0075D350 );
    int AssessEnterRoom_S()                                                                      zCall( 0x0075D4F0 );
    float GetDistToSound()                                                                       zCall( 0x0075D500 );
    zCVob* GetSoundSource()                                                                      zCall( 0x0075D5C0 );
    void SetSoundSource( int, zCVob*, zVEC3& )                                                   zCall( 0x0075D5D0 );
    void ClearPerceptionLists()                                                                  zCall( 0x0075D640 );
    void CreateVobList( zCArray<zCVob*>&, float )                                                zCall( 0x0075D730 );
    void ClearVobList()                                                                          zCall( 0x0075D7F0 );
    void InsertInVobList( zCVob* )                                                               zCall( 0x0075D870 );
    void RemoveFromVobList( zCVob* )                                                             zCall( 0x0075D9B0 );
    void CreateVobList( float )                                                                  zCall( 0x0075DA40 );
    void SetPerceptionTime( float )                                                              zCall( 0x0075DBA0 );
    void PerceiveAll()                                                                           zCall( 0x0075DBE0 );
    void PerceptionCheck()                                                                       zCall( 0x0075DD30 );
    int PercFilterNpc( oCNpc* )                                                                  zCall( 0x0075E1D0 );
    int PercFilterItem( oCItem* )                                                                zCall( 0x0075E1E0 );
    void ClearPerception()                                                                       zCall( 0x0075E200 );
    void EnablePerception( int, int )                                                            zCall( 0x0075E220 );
    void DisablePerception( int )                                                                zCall( 0x0075E360 );
    int HasPerception( int )                                                                     zCall( 0x0075E3C0 );
    int GetPerceptionFunc( int )                                                                 zCall( 0x0075E400 );
    void SetBodyState( int )                                                                     zCall( 0x0075E920 );
    int GetBodyState()                                                                           zCall( 0x0075EAE0 );
    int GetFullBodyState()                                                                       zCall( 0x0075EAF0 );
    zSTRING GetBodyStateName()                                                                   zCall( 0x0075EB10 );
    int HasBodyStateModifier( int )                                                              zCall( 0x0075EBF0 );
    void SetBodyStateModifier( int )                                                             zCall( 0x0075EC10 );
    void ClrBodyStateModifier( int )                                                             zCall( 0x0075EC40 );
    zSTRING GetBodyStateModifierNames()                                                          zCall( 0x0075EC70 );
    int ModifyBodyState( int, int )                                                              zCall( 0x0075EF50 );
    int IsBodyStateInterruptable()                                                               zCall( 0x0075EFA0 );
    int HasBodyStateFreeHands()                                                                  zCall( 0x0075EFD0 );
    int IsInGlobalCutscene()                                                                     zCall( 0x0075F000 );
    void MakeSpellBook()                                                                         zCall( 0x0075F040 );
    void DestroySpellBook()                                                                      zCall( 0x0075F0C0 );
    float GetDamageMultiplier()                                                                  zCall( 0x0075F2F0 );
    void SetDamageMultiplier( float )                                                            zCall( 0x0075F300 );
    void SetShowNews( int )                                                                      zCall( 0x0075F480 );
    void UseStandAI()                                                                            zCall( 0x0075F4D0 );
    void SetItemEffectControledByModel( oCItem*, zCModelNodeInst*, int, int, int )               zCall( 0x0075F560 );
    int IsVictimAwareOfTheft()                                                                   zCall( 0x00761EF0 );
    void CheckSpecialSituations()                                                                zCall( 0x00761F80 );
    void StopTheft( oCNpc*, int )                                                                zCall( 0x00762160 );
    void OpenInventory( int )                                                                    zCall( 0x00762250 );
    void CloseInventory()                                                                        zCall( 0x00762410 );
    int OpenSteal()                                                                              zCall( 0x00762430 );
    void CloseSteal()                                                                            zCall( 0x00762950 );
    void OpenDeadNpc()                                                                           zCall( 0x00762970 );
    void CloseDeadNpc()                                                                          zCall( 0x00762B40 );
    static void EnableDamageDebugOutput( int )                                                   zCall( 0x006643C0 );
    static void NotifyDamageToSpy( zSTRING& )                                                    zCall( 0x006643D0 );
    static void InitFightAI()                                                                    zCall( 0x0067C420 );
    static void ExitFightAI()                                                                    zCall( 0x0067C770 );
    static zSTRING GetInstanceByID( int )                                                        zCall( 0x00745940 );
    static int GetIDByInstance( zSTRING const& )                                                 zCall( 0x007459A0 );
    static void CreateSoundPerception( int, zCVob*, zVEC3 const&, zCVob*, int )                  zCall( 0x0075BB70 );
    static int AssessFightSound_S( zCVob*, zVEC3 const&, zCVob* )                                zCall( 0x0075C4A0 );
    static int AssessQuietSound_S( zCVob*, zVEC3 const& )                                        zCall( 0x0075C4D0 );
    static void SetPerceptionRange( int, float )                                                 zCall( 0x0075E440 );
    static int IsInPerceptionRange( int, float )                                                 zCall( 0x0075E460 );
    static int IsInPerceptionRange( int, zCVob*, zCVob* )                                        zCall( 0x0075E490 );
    static void InitStatics()                                                                    zCall( 0x0075E4D0 );
    static void ReleaseStatics()                                                                 zCall( 0x0075E8B0 );
    static void InitBodyStates()                                                                 zCall( 0x0075E8C0 );
    static void SetNpcAIDisabled( int )                                                          zCall( 0x0075F310 );
    static void ProcessAITimer()                                                                 zCall( 0x0075F360 );
    static int IsScriptStateAIEnabled()                                                          zCall( 0x0075F3E0 );
    static int IsMessageAIEnabled()                                                              zCall( 0x0075F430 );
    static zCObject* _CreateNewInstance()                                                        zCall( 0x0075FA00 );
    virtual zCClassDef* _GetClassDef() const                                                     zCall( 0x0072E370 );
    virtual void Archive( zCArchiver& )                                                          zCall( 0x00746470 );
    virtual void Unarchive( zCArchiver& )                                                        zCall( 0x00747230 );
    virtual ~oCNpc()                                                                             zCall( 0x0072E6A0 );
    virtual void OnTouch( zCVob* )                                                               zCall( 0x0074AF20 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                            zCall( 0x0074B020 );
    virtual zCVob::zTVobCharClass GetCharacterClass()                                            zCall( 0x0074ACB0 );
    virtual void SetVisual( zCVisual* )                                                          zCall( 0x0072E3F0 );
    virtual int GetScriptInstance( zSTRING*&, int& )                                             zCall( 0x007458C0 );
    virtual int SetByScriptInstance( zSTRING const*, int )                                       zCall( 0x007458F0 );
    virtual int GetCSStateFlags()                                                                zCall( 0x00732A10 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                 zCall( 0x0073DFA0 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                             zCall( 0x0073E170 );
    virtual void ShowDebugInfo( zCCamera* )                                                      zCall( 0x0075F0F0 );
    virtual int GetInstance()                                                                    zCall( 0x0072E380 );
    virtual zSTRING GetInstanceName()                                                            zCall( 0x00745880 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int )     zCall( 0x0073EB80 );
    virtual void SetWeaponMode( int )                                                            zCall( 0x00739940 );
    virtual void SetWeaponMode2( int )                                                           zCall( 0x00738E80 );
    virtual void DoDie( oCNpc* )                                                                 zCall( 0x00736760 );
    virtual oCItem* DoInsertMunition( zSTRING const& )                                           zCall( 0x00744190 );
    virtual void DoRemoveMunition()                                                              zCall( 0x00744470 );
    virtual int DoSetToFightMode( oCItem* )                                                      zCall( 0x00745350 );
    virtual int DoShootArrow( int )                                                              zCall( 0x007446B0 );
    virtual void OnDamage( oSDamageDescriptor& )                                                 zCall( 0x006660E0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )                            zCall( 0x0067B860 );
    virtual void ResetPos( zVEC3& )                                                              zCall( 0x006824D0 );
    virtual void EmergencyResetPos( zVEC3& )                                                     zCall( 0x006827D0 );
    virtual void InitByScript( int, int )                                                        zCall( 0x0072EE70 );
    virtual void Disable()                                                                       zCall( 0x00745A20 );
    virtual void Enable( zVEC3& )                                                                zCall( 0x00745D40 );
    virtual void InitHumanAI()                                                                   zCall( 0x0072F5B0 );
    virtual int IsMoreImportant( zCVob*, zCVob* )                                                zCall( 0x0075D6E0 );
    virtual int DoDoAniEvents()                                                                  zCall( 0x00742A20 );
    virtual int DoModelSwapMesh( zSTRING const&, zSTRING const& )                                zCall( 0x00743DC0 );
    virtual int DoTakeVob( zCVob* )                                                              zCall( 0x007449C0 );
    virtual int DoDropVob( zCVob* )                                                              zCall( 0x00744DD0 );
    virtual int DoRemoveFromInventory( oCItem* )                                                 zCall( 0x00745300 );
    virtual int DoPutInInventory( oCItem* )                                                      zCall( 0x007452E0 );
    virtual int DoThrowVob( zCVob*, float )                                                      zCall( 0x007450B0 );
    virtual int DoExchangeTorch()                                                                zCall( 0x00745370 );
    virtual void GetSoundMaterial_MA( zCSoundManager::zTSndManMedium&, oTSndMaterial&, zSTRING ) zCall( 0x0073EA10 );
    virtual void GetSoundMaterial_MH_HM( zCSoundManager::zTSndManMedium&, oTSndMaterial& )       zCall( 0x0073EC50 );
    virtual int IsAPlayer()                                                                      zCall( 0x007425A0 );
    virtual int IsSelfPlayer()                                                                   zCall( 0x007425B0 );
    virtual void SetAsPlayer()                                                                   zCall( 0x007426A0 );
    virtual int IsMonster()                                                                      zCall( 0x00742600 );
    virtual int IsHuman()                                                                        zCall( 0x00742640 );
    virtual int IsGoblin()                                                                       zCall( 0x00742650 );
    virtual int IsOrc()                                                                          zCall( 0x00742670 );
    virtual int IsSkeleton()                                                                     zCall( 0x00742680 );
    virtual int GetPlayerNumber()                                                                zCall( 0x007425C0 );
    virtual int IsAniMessageRunning()                                                            zCall( 0x0072E390 );
    virtual void ProcessNpc()                                                                    zCall( 0x0073E480 );
    virtual int AllowDiscardingOfSubtree()                                                       zCall( 0x00748DE0 );

    // static properties
    static zSTRING*& FightAIInstances;
    static oEBloodMode& modeBlood;
    static int& isEnabledDamageDebug;
    static oCStealContainer*& stealcontainer;
    static int& s_bEnabledDialogCamStop;
    static int& s_bTargetLocked;
    static zMAT4& s_playerPositionMatrix;
    static oCNpc*& player;
    static int& godmode;
    static int& angle_near;
    static int& angle_far_up;
    static int& angle_far_side;
    static int& game_mode;
    static oCNpc*& dontArchiveThisNpc;
    static int*& bodyStateList;
    static int& ai_disabled;
    static float& ai_messagesSkip;
    static float& ai_messagesSkipTimer;
    static float& ai_scriptStateSkip;
    static float& ai_scriptStateSkipTimer;
    static int& ai_baseEnabled;
    static int& isEnabledTalkBox;
    static int& isEnabledTalkBoxPlayer;
    static int& isEnabledTalkBoxAmbient;
    static int& isEnabledTalkBoxNoise;

    // user API
    #include "oCNpc.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ONPC_H__VER3__