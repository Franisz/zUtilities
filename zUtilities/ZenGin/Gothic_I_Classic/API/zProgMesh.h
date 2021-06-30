// Supported with union (c) 2018 Union team

#ifndef __ZPROG_MESH_H__VER0__
#define __ZPROG_MESH_H__VER0__

namespace Gothic_I_Classic {
  const int NUM_WEDGE_CACHE = 4096;
  const int NUM_POS_CACHE   = 2048;

  enum zTPMRenderFlags {
    zPM_RENDER_FLAG_SW_TRAFO_VERTS     = 1,
    zPM_RENDER_FLAG_PACK_DYNAMIC_VB    = 2,
    zPM_RENDER_FLAG_DONT_SET_TRANSFROM = 4
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

    void zTLazyMesh_OnInit() zCall( 0x005A1B00 );
    zTLazyMesh()             zInit( zTLazyMesh_OnInit() );
    ~zTLazyMesh()            zCall( 0x005A1BD0 );

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

      void zCSubMesh_OnInit() zCall( 0x005A4BE0 );
      zCSubMesh()             zInit( zCSubMesh_OnInit() );
      ~zCSubMesh()            zCall( 0x005A4C30 );

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
    zTLODParams lodParams;
    zTPMLightingMode lightingMode;
    unsigned long pmeshID;
    unsigned long renderSortKey;

    void zCProgMeshProto_OnInit()                                                                                                              zCall( 0x005A4CB0 );
    zCProgMeshProto()                                                                                                                          zInit( zCProgMeshProto_OnInit() );
    void CalcRenderSortKey()                                                                                                                   zCall( 0x005A4F20 );
    void PackStaticVertexBuffers()                                                                                                             zCall( 0x005A4FE0 );
    int __fastcall CheckRayPolyIntersection( zCSubMesh*, int, zVEC3 const&, zVEC3 const&, zVEC3&, float& ) const                               zCall( 0x005A5CE0 );
    int __fastcall CheckRayPolyIntersection2Sided( zCSubMesh*, int, zVEC3 const&, zVEC3 const&, zVEC3&, float& ) const                         zCall( 0x005A5FD0 );
    int GetNumTri() const                                                                                                                      zCall( 0x005A6470 );
    float __fastcall CalcLODRenderVertPerc( zTRenderContext const& )                                                                           zCall( 0x005A66C0 );
    int __fastcall CalcLODRenderArgs( zTRenderContext const&, zTLODRenderArgs& )                                                               zCall( 0x005A6870 );
    int __fastcall CalcLODRenderArgsSubMesh( zTRenderContext const&, zTLODRenderArgs const&, zCSubMesh const*, zTLODRenderArgsSubMesh& )       zCall( 0x005A6A90 );
    int __fastcall RenderProgMesh( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer*, float, float )                            zCall( 0x005A6B40 );
    int __fastcall RenderStatic( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer* )                                            zCall( 0x005A7110 );
    int __fastcall RenderStaticLOD( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer* )                                         zCall( 0x005A7200 );
    void __fastcall SoftwareTransformVerts( int, zTLODRenderArgs*, float, float )                                                              zCall( 0x005A7470 );
    int __fastcall RenderDynamicLOD( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer*, float, float )                          zCall( 0x005A7780 );
    void __fastcall CalcSubdiv( int, zTLODRenderArgs const* )                                                                                  zCall( 0x005A7E30 );
    void __fastcall CalcNumSubdivEdges( zCSubMesh*, zTLODRenderArgs const*, zTLODRenderArgsSubMesh& )                                          zCall( 0x005A7EF0 );
    void __fastcall CalcSubdivSubMesh( zCSubMesh*, zCVertexBuffer*, zTLODRenderArgs const*, zCRenderLightContainer*, zTLODRenderArgsSubMesh& ) zCall( 0x005A7F50 );
    int __fastcall RenderDynamicSubdiv( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer*, float, float )                       zCall( 0x005A8270 );
    int __fastcall RenderStaticLODShadow( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer* )                                   zCall( 0x005A86F0 );
    static zCObject* _CreateNewInstance()                                                                                                      zCall( 0x005A4780 );
    static void SetLODParamStrengthModifier( float )                                                                                           zCall( 0x005A4F60 );
    static float GetLODParamStrengthModifier()                                                                                                 zCall( 0x005A4FC0 );
    static zCVisual* Load_novt( zSTRING const& )                                                                                               zCall( 0x005A5280 );
    static int BuildProgMeshProto( zCMesh*, zCProgMeshProto*, zCArray<int>*, int )                                                             zCall( 0x005A5C70 );
    static void InitProgMeshProto()                                                                                                            zCall( 0x005A6490 );
    static int CreateDynamicVertexBuffer()                                                                                                     zCall( 0x005A65E0 );
    static void CleanupProgMeshProto()                                                                                                         zCall( 0x005A6650 );
    static unsigned short GetFileVersion()                                                                                                     zCall( 0x005A8AA0 );
    virtual zCClassDef* _GetClassDef() const                                                                                                   zCall( 0x005A4DF0 );
    virtual ~zCProgMeshProto()                                                                                                                 zCall( 0x005A4E30 );
    virtual int Render( zTRenderContext& )                                                                                                     zCall( 0x005A6B20 );
    virtual int IsBBox3DLocal()                                                                                                                zCall( 0x005A4AB0 );
    virtual zTBBox3D GetBBox3D()                                                                                                               zCall( 0x005A4AC0 );
    virtual zCOBBox3D* GetOBBox3D()                                                                                                            zCall( 0x005A4AF0 );
    virtual zSTRING GetVisualName()                                                                                                            zCall( 0x005A5230 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* )                                                                         zCall( 0x005A4B00 );
    virtual unsigned long GetRenderSortKey() const                                                                                             zCall( 0x005A4B10 );
    virtual int CanTraceRay() const                                                                                                            zCall( 0x005A4B20 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& )                                                                 zCall( 0x005A6290 );
    virtual zSTRING const* GetFileExtension( int )                                                                                             zCall( 0x005A5200 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                                                                                zCall( 0x005A5220 );
    virtual int Save( zCFileBIN& )                                                                                                             zCall( 0x005A8AB0 );
    virtual int Load( zCFileBIN& )                                                                                                             zCall( 0x005A8F20 );


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
    void CreatePMTriPosList()                                                               zCall( 0x0059F080 );
    void CalcPrelight( zTLazyMesh&, zTLazyMesh& )                                           zCall( 0x0059F820 );
    void CalcPosNormals( zTLazyMesh& )                                                      zCall( 0x0059F9B0 );
    void CalcTriPlaneList( zTLazyMesh const&, zTLazyMesh& )                                 zCall( 0x0059FB00 );
    void CalcSubdivData( zTLazyMesh const&, zTLazyMesh& )                                   zCall( 0x0059FF90 );
    void CreateLazySubMesh( int, zTLazyMesh&, zTLazyMesh& )                                 zCall( 0x005A0550 );
    void CopySubMeshData( unsigned char*&, zTLazyMesh const&, zCProgMeshProto::zCSubMesh* ) zCall( 0x005A0A60 );
    void CreateFinalPMData( int )                                                           zCall( 0x005A0C70 );
    void Clear()                                                                            zCall( 0x005A1DA0 );
    int BuildProgMeshProto( zCMesh*, zCProgMeshProto*, zCArray<int>*, int )                 zCall( 0x005A1F90 );

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

      void zTWeightEntry_OnInit() zCall( 0x00573470 );
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

    void zCMeshSoftSkin_OnInit()                                                                              zCall( 0x005A9750 );
    zCMeshSoftSkin()                                                                                          zInit( zCMeshSoftSkin_OnInit() );
    void AllocVertWeightStream( int, int )                                                                    zCall( 0x005A98F0 );
    void DeleteVertWeightStream()                                                                             zCall( 0x005A9950 );
    void AddNumWeightEntry( int const& )                                                                      zCall( 0x005A9980 );
    void AddWeightEntry( zTWeightEntry const& )                                                               zCall( 0x005A99A0 );
    void ResetVertWeightIterator()                                                                            zCall( 0x005A99E0 );
    int GetVertWeightStreamSize()                                                                             zCall( 0x005A99F0 );
    void BuildNodeIndexList()                                                                                 zCall( 0x005A9A30 );
    void DeleteNodeOBBList()                                                                                  zCall( 0x005A9C00 );
    void BuildNodeOBBList()                                                                                   zCall( 0x005A9C70 );
    int __fastcall RenderSoftSkin( zTRenderContext&, zCArray<zMAT4*> const&, zCRenderLightContainer*, float ) zCall( 0x005AA9F0 );
    static zCObject* _CreateNewInstance()                                                                     zCall( 0x005A49E0 );
    static unsigned short GetFileVersion()                                                                    zCall( 0x005AA210 );
    virtual zCClassDef* _GetClassDef() const                                                                  zCall( 0x005A4B30 );
    virtual ~zCMeshSoftSkin()                                                                                 zCall( 0x005A97E0 );
    virtual int Save( zCFileBIN& )                                                                            zCall( 0x005AA500 );
    virtual int Load( zCFileBIN& )                                                                            zCall( 0x005AA220 );

    // user API
    #include "zCMeshSoftSkin.inl"
  };

  class zCProgMeshConvertFileHandler : public zCScanDirFileHandler {
  public:

    void zCProgMeshConvertFileHandler_OnInit()                         zCall( 0x005AB060 );
    zCProgMeshConvertFileHandler()                                     zInit( zCProgMeshConvertFileHandler_OnInit() );
    virtual ~zCProgMeshConvertFileHandler()                            zCall( 0x004240B0 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zCall( 0x005AB140 );

    // user API
    #include "zCProgMeshConvertFileHandler.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZPROG_MESH_H__VER0__