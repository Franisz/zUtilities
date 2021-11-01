// Supported with union (c) 2018-2021 Union team

#ifndef __ONPC_MESSAGES_H__VER0__
#define __ONPC_MESSAGES_H__VER0__

#include "zVob.h"
#include "zBuffer.h"
#include "zSound.h"
#include "zModel.h"
#include "oNpc.h"

namespace Gothic_I_Classic {

  // sizeof 44h
  class oCNpcMessage : public zCEventMessage {
  public:
    zCLASS_DECLARATION( oCNpcMessage )

    zSTRING targetVobName; // sizeof 14h    offset 2Ch
    int highPriority : 1;  // sizeof 01h    offset bit
    int deleted      : 1;  // sizeof 01h    offset bit
    int inUse        : 1;  // sizeof 01h    offset bit

    void oCNpcMessage_OnInit()                                          zCall( 0x006BDC20 );
    oCNpcMessage()                                                      zInit( oCNpcMessage_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x006BBD60 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006BBE80 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006BDD60 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006BDDD0 );
    virtual ~oCNpcMessage()                                             zCall( 0x006BDD00 );
    virtual int IsOverlay()                                             zCall( 0x006BBEF0 );
    virtual int IsHighPriority()                                        zCall( 0x006BBF30 );
    virtual int IsJob()                                                 zCall( 0x006BBF00 );
    virtual void Delete()                                               zCall( 0x006BBE90 );
    virtual int IsDeleteable()                                          zCall( 0x006BBF20 );
    virtual int IsDeleted()                                             zCall( 0x006BBF10 );
    virtual void SetInUse( int )                                        zCall( 0x006BBEA0 );
    virtual int IsInUse()                                               zCall( 0x006BBEC0 );
    virtual void SetHighPriority( int )                                 zCall( 0x006BBED0 );

    // user API
    #include "oCNpcMessage.inl"
  };

  // sizeof 110h
  class oCMsgDamage : public oCNpcMessage {
  public:
    zCLASS_DECLARATION( oCMsgDamage )

    enum TDamageSubType {
      EV_DAMAGE_ONCE,
      EV_DAMAGE_PER_FRAME,
      EV_DAMAGE_MAX
    };

    oCNpc::oSDamageDescriptor descDamage; // sizeof CCh    offset 44h

    void oCMsgDamage_OnInit()                                                   zCall( 0x006BDE70 );
    void oCMsgDamage_OnInit( TDamageSubType )                                   zCall( 0x006BDF70 );
    void oCMsgDamage_OnInit( TDamageSubType, oCNpc::oSDamageDescriptor const& ) zCall( 0x006BE040 );
    oCMsgDamage()                                                               zInit( oCMsgDamage_OnInit() );
    oCMsgDamage( TDamageSubType a0 )                                            zInit( oCMsgDamage_OnInit( a0 ));
    oCMsgDamage( TDamageSubType a0, oCNpc::oSDamageDescriptor const& a1 )       zInit( oCMsgDamage_OnInit( a0, a1 ));
    static zCObject* _CreateNewInstance()                                       zCall( 0x006BC130 );
    virtual zCClassDef* _GetClassDef() const                                    zCall( 0x006BC260 );
    virtual void Archive( zCArchiver& )                                         zCall( 0x006BE370 );
    virtual void Unarchive( zCArchiver& )                                       zCall( 0x006BE3F0 );
    virtual ~oCMsgDamage()                                                      zCall( 0x006BE130 );
    virtual int IsOverlay()                                                     zCall( 0x006BC280 );
    virtual int IsNetRelevant()                                                 zCall( 0x006BC270 );
    virtual int IsHighPriority()                                                zCall( 0x006BC2A0 );
    virtual int IsDeleteable()                                                  zCall( 0x006BC290 );
    virtual int MD_GetNumOfSubTypes()                                           zCall( 0x006BE210 );
    virtual zSTRING MD_GetSubTypeString( int )                                  zCall( 0x006BE220 );
    virtual void Pack( zCBuffer&, zCEventManager* )                             zCall( 0x006BE350 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                           zCall( 0x006BE360 );

    // user API
    #include "oCMsgDamage.inl"
  };

  // sizeof 50h
  class oCMsgWeapon : public oCNpcMessage {
  public:
    zCLASS_DECLARATION( oCMsgWeapon )

    enum TWeaponSubType {
      EV_DRAWWEAPON,
      EV_DRAWWEAPON1,
      EV_DRAWWEAPON2,
      EV_REMOVEWEAPON,
      EV_REMOVEWEAPON1,
      EV_REMOVEWEAPON2,
      EV_CHOOSEWEAPON,
      EV_FORCEREMOVEWEAPON,
      EV_ATTACK,
      EV_EQUIPBESTWEAPON,
      EV_EQUIPBESTARMOR,
      EV_UNEQUIPWEAPONS,
      EV_UNEQUIPARMOR,
      EV_EQUIPARMOR,
      EV_WEAPON_MAX
    };

    int targetMode;          // sizeof 04h    offset 44h
    int duringRun       : 1; // sizeof 01h    offset bit
    int initDone        : 1; // sizeof 01h    offset bit
    int firstTime       : 1; // sizeof 01h    offset bit
    int useFist         : 1; // sizeof 01h    offset bit
    int showMagicCircle : 1; // sizeof 01h    offset bit
    int ani;                 // sizeof 04h    offset 4Ch

    void oCMsgWeapon_OnInit()                                           zCall( 0x006BF570 );
    void oCMsgWeapon_OnInit( TWeaponSubType, int, int )                 zCall( 0x006BF630 );
    oCMsgWeapon()                                                       zInit( oCMsgWeapon_OnInit() );
    oCMsgWeapon( TWeaponSubType a0, int a1, int a2 )                    zInit( oCMsgWeapon_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                               zCall( 0x006BC490 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006BC5A0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006BF710 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006BF7E0 );
    virtual ~oCMsgWeapon()                                              zCall( 0x006BC5E0 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x006BF920 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x006BF930 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()         zCall( 0x006BFD40 );
    virtual float MD_GetMinTime()                                       zCall( 0x006BFD50 );

    // user API
    #include "oCMsgWeapon.inl"
  };

  // sizeof 7Ch
  class oCMsgMovement : public oCNpcMessage {
  public:
    zCLASS_DECLARATION( oCMsgMovement )

    enum TMovementSubType {
      EV_ROBUSTTRACE,
      EV_GOTOPOS,
      EV_GOTOVOB,
      EV_GOROUTE,
      EV_TURN,
      EV_TURNTOPOS,
      EV_TURNTOVOB,
      EV_TURNAWAY,
      EV_JUMP,
      EV_SETWALKMODE,
      EV_WHIRLAROUND,
      EV_STANDUP,
      EV_CANSEENPC,
      EV_STRAFE,
      EV_GOTOFP,
      EV_DODGE,
      EV_BEAMTO,
      EV_ALIGNTOFP,
      EV_MOVE_MAX
    };

    zSTRING targetName; // sizeof 14h    offset 44h
    zCRoute* route;     // sizeof 04h    offset 58h
    zCVob* targetVob;   // sizeof 04h    offset 5Ch
    zVEC3 targetPos;    // sizeof 0Ch    offset 60h
    float angle;        // sizeof 04h    offset 6Ch
    float timer;        // sizeof 04h    offset 70h
    int targetMode;     // sizeof 04h    offset 74h
    int ani;            // sizeof 04h    offset 78h

    void oCMsgMovement_OnInit()                                              zCall( 0x006BE4B0 );
    void oCMsgMovement_OnInit( TMovementSubType, zSTRING const& )            zCall( 0x006BE5B0 );
    void oCMsgMovement_OnInit( TMovementSubType, zCVob* )                    zCall( 0x006BE790 );
    void oCMsgMovement_OnInit( TMovementSubType, zVEC3 const& )              zCall( 0x006BE890 );
    void oCMsgMovement_OnInit( TMovementSubType, float )                     zCall( 0x006BE980 );
    void oCMsgMovement_OnInit( TMovementSubType, int )                       zCall( 0x006BEA60 );
    oCMsgMovement()                                                          zInit( oCMsgMovement_OnInit() );
    oCMsgMovement( TMovementSubType a0, zSTRING const& a1 )                  zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, zCVob* a1 )                          zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, zVEC3 const& a1 )                    zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, float a1 )                           zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, int a1 )                             zInit( oCMsgMovement_OnInit( a0, a1 ));
    void Init()                                                              zCall( 0x006BEC20 );
    static zCObject* _CreateNewInstance()                                    zCall( 0x006BC820 );
    virtual zCClassDef* _GetClassDef() const                                 zCall( 0x006BC930 );
    virtual void Archive( zCArchiver& )                                      zCall( 0x006BEC60 );
    virtual void Unarchive( zCArchiver& )                                    zCall( 0x006BED80 );
    virtual ~oCMsgMovement()                                                 zCall( 0x006BEB40 );
    virtual void Delete()                                                    zCall( 0x006BF510 );
    virtual int MD_GetNumOfSubTypes()                                        zCall( 0x006BEEF0 );
    virtual zSTRING MD_GetSubTypeString( int )                               zCall( 0x006BEF00 );
    virtual zSTRING MD_GetVobRefName()                                       zCall( 0x006BF340 );
    virtual void MD_SetVobRefName( zSTRING const& )                          zCall( 0x006BF3C0 );
    virtual void MD_SetVobParam( zCVob* )                                    zCall( 0x006BF500 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()              zCall( 0x006BF520 );
    virtual float MD_GetMinTime()                                            zCall( 0x006BF560 );

    // user API
    #include "oCMsgMovement.inl"
  };

  // sizeof 58h
  class oCMsgAttack : public oCNpcMessage {
  public:
    zCLASS_DECLARATION( oCMsgAttack )

    enum TAttackSubType {
      EV_ATTACKFORWARD,
      EV_ATTACKLEFT,
      EV_ATTACKRIGHT,
      EV_ATTACKRUN,
      EV_ATTACKFINISH,
      EV_PARADE,
      EV_AIMAT,
      EV_SHOOTAT,
      EV_STOPAIM,
      EV_DEFEND,
      EV_ATTACKBOW,
      EV_ATTACKMAGIC,
      EV_ATTACK_MAX
    };

    int combo;             // sizeof 04h    offset 44h
    zCVob* target;         // sizeof 04h    offset 48h
    int hitAni;            // sizeof 04h    offset 4Ch
    float startFrame;      // sizeof 04h    offset 50h
    int enableNextHit : 1; // sizeof 01h    offset bit
    int reachedTarget : 1; // sizeof 01h    offset bit

    void oCMsgAttack_OnInit()                                                zCall( 0x006BFD60 );
    void oCMsgAttack_OnInit( TAttackSubType, int, int )                      zCall( 0x006BFEC0 );
    void oCMsgAttack_OnInit( TAttackSubType, zCVob*, float )                 zCall( 0x006BFF90 );
    oCMsgAttack()                                                            zInit( oCMsgAttack_OnInit() );
    oCMsgAttack( TAttackSubType a0, int a1, int a2 )                         zInit( oCMsgAttack_OnInit( a0, a1, a2 ));
    oCMsgAttack( TAttackSubType a0, zCVob* a1, float a2 )                    zInit( oCMsgAttack_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                                    zCall( 0x006BCB20 );
    virtual zCClassDef* _GetClassDef() const                                 zCall( 0x006BCC30 );
    virtual void Archive( zCArchiver& )                                      zCall( 0x006C0070 );
    virtual void Unarchive( zCArchiver& )                                    zCall( 0x006C0110 );
    virtual ~oCMsgAttack()                                                   zCall( 0x006BFE60 );
    virtual int IsOverlay()                                                  zCall( 0x006BCC50 );
    virtual int IsNetRelevant()                                              zCall( 0x006BCC40 );
    virtual int MD_GetNumOfSubTypes()                                        zCall( 0x006C0500 );
    virtual zSTRING MD_GetSubTypeString( int )                               zCall( 0x006C0510 );
    virtual void Pack( zCBuffer&, zCEventManager* )                          zCall( 0x006C0200 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                        zCall( 0x006C0390 );

    // user API
    #include "oCMsgAttack.inl"
  };

  // sizeof 50h
  class oCMsgUseItem : public oCNpcMessage {
  public:
    zCLASS_DECLARATION( oCMsgUseItem )

    enum TUseItemSubType {
      EV_DRINK,
      EV_EQUIPITEM,
      EV_UNEQUIPITEM,
      EV_USEITEM_MAX
    };

    zCVob* vob; // sizeof 04h    offset 44h
    int ani;    // sizeof 04h    offset 48h
    int state;  // sizeof 04h    offset 4Ch

    void oCMsgUseItem_OnInit()                                          zCall( 0x006C0880 );
    void oCMsgUseItem_OnInit( TUseItemSubType, zCVob* )                 zCall( 0x006C0970 );
    oCMsgUseItem()                                                      zInit( oCMsgUseItem_OnInit() );
    oCMsgUseItem( TUseItemSubType a0, zCVob* a1 )                       zInit( oCMsgUseItem_OnInit( a0, a1 ));
    static zCObject* _CreateNewInstance()                               zCall( 0x006BCE50 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006BCF70 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006C0B30 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006C0BB0 );
    virtual ~oCMsgUseItem()                                             zCall( 0x006C0A30 );
    virtual int IsNetRelevant()                                         zCall( 0x006BCF80 );
    virtual void Pack( zCBuffer&, zCEventManager* )                     zCall( 0x006C0A90 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                   zCall( 0x006C0AE0 );

    // user API
    #include "oCMsgUseItem.inl"
  };

  // sizeof 74h
  class oCMsgState : public oCNpcMessage {
  public:
    zCLASS_DECLARATION( oCMsgState )

    enum TStateSubType {
      EV_STARTSTATE,
      EV_WAIT,
      EV_SETNPCSTOSTATE,
      EV_SETTIME,
      EV_APPLYTIMEDOVERLAY,
      EV_STATE_MAX
    };

    int function;        // sizeof 04h    offset 44h
    int minutes;         // sizeof 04h    offset 48h
    int instance;        // sizeof 04h    offset 4Ch
    zSTRING wp;          // sizeof 14h    offset 50h
    float timer;         // sizeof 04h    offset 64h
    oCNpc* other;        // sizeof 04h    offset 68h
    oCNpc* victim;       // sizeof 04h    offset 6Ch
    int endOldState : 1; // sizeof 01h    offset bit
    int inRoutine   : 1; // sizeof 01h    offset bit

    void oCMsgState_OnInit()                                            zCall( 0x006C0C60 );
    void oCMsgState_OnInit( TStateSubType, float )                      zCall( 0x006C0D60 );
    void oCMsgState_OnInit( TStateSubType, int )                        zCall( 0x006C0E40 );
    void oCMsgState_OnInit( TStateSubType, int, int, zSTRING const& )   zCall( 0x006C0F20 );
    oCMsgState()                                                        zInit( oCMsgState_OnInit() );
    oCMsgState( TStateSubType a0, float a1 )                            zInit( oCMsgState_OnInit( a0, a1 ));
    oCMsgState( TStateSubType a0, int a1 )                              zInit( oCMsgState_OnInit( a0, a1 ));
    oCMsgState( TStateSubType a0, int a1, int a2, zSTRING const& a3 )   zInit( oCMsgState_OnInit( a0, a1, a2, a3 ));
    static zCObject* _CreateNewInstance()                               zCall( 0x006BD170 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006BD290 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006C11A0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006C1250 );
    virtual ~oCMsgState()                                               zCall( 0x006C1110 );
    virtual int IsOverlay()                                             zCall( 0x006BD2A0 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x006C1340 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x006C1350 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()         zCall( 0x006C1580 );
    virtual float MD_GetMinTime()                                       zCall( 0x006C1590 );

    // user API
    #include "oCMsgState.inl"
  };

  // sizeof 7Ch
  class oCMsgManipulate : public oCNpcMessage {
  public:
    zCLASS_DECLARATION( oCMsgManipulate )

    enum TManipulateSubType {
      EV_TAKEVOB,
      EV_DROPVOB,
      EV_THROWVOB,
      EV_EXCHANGE,
      EV_USEMOB,
      EV_USEITEM,
      EV_INSERTINTERACTITEM,
      EV_REMOVEINTERACTITEM,
      EV_CREATEINTERACTITEM,
      EV_DESTROYINTERACTITEM,
      EV_PLACEINTERACTITEM,
      EV_EXCHANGEINTERACTITEM,
      EV_USEMOBWITHITEM,
      EV_CALLSCRIPT,
      EV_EQUIPITEM,
      EV_USEITEMTOSTATE,
      EV_TAKEMOB,
      EV_DROPMOB,
      EV_MANIP_MAX
    };

    zSTRING name;     // sizeof 14h    offset 44h
    zSTRING slot;     // sizeof 14h    offset 58h
    zCVob* targetVob; // sizeof 04h    offset 6Ch
    int flag;         // sizeof 04h    offset 70h
    float aniCombY;   // sizeof 04h    offset 74h
    union {
      int npcSlot;
      int targetState;
      int aniID;
    };

    void oCMsgManipulate_OnInit()                                                     zCall( 0x006C15D0 );
    void oCMsgManipulate_OnInit( TManipulateSubType )                                 zCall( 0x006C16D0 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zCVob* )                         zCall( 0x006C17A0 );
    void oCMsgManipulate_OnInit( TManipulateSubType, int )                            zCall( 0x006C1870 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zSTRING const&, int )            zCall( 0x006C1940 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zCVob*, int )                    zCall( 0x006C1B10 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zSTRING const&, zSTRING const& ) zCall( 0x006C1BE0 );
    oCMsgManipulate()                                                                 zInit( oCMsgManipulate_OnInit() );
    oCMsgManipulate( TManipulateSubType a0 )                                          zInit( oCMsgManipulate_OnInit( a0 ));
    oCMsgManipulate( TManipulateSubType a0, zCVob* a1 )                               zInit( oCMsgManipulate_OnInit( a0, a1 ));
    oCMsgManipulate( TManipulateSubType a0, int a1 )                                  zInit( oCMsgManipulate_OnInit( a0, a1 ));
    oCMsgManipulate( TManipulateSubType a0, zSTRING const& a1, int a2 )               zInit( oCMsgManipulate_OnInit( a0, a1, a2 ));
    oCMsgManipulate( TManipulateSubType a0, zCVob* a1, int a2 )                       zInit( oCMsgManipulate_OnInit( a0, a1, a2 ));
    oCMsgManipulate( TManipulateSubType a0, zSTRING const& a1, zSTRING const& a2 )    zInit( oCMsgManipulate_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                                             zCall( 0x006BD4A0 );
    virtual zCClassDef* _GetClassDef() const                                          zCall( 0x006BD5C0 );
    virtual void Archive( zCArchiver& )                                               zCall( 0x006C1EA0 );
    virtual void Unarchive( zCArchiver& )                                             zCall( 0x006C1F80 );
    virtual ~oCMsgManipulate()                                                        zCall( 0x006C1DE0 );
    virtual int IsNetRelevant()                                                       zCall( 0x006BD5D0 );
    virtual int MD_GetNumOfSubTypes()                                                 zCall( 0x006C23A0 );
    virtual zSTRING MD_GetSubTypeString( int )                                        zCall( 0x006C23B0 );
    virtual zSTRING MD_GetVobRefName()                                                zCall( 0x006C2860 );
    virtual void MD_SetVobRefName( zSTRING const& )                                   zCall( 0x006C2910 );
    virtual void MD_SetVobParam( zCVob* )                                             zCall( 0x006C2A50 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()                       zCall( 0x006C2810 );
    virtual float MD_GetMinTime()                                                     zCall( 0x006C2850 );
    virtual void Pack( zCBuffer&, zCEventManager* )                                   zCall( 0x006C20A0 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                                 zCall( 0x006C2190 );

    // user API
    #include "oCMsgManipulate.inl"
  };

  // sizeof 98h
  class oCMsgConversation : public oCNpcMessage {
  public:
    zCLASS_DECLARATION( oCMsgConversation )

    enum TConversationSubType {
      EV_PLAYANISOUND,
      EV_PLAYANI,
      EV_PLAYSOUND,
      EV_LOOKAT,
      EV_OUTPUT,
      EV_OUTPUTSVM,
      EV_CUTSCENE,
      EV_WAITTILLEND,
      EV_ASK,
      EV_WAITFORQUESTION,
      EV_STOPLOOKAT,
      EV_STOPPOINTAT,
      EV_POINTAT,
      EV_QUICKLOOK,
      EV_PLAYANI_NOOVERLAY,
      EV_PLAYANI_FACE,
      EV_PROCESSINFOS,
      EV_STOPPROCESSINFOS,
      EV_OUTPUTSVM_OVERLAY,
      EV_CONV_MAX
    };

    zSTRING text;    // sizeof 14h    offset 44h
    zSTRING name;    // sizeof 14h    offset 58h
    zCVob* target;   // sizeof 04h    offset 6Ch
    zVEC3 targetPos; // sizeof 0Ch    offset 70h
    int ani;         // sizeof 04h    offset 7Ch
    union {
      zCModelAni* cAni;
      zCEventMessage* watchMsg;
    };

    int handle;      // sizeof 04h    offset 84h
    float timer;     // sizeof 04h    offset 88h
    int number;      // sizeof 04h    offset 8Ch
    int f_no;        // sizeof 04h    offset 90h
    int f_yes;       // sizeof 04h    offset 94h

    void oCMsgConversation_OnInit()                                                       zCall( 0x006C2A60 );
    void oCMsgConversation_OnInit( TConversationSubType )                                 zCall( 0x006C2B60 );
    void oCMsgConversation_OnInit( TConversationSubType, zSTRING const& )                 zCall( 0x006C2C40 );
    void oCMsgConversation_OnInit( TConversationSubType, zSTRING const&, zSTRING const& ) zCall( 0x006C2E30 );
    void oCMsgConversation_OnInit( TConversationSubType, zCVob* )                         zCall( 0x006C3040 );
    void oCMsgConversation_OnInit( TConversationSubType, int )                            zCall( 0x006C3120 );
    void oCMsgConversation_OnInit( TConversationSubType, int, int, float )                zCall( 0x006C3200 );
    oCMsgConversation()                                                                   zInit( oCMsgConversation_OnInit() );
    oCMsgConversation( TConversationSubType a0 )                                          zInit( oCMsgConversation_OnInit( a0 ));
    oCMsgConversation( TConversationSubType a0, zSTRING const& a1 )                       zInit( oCMsgConversation_OnInit( a0, a1 ));
    oCMsgConversation( TConversationSubType a0, zSTRING const& a1, zSTRING const& a2 )    zInit( oCMsgConversation_OnInit( a0, a1, a2 ));
    oCMsgConversation( TConversationSubType a0, zCVob* a1 )                               zInit( oCMsgConversation_OnInit( a0, a1 ));
    oCMsgConversation( TConversationSubType a0, int a1 )                                  zInit( oCMsgConversation_OnInit( a0, a1 ));
    oCMsgConversation( TConversationSubType a0, int a1, int a2, float a3 )                zInit( oCMsgConversation_OnInit( a0, a1, a2, a3 ));
    static zCObject* _CreateNewInstance()                                                 zCall( 0x006BD7E0 );
    virtual zCClassDef* _GetClassDef() const                                              zCall( 0x006BD900 );
    virtual void Archive( zCArchiver& )                                                   zCall( 0x006C33D0 );
    virtual void Unarchive( zCArchiver& )                                                 zCall( 0x006C34C0 );
    virtual ~oCMsgConversation()                                                          zCall( 0x006C3300 );
    virtual int IsOverlay()                                                               zCall( 0x006C3960 );
    virtual void Delete()                                                                 zCall( 0x006C3770 );
    virtual int MD_GetNumOfSubTypes()                                                     zCall( 0x006C3760 );
    virtual zSTRING MD_GetSubTypeString( int )                                            zCall( 0x006C39A0 );
    virtual zSTRING MD_GetVobRefName()                                                    zCall( 0x006C3B80 );
    virtual void MD_SetVobRefName( zSTRING const& )                                       zCall( 0x006C3BD0 );
    virtual void MD_SetVobParam( zCVob* )                                                 zCall( 0x006C3D10 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()                           zCall( 0x006C3D20 );
    virtual float MD_GetMinTime()                                                         zCall( 0x006C3D70 );

    // user API
    #include "oCMsgConversation.inl"
  };

  // sizeof 6Ch
  class oCMsgMagic : public oCNpcMessage {
  public:
    zCLASS_DECLARATION( oCMsgMagic )

    enum TConversationSubType {
      EV_OPEN,
      EV_CLOSE,
      EV_MOVE,
      EV_INVEST,
      EV_CAST,
      EV_SETLEVEL,
      EV_SHOWSYMBOL,
      EV_SETFRONTSPELL,
      EV_CASTSPELL,
      EV_READY,
      EV_UNREADY,
      EV_MAGIC_MAX
    };

    int what;         // sizeof 04h    offset 44h
    int level;        // sizeof 04h    offset 48h
    int removeSymbol; // sizeof 04h    offset 4Ch
    int manaInvested; // sizeof 04h    offset 50h
    int energyLeft;   // sizeof 04h    offset 54h
    zCVob* target;    // sizeof 04h    offset 58h
    zVEC3 targetPos;  // sizeof 0Ch    offset 5Ch
    int activeSpell;  // sizeof 04h    offset 68h

    void oCMsgMagic_OnInit()                                            zCall( 0x006C3E50 );
    void oCMsgMagic_OnInit( TConversationSubType )                      zCall( 0x006C3F20 );
    void oCMsgMagic_OnInit( TConversationSubType, int, int )            zCall( 0x006C3FD0 );
    oCMsgMagic()                                                        zInit( oCMsgMagic_OnInit() );
    oCMsgMagic( TConversationSubType a0 )                               zInit( oCMsgMagic_OnInit( a0 ));
    oCMsgMagic( TConversationSubType a0, int a1, int a2 )               zInit( oCMsgMagic_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                               zCall( 0x006BDAF0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006BDBE0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006C4440 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006C44E0 );
    virtual ~oCMsgMagic()                                               zCall( 0x006C4080 );
    virtual int IsNetRelevant()                                         zCall( 0x006BDC10 );
    virtual int IsHighPriority()                                        zCall( 0x006BDC00 );
    virtual int IsJob()                                                 zCall( 0x006BDBF0 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x006C4240 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x006C4250 );
    virtual void Pack( zCBuffer&, zCEventManager* )                     zCall( 0x006C40E0 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                   zCall( 0x006C4180 );

    // user API
    #include "oCMsgMagic.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ONPC_MESSAGES_H__VER0__