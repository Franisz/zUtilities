// Supported with union (c) 2018 Union team

#ifndef __ONPC_MESSAGES_H__VER1__
#define __ONPC_MESSAGES_H__VER1__

#include "zVob.h"
#include "zBuffer.h"
#include "zSound.h"
#include "zModel.h"
#include "oNpc.h"

namespace Gothic_I_Addon {

  class oCNpcMessage : public zCEventMessage {
  public:
    zCLASS_DECLARATION( oCNpcMessage )

    zSTRING targetVobName;
    int highPriority;
    int deleted;
    int inUse;

    void oCNpcMessage_OnInit()                                          zCall( 0x006F2F60 );
    oCNpcMessage()                                                      zInit( oCNpcMessage_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x006F0F80 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006F10A0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006F30B0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006F3110 );
    virtual ~oCNpcMessage()                                             zCall( 0x006F3040 );
    virtual int IsOverlay()                                             zCall( 0x006F10F0 );
    virtual int IsHighPriority()                                        zCall( 0x006F1130 );
    virtual int IsJob()                                                 zCall( 0x006F1100 );
    virtual void Delete()                                               zCall( 0x006F10B0 );
    virtual int IsDeleteable()                                          zCall( 0x006F1120 );
    virtual int IsDeleted()                                             zCall( 0x006F1110 );
    virtual void SetInUse( int )                                        zCall( 0x006F10C0 );
    virtual int IsInUse()                                               zCall( 0x006F10D0 );
    virtual void SetHighPriority( int )                                 zCall( 0x006F10E0 );

    // user API
    #include "oCNpcMessage.inl"
  };

  class oCMsgDamage : public oCNpcMessage {
  public:
    zCLASS_DECLARATION( oCMsgDamage )

    enum TDamageSubType {
      EV_DAMAGE_ONCE,
      EV_DAMAGE_PER_FRAME,
      EV_DAMAGE_MAX
    };

    oCNpc::oSDamageDescriptor descDamage;

    void oCMsgDamage_OnInit()                                                   zCall( 0x006F3190 );
    void oCMsgDamage_OnInit( TDamageSubType )                                   zCall( 0x006F3290 );
    void oCMsgDamage_OnInit( TDamageSubType, oCNpc::oSDamageDescriptor const& ) zCall( 0x006F3370 );
    oCMsgDamage()                                                               zInit( oCMsgDamage_OnInit() );
    oCMsgDamage( TDamageSubType a0 )                                            zInit( oCMsgDamage_OnInit( a0 ));
    oCMsgDamage( TDamageSubType a0, oCNpc::oSDamageDescriptor const& a1 )       zInit( oCMsgDamage_OnInit( a0, a1 ));
    static zCObject* _CreateNewInstance()                                       zCall( 0x006F1340 );
    virtual zCClassDef* _GetClassDef() const                                    zCall( 0x006F1470 );
    virtual void Archive( zCArchiver& )                                         zCall( 0x006F36E0 );
    virtual void Unarchive( zCArchiver& )                                       zCall( 0x006F3750 );
    virtual ~oCMsgDamage()                                                      zCall( 0x006F3460 );
    virtual int IsOverlay()                                                     zCall( 0x006F1490 );
    virtual int IsNetRelevant()                                                 zCall( 0x006F1480 );
    virtual int IsHighPriority()                                                zCall( 0x006F14B0 );
    virtual int IsDeleteable()                                                  zCall( 0x006F14A0 );
    virtual int MD_GetNumOfSubTypes()                                           zCall( 0x006F3560 );
    virtual zSTRING MD_GetSubTypeString( int )                                  zCall( 0x006F3570 );
    virtual void Pack( zCBuffer&, zCEventManager* )                             zCall( 0x006F36C0 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                           zCall( 0x006F36D0 );

    // user API
    #include "oCMsgDamage.inl"
  };

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

    int targetMode;
    int duringRun       : 1;
    int initDone        : 1;
    int firstTime       : 1;
    int useFist         : 1;
    int showMagicCircle : 1;
    int ani;

    void oCMsgWeapon_OnInit()                                           zCall( 0x006F48A0 );
    void oCMsgWeapon_OnInit( TWeaponSubType, int, int )                 zCall( 0x006F4970 );
    oCMsgWeapon()                                                       zInit( oCMsgWeapon_OnInit() );
    oCMsgWeapon( TWeaponSubType a0, int a1, int a2 )                    zInit( oCMsgWeapon_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                               zCall( 0x006F16C0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006F17D0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006F4A50 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006F4B10 );
    virtual ~oCMsgWeapon()                                              zCall( 0x006F1810 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x006F4C20 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x006F4C30 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()         zCall( 0x006F5040 );
    virtual float MD_GetMinTime()                                       zCall( 0x006F5050 );

    // user API
    #include "oCMsgWeapon.inl"
  };

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

    zSTRING targetName;
    zCRoute* route;
    zCVob* targetVob;
    zVEC3 targetPos;
    float angle;
    float timer;
    int targetMode;
    int ani;

    void oCMsgMovement_OnInit()                                              zCall( 0x006F37E0 );
    void oCMsgMovement_OnInit( TMovementSubType, zSTRING const& )            zCall( 0x006F38E0 );
    void oCMsgMovement_OnInit( TMovementSubType, zCVob* )                    zCall( 0x006F3AC0 );
    void oCMsgMovement_OnInit( TMovementSubType, zVEC3 const& )              zCall( 0x006F3BD0 );
    void oCMsgMovement_OnInit( TMovementSubType, float )                     zCall( 0x006F3CC0 );
    void oCMsgMovement_OnInit( TMovementSubType, int )                       zCall( 0x006F3DA0 );
    oCMsgMovement()                                                          zInit( oCMsgMovement_OnInit() );
    oCMsgMovement( TMovementSubType a0, zSTRING const& a1 )                  zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, zCVob* a1 )                          zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, zVEC3 const& a1 )                    zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, float a1 )                           zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, int a1 )                             zInit( oCMsgMovement_OnInit( a0, a1 ));
    void Init()                                                              zCall( 0x006F3F70 );
    static zCObject* _CreateNewInstance()                                    zCall( 0x006F1A80 );
    virtual zCClassDef* _GetClassDef() const                                 zCall( 0x006F1BA0 );
    virtual void Archive( zCArchiver& )                                      zCall( 0x006F3FB0 );
    virtual void Unarchive( zCArchiver& )                                    zCall( 0x006F40C0 );
    virtual ~oCMsgMovement()                                                 zCall( 0x006F3E80 );
    virtual void Delete()                                                    zCall( 0x006F4830 );
    virtual int MD_GetNumOfSubTypes()                                        zCall( 0x006F4210 );
    virtual zSTRING MD_GetSubTypeString( int )                               zCall( 0x006F4220 );
    virtual zSTRING MD_GetVobRefName()                                       zCall( 0x006F4670 );
    virtual void MD_SetVobRefName( zSTRING const& )                          zCall( 0x006F46E0 );
    virtual void MD_SetVobParam( zCVob* )                                    zCall( 0x006F4820 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()              zCall( 0x006F4840 );
    virtual float MD_GetMinTime()                                            zCall( 0x006F4890 );

    // user API
    #include "oCMsgMovement.inl"
  };

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
      EV_ATTACKASSASSIN,
      EV_ATTACK_MAX
    };

    int combo;
    zCVob* target;
    int hitAni;
    int victAni;
    float startFrame;
    int enableNextHit : 1;
    int reachedTarget : 1;

    void oCMsgAttack_OnInit()                                                zCall( 0x006F5060 );
    void oCMsgAttack_OnInit( TAttackSubType, int, int )                      zCall( 0x006F51D0 );
    void oCMsgAttack_OnInit( TAttackSubType, zCVob*, float )                 zCall( 0x006F52A0 );
    oCMsgAttack()                                                            zInit( oCMsgAttack_OnInit() );
    oCMsgAttack( TAttackSubType a0, int a1, int a2 )                         zInit( oCMsgAttack_OnInit( a0, a1, a2 ));
    oCMsgAttack( TAttackSubType a0, zCVob* a1, float a2 )                    zInit( oCMsgAttack_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                                    zCall( 0x006F1DB0 );
    virtual zCClassDef* _GetClassDef() const                                 zCall( 0x006F1ED0 );
    virtual void Archive( zCArchiver& )                                      zCall( 0x006F5380 );
    virtual void Unarchive( zCArchiver& )                                    zCall( 0x006F5410 );
    virtual ~oCMsgAttack()                                                   zCall( 0x006F5160 );
    virtual int IsOverlay()                                                  zCall( 0x006F1EF0 );
    virtual int IsNetRelevant()                                              zCall( 0x006F1EE0 );
    virtual int MD_GetNumOfSubTypes()                                        zCall( 0x006F5810 );
    virtual zSTRING MD_GetSubTypeString( int )                               zCall( 0x006F5820 );
    virtual void Pack( zCBuffer&, zCEventManager* )                          zCall( 0x006F54D0 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                        zCall( 0x006F5680 );

    // user API
    #include "oCMsgAttack.inl"
  };

  class oCMsgUseItem : public oCNpcMessage {
  public:
    zCLASS_DECLARATION( oCMsgUseItem )

    enum TUseItemSubType {
      EV_DRINK,
      EV_EQUIPITEM,
      EV_UNEQUIPITEM,
      EV_USEITEM_MAX
    };

    zCVob* vob;
    int ani;
    int state;

    void oCMsgUseItem_OnInit()                                          zCall( 0x006F5BC0 );
    void oCMsgUseItem_OnInit( TUseItemSubType, zCVob* )                 zCall( 0x006F5CB0 );
    oCMsgUseItem()                                                      zInit( oCMsgUseItem_OnInit() );
    oCMsgUseItem( TUseItemSubType a0, zCVob* a1 )                       zInit( oCMsgUseItem_OnInit( a0, a1 ));
    static zCObject* _CreateNewInstance()                               zCall( 0x006F2110 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006F2240 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006F5E90 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006F5F00 );
    virtual ~oCMsgUseItem()                                             zCall( 0x006F5D80 );
    virtual int IsNetRelevant()                                         zCall( 0x006F2250 );
    virtual void Pack( zCBuffer&, zCEventManager* )                     zCall( 0x006F5DF0 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                   zCall( 0x006F5E40 );

    // user API
    #include "oCMsgUseItem.inl"
  };

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

    int function;
    int minutes;
    int instance;
    zSTRING wp;
    float timer;
    oCNpc* other;
    oCNpc* victim;
    int endOldState : 1;
    int inRoutine   : 1;

    void oCMsgState_OnInit()                                            zCall( 0x006F5F90 );
    void oCMsgState_OnInit( TStateSubType, float )                      zCall( 0x006F60A0 );
    void oCMsgState_OnInit( TStateSubType, int )                        zCall( 0x006F6180 );
    void oCMsgState_OnInit( TStateSubType, int, int, zSTRING const& )   zCall( 0x006F6260 );
    oCMsgState()                                                        zInit( oCMsgState_OnInit() );
    oCMsgState( TStateSubType a0, float a1 )                            zInit( oCMsgState_OnInit( a0, a1 ));
    oCMsgState( TStateSubType a0, int a1 )                              zInit( oCMsgState_OnInit( a0, a1 ));
    oCMsgState( TStateSubType a0, int a1, int a2, zSTRING const& a3 )   zInit( oCMsgState_OnInit( a0, a1, a2, a3 ));
    static zCObject* _CreateNewInstance()                               zCall( 0x006F2460 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006F2580 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006F64F0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006F6590 );
    virtual ~oCMsgState()                                               zCall( 0x006F6440 );
    virtual int IsOverlay()                                             zCall( 0x006F2590 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x006F6650 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x006F6660 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()         zCall( 0x006F68B0 );
    virtual float MD_GetMinTime()                                       zCall( 0x006F68C0 );

    // user API
    #include "oCMsgState.inl"
  };

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
      EV_MANIP_MAX,
      EV_PUTINSLOT,
      EV_REMFROMSLOT
    };

    zSTRING name;
    zSTRING slot;
    zCVob* targetVob;
    int flag;
    float aniCombY;
    union {
      int npcSlot;
      int targetState;
      int aniID;
    };

    void oCMsgManipulate_OnInit()                                                     zCall( 0x006F6900 );
    void oCMsgManipulate_OnInit( TManipulateSubType )                                 zCall( 0x006F6A00 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zCVob* )                         zCall( 0x006F6AD0 );
    void oCMsgManipulate_OnInit( TManipulateSubType, int )                            zCall( 0x006F6BA0 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zSTRING const&, int )            zCall( 0x006F6C70 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zCVob*, int )                    zCall( 0x006F6E50 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zSTRING const&, zSTRING const& ) zCall( 0x006F6F20 );
    oCMsgManipulate()                                                                 zInit( oCMsgManipulate_OnInit() );
    oCMsgManipulate( TManipulateSubType a0 )                                          zInit( oCMsgManipulate_OnInit( a0 ));
    oCMsgManipulate( TManipulateSubType a0, zCVob* a1 )                               zInit( oCMsgManipulate_OnInit( a0, a1 ));
    oCMsgManipulate( TManipulateSubType a0, int a1 )                                  zInit( oCMsgManipulate_OnInit( a0, a1 ));
    oCMsgManipulate( TManipulateSubType a0, zSTRING const& a1, int a2 )               zInit( oCMsgManipulate_OnInit( a0, a1, a2 ));
    oCMsgManipulate( TManipulateSubType a0, zCVob* a1, int a2 )                       zInit( oCMsgManipulate_OnInit( a0, a1, a2 ));
    oCMsgManipulate( TManipulateSubType a0, zSTRING const& a1, zSTRING const& a2 )    zInit( oCMsgManipulate_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                                             zCall( 0x006F27A0 );
    virtual zCClassDef* _GetClassDef() const                                          zCall( 0x006F28C0 );
    virtual void Archive( zCArchiver& )                                               zCall( 0x006F7210 );
    virtual void Unarchive( zCArchiver& )                                             zCall( 0x006F72E0 );
    virtual ~oCMsgManipulate()                                                        zCall( 0x006F7120 );
    virtual int IsNetRelevant()                                                       zCall( 0x006F28D0 );
    virtual int MD_GetNumOfSubTypes()                                                 zCall( 0x006F7700 );
    virtual zSTRING MD_GetSubTypeString( int )                                        zCall( 0x006F7710 );
    virtual zSTRING MD_GetVobRefName()                                                zCall( 0x006F7C40 );
    virtual void MD_SetVobRefName( zSTRING const& )                                   zCall( 0x006F7D00 );
    virtual void MD_SetVobParam( zCVob* )                                             zCall( 0x006F7E40 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()                       zCall( 0x006F7BE0 );
    virtual float MD_GetMinTime()                                                     zCall( 0x006F7C30 );
    virtual void Pack( zCBuffer&, zCEventManager* )                                   zCall( 0x006F73D0 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                                 zCall( 0x006F74D0 );

    // user API
    #include "oCMsgManipulate.inl"
  };

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
      EV_PRINTSCREEN,
      EV_SNDPLAY,
      EV_SNDPLAY3D,
      EV_CONV_MAX
    };

    zSTRING text;
    zSTRING name;
    zCVob* target;
    zVEC3 targetPos;
    int ani;
    union {
      zCModelAni* cAni;
      zCEventMessage* watchMsg;
    };

    int handle;
    float timer;
    int number;
    int f_no;
    int f_yes;

    void oCMsgConversation_OnInit()                                                       zCall( 0x006F7E50 );
    void oCMsgConversation_OnInit( TConversationSubType )                                 zCall( 0x006F7F60 );
    void oCMsgConversation_OnInit( TConversationSubType, zSTRING const& )                 zCall( 0x006F8040 );
    void oCMsgConversation_OnInit( TConversationSubType, zSTRING const&, zSTRING const& ) zCall( 0x006F8250 );
    void oCMsgConversation_OnInit( TConversationSubType, zCVob* )                         zCall( 0x006F8480 );
    void oCMsgConversation_OnInit( TConversationSubType, int )                            zCall( 0x006F8560 );
    void oCMsgConversation_OnInit( TConversationSubType, int, int, float )                zCall( 0x006F8640 );
    oCMsgConversation()                                                                   zInit( oCMsgConversation_OnInit() );
    oCMsgConversation( TConversationSubType a0 )                                          zInit( oCMsgConversation_OnInit( a0 ));
    oCMsgConversation( TConversationSubType a0, zSTRING const& a1 )                       zInit( oCMsgConversation_OnInit( a0, a1 ));
    oCMsgConversation( TConversationSubType a0, zSTRING const& a1, zSTRING const& a2 )    zInit( oCMsgConversation_OnInit( a0, a1, a2 ));
    oCMsgConversation( TConversationSubType a0, zCVob* a1 )                               zInit( oCMsgConversation_OnInit( a0, a1 ));
    oCMsgConversation( TConversationSubType a0, int a1 )                                  zInit( oCMsgConversation_OnInit( a0, a1 ));
    oCMsgConversation( TConversationSubType a0, int a1, int a2, float a3 )                zInit( oCMsgConversation_OnInit( a0, a1, a2, a3 ));
    static zCObject* _CreateNewInstance()                                                 zCall( 0x006F2AF0 );
    virtual zCClassDef* _GetClassDef() const                                              zCall( 0x006F2C20 );
    virtual void Archive( zCArchiver& )                                                   zCall( 0x006F8830 );
    virtual void Unarchive( zCArchiver& )                                                 zCall( 0x006F8910 );
    virtual ~oCMsgConversation()                                                          zCall( 0x006F8740 );
    virtual int IsOverlay()                                                               zCall( 0x006F8D90 );
    virtual void Delete()                                                                 zCall( 0x006F8B80 );
    virtual int MD_GetNumOfSubTypes()                                                     zCall( 0x006F8B70 );
    virtual zSTRING MD_GetSubTypeString( int )                                            zCall( 0x006F8DE0 );
    virtual zSTRING MD_GetVobRefName()                                                    zCall( 0x006F8FF0 );
    virtual void MD_SetVobRefName( zSTRING const& )                                       zCall( 0x006F9040 );
    virtual void MD_SetVobParam( zCVob* )                                                 zCall( 0x006F9180 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()                           zCall( 0x006F9190 );
    virtual float MD_GetMinTime()                                                         zCall( 0x006F91E0 );

    // user API
    #include "oCMsgConversation.inl"
  };

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

    int what;
    int level;
    int removeSymbol;
    int manaInvested;
    int energyLeft;
    zCVob* target;
    zVEC3 targetPos;
    int activeSpell;

    void oCMsgMagic_OnInit()                                            zCall( 0x006F92D0 );
    void oCMsgMagic_OnInit( TConversationSubType )                      zCall( 0x006F93A0 );
    void oCMsgMagic_OnInit( TConversationSubType, int, int )            zCall( 0x006F9450 );
    oCMsgMagic()                                                        zInit( oCMsgMagic_OnInit() );
    oCMsgMagic( TConversationSubType a0 )                               zInit( oCMsgMagic_OnInit( a0 ));
    oCMsgMagic( TConversationSubType a0, int a1, int a2 )               zInit( oCMsgMagic_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                               zCall( 0x006F2E30 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006F2F20 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006F98D0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006F9960 );
    virtual ~oCMsgMagic()                                               zCall( 0x006F9500 );
    virtual int IsNetRelevant()                                         zCall( 0x006F2F50 );
    virtual int IsHighPriority()                                        zCall( 0x006F2F40 );
    virtual int IsJob()                                                 zCall( 0x006F2F30 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x006F96D0 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x006F96E0 );
    virtual void Pack( zCBuffer&, zCEventManager* )                     zCall( 0x006F9570 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                   zCall( 0x006F9610 );

    // user API
    #include "oCMsgMagic.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ONPC_MESSAGES_H__VER1__