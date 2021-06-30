// Supported with union (c) 2018 Union team

#ifndef __ZMORPH_MESH_H__VER2__
#define __ZMORPH_MESH_H__VER2__

namespace Gothic_II_Classic {

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

    void zCMorphMeshAni_OnInit()            zCall( 0x0059DBA0 );
    zCMorphMeshAni()                        zInit( zCMorphMeshAni_OnInit() );
    ~zCMorphMeshAni()                       zCall( 0x0059DC00 );
    void SetBlending( float, float )        zCall( 0x0059DCC0 );
    void Load( zCFileBIN& )                 zCall( 0x0059DD30 );
    void Save( zCFileBIN& )                 zCall( 0x0059DE40 );
    void SetFlagsByString( zSTRING const& ) zCall( 0x0059FB50 );

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
    int m_bAlphaTestingEnabled;

    void zCMorphMeshProto_OnInit()                                        zCall( 0x0059DF50 );
    zCMorphMeshProto()                                                    zInit( zCMorphMeshProto_OnInit() );
    ~zCMorphMeshProto()                                                   zCall( 0x0059E0A0 );
    int Release()                                                         zCall( 0x0059E300 );
    zCMorphMeshAni* SearchAni( zSTRING const& )                           zCall( 0x0059E580 );
    int LoadMMB( zSTRING const& )                                         zCall( 0x0059E630 );
    void SaveMMB( zSTRING const& )                                        zCall( 0x0059ED80 );
    zCMorphMeshAni* GenerateMorphAni( zCMesh*, zCArray<int> const&, int ) zCall( 0x0059F190 );
    zCMesh* Load3DSMAXAsc( zSTRING const&, float&, int, int )             zCall( 0x0059F690 );
    void ReadMorphRef( zCArray<int>& )                                    zCall( 0x0059F8F0 );
    void ReadMorphAni( zCArray<int> const& )                              zCall( 0x0059FC00 );
    void LoadMorphScript( zSTRING const& )                                zCall( 0x005A0460 );
    static zCMorphMeshProto* SearchName( zSTRING const& )                 zCall( 0x0059E330 );
    static zCMorphMeshProto* Load( zSTRING const& )                       zCall( 0x0059E3A0 );

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
    int m_bUsesAlphaTesting;
    zCArraySort<zTMorphAniEntry*>aniChannels;
    zCArray<zTRandAni> randAniList;

    zCMorphMesh() {}
    void zCMorphMesh_OnInit( zCMorphMeshProto* )                               zCall( 0x005A09F0 );
    void Init()                                                                zCall( 0x005A09D0 );
    zCMorphMesh( zCMorphMeshProto* a0 )                                        zInit( zCMorphMesh_OnInit( a0 ));
    zCMorphMeshAni* SearchAni( zSTRING const& )                                zCall( 0x005A0D60 );
    int Render_novt( zTRenderContext&, zCRenderLightContainer*, float, float ) zCall( 0x005A0E90 );
    void CalcVertPositions()                                                   zCall( 0x005A0F20 );
    void AdvanceAnis()                                                         zCall( 0x005A12D0 );
    int IsAniActive( zSTRING const& )                                          zCall( 0x005A14E0 );
    int IsAniActive( zCMorphMeshAni* )                                         zCall( 0x005A15C0 );
    void StopAni( zSTRING const& )                                             zCall( 0x005A1600 );
    void StopAni( zCMorphMeshAni* )                                            zCall( 0x005A1720 );
    void FadeOutAni( zSTRING const& )                                          zCall( 0x005A17A0 );
    void FadeOutAni( zCMorphMeshAni* )                                         zCall( 0x005A1890 );
    void StartAni( zSTRING const&, float, float )                              zCall( 0x005A1900 );
    void StartAni( zCMorphMeshAni*, float, float )                             zCall( 0x005A19D0 );
    void RemoveRandAni( zCMorphMeshAni* )                                      zCall( 0x005A1B90 );
    void AddRandAni( zCMorphMeshAni*, float, float, float, float, float )      zCall( 0x005A1C00 );
    void ProcessRandAnis()                                                     zCall( 0x005A1D70 );
    void SetTextureVar( int, int, zSTRING* )                                   zCall( 0x005A1E80 );
    void PrintStatus( int, int )                                               zCall( 0x005A1EB0 );
    static zCObject* _CreateNewInstance()                                      zCall( 0x0059D760 );
    static zCMorphMesh* Load( zSTRING const& )                                 zCall( 0x005A0BC0 );
    virtual zCClassDef* _GetClassDef() const                                   zCall( 0x0059D840 );
    virtual ~zCMorphMesh()                                                     zCall( 0x005A0AD0 );
    virtual int Render( zTRenderContext& )                                     zCall( 0x005A0E10 );
    virtual int IsBBox3DLocal()                                                zCall( 0x0059D850 );
    virtual zTBBox3D GetBBox3D()                                               zCall( 0x005A0CF0 );
    virtual zCOBBox3D* GetOBBox3D()                                            zCall( 0x0059D860 );
    virtual zSTRING GetVisualName()                                            zCall( 0x005A0D30 );
    virtual unsigned long GetRenderSortKey() const                             zCall( 0x0059D870 );
    virtual int CanTraceRay() const                                            zCall( 0x0059D8A0 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& ) zCall( 0x005A1E90 );
    virtual zSTRING const* GetFileExtension( int )                             zCall( 0x005A0C80 );
    virtual int GetAlphaTestingEnabled() const                                 zCall( 0x0059D880 );
    virtual void SetAlphaTestingEnabled( int )                                 zCall( 0x0059D890 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                zCall( 0x005A0CE0 );
    virtual void StartAnimation( zSTRING const& )                              zCall( 0x0059D8B0 );
    virtual void StopAnimation( zSTRING const& )                               zCall( 0x0059D970 );
    virtual int IsAnimationActive( zSTRING const& )                            zCall( 0x0059DA90 );
    virtual zSTRING const* GetAnyAnimation()                                   zCall( 0x005A18E0 );

    // user API
    #include "zCMorphMesh.inl"
  };

  class zCMorphMeshConvertFileHandler : public zCScanDirFileHandler {
  public:

    void zCMorphMeshConvertFileHandler_OnInit()                        zCall( 0x005A2600 );
    zCMorphMeshConvertFileHandler()                                    zInit( zCMorphMeshConvertFileHandler_OnInit() );
    virtual ~zCMorphMeshConvertFileHandler()                           zCall( 0x00424920 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zCall( 0x005A26E0 );

    // user API
    #include "zCMorphMeshConvertFileHandler.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZMORPH_MESH_H__VER2__