// Supported with union (c) 2018-2021 Union team

#ifndef __OVIS_FX_H__VER3__
#define __OVIS_FX_H__VER3__

#include "z3d.h"
#include "zAi.h"
#include "zParticle.h"
#include "zParser.h"
#include "zKbSplines.h"
#include "zSound.h"
#include "zVobMisc.h"

namespace Gothic_II_Addon {
  const int MAX_SPL_LEVEL          = 20;
  const int VFX_MAX_POS_SAMPLES    = 10;
  const int VFX_NUM_USERSTRINGS    = 5;
  const float VFX_LIFESPAN_FOREVER = -1;

  enum zTVFXState {
    zVFXSTATE_UNDEF,
    zVFXSTATE_OPEN,
    zVFXSTATE_INIT,
    zVFXSTATE_INVESTNEXT,
    zVFXSTATE_CAST,
    zVFXSTATE_STOP,
    zVFXSTATE_COLLIDE
  };

  enum TEmTrajectoryMode {
    EM_TRJ_UNDEF,
    EM_TRJ_FIXED,
    EM_TRJ_TARGET,
    EM_TRJ_LINE    = 4,
    EM_TRJ_SPLINE  = 8,
    EM_TRJ_RANDOM  = 16,
    EM_TRJ_CIRCLE  = 32,
    EM_TRJ_FOLLOW  = 64,
    EM_TRJ_MISSILE = 128
  };

  enum TTrjLoopMode {
    TRJ_LOOP_NONE,
    TRJ_LOOP_RESTART,
    TRJ_LOOP_PINGPONG,
    TRJ_LOOP_HALT,
    TRJ_LOOP_PINGPONG_ONCE
  };

  enum TEaseFunc {
    TEASEFUNC_LINEAR,
    TEASEFUNC_SINE,
    TEASEFUNC_EXP
  };

  enum TActionColl {
    TACTION_COLL_NONE,
    TACTION_COLL_COLLIDE,
    TACTION_COLL_BOUNCE,
    TACTION_COLL_CREATE      = 4,
    TACTION_COLL_CREATE_ONCE = 8,
    TACTION_COLL_NORESP      = 16,
    TACTION_COLL_CREATE_QUAD = 32
  };

  // sizeof 5Ch
  class oCTrajectory {
  public:
    zCArray<zCPositionKey*> keyList; // sizeof 0Ch    offset 00h
    zCKBSpline* spl;                 // sizeof 04h    offset 0Ch
    int mode;                        // sizeof 04h    offset 10h
    float length;                    // sizeof 04h    offset 14h
    zMAT4 res;                       // sizeof 40h    offset 18h
    int lastKey;                     // sizeof 04h    offset 58h

    oCTrajectory() {}
    void Calc()                                                         zCall( 0x00487960 );
    void Changed()                                                      zCall( 0x00487CF0 );
    zMAT4 Interpolate( float )                                          zCall( 0x00487D00 );
    zMAT4 InterpolateN( float )                                         zCall( 0x00488130 );
    void Draw()                                                         zCall( 0x00488240 );
    void Clear()                                                        zCall( 0x00488500 );
    zVEC3 RecalcByColl( zVEC3 const&, zVEC3 const&, zVEC3 const&, int ) zCall( 0x004885D0 );
    void ApplyGrav( float const& )                                      zCall( 0x00488A40 );
    void SetByList( zCArray<zCVob*> )                                   zCall( 0x00488AB0 );
    int VobCross( zCVob const* )                                        zCall( 0x00488C20 );
    ~oCTrajectory()                                                     zCall( 0x00489F50 );
    void InsertKey( zMAT4& )                                            zCall( 0x00490F50 );
    zMAT4 GetKey( int )                                                 zCall( 0x00491060 );
    int GetNumKeys()                                                    zCall( 0x004910E0 );

    // user API
    #include "oCTrajectory.inl"
  };

  // sizeof 1D4h
  class oCEmitterKey {
  public:
    zSTRING visName_S;                     // sizeof 14h    offset 00h
    float visSizeScale;                    // sizeof 04h    offset 14h
    float scaleDuration;                   // sizeof 04h    offset 18h
    float pfx_ppsValue;                    // sizeof 04h    offset 1Ch
    int pfx_ppsIsSmoothChg;                // sizeof 04h    offset 20h
    int pfx_ppsIsLoopingChg;               // sizeof 04h    offset 24h
    float pfx_scTime;                      // sizeof 04h    offset 28h
    zSTRING pfx_flyGravity_S;              // sizeof 14h    offset 2Ch
    zSTRING pfx_shpDim_S;                  // sizeof 14h    offset 40h
    int pfx_shpIsVolumeChg;                // sizeof 04h    offset 54h
    float pfx_shpScaleFPS;                 // sizeof 04h    offset 58h
    float pfx_shpDistribWalkSpeed;         // sizeof 04h    offset 5Ch
    zSTRING pfx_shpOffsetVec_S;            // sizeof 14h    offset 60h
    zSTRING pfx_shpDistribType_S;          // sizeof 14h    offset 74h
    zSTRING pfx_dirMode_S;                 // sizeof 14h    offset 88h
    zSTRING pfx_dirFOR_S;                  // sizeof 14h    offset 9Ch
    zSTRING pfx_dirModeTargetFOR_S;        // sizeof 14h    offset B0h
    zSTRING pfx_dirModeTargetPos_S;        // sizeof 14h    offset C4h
    float pfx_velAvg;                      // sizeof 04h    offset D8h
    float pfx_lspPartAvg;                  // sizeof 04h    offset DCh
    float pfx_visAlphaStart;               // sizeof 04h    offset E0h
    zSTRING lightPresetName;               // sizeof 14h    offset E4h
    float lightRange;                      // sizeof 04h    offset F8h
    zSTRING sfxID;                         // sizeof 14h    offset FCh
    int sfxIsAmbient;                      // sizeof 04h    offset 110h
    zSTRING emCreateFXID;                  // sizeof 14h    offset 114h
    float emFlyGravity;                    // sizeof 04h    offset 128h
    zSTRING emSelfRotVel_S;                // sizeof 14h    offset 12Ch
    zSTRING emTrjMode_S;                   // sizeof 14h    offset 140h
    float emTrjEaseVel;                    // sizeof 04h    offset 154h
    int emCheckCollision;                  // sizeof 04h    offset 158h
    float emFXLifeSpan;                    // sizeof 04h    offset 15Ch
    unsigned char dScriptEnd;              // sizeof 01h    offset 160h
    zVEC3 pfx_flyGravity;                  // sizeof 0Ch    offset 164h
    zVEC3 pfx_shpOffsetVec;                // sizeof 0Ch    offset 170h
    zTPFX_DistribType pfx_shpDistribType;  // sizeof 04h    offset 17Ch
    zTPFX_EmitterDirMode pfx_dirMode;      // sizeof 04h    offset 180h
    zTPFX_EmitterFOR pfx_dirFOR;           // sizeof 04h    offset 184h
    zTPFX_EmitterFOR pfx_dirModeTargetFOR; // sizeof 04h    offset 188h
    zVEC3 pfx_dirModeTargetPos;            // sizeof 0Ch    offset 18Ch
    zVEC3 emSelfRotVel;                    // sizeof 0Ch    offset 198h
    int emTrjMode;                         // sizeof 04h    offset 1A4h
    zSTRING name;                          // sizeof 14h    offset 1A8h
    zCVob* vob;                            // sizeof 04h    offset 1BCh
    zVEC3 targetPos;                       // sizeof 0Ch    offset 1C0h
    zCSoundFX* sfx;                        // sizeof 04h    offset 1CCh
    int sfxHnd;                            // sizeof 04h    offset 1D0h

    void oCEmitterKey_OnInit()                       zCall( 0x00488CB0 );
    oCEmitterKey()                                   zInit( oCEmitterKey_OnInit() );
    ~oCEmitterKey()                                  zCall( 0x00488FA0 );
    void SetByScript( zSTRING const& )               zCall( 0x004891A0 );
    void ParseStrings()                              zCall( 0x00489370 );
    void Edit()                                      zCall( 0x0049AFF0 );
    void SetDefaultByFX( oCVisualFX* )               zCall( 0x0049E430 );
    static void CreateNewScriptKey( zSTRING const& ) zCall( 0x0049B3E0 );

    // user API
    #include "oCEmitterKey.inl"
  };

  // sizeof 1Ch
  struct zSVisualFXColl {
    zCVob* foundVob;         // sizeof 04h    offset 00h
    zVEC3 foundContactPoint; // sizeof 0Ch    offset 04h
    zVEC3 foundNormal;       // sizeof 0Ch    offset 10h

    zSVisualFXColl() {}

    // user API
    #include "zSVisualFXColl.inl"
  };

  // sizeof 610h
  class oCVisualFX : public zCEffect {
  public:
    zCLASS_DECLARATION( oCVisualFX )

    zSTRING visName_S;                       // sizeof 14h    offset 120h
    zSTRING visSize_S;                       // sizeof 14h    offset 134h
    float visAlpha;                          // sizeof 04h    offset 148h
    zSTRING visAlphaBlendFunc_S;             // sizeof 14h    offset 14Ch
    float visTexAniFPS;                      // sizeof 04h    offset 160h
    int visTexAniIsLooping;                  // sizeof 04h    offset 164h
    zSTRING emTrjMode_S;                     // sizeof 14h    offset 168h
    zSTRING emTrjOriginNode_S;               // sizeof 14h    offset 17Ch
    zSTRING emTrjTargetNode_S;               // sizeof 14h    offset 190h
    float emTrjTargetRange;                  // sizeof 04h    offset 1A4h
    float emTrjTargetAzi;                    // sizeof 04h    offset 1A8h
    float emTrjTargetElev;                   // sizeof 04h    offset 1ACh
    int emTrjNumKeys;                        // sizeof 04h    offset 1B0h
    int emTrjNumKeysVar;                     // sizeof 04h    offset 1B4h
    float emTrjAngleElevVar;                 // sizeof 04h    offset 1B8h
    float emTrjAngleHeadVar;                 // sizeof 04h    offset 1BCh
    float emTrjKeyDistVar;                   // sizeof 04h    offset 1C0h
    zSTRING emTrjLoopMode_S;                 // sizeof 14h    offset 1C4h
    zSTRING emTrjEaseFunc_S;                 // sizeof 14h    offset 1D8h
    float emTrjEaseVel;                      // sizeof 04h    offset 1ECh
    float emTrjDynUpdateDelay;               // sizeof 04h    offset 1F0h
    int emTrjDynUpdateTargetOnly;            // sizeof 04h    offset 1F4h
    zSTRING emFXCreate_S;                    // sizeof 14h    offset 1F8h
    zSTRING emFXInvestOrigin_S;              // sizeof 14h    offset 20Ch
    zSTRING emFXInvestTarget_S;              // sizeof 14h    offset 220h
    float emFXTriggerDelay;                  // sizeof 04h    offset 234h
    int emFXCreatedOwnTrj;                   // sizeof 04h    offset 238h
    zSTRING emActionCollDyn_S;               // sizeof 14h    offset 23Ch
    zSTRING emActionCollStat_S;              // sizeof 14h    offset 250h
    zSTRING emFXCollStat_S;                  // sizeof 14h    offset 264h
    zSTRING emFXCollDyn_S;                   // sizeof 14h    offset 278h
    zSTRING emFXCollDynPerc_S;               // sizeof 14h    offset 28Ch
    zSTRING emFXCollStatAlign_S;             // sizeof 14h    offset 2A0h
    zSTRING emFXCollDynAlign_S;              // sizeof 14h    offset 2B4h
    float emFXLifeSpan;                      // sizeof 04h    offset 2C8h
    int emCheckCollision;                    // sizeof 04h    offset 2CCh
    int emAdjustShpToOrigin;                 // sizeof 04h    offset 2D0h
    float emInvestNextKeyDuration;           // sizeof 04h    offset 2D4h
    float emFlyGravity;                      // sizeof 04h    offset 2D8h
    zSTRING emSelfRotVel_S;                  // sizeof 14h    offset 2DCh
    zSTRING userString[VFX_NUM_USERSTRINGS]; // sizeof 64h    offset 2F0h
    zSTRING lightPresetName;                 // sizeof 14h    offset 354h
    zSTRING sfxID;                           // sizeof 14h    offset 368h
    int sfxIsAmbient;                        // sizeof 04h    offset 37Ch
    int sendAssessMagic;                     // sizeof 04h    offset 380h
    float secsPerDamage;                     // sizeof 04h    offset 384h
    unsigned char dScriptEnd;                // sizeof 01h    offset 388h
    zVEC3 visSize;                           // sizeof 0Ch    offset 38Ch
    int emTrjMode;                           // sizeof 04h    offset 398h
    int emActionCollDyn;                     // sizeof 04h    offset 39Ch
    int emActionCollStat;                    // sizeof 04h    offset 3A0h
    zVEC3 emSelfRotVel;                      // sizeof 0Ch    offset 3A4h
    TEaseFunc emTrjEaseFunc;                 // sizeof 04h    offset 3B0h
    TTrjLoopMode emTrjLoopMode;              // sizeof 04h    offset 3B4h
    zTVFXState fxState;                      // sizeof 04h    offset 3B8h
    oCVisualFX* root;                        // sizeof 04h    offset 3BCh
    oCVisualFX* parent;                      // sizeof 04h    offset 3C0h
    oCVisualFX* fxInvestOrigin;              // sizeof 04h    offset 3C4h
    oCVisualFX* fxInvestTarget;              // sizeof 04h    offset 3C8h
    oCVisualFXAI* ai;                        // sizeof 04h    offset 3CCh
    zCArray<oCVisualFX*> fxList;             // sizeof 0Ch    offset 3D0h
    zCArray<oCVisualFX*> childList;          // sizeof 0Ch    offset 3DCh
    zCArray<oCEmitterKey*> emKeyList;        // sizeof 0Ch    offset 3E8h
    zCArray<zCVob*> vobList;                 // sizeof 0Ch    offset 3F4h
    zCArray<zCVob*> ignoreVobList;           // sizeof 0Ch    offset 400h
    zCArray<zCVob*> allowedCollisionVobList; // sizeof 0Ch    offset 40Ch
    zCArray<zCVob*> collidedVobs;            // sizeof 0Ch    offset 418h
    zCArray<zSVisualFXColl>queuedCollisions; // sizeof 0Ch    offset 424h
    oCTrajectory trajectory;                 // sizeof 5Ch    offset 430h
    zCEarthquake* earthQuake;                // sizeof 04h    offset 48Ch
    zCVobScreenFX* screenFX;                 // sizeof 04h    offset 490h
    float screenFXTime;                      // sizeof 04h    offset 494h
    int screenFXDir;                         // sizeof 04h    offset 498h
    zCModelNodeInst* orgNode;                // sizeof 04h    offset 49Ch
    zCModelNodeInst* targetNode;             // sizeof 04h    offset 4A0h
    zCVisual* lastSetVisual;                 // sizeof 04h    offset 4A4h
    zCVob* origin;                           // sizeof 04h    offset 4A8h
    zCVob* inflictor;                        // sizeof 04h    offset 4ACh
    zCVob* target;                           // sizeof 04h    offset 4B0h
    zCVobLight* light;                       // sizeof 04h    offset 4B4h
    float lightRange;                        // sizeof 04h    offset 4B8h
    zCSoundFX* sfx;                          // sizeof 04h    offset 4BCh
    int sfxHnd;                              // sizeof 04h    offset 4C0h
    zSTRING fxName;                          // sizeof 14h    offset 4C4h
    oCEmitterKey* fxBackup;                  // sizeof 04h    offset 4D8h
    oCEmitterKey* lastSetKey;                // sizeof 04h    offset 4DCh
    oCEmitterKey* actKey;                    // sizeof 04h    offset 4E0h
    float frameTime;                         // sizeof 04h    offset 4E4h
    float collisionTime;                     // sizeof 04h    offset 4E8h
    float deleteTime;                        // sizeof 04h    offset 4ECh
    float damageTime;                        // sizeof 04h    offset 4F0h
    zVEC3 targetPos;                         // sizeof 0Ch    offset 4F4h
    zVEC3 lastTrjDir;                        // sizeof 0Ch    offset 500h
    zVEC3 keySize;                           // sizeof 0Ch    offset 50Ch
    zVEC3 actSize;                           // sizeof 0Ch    offset 518h
    zVEC3 castEndSize;                       // sizeof 0Ch    offset 524h
    float nextLevelTime;                     // sizeof 04h    offset 530h
    float easeTime;                          // sizeof 04h    offset 534h
    float age;                               // sizeof 04h    offset 538h
    float trjUpdateTime;                     // sizeof 04h    offset 53Ch
    float emTrjDist;                         // sizeof 04h    offset 540h
    float trjSign;                           // sizeof 04h    offset 544h
    float levelTime;                         // sizeof 04h    offset 548h
    float lifeSpanTimer;                     // sizeof 04h    offset 54Ch
    float fxStartTime;                       // sizeof 04h    offset 550h
    float oldFovX;                           // sizeof 04h    offset 554h
    float oldFovY;                           // sizeof 04h    offset 558h
    int collisionOccured          : 1;       // sizeof 01h    offset bit
    int showVisual                : 1;       // sizeof 01h    offset bit
    int isChild                   : 1;       // sizeof 01h    offset bit
    int isDeleted                 : 1;       // sizeof 01h    offset bit
    int initialized               : 1;       // sizeof 01h    offset bit
    int shouldDelete              : 1;       // sizeof 01h    offset bit
    int lightning                 : 1;       // sizeof 01h    offset bit
    int fxInvestOriginInitialized : 1;       // sizeof 01h    offset bit
    int fxInvestTargetInitialized : 1;       // sizeof 01h    offset bit
    int fxInvestStopped           : 1;       // sizeof 01h    offset bit
    int timeScaled                : 1;       // sizeof 01h    offset bit
    int fovMorph                  : 2;       // sizeof 02h    offset bit
    int level                     : 5;       // sizeof 05h    offset bit
    int collisionCtr              : 3;       // sizeof 03h    offset bit
    int queueSetLevel             : 5;       // sizeof 05h    offset bit
    float damage;                            // sizeof 04h    offset 560h
    int damageType;                          // sizeof 04h    offset 564h
    int spellType;                           // sizeof 04h    offset 568h
    int spellCat;                            // sizeof 04h    offset 56Ch
    int spellTargetTypes;                    // sizeof 04h    offset 570h
    float savePpsValue;                      // sizeof 04h    offset 574h
    zVEC2 saveVisSizeStart;                  // sizeof 08h    offset 578h
    zVEC3 transRing[VFX_MAX_POS_SAMPLES];    // sizeof 78h    offset 580h
    int ringPos;                             // sizeof 04h    offset 5F8h
    int emTrjFollowHitLastCheck;             // sizeof 04h    offset 5FCh
    int bIsProjectile;                       // sizeof 04h    offset 600h
    int bPfxMeshSetByVisualFX;               // sizeof 04h    offset 604h
    int m_bAllowMovement;                    // sizeof 04h    offset 608h
    float m_fSleepTimer;                     // sizeof 04h    offset 60Ch

    void oCVisualFX_OnInit()                                                                             zCall( 0x00489AA0 );
    oCVisualFX()                                                                                         zInit( oCVisualFX_OnInit() );
    void CleanUpCriticalFX()                                                                             zCall( 0x0048AC00 );
    void CreateHierachy()                                                                                zCall( 0x0048ADF0 );
    void DisposeHierachy()                                                                               zCall( 0x0048B0B0 );
    void InitValues()                                                                                    zCall( 0x0048B820 );
    void ParseStrings()                                                                                  zCall( 0x0048BE60 );
    void UpdateFXByEmitterKey( oCEmitterKey* )                                                           zCall( 0x0048DDC0 );
    void CreateBackup()                                                                                  zCall( 0x0048E5F0 );
    int FindKey( zSTRING const& )                                                                        zCall( 0x0048E600 );
    oCVisualFX* CreateAndCastFX( zSTRING const&, zCVob const*, zCVob const* )                            zCall( 0x0048EE80 );
    oCVisualFX* CreateAndCastFX( zSTRING const&, zMAT4 const& )                                          zCall( 0x0048F1E0 );
    void CreateInvestFX()                                                                                zCall( 0x00491510 );
    void InitInvestFX()                                                                                  zCall( 0x00491690 );
    void StopInvestFX()                                                                                  zCall( 0x00491830 );
    void InitEffect()                                                                                    zCall( 0x004943E0 );
    void EndEffect( int )                                                                                zCall( 0x00494C80 );
    void SetShowVisual( int )                                                                            zCall( 0x00494D20 );
    int ProcessQueuedCollisions()                                                                        zCall( 0x00495830 );
    int ProcessCollision( zSVisualFXColl& )                                                              zCall( 0x004958D0 );
    int CheckDeletion()                                                                                  zCall( 0x00496CF0 );
    void UpdateActKey()                                                                                  zCall( 0x00497300 );
    void DoMovements()                                                                                   zCall( 0x00497550 );
    int CheckDelayedTrigger()                                                                            zCall( 0x00498B70 );
    void AdjustShapeToOrigin()                                                                           zCall( 0x00498EE0 );
    void UpdateEffects()                                                                                 zCall( 0x004994A0 );
    void CalcPFXMesh()                                                                                   zCall( 0x00499B60 );
    void ReleasePFXMesh()                                                                                zCall( 0x00499D10 );
    void SetPFXShapeVisual( zCVisual*, int )                                                             zCall( 0x00499DF0 );
    void Edit()                                                                                          zCall( 0x0049A820 );
    void SetupEmitterKeysByVisual()                                                                      zCall( 0x0049E8B0 );
    zSTRING const& GetName() const                                                                       zCall( 0x006742F0 );
    static void SetupAIForAllFXInWorld()                                                                 zCall( 0x004898B0 );
    static void RemoveInstancesOfClass( zCClassDef&, int )                                               zCall( 0x00489A10 );
    static void PreSaveGameProcessing( int )                                                             zCall( 0x00489A80 );
    static void PostSaveGameProcessing()                                                                 zCall( 0x00489A90 );
    static void InitParser()                                                                             zCall( 0x0048B3F0 );
    static void ExitParser()                                                                             zCall( 0x0048B7F0 );
    static oCVisualFX* CreateAndPlay( zSTRING const&, zCVob const*, zCVob const*, int, float, int, int ) zCall( 0x0048E760 );
    static oCVisualFX* CreateAndPlay( zSTRING const&, zVEC3 const&, zCVob const*, int, float, int, int ) zCall( 0x0048EA80 );
    static zCObject* _CreateNewInstance()                                                                zCall( 0x0049A230 );
    static void CreateNewScriptFX( zSTRING const& )                                                      zCall( 0x0049ADB0 );
    static void FxConsole_ParameterChanged( zSTRING const& )                                             zCall( 0x0049B620 );
    static void EmConsole_ParameterChanged( zSTRING const& )                                             zCall( 0x0049C290 );
    static int FxConsole_EvalFunc( zSTRING const&, zSTRING& )                                            zCall( 0x0049C4D0 );
    static int EmConsole_EvalFunc( zSTRING const&, zSTRING& )                                            zCall( 0x0049D180 );
    virtual zCClassDef* _GetClassDef() const                                                             zCall( 0x0048A010 );
    virtual void Archive( zCArchiver& )                                                                  zCall( 0x00499B40 );
    virtual void Unarchive( zCArchiver& )                                                                zCall( 0x00499B50 );
    virtual ~oCVisualFX()                                                                                zCall( 0x0048A260 );
    virtual void OnTick()                                                                                zCall( 0x00499A20 );
    virtual int CanThisCollideWith( zCVob* )                                                             zCall( 0x00496AC0 );
    virtual void Open()                                                                                  zCall( 0x004918E0 );
    virtual void SetOrigin( zCVob*, int )                                                                zCall( 0x004910F0 );
    virtual void SetTarget( zCVob*, int )                                                                zCall( 0x004912E0 );
    virtual void SetTarget( zVEC3&, int )                                                                zCall( 0x00491450 );
    virtual void SetInflictor( zCVob* )                                                                  zCall( 0x00491220 );
    virtual zCVob* GetOrigin()                                                                           zCall( 0x0048A020 );
    virtual zCVob* GetTarget()                                                                           zCall( 0x0048A030 );
    virtual zCVob* GetInflictor()                                                                        zCall( 0x0048A040 );
    virtual void Init( zCVob const*, zVEC3 const& )                                                      zCall( 0x00491E10 );
    virtual void Init( zCVob const*, zCVob const*, zCVob const* )                                        zCall( 0x00491F20 );
    virtual void Init( zCArray<zCVob*> const& )                                                          zCall( 0x004926A0 );
    virtual void InvestNext()                                                                            zCall( 0x00492830 );
    virtual void SetLevel( int, int )                                                                    zCall( 0x00492CB0 );
    virtual int GetLevel() const                                                                         zCall( 0x00493150 );
    virtual void Cast( int )                                                                             zCall( 0x00493160 );
    virtual void Stop( int )                                                                             zCall( 0x00493BE0 );
    virtual void Kill()                                                                                  zCall( 0x00493F70 );
    virtual void Play( float, zMAT4 const*, zMAT4 const* )                                               zCall( 0x0048A050 );
    virtual int CanBeDeleted()                                                                           zCall( 0x004942B0 );
    virtual int IsFinished()                                                                             zCall( 0x004942F0 );
    virtual int IsLooping()                                                                              zCall( 0x00494370 );
    virtual void SetByScript( zSTRING const& )                                                           zCall( 0x0048D4B0 );
    virtual void SetDuration( float )                                                                    zCall( 0x0048A060 );
    virtual void Reset()                                                                                 zCall( 0x00491C20 );
    virtual void ResetForEditing()                                                                       zCall( 0x0049E950 );
    virtual void ReportCollision( zCCollisionReport const& )                                             zCall( 0x00494E80 );
    virtual void SetCollisionEnabled( int )                                                              zCall( 0x0048D330 );
    virtual void SetCollisionCandidates( zCArray<zCVob*> )                                               zCall( 0x004968E0 );
    virtual void GetCollisionCandidates( zCArray<zCVob*>& )                                              zCall( 0x0048A070 );
    virtual int GetNumCollisionCandidates()                                                              zCall( 0x0048A110 );
    virtual int GetCollidedCandidates( zCArray<zCVob*>& )                                                zCall( 0x00496A00 );
    virtual void SetDamage( float )                                                                      zCall( 0x0048A120 );
    virtual void SetDamageType( int )                                                                    zCall( 0x0048A130 );
    virtual float GetDamage() const                                                                      zCall( 0x0048A140 );
    virtual int GetDamageType() const                                                                    zCall( 0x0048A150 );
    virtual int IsASpell()                                                                               zCall( 0x0048A160 );
    virtual void SetSpellType( int )                                                                     zCall( 0x0048A170 );
    virtual int GetSpellType() const                                                                     zCall( 0x0048A180 );
    virtual void SetSpellCat( int )                                                                      zCall( 0x0048A190 );
    virtual int GetSpellCat() const                                                                      zCall( 0x0048A1A0 );
    virtual int GetSpellTargetTypes() const                                                              zCall( 0x0048A1B0 );
    virtual void SetSpellTargetTypes( int )                                                              zCall( 0x0048A1C0 );
    virtual int GetSendsAssessMagic()                                                                    zCall( 0x0048B350 );
    virtual void SetSendsAssessMagic( int )                                                              zCall( 0x0048B2C0 );
    virtual int GetIsProjectile()                                                                        zCall( 0x0048A1D0 );
    virtual void SetIsProjectile( int )                                                                  zCall( 0x0048A1E0 );
    virtual void SetVisualByString( zSTRING const& )                                                     zCall( 0x0048C220 );
    virtual void CalcTrajectory( int const& )                                                            zCall( 0x0048F620 );
    virtual void Collide( int )                                                                          zCall( 0x00493A00 );
    virtual void CollisionResponse( zVEC3 const&, int )                                                  zCall( 0x00496380 );

    // static properties
    static zCParser*& fxParser;
    static oCVisualFX*& actFX;

    // user API
    #include "oCVisualFX.inl"
  };

  // sizeof 2Ch
  class oCVisualFXAI : public zCAIBase {
  public:
    zCVob* vob;    // sizeof 04h    offset 24h
    int delete_it; // sizeof 04h    offset 28h

    oCVisualFXAI() {}
    virtual ~oCVisualFXAI()                                      zCall( 0x0048BDE0 );
    virtual void DoAI( zCVob*, int& )                            zCall( 0x0049A030 );
    virtual void ReportCollisionToAI( zCCollisionReport const& ) zCall( 0x0048BD70 );
    virtual void HostVobAddedToWorld( zCVob*, zCWorld* )         zCall( 0x0048BD90 );
    virtual int GetIsProjectile()                                zCall( 0x0048BDA0 );

    // user API
    #include "oCVisualFXAI.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OVIS_FX_H__VER3__