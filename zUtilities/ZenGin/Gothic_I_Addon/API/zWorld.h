// Supported with union (c) 2018-2021 Union team

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

  // sizeof 01h
  class zCCallback {
  public:

    zCCallback() {}

    // user API
    #include "zCCallback.inl"
  };

  // sizeof 04h
  class zCVobCallback : public zCCallback {
  public:

    zCVobCallback() {}
    virtual void HandleVob( zCVob*, void* ) zPureCall;

    // user API
    #include "zCVobCallback.inl"
  };

  // sizeof 04h
  class zCWorldPerFrameCallback : public zCCallback {
  public:
    
    virtual void DoWorldPerFrameCallback( zCWorld*, zCCamera* ) zPureCall;
    zCWorldPerFrameCallback() {}

    // user API
    #include "zCWorldPerFrameCallback.inl"
  };

  // sizeof 28h
  struct zTTraceRayReport {
    int foundHit;            // sizeof 04h    offset 00h
    zCVob* foundVob;         // sizeof 04h    offset 04h
    zCPolygon* foundPoly;    // sizeof 04h    offset 08h
    zVEC3 foundIntersection; // sizeof 0Ch    offset 0Ch
    zVEC3 foundPolyNormal;   // sizeof 0Ch    offset 18h
    zCVertex* foundVertex;   // sizeof 04h    offset 24h

    zTTraceRayReport() {}

    // user API
    #include "zTTraceRayReport.inl"
  };

  // sizeof 08h
  class zCTransferConstr {
  public:
    zCPatch* targetPatch; // sizeof 04h    offset 00h
    float formFactor;     // sizeof 04h    offset 04h

    zCTransferConstr() {}

    // user API
    #include "zCTransferConstr.inl"
  };
  
#pragma pack( push, 1 )

  // sizeof 06h
  class zCTransfer {
  public:
    zCPatch* targetPatch;      // sizeof 04h    offset 00h
    unsigned short formFactor; // sizeof 02h    offset 04h

    zCTransfer() {}

    // user API
    #include "zCTransfer.inl"
  };
  
#pragma pack( pop )

  // sizeof 5Ch
  class zCPatch {
  public:
    zVEC3 center;                     // sizeof 0Ch    offset 00h
    zVEC3 centerLight;                // sizeof 0Ch    offset 0Ch
    zVEC3 normal;                     // sizeof 0Ch    offset 18h
    float area;                       // sizeof 04h    offset 24h
    zVEC3 radiosity;                  // sizeof 0Ch    offset 28h
    zVEC3 radToShoot;                 // sizeof 0Ch    offset 34h
    short xpos;                       // sizeof 02h    offset 40h
    short ypos;                       // sizeof 02h    offset 42h
    zCArray<zCTransfer> transferList; // sizeof 0Ch    offset 44h
    zVEC3 reflectivity;               // sizeof 0Ch    offset 50h

    void zCPatch_OnInit() zCall( 0x0061EE90 );
    zCPatch()             zInit( zCPatch_OnInit() );
    void DoTransfers()    zCall( 0x00621CF0 );

    // user API
    #include "zCPatch.inl"
  };
    
#pragma pack( push, 1 )

  // sizeof 7Dh
  class zCPatchMap {
  public:
    char hit;                    // sizeof 01h    offset 00h
    short xdim;                  // sizeof 02h    offset 01h
    short ydim;                  // sizeof 02h    offset 03h
    zCArray<zCPatch*> patchList; // sizeof 0Ch    offset 05h
    zCArray<zCPolygon*> surface; // sizeof 0Ch    offset 11h
    zTPlane lightRejectPlane0;   // sizeof 10h    offset 1Dh
    zTPlane lightRejectPlane1;   // sizeof 10h    offset 2Dh
    zTBBox3D bbox3D;             // sizeof 18h    offset 3Dh
    zVEC3 lightmapOrigin;        // sizeof 0Ch    offset 55h
    zVEC3 lightmapUp;            // sizeof 0Ch    offset 61h
    zVEC3 lightmapRight;         // sizeof 0Ch    offset 6Dh
    zCPolygon* lastRayHitPoly;   // sizeof 04h    offset 79h

    zCPatchMap() {}
    int CheckRaySurfaceIntersection( zVEC3&, zVEC3&, zVEC3&, zCPolygon*& ) zCall( 0x0061EEE0 );
    ~zCPatchMap()                                                          zCall( 0x006214D0 );

    // user API
    #include "zCPatchMap.inl"
  };
    
#pragma pack( pop )

  // sizeof 6240h
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

    zCTree<zCVob> globalVobTree;                                 // sizeof 14h    offset 24h
    zTTraceRayReport traceRayReport;                             // sizeof 28h    offset 38h
    zCSession* ownerSession;                                     // sizeof 04h    offset 60h
    zCCSPlayer* csPlayer;                                        // sizeof 04h    offset 64h
    int compiled;                                                // sizeof 04h    offset 68h
    int compiledEditorMode;                                      // sizeof 04h    offset 6Ch
    int traceRayIgnoreVobFlag;                                   // sizeof 04h    offset 70h
    zTWld_RenderMode worldRenderMode;                            // sizeof 04h    offset 74h
    zCWayNet* wayNet;                                            // sizeof 04h    offset 78h
    int masterFrameCtr;                                          // sizeof 04h    offset 7Ch
    float vobFarClipZ;                                           // sizeof 04h    offset 80h
    float vobFarClipZScalability;                                // sizeof 04h    offset 84h
    zCArray<zCVob*> traceRayVobList;                             // sizeof 0Ch    offset 88h
    zCArray<zCVob*> traceRayTempIgnoreVobList;                   // sizeof 0Ch    offset 94h
    int renderingFirstTime;                                      // sizeof 04h    offset A0h
    int showWaynet;                                              // sizeof 04h    offset A4h
    int showTraceRayLines;                                       // sizeof 04h    offset A8h
    int showTextureStats;                                        // sizeof 04h    offset ACh
    zCViewProgressBar* progressBar;                              // sizeof 04h    offset B0h
    unsigned long unarchiveFileLen;                              // sizeof 04h    offset B4h
    unsigned long unarchiveStartPosVobtree;                      // sizeof 04h    offset B8h
    int numVobsInWorld;                                          // sizeof 04h    offset BCh
    zCArray<zCWorldPerFrameCallback*> perFrameCallbackList;      // sizeof 0Ch    offset C0h
    zCSkyControler* skyControlerIndoor;                          // sizeof 04h    offset CCh
    zCSkyControler* skyControlerOutdoor;                         // sizeof 04h    offset D0h
    zCSkyControler* activeSkyControler;                          // sizeof 04h    offset D4h
    zCArray<zCZone*> zoneGlobalList;                             // sizeof 0Ch    offset D8h
    zCArraySort<zCZone*> zoneActiveList;                         // sizeof 10h    offset E4h
    zCArraySort<zCZone*> zoneLastClassList;                      // sizeof 10h    offset F4h
    zCVobBBox3DSorter<zCZone> zoneBoxSorter;                     // sizeof 44h    offset 104h
    zCVobBBox3DSorter<zCZone>::zTBoxSortHandle zoneActiveHandle; // sizeof 44h    offset 148h
    int addZonesToWorld;                                         // sizeof 04h    offset 18Ch
    int showZonesDebugInfo;                                      // sizeof 04h    offset 190h
    zCCBspTree* cbspTree;                                        // sizeof 04h    offset 194h
    zCBspTree bspTree;                                           // sizeof 90h    offset 198h
    zCArray<zCVob*> activeVobList;                               // sizeof 0Ch    offset 228h
    zCArray<zCVob*> walkList;                                    // sizeof 0Ch    offset 234h
    zCArray<zCVob*> vobHashTable[zNUM_VOB_HASH];                 // sizeof 6000h  offset 240h

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