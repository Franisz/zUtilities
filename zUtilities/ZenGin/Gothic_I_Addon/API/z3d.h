// Supported with union (c) 2018-2021 Union team

#ifndef __Z3D_H__VER1__
#define __Z3D_H__VER1__

namespace Gothic_I_Addon {
  const int zMAX_POLY_VERTS      = 21;
  const int zMAX_POLY_CLIP_VERTS = zMAX_POLY_VERTS * 2;
  const int zTCAM_POLY_NUM_VERT  = 4;

  enum zTShadeMode {
    zSHADE_NORMAL,
    zSHADE_NOTHING,
    zSHADE_CONSTANT,
    zSHADE_GOURAUD,
    zSHADE_LIGHTMAP
  };

  enum zPROJECTION {
    PERSPECTIVE,
    ORTHOGONAL
  };

  enum zTCam_ClipType {
    zCAM_CLIP_TRIV_IN,
    zCAM_CLIP_TRIV_OUT,
    zCAM_CLIP_CROSSING
  };

  enum zTCam_DrawMode {
    zCAM_DRAW_NORMAL,
    zCAM_DRAW_NOTHING,
    zCAM_DRAW_WIRE,
    zCAM_DRAW_FLAT,
    zCAM_DRAW_TEX
  };

  enum zTCamTrafoType {
    zCAM_TRAFO_WORLD,
    zCAM_TRAFO_VIEW,
    zCAM_TRAFO_WORLDVIEW,
    zCAM_TRAFO_WORLDVIEW_INV,
    zCAM_TRAFO_VIEW_INV
  };

  // sizeof 24h
  struct zTEngineStats {
    int numVobAI;                // sizeof 04h    offset 00h
    int numVobAI_only;           // sizeof 04h    offset 04h
    int numVobAI_full;           // sizeof 04h    offset 08h
    int numVob_EndMovement;      // sizeof 04h    offset 0Ch
    int numVobFirstTestInterpen; // sizeof 04h    offset 10h
    int numModelUpdateBBoxTree;  // sizeof 04h    offset 14h
    int numPolysClipped;         // sizeof 04h    offset 18h
    int numPlanesClipped;        // sizeof 04h    offset 1Ch
    int numTraceRay;             // sizeof 04h    offset 20h

    zTEngineStats() {}
    void PrintScreen( int, int ) zCall( 0x0050E510 );

    // user API
    #include "zTEngineStats.inl"
  };

  // sizeof 0Ch
  class zCLineCache {
  public:
    // sizeof 14h
    struct zTCacheEntry {
      int x1;    // sizeof 04h    offset 00h
      int y1;    // sizeof 04h    offset 04h
      int x2;    // sizeof 04h    offset 08h
      int y2;    // sizeof 04h    offset 0Ch
      int color; // sizeof 04h    offset 10h

      zTCacheEntry() {}

      // user API
      #include "zCLineCache_zTCacheEntry.inl"
    };

    int numEntries;      // sizeof 04h    offset 00h
    int nextFree;        // sizeof 04h    offset 04h
    zTCacheEntry* cache; // sizeof 04h    offset 08h

    zCLineCache() {}
    ~zCLineCache()                                         zCall( 0x0050EA10 );
    void Line( int, int, int, int, zCOLOR )                zCall( 0x0050EA20 );
    void Flush( zCViewBase* )                              zCall( 0x0050EAC0 );
    void Line3D( zVEC3 const&, zVEC3 const&, zCOLOR, int ) zCall( 0x0050EB50 );
    void LineCS3D( zVEC3 const&, zVEC3 const&, zCOLOR )    zCall( 0x0050EF00 );

    // user API
    #include "zCLineCache.inl"
  };

  // sizeof 38h
  struct zTViewportData {
    int xmin;              // sizeof 04h    offset 00h
    int ymin;              // sizeof 04h    offset 04h
    int xdim;              // sizeof 04h    offset 08h
    int ydim;              // sizeof 04h    offset 0Ch
    float xminFloat;       // sizeof 04h    offset 10h
    float yminFloat;       // sizeof 04h    offset 14h
    float xmaxFloat;       // sizeof 04h    offset 18h
    float ymaxFloat;       // sizeof 04h    offset 1Ch
    float xdimFloat;       // sizeof 04h    offset 20h
    float ydimFloat;       // sizeof 04h    offset 24h
    float xdimFloatMinus1; // sizeof 04h    offset 28h
    float ydimFloatMinus1; // sizeof 04h    offset 2Ch
    float xcenter;         // sizeof 04h    offset 30h
    float ycenter;         // sizeof 04h    offset 34h

    zTViewportData() {}

    // user API
    #include "zTViewportData.inl"
  };

  // sizeof 918h
  class zCCamera {
  public:
    enum {
      CLIP_FLAGS_FULL        = 63,
      CLIP_FLAGS_FULL_WO_FAR = 15
    };

    enum {
      NUM_FRUSTUM_PLANES        = 6,
      NUM_FRUSTUM_PLANES_WO_FAR = 4
    };

    // sizeof 18h
    struct zTCamVertSimple {
      float x;      // sizeof 04h    offset 00h
      float y;      // sizeof 04h    offset 04h
      float z;      // sizeof 04h    offset 08h
      zVEC2 texuv;  // sizeof 08h    offset 0Ch
      zCOLOR color; // sizeof 04h    offset 14h

      zTCamVertSimple() {}

      // user API
      #include "zCCamera_zTCamVertSimple.inl"
    };

    zTPlane frustumplanes[NUM_FRUSTUM_PLANES];         // sizeof 60h    offset 00h
    unsigned char signbits[NUM_FRUSTUM_PLANES];        // sizeof 06h    offset 60h
    zTViewportData vpData;                             // sizeof 38h    offset 68h
    zCViewBase* targetView;                            // sizeof 04h    offset A0h
    zMAT4 camMatrix;                                   // sizeof 40h    offset A4h
    zMAT4 camMatrixInv;                                // sizeof 40h    offset E4h
    int tremorToggle;                                  // sizeof 04h    offset 124h
    float tremorScale;                                 // sizeof 04h    offset 128h
    zVEC3 tremorAmplitude;                             // sizeof 0Ch    offset 12Ch
    zVEC3 tremorOrigin;                                // sizeof 0Ch    offset 138h
    float tremorVelo;                                  // sizeof 04h    offset 144h
    zMAT4 trafoView;                                   // sizeof 40h    offset 148h
    zMAT4 trafoViewInv;                                // sizeof 40h    offset 188h
    zMAT4 trafoWorld;                                  // sizeof 40h    offset 1C8h
    zCMatrixStack<zMAT4, 8> trafoViewStack;            // sizeof 204h   offset 208h
    zCMatrixStack<zMAT4, 8> trafoWorldStack;           // sizeof 204h   offset 40Ch
    zCMatrixStack<zMAT4, 8> trafoWorldViewStack;       // sizeof 204h   offset 610h
    zMAT4 trafoProjection;                             // sizeof 40h    offset 814h
    zTCamVertSimple polyCamVerts[zTCAM_POLY_NUM_VERT]; // sizeof 60h    offset 854h
    zCPolygon* poly;                                   // sizeof 04h    offset 8B4h
    zCMesh* polyMesh;                                  // sizeof 04h    offset 8B8h
    zCMaterial* polyMaterial;                          // sizeof 04h    offset 8BCh
    int screenFadeEnabled;                             // sizeof 04h    offset 8C0h
    zCOLOR screenFadeColor;                            // sizeof 04h    offset 8C4h
    int cinemaScopeEnabled;                            // sizeof 04h    offset 8C8h
    zCOLOR cinemaScopeColor;                           // sizeof 04h    offset 8CCh
    zPROJECTION projection;                            // sizeof 04h    offset 8D0h
    zTCam_DrawMode drawMode;                           // sizeof 04h    offset 8D4h
    zTShadeMode shadeMode;                             // sizeof 04h    offset 8D8h
    int drawWire;                                      // sizeof 04h    offset 8DCh
    float farClipZ;                                    // sizeof 04h    offset 8E0h
    float nearClipZ;                                   // sizeof 04h    offset 8E4h
    float viewDistanceX;                               // sizeof 04h    offset 8E8h
    float viewDistanceY;                               // sizeof 04h    offset 8ECh
    float viewDistanceXInv;                            // sizeof 04h    offset 8F0h
    float viewDistanceYInv;                            // sizeof 04h    offset 8F4h
    int vobFarClipZ;                                   // sizeof 04h    offset 8F8h
    float fovH;                                        // sizeof 04h    offset 8FCh
    float fovV;                                        // sizeof 04h    offset 900h
    zCVob* connectedVob;                               // sizeof 04h    offset 904h
    float topBottomSin;                                // sizeof 04h    offset 908h
    float topBottomCos;                                // sizeof 04h    offset 90Ch
    float leftRightSin;                                // sizeof 04h    offset 910h
    float leftRightCos;                                // sizeof 04h    offset 914h

    void zCCamera_OnInit()                                                                zCall( 0x0054CDB0 );
    void Project( zVEC3 const* const, float&, float& ) const                              zCall( 0x00533550 );
    zCCamera()                                                                            zInit( zCCamera_OnInit() );
    ~zCCamera()                                                                           zCall( 0x0054D090 );
    void PushTransform( zTCamTrafoType )                                                  zCall( 0x0054D110 );
    void PopTransform( zTCamTrafoType )                                                   zCall( 0x0054D1A0 );
    void SetTransform( zTCamTrafoType, zMAT4 const& )                                     zCall( 0x0054D2E0 );
    zMAT4 const& GetTransform( zTCamTrafoType )                                           zCall( 0x0054D440 );
    void Activate()                                                                       zCall( 0x0054D4A0 );
    void CreateProjectionMatrix( zMAT4&, float, float, float, float )                     zCall( 0x0054D5B0 );
    void UpdateProjectionMatrix()                                                         zCall( 0x0054D630 );
    float GetFOV() const                                                                  zCall( 0x0054D680 );
    void GetFOV( float&, float& ) const                                                   zCall( 0x0054D690 );
    void SetFOV( float )                                                                  zCall( 0x0054D6C0 );
    void SetFOV( float, float )                                                           zCall( 0x0054D700 );
    void UpdateViewport()                                                                 zCall( 0x0054D830 );
    void SetRenderTarget( zCViewBase* )                                                   zCall( 0x0054D970 );
    void SetUpFrustum()                                                                   zCall( 0x0054D990 );
    void SetNearClipZ( float )                                                            zCall( 0x0054DC90 );
    void SetFarClipZ( float )                                                             zCall( 0x0054DD00 );
    zTCam_ClipType BBox3DInFrustum( zTBBox3D const& )                                     zCall( 0x0054DE40 );
    zTCam_ClipType BBox3DInFrustum( zTBBox3D const&, int& )                               zCall( 0x0054DEA0 );
    void StopTremor()                                                                     zCall( 0x0054E140 );
    void AddTremor( zVEC3 const&, float, float, zVEC3 const& )                            zCall( 0x0054E150 );
    void PreRenderProcessing()                                                            zCall( 0x0054E370 );
    void PostRenderProcessing()                                                           zCall( 0x0054E520 );
    void GetCamPos( zVEC3& ) const                                                        zCall( 0x0054E560 );
    void InitDrawPolySimple()                                                             zCall( 0x0054E590 );
    void CleanupDrawPolySimple()                                                          zCall( 0x0054E660 );
    void DrawPolySimple( zTCamVertSimple*, int, zCMaterial*, int )                        zCall( 0x0054E6C0 );
    void SetRenderScreenFade( zCOLOR )                                                    zCall( 0x0054E7D0 );
    void SetRenderCinemaScope( zCOLOR )                                                   zCall( 0x0054E7F0 );
    void RenderScreenFade()                                                               zCall( 0x0054E810 );
    void RenderCinemaScope()                                                              zCall( 0x0054E8E0 );
    int __fastcall ScreenProjectionTouchesPortalRough( zTBBox3D const&, zTBBox2D const& ) zCall( 0x0054EA40 );
    int __fastcall ScreenProjectionTouchesPortal( zTBBox3D const&, zTBBox2D const& )      zCall( 0x0054ED10 );
    void Project( zVEC3 const* const, int&, int& )                                        zCall( 0x00578B50 );
    void BackProject( int, int, zVEC3& ) const                                            zCall( 0x00658690 );

    // static properties
    static zCCamera*& activeCam;
    static zVEC3& activeCamPos;

    // user API
    #include "zCCamera.inl"
  };

  // sizeof 10h
  class zCVertex {
  public:
    zMEMPOOL_DECLARATION( zCVertex, 0x008B51D0 )

    zVEC3 position;                      // sizeof 0Ch    offset 00h
    union {
      group {
        unsigned short transformedIndex; // sizeof 02h    offset 0Ch
        unsigned short myIndex;          // sizeof 02h    offset 0Eh
      };
      unsigned int hackData;
    };

    void zCVertex_OnInit()                     zCall( 0x00570850 );
    void Draw( zCOLOR const&, int )            zCall( 0x0050F170 );
    zCVertexTransform* CreateVertexTransform() zCall( 0x0050F290 );
    ~zCVertex()                                zCall( 0x00568590 );
    zCVertex()                                 zInit( zCVertex_OnInit() );
    void ResetVertexTransform()                zCall( 0x005BF270 );
    static void ResetVertexTransforms()        zCall( 0x0050F260 );

    // user API
    #include "zCVertex.inl"
  };

  // sizeof 20h
  class zCVertFeature {
  public:
    zMEMPOOL_DECLARATION( zCVertFeature, 0x008B5240 )

    zVEC3 vertNormal; // sizeof 0Ch    offset 00h
    zCOLOR lightStat; // sizeof 04h    offset 0Ch
    zCOLOR lightDyn;  // sizeof 04h    offset 10h
    float texu;       // sizeof 04h    offset 14h
    float texv;       // sizeof 04h    offset 18h
    float _padding;   // sizeof 04h    offset 1Ch

    void zCVertFeature_OnInit() zCall( 0x0056DDC0 );
    zCVertFeature()             zInit( zCVertFeature_OnInit() );

    // user API
    #include "zCVertFeature.inl"
  };

  // sizeof 38h
  class zCPolygon {
  public:
    zMEMPOOL_DECLARATION( zCPolygon, 0x008B5280 )

    enum zTPortalType {
      zPORTAL_TYPE_NONE,
      zPORTAL_TYPE_SMALL,
      zPORTAL_TYPE_BIG,
      zPORTAL_TYPE_BIG_NOFADE
    };

#pragma pack( push, 1 )
    // sizeof 04h
    struct TFlags {
      unsigned char portalPoly          : 2;  // sizeof 02h    offset bit
      unsigned char occluder            : 1;  // sizeof 01h    offset bit
      unsigned char sectorPoly          : 1;  // sizeof 01h    offset bit
      unsigned char lodFlag             : 1;  // sizeof 01h    offset bit
      unsigned char portalIndoorOutdoor : 1;  // sizeof 01h    offset bit
      unsigned char ghostOccluder       : 1;  // sizeof 01h    offset bit
      unsigned char normalMainAxis      : 2;  // sizeof 02h    offset bit
      unsigned short sectorIndex        : 16; // sizeof 10h    offset bit

      TFlags() {}

      // user API
      #include "zCPolygon_TFlags.inl"
    };
#pragma pack( pop )

    zCVertex** vertex;         // sizeof 04h    offset 00h
    int lastTimeDrawn;         // sizeof 04h    offset 04h
    zTPlane polyPlane;         // sizeof 10h    offset 08h
    zCMaterial* material;      // sizeof 04h    offset 18h
    zCLightMap* lightmap;      // sizeof 04h    offset 1Ch
    zCVertex** clipVert;       // sizeof 04h    offset 20h
    zCVertFeature** clipFeat;  // sizeof 04h    offset 24h
    int numClipVert;           // sizeof 04h    offset 28h
    zCVertFeature** feature;   // sizeof 04h    offset 2Ch
    unsigned char polyNumVert; // sizeof 01h    offset 30h
    TFlags flags;              // sizeof 04h    offset 31h

    void zCPolygon_OnInit()                                                                                           zCall( 0x005B19F0 );
    int RenderPoly( int )                                                                                             zCall( 0x0052EB30 );
    int TransformProjectLight()                                                                                       zCall( 0x0052EFA0 );
    void SetMaterial( zCMaterial* )                                                                                   zCall( 0x0053A0A0 );
    zCPolygon()                                                                                                       zInit( zCPolygon_OnInit() );
    ~zCPolygon()                                                                                                      zCall( 0x005B1A20 );
    int __fastcall ClipToPlane( zCVertex**, zCVertFeature**, int, zCVertex**, zCVertFeature**, int&, zTPlane const& ) zCall( 0x005B1B00 );
    void Unclip()                                                                                                     zCall( 0x005B2080 );
    void CopyClipFeaturesForTexAniMapping()                                                                           zCall( 0x005B2100 );
    int __fastcall ClipToFrustum( int )                                                                               zCall( 0x005B2170 );
    int ClassifyPlane( zTPlane const& )                                                                               zCall( 0x005B23B0 );
    int ClassifyPlaneBSPBuild( zTPlane const& )                                                                       zCall( 0x005B2440 );
    int CalcNormal()                                                                                                  zCall( 0x005B24D0 );
    void GetScreenBBox2D( zTBBox2D& )                                                                                 zCall( 0x005B28D0 );
    void DrawWire( zCOLOR ) const                                                                                     zCall( 0x005B2970 );
    void LightDynCamSpace( zVEC3 const&, int )                                                                        zCall( 0x005B31B0 );
    void __fastcall LightClippedPoly( zCArray<zCVobLight*> const&, int )                                              zCall( 0x005B3370 );
    zVEC3 GetLightStatAtPos( zVEC3 const& )                                                                           zCall( 0x005B3950 );
    int __fastcall CheckRayPolyIntersection( zVEC3 const&, zVEC3 const&, zVEC3&, float& ) const                       zCall( 0x005B40A0 );
    int __fastcall CheckRayPolyIntersection2Sided( zVEC3 const&, zVEC3 const&, zVEC3&, float& ) const                 zCall( 0x005B4460 );
    void CalcNormalMainAxis()                                                                                         zCall( 0x005B47E0 );
    zTBBox3D GetBBox3D() const                                                                                        zCall( 0x005B4840 );
    zVEC3 GetCenter()                                                                                                 zCall( 0x005B48F0 );
    void SetMapping( zVEC2 const&, zVEC2 const&, zVEC2 const& )                                                       zCall( 0x005B4980 );
    void SetMapping( int, zVEC2 const& )                                                                              zCall( 0x005B49D0 );
    void Flip()                                                                                                       zCall( 0x005B49F0 );
    int VertPartOfPoly( zCVertex* ) const                                                                             zCall( 0x005B4A30 );
    int EdgePartOfPoly( zCVertex*, zCVertex* ) const                                                                  zCall( 0x005B4A60 );
    void TexTranslate( zVEC2 const& )                                                                                 zCall( 0x005B4AB0 );
    void TexSetTranslation( zVEC2 const& )                                                                            zCall( 0x005B4AF0 );
    void TexScale( float, float )                                                                                     zCall( 0x005B4B30 );
    void TexScale( zVEC2&, float, float )                                                                             zCall( 0x005B4B70 );
    void TexRotate( zVEC2&, float )                                                                                   zCall( 0x005B4C30 );
    void TexMirrorU( float )                                                                                          zCall( 0x005B4E10 );
    void TexMirrorV( float )                                                                                          zCall( 0x005B4E40 );
    void TexShearU( float )                                                                                           zCall( 0x005B4E70 );
    void TexShearV( float )                                                                                           zCall( 0x005B4F30 );
    void TexApplyPlanarMapping( zVEC3 const&, zVEC3 const&, zVEC3 const&, int )                                       zCall( 0x005B4FF0 );
    void TexApplyPlanarMapping( float, float, int )                                                                   zCall( 0x005B51C0 );
    void TexCorrectUV()                                                                                               zCall( 0x005B5840 );
    void AllocVerts( int )                                                                                            zCall( 0x005B59A0 );
    void AddVertex( zCVertex* )                                                                                       zCall( 0x005B5B30 );
    void AddVertexAndFeature( zCVertex*, zCVertFeature* )                                                             zCall( 0x005B5B50 );
    void SetVertices( zCVertex*, zCVertex*, zCVertex* )                                                               zCall( 0x005B5B90 );
    void SetVertices( zCVertex*, zCVertex*, zCVertex*, zCVertex*, int )                                               zCall( 0x005B5BF0 );
    void SetVertex( int, zCVertex* )                                                                                  zCall( 0x005B5C60 );
    void SetFeature( int, zCVertFeature* )                                                                            zCall( 0x005B5CA0 );
    void CopyValuesInto( zCPolygon* ) const                                                                           zCall( 0x005B5CE0 );
    void CopyPolyInto( zCPolygon* ) const                                                                             zCall( 0x005B5DA0 );
    void RemoveVerticesAndFeatures()                                                                                  zCall( 0x005B5E00 );
    float GetArea() const                                                                                             zCall( 0x005B5E90 );
    float GetLongestEdgeLen() const                                                                                   zCall( 0x005B5F30 );
    void ResetStaticLight()                                                                                           zCall( 0x005B5FB0 );
    void SetStaticLight( zCOLOR )                                                                                     zCall( 0x005B5FF0 );
    void SetLightDyn( zCOLOR )                                                                                        zCall( 0x005B6020 );
    void SetLightStatAlpha( unsigned char )                                                                           zCall( 0x005B6050 );
    void ResetLightDynToLightStat()                                                                                   zCall( 0x005B6080 );
    void AddToLightDyn( zCOLOR )                                                                                      zCall( 0x005B60B0 );
    int __fastcall CheckBBoxPolyIntersection( zTBBox3D const& ) const                                                 zCall( 0x005B6150 );
    int __fastcall CheckBSpherePolyIntersection( zTBSphere3D const& ) const                                           zCall( 0x005B6630 );
    void SplitPoly( zTPlane const&, zCPolygon*, zCPolygon*, zCMesh* )                                                 zCall( 0x005B6800 );
    int __fastcall IsIntersectingProjection( zCPolygon*, zVEC3 const& )                                               zCall( 0x005B6DC0 );
    int __fastcall IsIntersecting( zCPolygon* )                                                                       zCall( 0x005B75F0 );
    void LightStatic( zCVobLight&, zVEC3 const&, zMAT4&, zCWorld* )                                                   zCall( 0x0061BD10 );
    static void* S_AllocPointers( int )                                                                               zCall( 0x005B18F0 );
    static void S_DeletePointers( int, void* )                                                                        zCall( 0x005B1920 );
    static zCVertFeature* S_AllocVertFeatures( int )                                                                  zCall( 0x005B1950 );
    static void S_DeleteVertFeatures( int, zCVertFeature* )                                                           zCall( 0x005B19C0 );
    static void PrepareRendering()                                                                                    zCall( 0x005B2060 );
    static void LightPolyList( zCArray<zCVobLight*> const&, zCPolygon**, int, zMAT4* )                                zCall( 0x005B2A40 );
    static void TexApplyPlanarMapping( zCList<zCPolygon> const&, float, float, int )                                  zCall( 0x005B5290 );
    static void AlignPolyListToAvgPlane( zCArray<zCPolygon*> )                                                        zCall( 0x005B54E0 );

    // static properties
    static zCVertex*& s_clipVertScene;
    static int& s_numClipVertScene;
    static zCVertFeature*& s_clipFeatScene;
    static int& s_numClipFeatScene;
    static int& s_numVertListScene;
    static int& s_numFeatListScene;
    static zCVertex**& s_actClipVert;
    static int& s_actNumClipVert;

    // user API
    #include "zCPolygon.inl"
  };

  // sizeof 44h
  class zCPortal : public zCPolygon {
  public:
    zMEMPOOL_DECLARATION( zCPortal, 0x008B5260 )

    zCBspNode* frontBspNode; // sizeof 04h    offset 38h
    zCBspNode* backBspNode;  // sizeof 04h    offset 3Ch
    int lastTimeCompletely;  // sizeof 04h    offset 40h

    zCPortal() {}
    void zCPortal_OnInit( zTPlane const&, zCMesh* )                     zCall( 0x0052DFE0 );
    void RemoveFromBsp()                                                zCall( 0x0052DFC0 );
    zCPortal( zTPlane const& a0, zCMesh* a1 )                           zInit( zCPortal_OnInit( a0, a1 ));
    void Init()                                                         zCall( 0x005419B0 );
    ~zCPortal()                                                         zCall( 0x00541E50 );

    // static properties
    static zCMaterial*& portalDummyMaterial;

    // user API
    #include "zCPortal.inl"
  };

  inline void GetProjection( int& x, int& y, zVEC3 v ) {
    float fPixelPosX = FLT_MAX;
    float fPixelPosY = FLT_MAX;
    zCCamera* pCamera = zCCamera::activeCam;
    pCamera->Activate();
    zVEC3 vec = pCamera->camMatrix * v;
    if( vec[2] > 0 )
      pCamera->Project( &vec, fPixelPosX, fPixelPosY );

    x = screen->anx( fPixelPosX );
    y = screen->any( fPixelPosY );
  }

} // namespace Gothic_I_Addon

#endif // __Z3D_H__VER1__