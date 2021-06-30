// Supported with union (c) 2018 Union team

#ifndef __ONPC_H__VER0__
#define __ONPC_H__VER0__

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

namespace Gothic_I_Classic {
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
      NPC_TAL_MAX
    };

    oTEnumNpcTalent m_talent;
    int m_skill;
    int m_value;

    void oCNpcTalent_OnInit()                                           zCall( 0x0068A0C0 );
    oCNpcTalent()                                                       zInit( oCNpcTalent_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00689F40 );
    static void CreateTalentList( zCArray<oCNpcTalent*>* )              zCall( 0x0068A270 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0068A0B0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0068A3E0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0068A420 );
    virtual ~oCNpcTalent()                                              zCall( 0x0068A260 );

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

    void TNpcSlot_OnInit() zCall( 0x0068BE00 );
    void SetVob( oCVob* )  zCall( 0x0068A490 );
    void ClearVob()        zCall( 0x0068A530 );
    TNpcSlot()             zInit( TNpcSlot_OnInit() );
    ~TNpcSlot()            zCall( 0x0068C760 );

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
      void InitBlock( zCParser*, int, int ) zCall( 0x007480A0 );
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
      void oSDamageDescriptor_OnInit( oSDamageDescriptor const& ) zCall( 0x0072F280 );
      ~oSDamageDescriptor()                                       zCall( 0x0048D7C0 );
      void Release()                                              zCall( 0x0072F1A0 );
      void SetVisualFX( oCVisualFX* )                             zCall( 0x0072F1F0 );
      void SetFXHit( oCVisualFX* )                                zCall( 0x0072F240 );
      oSDamageDescriptor( oSDamageDescriptor const& a0 )          zInit( oSDamageDescriptor_OnInit( a0 ));
      oSDamageDescriptor& operator =( oSDamageDescriptor const& ) zCall( 0x0072F340 );
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
      ~oTRobustTrace() zCall( 0x0068BE90 );

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
      void TActiveInfo_OnInit( oCNpc const* ) zCall( 0x0068A580 );
      TActiveInfo( oCNpc const* a0 )          zInit( TActiveInfo_OnInit( a0 ));
      ~TActiveInfo()                          zCall( 0x0068A590 );

      // user API
      #include "oCNpc_TActiveInfo.inl"
    };

    class oCNpcTimedOverlay {
    public:
      zSTRING mdsOverlayName;
      float timer;

      oCNpcTimedOverlay() {}
      zSTRING GetMdsName() zCall( 0x0069B290 );
      ~oCNpcTimedOverlay() zCall( 0x0069B2F0 );
      int Process()        zCall( 0x006B8B10 );

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

    void oCNpc_OnInit()                                                                          zCall( 0x007CFFCD );
    int IsWaitingForAnswer()                                                                     zCall( 0x00632DA0 );
    int SetCurrentAnswer( int, int, oCNpc* )                                                     zCall( 0x00632DF0 );
    int EV_Ask( oCMsgConversation* )                                                             zCall( 0x00633310 );
    int EV_WaitForQuestion( oCMsgConversation* )                                                 zCall( 0x00633390 );
    int CanTalk()                                                                                zCall( 0x00633560 );
    void SetCanTalk( int )                                                                       zCall( 0x00633580 );
    void SetTalkingWith( oCNpc*, int )                                                           zCall( 0x006335A0 );
    oCNpc* GetTalkingWith()                                                                      zCall( 0x006335D0 );
    void StartTalkingWith( oCNpc* )                                                              zCall( 0x006335E0 );
    void StopTalkingWith()                                                                       zCall( 0x00633600 );
    zCEventMessage* GetTalkingWithMessage( oCNpc* )                                              zCall( 0x00633620 );
    int CanBeTalkedTo()                                                                          zCall( 0x006336D0 );
    void StopRunningOU()                                                                         zCall( 0x006338B0 );
    int AssessGivenItem( oCItem*, oCNpc* )                                                       zCall( 0x00633A10 );
    void SetTradeNpc( oCNpc* )                                                                   zCall( 0x00633BB0 );
    oCItem* GetTradeItem()                                                                       zCall( 0x00633BC0 );
    void OpenTradeContainer( oCItem*, oCNpc*, int )                                              zCall( 0x00633BE0 );
    void CloseTradeContainer()                                                                   zCall( 0x00633D90 );
    void OpenTradeOffer( oCNpc* )                                                                zCall( 0x00633E40 );
    int CheckItemReactModule( oCNpc*, oCItem* )                                                  zCall( 0x00633F60 );
    void ExchangeTradeModules( oCNpc* )                                                          zCall( 0x006340E0 );
    zSTRING GetBloodTexture()                                                                    zCall( 0x00648970 );
    TActiveInfo const* GetActiveInfo() const                                                     zCall( 0x0068A5D0 );
    TActiveInfo* GetActiveInfoWritable() const                                                   zCall( 0x0068A5F0 );
    void Shrink()                                                                                zCall( 0x0068A640 );
    void UnShrink()                                                                              zCall( 0x0068A6C0 );
    void AvoidShrink( int )                                                                      zCall( 0x0068ACD0 );
    int ApplyOverlay( zSTRING const& )                                                           zCall( 0x0068AD40 );
    void RemoveOverlay( zSTRING const& )                                                         zCall( 0x0068B040 );
    void SetModelScale( zVEC3 const& )                                                           zCall( 0x0068B230 );
    void SetFatness( float )                                                                     zCall( 0x0068B320 );
    oCNpc()                                                                                      zInit( oCNpc_OnInit() );
    void CleanUp()                                                                               zCall( 0x0068BED0 );
    void DeleteHumanAI()                                                                         zCall( 0x0068CEE0 );
    zSTRING GetGuildName()                                                                       zCall( 0x0068CF20 );
    zSTRING GetName( int )                                                                       zCall( 0x0068D0B0 );
    int IsHostile( oCNpc* )                                                                      zCall( 0x0068D100 );
    int IsFriendly( oCNpc* )                                                                     zCall( 0x0068D190 );
    int IsNeutral( oCNpc* )                                                                      zCall( 0x0068D220 );
    int IsAngry( oCNpc* )                                                                        zCall( 0x0068D2B0 );
    int GetAttitude( oCNpc* )                                                                    zCall( 0x0068D340 );
    int GetPermAttitude( oCNpc* )                                                                zCall( 0x0068D3C0 );
    void SetAttitude( int )                                                                      zCall( 0x0068D410 );
    void SetTmpAttitude( int )                                                                   zCall( 0x0068D460 );
    int GetProtectionByIndex( oEIndexDamage )                                                    zCall( 0x0068D4B0 );
    int GetProtectionByType( oETypeDamage )                                                      zCall( 0x0068D4C0 );
    int GetProtectionByMode( unsigned long )                                                     zCall( 0x0068D560 );
    int GetFullProtection()                                                                      zCall( 0x0068D5F0 );
    void SetProtectionByIndex( oEIndexDamage, int )                                              zCall( 0x0068D610 );
    int GetDamageByIndex( oEIndexDamage )                                                        zCall( 0x0068D630 );
    int GetDamageByType( oETypeDamage )                                                          zCall( 0x0068D640 );
    int GetDamageByMode( unsigned long )                                                         zCall( 0x0068D6E0 );
    int GetFullDamage()                                                                          zCall( 0x0068D770 );
    void SetDamages( int* )                                                                      zCall( 0x0068D790 );
    int GetAttribute( int )                                                                      zCall( 0x0068D7B0 );
    void ChangeAttribute( int, int )                                                             zCall( 0x0068D7C0 );
    void SetAttribute( int, int )                                                                zCall( 0x0068D840 );
    int GetOverlay( zSTRING& )                                                                   zCall( 0x0068D860 );
    void CheckModelOverlays()                                                                    zCall( 0x0068DA20 );
    void SetToMad( float )                                                                       zCall( 0x0068DC40 );
    void HealFromMad()                                                                           zCall( 0x0068DD80 );
    void SetToDrunk( float )                                                                     zCall( 0x0068DEA0 );
    void HealFromDrunk()                                                                         zCall( 0x0068DEB0 );
    void CheckAngryTime()                                                                        zCall( 0x0068DEC0 );
    int CanRecruitSC()                                                                           zCall( 0x0068DF70 );
    int IsDisguised()                                                                            zCall( 0x0068DF80 );
    int GetGuild()                                                                               zCall( 0x0068DFA0 );
    void SetGuild( int )                                                                         zCall( 0x0068DFB0 );
    int GetTrueGuild()                                                                           zCall( 0x0068DFC0 );
    void SetTrueGuild( int )                                                                     zCall( 0x0068DFD0 );
    int GetCamp()                                                                                zCall( 0x0068DFE0 );
    int IsGuildFriendly( int )                                                                   zCall( 0x0068DFF0 );
    int GetGuildAttitude( int )                                                                  zCall( 0x0068E020 );
    void CreateItems( int, int )                                                                 zCall( 0x0068E050 );
    void SetFlag( int )                                                                          zCall( 0x0068E130 );
    int HasFlag( int )                                                                           zCall( 0x0068E150 );
    oCNpcTalent* GetTalent( int, int )                                                           zCall( 0x0068E170 );
    void SetTalentValue( int, int )                                                              zCall( 0x0068E370 );
    int GetTalentValue( int )                                                                    zCall( 0x0068E570 );
    void SetTalentSkill( int, int )                                                              zCall( 0x0068E710 );
    int GetTalentSkill( int )                                                                    zCall( 0x0068ED40 );
    int HasTalent( int, int )                                                                    zCall( 0x0068EEE0 );
    int CanUse( oCItem* )                                                                        zCall( 0x0068EF00 );
    void DisplayCannotUse()                                                                      zCall( 0x0068F200 );
    void CheckAllCanUse()                                                                        zCall( 0x0068F340 );
    oCVob* GetSlotVob( zSTRING const& )                                                          zCall( 0x0068F450 );
    oCItem* GetSlotItem( zSTRING const& )                                                        zCall( 0x0068F4F0 );
    oCItem* GetItem( int, int )                                                                  zCall( 0x0068F590 );
    oCNpc* GetSlotNpc( zSTRING const& )                                                          zCall( 0x0068F5A0 );
    void AddItemEffects( oCItem* )                                                               zCall( 0x0068F640 );
    void RemoveItemEffects( oCItem* )                                                            zCall( 0x0068F7D0 );
    void EquipItem( oCItem* )                                                                    zCall( 0x0068F940 );
    void UnequipItem( oCItem* )                                                                  zCall( 0x0068FBC0 );
    int GetCutsceneDistance()                                                                    zCall( 0x0068FE30 );
    void SetCSEnabled( int )                                                                     zCall( 0x0068FE80 );
    void SetFocusVob( zCVob* )                                                                   zCall( 0x0068FF70 );
    zCVob* GetFocusVob()                                                                         zCall( 0x0068FFC0 );
    void ClearFocusVob()                                                                         zCall( 0x0068FFD0 );
    oCNpc* GetFocusNpc()                                                                         zCall( 0x00690000 );
    oCNpc* GetNearestFightNpcLeft()                                                              zCall( 0x00690030 );
    oCNpc* GetNearestFightNpcRight()                                                             zCall( 0x006901C0 );
    int FocusCheckBBox( zCVob const*, int, int, float, float& )                                  zCall( 0x00690350 );
    int FocusCheck( zCVob const*, int, int, float, float& )                                      zCall( 0x006905D0 );
    void ToggleFocusVob( int )                                                                   zCall( 0x00690910 );
    void CollectFocusVob()                                                                       zCall( 0x00690D70 );
    void GetNearestValidVob( float )                                                             zCall( 0x00691410 );
    void GetNearestVob( float )                                                                  zCall( 0x00691720 );
    oCAniCtrl_Human* GetAnictrl()                                                                zCall( 0x00691A00 );
    void ResetToHumanAI()                                                                        zCall( 0x00691A10 );
    void SetEnemy( oCNpc* )                                                                      zCall( 0x00691A80 );
    oCNpc* GetNextEnemy()                                                                        zCall( 0x00691CC0 );
    int IsConditionValid()                                                                       zCall( 0x00691F40 );
    int IsInFightFocus( zCVob* )                                                                 zCall( 0x00692010 );
    oCItem* HasEquippedStolenItem( oCNpc* )                                                      zCall( 0x00692080 );
    void Burn( int, float )                                                                      zCall( 0x00692250 );
    void StopBurn()                                                                              zCall( 0x00692500 );
    void Interrupt( int )                                                                        zCall( 0x00692830 );
    int GetWeaponDamage( oCItem* )                                                               zCall( 0x00692B90 );
    int GetBluntDamage( oCItem* )                                                                zCall( 0x00692BE0 );
    void DropUnconscious( float, oCNpc* )                                                        zCall( 0x00692C10 );
    void CheckUnconscious()                                                                      zCall( 0x00692F20 );
    zSTRING GetInterruptPrefix()                                                                 zCall( 0x006933C0 );
    void CompleteHeal()                                                                          zCall( 0x00693460 );
    int IsDead()                                                                                 zCall( 0x00693480 );
    int IsUnconscious()                                                                          zCall( 0x00693490 );
    void StartFadeAway()                                                                         zCall( 0x00693970 );
    int IsFadingAway()                                                                           zCall( 0x00693A60 );
    int FadeAway()                                                                               zCall( 0x00693A70 );
    int BeamTo( zSTRING const& )                                                                 zCall( 0x00693B10 );
    void DropInventory()                                                                         zCall( 0x00693DD0 );
    int HasInHand( int )                                                                         zCall( 0x00693DE0 );
    int HasInHand( zCVob* )                                                                      zCall( 0x00693F30 );
    void RemoveFromHand()                                                                        zCall( 0x00694060 );
    void DropAllInHand()                                                                         zCall( 0x00694230 );
    oCItem* GetWeapon()                                                                          zCall( 0x006943F0 );
    oCItem* GetEquippedMeleeWeapon()                                                             zCall( 0x00694580 );
    oCItem* GetEquippedRangedWeapon()                                                            zCall( 0x00694690 );
    oCItem* GetEquippedArmor()                                                                   zCall( 0x006947A0 );
    int IsSameHeight( zCVob* )                                                                   zCall( 0x00694830 );
    void TurnToEnemy()                                                                           zCall( 0x00694920 );
    int ShieldEquipped()                                                                         zCall( 0x006949F0 );
    int GetWeaponDamage()                                                                        zCall( 0x00694AC0 );
    void SetMovLock( int )                                                                       zCall( 0x00694C50 );
    int IsMovLock()                                                                              zCall( 0x00694C80 );
    void SetHead()                                                                               zCall( 0x00694C90 );
    void SetAdditionalVisuals( zSTRING&, int, int, zSTRING&, int, int, int )                     zCall( 0x00694EF0 );
    void InitModel()                                                                             zCall( 0x00695020 );
    zCModel* GetModel()                                                                          zCall( 0x00695300 );
    zSTRING GetVisualBody()                                                                      zCall( 0x006953A0 );
    zSTRING GetVisualHead()                                                                      zCall( 0x006953F0 );
    int StartFaceAni( zSTRING const&, float, float )                                             zCall( 0x00695440 );
    int StartStdFaceAni( int )                                                                   zCall( 0x00695540 );
    int StopFaceAni( zSTRING const& )                                                            zCall( 0x00695730 );
    int GetWeaponMode()                                                                          zCall( 0x00695820 );
    void SetWeaponMode2_novt( zSTRING const& )                                                   zCall( 0x00695840 );
    int GetNextWeaponMode( int, int, int )                                                       zCall( 0x00696640 );
    void Equip( oCItem* )                                                                        zCall( 0x006968F0 );
    void EquipWeapon( oCItem* )                                                                  zCall( 0x00696C20 );
    void EquipFarWeapon( oCItem* )                                                               zCall( 0x00696F00 );
    void EquipArmor( oCItem* )                                                                   zCall( 0x00697080 );
    void SetToFightMode( oCItem*, int )                                                          zCall( 0x00697330 );
    void SetToFistMode()                                                                         zCall( 0x00697540 );
    void Activate( int, int )                                                                    zCall( 0x00697740 );
    oCVob* GetRightHand()                                                                        zCall( 0x00697750 );
    oCVob* GetLeftHand()                                                                         zCall( 0x006977E0 );
    void DropVob( oCVob*, zVEC3& )                                                               zCall( 0x00697870 );
    void SetCarryVob( zCVob* )                                                                   zCall( 0x00697A00 );
    zCVob* GetCarryVob()                                                                         zCall( 0x00697CB0 );
    void SetLeftHand( oCVob* )                                                                   zCall( 0x00697CC0 );
    void SetRightHand( oCVob* )                                                                  zCall( 0x00697DC0 );
    int HasTorch()                                                                               zCall( 0x00697EC0 );
    void ExchangeTorch()                                                                         zCall( 0x00698000 );
    void SetTorchAni( int, int )                                                                 zCall( 0x00698010 );
    void CheckSetTorchAni()                                                                      zCall( 0x006982D0 );
    void CheckPutbackTorch()                                                                     zCall( 0x00698540 );
    int UseItem( oCItem* )                                                                       zCall( 0x00698810 );
    float GetThrowSpeed( float, float )                                                          zCall( 0x00698DE0 );
    int HasArrowInHand()                                                                         zCall( 0x00698E10 );
    int HasArrowInInv()                                                                          zCall( 0x00698F60 );
    int HasBoltInInv()                                                                           zCall( 0x00699050 );
    int HasBoltInHand()                                                                          zCall( 0x00699140 );
    int IsMunitionAvailable( oCItem* )                                                           zCall( 0x00699290 );
    void GetTalentInfo( int, zSTRING&, zSTRING&, zSTRING& )                                      zCall( 0x006993C0 );
    void GetSpellInfo( int, zSTRING&, zSTRING& )                                                 zCall( 0x006995F0 );
    void GetAttribInfo( int, zSTRING&, zSTRING& )                                                zCall( 0x006997E0 );
    oCVisualFX* GetConnectedEffect()                                                             zCall( 0x00699980 );
    void AssessStartEffect( oCVisualFX*, oCNpc* )                                                zCall( 0x00699990 );
    void AssessStopEffect( oCVisualFX*, oCNpc* )                                                 zCall( 0x00699A30 );
    void CreateSpell( int )                                                                      zCall( 0x00699A90 );
    void LearnSpell( int )                                                                       zCall( 0x00699B00 );
    int HasSpell( int )                                                                          zCall( 0x00699B40 );
    void DestroySpell( int )                                                                     zCall( 0x00699B60 );
    void SetActiveSpellInfo( int )                                                               zCall( 0x00699BA0 );
    int GetActiveSpellNr()                                                                       zCall( 0x00699BE0 );
    int GetActiveSpellCategory()                                                                 zCall( 0x00699C20 );
    int GetActiveSpellLevel()                                                                    zCall( 0x00699C60 );
    void InsertActiveSpell( oCSpell* )                                                           zCall( 0x00699CA0 );
    void RemoveActiveSpell( oCSpell* )                                                           zCall( 0x00699CC0 );
    void RemoveActiveSpell( int )                                                                zCall( 0x00699D50 );
    int DoActiveSpells()                                                                         zCall( 0x00699E00 );
    void KillActiveSpells()                                                                      zCall( 0x00699EE0 );
    oCSpell* IsSpellActive( int )                                                                zCall( 0x00699F70 );
    int HasMagic()                                                                               zCall( 0x00699FB0 );
    int GetNumberOfSpells()                                                                      zCall( 0x00699FE0 );
    void CopyTransformSpellInvariantValuesTo( oCNpc* )                                           zCall( 0x0069A000 );
    void OpenScreen_Help()                                                                       zCall( 0x0069A040 );
    void OpenScreen_Log()                                                                        zCall( 0x0069A050 );
    void OpenScreen_Map()                                                                        zCall( 0x0069A340 );
    void OpenScreen_Status()                                                                     zCall( 0x0069A400 );
    int IsVoiceActive()                                                                          zCall( 0x0069AD20 );
    void StopAllVoices()                                                                         zCall( 0x0069AD30 );
    int UpdateNextVoice()                                                                        zCall( 0x0069AD90 );
    void DoSpellBook()                                                                           zCall( 0x0069B340 );
    void OpenSpellBook( int )                                                                    zCall( 0x0069B350 );
    void CloseSpellBook( int )                                                                   zCall( 0x0069B3A0 );
    oCMag_Book* GetSpellBook()                                                                   zCall( 0x0069B3C0 );
    int HasSenseHear()                                                                           zCall( 0x0069B6D0 );
    int HasSenseSee()                                                                            zCall( 0x0069B6E0 );
    int HasSenseSmell()                                                                          zCall( 0x0069B6F0 );
    void SetSenses( int )                                                                        zCall( 0x0069B700 );
    void PrintStateCallDebug( zSTRING const&, int, int )                                         zCall( 0x0069B710 );
    int GetOldScriptState()                                                                      zCall( 0x0069B980 );
    int GetAIState()                                                                             zCall( 0x0069B990 );
    int GetAIStateTime()                                                                         zCall( 0x0069B9A0 );
    int IsAIState( int )                                                                         zCall( 0x0069B9B0 );
    void ShowState( int, int )                                                                   zCall( 0x0069B9C0 );
    int IsNear( oCNpc* )                                                                         zCall( 0x0069C570 );
    oCItem* DetectItem( int, int )                                                               zCall( 0x0069C5F0 );
    oCNpc* DetectPlayer()                                                                        zCall( 0x0069C6B0 );
    oCMobInter* FindMobInter( zSTRING const& )                                                   zCall( 0x0069C720 );
    zCVobSpot* FindSpot( zSTRING const&, int, float )                                            zCall( 0x0069C9A0 );
    void ForceVobDetection( zCVob* )                                                             zCall( 0x0069CD30 );
    int HasVobDetected( zCVob* )                                                                 zCall( 0x0069CE90 );
    int CheckForOwner( zCVob* )                                                                  zCall( 0x0069CED0 );
    void AI_ForceDetection()                                                                     zCall( 0x0069D010 );
    int CanSense( zCVob* )                                                                       zCall( 0x0069D020 );
    void DetectWitnesses( oCNpc*, int )                                                          zCall( 0x0069D0C0 );
    oCNpc* FindNpc( int, int, int, int )                                                         zCall( 0x0069D360 );
    oCNpc* FindNpcEx( int, int, int, int, int, int )                                             zCall( 0x0069D460 );
    int GetComrades()                                                                            zCall( 0x0069D650 );
    int AreWeStronger( oCNpc* )                                                                  zCall( 0x0069D850 );
    oCNpc* IsEnemyBehindFriend( oCNpc* )                                                         zCall( 0x0069DB70 );
    int InMobInteraction( zSTRING const&, int )                                                  zCall( 0x0069DD70 );
    int FreeLineOfSight( zCVob* )                                                                zCall( 0x0069DE50 );
    int FreeLineOfSight( zVEC3&, zCVob* )                                                        zCall( 0x0069DEB0 );
    int CanSee( zCVob*, int )                                                                    zCall( 0x0069E010 );
    void SetSwimDiveTime( float, float )                                                         zCall( 0x0069E370 );
    void GetSwimDiveTime( float&, float&, float& )                                               zCall( 0x0069E3A0 );
    void Regenerate()                                                                            zCall( 0x0069E3D0 );
    void RefreshNpc()                                                                            zCall( 0x0069E510 );
    void RenderNpc( zCView* )                                                                    zCall( 0x0069E770 );
    void SetKnowsPlayer( int )                                                                   zCall( 0x0069EA00 );
    int KnowsPlayer( oCNpc* )                                                                    zCall( 0x0069EA10 );
    int KnowsPlayer( int )                                                                       zCall( 0x0069EA20 );
    int HasMunitionInHand( oCItem* )                                                             zCall( 0x006A03A0 );
    void Pack( zCBuffer& )                                                                       zCall( 0x006A18B0 );
    void Unpack( zCBuffer& )                                                                     zCall( 0x006A1940 );
    int IsInFightMode_S( int )                                                                   zCall( 0x006A19E0 );
    int IsAiming_S( oCNpc* )                                                                     zCall( 0x006A1A60 );
    void ClearEM()                                                                               zCall( 0x006A2610 );
    void PreSaveGameProcessing()                                                                 zCall( 0x006A4500 );
    void PostSaveGameProcessing()                                                                zCall( 0x006A4810 );
    oCItem* IdentifyMushroom( oCItem* )                                                          zCall( 0x006A4A70 );
    void IdentifyAllMushrooms()                                                                  zCall( 0x006A4C60 );
    int HasMissionItem()                                                                         zCall( 0x006A4D90 );
    oCItem* IsInInv( oCItem*, int )                                                              zCall( 0x006A4E00 );
    oCItem* GetFromInv( int, int )                                                               zCall( 0x006A4E20 );
    oCItem* IsInInv( int, int )                                                                  zCall( 0x006A4E80 );
    oCItem* IsInInv( zSTRING const&, int )                                                       zCall( 0x006A4EA0 );
    int CanCarry( oCItem* )                                                                      zCall( 0x006A4EC0 );
    oCItem* PutInInv( oCItem* )                                                                  zCall( 0x006A4FF0 );
    oCItem* PutInInv( int, int )                                                                 zCall( 0x006A5180 );
    oCItem* PutInInv( zSTRING const&, int )                                                      zCall( 0x006A5230 );
    oCItem* RemoveFromInv( oCItem*, int )                                                        zCall( 0x006A5260 );
    oCItem* RemoveFromInv( int, int )                                                            zCall( 0x006A52B0 );
    oCItem* RemoveFromInv( zSTRING const&, int )                                                 zCall( 0x006A5300 );
    int IsSlotFree( zSTRING const& )                                                             zCall( 0x006A5350 );
    int IsSlotFree( TNpcSlot* )                                                                  zCall( 0x006A5420 );
    void SetToSlotPosition( zCVob*, zSTRING const& )                                             zCall( 0x006A5440 );
    void CreateInvSlot( zSTRING const& )                                                         zCall( 0x006A5480 );
    void DeleteInvSlot( zSTRING const& )                                                         zCall( 0x006A5670 );
    TNpcSlot* GetInvSlot( zSTRING const& )                                                       zCall( 0x006A5770 );
    TNpcSlot* GetInvSlot( zCVob* )                                                               zCall( 0x006A5830 );
    int IsInvSlotAvailable( zSTRING const& )                                                     zCall( 0x006A5870 );
    void PutInSlot( zSTRING const&, oCVob*, int )                                                zCall( 0x006A5940 );
    void PutInSlot( TNpcSlot*, oCVob*, int )                                                     zCall( 0x006A5A10 );
    void RemoveFromAllSlots( int )                                                               zCall( 0x006A5E40 );
    oCVob* RemoveFromSlot( zSTRING const&, int )                                                 zCall( 0x006A5E80 );
    oCVob* RemoveFromSlot( TNpcSlot*, int )                                                      zCall( 0x006A5F50 );
    oCVob* DropFromSlot( zSTRING const& )                                                        zCall( 0x006A61A0 );
    oCVob* DropFromSlot( TNpcSlot* )                                                             zCall( 0x006A6270 );
    void UpdateSlots()                                                                           zCall( 0x006A6530 );
    void SetInteractMob( oCMobInter* )                                                           zCall( 0x006A65C0 );
    oCMobInter* GetInteractMob()                                                                 zCall( 0x006A6650 );
    void SetInteractItem( oCItem* )                                                              zCall( 0x006A6670 );
    int EV_DrawWeapon( oCMsgWeapon* )                                                            zCall( 0x006A8500 );
    int EV_DrawWeapon1( oCMsgWeapon* )                                                           zCall( 0x006A8B80 );
    int EV_DrawWeapon2( oCMsgWeapon* )                                                           zCall( 0x006A8E20 );
    int EV_RemoveWeapon( oCMsgWeapon* )                                                          zCall( 0x006A93C0 );
    int EV_RemoveWeapon1( oCMsgWeapon* )                                                         zCall( 0x006A9790 );
    int EV_RemoveWeapon2( oCMsgWeapon* )                                                         zCall( 0x006A9920 );
    int EV_ChooseWeapon( oCMsgWeapon* )                                                          zCall( 0x006A9C80 );
    int EV_ForceRemoveWeapon( oCMsgWeapon* )                                                     zCall( 0x006A9F40 );
    int EV_EquipBestWeapon( oCMsgWeapon* )                                                       zCall( 0x006AA200 );
    void EquipBestWeapon( int )                                                                  zCall( 0x006AA220 );
    int EV_EquipBestArmor( oCMsgWeapon* )                                                        zCall( 0x006AA470 );
    void EquipBestArmor()                                                                        zCall( 0x006AA510 );
    int EV_UnequipWeapons( oCMsgWeapon* )                                                        zCall( 0x006AA5A0 );
    int EV_UnequipArmor( oCMsgWeapon* )                                                          zCall( 0x006AA760 );
    int EV_EquipArmor( oCMsgWeapon* )                                                            zCall( 0x006AA810 );
    int EV_AttackForward( oCMsgAttack* )                                                         zCall( 0x006AA870 );
    int EV_AttackLeft( oCMsgAttack* )                                                            zCall( 0x006AAF90 );
    int EV_AttackRight( oCMsgAttack* )                                                           zCall( 0x006AB760 );
    int EV_AttackRun( oCMsgAttack* )                                                             zCall( 0x006ABEF0 );
    int EV_AttackFinish( oCMsgAttack* )                                                          zCall( 0x006AC180 );
    int EV_Parade( oCMsgAttack* )                                                                zCall( 0x006AC8B0 );
    int InitAim( oCMsgAttack*, oCNpc**, int*, int*, int )                                        zCall( 0x006ACE60 );
    int TransitionAim( int, int )                                                                zCall( 0x006AD080 );
    int InterpolateAim( oCNpc* )                                                                 zCall( 0x006AD210 );
    int FinalizeAim( int, int )                                                                  zCall( 0x006AD350 );
    int EV_StopAim( oCMsgAttack* )                                                               zCall( 0x006AD490 );
    int EV_AimAt( oCMsgAttack* )                                                                 zCall( 0x006AD4B0 );
    int EV_ShootAt( oCMsgAttack* )                                                               zCall( 0x006AD580 );
    int EV_Defend( oCMsgAttack* )                                                                zCall( 0x006AD720 );
    int EV_Drink( oCMsgUseItem* )                                                                zCall( 0x006AD750 );
    int EV_TakeVob( oCMsgManipulate* )                                                           zCall( 0x006ADA70 );
    int EV_DropVob( oCMsgManipulate* )                                                           zCall( 0x006ADE00 );
    int EV_ThrowVob( oCMsgManipulate* )                                                          zCall( 0x006AE090 );
    int EV_Exchange( oCMsgManipulate* )                                                          zCall( 0x006AE310 );
    int EV_DropMob( oCMsgManipulate* )                                                           zCall( 0x006AE610 );
    int EV_TakeMob( oCMsgManipulate* )                                                           zCall( 0x006AE6F0 );
    int EV_UseMob( oCMsgManipulate* )                                                            zCall( 0x006AE7B0 );
    int EV_UseMobWithItem( oCMsgManipulate* )                                                    zCall( 0x006AE9D0 );
    int EV_InsertInteractItem( oCMsgManipulate* )                                                zCall( 0x006AEA20 );
    int EV_ExchangeInteractItem( oCMsgManipulate* )                                              zCall( 0x006AEC30 );
    int EV_RemoveInteractItem( oCMsgManipulate* )                                                zCall( 0x006AEDC0 );
    int EV_CreateInteractItem( oCMsgManipulate* )                                                zCall( 0x006AEDD0 );
    int EV_DestroyInteractItem( oCMsgManipulate* )                                               zCall( 0x006AEF60 );
    zCModelAni* InteractItemGetAni( zSTRING const&, int, int )                                   zCall( 0x006AF130 );
    int EV_PlaceInteractItem( oCMsgManipulate* )                                                 zCall( 0x006AF3B0 );
    int GetInteractItemMaxState( zSTRING const& )                                                zCall( 0x006AF4E0 );
    int InteractItemIsInState( zSTRING const&, int )                                             zCall( 0x006AF6D0 );
    int EV_EquipItem( oCMsgManipulate* )                                                         zCall( 0x006AF8B0 );
    int EV_UseItem( oCMsgManipulate* )                                                           zCall( 0x006AF950 );
    int EV_UseItemToState( oCMsgManipulate* )                                                    zCall( 0x006AFC70 );
    void CallScript( zSTRING const& )                                                            zCall( 0x006B05A0 );
    void CallScript( int )                                                                       zCall( 0x006B05D0 );
    int EV_CallScript( oCMsgManipulate* )                                                        zCall( 0x006B05F0 );
    int EV_Unconscious( oCMsgState* )                                                            zCall( 0x006B0760 );
    int EV_DoState( oCMsgState* )                                                                zCall( 0x006B09D0 );
    int EV_Wait( oCMsgState* )                                                                   zCall( 0x006B0BF0 );
    int ApplyTimedOverlayMds( zSTRING const&, float )                                            zCall( 0x006B0C60 );
    int EV_OutputSVM_Overlay( oCMsgConversation* )                                               zCall( 0x006B0E60 );
    int EV_OutputSVM( oCMsgConversation* )                                                       zCall( 0x006B15A0 );
    int EV_Output( oCMsgConversation* )                                                          zCall( 0x006B1A70 );
    int EV_PlayAni( oCMsgConversation* )                                                         zCall( 0x006B1E30 );
    int EV_PlayAniFace( oCMsgConversation* )                                                     zCall( 0x006B2030 );
    int StartDialogAni()                                                                         zCall( 0x006B2130 );
    int EV_PlayAniSound( oCMsgConversation* )                                                    zCall( 0x006B2350 );
    int ActivateDialogCam( float )                                                               zCall( 0x006B2430 );
    int DeactivateDialogCam()                                                                    zCall( 0x006B2670 );
    int EV_PlaySound( oCMsgConversation* )                                                       zCall( 0x006B2800 );
    int EV_LookAt( oCMsgConversation* )                                                          zCall( 0x006B3210 );
    int EV_StopLookAt( oCMsgConversation* )                                                      zCall( 0x006B34E0 );
    int EV_PointAt( oCMsgConversation* )                                                         zCall( 0x006B3690 );
    int EV_StopPointAt( oCMsgConversation* )                                                     zCall( 0x006B3830 );
    int EV_QuickLook( oCMsgConversation* )                                                       zCall( 0x006B3880 );
    int EV_Cutscene( oCMsgConversation* )                                                        zCall( 0x006B3B10 );
    int EV_WaitTillEnd( oCMsgConversation* )                                                     zCall( 0x006B3D00 );
    int EV_StopProcessInfos( oCMsgConversation* )                                                zCall( 0x006B3DB0 );
    int EV_ProcessInfos( oCMsgConversation* )                                                    zCall( 0x006B3DD0 );
    int AssessPlayer_S( oCNpc* )                                                                 zCall( 0x006B3E90 );
    int AssessEnemy_S( oCNpc* )                                                                  zCall( 0x006B4090 );
    int AssessFighter_S( oCNpc* )                                                                zCall( 0x006B4290 );
    int AssessBody_S( oCNpc* )                                                                   zCall( 0x006B4490 );
    int AssessItem_S( oCItem* )                                                                  zCall( 0x006B4690 );
    void SetNpcsToState( int, int )                                                              zCall( 0x006B4890 );
    void StopCutscenes()                                                                         zCall( 0x006B4960 );
    void CreatePassivePerception( int, zCVob*, zCVob* )                                          zCall( 0x006B49C0 );
    int AssessMurder_S( oCNpc* )                                                                 zCall( 0x006B5780 );
    int AssessThreat_S( oCNpc* )                                                                 zCall( 0x006B57A0 );
    int AssessDefeat_S( oCNpc* )                                                                 zCall( 0x006B5940 );
    int AssessDamage_S( oCNpc*, int )                                                            zCall( 0x006B5960 );
    int AssessOthersDamage_S( oCNpc*, oCNpc*, int )                                              zCall( 0x006B5B00 );
    int AssessRemoveWeapon_S( oCNpc* )                                                           zCall( 0x006B5B20 );
    int ObserveIntruder_S()                                                                      zCall( 0x006B5B40 );
    int AssessWarn_S( oCNpc* )                                                                   zCall( 0x006B5BD0 );
    int CatchThief_S( oCNpc* )                                                                   zCall( 0x006B5BF0 );
    int AssessTheft_S( oCNpc* )                                                                  zCall( 0x006B5D90 );
    int AssessCall_S( oCNpc* )                                                                   zCall( 0x006B5DB0 );
    int AssessTalk_S( oCNpc* )                                                                   zCall( 0x006B5F50 );
    int AssessGivenItem_S( oCNpc*, oCItem* )                                                     zCall( 0x006B60F0 );
    int AssessMagic_S( oCNpc*, int )                                                             zCall( 0x006B62F0 );
    int AssessStopMagic_S( oCNpc*, int )                                                         zCall( 0x006B65F0 );
    int AssessCaster_S( oCSpell* )                                                               zCall( 0x006B68C0 );
    int AssessFakeGuild_S()                                                                      zCall( 0x006B68E0 );
    int MoveMob_S( oCMOB* )                                                                      zCall( 0x006B6910 );
    int AssessUseMob_S( oCMobInter* )                                                            zCall( 0x006B69C0 );
    int MoveNpc_S( oCNpc* )                                                                      zCall( 0x006B6A10 );
    int AssessEnterRoom_S()                                                                      zCall( 0x006B6BB0 );
    float GetDistToSound()                                                                       zCall( 0x006B6BC0 );
    zCVob* GetSoundSource()                                                                      zCall( 0x006B6C80 );
    void SetSoundSource( int, zCVob*, zVEC3& )                                                   zCall( 0x006B6C90 );
    void ClearPerceptionLists()                                                                  zCall( 0x006B6D00 );
    void CreateVobList( zCArray<zCVob*>&, float )                                                zCall( 0x006B6DF0 );
    void ClearVobList()                                                                          zCall( 0x006B6EB0 );
    void InsertInVobList( zCVob* )                                                               zCall( 0x006B6F30 );
    void RemoveFromVobList( zCVob* )                                                             zCall( 0x006B7080 );
    void CreateVobList( float )                                                                  zCall( 0x006B7110 );
    void SetPerceptionTime( float )                                                              zCall( 0x006B7270 );
    void PerceiveAll()                                                                           zCall( 0x006B72B0 );
    void PerceptionCheck()                                                                       zCall( 0x006B7400 );
    int PercFilterNpc( oCNpc* )                                                                  zCall( 0x006B78B0 );
    int PercFilterItem( oCItem* )                                                                zCall( 0x006B78C0 );
    void ClearPerception()                                                                       zCall( 0x006B78E0 );
    void EnablePerception( int, int )                                                            zCall( 0x006B7900 );
    void DisablePerception( int )                                                                zCall( 0x006B7A40 );
    int HasPerception( int )                                                                     zCall( 0x006B7AA0 );
    int GetPerceptionFunc( int )                                                                 zCall( 0x006B7AE0 );
    void SetBodyState( int )                                                                     zCall( 0x006B8000 );
    int GetBodyState()                                                                           zCall( 0x006B8140 );
    int GetFullBodyState()                                                                       zCall( 0x006B8150 );
    zSTRING GetBodyStateName()                                                                   zCall( 0x006B8170 );
    int HasBodyStateModifier( int )                                                              zCall( 0x006B8250 );
    void SetBodyStateModifier( int )                                                             zCall( 0x006B8270 );
    void ClrBodyStateModifier( int )                                                             zCall( 0x006B82A0 );
    zSTRING GetBodyStateModifierNames()                                                          zCall( 0x006B82D0 );
    int ModifyBodyState( int, int )                                                              zCall( 0x006B85B0 );
    int IsBodyStateInterruptable()                                                               zCall( 0x006B8600 );
    int HasBodyStateFreeHands()                                                                  zCall( 0x006B8630 );
    int IsInGlobalCutscene()                                                                     zCall( 0x006B8660 );
    void MakeSpellBook()                                                                         zCall( 0x006B86A0 );
    void DestroySpellBook()                                                                      zCall( 0x006B8730 );
    float GetDamageMultiplier()                                                                  zCall( 0x006B8960 );
    void SetDamageMultiplier( float )                                                            zCall( 0x006B8970 );
    void SetShowNews( int )                                                                      zCall( 0x006B8AF0 );
    void UseStandAI()                                                                            zCall( 0x006B8B40 );
    int IsVictimAwareOfTheft()                                                                   zCall( 0x006BAD80 );
    void CheckSpecialSituations()                                                                zCall( 0x006BAE10 );
    void StopTheft( oCNpc*, int )                                                                zCall( 0x006BAFD0 );
    void OpenInventory()                                                                         zCall( 0x006BB0A0 );
    void CloseInventory()                                                                        zCall( 0x006BB2F0 );
    int OpenSteal()                                                                              zCall( 0x006BB350 );
    void CloseSteal()                                                                            zCall( 0x006BB860 );
    void OpenDeadNpc()                                                                           zCall( 0x006BB890 );
    void CloseDeadNpc()                                                                          zCall( 0x006BBAA0 );
    void InitDamage()                                                                            zCall( 0x0072F4C0 );
    int EV_DamageOnce( oCMsgDamage* )                                                            zCall( 0x0072F690 );
    int EV_DamagePerFrame( oCMsgDamage* )                                                        zCall( 0x0072F9D0 );
    void OnDamage_Hit( oSDamageDescriptor& )                                                     zCall( 0x00731410 );
    void OnDamage_Condition( oSDamageDescriptor& )                                               zCall( 0x00737C60 );
    void OnDamage_Script( oSDamageDescriptor& )                                                  zCall( 0x00738E40 );
    void OnDamage_Effects( oSDamageDescriptor& )                                                 zCall( 0x007396D0 );
    void OnDamage_Effects_Start( oSDamageDescriptor& )                                           zCall( 0x00739A20 );
    void OnDamage_Effects_End( oSDamageDescriptor& )                                             zCall( 0x0073F570 );
    void OnDamage_Anim( oSDamageDescriptor& )                                                    zCall( 0x00741990 );
    void OnDamage_Sound( oSDamageDescriptor& )                                                   zCall( 0x00746660 );
    void OnDamage_Events( oSDamageDescriptor& )                                                  zCall( 0x00746950 );
    void OnDamage_State( oSDamageDescriptor& )                                                   zCall( 0x00747630 );
    int HasFlag( unsigned long, unsigned long )                                                  zCall( 0x00747B40 );
    int IsNpcBetweenMeAndTarget( zCVob* )                                                        zCall( 0x007482A0 );
    int IsInDoubleFightRange( zCVob*, float& )                                                   zCall( 0x00748430 );
    int IsInFightRange( zCVob*, float& )                                                         zCall( 0x007485F0 );
    int GetFightRange()                                                                          zCall( 0x007487C0 );
    void SetFightRangeBase( int )                                                                zCall( 0x007487F0 );
    int GetFightRangeBase()                                                                      zCall( 0x00748800 );
    int GetFightRangeDynamic()                                                                   zCall( 0x00748810 );
    int GetFightRangeFist()                                                                      zCall( 0x00748830 );
    void SetFightRangeFist( int )                                                                zCall( 0x00748840 );
    int GetFightActionFromTable( int )                                                           zCall( 0x00748850 );
    int GetCurrentFightMove()                                                                    zCall( 0x00748890 );
    int FindNextFightAction()                                                                    zCall( 0x00748C20 );
    int ThinkNextFightAction()                                                                   zCall( 0x00749150 );
    int FightAttackMelee( int )                                                                  zCall( 0x007499D0 );
    int FightAttackBow()                                                                         zCall( 0x0074A440 );
    int EV_AttackBow( oCMsgAttack* )                                                             zCall( 0x0074A530 );
    int FightAttackMagic()                                                                       zCall( 0x0074A800 );
    int EV_AttackMagic( oCMsgAttack* )                                                           zCall( 0x0074A8D0 );
    int EV_CastSpell( oCMsgMagic* )                                                              zCall( 0x0074A8E0 );
    void CheckRunningFightAnis()                                                                 zCall( 0x0074A9F0 );
    void GotoFightPosition()                                                                     zCall( 0x0074ABA0 );
    void Fighting()                                                                              zCall( 0x0074AC90 );
    oCItem* GetSpellItem( int )                                                                  zCall( 0x0074AE90 );
    int ReadySpell( int, int )                                                                   zCall( 0x0074AEF0 );
    int UnreadySpell()                                                                           zCall( 0x0074B090 );
    int HasRangedWeaponAndAmmo()                                                                 zCall( 0x0074B140 );
    int CanDrawWeapon()                                                                          zCall( 0x0074B1F0 );
    int CanDive()                                                                                zCall( 0x0074B360 );
    int CanSwim()                                                                                zCall( 0x0074B390 );
    float GetClimbRange()                                                                        zCall( 0x0074B3C0 );
    float GetTurnSpeed()                                                                         zCall( 0x0074B3D0 );
    float GetJumpRange()                                                                         zCall( 0x0074B3F0 );
    int RbtChooseChasmAction( zVEC3 const&, zVEC3 const& )                                       zCall( 0x0074B400 );
    int CanGo( float, zVEC3& )                                                                   zCall( 0x0074B590 );
    float GetAngle( zCVob* )                                                                     zCall( 0x0074BC10 );
    void GetAngles( zVEC3&, float&, float& )                                                     zCall( 0x0074BD00 );
    void GetAngles( zCVob*, float&, float& )                                                     zCall( 0x0074C0D0 );
    float GetDistanceToPos2( zVEC3&, int )                                                       zCall( 0x0074C110 );
    float GetFallDownHeight()                                                                    zCall( 0x0074C1E0 );
    zCVob* GetRbtObstacleVob()                                                                   zCall( 0x0074C200 );
    zVEC3 GetVecNormalFromBBox( zCVob*, zVEC3& )                                                 zCall( 0x0074C210 );
    void SetFallDownDamage( int )                                                                zCall( 0x0074C7A0 );
    void SetFallDownHeight( float )                                                              zCall( 0x0074C7B0 );
    void SetRoute( zCRoute* )                                                                    zCall( 0x0074C7C0 );
    void CreateFallDamage( float )                                                               zCall( 0x0074C7F0 );
    void Fleeing()                                                                               zCall( 0x0074CAB0 );
    int ThinkNextFleeAction()                                                                    zCall( 0x0074CAC0 );
    void Follow()                                                                                zCall( 0x0074CEC0 );
    void StandUp( int, int )                                                                     zCall( 0x0074D5A0 );
    float Turn( zVEC3& )                                                                         zCall( 0x0074DA70 );
    float Turning( zVEC3& )                                                                      zCall( 0x0074DB90 );
    void AI_Flee( oCNpc* )                                                                       zCall( 0x0074DC80 );
    void AI_Follow( oCNpc* )                                                                     zCall( 0x0074DC90 );
    int EV_AlignToFP( oCMsgMovement* )                                                           zCall( 0x0074DCA0 );
    int EV_CanSeeNpc( oCMsgMovement* )                                                           zCall( 0x0074DEF0 );
    int EV_GoRoute( oCMsgMovement* )                                                             zCall( 0x0074DF40 );
    int EV_Jump( oCMsgMovement* )                                                                zCall( 0x0074E740 );
    int EV_RobustTrace( oCMsgMovement* )                                                         zCall( 0x0074E7A0 );
    int EV_StandUp( oCMsgMovement* )                                                             zCall( 0x0074E800 );
    int EV_Strafe( oCMsgMovement* )                                                              zCall( 0x0074E8E0 );
    int EV_WhirlAround( oCMsgMovement* )                                                         zCall( 0x0074ED50 );
    int EV_Dodge( oCMsgMovement* )                                                               zCall( 0x0074F3F0 );
    int EV_GotoPos( oCMsgMovement* )                                                             zCall( 0x0074F620 );
    int EV_GotoVob( oCMsgMovement* )                                                             zCall( 0x0074F6E0 );
    int EV_GotoFP( oCMsgMovement* )                                                              zCall( 0x0074F860 );
    int EV_SetWalkMode( oCMsgMovement* )                                                         zCall( 0x0074FAA0 );
    int EV_Turn( oCMsgMovement* )                                                                zCall( 0x0074FE90 );
    int EV_TurnAway( oCMsgMovement* )                                                            zCall( 0x0074FF70 );
    int EV_TurnToPos( oCMsgMovement* )                                                           zCall( 0x00750120 );
    int EV_TurnToVob( oCMsgMovement* )                                                           zCall( 0x00750210 );
    void ForceRotation( float )                                                                  zCall( 0x007504A0 );
    int RbtCheckForSolution( zVEC3, zVEC3 )                                                      zCall( 0x007504E0 );
    void RbtReset()                                                                              zCall( 0x00750610 );
    void RbtInit( zVEC3&, zCVob* )                                                               zCall( 0x00750720 );
    void RbtUpdate( zVEC3&, zCVob* )                                                             zCall( 0x00750740 );
    int RbtMoveToExactPosition()                                                                 zCall( 0x00750930 );
    int RobustTrace()                                                                            zCall( 0x00750A10 );
    float RbtCalcTurnDirection( zVEC3 const&, float, int )                                       zCall( 0x00750D60 );
    int RbtIsObjectObstacle( zCVob*, zVEC3 const&, zVEC3 const&, zVEC3& )                        zCall( 0x007510A0 );
    int RbtGetObstacle( zVEC3 const&, zVEC3 const&, zCVob*&, zVEC3& )                            zCall( 0x00751310 );
    int RbtGetSmallObstacle( zVEC3 const&, zCVob*&, zVEC3& )                                     zCall( 0x007514C0 );
    int RbtAvoidObstacles()                                                                      zCall( 0x00751610 );
    int RbtIsDirectionValid( zVEC3 const& )                                                      zCall( 0x00751CC0 );
    oSDirectionInfo* RbtInsertDirection( zVEC3 )                                                 zCall( 0x00751D40 );
    int RbtCheckLastDirection( float )                                                           zCall( 0x00751FD0 );
    int RbtCheckIfTargetVisible()                                                                zCall( 0x007522D0 );
    int RbtGotoFollowPosition()                                                                  zCall( 0x007524F0 );
    int CanStrafe( int, int )                                                                    zCall( 0x00752720 );
    int CanJumpBack( int )                                                                       zCall( 0x00752980 );
    void SetWalkStopChasm( int )                                                                 zCall( 0x00752B20 );
    int GetWalkStopChasm()                                                                       zCall( 0x00752B60 );
    static zSTRING GetInstanceByID( int )                                                        zCall( 0x006A1C40 );
    static int GetIDByInstance( zSTRING const& )                                                 zCall( 0x006A1CA0 );
    static void CreateSoundPerception( int, zCVob*, zVEC3 const&, zCVob*, int )                  zCall( 0x006B52C0 );
    static int AssessFightSound_S( zCVob*, zVEC3 const&, zCVob* )                                zCall( 0x006B5B80 );
    static int AssessQuietSound_S( zCVob*, zVEC3 const& )                                        zCall( 0x006B5BB0 );
    static void SetPerceptionRange( int, float )                                                 zCall( 0x006B7B20 );
    static int IsInPerceptionRange( int, float )                                                 zCall( 0x006B7B40 );
    static int IsInPerceptionRange( int, zCVob*, zCVob* )                                        zCall( 0x006B7B70 );
    static void InitStatics()                                                                    zCall( 0x006B7BB0 );
    static void ReleaseStatics()                                                                 zCall( 0x006B7F90 );
    static void InitBodyStates()                                                                 zCall( 0x006B7FA0 );
    static void SetNpcAIDisabled( int )                                                          zCall( 0x006B8980 );
    static void ProcessAITimer()                                                                 zCall( 0x006B89D0 );
    static int IsScriptStateAIEnabled()                                                          zCall( 0x006B8A50 );
    static int IsMessageAIEnabled()                                                              zCall( 0x006B8AA0 );
    static zCObject* _CreateNewInstance()                                                        zCall( 0x006B8DE0 );
    static void EnableDamageDebugOutput( int )                                                   zCall( 0x0072F3F0 );
    static void NotifyDamageToSpy( zSTRING& )                                                    zCall( 0x0072F400 );
    static void InitFightAI()                                                                    zCall( 0x00747D10 );
    static void ExitFightAI()                                                                    zCall( 0x00748240 );
    virtual zCClassDef* _GetClassDef() const                                                     zCall( 0x0068BE40 );
    virtual void Archive( zCArchiver& )                                                          zCall( 0x006A2680 );
    virtual void Unarchive( zCArchiver& )                                                        zCall( 0x006A31E0 );
    virtual ~oCNpc()                                                                             zCall( 0x0068C100 );
    virtual void OnTouch( zCVob* )                                                               zCall( 0x006A68E0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                            zCall( 0x006A69E0 );
    virtual zCVob::zTVobCharClass GetCharacterClass()                                            zCall( 0x006A6660 );
    virtual void SetVisual( zCVisual* )                                                          zCall( 0x0068BEB0 );
    virtual int GetScriptInstance( zSTRING*&, int& )                                             zCall( 0x006A1BC0 );
    virtual int SetByScriptInstance( zSTRING const*, int )                                       zCall( 0x006A1BF0 );
    virtual int GetCSStateFlags()                                                                zCall( 0x0068FEA0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                 zCall( 0x0069AA40 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                             zCall( 0x0069AC00 );
    virtual void ShowDebugInfo( zCCamera* )                                                      zCall( 0x006B8760 );
    virtual int GetInstance()                                                                    zCall( 0x0068BE50 );
    virtual zSTRING GetInstanceName()                                                            zCall( 0x006A1B80 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int )     zCall( 0x0069B520 );
    virtual void SetWeaponMode( int )                                                            zCall( 0x00696550 );
    virtual void SetWeaponMode2( int )                                                           zCall( 0x00695A60 );
    virtual void DoDie( oCNpc* )                                                                 zCall( 0x006934A0 );
    virtual oCItem* DoInsertMunition( zSTRING const& )                                           zCall( 0x006A04F0 );
    virtual void DoRemoveMunition()                                                              zCall( 0x006A07A0 );
    virtual int DoSetToFightMode( oCItem* )                                                      zCall( 0x006A1660 );
    virtual int DoShootArrow( int )                                                              zCall( 0x006A09F0 );
    virtual void OnDamage( oSDamageDescriptor& )                                                 zCall( 0x00730FE0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )                            zCall( 0x007476A0 );
    virtual void ResetPos( zVEC3& )                                                              zCall( 0x0074CED0 );
    virtual void EmergencyResetPos( zVEC3& )                                                     zCall( 0x0074D1E0 );
    virtual void InitByScript( int, int )                                                        zCall( 0x0068C840 );
    virtual void Disable()                                                                       zCall( 0x006A1D20 );
    virtual void Enable( zVEC3& )                                                                zCall( 0x006A2000 );
    virtual void InitHumanAI()                                                                   zCall( 0x0068CE20 );
    virtual int IsMoreImportant( zCVob*, zCVob* )                                                zCall( 0x006B6DA0 );
    virtual int DoDoAniEvents()                                                                  zCall( 0x0069EDF0 );
    virtual int DoModelSwapMesh( zSTRING const&, zSTRING const& )                                zCall( 0x006A0130 );
    virtual int DoTakeVob( zCVob* )                                                              zCall( 0x006A0D10 );
    virtual int DoDropVob( zCVob* )                                                              zCall( 0x006A10F0 );
    virtual int DoRemoveFromInventory( oCItem* )                                                 zCall( 0x006A1610 );
    virtual int DoPutInInventory( oCItem* )                                                      zCall( 0x006A15F0 );
    virtual int DoThrowVob( zCVob*, float )                                                      zCall( 0x006A13C0 );
    virtual int DoExchangeTorch()                                                                zCall( 0x006A1680 );
    virtual void GetSoundMaterial_MA( zCSoundManager::zTSndManMedium&, oTSndMaterial&, zSTRING ) zCall( 0x0069B3D0 );
    virtual void GetSoundMaterial_MH_HM( zCSoundManager::zTSndManMedium&, oTSndMaterial& )       zCall( 0x0069B600 );
    virtual int IsAPlayer()                                                                      zCall( 0x0069E9D0 );
    virtual int IsSelfPlayer()                                                                   zCall( 0x0069E9E0 );
    virtual void SetAsPlayer()                                                                   zCall( 0x0069EAE0 );
    virtual int IsMonster()                                                                      zCall( 0x0069EA30 );
    virtual int IsHalfMonster()                                                                  zCall( 0x0069EA40 );
    virtual int IsHuman()                                                                        zCall( 0x0069EA90 );
    virtual int IsGoblin()                                                                       zCall( 0x0069EAA0 );
    virtual int IsOrc()                                                                          zCall( 0x0069EAB0 );
    virtual int IsSkeleton()                                                                     zCall( 0x0069EAD0 );
    virtual int GetPlayerNumber()                                                                zCall( 0x0069E9F0 );
    virtual void ProcessNpc()                                                                    zCall( 0x0069AE50 );
    virtual int AllowDiscardingOfSubtree()                                                       zCall( 0x006A4A60 );

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

} // namespace Gothic_I_Classic

#endif // __ONPC_H__VER0__