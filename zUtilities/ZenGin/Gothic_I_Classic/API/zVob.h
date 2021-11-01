// Supported with union (c) 2018-2021 Union team

#ifndef __ZVOB_H__VER0__
#define __ZVOB_H__VER0__

namespace Gothic_I_Classic {

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

    void zCEventMessage_OnInit()                                                    zCall( 0x00413590 );
    void zCEventMessage_OnInit( unsigned short )                                    zCall( 0x005D8D10 );
    zCEventMessage()                                                                zInit( zCEventMessage_OnInit() );
    zCEventMessage( unsigned short a0 )                                             zInit( zCEventMessage_OnInit( a0 ));
    unsigned long GetMessageID() const                                              zCall( 0x005D8E80 );
    void PackToBuffer( zCBuffer&, zCEventManager* )                                 zCall( 0x005D8EE0 );
    unsigned short GetSubType() const                                               zCall( 0x0073F4C0 );
    static zCObject* _CreateNewInstance()                                           zCall( 0x005D1D20 );
    static void AnalyzeMessageID( unsigned long, unsigned short&, unsigned short& ) zCall( 0x005D8EA0 );
    static zCEventMessage* CreateFromID( unsigned long )                            zCall( 0x005D8EC0 );
    static zCEventMessage* CreateFromBuffer( zCBuffer&, zCEventManager* )           zCall( 0x005D8F30 );
    static void TestClassIntegrity()                                                zCall( 0x005D9190 );
    virtual zCClassDef* _GetClassDef() const                                        zCall( 0x00401DF0 );
    virtual void Archive( zCArchiver& )                                             zCall( 0x005D8F70 );
    virtual void Unarchive( zCArchiver& )                                           zCall( 0x005D9170 );
    virtual ~zCEventMessage()                                                       zCall( 0x00401F80 );
    virtual int IsOverlay()                                                         zCall( 0x00401E00 );
    virtual int IsNetRelevant()                                                     zCall( 0x00401E10 );
    virtual int IsHighPriority()                                                    zCall( 0x00401E20 );
    virtual int IsJob()                                                             zCall( 0x00401E30 );
    virtual void Delete()                                                           zCall( 0x00401E40 );
    virtual int IsDeleteable()                                                      zCall( 0x00401E50 );
    virtual int IsDeleted()                                                         zCall( 0x00401E60 );
    virtual void SetCutsceneMode( int )                                             zCall( 0x00401E70 );
    virtual int GetCutsceneMode()                                                   zCall( 0x00401E80 );
    virtual int MD_GetNumOfSubTypes()                                               zCall( 0x00401E90 );
    virtual zSTRING MD_GetSubTypeString( int )                                      zCall( 0x00401EA0 );
    virtual zSTRING MD_GetVobRefName()                                              zCall( 0x00401EE0 );
    virtual void MD_SetVobRefName( zSTRING const& )                                 zCall( 0x00401F20 );
    virtual void MD_SetVobParam( zCVob* )                                           zCall( 0x00401F30 );
    virtual zTTimeBehavior MD_GetTimeBehavior()                                     zCall( 0x00401F40 );
    virtual float MD_GetMinTime()                                                   zCall( 0x00401F50 );
    virtual void Pack( zCBuffer&, zCEventManager* )                                 zCall( 0x00401F60 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                               zCall( 0x00401F70 );

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
    void Clear()                                                        zCall( 0x005D97D0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005D2060 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00401FE0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005D9C00 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005D9C70 );
    virtual ~zCEventCore()                                              zCall( 0x005D9810 );
    virtual int IsNetRelevant()                                         zCall( 0x00402000 );
    virtual int MD_GetNumOfSubTypes()                                   zCall( 0x00401FF0 );
    virtual zSTRING MD_GetSubTypeString( int )                          zCall( 0x005D9A00 );
    virtual void Pack( zCBuffer&, zCEventManager* )                     zCall( 0x005D9830 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                   zCall( 0x005D98E0 );

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
      ~zTCollisionContext() zCall( 0x005F1EE0 );

      // user API
      #include "zCVob_zTCollisionContext.inl"
    };

    // sizeof 18h
    struct zTModelLimbColl {
      zCVob* hitVob;                            // sizeof 04h    offset 00h
      zCList<zCModelNodeInst> hitModelNodeList; // sizeof 08h    offset 04h
      zVEC3 approxCollisionPos;                 // sizeof 0Ch    offset 0Ch

      void zTModelLimbColl_OnInit() zCall( 0x005D8380 );
      zTModelLimbColl()             zInit( zTModelLimbColl_OnInit() );
      ~zTModelLimbColl()            zCall( 0x005D83B0 );

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

    void zCVob_OnInit()                                                                                zCall( 0x005D3030 );
    zVEC3 GetPositionWorld() const                                                                     zCall( 0x0051B3C0 );
    zVEC3 GetAtVectorWorld() const                                                                     zCall( 0x0051B3E0 );
    zVEC3 GetUpVectorWorld() const                                                                     zCall( 0x0051B400 );
    zVEC3 GetRightVectorWorld() const                                                                  zCall( 0x0051B420 );
    zCVob()                                                                                            zInit( zCVob_OnInit() );
    void SetVobID( unsigned long const& )                                                              zCall( 0x005D3720 );
    void SetAI( zCAIBase* )                                                                            zCall( 0x005D3730 );
    void SetVobPresetName( zSTRING const& )                                                            zCall( 0x005D3780 );
    zSTRING const& GetVobPresetName() const                                                            zCall( 0x005D3790 );
    zCRigidBody* GetRigidBody()                                                                        zCall( 0x005D37A0 );
    void __fastcall ArchivePacked( zCArchiver& )                                                       zCall( 0x005D3820 );
    void __fastcall ArchiveVerbose( zCArchiver& )                                                      zCall( 0x005D3BB0 );
    void __fastcall UnarchivePacked( zCArchiver&, int )                                                zCall( 0x005D3F90 );
    void __fastcall UnarchiveVerbose( zCArchiver& )                                                    zCall( 0x005D43E0 );
    void SetVobName( zSTRING const& )                                                                  zCall( 0x005D4970 );
    zCEventManager* __fastcall GetEM( int = 0 )                                                        zCall( 0x005D49B0 );
    zCOLOR CalcLightSampleAtOrigin()                                                                   zCall( 0x005D4CD0 );
    zCOLOR GetLightColorStat()                                                                         zCall( 0x005D4D50 );
    zCOLOR GetLightColorDyn()                                                                          zCall( 0x005D4FE0 );
    int __fastcall CalcStaticLight( zVEC3& ) const                                                     zCall( 0x005D51E0 );
    zSTRING const* GetSectorNameVobIsIn() const                                                        zCall( 0x005D5690 );
    void __fastcall SetGroundShadowSize( zVEC2 const& )                                                zCall( 0x005D57E0 );
    zVEC2 __fastcall GetGroundShadowSize() const                                                       zCall( 0x005D5830 );
    void __fastcall RenderGroundShadow( zTRenderContext& )                                             zCall( 0x005D5880 );
    zCVisual* GetClassHelperVisual() const                                                             zCall( 0x005D5D60 );
    void CalcRenderAlpha( float, zCVisual*&, float& )                                                  zCall( 0x005D5F60 );
    zCOLOR GetLightColorAtCenter() const                                                               zCall( 0x005D64E0 );
    void RemoveVobFromWorld()                                                                          zCall( 0x005D6670 );
    void RemoveVobSubtreeFromWorld()                                                                   zCall( 0x005D6690 );
    void AddRefVobSubtree( zCTree<zCVob>* )                                                            zCall( 0x005D66F0 );
    void ReleaseVobSubtree( zCTree<zCVob>* )                                                           zCall( 0x005D6730 );
    void RemoveWorldDependencies( int )                                                                zCall( 0x005D6790 );
    void RemoveVobFromGlobalVobTree()                                                                  zCall( 0x005D69E0 );
    void RemoveVobFromBspTree()                                                                        zCall( 0x005D6AC0 );
    zSTRING GetVobInfo()                                                                               zCall( 0x005D6AE0 );
    void SetSleeping( int )                                                                            zCall( 0x005D7250 );
    void UpdateVisualDependencies()                                                                    zCall( 0x005D7460 );
    void AddVobToWorld_CorrectParentDependencies()                                                     zCall( 0x005D74F0 );
    void ResetOnTimer()                                                                                zCall( 0x005D7510 );
    void SetOnTimer( float )                                                                           zCall( 0x005D7520 );
    int IsOnTimer() const                                                                              zCall( 0x005D7550 );
    void ProcessOnTimer()                                                                              zCall( 0x005D7570 );
    void DoFrameActivity()                                                                             zCall( 0x005D75A0 );
    void CheckModelLimbCollision( zCModelNodeInst*, int, zCList<zTModelLimbColl>& )                    zCall( 0x005D77B0 );
    zMAT4 GetTrafoModelNodeToWorld( zSTRING const& )                                                   zCall( 0x005D83E0 );
    zMAT4 GetTrafoModelNodeToWorld( zCModelNodeInst* )                                                 zCall( 0x005D84D0 );
    zTBBox2D GetScreenBBox2D() const                                                                   zCall( 0x005D8560 );
    void PackStateBinary( zCBuffer& ) const                                                            zCall( 0x005D88D0 );
    void UnpackStateBinary( zCBuffer& )                                                                zCall( 0x005D8980 );
    zCVisual* GetVisual() const                                                                        zCall( 0x005E9A70 );
    void CalcGroundPoly()                                                                              zCall( 0x005ED8A0 );
    void SetCollTypeDefaultFromVisual()                                                                zCall( 0x005ED9F0 );
    void TouchMovement()                                                                               zCall( 0x005EDB60 );
    zMAT4 const& GetNewTrafoObjToWorld() const                                                         zCall( 0x005EDB80 );
    zMAT4& GetNewTrafoObjToWorld()                                                                     zCall( 0x005EDBA0 );
    void SetNewTrafoObjToWorld( zMAT4 const& )                                                         zCall( 0x005EDBC0 );
    void SetBBox3DWorld( zTBBox3D const& )                                                             zCall( 0x005EDBE0 );
    void SetBBox3DLocal( zTBBox3D const& )                                                             zCall( 0x005EDC40 );
    zTBBox3D GetBBox3DLocal() const                                                                    zCall( 0x005EDCF0 );
    void Move( float, float, float )                                                                   zCall( 0x005EDDE0 );
    void MoveWorld( float, float, float )                                                              zCall( 0x005EDE50 );
    void MoveLocal( float, float, float )                                                              zCall( 0x005EDEC0 );
    void SetRotationWorld( zCQuat const& )                                                             zCall( 0x005EDFB0 );
    void RotateWorld( zVEC3 const&, float )                                                            zCall( 0x005EE010 );
    void RotateLocal( zVEC3 const&, float )                                                            zCall( 0x005EE100 );
    void RotateLocalX( float )                                                                         zCall( 0x005EE1A0 );
    void RotateLocalY( float )                                                                         zCall( 0x005EE210 );
    void RotateLocalZ( float )                                                                         zCall( 0x005EE280 );
    void RotateWorldX( float )                                                                         zCall( 0x005EE2F0 );
    void RotateWorldY( float )                                                                         zCall( 0x005EE320 );
    void RotateWorldZ( float )                                                                         zCall( 0x005EE350 );
    void GetPositionWorld( float&, float&, float& ) const                                              zCall( 0x005EE380 );
    void GetPositionLocal( float&, float&, float& ) const                                              zCall( 0x005EE3B0 );
    float GetDistanceToVob( zCVob& )                                                                   zCall( 0x005EE400 );
    float GetDistanceToVobApprox( zCVob& )                                                             zCall( 0x005EE460 );
    float GetDistanceToVob2( zCVob& )                                                                  zCall( 0x005EE530 );
    void SetPositionLocal( zVEC3 const& )                                                              zCall( 0x005EE590 );
    void SetPositionWorld( zVEC3 const& )                                                              zCall( 0x005EE650 );
    void SetTrafo( zMAT4 const& )                                                                      zCall( 0x005EE6B0 );
    void SetTrafoObjToWorld( zMAT4 const& )                                                            zCall( 0x005EE760 );
    void ResetRotationsLocal()                                                                         zCall( 0x005EE7C0 );
    void ResetXZRotationsLocal()                                                                       zCall( 0x005EE8E0 );
    void ResetRotationsWorld()                                                                         zCall( 0x005EEAB0 );
    void ResetXZRotationsWorld()                                                                       zCall( 0x005EEB40 );
    void SetHeadingYLocal( zVEC3 const& )                                                              zCall( 0x005EEC60 );
    void SetHeadingYWorld( zVEC3 const& )                                                              zCall( 0x005EED30 );
    void SetHeadingYWorld( zCVob* )                                                                    zCall( 0x005EEF00 );
    void SetHeadingLocal( zVEC3 const& )                                                               zCall( 0x005EF090 );
    void SetHeadingWorld( zVEC3 const& )                                                               zCall( 0x005EF150 );
    void SetHeadingWorld( zCVob* )                                                                     zCall( 0x005EF210 );
    void SetHeadingAtLocal( zVEC3 const& )                                                             zCall( 0x005EF2F0 );
    int HasParentVob() const                                                                           zCall( 0x005EF620 );
    void SetHeadingAtWorld( zVEC3 const& )                                                             zCall( 0x005EF640 );
    void __fastcall SetCollDetStat( int )                                                              zCall( 0x005EF8D0 );
    void __fastcall SetCollDetDyn( int )                                                               zCall( 0x005EF9C0 );
    void CorrectTrafo()                                                                                zCall( 0x005EFAC0 );
    void DoneWithTrafoLocal()                                                                          zCall( 0x005EFB30 );
    void CreateTrafoLocal() const                                                                      zCall( 0x005EFB80 );
    void SetPhysicsEnabled( int )                                                                      zCall( 0x005EFC20 );
    zVEC3 GetVelocity()                                                                                zCall( 0x005EFC50 );
    void UpdatePhysics()                                                                               zCall( 0x005EFD60 );
    int DetectCollision( zMAT4* )                                                                      zCall( 0x005F0320 );
    void __fastcall SetInMovement( int )                                                               zCall( 0x005F0460 );
    void __fastcall SetInMovementMode( zTMovementMode )                                                zCall( 0x005F04C0 );
    void BeginMovement()                                                                               zCall( 0x005F0510 );
    void ResetToOldMovementState()                                                                     zCall( 0x005F0690 );
    void __fastcall UpdateTouchList( zCArray<zCVob*> const& )                                          zCall( 0x005F06C0 );
    void __fastcall CalcDestinationBBox3DWorld( zTBBox3D& )                                            zCall( 0x005F0970 );
    void AdoptCollObjResults()                                                                         zCall( 0x005F0AB0 );
    void SetCollisionObject( zCCollisionObject* )                                                      zCall( 0x005F1050 );
    void SetCollisionClass( zCCollisionObjectDef* )                                                    zCall( 0x005F1080 );
    zCCollisionObject* GetCollisionObject() const                                                      zCall( 0x005F10C0 );
    void CreateCollisionObject()                                                                       zCall( 0x005F10D0 );
    void ResetCollisionObjectState()                                                                   zCall( 0x005F1100 );
    void __fastcall DestroyCollisionObject( int )                                                      zCall( 0x005F1140 );
    void CheckEmergencyPutToSleep()                                                                    zCall( 0x005F1180 );
    void __fastcall CollectCollisionContext_Vobs( zTBBox3D const&, zTCollisionContext& )               zCall( 0x005F12D0 );
    void __fastcall CollectCollisionContext_Static( zTBBox3D const&, zCArray<zCCollisionObject*>& )    zCall( 0x005F1530 );
    void __fastcall CollectCollisionContext( zTCollisionContext& )                                     zCall( 0x005F1840 );
    void __fastcall CleanupCollisionContext( zTCollisionContext const& )                               zCall( 0x005F18C0 );
    void __fastcall NotifyCollisionPair( zCCollisionReport*, zCArray<zCCollisionReport*> const&, int ) zCall( 0x005F1930 );
    void __fastcall ExecuteCollisionResponse( zCArray<zCCollisionReport*> const&, int& )               zCall( 0x005F1A00 );
    void CheckAndResolveCollisions()                                                                   zCall( 0x005F1AE0 );
    int IsColliding()                                                                                  zCall( 0x005F1F40 );
    void SetStaticVob( int )                                                                           zCall( 0x00645000 );
    zTVobType GetVobType() const                                                                       zCall( 0x00645020 );
    void SetDrawBBox3D( int )                                                                          zCall( 0x00645030 );
    void SetCollDet( int )                                                                             zCall( 0x00645050 );
    zCWorld* GetHomeWorld() const                                                                      zCall( 0x0073F4D0 );
    static zCObject* _CreateNewInstance()                                                              zCall( 0x005D2760 );
    static void InitVobSystem()                                                                        zCall( 0x005D3510 );
    static void CleanupVobSystem()                                                                     zCall( 0x005D3640 );
    static void ResetIDCtr()                                                                           zCall( 0x005D3700 );
    static unsigned long GetNextFreeVobID()                                                            zCall( 0x005D3710 );
    static void LoadGroundShadowMesh()                                                                 zCall( 0x005D56B0 );
    static void DeleteGroundShadowMesh()                                                               zCall( 0x005D57B0 );
    static void RepairIllegalFloats( zMAT4& )                                                          zCall( 0x005D87D0 );
    static zCVob* GetAutoLinkParent( zCVob* )                                                          zCall( 0x005ED290 );
    static int CanAutoLinkWith( zCVob*, zCVob* )                                                       zCall( 0x005ED2D0 );
    static void CheckAutoLink( zCVob*, zCVob* )                                                        zCall( 0x005ED410 );
    static void CheckAutoUnlink( zCVob* )                                                              zCall( 0x005ED690 );
    static void SetShowHelperVisuals( int )                                                            zCall( 0x00607650 );
    static int GetShowHelperVisuals()                                                                  zCall( 0x00607660 );
    virtual zCClassDef* _GetClassDef() const                                                           zCall( 0x00439220 );
    virtual void Archive( zCArchiver& )                                                                zCall( 0x005D3ED0 );
    virtual void Unarchive( zCArchiver& )                                                              zCall( 0x005D4820 );
    virtual ~zCVob()                                                                                   zCall( 0x005D32A0 );
    virtual void OnTrigger( zCVob*, zCVob* )                                                           zCall( 0x005D2FC0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                                         zCall( 0x005D2FD0 );
    virtual void OnTouch( zCVob* )                                                                     zCall( 0x005D2FE0 );
    virtual void OnUntouch( zCVob* )                                                                   zCall( 0x005D2FF0 );
    virtual void OnTouchLevel()                                                                        zCall( 0x005D3000 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )                                  zCall( 0x005D3010 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                                  zCall( 0x005D3020 );
    virtual void OnTick()                                                                              zCall( 0x00404130 );
    virtual void OnTimer()                                                                             zCall( 0x00439230 );
    virtual void PostLoad()                                                                            zCall( 0x00404140 );
    virtual zTVobCharClass GetCharacterClass()                                                         zCall( 0x00404150 );
    virtual void SetSleepingMode( zTVobSleepingMode )                                                  zCall( 0x005D7280 );
    virtual void EndMovement()                                                                         zCall( 0x005F0B60 );
    virtual int CanThisCollideWith( zCVob* )                                                           zCall( 0x00404160 );
    virtual int __fastcall Render( zTRenderContext& )                                                  zCall( 0x005D6090 );
    virtual void SetVisual( zCVisual* )                                                                zCall( 0x005D6E10 );
    virtual void SetVisual( zSTRING const& )                                                           zCall( 0x005D6FA0 );
    virtual int GetScriptInstance( zSTRING*&, int& )                                                   zCall( 0x00404170 );
    virtual int SetByScriptInstance( zSTRING const*, int )                                             zCall( 0x00404190 );
    virtual int GetCSStateFlags()                                                                      zCall( 0x004041A0 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& )                         zCall( 0x005D49E0 );
    virtual zSTRING const* GetTriggerTarget( int ) const                                               zCall( 0x00439240 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                       zCall( 0x005D66B0 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                                   zCall( 0x005D66D0 );


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

    void zCVobLightData_OnInit()               zCall( 0x005DDBA0 );
    int SetLensFlareFXByName( zSTRING const& ) zCall( 0x005DCC70 );
    zSTRING const& GetLensFlareFXName() const  zCall( 0x005DCD70 );
    void Archive( zCArchiver& )                zCall( 0x005DCD90 );
    void Unarchive( zCArchiver& )              zCall( 0x005DD200 );
    zCVobLightData()                           zInit( zCVobLightData_OnInit() );
    ~zCVobLightData()                          zCall( 0x005DDC10 );
    void SetRange( float, int )                zCall( 0x005DDC80 );

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
    static zCObject* _CreateNewInstance()                               zCall( 0x005D2350 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005D24B0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005DCA90 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005DCAC0 );
    virtual ~zCVobLightPreset()                                         zCall( 0x005D24F0 );

    // user API
    #include "zCVobLightPreset.inl"
  };

  // sizeof 15Ch
  class zCVobLight : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobLight )

    zCVobLightData lightData; // sizeof 48h    offset 100h
    zSTRING lightPresetInUse; // sizeof 14h    offset 148h

    void zCVobLight_OnInit()                                                              zCall( 0x005DB4A0 );
    zCVobLight()                                                                          zInit( zCVobLight_OnInit() );
    void DoAnimation()                                                                    zCall( 0x005DB820 );
    void SetRange( float, int )                                                           zCall( 0x005DBAF0 );
    void AddThisToPresetList( zSTRING const& ) const                                      zCall( 0x005DC0E0 );
    int SetByPreset( zSTRING const& )                                                     zCall( 0x005DC3C0 );
    int SetByPresetInUse()                                                                zCall( 0x005DC650 );
    static zCObject* _CreateNewInstance()                                                 zCall( 0x005DB350 );
    static void CleanupVobLight()                                                         zCall( 0x005DB640 );
    static zCOLOR SumLightsAtPositionWS( zCArray<zCVobLight*> const&, zVEC3 const&, int ) zCall( 0x005DBBE0 );
    static void LoadLightPresets()                                                        zCall( 0x005DBE60 );
    static void SaveLightPresets()                                                        zCall( 0x005DBFB0 );
    virtual zCClassDef* _GetClassDef() const                                              zCall( 0x005DB440 );
    virtual void Archive( zCArchiver& )                                                   zCall( 0x005DC890 );
    virtual void Unarchive( zCArchiver& )                                                 zCall( 0x005DC8E0 );
    virtual ~zCVobLight()                                                                 zCall( 0x005DB580 );
    virtual void OnTrigger( zCVob*, zCVob* )                                              zCall( 0x005DB6B0 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                            zCall( 0x005DB780 );


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

    void zCVobLevelCompo_OnInit()                                       zCall( 0x005D8A30 );
    zCVobLevelCompo()                                                   zInit( zCVobLevelCompo_OnInit() );
    int HasIdentityTrafo() const                                        zCall( 0x005D8A90 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005D29C0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005D2A80 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x005D8B10 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x005D8BC0 );
    virtual ~zCVobLevelCompo()                                          zCall( 0x005D2AC0 );
    virtual void SetVisual( zCVisual* )                                 zCall( 0x005D8C90 );
    virtual void SetVisual( zSTRING const& )                            zCall( 0x005D8CD0 );


    // static properties
    static int& unarcIgnoreVisuals;

    // user API
    #include "zCVobLevelCompo.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZVOB_H__VER0__