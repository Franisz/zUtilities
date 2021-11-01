// Supported with union (c) 2018-2021 Union team

#ifndef __ZPROG_MESH_H__VER3__
#define __ZPROG_MESH_H__VER3__

#include "zVisual.h"
#include "zRenderer.h"
#include "zScanDir.h"

namespace Gothic_II_Addon {
  const int NUM_WEDGE_CACHE = 4096;
  const int NUM_POS_CACHE   = 2048;
  const int NUM_LOD_CACHE   = 4096;

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

    void zTLazyMesh_OnInit() zCall( 0x005C39B0 );
    zTLazyMesh()             zInit( zTLazyMesh_OnInit() );
    ~zTLazyMesh()            zCall( 0x005C3A80 );

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

  // sizeof D8h
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

      void zCSubMesh_OnInit() zCall( 0x005C6A20 );
      zCSubMesh()             zInit( zCSubMesh_OnInit() );
      ~zCSubMesh()            zCall( 0x005C6A70 );

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
    int m_bUsesAlphaTesting;            // sizeof 04h    offset B8h
    zTLODParams lodParams;              // sizeof 10h    offset BCh
    zTPMLightingMode lightingMode;      // sizeof 04h    offset CCh
    unsigned long pmeshID;              // sizeof 04h    offset D0h
    unsigned long renderSortKey;        // sizeof 04h    offset D4h

    void zCProgMeshProto_OnInit()                                                                                                              zCall( 0x005C6AF0 );
    zCProgMeshProto()                                                                                                                          zInit( zCProgMeshProto_OnInit() );
    void CalcRenderSortKey()                                                                                                                   zCall( 0x005C6D70 );
    void PackStaticVertexBuffers()                                                                                                             zCall( 0x005C6E30 );
    int __fastcall CheckRayPolyIntersection( zCSubMesh*, int, zVEC3 const&, zVEC3 const&, zVEC3&, float& ) const                               zCall( 0x005C7BF0 );
    int __fastcall CheckRayPolyIntersection2Sided( zCSubMesh*, int, zVEC3 const&, zVEC3 const&, zVEC3&, float& ) const                         zCall( 0x005C7EE0 );
    int GetNumTri() const                                                                                                                      zCall( 0x005C8380 );
    zCPolygon* GetPolygon( int )                                                                                                               zCall( 0x005C83A0 );
    zCMesh* GetMesh( int )                                                                                                                     zCall( 0x005C8530 );
    int GetLowestLODNumPolys()                                                                                                                 zCall( 0x005C89B0 );
    zVEC3* GetLowestLODPoly( int, zVEC3*& )                                                                                                    zCall( 0x005C89D0 );
    float __fastcall CalcLODRenderVertPerc( zTRenderContext const& )                                                                           zCall( 0x005C8DF0 );
    int __fastcall CalcLODRenderArgs( zTRenderContext const&, zTLODRenderArgs& )                                                               zCall( 0x005C8FA0 );
    int __fastcall CalcLODRenderArgsMin( zTRenderContext const&, zTLODRenderArgs& )                                                            zCall( 0x005C91E0 );
    int __fastcall CalcLODRenderArgsSubMesh( zTRenderContext const&, zTLODRenderArgs const&, zCSubMesh const*, zTLODRenderArgsSubMesh& )       zCall( 0x005C93E0 );
    int __fastcall RenderProgMesh( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer*, float, float )                            zCall( 0x005C9680 );
    int __fastcall RenderStatic( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer* )                                            zCall( 0x005C9C50 );
    int __fastcall RenderStaticLOD( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer* )                                         zCall( 0x005C9E30 );
    void __fastcall SoftwareTransformVerts( int, zTLODRenderArgs*, float, float )                                                              zCall( 0x005CA170 );
    int __fastcall RenderDynamicLOD( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer*, float, float )                          zCall( 0x005CAF50 );
    void __fastcall CalcSubdiv( int, zTLODRenderArgs const* )                                                                                  zCall( 0x005CB820 );
    void __fastcall CalcNumSubdivEdges( zCSubMesh*, zTLODRenderArgs const*, zTLODRenderArgsSubMesh& )                                          zCall( 0x005CB8E0 );
    void __fastcall CalcSubdivSubMesh( zCSubMesh*, zCVertexBuffer*, zTLODRenderArgs const*, zCRenderLightContainer*, zTLODRenderArgsSubMesh& ) zCall( 0x005CB940 );
    int __fastcall RenderDynamicSubdiv( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer*, float, float )                       zCall( 0x005CBC60 );
    int __fastcall RenderStaticLODShadow( zTRenderContext&, int, zTLODRenderArgs*, zCRenderLightContainer* )                                   zCall( 0x005CC2F0 );
    static zCObject* _CreateNewInstance()                                                                                                      zCall( 0x005C65A0 );
    static void SetLODParamStrengthModifier( float )                                                                                           zCall( 0x005C6DB0 );
    static float GetLODParamStrengthModifier()                                                                                                 zCall( 0x005C6E10 );
    static zCVisual* Load_novt( zSTRING const& )                                                                                               zCall( 0x005C7180 );
    static int BuildProgMeshProto( zCMesh*, zCProgMeshProto*, zCArray<int>*, int )                                                             zCall( 0x005C7B90 );
    static void InitProgMeshProto()                                                                                                            zCall( 0x005C8BA0 );
    static int CreateDynamicVertexBuffer()                                                                                                     zCall( 0x005C8D20 );
    static void CleanupProgMeshProto()                                                                                                         zCall( 0x005C8D80 );
    static unsigned short GetFileVersion()                                                                                                     zCall( 0x005CCE00 );
    static void InitSetupLowestLOD()                                                                                                           zCall( 0x005CF510 );
    static void SetLODParamStrength( float )                                                                                                   zCall( 0x006370E0 );
    virtual zCClassDef* _GetClassDef() const                                                                                                   zCall( 0x005C6C40 );
    virtual ~zCProgMeshProto()                                                                                                                 zCall( 0x005C6C80 );
    virtual int Render( zTRenderContext& )                                                                                                     zCall( 0x005C9470 );
    virtual int IsBBox3DLocal()                                                                                                                zCall( 0x005C68B0 );
    virtual zTBBox3D GetBBox3D()                                                                                                               zCall( 0x005C68C0 );
    virtual zCOBBox3D* GetOBBox3D()                                                                                                            zCall( 0x005C68F0 );
    virtual zSTRING GetVisualName()                                                                                                            zCall( 0x005C7130 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* )                                                                         zCall( 0x005C6900 );
    virtual unsigned long GetRenderSortKey() const                                                                                             zCall( 0x005C6910 );
    virtual int CanTraceRay() const                                                                                                            zCall( 0x005C6920 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& )                                                                 zCall( 0x005C81A0 );
    virtual zSTRING const* GetFileExtension( int )                                                                                             zCall( 0x005C7100 );
    virtual int GetAlphaTestingEnabled() const                                                                                                 zCall( 0x005C6930 );
    virtual void SetAlphaTestingEnabled( int )                                                                                                 zCall( 0x005C6940 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                                                                                zCall( 0x005C7120 );
    virtual int Load( zCFileBIN& )                                                                                                             zCall( 0x005CD270 );
    virtual int Save( zCFileBIN& )                                                                                                             zCall( 0x005CCE10 );

    // static properties
    static int& s_frameCtr;
    static unsigned short int*& s_wedgeRemap;
    static zVEC3*& s_posCacheList;
    static zVEC3*& s_posNormalCSList;
    static zCArray<unsigned short>& s_workIndexList;
    static int& s_subMeshRenderDir;
    static zVEC3*& s_posCacheListLOD;
    static int*& s_posCacheListLODIndices;
    static int& s_posCacheCount;
    static int& s_posCacheCountLOD;
    static int& s_posCacheIndex;
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
    void CreatePMTriPosList()                                                               zCall( 0x005C0F20 );
    void CalcPrelight( zTLazyMesh&, zTLazyMesh& )                                           zCall( 0x005C16B0 );
    void CalcPosNormals( zTLazyMesh& )                                                      zCall( 0x005C1850 );
    void CalcTriPlaneList( zTLazyMesh const&, zTLazyMesh& )                                 zCall( 0x005C19A0 );
    void CalcSubdivData( zTLazyMesh const&, zTLazyMesh& )                                   zCall( 0x005C1EB0 );
    void CreateLazySubMesh( int, zTLazyMesh&, zTLazyMesh& )                                 zCall( 0x005C2450 );
    void CopySubMeshData( unsigned char*&, zTLazyMesh const&, zCProgMeshProto::zCSubMesh* ) zCall( 0x005C2940 );
    void CreateFinalPMData( int )                                                           zCall( 0x005C2B50 );
    void Clear()                                                                            zCall( 0x005C3C50 );
    int BuildProgMeshProto( zCMesh*, zCProgMeshProto*, zCArray<int>*, int )                 zCall( 0x005C3E40 );

    // user API
    #include "zCProgMeshBuilder.inl"
  };

  // sizeof 104h
  class zCMeshSoftSkin : public zCProgMeshProto {
  public:
    zCLASS_DECLARATION( zCMeshSoftSkin )

#pragma pack( push, 1 )
    // sizeof 11h
    struct zTWeightEntry {
      float weight;            // sizeof 04h    offset 00h
      zVEC3 vertPosOS;         // sizeof 0Ch    offset 04h
      unsigned char nodeIndex; // sizeof 01h    offset 10h

      void zTWeightEntry_OnInit() zCall( 0x0058DBF0 );
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

    zCArray<int> nodeIndexList;                     // sizeof 0Ch    offset D8h
    zCArray<zCOBBox3D*> nodeOBBList;                // sizeof 0Ch    offset E4h
    zCArray<zTNodeWedgeNormal> nodeWedgeNormalList; // sizeof 0Ch    offset F0h
    unsigned char* vertWeightStream;                // sizeof 04h    offset FCh
    unsigned char* iterator;                        // sizeof 04h    offset 100h

    void zCMeshSoftSkin_OnInit()                                                                              zCall( 0x005CDBD0 );
    zCMeshSoftSkin()                                                                                          zInit( zCMeshSoftSkin_OnInit() );
    void AllocVertWeightStream( int, int )                                                                    zCall( 0x005CDD70 );
    void DeleteVertWeightStream()                                                                             zCall( 0x005CDDC0 );
    void AddNumWeightEntry( int const& )                                                                      zCall( 0x005CDDF0 );
    void AddWeightEntry( zTWeightEntry const& )                                                               zCall( 0x005CDE10 );
    void ResetVertWeightIterator()                                                                            zCall( 0x005CDE50 );
    int GetVertWeightStreamSize()                                                                             zCall( 0x005CDE60 );
    void BuildNodeIndexList()                                                                                 zCall( 0x005CDEA0 );
    void DeleteNodeOBBList()                                                                                  zCall( 0x005CE050 );
    void BuildNodeOBBList()                                                                                   zCall( 0x005CE0C0 );
    int __fastcall RenderSoftSkin( zTRenderContext&, zCArray<zMAT4*> const&, zCRenderLightContainer*, float ) zCall( 0x005CEEA0 );
    void __fastcall SetupLowestLOD( zTRenderContext&, zCArray<zMAT4*> const&, float, int& )                   zCall( 0x005CF530 );
    int GetLowestLODNumPolys()                                                                                zCall( 0x005CFFC0 );
    zVEC3* GetLowestLODPoly( int, zVEC3*& )                                                                   zCall( 0x005CFFD0 );
    static zCObject* _CreateNewInstance()                                                                     zCall( 0x005C67F0 );
    static unsigned short GetFileVersion()                                                                    zCall( 0x005CE660 );
    virtual zCClassDef* _GetClassDef() const                                                                  zCall( 0x005C6950 );
    virtual ~zCMeshSoftSkin()                                                                                 zCall( 0x005CDC60 );
    virtual int Load( zCFileBIN& )                                                                            zCall( 0x005CE670 );
    virtual int Save( zCFileBIN& )                                                                            zCall( 0x005CE930 );

    // user API
    #include "zCMeshSoftSkin.inl"
  };

  // sizeof 30h
  class zCProgMeshConvertFileHandler : public zCScanDirFileHandler {
  public:

    void zCProgMeshConvertFileHandler_OnInit()                         zCall( 0x005D0100 );
    zCProgMeshConvertFileHandler()                                     zInit( zCProgMeshConvertFileHandler_OnInit() );
    virtual ~zCProgMeshConvertFileHandler()                            zCall( 0x00424C60 );
    virtual int HandleFile( zSTRING const&, char const*, _finddata_t ) zCall( 0x005D01E0 );

    // user API
    #include "zCProgMeshConvertFileHandler.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZPROG_MESH_H__VER3__