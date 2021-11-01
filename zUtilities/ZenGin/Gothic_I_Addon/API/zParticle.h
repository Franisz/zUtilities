// Supported with union (c) 2018-2021 Union team

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

  // sizeof 58h
  typedef struct zSParticle {
  public:
    zSParticle* next;       // sizeof 04h    offset 00h
    zVEC3 position;         // sizeof 0Ch    offset 04h
    zVEC3 vel;              // sizeof 0Ch    offset 10h
    float lifeSpan;         // sizeof 04h    offset 1Ch
    float alpha;            // sizeof 04h    offset 20h
    float alphaVel;         // sizeof 04h    offset 24h
    zVEC2 size;             // sizeof 08h    offset 28h
    zVEC2 sizeVel;          // sizeof 08h    offset 30h
    zVEC3 color;            // sizeof 0Ch    offset 38h
    zVEC3 colorVel;         // sizeof 0Ch    offset 44h
    float texAniFrame;      // sizeof 04h    offset 50h
    zCPolyStrip* polyStrip; // sizeof 04h    offset 54h

    void zSParticle_OnInit() zCall( 0x005A8690 );
    zSParticle()             zInit( zSParticle_OnInit() );
  } zTParticle;

  // sizeof 320h
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
    int endOfDScriptPart;                  // sizeof 04h    offset 230h
    zSTRING particleFXName;                // sizeof 14h    offset 234h
    zCArray<float> ppsScaleKeys;           // sizeof 0Ch    offset 248h
    zCParticleEmitter* ppsCreateEmitter;   // sizeof 04h    offset 254h
    zTPFX_EmitterShape shpType;            // sizeof 04h    offset 258h
    float shpCircleSphereRadius;           // sizeof 04h    offset 25Ch
    zVEC3 shpLineBoxDim;                   // sizeof 0Ch    offset 260h
    zCMesh* shpMesh;                       // sizeof 04h    offset 26Ch
    zCPolygon* shpMeshLastPoly;            // sizeof 04h    offset 270h
    zTPFX_EmitterFOR shpFOR;               // sizeof 04h    offset 274h
    zTPFX_DistribType shpDistribType;      // sizeof 04h    offset 278h
    zVEC3 shpOffsetVec;                    // sizeof 0Ch    offset 27Ch
    zCArray<float> shpScaleKeys;           // sizeof 0Ch    offset 288h
    zTPFX_EmitterDirMode dirMode;          // sizeof 04h    offset 294h
    zTPFX_EmitterFOR dirFOR;               // sizeof 04h    offset 298h
    zTPFX_EmitterFOR dirModeTargetFOR;     // sizeof 04h    offset 29Ch
    zVEC3 dirModeTargetPos;                // sizeof 0Ch    offset 2A0h
    zTBBox3D dirAngleBox;                  // sizeof 18h    offset 2ACh
    zVEC3 dirAngleBoxDim;                  // sizeof 0Ch    offset 2C4h
    zVEC3 flyGravity;                      // sizeof 0Ch    offset 2D0h
    zCTexture* visTexture;                 // sizeof 04h    offset 2DCh
    zCMesh* visMesh;                       // sizeof 04h    offset 2E0h
    zTPFX_EmitterVisOrient visOrientation; // sizeof 04h    offset 2E4h
    zVEC2 visSizeStart;                    // sizeof 08h    offset 2E8h
    zVEC3 visTexColorRGBAStart;            // sizeof 0Ch    offset 2F0h
    zVEC3 visTexColorRGBAEnd;              // sizeof 0Ch    offset 2FCh
    zTRnd_AlphaBlendFunc visAlphaFunc;     // sizeof 04h    offset 308h
    zCTexture* trlTexture;                 // sizeof 04h    offset 30Ch
    zCTexture* mrkTexture;                 // sizeof 04h    offset 310h
    int isOneShotFX;                       // sizeof 04h    offset 314h
    float dirAngleHeadVarRad;              // sizeof 04h    offset 318h
    float dirAngleElevVarRad;              // sizeof 04h    offset 31Ch

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

  // sizeof B0h
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
      void InsertPfxHead( zCParticleFX* ) zCall( 0x005A8A80 );
      void RemovePfx( zCParticleFX* )     zCall( 0x005A8AC0 );
      void TouchPfx( zCParticleFX* )      zCall( 0x005A8B30 );
      void ProcessList()                  zCall( 0x005A8C00 );
      int IsInList( zCParticleFX* )       zCall( 0x005A9280 );

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
    };
    zCParticleFX* nextPfx;                     // sizeof 04h    offset 7Ch
    zCParticleFX* prevPfx;                     // sizeof 04h    offset 80h
    float privateTotalTime;                    // sizeof 04h    offset 84h
    float lastTimeRendered;                    // sizeof 04h    offset 88h
    float timeScale;                           // sizeof 04h    offset 8Ch
    float localFrameTimeF;                     // sizeof 04h    offset 90h
    zCQuadMark* quadMark;                      // sizeof 04h    offset 94h
    zTBBox3D quadMarkBBox3DWorld;              // sizeof 18h    offset 98h

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