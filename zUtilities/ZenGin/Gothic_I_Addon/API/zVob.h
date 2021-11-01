// Supported with union (c) 2018-2021 Union team

#ifndef __ZVOB_H__VER1__
#define __ZVOB_H__VER1__

namespace Gothic_I_Addon {

  enum zTVobType {
    zVOB_TYPE_NORMAL,
    zVOB_TYPE_LIGHT,
    zVOB_TYPE_SOUND,
    zVOB_TYPE_LEVEL_COMPONENT,
    zVOB_TYPE_SPOT,
    zVOB_TYPE_CAMERA,
    zVOB_TYPE_STARTPOINT,
    zVOB_TYPE_WAYPOINT,
    zVOB_TYPE_MARKER,
    zVOB_TYPE_SEPARATOR = 127,
    zVOB_TYPE_MOB,
    zVOB_TYPE_ITEM,
    zVOB_TYPE_NSC
  };

  enum zTVobSleepingMode {
    zVOB_SLEEPING,
    zVOB_AWAKE,
    zVOB_AWAKE_DOAI_ONLY
  };

  enum zTVobLightType {
    zVOBLIGHT_TYPE_POINT,
    zVOBLIGHT_TYPE_SPOT,
    zVOBLIGHT_TYPE_DIR,
    zVOBLIGHT_TYPE_AMBIENT
  };

  enum zTVobLightQuality {
    zVOBLIGHT_QUAL_HI,
    zVOBLIGHT_QUAL_MID,
    zVOBLIGHT_QUAL_FASTEST
  };

  // sizeof 2Ch
  class zCEventMessage : public zCObject {
  public:
    zCLASS_DECLARATION( zCEventMessage )

    enum zTTimeBehavior {
      TBZero,
      TBFix,
      TBUnknown,
      TBAssembled
    };

    unsigned short int subType; // sizeof 02h    offset 24h
    int inCutscene;             // sizeof 04h    offset 28h

    void zCEventMessage_OnInit()                                                    zCall( 0x00415000 );
    void zCEventMessage_OnInit( unsigned short )                                    zCall( 0x005F8530 );
    zCEventMessage()                                                                zInit( zCEventMessage_OnInit() );
    zCEventMessage( unsigned short a0 )                                             zInit( zCEventMessage_OnInit( a0 ));
    unsigned long GetMessageID() const                                              zCall( 0x005F86A0 );
    void PackToBuffer( zCBuffer&, zCEventManager* )                                 zCall( 0x005F8700 );
    unsigned short GetSubType() const                                               zCall( 0x0077F580 );
    static zCObject* _CreateNewInstance()                                           zCall( 0x005F0EF0 );
    static void AnalyzeMessageID( unsigned long, unsigned short&, unsigned short& ) zCall( 0x005F86C0 );
    static zCEventMessage* CreateFromID( unsigned long )                            zCall( 0x005F86E0 );
    static zCEventMessage* CreateFromBuffer( zCBuffer&, zCEventManager* )           zCall( 0x005F8750 );
    static void TestClassIntegrity()                                                zCall( 0x005F8A00 );
    virtual zCClassDef* _GetClassDef() const                                        zCall( 0x00402200 );
    virtual void Archive( zCArchiver& )                                             zCall( 0x005F8790 );
    virtual void Unarchive( zCArchiver& )                                           zCall( 0x005F89E0 );
    virtual ~zCEventMessage()                                                       zCall( 0x004023B0 );
    virtual int IsOverlay()                                                         zCall( 0x00402210 );
    virtual int IsNetRelevant()                                                     zCall( 0x00402220 );
    virtual int IsHighPriority()                                                    zCall( 0x00402230 );
    virtual int IsJob()                                                             zCall( 0x00402240 );
    virtual void Delete()                                                           zCall( 0x00402250 );
    virtual int IsDeleteable()                                                      zCall( 0x00402260 );
    virtual int IsDeleted()                                                         zCall( 0x00402270 );
    virtual void SetCutsceneMode( int )                                             zCall( 0x00402280 );
    virtual int GetCutsceneMode()                                                   zCall( 0x00402290 );
    virtual int MD_GetNumOfSubTypes()                                               zCall( 0x004022A0 );
    virtual zSTRING MD_GetSubTypeString( int )                                      zCall( 0x004022B0 );
    virtual zSTRING MD_GetVobRefName()                                              zCall( 0x00402300 );
    virtual void MD_SetVobRefName( zSTRING const& )                                 zCall( 0x00402350 );
    virtual void MD_SetVobParam( zCVob* )                                           zCall( 0x00402360 );
    virtual zTTimeBehavior MD_GetTimeBehavior()                                     zCall( 0x00402370 );
    virtual float MD_GetMinTime()                                                   zCall( 0x00402380 );
    virtual void Pack( zCBuffer&, zCEventManager* )                                 zCall( 0x00402390 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                               zCall( 0x004023A0 );

    // user API
    #include "zCEventMessage.inl"
  };

  // sizeof 4Ch
  class zCEventCore : public zCEventMessage {
  public:
    zCLASS_DECLARATION( zCEventCore )

    enum zTEventCoreSubType {
      zEVENT_TRIGGER,
      zEVENT_UNTRIGGER,
      zEVENT_TOUCH,
      zEVENT_UNTOUCH,
      zEVENT_TOUCHLEVEL,
      zEVENT_DAMAGE,
      zEVENT_CORE_NUM_SUBTYPES
    };

    zCVob* otherVob;      // sizeof 04h    offset 2Ch
    zCVob* vobInstigator; // sizeof 04h    offset 30h
    float damage;         // sizeof 04h    offset 34h
    int damageType;       // sizeof 04h    offset 38h
    zCVob* inflictorVob;  // sizeof 04h    offset 3Ch
    zVEC3 hitLocation;    // sizeof 0Ch    offset 40h

    zCEventCore() {}
    void Clear()                                                        zCall( 0x005F9100 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005F1250 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00402410 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005F9550 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005F95C0 );
    virtual ~zCEventCore()                                              zCall( 0x005F9140 );
    virtual int IsNetRelevant()                                         zCall( 0x00402430 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x00402420 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x005F9340 );
    virtual void Pack( zCBuffer&, zCEventManager* )                     zCall( 0x005F9160 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                   zCall( 0x005F9210 );

    // user API
    #include "zCEventCore.inl"
  };

  // sizeof 100h
  class zCVob : public zCObject {
  public:
    zCLASS_DECLARATION( zCVob )

    enum zTVobCharClass {
      zVOB_CHAR_CLASS_NONE,
      zVOB_CHAR_CLASS_PC,
      zVOB_CHAR_CLASS_NPC
    };

    enum zTMovementMode {
      zVOB_MOVE_MODE_NOTINBLOCK,
      zVOB_MOVE_MODE_INBLOCK,
      zVOB_MOVE_MODE_INBLOCK_NOCD
    };

    enum {
      zVOB_CDMODE_EXACT,
      zVOB_CDMODE_SPEEDBOX,
      zVOB_CDMODE_ALL
    };

    enum zTDynShadowType {
      zDYN_SHADOW_TYPE_NONE,
      zDYN_SHADOW_TYPE_BLOB,
      zDYN_SHADOW_TYPE_COUNT
    };

    // sizeof 18h
    struct zTCollisionContext {
      zCArray<zCCollisionObject*> otherCollObjectList; // sizeof 0Ch    offset 00h
      zCArray<zCVob*> otherCollVobList;                // sizeof 0Ch    offset 0Ch

      zTCollisionContext() {}
      ~zTCollisionContext() zCall( 0x00612C80 );

      // user API
      #include "zCVob_zTCollisionContext.inl"
    };

    // sizeof 18h
    struct zTModelLimbColl {
      zCVob* hitVob;                            // sizeof 04h    offset 00h
      zCList<zCModelNodeInst> hitModelNodeList; // sizeof 08h    offset 04h
      zVEC3 approxCollisionPos;                 // sizeof 0Ch    offset 0Ch

      void zTModelLimbColl_OnInit() zCall( 0x005F7A70 );
      zTModelLimbColl()             zInit( zTModelLimbColl_OnInit() );
      ~zTModelLimbColl()            zCall( 0x005F7AA0 );

      // user API
      #include "zCVob_zTModelLimbColl.inl"
    };

    zCTree<zCVob>* globalVobTreeNode;               // sizeof 04h    offset 24h
    int lastTimeDrawn;                              // sizeof 04h    offset 28h
    unsigned long lastTimeCollected;                // sizeof 04h    offset 2Ch
    zCArray<zCBspLeaf*> vobLeafList;                // sizeof 0Ch    offset 30h
    zMAT4 trafoObjToWorld;                          // sizeof 40h    offset 3Ch
    zTBBox3D bbox3D;                                // sizeof 18h    offset 7Ch
    zCArray<zCVob*> touchVobList;                   // sizeof 0Ch    offset 94h
    zTVobType type;                                 // sizeof 04h    offset A0h
    unsigned long groundShadowSizePacked;           // sizeof 04h    offset A4h
    zCWorld* homeWorld;                             // sizeof 04h    offset A8h
    zCPolygon* groundPoly;                          // sizeof 04h    offset ACh
    zCAIBase* callback_ai;                          // sizeof 04h    offset B0h
    zMAT4* trafo;                                   // sizeof 04h    offset B4h
    zCVisual* visual;                               // sizeof 04h    offset B8h
    float visualAlpha;                              // sizeof 04h    offset BCh
    zCRigidBody* rigidBody;                         // sizeof 04h    offset C0h
    zCOLOR lightColorStat;                          // sizeof 04h    offset C4h
    zCOLOR lightColorDyn;                           // sizeof 04h    offset C8h
    zVEC3 lightDirectionStat;                       // sizeof 0Ch    offset CCh
    zSTRING* vobPresetName;                         // sizeof 04h    offset D8h
    zCEventManager* eventManager;                   // sizeof 04h    offset DCh
    float nextOnTimer;                              // sizeof 04h    offset E0h
    group {
      unsigned char showVisual                : 1;  // sizeof 01h    offset bit
      unsigned char drawBBox3D                : 1;  // sizeof 01h    offset bit
      unsigned char visualAlphaEnabled        : 1;  // sizeof 01h    offset bit
      unsigned char physicsEnabled            : 1;  // sizeof 01h    offset bit
      unsigned char staticVob                 : 1;  // sizeof 01h    offset bit
      unsigned char ignoredByTraceRay         : 1;  // sizeof 01h    offset bit
      unsigned char collDetectionStatic       : 1;  // sizeof 01h    offset bit
      unsigned char collDetectionDynamic      : 1;  // sizeof 01h    offset bit
      unsigned char castDynShadow             : 2;  // sizeof 02h    offset bit
      unsigned char lightColorStatDirty       : 1;  // sizeof 01h    offset bit
      unsigned char lightColorDynDirty        : 1;  // sizeof 01h    offset bit
      zTMovementMode isInMovementMode         : 2;  // sizeof 02h    offset bit
      unsigned char sleepingMode              : 2;  // sizeof 02h    offset bit
      unsigned char mbHintTrafoLocalConst     : 1;  // sizeof 01h    offset bit
      unsigned char mbInsideEndMovementMethod : 1;  // sizeof 01h    offset bit
      zTVisualCamAlign visualCamAlign         : 2;  // sizeof 02h    offset bit
      unsigned char collButNoMove             : 8;  // sizeof 08h    offset bit
      unsigned char dontWriteIntoArchive      : 1;  // sizeof 01h    offset bit
    };
    zCCollisionObjectDef* m_poCollisionObjectClass; // sizeof 04h    offset F8h
    zCCollisionObject* m_poCollisionObject;         // sizeof 04h    offset FCh

    void zCVob_OnInit()                                                                                zCall( 0x005F2220 );
    zVEC3 GetPositionWorld() const                                                                     zCall( 0x00489680 );
    zVEC3 GetUpVectorWorld() const                                                                     zCall( 0x00494290 );
    zVEC3 GetAtVectorWorld() const                                                                     zCall( 0x00514C80 );
    zVEC3 GetRightVectorWorld() const                                                                  zCall( 0x00531060 );
    zCVob()                                                                                            zInit( zCVob_OnInit() );
    void SetVobID( unsigned long const& )                                                              zCall( 0x005F2900 );
    void SetAI( zCAIBase* )                                                                            zCall( 0x005F2910 );
    void SetVobPresetName( zSTRING const& )                                                            zCall( 0x005F2960 );
    zSTRING const& GetVobPresetName() const                                                            zCall( 0x005F2970 );
    zCRigidBody* GetRigidBody()                                                                        zCall( 0x005F2980 );
    void __fastcall ArchivePacked( zCArchiver& )                                                       zCall( 0x005F2A00 );
    void __fastcall ArchiveVerbose( zCArchiver& )                                                      zCall( 0x005F2E60 );
    void __fastcall UnarchivePacked( zCArchiver&, int )                                                zCall( 0x005F3270 );
    void __fastcall UnarchiveVerbose( zCArchiver& )                                                    zCall( 0x005F3740 );
    void SetVobName( zSTRING const& )                                                                  zCall( 0x005F3D40 );
    zCEventManager* __fastcall GetEM( int = 0 )                                                        zCall( 0x005F3D80 );
    zCOLOR CalcLightSampleAtOrigin()                                                                   zCall( 0x005F40A0 );
    zCOLOR GetLightColorStat()                                                                         zCall( 0x005F4120 );
    zCOLOR GetLightColorDyn()                                                                          zCall( 0x005F43C0 );
    int __fastcall CalcStaticLight( zVEC3& ) const                                                     zCall( 0x005F45E0 );
    zSTRING const* GetSectorNameVobIsIn() const                                                        zCall( 0x005F4B10 );
    void __fastcall SetGroundShadowSize( zVEC2 const& )                                                zCall( 0x005F4C80 );
    zVEC2 __fastcall GetGroundShadowSize() const                                                       zCall( 0x005F4CC0 );
    void __fastcall RenderGroundShadow( zTRenderContext& )                                             zCall( 0x005F4D10 );
    zCVisual* GetClassHelperVisual() const                                                             zCall( 0x005F51D0 );
    void CalcRenderAlpha( float, zCVisual*&, float& )                                                  zCall( 0x005F53E0 );
    zCOLOR GetLightColorAtCenter() const                                                               zCall( 0x005F59F0 );
    void RemoveVobFromWorld()                                                                          zCall( 0x005F5BB0 );
    void RemoveVobSubtreeFromWorld()                                                                   zCall( 0x005F5BD0 );
    void AddRefVobSubtree( zCTree<zCVob>* )                                                            zCall( 0x005F5C30 );
    void ReleaseVobSubtree( zCTree<zCVob>* )                                                           zCall( 0x005F5C70 );
    void RemoveWorldDependencies( int )                                                                zCall( 0x005F5CD0 );
    void RemoveVobFromGlobalVobTree()                                                                  zCall( 0x005F5F20 );
    void RemoveVobFromBspTree()                                                                        zCall( 0x005F6000 );
    zSTRING GetVobInfo()                                                                               zCall( 0x005F6020 );
    void SetSleeping( int )                                                                            zCall( 0x005F68A0 );
    void UpdateVisualDependencies()                                                                    zCall( 0x005F6AA0 );
    void AddVobToWorld_CorrectParentDependencies()                                                     zCall( 0x005F6B30 );
    void ResetOnTimer()                                                                                zCall( 0x005F6B50 );
    void SetOnTimer( float )                                                                           zCall( 0x005F6B60 );
    int IsOnTimer() const                                                                              zCall( 0x005F6B90 );
    void ProcessOnTimer()                                                                              zCall( 0x005F6BB0 );
    void DoFrameActivity()                                                                             zCall( 0x005F6BE0 );
    void CheckModelLimbCollision( zCModelNodeInst*, int, zCList<zTModelLimbColl>& )                    zCall( 0x005F6E60 );
    zMAT4 GetTrafoModelNodeToWorld( zSTRING const& )                                                   zCall( 0x005F7AD0 );
    zMAT4 GetTrafoModelNodeToWorld( zCModelNodeInst* )                                                 zCall( 0x005F7C20 );
    zTBBox2D GetScreenBBox2D() const                                                                   zCall( 0x005F7CF0 );
    void PackStateBinary( zCBuffer& ) const                                                            zCall( 0x005F80C0 );
    void UnpackStateBinary( zCBuffer& )                                                                zCall( 0x005F81A0 );
    zCVisual* GetVisual() const                                                                        zCall( 0x0060A0A0 );
    void CalcGroundPoly()                                                                              zCall( 0x0060DFE0 );
    void SetCollTypeDefaultFromVisual()                                                                zCall( 0x0060E170 );
    void TouchMovement()                                                                               zCall( 0x0060E2E0 );
    zMAT4 const& GetNewTrafoObjToWorld() const                                                         zCall( 0x0060E300 );
    zMAT4& GetNewTrafoObjToWorld()                                                                     zCall( 0x0060E320 );
    void SetNewTrafoObjToWorld( zMAT4 const& )                                                         zCall( 0x0060E340 );
    void SetBBox3DWorld( zTBBox3D const& )                                                             zCall( 0x0060E360 );
    void SetBBox3DLocal( zTBBox3D const& )                                                             zCall( 0x0060E3C0 );
    zTBBox3D GetBBox3DLocal() const                                                                    zCall( 0x0060E470 );
    void Move( float, float, float )                                                                   zCall( 0x0060E5A0 );
    void MoveWorld( float, float, float )                                                              zCall( 0x0060E610 );
    void MoveLocal( float, float, float )                                                              zCall( 0x0060E680 );
    void SetRotationWorld( zCQuat const& )                                                             zCall( 0x0060E770 );
    void RotateWorld( zVEC3 const&, float )                                                            zCall( 0x0060E7D0 );
    void RotateLocal( zVEC3 const&, float )                                                            zCall( 0x0060E8E0 );
    void RotateLocalX( float )                                                                         zCall( 0x0060E980 );
    void RotateLocalY( float )                                                                         zCall( 0x0060E9F0 );
    void RotateLocalZ( float )                                                                         zCall( 0x0060EA60 );
    void RotateWorldX( float )                                                                         zCall( 0x0060EAD0 );
    void RotateWorldY( float )                                                                         zCall( 0x0060EB00 );
    void RotateWorldZ( float )                                                                         zCall( 0x0060EB30 );
    void GetPositionWorld( float&, float&, float& ) const                                              zCall( 0x0060EB60 );
    void GetPositionLocal( float&, float&, float& ) const                                              zCall( 0x0060EBA0 );
    float GetDistanceToVob( zCVob& )                                                                   zCall( 0x0060EBF0 );
    float GetDistanceToVobApprox( zCVob& )                                                             zCall( 0x0060EC90 );
    float GetDistanceToVob2( zCVob& )                                                                  zCall( 0x0060EDA0 );
    void SetPositionLocal( zVEC3 const& )                                                              zCall( 0x0060EE40 );
    void SetPositionWorld( zVEC3 const& )                                                              zCall( 0x0060EF20 );
    void SetTrafo( zMAT4 const& )                                                                      zCall( 0x0060EF80 );
    void SetTrafoObjToWorld( zMAT4 const& )                                                            zCall( 0x0060F030 );
    void ResetRotationsLocal()                                                                         zCall( 0x0060F090 );
    void ResetXZRotationsLocal()                                                                       zCall( 0x0060F1E0 );
    void ResetRotationsWorld()                                                                         zCall( 0x0060F430 );
    void ResetXZRotationsWorld()                                                                       zCall( 0x0060F4D0 );
    void SetHeadingYLocal( zVEC3 const& )                                                              zCall( 0x0060F680 );
    void SetHeadingYWorld( zVEC3 const& )                                                              zCall( 0x0060F770 );
    void SetHeadingYWorld( zCVob* )                                                                    zCall( 0x0060F860 );
    void SetHeadingLocal( zVEC3 const& )                                                               zCall( 0x0060F9A0 );
    void SetHeadingWorld( zVEC3 const& )                                                               zCall( 0x0060FA80 );
    void SetHeadingWorld( zCVob* )                                                                     zCall( 0x0060FB60 );
    void SetHeadingAtLocal( zVEC3 const& )                                                             zCall( 0x0060FC90 );
    int HasParentVob() const                                                                           zCall( 0x00610090 );
    void SetHeadingAtWorld( zVEC3 const& )                                                             zCall( 0x006100B0 );
    void __fastcall SetCollDetStat( int )                                                              zCall( 0x006103D0 );
    void __fastcall SetCollDetDyn( int )                                                               zCall( 0x006104E0 );
    void CorrectTrafo()                                                                                zCall( 0x006105F0 );
    void DoneWithTrafoLocal()                                                                          zCall( 0x00610660 );
    void CreateTrafoLocal() const                                                                      zCall( 0x006106B0 );
    void SetPhysicsEnabled( int )                                                                      zCall( 0x00610750 );
    zVEC3 GetVelocity()                                                                                zCall( 0x00610780 );
    void UpdatePhysics()                                                                               zCall( 0x006108C0 );
    int DetectCollision( zMAT4* )                                                                      zCall( 0x00610F40 );
    void __fastcall SetInMovement( int )                                                               zCall( 0x00611080 );
    void __fastcall SetInMovementMode( zTMovementMode )                                                zCall( 0x006110E0 );
    void BeginMovement()                                                                               zCall( 0x00611130 );
    void ResetToOldMovementState()                                                                     zCall( 0x006112E0 );
    void __fastcall UpdateTouchList( zCArray<zCVob*> const& )                                          zCall( 0x00611310 );
    void __fastcall CalcDestinationBBox3DWorld( zTBBox3D& )                                            zCall( 0x006115A0 );
    void AdoptCollObjResults()                                                                         zCall( 0x00611790 );
    void SetCollisionObject( zCCollisionObject* )                                                      zCall( 0x00611D40 );
    void SetCollisionClass( zCCollisionObjectDef* )                                                    zCall( 0x00611D70 );
    zCCollisionObject* GetCollisionObject() const                                                      zCall( 0x00611DB0 );
    void CreateCollisionObject()                                                                       zCall( 0x00611DC0 );
    void ResetCollisionObjectState()                                                                   zCall( 0x00611DF0 );
    void __fastcall DestroyCollisionObject( int )                                                      zCall( 0x00611E30 );
    void CheckEmergencyPutToSleep()                                                                    zCall( 0x00611E70 );
    void __fastcall CollectCollisionContext_Vobs( zTBBox3D const&, zTCollisionContext& )               zCall( 0x00612030 );
    void __fastcall CollectCollisionContext_Static( zTBBox3D const&, zCArray<zCCollisionObject*>& )    zCall( 0x006122A0 );
    void __fastcall CollectCollisionContext( zTCollisionContext& )                                     zCall( 0x006125A0 );
    void __fastcall CleanupCollisionContext( zTCollisionContext const& )                               zCall( 0x00612620 );
    void __fastcall NotifyCollisionPair( zCCollisionReport*, zCArray<zCCollisionReport*> const&, int ) zCall( 0x00612690 );
    void __fastcall ExecuteCollisionResponse( zCArray<zCCollisionReport*> const&, int& )               zCall( 0x00612760 );
    void CheckAndResolveCollisions()                                                                   zCall( 0x00612850 );
    int IsColliding()                                                                                  zCall( 0x00612CE0 );
    void Move( zVEC3 const& )                                                                          zCall( 0x0064FA60 );
    void SetStaticVob( int )                                                                           zCall( 0x0066C900 );
    zTVobType GetVobType() const                                                                       zCall( 0x0066C920 );
    void SetDrawBBox3D( int )                                                                          zCall( 0x0066C930 );
    void SetCollDet( int )                                                                             zCall( 0x0066C950 );
    zCWorld* GetHomeWorld() const                                                                      zCall( 0x0077F590 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x005F1980 );
    static void InitVobSystem()                                                                        zCall( 0x005F2710 );
    static void CleanupVobSystem()                                                                     zCall( 0x005F2850 );
    static void ResetIDCtr()                                                                           zCall( 0x005F28E0 );
    static unsigned long GetNextFreeVobID()                                                            zCall( 0x005F28F0 );
    static void LoadGroundShadowMesh()                                                                 zCall( 0x005F4B30 );
    static void DeleteGroundShadowMesh()                                                               zCall( 0x005F4C50 );
    static void RepairIllegalFloats( zMAT4& )                                                          zCall( 0x005F7FD0 );
    static zCVob* GetAutoLinkParent( zCVob* )                                                          zCall( 0x0060D970 );
    static int CanAutoLinkWith( zCVob*, zCVob* )                                                       zCall( 0x0060D9B0 );
    static void CheckAutoLink( zCVob*, zCVob* )                                                        zCall( 0x0060DB00 );
    static void CheckAutoUnlink( zCVob* )                                                              zCall( 0x0060DDB0 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x0043DCA0 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x005F31B0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x005F3BE0 );
    virtual ~zCVob()                                                                                   zCall( 0x005F2490 );
    virtual void OnTrigger( zCVob*, zCVob* )                                                           zCall( 0x005F21B0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                                         zCall( 0x005F21C0 );
    virtual void OnTouch( zCVob* )                                                                     zCall( 0x005F21D0 );
    virtual void OnUntouch( zCVob* )                                                                   zCall( 0x005F21E0 );
    virtual void OnTouchLevel()                                                                        zCall( 0x005F21F0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )                                  zCall( 0x005F2200 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                                  zCall( 0x005F2210 );
    virtual void OnTick()                                                                              zCall( 0x004048C0 );
    virtual void OnTimer()                                                                             zCall( 0x0043DCB0 );
    virtual void PostLoad()                                                                            zCall( 0x004048D0 );
    virtual zTVobCharClass GetCharacterClass()                                                         zCall( 0x004048E0 );
    virtual void SetSleepingMode( zTVobSleepingMode )                                                  zCall( 0x005F68C0 );
    virtual void EndMovement()                                                                         zCall( 0x00611840 );
    virtual int CanThisCollideWith( zCVob* )                                                           zCall( 0x004048F0 );
    virtual int __fastcall Render( zTRenderContext& )                                                  zCall( 0x005F5510 );
    virtual void SetVisual( zCVisual* )                                                                zCall( 0x005F63E0 );
    virtual void SetVisual( zSTRING const& )                                                           zCall( 0x005F6570 );
    virtual int GetScriptInstance( zSTRING*&, int& )                                                   zCall( 0x00404900 );
    virtual int SetByScriptInstance( zSTRING const*, int )                                             zCall( 0x00404920 );
    virtual int GetCSStateFlags()                                                                      zCall( 0x00404930 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& )                         zCall( 0x005F3DB0 );
    virtual zSTRING const* GetTriggerTarget( int ) const                                               zCall( 0x0043DCC0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                       zCall( 0x005F5BF0 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                                   zCall( 0x005F5C10 );


    // static properties
    static int& s_ignoreVisuals;
    static zCMesh*& s_shadowMesh;
    static unsigned long& s_nextFreeID;
    static int& s_vobAlreadyInMovement;
    static int& s_renderVobs;
    static int& s_showHelperVisuals;
    static zCCollisionDetector*& s_poCollisionDetector;

    // user API
    #include "zCVob.inl"
  };

  // sizeof 48h
  class zCVobLightData {
  public:
    zCArray<float> rangeAniScaleList;   // sizeof 0Ch    offset 00h
    zCArray<zCOLOR> colorAniList;       // sizeof 0Ch    offset 0Ch
    int lensFlareFXNo;                  // sizeof 04h    offset 18h
    zCLensFlareFX* lensFlareFX;         // sizeof 04h    offset 1Ch
    zCOLOR lightColor;                  // sizeof 04h    offset 20h
    float range;                        // sizeof 04h    offset 24h
    float rangeInv;                     // sizeof 04h    offset 28h
    float rangeBackup;                  // sizeof 04h    offset 2Ch
    float rangeAniActFrame;             // sizeof 04h    offset 30h
    float rangeAniFPS;                  // sizeof 04h    offset 34h
    float colorAniActFrame;             // sizeof 04h    offset 38h
    float colorAniFPS;                  // sizeof 04h    offset 3Ch
    float spotConeAngleDeg;             // sizeof 04h    offset 40h
    group {
      unsigned char isStatic       : 1; // sizeof 01h    offset bit
      unsigned char rangeAniSmooth : 1; // sizeof 01h    offset bit
      unsigned char rangeAniLoop   : 1; // sizeof 01h    offset bit
      unsigned char colorAniSmooth : 1; // sizeof 01h    offset bit
      unsigned char colorAniLoop   : 1; // sizeof 01h    offset bit
      unsigned char isTurnedOn     : 1; // sizeof 01h    offset bit
      unsigned char lightQuality   : 4; // sizeof 04h    offset bit
      unsigned char lightType      : 4; // sizeof 04h    offset bit
    };

    void zCVobLightData_OnInit()               zCall( 0x005FD8C0 );
    int SetLensFlareFXByName( zSTRING const& ) zCall( 0x005FC7E0 );
    zSTRING const& GetLensFlareFXName() const  zCall( 0x005FC900 );
    void Archive( zCArchiver& )                zCall( 0x005FC920 );
    void Unarchive( zCArchiver& )              zCall( 0x005FCE10 );
    zCVobLightData()                           zInit( zCVobLightData_OnInit() );
    ~zCVobLightData()                          zCall( 0x005FD930 );
    void SetRange( float, int )                zCall( 0x005FD9A0 );

    // user API
    #include "zCVobLightData.inl"
  };

  // sizeof 80h
  class zCVobLightPreset : public zCObject {
  public:
    zCLASS_DECLARATION( zCVobLightPreset )

    zCVobLightData lightData; // sizeof 48h    offset 24h
    zSTRING presetName;       // sizeof 14h    offset 6Ch

    zCVobLightPreset() {}
    static zCObject* _CreateNewInstance()                               zCall( 0x005F1550 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005F16B0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005FC600 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005FC630 );
    virtual ~zCVobLightPreset()                                         zCall( 0x005F16F0 );

    // user API
    #include "zCVobLightPreset.inl"
  };

  // sizeof 15Ch
  class zCVobLight : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobLight )

    zCVobLightData lightData; // sizeof 48h    offset 100h
    zSTRING lightPresetInUse; // sizeof 14h    offset 148h

    void zCVobLight_OnInit()                                                              zCall( 0x005FAFC0 );
    zCVobLight()                                                                          zInit( zCVobLight_OnInit() );
    void DoAnimation()                                                                    zCall( 0x005FB340 );
    void SetRange( float, int )                                                           zCall( 0x005FB5F0 );
    void AddThisToPresetList( zSTRING const& ) const                                      zCall( 0x005FBC00 );
    int SetByPreset( zSTRING const& )                                                     zCall( 0x005FBF00 );
    int SetByPresetInUse()                                                                zCall( 0x005FC1A0 );
    static zCObject* _CreateNewInstance()                                                 zCall( 0x005FAE70 );
    static void CleanupVobLight()                                                         zCall( 0x005FB160 );
    static zCOLOR SumLightsAtPositionWS( zCArray<zCVobLight*> const&, zVEC3 const&, int ) zCall( 0x005FB6E0 );
    static void LoadLightPresets()                                                        zCall( 0x005FB970 );
    static void SaveLightPresets()                                                        zCall( 0x005FBAD0 );
    virtual zCClassDef* _GetClassDef() const                                              zCall( 0x005FAF60 );
    virtual void Archive( zCArchiver& )                                                   zCall( 0x005FC3F0 );
    virtual void Unarchive( zCArchiver& )                                                 zCall( 0x005FC440 );
    virtual ~zCVobLight()                                                                 zCall( 0x005FB0A0 );
    virtual void OnTrigger( zCVob*, zCVob* )                                              zCall( 0x005FB1D0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                            zCall( 0x005FB2A0 );


    // static properties
    static zCArray<zCVobLightPreset*>& lightPresetList;
    static int& renderLightVisuals;

    // user API
    #include "zCVobLight.inl"
  };

  // sizeof 100h
  class zCVobLevelCompo : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobLevelCompo )

    void zCVobLevelCompo_OnInit()                                       zCall( 0x005F8250 );
    zCVobLevelCompo()                                                   zInit( zCVobLevelCompo_OnInit() );
    int HasIdentityTrafo() const                                        zCall( 0x005F82B0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005F1BF0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005F1CB0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005F8330 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005F83E0 );
    virtual ~zCVobLevelCompo()                                          zCall( 0x005F1CF0 );
    virtual void SetVisual( zCVisual* )                                 zCall( 0x005F84B0 );
    virtual void SetVisual( zSTRING const& )                            zCall( 0x005F84F0 );


    // static properties
    static int& unarcIgnoreVisuals;

    // user API
    #include "zCVobLevelCompo.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZVOB_H__VER1__