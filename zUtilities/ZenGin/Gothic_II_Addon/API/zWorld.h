// Supported with union (c) 2018 Union team

#ifndef __ZWORLD_H__VER3__
#define __ZWORLD_H__VER3__

#include "zObject.h"
#include "zBsp.h"
#include "zVob.h"
#include "zZone.h"

namespace Gothic_II_Addon {
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
    zTRACERAY_VOB_TEST_HELPER_VISUALS = 1 << 13,
    zTRACERAY_VOB_IGNORE_PROJECTILES  = 1 << 14
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

    void zCPatch_OnInit() zCall( 0x0062C0C0 );
    zCPatch()             zInit( zCPatch_OnInit() );
    void DoTransfers()    zCall( 0x0062F000 );

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
    int CheckRaySurfaceIntersection( zVEC3&, zVEC3&, zVEC3&, zCPolygon*& ) zCall( 0x0062C110 );
    ~zCPatchMap()                                                          zCall( 0x0062E760 );

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
    zSTRING m_strlevelName;
    int compiled;
    int compiledEditorMode;
    int traceRayIgnoreVobFlag;
    int m_bIsInventoryWorld;
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

    void zCWorld_OnInit()                                                                                          zCall( 0x0061FA40 );
    zCWorld()                                                                                                      zInit( zCWorld_OnInit() );
    zCSkyControler* GetActiveSkyControler()                                                                        zCall( 0x006203A0 );
    void SetSkyControlerIndoor( zCSkyControler* )                                                                  zCall( 0x006203D0 );
    void SetSkyControlerOutdoor( zCSkyControler* )                                                                 zCall( 0x00620410 );
    void AddZone( zCZone* )                                                                                        zCall( 0x006204C0 );
    void RemoveZone( zCZone* )                                                                                     zCall( 0x00620630 );
    void RemoveAllZones()                                                                                          zCall( 0x00620770 );
    void UpdateZone( zCZone* )                                                                                     zCall( 0x006207E0 );
    void ProcessZones()                                                                                            zCall( 0x006207F0 );
    void ShowZonesDebugInfo()                                                                                      zCall( 0x00620E60 );
    void ShowTextureStats()                                                                                        zCall( 0x00621280 );
    void Render( zCCamera& )                                                                                       zCall( 0x00621700 );
    int __fastcall TraceRayFirstHit( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int )                     zCall( 0x00621960 );
    int __fastcall TraceRayNearestHit( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int )                   zCall( 0x00621B80 );
    int __fastcall TraceRayFirstHit( zVEC3 const&, zVEC3 const&, zCVob*, int )                                     zCall( 0x00621E70 );
    int __fastcall TraceRayNearestHit( zVEC3 const&, zVEC3 const&, zCVob*, int )                                   zCall( 0x00621FA0 );
    int __fastcall TraceRayFirstHitCache( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int, zCRayCache* )   zCall( 0x006220D0 );
    int __fastcall TraceRayFirstHitCache( zVEC3 const&, zVEC3 const&, zCVob*, int, zCRayCache* )                   zCall( 0x00622230 );
    int __fastcall TraceRayNearestHitCache( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int, zCRayCache* ) zCall( 0x006223F0 );
    int __fastcall TraceRayNearestHitCache( zVEC3 const&, zVEC3 const&, zCVob*, int, zCRayCache* )                 zCall( 0x00622550 );
    int __fastcall PickScene( zCCamera&, int, int, float )                                                         zCall( 0x00622710 );
    int TraverseBsp( zCCBspTree*, zCTree<zCVob>*, int )                                                            zCall( 0x00622980 );
    int TraverseBspAddVobsToMesh( zCCBspTree*, zCTree<zCVob>* )                                                    zCall( 0x00622A80 );
    void SaveBspTreeMesh3DS( zSTRING const& )                                                                      zCall( 0x00622E90 );
    void CompileWorld( zTBspTreeMode const&, float, int, int, zCArray<zCPolygon*>* )                               zCall( 0x00622EC0 );
    void SearchZoneListByClass( zCClassDef*, zCArray<zCZone*>& )                                                   zCall( 0x00624400 );
    zCZone* SearchZoneDefaultByClass( zCClassDef* )                                                                zCall( 0x00624530 );
    int ShouldAddThisVobToBsp( zCVob* ) const                                                                      zCall( 0x006247B0 );
    zCTree<zCVob>* AddVobAsChild_novt( zCVob*, zCVob* )                                                            zCall( 0x006247F0 );
    zCTree<zCVob>* AddVob( zCVob* )                                                                                zCall( 0x00624810 );
    void RemoveVob_novt( zCTree<zCVob>* )                                                                          zCall( 0x00624BA0 );
    void RemoveVobSubtree_r( zCTree<zCVob>*, int )                                                                 zCall( 0x00624BC0 );
    void RemoveVobSubtree_novt( zCTree<zCVob>* )                                                                   zCall( 0x00624D90 );
    void MoveVobSubtreeTo_novt( zCVob*, zCVob* )                                                                   zCall( 0x00624E70 );
    void MoveVobSubtreeToWorldSpace( zCVob* )                                                                      zCall( 0x00624E90 );
    void RemoveVobFromLists( zCVob* )                                                                              zCall( 0x00624EB0 );
    void PrintStatus()                                                                                             zCall( 0x00625080 );
    void PrintGlobalVobTree( zCTree<zCVob>*, int )                                                                 zCall( 0x00625AE0 );
    void PrintActiveVobs()                                                                                         zCall( 0x00625DA0 );
    void UpdateVobTreeBspDependencies( zCTree<zCVob>* )                                                            zCall( 0x00625FE0 );
    void MoveVobs()                                                                                                zCall( 0x00626050 );
    void AdvanceClock( float )                                                                                     zCall( 0x006260E0 );
    void SaveBspTree( zFILE& )                                                                                     zCall( 0x00626120 );
    int LoadBspTree( zFILE&, int )                                                                                 zCall( 0x006262A0 );
    void DebugMarkOccluderPolys()                                                                                  zCall( 0x006263D0 );
    void __fastcall UnarcTraverseVobs( zCArchiver&, zCTree<zCVob>* )                                               zCall( 0x00626570 );
    zCViewProgressBar* GetProgressBar() const                                                                      zCall( 0x006269C0 );
    void __fastcall ArcTraverseVobs( zCArchiver&, zCTree<zCVob>*, int )                                            zCall( 0x006274A0 );
    void TraverseVobTree( zCVobCallback&, void*, zCTree<zCVob>* )                                                  zCall( 0x00627F10 );
    unsigned long GetVobHashIndex( zSTRING const& )                                                                zCall( 0x00627F70 );
    unsigned long GetVobHashIndex( zCVob* )                                                                        zCall( 0x00627FA0 );
    void InsertVobHashTable( zCVob* )                                                                              zCall( 0x00627FE0 );
    void RemoveVobHashTable( zCVob* )                                                                              zCall( 0x00628100 );
    zCVob* SearchVobHashTable( zSTRING const& )                                                                    zCall( 0x00628190 );
    void SearchVobListHashTable( zSTRING const&, zCArray<zCVob*>& )                                                zCall( 0x00628270 );
    void SetOwnerSession( zCSession* )                                                                             zCall( 0x00628430 );
    zCSession* GetOwnerSession()                                                                                   zCall( 0x00628480 );
    void ResetCutscenePlayer()                                                                                     zCall( 0x00628490 );
    void RegisterPerFrameCallback( zCWorldPerFrameCallback* )                                                      zCall( 0x006284E0 );
    void UnregisterPerFrameCallback( zCWorldPerFrameCallback* )                                                    zCall( 0x00628610 );
    void LightWorldStaticUncompiled( zCTree<zCVob>* )                                                              zCall( 0x00629B30 );
    void LightWorldStaticCompiled()                                                                                zCall( 0x00629F70 );
    void GenerateStaticVertexLighting()                                                                            zCall( 0x0062A760 );
    int LightingTestRay( zVEC3 const&, zVEC3 const&, zVEC3&, zCPolygon*& )                                         zCall( 0x0062AA70 );
    int GetSurfaceLightmapBBox2D( zCArray<zCPolygon*>&, zTBBox2D&, int* const )                                    zCall( 0x0062AB30 );
    zVEC3 GetPhongNormal( zCPolygon*, zVEC3 const& )                                                               zCall( 0x0062AF90 );
    zCPatchMap* GeneratePatchMapFromSurface( zCArray<zCPolygon*>& )                                                zCall( 0x0062B350 );
    void GenerateLightmapFromPatchMap( zCPatchMap* )                                                               zCall( 0x0062C1B0 );
    void LightPatchMap( zCPatchMap* )                                                                              zCall( 0x0062D4C0 );
    void GenerateSurfaces( int, zTBBox3D* )                                                                        zCall( 0x0062D970 );
    void MakeTransfers()                                                                                           zCall( 0x0062E800 );
    void GenerateLightmapsRadiosity( zTBBox3D* )                                                                   zCall( 0x0062F150 );
    void GenerateLightmaps( zTStaticWorldLightMode const&, zTBBox3D* )                                             zCall( 0x0062F3A0 );
    void GenerateStaticWorldLighting( zTStaticWorldLightMode const&, zTBBox3D* )                                   zCall( 0x0062FB70 );
    void MakeVobLightingDirty()                                                                                    zCall( 0x0062FE60 );
    void SetVobFarClipZScalability( float )                                                                        zCall( 0x00637210 );
    zCBspTree* GetBspTree()                                                                                        zCall( 0x006D0020 );
    static zCObject* _CreateNewInstance()                                                                          zCall( 0x0061F9B0 );
    static int ActiveZoneListCompare( void const*, void const* )                                                   zCall( 0x00620470 );
    static int GetWaveAnisEnabled()                                                                                zCall( 0x006371D0 );
    static void SetWaveAnisEnabled( int )                                                                          zCall( 0x006371E0 );
    static int GetShowTextureStats()                                                                               zCall( 0x006371F0 );
    static void SetShowTextureStats( int )                                                                         zCall( 0x00637200 );
    virtual zCClassDef* _GetClassDef() const                                                                       zCall( 0x00620040 );
    virtual void Archive( zCArchiver& )                                                                            zCall( 0x00627890 );
    virtual void Unarchive( zCArchiver& )                                                                          zCall( 0x006269D0 );
    virtual ~zCWorld()                                                                                             zCall( 0x006200F0 );
    virtual int LoadWorld( zSTRING const&, zTWorldLoadMode )                                                       zCall( 0x006270D0 );
    virtual int SaveWorld( zSTRING const&, zTWorldSaveMode, int, int )                                             zCall( 0x00627BB0 );
    virtual zCVob* MergeVobSubtree( zSTRING const&, zCVob*, zTWorldLoadMergeMode )                                 zCall( 0x006273E0 );
    virtual int SaveVobSubtree( zSTRING const&, zCVob*, int, int )                                                 zCall( 0x00627E50 );
    virtual void DisposeWorld()                                                                                    zCall( 0x00623D30 );
    virtual int DisposeVobs( zCTree<zCVob>* )                                                                      zCall( 0x00623960 );
    virtual int DisposeVobsDbg( zCTree<zCVob>* )                                                                   zCall( 0x00623AF0 );
    virtual void DisposeStaticWorld()                                                                              zCall( 0x00623C80 );
    virtual zCTree<zCVob>* AddVobAsChild( zCVob*, zCTree<zCVob>* )                                                 zCall( 0x006245A0 );
    virtual void RemoveVob( zCVob* )                                                                               zCall( 0x00624B70 );
    virtual void RemoveVobSubtree( zCVob* )                                                                        zCall( 0x00624D60 );
    virtual void MoveVobSubtreeTo( zCVob*, zCTree<zCVob>* )                                                        zCall( 0x00624DB0 );
    virtual zCPlayerGroup* GetPlayerGroup()                                                                        zCall( 0x00620050 );
    virtual zCVob* SearchVob( zCVob*, zCTree<zCVob>* )                                                             zCall( 0x00623F10 );
    virtual zCVob* SearchVobByID( unsigned long, zCTree<zCVob>* )                                                  zCall( 0x00623F60 );
    virtual zCVob* SearchVobByName( zSTRING const& )                                                               zCall( 0x00623FB0 );
    virtual void SearchVobListByName( zSTRING const&, zCArray<zCVob*>& )                                           zCall( 0x00624090 );
    virtual void SearchVobListByClass( zCClassDef*, zCArray<zCVob*>&, zCTree<zCVob>* )                             zCall( 0x00624250 );
    virtual void SearchVobListByBaseClass( zCClassDef*, zCArray<zCVob*>&, zCTree<zCVob>* )                         zCall( 0x00624320 );
    virtual void VobAddedToWorld( zCVob* )                                                                         zCall( 0x00624830 );
    virtual void VobRemovedFromWorld( zCVob* )                                                                     zCall( 0x00624970 );
    virtual void RenderWaynet( zCCamera* )                                                                         zCall( 0x00620450 );

    static zTWorldLoadMode& s_worldLoadMode;
    static zTWorldSaveMode& s_worldSaveMode;
    static zTWorldLoadMergeMode& s_worldMergeMode;
    static int& s_bFadeOutFarVerts;
    static int& s_bWaveAnisEnabled;
    static int& s_bAlternateRenderOrder;
    static int& s_bEnvMappingEnabled;
    static int& s_bAmbientVobsEnabled;
    static int& showTextureStats;

    // user API
    #include "zCWorld.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZWORLD_H__VER3__