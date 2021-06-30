// Supported with union (c) 2018 Union team

#ifndef __ZPARTICLE_H__VER1__
#define __ZPARTICLE_H__VER1__

namespace Gothic_I_Addon {
  const int zPARTICLE_MAX_GLOBAL = 4096;

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
    zPFX_FOR_OBJECT
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

  typedef struct zSParticle {
  public:
    zSParticle* next;
    zVEC3 position;
    zVEC3 vel;
    float lifeSpan;
    float alpha;
    float alphaVel;
    zVEC2 size;
    zVEC2 sizeVel;
    zVEC3 color;
    zVEC3 colorVel;
    float texAniFrame;
    zCPolyStrip* polyStrip;

    void zSParticle_OnInit() zCall( 0x005A8690 );
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
    int endOfDScriptPart;
    zSTRING particleFXName;
    zCArray<float> ppsScaleKeys;
    zCParticleEmitter* ppsCreateEmitter;
    zTPFX_EmitterShape shpType;
    float shpCircleSphereRadius;
    zVEC3 shpLineBoxDim;
    zCMesh* shpMesh;
    zCPolygon* shpMeshLastPoly;
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
    zCMesh* visMesh;
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

    void zCParticleEmitter_OnInit( zCParticleEmitter const& )  zCall( 0x005A98B0 );
    void zCParticleEmitter_OnInit()                            zCall( 0x005AD6F0 );
    zCParticleEmitter( zCParticleEmitter const& a0 )           zInit( zCParticleEmitter_OnInit( a0 ));
    zCParticleEmitter()                                        zInit( zCParticleEmitter_OnInit() );
    ~zCParticleEmitter()                                       zCall( 0x005AD9E0 );
    void AddCompoundReferences()                               zCall( 0x005ADDF0 );
    void ResetStrings()                                        zCall( 0x005ADE40 );
    void Reset()                                               zCall( 0x005AE120 );
    void UpdateInternals()                                     zCall( 0x005AE680 );
    void SetOutputDir( zVEC3 const& )                          zCall( 0x005AF1D0 );
    void ConvertAnglesIntoBox()                                zCall( 0x005AF420 );
    zVEC3 GetPosition()                                        zCall( 0x005AF470 );
    zVEC3 __fastcall GetVelocity( zSParticle*, zCParticleFX* ) zCall( 0x005AF9B0 );
    zCParticleEmitter& operator =( zCParticleEmitter const& )  zCall( 0x006FEF00 );
    static zVEC3 String2Vec3( zSTRING const& )                 zCall( 0x005AE140 );
    static zVEC2 String2Vec2( zSTRING const& )                 zCall( 0x005AE420 );

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
      void InsertPfxHead( zCParticleFX* ) zCall( 0x005A8A80 );
      void RemovePfx( zCParticleFX* )     zCall( 0x005A8AC0 );
      void TouchPfx( zCParticleFX* )      zCall( 0x005A8B30 );
      void ProcessList()                  zCall( 0x005A8C00 );
      int IsInList( zCParticleFX* )       zCall( 0x005A9280 );

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
    };
    zCParticleFX* nextPfx;
    zCParticleFX* prevPfx;
    float privateTotalTime;
    float lastTimeRendered;
    float timeScale;
    float localFrameTimeF;
    zCQuadMark* quadMark;
    zTBBox3D quadMarkBBox3DWorld;

    void zCParticleFX_OnInit()                                          zCall( 0x005A8760 );
    zCParticleFX()                                                      zInit( zCParticleFX_OnInit() );
    void InitEmitterVars()                                              zCall( 0x005A9320 );
    void FreeParticles()                                                zCall( 0x005A9340 );
    void RemoveEmitter()                                                zCall( 0x005A9700 );
    int SetEmitter( zCParticleEmitter*, int )                           zCall( 0x005A9740 );
    int SetEmitter( zSTRING const&, int )                               zCall( 0x005AA1A0 );
    int SetAndStartEmitter( zSTRING const&, int )                       zCall( 0x005AA400 );
    int SetAndStartEmitter( zCParticleEmitter*, int )                   zCall( 0x005AA430 );
    void StopEmitterOutput()                                            zCall( 0x005AA460 );
    void RestoreEmitterOutput()                                         zCall( 0x005AA470 );
    int CalcIsDead()                                                    zCall( 0x005AA7D0 );
    void UpdateParticleFX()                                             zCall( 0x005AA850 );
    void CreateParticlesUpdateDependencies()                            zCall( 0x005AA930 );
    void UpdateParticle( zSParticle* )                                  zCall( 0x005AABF0 );
    float GetShapeScaleThisFrame()                                      zCall( 0x005AC960 );
    int GetNumParticlesThisFrame()                                      zCall( 0x005ACAA0 );
    void CheckDependentEmitter()                                        zCall( 0x005ACC20 );
    void CreateParticles()                                              zCall( 0x005ACE10 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005A7C60 );
    static void ParseParticleFXScript()                                 zCall( 0x005A7DB0 );
    static void InitParticleFX()                                        zCall( 0x005A82B0 );
    static void CleanupParticleFX()                                     zCall( 0x005A86A0 );
    static zCParticleEmitter* SearchParticleEmitter( zSTRING const& )   zCall( 0x005A9520 );
    static zCParticleFX* Load( zSTRING const& )                         zCall( 0x005AA4B0 );
    static float PartRand()                                             zCall( 0x005AA830 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005A8860 );
    virtual ~zCParticleFX()                                             zCall( 0x005A88D0 );
    virtual int Render( zTRenderContext& )                              zCall( 0x005AB4E0 );
    virtual int IsBBox3DLocal()                                         zCall( 0x005A8870 );
    virtual zTBBox3D GetBBox3D()                                        zCall( 0x005AA6A0 );
    virtual zSTRING GetVisualName()                                     zCall( 0x005A9470 );
    virtual int GetVisualDied()                                         zCall( 0x005A8880 );
    virtual void SetVisualUsedBy( zCVob* )                              zCall( 0x005A9390 );
    virtual unsigned long GetRenderSortKey() const                      zCall( 0x005A8890 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )            zCall( 0x005A8A70 );
    virtual void HostVobAddedToWorld( zCVob*, zCWorld* )                zCall( 0x005A8A50 );
    virtual zSTRING const* GetFileExtension( int )                      zCall( 0x005A92B0 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const         zCall( 0x005A9310 );


    // static properties
    static zCParser*& s_pfxParser;
    static zCArraySort<zCParticleEmitter*>& s_emitterPresetList;
    static zCParticleEmitter& s_emitterDummyDefault;
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

} // namespace Gothic_I_Addon

#endif // __ZPARTICLE_H__VER1__