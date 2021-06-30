// Supported with union (c) 2018 Union team

#ifndef __OVIS_FX_H__VER2__
#define __OVIS_FX_H__VER2__

#include "z3d.h"
#include "zAi.h"
#include "zParticle.h"
#include "zParser.h"
#include "zKbSplines.h"
#include "zSound.h"
#include "zVobMisc.h"

namespace Gothic_II_Classic {
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
    void Calc()                                                         zCall( 0x00486300 );
    void Changed()                                                      zCall( 0x00486690 );
    zMAT4 Interpolate( float )                                          zCall( 0x004866A0 );
    zMAT4 InterpolateN( float )                                         zCall( 0x00486AD0 );
    void Draw()                                                         zCall( 0x00486BE0 );
    void Clear()                                                        zCall( 0x00486EA0 );
    zVEC3 RecalcByColl( zVEC3 const&, zVEC3 const&, zVEC3 const&, int ) zCall( 0x00486F70 );
    void ApplyGrav( float const& )                                      zCall( 0x004873E0 );
    void SetByList( zCArray<zCVob*> )                                   zCall( 0x00487450 );
    int VobCross( zCVob const* )                                        zCall( 0x004875C0 );
    ~oCTrajectory()                                                     zCall( 0x00488790 );
    void InsertKey( zMAT4& )                                            zCall( 0x0048F5B0 );
    zMAT4 GetKey( int )                                                 zCall( 0x0048F6C0 );
    int GetNumKeys()                                                    zCall( 0x0048F740 );

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

    void oCEmitterKey_OnInit()                       zCall( 0x00487650 );
    oCEmitterKey()                                   zInit( oCEmitterKey_OnInit() );
    ~oCEmitterKey()                                  zCall( 0x00487940 );
    void SetByScript( zSTRING const& )               zCall( 0x00487B40 );
    void ParseStrings()                              zCall( 0x00487D10 );
    void Edit()                                      zCall( 0x00498E50 );
    void SetDefaultByFX( oCVisualFX* )               zCall( 0x0049C2A0 );
    static void CreateNewScriptKey( zSTRING const& ) zCall( 0x00499240 );

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
    int spellTargetTypes;
    float savePpsValue;
    zVEC2 saveVisSizeStart;
    zVEC3 transRing[VFX_MAX_POS_SAMPLES];
    int ringPos;
    int emTrjFollowHitLastCheck;
    int bIsProjectile;

    void oCVisualFX_OnInit()                                                                             zCall( 0x004882E0 );
    oCVisualFX()                                                                                         zInit( oCVisualFX_OnInit() );
    void CreateHierachy()                                                                                zCall( 0x004895B0 );
    void DisposeHierachy()                                                                               zCall( 0x00489850 );
    void InitValues()                                                                                    zCall( 0x00489EB0 );
    void ParseStrings()                                                                                  zCall( 0x0048A4E0 );
    void UpdateFXByEmitterKey( oCEmitterKey* )                                                           zCall( 0x0048C430 );
    void CreateBackup()                                                                                  zCall( 0x0048CC30 );
    int FindKey( zSTRING const& )                                                                        zCall( 0x0048CC40 );
    oCVisualFX* CreateAndCastFX( zSTRING const&, zCVob const*, zCVob const* )                            zCall( 0x0048D4C0 );
    oCVisualFX* CreateAndCastFX( zSTRING const&, zMAT4 const& )                                          zCall( 0x0048D810 );
    void CreateInvestFX()                                                                                zCall( 0x0048FB80 );
    void InitInvestFX()                                                                                  zCall( 0x0048FD00 );
    void StopInvestFX()                                                                                  zCall( 0x0048FE60 );
    void InitEffect()                                                                                    zCall( 0x00492950 );
    void EndEffect( int )                                                                                zCall( 0x004930A0 );
    void SetShowVisual( int )                                                                            zCall( 0x00493140 );
    int ProcessQueuedCollisions()                                                                        zCall( 0x00493C50 );
    int ProcessCollision( zSVisualFXColl& )                                                              zCall( 0x00493CF0 );
    int CheckDeletion()                                                                                  zCall( 0x00495120 );
    void UpdateActKey()                                                                                  zCall( 0x00495730 );
    void DoMovements()                                                                                   zCall( 0x00495980 );
    int CheckDelayedTrigger()                                                                            zCall( 0x00496EC0 );
    void AdjustShapeToOrigin()                                                                           zCall( 0x00497230 );
    void UpdateEffects()                                                                                 zCall( 0x00497840 );
    void Edit()                                                                                          zCall( 0x00498680 );
    void SetupEmitterKeysByVisual()                                                                      zCall( 0x0049C720 );
    zSTRING const& GetName() const                                                                       zCall( 0x0078B010 );
    static void RemoveInstancesOfClass( zCClassDef&, int )                                               zCall( 0x00488250 );
    static void PreSaveGameProcessing( int )                                                             zCall( 0x004882C0 );
    static void PostSaveGameProcessing()                                                                 zCall( 0x004882D0 );
    static void InitParser()                                                                             zCall( 0x00489B90 );
    static void ExitParser()                                                                             zCall( 0x00489E80 );
    static oCVisualFX* CreateAndPlay( zSTRING const&, zCVob const*, zCVob const*, int, float, int, int ) zCall( 0x0048CDA0 );
    static oCVisualFX* CreateAndPlay( zSTRING const&, zVEC3 const&, zCVob const*, int, float, int, int ) zCall( 0x0048D0C0 );
    static zCObject* _CreateNewInstance()                                                                zCall( 0x004980C0 );
    static void CreateNewScriptFX( zSTRING const& )                                                      zCall( 0x00498C10 );
    static void FxConsole_ParameterChanged( zSTRING const& )                                             zCall( 0x00499480 );
    static void EmConsole_ParameterChanged( zSTRING const& )                                             zCall( 0x0049A0F0 );
    static int FxConsole_EvalFunc( zSTRING const&, zSTRING& )                                            zCall( 0x0049A330 );
    static int EmConsole_EvalFunc( zSTRING const&, zSTRING& )                                            zCall( 0x0049AFC0 );
    virtual zCClassDef* _GetClassDef() const                                                             zCall( 0x00488850 );
    virtual void Archive( zCArchiver& )                                                                  zCall( 0x00497EA0 );
    virtual void Unarchive( zCArchiver& )                                                                zCall( 0x00497EB0 );
    virtual ~oCVisualFX()                                                                                zCall( 0x00488A80 );
    virtual void OnTick()                                                                                zCall( 0x00497DC0 );
    virtual int CanThisCollideWith( zCVob* )                                                             zCall( 0x00494EF0 );
    virtual void Open()                                                                                  zCall( 0x0048FF10 );
    virtual void SetOrigin( zCVob* )                                                                     zCall( 0x0048F770 );
    virtual void SetTarget( zCVob* )                                                                     zCall( 0x0048F950 );
    virtual void SetTarget( zVEC3& )                                                                     zCall( 0x0048FAC0 );
    virtual void SetInflictor( zCVob* )                                                                  zCall( 0x0048F890 );
    virtual zCVob* GetOrigin()                                                                           zCall( 0x00488860 );
    virtual zCVob* GetTarget()                                                                           zCall( 0x00488870 );
    virtual zCVob* GetInflictor()                                                                        zCall( 0x00488880 );
    virtual void Init( zCVob const*, zVEC3 const& )                                                      zCall( 0x00490430 );
    virtual void Init( zCVob const*, zCVob const*, zCVob const* )                                        zCall( 0x00490540 );
    virtual void Init( zCArray<zCVob*> const& )                                                          zCall( 0x00490C90 );
    virtual void InvestNext()                                                                            zCall( 0x00490E20 );
    virtual void SetLevel( int )                                                                         zCall( 0x004912A0 );
    virtual int GetLevel() const                                                                         zCall( 0x00491720 );
    virtual void Cast( int )                                                                             zCall( 0x00491730 );
    virtual void Stop( int )                                                                             zCall( 0x004921B0 );
    virtual void Kill()                                                                                  zCall( 0x00492540 );
    virtual void Play( float, zMAT4 const*, zMAT4 const* )                                               zCall( 0x00488890 );
    virtual int CanBeDeleted()                                                                           zCall( 0x00492820 );
    virtual int IsFinished()                                                                             zCall( 0x00492860 );
    virtual int IsLooping()                                                                              zCall( 0x004928E0 );
    virtual void SetByScript( zSTRING const& )                                                           zCall( 0x0048BB20 );
    virtual void SetDuration( float )                                                                    zCall( 0x004888A0 );
    virtual void Reset()                                                                                 zCall( 0x00490250 );
    virtual void ReportCollision( zCCollisionReport const& )                                             zCall( 0x004932A0 );
    virtual void SetCollisionEnabled( int )                                                              zCall( 0x0048B9C0 );
    virtual void SetCollisionCandidates( zCArray<zCVob*> )                                               zCall( 0x00494D10 );
    virtual void GetCollisionCandidates( zCArray<zCVob*>& )                                              zCall( 0x004888B0 );
    virtual int GetNumCollisionCandidates()                                                              zCall( 0x00488950 );
    virtual int GetCollidedCandidates( zCArray<zCVob*>& )                                                zCall( 0x00494E30 );
    virtual void SetDamage( float )                                                                      zCall( 0x00488960 );
    virtual void SetDamageType( int )                                                                    zCall( 0x00488970 );
    virtual float GetDamage() const                                                                      zCall( 0x00488980 );
    virtual int GetDamageType() const                                                                    zCall( 0x00488990 );
    virtual int IsASpell()                                                                               zCall( 0x004889A0 );
    virtual void SetSpellType( int )                                                                     zCall( 0x004889B0 );
    virtual int GetSpellType() const                                                                     zCall( 0x004889C0 );
    virtual int GetSpellTargetTypes() const                                                              zCall( 0x004889D0 );
    virtual void SetSpellTargetTypes( int )                                                              zCall( 0x004889E0 );
    virtual int GetSendsAssessMagic()                                                                    zCall( 0x00489AF0 );
    virtual void SetSendsAssessMagic( int )                                                              zCall( 0x00489A60 );
    virtual int GetIsProjectile()                                                                        zCall( 0x004889F0 );
    virtual void SetIsProjectile( int )                                                                  zCall( 0x00488A00 );
    virtual void SetVisualByString( zSTRING const& )                                                     zCall( 0x0048A8B0 );
    virtual void CalcTrajectory( int const& )                                                            zCall( 0x0048DC20 );
    virtual void Collide( int )                                                                          zCall( 0x00491FD0 );
    virtual void CollisionResponse( zVEC3 const&, int )                                                  zCall( 0x004947C0 );

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
    virtual ~oCVisualFXAI()                                      zCall( 0x0048A470 );
    virtual void DoAI( zCVob*, int& )                            zCall( 0x00497EC0 );
    virtual void ReportCollisionToAI( zCCollisionReport const& ) zCall( 0x0048A410 );
    virtual void HostVobAddedToWorld( zCVob*, zCWorld* )         zCall( 0x0048A430 );

    // user API
    #include "oCVisualFXAI.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OVIS_FX_H__VER2__