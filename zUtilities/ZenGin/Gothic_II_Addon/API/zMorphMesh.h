// Supported with union (c) 2018-2021 Union team

#ifndef __ZMORPH_MESH_H__VER3__
#define __ZMORPH_MESH_H__VER3__

#include "z3d.h"
#include "zProgMesh.h"
#include "zModel.h"

namespace Gothic_II_Addon {

  // sizeof 50h
  class zCMorphMeshAni {
  public:
    // sizeof 01h
    struct zCMorphMeshAniDummy0 {
      unsigned char discontinuity : 1; // sizeof 01h    offset bit
      unsigned char looping       : 1; // sizeof 01h    offset bit
      unsigned char shape         : 1; // sizeof 01h    offset bit
      unsigned char refShape      : 1; // sizeof 01h    offset bit
    };

    zSTRING aniName;            // sizeof 14h    offset 00h
    zSTRING ascName;            // sizeof 14h    offset 14h
    float blendInSpeed;         // sizeof 04h    offset 28h
    float blendOutSpeed;        // sizeof 04h    offset 2Ch
    float holdTime;             // sizeof 04h    offset 30h
    int layer;                  // sizeof 04h    offset 34h
    float fpsRate;              // sizeof 04h    offset 38h
    zCMorphMeshAniDummy0 flags; // sizeof 01h    offset 3Ch
    int numVert;                // sizeof 04h    offset 40h
    int* vertIndexList;         // sizeof 04h    offset 44h
    int numFrames;              // sizeof 04h    offset 48h
    zVEC3* vertPosMatrix;       // sizeof 04h    offset 4Ch

    void zCMorphMeshAni_OnInit()            zCall( 0x005A3100 );
    zCMorphMeshAni()                        zInit( zCMorphMeshAni_OnInit() );
    ~zCMorphMeshAni()                       zCall( 0x005A3160 );
    void SetBlending( float, float )        zCall( 0x005A3220 );
    void Load( zCFileBIN& )                 zCall( 0x005A3290 );
    void Save( zCFileBIN& )                 zCall( 0x005A33A0 );
    void SetFlagsByString( zSTRING const& ) zCall( 0x005A50B0 );

    // user API
    #include "zCMorphMeshAni.inl"
  };

  // sizeof 3Ch
  class zCMorphMeshProto {
  public:
    zCMorphMeshProto* next;               // sizeof 04h    offset 00h
    zCMorphMeshProto* prev;               // sizeof 04h    offset 04h
    int refCtr;                           // sizeof 04h    offset 08h
    zSTRING morphProtoName;               // sizeof 14h    offset 0Ch
    zCProgMeshProto* morphRefMesh;        // sizeof 04h    offset 20h
    zVEC3* morphRefMeshVertPos;           // sizeof 04h    offset 24h
    zCArraySort<zCMorphMeshAni*> aniList; // sizeof 10h    offset 28h
    int m_bAlphaTestingEnabled;           // sizeof 04h    offset 38h

    void zCMorphMeshProto_OnInit()                                        zCall( 0x005A34B0 );
    zCMorphMeshProto()                                                    zInit( zCMorphMeshProto_OnInit() );
    ~zCMorphMeshProto()                                                   zCall( 0x005A3600 );
    int Release()                                                         zCall( 0x005A3860 );
    zCMorphMeshAni* SearchAni( zSTRING const& )                           zCall( 0x005A3AE0 );
    int LoadMMB( zSTRING const& )                                         zCall( 0x005A3B90 );
    void SaveMMB( zSTRING const& )                                        zCall( 0x005A42E0 );
    zCMorphMeshAni* GenerateMorphAni( zCMesh*, zCArray<int> const&, int ) zCall( 0x005A46F0 );
    zCMesh* Load3DSMAXAsc( zSTRING const&, float&, int, int )             zCall( 0x005A4BF0 );
    void ReadMorphRef( zCArray<int>& )                                    zCall( 0x005A4E50 );
    void ReadMorphAni( zCArray<int> const& )                              zCall( 0x005A5160 );
    void LoadMorphScript( zSTRING const& )                                zCall( 0x005A59C0 );
    static zCMorphMeshProto* SearchName( zSTRING const& )                 zCall( 0x005A3890 );
    static zCMorphMeshProto* Load( zSTRING const& )                       zCall( 0x005A3900 );

    // static properties
    static int& autoConvertBinaryFile;
    static zCMorphMeshProto*& morphRoot;

    // user API
    #include "zCMorphMeshProto.inl"
  };

  // sizeof 88h
  class zCMorphMesh : public zCVisualAnimate {
  public:
    zCLASS_DECLARATION( zCMorphMesh )

    enum {
      zMORPH_BLEND_STATE_FADEIN,
      zMORPH_BLEND_STATE_CONST,
      zMORPH_BLEND_STATE_FADEOUT
    };

    // sizeof 2Ch
    struct zTMorphAniEntry {
      zCMorphMeshAni* ani; // sizeof 04h    offset 00h
      float weight;        // sizeof 04h    offset 04h
      float weightDest;    // sizeof 04h    offset 08h
      float actFrame;      // sizeof 04h    offset 0Ch
      int actFrameInt;     // sizeof 04h    offset 10h
      int nextFrameInt;    // sizeof 04h    offset 14h
      float frac;          // sizeof 04h    offset 18h
      float blendInSpeed;  // sizeof 04h    offset 1Ch
      float blendOutSpeed; // sizeof 04h    offset 20h
      float holdTime;      // sizeof 04h    offset 24h
      int blendState;      // sizeof 04h    offset 28h

      zTMorphAniEntry() {}

      // user API
      #include "zCMorphMesh_zTMorphAniEntry.inl"
    };

    // sizeof 1Ch
    struct zTRandAni {
      float randAniTimer;      // sizeof 04h    offset 00h
      zCMorphMeshAni* randAni; // sizeof 04h    offset 04h
      float randAniTimeMin;    // sizeof 04h    offset 08h
      float randAniTimeMinVar; // sizeof 04h    offset 0Ch
      float randAniTimeMax;    // sizeof 04h    offset 10h
      float randAniTimeMaxVar; // sizeof 04h    offset 14h
      float randAniProbMin;    // sizeof 04h    offset 18h

      zTRandAni() {}

      // user API
      #include "zCMorphMesh_zTRandAni.inl"
    };

    zCMorphMeshProto* morphProto;             // sizeof 04h    offset 34h
    zCProgMeshProto* morphMesh;               // sizeof 04h    offset 38h
    zCMorphMeshAni* refShapeAni;              // sizeof 04h    offset 3Ch
    zCModelTexAniState texAniState;           // sizeof 28h    offset 40h
    int m_bUsesAlphaTesting;                  // sizeof 04h    offset 68h
    zCArraySort<zTMorphAniEntry*>aniChannels; // sizeof 10h    offset 6Ch
    zCArray<zTRandAni> randAniList;           // sizeof 0Ch    offset 7Ch

    zCMorphMesh() {}
    void zCMorphMesh_OnInit( zCMorphMeshProto* )                               zCall( 0x005A5F50 );
    void Init()                                                                zCall( 0x005A5F30 );
    zCMorphMesh( zCMorphMeshProto* a0 )                                        zInit( zCMorphMesh_OnInit( a0 ));
    zCMorphMeshAni* SearchAni( zSTRING const& )                                zCall( 0x005A62C0 );
    int Render_novt( zTRenderContext&, zCRenderLightContainer*, float, float ) zCall( 0x005A63F0 );
    void CalcVertPositions()                                                   zCall( 0x005A6480 );
    void AdvanceAnis()                                                         zCall( 0x005A6830 );
    int IsAniActive( zSTRING const& )                                          zCall( 0x005A6A40 );
    int IsAniActive( zCMorphMeshAni* )                                         zCall( 0x005A6B20 );
    void StopAni( zSTRING const& )                                             zCall( 0x005A6B60 );
    void StopAni( zCMorphMeshAni* )                                            zCall( 0x005A6C80 );
    void FadeOutAni( zSTRING const& )                                          zCall( 0x005A6D00 );
    void FadeOutAni( zCMorphMeshAni* )                                         zCall( 0x005A6DF0 );
    void StartAni( zSTRING const&, float, float )                              zCall( 0x005A6E60 );
    void StartAni( zCMorphMeshAni*, float, float )                             zCall( 0x005A6F30 );
    void RemoveRandAni( zCMorphMeshAni* )                                      zCall( 0x005A70F0 );
    void AddRandAni( zCMorphMeshAni*, float, float, float, float, float )      zCall( 0x005A7160 );
    void ProcessRandAnis()                                                     zCall( 0x005A72D0 );
    void SetTextureVar( int, int, zSTRING* )                                   zCall( 0x005A73E0 );
    void PrintStatus( int, int )                                               zCall( 0x005A7410 );
    static zCObject* _CreateNewInstance()                                      zCall( 0x005A2CC0 );
    static zCMorphMesh* Load( zSTRING const& )                                 zCall( 0x005A6120 );
    virtual zCClassDef* _GetClassDef() const                                   zCall( 0x005A2DA0 );
    virtual ~zCMorphMesh()                                                     zCall( 0x005A6030 );
    virtual int Render( zTRenderContext& )                                     zCall( 0x005A6370 );
    virtual int IsBBox3DLocal()                                                zCall( 0x005A2DB0 );
    virtual zTBBox3D GetBBox3D()                                               zCall( 0x005A6250 );
    virtual zCOBBox3D* GetOBBox3D()                                            zCall( 0x005A2DC0 );
    virtual zSTRING GetVisualName()                                            zCall( 0x005A6290 );
    virtual unsigned long GetRenderSortKey() const                             zCall( 0x005A2DD0 );
    virtual int CanTraceRay() const                                            zCall( 0x005A2E00 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& ) zCall( 0x005A73F0 );
    virtual zSTRING const* GetFileExtension( int )                             zCall( 0x005A61E0 );
    virtual int GetAlphaTestingEnabled() const                                 zCall( 0x005A2DE0 );
    virtual void SetAlphaTestingEnabled( int )                                 zCall( 0x005A2DF0 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                zCall( 0x005A6240 );
    virtual void StartAnimation( zSTRING const& )                              zCall( 0x005A2E10 );
    virtual void StopAnimation( zSTRING const& )                               zCall( 0x005A2ED0 );
    virtual int IsAnimationActive( zSTRING const& )                            zCall( 0x005A2FF0 );
    virtual zSTRING const* GetAnyAnimation()                                   zCall( 0x005A6E40 );

    // user API
    #include "zCMorphMesh.inl"
  };

  // sizeof 30h
  class zCMorphMeshConvertFileHandler : public zCScanDirFileHandler {
  public:

    void zCMorphMeshConvertFileHandler_OnInit()                        zCall( 0x005A7B60 );
    zCMorphMeshConvertFileHandler()                                    zInit( zCMorphMeshConvertFileHandler_OnInit() );
    virtual ~zCMorphMeshConvertFileHandler()                           zCall( 0x00424C50 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zCall( 0x005A7C40 );

    // user API
    #include "zCMorphMeshConvertFileHandler.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZMORPH_MESH_H__VER3__