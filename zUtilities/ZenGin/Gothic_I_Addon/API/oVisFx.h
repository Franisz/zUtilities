// Supported with union (c) 2018 Union team

#ifndef __OVIS_FX_H__VER1__
#define __OVIS_FX_H__VER1__

#include "z3d.h"
#include "zAi.h"
#include "zParticle.h"
#include "zParser.h"
#include "zKbSplines.h"
#include "zSound.h"
#include "zVobMisc.h"

namespace Gothic_I_Addon {
  const int MAX_SPL_LEVEL          = 20;
  const int VFX_MAX_POS_SAMPLES    = 10;
  const int VFX_NUM_USERSTRINGS    = 3;
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
    EM_TRJ_LINE   = 4,
    EM_TRJ_SPLINE = 8,
    EM_TRJ_RANDOM = 16,
    EM_TRJ_CIRCLE = 32,
    EM_TRJ_FOLLOW = 64
  };

  enum TTrjLoopMode {
    TRJ_LOOP_NONE,
    TRJ_LOOP_RESTART,
    TRJ_LOOP_PINGPONG,
    TRJ_LOOP_HALT
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
    void Calc()                                                         zCall( 0x0048AE10 );
    void Changed()                                                      zCall( 0x0048B180 );
    zMAT4 Interpolate( float )                                          zCall( 0x0048B190 );
    zMAT4 InterpolateN( float )                                         zCall( 0x0048B600 );
    void Draw()                                                         zCall( 0x0048B710 );
    void Clear()                                                        zCall( 0x0048B990 );
    zVEC3 RecalcByColl( zVEC3 const&, zVEC3 const&, zVEC3 const&, int ) zCall( 0x0048BA50 );
    void ApplyGrav( float const& )                                      zCall( 0x0048BF00 );
    void SetByList( zCArray<zCVob*> )                                   zCall( 0x0048BF80 );
    int VobCross( zCVob const* )                                        zCall( 0x0048C120 );
    ~oCTrajectory()                                                     zCall( 0x0048D580 );
    void InsertKey( zMAT4& )                                            zCall( 0x004942C0 );
    zMAT4 GetKey( int )                                                 zCall( 0x004943F0 );
    void SetKey( int, zMAT4 )                                           zCall( 0x004944E0 );
    int GetNumKeys()                                                    zCall( 0x00494510 );

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

    void oCEmitterKey_OnInit()                       zCall( 0x0048C1C0 );
    oCEmitterKey()                                   zInit( oCEmitterKey_OnInit() );
    ~oCEmitterKey()                                  zCall( 0x0048C4B0 );
    void SetByScript( zSTRING const& )               zCall( 0x0048C770 );
    void ParseStrings()                              zCall( 0x0048C9B0 );
    void Edit()                                      zCall( 0x0049CD50 );
    void SetDefaultByFX( oCVisualFX* )               zCall( 0x004A09C0 );
    static void CreateNewScriptKey( zSTRING const& ) zCall( 0x0049D1C0 );

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
    int fxInvestOriginInitialized;
    int fxInvestTargetInitialized;
    int fxInvestStopped;
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
    int level;
    int collisionOccured;
    int collisionCtr;
    int showVisual;
    int isChild;
    int isDeleted;
    int initialized;
    int shouldDelete;
    int lightning;
    int queueSetLevel;
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
    float damage;
    int damageType;
    int spellType;
    int spellTargetTypes;
    float savePpsValue;
    zVEC2 saveVisSizeStart;
    zVEC3 transRing[VFX_MAX_POS_SAMPLES];
    int ringPos;
    int emTrjFollowHitLastCheck;
    int bIsProjectile;

    void oCVisualFX_OnInit()                                                                             zCall( 0x0048D120 );
    oCVisualFX()                                                                                         zInit( oCVisualFX_OnInit() );
    void CreateHierachy()                                                                                zCall( 0x0048E490 );
    void DisposeHierachy()                                                                               zCall( 0x0048E760 );
    void InitValues()                                                                                    zCall( 0x0048ECB0 );
    void ParseStrings()                                                                                  zCall( 0x0048F320 );
    void UpdateFXByEmitterKey( oCEmitterKey* )                                                           zCall( 0x00491380 );
    void CreateBackup()                                                                                  zCall( 0x00491BD0 );
    int FindKey( zSTRING const& )                                                                        zCall( 0x00491BE0 );
    oCVisualFX* CreateAndCastFX( zSTRING const&, zCVob const*, zCVob const* )                            zCall( 0x00492530 );
    oCVisualFX* CreateAndCastFX( zSTRING const&, zMAT4 const& )                                          zCall( 0x00492890 );
    void CreateInvestFX()                                                                                zCall( 0x00494BF0 );
    void InitInvestFX()                                                                                  zCall( 0x00494DB0 );
    void StopInvestFX()                                                                                  zCall( 0x00494F10 );
    void SetShowVisual( int )                                                                            zCall( 0x00497260 );
    void InitEffect()                                                                                    zCall( 0x00497B80 );
    void EndEffect( int )                                                                                zCall( 0x00498050 );
    int ProcessQueuedCollisions()                                                                        zCall( 0x00498AA0 );
    int ProcessCollision( zSVisualFXColl& )                                                              zCall( 0x00498B50 );
    int CheckDeletion()                                                                                  zCall( 0x00499CC0 );
    void UpdateActKey()                                                                                  zCall( 0x0049A110 );
    void DoMovements()                                                                                   zCall( 0x0049A390 );
    int CheckDelayedTrigger()                                                                            zCall( 0x0049AEE0 );
    void AdjustShapeToOrigin()                                                                           zCall( 0x0049B170 );
    void UpdateEffects()                                                                                 zCall( 0x0049B630 );
    void Edit()                                                                                          zCall( 0x0049C480 );
    void SetupEmitterKeysByVisual()                                                                      zCall( 0x004A0E40 );
    zSTRING const& GetName() const                                                                       zCall( 0x0077F620 );
    static void RemoveInstancesOfClass( zCClassDef&, int )                                               zCall( 0x0048CF00 );
    static void PreSaveGameProcessing( int )                                                             zCall( 0x0048D100 );
    static void PostSaveGameProcessing()                                                                 zCall( 0x0048D110 );
    static void InitParser()                                                                             zCall( 0x0048E980 );
    static void ExitParser()                                                                             zCall( 0x0048EC80 );
    static oCVisualFX* CreateAndPlay( zSTRING const&, zCVob const*, zCVob const*, int, float, int, int ) zCall( 0x00491D60 );
    static oCVisualFX* CreateAndPlay( zSTRING const&, zVEC3 const&, zCVob const*, int, float, int, int ) zCall( 0x004920B0 );
    static zCObject* _CreateNewInstance()                                                                zCall( 0x0049BCE0 );
    static void CreateNewScriptFX( zSTRING const& )                                                      zCall( 0x0049CAC0 );
    static void FxConsole_ParameterChanged( zSTRING const& )                                             zCall( 0x0049D450 );
    static void EmConsole_ParameterChanged( zSTRING const& )                                             zCall( 0x0049E2D0 );
    static int FxConsole_EvalFunc( zSTRING const&, zSTRING& )                                            zCall( 0x0049E5D0 );
    static int EmConsole_EvalFunc( zSTRING const&, zSTRING& )                                            zCall( 0x0049F400 );
    virtual zCClassDef* _GetClassDef() const                                                             zCall( 0x0048D640 );
    virtual void Archive( zCArchiver& )                                                                  zCall( 0x0049BAA0 );
    virtual void Unarchive( zCArchiver& )                                                                zCall( 0x0049BAB0 );
    virtual ~oCVisualFX()                                                                                zCall( 0x0048D880 );
    virtual void OnTick()                                                                                zCall( 0x0049B9C0 );
    virtual int CanThisCollideWith( zCVob* )                                                             zCall( 0x00499A80 );
    virtual void Open()                                                                                  zCall( 0x00494FC0 );
    virtual void SetOrigin( zCVob* )                                                                     zCall( 0x00494950 );
    virtual void SetTarget( zCVob* )                                                                     zCall( 0x00494A20 );
    virtual void SetTarget( zVEC3& )                                                                     zCall( 0x00494B80 );
    virtual void SetInflictor( zCVob* )                                                                  zCall( 0x004949C0 );
    virtual zCVob* GetOrigin()                                                                           zCall( 0x0048D650 );
    virtual zCVob* GetTarget()                                                                           zCall( 0x0048D660 );
    virtual zCVob* GetInflictor()                                                                        zCall( 0x0048D670 );
    virtual void Init( zCVob const*, zVEC3 const& )                                                      zCall( 0x00495520 );
    virtual void Init( zCVob const*, zCVob const*, zCVob const* )                                        zCall( 0x00495640 );
    virtual void Init( zCArray<zCVob*> const& )                                                          zCall( 0x00495DA0 );
    virtual void InvestNext()                                                                            zCall( 0x00495F30 );
    virtual void SetLevel( int )                                                                         zCall( 0x00496310 );
    virtual int GetLevel() const                                                                         zCall( 0x00496710 );
    virtual void Cast( int )                                                                             zCall( 0x00496720 );
    virtual void Stop( int )                                                                             zCall( 0x004973B0 );
    virtual void Kill()                                                                                  zCall( 0x004977A0 );
    virtual void Play( float, zMAT4 const*, zMAT4 const* )                                               zCall( 0x0048D680 );
    virtual int CanBeDeleted()                                                                           zCall( 0x00497A40 );
    virtual int IsFinished()                                                                             zCall( 0x00497A80 );
    virtual int IsLooping()                                                                              zCall( 0x00497B10 );
    virtual void SetByScript( zSTRING const& )                                                           zCall( 0x00490910 );
    virtual void SetDuration( float )                                                                    zCall( 0x0048D690 );
    virtual void Reset()                                                                                 zCall( 0x00495330 );
    virtual void ReportCollision( zCCollisionReport const& )                                             zCall( 0x004980A0 );
    virtual void SetCollisionEnabled( int )                                                              zCall( 0x004907F0 );
    virtual void SetCollisionCandidates( zCArray<zCVob*> )                                               zCall( 0x004998A0 );
    virtual void GetCollisionCandidates( zCArray<zCVob*>& )                                              zCall( 0x0048D6A0 );
    virtual int GetNumCollisionCandidates()                                                              zCall( 0x0048D750 );
    virtual int GetCollidedCandidates( zCArray<zCVob*>& )                                                zCall( 0x004999B0 );
    virtual void SetDamage( float )                                                                      zCall( 0x0048D760 );
    virtual void SetDamageType( int )                                                                    zCall( 0x0048D770 );
    virtual float GetDamage() const                                                                      zCall( 0x0048D780 );
    virtual int GetDamageType() const                                                                    zCall( 0x0048D790 );
    virtual int IsASpell()                                                                               zCall( 0x0048D7A0 );
    virtual void SetSpellType( int )                                                                     zCall( 0x0048D7B0 );
    virtual int GetSpellType() const                                                                     zCall( 0x0048D7C0 );
    virtual int GetSpellTargetTypes() const                                                              zCall( 0x0048D7D0 );
    virtual void SetSpellTargetTypes( int )                                                              zCall( 0x0048D7E0 );
    virtual int GetIsProjectile()                                                                        zCall( 0x0048D7F0 );
    virtual void SetIsProjectile( int )                                                                  zCall( 0x0048D800 );
    virtual void SetVisualByString( zSTRING const& )                                                     zCall( 0x0048F6A0 );
    virtual void CalcTrajectory( int const& )                                                            zCall( 0x00492CF0 );
    virtual void Collide( int )                                                                          zCall( 0x00496FC0 );
    virtual void CollisionResponse( zVEC3 const&, int )                                                  zCall( 0x00499300 );


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
    virtual ~oCVisualFXAI()                                      zCall( 0x0048F2B0 );
    virtual void DoAI( zCVob*, int& )                            zCall( 0x0049BAC0 );
    virtual void ReportCollisionToAI( zCCollisionReport const& ) zCall( 0x0048F250 );
    virtual void HostVobAddedToWorld( zCVob*, zCWorld* )         zCall( 0x0048F270 );

    // user API
    #include "oCVisualFXAI.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OVIS_FX_H__VER1__