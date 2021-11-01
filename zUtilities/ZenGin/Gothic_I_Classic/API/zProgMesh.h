// Supported with union (c) 2018-2021 Union team

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

  // sizeof C0h
  struct zTLazyMesh {
    zCArray<int> wedgePermut;                      // sizeof 0Ch    offset 00h
    zCArray<int> wedgeParent;                      // sizeof 0Ch    offset 0Ch
    zCArray<unsigned short int> triMatIndexList;   // sizeof 0Ch    offset 18h
    zCArray<zVEC3> posList;                        // sizeof 0Ch    offset 24h
    zCArray<zVEC3> posNormalList;                  // sizeof 0Ch    offset 30h
    zCArray<zCMaterial*> matList;                  // sizeof 0Ch    offset 3Ch
    zCArray<zTPMTriangle> triList;                 // sizeof 0Ch    offset 48h
    zCArray<zTPMWedge> wedgeList;                  // sizeof 0Ch    offset 54h
    zCArray<float> colorList;                      // sizeof 0Ch    offset 60h
    zCArray<unsigned short int> wedgeMap;          // sizeof 0Ch    offset 6Ch
    zCArray<zTPMVertexUpdate> vertexUpdates;       // sizeof 0Ch    offset 78h
    zCArray<unsigned short int> triPlaneIndexList; // sizeof 0Ch    offset 84h
    zCArray<zTPlane> triPlaneList;                 // sizeof 0Ch    offset 90h
    zCArray<zTPMTriangleEdges> triEdgeList;        // sizeof 0Ch    offset 9Ch
    zCArray<zTPMEdge> edgeList;                    // sizeof 0Ch    offset A8h
    zCArray<float> edgeScoreList;                  // sizeof 0Ch    offset B4h

    void zTLazyMesh_OnInit() zCall( 0x005A1B00 );
    zTLazyMesh()             zInit( zTLazyMesh_OnInit() );
    ~zTLazyMesh()            zCall( 0x005A1BD0 );

    // user API
    #include "zTLazyMesh.inl"
  };

  // sizeof 18h
  struct zTPMWedge {
    zVEC3 normal;                // sizeof 0Ch    offset 00h
    zVEC2 texUV;                 // sizeof 08h    offset 0Ch
    unsigned short int position; // sizeof 02h    offset 14h

    zTPMWedge() {}

    // user API
    #include "zTPMWedge.inl"
  };

  // sizeof 06h
  struct zTPMTriangle {
    unsigned short int wedge[3]; // sizeof 06h    offset 00h

    zTPMTriangle() {}

    // user API
    #include "zTPMTriangle.inl"
  };

  // sizeof 06h
  struct zTPMTriangleEdges {
    unsigned short int edge[3]; // sizeof 06h    offset 00h

    zTPMTriangleEdges() {}

    // user API
    #include "zTPMTriangleEdges.inl"
  };

  // sizeof 04h
  struct zTPMEdge {
    unsigned short int wedge[2]; // sizeof 04h    offset 00h

    zTPMEdge() {}

    // user API
    #include "zTPMEdge.inl"
  };

  // sizeof 04h
  struct zTPMVertexUpdate {
    unsigned short int numNewTri;   // sizeof 02h    offset 00h
    unsigned short int numNewWedge; // sizeof 02h    offset 02h

    zTPMVertexUpdate() {}

    // user API
    #include "zTPMVertexUpdate.inl"
  };

  // sizeof D4h
  class zCProgMeshProto : public zCVisual {
  public:
    zCLASS_DECLARATION( zCProgMeshProto )

    // sizeof 10h
    struct zTLODRenderArgs {
      float vertPerc;     // sizeof 04h    offset 00h
      int numPos;         // sizeof 04h    offset 04h
      int numMinMorphPos; // sizeof 04h    offset 08h
      float morphFrac;    // sizeof 04h    offset 0Ch

      zTLODRenderArgs() {}

      // user API
      #include "zCProgMeshProto_zTLODRenderArgs.inl"
    };

    // sizeof 10h
    struct zTLODParams {
      float strength;   // sizeof 04h    offset 00h
      float zDisplace2; // sizeof 04h    offset 04h
      float morphPerc;  // sizeof 04h    offset 08h
      int minVerts;     // sizeof 04h    offset 0Ch

      zTLODParams() {}

      // user API
      #include "zCProgMeshProto_zTLODParams.inl"
    };

    // sizeof 58h
    class zCSubMesh {
    public:
      zCMaterial* material;                               // sizeof 04h    offset 00h
      zCArrayAdapt<zTPMTriangle> triList;                 // sizeof 08h    offset 04h
      zCArrayAdapt<zTPMWedge> wedgeList;                  // sizeof 08h    offset 0Ch
      zCArrayAdapt<float> colorList;                      // sizeof 08h    offset 14h
      zCArrayAdapt<unsigned short int> triPlaneIndexList; // sizeof 08h    offset 1Ch
      zCArrayAdapt<zTPlane> triPlaneList;                 // sizeof 08h    offset 24h
      zCArrayAdapt<zTPMTriangleEdges> triEdgeList;        // sizeof 08h    offset 2Ch
      zCArrayAdapt<zTPMEdge> edgeList;                    // sizeof 08h    offset 34h
      zCArrayAdapt<float> edgeScoreList;                  // sizeof 08h    offset 3Ch
      zCArrayAdapt<unsigned short int> wedgeMap;          // sizeof 08h    offset 44h
      zCArrayAdapt<zTPMVertexUpdate> vertexUpdates;       // sizeof 08h    offset 4Ch
      int vbStartIndex;                                   // sizeof 04h    offset 54h

      void zCSubMesh_OnInit() zCall( 0x005A4BE0 );
      zCSubMesh()             zInit( zCSubMesh_OnInit() );
      ~zCSubMesh()            zCall( 0x005A4C30 );

      // user API
      #include "zCProgMeshProto_zCSubMesh.inl"
    };

    // sizeof 10h
    struct zTLODRenderArgsSubMesh {
      int numTri;           // sizeof 04h    offset 00h
      int numWedge;         // sizeof 04h    offset 04h
      int numMinMorphWedge; // sizeof 04h    offset 08h
      int numSubdivEdges;   // sizeof 04h    offset 0Ch

      zTLODRenderArgsSubMesh() {}

      // user API
      #include "zCProgMeshProto_zTLODRenderArgsSubMesh.inl"
    };

    zCArrayAdapt<zVEC3> posList;        // sizeof 08h    offset 34h
    zCArrayAdapt<zVEC3> posNormalList;  // sizeof 08h    offset 3Ch
    zTBBox3D bbox3D;                    // sizeof 18h    offset 44h
    zCOBBox3D obbox3D;                  // sizeof 44h    offset 5Ch
    zCVertexBuffer* vertexBufferStatic; // sizeof 04h    offset A0h
    zCSubMesh* subMeshList;             // sizeof 04h    offset A4h
    int numSubMeshes;                   // sizeof 04h    offset A8h
    unsigned char* dataPool;            // sizeof 04h    offset ACh
    unsigned long dataSize;             // sizeof 04h    offset B0h
    float avgTriArea;                   // sizeof 04h    offset B4h
    zTLODParams lodParams;              // sizeof 10h    offset B8h
    zTPMLightingMode lightingMode;      // sizeof 04h    offset C8h
    unsigned long pmeshID;              // sizeof 04h    offset CCh
    unsigned long renderSortKey;        // sizeof 04h    offset D0h

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

  // sizeof 01h
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

  // sizeof 100h
  class zCMeshSoftSkin : public zCProgMeshProto {
  public:
    zCLASS_DECLARATION( zCMeshSoftSkin )

#pragma pack( push, 1 )
    // sizeof 11h
    struct zTWeightEntry {
      float weight;            // sizeof 04h    offset 00h
      zVEC3 vertPosOS;         // sizeof 0Ch    offset 04h
      unsigned char nodeIndex; // sizeof 01h    offset 10h

      void zTWeightEntry_OnInit() zCall( 0x00573470 );
      zTWeightEntry()             zInit( zTWeightEntry_OnInit() );

      // user API
      #include "zCMeshSoftSkin_zTWeightEntry.inl"
    };
#pragma pack( pop )

    // sizeof 10h
    struct zTNodeWedgeNormal {
      zVEC3 normal;  // sizeof 0Ch    offset 00h
      int nodeIndex; // sizeof 04h    offset 0Ch

      zTNodeWedgeNormal() {}

      // user API
      #include "zCMeshSoftSkin_zTNodeWedgeNormal.inl"
    };

    zCArray<int> nodeIndexList;                     // sizeof 0Ch    offset D4h
    zCArray<zCOBBox3D*> nodeOBBList;                // sizeof 0Ch    offset E0h
    zCArray<zTNodeWedgeNormal> nodeWedgeNormalList; // sizeof 0Ch    offset ECh
    unsigned char* vertWeightStream;                // sizeof 04h    offset F8h
    unsigned char* iterator;                        // sizeof 04h    offset FCh

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

  // sizeof 30h
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