// Supported with union (c) 2018 Union team

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

  class oCTrajectory {
  public:
    zCArray<zCPositionKey*> keyList;
    zCKBSpline* spl;
    int mode;
    float length;
    zMAT4 res;
    int lastKey;

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

  class oCEmitterKey {
  public:
    zSTRING visName_S;
    float visSizeScale;
    float scaleDuration;
    float pfx_ppsValue;
    int pfx_ppsIsSmoothChg;
    int pfx_ppsIsLoopingChg;
    float pfx_scTime;
    zSTRING pfx_flyGravity_S;
    zSTRING pfx_shpDim_S;
    int pfx_shpIsVolumeChg;
    float pfx_shpScaleFPS;
    float pfx_shpDistribWalkSpeed;
    zSTRING pfx_shpOffsetVec_S;
    zSTRING pfx_shpDistribType_S;
    zSTRING pfx_dirMode_S;
    zSTRING pfx_dirFOR_S;
    zSTRING pfx_dirModeTargetFOR_S;
    zSTRING pfx_dirModeTargetPos_S;
    float pfx_velAvg;
    float pfx_lspPartAvg;
    float pfx_visAlphaStart;
    zSTRING lightPresetName;
    float lightRange;
    zSTRING sfxID;
    int sfxIsAmbient;
    zSTRING emCreateFXID;
    float emFlyGravity;
    zSTRING emSelfRotVel_S;
    zSTRING emTrjMode_S;
    float emTrjEaseVel;
    int emCheckCollision;
    float emFXLifeSpan;
    unsigned char dScriptEnd;
    zVEC3 pfx_flyGravity;
    zVEC3 pfx_shpOffsetVec;
    zTPFX_DistribType pfx_shpDistribType;
    zTPFX_EmitterDirMode pfx_dirMode;
    zTPFX_EmitterFOR pfx_dirFOR;
    zTPFX_EmitterFOR pfx_dirModeTargetFOR;
    zVEC3 pfx_dirModeTargetPos;
    zVEC3 emSelfRotVel;
    int emTrjMode;
    zSTRING name;
    zCVob* vob;
    zVEC3 targetPos;
    zCSoundFX* sfx;
    int sfxHnd;

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

  struct zSVisualFXColl {
    zCVob* foundVob;
    zVEC3 foundContactPoint;
    zVEC3 foundNormal;

    zSVisualFXColl() {}

    // user API
    #include "zSVisualFXColl.inl"
  };

  class oCVisualFX : public zCEffect {
  public:
    zCLASS_DECLARATION( oCVisualFX )

    zSTRING visName_S;
    zSTRING visSize_S;
    float visAlpha;
    zSTRING visAlphaBlendFunc_S;
    float visTexAniFPS;
    int visTexAniIsLooping;
    zSTRING emTrjMode_S;
    zSTRING emTrjOriginNode_S;
    zSTRING emTrjTargetNode_S;
    float emTrjTargetRange;
    float emTrjTargetAzi;
    float emTrjTargetElev;
    int emTrjNumKeys;
    int emTrjNumKeysVar;
    float emTrjAngleElevVar;
    float emTrjAngleHeadVar;
    float emTrjKeyDistVar;
    zSTRING emTrjLoopMode_S;
    zSTRING emTrjEaseFunc_S;
    float emTrjEaseVel;
    float emTrjDynUpdateDelay;
    int emTrjDynUpdateTargetOnly;
    zSTRING emFXCreate_S;
    zSTRING emFXInvestOrigin_S;
    zSTRING emFXInvestTarget_S;
    float emFXTriggerDelay;
    int emFXCreatedOwnTrj;
    zSTRING emActionCollDyn_S;
    zSTRING emActionCollStat_S;
    zSTRING emFXCollStat_S;
    zSTRING emFXCollDyn_S;
    zSTRING emFXCollDynPerc_S;
    zSTRING emFXCollStatAlign_S;
    zSTRING emFXCollDynAlign_S;
    float emFXLifeSpan;
    int emCheckCollision;
    int emAdjustShpToOrigin;
    float emInvestNextKeyDuration;
    float emFlyGravity;
    zSTRING emSelfRotVel_S;
    zSTRING userString[VFX_NUM_USERSTRINGS];
    zSTRING lightPresetName;
    zSTRING sfxID;
    int sfxIsAmbient;
    int sendAssessMagic;
    float secsPerDamage;
    unsigned char dScriptEnd;
    zVEC3 visSize;
    int emTrjMode;
    int emActionCollDyn;
    int emActionCollStat;
    zVEC3 emSelfRotVel;
    TEaseFunc emTrjEaseFunc;
    TTrjLoopMode emTrjLoopMode;
    zTVFXState fxState;
    oCVisualFX* root;
    oCVisualFX* parent;
    oCVisualFX* fxInvestOrigin;
    oCVisualFX* fxInvestTarget;
    oCVisualFXAI* ai;
    zCArray<oCVisualFX*> fxList;
    zCArray<oCVisualFX*> childList;
    zCArray<oCEmitterKey*> emKeyList;
    zCArray<zCVob*> vobList;
    zCArray<zCVob*> ignoreVobList;
    zCArray<zCVob*> allowedCollisionVobList;
    zCArray<zCVob*> collidedVobs;
    zCArray<zSVisualFXColl>queuedCollisions;
    oCTrajectory trajectory;
    zCEarthquake* earthQuake;
    zCVobScreenFX* screenFX;
    float screenFXTime;
    int screenFXDir;
    zCModelNodeInst* orgNode;
    zCModelNodeInst* targetNode;
    zCVisual* lastSetVisual;
    zCVob* origin;
    zCVob* inflictor;
    zCVob* target;
    zCVobLight* light;
    float lightRange;
    zCSoundFX* sfx;
    int sfxHnd;
    zSTRING fxName;
    oCEmitterKey* fxBackup;
    oCEmitterKey* lastSetKey;
    oCEmitterKey* actKey;
    float frameTime;
    float collisionTime;
    float deleteTime;
    float damageTime;
    zVEC3 targetPos;
    zVEC3 lastTrjDir;
    zVEC3 keySize;
    zVEC3 actSize;
    zVEC3 castEndSize;
    float nextLevelTime;
    float easeTime;
    float age;
    float trjUpdateTime;
    float emTrjDist;
    float trjSign;
    float levelTime;
    float lifeSpanTimer;
    float fxStartTime;
    float oldFovX;
    float oldFovY;
    int collisionOccured          : 1;
    int showVisual                : 1;
    int isChild                   : 1;
    int isDeleted                 : 1;
    int initialized               : 1;
    int shouldDelete              : 1;
    int lightning                 : 1;
    int fxInvestOriginInitialized : 1;
    int fxInvestTargetInitialized : 1;
    int fxInvestStopped           : 1;
    int timeScaled                : 1;
    int fovMorph                  : 2;
    int level                     : 5;
    int collisionCtr              : 3;
    int queueSetLevel             : 5;
    float damage;
    int damageType;
    int spellType;
    int spellCat;
    int spellTargetTypes;
    float savePpsValue;
    zVEC2 saveVisSizeStart;
    zVEC3 transRing[VFX_MAX_POS_SAMPLES];
    int ringPos;
    int emTrjFollowHitLastCheck;
    int bIsProjectile;
    int bPfxMeshSetByVisualFX;
    int m_bAllowMovement;
    float m_fSleepTimer;

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

  class oCVisualFXAI : public zCAIBase {
  public:
    zCVob* vob;
    int delete_it;

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