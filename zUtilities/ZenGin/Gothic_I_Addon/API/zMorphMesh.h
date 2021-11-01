// Supported with union (c) 2018-2021 Union team

#ifndef __ZMORPH_MESH_H__VER1__
#define __ZMORPH_MESH_H__VER1__

namespace Gothic_I_Addon {

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

    void zCMorphMeshAni_OnInit()            zCall( 0x0059E170 );
    zCMorphMeshAni()                        zInit( zCMorphMeshAni_OnInit() );
    ~zCMorphMeshAni()                       zCall( 0x0059E1D0 );
    void SetBlending( float, float )        zCall( 0x0059E2B0 );
    void Load( zCFileBIN& )                 zCall( 0x0059E320 );
    void Save( zCFileBIN& )                 zCall( 0x0059E460 );
    void SetFlagsByString( zSTRING const& ) zCall( 0x005A0440 );

    // user API
    #include "zCMorphMeshAni.inl"
  };

  // sizeof 38h
  class zCMorphMeshProto {
  public:
    zCMorphMeshProto* next;               // sizeof 04h    offset 00h
    zCMorphMeshProto* prev;               // sizeof 04h    offset 04h
    int refCtr;                           // sizeof 04h    offset 08h
    zSTRING morphProtoName;               // sizeof 14h    offset 0Ch
    zCProgMeshProto* morphRefMesh;        // sizeof 04h    offset 20h
    zVEC3* morphRefMeshVertPos;           // sizeof 04h    offset 24h
    zCArraySort<zCMorphMeshAni*> aniList; // sizeof 10h    offset 28h

    void zCMorphMeshProto_OnInit()                                        zCall( 0x0059E570 );
    zCMorphMeshProto()                                                    zInit( zCMorphMeshProto_OnInit() );
    ~zCMorphMeshProto()                                                   zCall( 0x0059E720 );
    int Release()                                                         zCall( 0x0059E9A0 );
    zCMorphMeshAni* SearchAni( zSTRING const& )                           zCall( 0x0059ED20 );
    int LoadMMB( zSTRING const& )                                         zCall( 0x0059EDD0 );
    void SaveMMB( zSTRING const& )                                        zCall( 0x0059F5A0 );
    zCMorphMeshAni* GenerateMorphAni( zCMesh*, zCArray<int> const&, int ) zCall( 0x0059F9C0 );
    zCMesh* Load3DSMAXAsc( zSTRING const&, float&, int, int )             zCall( 0x0059FF90 );
    void ReadMorphRef( zCArray<int>& )                                    zCall( 0x005A0180 );
    void ReadMorphAni( zCArray<int> const& )                              zCall( 0x005A04F0 );
    void LoadMorphScript( zSTRING const& )                                zCall( 0x005A0E60 );
    static zCMorphMeshProto* SearchName( zSTRING const& )                 zCall( 0x0059E9D0 );
    static zCMorphMeshProto* Load( zSTRING const& )                       zCall( 0x0059EA40 );

    // static properties
    static int& autoConvertBinaryFile;
    static zCMorphMeshProto*& morphRoot;

    // user API
    #include "zCMorphMeshProto.inl"
  };

  // sizeof 84h
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
    zCArraySort<zTMorphAniEntry*>aniChannels; // sizeof 10h    offset 68h
    zCArray<zTRandAni> randAniList;           // sizeof 0Ch    offset 78h

    zCMorphMesh() {}
    void zCMorphMesh_OnInit( zCMorphMeshProto* )                               zCall( 0x005A1470 );
    void Init()                                                                zCall( 0x005A1460 );
    zCMorphMesh( zCMorphMeshProto* a0 )                                        zInit( zCMorphMesh_OnInit( a0 ));
    zCMorphMeshAni* SearchAni( zSTRING const& )                                zCall( 0x005A1820 );
    int Render_novt( zTRenderContext&, zCRenderLightContainer*, float, float ) zCall( 0x005A1950 );
    void CalcVertPositions()                                                   zCall( 0x005A19E0 );
    void AdvanceAnis()                                                         zCall( 0x005A1E90 );
    int IsAniActive( zSTRING const& )                                          zCall( 0x005A2090 );
    int IsAniActive( zCMorphMeshAni* )                                         zCall( 0x005A2170 );
    void StopAni( zSTRING const& )                                             zCall( 0x005A21B0 );
    void StopAni( zCMorphMeshAni* )                                            zCall( 0x005A22C0 );
    void FadeOutAni( zSTRING const& )                                          zCall( 0x005A2330 );
    void FadeOutAni( zCMorphMeshAni* )                                         zCall( 0x005A2420 );
    void StartAni( zSTRING const&, float, float )                              zCall( 0x005A2480 );
    void StartAni( zCMorphMeshAni*, float, float )                             zCall( 0x005A2540 );
    void RemoveRandAni( zCMorphMeshAni* )                                      zCall( 0x005A2730 );
    void AddRandAni( zCMorphMeshAni*, float, float, float, float, float )      zCall( 0x005A27A0 );
    void ProcessRandAnis()                                                     zCall( 0x005A2940 );
    void SetTextureVar( int, int, zSTRING* )                                   zCall( 0x005A2A60 );
    void PrintStatus( int, int )                                               zCall( 0x005A2AB0 );
    static zCObject* _CreateNewInstance()                                      zCall( 0x0059DD60 );
    static zCMorphMesh* Load( zSTRING const& )                                 zCall( 0x005A1650 );
    virtual zCClassDef* _GetClassDef() const                                   zCall( 0x0059DE40 );
    virtual ~zCMorphMesh()                                                     zCall( 0x005A1550 );
    virtual int Render( zTRenderContext& )                                     zCall( 0x005A18D0 );
    virtual int IsBBox3DLocal()                                                zCall( 0x0059DE50 );
    virtual zTBBox3D GetBBox3D()                                               zCall( 0x005A1790 );
    virtual zCOBBox3D* GetOBBox3D()                                            zCall( 0x0059DE60 );
    virtual zSTRING GetVisualName()                                            zCall( 0x005A17F0 );
    virtual unsigned long GetRenderSortKey() const                             zCall( 0x0059DE70 );
    virtual int CanTraceRay() const                                            zCall( 0x0059DE80 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& ) zCall( 0x005A2A80 );
    virtual zSTRING const* GetFileExtension( int )                             zCall( 0x005A1720 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                zCall( 0x005A1780 );
    virtual void StartAnimation( zSTRING const& )                              zCall( 0x0059DE90 );
    virtual void StopAnimation( zSTRING const& )                               zCall( 0x0059DF50 );
    virtual int IsAnimationActive( zSTRING const& )                            zCall( 0x0059E060 );
    virtual zSTRING const* GetAnyAnimation()                                   zCall( 0x005A2460 );

    // user API
    #include "zCMorphMesh.inl"
  };

  // sizeof 30h
  class zCMorphMeshConvertFileHandler : public zCScanDirFileHandler {
  public:

    void zCMorphMeshConvertFileHandler_OnInit()                        zCall( 0x005A31B0 );
    zCMorphMeshConvertFileHandler()                                    zInit( zCMorphMeshConvertFileHandler_OnInit() );
    virtual ~zCMorphMeshConvertFileHandler()                           zCall( 0x00426B00 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zCall( 0x005A3290 );

    // user API
    #include "zCMorphMeshConvertFileHandler.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZMORPH_MESH_H__VER1__