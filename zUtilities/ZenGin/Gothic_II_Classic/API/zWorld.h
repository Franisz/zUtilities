// Supported with union (c) 2018-2021 Union team

#ifndef __ZWORLD_H__VER2__
#define __ZWORLD_H__VER2__

#include "zObject.h"
#include "zBsp.h"
#include "zVob.h"
#include "zZone.h"

namespace Gothic_II_Classic {
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

    void zCPatch_OnInit() zCall( 0x00624940 );
    zCPatch()             zInit( zCPatch_OnInit() );
    void DoTransfers()    zCall( 0x00627880 );

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
    int CheckRaySurfaceIntersection( zVEC3&, zVEC3&, zVEC3&, zCPolygon*& ) zCall( 0x00624990 );
    ~zCPatchMap()                                                          zCall( 0x00626FE0 );

    // user API
    #include "zCPatchMap.inl"
  };
    
#pragma pack( pop )

  // sizeof 6254h
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
    zSTRING m_strlevelName;                                      // sizeof 14h    offset 68h
    int compiled;                                                // sizeof 04h    offset 7Ch
    int compiledEditorMode;                                      // sizeof 04h    offset 80h
    int traceRayIgnoreVobFlag;                                   // sizeof 04h    offset 84h
    zTWld_RenderMode worldRenderMode;                            // sizeof 04h    offset 88h
    zCWayNet* wayNet;                                            // sizeof 04h    offset 8Ch
    int masterFrameCtr;                                          // sizeof 04h    offset 90h
    float vobFarClipZ;                                           // sizeof 04h    offset 94h
    float vobFarClipZScalability;                                // sizeof 04h    offset 98h
    zCArray<zCVob*> traceRayVobList;                             // sizeof 0Ch    offset 9Ch
    zCArray<zCVob*> traceRayTempIgnoreVobList;                   // sizeof 0Ch    offset A8h
    int renderingFirstTime;                                      // sizeof 04h    offset B4h
    int showWaynet;                                              // sizeof 04h    offset B8h
    int showTraceRayLines;                                       // sizeof 04h    offset BCh
    int showTextureStats;                                        // sizeof 04h    offset C0h
    zCViewProgressBar* progressBar;                              // sizeof 04h    offset C4h
    unsigned long unarchiveFileLen;                              // sizeof 04h    offset C8h
    unsigned long unarchiveStartPosVobtree;                      // sizeof 04h    offset CCh
    int numVobsInWorld;                                          // sizeof 04h    offset D0h
    zCArray<zCWorldPerFrameCallback*> perFrameCallbackList;      // sizeof 0Ch    offset D4h
    zCSkyControler* skyControlerIndoor;                          // sizeof 04h    offset E0h
    zCSkyControler* skyControlerOutdoor;                         // sizeof 04h    offset E4h
    zCSkyControler* activeSkyControler;                          // sizeof 04h    offset E8h
    zCArray<zCZone*> zoneGlobalList;                             // sizeof 0Ch    offset ECh
    zCArraySort<zCZone*> zoneActiveList;                         // sizeof 10h    offset F8h
    zCArraySort<zCZone*> zoneLastClassList;                      // sizeof 10h    offset 108h
    zCVobBBox3DSorter<zCZone> zoneBoxSorter;                     // sizeof 44h    offset 118h
    zCVobBBox3DSorter<zCZone>::zTBoxSortHandle zoneActiveHandle; // sizeof 44h    offset 15Ch
    int addZonesToWorld;                                         // sizeof 04h    offset 1A0h
    int showZonesDebugInfo;                                      // sizeof 04h    offset 1A4h
    zCCBspTree* cbspTree;                                        // sizeof 04h    offset 1A8h
    zCBspTree bspTree;                                           // sizeof 90h    offset 1ACh
    zCArray<zCVob*> activeVobList;                               // sizeof 0Ch    offset 23Ch
    zCArray<zCVob*> walkList;                                    // sizeof 0Ch    offset 248h
    zCArray<zCVob*> vobHashTable[zNUM_VOB_HASH];                 // sizeof 6000h  offset 254h

    void zCWorld_OnInit()                                                                                          zCall( 0x006182F0 );
    zCWorld()                                                                                                      zInit( zCWorld_OnInit() );
    zCSkyControler* GetActiveSkyControler()                                                                        zCall( 0x00618C50 );
    void SetSkyControlerIndoor( zCSkyControler* )                                                                  zCall( 0x00618C80 );
    void SetSkyControlerOutdoor( zCSkyControler* )                                                                 zCall( 0x00618CC0 );
    void AddZone( zCZone* )                                                                                        zCall( 0x00618D70 );
    void RemoveZone( zCZone* )                                                                                     zCall( 0x00618EE0 );
    void RemoveAllZones()                                                                                          zCall( 0x00619020 );
    void UpdateZone( zCZone* )                                                                                     zCall( 0x00619090 );
    void ProcessZones()                                                                                            zCall( 0x006190A0 );
    void ShowZonesDebugInfo()                                                                                      zCall( 0x00619710 );
    void ShowTextureStats()                                                                                        zCall( 0x00619B30 );
    void Render( zCCamera& )                                                                                       zCall( 0x00619FB0 );
    int __fastcall TraceRayFirstHit( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int )                     zCall( 0x0061A210 );
    int __fastcall TraceRayNearestHit( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int )                   zCall( 0x0061A410 );
    int __fastcall TraceRayFirstHit( zVEC3 const&, zVEC3 const&, zCVob*, int )                                     zCall( 0x0061A6E0 );
    int __fastcall TraceRayNearestHit( zVEC3 const&, zVEC3 const&, zCVob*, int )                                   zCall( 0x0061A810 );
    int __fastcall TraceRayFirstHitCache( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int, zCRayCache* )   zCall( 0x0061A940 );
    int __fastcall TraceRayFirstHitCache( zVEC3 const&, zVEC3 const&, zCVob*, int, zCRayCache* )                   zCall( 0x0061AAA0 );
    int __fastcall TraceRayNearestHitCache( zVEC3 const&, zVEC3 const&, zCArray<zCVob*> const*, int, zCRayCache* ) zCall( 0x0061AC60 );
    int __fastcall TraceRayNearestHitCache( zVEC3 const&, zVEC3 const&, zCVob*, int, zCRayCache* )                 zCall( 0x0061ADC0 );
    int __fastcall PickScene( zCCamera&, int, int, float )                                                         zCall( 0x0061AF80 );
    int TraverseBsp( zCCBspTree*, zCTree<zCVob>*, int )                                                            zCall( 0x0061B1F0 );
    int TraverseBspAddVobsToMesh( zCCBspTree*, zCTree<zCVob>* )                                                    zCall( 0x0061B2F0 );
    void SaveBspTreeMesh3DS( zSTRING const& )                                                                      zCall( 0x0061B700 );
    void CompileWorld( zTBspTreeMode const&, float, int, int, zCArray<zCPolygon*>* )                               zCall( 0x0061B730 );
    void SearchZoneListByClass( zCClassDef*, zCArray<zCZone*>& )                                                   zCall( 0x0061CC70 );
    zCZone* SearchZoneDefaultByClass( zCClassDef* )                                                                zCall( 0x0061CDA0 );
    int ShouldAddThisVobToBsp( zCVob* ) const                                                                      zCall( 0x0061D020 );
    zCTree<zCVob>* AddVobAsChild_novt( zCVob*, zCVob* )                                                            zCall( 0x0061D060 );
    zCTree<zCVob>* AddVob( zCVob* )                                                                                zCall( 0x0061D080 );
    void RemoveVob_novt( zCTree<zCVob>* )                                                                          zCall( 0x0061D410 );
    void RemoveVobSubtree_r( zCTree<zCVob>*, int )                                                                 zCall( 0x0061D430 );
    void RemoveVobSubtree_novt( zCTree<zCVob>* )                                                                   zCall( 0x0061D600 );
    void MoveVobSubtreeTo_novt( zCVob*, zCVob* )                                                                   zCall( 0x0061D6E0 );
    void MoveVobSubtreeToWorldSpace( zCVob* )                                                                      zCall( 0x0061D700 );
    void RemoveVobFromLists( zCVob* )                                                                              zCall( 0x0061D720 );
    void PrintStatus()                                                                                             zCall( 0x0061D8F0 );
    void PrintGlobalVobTree( zCTree<zCVob>*, int )                                                                 zCall( 0x0061E350 );
    void PrintActiveVobs()                                                                                         zCall( 0x0061E610 );
    void UpdateVobTreeBspDependencies( zCTree<zCVob>* )                                                            zCall( 0x0061E850 );
    void MoveVobs()                                                                                                zCall( 0x0061E8C0 );
    void AdvanceClock( float )                                                                                     zCall( 0x0061E950 );
    void SaveBspTree( zFILE& )                                                                                     zCall( 0x0061E990 );
    int LoadBspTree( zFILE&, int )                                                                                 zCall( 0x0061EB10 );
    void DebugMarkOccluderPolys()                                                                                  zCall( 0x0061EC40 );
    void __fastcall UnarcTraverseVobs( zCArchiver&, zCTree<zCVob>* )                                               zCall( 0x0061EDE0 );
    zCViewProgressBar* GetProgressBar() const                                                                      zCall( 0x0061F230 );
    void __fastcall ArcTraverseVobs( zCArchiver&, zCTree<zCVob>*, int )                                            zCall( 0x0061FD20 );
    void TraverseVobTree( zCVobCallback&, void*, zCTree<zCVob>* )                                                  zCall( 0x00620790 );
    unsigned long GetVobHashIndex( zSTRING const& )                                                                zCall( 0x006207F0 );
    unsigned long GetVobHashIndex( zCVob* )                                                                        zCall( 0x00620820 );
    void InsertVobHashTable( zCVob* )                                                                              zCall( 0x00620860 );
    void RemoveVobHashTable( zCVob* )                                                                              zCall( 0x00620980 );
    zCVob* SearchVobHashTable( zSTRING const& )                                                                    zCall( 0x00620A10 );
    void SearchVobListHashTable( zSTRING const&, zCArray<zCVob*>& )                                                zCall( 0x00620AF0 );
    void SetOwnerSession( zCSession* )                                                                             zCall( 0x00620CB0 );
    zCSession* GetOwnerSession()                                                                                   zCall( 0x00620D00 );
    void ResetCutscenePlayer()                                                                                     zCall( 0x00620D10 );
    void RegisterPerFrameCallback( zCWorldPerFrameCallback* )                                                      zCall( 0x00620D60 );
    void UnregisterPerFrameCallback( zCWorldPerFrameCallback* )                                                    zCall( 0x00620E90 );
    void LightWorldStaticUncompiled( zCTree<zCVob>* )                                                              zCall( 0x006223B0 );
    void LightWorldStaticCompiled()                                                                                zCall( 0x006227F0 );
    void GenerateStaticVertexLighting()                                                                            zCall( 0x00622FE0 );
    int LightingTestRay( zVEC3 const&, zVEC3 const&, zVEC3&, zCPolygon*& )                                         zCall( 0x006232F0 );
    int GetSurfaceLightmapBBox2D( zCArray<zCPolygon*>&, zTBBox2D&, int* const )                                    zCall( 0x006233B0 );
    zVEC3 GetPhongNormal( zCPolygon*, zVEC3 const& )                                                               zCall( 0x00623810 );
    zCPatchMap* GeneratePatchMapFromSurface( zCArray<zCPolygon*>& )                                                zCall( 0x00623BD0 );
    void GenerateLightmapFromPatchMap( zCPatchMap* )                                                               zCall( 0x00624A30 );
    void LightPatchMap( zCPatchMap* )                                                                              zCall( 0x00625D40 );
    void GenerateSurfaces( int, zTBBox3D* )                                                                        zCall( 0x006261F0 );
    void MakeTransfers()                                                                                           zCall( 0x00627080 );
    void GenerateLightmapsRadiosity( zTBBox3D* )                                                                   zCall( 0x006279D0 );
    void GenerateLightmaps( zTStaticWorldLightMode const&, zTBBox3D* )                                             zCall( 0x00627C20 );
    void GenerateStaticWorldLighting( zTStaticWorldLightMode const&, zTBBox3D* )                                   zCall( 0x006283F0 );
    void MakeVobLightingDirty()                                                                                    zCall( 0x006286E0 );
    int GetShowTextureStats() const                                                                                zCall( 0x0062FA10 );
    void SetShowTextureStats( int )                                                                                zCall( 0x0062FA20 );
    void SetVobFarClipZScalability( float )                                                                        zCall( 0x0062FA30 );
    zCBspTree* GetBspTree()                                                                                        zCall( 0x006732A0 );
    static zCObject* _CreateNewInstance()                                                                          zCall( 0x00618260 );
    static int ActiveZoneListCompare( void const*, void const* )                                                   zCall( 0x00618D20 );
    static int GetWaveAnisEnabled()                                                                                zCall( 0x0062F9F0 );
    static void SetWaveAnisEnabled( int )                                                                          zCall( 0x0062FA00 );
    virtual zCClassDef* _GetClassDef() const                                                                       zCall( 0x006188F0 );
    virtual void Archive( zCArchiver& )                                                                            zCall( 0x00620110 );
    virtual void Unarchive( zCArchiver& )                                                                          zCall( 0x0061F240 );
    virtual ~zCWorld()                                                                                             zCall( 0x006189A0 );
    virtual int LoadWorld( zSTRING const&, zTWorldLoadMode )                                                       zCall( 0x0061F940 );
    virtual int SaveWorld( zSTRING const&, zTWorldSaveMode, int, int )                                             zCall( 0x00620430 );
    virtual zCVob* MergeVobSubtree( zSTRING const&, zCVob*, zTWorldLoadMergeMode )                                 zCall( 0x0061FC60 );
    virtual int SaveVobSubtree( zSTRING const&, zCVob*, int, int )                                                 zCall( 0x006206D0 );
    virtual void DisposeWorld()                                                                                    zCall( 0x0061C5A0 );
    virtual int DisposeVobs( zCTree<zCVob>* )                                                                      zCall( 0x0061C1D0 );
    virtual int DisposeVobsDbg( zCTree<zCVob>* )                                                                   zCall( 0x0061C360 );
    virtual void DisposeStaticWorld()                                                                              zCall( 0x0061C4F0 );
    virtual zCTree<zCVob>* AddVobAsChild( zCVob*, zCTree<zCVob>* )                                                 zCall( 0x0061CE10 );
    virtual void RemoveVob( zCVob* )                                                                               zCall( 0x0061D3E0 );
    virtual void RemoveVobSubtree( zCVob* )                                                                        zCall( 0x0061D5D0 );
    virtual void MoveVobSubtreeTo( zCVob*, zCTree<zCVob>* )                                                        zCall( 0x0061D620 );
    virtual zCPlayerGroup* GetPlayerGroup()                                                                        zCall( 0x00618900 );
    virtual zCVob* SearchVob( zCVob*, zCTree<zCVob>* )                                                             zCall( 0x0061C780 );
    virtual zCVob* SearchVobByID( unsigned long, zCTree<zCVob>* )                                                  zCall( 0x0061C7D0 );
    virtual zCVob* SearchVobByName( zSTRING const& )                                                               zCall( 0x0061C820 );
    virtual void SearchVobListByName( zSTRING const&, zCArray<zCVob*>& )                                           zCall( 0x0061C900 );
    virtual void SearchVobListByClass( zCClassDef*, zCArray<zCVob*>&, zCTree<zCVob>* )                             zCall( 0x0061CAC0 );
    virtual void SearchVobListByBaseClass( zCClassDef*, zCArray<zCVob*>&, zCTree<zCVob>* )                         zCall( 0x0061CB90 );
    virtual void VobAddedToWorld( zCVob* )                                                                         zCall( 0x0061D0A0 );
    virtual void VobRemovedFromWorld( zCVob* )                                                                     zCall( 0x0061D1E0 );
    virtual void RenderWaynet( zCCamera* )                                                                         zCall( 0x00618D00 );

    // static properties
    static zTWorldLoadMode& s_worldLoadMode;
    static zTWorldSaveMode& s_worldSaveMode;
    static zTWorldLoadMergeMode& s_worldMergeMode;
    static int& s_bFadeOutFarVerts;
    static int& s_bWaveAnisEnabled;
    static int& s_bAlternateRenderOrder;
    static int& s_bEnvMappingEnabled;
    static int& s_bAmbientVobsEnabled;

    // user API
    #include "zCWorld.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZWORLD_H__VER2__