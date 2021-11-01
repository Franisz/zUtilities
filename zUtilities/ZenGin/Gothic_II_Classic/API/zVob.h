// Supported with union (c) 2018-2021 Union team

#ifndef __ZVOB_H__VER2__
#define __ZVOB_H__VER2__

namespace Gothic_II_Classic {

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

  enum zTAnimationMode {
    zVISUAL_ANIMODE_NONE,
    zVISUAL_ANIMODE_WIND,
    zVISUAL_ANIMODE_WIND2
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

    void zCEventMessage_OnInit()                                                    zCall( 0x00413B60 );
    void zCEventMessage_OnInit( unsigned short )                                    zCall( 0x005FE6D0 );
    zCEventMessage()                                                                zInit( zCEventMessage_OnInit() );
    zCEventMessage( unsigned short a0 )                                             zInit( zCEventMessage_OnInit( a0 ));
    unsigned long GetMessageID() const                                              zCall( 0x005FE840 );
    void PackToBuffer( zCBuffer&, zCEventManager* )                                 zCall( 0x005FE8A0 );
    unsigned short GetSubType() const                                               zCall( 0x0078AFB0 );
    static zCObject* _CreateNewInstance()                                           zCall( 0x005F6100 );
    static void AnalyzeMessageID( unsigned long, unsigned short&, unsigned short& ) zCall( 0x005FE860 );
    static zCEventMessage* CreateFromID( unsigned long )                            zCall( 0x005FE880 );
    static zCEventMessage* CreateFromBuffer( zCBuffer&, zCEventManager* )           zCall( 0x005FE8F0 );
    static void TestClassIntegrity()                                                zCall( 0x005FEB50 );
    virtual zCClassDef* _GetClassDef() const                                        zCall( 0x00401F30 );
    virtual void Archive( zCArchiver& )                                             zCall( 0x005FE930 );
    virtual void Unarchive( zCArchiver& )                                           zCall( 0x005FEB30 );
    virtual ~zCEventMessage()                                                       zCall( 0x004020D0 );
    virtual int IsOverlay()                                                         zCall( 0x00401F40 );
    virtual int IsNetRelevant()                                                     zCall( 0x00401F50 );
    virtual int IsHighPriority()                                                    zCall( 0x00401F60 );
    virtual int IsJob()                                                             zCall( 0x00401F70 );
    virtual int GetIgnoreCutsceneMode()                                             zCall( 0x00401F80 );
    virtual void Delete()                                                           zCall( 0x00401F90 );
    virtual int IsDeleteable()                                                      zCall( 0x00401FA0 );
    virtual int IsDeleted()                                                         zCall( 0x00401FB0 );
    virtual void SetCutsceneMode( int )                                             zCall( 0x00401FC0 );
    virtual int GetCutsceneMode()                                                   zCall( 0x00401FD0 );
    virtual int MD_GetNumOfSubTypes()                                               zCall( 0x00401FE0 );
    virtual zSTRING MD_GetSubTypeString( int )                                      zCall( 0x00401FF0 );
    virtual zSTRING MD_GetVobRefName()                                              zCall( 0x00402030 );
    virtual void MD_SetVobRefName( zSTRING const& )                                 zCall( 0x00402070 );
    virtual void MD_SetVobParam( zCVob* )                                           zCall( 0x00402080 );
    virtual zTTimeBehavior MD_GetTimeBehavior()                                     zCall( 0x00402090 );
    virtual float MD_GetMinTime()                                                   zCall( 0x004020A0 );
    virtual void Pack( zCBuffer&, zCEventManager* )                                 zCall( 0x004020B0 );
    virtual void Unpack( zCBuffer&, zCEventManager* )                               zCall( 0x004020C0 );

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
    void Clear()                                      zCall( 0x005FF230 );
    static zCObject* _CreateNewInstance()             zCall( 0x005F6460 );
    virtual zCClassDef* _GetClassDef() const          zCall( 0x00402130 );
    virtual void Archive( zCArchiver& )               zCall( 0x005FF660 );
    virtual void Unarchive( zCArchiver& )             zCall( 0x005FF6D0 );
    virtual ~zCEventCore()                            zCall( 0x005FF270 );
    virtual int IsNetRelevant()                       zCall( 0x00402150 );
    virtual int MD_GetNumOfSubTypes()                 zCall( 0x00402140 );
    virtual zSTRING MD_GetSubTypeString( int )        zCall( 0x005FF460 );
    virtual void Pack( zCBuffer&, zCEventManager* )   zCall( 0x005FF290 );
    virtual void Unpack( zCBuffer&, zCEventManager* ) zCall( 0x005FF340 );

    // user API
    #include "zCEventCore.inl"
  };

  // sizeof 120h
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
      ~zTCollisionContext() zCall( 0x00617D40 );

      // user API
      #include "zCVob_zTCollisionContext.inl"
    };

    // sizeof 1Ch
    struct zTModelLimbColl {
      zCVob* hitVob;                            // sizeof 04h    offset 00h
      zCMaterial* hitMaterial;                  // sizeof 04h    offset 04h
      zCList<zCModelNodeInst> hitModelNodeList; // sizeof 08h    offset 08h
      zVEC3 approxCollisionPos;                 // sizeof 0Ch    offset 10h

      void zTModelLimbColl_OnInit() zCall( 0x005FCBA0 );
      zTModelLimbColl()             zInit( zTModelLimbColl_OnInit() );
      ~zTModelLimbColl()            zCall( 0x005FCBD0 );

      // user API
      #include "zCVob_zTModelLimbColl.inl"
    };

    zCTree<zCVob>* globalVobTreeNode;               // sizeof 04h    offset 24h
    int lastTimeDrawn;                              // sizeof 04h    offset 28h
    unsigned long lastTimeCollected;                // sizeof 04h    offset 2Ch
    zCArray<zCBspLeaf*> vobLeafList;                // sizeof 0Ch    offset 30h
    zMAT4 trafoObjToWorld;                          // sizeof 40h    offset 3Ch
    zTBBox3D bbox3D;                                // sizeof 18h    offset 7Ch
    zTBSphere3D bsphere3D;                          // sizeof 10h    offset 94h
    zCArray<zCVob*> touchVobList;                   // sizeof 0Ch    offset A4h
    zTVobType type;                                 // sizeof 04h    offset B0h
    unsigned long groundShadowSizePacked;           // sizeof 04h    offset B4h
    zCWorld* homeWorld;                             // sizeof 04h    offset B8h
    zCPolygon* groundPoly;                          // sizeof 04h    offset BCh
    zCAIBase* callback_ai;                          // sizeof 04h    offset C0h
    zMAT4* trafo;                                   // sizeof 04h    offset C4h
    zCVisual* visual;                               // sizeof 04h    offset C8h
    float visualAlpha;                              // sizeof 04h    offset CCh
    float m_fVobFarClipZScale;                      // sizeof 04h    offset D0h
    zTAnimationMode m_AniMode;                      // sizeof 04h    offset D4h
    float m_aniModeStrength;                        // sizeof 04h    offset D8h
    int m_zBias;                                    // sizeof 04h    offset DCh
    zCRigidBody* rigidBody;                         // sizeof 04h    offset E0h
    zCOLOR lightColorStat;                          // sizeof 04h    offset E4h
    zCOLOR lightColorDyn;                           // sizeof 04h    offset E8h
    zVEC3 lightDirectionStat;                       // sizeof 0Ch    offset ECh
    zSTRING* vobPresetName;                         // sizeof 04h    offset F8h
    zCEventManager* eventManager;                   // sizeof 04h    offset FCh
    float nextOnTimer;                              // sizeof 04h    offset 100h
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
      unsigned char collButNoMove             : 4;  // sizeof 04h    offset bit
      unsigned char dontWriteIntoArchive      : 1;  // sizeof 01h    offset bit
      unsigned char bIsInWater                : 1;  // sizeof 01h    offset bit
      unsigned char bIsAmbientVob             : 1;  // sizeof 01h    offset bit
    };
    zCCollisionObjectDef* m_poCollisionObjectClass; // sizeof 04h    offset 118h
    zCCollisionObject* m_poCollisionObject;         // sizeof 04h    offset 11Ch

    void zCVob_OnInit()                                                                                           zCall( 0x005F73F0 );
    zVEC3 GetPositionWorld() const                                                                                zCall( 0x0052AD40 );
    zVEC3 GetAtVectorWorld() const                                                                                zCall( 0x0052AD60 );
    zVEC3 GetUpVectorWorld() const                                                                                zCall( 0x0052AD80 );
    zVEC3 GetRightVectorWorld() const                                                                             zCall( 0x0052ADA0 );
    zCVob()                                                                                                       zInit( zCVob_OnInit() );
    void SetVobID( unsigned long const& )                                                                         zCall( 0x005F7AF0 );
    void SetAI( zCAIBase* )                                                                                       zCall( 0x005F7B00 );
    void SetVobPresetName( zSTRING const& )                                                                       zCall( 0x005F7B50 );
    zSTRING const& GetVobPresetName() const                                                                       zCall( 0x005F7B60 );
    zCRigidBody* GetRigidBody()                                                                                   zCall( 0x005F7B70 );
    void __fastcall ArchivePacked( zCArchiver& )                                                                  zCall( 0x005F7BE0 );
    void __fastcall ArchiveVerbose( zCArchiver& )                                                                 zCall( 0x005F7FC0 );
    void __fastcall UnarchivePacked( zCArchiver&, int )                                                           zCall( 0x005F8410 );
    void __fastcall UnarchiveVerbose( zCArchiver& )                                                               zCall( 0x005F8930 );
    void SetVobName( zSTRING const& )                                                                             zCall( 0x005F8FD0 );
    zCEventManager* __fastcall GetEM( int = 0 )                                                                   zCall( 0x005F9010 );
    zCOLOR CalcLightSampleAtOrigin()                                                                              zCall( 0x005F9330 );
    zCOLOR GetLightColorStat()                                                                                    zCall( 0x005F93B0 );
    zCOLOR GetLightColorStatGroundPoly()                                                                          zCall( 0x005F9640 );
    zCOLOR GetLightColorDyn()                                                                                     zCall( 0x005F9670 );
    int __fastcall CalcStaticLight( zVEC3& ) const                                                                zCall( 0x005F9850 );
    zSTRING const* GetSectorNameVobIsIn() const                                                                   zCall( 0x005F9CE0 );
    void __fastcall SetGroundShadowSize( zVEC2 const& )                                                           zCall( 0x005F9E30 );
    zVEC2 __fastcall GetGroundShadowSize() const                                                                  zCall( 0x005F9E80 );
    void __fastcall RenderGroundShadow( zTRenderContext& )                                                        zCall( 0x005F9ED0 );
    zCVisual* GetClassHelperVisual() const                                                                        zCall( 0x005FA3C0 );
    void CalcRenderAlpha( float, zCVisual*&, float& )                                                             zCall( 0x005FA5C0 );
    zCOLOR GetLightColorAtCenter() const                                                                          zCall( 0x005FAC90 );
    void RemoveVobFromWorld()                                                                                     zCall( 0x005FAE10 );
    void RemoveVobSubtreeFromWorld()                                                                              zCall( 0x005FAE30 );
    void AddRefVobSubtree( zCTree<zCVob>*, int )                                                                  zCall( 0x005FAE90 );
    void ReleaseVobSubtree( zCTree<zCVob>* )                                                                      zCall( 0x005FAF10 );
    void RemoveWorldDependencies( int )                                                                           zCall( 0x005FAF70 );
    void RemoveVobFromGlobalVobTree()                                                                             zCall( 0x005FB1C0 );
    void RemoveVobFromBspTree()                                                                                   zCall( 0x005FB2B0 );
    zSTRING GetVobInfo()                                                                                          zCall( 0x005FB2D0 );
    void SetSleeping( int )                                                                                       zCall( 0x005FBB00 );
    void UpdateVisualDependencies()                                                                               zCall( 0x005FBCF0 );
    void AddVobToWorld_CorrectParentDependencies()                                                                zCall( 0x005FBD80 );
    void ResetOnTimer()                                                                                           zCall( 0x005FBDA0 );
    void SetOnTimer( float )                                                                                      zCall( 0x005FBDB0 );
    int IsOnTimer() const                                                                                         zCall( 0x005FBDE0 );
    void ProcessOnTimer()                                                                                         zCall( 0x005FBE00 );
    void DoFrameActivity()                                                                                        zCall( 0x005FBE30 );
    void CheckModelLimbCollision( zCModelNodeInst*, int, zCList<zTModelLimbColl>& )                               zCall( 0x005FC050 );
    void CheckModelLimbCollisionLevel( zCModelNodeInst*, int, zCList<zTModelLimbColl>& )                          zCall( 0x005FCC00 );
    void CheckModelLimbCollisionPolys( zCModelNodeInst*, int, zCPolygon**, int const&, zCList<zTModelLimbColl>& ) zCall( 0x005FD890 );
    zMAT4 GetTrafoModelNodeToWorld( zSTRING const& )                                                              zCall( 0x005FDAE0 );
    zMAT4 GetTrafoModelNodeToWorld( zCModelNodeInst* )                                                            zCall( 0x005FDBD0 );
    zTBBox2D GetScreenBBox2D()                                                                                    zCall( 0x005FDC60 );
    void PackStateBinary( zCBuffer& ) const                                                                       zCall( 0x005FE290 );
    void UnpackStateBinary( zCBuffer& )                                                                           zCall( 0x005FE340 );
    zCVisual* GetVisual() const                                                                                   zCall( 0x0060F460 );
    void CalcGroundPoly()                                                                                         zCall( 0x00613610 );
    void CalcWaterVob()                                                                                           zCall( 0x00613760 );
    void SetCollTypeDefaultFromVisual()                                                                           zCall( 0x00613830 );
    void TouchMovement()                                                                                          zCall( 0x006139A0 );
    zMAT4 const& GetNewTrafoObjToWorld() const                                                                    zCall( 0x006139C0 );
    zMAT4& GetNewTrafoObjToWorld()                                                                                zCall( 0x006139E0 );
    void SetNewTrafoObjToWorld( zMAT4 const& )                                                                    zCall( 0x00613A00 );
    void SetBBox3DWorld( zTBBox3D const& )                                                                        zCall( 0x00613A20 );
    void SetBBox3DLocal( zTBBox3D const& )                                                                        zCall( 0x00613A80 );
    zTBBox3D GetBBox3DLocal() const                                                                               zCall( 0x00613B30 );
    void Move( float, float, float )                                                                              zCall( 0x00613C20 );
    void MoveWorld( float, float, float )                                                                         zCall( 0x00613C90 );
    void MoveLocal( float, float, float )                                                                         zCall( 0x00613D00 );
    void SetRotationWorld( zCQuat const& )                                                                        zCall( 0x00613DF0 );
    void RotateWorld( zVEC3 const&, float )                                                                       zCall( 0x00613E50 );
    void RotateLocal( zVEC3 const&, float )                                                                       zCall( 0x00613F40 );
    void RotateLocalX( float )                                                                                    zCall( 0x00613FE0 );
    void RotateLocalY( float )                                                                                    zCall( 0x00614050 );
    void RotateLocalZ( float )                                                                                    zCall( 0x006140C0 );
    void RotateWorldX( float )                                                                                    zCall( 0x00614130 );
    void RotateWorldY( float )                                                                                    zCall( 0x00614160 );
    void RotateWorldZ( float )                                                                                    zCall( 0x00614190 );
    void GetPositionWorld( float&, float&, float& ) const                                                         zCall( 0x006141C0 );
    void GetPositionLocal( float&, float&, float& ) const                                                         zCall( 0x006141F0 );
    float GetDistanceToVob( zCVob& )                                                                              zCall( 0x00614240 );
    float GetDistanceToVobApprox( zCVob& )                                                                        zCall( 0x006142A0 );
    float GetDistanceToVob2( zCVob& )                                                                             zCall( 0x00614370 );
    void SetPositionLocal( zVEC3 const& )                                                                         zCall( 0x006143D0 );
    void SetPositionWorld( zVEC3 const& )                                                                         zCall( 0x00614490 );
    void SetTrafo( zMAT4 const& )                                                                                 zCall( 0x006144F0 );
    void SetTrafoObjToWorld( zMAT4 const& )                                                                       zCall( 0x006145A0 );
    void ResetRotationsLocal()                                                                                    zCall( 0x00614600 );
    void ResetXZRotationsLocal()                                                                                  zCall( 0x00614720 );
    void ResetRotationsWorld()                                                                                    zCall( 0x006148F0 );
    void ResetXZRotationsWorld()                                                                                  zCall( 0x00614980 );
    void SetHeadingYLocal( zVEC3 const& )                                                                         zCall( 0x00614AA0 );
    void SetHeadingYWorld( zVEC3 const& )                                                                         zCall( 0x00614B70 );
    void SetHeadingYWorld( zCVob* )                                                                               zCall( 0x00614D40 );
    void SetHeadingLocal( zVEC3 const& )                                                                          zCall( 0x00614ED0 );
    void SetHeadingWorld( zVEC3 const& )                                                                          zCall( 0x00614F90 );
    void SetHeadingWorld( zCVob* )                                                                                zCall( 0x00615050 );
    void SetHeadingAtLocal( zVEC3 const& )                                                                        zCall( 0x00615130 );
    int HasParentVob() const                                                                                      zCall( 0x00615460 );
    void SetHeadingAtWorld( zVEC3 const& )                                                                        zCall( 0x00615480 );
    void __fastcall SetCollDetStat( int )                                                                         zCall( 0x00615710 );
    void __fastcall SetCollDetDyn( int )                                                                          zCall( 0x00615800 );
    void CorrectTrafo()                                                                                           zCall( 0x00615900 );
    void DoneWithTrafoLocal()                                                                                     zCall( 0x00615970 );
    void CreateTrafoLocal() const                                                                                 zCall( 0x006159C0 );
    void SetPhysicsEnabled( int )                                                                                 zCall( 0x00615A50 );
    zVEC3 GetVelocity()                                                                                           zCall( 0x00615A80 );
    void UpdatePhysics()                                                                                          zCall( 0x00615B90 );
    int DetectCollision( zMAT4* )                                                                                 zCall( 0x00616150 );
    void __fastcall SetInMovement( int )                                                                          zCall( 0x00616290 );
    void __fastcall SetInMovementMode( zTMovementMode )                                                           zCall( 0x006162F0 );
    void BeginMovement()                                                                                          zCall( 0x00616340 );
    void ResetToOldMovementState()                                                                                zCall( 0x006164C0 );
    void __fastcall UpdateTouchList( zCArray<zCVob*> const& )                                                     zCall( 0x006164F0 );
    void __fastcall CalcDestinationBBox3DWorld( zTBBox3D& )                                                       zCall( 0x006167A0 );
    void AdoptCollObjResults()                                                                                    zCall( 0x006168E0 );
    void SetCollisionObject( zCCollisionObject* )                                                                 zCall( 0x00616E90 );
    void SetCollisionClass( zCCollisionObjectDef* )                                                               zCall( 0x00616EC0 );
    zCCollisionObject* GetCollisionObject() const                                                                 zCall( 0x00616F00 );
    void CreateCollisionObject()                                                                                  zCall( 0x00616F10 );
    void ResetCollisionObjectState()                                                                              zCall( 0x00616F40 );
    void __fastcall DestroyCollisionObject( int )                                                                 zCall( 0x00616F80 );
    void CheckEmergencyPutToSleep()                                                                               zCall( 0x00616FC0 );
    void __fastcall CollectCollisionContext_Vobs( zTBBox3D const&, zTCollisionContext& )                          zCall( 0x00617120 );
    void __fastcall CollectCollisionContext_Static( zTBBox3D const&, zCArray<zCCollisionObject*>& )               zCall( 0x00617380 );
    void __fastcall CollectCollisionContext( zTCollisionContext& )                                                zCall( 0x00617670 );
    void __fastcall CleanupCollisionContext( zTCollisionContext const& )                                          zCall( 0x006176F0 );
    void __fastcall NotifyCollisionPair( zCCollisionReport*, zCArray<zCCollisionReport*> const&, int )            zCall( 0x00617760 );
    void __fastcall ExecuteCollisionResponse( zCArray<zCCollisionReport*> const&, int& )                          zCall( 0x00617830 );
    void CheckAndResolveCollisions()                                                                              zCall( 0x00617910 );
    int IsColliding()                                                                                             zCall( 0x00617DA0 );
    void SetStaticVob( int )                                                                                      zCall( 0x00673230 );
    zTVobType GetVobType() const                                                                                  zCall( 0x00673250 );
    void SetDrawBBox3D( int )                                                                                     zCall( 0x00673260 );
    void SetCollDet( int )                                                                                        zCall( 0x00673280 );
    zCWorld* GetHomeWorld() const                                                                                 zCall( 0x0078AFC0 );
    static zCObject* _CreateNewInstance()                                                                         zCall( 0x005F6B50 );
    static void InitVobSystem()                                                                                   zCall( 0x005F78F0 );
    static void CleanupVobSystem()                                                                                zCall( 0x005F7A10 );
    static void ResetIDCtr()                                                                                      zCall( 0x005F7AD0 );
    static unsigned long GetNextFreeVobID()                                                                       zCall( 0x005F7AE0 );
    static void LoadGroundShadowMesh()                                                                            zCall( 0x005F9D00 );
    static void DeleteGroundShadowMesh()                                                                          zCall( 0x005F9E00 );
    static void RepairIllegalFloats( zMAT4& )                                                                     zCall( 0x005FE090 );
    static zCVob* GetAutoLinkParent( zCVob* )                                                                     zCall( 0x00613000 );
    static int CanAutoLinkWith( zCVob*, zCVob* )                                                                  zCall( 0x00613040 );
    static void CheckAutoLink( zCVob*, zCVob* )                                                                   zCall( 0x00613180 );
    static void CheckAutoUnlink( zCVob* )                                                                         zCall( 0x00613400 );
    static void SetShowHelperVisuals( int )                                                                       zCall( 0x0062F910 );
    static int GetShowHelperVisuals()                                                                             zCall( 0x0062F920 );
    static int GetAnimationsEnabled()                                                                             zCall( 0x0062F930 );
    static void SetAnimationsEnabled( int )                                                                       zCall( 0x0062F940 );
    virtual zCClassDef* _GetClassDef() const                                                                      zCall( 0x0043C680 );
    virtual void Archive( zCArchiver& )                                                                           zCall( 0x005F8350 );
    virtual void Unarchive( zCArchiver& )                                                                         zCall( 0x005F8E80 );
    virtual ~zCVob()                                                                                              zCall( 0x005F7680 );
    virtual void OnTrigger( zCVob*, zCVob* )                                                                      zCall( 0x005F7380 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                                                    zCall( 0x005F7390 );
    virtual void OnTouch( zCVob* )                                                                                zCall( 0x005F73A0 );
    virtual void OnUntouch( zCVob* )                                                                              zCall( 0x005F73B0 );
    virtual void OnTouchLevel()                                                                                   zCall( 0x005F73C0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )                                             zCall( 0x005F73D0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                                             zCall( 0x005F73E0 );
    virtual void OnTick()                                                                                         zCall( 0x00404270 );
    virtual void OnTimer()                                                                                        zCall( 0x0043C690 );
    virtual void PostLoad()                                                                                       zCall( 0x00404280 );
    virtual zTVobCharClass GetCharacterClass()                                                                    zCall( 0x00404290 );
    virtual void SetSleepingMode( zTVobSleepingMode )                                                             zCall( 0x005FBB30 );
    virtual void EndMovement()                                                                                    zCall( 0x00616990 );
    virtual int CanThisCollideWith( zCVob* )                                                                      zCall( 0x004042A0 );
    virtual int __fastcall Render( zTRenderContext& )                                                             zCall( 0x005FA7A0 );
    virtual void SetVisual( zCVisual* )                                                                           zCall( 0x005FB6C0 );
    virtual void SetVisual( zSTRING const& )                                                                      zCall( 0x005FB850 );
    virtual int GetScriptInstance( zSTRING*&, int& )                                                              zCall( 0x004042B0 );
    virtual int SetByScriptInstance( zSTRING const*, int )                                                        zCall( 0x004042D0 );
    virtual int GetCSStateFlags()                                                                                 zCall( 0x004042E0 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& )                                    zCall( 0x005F9040 );
    virtual zSTRING const* GetTriggerTarget( int ) const                                                          zCall( 0x0043C6A0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                                  zCall( 0x005FAE50 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                                              zCall( 0x005FAE70 );

    // static properties
    static int& s_ignoreVisuals;
    static zCMesh*& s_shadowMesh;
    static unsigned long& s_nextFreeID;
    static int& s_vobAlreadyInMovement;
    static int& s_renderVobs;
    static int& s_showHelperVisuals;
    static int& s_enableAnimations;
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
      unsigned char m_bCanMove     : 1; // sizeof 01h    offset bit
    };

    void zCVobLightData_OnInit()               zCall( 0x006036B0 );
    int SetLensFlareFXByName( zSTRING const& ) zCall( 0x006026B0 );
    zSTRING const& GetLensFlareFXName() const  zCall( 0x006027B0 );
    void Archive( zCArchiver& )                zCall( 0x006027D0 );
    void Unarchive( zCArchiver& )              zCall( 0x00602CE0 );
    zCVobLightData()                           zInit( zCVobLightData_OnInit() );
    ~zCVobLightData()                          zCall( 0x00603730 );
    void SetRange( float, int )                zCall( 0x006037A0 );

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
    static zCObject* _CreateNewInstance()    zCall( 0x005F6730 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x005F68A0 );
    virtual void Archive( zCArchiver& )      zCall( 0x006024D0 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00602500 );
    virtual ~zCVobLightPreset()              zCall( 0x005F68E0 );

    // user API
    #include "zCVobLightPreset.inl"
  };

  // sizeof 17Ch
  class zCVobLight : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobLight )

    zCVobLightData lightData; // sizeof 48h    offset 120h
    zSTRING lightPresetInUse; // sizeof 14h    offset 168h

    void zCVobLight_OnInit()                                                              zCall( 0x00600EF0 );
    zCVobLight()                                                                          zInit( zCVobLight_OnInit() );
    void DoAnimation()                                                                    zCall( 0x00601270 );
    void SetRange( float, int )                                                           zCall( 0x00601540 );
    void AddThisToPresetList( zSTRING const& ) const                                      zCall( 0x00601B30 );
    int SetByPreset( zSTRING const& )                                                     zCall( 0x00601E00 );
    int SetByPresetInUse()                                                                zCall( 0x00602080 );
    static zCObject* _CreateNewInstance()                                                 zCall( 0x00600DB0 );
    static void CleanupVobLight()                                                         zCall( 0x00601090 );
    static zCOLOR SumLightsAtPositionWS( zCArray<zCVobLight*> const&, zVEC3 const&, int ) zCall( 0x00601630 );
    static void LoadLightPresets()                                                        zCall( 0x006018B0 );
    static void SaveLightPresets()                                                        zCall( 0x00601A00 );
    virtual zCClassDef* _GetClassDef() const                                              zCall( 0x00600E90 );
    virtual void Archive( zCArchiver& )                                                   zCall( 0x006022D0 );
    virtual void Unarchive( zCArchiver& )                                                 zCall( 0x00602320 );
    virtual ~zCVobLight()                                                                 zCall( 0x00600FD0 );
    virtual void OnTrigger( zCVob*, zCVob* )                                              zCall( 0x00601100 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                            zCall( 0x006011D0 );

    // static properties
    static zCArray<zCVobLightPreset*>& lightPresetList;
    static int& renderLightVisuals;

    // user API
    #include "zCVobLight.inl"
  };

  // sizeof 120h
  class zCVobLevelCompo : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobLevelCompo )

    void zCVobLevelCompo_OnInit()            zCall( 0x005FE3F0 );
    zCVobLevelCompo()                        zInit( zCVobLevelCompo_OnInit() );
    int HasIdentityTrafo() const             zCall( 0x005FE450 );
    static zCObject* _CreateNewInstance()    zCall( 0x005F6DA0 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x005F6E40 );
    virtual void Archive( zCArchiver& )      zCall( 0x005FE4D0 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x005FE580 );
    virtual ~zCVobLevelCompo()               zCall( 0x005F6E80 );
    virtual void SetVisual( zCVisual* )      zCall( 0x005FE650 );
    virtual void SetVisual( zSTRING const& ) zCall( 0x005FE690 );

    // static properties
    static int& unarcIgnoreVisuals;

    // user API
    #include "zCVobLevelCompo.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVOB_H__VER2__