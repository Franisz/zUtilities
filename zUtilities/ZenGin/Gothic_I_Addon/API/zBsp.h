// Supported with union (c) 2018-2021 Union team

#ifndef __ZBSP_H__VER1__
#define __ZBSP_H__VER1__

namespace Gothic_I_Addon {
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

    void zCBspBase_OnInit()                                                                   zCall( 0x0053C570 );
    void DescribeTree( int )                                                                  zCall( 0x0052E7B0 );
    int CountNodes()                                                                          zCall( 0x0052FFC0 );
    void __fastcall AddVobsToRenderListSubtree( int )                                         zCall( 0x00531D90 );
    zTBBox2D GetScreenBBox2D() const                                                          zCall( 0x00531E70 );
    void CollectNodeLights()                                                                  zCall( 0x00532130 );
    void RenderTrivInIndoor()                                                                 zCall( 0x00532480 );
    void __fastcall RenderIndoor( int )                                                       zCall( 0x005324C0 );
    void __fastcall RenderNodeOutdoor( int )                                                  zCall( 0x00532560 );
    void __fastcall AddVobToLeafs( zCVob* )                                                   zCall( 0x00533F00 );
    void __fastcall AddVobLightToLeafs( zCVobLight* )                                         zCall( 0x00534040 );
    void __fastcall RemoveVobFromLeafs( zCVob* )                                              zCall( 0x005343E0 );
    void __fastcall CollectVobsSubtree( zCArray<zCVob*>& ) const                              zCall( 0x00534590 );
    void __fastcall CollectVobsInBBox3D( zCArray<zCVob*>&, zTBBox3D const& ) const            zCall( 0x005345A0 );
    void __fastcall CollectVobsSubtree_I( zCArray<zCVob*>& ) const                            zCall( 0x005345C0 );
    void __fastcall CollectLightVobsSubtree( zCArray<zCVob*>& ) const                         zCall( 0x005347B0 );
    void __fastcall CollectLightVobsSubtree_I( zCArray<zCVob*>& ) const                       zCall( 0x005347C0 );
    void __fastcall CollectVobsInBBox3D_I( zCArray<zCVob*>&, zTBBox3D const& ) const          zCall( 0x005349B0 );
    zCBspLeaf* FindLeaf( zVEC3 const& )                                                       zCall( 0x00534E00 );
    int __fastcall CheckRayAgainstPolys( zVEC3 const&, zVEC3 const&, zVEC3& ) const           zCall( 0x00534F30 );
    int __fastcall CheckRayAgainstPolysNearestHit( zVEC3 const&, zVEC3 const&, zVEC3& ) const zCall( 0x00535090 );
    int __fastcall CheckRayAgainstPolysCache( zVEC3 const&, zVEC3 const&, zVEC3& ) const      zCall( 0x00535270 );
    int __fastcall RayIntersection( zVEC3 const&, zVEC3 const&, zVEC3& ) const                zCall( 0x00535450 );
    void CollectPolysInBBox3DRec() const                                                      zCall( 0x00535CD0 );
    int __fastcall CollectPolysInBBox3D( zTBBox3D const&, zCPolygon**&, int& ) const          zCall( 0x00535F20 );
    void SortNodePolys( zCBspTree* )                                                          zCall( 0x00536B20 );
    void SaveBINRec( zCFileBIN& )                                                             zCall( 0x0053A550 );
    void LoadBINRec( zCFileBIN& )                                                             zCall( 0x0053A650 );
    zCBspBase()                                                                               zInit( zCBspBase_OnInit() );
    static void ReleaseStaticReferences()                                                     zCall( 0x0052DAB0 );
    static void __fastcall RenderOutdoor( zCBspBase*, zTBBox3D, int, int )                    zCall( 0x00532890 );

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
    char hasLOD;                 // sizeof 01h    offset 49h

    void zCBspNode_OnInit()              zCall( 0x0052FFA0 );
    zCBspNode()                          zInit( zCBspNode_OnInit() );
    void CalcPlaneSignbits( zCBspTree* ) zCall( 0x00533EC0 );

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

    void zCBspLeaf_OnInit()                                                             zCall( 0x0052F530 );
    zCBspLeaf()                                                                         zInit( zCBspLeaf_OnInit() );
    ~zCBspLeaf()                                                                        zCall( 0x005310E0 );
    void PolyPlueckerAddRef()                                                           zCall( 0x00531340 );
    void PolyPlueckerRelease()                                                          zCall( 0x00531610 );
    void __fastcall AddVobsToRenderList( zTBBox2D* )                                    zCall( 0x00531640 );
    void AddVobsToRenderListOutdoor()                                                   zCall( 0x00531860 );
    void __fastcall AddVobsToRenderListOutdoor( zCBspSector*, zTBBox2D const& )         zCall( 0x00531BA0 );
    void __fastcall RenderLeafIndoor( int )                                             zCall( 0x005322C0 );
    void __fastcall TraceRayCollectVobs( zCArray<zCVob*>&, zTBBox3D const&, int ) const zCall( 0x00534BF0 );

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

    void zCBspTree_OnInit()                                                                                zCall( 0x0052F190 );
    zCBspTree()                                                                                            zInit( zCBspTree_OnInit() );
    ~zCBspTree()                                                                                           zCall( 0x0052F330 );
    void InitTree()                                                                                        zCall( 0x0052F450 );
    void DisposeTree()                                                                                     zCall( 0x0052F5B0 );
    zCBspBase* BuildRecursive( zCCBspNode* )                                                               zCall( 0x0052F830 );
    void Build( zCCBspTree* )                                                                              zCall( 0x0052FB30 );
    void UpdateVertexDependencies( zCVertex* )                                                             zCall( 0x00530000 );
    int CollectPolysInBBox3DAngle( zTBBox3D const&, zVEC3 const&, float, float, zCPolygon**&, int& ) const zCall( 0x005301F0 );
    void RenderLightList()                                                                                 zCall( 0x00530360 );
    void RenderVobList()                                                                                   zCall( 0x005304A0 );
    void Render()                                                                                          zCall( 0x005335A0 );
    void RemoveVob( zCVob* )                                                                               zCall( 0x005344A0 );
    void AddVob( zCVob* )                                                                                  zCall( 0x005344B0 );
    void AdjustVob( zCVob* )                                                                               zCall( 0x00534520 );
    zTBBox3D CalcLeafRealBBox3D( zVEC3 const& )                                                            zCall( 0x00534E40 );
    int TraceRay( zVEC3 const&, zVEC3 const&, int, zVEC3&, zCPolygon*&, zCArray<zCVob*>* ) const           zCall( 0x005356E0 );
    int FindLeaks( zCArray<zCPolygon*>& )                                                                  zCall( 0x00536160 );
    void MarkOccluderPolys()                                                                               zCall( 0x005364F0 );
    zSTRING const* GetSectorNameVobIsIn( zCVob const* ) const                                              zCall( 0x005377A0 );
    zCBspSector* GetBspSectorByName( zSTRING const& ) const                                                zCall( 0x0053A100 );
    void CreateBspSectors2( zCCBspTree* )                                                                  zCall( 0x0053A1B0 );
    void SaveBIN( zCFileBIN& )                                                                             zCall( 0x0053A7E0 );
    void ConnectMaterialsToSectors()                                                                       zCall( 0x0053B170 );
    int LoadBIN( zCFileBIN&, int )                                                                         zCall( 0x0053B550 );
    void CalcStaticLeafLightData()                                                                         zCall( 0x0053C5A0 );
    void PreprocessIndoorPortals( zCMesh*, zCArray<zCBuildPortal*>& )                                      zCall( 0x00544DA0 );
    void GetPolyNeighbours( zCPolygon*, zCPolygon**&, int& )                                               zCall( 0x00545120 );
    void PostprocessIndoorPortals( zCArray<zCBuildPortal*>& )                                              zCall( 0x00545200 );
    static void S_SetStaticMeshLODValue( float )                                                           zCall( 0x0052F7D0 );
    static float S_GetStaticMeshLODValue()                                                                 zCall( 0x0052F820 );
    static void SetRayCache( zCRayCache* )                                                                 zCall( 0x005358E0 );
    static unsigned short GetFileVersion()                                                                 zCall( 0x0053A540 );

    // static properties
    static int& s_showPortals;

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

  // sizeof 58h
  class zCCBspNode {
  public:
    zTPlane plane;                // sizeof 10h    offset 00h
    zCCBspNode* front;            // sizeof 04h    offset 10h
    zCCBspNode* back;             // sizeof 04h    offset 14h
    zCCBspNode* parent;           // sizeof 04h    offset 18h
    zTBBox3D bbox3D;              // sizeof 18h    offset 1Ch
    zTBBox3D bbox3DCell;          // sizeof 18h    offset 34h
    zCList2<zTPolyNode> polyList; // sizeof 08h    offset 4Ch
    int LODIter;                  // sizeof 04h    offset 54h

    zCCBspNode() {}
    void zCCBspNode_OnInit( zCCBspNode* )                                          zCall( 0x00543BB0 );
    int CheckRayAgainstPolysNearestHit( zVEC3 const&, zVEC3 const&, zVEC3& ) const zCall( 0x005358F0 );
    int RayIntersectionOctree( zVEC3 const&, zVEC3 const&, zVEC3& )                zCall( 0x00535A20 );
    int TraceRay( zVEC3 const&, zVEC3 const&, zCPolygon*&, zVEC3& )                zCall( 0x00535C60 );
    int TraceRay( zVEC3 const&, zVEC3 const&, zCPolygon*& )                        zCall( 0x00535C90 );
    void CollectPolysInBBox3DRec()                                                 zCall( 0x00535F70 );
    int CollectPolysInBBox3D( zTBBox3D const&, zCPolygon**&, int& )                zCall( 0x00536110 );
    ~zCCBspNode()                                                                  zCall( 0x0053D8E0 );
    void RemovePoly( zCPolygon* )                                                  zCall( 0x0053E850 );
    void LODGenerate( zCMesh* )                                                    zCall( 0x0053E920 );
    void LODTriangulatePortal( zCPolygon*, zCMesh*, zCArray<zCPolygon*>& )         zCall( 0x0053EF80 );
    void LODCollectLeafPolys( zCCBspNode*, zCArraySort<zCPolygon*>&, zCMesh* )     zCall( 0x0053F340 );
    int DoesNodeContainPoly( zCPolygon* )                                          zCall( 0x00540CA0 );
    int CheckPortalConsistency()                                                   zCall( 0x00540D20 );
    void SplitPortals()                                                            zCall( 0x00541420 );
    zCPortal* SplitPortalByAllPortals( zCPortal* )                                 zCall( 0x005419D0 );
    void EnumeratePortals()                                                        zCall( 0x00541C90 );
    void ClassifyPortals()                                                         zCall( 0x00541DD0 );
    void Portalize()                                                               zCall( 0x00541E60 );
    void SelectPlane( zTPlane&, zTPolyNode*&, int& )                               zCall( 0x005421C0 );
    void SelectPlaneOctree( zCCBspTree*, zTPlane&, int )                           zCall( 0x00542440 );
    int ClassifyRayToNode( zVEC3 const&, zVEC3 const& )                            zCall( 0x00542680 );
    int ClassifyPolyToNode2( zCPolygon* )                                          zCall( 0x005428A0 );
    int OutdoorKillRedundantLeafs()                                                zCall( 0x00542BF0 );
    void AddPoly( zCPolygon* )                                                     zCall( 0x00542E40 );
    void BuildTree( int )                                                          zCall( 0x00542E90 );
    zCCBspNode( zCCBspNode* a0 )                                                   zInit( zCCBspNode_OnInit( a0 ));
    void PushPolyFront( zTPolyNode* )                                              zCall( 0x00543BD0 );
    void CalcBBox3D()                                                              zCall( 0x00543C70 );
    void CalcSubtreeBBox3D()                                                       zCall( 0x00543D50 );
    void CalcSubtreeBBox3DCell()                                                   zCall( 0x00543F00 );
    int CountNodes()                                                               zCall( 0x00543FF0 );
    int CountLeafs()                                                               zCall( 0x00544020 );
    int CountPolys()                                                               zCall( 0x00544060 );
    void CountDepthRec( int, int&, int&, int& )                                    zCall( 0x00544090 );
    void CountDepth( int&, int&, int& )                                            zCall( 0x00544100 );
    void DescribeTree( int )                                                       zCall( 0x005441B0 );

    // user API
    #include "zCCBspNode.inl"
  };

  // sizeof 90h
  class zCCBspTree {
  public:
    enum zTSpanningMode {
      zSPANNING_SPLIT,
      zSPANNING_CENTER,
      zSPANNING_PUSHBOTH
    };

    zCCBspNode bspRoot;               // sizeof 58h    offset 00h
    zCMesh* mesh;                     // sizeof 04h    offset 58h
    zTBspTreeMode bspTreeMode;        // sizeof 04h    offset 5Ch
    zCArray<zCBspSector*> sectorList; // sizeof 0Ch    offset 60h
    zTSpanningMode cfg_spanningMode;  // sizeof 04h    offset 6Ch
    int cfg_useAllPolys;              // sizeof 04h    offset 70h
    int cfg_octree;                   // sizeof 04h    offset 74h
    zTBspBuildType cfg_bspType;       // sizeof 04h    offset 78h
    float cfg_optimize;               // sizeof 04h    offset 7Ch
    float cfg_wbalance;               // sizeof 04h    offset 80h
    float cfg_wsplit;                 // sizeof 04h    offset 84h
    float cfg_wplanar;                // sizeof 04h    offset 88h
    int cfg_portalize;                // sizeof 04h    offset 8Ch

    void zCCBspTree_OnInit()                                 zCall( 0x0053D820 );
    zCBspSector* GetBspSectorByName( zSTRING const& ) const  zCall( 0x005376F0 );
    void GetPolyNeighbours( zCPolygon*, zCPolygon**&, int& ) zCall( 0x005377C0 );
    void MarkGhostOccluder()                                 zCall( 0x005378C0 );
    void CreateBspSectors()                                  zCall( 0x00537A80 );
    zCCBspTree()                                             zInit( zCCBspTree_OnInit() );
    void SetBspTreeMode( zTBspTreeMode const& )              zCall( 0x0053D950 );
    ~zCCBspTree()                                            zCall( 0x0053D9E0 );
    void DeleteTree()                                        zCall( 0x0053DAB0 );
    void AddMesh( zCMesh* )                                  zCall( 0x0053DC00 );
    void AddMesh( zCMesh*, zMAT4 const& )                    zCall( 0x0053DC30 );
    void BuildTree( float )                                  zCall( 0x0053DF60 );

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
    void CalcCenterByPortals()                                         zCall( 0x0052DDB0 );
    int IsRendered() const                                             zCall( 0x0052DE50 );
    void Rendered()                                                    zCall( 0x0052DE70 );
    int IsActivated() const                                            zCall( 0x0052DE80 );
    void Activate()                                                    zCall( 0x0052DEA0 );
    int HasManyBigPortals() const                                      zCall( 0x0052DF80 );
    ~zCBspSector()                                                     zCall( 0x0052F720 );
    void RenderSector()                                                zCall( 0x00536B70 );
    void ActivateSectorRec( zTBBox2D const&, zCBspSector*, int )       zCall( 0x00536CB0 );
    void ActivateSectorRecIndoor( zTBBox2D const&, zCBspSector*, int ) zCall( 0x005371D0 );
    static int CompareOutdoorPortalBBox2D( void const*, void const* )  zCall( 0x0052DBB0 );
    static void InitHorizonByOutdoorPortals()                          zCall( 0x0052DBF0 );
    static void RenderActiveSectorList()                               zCall( 0x005376C0 );

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

    void zCBuildPortal_OnInit() zCall( 0x00544C90 );
    zCBuildPortal()             zInit( zCBuildPortal_OnInit() );
    ~zCBuildPortal()            zCall( 0x00544D10 );

    // user API
    #include "zCBuildPortal.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZBSP_H__VER1__