// Supported with union (c) 2018 Union team

#ifndef __ONPC_H__VER2__
#define __ONPC_H__VER2__

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

namespace Gothic_II_Classic {
  static const int NPC_ATR_HITPOINTS                    = 0;
  static const int NPC_ATR_HITPOINTSMAX                 = 1;
  static const int NPC_ATR_MANA                         = 2;
  static const int NPC_ATR_MANAMAX                      = 3;
  static const int NPC_ATR_STRENGTH                     = 4;
  static const int NPC_ATR_DEXTERITY                    = 5;
  static const int NPC_ATR_REGENERATEHP                 = 6;
  static const int NPC_ATR_REGENERATEMANA               = 7;
  static const int NPC_ATR_MAX                          = 8;
  static const int NPC_TAL_FIGHT_USED                   = 0x00000FFF;
  static const int NPC_TAL_FIGHT_MAX                    = 12;
  static const int NPC_TAL_USED                         = 0x0000024D;
  static const int NPC_TAL_MAX                          = 17;
  static const int NPC_HITCHANCE_1H                     = 1;
  static const int NPC_HITCHANCE_2H                     = 2;
  static const int NPC_HITCHANCE_BOW                    = 3;
  static const int NPC_HITCHANCE_CROSSBOW               = 4;
  static const int NPC_HITCHANCE_MAX                    = 5;
  static const char* PLAYER_MOB_MISSING_KEY             = "PLAYER_MOB_MISSING_KEY";
  static const char* PLAYER_MOB_MISSING_LOCKPICK        = "PLAYER_MOB_MISSING_LOCKPICK";
  static const char* PLAYER_MOB_MISSING_KEY_OR_LOCKPICK = "PLAYER_MOB_MISSING_KEY_OR_LOCKPICK";
  static const char* PLAYER_MOB_NEVER_OPEN              = "PLAYER_MOB_NEVER_OPEN";
  static const char* PLAYER_MOB_TOO_FAR_AWAY            = "PLAYER_MOB_TOO_FAR_AWAY";
  static const char* PLAYER_MOB_WRONG_SIDE              = "PLAYER_MOB_WRONG_SIDE";
  static const char* PLAYER_MOB_MISSING_ITEM            = "PLAYER_MOB_MISSING_ITEM";
  static const char* PLAYER_MOB_ANOTHER_IS_USING        = "PLAYER_MOB_ANOTHER_IS_USING";
  static const char* PLAYER_PLUNDER_IS_EMPTY            = "PLAYER_PLUNDER_IS_EMPTY";
  static const char* PLAYER_RANGED_NO_AMMO              = "PLAYER_RANGED_NO_AMMO";
  static const char* NPC_NODE_RIGHTHAND                 = "ZS_RIGHTHAND";
  static const char* NPC_NODE_LEFTHAND                  = "ZS_LEFTHAND";
  static const char* NPC_NODE_SWORD                     = "ZS_SWORD";
  static const char* NPC_NODE_LONGSWORD                 = "ZS_LONGSWORD";
  static const char* NPC_NODE_BOW                       = "ZS_BOW";
  static const char* NPC_NODE_CROSSBOW                  = "ZS_CROSSBOW";
  static const char* NPC_NODE_SHIELD                    = "ZS_SHIELD";
  static const char* NPC_NODE_HELMET                    = "ZS_HELMET";
  static const char* NPC_NODE_JAWS                      = "ZS_JAWS";
  static const char* NPC_NODE_TORSO                     = "ZS_TORSO";
  static const char* NPC_NODE_LEFTARM                   = "ZS_LEFTARM";
  static const int NPC_FLAG_NFOCUS                      = 1<<18;
  static const int BS_STAND                             = 0;
  static const int BS_WALK                              = 1;
  static const int BS_SNEAK                             = 2;
  static const int BS_RUN                               = 3;
  static const int BS_SPRINT                            = 4;
  static const int BS_SWIM                              = 5;
  static const int BS_CRAWL                             = 6;
  static const int BS_DIVE                              = 7;
  static const int BS_JUMP                              = 8;
  static const int BS_CLIMB                             = 9;
  static const int BS_FALL                              = 10;
  static const int BS_SIT                               = 11;
  static const int BS_LIE                               = 12;
  static const int BS_INVENTORY                         = 13;
  static const int BS_ITEMINTERACT                      = 14;
  static const int BS_MOBINTERACT                       = 15;
  static const int BS_MOBINTERACT_INTERRUPT             = 16;
  static const int BS_TAKEITEM                          = 17;
  static const int BS_DROPITEM                          = 18;
  static const int BS_THROWITEM                         = 19;
  static const int BS_PICKPOCKET                        = 20;
  static const int BS_STUMBLE                           = 21;
  static const int BS_UNCONSCIOUS                       = 22;
  static const int BS_DEAD                              = 23;
  static const int BS_AIMNEAR                           = 24;
  static const int BS_AIMFAR                            = 25;
  static const int BS_HIT                               = 26;
  static const int BS_PARADE                            = 27;
  static const int BS_CASTING                           = 28;
  static const int BS_PETRIFIED                         = 29;
  static const int BS_CONTROLLING                       = 30;
  static const int BS_MAX                               = 31;
  static const int BS_MOD_HIDDEN                        = 128;
  static const int BS_MOD_DRUNK                         = 256;
  static const int BS_MOD_NUTS                          = 512;
  static const int BS_MOD_BURNING                       = 1024;
  static const int BS_MOD_CONTROLLED                    = 2048;
  static const int BS_MOD_TRANSFORMED                   = 4096;
  static const int BS_MOD_CONTROLLING                   = 8192;
  static const int BS_FLAG_INTERRUPTABLE                = 32768;
  static const int BS_FLAG_FREEHANDS                    = 65536;
  static const int BS_ONLY_STATE                        = BS_MOD_HIDDEN - 1;
  static const int BS_MOD_ACTIVE                        = BS_MOD_HIDDEN | BS_MOD_DRUNK | BS_MOD_NUTS | BS_MOD_BURNING | BS_MOD_CONTROLLED | BS_MOD_TRANSFORMED | BS_MOD_CONTROLLING;
  static const int NPC_ATT_MAX                          = 4;
  static const int NPC_NAME_MAX                         = 5;
  static const int NPC_MIS_MAX                          = 5;
  static const int NPC_FLAG_FRIENDS                     = 1 << 0;
  static const int NPC_FLAG_IMMORTAL                    = 1 << 1;
  static const int NPC_FLAG_PROTECTED                   = 1 << 2;
  static const int NPC_SENSE_SEE                        = 1 << 0;
  static const int NPC_SENSE_HEAR                       = 1 << 1;
  static const int NPC_SENSE_SMELL                      = 1 << 2;
  static const float NPC_TURNVELOCITY                   = 150.0f;
  static const int NPC_GIL_NONE                         = 0;
  static const int NPC_GIL_PALADIN                      = 1;
  static const int NPC_GIL_MILIZ                        = 2;
  static const int NPC_GIL_VOLK                         = 3;
  static const int NPC_GIL_FEUERKREIS                   = 4;
  static const int NPC_GIL_NOVIZE                       = 5;
  static const int NPC_GIL_DRACHENJAEGER                = 6;
  static const int NPC_GIL_SOELDNER                     = 7;
  static const int NPC_GIL_BAUERN                       = 8;
  static const int NPC_GIL_BANDIT                       = 9;
  static const int NPC_GIL_PRISONER                     = 10;
  static const int NPC_GIL_DEMENTOR                     = 11;
  static const int NPC_GIL_EMTPY1                       = 12;
  static const int NPC_GIL_EMTPY2                       = 13;
  static const int NPC_GIL_EMTPY3                       = 14;
  static const int NPC_GIL_EMTPY4                       = 15;
  static const int NPC_GIL_HUMANS                       = 16;
  static const int NPC_GIL_MEATBUG                      = 17;
  static const int NPC_GIL_SHEEP                        = 18;
  static const int NPC_GIL_GOBBO                        = 19;
  static const int NPC_GIL_GOBBO_SKELETON               = 20;
  static const int NPC_GIL_SUMMONED_GOBBO_SKELETON      = 21;
  static const int NPC_GIL_SCAVANGER                    = 22;
  static const int NPC_GIL_GIANT_RAT                    = 23;
  static const int NPC_GIL_GIANT_BUG                    = 24;
  static const int NPC_GIL_BLOODFLY                     = 25;
  static const int NPC_GIL_WARAN                        = 26;
  static const int NPC_GIL_WOLF                         = 27;
  static const int NPC_GIL_SUMMONED_WOLF                = 28;
  static const int NPC_GIL_MINECRAWLER                  = 29;
  static const int NPC_GIL_LURKER                       = 30;
  static const int NPC_GIL_SKELETON                     = 31;
  static const int NPC_GIL_SUMMONED_SKELETON            = 32;
  static const int NPC_GIL_SKELETON_MAGE                = 33;
  static const int NPC_GIL_ZOMBIE                       = 34;
  static const int NPC_GIL_SNAPPER                      = 35;
  static const int NPC_GIL_SHADOWBEAST                  = 36;
  static const int NPC_GIL_SHADOWBEAST_SKELETON         = 37;
  static const int NPC_GIL_HARPY                        = 38;
  static const int NPC_GIL_STONEGOLEM                   = 39;
  static const int NPC_GIL_FIREGOLEM                    = 40;
  static const int NPC_GIL_ICEGOLEM                     = 41;
  static const int NPC_GIL_SUMMONED_GOLEM               = 42;
  static const int NPC_GIL_DEMON                        = 43;
  static const int NPC_GIL_SUMMONED_DEMON               = 44;
  static const int NPC_GIL_TROLL                        = 45;
  static const int NPC_GIL_SWAMPSHARK                   = 46;
  static const int NPC_GIL_DRAGON                       = 47;
  static const int NPC_GIL_MOLERAT                      = 48;
  static const int NPC_GIL_MONSTEREMPTY1                = 49;
  static const int NPC_GIL_MONSTEREMPTY2                = 50;
  static const int NPC_GIL_MONSTEREMPTY3                = 51;
  static const int NPC_GIL_MONSTEREMPTY4                = 52;
  static const int NPC_GIL_MONSTEREMPTY5                = 53;
  static const int NPC_GIL_ORCS                         = 54;
  static const int NPC_GIL_FRIENDLYORC                  = 56;
  static const int NPC_GIL_UNDEADORC                    = 57;
  static const int NPC_GIL_DRACONIAN                    = 58;
  static const int NPC_GIL_EMPTYORC1                    = 59;
  static const int NPC_GIL_EMPTYORC2                    = 60;
  static const int NPC_GIL_EMPTYORC3                    = 61;
  static const int NPC_GIL_MAX                          = 62;
  static const int FA_MAX_SITUATIONS                    = 19;
  static const int FA_MAX_ENTRY                         = 6;

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

    void oCNpcTalent_OnInit()                              zCall( 0x006CE430 );
    oCNpcTalent()                                          zInit( oCNpcTalent_OnInit() );
    static zCObject* _CreateNewInstance()                  zCall( 0x006CE2A0 );
    static void CreateTalentList( zCArray<oCNpcTalent*>* ) zCall( 0x006CE5E0 );
    virtual zCClassDef* _GetClassDef() const               zCall( 0x006CE420 );
    virtual void Archive( zCArchiver& )                    zCall( 0x006CE720 );
    virtual void Unarchive( zCArchiver& )                  zCall( 0x006CE760 );
    virtual ~oCNpcTalent()                                 zCall( 0x006CE5D0 );

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

    void TNpcSlot_OnInit() zCall( 0x006D0100 );
    void SetVob( oCVob* )  zCall( 0x006CE7D0 );
    void ClearVob()        zCall( 0x006CE880 );
    TNpcSlot()             zInit( TNpcSlot_OnInit() );
    ~TNpcSlot()            zCall( 0x006D0B30 );

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
      void InitBlock( zCParser*, int, int ) zCall( 0x00792DA0 );
      int GetOwnAction( int )               zCall( 0x00792FC0 );
    } oSActionBlock;

    typedef struct oSFightAI {
    public:
      oSActionBlock myactions[FA_MAX_SITUATIONS];

      oSFightAI() {}
      void Init( zCParser*, int ) zCall( 0x00792FF0 );
      int GetOwnAction( int )     zCall( 0x00793020 );
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
      void oSDamageDescriptor_OnInit( oSDamageDescriptor const& ) zCall( 0x0077AFE0 );
      ~oSDamageDescriptor()                                       zCall( 0x00494730 );
      void Release()                                              zCall( 0x0077AF00 );
      void SetVisualFX( oCVisualFX* )                             zCall( 0x0077AF50 );
      void SetFXHit( oCVisualFX* )                                zCall( 0x0077AFA0 );
      oSDamageDescriptor( oSDamageDescriptor const& a0 )          zInit( oSDamageDescriptor_OnInit( a0 ));
      oSDamageDescriptor& operator =( oSDamageDescriptor const& ) zCall( 0x0077B0A0 );
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
      ~oTRobustTrace() zCall( 0x006D01A0 );

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
      void TActiveInfo_OnInit( oCNpc const* ) zCall( 0x006CE8D0 );
      TActiveInfo( oCNpc const* a0 )          zInit( TActiveInfo_OnInit( a0 ));
      ~TActiveInfo()                          zCall( 0x006CE8E0 );

      // user API
      #include "oCNpc_TActiveInfo.inl"
    };

    class oCNpcTimedOverlay {
    public:
      zSTRING mdsOverlayName;
      float timer;

      oCNpcTimedOverlay() {}
      zSTRING GetMdsName() zCall( 0x006DFFE0 );
      ~oCNpcTimedOverlay() zCall( 0x006E0040 );
      int Process()        zCall( 0x00700520 );

      // user API
      #include "oCNpc_oCNpcTimedOverlay.inl"
    };

    group {
      int idx;
      zSTRING name[5];
      zSTRING slot;
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
      int aiscriptvars[70];
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

    void oCNpc_OnInit()                                                                          zCall( 0x0081FFC1 );
    int IsWaitingForAnswer()                                                                     zCall( 0x0065FDA0 );
    int SetCurrentAnswer( int, int, oCNpc* )                                                     zCall( 0x0065FDF0 );
    int EV_Ask( oCMsgConversation* )                                                             zCall( 0x00660310 );
    int EV_WaitForQuestion( oCMsgConversation* )                                                 zCall( 0x00660390 );
    int CanTalk()                                                                                zCall( 0x00660560 );
    void SetCanTalk( int )                                                                       zCall( 0x00660580 );
    void SetTalkingWith( oCNpc*, int )                                                           zCall( 0x006605A0 );
    oCNpc* GetTalkingWith()                                                                      zCall( 0x006605D0 );
    void StartTalkingWith( oCNpc* )                                                              zCall( 0x006605E0 );
    void StopTalkingWith()                                                                       zCall( 0x00660600 );
    zCEventMessage* GetTalkingWithMessage( oCNpc* )                                              zCall( 0x00660620 );
    int CanBeTalkedTo()                                                                          zCall( 0x006606D0 );
    void StopRunningOU()                                                                         zCall( 0x006608B0 );
    int AssessGivenItem( oCItem*, oCNpc* )                                                       zCall( 0x00660A20 );
    oCNpc* GetTradeNpc()                                                                         zCall( 0x00660BC0 );
    void SetTradeNpc( oCNpc* )                                                                   zCall( 0x00660BD0 );
    oCItem* GetTradeItem()                                                                       zCall( 0x00660BE0 );
    void OpenTradeContainer( oCItem*, oCNpc*, int )                                              zCall( 0x00660C00 );
    void CloseTradeContainer()                                                                   zCall( 0x00660DE0 );
    void OpenTradeOffer( oCNpc* )                                                                zCall( 0x00660E90 );
    int CheckItemReactModule( oCNpc*, oCItem* )                                                  zCall( 0x00660FB0 );
    void ExchangeTradeModules( oCNpc* )                                                          zCall( 0x00661130 );
    zSTRING GetBloodTexture()                                                                    zCall( 0x00676B30 );
    TActiveInfo const* GetActiveInfo() const                                                     zCall( 0x006CE920 );
    TActiveInfo* GetActiveInfoWritable() const                                                   zCall( 0x006CE940 );
    void Shrink()                                                                                zCall( 0x006CE990 );
    void UnShrink()                                                                              zCall( 0x006CEA10 );
    void AvoidShrink( int )                                                                      zCall( 0x006CF050 );
    int ApplyOverlay( zSTRING const& )                                                           zCall( 0x006CF0C0 );
    void RemoveOverlay( zSTRING const& )                                                         zCall( 0x006CF3C0 );
    void SetModelScale( zVEC3 const& )                                                           zCall( 0x006CF5B0 );
    void SetFatness( float )                                                                     zCall( 0x006CF6A0 );
    oCNpc()                                                                                      zInit( oCNpc_OnInit() );
    void CleanUp()                                                                               zCall( 0x006D01E0 );
    void DeleteHumanAI()                                                                         zCall( 0x006D1280 );
    zSTRING GetGuildName()                                                                       zCall( 0x006D12C0 );
    zSTRING GetName( int )                                                                       zCall( 0x006D1450 );
    int IsHostile( oCNpc* )                                                                      zCall( 0x006D14A0 );
    int IsFriendly( oCNpc* )                                                                     zCall( 0x006D1530 );
    int IsNeutral( oCNpc* )                                                                      zCall( 0x006D15C0 );
    int IsAngry( oCNpc* )                                                                        zCall( 0x006D1650 );
    int GetAttitude( oCNpc* )                                                                    zCall( 0x006D16E0 );
    int GetPermAttitude( oCNpc* )                                                                zCall( 0x006D1760 );
    void SetAttitude( int )                                                                      zCall( 0x006D17B0 );
    void SetTmpAttitude( int )                                                                   zCall( 0x006D1800 );
    int GetProtectionByIndex( oEIndexDamage )                                                    zCall( 0x006D1850 );
    int GetProtectionByType( oETypeDamage )                                                      zCall( 0x006D1860 );
    int GetProtectionByMode( unsigned long )                                                     zCall( 0x006D1900 );
    int GetFullProtection()                                                                      zCall( 0x006D1990 );
    void SetProtectionByIndex( oEIndexDamage, int )                                              zCall( 0x006D19B0 );
    int GetDamageByIndex( oEIndexDamage )                                                        zCall( 0x006D19D0 );
    int GetDamageByType( oETypeDamage )                                                          zCall( 0x006D19E0 );
    int GetDamageByMode( unsigned long )                                                         zCall( 0x006D1A80 );
    int GetFullDamage()                                                                          zCall( 0x006D1B10 );
    void SetDamages( int* )                                                                      zCall( 0x006D1B30 );
    int GetAttribute( int )                                                                      zCall( 0x006D1B50 );
    int GetHitChance( int )                                                                      zCall( 0x006D1B60 );
    void SetHitChance( int, int )                                                                zCall( 0x006D1B70 );
    void ChangeAttribute( int, int )                                                             zCall( 0x006D1B90 );
    void SetAttribute( int, int )                                                                zCall( 0x006D1C20 );
    int GetOverlay( zSTRING& )                                                                   zCall( 0x006D1C40 );
    void CheckModelOverlays()                                                                    zCall( 0x006D1E00 );
    void SetToMad( float )                                                                       zCall( 0x006D2020 );
    void HealFromMad()                                                                           zCall( 0x006D2160 );
    void SetToDrunk( float )                                                                     zCall( 0x006D2280 );
    void HealFromDrunk()                                                                         zCall( 0x006D2290 );
    void CheckAngryTime()                                                                        zCall( 0x006D22A0 );
    int CanRecruitSC()                                                                           zCall( 0x006D2350 );
    int IsDisguised()                                                                            zCall( 0x006D2360 );
    int GetGuild()                                                                               zCall( 0x006D2380 );
    void SetGuild( int )                                                                         zCall( 0x006D2390 );
    int GetTrueGuild()                                                                           zCall( 0x006D23A0 );
    void SetTrueGuild( int )                                                                     zCall( 0x006D23B0 );
    int GetCamp()                                                                                zCall( 0x006D23C0 );
    int IsGuildFriendly( int )                                                                   zCall( 0x006D23D0 );
    int GetGuildAttitude( int )                                                                  zCall( 0x006D2400 );
    void CreateItems( int, int )                                                                 zCall( 0x006D2430 );
    void SetFlag( int )                                                                          zCall( 0x006D2510 );
    int HasFlag( int )                                                                           zCall( 0x006D2530 );
    oCNpcTalent* GetTalent( int, int )                                                           zCall( 0x006D2550 );
    void SetTalentValue( int, int )                                                              zCall( 0x006D2730 );
    int GetTalentValue( int )                                                                    zCall( 0x006D2910 );
    void SetTalentSkill( int, int )                                                              zCall( 0x006D2AB0 );
    int GetTalentSkill( int )                                                                    zCall( 0x006D3340 );
    int HasTalent( int, int )                                                                    zCall( 0x006D34E0 );
    int CanUse( oCItem* )                                                                        zCall( 0x006D3500 );
    void DisplayCannotUse()                                                                      zCall( 0x006D3800 );
    void CheckAllCanUse()                                                                        zCall( 0x006D3930 );
    oCVob* GetSlotVob( zSTRING const& )                                                          zCall( 0x006D3A40 );
    oCItem* GetSlotItem( zSTRING const& )                                                        zCall( 0x006D3AE0 );
    oCItem* GetItem( int, int )                                                                  zCall( 0x006D3B80 );
    oCNpc* GetSlotNpc( zSTRING const& )                                                          zCall( 0x006D3BA0 );
    void AddItemEffects( oCItem* )                                                               zCall( 0x006D3C40 );
    void RemoveItemEffects( oCItem* )                                                            zCall( 0x006D3DC0 );
    void EquipItem( oCItem* )                                                                    zCall( 0x006D3F10 );
    void UnequipItem( oCItem* )                                                                  zCall( 0x006D4190 );
    int GetCutsceneDistance()                                                                    zCall( 0x006D4400 );
    void SetCSEnabled( int )                                                                     zCall( 0x006D4450 );
    void SetFocusVob( zCVob* )                                                                   zCall( 0x006D4540 );
    zCVob* GetFocusVob()                                                                         zCall( 0x006D4590 );
    void ClearFocusVob()                                                                         zCall( 0x006D45A0 );
    oCNpc* GetFocusNpc()                                                                         zCall( 0x006D45D0 );
    oCNpc* GetNearestFightNpcLeft()                                                              zCall( 0x006D4600 );
    oCNpc* GetNearestFightNpcRight()                                                             zCall( 0x006D4790 );
    int FocusCheckBBox( zCVob const*, int, int, float, float& )                                  zCall( 0x006D4920 );
    int FocusCheck( zCVob const*, int, int, float, float& )                                      zCall( 0x006D4BA0 );
    void ToggleFocusVob( int )                                                                   zCall( 0x006D4F90 );
    void CollectFocusVob( int )                                                                  zCall( 0x006D53F0 );
    void GetNearestValidVob( float )                                                             zCall( 0x006D5ED0 );
    void GetNearestVob( float )                                                                  zCall( 0x006D6240 );
    oCAniCtrl_Human* GetAnictrl()                                                                zCall( 0x006D6520 );
    void ResetToHumanAI()                                                                        zCall( 0x006D6530 );
    void SetEnemy( oCNpc* )                                                                      zCall( 0x006D65A0 );
    oCNpc* GetNextEnemy()                                                                        zCall( 0x006D67E0 );
    int IsConditionValid()                                                                       zCall( 0x006D6A60 );
    int IsInFightFocus( zCVob* )                                                                 zCall( 0x006D6B30 );
    oCItem* HasEquippedStolenItem( oCNpc* )                                                      zCall( 0x006D6BA0 );
    void Burn( int, float )                                                                      zCall( 0x006D6DC0 );
    void StopBurn()                                                                              zCall( 0x006D7040 );
    void Interrupt( int, int )                                                                   zCall( 0x006D7350 );
    int GetWeaponDamage( oCItem* )                                                               zCall( 0x006D76D0 );
    int GetBluntDamage( oCItem* )                                                                zCall( 0x006D7720 );
    void DropUnconscious( float, oCNpc* )                                                        zCall( 0x006D7750 );
    void CheckUnconscious()                                                                      zCall( 0x006D7AD0 );
    zSTRING GetInterruptPrefix()                                                                 zCall( 0x006D7F20 );
    void CompleteHeal()                                                                          zCall( 0x006D7FC0 );
    int IsUnconscious()                                                                          zCall( 0x006D7FF0 );
    void StartFadeAway()                                                                         zCall( 0x006D85E0 );
    int IsFadingAway()                                                                           zCall( 0x006D86D0 );
    int FadeAway()                                                                               zCall( 0x006D86E0 );
    int BeamTo( zSTRING const& )                                                                 zCall( 0x006D8780 );
    void DropInventory()                                                                         zCall( 0x006D8A40 );
    int HasInHand( int )                                                                         zCall( 0x006D8A50 );
    int HasInHand( zCVob* )                                                                      zCall( 0x006D8BA0 );
    void RemoveFromHand()                                                                        zCall( 0x006D8CD0 );
    void DropAllInHand()                                                                         zCall( 0x006D8EA0 );
    oCItem* GetWeapon()                                                                          zCall( 0x006D9060 );
    oCItem* GetEquippedMeleeWeapon()                                                             zCall( 0x006D91F0 );
    oCItem* GetEquippedRangedWeapon()                                                            zCall( 0x006D9300 );
    oCItem* GetEquippedArmor()                                                                   zCall( 0x006D9410 );
    int IsSameHeight( zCVob* )                                                                   zCall( 0x006D94A0 );
    void TurnToEnemy()                                                                           zCall( 0x006D9590 );
    int ShieldEquipped()                                                                         zCall( 0x006D9710 );
    int GetWeaponDamage()                                                                        zCall( 0x006D97E0 );
    void SetMovLock( int )                                                                       zCall( 0x006D9970 );
    int IsMovLock()                                                                              zCall( 0x006D99A0 );
    void SetHead()                                                                               zCall( 0x006D99B0 );
    void SetAdditionalVisuals( zSTRING&, int, int, zSTRING&, int, int, int )                     zCall( 0x006D9C10 );
    void InitModel()                                                                             zCall( 0x006D9D40 );
    zCModel* GetModel()                                                                          zCall( 0x006D9FE0 );
    zSTRING GetVisualBody()                                                                      zCall( 0x006DA080 );
    zSTRING GetVisualHead()                                                                      zCall( 0x006DA0D0 );
    int StartFaceAni( zSTRING const&, float, float )                                             zCall( 0x006DA120 );
    int StartStdFaceAni( int )                                                                   zCall( 0x006DA220 );
    int StopFaceAni( zSTRING const& )                                                            zCall( 0x006DA410 );
    int GetWeaponMode()                                                                          zCall( 0x006DA500 );
    void SetWeaponMode2_novt( zSTRING const& )                                                   zCall( 0x006DA520 );
    int GetNextWeaponMode( int, int, int )                                                       zCall( 0x006DB2F0 );
    void Equip( oCItem* )                                                                        zCall( 0x006DB550 );
    void EquipWeapon( oCItem* )                                                                  zCall( 0x006DB870 );
    void EquipFarWeapon( oCItem* )                                                               zCall( 0x006DBB50 );
    void EquipArmor( oCItem* )                                                                   zCall( 0x006DBCD0 );
    void SetToFightMode( oCItem*, int )                                                          zCall( 0x006DBF70 );
    void SetToFistMode()                                                                         zCall( 0x006DC180 );
    void Activate( int, int )                                                                    zCall( 0x006DC380 );
    oCVob* GetRightHand()                                                                        zCall( 0x006DC390 );
    oCVob* GetLeftHand()                                                                         zCall( 0x006DC420 );
    void DropVob( oCVob*, zVEC3& )                                                               zCall( 0x006DC4B0 );
    void SetCarryVob( zCVob* )                                                                   zCall( 0x006DC640 );
    zCVob* GetCarryVob()                                                                         zCall( 0x006DC8F0 );
    void SetLeftHand( oCVob* )                                                                   zCall( 0x006DC900 );
    void SetRightHand( oCVob* )                                                                  zCall( 0x006DCA00 );
    int HasTorch()                                                                               zCall( 0x006DCB00 );
    void ExchangeTorch()                                                                         zCall( 0x006DCC40 );
    void SetTorchAni( int, int )                                                                 zCall( 0x006DCC50 );
    void CheckSetTorchAni()                                                                      zCall( 0x006DCF10 );
    void CheckPutbackTorch()                                                                     zCall( 0x006DD180 );
    int UseItem( oCItem* )                                                                       zCall( 0x006DD450 );
    float GetThrowSpeed( float, float )                                                          zCall( 0x006DDA60 );
    int HasArrowInHand()                                                                         zCall( 0x006DDA90 );
    int HasArrowInInv()                                                                          zCall( 0x006DDBE0 );
    int HasBoltInInv()                                                                           zCall( 0x006DDCD0 );
    int HasBoltInHand()                                                                          zCall( 0x006DDDC0 );
    int IsMunitionAvailable( oCItem* )                                                           zCall( 0x006DDF10 );
    void GetTalentInfo( int, zSTRING&, zSTRING&, zSTRING& )                                      zCall( 0x006DE090 );
    void GetSpellInfo( int, zSTRING&, zSTRING& )                                                 zCall( 0x006DE2C0 );
    void GetAttribInfo( int, zSTRING&, zSTRING& )                                                zCall( 0x006DE4B0 );
    void CreateSpell( int )                                                                      zCall( 0x006DE650 );
    void LearnSpell( int )                                                                       zCall( 0x006DE6B0 );
    int HasSpell( int )                                                                          zCall( 0x006DE6F0 );
    void DestroySpell( int )                                                                     zCall( 0x006DE710 );
    void SetActiveSpellInfo( int )                                                               zCall( 0x006DE750 );
    int GetActiveSpellNr()                                                                       zCall( 0x006DE790 );
    int GetActiveSpellCategory()                                                                 zCall( 0x006DE7D0 );
    int GetActiveSpellLevel()                                                                    zCall( 0x006DE810 );
    void InsertActiveSpell( oCSpell* )                                                           zCall( 0x006DE850 );
    void RemoveActiveSpell( oCSpell* )                                                           zCall( 0x006DE870 );
    void RemoveActiveSpell( int )                                                                zCall( 0x006DE900 );
    int DoActiveSpells()                                                                         zCall( 0x006DE9B0 );
    void KillActiveSpells()                                                                      zCall( 0x006DEA90 );
    oCSpell* IsSpellActive( int )                                                                zCall( 0x006DEB20 );
    int HasMagic()                                                                               zCall( 0x006DEB60 );
    int GetNumberOfSpells()                                                                      zCall( 0x006DEB90 );
    void CopyTransformSpellInvariantValuesTo( oCNpc* )                                           zCall( 0x006DEBB0 );
    void OpenScreen_Help()                                                                       zCall( 0x006DED90 );
    void OpenScreen_Log()                                                                        zCall( 0x006DEDA0 );
    void OpenScreen_Map()                                                                        zCall( 0x006DF0B0 );
    void OpenScreen_Status()                                                                     zCall( 0x006DF160 );
    int IsVoiceActive()                                                                          zCall( 0x006DFA60 );
    void StopAllVoices()                                                                         zCall( 0x006DFA70 );
    int UpdateNextVoice()                                                                        zCall( 0x006DFAD0 );
    void DoSpellBook()                                                                           zCall( 0x006E0090 );
    void OpenSpellBook( int )                                                                    zCall( 0x006E00A0 );
    void CloseSpellBook( int )                                                                   zCall( 0x006E00F0 );
    oCMag_Book* GetSpellBook()                                                                   zCall( 0x006E0110 );
    int HasSenseHear()                                                                           zCall( 0x006E0430 );
    int HasSenseSee()                                                                            zCall( 0x006E0440 );
    int HasSenseSmell()                                                                          zCall( 0x006E0450 );
    void SetSenses( int )                                                                        zCall( 0x006E0460 );
    void PrintStateCallDebug( zSTRING const&, int, int )                                         zCall( 0x006E0470 );
    int GetOldScriptState()                                                                      zCall( 0x006E06E0 );
    int GetAIState()                                                                             zCall( 0x006E06F0 );
    int GetAIStateTime()                                                                         zCall( 0x006E0700 );
    int IsAIState( int )                                                                         zCall( 0x006E0710 );
    void ShowState( int, int )                                                                   zCall( 0x006E0720 );
    int IsNear( oCNpc* )                                                                         zCall( 0x006E13D0 );
    oCItem* DetectItem( int, int )                                                               zCall( 0x006E1450 );
    oCNpc* DetectPlayer()                                                                        zCall( 0x006E1510 );
    oCMobInter* FindMobInter( zSTRING const& )                                                   zCall( 0x006E1580 );
    zCVobSpot* FindSpot( zSTRING const&, int, float )                                            zCall( 0x006E17F0 );
    void ForceVobDetection( zCVob* )                                                             zCall( 0x006E1B80 );
    int HasVobDetected( zCVob* )                                                                 zCall( 0x006E1CC0 );
    int CheckForOwner( zCVob* )                                                                  zCall( 0x006E1D00 );
    void AI_ForceDetection()                                                                     zCall( 0x006E1E40 );
    int CanSense( zCVob* )                                                                       zCall( 0x006E1E50 );
    void DetectWitnesses( oCNpc*, int )                                                          zCall( 0x006E1EF0 );
    oCNpc* FindNpc( int, int, int, int )                                                         zCall( 0x006E2190 );
    oCNpc* FindNpcEx( int, int, int, int, int, int )                                             zCall( 0x006E2290 );
    oCNpc* FindNpcExAtt( int, int, int, int, int, int, int )                                     zCall( 0x006E2480 );
    int GetComrades()                                                                            zCall( 0x006E26D0 );
    int AreWeStronger( oCNpc* )                                                                  zCall( 0x006E28D0 );
    oCNpc* IsEnemyBehindFriend( oCNpc* )                                                         zCall( 0x006E2BF0 );
    int InMobInteraction( zSTRING const&, int )                                                  zCall( 0x006E2DF0 );
    int FreeLineOfSight( zCVob* )                                                                zCall( 0x006E2ED0 );
    int FreeLineOfSight( zVEC3&, zCVob* )                                                        zCall( 0x006E2F30 );
    int FreeLineOfSight_WP( zVEC3&, zCVob* )                                                     zCall( 0x006E3090 );
    int CanSee( zCVob*, int )                                                                    zCall( 0x006E3200 );
    void SetSwimDiveTime( float, float )                                                         zCall( 0x006E3560 );
    void GetSwimDiveTime( float&, float&, float& )                                               zCall( 0x006E3590 );
    void Regenerate()                                                                            zCall( 0x006E35C0 );
    void RefreshNpc()                                                                            zCall( 0x006E3700 );
    void RenderNpc( zCView* )                                                                    zCall( 0x006E3960 );
    void SetKnowsPlayer( int )                                                                   zCall( 0x006E3BC0 );
    int KnowsPlayer( oCNpc* )                                                                    zCall( 0x006E3BD0 );
    int KnowsPlayer( int )                                                                       zCall( 0x006E3BE0 );
    int HasMunitionInHand( oCItem* )                                                             zCall( 0x006E55D0 );
    void Pack( zCBuffer& )                                                                       zCall( 0x006E6B10 );
    void Unpack( zCBuffer& )                                                                     zCall( 0x006E6BA0 );
    int IsInFightMode_S( int )                                                                   zCall( 0x006E6C40 );
    int IsAiming_S( oCNpc* )                                                                     zCall( 0x006E6CC0 );
    void ClearEM()                                                                               zCall( 0x006E7960 );
    void PreSaveGameProcessing()                                                                 zCall( 0x006E9DA0 );
    void PostSaveGameProcessing()                                                                zCall( 0x006EA0B0 );
    oCItem* IdentifyMushroom( oCItem* )                                                          zCall( 0x006EA310 );
    void IdentifyAllMushrooms()                                                                  zCall( 0x006EA500 );
    int HasMissionItem()                                                                         zCall( 0x006EA630 );
    oCItem* IsInInv( oCItem*, int )                                                              zCall( 0x006EA680 );
    oCItem* GetFromInv( int, int )                                                               zCall( 0x006EA6A0 );
    oCItem* IsInInv( int, int )                                                                  zCall( 0x006EA700 );
    oCItem* IsInInv( zSTRING const&, int )                                                       zCall( 0x006EA720 );
    int CanCarry( oCItem* )                                                                      zCall( 0x006EA740 );
    oCItem* PutInInv( oCItem* )                                                                  zCall( 0x006EA870 );
    oCItem* PutInInv( int, int )                                                                 zCall( 0x006EAA00 );
    oCItem* PutInInv( zSTRING const&, int )                                                      zCall( 0x006EAAB0 );
    oCItem* RemoveFromInv( oCItem*, int )                                                        zCall( 0x006EAAE0 );
    oCItem* RemoveFromInv( int, int )                                                            zCall( 0x006EAB30 );
    oCItem* RemoveFromInv( zSTRING const&, int )                                                 zCall( 0x006EAB80 );
    int IsSlotFree( zSTRING const& )                                                             zCall( 0x006EABD0 );
    int IsSlotFree( TNpcSlot* )                                                                  zCall( 0x006EACA0 );
    void SetToSlotPosition( zCVob*, zSTRING const& )                                             zCall( 0x006EACC0 );
    void CreateInvSlot( zSTRING const& )                                                         zCall( 0x006EAD00 );
    void DeleteInvSlot( zSTRING const& )                                                         zCall( 0x006EAEE0 );
    TNpcSlot* GetInvSlot( zSTRING const& )                                                       zCall( 0x006EAFE0 );
    TNpcSlot* GetInvSlot( zCVob* )                                                               zCall( 0x006EB0A0 );
    int IsInvSlotAvailable( zSTRING const& )                                                     zCall( 0x006EB0E0 );
    void PutInSlot( zSTRING const&, oCVob*, int )                                                zCall( 0x006EB1B0 );
    void PutInSlot( TNpcSlot*, oCVob*, int )                                                     zCall( 0x006EB280 );
    void RemoveFromAllSlots( int )                                                               zCall( 0x006EB6B0 );
    oCVob* RemoveFromSlot( zSTRING const&, int )                                                 zCall( 0x006EB6F0 );
    oCVob* RemoveFromSlot( TNpcSlot*, int )                                                      zCall( 0x006EB7C0 );
    oCVob* DropFromSlot( zSTRING const& )                                                        zCall( 0x006EBA10 );
    oCVob* DropFromSlot( TNpcSlot* )                                                             zCall( 0x006EBAE0 );
    void UpdateSlots()                                                                           zCall( 0x006EBDA0 );
    void SetInteractMob( oCMobInter* )                                                           zCall( 0x006EBE30 );
    oCMobInter* GetInteractMob()                                                                 zCall( 0x006EBFD0 );
    void SetInteractItem( oCItem* )                                                              zCall( 0x006EBFF0 );
    int EV_DrawWeapon( oCMsgWeapon* )                                                            zCall( 0x006EDEF0 );
    int EV_DrawWeapon1( oCMsgWeapon* )                                                           zCall( 0x006EE570 );
    int EV_DrawWeapon2( oCMsgWeapon* )                                                           zCall( 0x006EE810 );
    int EV_RemoveWeapon( oCMsgWeapon* )                                                          zCall( 0x006EEDB0 );
    int EV_RemoveWeapon1( oCMsgWeapon* )                                                         zCall( 0x006EF6E0 );
    int EV_RemoveWeapon2( oCMsgWeapon* )                                                         zCall( 0x006EF860 );
    int EV_ChooseWeapon( oCMsgWeapon* )                                                          zCall( 0x006EFBB0 );
    int EV_ForceRemoveWeapon( oCMsgWeapon* )                                                     zCall( 0x006EFE70 );
    int EV_EquipBestWeapon( oCMsgWeapon* )                                                       zCall( 0x006F0130 );
    void EquipBestWeapon( int )                                                                  zCall( 0x006F0150 );
    int EV_EquipBestArmor( oCMsgWeapon* )                                                        zCall( 0x006F0240 );
    void EquipBestArmor()                                                                        zCall( 0x006F02D0 );
    int EV_UnequipWeapons( oCMsgWeapon* )                                                        zCall( 0x006F0350 );
    int EV_UnequipArmor( oCMsgWeapon* )                                                          zCall( 0x006F0510 );
    int EV_EquipArmor( oCMsgWeapon* )                                                            zCall( 0x006F05C0 );
    int EV_AttackForward( oCMsgAttack* )                                                         zCall( 0x006F0620 );
    int EV_AttackLeft( oCMsgAttack* )                                                            zCall( 0x006F1380 );
    int EV_AttackRight( oCMsgAttack* )                                                           zCall( 0x006F1F20 );
    int EV_AttackRun( oCMsgAttack* )                                                             zCall( 0x006F29F0 );
    int EV_AttackFinish( oCMsgAttack* )                                                          zCall( 0x006F2D10 );
    int EV_Parade( oCMsgAttack* )                                                                zCall( 0x006F34F0 );
    int InitAim( oCMsgAttack*, oCNpc**, int*, int*, int )                                        zCall( 0x006F3BC0 );
    int TransitionAim( int, int )                                                                zCall( 0x006F3D50 );
    int InterpolateAim( oCNpc* )                                                                 zCall( 0x006F3EE0 );
    int FinalizeAim( int, int )                                                                  zCall( 0x006F4020 );
    int EV_StopAim( oCMsgAttack* )                                                               zCall( 0x006F4140 );
    int EV_AimAt( oCMsgAttack* )                                                                 zCall( 0x006F4160 );
    int EV_ShootAt( oCMsgAttack* )                                                               zCall( 0x006F4230 );
    int EV_Defend( oCMsgAttack* )                                                                zCall( 0x006F43B0 );
    int EV_Drink( oCMsgUseItem* )                                                                zCall( 0x006F43E0 );
    int EV_TakeVob( oCMsgManipulate* )                                                           zCall( 0x006F4700 );
    int EV_DropVob( oCMsgManipulate* )                                                           zCall( 0x006F4A90 );
    int EV_ThrowVob( oCMsgManipulate* )                                                          zCall( 0x006F4D80 );
    int EV_Exchange( oCMsgManipulate* )                                                          zCall( 0x006F5000 );
    int EV_DropMob( oCMsgManipulate* )                                                           zCall( 0x006F5300 );
    int EV_TakeMob( oCMsgManipulate* )                                                           zCall( 0x006F53C0 );
    int EV_UseMob( oCMsgManipulate* )                                                            zCall( 0x006F5460 );
    int EV_UseMobWithItem( oCMsgManipulate* )                                                    zCall( 0x006F5660 );
    int EV_InsertInteractItem( oCMsgManipulate* )                                                zCall( 0x006F56B0 );
    int EV_ExchangeInteractItem( oCMsgManipulate* )                                              zCall( 0x006F58C0 );
    int EV_RemoveInteractItem( oCMsgManipulate* )                                                zCall( 0x006F5A50 );
    int EV_CreateInteractItem( oCMsgManipulate* )                                                zCall( 0x006F5A60 );
    int EV_DestroyInteractItem( oCMsgManipulate* )                                               zCall( 0x006F5D10 );
    zCModelAni* InteractItemGetAni( zSTRING const&, int, int )                                   zCall( 0x006F5EE0 );
    int EV_PlaceInteractItem( oCMsgManipulate* )                                                 zCall( 0x006F61F0 );
    int GetInteractItemMaxState( zSTRING const& )                                                zCall( 0x006F6320 );
    int InteractItemIsInState( zSTRING const&, int )                                             zCall( 0x006F6530 );
    int EV_EquipItem( oCMsgManipulate* )                                                         zCall( 0x006F6750 );
    int EV_UseItem( oCMsgManipulate* )                                                           zCall( 0x006F67F0 );
    int EV_UseItemToState( oCMsgManipulate* )                                                    zCall( 0x006F6AC0 );
    void CallScript( zSTRING const& )                                                            zCall( 0x006F73A0 );
    void CallScript( int )                                                                       zCall( 0x006F73D0 );
    int EV_CallScript( oCMsgManipulate* )                                                        zCall( 0x006F73F0 );
    int EV_Unconscious( oCMsgState* )                                                            zCall( 0x006F7560 );
    int EV_DoState( oCMsgState* )                                                                zCall( 0x006F77D0 );
    int EV_Wait( oCMsgState* )                                                                   zCall( 0x006F79F0 );
    int ApplyTimedOverlayMds( zSTRING const&, float )                                            zCall( 0x006F7A60 );
    int EV_OutputSVM_Overlay( oCMsgConversation* )                                               zCall( 0x006F7C30 );
    int EV_OutputSVM( oCMsgConversation* )                                                       zCall( 0x006F83C0 );
    int EV_Output( oCMsgConversation* )                                                          zCall( 0x006F88C0 );
    int EV_PlayAni( oCMsgConversation* )                                                         zCall( 0x006F8C80 );
    int EV_PlayAniFace( oCMsgConversation* )                                                     zCall( 0x006F8EB0 );
    int StartDialogAni()                                                                         zCall( 0x006F8FB0 );
    int EV_PlayAniSound( oCMsgConversation* )                                                    zCall( 0x006F9220 );
    int ActivateDialogCam( float )                                                               zCall( 0x006F9300 );
    int DeactivateDialogCam()                                                                    zCall( 0x006F9530 );
    int EV_PlaySound( oCMsgConversation* )                                                       zCall( 0x006F96C0 );
    int EV_SndPlay( oCMsgConversation* )                                                         zCall( 0x006FA180 );
    int EV_PrintScreen( oCMsgConversation* )                                                     zCall( 0x006FA350 );
    void AddEffect( zSTRING const&, zCVob const* )                                               zCall( 0x006FA610 );
    void RemoveEffect( zSTRING const& )                                                          zCall( 0x006FA850 );
    int EV_StartFX( oCMsgConversation* )                                                         zCall( 0x006FA970 );
    int EV_StopFX( oCMsgConversation* )                                                          zCall( 0x006FA990 );
    int EV_LookAt( oCMsgConversation* )                                                          zCall( 0x006FAAD0 );
    int EV_StopLookAt( oCMsgConversation* )                                                      zCall( 0x006FAF10 );
    int EV_PointAt( oCMsgConversation* )                                                         zCall( 0x006FAFD0 );
    int EV_StopPointAt( oCMsgConversation* )                                                     zCall( 0x006FB170 );
    int EV_QuickLook( oCMsgConversation* )                                                       zCall( 0x006FB1C0 );
    int EV_Cutscene( oCMsgConversation* )                                                        zCall( 0x006FB450 );
    int EV_WaitTillEnd( oCMsgConversation* )                                                     zCall( 0x006FB640 );
    int EV_StopProcessInfos( oCMsgConversation* )                                                zCall( 0x006FB6F0 );
    int EV_ProcessInfos( oCMsgConversation* )                                                    zCall( 0x006FB710 );
    int AssessPlayer_S( oCNpc* )                                                                 zCall( 0x006FB7D0 );
    int AssessEnemy_S( oCNpc* )                                                                  zCall( 0x006FB9D0 );
    int AssessFighter_S( oCNpc* )                                                                zCall( 0x006FBBD0 );
    int AssessBody_S( oCNpc* )                                                                   zCall( 0x006FBDD0 );
    int AssessItem_S( oCItem* )                                                                  zCall( 0x006FBFD0 );
    void SetNpcsToState( int, int )                                                              zCall( 0x006FC1D0 );
    void StopCutscenes()                                                                         zCall( 0x006FC2A0 );
    void CreatePassivePerception( int, zCVob*, zCVob* )                                          zCall( 0x006FC300 );
    int AssessMurder_S( oCNpc* )                                                                 zCall( 0x006FD0C0 );
    int AssessThreat_S( oCNpc* )                                                                 zCall( 0x006FD0E0 );
    int AssessDefeat_S( oCNpc* )                                                                 zCall( 0x006FD2E0 );
    int AssessDamage_S( oCNpc*, int )                                                            zCall( 0x006FD300 );
    int AssessOthersDamage_S( oCNpc*, oCNpc*, int )                                              zCall( 0x006FD4A0 );
    int AssessRemoveWeapon_S( oCNpc* )                                                           zCall( 0x006FD4C0 );
    int ObserveIntruder_S()                                                                      zCall( 0x006FD4E0 );
    int AssessWarn_S( oCNpc* )                                                                   zCall( 0x006FD590 );
    int CatchThief_S( oCNpc* )                                                                   zCall( 0x006FD5B0 );
    int AssessTheft_S( oCNpc* )                                                                  zCall( 0x006FD750 );
    int AssessCall_S( oCNpc* )                                                                   zCall( 0x006FD770 );
    int AssessTalk_S( oCNpc* )                                                                   zCall( 0x006FD910 );
    int AssessGivenItem_S( oCNpc*, oCItem* )                                                     zCall( 0x006FDAB0 );
    int AssessMagic_S( oCNpc*, int )                                                             zCall( 0x006FDCB0 );
    int AssessStopMagic_S( oCNpc*, int )                                                         zCall( 0x006FDFB0 );
    int AssessCaster_S( oCSpell* )                                                               zCall( 0x006FE280 );
    int AssessFakeGuild_S()                                                                      zCall( 0x006FE2A0 );
    int MoveMob_S( oCMOB* )                                                                      zCall( 0x006FE2D0 );
    int AssessUseMob_S( oCMobInter* )                                                            zCall( 0x006FE380 );
    int MoveNpc_S( oCNpc* )                                                                      zCall( 0x006FE3D0 );
    int AssessEnterRoom_S()                                                                      zCall( 0x006FE570 );
    float GetDistToSound()                                                                       zCall( 0x006FE580 );
    zCVob* GetSoundSource()                                                                      zCall( 0x006FE640 );
    void SetSoundSource( int, zCVob*, zVEC3& )                                                   zCall( 0x006FE650 );
    void ClearPerceptionLists()                                                                  zCall( 0x006FE6C0 );
    void CreateVobList( zCArray<zCVob*>&, float )                                                zCall( 0x006FE7B0 );
    void ClearVobList()                                                                          zCall( 0x006FE870 );
    void InsertInVobList( zCVob* )                                                               zCall( 0x006FE8F0 );
    void RemoveFromVobList( zCVob* )                                                             zCall( 0x006FEA30 );
    void CreateVobList( float )                                                                  zCall( 0x006FEAC0 );
    void SetPerceptionTime( float )                                                              zCall( 0x006FEC20 );
    void PerceiveAll()                                                                           zCall( 0x006FEC60 );
    void PerceptionCheck()                                                                       zCall( 0x006FEDB0 );
    int PercFilterNpc( oCNpc* )                                                                  zCall( 0x006FF250 );
    int PercFilterItem( oCItem* )                                                                zCall( 0x006FF260 );
    void ClearPerception()                                                                       zCall( 0x006FF280 );
    void EnablePerception( int, int )                                                            zCall( 0x006FF2A0 );
    void DisablePerception( int )                                                                zCall( 0x006FF3E0 );
    int HasPerception( int )                                                                     zCall( 0x006FF440 );
    int GetPerceptionFunc( int )                                                                 zCall( 0x006FF480 );
    void SetBodyState( int )                                                                     zCall( 0x006FF9A0 );
    int GetBodyState()                                                                           zCall( 0x006FFB60 );
    int GetFullBodyState()                                                                       zCall( 0x006FFB70 );
    zSTRING GetBodyStateName()                                                                   zCall( 0x006FFB90 );
    int HasBodyStateModifier( int )                                                              zCall( 0x006FFC70 );
    void SetBodyStateModifier( int )                                                             zCall( 0x006FFC90 );
    void ClrBodyStateModifier( int )                                                             zCall( 0x006FFCC0 );
    zSTRING GetBodyStateModifierNames()                                                          zCall( 0x006FFCF0 );
    int ModifyBodyState( int, int )                                                              zCall( 0x006FFFD0 );
    int IsBodyStateInterruptable()                                                               zCall( 0x00700020 );
    int HasBodyStateFreeHands()                                                                  zCall( 0x00700050 );
    int IsInGlobalCutscene()                                                                     zCall( 0x00700080 );
    void MakeSpellBook()                                                                         zCall( 0x007000C0 );
    void DestroySpellBook()                                                                      zCall( 0x00700140 );
    float GetDamageMultiplier()                                                                  zCall( 0x00700370 );
    void SetDamageMultiplier( float )                                                            zCall( 0x00700380 );
    void SetShowNews( int )                                                                      zCall( 0x00700500 );
    void UseStandAI()                                                                            zCall( 0x00700550 );
    int IsVictimAwareOfTheft()                                                                   zCall( 0x007029C0 );
    void CheckSpecialSituations()                                                                zCall( 0x00702A50 );
    void StopTheft( oCNpc*, int )                                                                zCall( 0x00702C20 );
    void OpenInventory( int )                                                                    zCall( 0x00702D10 );
    void CloseInventory()                                                                        zCall( 0x00702ED0 );
    int OpenSteal()                                                                              zCall( 0x00702EF0 );
    void CloseSteal()                                                                            zCall( 0x00703410 );
    void OpenDeadNpc()                                                                           zCall( 0x00703430 );
    void CloseDeadNpc()                                                                          zCall( 0x00703600 );
    void InitDamage()                                                                            zCall( 0x0077B220 );
    int EV_DamageOnce( oCMsgDamage* )                                                            zCall( 0x0077B3F0 );
    int EV_DamagePerFrame( oCMsgDamage* )                                                        zCall( 0x0077B730 );
    void OnDamage_Hit( oSDamageDescriptor& )                                                     zCall( 0x0077D390 );
    void OnDamage_Condition( oSDamageDescriptor& )                                               zCall( 0x00783C70 );
    void OnDamage_Script( oSDamageDescriptor& )                                                  zCall( 0x00784F60 );
    void OnDamage_Effects( oSDamageDescriptor& )                                                 zCall( 0x00785830 );
    void OnDamage_Effects_Start( oSDamageDescriptor& )                                           zCall( 0x00785B80 );
    void OnDamage_Effects_End( oSDamageDescriptor& )                                             zCall( 0x0078B020 );
    void OnDamage_Anim( oSDamageDescriptor& )                                                    zCall( 0x0078C8F0 );
    void OnDamage_Sound( oSDamageDescriptor& )                                                   zCall( 0x007914F0 );
    void OnDamage_Events( oSDamageDescriptor& )                                                  zCall( 0x00791830 );
    void OnDamage_State( oSDamageDescriptor& )                                                   zCall( 0x00792430 );
    int HasFlag( unsigned long, unsigned long )                                                  zCall( 0x00792950 );
    int IsNpcBetweenMeAndTarget( zCVob* )                                                        zCall( 0x00793330 );
    int IsInDoubleFightRange( zCVob*, float& )                                                   zCall( 0x00793500 );
    int IsInFightRange( zCVob*, float& )                                                         zCall( 0x007936C0 );
    int GetFightRange()                                                                          zCall( 0x007938E0 );
    void SetFightRangeBase( int )                                                                zCall( 0x00793910 );
    int GetFightRangeBase()                                                                      zCall( 0x00793920 );
    int GetFightRangeDynamic()                                                                   zCall( 0x00793930 );
    int GetFightRangeFist()                                                                      zCall( 0x00793950 );
    int GetFightRangeG()                                                                         zCall( 0x00793960 );
    void SetFightRangeFist( int )                                                                zCall( 0x00793970 );
    void SetFightRangeG( int )                                                                   zCall( 0x00793980 );
    int GetFightActionFromTable( int )                                                           zCall( 0x00793990 );
    int GetCurrentFightMove()                                                                    zCall( 0x007939D0 );
    int FindNextFightAction()                                                                    zCall( 0x007941E0 );
    int ThinkNextFightAction()                                                                   zCall( 0x00794EB0 );
    int FightAttackMelee( int )                                                                  zCall( 0x007959E0 );
    int FightAttackBow()                                                                         zCall( 0x00796220 );
    int EV_AttackBow( oCMsgAttack* )                                                             zCall( 0x00796300 );
    int FightAttackMagic()                                                                       zCall( 0x00796580 );
    int EV_AttackMagic( oCMsgAttack* )                                                           zCall( 0x00796630 );
    int EV_CastSpell( oCMsgMagic* )                                                              zCall( 0x00796640 );
    void CheckRunningFightAnis()                                                                 zCall( 0x00796930 );
    void GotoFightPosition()                                                                     zCall( 0x00796AE0 );
    void Fighting()                                                                              zCall( 0x00796BD0 );
    oCItem* GetSpellItem( int )                                                                  zCall( 0x00796D90 );
    int ReadySpell( int, int )                                                                   zCall( 0x00796E00 );
    int UnreadySpell()                                                                           zCall( 0x00796FA0 );
    int HasRangedWeaponAndAmmo()                                                                 zCall( 0x00797030 );
    int CanDrawWeapon()                                                                          zCall( 0x007970E0 );
    int CanDive()                                                                                zCall( 0x00797420 );
    int CanSwim()                                                                                zCall( 0x00797450 );
    float GetClimbRange()                                                                        zCall( 0x00797480 );
    float GetTurnSpeed()                                                                         zCall( 0x00797490 );
    float GetJumpRange()                                                                         zCall( 0x007974B0 );
    int RbtChooseChasmAction( zVEC3 const&, zVEC3 const& )                                       zCall( 0x007974C0 );
    int CanGo( float, zVEC3& )                                                                   zCall( 0x00797650 );
    float GetAngle( zCVob* )                                                                     zCall( 0x00797CE0 );
    void GetAngles( zVEC3&, float&, float& )                                                     zCall( 0x00797DD0 );
    void GetAngles( zCVob*, float&, float& )                                                     zCall( 0x007981A0 );
    float GetDistanceToPos2( zVEC3&, int )                                                       zCall( 0x007981E0 );
    float GetFallDownHeight()                                                                    zCall( 0x007982B0 );
    zCVob* GetRbtObstacleVob()                                                                   zCall( 0x007982D0 );
    zVEC3 GetVecNormalFromBBox( zCVob*, zVEC3& )                                                 zCall( 0x007982E0 );
    void SetFallDownDamage( int )                                                                zCall( 0x00798870 );
    void SetFallDownHeight( float )                                                              zCall( 0x00798880 );
    void SetRoute( zCRoute* )                                                                    zCall( 0x00798890 );
    void CreateFallDamage( float )                                                               zCall( 0x007988C0 );
    void Fleeing()                                                                               zCall( 0x00798BE0 );
    int ThinkNextFleeAction()                                                                    zCall( 0x00798BF0 );
    void Follow()                                                                                zCall( 0x00798FE0 );
    void StandUp( int, int )                                                                     zCall( 0x00799640 );
    float Turn( zVEC3& )                                                                         zCall( 0x00799B00 );
    float Turning( zVEC3& )                                                                      zCall( 0x00799C20 );
    void AI_Flee( oCNpc* )                                                                       zCall( 0x00799D10 );
    void AI_Follow( oCNpc* )                                                                     zCall( 0x00799D20 );
    int EV_AlignToFP( oCMsgMovement* )                                                           zCall( 0x00799D30 );
    int EV_CanSeeNpc( oCMsgMovement* )                                                           zCall( 0x00799F80 );
    int EV_GoRoute( oCMsgMovement* )                                                             zCall( 0x00799FD0 );
    int EV_Jump( oCMsgMovement* )                                                                zCall( 0x0079A720 );
    int EV_RobustTrace( oCMsgMovement* )                                                         zCall( 0x0079A780 );
    int EV_StandUp( oCMsgMovement* )                                                             zCall( 0x0079A7E0 );
    int EV_Strafe( oCMsgMovement* )                                                              zCall( 0x0079A8E0 );
    int EV_WhirlAround( oCMsgMovement* )                                                         zCall( 0x0079B6F0 );
    int EV_Dodge( oCMsgMovement* )                                                               zCall( 0x0079BD90 );
    int EV_GotoPos( oCMsgMovement* )                                                             zCall( 0x0079BFC0 );
    int EV_GotoVob( oCMsgMovement* )                                                             zCall( 0x0079C080 );
    int EV_GotoFP( oCMsgMovement* )                                                              zCall( 0x0079C200 );
    int EV_SetWalkMode( oCMsgMovement* )                                                         zCall( 0x0079C4F0 );
    int EV_Turn( oCMsgMovement* )                                                                zCall( 0x0079C8E0 );
    int EV_TurnAway( oCMsgMovement* )                                                            zCall( 0x0079C9C0 );
    int EV_TurnToPos( oCMsgMovement* )                                                           zCall( 0x0079CB70 );
    int EV_TurnToVob( oCMsgMovement* )                                                           zCall( 0x0079CC60 );
    void ForceRotation( float )                                                                  zCall( 0x0079CEF0 );
    int RbtCheckForSolution( zVEC3, zVEC3 )                                                      zCall( 0x0079CF30 );
    void RbtReset()                                                                              zCall( 0x0079D060 );
    void RbtInit( zVEC3&, zCVob* )                                                               zCall( 0x0079D170 );
    void RbtUpdate( zVEC3&, zCVob* )                                                             zCall( 0x0079D190 );
    int RbtMoveToExactPosition()                                                                 zCall( 0x0079D380 );
    int RobustTrace()                                                                            zCall( 0x0079D460 );
    float RbtCalcTurnDirection( zVEC3 const&, float, int )                                       zCall( 0x0079D7A0 );
    int RbtIsObjectObstacle( zCVob*, zVEC3 const&, zVEC3 const&, zVEC3& )                        zCall( 0x0079DB80 );
    int RbtGetObstacle( zVEC3 const&, zVEC3 const&, zCVob*&, zVEC3& )                            zCall( 0x0079DDE0 );
    int RbtGetSmallObstacle( zVEC3 const&, zCVob*&, zVEC3& )                                     zCall( 0x0079DF90 );
    int RbtAvoidObstacles()                                                                      zCall( 0x0079E0E0 );
    int RbtIsDirectionValid( zVEC3 const& )                                                      zCall( 0x0079E770 );
    oSDirectionInfo* RbtInsertDirection( zVEC3 )                                                 zCall( 0x0079E7F0 );
    int RbtCheckLastDirection( float )                                                           zCall( 0x0079EA50 );
    int RbtCheckIfTargetVisible()                                                                zCall( 0x0079ED50 );
    int RbtGotoFollowPosition()                                                                  zCall( 0x0079EF70 );
    int CanStrafe( int, int )                                                                    zCall( 0x0079F190 );
    int CanJumpBack( int )                                                                       zCall( 0x0079F3F0 );
    void SetWalkStopChasm( int )                                                                 zCall( 0x0079F590 );
    int GetWalkStopChasm()                                                                       zCall( 0x0079F5D0 );
    static zSTRING GetInstanceByID( int )                                                        zCall( 0x006E6EA0 );
    static int GetIDByInstance( zSTRING const& )                                                 zCall( 0x006E6F00 );
    static void CreateSoundPerception( int, zCVob*, zVEC3 const&, zCVob*, int )                  zCall( 0x006FCC00 );
    static int AssessFightSound_S( zCVob*, zVEC3 const&, zCVob* )                                zCall( 0x006FD520 );
    static int AssessQuietSound_S( zCVob*, zVEC3 const& )                                        zCall( 0x006FD550 );
    static void SetPerceptionRange( int, float )                                                 zCall( 0x006FF4C0 );
    static int IsInPerceptionRange( int, float )                                                 zCall( 0x006FF4E0 );
    static int IsInPerceptionRange( int, zCVob*, zCVob* )                                        zCall( 0x006FF510 );
    static void InitStatics()                                                                    zCall( 0x006FF550 );
    static void ReleaseStatics()                                                                 zCall( 0x006FF930 );
    static void InitBodyStates()                                                                 zCall( 0x006FF940 );
    static void SetNpcAIDisabled( int )                                                          zCall( 0x00700390 );
    static void ProcessAITimer()                                                                 zCall( 0x007003E0 );
    static int IsScriptStateAIEnabled()                                                          zCall( 0x00700460 );
    static int IsMessageAIEnabled()                                                              zCall( 0x007004B0 );
    static zCObject* _CreateNewInstance()                                                        zCall( 0x007007D0 );
    static void EnableDamageDebugOutput( int )                                                   zCall( 0x0077B150 );
    static void NotifyDamageToSpy( zSTRING& )                                                    zCall( 0x0077B160 );
    static void InitFightAI()                                                                    zCall( 0x00793050 );
    static void ExitFightAI()                                                                    zCall( 0x007932D0 );
    virtual zCClassDef* _GetClassDef() const                                                     zCall( 0x006D0140 );
    virtual void Archive( zCArchiver& )                                                          zCall( 0x006E79D0 );
    virtual void Unarchive( zCArchiver& )                                                        zCall( 0x006E8790 );
    virtual ~oCNpc()                                                                             zCall( 0x006D0450 );
    virtual void OnTouch( zCVob* )                                                               zCall( 0x006EC260 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                            zCall( 0x006EC360 );
    virtual zCVob::zTVobCharClass GetCharacterClass()                                            zCall( 0x006EBFE0 );
    virtual void SetVisual( zCVisual* )                                                          zCall( 0x006D01C0 );
    virtual int GetScriptInstance( zSTRING*&, int& )                                             zCall( 0x006E6E20 );
    virtual int SetByScriptInstance( zSTRING const*, int )                                       zCall( 0x006E6E50 );
    virtual int GetCSStateFlags()                                                                zCall( 0x006D4470 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                 zCall( 0x006DF780 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                             zCall( 0x006DF940 );
    virtual void ShowDebugInfo( zCCamera* )                                                      zCall( 0x00700170 );
    virtual int GetInstance()                                                                    zCall( 0x006D0150 );
    virtual zSTRING GetInstanceName()                                                            zCall( 0x006E6DE0 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int )     zCall( 0x006E0290 );
    virtual void SetWeaponMode( int )                                                            zCall( 0x006DB200 );
    virtual void SetWeaponMode2( int )                                                           zCall( 0x006DA740 );
    virtual void DoDie( oCNpc* )                                                                 zCall( 0x006D8000 );
    virtual oCItem* DoInsertMunition( zSTRING const& )                                           zCall( 0x006E5720 );
    virtual void DoRemoveMunition()                                                              zCall( 0x006E59D0 );
    virtual int DoSetToFightMode( oCItem* )                                                      zCall( 0x006E68C0 );
    virtual int DoShootArrow( int )                                                              zCall( 0x006E5C20 );
    virtual void OnDamage( oSDamageDescriptor& )                                                 zCall( 0x0077CE70 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )                            zCall( 0x007924B0 );
    virtual void ResetPos( zVEC3& )                                                              zCall( 0x00798FF0 );
    virtual void EmergencyResetPos( zVEC3& )                                                     zCall( 0x007992D0 );
    virtual void InitByScript( int, int )                                                        zCall( 0x006D0C10 );
    virtual void Disable()                                                                       zCall( 0x006E6F80 );
    virtual void Enable( zVEC3& )                                                                zCall( 0x006E72C0 );
    virtual void InitHumanAI()                                                                   zCall( 0x006D11E0 );
    virtual int IsMoreImportant( zCVob*, zCVob* )                                                zCall( 0x006FE760 );
    virtual int DoDoAniEvents()                                                                  zCall( 0x006E3FC0 );
    virtual int DoModelSwapMesh( zSTRING const&, zSTRING const& )                                zCall( 0x006E5360 );
    virtual int DoTakeVob( zCVob* )                                                              zCall( 0x006E5F30 );
    virtual int DoDropVob( zCVob* )                                                              zCall( 0x006E6340 );
    virtual int DoRemoveFromInventory( oCItem* )                                                 zCall( 0x006E6870 );
    virtual int DoPutInInventory( oCItem* )                                                      zCall( 0x006E6850 );
    virtual int DoThrowVob( zCVob*, float )                                                      zCall( 0x006E6620 );
    virtual int DoExchangeTorch()                                                                zCall( 0x006E68E0 );
    virtual void GetSoundMaterial_MA( zCSoundManager::zTSndManMedium&, oTSndMaterial&, zSTRING ) zCall( 0x006E0120 );
    virtual void GetSoundMaterial_MH_HM( zCSoundManager::zTSndManMedium&, oTSndMaterial& )       zCall( 0x006E0360 );
    virtual int IsAPlayer()                                                                      zCall( 0x006E3B90 );
    virtual int IsSelfPlayer()                                                                   zCall( 0x006E3BA0 );
    virtual void SetAsPlayer()                                                                   zCall( 0x006E3C90 );
    virtual int IsMonster()                                                                      zCall( 0x006E3BF0 );
    virtual int IsHuman()                                                                        zCall( 0x006E3C30 );
    virtual int IsGoblin()                                                                       zCall( 0x006E3C40 );
    virtual int IsOrc()                                                                          zCall( 0x006E3C60 );
    virtual int IsSkeleton()                                                                     zCall( 0x006E3C70 );
    virtual int GetPlayerNumber()                                                                zCall( 0x006E3BB0 );
    virtual int IsAniMessageRunning()                                                            zCall( 0x006D0160 );
    virtual void ProcessNpc()                                                                    zCall( 0x006DFB90 );
    virtual int AllowDiscardingOfSubtree()                                                       zCall( 0x006EA300 );

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

} // namespace Gothic_II_Classic

#endif // __ONPC_H__VER2__