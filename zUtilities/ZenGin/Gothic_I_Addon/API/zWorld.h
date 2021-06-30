// Supported with union (c) 2018 Union team

#ifndef __ZWORLD_H__VER1__
#define __ZWORLD_H__VER1__

namespace Gothic_I_Addon {
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

    void zCPatch_OnInit() zCall( 0x0061EE90 );
    zCPatch()             zInit( zCPatch_OnInit() );
    void DoTransfers()    zCall( 0x00621CF0 );

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
    int CheckRaySurfaceIntersection( zVEC3&, zVEC3&, zVEC3&, zCPolygon*& ) zCall( 0x0061EEE0 );
    ~zCPatchMap()                                                          zCall( 0x006214D0 );

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

    void zCWorld_OnInit()                                                                                          zCall( 0x006131C0 );
    zCWorld()                                                                                                      zInit( zCWorld_OnInit() );
    zCSkyControler* GetActiveSkyControler()                                                                        zCall( 0x00613A60 );
    void SetSkyControlerIndoor( zCSkyControler* )                                                                  zCall( 0x00613A90 );
    void SetSkyControlerOutdoor( zCSkyControler* )                                                                 zCall( 0x00613AD0 );
    void AddZone( zCZone* )                                                                                        zCall( 0x00613B80 );
    void RemoveZone( zCZone* )                                                                                     zCall( 0x00613D10 );
    void RemoveAllZones()                                                                                          zCall( 0x00613E40 );
    void UpdateZone( zCZone* )                                                                                     zCall( 0x00613EB0 );
    void ProcessZones()                                                                                            zCall( 0x00613ED0 );
    void ShowZonesDebugInfo()                                                                                      zCall( 0x006144D0 );
    void ShowTextureStats()                                                                                        zCall( 0x00614920 );
    void Render( zCCamera& )                                                                                       zCall( 0x00614D70 );
    int __fastcall TraceRayFirstHit( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int )                     zCall( 0x00614F70 );
    int __fastcall TraceRayNearestHit( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int )                   zCall( 0x006151A0 );
    int __fastcall TraceRayFirstHit( zVEC3 const&, zVEC3 const&, zCVob*, int )                                     zCall( 0x006154C0 );
    int __fastcall TraceRayNearestHit( zVEC3 const&, zVEC3 const&, zCVob*, int )                                   zCall( 0x00615600 );
    int __fastcall TraceRayFirstHitCache( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int, zCRayCache* )   zCall( 0x00615740 );
    int __fastcall TraceRayFirstHitCache( zVEC3 const&, zVEC3 const&, zCVob*, int, zCRayCache* )                   zCall( 0x00615810 );
    int __fastcall TraceRayNearestHitCache( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int, zCRayCache* ) zCall( 0x00615940 );
    int __fastcall TraceRayNearestHitCache( zVEC3 const&, zVEC3 const&, zCVob*, int, zCRayCache* )                 zCall( 0x00615A10 );
    int __fastcall PickScene( zCCamera&, int, int, float )                                                         zCall( 0x00615B40 );
    int TraverseBsp( zCCBspTree*, zCTree<zCVob>*, int )                                                            zCall( 0x00615DA0 );
    void SaveBspTreeMesh3DS( zSTRING const& )                                                                      zCall( 0x00615EA0 );
    void CompileWorld( zTBspTreeMode const&, float, int, int, zCArray<zCPolygon*>* )                               zCall( 0x00615ED0 );
    void SearchZoneListByClass( zCClassDef*, zCArray<zCZone*>& )                                                   zCall( 0x00616EE0 );
    zCZone* SearchZoneDefaultByClass( zCClassDef* )                                                                zCall( 0x00617020 );
    int ShouldAddThisVobToBsp( zCVob* ) const                                                                      zCall( 0x006172A0 );
    zCTree<zCVob>* AddVobAsChild_novt( zCVob*, zCVob* )                                                            zCall( 0x006172F0 );
    zCTree<zCVob>* AddVob( zCVob* )                                                                                zCall( 0x00617320 );
    void RemoveVob_novt( zCTree<zCVob>* )                                                                          zCall( 0x006176C0 );
    void RemoveVobSubtree_r( zCTree<zCVob>*, int )                                                                 zCall( 0x006176E0 );
    void RemoveVobSubtree_novt( zCTree<zCVob>* )                                                                   zCall( 0x006178C0 );
    void MoveVobSubtreeTo_novt( zCVob*, zCVob* )                                                                   zCall( 0x006179A0 );
    void MoveVobSubtreeToWorldSpace( zCVob* )                                                                      zCall( 0x006179C0 );
    void RemoveVobFromLists( zCVob* )                                                                              zCall( 0x006179E0 );
    void PrintStatus()                                                                                             zCall( 0x00617BD0 );
    void PrintGlobalVobTree( zCTree<zCVob>*, int )                                                                 zCall( 0x006185F0 );
    void PrintActiveVobs()                                                                                         zCall( 0x00618900 );
    void UpdateVobTreeBspDependencies( zCTree<zCVob>* )                                                            zCall( 0x00618B40 );
    void MoveVobs()                                                                                                zCall( 0x00618BA0 );
    void AdvanceClock( float )                                                                                     zCall( 0x00618C30 );
    void SaveBspTree( zFILE& )                                                                                     zCall( 0x00618C70 );
    int LoadBspTree( zFILE&, int )                                                                                 zCall( 0x00618E10 );
    void DebugMarkOccluderPolys()                                                                                  zCall( 0x00618F40 );
    void __fastcall UnarcTraverseVobs( zCArchiver&, zCTree<zCVob>* )                                               zCall( 0x00619390 );
    zCViewProgressBar* GetProgressBar() const                                                                      zCall( 0x00619760 );
    void __fastcall ArcTraverseVobs( zCArchiver&, zCTree<zCVob>*, int )                                            zCall( 0x0061A1F0 );
    void TraverseVobTree( zCVobCallback&, void*, zCTree<zCVob>* )                                                  zCall( 0x0061ABD0 );
    unsigned long GetVobHashIndex( zSTRING const& )                                                                zCall( 0x0061AC30 );
    unsigned long GetVobHashIndex( zCVob* )                                                                        zCall( 0x0061AC60 );
    void InsertVobHashTable( zCVob* )                                                                              zCall( 0x0061ACA0 );
    void RemoveVobHashTable( zCVob* )                                                                              zCall( 0x0061ADE0 );
    zCVob* SearchVobHashTable( zSTRING const& )                                                                    zCall( 0x0061AE70 );
    void SearchVobListHashTable( zSTRING const&, zCArray<zCVob*>& )                                                zCall( 0x0061AF60 );
    void SetOwnerSession( zCSession* )                                                                             zCall( 0x0061B150 );
    zCSession* GetOwnerSession()                                                                                   zCall( 0x0061B1A0 );
    void ResetCutscenePlayer()                                                                                     zCall( 0x0061B1B0 );
    void RegisterPerFrameCallback( zCWorldPerFrameCallback* )                                                      zCall( 0x0061B200 );
    void UnregisterPerFrameCallback( zCWorldPerFrameCallback* )                                                    zCall( 0x0061B350 );
    void LightWorldStaticUncompiled( zCTree<zCVob>* )                                                              zCall( 0x0061C840 );
    void LightWorldStaticCompiled()                                                                                zCall( 0x0061CCE0 );
    void GenerateStaticVertexLighting()                                                                            zCall( 0x0061D340 );
    int LightingTestRay( zVEC3 const&, zVEC3 const&, zVEC3&, zCPolygon*& )                                         zCall( 0x0061D630 );
    int GetSurfaceLightmapBBox2D( zCArray<zCPolygon*>&, zTBBox2D&, int* const )                                    zCall( 0x0061D700 );
    zVEC3 GetPhongNormal( zCPolygon*, zVEC3 const& )                                                               zCall( 0x0061DB90 );
    zCPatchMap* GeneratePatchMapFromSurface( zCArray<zCPolygon*>& )                                                zCall( 0x0061DFA0 );
    void GenerateLightmapFromPatchMap( zCPatchMap* )                                                               zCall( 0x0061EF80 );
    void LightPatchMap( zCPatchMap* )                                                                              zCall( 0x00620320 );
    void GenerateSurfaces( int, zTBBox3D* )                                                                        zCall( 0x00620830 );
    void MakeTransfers()                                                                                           zCall( 0x00621570 );
    void GenerateLightmapsRadiosity( zTBBox3D* )                                                                   zCall( 0x00621E80 );
    void GenerateLightmaps( zTStaticWorldLightMode const&, zTBBox3D* )                                             zCall( 0x006220E0 );
    void GenerateStaticWorldLighting( zTStaticWorldLightMode const&, zTBBox3D* )                                   zCall( 0x00622880 );
    void MakeVobLightingDirty()                                                                                    zCall( 0x006228C0 );
    zCBspTree* GetBspTree()                                                                                        zCall( 0x006299A0 );
    void SetVobFarClipZScalability( float )                                                                        zCall( 0x006299B0 );
    static zCObject* _CreateNewInstance()                                                                          zCall( 0x00613150 );
    static int ActiveZoneListCompare( void const*, void const* )                                                   zCall( 0x00613B30 );
    virtual zCClassDef* _GetClassDef() const                                                                       zCall( 0x00613730 );
    virtual void Archive( zCArchiver& )                                                                            zCall( 0x0061A510 );
    virtual void Unarchive( zCArchiver& )                                                                          zCall( 0x00619770 );
    virtual ~zCWorld()                                                                                             zCall( 0x006137E0 );
    virtual int LoadWorld( zSTRING const&, zTWorldLoadMode )                                                       zCall( 0x00619EC0 );
    virtual int SaveWorld( zSTRING const&, zTWorldSaveMode, int, int )                                             zCall( 0x0061A850 );
    virtual zCVob* MergeVobSubtree( zSTRING const&, zCVob*, zTWorldLoadMergeMode )                                 zCall( 0x0061A130 );
    virtual int SaveVobSubtree( zSTRING const&, zCVob*, int, int )                                                 zCall( 0x0061AB10 );
    virtual void DisposeWorld()                                                                                    zCall( 0x00616780 );
    virtual int DisposeVobs( zCTree<zCVob>* )                                                                      zCall( 0x00616570 );
    virtual void DisposeStaticWorld()                                                                              zCall( 0x00616710 );
    virtual zCTree<zCVob>* AddVobAsChild( zCVob*, zCTree<zCVob>* )                                                 zCall( 0x00617090 );
    virtual void RemoveVob( zCVob* )                                                                               zCall( 0x00617690 );
    virtual void RemoveVobSubtree( zCVob* )                                                                        zCall( 0x00617890 );
    virtual void MoveVobSubtreeTo( zCVob*, zCTree<zCVob>* )                                                        zCall( 0x006178E0 );
    virtual zCPlayerGroup* GetPlayerGroup()                                                                        zCall( 0x00613740 );
    virtual zCVob* SearchVob( zCVob*, zCTree<zCVob>* )                                                             zCall( 0x00616980 );
    virtual zCVob* SearchVobByID( unsigned long, zCTree<zCVob>* )                                                  zCall( 0x006169D0 );
    virtual zCVob* SearchVobByName( zSTRING const& )                                                               zCall( 0x00616A20 );
    virtual void SearchVobListByName( zSTRING const&, zCArray<zCVob*>& )                                           zCall( 0x00616B10 );
    virtual void SearchVobListByClass( zCClassDef*, zCArray<zCVob*>&, zCTree<zCVob>* )                             zCall( 0x00616D00 );
    virtual void SearchVobListByBaseClass( zCClassDef*, zCArray<zCVob*>&, zCTree<zCVob>* )                         zCall( 0x00616DE0 );
    virtual void VobAddedToWorld( zCVob* )                                                                         zCall( 0x00617340 );
    virtual void VobRemovedFromWorld( zCVob* )                                                                     zCall( 0x006174A0 );
    virtual void RenderWaynet( zCCamera* )                                                                         zCall( 0x00613B10 );


    // static properties
    static zTWorldLoadMode& s_worldLoadMode;
    static zTWorldSaveMode& s_worldSaveMode;
    static zTWorldLoadMergeMode& s_worldMergeMode;

    // user API
    #include "zCWorld.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZWORLD_H__VER1__