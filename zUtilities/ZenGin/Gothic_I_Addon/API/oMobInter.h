// Supported with union (c) 2018-2021 Union team

#ifndef __OMOB_INTER_H__VER1__
#define __OMOB_INTER_H__VER1__

#include "oVob.h"
#include "oItem.h"
#include "oNpc.h"
#include "zModel.h"

namespace Gothic_I_Addon {

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

  // sizeof 168h
  class oCMOB : public oCVob {
  public:
    zCLASS_DECLARATION( oCMOB )

    zSTRING name;                // sizeof 14h    offset 100h
    int hitp             : 12;   // sizeof 0Ch    offset bit
    int damage           : 12;   // sizeof 0Ch    offset bit
    int isDestroyed      : 1;    // sizeof 01h    offset bit
    int moveable         : 1;    // sizeof 01h    offset bit
    int takeable         : 1;    // sizeof 01h    offset bit
    int focusOverride    : 1;    // sizeof 01h    offset bit
    oTSndMaterial sndMat : 3;    // sizeof 03h    offset bit
    zSTRING visualDestroyed;     // sizeof 14h    offset 118h
    zSTRING ownerStr;            // sizeof 14h    offset 12Ch
    zSTRING ownerGuildStr;       // sizeof 14h    offset 140h
    int owner;                   // sizeof 04h    offset 154h
    int ownerGuild;              // sizeof 04h    offset 158h
    int focusNameIndex;          // sizeof 04h    offset 15Ch
    zCList<zCVob> ignoreVobList; // sizeof 08h    offset 160h

    void oCMOB_OnInit()                                                                      zCall( 0x006A8D90 );
    oCMOB()                                                                                  zInit( oCMOB_OnInit() );
    void SetMoveable( int )                                                                  zCall( 0x006A9430 );
    int IsMoveable()                                                                         zCall( 0x006A9460 );
    void SetOwner( zSTRING const&, zSTRING const& )                                          zCall( 0x006A94D0 );
    void SetOwner( int, int )                                                                zCall( 0x006A96C0 );
    int IsOwner( oCNpc* )                                                                    zCall( 0x006A9720 );
    void Hit( int )                                                                          zCall( 0x006A9770 );
    void InsertInIgnoreList( zCVob* )                                                        zCall( 0x006A9A20 );
    void RemoveFromIgnoreList( zCVob* )                                                      zCall( 0x006A9A50 );
    static zCObject* _CreateNewInstance()                                                    zCall( 0x006A5900 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x006A8EC0 );
    virtual void Archive( zCArchiver& )                                                      zCall( 0x006A9B00 );
    virtual void Unarchive( zCArchiver& )                                                    zCall( 0x006A9C40 );
    virtual ~oCMOB()                                                                         zCall( 0x006A8F00 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )                        zCall( 0x006A93F0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                        zCall( 0x006A9400 );
    virtual int CanThisCollideWith( zCVob* )                                                 zCall( 0x006A9AC0 );
    virtual void SetVisual( zCVisual* )                                                      zCall( 0x006A90A0 );
    virtual int IsOwnedByGuild( int )                                                        zCall( 0x006A96E0 );
    virtual int IsOwnedByNpc( int )                                                          zCall( 0x006A9700 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int ) zCall( 0x006A94B0 );
    virtual void SetSoundMaterial( oTSndMaterial )                                           zCall( 0x006A9470 );
    virtual oTSndMaterial GetSoundMaterial()                                                 zCall( 0x006A94A0 );
    virtual void SetName( zSTRING const& )                                                   zCall( 0x006A90C0 );
    virtual zSTRING GetName()                                                                zCall( 0x006A90E0 );
    virtual zCModel* GetModel()                                                              zCall( 0x006A9410 );
    virtual zSTRING GetScemeName()                                                           zCall( 0x006A91E0 );
    virtual void Destroy()                                                                   zCall( 0x006A9780 );
    virtual int AllowDiscardingOfSubtree()                                                   zCall( 0x006AA2D0 );

    // user API
    #include "oCMOB.inl"
  };

  // sizeof 220h
  class oCMobInter : public oCMOB {
  public:
    zCLASS_DECLARATION( oCMobInter )

    enum TMobInterDirection {
      MOBINTER_DIRECTION_NONE,
      MOBINTER_DIRECTION_UP,
      MOBINTER_DIRECTION_DOWN
    };

    zCList<TMobOptPos> optimalPosList;  // sizeof 08h    offset 168h
    zSTRING triggerTarget;              // sizeof 14h    offset 170h
    zSTRING useWithItem;                // sizeof 14h    offset 184h
    zSTRING sceme;                      // sizeof 14h    offset 198h
    zSTRING conditionFunc;              // sizeof 14h    offset 1ACh
    zSTRING onStateFuncName;            // sizeof 14h    offset 1C0h
    int state;                          // sizeof 04h    offset 1D4h
    int state_num;                      // sizeof 04h    offset 1D8h
    int state_target;                   // sizeof 04h    offset 1DCh
    int rewind;                         // sizeof 04h    offset 1E0h
    zVEC3 lastHeading;                  // sizeof 0Ch    offset 1E4h
    int mobStateAni;                    // sizeof 04h    offset 1F0h
    int npcStateAni;                    // sizeof 04h    offset 1F4h
    int npcsMax     : 8;                // sizeof 08h    offset bit
    int npcsNeeded  : 8;                // sizeof 08h    offset bit
    int npcsCurrent : 8;                // sizeof 08h    offset bit
    int tmpState    : 8;                // sizeof 08h    offset bit
    int tmpStateChanged;                // sizeof 04h    offset 1FCh
    TMobInterDirection Direction;       // sizeof 04h    offset 200h
    int onInterruptReturnToSlotPos : 1; // sizeof 01h    offset bit
    zVEC3 startPos;                     // sizeof 0Ch    offset 208h
    float aniCombHeight;                // sizeof 04h    offset 214h
    zCVob* inUseVob;                    // sizeof 04h    offset 218h
    float timerEnd;                     // sizeof 04h    offset 21Ch

    void oCMobInter_OnInit()                                            zCall( 0x006AA630 );
    oCMobInter()                                                        zInit( oCMobInter_OnInit() );
    void SetTempState( int )                                            zCall( 0x006AABB0 );
    int IsTempStateChanged()                                            zCall( 0x006AABF0 );
    void SetStateToTempState()                                          zCall( 0x006AAC00 );
    void SetMobBodyState( oCNpc* )                                      zCall( 0x006AAC90 );
    int HasUseWithItem( oCNpc* )                                        zCall( 0x006AB1C0 );
    void ScanIdealPositions()                                           zCall( 0x006AB290 );
    int GetFreePosition( oCNpc*, zVEC3& )                               zCall( 0x006AB640 );
    void SetHeading( oCNpc* )                                           zCall( 0x006AB990 );
    void SetIdealPosition( oCNpc* )                                     zCall( 0x006AB9E0 );
    void SendStateChange( int, int )                                    zCall( 0x006AC5B0 );
    void SendEndInteraction( oCNpc*, int, int )                         zCall( 0x006AC8C0 );
    void StartTransitionAniNpc( oCNpc*, zSTRING const& )                zCall( 0x006AD920 );
    int IsMultiMob()                                                    zCall( 0x006AE690 );
    int IsAvailable( oCNpc* )                                           zCall( 0x006AE6B0 );
    void MarkAsUsed( float, zCVob* )                                    zCall( 0x006AE710 );
    static zCObject* _CreateNewInstance()                               zCall( 0x006A5B70 );
    static int SetAllMobsToState( oCWorld*, zSTRING const&, int )       zCall( 0x006AA2E0 );
    static int TraverseMobs( zCTree<zCVob>*, zSTRING const&, int, int ) zCall( 0x006AA300 );
    static void TriggerAllMobsToTmpState( zCWorld* )                    zCall( 0x006AA490 );
    static void TraverseTriggerMobs( zCTree<zCVob>* )                   zCall( 0x006AA560 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006AA7B0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006AFC20 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006AFCC0 );
    virtual ~oCMobInter()                                               zCall( 0x006AA7F0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x006ABF70 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x006AC2A0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )   zCall( 0x006AAFA0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x006AAFB0 );
    virtual void OnTick()                                               zCall( 0x006ABEE0 );
    virtual void SetVisual( zCVisual* )                                 zCall( 0x006AAA10 );
    virtual zSTRING const* GetTriggerTarget( int ) const                zCall( 0x006A6060 );
    virtual zSTRING GetScemeName()                                      zCall( 0x006AB240 );
    virtual int GetState()                                              zCall( 0x006A5FF0 );
    virtual int GetStateNum()                                           zCall( 0x006A6000 );
    virtual TMobInterDirection GetDirection()                           zCall( 0x006A6010 );
    virtual void SetDirection( TMobInterDirection )                     zCall( 0x006A6020 );
    virtual void SetUseWithItem( zSTRING const& )                       zCall( 0x006AB060 );
    virtual int GetUseWithItem()                                        zCall( 0x006AB1A0 );
    virtual void Reset()                                                zCall( 0x006ABC70 );
    virtual void Interact( oCNpc*, int, int, int, int, int )            zCall( 0x006ACA60 );
    virtual void EndInteraction( oCNpc*, int )                          zCall( 0x006AF1D0 );
    virtual void InterruptInteraction( oCNpc* )                         zCall( 0x006AE470 );
    virtual void StopInteraction( oCNpc* )                              zCall( 0x006AF4B0 );
    virtual int CanInteractWith( oCNpc* )                               zCall( 0x006AE730 );
    virtual int IsInteractingWith( oCNpc* )                             zCall( 0x006AEDB0 );
    virtual int IsOccupied()                                            zCall( 0x006A6030 );
    virtual int AI_UseMobToState( oCNpc*, int )                         zCall( 0x006AF7D0 );
    virtual int IsIn( int )                                             zCall( 0x006A6050 );
    virtual int IsInState( oCNpc*, int )                                zCall( 0x006AD2F0 );
    virtual void StartInteraction( oCNpc* )                             zCall( 0x006AEDE0 );
    virtual void StartStateChange( oCNpc*, int, int )                   zCall( 0x006AD670 );
    virtual void CheckStateChange( oCNpc* )                             zCall( 0x006ADC50 );
    virtual int CanChangeState( oCNpc*, int, int )                      zCall( 0x006AD420 );
    virtual void GetTransitionNames( int, int, zSTRING&, zSTRING& )     zCall( 0x006ACDE0 );
    virtual void OnBeginStateChange( oCNpc*, int, int )                 zCall( 0x006AE400 );
    virtual void OnEndStateChange( oCNpc*, int, int )                   zCall( 0x006AE410 );
    virtual void CallOnStateFunc( oCNpc*, int )                         zCall( 0x006AE040 );
    virtual void SendCallOnStateFunc( oCNpc*, int )                     zCall( 0x006AE250 );
    virtual TMobOptPos* SearchFreePosition( oCNpc*, float )             zCall( 0x006AB6C0 );

    // user API
    #include "oCMobInter.inl"
  };

  // sizeof 234h
  class oCMobBed : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobBed )

    zSTRING addName; // sizeof 14h    offset 220h

    void oCMobBed_OnInit()                                              zCall( 0x006B07B0 );
    oCMobBed()                                                          zInit( oCMobBed_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x006A5E00 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006A60A0 );
    virtual ~oCMobBed()                                                 zCall( 0x006B09A0 );
    virtual zSTRING GetScemeName()                                      zCall( 0x006B0C40 );
    virtual void StartInteraction( oCNpc* )                             zCall( 0x006B0BC0 );
    virtual void OnBeginStateChange( oCNpc*, int, int )                 zCall( 0x006B0BD0 );
    virtual void OnEndStateChange( oCNpc*, int, int )                   zCall( 0x006B0BE0 );
    virtual TMobOptPos* SearchFreePosition( oCNpc*, float )             zCall( 0x006B0CF0 );

    // user API
    #include "oCMobBed.inl"
  };

  // sizeof 220h
  class oCMobSwitch : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobSwitch )

    void oCMobSwitch_OnInit()                                           zCall( 0x006B0E80 );
    oCMobSwitch()                                                       zInit( oCMobSwitch_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x006A62B0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006A6400 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006B11B0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006B1250 );
    virtual ~oCMobSwitch()                                              zCall( 0x006B0FA0 );

    // user API
    #include "oCMobSwitch.inl"
  };

  // sizeof 228h
  class oCMobItemSlot : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobItemSlot )

    oCItem* insertedItem; // sizeof 04h    offset 220h
    int removeable;       // sizeof 04h    offset 224h

    void oCMobItemSlot_OnInit()                                         zCall( 0x006B5B00 );
    oCMobItemSlot()                                                     zInit( oCMobItemSlot_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x006A7EE0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006A7FA0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006B6140 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006B6210 );
    virtual ~oCMobItemSlot()                                            zCall( 0x006B5B50 );
    virtual int GetUseWithItem()                                        zCall( 0x006B5D60 );
    virtual int CanInteractWith( oCNpc* )                               zCall( 0x006B5DA0 );
    virtual int IsIn( int )                                             zCall( 0x006B6110 );
    virtual oCItem* GetInsertedItem()                                   zCall( 0x006B5DC0 );
    virtual int PlaceItem( oCItem* )                                    zCall( 0x006B5DD0 );
    virtual oCItem* RemoveItem()                                        zCall( 0x006B60D0 );

    // user API
    #include "oCMobItemSlot.inl"
  };

  // sizeof 24Ch
  class oCMobLockable : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobLockable )

    int locked     : 1;  // sizeof 01h    offset bit
    int autoOpen   : 1;  // sizeof 01h    offset bit
    int pickLockNr : 30; // sizeof 1Eh    offset bit
    zSTRING keyInstance; // sizeof 14h    offset 224h
    zSTRING pickLockStr; // sizeof 14h    offset 238h

    void oCMobLockable_OnInit()                              zCall( 0x006B1300 );
    oCMobLockable()                                          zInit( oCMobLockable_OnInit() );
    int CanOpen( oCNpc* )                                    zCall( 0x006B1F20 );
    virtual zCClassDef* _GetClassDef() const                 zCall( 0x006A6A00 );
    virtual void Archive( zCArchiver& )                      zCall( 0x006B2FE0 );
    virtual void Unarchive( zCArchiver& )                    zCall( 0x006B30D0 );
    virtual ~oCMobLockable()                                 zCall( 0x006B14D0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )        zCall( 0x006A6CB0 );
    virtual void Interact( oCNpc*, int, int, int, int, int ) zCall( 0x006B16F0 );
    virtual int CanInteractWith( oCNpc* )                    zCall( 0x006B16C0 );
    virtual int CanChangeState( oCNpc*, int, int )           zCall( 0x006B1D00 );
    virtual void OnEndStateChange( oCNpc*, int, int )        zCall( 0x006B1D50 );
    virtual void SetLocked( int )                            zCall( 0x006A6A10 );
    virtual void SetKeyInstance( zSTRING const& )            zCall( 0x006A6A30 );
    virtual void SetPickLockStr( zSTRING const& )            zCall( 0x006A6B70 );
    virtual void Open( oCNpc* )                              zPureCall;
    virtual void Close( oCNpc* )                             zPureCall;
    virtual void Lock( oCNpc* )                              zCall( 0x006B2DB0 );
    virtual void Unlock( oCNpc*, int )                       zCall( 0x006B25E0 );
    virtual int PickLock( oCNpc*, char )                     zCall( 0x006B2260 );

    // user API
    #include "oCMobLockable.inl"
  };

  // sizeof 270h
  class oCMobContainer : public oCMobLockable {
  public:
    zCLASS_DECLARATION( oCMobContainer )

    zSTRING contains;               // sizeof 14h    offset 24Ch
    oCItemContainer* items;         // sizeof 04h    offset 260h
    zCListSort<oCItem> containList; // sizeof 0Ch    offset 264h

    void oCMobContainer_OnInit()                                        zCall( 0x006B31E0 );
    oCMobContainer()                                                    zInit( oCMobContainer_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x006A6810 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006A6D80 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006B40C0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006B4260 );
    virtual ~oCMobContainer()                                           zCall( 0x006B33B0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x006B35E0 );
    virtual void Destroy()                                              zCall( 0x006B36E0 );
    virtual void Reset()                                                zCall( 0x006B38A0 );
    virtual int IsIn( int )                                             zCall( 0x006B3F60 );
    virtual void Open( oCNpc* )                                         zCall( 0x006B3FA0 );
    virtual void Close( oCNpc* )                                        zCall( 0x006B4080 );
    virtual void Insert( oCItem* )                                      zCall( 0x006B3A00 );
    virtual void Remove( oCItem* )                                      zCall( 0x006B3A30 );
    virtual oCItem* Remove( oCItem*, int )                              zCall( 0x006B3AB0 );
    virtual void CreateContents( zSTRING const& )                       zCall( 0x006B3BC0 );

    // user API
    #include "oCMobContainer.inl"
  };

  // sizeof 260h
  class oCMobDoor : public oCMobLockable {
  public:
    zCLASS_DECLARATION( oCMobDoor )

    zSTRING addName; // sizeof 14h    offset 24Ch

    void oCMobDoor_OnInit()                                             zCall( 0x006B44E0 );
    oCMobDoor()                                                         zInit( oCMobDoor_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x006A7690 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006A7880 );
    virtual ~oCMobDoor()                                                zCall( 0x006B46F0 );
    virtual zSTRING GetScemeName()                                      zCall( 0x006B48B0 );
    virtual TMobOptPos* SearchFreePosition( oCNpc*, float )             zCall( 0x006B4960 );
    virtual void Open( oCNpc* )                                         zCall( 0x006A7890 );
    virtual void Close( oCNpc* )                                        zCall( 0x006A78A0 );

    // user API
    #include "oCMobDoor.inl"
  };

  // sizeof 24Ch
  class oCMobFire : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobFire )

    zSTRING fireSlot;        // sizeof 14h    offset 220h
    zSTRING fireVobtreeName; // sizeof 14h    offset 234h
    zCVob* fireVobtree;      // sizeof 04h    offset 248h

    void oCMobFire_OnInit()                                             zCall( 0x006AFD70 );
    oCMobFire()                                                         zInit( oCMobFire_OnInit() );
    void DeleteEffects()                                                zCall( 0x006B0180 );
    static zCObject* _CreateNewInstance()                               zCall( 0x006A7AB0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006A7CD0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006B05C0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006B06D0 );
    virtual ~oCMobFire()                                                zCall( 0x006AFF80 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x006B02B0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x006B04F0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )   zCall( 0x006B01D0 );
    virtual void OnEndStateChange( oCNpc*, int, int )                   zCall( 0x006B0220 );
    virtual void PreSave()                                              zCall( 0x006B0560 );
    virtual void PostSave()                                             zCall( 0x006B06A0 );

    // user API
    #include "oCMobFire.inl"
  };

  // sizeof 220h
  class oCMobWheel : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobWheel )

    void oCMobWheel_OnInit()                                            zCall( 0x006B4AF0 );
    oCMobWheel()                                                        zInit( oCMobWheel_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x006A6F90 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006A70F0 );
    virtual ~oCMobWheel()                                               zCall( 0x006B4E80 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x006B4C20 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x006B4D40 );
    virtual void Interact( oCNpc*, int, int, int, int, int )            zCall( 0x006B4E50 );

    // user API
    #include "oCMobWheel.inl"
  };

  // sizeof 228h
  class oCMobLadder : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobLadder )

    int Interacting; // sizeof 04h    offset 220h
    int PrevAction;  // sizeof 04h    offset 224h

    void oCMobLadder_OnInit()                                           zCall( 0x006B5090 );
    oCMobLadder()                                                       zInit( oCMobLadder_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x006A7300 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006A7470 );
    virtual ~oCMobLadder()                                              zCall( 0x006B51D0 );
    virtual int DoFocusCheckBBox()                                      zCall( 0x006A7480 );
    virtual void Interact( oCNpc*, int, int, int, int, int )            zCall( 0x006B5690 );
    virtual void EndInteraction( oCNpc*, int )                          zCall( 0x006B5AE0 );
    virtual int CanInteractWith( oCNpc* )                               zCall( 0x006B5610 );
    virtual void StartInteraction( oCNpc* )                             zCall( 0x006B53E0 );
    virtual int CanChangeState( oCNpc*, int, int )                      zCall( 0x006B55C0 );
    virtual TMobOptPos* SearchFreePosition( oCNpc*, float )             zCall( 0x006B5620 );

    // user API
    #include "oCMobLadder.inl"
  };

  // sizeof 100h
  class oCDummyVobGenerator : public zCVob {
  public:
    zCLASS_DECLARATION( oCDummyVobGenerator )

    void oCDummyVobGenerator_OnInit()                                   zCall( 0x006B6300 );
    oCDummyVobGenerator()                                               zInit( oCDummyVobGenerator_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x006A81B0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006A8290 );
    virtual ~oCDummyVobGenerator()                                      zCall( 0x006A82D0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x006B6370 );

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

    void oCMobMsg_OnInit( TMobMsgSubType, oCNpc* )                      zCall( 0x006A86B0 );
    void oCMobMsg_OnInit()                                              zCall( 0x006A8830 );
    void oCMobMsg_OnInit( TMobMsgSubType, oCNpc*, int )                 zCall( 0x006A8970 );
    oCMobMsg( TMobMsgSubType a0, oCNpc* a1 )                            zInit( oCMobMsg_OnInit( a0, a1 ));
    oCMobMsg()                                                          zInit( oCMobMsg_OnInit() );
    oCMobMsg( TMobMsgSubType a0, oCNpc* a1, int a2 )                    zInit( oCMobMsg_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                               zCall( 0x006A8520 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x006A8690 );
    virtual ~oCMobMsg()                                                 zCall( 0x006A8820 );
    virtual int IsNetRelevant()                                         zCall( 0x006A86A0 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x006A8BE0 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x006A8BF0 );
    virtual void Pack( zCBuffer&, zCEventManager* )                     zCall( 0x006A8AC0 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                   zCall( 0x006A8B40 );

    // user API
    #include "oCMobMsg.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OMOB_INTER_H__VER1__