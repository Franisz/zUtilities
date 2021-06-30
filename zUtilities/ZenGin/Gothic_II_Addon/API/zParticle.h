// Supported with union (c) 2018 Union team

#ifndef __ZPARTICLE_H__VER3__
#define __ZPARTICLE_H__VER3__

#include "zVisual.h"
#include "zRenderer.h"
#include "zProgMesh.h"
#include "zModel.h"

namespace Gothic_II_Addon {

  enum zTPFX_EmitterShape {
    zPFX_EMITTER_SHAPE_POINT,
    zPFX_EMITTER_SHAPE_LINE,
    zPFX_EMITTER_SHAPE_BOX,
    zPFX_EMITTER_SHAPE_CIRCLE,
    zPFX_EMITTER_SHAPE_SPHERE,
    zPFX_EMITTER_SHAPE_MESH
  };

  enum zTPFX_EmitterFOR {
    zPFX_FOR_WORLD,
    zPFX_FOR_OBJECT,
    zPFX_FOR_OBJECT_EACH_FRAME
  };

  enum zTPFX_EmitterDirMode {
    zPFX_EMITTER_DIRMODE_NONE,
    zPFX_EMITTER_DIRMODE_DIR,
    zPFX_EMITTER_DIRMODE_TARGET,
    zPFX_EMITTER_DIRMODE_MESH
  };

  enum zTPFX_EmitterVisOrient {
    zPFX_EMITTER_VISORIENT_NONE,
    zPFX_EMITTER_VISORIENT_VELO_ALIGNED,
    zPFX_EMITTER_VISORIENT_VOB_XZPLANE,
    zPFX_EMITTER_VISORIENT_VELO_ALIGNED3D
  };

  enum zTPFX_DistribType {
    zPFX_EMITTER_DISTRIBTYPE_RAND,
    zPFX_EMITTER_DISTRIBTYPE_UNIFORM,
    zPFX_EMITTER_DISTRIBTYPE_WALK
  };

  enum zTPFX_FlockMode {
    zPFX_FLOCK_NONE,
    zPFX_FLOCK_WIND,
    zPFX_FLOCK_WIND_PLANTS
  };

  typedef struct zSParticle {
  public:
    zSParticle* next;
    zVEC3 position;
    zVEC3 positionWS;
    zVEC3 vel;
    float lifeSpan;
    float alpha;
    float alphaVel;
    zVEC2 size;
    zVEC2 sizeVel;
    zVEC3 color;
    zVEC3 colorVel;
    zCPolyStrip* polyStrip;

    void zSParticle_OnInit() zCall( 0x005ACEA0 );
    zSParticle()             zInit( zSParticle_OnInit() );
  } zTParticle;

  class zCParticleEmitter {
  public:
    float ppsValue;
    zSTRING ppsScaleKeys_S;
    int ppsIsLooping;
    int ppsIsSmooth;
    float ppsFPS;
    zSTRING ppsCreateEm_S;
    float ppsCreateEmDelay;
    zSTRING shpType_S;
    zSTRING shpFOR_S;
    zSTRING shpOffsetVec_S;
    zSTRING shpDistribType_S;
    float shpDistribWalkSpeed;
    int shpIsVolume;
    zSTRING shpDim_S;
    zSTRING shpMesh_S;
    int shpMeshRender_B;
    zSTRING shpScaleKeys_S;
    int shpScaleIsLooping;
    int shpScaleIsSmooth;
    float shpScaleFPS;
    zSTRING dirMode_S;
    zSTRING dirFOR_S;
    zSTRING dirModeTargetFOR_S;
    zSTRING dirModeTargetPos_S;
    float dirAngleHead;
    float dirAngleHeadVar;
    float dirAngleElev;
    float dirAngleElevVar;
    float velAvg;
    float velVar;
    float lspPartAvg;
    float lspPartVar;
    zSTRING flyGravity_S;
    int flyCollDet_B;
    zSTRING visName_S;
    zSTRING visOrientation_S;
    int visTexIsQuadPoly;
    float visTexAniFPS;
    int visTexAniIsLooping;
    zSTRING visTexColorStart_S;
    zSTRING visTexColorEnd_S;
    zSTRING visSizeStart_S;
    float visSizeEndScale;
    zSTRING visAlphaFunc_S;
    float visAlphaStart;
    float visAlphaEnd;
    float trlFadeSpeed;
    zSTRING trlTexture_S;
    float trlWidth;
    float mrkFadeSpeed;
    zSTRING mrkTexture_S;
    float mrkSize;
    zSTRING m_flockMode_S;
    float m_fFlockWeight;
    int m_bSlowLocalFOR;
    zSTRING m_timeStartEnd_S;
    int m_bIsAmbientPFX;
    int endOfDScriptPart;
    zSTRING particleFXName;
    zCArray<float> ppsScaleKeys;
    zCParticleEmitter* ppsCreateEmitter;
    zTPFX_EmitterShape shpType;
    float shpCircleSphereRadius;
    zVEC3 shpLineBoxDim;
    zVEC3* shpMeshLastPolyNormal;
    zCMesh* shpMesh;
    zCProgMeshProto* shpProgMesh;
    zCModel* shpModel;
    zTPFX_EmitterFOR shpFOR;
    zTPFX_DistribType shpDistribType;
    zVEC3 shpOffsetVec;
    zCArray<float> shpScaleKeys;
    zTPFX_EmitterDirMode dirMode;
    zTPFX_EmitterFOR dirFOR;
    zTPFX_EmitterFOR dirModeTargetFOR;
    zVEC3 dirModeTargetPos;
    zTBBox3D dirAngleBox;
    zVEC3 dirAngleBoxDim;
    zVEC3 flyGravity;
    zCTexture* visTexture;
    zTPFX_EmitterVisOrient visOrientation;
    zVEC2 visSizeStart;
    zVEC3 visTexColorRGBAStart;
    zVEC3 visTexColorRGBAEnd;
    zTRnd_AlphaBlendFunc visAlphaFunc;
    zCTexture* trlTexture;
    zCTexture* mrkTexture;
    int isOneShotFX;
    float dirAngleHeadVarRad;
    float dirAngleElevVarRad;
    zTPFX_FlockMode m_flockMode;
    float m_ooAlphaDist;
    float m_startTime;
    float m_endTime;

    void zCParticleEmitter_OnInit( zCParticleEmitter const& )  zCall( 0x005AE140 );
    void zCParticleEmitter_OnInit()                            zCall( 0x005B2860 );
    zCParticleEmitter( zCParticleEmitter const& a0 )           zInit( zCParticleEmitter_OnInit( a0 ));
    zCParticleEmitter()                                        zInit( zCParticleEmitter_OnInit() );
    ~zCParticleEmitter()                                       zCall( 0x005B2B80 );
    void UpdateVelocity()                                      zCall( 0x005B2EE0 );
    void AddCompoundReferences()                               zCall( 0x005B2EF0 );
    void ResetStrings()                                        zCall( 0x005B2F50 );
    void Reset()                                               zCall( 0x005B31F0 );
    void UpdateInternals()                                     zCall( 0x005B36B0 );
    void SetOutputDir( zVEC3 const& )                          zCall( 0x005B45F0 );
    void ConvertAnglesIntoBox()                                zCall( 0x005B4830 );
    zVEC3 GetPosition()                                        zCall( 0x005B4880 );
    zVEC3 __fastcall GetVelocity( zSParticle*, zCParticleFX* ) zCall( 0x005B5060 );
    zCParticleEmitter& operator =( zCParticleEmitter const& )  zCall( 0x00770750 );
    static zVEC3 String2Vec3( zSTRING const& )                 zCall( 0x005B3210 );
    static zVEC2 String2Vec2( zSTRING const& )                 zCall( 0x005B3490 );

    // user API
    #include "zCParticleEmitter.inl"
  };

  class zCParticleEmitterVars {
  public:
    float ppsScaleKeysActFrame;
    float ppsNumParticlesFraction;
    float ppsTotalLifeTime;
    int ppsDependentEmitterCreated;
    float shpScaleKeysActFrame;
    float uniformValue;
    float uniformDelta;

    zCParticleEmitterVars() {}

    // user API
    #include "zCParticleEmitterVars.inl"
  };

  class zCParticleFX : public zCVisual {
  public:
    zCLASS_DECLARATION( zCParticleFX )

    class zCStaticPfxList {
    public:
      zCParticleFX* pfxListHead;
      zCParticleFX* pfxListTail;
      int numInList;

      zCStaticPfxList() {}
      void InsertPfxHead( zCParticleFX* ) zCall( 0x005AD280 );
      void RemovePfx( zCParticleFX* )     zCall( 0x005AD2C0 );
      void TouchPfx( zCParticleFX* )      zCall( 0x005AD330 );
      void ProcessList()                  zCall( 0x005AD3F0 );
      int IsInList( zCParticleFX* )       zCall( 0x005ADB70 );

      // user API
      #include "zCParticleFX_zCStaticPfxList.inl"
    };

    zTParticle* firstPart;
    zCParticleEmitterVars emitterVars;
    zCParticleEmitter* emitter;
    zTBBox3D bbox3DWorld;
    zCVob* connectedVob;
    int bboxUpdateCtr;
    group {
      unsigned char emitterIsOwned        : 1;
      unsigned char dontKillPFXWhenDone   : 1;
      unsigned char dead                  : 1;
      unsigned char isOneShotFX           : 1;
      unsigned char forceEveryFrameUpdate : 1;
      unsigned char renderUnderWaterOnly  : 1;
    };
    zCParticleFX* nextPfx;
    zCParticleFX* prevPfx;
    float privateTotalTime;
    float lastTimeRendered;
    float timeScale;
    float localFrameTimeF;
    zCQuadMark* quadMark;
    zTBBox3D quadMarkBBox3DWorld;
    float m_BboxYRangeInv;
    int m_bVisualNeverDies;

    void zCParticleFX_OnInit()                                        zCall( 0x005ACF70 );
    zCParticleFX()                                                    zInit( zCParticleFX_OnInit() );
    void InitEmitterVars()                                            zCall( 0x005ADC10 );
    void FreeParticles()                                              zCall( 0x005ADC30 );
    void RemoveEmitter()                                              zCall( 0x005ADFA0 );
    int SetEmitter( zCParticleEmitter*, int )                         zCall( 0x005ADFE0 );
    int SetEmitter( zSTRING const&, int )                             zCall( 0x005AEB40 );
    int SetAndStartEmitter( zSTRING const&, int )                     zCall( 0x005AED40 );
    int SetAndStartEmitter( zCParticleEmitter*, int )                 zCall( 0x005AED70 );
    void StopEmitterOutput()                                          zCall( 0x005AEDA0 );
    void RestoreEmitterOutput()                                       zCall( 0x005AEDB0 );
    int CalcIsDead()                                                  zCall( 0x005AF0D0 );
    void UpdateParticleFX()                                           zCall( 0x005AF160 );
    void CreateParticlesUpdateDependencies()                          zCall( 0x005AF240 );
    void UpdateParticle( zSParticle* )                                zCall( 0x005AF500 );
    float GetShapeScaleThisFrame()                                    zCall( 0x005B1920 );
    int GetNumParticlesThisFrame()                                    zCall( 0x005B1A90 );
    void CheckDependentEmitter()                                      zCall( 0x005B1C30 );
    void CreateParticles()                                            zCall( 0x005B1DD0 );
    static zCObject* _CreateNewInstance()                             zCall( 0x005AC430 );
    static void ParseParticleFXScript()                               zCall( 0x005AC560 );
    static void InitParticleFX()                                      zCall( 0x005ACB50 );
    static void CleanupParticleFX()                                   zCall( 0x005ACEB0 );
    static zCParticleEmitter* SearchParticleEmitter( zSTRING const& ) zCall( 0x005ADDE0 );
    static zCParticleFX* Load( zSTRING const& )                       zCall( 0x005AEDF0 );
    static float PartRand()                                           zCall( 0x005AF140 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x005AD070 );
    virtual ~zCParticleFX()                                           zCall( 0x005AD0E0 );
    virtual int Render( zTRenderContext& )                            zCall( 0x005B0310 );
    virtual int IsBBox3DLocal()                                       zCall( 0x005AD080 );
    virtual zTBBox3D GetBBox3D()                                      zCall( 0x005AEFA0 );
    virtual zSTRING GetVisualName()                                   zCall( 0x005ADD30 );
    virtual int GetVisualDied()                                       zCall( 0x005AD090 );
    virtual void SetVisualUsedBy( zCVob* )                            zCall( 0x005ADC80 );
    virtual unsigned long GetRenderSortKey() const                    zCall( 0x005AD0A0 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )          zCall( 0x005AD270 );
    virtual void HostVobAddedToWorld( zCVob*, zCWorld* )              zCall( 0x005AD250 );
    virtual zSTRING const* GetFileExtension( int )                    zCall( 0x005ADBA0 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const       zCall( 0x005ADC00 );

    // static properties
    static zCParser*& s_pfxParser;
    static zCArraySort<zCParticleEmitter*>& s_emitterPresetList;
    static zCParticleEmitter& s_emitterDummyDefault;
    static int& s_bAmbientPFXEnabled;
    static int& s_globNumPart;
    static zTParticle*& s_globPartList;
    static zTParticle*& s_globFreePart;
    static zCMesh*& s_partMeshTri;
    static zCMesh*& s_partMeshQuad;
    static int& s_showDebugInfo;
    static zCStaticPfxList& s_pfxList;

    // user API
    #include "zCParticleFX.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZPARTICLE_H__VER3__