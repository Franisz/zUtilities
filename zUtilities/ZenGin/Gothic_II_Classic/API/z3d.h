// Supported with union (c) 2018-2021 Union team

#ifndef __Z3D_H__VER2__
#define __Z3D_H__VER2__

namespace Gothic_II_Classic {
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
    void PrintScreen( int, int ) zCall( 0x00507F40 );

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
    ~zCLineCache()                                         zCall( 0x00508560 );
    void Line( int, int, int, int, zCOLOR )                zCall( 0x00508570 );
    void Flush( zCViewBase* )                              zCall( 0x00508600 );
    void Line3D( zVEC3 const&, zVEC3 const&, zCOLOR, int ) zCall( 0x005086A0 );
    void LineCS3D( zVEC3 const&, zVEC3 const&, zCOLOR )    zCall( 0x00508AA0 );

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

  // sizeof 934h
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
    zSTRING screenFadeTexture;                         // sizeof 14h    offset 8C8h
    float screenFadeTextureAniFPS;                     // sizeof 04h    offset 8DCh
    zTRnd_AlphaBlendFunc screenFadeTextureBlendFunc;   // sizeof 04h    offset 8E0h
    int cinemaScopeEnabled;                            // sizeof 04h    offset 8E4h
    zCOLOR cinemaScopeColor;                           // sizeof 04h    offset 8E8h
    zPROJECTION projection;                            // sizeof 04h    offset 8ECh
    zTCam_DrawMode drawMode;                           // sizeof 04h    offset 8F0h
    zTShadeMode shadeMode;                             // sizeof 04h    offset 8F4h
    int drawWire;                                      // sizeof 04h    offset 8F8h
    float farClipZ;                                    // sizeof 04h    offset 8FCh
    float nearClipZ;                                   // sizeof 04h    offset 900h
    float viewDistanceX;                               // sizeof 04h    offset 904h
    float viewDistanceY;                               // sizeof 04h    offset 908h
    float viewDistanceXInv;                            // sizeof 04h    offset 90Ch
    float viewDistanceYInv;                            // sizeof 04h    offset 910h
    int vobFarClipZ;                                   // sizeof 04h    offset 914h
    float fovH;                                        // sizeof 04h    offset 918h
    float fovV;                                        // sizeof 04h    offset 91Ch
    zCVob* connectedVob;                               // sizeof 04h    offset 920h
    float topBottomSin;                                // sizeof 04h    offset 924h
    float topBottomCos;                                // sizeof 04h    offset 928h
    float leftRightSin;                                // sizeof 04h    offset 92Ch
    float leftRightCos;                                // sizeof 04h    offset 930h

    void zCCamera_OnInit()                                                                zCall( 0x00544C40 );
    void Project( zVEC3 const* const, float&, float& ) const                              zCall( 0x0052D0E0 );
    zCCamera()                                                                            zInit( zCCamera_OnInit() );
    ~zCCamera()                                                                           zCall( 0x00545070 );
    void PushTransform( zTCamTrafoType )                                                  zCall( 0x00545150 );
    void PopTransform( zTCamTrafoType )                                                   zCall( 0x005451E0 );
    void SetTransform( zTCamTrafoType, zMAT4 const& )                                     zCall( 0x00545320 );
    zMAT4 const& GetTransform( zTCamTrafoType )                                           zCall( 0x00545480 );
    void Activate()                                                                       zCall( 0x005454E0 );
    void CreateProjectionMatrix( zMAT4&, float, float, float, float )                     zCall( 0x005455F0 );
    void UpdateProjectionMatrix()                                                         zCall( 0x00545670 );
    float GetFOV() const                                                                  zCall( 0x005456C0 );
    void GetFOV( float&, float& ) const                                                   zCall( 0x005456D0 );
    void SetFOV( float )                                                                  zCall( 0x00545700 );
    void SetFOV( float, float )                                                           zCall( 0x00545740 );
    void UpdateViewport()                                                                 zCall( 0x00545870 );
    void SetRenderTarget( zCViewBase* )                                                   zCall( 0x005459B0 );
    void SetRenderScreenFadeTex( zSTRING )                                                zCall( 0x005459D0 );
    void SetUpFrustum()                                                                   zCall( 0x00545B00 );
    void SetFarClipZ( float )                                                             zCall( 0x00545FE0 );
    zTCam_ClipType BBox3DInFrustum( zTBBox3D const& )                                     zCall( 0x00546190 );
    zTCam_ClipType BBox3DInFrustum( zTBBox3D const&, int& )                               zCall( 0x005461F0 );
    void StopTremor()                                                                     zCall( 0x00546430 );
    void AddTremor( zVEC3 const&, float, float, zVEC3 const& )                            zCall( 0x00546440 );
    void PreRenderProcessing()                                                            zCall( 0x005465B0 );
    void PostRenderProcessing()                                                           zCall( 0x00546700 );
    void GetCamPos( zVEC3& ) const                                                        zCall( 0x00546740 );
    void InitDrawPolySimple()                                                             zCall( 0x00546770 );
    void CleanupDrawPolySimple()                                                          zCall( 0x00546830 );
    void DrawPolySimple( zTCamVertSimple*, int, zCMaterial*, int )                        zCall( 0x00546890 );
    void SetRenderScreenFade( zCOLOR )                                                    zCall( 0x005469A0 );
    void SetRenderScreenFadeTexAniFPS( float )                                            zCall( 0x005469C0 );
    void SetRenderScreenFadeTexBlendFunc( zTRnd_AlphaBlendFunc )                          zCall( 0x005469F0 );
    void SetRenderCinemaScope( zCOLOR )                                                   zCall( 0x00546A00 );
    void RenderScreenFade()                                                               zCall( 0x00546A20 );
    void RenderCinemaScope()                                                              zCall( 0x00546B10 );
    int __fastcall ScreenProjectionTouchesPortalRough( zTBBox3D const&, zTBBox2D const& ) zCall( 0x00546C60 );
    int __fastcall ScreenProjectionTouchesPortal( zTBBox3D const&, zTBBox2D const& )      zCall( 0x00546EE0 );
    void ProjectClamp( zCVertexTransform*, float ) const                                  zCall( 0x00566AB0 );
    void Project( zVEC3 const* const, int&, int& )                                        zCall( 0x00574F20 );
    void Project( zVEC3 const* const, float, float&, float& ) const                       zCall( 0x005FE050 );

    // static properties
    static zCCamera*& activeCam;
    static zVEC3& activeCamPos;

    // user API
    #include "zCCamera.inl"
  };

  // sizeof 14h
  class zCVertex {
  public:
    zMEMPOOL_DECLARATION( zCVertex, 0x008C5CCC )

    zVEC3 position;           // sizeof 0Ch    offset 00h
    union {
      group {
        int transformedIndex; // sizeof 04h    offset 0Ch
        int myIndex;          // sizeof 04h    offset 10h
      };
      unsigned int hackData;
    };

    void zCVertex_OnInit()                     zCall( 0x0056C410 );
    void Draw( zCOLOR const&, int )            zCall( 0x00508D60 );
    zCVertexTransform* CreateVertexTransform() zCall( 0x00508E50 );
    ~zCVertex()                                zCall( 0x00562280 );
    zCVertex()                                 zInit( zCVertex_OnInit() );
    void ResetVertexTransform()                zCall( 0x005BEF20 );
    static void ResetVertexTransforms()        zCall( 0x00508E20 );

    // user API
    #include "zCVertex.inl"
  };

  // sizeof 1Ch
  class zCVertFeature {
  public:
    zMEMPOOL_DECLARATION( zCVertFeature, 0x008C5D30 )

    zVEC3 vertNormal; // sizeof 0Ch    offset 00h
    zCOLOR lightStat; // sizeof 04h    offset 0Ch
    zCOLOR lightDyn;  // sizeof 04h    offset 10h
    float texu;       // sizeof 04h    offset 14h
    float texv;       // sizeof 04h    offset 18h

    void zCVertFeature_OnInit() zCall( 0x00568510 );
    zCVertFeature()             zInit( zCVertFeature_OnInit() );

    // user API
    #include "zCVertFeature.inl"
  };

  // sizeof 34h
  class zCPolygon {
  public:
    zMEMPOOL_DECLARATION( zCPolygon, 0x008C5D68 )

    enum zTPortalType {
      zPORTAL_TYPE_NONE,
      zPORTAL_TYPE_SMALL,
      zPORTAL_TYPE_BIG,
      zPORTAL_TYPE_BIG_NOFADE
    };

    // sizeof 14h
    struct zSPolySavedValues {
      zCPolygon* poly; // sizeof 04h    offset 00h
      zTPlane plane;   // sizeof 10h    offset 04h

      zSPolySavedValues() {}

      // user API
      #include "zCPolygon_zSPolySavedValues.inl"
    };

    // sizeof 08h
    struct zSVertexSavedValues {
      zCVertex* vert; // sizeof 04h    offset 00h
      float offset;   // sizeof 04h    offset 04h

      zSVertexSavedValues() {}

      // user API
      #include "zCPolygon_zSVertexSavedValues.inl"
    };

    // sizeof 20h
    struct zSFeatureSavedValues {
      zCVertFeature* feat; // sizeof 04h    offset 00h
      zCOLOR color;        // sizeof 04h    offset 04h
      zVEC3 mapping;       // sizeof 0Ch    offset 08h
      zVEC3 vertNormal;    // sizeof 0Ch    offset 14h

      zSFeatureSavedValues() {}

      // user API
      #include "zCPolygon_zSFeatureSavedValues.inl"
    };

#pragma pack( push, 1 )
    // sizeof 03h
    struct TFlags {
      unsigned char portalPoly          : 2;  // sizeof 02h    offset bit
      unsigned char occluder            : 1;  // sizeof 01h    offset bit
      unsigned char sectorPoly          : 1;  // sizeof 01h    offset bit
      unsigned char mustRelight         : 1;  // sizeof 01h    offset bit
      unsigned char portalIndoorOutdoor : 1;  // sizeof 01h    offset bit
      unsigned char ghostOccluder       : 1;  // sizeof 01h    offset bit
      unsigned char noDynLightNear      : 1;  // sizeof 01h    offset bit
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
    TFlags flags;              // sizeof 03h    offset 31h

    void zCPolygon_OnInit()                                                                                           zCall( 0x005B1430 );
    int RenderPoly( int )                                                                                             zCall( 0x00526FE0 );
    void ApplyMorphing()                                                                                              zCall( 0x00527620 );
    void __fastcall LightClippedPoly( int )                                                                           zCall( 0x00527F40 );
    int TransformProjectLight()                                                                                       zCall( 0x005287F0 );
    int TransformProject()                                                                                            zCall( 0x005289C0 );
    void SetMaterial( zCMaterial* )                                                                                   zCall( 0x005345B0 );
    zCPolygon()                                                                                                       zInit( zCPolygon_OnInit() );
    ~zCPolygon()                                                                                                      zCall( 0x005B1470 );
    int __fastcall ClipToPlane( zCVertex**, zCVertFeature**, int, zCVertex**, zCVertFeature**, int&, zTPlane const& ) zCall( 0x005B1780 );
    int __fastcall ClipToPlane_Occluder( zCVertex**, int, zCVertex**, int&, zTPlane const& )                          zCall( 0x005B1C20 );
    void Unclip()                                                                                                     zCall( 0x005B1EA0 );
    void Unclip_Occluder()                                                                                            zCall( 0x005B1F20 );
    void CopyClipFeaturesForTexAniMapping()                                                                           zCall( 0x005B1F40 );
    int __fastcall ClipToFrustum( int )                                                                               zCall( 0x005B1FB0 );
    int __fastcall ClipToFrustum_Occluder( int )                                                                      zCall( 0x005B22F0 );
    int ClassifyPlane( zTPlane const& )                                                                               zCall( 0x005B24D0 );
    int ClassifyPlaneBSPBuild( zTPlane const& )                                                                       zCall( 0x005B2580 );
    int CalcNormal()                                                                                                  zCall( 0x005B2610 );
    int CalcNormalApprox()                                                                                            zCall( 0x005B2A30 );
    void GetScreenBBox2D( zTBBox2D& )                                                                                 zCall( 0x005B2E60 );
    void DrawWire( zCOLOR ) const                                                                                     zCall( 0x005B2F00 );
    void LightDynCamSpace( zVEC3 const&, int )                                                                        zCall( 0x005B36E0 );
    zVEC3 GetLightStatAtPos( zVEC3 const& )                                                                           zCall( 0x005B38A0 );
    int __fastcall CheckRayPolyIntersection( zVEC3 const&, zVEC3 const&, zVEC3&, float& ) const                       zCall( 0x005B3FB0 );
    int __fastcall CheckRayPolyIntersection2Sided( zVEC3 const&, zVEC3 const&, zVEC3&, float& ) const                 zCall( 0x005B4340 );
    zTBBox3D GetBBox3D() const                                                                                        zCall( 0x005B46B0 );
    zVEC3 GetCenter()                                                                                                 zCall( 0x005B4780 );
    void SetMapping( zVEC2 const&, zVEC2 const&, zVEC2 const& )                                                       zCall( 0x005B4800 );
    void SetMapping( int, zVEC2 const& )                                                                              zCall( 0x005B4850 );
    void Flip()                                                                                                       zCall( 0x005B4870 );
    int VertPartOfPoly( zCVertex* ) const                                                                             zCall( 0x005B48B0 );
    int EdgePartOfPoly( zCVertex*, zCVertex* ) const                                                                  zCall( 0x005B48E0 );
    int EdgePositionsPartOfPoly( zCVertex*, zCVertex* ) const                                                         zCall( 0x005B4930 );
    void TexTranslate( zVEC2 const& )                                                                                 zCall( 0x005B4980 );
    void TexSetTranslation( zVEC2 const& )                                                                            zCall( 0x005B49C0 );
    void TexScale( float, float )                                                                                     zCall( 0x005B4A00 );
    void TexScale( zVEC2&, float, float )                                                                             zCall( 0x005B4A40 );
    void TexRotate( zVEC2&, float )                                                                                   zCall( 0x005B4B00 );
    void TexMirrorU( float )                                                                                          zCall( 0x005B4CD0 );
    void TexMirrorV( float )                                                                                          zCall( 0x005B4D00 );
    void TexShearU( float )                                                                                           zCall( 0x005B4D30 );
    void TexShearV( float )                                                                                           zCall( 0x005B4DF0 );
    void TexApplyPlanarMapping( zVEC3 const&, zVEC3 const&, zVEC3 const&, int )                                       zCall( 0x005B4EB0 );
    void TexApplyPlanarMapping( float, float, int )                                                                   zCall( 0x005B5060 );
    void TexCorrectUV()                                                                                               zCall( 0x005B5650 );
    void AllocVerts( int )                                                                                            zCall( 0x005B57A0 );
    void AddVertex( zCVertex* )                                                                                       zCall( 0x005B5910 );
    void AddVertexAndFeature( zCVertex*, zCVertFeature* )                                                             zCall( 0x005B5930 );
    void SetVertices( zCVertex*, zCVertex*, zCVertex* )                                                               zCall( 0x005B5970 );
    void SetVertices( zCVertex*, zCVertex*, zCVertex*, zCVertex*, int )                                               zCall( 0x005B59D0 );
    void SetVertex( int, zCVertex* )                                                                                  zCall( 0x005B5A40 );
    void SetFeature( int, zCVertFeature* )                                                                            zCall( 0x005B5A80 );
    void CopyValuesInto( zCPolygon* ) const                                                                           zCall( 0x005B5AC0 );
    void CopyPolyInto( zCPolygon* ) const                                                                             zCall( 0x005B5B70 );
    void RemoveVerticesAndFeatures()                                                                                  zCall( 0x005B5BD0 );
    float GetArea() const                                                                                             zCall( 0x005B5C60 );
    float GetLongestEdgeLen() const                                                                                   zCall( 0x005B5D00 );
    void ResetStaticLight()                                                                                           zCall( 0x005B5D70 );
    void SetStaticLight( zCOLOR )                                                                                     zCall( 0x005B5DB0 );
    void SetLightDyn( zCOLOR )                                                                                        zCall( 0x005B5DE0 );
    void SetLightStatAlpha( unsigned char )                                                                           zCall( 0x005B5E10 );
    void ResetLightDynToLightStat()                                                                                   zCall( 0x005B5E40 );
    void AddToLightDyn( zCOLOR )                                                                                      zCall( 0x005B5E70 );
    int __fastcall CheckBBoxPolyIntersection( zTBBox3D const& ) const                                                 zCall( 0x005B5F00 );
    int __fastcall CheckBSpherePolyIntersection( zTBSphere3D const& ) const                                           zCall( 0x005B6380 );
    void SplitPoly( zTPlane const&, zCPolygon*, zCPolygon*, zCMesh* )                                                 zCall( 0x005B64F0 );
    int __fastcall IsIntersectingProjection( zCPolygon*, zVEC3 const& )                                               zCall( 0x005B6A40 );
    int __fastcall IsIntersecting( zCPolygon* )                                                                       zCall( 0x005B71B0 );
    int IsNeighbourOf( zCPolygon const* )                                                                             zCall( 0x005B7280 );
    int GetStaticLODPossible()                                                                                        zCall( 0x005B7350 );
    void LightStatic( zCVobLight&, zVEC3 const&, zMAT4&, zCWorld* )                                                   zCall( 0x00621720 );
    void SmoothSectorBorder( zCWorld* )                                                                               zCall( 0x00622080 );
    static void* S_AllocPointers( int )                                                                               zCall( 0x005B1350 );
    static void S_DeletePointers( int, void* )                                                                        zCall( 0x005B1370 );
    static zCVertFeature* S_AllocVertFeatures( int )                                                                  zCall( 0x005B13A0 );
    static void S_DeleteVertFeatures( int, zCVertFeature* )                                                           zCall( 0x005B1400 );
    static void S_InitMorph()                                                                                         zCall( 0x005B1580 );
    static void S_EmptyMorphedVerts()                                                                                 zCall( 0x005B15A0 );
    static void S_ResetMorphedVerts()                                                                                 zCall( 0x005B15C0 );
    static void S_DeleteMorphedVerts()                                                                                zCall( 0x005B16F0 );
    static void PrepareRendering()                                                                                    zCall( 0x005B1E80 );
    static void LightPolyList( zCArray<zCVobLight*> const&, zCPolygon**, int, zMAT4* )                                zCall( 0x005B2FC0 );
    static void TexApplyPlanarMapping( zCList<zCPolygon> const&, float, float, int )                                  zCall( 0x005B5120 );
    static void AlignPolyListToAvgPlane( zCArray<zCPolygon*> )                                                        zCall( 0x005B5360 );

    // static properties
    static zCVertex*& s_clipVertScene;
    static int& s_numClipVertScene;
    static zCVertFeature*& s_clipFeatScene;
    static int& s_numClipFeatScene;
    static int& s_numVertListScene;
    static int& s_numFeatListScene;
    static zCVertex**& s_actClipVert;
    static int& s_actNumClipVert;
    static zCArraySort<zSVertexSavedValues>& morphedVerticesList_Height;
    static zCArraySort<zSVertexSavedValues>& morphedVerticesList_Wall;
    static zCArraySort<zSFeatureSavedValues>& morphedFeatureList;
    static zCArray<zSPolySavedValues>& morphedPolysSavedValuesList;

    // user API
    #include "zCPolygon.inl"
  };

  // sizeof 40h
  class zCPortal : public zCPolygon {
  public:
    zMEMPOOL_DECLARATION( zCPortal, 0x008C5D4C )

    zCBspNode* frontBspNode; // sizeof 04h    offset 34h
    zCBspNode* backBspNode;  // sizeof 04h    offset 38h
    int lastTimeCompletely;  // sizeof 04h    offset 3Ch

    zCPortal() {}
    void zCPortal_OnInit( zTPlane const&, zCMesh* ) zCall( 0x005265C0 );
    void RemoveFromBsp()                            zCall( 0x005265A0 );
    zCPortal( zTPlane const& a0, zCMesh* a1 )       zInit( zCPortal_OnInit( a0, a1 ));
    void Init()                                     zCall( 0x00539C50 );
    ~zCPortal()                                     zCall( 0x0053A0B0 );

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

} // namespace Gothic_II_Classic

#endif // __Z3D_H__VER2__