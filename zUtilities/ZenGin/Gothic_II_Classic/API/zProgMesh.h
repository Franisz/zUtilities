// Supported with union (c) 2018 Union team

#ifndef __ZPROG_MESH_H__VER2__
#define __ZPROG_MESH_H__VER2__

namespace Gothic_II_Classic {
  const int NUM_WEDGE_CACHE = 4096;
  const int NUM_POS_CACHE   = 2048;

  enum zTPMRenderFlags {
    zPM_RENDER_FLAG_SW_TRAFO_VERTS     = 1,
    zPM_RENDER_FLAG_PACK_DYNAMIC_VB    = 2,
    zPM_RENDER_FLAG_DONT_SET_TRANSFROM = 4,
    zPM_RENDER_FLAG_MORPH              = 8
  };

  enum zTPMLightingMode {
    zPM_LIGHTING_MODE_PRELIT = 0,
    zPM_LIGHTING_MODE_EXACT
  };

  enum zTPMBuildFlags {
    zPM_BUILD_FLAG_NO_LOD                  = 1,
    zPM_BUILD_FLAG_NO_TRIPLANES            = 2,
    zPM_BUILD_FLAG_NO_POSNORMALS           = 4,
    zPM_BUILD_FLAG_FORCE_SMOOTH_NORMALS    = 8,
    zPM_BUILD_FLAG_DONT_REMOVE_DEGEN_POLYS = 16,
    zPM_BUILD_FLAG_CREATE_SUBDIV_DATA      = 32
  };

  struct zTLazyMesh {
    zCArray<int> wedgePermut;
    zCArray<int> wedgeParent;
    zCArray<unsigned short int> triMatIndexList;
    zCArray<zVEC3> posList;
    zCArray<zVEC3> posNormalList;
    zCArray<zCMaterial*> matList;
    zCArray<zTPMTriangle> triList;
    zCArray<zTPMWedge> wedgeList;
    zCArray<float> colorList;
    zCArray<unsigned short int> wedgeMap;
    zCArray<zTPMVertexUpdate> vertexUpdates;
    zCArray<unsigned short int> triPlaneIndexList;
    zCArray<zTPlane> triPlaneList;
    zCArray<zTPMTriangleEdges> triEdgeList;
    zCArray<zTPMEdge> edgeList;
    zCArray<float> edgeScoreList;

    void zTLazyMesh_OnInit() zCall( 0x005BDE40 );
    zTLazyMesh()             zInit( zTLazyMesh_OnInit() );
    ~zTLazyMesh()            zCall( 0x005BDF10 );

    // user API
    #include "zTLazyMesh.inl"
  };

  struct zTPMWedge {
    zVEC3 normal;
    zVEC2 texUV;
    unsigned short int position;

    zTPMWedge() {}

    // user API
    #include "zTPMWedge.inl"
  };

  struct zTPMTriangle {
    unsigned short int wedge[3];

    zTPMTriangle() {}

    // user API
    #include "zTPMTriangle.inl"
  };

  struct zTPMTriangleEdges {
    unsigned short int edge[3];

    zTPMTriangleEdges() {}

    // user API
    #include "zTPMTriangleEdges.inl"
  };

  struct zTPMEdge {
    unsigned short int wedge[2];

    zTPMEdge() {}

    // user API
    #include "zTPMEdge.inl"
  };

  struct zTPMVertexUpdate {
    unsigned short int numNewTri;
    unsigned short int numNewWedge;

    zTPMVertexUpdate() {}

    // user API
    #include "zTPMVertexUpdate.inl"
  };

  class zCProgMeshProto : public zCVisual {
  public:
    zCLASS_DECLARATION( zCProgMeshProto )

    struct zTLODRenderArgs {
      float vertPerc;
      int numPos;
      int numMinMorphPos;
      float morphFrac;

      zTLODRenderArgs() {}

      // user API
      #include "zCProgMeshProto_zTLODRenderArgs.inl"
    };

    struct zTLODParams {
      float strength;
      float zDisplace2;
      float morphPerc;
      int minVerts;

      zTLODParams() {}

      // user API
      #include "zCProgMeshProto_zTLODParams.inl"
    };

    class zCSubMesh {
    public:
      zCMaterial* material;
      zCArrayAdapt<zTPMTriangle> triList;
      zCArrayAdapt<zTPMWedge> wedgeList;
      zCArrayAdapt<float> colorList;
      zCArrayAdapt<unsigned short int> triPlaneIndexList;
      zCArrayAdapt<zTPlane> triPlaneList;
      zCArrayAdapt<zTPMTriangleEdges> triEdgeList;
      zCArrayAdapt<zTPMEdge> edgeList;
      zCArrayAdapt<float> edgeScoreList;
      zCArrayAdapt<unsigned short int> wedgeMap;
      zCArrayAdapt<zTPMVertexUpdate> vertexUpdates;
      int vbStartIndex;

      void zCSubMesh_OnInit() zCall( 0x005C0EA0 );
      zCSubMesh()             zInit( zCSubMesh_OnInit() );
      ~zCSubMesh()            zCall( 0x005C0EF0 );

      // user API
      #include "zCProgMeshProto_zCSubMesh.inl"
    };

    struct zTLODRenderArgsSubMesh {
      int numTri;
      int numWedge;
      int numMinMorphWedge;
      int numSubdivEdges;

      zTLODRenderArgsSubMesh() {}

      // user API
      #include "zCProgMeshProto_zTLODRenderArgsSubMesh.inl"
    };

    zCArrayAdapt<zVEC3> posList;
    zCArrayAdapt<zVEC3> posNormalList;
    zTBBox3D bbox3D;
    zCOBBox3D obbox3D;
    zCVertexBuffer* vertexBufferStatic;
    zCSubMesh* subMeshList;
    int numSubMeshes;
    unsigned char* dataPool;
    unsigned long dataSize;
    float avgTriArea;
    int m_bUsesAlphaTesting;
    zTLODParams lodParams;
    zTPMLightingMode lightingMode;
    unsigned long pmeshID;
    unsigned long renderSortKey;

    void zCProgMeshProto_OnInit()                                                                                                              zCall( 0x005C0F70 );
    zCProgMeshProto()                                                                                                                          zInit( zCProgMeshProto_OnInit() );
    void CalcRenderSortKey()                                                                                                                   zCall( 0x005C11F0 );
    void PackStaticVertexBuffers()                                                                                                             zCall( 0x005C12B0 );
    int __fastcall CheckRayPolyIntersection( zCSubMesh*, int, zVEC3 const&, zVEC3 const&, zVEC3&, float& ) const                               zCall( 0x005C2030 );
    int __fastcall CheckRayPolyIntersection2Sided( zCSubMesh*, int, zVEC3 const&, zVEC3 const&, zVEC3&, float& ) const                         zCall( 0x005C2320 );
    int GetNumTri() const                                                                                                                      zCall( 0x005C27C0 );
    zCPolygon* GetPolygon( int )                                                                                                               zCall( 0x005C27E0 );
    zCMesh* GetMesh( int )                                                                                                                     zCall( 0x005C2970 );
    float __fastcall CalcLODRenderVertPerc( zTRenderContext const& )                                                                           zCall( 0x005C3040 );
    int __fastcall CalcLODRenderArgs( zTRenderContext const&, zTLODRenderArgs& )                                                               zCall( 0x005C31F0 );
    int __fastcall CalcLODRenderArgsSubMesh( zTRenderContext const&, zTLODRenderArgs const&, zCSubMesh const*, zTLODRenderArgsSubMesh& )       zCall( 0x005C3430 );
    int __fastcall RenderProgMesh( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer*, float, float )                            zCall( 0x005C36D0 );
    int __fastcall RenderStatic( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer* )                                            zCall( 0x005C3CA0 );
    int __fastcall RenderStaticLOD( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer* )                                         zCall( 0x005C3E80 );
    void __fastcall SoftwareTransformVerts( int, zTLODRenderArgs*, float, float )                                                              zCall( 0x005C41C0 );
    int __fastcall RenderDynamicLOD( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer*, float, float )                          zCall( 0x005C4FA0 );
    void __fastcall CalcSubdiv( int, zTLODRenderArgs const* )                                                                                  zCall( 0x005C5870 );
    void __fastcall CalcNumSubdivEdges( zCSubMesh*, zTLODRenderArgs const*, zTLODRenderArgsSubMesh& )                                          zCall( 0x005C5930 );
    void __fastcall CalcSubdivSubMesh( zCSubMesh*, zCVertexBuffer*, zTLODRenderArgs const*, zCRenderLightContainer*, zTLODRenderArgsSubMesh& ) zCall( 0x005C5990 );
    int __fastcall RenderDynamicSubdiv( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer*, float, float )                       zCall( 0x005C5CB0 );
    int __fastcall RenderStaticLODShadow( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer* )                                   zCall( 0x005C6340 );
    static zCObject* _CreateNewInstance()                                                                                                      zCall( 0x005C0A30 );
    static void SetLODParamStrengthModifier( float )                                                                                           zCall( 0x005C1230 );
    static float GetLODParamStrengthModifier()                                                                                                 zCall( 0x005C1290 );
    static zCVisual* Load_novt( zSTRING const& )                                                                                               zCall( 0x005C1600 );
    static int BuildProgMeshProto( zCMesh*, zCProgMeshProto*, zCArray<int>*, int )                                                             zCall( 0x005C1FD0 );
    static void InitProgMeshProto()                                                                                                            zCall( 0x005C2DF0 );
    static int CreateDynamicVertexBuffer()                                                                                                     zCall( 0x005C2F70 );
    static void CleanupProgMeshProto()                                                                                                         zCall( 0x005C2FD0 );
    static unsigned short GetFileVersion()                                                                                                     zCall( 0x005C6E50 );
    static void SetLODParamStrength( float )                                                                                                   zCall( 0x0062FA40 );
    virtual zCClassDef* _GetClassDef() const                                                                                                   zCall( 0x005C10C0 );
    virtual ~zCProgMeshProto()                                                                                                                 zCall( 0x005C1100 );
    virtual int Render( zTRenderContext& )                                                                                                     zCall( 0x005C34C0 );
    virtual int IsBBox3DLocal()                                                                                                                zCall( 0x005C0D40 );
    virtual zTBBox3D GetBBox3D()                                                                                                               zCall( 0x005C0D50 );
    virtual zCOBBox3D* GetOBBox3D()                                                                                                            zCall( 0x005C0D80 );
    virtual zSTRING GetVisualName()                                                                                                            zCall( 0x005C15B0 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* )                                                                         zCall( 0x005C0D90 );
    virtual unsigned long GetRenderSortKey() const                                                                                             zCall( 0x005C0DA0 );
    virtual int CanTraceRay() const                                                                                                            zCall( 0x005C0DB0 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& )                                                                 zCall( 0x005C25E0 );
    virtual zSTRING const* GetFileExtension( int )                                                                                             zCall( 0x005C1580 );
    virtual int GetAlphaTestingEnabled() const                                                                                                 zCall( 0x005C0DC0 );
    virtual void SetAlphaTestingEnabled( int )                                                                                                 zCall( 0x005C0DD0 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                                                                                zCall( 0x005C15A0 );
    virtual int Save( zCFileBIN& )                                                                                                             zCall( 0x005C6E60 );
    virtual int Load( zCFileBIN& )                                                                                                             zCall( 0x005C72C0 );

    // static properties
    static int& s_frameCtr;
    static unsigned short int*& s_wedgeRemap;
    static zVEC3*& s_posCacheList;
    static zVEC3*& s_posNormalCSList;
    static zCArray<unsigned short>& s_workIndexList;
    static int& s_subMeshRenderDir;
    static zCVertexBufferDyn*& s_vertBufferColor;
    static zCVertexBufferDyn*& s_vertBufferNormal;
    static float& s_lodParamStrengthOverride;
    static float& s_lodParamStrengthModifier;
    static int& s_markMeshMaterials;
    static int& s_autoSubdivEnabled;
    static unsigned long& s_classCtorCtr;

    // user API
    #include "zCProgMeshProto.inl"
  };

  class zCProgMeshBuilder {
  public:

    zCProgMeshBuilder() {}
    void CreatePMTriPosList()                                                               zCall( 0x005BB3B0 );
    void CalcPrelight( zTLazyMesh&, zTLazyMesh& )                                           zCall( 0x005BBB40 );
    void CalcPosNormals( zTLazyMesh& )                                                      zCall( 0x005BBCE0 );
    void CalcTriPlaneList( zTLazyMesh const&, zTLazyMesh& )                                 zCall( 0x005BBE30 );
    void CalcSubdivData( zTLazyMesh const&, zTLazyMesh& )                                   zCall( 0x005BC340 );
    void CreateLazySubMesh( int, zTLazyMesh&, zTLazyMesh& )                                 zCall( 0x005BC8E0 );
    void CopySubMeshData( unsigned char*&, zTLazyMesh const&, zCProgMeshProto::zCSubMesh* ) zCall( 0x005BCDD0 );
    void CreateFinalPMData( int )                                                           zCall( 0x005BCFE0 );
    void Clear()                                                                            zCall( 0x005BE0E0 );
    int BuildProgMeshProto( zCMesh*, zCProgMeshProto*, zCArray<int>*, int )                 zCall( 0x005BE2D0 );

    // user API
    #include "zCProgMeshBuilder.inl"
  };

  class zCMeshSoftSkin : public zCProgMeshProto {
  public:
    zCLASS_DECLARATION( zCMeshSoftSkin )

#pragma pack( push, 1 )
    struct zTWeightEntry {
      float weight;
      zVEC3 vertPosOS;
      unsigned char nodeIndex;

      void zTWeightEntry_OnInit() zCall( 0x00588690 );
      zTWeightEntry()             zInit( zTWeightEntry_OnInit() );

      // user API
      #include "zCMeshSoftSkin_zTWeightEntry.inl"
    };
#pragma pack( pop )

    struct zTNodeWedgeNormal {
      zVEC3 normal;
      int nodeIndex;

      zTNodeWedgeNormal() {}

      // user API
      #include "zCMeshSoftSkin_zTNodeWedgeNormal.inl"
    };

    zCArray<int> nodeIndexList;
    zCArray<zCOBBox3D*> nodeOBBList;
    zCArray<zTNodeWedgeNormal> nodeWedgeNormalList;
    unsigned char* vertWeightStream;
    unsigned char* iterator;

    void zCMeshSoftSkin_OnInit()                                                                              zCall( 0x005C7C20 );
    zCMeshSoftSkin()                                                                                          zInit( zCMeshSoftSkin_OnInit() );
    void AllocVertWeightStream( int, int )                                                                    zCall( 0x005C7DC0 );
    void DeleteVertWeightStream()                                                                             zCall( 0x005C7E10 );
    void AddNumWeightEntry( int const& )                                                                      zCall( 0x005C7E40 );
    void AddWeightEntry( zTWeightEntry const& )                                                               zCall( 0x005C7E60 );
    void ResetVertWeightIterator()                                                                            zCall( 0x005C7EA0 );
    int GetVertWeightStreamSize()                                                                             zCall( 0x005C7EB0 );
    void BuildNodeIndexList()                                                                                 zCall( 0x005C7EF0 );
    void DeleteNodeOBBList()                                                                                  zCall( 0x005C80A0 );
    void BuildNodeOBBList()                                                                                   zCall( 0x005C8110 );
    int __fastcall RenderSoftSkin( zTRenderContext&, zCArray<zMAT4*> const&, zCRenderLightContainer*, float ) zCall( 0x005C8EF0 );
    static zCObject* _CreateNewInstance()                                                                     zCall( 0x005C0C80 );
    static unsigned short GetFileVersion()                                                                    zCall( 0x005C86B0 );
    virtual zCClassDef* _GetClassDef() const                                                                  zCall( 0x005C0DE0 );
    virtual ~zCMeshSoftSkin()                                                                                 zCall( 0x005C7CB0 );
    virtual int Save( zCFileBIN& )                                                                            zCall( 0x005C8980 );
    virtual int Load( zCFileBIN& )                                                                            zCall( 0x005C86C0 );

    // user API
    #include "zCMeshSoftSkin.inl"
  };

  class zCProgMeshConvertFileHandler : public zCScanDirFileHandler {
  public:

    void zCProgMeshConvertFileHandler_OnInit()                         zCall( 0x005C9560 );
    zCProgMeshConvertFileHandler()                                     zInit( zCProgMeshConvertFileHandler_OnInit() );
    virtual ~zCProgMeshConvertFileHandler()                            zCall( 0x00424930 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zCall( 0x005C9640 );

    // user API
    #include "zCProgMeshConvertFileHandler.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZPROG_MESH_H__VER2__