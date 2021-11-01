// Supported with union (c) 2018-2021 Union team

#ifndef __ZVOB_H__VER3__
#define __ZVOB_H__VER3__

#include "z3d.h"
#include "zBsp.h"
#include "zSound.h"
#include "zVisual.h"

namespace Gothic_II_Addon {

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
    void zCEventMessage_OnInit( unsigned short )                                    zCall( 0x00605560 );
    zCEventMessage()                                                                zInit( zCEventMessage_OnInit() );
    zCEventMessage( unsigned short a0 )                                             zInit( zCEventMessage_OnInit( a0 ));
    unsigned long GetMessageID() const                                              zCall( 0x006056D0 );
    void PackToBuffer( zCBuffer&, zCEventManager* )                                 zCall( 0x00605730 );
    unsigned short GetSubType() const                                               zCall( 0x00674290 );
    static zCObject* _CreateNewInstance()                                           zCall( 0x005FCEF0 );
    static void AnalyzeMessageID( unsigned long, unsigned short&, unsigned short& ) zCall( 0x006056F0 );
    static zCEventMessage* CreateFromID( unsigned long )                            zCall( 0x00605710 );
    static zCEventMessage* CreateFromBuffer( zCBuffer&, zCEventManager* )           zCall( 0x00605780 );
    static void TestClassIntegrity()                                                zCall( 0x006059E0 );
    virtual zCClassDef* _GetClassDef() const                                        zCall( 0x00401F30 );
    virtual void Archive( zCArchiver& )                                             zCall( 0x006057C0 );
    virtual void Unarchive( zCArchiver& )                                           zCall( 0x006059C0 );
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
    void Clear()                                      zCall( 0x006060C0 );
    static zCObject* _CreateNewInstance()             zCall( 0x005FD250 );
    virtual zCClassDef* _GetClassDef() const          zCall( 0x00402130 );
    virtual void Archive( zCArchiver& )               zCall( 0x006064F0 );
    virtual void Unarchive( zCArchiver& )             zCall( 0x00606560 );
    virtual ~zCEventCore()                            zCall( 0x00606100 );
    virtual int IsNetRelevant()                       zCall( 0x00402150 );
    virtual int MD_GetNumOfSubTypes()                 zCall( 0x00402140 );
    virtual zSTRING MD_GetSubTypeString( int )        zCall( 0x006062F0 );
    virtual void Pack( zCBuffer&, zCEventManager* )   zCall( 0x00606120 );
    virtual void Unpack( zCBuffer&, zCEventManager* ) zCall( 0x006061D0 );

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
      ~zTCollisionContext() zCall( 0x0061F490 );

      // user API
      #include "zCVob_zTCollisionContext.inl"
    };

    // sizeof 1Ch
    struct zTModelLimbColl {
      zCVob* hitVob;                            // sizeof 04h    offset 00h
      zCMaterial* hitMaterial;                  // sizeof 04h    offset 04h
      zCList<zCModelNodeInst> hitModelNodeList; // sizeof 08h    offset 08h
      zVEC3 approxCollisionPos;                 // sizeof 0Ch    offset 10h

      void zTModelLimbColl_OnInit() zCall( 0x00603A20 );
      zTModelLimbColl()             zInit( zTModelLimbColl_OnInit() );
      ~zTModelLimbColl()            zCall( 0x00603A50 );

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

    void zCVob_OnInit()                                                                                           zCall( 0x005FE1E0 );
    zVEC3 GetPositionWorld() const                                                                                zCall( 0x0052DC90 );
    zVEC3 GetAtVectorWorld() const                                                                                zCall( 0x0052DCB0 );
    zVEC3 GetUpVectorWorld() const                                                                                zCall( 0x0052DCD0 );
    zVEC3 GetRightVectorWorld() const                                                                             zCall( 0x0052DCF0 );
    zCVob()                                                                                                       zInit( zCVob_OnInit() );
    void SetVobID( unsigned long const& )                                                                         zCall( 0x005FE8E0 );
    void SetAI( zCAIBase* )                                                                                       zCall( 0x005FE8F0 );
    void SetVobPresetName( zSTRING const& )                                                                       zCall( 0x005FE940 );
    zSTRING const& GetVobPresetName() const                                                                       zCall( 0x005FE950 );
    zCRigidBody* GetRigidBody()                                                                                   zCall( 0x005FE960 );
    void __fastcall ArchivePacked( zCArchiver& )                                                                  zCall( 0x005FE9D0 );
    void __fastcall ArchiveVerbose( zCArchiver& )                                                                 zCall( 0x005FEDB0 );
    void __fastcall UnarchivePacked( zCArchiver&, int )                                                           zCall( 0x005FF200 );
    void __fastcall UnarchiveVerbose( zCArchiver& )                                                               zCall( 0x005FF720 );
    void SetVobName( zSTRING const& )                                                                             zCall( 0x005FFDD0 );
    zCEventManager* __fastcall GetEM( int = 0 )                                                                   zCall( 0x005FFE10 );
    zCOLOR CalcLightSampleAtOrigin()                                                                              zCall( 0x00600130 );
    zCOLOR GetLightColorStat()                                                                                    zCall( 0x006001B0 );
    zCOLOR GetLightColorStatGroundPoly()                                                                          zCall( 0x00600440 );
    zCOLOR GetLightColorDyn()                                                                                     zCall( 0x00600470 );
    int __fastcall CalcStaticLight( zVEC3& ) const                                                                zCall( 0x00600650 );
    zSTRING const* GetSectorNameVobIsIn() const                                                                   zCall( 0x00600AE0 );
    void __fastcall SetGroundShadowSize( zVEC2 const& )                                                           zCall( 0x00600C30 );
    zVEC2 __fastcall GetGroundShadowSize() const                                                                  zCall( 0x00600C80 );
    void __fastcall RenderGroundShadow( zTRenderContext& )                                                        zCall( 0x00600CD0 );
    zCVisual* GetClassHelperVisual() const                                                                        zCall( 0x006011E0 );
    void CalcRenderAlpha( float, zCVisual*&, float& )                                                             zCall( 0x006013E0 );
    zCOLOR GetLightColorAtCenter() const                                                                          zCall( 0x00601AC0 );
    void RemoveVobFromWorld()                                                                                     zCall( 0x00601C40 );
    void RemoveVobSubtreeFromWorld()                                                                              zCall( 0x00601C60 );
    void AddRefVobSubtree( zCTree<zCVob>*, int )                                                                  zCall( 0x00601CC0 );
    void ReleaseVobSubtree( zCTree<zCVob>* )                                                                      zCall( 0x00601D40 );
    void RemoveWorldDependencies( int )                                                                           zCall( 0x00601DA0 );
    void RemoveVobFromGlobalVobTree()                                                                             zCall( 0x00601FF0 );
    void RemoveVobFromBspTree()                                                                                   zCall( 0x006020E0 );
    zSTRING GetVobInfo()                                                                                          zCall( 0x00602100 );
    void SetSleeping( int )                                                                                       zCall( 0x00602930 );
    void UpdateVisualDependencies( int )                                                                          zCall( 0x00602B20 );
    void AddVobToWorld_CorrectParentDependencies()                                                                zCall( 0x00602BB0 );
    void ResetOnTimer()                                                                                           zCall( 0x00602BD0 );
    void SetOnTimer( float )                                                                                      zCall( 0x00602BE0 );
    int IsOnTimer() const                                                                                         zCall( 0x00602C10 );
    void ProcessOnTimer()                                                                                         zCall( 0x00602C30 );
    void DoFrameActivity()                                                                                        zCall( 0x00602C60 );
    void CheckModelLimbCollision( zCModelNodeInst*, int, zCList<zTModelLimbColl>& )                               zCall( 0x00602ED0 );
    void CheckModelLimbCollisionLevel( zCModelNodeInst*, int, zCList<zTModelLimbColl>& )                          zCall( 0x00603A80 );
    void CheckModelLimbCollisionPolys( zCModelNodeInst*, int, zCPolygon**, int const&, zCList<zTModelLimbColl>& ) zCall( 0x00604710 );
    zMAT4 GetTrafoModelNodeToWorld( zSTRING const& )                                                              zCall( 0x00604960 );
    zMAT4 GetTrafoModelNodeToWorld( zCModelNodeInst* )                                                            zCall( 0x00604A50 );
    zTBBox2D GetScreenBBox2D()                                                                                    zCall( 0x00604AE0 );
    void PackStateBinary( zCBuffer& ) const                                                                       zCall( 0x00605110 );
    void UnpackStateBinary( zCBuffer& )                                                                           zCall( 0x006051C0 );
    int GetIsProjectile() const                                                                                   zCall( 0x00606C00 );
    zCVisual* GetVisual() const                                                                                   zCall( 0x00616B20 );
    void CalcGroundPoly()                                                                                         zCall( 0x0061ACD0 );
    void CalcWaterVob()                                                                                           zCall( 0x0061AE20 );
    void SetCollTypeDefaultFromVisual()                                                                           zCall( 0x0061AEF0 );
    void TouchMovement()                                                                                          zCall( 0x0061B060 );
    zMAT4 const& GetNewTrafoObjToWorld() const                                                                    zCall( 0x0061B080 );
    zMAT4& GetNewTrafoObjToWorld()                                                                                zCall( 0x0061B0A0 );
    void SetNewTrafoObjToWorld( zMAT4 const& )                                                                    zCall( 0x0061B0C0 );
    void SetBBox3DWorld( zTBBox3D const& )                                                                        zCall( 0x0061B0E0 );
    void SetBBox3DLocal( zTBBox3D const& )                                                                        zCall( 0x0061B140 );
    zTBBox3D GetBBox3DLocal() const                                                                               zCall( 0x0061B1F0 );
    void Move( float, float, float )                                                                              zCall( 0x0061B2E0 );
    void MoveWorld( float, float, float )                                                                         zCall( 0x0061B350 );
    void MoveLocal( float, float, float )                                                                         zCall( 0x0061B3C0 );
    void SetRotationWorld( zCQuat const& )                                                                        zCall( 0x0061B4C0 );
    void RotateWorld( zVEC3 const&, float )                                                                       zCall( 0x0061B520 );
    void RotateLocal( zVEC3 const&, float )                                                                       zCall( 0x0061B610 );
    void RotateLocalX( float )                                                                                    zCall( 0x0061B6B0 );
    void RotateLocalY( float )                                                                                    zCall( 0x0061B720 );
    void RotateLocalZ( float )                                                                                    zCall( 0x0061B790 );
    void RotateWorldX( float )                                                                                    zCall( 0x0061B800 );
    void RotateWorldY( float )                                                                                    zCall( 0x0061B830 );
    void RotateWorldZ( float )                                                                                    zCall( 0x0061B860 );
    void GetPositionWorld( float&, float&, float& ) const                                                         zCall( 0x0061B890 );
    void GetPositionLocal( float&, float&, float& ) const                                                         zCall( 0x0061B8C0 );
    float GetDistanceToVob( zCVob& )                                                                              zCall( 0x0061B910 );
    float GetDistanceToVobApprox( zCVob& )                                                                        zCall( 0x0061B970 );
    float GetDistanceToVob2( zCVob& )                                                                             zCall( 0x0061BA40 );
    void SetPositionLocal( zVEC3 const& )                                                                         zCall( 0x0061BAA0 );
    void SetPositionWorld( zVEC3 const& )                                                                         zCall( 0x0061BB70 );
    void SetTrafo( zMAT4 const& )                                                                                 zCall( 0x0061BBD0 );
    void SetTrafoObjToWorld( zMAT4 const& )                                                                       zCall( 0x0061BC80 );
    void ResetRotationsLocal()                                                                                    zCall( 0x0061BCF0 );
    void ResetXZRotationsLocal()                                                                                  zCall( 0x0061BE20 );
    void ResetRotationsWorld()                                                                                    zCall( 0x0061C000 );
    void ResetXZRotationsWorld()                                                                                  zCall( 0x0061C090 );
    void SetHeadingYLocal( zVEC3 const& )                                                                         zCall( 0x0061C1B0 );
    void SetHeadingYWorld( zVEC3 const& )                                                                         zCall( 0x0061C280 );
    void SetHeadingYWorld( zCVob* )                                                                               zCall( 0x0061C450 );
    void SetHeadingLocal( zVEC3 const& )                                                                          zCall( 0x0061C5E0 );
    void SetHeadingWorld( zVEC3 const& )                                                                          zCall( 0x0061C6B0 );
    void SetHeadingWorld( zCVob* )                                                                                zCall( 0x0061C780 );
    void SetHeadingAtLocal( zVEC3 const& )                                                                        zCall( 0x0061C860 );
    int HasParentVob() const                                                                                      zCall( 0x0061CBA0 );
    void SetHeadingAtWorld( zVEC3 const& )                                                                        zCall( 0x0061CBC0 );
    void __fastcall SetCollDetStat( int )                                                                         zCall( 0x0061CE50 );
    void __fastcall SetCollDetDyn( int )                                                                          zCall( 0x0061CF40 );
    void CorrectTrafo()                                                                                           zCall( 0x0061D040 );
    void DoneWithTrafoLocal()                                                                                     zCall( 0x0061D0B0 );
    void CreateTrafoLocal() const                                                                                 zCall( 0x0061D100 );
    void SetPhysicsEnabled( int )                                                                                 zCall( 0x0061D190 );
    zVEC3 GetVelocity()                                                                                           zCall( 0x0061D1C0 );
    void UpdatePhysics()                                                                                          zCall( 0x0061D2D0 );
    int DetectCollision( zMAT4* )                                                                                 zCall( 0x0061D890 );
    void __fastcall SetInMovement( int )                                                                          zCall( 0x0061D9D0 );
    void __fastcall SetInMovementMode( zTMovementMode )                                                           zCall( 0x0061DA30 );
    void BeginMovement()                                                                                          zCall( 0x0061DA80 );
    void ResetToOldMovementState()                                                                                zCall( 0x0061DC00 );
    void __fastcall UpdateTouchList( zCArray<zCVob*> const& )                                                     zCall( 0x0061DC30 );
    void __fastcall CalcDestinationBBox3DWorld( zTBBox3D& )                                                       zCall( 0x0061DEE0 );
    void AdoptCollObjResults()                                                                                    zCall( 0x0061E020 );
    void SetCollisionObject( zCCollisionObject* )                                                                 zCall( 0x0061E5E0 );
    void SetCollisionClass( zCCollisionObjectDef* )                                                               zCall( 0x0061E610 );
    zCCollisionObject* GetCollisionObject() const                                                                 zCall( 0x0061E650 );
    void CreateCollisionObject()                                                                                  zCall( 0x0061E660 );
    void ResetCollisionObjectState()                                                                              zCall( 0x0061E690 );
    void __fastcall DestroyCollisionObject( int )                                                                 zCall( 0x0061E6D0 );
    void CheckEmergencyPutToSleep()                                                                               zCall( 0x0061E710 );
    void __fastcall CollectCollisionContext_Vobs( zTBBox3D const&, zTCollisionContext& )                          zCall( 0x0061E870 );
    void __fastcall CollectCollisionContext_Static( zTBBox3D const&, zCArray<zCCollisionObject*>& )               zCall( 0x0061EAD0 );
    void __fastcall CollectCollisionContext( zTCollisionContext& )                                                zCall( 0x0061EDC0 );
    void __fastcall CleanupCollisionContext( zTCollisionContext const& )                                          zCall( 0x0061EE40 );
    void __fastcall NotifyCollisionPair( zCCollisionReport*, zCArray<zCCollisionReport*> const&, int )            zCall( 0x0061EEB0 );
    void __fastcall ExecuteCollisionResponse( zCArray<zCCollisionReport*> const&, int& )                          zCall( 0x0061EF80 );
    void CheckAndResolveCollisions()                                                                              zCall( 0x0061F060 );
    int IsColliding()                                                                                             zCall( 0x0061F4F0 );
    zCWorld* GetHomeWorld() const                                                                                 zCall( 0x006742A0 );
    void SetStaticVob( int )                                                                                      zCall( 0x006CFFB0 );
    zTVobType GetVobType() const                                                                                  zCall( 0x006CFFD0 );
    void SetDrawBBox3D( int )                                                                                     zCall( 0x006CFFE0 );
    void SetCollDet( int )                                                                                        zCall( 0x006D0000 );
    static zCObject* _CreateNewInstance()                                                                         zCall( 0x005FD940 );
    static void InitVobSystem()                                                                                   zCall( 0x005FE6E0 );
    static void CleanupVobSystem()                                                                                zCall( 0x005FE800 );
    static void ResetIDCtr()                                                                                      zCall( 0x005FE8C0 );
    static unsigned long GetNextFreeVobID()                                                                       zCall( 0x005FE8D0 );
    static void LoadGroundShadowMesh()                                                                            zCall( 0x00600B00 );
    static void DeleteGroundShadowMesh()                                                                          zCall( 0x00600C00 );
    static void RepairIllegalFloats( zMAT4& )                                                                     zCall( 0x00604F10 );
    static zCVob* GetAutoLinkParent( zCVob* )                                                                     zCall( 0x0061A6C0 );
    static int CanAutoLinkWith( zCVob*, zCVob* )                                                                  zCall( 0x0061A700 );
    static void CheckAutoLink( zCVob*, zCVob* )                                                                   zCall( 0x0061A840 );
    static void CheckAutoUnlink( zCVob* )                                                                         zCall( 0x0061AAC0 );
    static void SetShowHelperVisuals( int )                                                                       zCall( 0x00637110 );
    static int GetShowHelperVisuals()                                                                             zCall( 0x00637120 );
    static int GetAnimationsEnabled()                                                                             zCall( 0x00637130 );
    static void SetAnimationsEnabled( int )                                                                       zCall( 0x00637140 );
    virtual zCClassDef* _GetClassDef() const                                                                      zCall( 0x0043CCB0 );
    virtual void Archive( zCArchiver& )                                                                           zCall( 0x005FF140 );
    virtual void Unarchive( zCArchiver& )                                                                         zCall( 0x005FFC70 );
    virtual ~zCVob()                                                                                              zCall( 0x005FE470 );
    virtual void OnTrigger( zCVob*, zCVob* )                                                                      zCall( 0x005FE170 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                                                    zCall( 0x005FE180 );
    virtual void OnTouch( zCVob* )                                                                                zCall( 0x005FE190 );
    virtual void OnUntouch( zCVob* )                                                                              zCall( 0x005FE1A0 );
    virtual void OnTouchLevel()                                                                                   zCall( 0x005FE1B0 );
    virtual void OnDamage( zCVob*, zCVob*, float, int, zVEC3 const& )                                             zCall( 0x005FE1C0 );
    virtual void OnMessage( zCEventMessage*, zCVob* )                                                             zCall( 0x005FE1D0 );
    virtual void OnTick()                                                                                         zCall( 0x00404270 );
    virtual void OnTimer()                                                                                        zCall( 0x0043CCC0 );
    virtual void PostLoad()                                                                                       zCall( 0x00404280 );
    virtual zTVobCharClass GetCharacterClass()                                                                    zCall( 0x00404290 );
    virtual void SetSleepingMode( zTVobSleepingMode )                                                             zCall( 0x00602960 );
    virtual void EndMovement( int )                                                                               zCall( 0x0061E0D0 );
    virtual int CanThisCollideWith( zCVob* )                                                                      zCall( 0x004042A0 );
    virtual int __fastcall Render( zTRenderContext& )                                                             zCall( 0x006015D0 );
    virtual void SetVisual( zCVisual* )                                                                           zCall( 0x006024F0 );
    virtual void SetVisual( zSTRING const& )                                                                      zCall( 0x00602680 );
    virtual int GetScriptInstance( zSTRING*&, int& )                                                              zCall( 0x004042B0 );
    virtual int SetByScriptInstance( zSTRING const*, int )                                                        zCall( 0x004042D0 );
    virtual int GetCSStateFlags()                                                                                 zCall( 0x004042E0 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& )                                    zCall( 0x005FFE40 );
    virtual zSTRING const* GetTriggerTarget( int ) const                                                          zCall( 0x0043CCD0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                                                  zCall( 0x00601C80 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                                              zCall( 0x00601CA0 );

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

    void zCVobLightData_OnInit()               zCall( 0x0060A970 );
    int SetLensFlareFXByName( zSTRING const& ) zCall( 0x00609970 );
    zSTRING const& GetLensFlareFXName() const  zCall( 0x00609A70 );
    void Archive( zCArchiver& )                zCall( 0x00609A90 );
    void Unarchive( zCArchiver& )              zCall( 0x00609FA0 );
    zCVobLightData()                           zInit( zCVobLightData_OnInit() );
    ~zCVobLightData()                          zCall( 0x0060A9F0 );
    void SetRange( float, int )                zCall( 0x0060AA60 );

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
    static zCObject* _CreateNewInstance()    zCall( 0x005FD520 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x005FD690 );
    virtual void Archive( zCArchiver& )      zCall( 0x00609790 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x006097C0 );
    virtual ~zCVobLightPreset()              zCall( 0x005FD6D0 );

    // user API
    #include "zCVobLightPreset.inl"
  };

  // sizeof 188h
  class zCVobLight : public zCVob {
  public:
    zCLASS_DECLARATION( zCVobLight )

    zCVobLightData lightData;                         // sizeof 48h    offset 120h
    zTRayTurboValMap<zCPolygon*, int>affectedPolyMap; // sizeof 0Ch    offset 168h
    zSTRING lightPresetInUse;                         // sizeof 14h    offset 174h

    void zCVobLight_OnInit()                                                              zCall( 0x00607D10 );
    zCVobLight()                                                                          zInit( zCVobLight_OnInit() );
    void DoAnimation()                                                                    zCall( 0x006081C0 );
    void SetRange( float, int )                                                           zCall( 0x00608320 );
    void AddThisToPresetList( zSTRING const& ) const                                      zCall( 0x00608910 );
    int SetByPreset( zSTRING const& )                                                     zCall( 0x00608BE0 );
    int SetByPresetInUse()                                                                zCall( 0x00608E60 );
    static zCObject* _CreateNewInstance()                                                 zCall( 0x00607C60 );
    static void CleanupVobLight()                                                         zCall( 0x00607FE0 );
    static zCOLOR SumLightsAtPositionWS( zCArray<zCVobLight*> const&, zVEC3 const&, int ) zCall( 0x00608410 );
    static void LoadLightPresets()                                                        zCall( 0x00608690 );
    static void SaveLightPresets()                                                        zCall( 0x006087E0 );
    virtual zCClassDef* _GetClassDef() const                                              zCall( 0x00607E00 );
    virtual void Archive( zCArchiver& )                                                   zCall( 0x006090B0 );
    virtual void Unarchive( zCArchiver& )                                                 zCall( 0x00609100 );
    virtual ~zCVobLight()                                                                 zCall( 0x00607E40 );
    virtual void OnTrigger( zCVob*, zCVob* )                                              zCall( 0x00608050 );
    virtual void OnUntrigger( zCVob*, zCVob* )                                            zCall( 0x00608120 );
    virtual void EndMovement( int )                                                       zCall( 0x006092B0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                          zCall( 0x00609530 );

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

    void zCVobLevelCompo_OnInit()            zCall( 0x00605280 );
    zCVobLevelCompo()                        zInit( zCVobLevelCompo_OnInit() );
    int HasIdentityTrafo() const             zCall( 0x006052E0 );
    static zCObject* _CreateNewInstance()    zCall( 0x005FDB90 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x005FDC30 );
    virtual void Archive( zCArchiver& )      zCall( 0x00605360 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00605410 );
    virtual ~zCVobLevelCompo()               zCall( 0x005FDC70 );
    virtual void SetVisual( zCVisual* )      zCall( 0x006054E0 );
    virtual void SetVisual( zSTRING const& ) zCall( 0x00605520 );

    // static properties
    static int& unarcIgnoreVisuals;

    // user API
    #include "zCVobLevelCompo.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVOB_H__VER3__