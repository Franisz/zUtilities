// Supported with union (c) 2018 Union team

#ifndef __ZBSP_H__VER0__
#define __ZBSP_H__VER0__

namespace Gothic_I_Classic {
  const int zBSP_LEAF_LIGHT_UNDEFINED = -99;

  enum zTBspPolyCont {
    zBSP_CONT_NOTHING = 0,
    zBSP_CONT_MESH    = -1,
    zBSP_CONT_BSP     = -2
  };

  enum zTBspNodeType {
    zBSP_LEAF = 1,
    zBSP_NODE = 0
  };

  enum zTBspTreeMode {
    zBSP_MODE_INDOOR,
    zBSP_MODE_OUTDOOR
  };

  enum zTBspBuildType {
    zBSP_TYPE_OCTREE,
    zBSP_TYPE_OCTREE_SOLID,
    zBSP_TYPE_LEAFY_BSP
  };

  class zCBspBase {
  public:
    zCBspNode* parent;
    zTBBox3D bbox3D;
    zCPolygon** polyList;
    int numPolys;
    zTBspNodeType nodeType;

    void zCBspBase_OnInit()                                                                   zCall( 0x00526200 );
    void DescribeTree( int )                                                                  zCall( 0x00518C50 );
    int CountNodes()                                                                          zCall( 0x0051A320 );
    void __fastcall AddVobsToRenderListSubtree( int )                                         zCall( 0x0051C0F0 );
    zTBBox2D GetScreenBBox2D() const                                                          zCall( 0x0051C1C0 );
    void CollectNodeLights()                                                                  zCall( 0x0051C430 );
    void RenderTrivInIndoor()                                                                 zCall( 0x0051C780 );
    void __fastcall RenderIndoor( int )                                                       zCall( 0x0051C7C0 );
    void __fastcall RenderNodeOutdoor( int )                                                  zCall( 0x0051C860 );
    void __fastcall AddVobToLeafs( zCVob* )                                                   zCall( 0x0051E1C0 );
    void __fastcall AddVobLightToLeafs( zCVobLight* )                                         zCall( 0x0051E300 );
    void __fastcall RemoveVobFromLeafs( zCVob* )                                              zCall( 0x0051E610 );
    void __fastcall CollectVobsSubtree( zCArray<zCVob*>& ) const                              zCall( 0x0051E7B0 );
    void __fastcall CollectVobsInBBox3D( zCArray<zCVob*>&, zTBBox3D const& ) const            zCall( 0x0051E7C0 );
    void __fastcall CollectVobsSubtree_I( zCArray<zCVob*>& ) const                            zCall( 0x0051E7D0 );
    void __fastcall CollectLightVobsSubtree( zCArray<zCVob*>& ) const                         zCall( 0x0051E9D0 );
    void __fastcall CollectLightVobsSubtree_I( zCArray<zCVob*>& ) const                       zCall( 0x0051E9E0 );
    void __fastcall CollectVobsInBBox3D_I( zCArray<zCVob*>&, zTBBox3D const& ) const          zCall( 0x0051EBE0 );
    zCBspLeaf* FindLeaf( zVEC3 const& )                                                       zCall( 0x0051F050 );
    int __fastcall CheckRayAgainstPolys( zVEC3 const&, zVEC3 const&, zVEC3& ) const           zCall( 0x0051F180 );
    int __fastcall CheckRayAgainstPolysNearestHit( zVEC3 const&, zVEC3 const&, zVEC3& ) const zCall( 0x0051F2A0 );
    int __fastcall CheckRayAgainstPolysCache( zVEC3 const&, zVEC3 const&, zVEC3& ) const      zCall( 0x0051F440 );
    int __fastcall RayIntersection( zVEC3 const&, zVEC3 const&, zVEC3& ) const                zCall( 0x0051F5E0 );
    void CollectPolysInBBox3DRec() const                                                      zCall( 0x0051FE70 );
    int __fastcall CollectPolysInBBox3D( zTBBox3D const&, zCPolygon**&, int& ) const          zCall( 0x005200C0 );
    void SortNodePolys( zCBspTree* )                                                          zCall( 0x00520C00 );
    void SaveBINRec( zCFileBIN& )                                                             zCall( 0x00524230 );
    void LoadBINRec( zCFileBIN& )                                                             zCall( 0x00524330 );
    zCBspBase()                                                                               zInit( zCBspBase_OnInit() );
    static void ReleaseStaticReferences()                                                     zCall( 0x00518090 );
    static void __fastcall RenderOutdoor( zCBspBase*, zTBBox3D, int, int )                    zCall( 0x0051CBA0 );

    // user API
    #include "zCBspBase.inl"
  };

  class zCBspNode : public zCBspBase {
  public:
    zTPlane plane;
    zCBspBase* front;
    zCBspBase* back;
    zCBspLeaf* leafList;
    int numLeafs;
    unsigned char planeSignbits;
    char hasLOD;

    void zCBspNode_OnInit()              zCall( 0x0051A300 );
    zCBspNode()                          zInit( zCBspNode_OnInit() );
    void CalcPlaneSignbits( zCBspTree* ) zCall( 0x0051E180 );

    // user API
    #include "zCBspNode.inl"
  };

  class zCBspLeaf : public zCBspBase {
  public:

    int lastTimeLighted;
    zCArray<zCVob*> leafVobList;
    zCArray<zCVobLight*> lightVobList;
    int lastTimeActivated;
    unsigned short sectorIndex;
    unsigned short polyPlueckerRefCtr;
    zCPluecker* polyPluecker;
    zVEC3 lightPosition;

    void zCBspLeaf_OnInit()                                                             zCall( 0x005198F0 );
    zCBspLeaf()                                                                         zInit( zCBspLeaf_OnInit() );
    ~zCBspLeaf()                                                                        zCall( 0x0051B490 );
    void PolyPlueckerAddRef()                                                           zCall( 0x0051B6E0 );
    void PolyPlueckerRelease()                                                          zCall( 0x0051B960 );
    void __fastcall AddVobsToRenderList( zTBBox2D* )                                    zCall( 0x0051B990 );
    void AddVobsToRenderListOutdoor()                                                   zCall( 0x0051BBA0 );
    void __fastcall AddVobsToRenderListOutdoor( zCBspSector*, zTBBox2D const& )         zCall( 0x0051BEF0 );
    void __fastcall RenderLeafIndoor( int )                                             zCall( 0x0051C5C0 );
    void __fastcall TraceRayCollectVobs( zCArray<zCVob*>&, zTBBox3D const&, int ) const zCall( 0x0051EE30 );

    // user API
    #include "zCBspLeaf.inl"
  };

  class zCBspTree {
  public:
    zCBspNode* actNodePtr;
    zCBspLeaf* actLeafPtr;
    zCBspBase* bspRoot;
    zCMesh* mesh;
    zCPolygon** treePolyList;
    zCBspNode* nodeList;
    zCBspLeaf* leafList;
    int numNodes;
    int numLeafs;
    int numPolys;
    zCArray<zCVob*> renderVobList;
    zCArray<zCVobLight*> renderLightList;
    zCArray<zCBspSector*> sectorList;
    zCArray<zCPolygon*> portalList;
    zTBspTreeMode bspTreeMode;
    zTWld_RenderMode worldRenderMode;
    float vobFarClipZ;
    zTPlane vobFarPlane;
    int vobFarPlaneSignbits;
    int drawVobBBox3D;
    int leafsRendered;
    int vobsRendered;
    int masterFrameCtr;
    zCPolygon** actPolyPtr;
    int compiled;

    void zCBspTree_OnInit()                                                                                zCall( 0x00519560 );
    zCBspTree()                                                                                            zInit( zCBspTree_OnInit() );
    ~zCBspTree()                                                                                           zCall( 0x005196F0 );
    void InitTree()                                                                                        zCall( 0x00519810 );
    void DisposeTree()                                                                                     zCall( 0x00519970 );
    zCBspBase* BuildRecursive( zCCBspNode* )                                                               zCall( 0x00519BD0 );
    void Build( zCCBspTree* )                                                                              zCall( 0x00519EB0 );
    void UpdateVertexDependencies( zCVertex* )                                                             zCall( 0x0051A360 );
    int CollectPolysInBBox3DAngle( zTBBox3D const&, zVEC3 const&, float, float, zCPolygon**&, int& ) const zCall( 0x0051A530 );
    void RenderLightList()                                                                                 zCall( 0x0051A6A0 );
    void RenderVobList()                                                                                   zCall( 0x0051A7E0 );
    void Render()                                                                                          zCall( 0x0051D840 );
    void RemoveVob( zCVob* )                                                                               zCall( 0x0051E6E0 );
    void AddVob( zCVob* )                                                                                  zCall( 0x0051E6F0 );
    void AdjustVob( zCVob* )                                                                               zCall( 0x0051E750 );
    zTBBox3D CalcLeafRealBBox3D( zVEC3 const& )                                                            zCall( 0x0051F090 );
    int TraceRay( zVEC3 const&, zVEC3 const&, int, zVEC3&, zCPolygon*&, zCArray<zCVob*>* ) const           zCall( 0x0051F850 );
    int FindLeaks( zCArray<zCPolygon*>& )                                                                  zCall( 0x00520310 );
    void MarkOccluderPolys()                                                                               zCall( 0x00520640 );
    zSTRING const* GetSectorNameVobIsIn( zCVob const* ) const                                              zCall( 0x00521920 );
    zCBspSector* GetBspSectorByName( zSTRING const& ) const                                                zCall( 0x00523DF0 );
    void CreateBspSectors2( zCCBspTree* )                                                                  zCall( 0x00523EA0 );
    void SaveBIN( zCFileBIN& )                                                                             zCall( 0x005244C0 );
    void ConnectMaterialsToSectors()                                                                       zCall( 0x00524FC0 );
    int LoadBIN( zCFileBIN&, int )                                                                         zCall( 0x00525330 );
    void CalcStaticLeafLightData()                                                                         zCall( 0x00526230 );
    void PreprocessIndoorPortals( zCMesh*, zCArray<zCBuildPortal*>& )                                      zCall( 0x0052E430 );
    void GetPolyNeighbours( zCPolygon*, zCPolygon**&, int& )                                               zCall( 0x0052E790 );
    void PostprocessIndoorPortals( zCArray<zCBuildPortal*>& )                                              zCall( 0x0052E840 );
    static void S_SetStaticMeshLODValue( float )                                                           zCall( 0x00519B70 );
    static float S_GetStaticMeshLODValue()                                                                 zCall( 0x00519BC0 );
    static void SetRayCache( zCRayCache* )                                                                 zCall( 0x0051FA50 );
    static unsigned short GetFileVersion()                                                                 zCall( 0x00524220 );

    // static properties
    static int& s_showPortals;

    // user API
    #include "zCBspTree.inl"
  };

  class zTPolyNode {
  public:
    zCPolygon* poly;
    zTPolyNode* next;
    int marked;
    char isCompleteInside;

    zTPolyNode() {}

    // user API
    #include "zTPolyNode.inl"
  };

  class zCCBspNode {
  public:
    zTPlane plane;
    zCCBspNode* front;
    zCCBspNode* back;
    zCCBspNode* parent;
    zTBBox3D bbox3D;
    zTBBox3D bbox3DCell;
    zCList2<zTPolyNode> polyList;
    int LODIter;

    zCCBspNode() {}
    void zCCBspNode_OnInit( zCCBspNode* )                                          zCall( 0x0052D330 );
    int CheckRayAgainstPolysNearestHit( zVEC3 const&, zVEC3 const&, zVEC3& ) const zCall( 0x0051FA60 );
    int RayIntersectionOctree( zVEC3 const&, zVEC3 const&, zVEC3& )                zCall( 0x0051FB80 );
    int TraceRay( zVEC3 const&, zVEC3 const&, zCPolygon*&, zVEC3& )                zCall( 0x0051FE00 );
    int TraceRay( zVEC3 const&, zVEC3 const&, zCPolygon*& )                        zCall( 0x0051FE30 );
    void CollectPolysInBBox3DRec()                                                 zCall( 0x00520110 );
    int CollectPolysInBBox3D( zTBBox3D const&, zCPolygon**&, int& )                zCall( 0x005202C0 );
    ~zCCBspNode()                                                                  zCall( 0x005274D0 );
    void RemovePoly( zCPolygon* )                                                  zCall( 0x005282C0 );
    void LODGenerate( zCMesh* )                                                    zCall( 0x005283A0 );
    void LODTriangulatePortal( zCPolygon*, zCMesh*, zCArray<zCPolygon*>& )         zCall( 0x00528970 );
    void LODCollectLeafPolys( zCCBspNode*, zCArraySort<zCPolygon*>&, zCMesh* )     zCall( 0x00528CF0 );
    int DoesNodeContainPoly( zCPolygon* )                                          zCall( 0x0052A610 );
    int CheckPortalConsistency()                                                   zCall( 0x0052A690 );
    void SplitPortals()                                                            zCall( 0x0052ADC0 );
    zCPortal* SplitPortalByAllPortals( zCPortal* )                                 zCall( 0x0052B350 );
    void EnumeratePortals()                                                        zCall( 0x0052B600 );
    void ClassifyPortals()                                                         zCall( 0x0052B760 );
    void Portalize()                                                               zCall( 0x0052B7F0 );
    void SelectPlane( zTPlane&, zTPolyNode*&, int& )                               zCall( 0x0052BAE0 );
    void SelectPlaneOctree( zCCBspTree*, zTPlane&, int )                           zCall( 0x0052BD40 );
    int ClassifyRayToNode( zVEC3 const&, zVEC3 const& )                            zCall( 0x0052BF60 );
    int ClassifyPolyToNode2( zCPolygon* )                                          zCall( 0x0052C1A0 );
    int OutdoorKillRedundantLeafs()                                                zCall( 0x0052C410 );
    void AddPoly( zCPolygon* )                                                     zCall( 0x0052C660 );
    void BuildTree( int )                                                          zCall( 0x0052C6B0 );
    zCCBspNode( zCCBspNode* a0 )                                                   zInit( zCCBspNode_OnInit( a0 ));
    void PushPolyFront( zTPolyNode* )                                              zCall( 0x0052D350 );
    void CalcBBox3D()                                                              zCall( 0x0052D3F0 );
    void CalcSubtreeBBox3D()                                                       zCall( 0x0052D4D0 );
    void CalcSubtreeBBox3DCell()                                                   zCall( 0x0052D680 );
    int CountNodes()                                                               zCall( 0x0052D770 );
    int CountLeafs()                                                               zCall( 0x0052D7A0 );
    int CountPolys()                                                               zCall( 0x0052D7E0 );
    void CountDepthRec( int, int&, int&, int& )                                    zCall( 0x0052D810 );
    void CountDepth( int&, int&, int& )                                            zCall( 0x0052D880 );
    void DescribeTree( int )                                                       zCall( 0x0052D930 );

    // user API
    #include "zCCBspNode.inl"
  };

  class zCCBspTree {
  public:
    enum zTSpanningMode {
      zSPANNING_SPLIT,
      zSPANNING_CENTER,
      zSPANNING_PUSHBOTH
    };

    zCCBspNode bspRoot;
    zCMesh* mesh;
    zTBspTreeMode bspTreeMode;
    zCArray<zCBspSector*> sectorList;
    zTSpanningMode cfg_spanningMode;
    int cfg_useAllPolys;
    int cfg_octree;
    zTBspBuildType cfg_bspType;
    float cfg_optimize;
    float cfg_wbalance;
    float cfg_wsplit;
    float cfg_wplanar;
    int cfg_portalize;

    void zCCBspTree_OnInit()                                 zCall( 0x00527410 );
    zCBspSector* GetBspSectorByName( zSTRING const& ) const  zCall( 0x00521870 );
    void GetPolyNeighbours( zCPolygon*, zCPolygon**&, int& ) zCall( 0x00521940 );
    void MarkGhostOccluder()                                 zCall( 0x00521A20 );
    void CreateBspSectors()                                  zCall( 0x00521BD0 );
    zCCBspTree()                                             zInit( zCCBspTree_OnInit() );
    void SetBspTreeMode( zTBspTreeMode const& )              zCall( 0x00527540 );
    ~zCCBspTree()                                            zCall( 0x005275C0 );
    void DeleteTree()                                        zCall( 0x005276A0 );
    void AddMesh( zCMesh* )                                  zCall( 0x005277F0 );
    void AddMesh( zCMesh*, zMAT4 const& )                    zCall( 0x00527820 );
    void BuildTree( float )                                  zCall( 0x00527B00 );

    // user API
    #include "zCCBspTree.inl"
  };

  class zCBspSector {
  public:
    struct zTPortalInfo {
      unsigned char visible;
      unsigned char alpha;

      zTPortalInfo() {}

      // user API
      #include "zCBspSector_zTPortalInfo.inl"
    };

    zSTRING sectorName;
    zCArray<zCBspBase*> sectorNodes;
    unsigned long sectorIndex;
    zCArray<zCPolygon*> sectorPortals;
    zCArray<zTPortalInfo> sectorPortalInfo;
    int activated;
    int rendered;
    zTBBox2D activePortal;
    zVEC3 sectorCenter;
    char hasBigNoFade;

    zCBspSector() {}
    void CalcCenterByPortals()                                         zCall( 0x00518380 );
    int IsRendered() const                                             zCall( 0x00518420 );
    void Rendered()                                                    zCall( 0x00518440 );
    int IsActivated() const                                            zCall( 0x00518450 );
    void Activate()                                                    zCall( 0x00518470 );
    int HasManyBigPortals() const                                      zCall( 0x00518550 );
    ~zCBspSector()                                                     zCall( 0x00519AD0 );
    void RenderSector()                                                zCall( 0x00520C50 );
    void ActivateSectorRec( zTBBox2D const&, zCBspSector*, int )       zCall( 0x00520D90 );
    void ActivateSectorRecIndoor( zTBBox2D const&, zCBspSector*, int ) zCall( 0x00521310 );
    static int CompareOutdoorPortalBBox2D( void const*, void const* )  zCall( 0x00518190 );
    static void InitHorizonByOutdoorPortals()                          zCall( 0x005181D0 );
    static void RenderActiveSectorList()                               zCall( 0x00521830 );

    // static properties
    static int& s_sectorsRendered;
    static int& s_startPointOutdoor;
    static int& s_outdoorPortal;
    static zCArray<zCBspSector*>& s_activeSectorList;
    static zCArray<zTBBox2D>& s_activeOutdoorPortals;

    // user API
    #include "zCBspSector.inl"
  };

  class zCBuildPortal {
  public:
    zCPolygon* portalPoly;
    zCPolygon* portalPolyBack;
    zCArray<zCPolygon*> borderPolyList;
    zCArray<zCPolygon*> polyBucket[2];
    zCArray<zCBuildPortal*> portalBucket[2];
    zCBspSector* sector[2];

    void zCBuildPortal_OnInit() zCall( 0x0052E320 );
    zCBuildPortal()             zInit( zCBuildPortal_OnInit() );
    ~zCBuildPortal()            zCall( 0x0052E3A0 );

    // user API
    #include "zCBuildPortal.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZBSP_H__VER0__