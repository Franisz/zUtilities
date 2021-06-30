// Supported with union (c) 2018 Union team

#ifndef __OMOB_INTER_H__VER3__
#define __OMOB_INTER_H__VER3__

#include "oVob.h"
#include "oItem.h"
#include "oNpc.h"
#include "zModel.h"

namespace Gothic_II_Addon {

  struct TMobOptPos {
  public:
    zMAT4 trafo;
    int distance;
    oCNpc* npc;
    zSTRING nodeName;

    // user API
    #include "TMobOptPos.inl"
  };

  class oCMOB : public oCVob {
  public:
    zCLASS_DECLARATION( oCMOB )

    zSTRING name;
    int hitp             : 12;
    int damage           : 12;
    int isDestroyed      : 1;
    int moveable         : 1;
    int takeable         : 1;
    int focusOverride    : 1;
    oTSndMaterial sndMat : 3;
    zSTRING visualDestroyed;
    zSTRING ownerStr;
    zSTRING ownerGuildStr;
    int owner;
    int ownerGuild;
    int focusNameIndex;
    zCList<zCVob> ignoreVobList;

    void oCMOB_OnInit()                                                                      zCall( 0x0071B8F0 );
    oCMOB()                                                                                  zInit( oCMOB_OnInit() );
    void SetMoveable( int )                                                                  zCall( 0x0071BF00 );
    int IsMoveable()                                                                         zCall( 0x0071BF20 );
    void SetOwner( zSTRING const&, zSTRING const& )                                          zCall( 0x0071BF80 );
    void SetOwner( int, int )                                                                zCall( 0x0071C170 );
    int IsOwner( oCNpc* )                                                                    zCall( 0x0071C1D0 );
    void Hit( int )                                                                          zCall( 0x0071C220 );
    void InsertInIgnoreList( zCVob* )                                                        zCall( 0x0071C490 );
    void RemoveFromIgnoreList( zCVob* )                                                      zCall( 0x0071C4C0 );
    static zCObject* _CreateNewInstance()                                                    zCall( 0x00718590 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x0071BA20 );
    virtual void Archive( zCArchiver& )                                                      zCall( 0x0071C560 );
    virtual void Unarchive( zCArchiver& )                                                    zCall( 0x0071C6A0 );
    virtual ~oCMOB()                                                                         zCall( 0x0071BA60 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )                        zCall( 0x0071BEC0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                        zCall( 0x0071BED0 );
    virtual int CanThisCollideWith( zCVob* )                                                 zCall( 0x0071C520 );
    virtual void SetVisual( zCVisual* )                                                      zCall( 0x0071BBF0 );
    virtual int IsOwnedByGuild( int )                                                        zCall( 0x0071C190 );
    virtual int IsOwnedByNpc( int )                                                          zCall( 0x0071C1B0 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int ) zCall( 0x0071BF60 );
    virtual void SetSoundMaterial( oTSndMaterial )                                           zCall( 0x0071BF30 );
    virtual oTSndMaterial GetSoundMaterial()                                                 zCall( 0x0071BF50 );
    virtual void SetName( zSTRING const& )                                                   zCall( 0x0071BC10 );
    virtual zSTRING GetName()                                                                zCall( 0x0071BC30 );
    virtual zCModel* GetModel()                                                              zCall( 0x0071BEE0 );
    virtual zSTRING GetScemeName()                                                           zCall( 0x0071BD00 );
    virtual void Destroy()                                                                   zCall( 0x0071C230 );
    virtual int AllowDiscardingOfSubtree()                                                   zCall( 0x0071CCC0 );

    // user API
    #include "oCMOB.inl"
  };

  class oCMobInter : public oCMOB {
  public:
    zCLASS_DECLARATION( oCMobInter )

    enum TMobInterDirection {
      MOBINTER_DIRECTION_NONE,
      MOBINTER_DIRECTION_UP,
      MOBINTER_DIRECTION_DOWN
    };

    zCList<TMobOptPos> optimalPosList;
    zSTRING triggerTarget;
    zSTRING useWithItem;
    zSTRING sceme;
    zSTRING conditionFunc;
    zSTRING onStateFuncName;
    int state;
    int state_num;
    int state_target;
    int rewind;
    int mobStateAni;
    int npcStateAni;
    int npcsMax     : 8;
    int npcsNeeded  : 8;
    int npcsCurrent : 8;
    int tmpState    : 8;
    int tmpStateChanged;
    TMobInterDirection Direction;
    int onInterruptReturnToSlotPos : 1;
    zVEC3 startPos;
    float aniCombHeight;
    zCVob* inUseVob;
    float timerEnd;

    void oCMobInter_OnInit()                                              zCall( 0x0071D010 );
    oCMobInter()                                                          zInit( oCMobInter_OnInit() );
    void SetTempState( int )                                              zCall( 0x0071D540 );
    int IsTempStateChanged()                                              zCall( 0x0071D580 );
    void SetStateToTempState()                                            zCall( 0x0071D590 );
    void SetMobBodyState( oCNpc* )                                        zCall( 0x0071D610 );
    int HasUseWithItem( oCNpc* )                                          zCall( 0x0071DB60 );
    void ScanIdealPositions()                                             zCall( 0x0071DC30 );
    int GetFreePosition( oCNpc*, zVEC3& )                                 zCall( 0x0071DF50 );
    void SetHeading( oCNpc* )                                             zCall( 0x0071E1F0 );
    void SetIdealPosition( oCNpc* )                                       zCall( 0x0071E240 );
    void SendStateChange( int, int )                                      zCall( 0x0071ED90 );
    void SendEndInteraction( oCNpc*, int, int )                           zCall( 0x0071F080 );
    void StartTransitionAniNpc( oCNpc*, zSTRING const& )                  zCall( 0x00720150 );
    int IsMultiMob()                                                      zCall( 0x00720EB0 );
    int IsAvailable( oCNpc* )                                             zCall( 0x00720EC0 );
    void MarkAsUsed( float, zCVob* )                                      zCall( 0x00720F20 );
    static zCObject* _CreateNewInstance()                                 zCall( 0x007187E0 );
    static int SetAllMobsToState( oCWorld*, zSTRING const&, int )         zCall( 0x0071CCD0 );
    static void TraverseMobs( zCTree<zCVob>*, zSTRING const&, int, int* ) zCall( 0x0071CD00 );
    static void TriggerAllMobsToTmpState( zCWorld* )                      zCall( 0x0071CE90 );
    static void TraverseTriggerMobs( zCTree<zCVob>* )                     zCall( 0x0071CF50 );
    virtual zCClassDef* _GetClassDef() const                              zCall( 0x0071D190 );
    virtual void Archive( zCArchiver& )                                   zCall( 0x00722310 );
    virtual void Unarchive( zCArchiver& )                                 zCall( 0x007223B0 );
    virtual ~oCMobInter()                                                 zCall( 0x0071D1D0 );
    virtual void OnTrigger( zCVob*, zCVob* )                              zCall( 0x0071E7D0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                            zCall( 0x0071EAC0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )     zCall( 0x0071D940 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                     zCall( 0x0071D950 );
    virtual void OnTick()                                                 zCall( 0x0071E750 );
    virtual void SetVisual( zCVisual* )                                   zCall( 0x0071D3C0 );
    virtual zSTRING const* GetTriggerTarget( int ) const                  zCall( 0x00718CE0 );
    virtual zSTRING GetScemeName()                                        zCall( 0x0071DBE0 );
    virtual int GetState()                                                zCall( 0x00718C80 );
    virtual int GetStateNum()                                             zCall( 0x00718C90 );
    virtual TMobInterDirection GetDirection()                             zCall( 0x00718CA0 );
    virtual void SetDirection( TMobInterDirection )                       zCall( 0x00718CB0 );
    virtual void SetUseWithItem( zSTRING const& )                         zCall( 0x0071DA00 );
    virtual int GetUseWithItem()                                          zCall( 0x0071DB40 );
    virtual void Reset()                                                  zCall( 0x0071E490 );
    virtual void Interact( oCNpc*, int, int, int, int, int )              zCall( 0x0071F210 );
    virtual void EndInteraction( oCNpc*, int )                            zCall( 0x00721950 );
    virtual void InterruptInteraction( oCNpc* )                           zCall( 0x00720CE0 );
    virtual void StopInteraction( oCNpc* )                                zCall( 0x00721C20 );
    virtual int CanInteractWith( oCNpc* )                                 zCall( 0x00720F40 );
    virtual int IsInteractingWith( oCNpc* )                               zCall( 0x00721550 );
    virtual int IsOccupied()                                              zCall( 0x00718CC0 );
    virtual int AI_UseMobToState( oCNpc*, int )                           zCall( 0x00721F00 );
    virtual int IsIn( int )                                               zCall( 0x00718CD0 );
    virtual int IsInState( oCNpc*, int )                                  zCall( 0x0071FB00 );
    virtual void StartInteraction( oCNpc* )                               zCall( 0x00721580 );
    virtual void StartStateChange( oCNpc*, int, int )                     zCall( 0x0071FEA0 );
    virtual void CheckStateChange( oCNpc* )                               zCall( 0x00720440 );
    virtual int CanChangeState( oCNpc*, int, int )                        zCall( 0x0071FC40 );
    virtual void GetTransitionNames( int, int, zSTRING&, zSTRING& )       zCall( 0x0071F5E0 );
    virtual void OnBeginStateChange( oCNpc*, int, int )                   zCall( 0x00720C70 );
    virtual void OnEndStateChange( oCNpc*, int, int )                     zCall( 0x00720C80 );
    virtual void CallOnStateFunc( oCNpc*, int )                           zCall( 0x00720870 );
    virtual void SendCallOnStateFunc( oCNpc*, int )                       zCall( 0x00720AD0 );
    virtual TMobOptPos* SearchFreePosition( oCNpc*, float )               zCall( 0x0071DFC0 );

    // user API
    #include "oCMobInter.inl"
  };

  class oCMobBed : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobBed )

    zSTRING addName;

    void oCMobBed_OnInit()                                  zCall( 0x00722E50 );
    oCMobBed()                                              zInit( oCMobBed_OnInit() );
    static zCObject* _CreateNewInstance()                   zCall( 0x00718A50 );
    virtual zCClassDef* _GetClassDef() const                zCall( 0x00718D20 );
    virtual ~oCMobBed()                                     zCall( 0x00723040 );
    virtual zSTRING GetScemeName()                          zCall( 0x007232A0 );
    virtual void StartInteraction( oCNpc* )                 zCall( 0x00723220 );
    virtual void OnBeginStateChange( oCNpc*, int, int )     zCall( 0x00723230 );
    virtual void OnEndStateChange( oCNpc*, int, int )       zCall( 0x00723240 );
    virtual TMobOptPos* SearchFreePosition( oCNpc*, float ) zCall( 0x00723350 );

    // user API
    #include "oCMobBed.inl"
  };

  class oCMobSwitch : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobSwitch )

    void oCMobSwitch_OnInit()                zCall( 0x007234E0 );
    oCMobSwitch()                            zInit( oCMobSwitch_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x00718F20 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00719060 );
    virtual void Archive( zCArchiver& )      zCall( 0x007237D0 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00723870 );
    virtual ~oCMobSwitch()                   zCall( 0x00723600 );

    // user API
    #include "oCMobSwitch.inl"
  };

  class oCMobItemSlot : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobItemSlot )

    oCItem* insertedItem;
    int removeable;

    void oCMobItemSlot_OnInit()              zCall( 0x00727E80 );
    oCMobItemSlot()                          zInit( oCMobItemSlot_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x0071AA50 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x0071AB00 );
    virtual void Archive( zCArchiver& )      zCall( 0x00728430 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00728500 );
    virtual ~oCMobItemSlot()                 zCall( 0x00727ED0 );
    virtual int GetUseWithItem()             zCall( 0x007280B0 );
    virtual int CanInteractWith( oCNpc* )    zCall( 0x007280F0 );
    virtual int IsIn( int )                  zCall( 0x00728400 );
    virtual oCItem* GetInsertedItem()        zCall( 0x00728110 );
    virtual int PlaceItem( oCItem* )         zCall( 0x00728120 );
    virtual oCItem* RemoveItem()             zCall( 0x007283C0 );

    // user API
    #include "oCMobItemSlot.inl"
  };

  class oCMobLockable : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobLockable )

    int locked     : 1;
    int autoOpen   : 1;
    int pickLockNr : 30;
    zSTRING keyInstance;
    zSTRING pickLockStr;

    void oCMobLockable_OnInit()                              zCall( 0x00723920 );
    oCMobLockable()                                          zInit( oCMobLockable_OnInit() );
    int CanOpen( oCNpc* )                                    zCall( 0x007244F0 );
    virtual zCClassDef* _GetClassDef() const                 zCall( 0x00719610 );
    virtual void Archive( zCArchiver& )                      zCall( 0x007253B0 );
    virtual void Unarchive( zCArchiver& )                    zCall( 0x007254A0 );
    virtual ~oCMobLockable()                                 zCall( 0x00723B00 );
    virtual void OnMessage( zCEventMessage*, zCVob* )        zCall( 0x007198C0 );
    virtual void Interact( oCNpc*, int, int, int, int, int ) zCall( 0x00723CF0 );
    virtual int CanInteractWith( oCNpc* )                    zCall( 0x00723CC0 );
    virtual int CanChangeState( oCNpc*, int, int )           zCall( 0x007242E0 );
    virtual void OnEndStateChange( oCNpc*, int, int )        zCall( 0x00724330 );
    virtual void SetLocked( int )                            zCall( 0x00719620 );
    virtual void SetKeyInstance( zSTRING const& )            zCall( 0x00719640 );
    virtual void SetPickLockStr( zSTRING const& )            zCall( 0x00719780 );
    virtual void Open( oCNpc* )                              zPureCall;
    virtual void Close( oCNpc* )                             zPureCall;
    virtual void Lock( oCNpc* )                              zCall( 0x007251C0 );
    virtual void Unlock( oCNpc*, int )                       zCall( 0x00724A70 );
    virtual int PickLock( oCNpc*, char )                     zCall( 0x00724800 );

    // user API
    #include "oCMobLockable.inl"
  };

  class oCMobContainer : public oCMobLockable {
  public:
    zCLASS_DECLARATION( oCMobContainer )

    zSTRING contains;
    oCItemContainer* items;
    zCListSort<oCItem> containList;

    void oCMobContainer_OnInit()                      zCall( 0x007257E0 );
    oCMobContainer()                                  zInit( oCMobContainer_OnInit() );
    static zCObject* _CreateNewInstance()             zCall( 0x00719440 );
    virtual zCClassDef* _GetClassDef() const          zCall( 0x00719990 );
    virtual void Archive( zCArchiver& )               zCall( 0x00726680 );
    virtual void Unarchive( zCArchiver& )             zCall( 0x00726820 );
    virtual ~oCMobContainer()                         zCall( 0x007259A0 );
    virtual void OnMessage( zCEventMessage*, zCVob* ) zCall( 0x00725BB0 );
    virtual void Destroy()                            zCall( 0x00725CB0 );
    virtual void Reset()                              zCall( 0x00725E60 );
    virtual int IsIn( int )                           zCall( 0x007264C0 );
    virtual void Open( oCNpc* )                       zCall( 0x00726500 );
    virtual void Close( oCNpc* )                      zCall( 0x00726640 );
    virtual void Insert( oCItem* )                    zCall( 0x00725FC0 );
    virtual void Remove( oCItem* )                    zCall( 0x00725FF0 );
    virtual oCItem* Remove( oCItem*, int )            zCall( 0x00726080 );
    virtual void CreateContents( zSTRING const& )     zCall( 0x00726190 );

    // user API
    #include "oCMobContainer.inl"
  };

  class oCMobDoor : public oCMobLockable {
  public:
    zCLASS_DECLARATION( oCMobDoor )

    zSTRING addName;

    void oCMobDoor_OnInit()                                 zCall( 0x007269B0 );
    oCMobDoor()                                             zInit( oCMobDoor_OnInit() );
    static zCObject* _CreateNewInstance()                   zCall( 0x0071A250 );
    virtual zCClassDef* _GetClassDef() const                zCall( 0x0071A420 );
    virtual ~oCMobDoor()                                    zCall( 0x00726BB0 );
    virtual zSTRING GetScemeName()                          zCall( 0x00726D60 );
    virtual TMobOptPos* SearchFreePosition( oCNpc*, float ) zCall( 0x00726E10 );
    virtual void Open( oCNpc* )                             zCall( 0x0071A430 );
    virtual void Close( oCNpc* )                            zCall( 0x0071A440 );

    // user API
    #include "oCMobDoor.inl"
  };

  class oCMobFire : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobFire )

    zSTRING fireSlot;
    zSTRING fireVobtreeName;
    zCVob* fireVobtree;

    void oCMobFire_OnInit()                                           zCall( 0x00722460 );
    oCMobFire()                                                       zInit( oCMobFire_OnInit() );
    void DeleteEffects()                                              zCall( 0x00722850 );
    static zCObject* _CreateNewInstance()                             zCall( 0x0071A640 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x0071A850 );
    virtual void Archive( zCArchiver& )                               zCall( 0x00722C60 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x00722D70 );
    virtual ~oCMobFire()                                              zCall( 0x00722670 );
    virtual void OnTrigger( zCVob*, zCVob* )                          zCall( 0x00722980 );
    virtual void OnUntrigger( zCVob*, zCVob* )                        zCall( 0x00722B90 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& ) zCall( 0x007228A0 );
    virtual void OnEndStateChange( oCNpc*, int, int )                 zCall( 0x007228F0 );
    virtual void PreSave()                                            zCall( 0x00722C00 );
    virtual void PostSave()                                           zCall( 0x00722D40 );

    // user API
    #include "oCMobFire.inl"
  };

  class oCMobWheel : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobWheel )

    void oCMobWheel_OnInit()                                 zCall( 0x00726FA0 );
    oCMobWheel()                                             zInit( oCMobWheel_OnInit() );
    static zCObject* _CreateNewInstance()                    zCall( 0x00719B90 );
    virtual zCClassDef* _GetClassDef() const                 zCall( 0x00719CE0 );
    virtual ~oCMobWheel()                                    zCall( 0x007272F0 );
    virtual void OnTrigger( zCVob*, zCVob* )                 zCall( 0x007270D0 );
    virtual void OnUntrigger( zCVob*, zCVob* )               zCall( 0x007271E0 );
    virtual void Interact( oCNpc*, int, int, int, int, int ) zCall( 0x007272E0 );

    // user API
    #include "oCMobWheel.inl"
  };

  class oCMobLadder : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobLadder )

    int Interacting;
    int PrevAction;

    void oCMobLadder_OnInit()                                zCall( 0x007274C0 );
    oCMobLadder()                                            zInit( oCMobLadder_OnInit() );
    static zCObject* _CreateNewInstance()                    zCall( 0x00719EE0 );
    virtual zCClassDef* _GetClassDef() const                 zCall( 0x0071A040 );
    virtual ~oCMobLadder()                                   zCall( 0x00727600 );
    virtual int DoFocusCheckBBox()                           zCall( 0x0071A050 );
    virtual void Interact( oCNpc*, int, int, int, int, int ) zCall( 0x00727A60 );
    virtual void EndInteraction( oCNpc*, int )               zCall( 0x00727E60 );
    virtual int CanInteractWith( oCNpc* )                    zCall( 0x007279E0 );
    virtual void StartInteraction( oCNpc* )                  zCall( 0x007277D0 );
    virtual int CanChangeState( oCNpc*, int, int )           zCall( 0x00727990 );
    virtual TMobOptPos* SearchFreePosition( oCNpc*, float )  zCall( 0x007279F0 );

    // user API
    #include "oCMobLadder.inl"
  };

  class oCDummyVobGenerator : public zCVob {
  public:
    zCLASS_DECLARATION( oCDummyVobGenerator )

    void oCDummyVobGenerator_OnInit()        zCall( 0x007285F0 );
    oCDummyVobGenerator()                    zInit( oCDummyVobGenerator_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x0071AD00 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x0071ADC0 );
    virtual ~oCDummyVobGenerator()           zCall( 0x0071AE00 );
    virtual void OnTrigger( zCVob*, zCVob* ) zCall( 0x00728660 );

    // user API
    #include "oCDummyVobGenerator.inl"
  };

  class oCMobMsg : public zCEventMessage {
  public:
    zCLASS_DECLARATION( oCMobMsg )

    enum TMobMsgSubType {
      EV_STARTINTERACTION,
      EV_STARTSTATECHANGE,
      EV_ENDINTERACTION,
      EV_UNLOCK,
      EV_LOCK,
      EV_CALLSCRIPT
    };

    oCNpc* npc;
    int from;
    int to      : 31;
    int playAni : 1;

    void oCMobMsg_OnInit( TMobMsgSubType, oCNpc* )      zCall( 0x0071B220 );
    void oCMobMsg_OnInit()                              zCall( 0x0071B3A0 );
    void oCMobMsg_OnInit( TMobMsgSubType, oCNpc*, int ) zCall( 0x0071B4D0 );
    oCMobMsg( TMobMsgSubType a0, oCNpc* a1 )            zInit( oCMobMsg_OnInit( a0, a1 ));
    oCMobMsg()                                          zInit( oCMobMsg_OnInit() );
    oCMobMsg( TMobMsgSubType a0, oCNpc* a1, int a2 )    zInit( oCMobMsg_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()               zCall( 0x0071B030 );
    virtual zCClassDef* _GetClassDef() const            zCall( 0x0071B200 );
    virtual ~oCMobMsg()                                 zCall( 0x0071B390 );
    virtual int IsNetRelevant()                         zCall( 0x0071B210 );
    virtual int MD_GetNumOfSubTypes()                   zCall( 0x0071B740 );
    virtual zSTRING MD_GetSubTypeString( int )          zCall( 0x0071B750 );
    virtual void Pack( zCBuffer&, zCEventManager* )     zCall( 0x0071B620 );
    virtual void Unpack( zCBuffer&, zCEventManager* )   zCall( 0x0071B6A0 );

    // user API
    #include "oCMobMsg.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OMOB_INTER_H__VER3__