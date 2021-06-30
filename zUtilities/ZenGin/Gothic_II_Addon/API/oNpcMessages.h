// Supported with union (c) 2018 Union team

#ifndef __ONPC_MESSAGES_H__VER3__
#define __ONPC_MESSAGES_H__VER3__

#include "zVob.h"
#include "zBuffer.h"
#include "zSound.h"
#include "zModel.h"
#include "oNpc.h"

namespace Gothic_II_Addon {

  class oCNpcMessage : public zCEventMessage {
  public:
    zCLASS_DECLARATION( oCNpcMessage )

    zSTRING targetVobName;
    int highPriority : 1;
    int deleted      : 1;
    int inUse        : 1;

    void oCNpcMessage_OnInit()               zCall( 0x00764DC0 );
    oCNpcMessage()                           zInit( oCNpcMessage_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x00762FF0 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x007630F0 );
    virtual void Archive( zCArchiver& )      zCall( 0x00764F00 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00764F70 );
    virtual ~oCNpcMessage()                  zCall( 0x00764EA0 );
    virtual int IsOverlay()                  zCall( 0x00763170 );
    virtual int IsHighPriority()             zCall( 0x007631B0 );
    virtual int IsJob()                      zCall( 0x00763180 );
    virtual int GetIgnoreCutsceneMode()      zCall( 0x00763160 );
    virtual void Delete()                    zCall( 0x00763100 );
    virtual int IsDeleteable()               zCall( 0x007631A0 );
    virtual int IsDeleted()                  zCall( 0x00763190 );
    virtual void SetInUse( int )             zCall( 0x00763110 );
    virtual int IsInUse()                    zCall( 0x00763130 );
    virtual void SetHighPriority( int )      zCall( 0x00763140 );

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

    void oCMsgDamage_OnInit()                                                   zCall( 0x00765010 );
    void oCMsgDamage_OnInit( TDamageSubType )                                   zCall( 0x00765110 );
    void oCMsgDamage_OnInit( TDamageSubType, oCNpc::oSDamageDescriptor const& ) zCall( 0x007651E0 );
    oCMsgDamage()                                                               zInit( oCMsgDamage_OnInit() );
    oCMsgDamage( TDamageSubType a0 )                                            zInit( oCMsgDamage_OnInit( a0 ));
    oCMsgDamage( TDamageSubType a0, oCNpc::oSDamageDescriptor const& a1 )       zInit( oCMsgDamage_OnInit( a0, a1 ));
    static zCObject* _CreateNewInstance()                                       zCall( 0x007633B0 );
    virtual zCClassDef* _GetClassDef() const                                    zCall( 0x007634B0 );
    virtual void Archive( zCArchiver& )                                         zCall( 0x00765510 );
    virtual void Unarchive( zCArchiver& )                                       zCall( 0x00765590 );
    virtual ~oCMsgDamage()                                                      zCall( 0x007652D0 );
    virtual int IsOverlay()                                                     zCall( 0x007634D0 );
    virtual int IsNetRelevant()                                                 zCall( 0x007634C0 );
    virtual int IsHighPriority()                                                zCall( 0x007634F0 );
    virtual int IsDeleteable()                                                  zCall( 0x007634E0 );
    virtual int MD_GetNumOfSubTypes()                                           zCall( 0x007653B0 );
    virtual zSTRING MD_GetSubTypeString( int )                                  zCall( 0x007653C0 );
    virtual void Pack( zCBuffer&, zCEventManager* )                             zCall( 0x007654F0 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                           zCall( 0x00765500 );

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

    void oCMsgWeapon_OnInit()                                   zCall( 0x00766710 );
    void oCMsgWeapon_OnInit( TWeaponSubType, int, int )         zCall( 0x007667D0 );
    oCMsgWeapon()                                               zInit( oCMsgWeapon_OnInit() );
    oCMsgWeapon( TWeaponSubType a0, int a1, int a2 )            zInit( oCMsgWeapon_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                       zCall( 0x007636E0 );
    virtual zCClassDef* _GetClassDef() const                    zCall( 0x007637D0 );
    virtual void Archive( zCArchiver& )                         zCall( 0x007668B0 );
    virtual void Unarchive( zCArchiver& )                       zCall( 0x00766980 );
    virtual ~oCMsgWeapon()                                      zCall( 0x00763810 );
    virtual int MD_GetNumOfSubTypes()                           zCall( 0x00766AC0 );
    virtual zSTRING MD_GetSubTypeString( int )                  zCall( 0x00766AD0 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior() zCall( 0x00766EE0 );
    virtual float MD_GetMinTime()                               zCall( 0x00766EF0 );

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

    void oCMsgMovement_OnInit()                                   zCall( 0x00765650 );
    void oCMsgMovement_OnInit( TMovementSubType, zSTRING const& ) zCall( 0x00765750 );
    void oCMsgMovement_OnInit( TMovementSubType, zCVob* )         zCall( 0x00765930 );
    void oCMsgMovement_OnInit( TMovementSubType, zVEC3 const& )   zCall( 0x00765A30 );
    void oCMsgMovement_OnInit( TMovementSubType, float )          zCall( 0x00765B20 );
    void oCMsgMovement_OnInit( TMovementSubType, int )            zCall( 0x00765C00 );
    oCMsgMovement()                                               zInit( oCMsgMovement_OnInit() );
    oCMsgMovement( TMovementSubType a0, zSTRING const& a1 )       zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, zCVob* a1 )               zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, zVEC3 const& a1 )         zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, float a1 )                zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, int a1 )                  zInit( oCMsgMovement_OnInit( a0, a1 ));
    void Init()                                                   zCall( 0x00765DC0 );
    static zCObject* _CreateNewInstance()                         zCall( 0x00763A50 );
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x00763B50 );
    virtual void Archive( zCArchiver& )                           zCall( 0x00765E00 );
    virtual void Unarchive( zCArchiver& )                         zCall( 0x00765F20 );
    virtual ~oCMsgMovement()                                      zCall( 0x00765CE0 );
    virtual void Delete()                                         zCall( 0x007666B0 );
    virtual int MD_GetNumOfSubTypes()                             zCall( 0x00766090 );
    virtual zSTRING MD_GetSubTypeString( int )                    zCall( 0x007660A0 );
    virtual zSTRING MD_GetVobRefName()                            zCall( 0x007664E0 );
    virtual void MD_SetVobRefName( zSTRING const& )               zCall( 0x00766560 );
    virtual void MD_SetVobParam( zCVob* )                         zCall( 0x007666A0 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()   zCall( 0x007666C0 );
    virtual float MD_GetMinTime()                                 zCall( 0x00766700 );

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
      EV_ATTACK_MAX
    };

    int combo;
    zCVob* target;
    int hitAni;
    float startFrame;
    int enableNextHit : 1;
    int reachedTarget : 1;

    void oCMsgAttack_OnInit()                                zCall( 0x00766F00 );
    void oCMsgAttack_OnInit( TAttackSubType, int, int )      zCall( 0x00767060 );
    void oCMsgAttack_OnInit( TAttackSubType, zCVob*, float ) zCall( 0x00767130 );
    oCMsgAttack()                                            zInit( oCMsgAttack_OnInit() );
    oCMsgAttack( TAttackSubType a0, int a1, int a2 )         zInit( oCMsgAttack_OnInit( a0, a1, a2 ));
    oCMsgAttack( TAttackSubType a0, zCVob* a1, float a2 )    zInit( oCMsgAttack_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                    zCall( 0x00763D40 );
    virtual zCClassDef* _GetClassDef() const                 zCall( 0x00763E40 );
    virtual void Archive( zCArchiver& )                      zCall( 0x00767210 );
    virtual void Unarchive( zCArchiver& )                    zCall( 0x007672B0 );
    virtual ~oCMsgAttack()                                   zCall( 0x00767000 );
    virtual int IsOverlay()                                  zCall( 0x00763E60 );
    virtual int IsNetRelevant()                              zCall( 0x00763E50 );
    virtual int MD_GetNumOfSubTypes()                        zCall( 0x007676A0 );
    virtual zSTRING MD_GetSubTypeString( int )               zCall( 0x007676B0 );
    virtual void Pack( zCBuffer&, zCEventManager* )          zCall( 0x007673A0 );
    virtual void Unpack( zCBuffer&, zCEventManager* )        zCall( 0x00767530 );

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

    void oCMsgUseItem_OnInit()                          zCall( 0x00767A20 );
    void oCMsgUseItem_OnInit( TUseItemSubType, zCVob* ) zCall( 0x00767B10 );
    oCMsgUseItem()                                      zInit( oCMsgUseItem_OnInit() );
    oCMsgUseItem( TUseItemSubType a0, zCVob* a1 )       zInit( oCMsgUseItem_OnInit( a0, a1 ));
    static zCObject* _CreateNewInstance()               zCall( 0x00764060 );
    virtual zCClassDef* _GetClassDef() const            zCall( 0x00764170 );
    virtual void Archive( zCArchiver& )                 zCall( 0x00767CD0 );
    virtual void Unarchive( zCArchiver& )               zCall( 0x00767D50 );
    virtual ~oCMsgUseItem()                             zCall( 0x00767BD0 );
    virtual int IsNetRelevant()                         zCall( 0x00764180 );
    virtual void Pack( zCBuffer&, zCEventManager* )     zCall( 0x00767C30 );
    virtual void Unpack( zCBuffer&, zCEventManager* )   zCall( 0x00767C80 );

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

    void oCMsgState_OnInit()                                          zCall( 0x00767E00 );
    void oCMsgState_OnInit( TStateSubType, float )                    zCall( 0x00767F00 );
    void oCMsgState_OnInit( TStateSubType, int )                      zCall( 0x00767FE0 );
    void oCMsgState_OnInit( TStateSubType, int, int, zSTRING const& ) zCall( 0x007680C0 );
    oCMsgState()                                                      zInit( oCMsgState_OnInit() );
    oCMsgState( TStateSubType a0, float a1 )                          zInit( oCMsgState_OnInit( a0, a1 ));
    oCMsgState( TStateSubType a0, int a1 )                            zInit( oCMsgState_OnInit( a0, a1 ));
    oCMsgState( TStateSubType a0, int a1, int a2, zSTRING const& a3 ) zInit( oCMsgState_OnInit( a0, a1, a2, a3 ));
    static zCObject* _CreateNewInstance()                             zCall( 0x00764370 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x00764470 );
    virtual void Archive( zCArchiver& )                               zCall( 0x00768340 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x007683F0 );
    virtual ~oCMsgState()                                             zCall( 0x007682B0 );
    virtual int IsOverlay()                                           zCall( 0x00764480 );
    virtual int MD_GetNumOfSubTypes()                                 zCall( 0x007684E0 );
    virtual zSTRING MD_GetSubTypeString( int )                        zCall( 0x007684F0 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()       zCall( 0x00768720 );
    virtual float MD_GetMinTime()                                     zCall( 0x00768730 );

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
      EV_MANIP_MAX
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

    void oCMsgManipulate_OnInit()                                                     zCall( 0x00768770 );
    void oCMsgManipulate_OnInit( TManipulateSubType )                                 zCall( 0x00768870 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zCVob* )                         zCall( 0x00768940 );
    void oCMsgManipulate_OnInit( TManipulateSubType, int )                            zCall( 0x00768A10 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zSTRING const&, int )            zCall( 0x00768AE0 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zCVob*, int )                    zCall( 0x00768CB0 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zSTRING const&, zSTRING const& ) zCall( 0x00768D80 );
    oCMsgManipulate()                                                                 zInit( oCMsgManipulate_OnInit() );
    oCMsgManipulate( TManipulateSubType a0 )                                          zInit( oCMsgManipulate_OnInit( a0 ));
    oCMsgManipulate( TManipulateSubType a0, zCVob* a1 )                               zInit( oCMsgManipulate_OnInit( a0, a1 ));
    oCMsgManipulate( TManipulateSubType a0, int a1 )                                  zInit( oCMsgManipulate_OnInit( a0, a1 ));
    oCMsgManipulate( TManipulateSubType a0, zSTRING const& a1, int a2 )               zInit( oCMsgManipulate_OnInit( a0, a1, a2 ));
    oCMsgManipulate( TManipulateSubType a0, zCVob* a1, int a2 )                       zInit( oCMsgManipulate_OnInit( a0, a1, a2 ));
    oCMsgManipulate( TManipulateSubType a0, zSTRING const& a1, zSTRING const& a2 )    zInit( oCMsgManipulate_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                                             zCall( 0x00764680 );
    virtual zCClassDef* _GetClassDef() const                                          zCall( 0x00764780 );
    virtual void Archive( zCArchiver& )                                               zCall( 0x00769040 );
    virtual void Unarchive( zCArchiver& )                                             zCall( 0x00769120 );
    virtual ~oCMsgManipulate()                                                        zCall( 0x00768F80 );
    virtual int IsNetRelevant()                                                       zCall( 0x00764790 );
    virtual int MD_GetNumOfSubTypes()                                                 zCall( 0x00769540 );
    virtual zSTRING MD_GetSubTypeString( int )                                        zCall( 0x00769550 );
    virtual zSTRING MD_GetVobRefName()                                                zCall( 0x00769A00 );
    virtual void MD_SetVobRefName( zSTRING const& )                                   zCall( 0x00769AB0 );
    virtual void MD_SetVobParam( zCVob* )                                             zCall( 0x00769BF0 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()                       zCall( 0x007699B0 );
    virtual float MD_GetMinTime()                                                     zCall( 0x007699F0 );
    virtual void Pack( zCBuffer&, zCEventManager* )                                   zCall( 0x00769240 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                                 zCall( 0x00769330 );

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
      EV_SNDPLAY,
      EV_SNDPLAY3D,
      EV_PRINTSCREEN,
      EV_STARTFX,
      EV_STOPFX,
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

    void oCMsgConversation_OnInit()                                                       zCall( 0x00769C00 );
    void oCMsgConversation_OnInit( TConversationSubType )                                 zCall( 0x00769D00 );
    void oCMsgConversation_OnInit( TConversationSubType, zSTRING const& )                 zCall( 0x00769DE0 );
    void oCMsgConversation_OnInit( TConversationSubType, zSTRING const&, zSTRING const& ) zCall( 0x00769FD0 );
    void oCMsgConversation_OnInit( TConversationSubType, zCVob* )                         zCall( 0x0076A1E0 );
    void oCMsgConversation_OnInit( TConversationSubType, int )                            zCall( 0x0076A2C0 );
    void oCMsgConversation_OnInit( TConversationSubType, int, int, float )                zCall( 0x0076A3A0 );
    oCMsgConversation()                                                                   zInit( oCMsgConversation_OnInit() );
    oCMsgConversation( TConversationSubType a0 )                                          zInit( oCMsgConversation_OnInit( a0 ));
    oCMsgConversation( TConversationSubType a0, zSTRING const& a1 )                       zInit( oCMsgConversation_OnInit( a0, a1 ));
    oCMsgConversation( TConversationSubType a0, zSTRING const& a1, zSTRING const& a2 )    zInit( oCMsgConversation_OnInit( a0, a1, a2 ));
    oCMsgConversation( TConversationSubType a0, zCVob* a1 )                               zInit( oCMsgConversation_OnInit( a0, a1 ));
    oCMsgConversation( TConversationSubType a0, int a1 )                                  zInit( oCMsgConversation_OnInit( a0, a1 ));
    oCMsgConversation( TConversationSubType a0, int a1, int a2, float a3 )                zInit( oCMsgConversation_OnInit( a0, a1, a2, a3 ));
    static zCObject* _CreateNewInstance()                                                 zCall( 0x007649A0 );
    virtual zCClassDef* _GetClassDef() const                                              zCall( 0x00764AB0 );
    virtual void Archive( zCArchiver& )                                                   zCall( 0x0076A570 );
    virtual void Unarchive( zCArchiver& )                                                 zCall( 0x0076A660 );
    virtual ~oCMsgConversation()                                                          zCall( 0x0076A4A0 );
    virtual int IsOverlay()                                                               zCall( 0x0076AB00 );
    virtual void Delete()                                                                 zCall( 0x0076A910 );
    virtual int MD_GetNumOfSubTypes()                                                     zCall( 0x0076A900 );
    virtual zSTRING MD_GetSubTypeString( int )                                            zCall( 0x0076AB60 );
    virtual zSTRING MD_GetVobRefName()                                                    zCall( 0x0076AD60 );
    virtual void MD_SetVobRefName( zSTRING const& )                                       zCall( 0x0076ADB0 );
    virtual void MD_SetVobParam( zCVob* )                                                 zCall( 0x0076AEF0 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()                           zCall( 0x0076AF00 );
    virtual float MD_GetMinTime()                                                         zCall( 0x0076AF50 );

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

    void oCMsgMagic_OnInit()                                 zCall( 0x0076B030 );
    void oCMsgMagic_OnInit( TConversationSubType )           zCall( 0x0076B100 );
    void oCMsgMagic_OnInit( TConversationSubType, int, int ) zCall( 0x0076B1B0 );
    oCMsgMagic()                                             zInit( oCMsgMagic_OnInit() );
    oCMsgMagic( TConversationSubType a0 )                    zInit( oCMsgMagic_OnInit( a0 ));
    oCMsgMagic( TConversationSubType a0, int a1, int a2 )    zInit( oCMsgMagic_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                    zCall( 0x00764CB0 );
    virtual zCClassDef* _GetClassDef() const                 zCall( 0x00764D80 );
    virtual void Archive( zCArchiver& )                      zCall( 0x0076B5E0 );
    virtual void Unarchive( zCArchiver& )                    zCall( 0x0076B680 );
    virtual ~oCMsgMagic()                                    zCall( 0x0076B260 );
    virtual int IsNetRelevant()                              zCall( 0x00764DB0 );
    virtual int IsHighPriority()                             zCall( 0x00764DA0 );
    virtual int IsJob()                                      zCall( 0x00764D90 );
    virtual int MD_GetNumOfSubTypes()                        zCall( 0x0076B420 );
    virtual zSTRING MD_GetSubTypeString( int )               zCall( 0x0076B430 );
    virtual void Pack( zCBuffer&, zCEventManager* )          zCall( 0x0076B2C0 );
    virtual void Unpack( zCBuffer&, zCEventManager* )        zCall( 0x0076B360 );

    // user API
    #include "oCMsgMagic.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ONPC_MESSAGES_H__VER3__