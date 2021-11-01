// Supported with union (c) 2018-2021 Union team

#ifndef __ZBSP_H__VER2__
#define __ZBSP_H__VER2__

namespace Gothic_II_Classic {
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

  // sizeof 28h
  class zCBspBase {
  public:
    zCBspNode* parent;      // sizeof 04h    offset 00h
    zTBBox3D bbox3D;        // sizeof 18h    offset 04h
    zCPolygon** polyList;   // sizeof 04h    offset 1Ch
    int numPolys;           // sizeof 04h    offset 20h
    zTBspNodeType nodeType; // sizeof 04h    offset 24h

    zCBspBase() {}
    void DescribeTree( int )                                                                  zCall( 0x00526C20 );
    int CountNodes()                                                                          zCall( 0x00529C70 );
    void __fastcall AddVobsToRenderListSubtree( int )                                         zCall( 0x0052BAF0 );
    zTBBox2D GetScreenBBox2D() const                                                          zCall( 0x0052BBC0 );
    void CollectNodeLights()                                                                  zCall( 0x0052BE30 );
    void RenderTrivInIndoor()                                                                 zCall( 0x0052C150 );
    void __fastcall RenderIndoor( int )                                                       zCall( 0x0052C190 );
    void __fastcall RenderNodeOutdoor( int )                                                  zCall( 0x0052C230 );
    void __fastcall AddVobToLeafs( zCVob* )                                                   zCall( 0x0052DBA0 );
    void __fastcall AddVobLightToLeafs( zCVobLight* )                                         zCall( 0x0052DCE0 );
    void __fastcall RemoveVobFromLeafs( zCVob* )                                              zCall( 0x0052DFF0 );
    void __fastcall CollectVobsSubtree( zCArray<zCVob*>& ) const                              zCall( 0x0052E190 );
    void __fastcall CollectVobsInBBox3D( zCArray<zCVob*>&, zTBBox3D const& ) const            zCall( 0x0052E1A0 );
    void __fastcall CollectVobsSubtree_I( zCArray<zCVob*>& ) const                            zCall( 0x0052E1B0 );
    void __fastcall CollectLightVobsSubtree( zCArray<zCVob*>& ) const                         zCall( 0x0052E390 );
    void __fastcall CollectLightVobsSubtree_I( zCArray<zCVob*>& ) const                       zCall( 0x0052E3A0 );
    void __fastcall CollectVobsInBBox3D_I( zCArray<zCVob*>&, zTBBox3D const& ) const          zCall( 0x0052E580 );
    zCBspLeaf* FindLeaf( zVEC3 const& )                                                       zCall( 0x0052E9C0 );
    int __fastcall CheckRayAgainstPolys( zVEC3 const&, zVEC3 const&, zVEC3& ) const           zCall( 0x0052EB30 );
    int __fastcall CheckRayAgainstPolysNearestHit( zVEC3 const&, zVEC3 const&, zVEC3& ) const zCall( 0x0052EC60 );
    int __fastcall CheckRayAgainstPolysCache( zVEC3 const&, zVEC3 const&, zVEC3& ) const      zCall( 0x0052EE10 );
    int __fastcall RayIntersection( zVEC3 const&, zVEC3 const&, zVEC3& ) const                zCall( 0x0052EFC0 );
    void CollectPolysInBBox3DRec() const                                                      zCall( 0x0052F920 );
    int __fastcall CollectPolysInBBox3D( zTBBox3D const&, zCPolygon**&, int& ) const          zCall( 0x0052FB50 );
    void SortNodePolys( zCBspTree* )                                                          zCall( 0x00531160 );
    void SaveBINRec( zCFileBIN& )                                                             zCall( 0x00534A40 );
    void LoadBINRec( zCFileBIN& )                                                             zCall( 0x00534B30 );
    static void ReleaseStaticReferences()                                                     zCall( 0x005261E0 );
    static void __fastcall RenderOutdoor( zCBspBase*, zTBBox3D, int, int )                    zCall( 0x0052C540 );

    // user API
    #include "zCBspBase.inl"
  };

  // sizeof 4Ch
  class zCBspNode : public zCBspBase {
  public:
    zTPlane plane;               // sizeof 10h    offset 28h
    zCBspBase* front;            // sizeof 04h    offset 38h
    zCBspBase* back;             // sizeof 04h    offset 3Ch
    zCBspLeaf* leafList;         // sizeof 04h    offset 40h
    int numLeafs;                // sizeof 04h    offset 44h
    unsigned char planeSignbits; // sizeof 01h    offset 48h

    void zCBspNode_OnInit()              zCall( 0x00529750 );
    zCBspNode()                          zInit( zCBspNode_OnInit() );
    void CalcPlaneSignbits( zCBspTree* ) zCall( 0x0052DB60 );

    // user API
    #include "zCBspNode.inl"
  };

  // sizeof 5Ch
  class zCBspLeaf : public zCBspBase {
  public:

    int lastTimeLighted;               // sizeof 04h    offset 28h
    zCArray<zCVob*> leafVobList;       // sizeof 0Ch    offset 2Ch
    zCArray<zCVobLight*> lightVobList; // sizeof 0Ch    offset 38h
    int lastTimeActivated;             // sizeof 04h    offset 44h
    unsigned short sectorIndex;        // sizeof 02h    offset 48h
    unsigned short polyPlueckerRefCtr; // sizeof 02h    offset 4Ah
    zCPluecker* polyPluecker;          // sizeof 04h    offset 4Ch
    zVEC3 lightPosition;               // sizeof 0Ch    offset 50h

    void zCBspLeaf_OnInit()                                                             zCall( 0x00528DE0 );
    zCBspLeaf()                                                                         zInit( zCBspLeaf_OnInit() );
    ~zCBspLeaf()                                                                        zCall( 0x0052AE10 );
    void PolyPlueckerAddRef()                                                           zCall( 0x0052B060 );
    void PolyPlueckerRelease()                                                          zCall( 0x0052B350 );
    void __fastcall AddVobsToRenderList( zTBBox2D* )                                    zCall( 0x0052B380 );
    void AddVobsToRenderListOutdoor()                                                   zCall( 0x0052B580 );
    void __fastcall AddVobsToRenderListOutdoor( zCBspSector*, zTBBox2D const& )         zCall( 0x0052B8F0 );
    void __fastcall RenderLeafIndoor( int )                                             zCall( 0x0052C0A0 );
    void __fastcall TraceRayCollectVobs( zCArray<zCVob*>&, zTBBox3D const&, int ) const zCall( 0x0052E7B0 );

    // user API
    #include "zCBspLeaf.inl"
  };

  // sizeof 90h
  class zCBspTree {
  public:
    zCBspNode* actNodePtr;                // sizeof 04h    offset 00h
    zCBspLeaf* actLeafPtr;                // sizeof 04h    offset 04h
    zCBspBase* bspRoot;                   // sizeof 04h    offset 08h
    zCMesh* mesh;                         // sizeof 04h    offset 0Ch
    zCPolygon** treePolyList;             // sizeof 04h    offset 10h
    zCBspNode* nodeList;                  // sizeof 04h    offset 14h
    zCBspLeaf* leafList;                  // sizeof 04h    offset 18h
    int numNodes;                         // sizeof 04h    offset 1Ch
    int numLeafs;                         // sizeof 04h    offset 20h
    int numPolys;                         // sizeof 04h    offset 24h
    zCArray<zCVob*> renderVobList;        // sizeof 0Ch    offset 28h
    zCArray<zCVobLight*> renderLightList; // sizeof 0Ch    offset 34h
    zCArray<zCBspSector*> sectorList;     // sizeof 0Ch    offset 40h
    zCArray<zCPolygon*> portalList;       // sizeof 0Ch    offset 4Ch
    zTBspTreeMode bspTreeMode;            // sizeof 04h    offset 58h
    zTWld_RenderMode worldRenderMode;     // sizeof 04h    offset 5Ch
    float vobFarClipZ;                    // sizeof 04h    offset 60h
    zTPlane vobFarPlane;                  // sizeof 10h    offset 64h
    int vobFarPlaneSignbits;              // sizeof 04h    offset 74h
    int drawVobBBox3D;                    // sizeof 04h    offset 78h
    int leafsRendered;                    // sizeof 04h    offset 7Ch
    int vobsRendered;                     // sizeof 04h    offset 80h
    int masterFrameCtr;                   // sizeof 04h    offset 84h
    zCPolygon** actPolyPtr;               // sizeof 04h    offset 88h
    int compiled;                         // sizeof 04h    offset 8Ch

    void zCBspTree_OnInit()                                                                                zCall( 0x00528B80 );
    zCBspTree()                                                                                            zInit( zCBspTree_OnInit() );
    ~zCBspTree()                                                                                           zCall( 0x00528BF0 );
    void InitTree()                                                                                        zCall( 0x00528D10 );
    void DisposeTree()                                                                                     zCall( 0x00528E60 );
    zCBspBase* BuildRecursive( zCCBspNode* )                                                               zCall( 0x00529060 );
    void Build( zCCBspTree* )                                                                              zCall( 0x00529340 );
    void OptimizeLight()                                                                                   zCall( 0x00529770 );
    void UpdateVertexDependencies( zCVertex* )                                                             zCall( 0x00529CB0 );
    int CollectPolysInBBox3DAngle( zTBBox3D const&, zVEC3 const&, float, float, zCPolygon**&, int& ) const zCall( 0x00529EC0 );
    void RenderLightList()                                                                                 zCall( 0x0052A030 );
    void RenderVobList()                                                                                   zCall( 0x0052A150 );
    void Render()                                                                                          zCall( 0x0052D130 );
    void RemoveVob( zCVob* )                                                                               zCall( 0x0052E0C0 );
    void AddVob( zCVob* )                                                                                  zCall( 0x0052E0D0 );
    void AdjustVob( zCVob* )                                                                               zCall( 0x0052E130 );
    zTBBox3D CalcLeafRealBBox3D( zVEC3 const& )                                                            zCall( 0x0052EA20 );
    int TraceRay( zVEC3 const&, zVEC3 const&, int, zVEC3&, zCPolygon*&, zCArray<zCVob*>* ) const           zCall( 0x0052F230 );
    int FindLeaks( zCArray<zCPolygon*>& )                                                                  zCall( 0x0052FD80 );
    void MarkOccluderPolys()                                                                               zCall( 0x005300D0 );
    float GetOccluderAreaRec( zCPolygon const*, zCArray<zCPolygon*>& )                                     zCall( 0x00530EB0 );
    zSTRING const* GetSectorNameVobIsIn( zCVob const* ) const                                              zCall( 0x00531E20 );
    zCBspSector* GetBspSectorByName( zSTRING const& ) const                                                zCall( 0x00534600 );
    void CreateBspSectors2( zCCBspTree* )                                                                  zCall( 0x005346B0 );
    void SaveBIN( zCFileBIN& )                                                                             zCall( 0x00534CB0 );
    void ConnectMaterialsToSectors()                                                                       zCall( 0x00535740 );
    int LoadBIN( zCFileBIN&, int )                                                                         zCall( 0x00535AB0 );
    void CalcStaticLeafLightData()                                                                         zCall( 0x005369C0 );
    void PreprocessIndoorPortals( zCMesh*, zCArray<zCBuildPortal*>& )                                      zCall( 0x0053CCE0 );
    void GetPolyNeighbours( zCPolygon*, zCPolygon**&, int& )                                               zCall( 0x0053D090 );
    void PostprocessIndoorPortals( zCArray<zCBuildPortal*>& )                                              zCall( 0x0053D140 );
    static void SetRayCache( zCRayCache* )                                                                 zCall( 0x0052F470 );
    static unsigned short GetFileVersion()                                                                 zCall( 0x00534A30 );
    static int GetShowPortals()                                                                            zCall( 0x0062F950 );
    static void SetShowPortals( int )                                                                      zCall( 0x0062F960 );

    // static properties
    static int& s_showPortals;
    static int& s_renderAllPortals;

    // user API
    #include "zCBspTree.inl"
  };

  // sizeof 10h
  class zTPolyNode {
  public:
    zCPolygon* poly;       // sizeof 04h    offset 00h
    zTPolyNode* next;      // sizeof 04h    offset 04h
    int marked;            // sizeof 04h    offset 08h
    char isCompleteInside; // sizeof 01h    offset 0Ch

    zTPolyNode() {}

    // user API
    #include "zTPolyNode.inl"
  };

  // sizeof 54h
  class zCCBspNode {
  public:
    zTPlane plane;                // sizeof 10h    offset 00h
    zCCBspNode* front;            // sizeof 04h    offset 10h
    zCCBspNode* back;             // sizeof 04h    offset 14h
    zCCBspNode* parent;           // sizeof 04h    offset 18h
    zTBBox3D bbox3D;              // sizeof 18h    offset 1Ch
    zTBBox3D bbox3DCell;          // sizeof 18h    offset 34h
    zCList2<zTPolyNode> polyList; // sizeof 08h    offset 4Ch

    zCCBspNode() {}
    void zCCBspNode_OnInit( zCCBspNode* )                                          zCall( 0x0053BD50 );
    int CheckRayAgainstPolysNearestHit( zVEC3 const&, zVEC3 const&, zVEC3& ) const zCall( 0x0052F480 );
    int RayIntersectionOctree( zVEC3 const&, zVEC3 const&, zVEC3& )                zCall( 0x0052F5A0 );
    int TraceRay( zVEC3 const&, zVEC3 const&, zCPolygon*&, zVEC3& )                zCall( 0x0052F8B0 );
    int TraceRay( zVEC3 const&, zVEC3 const&, zCPolygon*& )                        zCall( 0x0052F8E0 );
    void CollectPolysInBBox3DRec()                                                 zCall( 0x0052FBA0 );
    int CollectPolysInBBox3D( zTBBox3D const&, zCPolygon**&, int& )                zCall( 0x0052FD30 );
    ~zCCBspNode()                                                                  zCall( 0x00537E90 );
    void RemovePoly( zCPolygon* )                                                  zCall( 0x00538E40 );
    int DoesNodeContainPoly( zCPolygon* )                                          zCall( 0x00538F20 );
    int CheckPortalConsistency()                                                   zCall( 0x00538FF0 );
    void SplitPortals()                                                            zCall( 0x00539760 );
    zCPortal* SplitPortalByAllPortals( zCPortal* )                                 zCall( 0x00539C70 );
    void EnumeratePortals()                                                        zCall( 0x00539F00 );
    void ClassifyPortals()                                                         zCall( 0x0053A030 );
    void Portalize()                                                               zCall( 0x0053A0C0 );
    void SelectPlane( zTPlane&, zTPolyNode*&, int& )                               zCall( 0x0053A4B0 );
    void SelectPlaneOctree( zCCBspTree*, zTPlane&, int )                           zCall( 0x0053A700 );
    int ClassifyRayToNode( zVEC3 const&, zVEC3 const& )                            zCall( 0x0053A920 );
    int ClassifyPolyToNode2( zCPolygon* )                                          zCall( 0x0053ABE0 );
    int OutdoorKillRedundantLeafs()                                                zCall( 0x0053AE50 );
    void AddPoly( zCPolygon* )                                                     zCall( 0x0053B0A0 );
    void BuildTree( int )                                                          zCall( 0x0053B0E0 );
    zCCBspNode( zCCBspNode* a0 )                                                   zInit( zCCBspNode_OnInit( a0 ));
    void PushPolyFront( zTPolyNode* )                                              zCall( 0x0053BD70 );
    void CalcBBox3D()                                                              zCall( 0x0053BE00 );
    void CalcSubtreeBBox3D()                                                       zCall( 0x0053BF00 );
    void CalcSubtreeBBox3DCell()                                                   zCall( 0x0053C0F0 );
    int CountNodes()                                                               zCall( 0x0053C1E0 );
    int CountLeafs()                                                               zCall( 0x0053C210 );
    int CountPolys()                                                               zCall( 0x0053C250 );
    void CountDepthRec( int, int&, int&, int& )                                    zCall( 0x0053C280 );
    void CountDepth( int&, int&, int& )                                            zCall( 0x0053C2F0 );
    void DescribeTree( int )                                                       zCall( 0x0053C3A0 );

    // user API
    #include "zCCBspNode.inl"
  };

  // sizeof 8Ch
  class zCCBspTree {
  public:
    enum zTSpanningMode {
      zSPANNING_SPLIT,
      zSPANNING_CENTER,
      zSPANNING_PUSHBOTH
    };

    zCCBspNode bspRoot;               // sizeof 54h    offset 00h
    zCMesh* mesh;                     // sizeof 04h    offset 54h
    zTBspTreeMode bspTreeMode;        // sizeof 04h    offset 58h
    zCArray<zCBspSector*> sectorList; // sizeof 0Ch    offset 5Ch
    zTSpanningMode cfg_spanningMode;  // sizeof 04h    offset 68h
    int cfg_useAllPolys;              // sizeof 04h    offset 6Ch
    int cfg_octree;                   // sizeof 04h    offset 70h
    zTBspBuildType cfg_bspType;       // sizeof 04h    offset 74h
    float cfg_optimize;               // sizeof 04h    offset 78h
    float cfg_wbalance;               // sizeof 04h    offset 7Ch
    float cfg_wsplit;                 // sizeof 04h    offset 80h
    float cfg_wplanar;                // sizeof 04h    offset 84h
    int cfg_portalize;                // sizeof 04h    offset 88h

    void zCCBspTree_OnInit()                                 zCall( 0x00537DE0 );
    zCBspSector* GetBspSectorByName( zSTRING const& ) const  zCall( 0x00531D70 );
    void GetPolyNeighbours( zCPolygon*, zCPolygon**&, int& ) zCall( 0x00531E40 );
    void MarkGhostOccluder()                                 zCall( 0x00531F20 );
    void CreateBspSectors()                                  zCall( 0x00532150 );
    zCCBspTree()                                             zInit( zCCBspTree_OnInit() );
    void SetBspTreeMode( zTBspTreeMode const& )              zCall( 0x00537F00 );
    ~zCCBspTree()                                            zCall( 0x00537F80 );
    void DeleteTree()                                        zCall( 0x00538060 );
    void AddMesh( zCMesh* )                                  zCall( 0x005381B0 );
    void AddMesh( zCMesh*, zMAT4 const& )                    zCall( 0x005381E0 );
    void BuildTree( float )                                  zCall( 0x005384E0 );

    // user API
    #include "zCCBspTree.inl"
  };

  // sizeof 64h
  class zCBspSector {
  public:
    // sizeof 02h
    struct zTPortalInfo {
      unsigned char visible; // sizeof 01h    offset 00h
      unsigned char alpha;   // sizeof 01h    offset 01h

      zTPortalInfo() {}

      // user API
      #include "zCBspSector_zTPortalInfo.inl"
    };

    zSTRING sectorName;                     // sizeof 14h    offset 00h
    zCArray<zCBspBase*> sectorNodes;        // sizeof 0Ch    offset 14h
    unsigned long sectorIndex;              // sizeof 04h    offset 20h
    zCArray<zCPolygon*> sectorPortals;      // sizeof 0Ch    offset 24h
    zCArray<zTPortalInfo> sectorPortalInfo; // sizeof 0Ch    offset 30h
    int activated;                          // sizeof 04h    offset 3Ch
    int rendered;                           // sizeof 04h    offset 40h
    zTBBox2D activePortal;                  // sizeof 10h    offset 44h
    zVEC3 sectorCenter;                     // sizeof 0Ch    offset 54h
    char hasBigNoFade;                      // sizeof 01h    offset 60h

    zCBspSector() {}
    void CalcCenterByPortals()                                         zCall( 0x005264C0 );
    int HasManyBigPortals() const                                      zCall( 0x00526560 );
    ~zCBspSector()                                                     zCall( 0x00528FC0 );
    void RenderSector()                                                zCall( 0x005311B0 );
    void ActivateSectorRec( zTBBox2D const&, zCBspSector*, int )       zCall( 0x00531280 );
    void ActivateSectorRecIndoor( zTBBox2D const&, zCBspSector*, int ) zCall( 0x00531810 );
    static int CompareOutdoorPortalBBox2D( void const*, void const* )  zCall( 0x005262E0 );
    static void InitHorizonByOutdoorPortals()                          zCall( 0x00526320 );
    static void RenderActiveSectorList()                               zCall( 0x00531D30 );

    // static properties
    static int& s_sectorsRendered;
    static int& s_startPointOutdoor;
    static int& s_outdoorPortal;
    static zCArray<zCBspSector*>& s_activeSectorList;
    static zCArray<zTBBox2D>& s_activeOutdoorPortals;

    // user API
    #include "zCBspSector.inl"
  };

  // sizeof 4Ch
  class zCBuildPortal {
  public:
    zCPolygon* portalPoly;                   // sizeof 04h    offset 00h
    zCPolygon* portalPolyBack;               // sizeof 04h    offset 04h
    zCArray<zCPolygon*> borderPolyList;      // sizeof 0Ch    offset 08h
    zCArray<zCPolygon*> polyBucket[2];       // sizeof 18h    offset 14h
    zCArray<zCBuildPortal*> portalBucket[2]; // sizeof 18h    offset 2Ch
    zCBspSector* sector[2];                  // sizeof 08h    offset 44h

    void zCBuildPortal_OnInit() zCall( 0x0053CBD0 );
    zCBuildPortal()             zInit( zCBuildPortal_OnInit() );
    ~zCBuildPortal()            zCall( 0x0053CC50 );

    // user API
    #include "zCBuildPortal.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZBSP_H__VER2__