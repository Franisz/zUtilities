// Supported with union (c) 2018 Union team

#ifndef __ONPC_H__VER1__
#define __ONPC_H__VER1__

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

namespace Gothic_I_Addon {
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
  static const int NPC_TAL_MAX                           = 23;
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
  static const int NPC_SENSE_SEE                         = 1 << 0;
  static const int NPC_SENSE_HEAR                        = 1 << 1;
  static const int NPC_SENSE_SMELL                       = 1 << 2;
  static const float NPC_TURNVELOCITY                    = 150.0f;
  static const int NPC_GIL_NONE                          = 0;
  static const int NPC_GIL_ERZBARONE                     = 1;
  static const int NPC_GIL_SOELDNER                      = 2;
  static const int NPC_GIL_SCHATTEN                      = 3;
  static const int NPC_GIL_FEUERKREIS                    = 4;
  static const int NPC_GIL_VOLK                          = 5;
  static const int NPC_GIL_WASSERKREIS                   = 6;
  static const int NPC_GIL_GARDE                         = 7;
  static const int NPC_GIL_ORGANISATOREN                 = 8;
  static const int NPC_GIL_BAUERN                        = 9;
  static const int NPC_GIL_SCHUERFERBUND                 = 10;
  static const int NPC_GIL_GURUS                         = 11;
  static const int NPC_GIL_NOVIZEN                       = 12;
  static const int NPC_GIL_TEMPLER                       = 13;
  static const int NPC_GIL_DAEMONEN                      = 14;
  static const int NPC_GIL_MEISTER                       = 15;
  static const int NPC_GIL_HUMANS                        = 16;
  static const int NPC_GIL_WARAN                         = 17;
  static const int NPC_GIL_SCHLAEFER                     = 18;
  static const int NPC_GIL_GOBBO                         = 19;
  static const int NPC_GIL_TROLL                         = 20;
  static const int NPC_GIL_SNAPPER                       = 21;
  static const int NPC_GIL_MINECRAWLER                   = 22;
  static const int NPC_GIL_MEATBUG                       = 23;
  static const int NPC_GIL_SCAVANGER                     = 24;
  static const int NPC_GIL_DEMON                         = 25;
  static const int NPC_GIL_WOLF                          = 26;
  static const int NPC_GIL_SHADOW                        = 27;
  static const int NPC_GIL_BLOODFLY                      = 28;
  static const int NPC_GIL_SHARK                         = 29;
  static const int NPC_GIL_ZOMBIE                        = 30;
  static const int NPC_GIL_UNDEAD                        = 31;
  static const int NPC_GIL_SKELETON                      = 32;
  static const int NPC_GIL_ORCDOG                        = 33;
  static const int NPC_GIL_MOLERAT                       = 34;
  static const int NPC_GIL_GOLEM                         = 35;
  static const int NPC_GIL_LURKER                        = 36;
  static const int NPC_GIL_ORCS                          = 37;
  static const int NPC_GIL_ORCSHAMAN                     = 38;
  static const int NPC_GIL_ORCWARRIOR                    = 39;
  static const int NPC_GIL_ORCSCOUT                      = 40;
  static const int NPC_GIL_ORCSLAVE                      = 41;
  static const int NPC_GIL_MAX                           = 42;
  static const int FA_MAX_SITUATIONS                     = 17;
  static const int FA_MAX_ENTRY                          = 6;

  enum {
    NPC_GAME_NORMAL,
    NPC_GAME_PLUNDER,
    NPC_GAME_STEAL
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
    NPC_WEAPON_STAFF,
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
      NPC_TAL_STAFF,
      NPC_TAL_BOW,
      NPC_TAL_CROSSBOW,
      NPC_TAL_PICKLOCK,
      NPC_TAL_PICKPOCKET,
      NPC_TAL_MAGE,
      NPC_TAL_SNEAK,
      NPC_TAL_REGENERATE,
      NPC_TAL_FIREMASTER,
      NPC_TAL_ACROBAT,
      NPC_TAL_USERDEF_1,
      NPC_TAL_USERDEF_2,
      NPC_TAL_USERDEF_3,
      NPC_TAL_USERDEF_4,
      NPC_TAL_USERDEF_5,
      NPC_TAL_USERDEF_6,
      NPC_TAL_USERDEF_7,
      NPC_TAL_USERDEF_8,
      NPC_TAL_USERDEF_9,
      NPC_TAL_USERDEF_10,
      NPC_TAL_MAX
    };

    oTEnumNpcTalent m_talent;
    int m_skill;
    int m_value;

    void oCNpcTalent_OnInit()                                           zCall( 0x006BA650 );
    oCNpcTalent()                                                       zInit( oCNpcTalent_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x006BA4D0 );
    static void CreateTalentList( zCArray<oCNpcTalent*>* )              zCall( 0x006BA800 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006BA640 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006BA970 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006BA9B0 );
    virtual ~oCNpcTalent()                                              zCall( 0x006BA7F0 );

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

    void TNpcSlot_OnInit() zCall( 0x006BC4D0 );
    void SetVob( oCVob* )  zCall( 0x006BAA20 );
    void ClearVob()        zCall( 0x006BAAC0 );
    TNpcSlot()             zInit( TNpcSlot_OnInit() );
    ~TNpcSlot()            zCall( 0x006BCEC0 );

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
      void InitBlock( zCParser*, int, int ) zCall( 0x007890C0 );
    } oSActionBlock;

    typedef struct oSFightAI {
    public:
      oSActionBlock myactions[FA_MAX_SITUATIONS];

      oSFightAI() {}
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
      void oSDamageDescriptor_OnInit( oSDamageDescriptor const& ) zCall( 0x0076DBC0 );
      ~oSDamageDescriptor()                                       zCall( 0x00499260 );
      void Release()                                              zCall( 0x0076DAC0 );
      void SetVisualFX( oCVisualFX* )                             zCall( 0x0076DB20 );
      void SetFXHit( oCVisualFX* )                                zCall( 0x0076DB70 );
      oSDamageDescriptor( oSDamageDescriptor const& a0 )          zInit( oSDamageDescriptor_OnInit( a0 ));
      oSDamageDescriptor& operator =( oSDamageDescriptor const& ) zCall( 0x0076DC80 );
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
      ~oTRobustTrace() zCall( 0x006BC560 );

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
      void TActiveInfo_OnInit( oCNpc const* ) zCall( 0x006BAB10 );
      TActiveInfo( oCNpc const* a0 )          zInit( TActiveInfo_OnInit( a0 ));
      ~TActiveInfo()                          zCall( 0x006BAB20 );

      // user API
      #include "oCNpc_TActiveInfo.inl"
    };

    class oCNpcTimedOverlay {
    public:
      zSTRING mdsOverlayName;
      float timer;

      oCNpcTimedOverlay() {}
      zSTRING GetMdsName() zCall( 0x006CD260 );
      ~oCNpcTimedOverlay() zCall( 0x006CD2D0 );
      int Process()        zCall( 0x006ED610 );

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
      int aiscriptvars[50];
      zSTRING wpname;
      unsigned long experience_points;
      unsigned long experience_points_next_level;
      unsigned long learn_points;
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
    oCVisualFX* visualFX;
    oCMagFrontier magFrontier;
    oCNpc_States state;
    oCNpcInventory inventory2;
    oCItemContainer* trader;
    oCNpc* tradeNpc;
    float rangeToPlayer;
    zCArray<int> listOfVoiceHandles;
    int voiceIndex;
    int showaidebug      : 1;
    int showNews         : 1;
    int csAllowedAsRole  : 1;
    int isSummoned       : 1;
    int respawnOn        : 1;
    int movlock          : 1;
    int drunk            : 1;
    int mad              : 1;
    int overlay_wounded  : 1;
    int inOnDamage       : 1;
    int autoremoveweapon : 1;
    int openinventory    : 1;
    int askroutine       : 1;
    int spawnInRange     : 1;
    int body_TexVarNr    : 16;
    int body_TexColorNr  : 16;
    int head_TexVarNr    : 16;
    int teeth_TexVarNr   : 16;
    int guildTrue        : 8;
    int drunk_heal       : 8;
    int mad_heal         : 8;
    int spells           : 8;
    int bodyState        : 19;
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
    int slotItemsCreated;
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
    float fight_waitTime;
    int fight_waitForAniEnd;
    float fight_lastStrafeFrame;
    int soundType;
    zCVob* soundVob;
    zVEC3 soundPosition;
    zCPlayerGroup* playerGroup;

    void oCNpc_OnInit()                                                                          zCall( 0x00812F90 );
    void SetBloodEmitter( zSTRING )                                                              zCall( 0x00640E90 );
    void SetBloodTexture( zSTRING )                                                              zCall( 0x00641000 );
    int IsWaitingForAnswer()                                                                     zCall( 0x00658BA0 );
    int SetCurrentAnswer( int, int, oCNpc* )                                                     zCall( 0x00658BF0 );
    int EV_Ask( oCMsgConversation* )                                                             zCall( 0x00659140 );
    int EV_WaitForQuestion( oCMsgConversation* )                                                 zCall( 0x006591C0 );
    int CanTalk()                                                                                zCall( 0x006593B0 );
    void SetCanTalk( int )                                                                       zCall( 0x006593D0 );
    void SetTalkingWith( oCNpc*, int )                                                           zCall( 0x006593F0 );
    oCNpc* GetTalkingWith()                                                                      zCall( 0x00659420 );
    void StartTalkingWith( oCNpc* )                                                              zCall( 0x00659430 );
    void StopTalkingWith()                                                                       zCall( 0x00659460 );
    zCEventMessage* GetTalkingWithMessage( oCNpc* )                                              zCall( 0x00659480 );
    int CanBeTalkedTo()                                                                          zCall( 0x00659530 );
    void StopRunningOU()                                                                         zCall( 0x00659720 );
    int AssessGivenItem( oCItem*, oCNpc* )                                                       zCall( 0x00659880 );
    void SetTradeNpc( oCNpc* )                                                                   zCall( 0x00659A30 );
    oCItem* GetTradeItem()                                                                       zCall( 0x00659A40 );
    void OpenTradeContainer( oCItem*, oCNpc*, int )                                              zCall( 0x00659A60 );
    void CloseTradeContainer()                                                                   zCall( 0x00659C10 );
    void OpenTradeOffer( oCNpc* )                                                                zCall( 0x00659CC0 );
    int CheckItemReactModule( oCNpc*, oCItem* )                                                  zCall( 0x00659DE0 );
    void ExchangeTradeModules( oCNpc* )                                                          zCall( 0x00659F60 );
    zSTRING GetBloodTexture()                                                                    zCall( 0x00670650 );
    TActiveInfo const* GetActiveInfo() const                                                     zCall( 0x006BAB60 );
    TActiveInfo* GetActiveInfoWritable() const                                                   zCall( 0x006BAB80 );
    void Shrink()                                                                                zCall( 0x006BABD0 );
    void UnShrink()                                                                              zCall( 0x006BAC50 );
    void AvoidShrink( int )                                                                      zCall( 0x006BB260 );
    int ApplyOverlay( zSTRING const& )                                                           zCall( 0x006BB2D0 );
    void RemoveOverlay( zSTRING const& )                                                         zCall( 0x006BB620 );
    void SetModelScale( zVEC3 const& )                                                           zCall( 0x006BB830 );
    void SetFatness( float )                                                                     zCall( 0x006BB910 );
    oCNpc()                                                                                      zInit( oCNpc_OnInit() );
    void CleanUp()                                                                               zCall( 0x006BC5A0 );
    void DeleteHumanAI()                                                                         zCall( 0x006BD6D0 );
    zSTRING GetGuildName()                                                                       zCall( 0x006BD720 );
    zSTRING GetName( int )                                                                       zCall( 0x006BD8F0 );
    int IsHostile( oCNpc* )                                                                      zCall( 0x006BD940 );
    int IsFriendly( oCNpc* )                                                                     zCall( 0x006BD9E0 );
    int IsNeutral( oCNpc* )                                                                      zCall( 0x006BDA80 );
    int IsAngry( oCNpc* )                                                                        zCall( 0x006BDB20 );
    int GetAttitude( oCNpc* )                                                                    zCall( 0x006BDBC0 );
    int GetPermAttitude( oCNpc* )                                                                zCall( 0x006BDC40 );
    void SetAttitude( int )                                                                      zCall( 0x006BDC90 );
    void SetTmpAttitude( int )                                                                   zCall( 0x006BDCE0 );
    int GetProtectionByIndex( oEIndexDamage )                                                    zCall( 0x006BDD30 );
    int GetProtectionByType( oETypeDamage )                                                      zCall( 0x006BDD40 );
    int GetProtectionByMode( unsigned long )                                                     zCall( 0x006BDDE0 );
    int GetFullProtection()                                                                      zCall( 0x006BDE70 );
    void SetProtectionByIndex( oEIndexDamage, int )                                              zCall( 0x006BDE90 );
    int GetDamageByIndex( oEIndexDamage )                                                        zCall( 0x006BDEB0 );
    int GetDamageByType( oETypeDamage )                                                          zCall( 0x006BDEC0 );
    int GetDamageByMode( unsigned long )                                                         zCall( 0x006BDF60 );
    int GetFullDamage()                                                                          zCall( 0x006BDFF0 );
    void SetDamages( int* )                                                                      zCall( 0x006BE010 );
    int GetAttribute( int )                                                                      zCall( 0x006BE030 );
    void ChangeAttribute( int, int )                                                             zCall( 0x006BE040 );
    void SetAttribute( int, int )                                                                zCall( 0x006BE0C0 );
    int GetOverlay( zSTRING& )                                                                   zCall( 0x006BE0E0 );
    void CheckModelOverlays()                                                                    zCall( 0x006BE2E0 );
    void SetToMad( float )                                                                       zCall( 0x006BE540 );
    void HealFromMad()                                                                           zCall( 0x006BE6C0 );
    void SetToDrunk( float )                                                                     zCall( 0x006BE830 );
    void HealFromDrunk()                                                                         zCall( 0x006BE840 );
    void CheckAngryTime()                                                                        zCall( 0x006BE850 );
    int CanRecruitSC()                                                                           zCall( 0x006BE900 );
    int IsDisguised()                                                                            zCall( 0x006BE910 );
    int GetGuild()                                                                               zCall( 0x006BE930 );
    void SetGuild( int )                                                                         zCall( 0x006BE940 );
    int GetTrueGuild()                                                                           zCall( 0x006BE950 );
    void SetTrueGuild( int )                                                                     zCall( 0x006BE960 );
    int GetCamp()                                                                                zCall( 0x006BE990 );
    int IsGuildFriendly( int )                                                                   zCall( 0x006BE9A0 );
    int GetGuildAttitude( int )                                                                  zCall( 0x006BE9D0 );
    void CreateItems( int, int )                                                                 zCall( 0x006BEA00 );
    void SetFlag( int )                                                                          zCall( 0x006BEAF0 );
    int HasFlag( int )                                                                           zCall( 0x006BEB10 );
    oCNpcTalent* GetTalent( int, int )                                                           zCall( 0x006BEB30 );
    void SetTalentValue( int, int )                                                              zCall( 0x006BED50 );
    int GetTalentValue( int )                                                                    zCall( 0x006BEF70 );
    void SetTalentSkill( int, int )                                                              zCall( 0x006BF130 );
    int GetTalentSkill( int )                                                                    zCall( 0x006BF970 );
    int HasTalent( int, int )                                                                    zCall( 0x006BFB30 );
    int CanUse( oCItem* )                                                                        zCall( 0x006BFB50 );
    void DisplayCannotUse()                                                                      zCall( 0x006BFE90 );
    void CheckAllCanUse()                                                                        zCall( 0x006BFFE0 );
    oCVob* GetSlotVob( zSTRING const& )                                                          zCall( 0x006C00E0 );
    oCItem* GetSlotItem( zSTRING const& )                                                        zCall( 0x006C0180 );
    oCItem* GetItem( int, int )                                                                  zCall( 0x006C0220 );
    oCNpc* GetSlotNpc( zSTRING const& )                                                          zCall( 0x006C0240 );
    void AddItemEffects( oCItem* )                                                               zCall( 0x006C02E0 );
    void RemoveItemEffects( oCItem* )                                                            zCall( 0x006C0470 );
    void EquipItem( oCItem* )                                                                    zCall( 0x006C05E0 );
    void UnequipItem( oCItem* )                                                                  zCall( 0x006C08C0 );
    void RemoveSlotItems()                                                                       zCall( 0x006C0B90 );
    int GetCutsceneDistance()                                                                    zCall( 0x006C11A0 );
    void SetCSEnabled( int )                                                                     zCall( 0x006C1200 );
    void SetFocusVob( zCVob* )                                                                   zCall( 0x006C12E0 );
    zCVob* GetFocusVob()                                                                         zCall( 0x006C1330 );
    void ClearFocusVob()                                                                         zCall( 0x006C1340 );
    oCNpc* GetFocusNpc()                                                                         zCall( 0x006C1380 );
    oCNpc* GetNearestFightNpcLeft()                                                              zCall( 0x006C13C0 );
    oCNpc* GetNearestFightNpcRight()                                                             zCall( 0x006C1550 );
    int FocusCheckBBox( zCVob const*, int, int, float, float& )                                  zCall( 0x006C16E0 );
    int FocusCheck( zCVob const*, int, int, float, float& )                                      zCall( 0x006C19C0 );
    void ToggleFocusVob( int )                                                                   zCall( 0x006C1D70 );
    void CollectFocusVob()                                                                       zCall( 0x006C2210 );
    void GetNearestValidVob( float )                                                             zCall( 0x006C2A00 );
    void GetNearestVob( float )                                                                  zCall( 0x006C2D20 );
    oCAniCtrl_Human* GetAnictrl()                                                                zCall( 0x006C3010 );
    void ResetToHumanAI()                                                                        zCall( 0x006C3020 );
    void SetEnemy( oCNpc* )                                                                      zCall( 0x006C30A0 );
    oCNpc* GetNextEnemy()                                                                        zCall( 0x006C32F0 );
    int IsConditionValid()                                                                       zCall( 0x006C3570 );
    int IsInFightFocus( zCVob* )                                                                 zCall( 0x006C3630 );
    oCItem* HasEquippedStolenItem( oCNpc* )                                                      zCall( 0x006C36A0 );
    void Burn( int, float )                                                                      zCall( 0x006C3880 );
    void StopBurn()                                                                              zCall( 0x006C3B80 );
    void Interrupt( int, int )                                                                   zCall( 0x006C3F50 );
    int GetWeaponDamage( oCItem* )                                                               zCall( 0x006C4270 );
    int GetBluntDamage( oCItem* )                                                                zCall( 0x006C42C0 );
    void DropUnconscious( float, oCNpc* )                                                        zCall( 0x006C42F0 );
    void CheckUnconscious()                                                                      zCall( 0x006C4610 );
    zSTRING GetInterruptPrefix()                                                                 zCall( 0x006C4B10 );
    void CompleteHeal()                                                                          zCall( 0x006C4BB0 );
    int IsDead()                                                                                 zCall( 0x006C4BD0 );
    int IsUnconscious()                                                                          zCall( 0x006C4BE0 );
    void StartFadeAway()                                                                         zCall( 0x006C5120 );
    int IsFadingAway()                                                                           zCall( 0x006C5210 );
    int FadeAway()                                                                               zCall( 0x006C5220 );
    int BeamTo( zSTRING const& )                                                                 zCall( 0x006C52B0 );
    void DropInventory()                                                                         zCall( 0x006C55A0 );
    int HasInHand( int )                                                                         zCall( 0x006C55B0 );
    int HasInHand( zCVob* )                                                                      zCall( 0x006C5720 );
    void RemoveFromHand()                                                                        zCall( 0x006C5860 );
    void DropAllInHand()                                                                         zCall( 0x006C5A50 );
    oCItem* GetWeapon()                                                                          zCall( 0x006C5C30 );
    oCItem* GetEquippedMeleeWeapon()                                                             zCall( 0x006C5E00 );
    oCItem* GetEquippedRangedWeapon()                                                            zCall( 0x006C5F30 );
    oCItem* GetEquippedArmor()                                                                   zCall( 0x006C6060 );
    int IsSameHeight( zCVob* )                                                                   zCall( 0x006C6100 );
    void TurnToEnemy()                                                                           zCall( 0x006C6200 );
    int ShieldEquipped()                                                                         zCall( 0x006C62D0 );
    int GetWeaponDamage()                                                                        zCall( 0x006C63A0 );
    void SetMovLock( int )                                                                       zCall( 0x006C6570 );
    int IsMovLock()                                                                              zCall( 0x006C65A0 );
    void SetHead()                                                                               zCall( 0x006C65B0 );
    void SetAdditionalVisuals( zSTRING&, int, int, zSTRING&, int, int, int )                     zCall( 0x006C6850 );
    void InitModel()                                                                             zCall( 0x006C69B0 );
    zCModel* GetModel()                                                                          zCall( 0x006C6CD0 );
    zSTRING GetVisualBody()                                                                      zCall( 0x006C6D80 );
    zSTRING GetVisualHead()                                                                      zCall( 0x006C6DD0 );
    int StartFaceAni( zSTRING const&, float, float )                                             zCall( 0x006C6E20 );
    int StartStdFaceAni( int )                                                                   zCall( 0x006C6F20 );
    int StopFaceAni( zSTRING const& )                                                            zCall( 0x006C7130 );
    int GetWeaponMode()                                                                          zCall( 0x006C7230 );
    void SetWeaponMode2_novt( zSTRING const& )                                                   zCall( 0x006C7250 );
    int GetNextWeaponMode( int, int, int )                                                       zCall( 0x006C81B0 );
    void Equip( oCItem* )                                                                        zCall( 0x006C8440 );
    void EquipWeapon( oCItem* )                                                                  zCall( 0x006C8770 );
    void EquipFarWeapon( oCItem* )                                                               zCall( 0x006C8A80 );
    void EquipArmor( oCItem* )                                                                   zCall( 0x006C8C20 );
    void SetToFightMode( oCItem*, int )                                                          zCall( 0x006C8F20 );
    void SetToFistMode()                                                                         zCall( 0x006C9140 );
    void Activate( int, int )                                                                    zCall( 0x006C9350 );
    oCVob* GetRightHand()                                                                        zCall( 0x006C9360 );
    oCVob* GetLeftHand()                                                                         zCall( 0x006C9400 );
    void DropVob( oCVob*, zVEC3& )                                                               zCall( 0x006C94A0 );
    void SetCarryVob( zCVob* )                                                                   zCall( 0x006C9640 );
    zCVob* GetCarryVob()                                                                         zCall( 0x006C9940 );
    void SetLeftHand( oCVob* )                                                                   zCall( 0x006C9950 );
    void SetRightHand( oCVob* )                                                                  zCall( 0x006C9A50 );
    int HasTorch()                                                                               zCall( 0x006C9B50 );
    void ExchangeTorch()                                                                         zCall( 0x006C9CB0 );
    void SetTorchAni( int, int )                                                                 zCall( 0x006C9CC0 );
    void CheckSetTorchAni()                                                                      zCall( 0x006C9FF0 );
    void CheckPutbackTorch()                                                                     zCall( 0x006CA280 );
    int UseItem( oCItem* )                                                                       zCall( 0x006CA590 );
    float GetThrowSpeed( float, float )                                                          zCall( 0x006CABB0 );
    int HasArrowInHand()                                                                         zCall( 0x006CABE0 );
    int HasArrowInInv()                                                                          zCall( 0x006CAD50 );
    int HasBoltInInv()                                                                           zCall( 0x006CAE50 );
    int HasBoltInHand()                                                                          zCall( 0x006CAF50 );
    int IsMunitionAvailable( oCItem* )                                                           zCall( 0x006CB0C0 );
    void GetTalentInfo( int, zSTRING&, zSTRING&, zSTRING& )                                      zCall( 0x006CB260 );
    void GetSpellInfo( int, zSTRING&, zSTRING& )                                                 zCall( 0x006CB4D0 );
    void GetAttribInfo( int, zSTRING&, zSTRING& )                                                zCall( 0x006CB6E0 );
    oCVisualFX* GetConnectedEffect()                                                             zCall( 0x006CB890 );
    void AssessStartEffect( oCVisualFX*, oCNpc* )                                                zCall( 0x006CB8A0 );
    void AssessStopEffect( oCVisualFX*, oCNpc* )                                                 zCall( 0x006CB940 );
    void CreateSpell( int )                                                                      zCall( 0x006CB9A0 );
    void LearnSpell( int )                                                                       zCall( 0x006CBA10 );
    int HasSpell( int )                                                                          zCall( 0x006CBA60 );
    void DestroySpell( int )                                                                     zCall( 0x006CBA90 );
    void SetActiveSpellInfo( int )                                                               zCall( 0x006CBAE0 );
    int GetActiveSpellNr()                                                                       zCall( 0x006CBB30 );
    int GetActiveSpellCategory()                                                                 zCall( 0x006CBB70 );
    int GetActiveSpellLevel()                                                                    zCall( 0x006CBBB0 );
    void InsertActiveSpell( oCSpell* )                                                           zCall( 0x006CBBF0 );
    void RemoveActiveSpell( oCSpell* )                                                           zCall( 0x006CBC10 );
    void RemoveActiveSpell( int )                                                                zCall( 0x006CBC90 );
    int DoActiveSpells()                                                                         zCall( 0x006CBD40 );
    void KillActiveSpells()                                                                      zCall( 0x006CBE20 );
    oCSpell* IsSpellActive( int )                                                                zCall( 0x006CBEB0 );
    int HasMagic()                                                                               zCall( 0x006CBEF0 );
    int GetNumberOfSpells()                                                                      zCall( 0x006CBF20 );
    void CopyTransformSpellInvariantValuesTo( oCNpc* )                                           zCall( 0x006CBF40 );
    void OpenScreen_Help()                                                                       zCall( 0x006CBF80 );
    void OpenScreen_Log()                                                                        zCall( 0x006CBF90 );
    void OpenScreen_Map()                                                                        zCall( 0x006CC2B0 );
    void OpenScreen_Status()                                                                     zCall( 0x006CC370 );
    int IsVoiceActive()                                                                          zCall( 0x006CCCC0 );
    void StopAllVoices()                                                                         zCall( 0x006CCCD0 );
    int UpdateNextVoice()                                                                        zCall( 0x006CCD40 );
    void DoSpellBook()                                                                           zCall( 0x006CD320 );
    void OpenSpellBook( int )                                                                    zCall( 0x006CD330 );
    void CloseSpellBook( int )                                                                   zCall( 0x006CD380 );
    oCMag_Book* GetSpellBook()                                                                   zCall( 0x006CD3A0 );
    int HasSenseHear()                                                                           zCall( 0x006CD690 );
    int HasSenseSee()                                                                            zCall( 0x006CD6A0 );
    int HasSenseSmell()                                                                          zCall( 0x006CD6B0 );
    void SetSenses( int )                                                                        zCall( 0x006CD6C0 );
    void PrintStateCallDebug( zSTRING const&, int, int )                                         zCall( 0x006CD6D0 );
    int GetOldScriptState()                                                                      zCall( 0x006CD980 );
    int GetAIState()                                                                             zCall( 0x006CD990 );
    int GetAIStateTime()                                                                         zCall( 0x006CD9A0 );
    int IsAIState( int )                                                                         zCall( 0x006CD9B0 );
    void ShowState( int, int )                                                                   zCall( 0x006CD9D0 );
    int IsNear( oCNpc* )                                                                         zCall( 0x006CE6A0 );
    oCItem* DetectItem( int, int )                                                               zCall( 0x006CE760 );
    oCNpc* DetectPlayer()                                                                        zCall( 0x006CE820 );
    oCMobInter* FindMobInter( zSTRING const& )                                                   zCall( 0x006CE890 );
    zCVobSpot* FindSpot( zSTRING const&, int, float )                                            zCall( 0x006CEB50 );
    void ForceVobDetection( zCVob* )                                                             zCall( 0x006CEEF0 );
    int HasVobDetected( zCVob* )                                                                 zCall( 0x006CF060 );
    int CheckForOwner( zCVob* )                                                                  zCall( 0x006CF0A0 );
    void AI_ForceDetection()                                                                     zCall( 0x006CF200 );
    int CanSense( zCVob* )                                                                       zCall( 0x006CF210 );
    void DetectWitnesses( oCNpc*, int )                                                          zCall( 0x006CF2B0 );
    oCNpc* FindNpc( int, int, int, int )                                                         zCall( 0x006CF590 );
    oCNpc* FindNpcEx( int, int, int, int, int, int )                                             zCall( 0x006CF690 );
    int GetComrades()                                                                            zCall( 0x006CF880 );
    int AreWeStronger( oCNpc* )                                                                  zCall( 0x006CFA70 );
    oCNpc* IsEnemyBehindFriend( oCNpc* )                                                         zCall( 0x006CFDD0 );
    int InMobInteraction( zSTRING const&, int )                                                  zCall( 0x006CFFF0 );
    int FreeLineOfSight( zCVob* )                                                                zCall( 0x006D0100 );
    int FreeLineOfSight( zVEC3&, zCVob* )                                                        zCall( 0x006D0170 );
    int CanSee( zCVob*, int )                                                                    zCall( 0x006D0360 );
    void SetSwimDiveTime( float, float )                                                         zCall( 0x006D0710 );
    void GetSwimDiveTime( float&, float&, float& )                                               zCall( 0x006D0740 );
    void Regenerate()                                                                            zCall( 0x006D0770 );
    void RefreshNpc()                                                                            zCall( 0x006D08B0 );
    void RenderNpc( zCView* )                                                                    zCall( 0x006D0B10 );
    void SetKnowsPlayer( int )                                                                   zCall( 0x006D0DA0 );
    int KnowsPlayer( oCNpc* )                                                                    zCall( 0x006D0DB0 );
    int KnowsPlayer( int )                                                                       zCall( 0x006D0DC0 );
    int HasMunitionInHand( oCItem* )                                                             zCall( 0x006D2A20 );
    void Pack( zCBuffer& )                                                                       zCall( 0x006D4090 );
    void Unpack( zCBuffer& )                                                                     zCall( 0x006D4120 );
    int IsInFightMode_S( int )                                                                   zCall( 0x006D41C0 );
    int IsAiming_S( oCNpc* )                                                                     zCall( 0x006D4240 );
    void ClearEM()                                                                               zCall( 0x006D4E70 );
    void PreSaveGameProcessing()                                                                 zCall( 0x006D6F60 );
    void PostSaveGameProcessing()                                                                zCall( 0x006D72A0 );
    oCItem* IdentifyMushroom( oCItem* )                                                          zCall( 0x006D7530 );
    void IdentifyAllMushrooms()                                                                  zCall( 0x006D7710 );
    int HasMissionItem()                                                                         zCall( 0x006D7850 );
    oCItem* IsInInv( oCItem*, int )                                                              zCall( 0x006D78B0 );
    oCItem* GetFromInv( int, int )                                                               zCall( 0x006D78D0 );
    oCItem* IsInInv( int, int )                                                                  zCall( 0x006D7930 );
    oCItem* IsInInv( zSTRING const&, int )                                                       zCall( 0x006D7950 );
    int CanCarry( oCItem* )                                                                      zCall( 0x006D7970 );
    oCItem* PutInInv( oCItem* )                                                                  zCall( 0x006D7AC0 );
    oCItem* PutInInv( int, int )                                                                 zCall( 0x006D7C60 );
    oCItem* PutInInv( zSTRING const&, int )                                                      zCall( 0x006D7D10 );
    oCItem* RemoveFromInv( oCItem*, int )                                                        zCall( 0x006D7D40 );
    oCItem* RemoveFromInv( int, int )                                                            zCall( 0x006D7D90 );
    oCItem* RemoveFromInv( zSTRING const&, int )                                                 zCall( 0x006D7DE0 );
    int IsSlotFree( zSTRING const& )                                                             zCall( 0x006D7E30 );
    int IsSlotFree( TNpcSlot* )                                                                  zCall( 0x006D7EF0 );
    void SetToSlotPosition( zCVob*, zSTRING const& )                                             zCall( 0x006D7F10 );
    void CreateInvSlot( zSTRING const& )                                                         zCall( 0x006D7F90 );
    void DeleteInvSlot( zSTRING const& )                                                         zCall( 0x006D8190 );
    TNpcSlot* GetInvSlot( zSTRING const& )                                                       zCall( 0x006D8290 );
    TNpcSlot* GetInvSlot( zCVob* )                                                               zCall( 0x006D8340 );
    int IsInvSlotAvailable( zSTRING const& )                                                     zCall( 0x006D8380 );
    void PutInSlot( zSTRING const&, oCVob*, int )                                                zCall( 0x006D8440 );
    void PutInSlot( TNpcSlot*, oCVob*, int )                                                     zCall( 0x006D8500 );
    void RemoveFromAllSlots( int )                                                               zCall( 0x006D89A0 );
    oCVob* RemoveFromSlot( zSTRING const&, int )                                                 zCall( 0x006D89E0 );
    oCVob* RemoveFromSlot( TNpcSlot*, int )                                                      zCall( 0x006D8AA0 );
    oCVob* DropFromSlot( zSTRING const& )                                                        zCall( 0x006D8D00 );
    oCVob* DropFromSlot( TNpcSlot* )                                                             zCall( 0x006D8DD0 );
    void UpdateSlots()                                                                           zCall( 0x006D90E0 );
    void SetInteractMob( oCMobInter* )                                                           zCall( 0x006D91A0 );
    oCMobInter* GetInteractMob()                                                                 zCall( 0x006D9230 );
    void SetInteractItem( oCItem* )                                                              zCall( 0x006D9250 );
    int EV_DrawWeapon( oCMsgWeapon* )                                                            zCall( 0x006DB1B0 );
    int EV_DrawWeapon1( oCMsgWeapon* )                                                           zCall( 0x006DB860 );
    int EV_DrawWeapon2( oCMsgWeapon* )                                                           zCall( 0x006DBB30 );
    int EV_RemoveWeapon( oCMsgWeapon* )                                                          zCall( 0x006DC1B0 );
    int EV_RemoveWeapon1( oCMsgWeapon* )                                                         zCall( 0x006DC650 );
    int EV_RemoveWeapon2( oCMsgWeapon* )                                                         zCall( 0x006DC7E0 );
    int EV_ChooseWeapon( oCMsgWeapon* )                                                          zCall( 0x006DCB30 );
    int EV_ForceRemoveWeapon( oCMsgWeapon* )                                                     zCall( 0x006DCE20 );
    int EV_EquipBestWeapon( oCMsgWeapon* )                                                       zCall( 0x006DD0F0 );
    void EquipBestWeapon( int )                                                                  zCall( 0x006DD110 );
    int EV_EquipBestArmor( oCMsgWeapon* )                                                        zCall( 0x006DD230 );
    void EquipBestArmor()                                                                        zCall( 0x006DD2C0 );
    int EV_UnequipWeapons( oCMsgWeapon* )                                                        zCall( 0x006DD340 );
    int EV_UnequipArmor( oCMsgWeapon* )                                                          zCall( 0x006DD520 );
    int EV_EquipArmor( oCMsgWeapon* )                                                            zCall( 0x006DD5D0 );
    int EV_AttackForward( oCMsgAttack* )                                                         zCall( 0x006DD630 );
    int EV_AttackLeft( oCMsgAttack* )                                                            zCall( 0x006DDD70 );
    int EV_AttackRight( oCMsgAttack* )                                                           zCall( 0x006DE570 );
    int EV_AttackRun( oCMsgAttack* )                                                             zCall( 0x006DED30 );
    int EV_AttackFinish( oCMsgAttack* )                                                          zCall( 0x006DEFD0 );
    int EV_AttackAssassin( oCMsgAttack* )                                                        zCall( 0x006DF860 );
    int EV_Parade( oCMsgAttack* )                                                                zCall( 0x006DFFC0 );
    int InitAim( oCMsgAttack*, oCNpc**, int*, int*, int )                                        zCall( 0x006E05E0 );
    int TransitionAim( int, int )                                                                zCall( 0x006E0790 );
    int InterpolateAim( oCNpc* )                                                                 zCall( 0x006E0930 );
    int FinalizeAim( int, int )                                                                  zCall( 0x006E0A80 );
    int EV_StopAim( oCMsgAttack* )                                                               zCall( 0x006E0BC0 );
    int EV_AimAt( oCMsgAttack* )                                                                 zCall( 0x006E0BE0 );
    int EV_ShootAt( oCMsgAttack* )                                                               zCall( 0x006E0CB0 );
    int EV_Defend( oCMsgAttack* )                                                                zCall( 0x006E0E60 );
    int EV_Drink( oCMsgUseItem* )                                                                zCall( 0x006E0E90 );
    int EV_TakeVob( oCMsgManipulate* )                                                           zCall( 0x006E11D0 );
    int EV_DropVob( oCMsgManipulate* )                                                           zCall( 0x006E15B0 );
    int EV_ThrowVob( oCMsgManipulate* )                                                          zCall( 0x006E1860 );
    int EV_Exchange( oCMsgManipulate* )                                                          zCall( 0x006E1B00 );
    int EV_DropMob( oCMsgManipulate* )                                                           zCall( 0x006E1E20 );
    int EV_TakeMob( oCMsgManipulate* )                                                           zCall( 0x006E1F10 );
    int EV_UseMob( oCMsgManipulate* )                                                            zCall( 0x006E1FD0 );
    int EV_UseMobWithItem( oCMsgManipulate* )                                                    zCall( 0x006E2220 );
    int EV_InsertInteractItem( oCMsgManipulate* )                                                zCall( 0x006E2280 );
    int EV_ExchangeInteractItem( oCMsgManipulate* )                                              zCall( 0x006E24A0 );
    int EV_RemoveInteractItem( oCMsgManipulate* )                                                zCall( 0x006E2630 );
    int EV_CreateInteractItem( oCMsgManipulate* )                                                zCall( 0x006E2640 );
    int EV_DestroyInteractItem( oCMsgManipulate* )                                               zCall( 0x006E27D0 );
    int EV_PutInSlot( oCMsgManipulate* )                                                         zCall( 0x006E29D0 );
    int EV_RemoveFromSlot( oCMsgManipulate* )                                                    zCall( 0x006E2C90 );
    zCModelAni* InteractItemGetAni( zSTRING const&, int, int )                                   zCall( 0x006E2E90 );
    int EV_PlaceInteractItem( oCMsgManipulate* )                                                 zCall( 0x006E3170 );
    int GetInteractItemMaxState( zSTRING const& )                                                zCall( 0x006E32B0 );
    int InteractItemIsInState( zSTRING const&, int )                                             zCall( 0x006E34C0 );
    int EV_EquipItem( oCMsgManipulate* )                                                         zCall( 0x006E36D0 );
    int EV_UseItem( oCMsgManipulate* )                                                           zCall( 0x006E3770 );
    int EV_UseItemToState( oCMsgManipulate* )                                                    zCall( 0x006E3AF0 );
    void CallScript( zSTRING const& )                                                            zCall( 0x006E44F0 );
    void CallScript( int )                                                                       zCall( 0x006E4520 );
    int EV_CallScript( oCMsgManipulate* )                                                        zCall( 0x006E4540 );
    int EV_Unconscious( oCMsgState* )                                                            zCall( 0x006E46E0 );
    int EV_DoState( oCMsgState* )                                                                zCall( 0x006E4980 );
    int EV_Wait( oCMsgState* )                                                                   zCall( 0x006E4BD0 );
    int ApplyTimedOverlayMds( zSTRING const&, float )                                            zCall( 0x006E4C40 );
    int EV_OutputSVM_Overlay( oCMsgConversation* )                                               zCall( 0x006E4E20 );
    int EV_PrintScreen( oCMsgConversation* )                                                     zCall( 0x006E5610 );
    int EV_OutputSVM( oCMsgConversation* )                                                       zCall( 0x006E5750 );
    int EV_Output( oCMsgConversation* )                                                          zCall( 0x006E5CA0 );
    int EV_PlayAni( oCMsgConversation* )                                                         zCall( 0x006E60C0 );
    int EV_PlayAniFace( oCMsgConversation* )                                                     zCall( 0x006E6380 );
    int StartDialogAni()                                                                         zCall( 0x006E6470 );
    int EV_PlayAniSound( oCMsgConversation* )                                                    zCall( 0x006E66D0 );
    int ActivateDialogCam( float )                                                               zCall( 0x006E67C0 );
    int DeactivateDialogCam()                                                                    zCall( 0x006E6A10 );
    int EV_PlaySound( oCMsgConversation* )                                                       zCall( 0x006E6BB0 );
    int EV_SndPlay( oCMsgConversation* )                                                         zCall( 0x006E77E0 );
    int EV_LookAt( oCMsgConversation* )                                                          zCall( 0x006E7870 );
    int EV_StopLookAt( oCMsgConversation* )                                                      zCall( 0x006E7B70 );
    int EV_PointAt( oCMsgConversation* )                                                         zCall( 0x006E7D40 );
    int EV_StopPointAt( oCMsgConversation* )                                                     zCall( 0x006E7EF0 );
    int EV_QuickLook( oCMsgConversation* )                                                       zCall( 0x006E7F40 );
    int EV_Cutscene( oCMsgConversation* )                                                        zCall( 0x006E81E0 );
    int EV_WaitTillEnd( oCMsgConversation* )                                                     zCall( 0x006E83E0 );
    int EV_StopProcessInfos( oCMsgConversation* )                                                zCall( 0x006E8480 );
    int EV_ProcessInfos( oCMsgConversation* )                                                    zCall( 0x006E84A0 );
    int AssessPlayer_S( oCNpc* )                                                                 zCall( 0x006E8560 );
    int AssessEnemy_S( oCNpc* )                                                                  zCall( 0x006E8780 );
    int AssessFighter_S( oCNpc* )                                                                zCall( 0x006E89A0 );
    int AssessBody_S( oCNpc* )                                                                   zCall( 0x006E8BC0 );
    int AssessItem_S( oCItem* )                                                                  zCall( 0x006E8DE0 );
    void SetNpcsToState( int, int )                                                              zCall( 0x006E9000 );
    void StopCutscenes()                                                                         zCall( 0x006E90D0 );
    void CreatePassivePerception( int, zCVob*, zCVob* )                                          zCall( 0x006E9130 );
    int AssessMurder_S( oCNpc* )                                                                 zCall( 0x006E9FD0 );
    int AssessThreat_S( oCNpc* )                                                                 zCall( 0x006E9FF0 );
    int AssessDefeat_S( oCNpc* )                                                                 zCall( 0x006EA1A0 );
    int AssessDamage_S( oCNpc*, int )                                                            zCall( 0x006EA1C0 );
    int AssessOthersDamage_S( oCNpc*, oCNpc*, int )                                              zCall( 0x006EA370 );
    int AssessRemoveWeapon_S( oCNpc* )                                                           zCall( 0x006EA390 );
    int ObserveIntruder_S()                                                                      zCall( 0x006EA3B0 );
    int AssessWarn_S( oCNpc* )                                                                   zCall( 0x006EA440 );
    int CatchThief_S( oCNpc* )                                                                   zCall( 0x006EA460 );
    int AssessTheft_S( oCNpc* )                                                                  zCall( 0x006EA610 );
    int AssessCall_S( oCNpc* )                                                                   zCall( 0x006EA630 );
    int AssessTalk_S( oCNpc* )                                                                   zCall( 0x006EA7E0 );
    int AssessGivenItem_S( oCNpc*, oCItem* )                                                     zCall( 0x006EA990 );
    int AssessMagic_S( oCNpc*, int )                                                             zCall( 0x006EABB0 );
    int AssessStopMagic_S( oCNpc*, int )                                                         zCall( 0x006EAEF0 );
    int AssessCaster_S( oCSpell* )                                                               zCall( 0x006EB1F0 );
    int AssessFakeGuild_S()                                                                      zCall( 0x006EB210 );
    int MoveMob_S( oCMOB* )                                                                      zCall( 0x006EB240 );
    int AssessUseMob_S( oCMobInter* )                                                            zCall( 0x006EB2F0 );
    int MoveNpc_S( oCNpc* )                                                                      zCall( 0x006EB340 );
    int AssessEnterRoom_S()                                                                      zCall( 0x006EB4F0 );
    float GetDistToSound()                                                                       zCall( 0x006EB500 );
    zCVob* GetSoundSource()                                                                      zCall( 0x006EB5D0 );
    void SetSoundSource( int, zCVob*, zVEC3& )                                                   zCall( 0x006EB5E0 );
    void ClearPerceptionLists()                                                                  zCall( 0x006EB660 );
    void CreateVobList( zCArray<zCVob*>&, float )                                                zCall( 0x006EB750 );
    void ClearVobList()                                                                          zCall( 0x006EB830 );
    void InsertInVobList( zCVob* )                                                               zCall( 0x006EB8B0 );
    void RemoveFromVobList( zCVob* )                                                             zCall( 0x006EBA10 );
    void CreateVobList( float )                                                                  zCall( 0x006EBAA0 );
    void SetPerceptionTime( float )                                                              zCall( 0x006EBC90 );
    void PerceiveAll()                                                                           zCall( 0x006EBCD0 );
    void PerceptionCheck()                                                                       zCall( 0x006EBE30 );
    int PercFilterNpc( oCNpc* )                                                                  zCall( 0x006EC2E0 );
    int PercFilterItem( oCItem* )                                                                zCall( 0x006EC2F0 );
    void ClearPerception()                                                                       zCall( 0x006EC310 );
    void EnablePerception( int, int )                                                            zCall( 0x006EC330 );
    void DisablePerception( int )                                                                zCall( 0x006EC4A0 );
    int HasPerception( int )                                                                     zCall( 0x006EC500 );
    int GetPerceptionFunc( int )                                                                 zCall( 0x006EC540 );
    void SetBodyState( int )                                                                     zCall( 0x006ECAB0 );
    int GetBodyState()                                                                           zCall( 0x006ECC00 );
    int GetFullBodyState()                                                                       zCall( 0x006ECC10 );
    zSTRING GetBodyStateName()                                                                   zCall( 0x006ECC30 );
    int HasBodyStateModifier( int )                                                              zCall( 0x006ECD10 );
    void SetBodyStateModifier( int )                                                             zCall( 0x006ECD30 );
    void ClrBodyStateModifier( int )                                                             zCall( 0x006ECD60 );
    zSTRING GetBodyStateModifierNames()                                                          zCall( 0x006ECD90 );
    int ModifyBodyState( int, int )                                                              zCall( 0x006ED090 );
    int IsBodyStateInterruptable()                                                               zCall( 0x006ED0E0 );
    int HasBodyStateFreeHands()                                                                  zCall( 0x006ED110 );
    int IsInGlobalCutscene()                                                                     zCall( 0x006ED140 );
    void MakeSpellBook()                                                                         zCall( 0x006ED180 );
    void DestroySpellBook()                                                                      zCall( 0x006ED220 );
    float GetDamageMultiplier()                                                                  zCall( 0x006ED460 );
    void SetDamageMultiplier( float )                                                            zCall( 0x006ED470 );
    void SetShowNews( int )                                                                      zCall( 0x006ED5F0 );
    void UseStandAI()                                                                            zCall( 0x006ED640 );
    int IsVictimAwareOfTheft()                                                                   zCall( 0x006EFC20 );
    void CheckSpecialSituations()                                                                zCall( 0x006EFCC0 );
    void StopTheft( oCNpc*, int )                                                                zCall( 0x006EFEB0 );
    void OpenInventory()                                                                         zCall( 0x006EFFA0 );
    void CloseInventory()                                                                        zCall( 0x006F0200 );
    int OpenSteal()                                                                              zCall( 0x006F0260 );
    void CloseSteal()                                                                            zCall( 0x006F0860 );
    void OpenDeadNpc()                                                                           zCall( 0x006F0880 );
    void CloseDeadNpc()                                                                          zCall( 0x006F0A10 );
    void InitDamage()                                                                            zCall( 0x0076DE20 );
    int EV_DamageOnce( oCMsgDamage* )                                                            zCall( 0x0076DFF0 );
    int EV_DamagePerFrame( oCMsgDamage* )                                                        zCall( 0x0076E380 );
    void OnDamage_Hit( oSDamageDescriptor& )                                                     zCall( 0x007700A0 );
    void OnDamage_Condition( oSDamageDescriptor& )                                               zCall( 0x00777150 );
    void OnDamage_Script( oSDamageDescriptor& )                                                  zCall( 0x007784F0 );
    void OnDamage_Effects( oSDamageDescriptor& )                                                 zCall( 0x00778E50 );
    void OnDamage_Effects_Start( oSDamageDescriptor& )                                           zCall( 0x007791F0 );
    void OnDamage_Effects_End( oSDamageDescriptor& )                                             zCall( 0x0077F630 );
    void OnDamage_Anim( oSDamageDescriptor& )                                                    zCall( 0x00781E70 );
    void OnDamage_Sound( oSDamageDescriptor& )                                                   zCall( 0x007874D0 );
    void OnDamage_Events( oSDamageDescriptor& )                                                  zCall( 0x00787810 );
    void OnDamage_State( oSDamageDescriptor& )                                                   zCall( 0x00788440 );
    int HasFlag( unsigned long, unsigned long )                                                  zCall( 0x00788990 );
    int IsNpcBetweenMeAndTarget( zCVob* )                                                        zCall( 0x007892F0 );
    int IsInDoubleFightRange( zCVob*, float& )                                                   zCall( 0x00789510 );
    int IsInFightRange( zCVob*, float& )                                                         zCall( 0x00789770 );
    int GetFightRange()                                                                          zCall( 0x007899D0 );
    void SetFightRangeBase( int )                                                                zCall( 0x00789A00 );
    int GetFightRangeBase()                                                                      zCall( 0x00789A10 );
    int GetFightRangeDynamic()                                                                   zCall( 0x00789A20 );
    int GetFightRangeFist()                                                                      zCall( 0x00789A40 );
    void SetFightRangeFist( int )                                                                zCall( 0x00789A50 );
    int GetFightActionFromTable( int )                                                           zCall( 0x00789A60 );
    int GetCurrentFightMove()                                                                    zCall( 0x00789AA0 );
    int FindNextFightAction()                                                                    zCall( 0x00789E40 );
    int ThinkNextFightAction()                                                                   zCall( 0x0078A470 );
    int FightAttackMelee( int )                                                                  zCall( 0x0078AE80 );
    int FightAttackBow()                                                                         zCall( 0x0078B8C0 );
    int EV_AttackBow( oCMsgAttack* )                                                             zCall( 0x0078B9B0 );
    int FightAttackMagic()                                                                       zCall( 0x0078BC80 );
    int EV_AttackMagic( oCMsgAttack* )                                                           zCall( 0x0078BD80 );
    int EV_CastSpell( oCMsgMagic* )                                                              zCall( 0x0078BD90 );
    void CheckRunningFightAnis()                                                                 zCall( 0x0078BEA0 );
    void GotoFightPosition()                                                                     zCall( 0x0078C070 );
    void Fighting()                                                                              zCall( 0x0078C180 );
    oCItem* GetSpellItem( int )                                                                  zCall( 0x0078C380 );
    int ReadySpell( int, int )                                                                   zCall( 0x0078C3E0 );
    int UnreadySpell()                                                                           zCall( 0x0078C590 );
    int HasRangedWeaponAndAmmo()                                                                 zCall( 0x0078C640 );
    int CanDrawWeapon()                                                                          zCall( 0x0078C6F0 );
    int CanDive()                                                                                zCall( 0x0078CB00 );
    int CanSwim()                                                                                zCall( 0x0078CB30 );
    float GetClimbRange()                                                                        zCall( 0x0078CB60 );
    float GetTurnSpeed()                                                                         zCall( 0x0078CB70 );
    float GetJumpRange()                                                                         zCall( 0x0078CB90 );
    int RbtChooseChasmAction( zVEC3 const&, zVEC3 const& )                                       zCall( 0x0078CBA0 );
    int CanGo( float, zVEC3& )                                                                   zCall( 0x0078CD30 );
    float GetAngle( zCVob* )                                                                     zCall( 0x0078D5A0 );
    void GetAngles( zVEC3&, float&, float& )                                                     zCall( 0x0078D6E0 );
    void GetAngles( zCVob*, float&, float& )                                                     zCall( 0x0078DAC0 );
    float GetDistanceToPos2( zVEC3&, int )                                                       zCall( 0x0078DB10 );
    float GetFallDownHeight()                                                                    zCall( 0x0078DBF0 );
    zCVob* GetRbtObstacleVob()                                                                   zCall( 0x0078DC10 );
    zVEC3 GetVecNormalFromBBox( zCVob*, zVEC3& )                                                 zCall( 0x0078DC20 );
    void SetFallDownDamage( int )                                                                zCall( 0x0078E2D0 );
    void SetFallDownHeight( float )                                                              zCall( 0x0078E2E0 );
    void SetRoute( zCRoute* )                                                                    zCall( 0x0078E2F0 );
    void CreateFallDamage( float )                                                               zCall( 0x0078E320 );
    void Fleeing()                                                                               zCall( 0x0078E630 );
    int ThinkNextFleeAction()                                                                    zCall( 0x0078E640 );
    void Follow()                                                                                zCall( 0x0078EA50 );
    void StandUp( int, int )                                                                     zCall( 0x0078F130 );
    float Turn( zVEC3& )                                                                         zCall( 0x0078F700 );
    float Turning( zVEC3& )                                                                      zCall( 0x0078F820 );
    void AI_Flee( oCNpc* )                                                                       zCall( 0x0078F910 );
    void AI_Follow( oCNpc* )                                                                     zCall( 0x0078F920 );
    int EV_AlignToFP( oCMsgMovement* )                                                           zCall( 0x0078F930 );
    int EV_CanSeeNpc( oCMsgMovement* )                                                           zCall( 0x0078FC00 );
    int EV_GoRoute( oCMsgMovement* )                                                             zCall( 0x0078FC50 );
    int EV_Jump( oCMsgMovement* )                                                                zCall( 0x00790530 );
    int EV_RobustTrace( oCMsgMovement* )                                                         zCall( 0x00790590 );
    int EV_StandUp( oCMsgMovement* )                                                             zCall( 0x007905F0 );
    int EV_Strafe( oCMsgMovement* )                                                              zCall( 0x007906D0 );
    int EV_WhirlAround( oCMsgMovement* )                                                         zCall( 0x00790B90 );
    int EV_Dodge( oCMsgMovement* )                                                               zCall( 0x007912B0 );
    int EV_GotoPos( oCMsgMovement* )                                                             zCall( 0x00791510 );
    int EV_GotoVob( oCMsgMovement* )                                                             zCall( 0x007915D0 );
    int EV_GotoFP( oCMsgMovement* )                                                              zCall( 0x00791760 );
    int EV_SetWalkMode( oCMsgMovement* )                                                         zCall( 0x00791A50 );
    int EV_Turn( oCMsgMovement* )                                                                zCall( 0x00791E40 );
    int EV_TurnAway( oCMsgMovement* )                                                            zCall( 0x00791F20 );
    int EV_TurnToPos( oCMsgMovement* )                                                           zCall( 0x00792190 );
    int EV_TurnToVob( oCMsgMovement* )                                                           zCall( 0x00792280 );
    void ForceRotation( float )                                                                  zCall( 0x00792550 );
    int RbtCheckForSolution( zVEC3, zVEC3 )                                                      zCall( 0x00792590 );
    void RbtReset()                                                                              zCall( 0x007926D0 );
    void RbtInit( zVEC3&, zCVob* )                                                               zCall( 0x007927E0 );
    void RbtUpdate( zVEC3&, zCVob* )                                                             zCall( 0x00792800 );
    int RbtMoveToExactPosition()                                                                 zCall( 0x00792A30 );
    int RobustTrace()                                                                            zCall( 0x00792B10 );
    float RbtCalcTurnDirection( zVEC3 const&, float, int )                                       zCall( 0x00792E70 );
    int RbtIsObjectObstacle( zCVob*, zVEC3 const&, zVEC3 const&, zVEC3& )                        zCall( 0x00793200 );
    int RbtGetObstacle( zVEC3 const&, zVEC3 const&, zCVob*&, zVEC3& )                            zCall( 0x007934A0 );
    int RbtGetSmallObstacle( zVEC3 const&, zCVob*&, zVEC3& )                                     zCall( 0x00793660 );
    int RbtAvoidObstacles()                                                                      zCall( 0x007937F0 );
    int RbtIsDirectionValid( zVEC3 const& )                                                      zCall( 0x00793F10 );
    oSDirectionInfo* RbtInsertDirection( zVEC3 )                                                 zCall( 0x00793FA0 );
    int RbtCheckLastDirection( float )                                                           zCall( 0x00794220 );
    int RbtCheckIfTargetVisible()                                                                zCall( 0x00794520 );
    int RbtGotoFollowPosition()                                                                  zCall( 0x007947E0 );
    int CanStrafe( int, int )                                                                    zCall( 0x00794A60 );
    int CanJumpBack( int )                                                                       zCall( 0x00794D30 );
    void SetWalkStopChasm( int )                                                                 zCall( 0x00794F40 );
    int GetWalkStopChasm()                                                                       zCall( 0x00794F80 );
    static zSTRING GetInstanceByID( int )                                                        zCall( 0x006D4430 );
    static int GetIDByInstance( zSTRING const& )                                                 zCall( 0x006D4490 );
    static void CreateSoundPerception( int, zCVob*, zVEC3 const&, zCVob*, int )                  zCall( 0x006E9AF0 );
    static int AssessFightSound_S( zCVob*, zVEC3 const&, zCVob* )                                zCall( 0x006EA3F0 );
    static int AssessQuietSound_S( zCVob*, zVEC3 const& )                                        zCall( 0x006EA420 );
    static void SetPerceptionRange( int, float )                                                 zCall( 0x006EC580 );
    static int IsInPerceptionRange( int, float )                                                 zCall( 0x006EC5A0 );
    static int IsInPerceptionRange( int, zCVob*, zCVob* )                                        zCall( 0x006EC5D0 );
    static void InitStatics()                                                                    zCall( 0x006EC610 );
    static void ReleaseStatics()                                                                 zCall( 0x006ECA40 );
    static void InitBodyStates()                                                                 zCall( 0x006ECA50 );
    static void SetNpcAIDisabled( int )                                                          zCall( 0x006ED480 );
    static void ProcessAITimer()                                                                 zCall( 0x006ED4D0 );
    static int IsScriptStateAIEnabled()                                                          zCall( 0x006ED550 );
    static int IsMessageAIEnabled()                                                              zCall( 0x006ED5A0 );
    static zCObject* _CreateNewInstance()                                                        zCall( 0x006ED8F0 );
    static void EnableDamageDebugOutput( int )                                                   zCall( 0x0076DD40 );
    static void NotifyDamageToSpy( zSTRING& )                                                    zCall( 0x0076DD50 );
    static void InitFightAI()                                                                    zCall( 0x00788E00 );
    static void ExitFightAI()                                                                    zCall( 0x007892A0 );
    virtual zCClassDef* _GetClassDef() const                                                     zCall( 0x006BC510 );
    virtual void Archive( zCArchiver& )                                                          zCall( 0x006D4EE0 );
    virtual void Unarchive( zCArchiver& )                                                        zCall( 0x006D5AD0 );
    virtual ~oCNpc()                                                                             zCall( 0x006BC7F0 );
    virtual void OnTouch( zCVob* )                                                               zCall( 0x006D94C0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                            zCall( 0x006D95F0 );
    virtual zCVob::zTVobCharClass GetCharacterClass()                                            zCall( 0x006D9240 );
    virtual void SetVisual( zCVisual* )                                                          zCall( 0x006BC580 );
    virtual int GetScriptInstance( zSTRING*&, int& )                                             zCall( 0x006D43B0 );
    virtual int SetByScriptInstance( zSTRING const*, int )                                       zCall( 0x006D43E0 );
    virtual int GetCSStateFlags()                                                                zCall( 0x006C1220 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                 zCall( 0x006CC9F0 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                             zCall( 0x006CCB90 );
    virtual void ShowDebugInfo( zCCamera* )                                                      zCall( 0x006ED250 );
    virtual int GetInstance()                                                                    zCall( 0x006BC520 );
    virtual zSTRING GetInstanceName()                                                            zCall( 0x006D4370 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int )     zCall( 0x006CD500 );
    virtual void SetWeaponMode( int )                                                            zCall( 0x006C80C0 );
    virtual void SetWeaponMode2( int )                                                           zCall( 0x006C74A0 );
    virtual void DoDie( oCNpc* )                                                                 zCall( 0x006C4BF0 );
    virtual oCItem* DoInsertMunition( zSTRING const& )                                           zCall( 0x006D2B80 );
    virtual void DoRemoveMunition()                                                              zCall( 0x006D2E80 );
    virtual int DoSetToFightMode( oCItem* )                                                      zCall( 0x006D3DF0 );
    virtual int DoShootArrow( int )                                                              zCall( 0x006D3100 );
    virtual void OnDamage( oSDamageDescriptor& )                                                 zCall( 0x0076FBF0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )                            zCall( 0x007884B0 );
    virtual void ResetPos( zVEC3& )                                                              zCall( 0x0078EA60 );
    virtual void EmergencyResetPos( zVEC3& )                                                     zCall( 0x0078ED20 );
    virtual void InitByScript( int, int )                                                        zCall( 0x006BCFB0 );
    virtual void Disable()                                                                       zCall( 0x006D4510 );
    virtual void Enable( zVEC3& )                                                                zCall( 0x006D4820 );
    virtual void InitHumanAI()                                                                   zCall( 0x006BD610 );
    virtual int IsMoreImportant( zCVob*, zCVob* )                                                zCall( 0x006EB700 );
    virtual int DoDoAniEvents()                                                                  zCall( 0x006D1200 );
    virtual int DoModelSwapMesh( zSTRING const&, zSTRING const& )                                zCall( 0x006D2760 );
    virtual int DoTakeVob( zCVob* )                                                              zCall( 0x006D3430 );
    virtual int DoDropVob( zCVob* )                                                              zCall( 0x006D3830 );
    virtual int DoRemoveFromInventory( oCItem* )                                                 zCall( 0x006D3DA0 );
    virtual int DoPutInInventory( oCItem* )                                                      zCall( 0x006D3D80 );
    virtual int DoThrowVob( zCVob*, float )                                                      zCall( 0x006D3B30 );
    virtual int DoExchangeTorch()                                                                zCall( 0x006D3E10 );
    virtual void GetSoundMaterial_MA( zCSoundManager::zTSndManMedium&, oTSndMaterial&, zSTRING ) zCall( 0x006CD3B0 );
    virtual void GetSoundMaterial_MH_HM( zCSoundManager::zTSndManMedium&, oTSndMaterial& )       zCall( 0x006CD5D0 );
    virtual int IsAPlayer()                                                                      zCall( 0x006D0D70 );
    virtual int IsSelfPlayer()                                                                   zCall( 0x006D0D80 );
    virtual void SetAsPlayer()                                                                   zCall( 0x006D0EC0 );
    virtual int IsMonster()                                                                      zCall( 0x006D0DD0 );
    virtual int IsHalfMonster()                                                                  zCall( 0x006D0DE0 );
    virtual int IsHuman()                                                                        zCall( 0x006D0E30 );
    virtual int IsGoblin()                                                                       zCall( 0x006D0E50 );
    virtual int IsOrc()                                                                          zCall( 0x006D0E70 );
    virtual int IsSkeleton()                                                                     zCall( 0x006D0EA0 );
    virtual int GetPlayerNumber()                                                                zCall( 0x006D0D90 );
    virtual void ProcessNpc()                                                                    zCall( 0x006CCE00 );
    virtual int AllowDiscardingOfSubtree()                                                       zCall( 0x006D7520 );


    // static properties
    static zSTRING*& FightAIInstances;
    static oEBloodMode& modeBlood;
    static int& isEnabledDamageDebug;
    static oCStealContainer*& stealcontainer;
    static int& s_bEnabledDialogCamStop;
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

    // user API
    #include "oCNpc.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ONPC_H__VER1__