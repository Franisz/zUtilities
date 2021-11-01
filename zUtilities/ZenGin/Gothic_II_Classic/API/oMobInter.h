// Supported with union (c) 2018-2021 Union team

#ifndef __OMOB_INTER_H__VER2__
#define __OMOB_INTER_H__VER2__

#include "oVob.h"
#include "oItem.h"
#include "oNpc.h"
#include "zModel.h"

namespace Gothic_II_Classic {

  // sizeof 5Ch
  struct TMobOptPos {
  public:
    zMAT4 trafo;      // sizeof 40h    offset 00h
    int distance;     // sizeof 04h    offset 40h
    oCNpc* npc;       // sizeof 04h    offset 44h
    zSTRING nodeName; // sizeof 14h    offset 48h

    // user API
    #include "TMobOptPos.inl"
  };

  // sizeof 188h
  class oCMOB : public oCVob {
  public:
    zCLASS_DECLARATION( oCMOB )

    zSTRING name;                // sizeof 14h    offset 120h
    int hitp             : 12;   // sizeof 0Ch    offset bit
    int damage           : 12;   // sizeof 0Ch    offset bit
    int isDestroyed      : 1;    // sizeof 01h    offset bit
    int moveable         : 1;    // sizeof 01h    offset bit
    int takeable         : 1;    // sizeof 01h    offset bit
    int focusOverride    : 1;    // sizeof 01h    offset bit
    oTSndMaterial sndMat : 3;    // sizeof 03h    offset bit
    zSTRING visualDestroyed;     // sizeof 14h    offset 138h
    zSTRING ownerStr;            // sizeof 14h    offset 14Ch
    zSTRING ownerGuildStr;       // sizeof 14h    offset 160h
    int owner;                   // sizeof 04h    offset 174h
    int ownerGuild;              // sizeof 04h    offset 178h
    int focusNameIndex;          // sizeof 04h    offset 17Ch
    zCList<zCVob> ignoreVobList; // sizeof 08h    offset 180h

    void oCMOB_OnInit()                                                                      zCall( 0x006BD860 );
    oCMOB()                                                                                  zInit( oCMOB_OnInit() );
    void SetMoveable( int )                                                                  zCall( 0x006BDE70 );
    int IsMoveable()                                                                         zCall( 0x006BDE90 );
    void SetOwner( zSTRING const&, zSTRING const& )                                          zCall( 0x006BDEF0 );
    void SetOwner( int, int )                                                                zCall( 0x006BE0E0 );
    int IsOwner( oCNpc* )                                                                    zCall( 0x006BE140 );
    void Hit( int )                                                                          zCall( 0x006BE190 );
    void InsertInIgnoreList( zCVob* )                                                        zCall( 0x006BE400 );
    void RemoveFromIgnoreList( zCVob* )                                                      zCall( 0x006BE430 );
    static zCObject* _CreateNewInstance()                                                    zCall( 0x006BA500 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x006BD990 );
    virtual void Archive( zCArchiver& )                                                      zCall( 0x006BE4D0 );
    virtual void Unarchive( zCArchiver& )                                                    zCall( 0x006BE610 );
    virtual ~oCMOB()                                                                         zCall( 0x006BD9D0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )                        zCall( 0x006BDE30 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                        zCall( 0x006BDE40 );
    virtual int CanThisCollideWith( zCVob* )                                                 zCall( 0x006BE490 );
    virtual void SetVisual( zCVisual* )                                                      zCall( 0x006BDB60 );
    virtual int IsOwnedByGuild( int )                                                        zCall( 0x006BE100 );
    virtual int IsOwnedByNpc( int )                                                          zCall( 0x006BE120 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int ) zCall( 0x006BDED0 );
    virtual void SetSoundMaterial( oTSndMaterial )                                           zCall( 0x006BDEA0 );
    virtual oTSndMaterial GetSoundMaterial()                                                 zCall( 0x006BDEC0 );
    virtual void SetName( zSTRING const& )                                                   zCall( 0x006BDB80 );
    virtual zSTRING GetName()                                                                zCall( 0x006BDBA0 );
    virtual zCModel* GetModel()                                                              zCall( 0x006BDE50 );
    virtual zSTRING GetScemeName()                                                           zCall( 0x006BDC70 );
    virtual void Destroy()                                                                   zCall( 0x006BE1A0 );
    virtual int AllowDiscardingOfSubtree()                                                   zCall( 0x006BEC30 );

    // user API
    #include "oCMOB.inl"
  };

  // sizeof 234h
  class oCMobInter : public oCMOB {
  public:
    zCLASS_DECLARATION( oCMobInter )

    enum TMobInterDirection {
      MOBINTER_DIRECTION_NONE,
      MOBINTER_DIRECTION_UP,
      MOBINTER_DIRECTION_DOWN
    };

    zCList<TMobOptPos> optimalPosList;  // sizeof 08h    offset 188h
    zSTRING triggerTarget;              // sizeof 14h    offset 190h
    zSTRING useWithItem;                // sizeof 14h    offset 1A4h
    zSTRING sceme;                      // sizeof 14h    offset 1B8h
    zSTRING conditionFunc;              // sizeof 14h    offset 1CCh
    zSTRING onStateFuncName;            // sizeof 14h    offset 1E0h
    int state;                          // sizeof 04h    offset 1F4h
    int state_num;                      // sizeof 04h    offset 1F8h
    int state_target;                   // sizeof 04h    offset 1FCh
    int rewind;                         // sizeof 04h    offset 200h
    int mobStateAni;                    // sizeof 04h    offset 204h
    int npcStateAni;                    // sizeof 04h    offset 208h
    int npcsMax     : 8;                // sizeof 08h    offset bit
    int npcsNeeded  : 8;                // sizeof 08h    offset bit
    int npcsCurrent : 8;                // sizeof 08h    offset bit
    int tmpState    : 8;                // sizeof 08h    offset bit
    int tmpStateChanged;                // sizeof 04h    offset 210h
    TMobInterDirection Direction;       // sizeof 04h    offset 214h
    int onInterruptReturnToSlotPos : 1; // sizeof 01h    offset bit
    zVEC3 startPos;                     // sizeof 0Ch    offset 21Ch
    float aniCombHeight;                // sizeof 04h    offset 228h
    zCVob* inUseVob;                    // sizeof 04h    offset 22Ch
    float timerEnd;                     // sizeof 04h    offset 230h

    void oCMobInter_OnInit()                                              zCall( 0x006BEF80 );
    oCMobInter()                                                          zInit( oCMobInter_OnInit() );
    void SetTempState( int )                                              zCall( 0x006BF4B0 );
    int IsTempStateChanged()                                              zCall( 0x006BF4F0 );
    void SetStateToTempState()                                            zCall( 0x006BF500 );
    void SetMobBodyState( oCNpc* )                                        zCall( 0x006BF580 );
    int HasUseWithItem( oCNpc* )                                          zCall( 0x006BFAD0 );
    void ScanIdealPositions()                                             zCall( 0x006BFBA0 );
    int GetFreePosition( oCNpc*, zVEC3& )                                 zCall( 0x006BFEC0 );
    void SetHeading( oCNpc* )                                             zCall( 0x006C0160 );
    void SetIdealPosition( oCNpc* )                                       zCall( 0x006C01B0 );
    void SendStateChange( int, int )                                      zCall( 0x006C0D00 );
    void SendEndInteraction( oCNpc*, int, int )                           zCall( 0x006C0FF0 );
    void StartTransitionAniNpc( oCNpc*, zSTRING const& )                  zCall( 0x006C20C0 );
    int IsMultiMob()                                                      zCall( 0x006C2E20 );
    int IsAvailable( oCNpc* )                                             zCall( 0x006C2E30 );
    void MarkAsUsed( float, zCVob* )                                      zCall( 0x006C2E90 );
    static zCObject* _CreateNewInstance()                                 zCall( 0x006BA750 );
    static int SetAllMobsToState( oCWorld*, zSTRING const&, int )         zCall( 0x006BEC40 );
    static void TraverseMobs( zCTree<zCVob>*, zSTRING const&, int, int* ) zCall( 0x006BEC70 );
    static void TriggerAllMobsToTmpState( zCWorld* )                      zCall( 0x006BEE00 );
    static void TraverseTriggerMobs( zCTree<zCVob>* )                     zCall( 0x006BEEC0 );
    virtual zCClassDef* _GetClassDef() const                              zCall( 0x006BF100 );
    virtual void Archive( zCArchiver& )                                   zCall( 0x006C4280 );
    virtual void Unarchive( zCArchiver& )                                 zCall( 0x006C4320 );
    virtual ~oCMobInter()                                                 zCall( 0x006BF140 );
    virtual void OnTrigger( zCVob*, zCVob* )                              zCall( 0x006C0740 );
    virtual void OnUntrigger( zCVob*, zCVob* )                            zCall( 0x006C0A30 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )     zCall( 0x006BF8B0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                     zCall( 0x006BF8C0 );
    virtual void OnTick()                                                 zCall( 0x006C06C0 );
    virtual void SetVisual( zCVisual* )                                   zCall( 0x006BF330 );
    virtual zSTRING const* GetTriggerTarget( int ) const                  zCall( 0x006BAC50 );
    virtual zSTRING GetScemeName()                                        zCall( 0x006BFB50 );
    virtual int GetState()                                                zCall( 0x006BABF0 );
    virtual int GetStateNum()                                             zCall( 0x006BAC00 );
    virtual TMobInterDirection GetDirection()                             zCall( 0x006BAC10 );
    virtual void SetDirection( TMobInterDirection )                       zCall( 0x006BAC20 );
    virtual void SetUseWithItem( zSTRING const& )                         zCall( 0x006BF970 );
    virtual int GetUseWithItem()                                          zCall( 0x006BFAB0 );
    virtual void Reset()                                                  zCall( 0x006C0400 );
    virtual void Interact( oCNpc*, int, int, int, int, int )              zCall( 0x006C1180 );
    virtual void EndInteraction( oCNpc*, int )                            zCall( 0x006C38C0 );
    virtual void InterruptInteraction( oCNpc* )                           zCall( 0x006C2C50 );
    virtual void StopInteraction( oCNpc* )                                zCall( 0x006C3B90 );
    virtual int CanInteractWith( oCNpc* )                                 zCall( 0x006C2EB0 );
    virtual int IsInteractingWith( oCNpc* )                               zCall( 0x006C34C0 );
    virtual int IsOccupied()                                              zCall( 0x006BAC30 );
    virtual int AI_UseMobToState( oCNpc*, int )                           zCall( 0x006C3E70 );
    virtual int IsIn( int )                                               zCall( 0x006BAC40 );
    virtual int IsInState( oCNpc*, int )                                  zCall( 0x006C1A70 );
    virtual void StartInteraction( oCNpc* )                               zCall( 0x006C34F0 );
    virtual void StartStateChange( oCNpc*, int, int )                     zCall( 0x006C1E10 );
    virtual void CheckStateChange( oCNpc* )                               zCall( 0x006C23B0 );
    virtual int CanChangeState( oCNpc*, int, int )                        zCall( 0x006C1BB0 );
    virtual void GetTransitionNames( int, int, zSTRING&, zSTRING& )       zCall( 0x006C1550 );
    virtual void OnBeginStateChange( oCNpc*, int, int )                   zCall( 0x006C2BE0 );
    virtual void OnEndStateChange( oCNpc*, int, int )                     zCall( 0x006C2BF0 );
    virtual void CallOnStateFunc( oCNpc*, int )                           zCall( 0x006C27E0 );
    virtual void SendCallOnStateFunc( oCNpc*, int )                       zCall( 0x006C2A40 );
    virtual TMobOptPos* SearchFreePosition( oCNpc*, float )               zCall( 0x006BFF30 );

    // user API
    #include "oCMobInter.inl"
  };

  // sizeof 248h
  class oCMobBed : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobBed )

    zSTRING addName; // sizeof 14h    offset 234h

    void oCMobBed_OnInit()                                  zCall( 0x006C4DC0 );
    oCMobBed()                                              zInit( oCMobBed_OnInit() );
    static zCObject* _CreateNewInstance()                   zCall( 0x006BA9C0 );
    virtual zCClassDef* _GetClassDef() const                zCall( 0x006BAC90 );
    virtual ~oCMobBed()                                     zCall( 0x006C4FB0 );
    virtual zSTRING GetScemeName()                          zCall( 0x006C5210 );
    virtual void StartInteraction( oCNpc* )                 zCall( 0x006C5190 );
    virtual void OnBeginStateChange( oCNpc*, int, int )     zCall( 0x006C51A0 );
    virtual void OnEndStateChange( oCNpc*, int, int )       zCall( 0x006C51B0 );
    virtual TMobOptPos* SearchFreePosition( oCNpc*, float ) zCall( 0x006C52C0 );

    // user API
    #include "oCMobBed.inl"
  };

  // sizeof 234h
  class oCMobSwitch : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobSwitch )

    void oCMobSwitch_OnInit()                zCall( 0x006C5450 );
    oCMobSwitch()                            zInit( oCMobSwitch_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x006BAE90 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x006BAFD0 );
    virtual void Archive( zCArchiver& )      zCall( 0x006C5740 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x006C57E0 );
    virtual ~oCMobSwitch()                   zCall( 0x006C5570 );

    // user API
    #include "oCMobSwitch.inl"
  };

  // sizeof 23Ch
  class oCMobItemSlot : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobItemSlot )

    oCItem* insertedItem; // sizeof 04h    offset 234h
    int removeable;       // sizeof 04h    offset 238h

    void oCMobItemSlot_OnInit()              zCall( 0x006C9DF0 );
    oCMobItemSlot()                          zInit( oCMobItemSlot_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x006BC9C0 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x006BCA70 );
    virtual void Archive( zCArchiver& )      zCall( 0x006CA3A0 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x006CA470 );
    virtual ~oCMobItemSlot()                 zCall( 0x006C9E40 );
    virtual int GetUseWithItem()             zCall( 0x006CA020 );
    virtual int CanInteractWith( oCNpc* )    zCall( 0x006CA060 );
    virtual int IsIn( int )                  zCall( 0x006CA370 );
    virtual oCItem* GetInsertedItem()        zCall( 0x006CA080 );
    virtual int PlaceItem( oCItem* )         zCall( 0x006CA090 );
    virtual oCItem* RemoveItem()             zCall( 0x006CA330 );

    // user API
    #include "oCMobItemSlot.inl"
  };

  // sizeof 260h
  class oCMobLockable : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobLockable )

    int locked     : 1;  // sizeof 01h    offset bit
    int autoOpen   : 1;  // sizeof 01h    offset bit
    int pickLockNr : 30; // sizeof 1Eh    offset bit
    zSTRING keyInstance; // sizeof 14h    offset 238h
    zSTRING pickLockStr; // sizeof 14h    offset 24Ch

    void oCMobLockable_OnInit()                              zCall( 0x006C5890 );
    oCMobLockable()                                          zInit( oCMobLockable_OnInit() );
    int CanOpen( oCNpc* )                                    zCall( 0x006C6460 );
    virtual zCClassDef* _GetClassDef() const                 zCall( 0x006BB580 );
    virtual void Archive( zCArchiver& )                      zCall( 0x006C7320 );
    virtual void Unarchive( zCArchiver& )                    zCall( 0x006C7410 );
    virtual ~oCMobLockable()                                 zCall( 0x006C5A70 );
    virtual void OnMessage( zCEventMessage*, zCVob* )        zCall( 0x006BB830 );
    virtual void Interact( oCNpc*, int, int, int, int, int ) zCall( 0x006C5C60 );
    virtual int CanInteractWith( oCNpc* )                    zCall( 0x006C5C30 );
    virtual int CanChangeState( oCNpc*, int, int )           zCall( 0x006C6250 );
    virtual void OnEndStateChange( oCNpc*, int, int )        zCall( 0x006C62A0 );
    virtual void SetLocked( int )                            zCall( 0x006BB590 );
    virtual void SetKeyInstance( zSTRING const& )            zCall( 0x006BB5B0 );
    virtual void SetPickLockStr( zSTRING const& )            zCall( 0x006BB6F0 );
    virtual void Open( oCNpc* )                              zPureCall;
    virtual void Close( oCNpc* )                             zPureCall;
    virtual void Lock( oCNpc* )                              zCall( 0x006C7130 );
    virtual void Unlock( oCNpc*, int )                       zCall( 0x006C69E0 );
    virtual int PickLock( oCNpc*, char )                     zCall( 0x006C6770 );

    // user API
    #include "oCMobLockable.inl"
  };

  // sizeof 284h
  class oCMobContainer : public oCMobLockable {
  public:
    zCLASS_DECLARATION( oCMobContainer )

    zSTRING contains;               // sizeof 14h    offset 260h
    oCItemContainer* items;         // sizeof 04h    offset 274h
    zCListSort<oCItem> containList; // sizeof 0Ch    offset 278h

    void oCMobContainer_OnInit()                      zCall( 0x006C7750 );
    oCMobContainer()                                  zInit( oCMobContainer_OnInit() );
    static zCObject* _CreateNewInstance()             zCall( 0x006BB3B0 );
    virtual zCClassDef* _GetClassDef() const          zCall( 0x006BB900 );
    virtual void Archive( zCArchiver& )               zCall( 0x006C85F0 );
    virtual void Unarchive( zCArchiver& )             zCall( 0x006C8790 );
    virtual ~oCMobContainer()                         zCall( 0x006C7910 );
    virtual void OnMessage( zCEventMessage*, zCVob* ) zCall( 0x006C7B20 );
    virtual void Destroy()                            zCall( 0x006C7C20 );
    virtual void Reset()                              zCall( 0x006C7DD0 );
    virtual int IsIn( int )                           zCall( 0x006C8430 );
    virtual void Open( oCNpc* )                       zCall( 0x006C8470 );
    virtual void Close( oCNpc* )                      zCall( 0x006C85B0 );
    virtual void Insert( oCItem* )                    zCall( 0x006C7F30 );
    virtual void Remove( oCItem* )                    zCall( 0x006C7F60 );
    virtual oCItem* Remove( oCItem*, int )            zCall( 0x006C7FF0 );
    virtual void CreateContents( zSTRING const& )     zCall( 0x006C8100 );

    // user API
    #include "oCMobContainer.inl"
  };

  // sizeof 274h
  class oCMobDoor : public oCMobLockable {
  public:
    zCLASS_DECLARATION( oCMobDoor )

    zSTRING addName; // sizeof 14h    offset 260h

    void oCMobDoor_OnInit()                                 zCall( 0x006C8920 );
    oCMobDoor()                                             zInit( oCMobDoor_OnInit() );
    static zCObject* _CreateNewInstance()                   zCall( 0x006BC1C0 );
    virtual zCClassDef* _GetClassDef() const                zCall( 0x006BC390 );
    virtual ~oCMobDoor()                                    zCall( 0x006C8B20 );
    virtual zSTRING GetScemeName()                          zCall( 0x006C8CD0 );
    virtual TMobOptPos* SearchFreePosition( oCNpc*, float ) zCall( 0x006C8D80 );
    virtual void Open( oCNpc* )                             zCall( 0x006BC3A0 );
    virtual void Close( oCNpc* )                            zCall( 0x006BC3B0 );

    // user API
    #include "oCMobDoor.inl"
  };

  // sizeof 260h
  class oCMobFire : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobFire )

    zSTRING fireSlot;        // sizeof 14h    offset 234h
    zSTRING fireVobtreeName; // sizeof 14h    offset 248h
    zCVob* fireVobtree;      // sizeof 04h    offset 25Ch

    void oCMobFire_OnInit()                                           zCall( 0x006C43D0 );
    oCMobFire()                                                       zInit( oCMobFire_OnInit() );
    void DeleteEffects()                                              zCall( 0x006C47C0 );
    static zCObject* _CreateNewInstance()                             zCall( 0x006BC5B0 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x006BC7C0 );
    virtual void Archive( zCArchiver& )                               zCall( 0x006C4BD0 );
    virtual void Unarchive( zCArchiver& )                             zCall( 0x006C4CE0 );
    virtual ~oCMobFire()                                              zCall( 0x006C45E0 );
    virtual void OnTrigger( zCVob*, zCVob* )                          zCall( 0x006C48F0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                        zCall( 0x006C4B00 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& ) zCall( 0x006C4810 );
    virtual void OnEndStateChange( oCNpc*, int, int )                 zCall( 0x006C4860 );
    virtual void PreSave()                                            zCall( 0x006C4B70 );
    virtual void PostSave()                                           zCall( 0x006C4CB0 );

    // user API
    #include "oCMobFire.inl"
  };

  // sizeof 234h
  class oCMobWheel : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobWheel )

    void oCMobWheel_OnInit()                                 zCall( 0x006C8F10 );
    oCMobWheel()                                             zInit( oCMobWheel_OnInit() );
    static zCObject* _CreateNewInstance()                    zCall( 0x006BBB00 );
    virtual zCClassDef* _GetClassDef() const                 zCall( 0x006BBC50 );
    virtual ~oCMobWheel()                                    zCall( 0x006C9260 );
    virtual void OnTrigger( zCVob*, zCVob* )                 zCall( 0x006C9040 );
    virtual void OnUntrigger( zCVob*, zCVob* )               zCall( 0x006C9150 );
    virtual void Interact( oCNpc*, int, int, int, int, int ) zCall( 0x006C9250 );

    // user API
    #include "oCMobWheel.inl"
  };

  // sizeof 23Ch
  class oCMobLadder : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobLadder )

    int Interacting; // sizeof 04h    offset 234h
    int PrevAction;  // sizeof 04h    offset 238h

    void oCMobLadder_OnInit()                                zCall( 0x006C9430 );
    oCMobLadder()                                            zInit( oCMobLadder_OnInit() );
    static zCObject* _CreateNewInstance()                    zCall( 0x006BBE50 );
    virtual zCClassDef* _GetClassDef() const                 zCall( 0x006BBFB0 );
    virtual ~oCMobLadder()                                   zCall( 0x006C9570 );
    virtual int DoFocusCheckBBox()                           zCall( 0x006BBFC0 );
    virtual void Interact( oCNpc*, int, int, int, int, int ) zCall( 0x006C99D0 );
    virtual void EndInteraction( oCNpc*, int )               zCall( 0x006C9DD0 );
    virtual int CanInteractWith( oCNpc* )                    zCall( 0x006C9950 );
    virtual void StartInteraction( oCNpc* )                  zCall( 0x006C9740 );
    virtual int CanChangeState( oCNpc*, int, int )           zCall( 0x006C9900 );
    virtual TMobOptPos* SearchFreePosition( oCNpc*, float )  zCall( 0x006C9960 );

    // user API
    #include "oCMobLadder.inl"
  };

  // sizeof 120h
  class oCDummyVobGenerator : public zCVob {
  public:
    zCLASS_DECLARATION( oCDummyVobGenerator )

    void oCDummyVobGenerator_OnInit()        zCall( 0x006CA560 );
    oCDummyVobGenerator()                    zInit( oCDummyVobGenerator_OnInit() );
    static zCObject* _CreateNewInstance()    zCall( 0x006BCC70 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x006BCD30 );
    virtual ~oCDummyVobGenerator()           zCall( 0x006BCD70 );
    virtual void OnTrigger( zCVob*, zCVob* ) zCall( 0x006CA5D0 );

    // user API
    #include "oCDummyVobGenerator.inl"
  };

  // sizeof 38h
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

    oCNpc* npc;       // sizeof 04h    offset 2Ch
    int from;         // sizeof 04h    offset 30h
    int to      : 31; // sizeof 1Fh    offset bit
    int playAni : 1;  // sizeof 01h    offset bit

    void oCMobMsg_OnInit( TMobMsgSubType, oCNpc* )      zCall( 0x006BD190 );
    void oCMobMsg_OnInit()                              zCall( 0x006BD310 );
    void oCMobMsg_OnInit( TMobMsgSubType, oCNpc*, int ) zCall( 0x006BD440 );
    oCMobMsg( TMobMsgSubType a0, oCNpc* a1 )            zInit( oCMobMsg_OnInit( a0, a1 ));
    oCMobMsg()                                          zInit( oCMobMsg_OnInit() );
    oCMobMsg( TMobMsgSubType a0, oCNpc* a1, int a2 )    zInit( oCMobMsg_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()               zCall( 0x006BCFA0 );
    virtual zCClassDef* _GetClassDef() const            zCall( 0x006BD170 );
    virtual ~oCMobMsg()                                 zCall( 0x006BD300 );
    virtual int IsNetRelevant()                         zCall( 0x006BD180 );
    virtual int MD_GetNumOfSubTypes()                   zCall( 0x006BD6B0 );
    virtual zSTRING MD_GetSubTypeString( int )          zCall( 0x006BD6C0 );
    virtual void Pack( zCBuffer&, zCEventManager* )     zCall( 0x006BD590 );
    virtual void Unpack( zCBuffer&, zCEventManager* )   zCall( 0x006BD610 );

    // user API
    #include "oCMobMsg.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OMOB_INTER_H__VER2__