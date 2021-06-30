// Supported with union (c) 2018 Union team

#ifndef __ZMORPH_MESH_H__VER1__
#define __ZMORPH_MESH_H__VER1__

namespace Gothic_I_Addon {

  class zCMorphMeshAni {
  public:
    struct zCMorphMeshAniDummy0 {
      unsigned char discontinuity : 1;
      unsigned char looping       : 1;
      unsigned char shape         : 1;
      unsigned char refShape      : 1;
    };

    zSTRING aniName;
    zSTRING ascName;
    float blendInSpeed;
    float blendOutSpeed;
    float holdTime;
    int layer;
    float fpsRate;
    zCMorphMeshAniDummy0 flags;
    int numVert;
    int* vertIndexList;
    int numFrames;
    zVEC3* vertPosMatrix;

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

  class zCMorphMeshProto {
  public:
    zCMorphMeshProto* next;
    zCMorphMeshProto* prev;
    int refCtr;
    zSTRING morphProtoName;
    zCProgMeshProto* morphRefMesh;
    zVEC3* morphRefMeshVertPos;
    zCArraySort<zCMorphMeshAni*> aniList;

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

  class zCMorphMesh : public zCVisualAnimate {
  public:
    zCLASS_DECLARATION( zCMorphMesh )

    enum {
      zMORPH_BLEND_STATE_FADEIN,
      zMORPH_BLEND_STATE_CONST,
      zMORPH_BLEND_STATE_FADEOUT
    };

    struct zTMorphAniEntry {
      zCMorphMeshAni* ani;
      float weight;
      float weightDest;
      float actFrame;
      int actFrameInt;
      int nextFrameInt;
      float frac;
      float blendInSpeed;
      float blendOutSpeed;
      float holdTime;
      int blendState;

      zTMorphAniEntry() {}

      // user API
      #include "zCMorphMesh_zTMorphAniEntry.inl"
    };

    struct zTRandAni {
      float randAniTimer;
      zCMorphMeshAni* randAni;
      float randAniTimeMin;
      float randAniTimeMinVar;
      float randAniTimeMax;
      float randAniTimeMaxVar;
      float randAniProbMin;

      zTRandAni() {}

      // user API
      #include "zCMorphMesh_zTRandAni.inl"
    };

    zCMorphMeshProto* morphProto;
    zCProgMeshProto* morphMesh;
    zCMorphMeshAni* refShapeAni;
    zCModelTexAniState texAniState;
    zCArraySort<zTMorphAniEntry*>aniChannels;
    zCArray<zTRandAni> randAniList;

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