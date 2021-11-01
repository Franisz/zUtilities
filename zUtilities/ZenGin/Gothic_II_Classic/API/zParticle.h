// Supported with union (c) 2018-2021 Union team

#ifndef __ZPARTICLE_H__VER2__
#define __ZPARTICLE_H__VER2__

namespace Gothic_II_Classic {
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
    zPFX_FLOCK_WIND_PLANTS,
    zPFX_FLOCK_WIND_RAND
  };

  // sizeof 64h
  typedef struct zSParticle {
  public:
    zSParticle* next;        // sizeof 04h    offset 00h
    zVEC3 position;          // sizeof 0Ch    offset 04h
    zVEC3 positionWS;        // sizeof 0Ch    offset 10h
    zVEC3 vel;               // sizeof 0Ch    offset 1Ch
    float lifeSpan;          // sizeof 04h    offset 28h
    float alpha;             // sizeof 04h    offset 2Ch
    float alphaVel;          // sizeof 04h    offset 30h
    zVEC2 size;              // sizeof 08h    offset 34h
    zVEC2 sizeVel;           // sizeof 08h    offset 3Ch
    zVEC3 color;             // sizeof 0Ch    offset 44h
    zVEC3 colorVel;          // sizeof 0Ch    offset 50h
    float flockFreeWillTime; // sizeof 04h    offset 5Ch
    zCPolyStrip* polyStrip;  // sizeof 04h    offset 60h

    void zSParticle_OnInit() zCall( 0x005A7820 );
    zSParticle()             zInit( zSParticle_OnInit() );
  } zTParticle;

  // sizeof 364h
  class zCParticleEmitter {
  public:
    float ppsValue;                        // sizeof 04h    offset 00h
    zSTRING ppsScaleKeys_S;                // sizeof 14h    offset 04h
    int ppsIsLooping;                      // sizeof 04h    offset 18h
    int ppsIsSmooth;                       // sizeof 04h    offset 1Ch
    float ppsFPS;                          // sizeof 04h    offset 20h
    zSTRING ppsCreateEm_S;                 // sizeof 14h    offset 24h
    float ppsCreateEmDelay;                // sizeof 04h    offset 38h
    zSTRING shpType_S;                     // sizeof 14h    offset 3Ch
    zSTRING shpFOR_S;                      // sizeof 14h    offset 50h
    zSTRING shpOffsetVec_S;                // sizeof 14h    offset 64h
    zSTRING shpDistribType_S;              // sizeof 14h    offset 78h
    float shpDistribWalkSpeed;             // sizeof 04h    offset 8Ch
    int shpIsVolume;                       // sizeof 04h    offset 90h
    zSTRING shpDim_S;                      // sizeof 14h    offset 94h
    zSTRING shpMesh_S;                     // sizeof 14h    offset A8h
    int shpMeshRender_B;                   // sizeof 04h    offset BCh
    zSTRING shpScaleKeys_S;                // sizeof 14h    offset C0h
    int shpScaleIsLooping;                 // sizeof 04h    offset D4h
    int shpScaleIsSmooth;                  // sizeof 04h    offset D8h
    float shpScaleFPS;                     // sizeof 04h    offset DCh
    zSTRING dirMode_S;                     // sizeof 14h    offset E0h
    zSTRING dirFOR_S;                      // sizeof 14h    offset F4h
    zSTRING dirModeTargetFOR_S;            // sizeof 14h    offset 108h
    zSTRING dirModeTargetPos_S;            // sizeof 14h    offset 11Ch
    float dirAngleHead;                    // sizeof 04h    offset 130h
    float dirAngleHeadVar;                 // sizeof 04h    offset 134h
    float dirAngleElev;                    // sizeof 04h    offset 138h
    float dirAngleElevVar;                 // sizeof 04h    offset 13Ch
    float velAvg;                          // sizeof 04h    offset 140h
    float velVar;                          // sizeof 04h    offset 144h
    float lspPartAvg;                      // sizeof 04h    offset 148h
    float lspPartVar;                      // sizeof 04h    offset 14Ch
    zSTRING flyGravity_S;                  // sizeof 14h    offset 150h
    int flyCollDet_B;                      // sizeof 04h    offset 164h
    zSTRING visName_S;                     // sizeof 14h    offset 168h
    zSTRING visOrientation_S;              // sizeof 14h    offset 17Ch
    int visTexIsQuadPoly;                  // sizeof 04h    offset 190h
    float visTexAniFPS;                    // sizeof 04h    offset 194h
    int visTexAniIsLooping;                // sizeof 04h    offset 198h
    zSTRING visTexColorStart_S;            // sizeof 14h    offset 19Ch
    zSTRING visTexColorEnd_S;              // sizeof 14h    offset 1B0h
    zSTRING visSizeStart_S;                // sizeof 14h    offset 1C4h
    float visSizeEndScale;                 // sizeof 04h    offset 1D8h
    zSTRING visAlphaFunc_S;                // sizeof 14h    offset 1DCh
    float visAlphaStart;                   // sizeof 04h    offset 1F0h
    float visAlphaEnd;                     // sizeof 04h    offset 1F4h
    float trlFadeSpeed;                    // sizeof 04h    offset 1F8h
    zSTRING trlTexture_S;                  // sizeof 14h    offset 1FCh
    float trlWidth;                        // sizeof 04h    offset 210h
    float mrkFadeSpeed;                    // sizeof 04h    offset 214h
    zSTRING mrkTexture_S;                  // sizeof 14h    offset 218h
    float mrkSize;                         // sizeof 04h    offset 22Ch
    zSTRING m_flockMode_S;                 // sizeof 14h    offset 230h
    float m_fFlockWeight;                  // sizeof 04h    offset 244h
    int m_bSlowLocalFOR;                   // sizeof 04h    offset 248h
    zSTRING m_timeStartEnd_S;              // sizeof 14h    offset 24Ch
    int m_bIsAmbientPFX;                   // sizeof 04h    offset 260h
    int endOfDScriptPart;                  // sizeof 04h    offset 264h
    zSTRING particleFXName;                // sizeof 14h    offset 268h
    zCArray<float> ppsScaleKeys;           // sizeof 0Ch    offset 27Ch
    zCParticleEmitter* ppsCreateEmitter;   // sizeof 04h    offset 288h
    zTPFX_EmitterShape shpType;            // sizeof 04h    offset 28Ch
    float shpCircleSphereRadius;           // sizeof 04h    offset 290h
    zVEC3 shpLineBoxDim;                   // sizeof 0Ch    offset 294h
    zCMesh* shpMesh;                       // sizeof 04h    offset 2A0h
    zCPolygon* shpMeshLastPoly;            // sizeof 04h    offset 2A4h
    zTPFX_EmitterFOR shpFOR;               // sizeof 04h    offset 2A8h
    zTPFX_DistribType shpDistribType;      // sizeof 04h    offset 2ACh
    zVEC3 shpOffsetVec;                    // sizeof 0Ch    offset 2B0h
    zCArray<float> shpScaleKeys;           // sizeof 0Ch    offset 2BCh
    zTPFX_EmitterDirMode dirMode;          // sizeof 04h    offset 2C8h
    zTPFX_EmitterFOR dirFOR;               // sizeof 04h    offset 2CCh
    zTPFX_EmitterFOR dirModeTargetFOR;     // sizeof 04h    offset 2D0h
    zVEC3 dirModeTargetPos;                // sizeof 0Ch    offset 2D4h
    zTBBox3D dirAngleBox;                  // sizeof 18h    offset 2E0h
    zVEC3 dirAngleBoxDim;                  // sizeof 0Ch    offset 2F8h
    zVEC3 flyGravity;                      // sizeof 0Ch    offset 304h
    zCTexture* visTexture;                 // sizeof 04h    offset 310h
    zCMesh* visMesh;                       // sizeof 04h    offset 314h
    zTPFX_EmitterVisOrient visOrientation; // sizeof 04h    offset 318h
    zVEC2 visSizeStart;                    // sizeof 08h    offset 31Ch
    zVEC3 visTexColorRGBAStart;            // sizeof 0Ch    offset 324h
    zVEC3 visTexColorRGBAEnd;              // sizeof 0Ch    offset 330h
    zTRnd_AlphaBlendFunc visAlphaFunc;     // sizeof 04h    offset 33Ch
    zCTexture* trlTexture;                 // sizeof 04h    offset 340h
    zCTexture* mrkTexture;                 // sizeof 04h    offset 344h
    int isOneShotFX;                       // sizeof 04h    offset 348h
    float dirAngleHeadVarRad;              // sizeof 04h    offset 34Ch
    float dirAngleElevVarRad;              // sizeof 04h    offset 350h
    zTPFX_FlockMode m_flockMode;           // sizeof 04h    offset 354h
    float m_ooAlphaDist;                   // sizeof 04h    offset 358h
    float m_startTime;                     // sizeof 04h    offset 35Ch
    float m_endTime;                       // sizeof 04h    offset 360h

    void zCParticleEmitter_OnInit( zCParticleEmitter const& )  zCall( 0x005A8A70 );
    void zCParticleEmitter_OnInit()                            zCall( 0x005AD200 );
    zCParticleEmitter( zCParticleEmitter const& a0 )           zInit( zCParticleEmitter_OnInit( a0 ));
    zCParticleEmitter()                                        zInit( zCParticleEmitter_OnInit() );
    ~zCParticleEmitter()                                       zCall( 0x005AD520 );
    void UpdateVelocity()                                      zCall( 0x005AD860 );
    void AddCompoundReferences()                               zCall( 0x005AD870 );
    void ResetStrings()                                        zCall( 0x005AD8C0 );
    void Reset()                                               zCall( 0x005ADB60 );
    void UpdateInternals()                                     zCall( 0x005AE020 );
    void SetOutputDir( zVEC3 const& )                          zCall( 0x005AEE70 );
    void ConvertAnglesIntoBox()                                zCall( 0x005AF0B0 );
    zVEC3 GetPosition()                                        zCall( 0x005AF100 );
    zVEC3 __fastcall GetVelocity( zSParticle*, zCParticleFX* ) zCall( 0x005AF500 );
    zCParticleEmitter& operator =( zCParticleEmitter const& )  zCall( 0x007111E0 );
    static zVEC3 String2Vec3( zSTRING const& )                 zCall( 0x005ADB80 );
    static zVEC2 String2Vec2( zSTRING const& )                 zCall( 0x005ADE00 );

    // user API
    #include "zCParticleEmitter.inl"
  };

  // sizeof 1Ch
  class zCParticleEmitterVars {
  public:
    float ppsScaleKeysActFrame;     // sizeof 04h    offset 00h
    float ppsNumParticlesFraction;  // sizeof 04h    offset 04h
    float ppsTotalLifeTime;         // sizeof 04h    offset 08h
    int ppsDependentEmitterCreated; // sizeof 04h    offset 0Ch
    float shpScaleKeysActFrame;     // sizeof 04h    offset 10h
    float uniformValue;             // sizeof 04h    offset 14h
    float uniformDelta;             // sizeof 04h    offset 18h

    zCParticleEmitterVars() {}

    // user API
    #include "zCParticleEmitterVars.inl"
  };

  // sizeof B8h
  class zCParticleFX : public zCVisual {
  public:
    zCLASS_DECLARATION( zCParticleFX )

    // sizeof 0Ch
    class zCStaticPfxList {
    public:
      zCParticleFX* pfxListHead; // sizeof 04h    offset 00h
      zCParticleFX* pfxListTail; // sizeof 04h    offset 04h
      int numInList;             // sizeof 04h    offset 08h

      zCStaticPfxList() {}
      void InsertPfxHead( zCParticleFX* ) zCall( 0x005A7C00 );
      void RemovePfx( zCParticleFX* )     zCall( 0x005A7C40 );
      void TouchPfx( zCParticleFX* )      zCall( 0x005A7CB0 );
      void ProcessList()                  zCall( 0x005A7D70 );
      int IsInList( zCParticleFX* )       zCall( 0x005A84B0 );

      // user API
      #include "zCParticleFX_zCStaticPfxList.inl"
    };

    zTParticle* firstPart;                     // sizeof 04h    offset 34h
    zCParticleEmitterVars emitterVars;         // sizeof 1Ch    offset 38h
    zCParticleEmitter* emitter;                // sizeof 04h    offset 54h
    zTBBox3D bbox3DWorld;                      // sizeof 18h    offset 58h
    zCVob* connectedVob;                       // sizeof 04h    offset 70h
    int bboxUpdateCtr;                         // sizeof 04h    offset 74h
    group {
      unsigned char emitterIsOwned        : 1; // sizeof 01h    offset bit
      unsigned char dontKillPFXWhenDone   : 1; // sizeof 01h    offset bit
      unsigned char dead                  : 1; // sizeof 01h    offset bit
      unsigned char isOneShotFX           : 1; // sizeof 01h    offset bit
      unsigned char forceEveryFrameUpdate : 1; // sizeof 01h    offset bit
      unsigned char renderUnderWaterOnly  : 1; // sizeof 01h    offset bit
    };
    zCParticleFX* nextPfx;                     // sizeof 04h    offset 7Ch
    zCParticleFX* prevPfx;                     // sizeof 04h    offset 80h
    float privateTotalTime;                    // sizeof 04h    offset 84h
    float lastTimeRendered;                    // sizeof 04h    offset 88h
    float timeScale;                           // sizeof 04h    offset 8Ch
    float localFrameTimeF;                     // sizeof 04h    offset 90h
    zCQuadMark* quadMark;                      // sizeof 04h    offset 94h
    zTBBox3D quadMarkBBox3DWorld;              // sizeof 18h    offset 98h
    float m_BboxYRangeInv;                     // sizeof 04h    offset B0h
    int m_bVisualNeverDies;                    // sizeof 04h    offset B4h

    void zCParticleFX_OnInit()                                        zCall( 0x005A78F0 );
    zCParticleFX()                                                    zInit( zCParticleFX_OnInit() );
    void InitEmitterVars()                                            zCall( 0x005A8550 );
    void FreeParticles()                                              zCall( 0x005A8570 );
    void RemoveEmitter()                                              zCall( 0x005A88E0 );
    int SetEmitter( zCParticleEmitter*, int )                         zCall( 0x005A8920 );
    int SetEmitter( zSTRING const&, int )                             zCall( 0x005A9460 );
    int SetAndStartEmitter( zSTRING const&, int )                     zCall( 0x005A9660 );
    int SetAndStartEmitter( zCParticleEmitter*, int )                 zCall( 0x005A9690 );
    void StopEmitterOutput()                                          zCall( 0x005A96C0 );
    void RestoreEmitterOutput()                                       zCall( 0x005A96D0 );
    int CalcIsDead()                                                  zCall( 0x005A99F0 );
    void UpdateParticleFX()                                           zCall( 0x005A9A80 );
    void CreateParticlesUpdateDependencies()                          zCall( 0x005A9B60 );
    void UpdateParticle( zSParticle* )                                zCall( 0x005A9E10 );
    float GetShapeScaleThisFrame()                                    zCall( 0x005AC2C0 );
    int GetNumParticlesThisFrame()                                    zCall( 0x005AC430 );
    void CheckDependentEmitter()                                      zCall( 0x005AC5D0 );
    void CreateParticles()                                            zCall( 0x005AC770 );
    static zCObject* _CreateNewInstance()                             zCall( 0x005A6ED0 );
    static void ParseParticleFXScript()                               zCall( 0x005A7000 );
    static void InitParticleFX()                                      zCall( 0x005A74D0 );
    static void CleanupParticleFX()                                   zCall( 0x005A7830 );
    static zCParticleEmitter* SearchParticleEmitter( zSTRING const& ) zCall( 0x005A8720 );
    static zCParticleFX* Load( zSTRING const& )                       zCall( 0x005A9710 );
    static float PartRand()                                           zCall( 0x005A9A60 );
    virtual zCClassDef* _GetClassDef() const                          zCall( 0x005A79F0 );
    virtual ~zCParticleFX()                                           zCall( 0x005A7A60 );
    virtual int Render( zTRenderContext& )                            zCall( 0x005AADB0 );
    virtual int IsBBox3DLocal()                                       zCall( 0x005A7A00 );
    virtual zTBBox3D GetBBox3D()                                      zCall( 0x005A98C0 );
    virtual zSTRING GetVisualName()                                   zCall( 0x005A8670 );
    virtual int GetVisualDied()                                       zCall( 0x005A7A10 );
    virtual void SetVisualUsedBy( zCVob* )                            zCall( 0x005A85C0 );
    virtual unsigned long GetRenderSortKey() const                    zCall( 0x005A7A20 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )          zCall( 0x005A7BF0 );
    virtual void HostVobAddedToWorld( zCVob*, zCWorld* )              zCall( 0x005A7BD0 );
    virtual zSTRING const* GetFileExtension( int )                    zCall( 0x005A84E0 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const       zCall( 0x005A8540 );

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

} // namespace Gothic_II_Classic

#endif // __ZPARTICLE_H__VER2__