// Supported with union (c) 2018-2021 Union team

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

  // sizeof 60h
  typedef struct zSParticle {
  public:
    zSParticle* next;       // sizeof 04h    offset 00h
    zVEC3 position;         // sizeof 0Ch    offset 04h
    zVEC3 positionWS;       // sizeof 0Ch    offset 10h
    zVEC3 vel;              // sizeof 0Ch    offset 1Ch
    float lifeSpan;         // sizeof 04h    offset 28h
    float alpha;            // sizeof 04h    offset 2Ch
    float alphaVel;         // sizeof 04h    offset 30h
    zVEC2 size;             // sizeof 08h    offset 34h
    zVEC2 sizeVel;          // sizeof 08h    offset 3Ch
    zVEC3 color;            // sizeof 0Ch    offset 44h
    zVEC3 colorVel;         // sizeof 0Ch    offset 50h
    zCPolyStrip* polyStrip; // sizeof 04h    offset 5Ch

    void zSParticle_OnInit() zCall( 0x005ACEA0 );
    zSParticle()             zInit( zSParticle_OnInit() );
  } zTParticle;

  // sizeof 368h
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
    zVEC3* shpMeshLastPolyNormal;          // sizeof 04h    offset 2A0h
    zCMesh* shpMesh;                       // sizeof 04h    offset 2A4h
    zCProgMeshProto* shpProgMesh;          // sizeof 04h    offset 2A8h
    zCModel* shpModel;                     // sizeof 04h    offset 2ACh
    zTPFX_EmitterFOR shpFOR;               // sizeof 04h    offset 2B0h
    zTPFX_DistribType shpDistribType;      // sizeof 04h    offset 2B4h
    zVEC3 shpOffsetVec;                    // sizeof 0Ch    offset 2B8h
    zCArray<float> shpScaleKeys;           // sizeof 0Ch    offset 2C4h
    zTPFX_EmitterDirMode dirMode;          // sizeof 04h    offset 2D0h
    zTPFX_EmitterFOR dirFOR;               // sizeof 04h    offset 2D4h
    zTPFX_EmitterFOR dirModeTargetFOR;     // sizeof 04h    offset 2D8h
    zVEC3 dirModeTargetPos;                // sizeof 0Ch    offset 2DCh
    zTBBox3D dirAngleBox;                  // sizeof 18h    offset 2E8h
    zVEC3 dirAngleBoxDim;                  // sizeof 0Ch    offset 300h
    zVEC3 flyGravity;                      // sizeof 0Ch    offset 30Ch
    zCTexture* visTexture;                 // sizeof 04h    offset 318h
    zTPFX_EmitterVisOrient visOrientation; // sizeof 04h    offset 31Ch
    zVEC2 visSizeStart;                    // sizeof 08h    offset 320h
    zVEC3 visTexColorRGBAStart;            // sizeof 0Ch    offset 328h
    zVEC3 visTexColorRGBAEnd;              // sizeof 0Ch    offset 334h
    zTRnd_AlphaBlendFunc visAlphaFunc;     // sizeof 04h    offset 340h
    zCTexture* trlTexture;                 // sizeof 04h    offset 344h
    zCTexture* mrkTexture;                 // sizeof 04h    offset 348h
    int isOneShotFX;                       // sizeof 04h    offset 34Ch
    float dirAngleHeadVarRad;              // sizeof 04h    offset 350h
    float dirAngleElevVarRad;              // sizeof 04h    offset 354h
    zTPFX_FlockMode m_flockMode;           // sizeof 04h    offset 358h
    float m_ooAlphaDist;                   // sizeof 04h    offset 35Ch
    float m_startTime;                     // sizeof 04h    offset 360h
    float m_endTime;                       // sizeof 04h    offset 364h

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
      void InsertPfxHead( zCParticleFX* ) zCall( 0x005AD280 );
      void RemovePfx( zCParticleFX* )     zCall( 0x005AD2C0 );
      void TouchPfx( zCParticleFX* )      zCall( 0x005AD330 );
      void ProcessList()                  zCall( 0x005AD3F0 );
      int IsInList( zCParticleFX* )       zCall( 0x005ADB70 );

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