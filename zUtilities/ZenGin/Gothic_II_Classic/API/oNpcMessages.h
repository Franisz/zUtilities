// Supported with union (c) 2018-2021 Union team

#ifndef __ONPC_MESSAGES_H__VER2__
#define __ONPC_MESSAGES_H__VER2__

#include "zVob.h"
#include "zBuffer.h"
#include "zSound.h"
#include "zModel.h"
#include "oNpc.h"

namespace Gothic_II_Classic {

  // sizeof 44h
  class oCNpcMessage : public zCEventMessage {
  public:
    zCLASS_DECLARATION( oCNpcMessage )

    zSTRING targetVobName; // sizeof 14h    offset 2Ch
    int highPriority : 1;  // sizeof 01h    offset bit
    int deleted      : 1;  // sizeof 01h    offset bit
    int inUse        : 1;  // sizeof 01h    offset bit

    void oCNpcMessage_OnInit()               zCall( 0x00705880 );
    oCNpcMessage()                           zInit( oCNpcMessage_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x00703AB0 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00703BB0 );
    virtual void Archive( zCArchiver& )      zCall( 0x007059C0 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00705A30 );
    virtual ~oCNpcMessage()                  zCall( 0x00705960 );
    virtual int IsOverlay()                  zCall( 0x00703C30 );
    virtual int IsHighPriority()             zCall( 0x00703C70 );
    virtual int IsJob()                      zCall( 0x00703C40 );
    virtual int GetIgnoreCutsceneMode()      zCall( 0x00703C20 );
    virtual void Delete()                    zCall( 0x00703BC0 );
    virtual int IsDeleteable()               zCall( 0x00703C60 );
    virtual int IsDeleted()                  zCall( 0x00703C50 );
    virtual void SetInUse( int )             zCall( 0x00703BD0 );
    virtual int IsInUse()                    zCall( 0x00703BF0 );
    virtual void SetHighPriority( int )      zCall( 0x00703C00 );

    // user API
    #include "oCNpcMessage.inl"
  };

  // sizeof 114h
  class oCMsgDamage : public oCNpcMessage {
  public:
    zCLASS_DECLARATION( oCMsgDamage )

    enum TDamageSubType {
      EV_DAMAGE_ONCE,
      EV_DAMAGE_PER_FRAME,
      EV_DAMAGE_MAX
    };

    oCNpc::oSDamageDescriptor descDamage; // sizeof D0h    offset 44h

    void oCMsgDamage_OnInit()                                                   zCall( 0x00705AD0 );
    void oCMsgDamage_OnInit( TDamageSubType )                                   zCall( 0x00705BD0 );
    void oCMsgDamage_OnInit( TDamageSubType, oCNpc::oSDamageDescriptor const& ) zCall( 0x00705CA0 );
    oCMsgDamage()                                                               zInit( oCMsgDamage_OnInit() );
    oCMsgDamage( TDamageSubType a0 )                                            zInit( oCMsgDamage_OnInit( a0 ));
    oCMsgDamage( TDamageSubType a0, oCNpc::oSDamageDescriptor const& a1 )       zInit( oCMsgDamage_OnInit( a0, a1 ));
    static zCObject* _CreateNewInstance()                                       zCall( 0x00703E70 );
    virtual zCClassDef* _GetClassDef() const                                    zCall( 0x00703F70 );
    virtual void Archive( zCArchiver& )                                         zCall( 0x00705FD0 );
    virtual void Unarchive( zCArchiver& )                                       zCall( 0x00706050 );
    virtual ~oCMsgDamage()                                                      zCall( 0x00705D90 );
    virtual int IsOverlay()                                                     zCall( 0x00703F90 );
    virtual int IsNetRelevant()                                                 zCall( 0x00703F80 );
    virtual int IsHighPriority()                                                zCall( 0x00703FB0 );
    virtual int IsDeleteable()                                                  zCall( 0x00703FA0 );
    virtual int MD_GetNumOfSubTypes()                                           zCall( 0x00705E70 );
    virtual zSTRING MD_GetSubTypeString( int )                                  zCall( 0x00705E80 );
    virtual void Pack( zCBuffer&, zCEventManager* )                             zCall( 0x00705FB0 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                           zCall( 0x00705FC0 );

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

    void oCMsgWeapon_OnInit()                                   zCall( 0x007071D0 );
    void oCMsgWeapon_OnInit( TWeaponSubType, int, int )         zCall( 0x00707290 );
    oCMsgWeapon()                                               zInit( oCMsgWeapon_OnInit() );
    oCMsgWeapon( TWeaponSubType a0, int a1, int a2 )            zInit( oCMsgWeapon_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                       zCall( 0x007041A0 );
    virtual zCClassDef* _GetClassDef() const                    zCall( 0x00704290 );
    virtual void Archive( zCArchiver& )                         zCall( 0x00707370 );
    virtual void Unarchive( zCArchiver& )                       zCall( 0x00707440 );
    virtual ~oCMsgWeapon()                                      zCall( 0x007042D0 );
    virtual int MD_GetNumOfSubTypes()                           zCall( 0x00707580 );
    virtual zSTRING MD_GetSubTypeString( int )                  zCall( 0x00707590 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior() zCall( 0x007079A0 );
    virtual float MD_GetMinTime()                               zCall( 0x007079B0 );

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

    void oCMsgMovement_OnInit()                                   zCall( 0x00706110 );
    void oCMsgMovement_OnInit( TMovementSubType, zSTRING const& ) zCall( 0x00706210 );
    void oCMsgMovement_OnInit( TMovementSubType, zCVob* )         zCall( 0x007063F0 );
    void oCMsgMovement_OnInit( TMovementSubType, zVEC3 const& )   zCall( 0x007064F0 );
    void oCMsgMovement_OnInit( TMovementSubType, float )          zCall( 0x007065E0 );
    void oCMsgMovement_OnInit( TMovementSubType, int )            zCall( 0x007066C0 );
    oCMsgMovement()                                               zInit( oCMsgMovement_OnInit() );
    oCMsgMovement( TMovementSubType a0, zSTRING const& a1 )       zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, zCVob* a1 )               zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, zVEC3 const& a1 )         zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, float a1 )                zInit( oCMsgMovement_OnInit( a0, a1 ));
    oCMsgMovement( TMovementSubType a0, int a1 )                  zInit( oCMsgMovement_OnInit( a0, a1 ));
    void Init()                                                   zCall( 0x00706880 );
    static zCObject* _CreateNewInstance()                         zCall( 0x00704510 );
    virtual zCClassDef* _GetClassDef() const                      zCall( 0x00704610 );
    virtual void Archive( zCArchiver& )                           zCall( 0x007068C0 );
    virtual void Unarchive( zCArchiver& )                         zCall( 0x007069E0 );
    virtual ~oCMsgMovement()                                      zCall( 0x007067A0 );
    virtual void Delete()                                         zCall( 0x00707170 );
    virtual int MD_GetNumOfSubTypes()                             zCall( 0x00706B50 );
    virtual zSTRING MD_GetSubTypeString( int )                    zCall( 0x00706B60 );
    virtual zSTRING MD_GetVobRefName()                            zCall( 0x00706FA0 );
    virtual void MD_SetVobRefName( zSTRING const& )               zCall( 0x00707020 );
    virtual void MD_SetVobParam( zCVob* )                         zCall( 0x00707160 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()   zCall( 0x00707180 );
    virtual float MD_GetMinTime()                                 zCall( 0x007071C0 );

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

    void oCMsgAttack_OnInit()                                zCall( 0x007079C0 );
    void oCMsgAttack_OnInit( TAttackSubType, int, int )      zCall( 0x00707B20 );
    void oCMsgAttack_OnInit( TAttackSubType, zCVob*, float ) zCall( 0x00707BF0 );
    oCMsgAttack()                                            zInit( oCMsgAttack_OnInit() );
    oCMsgAttack( TAttackSubType a0, int a1, int a2 )         zInit( oCMsgAttack_OnInit( a0, a1, a2 ));
    oCMsgAttack( TAttackSubType a0, zCVob* a1, float a2 )    zInit( oCMsgAttack_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                    zCall( 0x00704800 );
    virtual zCClassDef* _GetClassDef() const                 zCall( 0x00704900 );
    virtual void Archive( zCArchiver& )                      zCall( 0x00707CD0 );
    virtual void Unarchive( zCArchiver& )                    zCall( 0x00707D70 );
    virtual ~oCMsgAttack()                                   zCall( 0x00707AC0 );
    virtual int IsOverlay()                                  zCall( 0x00704920 );
    virtual int IsNetRelevant()                              zCall( 0x00704910 );
    virtual int MD_GetNumOfSubTypes()                        zCall( 0x00708160 );
    virtual zSTRING MD_GetSubTypeString( int )               zCall( 0x00708170 );
    virtual void Pack( zCBuffer&, zCEventManager* )          zCall( 0x00707E60 );
    virtual void Unpack( zCBuffer&, zCEventManager* )        zCall( 0x00707FF0 );

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

    void oCMsgUseItem_OnInit()                          zCall( 0x007084E0 );
    void oCMsgUseItem_OnInit( TUseItemSubType, zCVob* ) zCall( 0x007085D0 );
    oCMsgUseItem()                                      zInit( oCMsgUseItem_OnInit() );
    oCMsgUseItem( TUseItemSubType a0, zCVob* a1 )       zInit( oCMsgUseItem_OnInit( a0, a1 ));
    static zCObject* _CreateNewInstance()               zCall( 0x00704B20 );
    virtual zCClassDef* _GetClassDef() const            zCall( 0x00704C30 );
    virtual void Archive( zCArchiver& )                 zCall( 0x00708790 );
    virtual void Unarchive( zCArchiver& )               zCall( 0x00708810 );
    virtual ~oCMsgUseItem()                             zCall( 0x00708690 );
    virtual int IsNetRelevant()                         zCall( 0x00704C40 );
    virtual void Pack( zCBuffer&, zCEventManager* )     zCall( 0x007086F0 );
    virtual void Unpack( zCBuffer&, zCEventManager* )   zCall( 0x00708740 );

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

    void oCMsgState_OnInit()                                          zCall( 0x007088C0 );
    void oCMsgState_OnInit( TStateSubType, float )                    zCall( 0x007089C0 );
    void oCMsgState_OnInit( TStateSubType, int )                      zCall( 0x00708AA0 );
    void oCMsgState_OnInit( TStateSubType, int, int, zSTRING const& ) zCall( 0x00708B80 );
    oCMsgState()                                                      zInit( oCMsgState_OnInit() );
    oCMsgState( TStateSubType a0, float a1 )                          zInit( oCMsgState_OnInit( a0, a1 ));
    oCMsgState( TStateSubType a0, int a1 )                            zInit( oCMsgState_OnInit( a0, a1 ));
    oCMsgState( TStateSubType a0, int a1, int a2, zSTRING const& a3 ) zInit( oCMsgState_OnInit( a0, a1, a2, a3 ));
    static zCObject* _CreateNewInstance()                             zCall( 0x00704E30 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x00704F30 );
    virtual void Archive( zCArchiver& )                               zCall( 0x00708E00 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x00708EB0 );
    virtual ~oCMsgState()                                             zCall( 0x00708D70 );
    virtual int IsOverlay()                                           zCall( 0x00704F40 );
    virtual int MD_GetNumOfSubTypes()                                 zCall( 0x00708FA0 );
    virtual zSTRING MD_GetSubTypeString( int )                        zCall( 0x00708FB0 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()       zCall( 0x007091E0 );
    virtual float MD_GetMinTime()                                     zCall( 0x007091F0 );

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

    void oCMsgManipulate_OnInit()                                                     zCall( 0x00709230 );
    void oCMsgManipulate_OnInit( TManipulateSubType )                                 zCall( 0x00709330 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zCVob* )                         zCall( 0x00709400 );
    void oCMsgManipulate_OnInit( TManipulateSubType, int )                            zCall( 0x007094D0 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zSTRING const&, int )            zCall( 0x007095A0 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zCVob*, int )                    zCall( 0x00709770 );
    void oCMsgManipulate_OnInit( TManipulateSubType, zSTRING const&, zSTRING const& ) zCall( 0x00709840 );
    oCMsgManipulate()                                                                 zInit( oCMsgManipulate_OnInit() );
    oCMsgManipulate( TManipulateSubType a0 )                                          zInit( oCMsgManipulate_OnInit( a0 ));
    oCMsgManipulate( TManipulateSubType a0, zCVob* a1 )                               zInit( oCMsgManipulate_OnInit( a0, a1 ));
    oCMsgManipulate( TManipulateSubType a0, int a1 )                                  zInit( oCMsgManipulate_OnInit( a0, a1 ));
    oCMsgManipulate( TManipulateSubType a0, zSTRING const& a1, int a2 )               zInit( oCMsgManipulate_OnInit( a0, a1, a2 ));
    oCMsgManipulate( TManipulateSubType a0, zCVob* a1, int a2 )                       zInit( oCMsgManipulate_OnInit( a0, a1, a2 ));
    oCMsgManipulate( TManipulateSubType a0, zSTRING const& a1, zSTRING const& a2 )    zInit( oCMsgManipulate_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                                             zCall( 0x00705140 );
    virtual zCClassDef* _GetClassDef() const                                          zCall( 0x00705240 );
    virtual void Archive( zCArchiver& )                                               zCall( 0x00709B00 );
    virtual void Unarchive( zCArchiver& )                                             zCall( 0x00709BE0 );
    virtual ~oCMsgManipulate()                                                        zCall( 0x00709A40 );
    virtual int IsNetRelevant()                                                       zCall( 0x00705250 );
    virtual int MD_GetNumOfSubTypes()                                                 zCall( 0x0070A000 );
    virtual zSTRING MD_GetSubTypeString( int )                                        zCall( 0x0070A010 );
    virtual zSTRING MD_GetVobRefName()                                                zCall( 0x0070A4C0 );
    virtual void MD_SetVobRefName( zSTRING const& )                                   zCall( 0x0070A570 );
    virtual void MD_SetVobParam( zCVob* )                                             zCall( 0x0070A6B0 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()                       zCall( 0x0070A470 );
    virtual float MD_GetMinTime()                                                     zCall( 0x0070A4B0 );
    virtual void Pack( zCBuffer&, zCEventManager* )                                   zCall( 0x00709D00 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                                 zCall( 0x00709DF0 );

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
      EV_SNDPLAY,
      EV_SNDPLAY3D,
      EV_PRINTSCREEN,
      EV_STARTFX,
      EV_STOPFX,
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

    void oCMsgConversation_OnInit()                                                       zCall( 0x0070A6C0 );
    void oCMsgConversation_OnInit( TConversationSubType )                                 zCall( 0x0070A7C0 );
    void oCMsgConversation_OnInit( TConversationSubType, zSTRING const& )                 zCall( 0x0070A8A0 );
    void oCMsgConversation_OnInit( TConversationSubType, zSTRING const&, zSTRING const& ) zCall( 0x0070AA90 );
    void oCMsgConversation_OnInit( TConversationSubType, zCVob* )                         zCall( 0x0070ACA0 );
    void oCMsgConversation_OnInit( TConversationSubType, int )                            zCall( 0x0070AD80 );
    void oCMsgConversation_OnInit( TConversationSubType, int, int, float )                zCall( 0x0070AE60 );
    oCMsgConversation()                                                                   zInit( oCMsgConversation_OnInit() );
    oCMsgConversation( TConversationSubType a0 )                                          zInit( oCMsgConversation_OnInit( a0 ));
    oCMsgConversation( TConversationSubType a0, zSTRING const& a1 )                       zInit( oCMsgConversation_OnInit( a0, a1 ));
    oCMsgConversation( TConversationSubType a0, zSTRING const& a1, zSTRING const& a2 )    zInit( oCMsgConversation_OnInit( a0, a1, a2 ));
    oCMsgConversation( TConversationSubType a0, zCVob* a1 )                               zInit( oCMsgConversation_OnInit( a0, a1 ));
    oCMsgConversation( TConversationSubType a0, int a1 )                                  zInit( oCMsgConversation_OnInit( a0, a1 ));
    oCMsgConversation( TConversationSubType a0, int a1, int a2, float a3 )                zInit( oCMsgConversation_OnInit( a0, a1, a2, a3 ));
    static zCObject* _CreateNewInstance()                                                 zCall( 0x00705460 );
    virtual zCClassDef* _GetClassDef() const                                              zCall( 0x00705570 );
    virtual void Archive( zCArchiver& )                                                   zCall( 0x0070B030 );
    virtual void Unarchive( zCArchiver& )                                                 zCall( 0x0070B120 );
    virtual ~oCMsgConversation()                                                          zCall( 0x0070AF60 );
    virtual int IsOverlay()                                                               zCall( 0x0070B5C0 );
    virtual void Delete()                                                                 zCall( 0x0070B3D0 );
    virtual int MD_GetNumOfSubTypes()                                                     zCall( 0x0070B3C0 );
    virtual zSTRING MD_GetSubTypeString( int )                                            zCall( 0x0070B620 );
    virtual zSTRING MD_GetVobRefName()                                                    zCall( 0x0070B820 );
    virtual void MD_SetVobRefName( zSTRING const& )                                       zCall( 0x0070B870 );
    virtual void MD_SetVobParam( zCVob* )                                                 zCall( 0x0070B9B0 );
    virtual zCEventMessage::zTTimeBehavior MD_GetTimeBehavior()                           zCall( 0x0070B9C0 );
    virtual float MD_GetMinTime()                                                         zCall( 0x0070BA10 );

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

    void oCMsgMagic_OnInit()                                 zCall( 0x0070BAF0 );
    void oCMsgMagic_OnInit( TConversationSubType )           zCall( 0x0070BBC0 );
    void oCMsgMagic_OnInit( TConversationSubType, int, int ) zCall( 0x0070BC70 );
    oCMsgMagic()                                             zInit( oCMsgMagic_OnInit() );
    oCMsgMagic( TConversationSubType a0 )                    zInit( oCMsgMagic_OnInit( a0 ));
    oCMsgMagic( TConversationSubType a0, int a1, int a2 )    zInit( oCMsgMagic_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                    zCall( 0x00705770 );
    virtual zCClassDef* _GetClassDef() const                 zCall( 0x00705840 );
    virtual void Archive( zCArchiver& )                      zCall( 0x0070C0A0 );
    virtual void Unarchive( zCArchiver& )                    zCall( 0x0070C140 );
    virtual ~oCMsgMagic()                                    zCall( 0x0070BD20 );
    virtual int IsNetRelevant()                              zCall( 0x00705870 );
    virtual int IsHighPriority()                             zCall( 0x00705860 );
    virtual int IsJob()                                      zCall( 0x00705850 );
    virtual int MD_GetNumOfSubTypes()                        zCall( 0x0070BEE0 );
    virtual zSTRING MD_GetSubTypeString( int )               zCall( 0x0070BEF0 );
    virtual void Pack( zCBuffer&, zCEventManager* )          zCall( 0x0070BD80 );
    virtual void Unpack( zCBuffer&, zCEventManager* )        zCall( 0x0070BE20 );

    // user API
    #include "oCMsgMagic.inl"
  };

  // sizeof 4Ch
  class oCMsgRequest : public oCNpcMessage {
  public:
    zCLASS_DECLARATION( oCMsgRequest )

    enum TRequestSubType {
      EV_REQUEST_0,
      EV_REQUEST_1,
      EV_REQUEST_2,
      EV_REQUEST_3,
      EV_REQUEST_4,
      EV_REQUEST_5,
      EV_REQUEST_6,
      EV_REQUEST_7,
      EV_REQUEST_8,
      EV_REQUEST_9,
      EV_REQUEST_MAX
    };

    TRequestSubType subType; // sizeof 04h    offset 44h
    float delay;             // sizeof 04h    offset 48h

    oCMsgRequest() {}

    // user API
    #include "oCMsgRequest.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ONPC_MESSAGES_H__VER2__