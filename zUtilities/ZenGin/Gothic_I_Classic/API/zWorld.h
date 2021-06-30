// Supported with union (c) 2018 Union team

#ifndef __ZWORLD_H__VER0__
#define __ZWORLD_H__VER0__

namespace Gothic_I_Classic {
  const int zNUM_VOB_HASH = 2048;

  enum zTTraceRayFlags {
    zTRACERAY_VOB_IGNORE_NO_CD_DYN    = 1 << 0,
    zTRACERAY_VOB_IGNORE              = 1 << 1,
    zTRACERAY_VOB_BBOX                = 1 << 2,
    zTRACERAY_VOB_OBB                 = 1 << 3,
    zTRACERAY_STAT_IGNORE             = 1 << 4,
    zTRACERAY_STAT_POLY               = 1 << 5,
    zTRACERAY_STAT_PORTALS            = 1 << 6,
    zTRACERAY_POLY_NORMAL             = 1 << 7,
    zTRACERAY_POLY_IGNORE_TRANSP      = 1 << 8,
    zTRACERAY_POLY_TEST_WATER         = 1 << 9,
    zTRACERAY_POLY_2SIDED             = 1 << 10,
    zTRACERAY_VOB_IGNORE_CHARACTER    = 1 << 11,
    zTRACERAY_FIRSTHIT                = 1 << 12,
    zTRACERAY_VOB_TEST_HELPER_VISUALS = 1 << 13
  };

  enum zTWld_RenderMode {
    zWLD_RENDER_MODE_VERT_LIGHT,
    zWLD_RENDER_MODE_LIGHTMAPS
  };

  class zCCallback {
  public:

    zCCallback() {}

    // user API
    #include "zCCallback.inl"
  };

  class zCVobCallback : public zCCallback {
  public:

    zCVobCallback() {}
    virtual void HandleVob( zCVob*, void* ) zPureCall;

    // user API
    #include "zCVobCallback.inl"
  };

  class zCWorldPerFrameCallback : public zCCallback {
  public:
    
    virtual void DoWorldPerFrameCallback( zCWorld*, zCCamera* ) zPureCall;
    zCWorldPerFrameCallback() {}

    // user API
    #include "zCWorldPerFrameCallback.inl"
  };

  struct zTTraceRayReport {
    int foundHit;
    zCVob* foundVob;
    zCPolygon* foundPoly;
    zVEC3 foundIntersection;
    zVEC3 foundPolyNormal;
    zCVertex* foundVertex;

    zTTraceRayReport() {}

    // user API
    #include "zTTraceRayReport.inl"
  };

  class zCTransferConstr {
  public:
    zCPatch* targetPatch;
    float formFactor;

    zCTransferConstr() {}

    // user API
    #include "zCTransferConstr.inl"
  };
  
#pragma pack( push, 1 )

  class zCTransfer {
  public:
    zCPatch* targetPatch;
    unsigned short formFactor;

    zCTransfer() {}

    // user API
    #include "zCTransfer.inl"
  };
  
#pragma pack( pop )

  class zCPatch {
  public:
    zVEC3 center;
    zVEC3 centerLight;
    zVEC3 normal;
    float area;
    zVEC3 radiosity;
    zVEC3 radToShoot;
    short xpos;
    short ypos;
    zCArray<zCTransfer> transferList;
    zVEC3 reflectivity;

    zCPatch() {}
    void DoTransfers() zCall( 0x006000D0 );

    // user API
    #include "zCPatch.inl"
  };
    
#pragma pack( push, 1 )

  class zCPatchMap {
  public:
    char hit;
    short xdim;
    short ydim;
    zCArray<zCPatch*> patchList;
    zCArray<zCPolygon*> surface;
    zTPlane lightRejectPlane0;
    zTPlane lightRejectPlane1;
    zTBBox3D bbox3D;
    zVEC3 lightmapOrigin;
    zVEC3 lightmapUp;
    zVEC3 lightmapRight;
    zCPolygon* lastRayHitPoly;

    zCPatchMap() {}
    int CheckRaySurfaceIntersection( zVEC3&, zVEC3&, zVEC3&, zCPolygon*& ) zCall( 0x005FD520 );
    ~zCPatchMap()                                                          zCall( 0x005FF8F0 );

    // user API
    #include "zCPatchMap.inl"
  };
    
#pragma pack( pop )

  class zCWorld : public zCObject {
  public:
    zCLASS_DECLARATION( zCWorld )

    enum zTWorldLoadMode {
      zWLD_LOAD_GAME_STARTUP,
      zWLD_LOAD_GAME_SAVED_DYN,
      zWLD_LOAD_GAME_SAVED_STAT,
      zWLD_LOAD_EDITOR_COMPILED,
      zWLD_LOAD_EDITOR_UNCOMPILED,
      zWLD_LOAD_MERGE
    };

    enum zTWorldSaveMode {
      zWLD_SAVE_GAME_SAVED_DYN,
      zWLD_SAVE_EDITOR_COMPILED,
      zWLD_SAVE_EDITOR_UNCOMPILED,
      zWLD_SAVE_COMPILED_ONLY
    };

    enum zTWorldLoadMergeMode {
      zWLD_LOAD_MERGE_ADD,
      zWLD_LOAD_MERGE_REPLACE_ROOT_VISUAL
    };

    enum zTStaticWorldLightMode {
      zWLD_LIGHT_VERTLIGHT_ONLY,
      zWLD_LIGHT_VERTLIGHT_LIGHTMAPS_LOW_QUAL,
      zWLD_LIGHT_VERTLIGHT_LIGHTMAPS_MID_QUAL,
      zWLD_LIGHT_VERTLIGHT_LIGHTMAPS_HI_QUAL
    };

    zCTree<zCVob> globalVobTree;
    zTTraceRayReport traceRayReport;
    zCSession* ownerSession;
    zCCSPlayer* csPlayer;
    int compiled;
    int compiledEditorMode;
    int traceRayIgnoreVobFlag;
    zTWld_RenderMode worldRenderMode;
    zCWayNet* wayNet;
    int masterFrameCtr;
    float vobFarClipZ;
    float vobFarClipZScalability;
    zCArray<zCVob*> traceRayVobList;
    zCArray<zCVob*> traceRayTempIgnoreVobList;
    int renderingFirstTime;
    int showWaynet;
    int showTraceRayLines;
    int showTextureStats;
    zCViewProgressBar* progressBar;
    unsigned long unarchiveFileLen;
    unsigned long unarchiveStartPosVobtree;
    int numVobsInWorld;
    zCArray<zCWorldPerFrameCallback*> perFrameCallbackList;
    zCSkyControler* skyControlerIndoor;
    zCSkyControler* skyControlerOutdoor;
    zCSkyControler* activeSkyControler;
    zCArray<zCZone*> zoneGlobalList;
    zCArraySort<zCZone*> zoneActiveList;
    zCArraySort<zCZone*> zoneLastClassList;
    zCVobBBox3DSorter<zCZone> zoneBoxSorter;
    zCVobBBox3DSorter<zCZone>::zTBoxSortHandle zoneActiveHandle;
    int addZonesToWorld;
    int showZonesDebugInfo;
    zCCBspTree* cbspTree;
    zCBspTree bspTree;
    zCArray<zCVob*> activeVobList;
    zCArray<zCVob*> walkList;
    zCArray<zCVob*> vobHashTable[zNUM_VOB_HASH];

    void zCWorld_OnInit()                                                                                          zCall( 0x005F2410 );
    zCWorld()                                                                                                      zInit( zCWorld_OnInit() );
    zCSkyControler* GetActiveSkyControler()                                                                        zCall( 0x005F2C80 );
    void SetSkyControlerIndoor( zCSkyControler* )                                                                  zCall( 0x005F2CB0 );
    void SetSkyControlerOutdoor( zCSkyControler* )                                                                 zCall( 0x005F2CF0 );
    void AddZone( zCZone* )                                                                                        zCall( 0x005F2DA0 );
    void RemoveZone( zCZone* )                                                                                     zCall( 0x005F2F30 );
    void RemoveAllZones()                                                                                          zCall( 0x005F3070 );
    void UpdateZone( zCZone* )                                                                                     zCall( 0x005F30E0 );
    void ProcessZones()                                                                                            zCall( 0x005F30F0 );
    void ShowZonesDebugInfo()                                                                                      zCall( 0x005F3700 );
    void ShowTextureStats()                                                                                        zCall( 0x005F3AE0 );
    void Render( zCCamera& )                                                                                       zCall( 0x005F3EC0 );
    int __fastcall TraceRayFirstHit( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int )                     zCall( 0x005F40C0 );
    int __fastcall TraceRayNearestHit( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int )                   zCall( 0x005F42C0 );
    int __fastcall TraceRayFirstHit( zVEC3 const&, zVEC3 const&, zCVob*, int )                                     zCall( 0x005F4590 );
    int __fastcall TraceRayNearestHit( zVEC3 const&, zVEC3 const&, zCVob*, int )                                   zCall( 0x005F46E0 );
    int __fastcall TraceRayFirstHitCache( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int, zCRayCache* )   zCall( 0x005F4830 );
    int __fastcall TraceRayFirstHitCache( zVEC3 const&, zVEC3 const&, zCVob*, int, zCRayCache* )                   zCall( 0x005F48F0 );
    int __fastcall TraceRayNearestHitCache( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int, zCRayCache* ) zCall( 0x005F4A10 );
    int __fastcall TraceRayNearestHitCache( zVEC3 const&, zVEC3 const&, zCVob*, int, zCRayCache* )                 zCall( 0x005F4AD0 );
    int __fastcall PickScene( zCCamera&, int, int, float )                                                         zCall( 0x005F4BF0 );
    int TraverseBsp( zCCBspTree*, zCTree<zCVob>*, int )                                                            zCall( 0x005F4E60 );
    void SaveBspTreeMesh3DS( zSTRING const& )                                                                      zCall( 0x005F4F60 );
    void CompileWorld( zTBspTreeMode const&, float, int, int, zCArray<zCPolygon*>* )                               zCall( 0x005F4F90 );
    void SearchZoneListByClass( zCClassDef*, zCArray<zCZone*>& )                                                   zCall( 0x005F5F10 );
    zCZone* SearchZoneDefaultByClass( zCClassDef* )                                                                zCall( 0x005F6060 );
    int ShouldAddThisVobToBsp( zCVob* ) const                                                                      zCall( 0x005F62E0 );
    zCTree<zCVob>* AddVobAsChild_novt( zCVob*, zCVob* )                                                            zCall( 0x005F6320 );
    zCTree<zCVob>* AddVob( zCVob* )                                                                                zCall( 0x005F6340 );
    void RemoveVob_novt( zCTree<zCVob>* )                                                                          zCall( 0x005F66F0 );
    void RemoveVobSubtree_r( zCTree<zCVob>*, int )                                                                 zCall( 0x005F6710 );
    void RemoveVobSubtree_novt( zCTree<zCVob>* )                                                                   zCall( 0x005F68E0 );
    void MoveVobSubtreeTo_novt( zCVob*, zCVob* )                                                                   zCall( 0x005F69C0 );
    void MoveVobSubtreeToWorldSpace( zCVob* )                                                                      zCall( 0x005F69E0 );
    void RemoveVobFromLists( zCVob* )                                                                              zCall( 0x005F6A00 );
    void PrintStatus()                                                                                             zCall( 0x005F6BF0 );
    void PrintGlobalVobTree( zCTree<zCVob>*, int )                                                                 zCall( 0x005F74C0 );
    void PrintActiveVobs()                                                                                         zCall( 0x005F7780 );
    void UpdateVobTreeBspDependencies( zCTree<zCVob>* )                                                            zCall( 0x005F7980 );
    void MoveVobs()                                                                                                zCall( 0x005F79F0 );
    void AdvanceClock( float )                                                                                     zCall( 0x005F7A80 );
    void SaveBspTree( zFILE& )                                                                                     zCall( 0x005F7AC0 );
    int LoadBspTree( zFILE&, int )                                                                                 zCall( 0x005F7C40 );
    void DebugMarkOccluderPolys()                                                                                  zCall( 0x005F7D70 );
    void __fastcall UnarcTraverseVobs( zCArchiver&, zCTree<zCVob>* )                                               zCall( 0x005F7F40 );
    zCViewProgressBar* GetProgressBar() const                                                                      zCall( 0x005F82F0 );
    void __fastcall ArcTraverseVobs( zCArchiver&, zCTree<zCVob>*, int )                                            zCall( 0x005F8D00 );
    void TraverseVobTree( zCVobCallback&, void*, zCTree<zCVob>* )                                                  zCall( 0x005F9690 );
    unsigned long GetVobHashIndex( zSTRING const& )                                                                zCall( 0x005F96F0 );
    unsigned long GetVobHashIndex( zCVob* )                                                                        zCall( 0x005F9720 );
    void InsertVobHashTable( zCVob* )                                                                              zCall( 0x005F9760 );
    void RemoveVobHashTable( zCVob* )                                                                              zCall( 0x005F98A0 );
    zCVob* SearchVobHashTable( zSTRING const& )                                                                    zCall( 0x005F9930 );
    void SearchVobListHashTable( zSTRING const&, zCArray<zCVob*>& )                                                zCall( 0x005F9A10 );
    void SetOwnerSession( zCSession* )                                                                             zCall( 0x005F9BF0 );
    zCSession* GetOwnerSession()                                                                                   zCall( 0x005F9C40 );
    void ResetCutscenePlayer()                                                                                     zCall( 0x005F9C50 );
    void RegisterPerFrameCallback( zCWorldPerFrameCallback* )                                                      zCall( 0x005F9CA0 );
    void UnregisterPerFrameCallback( zCWorldPerFrameCallback* )                                                    zCall( 0x005F9DF0 );
    void LightWorldStaticUncompiled( zCTree<zCVob>* )                                                              zCall( 0x005FB120 );
    void LightWorldStaticCompiled()                                                                                zCall( 0x005FB530 );
    void GenerateStaticVertexLighting()                                                                            zCall( 0x005FBB60 );
    int LightingTestRay( zVEC3 const&, zVEC3 const&, zVEC3&, zCPolygon*& )                                         zCall( 0x005FBE30 );
    int GetSurfaceLightmapBBox2D( zCArray<zCPolygon*>&, zTBBox2D&, int* const )                                    zCall( 0x005FBEF0 );
    zVEC3 GetPhongNormal( zCPolygon*, zVEC3 const& )                                                               zCall( 0x005FC350 );
    zCPatchMap* GeneratePatchMapFromSurface( zCArray<zCPolygon*>& )                                                zCall( 0x005FC710 );
    void GenerateLightmapFromPatchMap( zCPatchMap* )                                                               zCall( 0x005FD5C0 );
    void LightPatchMap( zCPatchMap* )                                                                              zCall( 0x005FE870 );
    void GenerateSurfaces( int, zTBBox3D* )                                                                        zCall( 0x005FED20 );
    void MakeTransfers()                                                                                           zCall( 0x005FF990 );
    void GenerateLightmapsRadiosity( zTBBox3D* )                                                                   zCall( 0x00600220 );
    void GenerateLightmaps( zTStaticWorldLightMode const&, zTBBox3D* )                                             zCall( 0x00600470 );
    void GenerateStaticWorldLighting( zTStaticWorldLightMode const&, zTBBox3D* )                                   zCall( 0x00600B60 );
    void MakeVobLightingDirty()                                                                                    zCall( 0x00600BA0 );
    zCBspTree* GetBspTree()                                                                                        zCall( 0x006076F0 );
    void SetVobFarClipZScalability( float )                                                                        zCall( 0x00607700 );
    static zCObject* _CreateNewInstance()                                                                          zCall( 0x005F23A0 );
    static int ActiveZoneListCompare( void const*, void const* )                                                   zCall( 0x005F2D50 );
    virtual zCClassDef* _GetClassDef() const                                                                       zCall( 0x005F2960 );
    virtual void Archive( zCArchiver& )                                                                            zCall( 0x005F9010 );
    virtual void Unarchive( zCArchiver& )                                                                          zCall( 0x005F8300 );
    virtual ~zCWorld()                                                                                             zCall( 0x005F2A10 );
    virtual int LoadWorld( zSTRING const&, zTWorldLoadMode )                                                       zCall( 0x005F8A00 );
    virtual int SaveWorld( zSTRING const&, zTWorldSaveMode, int, int )                                             zCall( 0x005F9330 );
    virtual zCVob* MergeVobSubtree( zSTRING const&, zCVob*, zTWorldLoadMergeMode )                                 zCall( 0x005F8C40 );
    virtual int SaveVobSubtree( zSTRING const&, zCVob*, int, int )                                                 zCall( 0x005F95D0 );
    virtual void DisposeWorld()                                                                                    zCall( 0x005F5800 );
    virtual int DisposeVobs( zCTree<zCVob>* )                                                                      zCall( 0x005F55F0 );
    virtual void DisposeStaticWorld()                                                                              zCall( 0x005F5790 );
    virtual zCTree<zCVob>* AddVobAsChild( zCVob*, zCTree<zCVob>* )                                                 zCall( 0x005F60D0 );
    virtual void RemoveVob( zCVob* )                                                                               zCall( 0x005F66C0 );
    virtual void RemoveVobSubtree( zCVob* )                                                                        zCall( 0x005F68B0 );
    virtual void MoveVobSubtreeTo( zCVob*, zCTree<zCVob>* )                                                        zCall( 0x005F6900 );
    virtual zCPlayerGroup* GetPlayerGroup()                                                                        zCall( 0x005F2970 );
    virtual zCVob* SearchVob( zCVob*, zCTree<zCVob>* )                                                             zCall( 0x005F59E0 );
    virtual zCVob* SearchVobByID( unsigned long, zCTree<zCVob>* )                                                  zCall( 0x005F5A30 );
    virtual zCVob* SearchVobByName( zSTRING const& )                                                               zCall( 0x005F5A80 );
    virtual void SearchVobListByName( zSTRING const&, zCArray<zCVob*>& )                                           zCall( 0x005F5B60 );
    virtual void SearchVobListByClass( zCClassDef*, zCArray<zCVob*>&, zCTree<zCVob>* )                             zCall( 0x005F5D40 );
    virtual void SearchVobListByBaseClass( zCClassDef*, zCArray<zCVob*>&, zCTree<zCVob>* )                         zCall( 0x005F5E20 );
    virtual void VobAddedToWorld( zCVob* )                                                                         zCall( 0x005F6360 );
    virtual void VobRemovedFromWorld( zCVob* )                                                                     zCall( 0x005F64C0 );
    virtual void RenderWaynet( zCCamera* )                                                                         zCall( 0x005F2D30 );


    // static properties
    static zTWorldLoadMode& s_worldLoadMode;
    static zTWorldSaveMode& s_worldSaveMode;
    static zTWorldLoadMergeMode& s_worldMergeMode;

    // user API
    #include "zCWorld.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZWORLD_H__VER0__