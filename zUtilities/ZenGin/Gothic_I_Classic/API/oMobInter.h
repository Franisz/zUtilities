// Supported with union (c) 2018-2021 Union team

#ifndef __OMOB_INTER_H__VER0__
#define __OMOB_INTER_H__VER0__

#include "oVob.h"
#include "oItem.h"
#include "oNpc.h"
#include "zModel.h"

namespace Gothic_I_Classic {

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

    void oCMOB_OnInit()                                                                      zCall( 0x0067A710 );
    oCMOB()                                                                                  zInit( oCMOB_OnInit() );
    void SetMoveable( int )                                                                  zCall( 0x0067AD20 );
    int IsMoveable()                                                                         zCall( 0x0067AD40 );
    void SetOwner( zSTRING const&, zSTRING const& )                                          zCall( 0x0067ADA0 );
    void SetOwner( int, int )                                                                zCall( 0x0067AF90 );
    int IsOwner( oCNpc* )                                                                    zCall( 0x0067AFF0 );
    void Hit( int )                                                                          zCall( 0x0067B040 );
    void InsertInIgnoreList( zCVob* )                                                        zCall( 0x0067B2D0 );
    void RemoveFromIgnoreList( zCVob* )                                                      zCall( 0x0067B300 );
    static zCObject* _CreateNewInstance()                                                    zCall( 0x00677470 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x0067A840 );
    virtual void Archive( zCArchiver& )                                                      zCall( 0x0067B3A0 );
    virtual void Unarchive( zCArchiver& )                                                    zCall( 0x0067B4E0 );
    virtual ~oCMOB()                                                                         zCall( 0x0067A880 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )                        zCall( 0x0067ACE0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                        zCall( 0x0067ACF0 );
    virtual int CanThisCollideWith( zCVob* )                                                 zCall( 0x0067B360 );
    virtual void SetVisual( zCVisual* )                                                      zCall( 0x0067AA10 );
    virtual int IsOwnedByGuild( int )                                                        zCall( 0x0067AFB0 );
    virtual int IsOwnedByNpc( int )                                                          zCall( 0x0067AFD0 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int ) zCall( 0x0067AD80 );
    virtual void SetSoundMaterial( oTSndMaterial )                                           zCall( 0x0067AD50 );
    virtual oTSndMaterial GetSoundMaterial()                                                 zCall( 0x0067AD70 );
    virtual void SetName( zSTRING const& )                                                   zCall( 0x0067AA30 );
    virtual zSTRING GetName()                                                                zCall( 0x0067AA50 );
    virtual zCModel* GetModel()                                                              zCall( 0x0067AD00 );
    virtual zSTRING GetScemeName()                                                           zCall( 0x0067AB20 );
    virtual void Destroy()                                                                   zCall( 0x0067B050 );
    virtual int AllowDiscardingOfSubtree()                                                   zCall( 0x0067BB00 );

    // user API
    #include "oCMOB.inl"
  };

  // sizeof 210h
  class oCMobInter : public oCMOB {
  public:
    zCLASS_DECLARATION( oCMobInter )

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
    int mobStateAni;                    // sizeof 04h    offset 1E4h
    int npcStateAni;                    // sizeof 04h    offset 1E8h
    int npcsMax     : 8;                // sizeof 08h    offset bit
    int npcsNeeded  : 8;                // sizeof 08h    offset bit
    int npcsCurrent : 8;                // sizeof 08h    offset bit
    int tmpState    : 8;                // sizeof 08h    offset bit
    int tmpStateChanged;                // sizeof 04h    offset 1F0h
    int onInterruptReturnToSlotPos : 1; // sizeof 01h    offset bit
    zVEC3 startPos;                     // sizeof 0Ch    offset 1F8h
    float aniCombHeight;                // sizeof 04h    offset 204h
    zCVob* inUseVob;                    // sizeof 04h    offset 208h
    float timerEnd;                     // sizeof 04h    offset 20Ch

    void oCMobInter_OnInit()                                            zCall( 0x0067BE10 );
    oCMobInter()                                                        zInit( oCMobInter_OnInit() );
    void SetTempState( int )                                            zCall( 0x0067C330 );
    int IsTempStateChanged()                                            zCall( 0x0067C370 );
    void SetStateToTempState()                                          zCall( 0x0067C380 );
    void SetMobBodyState( oCNpc* )                                      zCall( 0x0067C400 );
    int HasUseWithItem( oCNpc* )                                        zCall( 0x0067C8F0 );
    void ScanIdealPositions()                                           zCall( 0x0067C9C0 );
    int GetFreePosition( oCNpc*, zVEC3& )                               zCall( 0x0067CD00 );
    void SetHeading( oCNpc* )                                           zCall( 0x0067CEA0 );
    void SetIdealPosition( oCNpc* )                                     zCall( 0x0067CEF0 );
    void SendStateChange( int, int )                                    zCall( 0x0067D8C0 );
    void SendEndInteraction( oCNpc*, int, int )                         zCall( 0x0067DBD0 );
    void StartTransitionAniNpc( oCNpc*, zSTRING const& )                zCall( 0x0067E940 );
    int IsMultiMob()                                                    zCall( 0x0067F560 );
    int IsAvailable( oCNpc* )                                           zCall( 0x0067F570 );
    void MarkAsUsed( float, zCVob* )                                    zCall( 0x0067F5D0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x006776D0 );
    static int SetAllMobsToState( oCWorld*, zSTRING const&, int )       zCall( 0x0067BB10 );
    static void TraverseMobs( zCTree<zCVob>*, zSTRING const&, int )     zCall( 0x0067BB40 );
    static void TriggerAllMobsToTmpState( zCWorld* )                    zCall( 0x0067BC90 );
    static void TraverseTriggerMobs( zCTree<zCVob>* )                   zCall( 0x0067BD50 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0067BF80 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00680940 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x006809E0 );
    virtual ~oCMobInter()                                               zCall( 0x0067BFC0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x0067D300 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x0067D5F0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )   zCall( 0x0067C6D0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x0067C6E0 );
    virtual void OnTick()                                               zCall( 0x0067D280 );
    virtual void SetVisual( zCVisual* )                                 zCall( 0x0067C1B0 );
    virtual zSTRING const* GetTriggerTarget( int ) const                zCall( 0x00677AA0 );
    virtual zSTRING GetScemeName()                                      zCall( 0x0067C970 );
    virtual int GetState()                                              zCall( 0x00677A80 );
    virtual void SetUseWithItem( zSTRING const& )                       zCall( 0x0067C790 );
    virtual int GetUseWithItem()                                        zCall( 0x0067C8D0 );
    virtual void Reset()                                                zCall( 0x0067D140 );
    virtual void Interact( oCNpc*, int, int, int, int, int )            zCall( 0x0067DD70 );
    virtual void EndInteraction( oCNpc*, int )                          zCall( 0x0067FFD0 );
    virtual void InterruptInteraction( oCNpc* )                         zCall( 0x0067F360 );
    virtual void StopInteraction( oCNpc* )                              zCall( 0x00680250 );
    virtual int CanInteractWith( oCNpc* )                               zCall( 0x0067F5F0 );
    virtual int IsInteractingWith( oCNpc* )                             zCall( 0x0067FC70 );
    virtual int AI_UseMobToState( oCNpc*, int )                         zCall( 0x006804F0 );
    virtual int IsIn( int )                                             zCall( 0x00677A90 );
    virtual int IsInState( oCNpc*, int )                                zCall( 0x0067E340 );
    virtual void StartInteraction( oCNpc* )                             zCall( 0x0067FCA0 );
    virtual void StartStateChange( oCNpc*, int, int )                   zCall( 0x0067E6E0 );
    virtual void CheckStateChange( oCNpc* )                             zCall( 0x0067EC30 );
    virtual int CanChangeState( oCNpc*, int, int )                      zCall( 0x0067E480 );
    virtual void GetTransitionNames( int, int, zSTRING&, zSTRING& )     zCall( 0x0067DED0 );
    virtual void OnBeginStateChange( oCNpc*, int, int )                 zCall( 0x0067F2F0 );
    virtual void OnEndStateChange( oCNpc*, int, int )                   zCall( 0x0067F300 );
    virtual void CallOnStateFunc( oCNpc*, int )                         zCall( 0x0067EF60 );
    virtual void SendCallOnStateFunc( oCNpc*, int )                     zCall( 0x0067F140 );
    virtual TMobOptPos* SearchFreePosition( oCNpc* )                    zCall( 0x0067CD60 );

    // user API
    #include "oCMobInter.inl"
  };

  // sizeof 210h
  class oCMobBed : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobBed )

    void oCMobBed_OnInit()                                              zCall( 0x00681470 );
    oCMobBed()                                                          zInit( oCMobBed_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00677950 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00677AE0 );
    virtual ~oCMobBed()                                                 zCall( 0x00681590 );
    virtual void StartInteraction( oCNpc* )                             zCall( 0x00681760 );
    virtual void OnBeginStateChange( oCNpc*, int, int )                 zCall( 0x00681770 );
    virtual void OnEndStateChange( oCNpc*, int, int )                   zCall( 0x00681780 );

    // user API
    #include "oCMobBed.inl"
  };

  // sizeof 210h
  class oCMobSwitch : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobSwitch )

    void oCMobSwitch_OnInit()                                           zCall( 0x006817E0 );
    oCMobSwitch()                                                       zInit( oCMobSwitch_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00677CE0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00677E30 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00681AD0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00681B70 );
    virtual ~oCMobSwitch()                                              zCall( 0x00681900 );

    // user API
    #include "oCMobSwitch.inl"
  };

  // sizeof 218h
  class oCMobItemSlot : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobItemSlot )

    oCItem* insertedItem; // sizeof 04h    offset 210h
    int removeable;       // sizeof 04h    offset 214h

    void oCMobItemSlot_OnInit()                                         zCall( 0x00685E00 );
    oCMobItemSlot()                                                     zInit( oCMobItemSlot_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00679890 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00679950 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006863B0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00686480 );
    virtual ~oCMobItemSlot()                                            zCall( 0x00685E50 );
    virtual int GetUseWithItem()                                        zCall( 0x00686030 );
    virtual int CanInteractWith( oCNpc* )                               zCall( 0x00686070 );
    virtual int IsIn( int )                                             zCall( 0x00686380 );
    virtual oCItem* GetInsertedItem()                                   zCall( 0x00686090 );
    virtual int PlaceItem( oCItem* )                                    zCall( 0x006860A0 );
    virtual oCItem* RemoveItem()                                        zCall( 0x00686340 );

    // user API
    #include "oCMobItemSlot.inl"
  };

  // sizeof 23Ch
  class oCMobLockable : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobLockable )

    int locked     : 1;  // sizeof 01h    offset bit
    int autoOpen   : 1;  // sizeof 01h    offset bit
    int pickLockNr : 30; // sizeof 1Eh    offset bit
    zSTRING keyInstance; // sizeof 14h    offset 214h
    zSTRING pickLockStr; // sizeof 14h    offset 228h

    void oCMobLockable_OnInit()                              zCall( 0x00681C20 );
    oCMobLockable()                                          zInit( oCMobLockable_OnInit() );
    int CanOpen( oCNpc* )                                    zCall( 0x006827C0 );
    virtual zCClassDef* _GetClassDef() const                 zCall( 0x00678400 );
    virtual void Archive( zCArchiver& )                      zCall( 0x006835F0 );
    virtual void Unarchive( zCArchiver& )                    zCall( 0x006836E0 );
    virtual ~oCMobLockable()                                 zCall( 0x00681E00 );
    virtual void OnMessage( zCEventMessage*, zCVob* )        zCall( 0x006786B0 );
    virtual void Interact( oCNpc*, int, int, int, int, int ) zCall( 0x00681FF0 );
    virtual int CanInteractWith( oCNpc* )                    zCall( 0x00681FC0 );
    virtual int CanChangeState( oCNpc*, int, int )           zCall( 0x006825B0 );
    virtual void OnEndStateChange( oCNpc*, int, int )        zCall( 0x00682600 );
    virtual void SetLocked( int )                            zCall( 0x00678410 );
    virtual void SetKeyInstance( zSTRING const& )            zCall( 0x00678430 );
    virtual void SetPickLockStr( zSTRING const& )            zCall( 0x00678570 );
    virtual void Open( oCNpc* )                              zPureCall;
    virtual void Close( oCNpc* )                             zPureCall;
    virtual void Lock( oCNpc* )                              zCall( 0x00683400 );
    virtual void Unlock( oCNpc*, int )                       zCall( 0x00682CC0 );
    virtual int PickLock( oCNpc*, char )                     zCall( 0x00682990 );

    // user API
    #include "oCMobLockable.inl"
  };

  // sizeof 260h
  class oCMobContainer : public oCMobLockable {
  public:
    zCLASS_DECLARATION( oCMobContainer )

    zSTRING contains;               // sizeof 14h    offset 23Ch
    oCItemContainer* items;         // sizeof 04h    offset 250h
    zCListSort<oCItem> containList; // sizeof 0Ch    offset 254h

    void oCMobContainer_OnInit()                                        zCall( 0x006837F0 );
    oCMobContainer()                                                    zInit( oCMobContainer_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00678210 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00678780 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x006844D0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00684670 );
    virtual ~oCMobContainer()                                           zCall( 0x006839B0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                   zCall( 0x00683BC0 );
    virtual void Destroy()                                              zCall( 0x00683CC0 );
    virtual void Reset()                                                zCall( 0x00683E70 );
    virtual int IsIn( int )                                             zCall( 0x00684390 );
    virtual void Open( oCNpc* )                                         zCall( 0x006843D0 );
    virtual void Close( oCNpc* )                                        zCall( 0x00684490 );
    virtual void Insert( oCItem* )                                      zCall( 0x00683E80 );
    virtual void Remove( oCItem* )                                      zCall( 0x00683EB0 );
    virtual oCItem* Remove( oCItem*, int )                              zCall( 0x00683F40 );
    virtual void CreateContents( zSTRING const& )                       zCall( 0x00684050 );

    // user API
    #include "oCMobContainer.inl"
  };

  // sizeof 250h
  class oCMobDoor : public oCMobLockable {
  public:
    zCLASS_DECLARATION( oCMobDoor )

    zSTRING addName; // sizeof 14h    offset 23Ch

    void oCMobDoor_OnInit()                                             zCall( 0x006848F0 );
    oCMobDoor()                                                         zInit( oCMobDoor_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00679050 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00679240 );
    virtual ~oCMobDoor()                                                zCall( 0x00684AF0 );
    virtual zSTRING GetScemeName()                                      zCall( 0x00684CA0 );
    virtual TMobOptPos* SearchFreePosition( oCNpc* )                    zCall( 0x00684D50 );
    virtual void Open( oCNpc* )                                         zCall( 0x00679250 );
    virtual void Close( oCNpc* )                                        zCall( 0x00679260 );

    // user API
    #include "oCMobDoor.inl"
  };

  // sizeof 23Ch
  class oCMobFire : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobFire )

    zSTRING fireSlot;        // sizeof 14h    offset 210h
    zSTRING fireVobtreeName; // sizeof 14h    offset 224h
    zCVob* fireVobtree;      // sizeof 04h    offset 238h

    void oCMobFire_OnInit()                                             zCall( 0x00680A90 );
    oCMobFire()                                                         zInit( oCMobFire_OnInit() );
    void DeleteEffects()                                                zCall( 0x00680E80 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00679460 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00679690 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00681280 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00681390 );
    virtual ~oCMobFire()                                                zCall( 0x00680CA0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x00680FB0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x006811B0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )   zCall( 0x00680ED0 );
    virtual void OnEndStateChange( oCNpc*, int, int )                   zCall( 0x00680F20 );
    virtual void PreSave()                                              zCall( 0x00681220 );
    virtual void PostSave()                                             zCall( 0x00681360 );

    // user API
    #include "oCMobFire.inl"
  };

  // sizeof 210h
  class oCMobWheel : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobWheel )

    void oCMobWheel_OnInit()                                            zCall( 0x00684ED0 );
    oCMobWheel()                                                        zInit( oCMobWheel_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00678980 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00678AE0 );
    virtual ~oCMobWheel()                                               zCall( 0x006853E0 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x00685000 );
    virtual void OnUntrigger( zCVob*, zCVob* )                          zCall( 0x00685110 );
    virtual void Interact( oCNpc*, int, int, int, int, int )            zCall( 0x00685210 );

    // user API
    #include "oCMobWheel.inl"
  };

  // sizeof 210h
  class oCMobLadder : public oCMobInter {
  public:
    zCLASS_DECLARATION( oCMobLadder )

    void oCMobLadder_OnInit()                                           zCall( 0x006855B0 );
    oCMobLadder()                                                       zInit( oCMobLadder_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00678CE0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00678E40 );
    virtual ~oCMobLadder()                                              zCall( 0x006856E0 );
    virtual int DoFocusCheckBBox()                                      zCall( 0x00678E50 );
    virtual void Interact( oCNpc*, int, int, int, int, int )            zCall( 0x00685B20 );
    virtual int CanInteractWith( oCNpc* )                               zCall( 0x00685AA0 );
    virtual void StartInteraction( oCNpc* )                             zCall( 0x006858B0 );
    virtual int CanChangeState( oCNpc*, int, int )                      zCall( 0x00685A50 );
    virtual TMobOptPos* SearchFreePosition( oCNpc* )                    zCall( 0x00685AB0 );

    // user API
    #include "oCMobLadder.inl"
  };

  // sizeof 100h
  class oCDummyVobGenerator : public zCVob {
  public:
    zCLASS_DECLARATION( oCDummyVobGenerator )

    void oCDummyVobGenerator_OnInit()                                   zCall( 0x00686570 );
    oCDummyVobGenerator()                                               zInit( oCDummyVobGenerator_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x00679B50 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00679C30 );
    virtual ~oCDummyVobGenerator()                                      zCall( 0x00679C70 );
    virtual void OnTrigger( zCVob*, zCVob* )                            zCall( 0x006865E0 );

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

    void oCMobMsg_OnInit( TMobMsgSubType, oCNpc* )                      zCall( 0x0067A040 );
    void oCMobMsg_OnInit()                                              zCall( 0x0067A1C0 );
    void oCMobMsg_OnInit( TMobMsgSubType, oCNpc*, int )                 zCall( 0x0067A2F0 );
    oCMobMsg( TMobMsgSubType a0, oCNpc* a1 )                            zInit( oCMobMsg_OnInit( a0, a1 ));
    oCMobMsg()                                                          zInit( oCMobMsg_OnInit() );
    oCMobMsg( TMobMsgSubType a0, oCNpc* a1, int a2 )                    zInit( oCMobMsg_OnInit( a0, a1, a2 ));
    static zCObject* _CreateNewInstance()                               zCall( 0x00679EA0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0067A020 );
    virtual ~oCMobMsg()                                                 zCall( 0x0067A1B0 );
    virtual int IsNetRelevant()                                         zCall( 0x0067A030 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x0067A560 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x0067A570 );
    virtual void Pack( zCBuffer&, zCEventManager* )                     zCall( 0x0067A440 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                   zCall( 0x0067A4C0 );

    // user API
    #include "oCMobMsg.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OMOB_INTER_H__VER0__