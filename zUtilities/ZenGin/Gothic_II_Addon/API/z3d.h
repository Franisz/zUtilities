// Supported with union (c) 2018-2021 Union team

#ifndef __Z3D_H__VER3__
#define __Z3D_H__VER3__

#include "zMaterial.h"
#include "zBVolume.h"
#include "zMemPool.h"

namespace Gothic_II_Addon {
  const int zMAX_POLY_VERTS            = 21;
  const int zMAX_POLY_CLIP_VERTS       = zMAX_POLY_VERTS * 2;
  const int zMAX_POLY_CLIP_VERTS_SCENE = 8192;
  const int zMAX_POLY_VERT_LIST_SCENE  = 16384;
  const int zTCAM_POLY_NUM_VERT        = 4;

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
    void PrintScreen( int, int ) zCall( 0x0050ACF0 );

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
    ~zCLineCache()                                         zCall( 0x0050B310 );
    void Line( int, int, int, int, zCOLOR )                zCall( 0x0050B320 );
    void Flush( zCViewBase* )                              zCall( 0x0050B3B0 );
    void Line3D( zVEC3 const&, zVEC3 const&, zCOLOR, int ) zCall( 0x0050B450 );
    void LineCS3D( zVEC3 const&, zVEC3 const&, zCOLOR )    zCall( 0x0050B850 );

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

    void zCCamera_OnInit()                                                                zCall( 0x00549E60 );
    void Project( zVEC3 const* const, float&, float& ) const                              zCall( 0x00530030 );
    zCCamera()                                                                            zInit( zCCamera_OnInit() );
    ~zCCamera()                                                                           zCall( 0x0054A290 );
    void PushTransform( zTCamTrafoType )                                                  zCall( 0x0054A370 );
    void PopTransform( zTCamTrafoType )                                                   zCall( 0x0054A400 );
    void SetTransform( zTCamTrafoType, zMAT4 const& )                                     zCall( 0x0054A540 );
    zMAT4 const& GetTransform( zTCamTrafoType )                                           zCall( 0x0054A6A0 );
    void Activate()                                                                       zCall( 0x0054A700 );
    void CreateProjectionMatrix( zMAT4&, float, float, float, float )                     zCall( 0x0054A810 );
    void UpdateProjectionMatrix()                                                         zCall( 0x0054A890 );
    float GetFOV() const                                                                  zCall( 0x0054A8E0 );
    void GetFOV( float&, float& ) const                                                   zCall( 0x0054A8F0 );
    void SetFOV( float )                                                                  zCall( 0x0054A920 );
    void SetFOV( float, float )                                                           zCall( 0x0054A960 );
    void UpdateViewport()                                                                 zCall( 0x0054AA90 );
    void SetRenderTarget( zCViewBase* )                                                   zCall( 0x0054ABD0 );
    void SetRenderScreenFadeTex( zSTRING )                                                zCall( 0x0054ABF0 );
    void SetUpFrustum()                                                                   zCall( 0x0054AD20 );
    void SetFarClipZ( float )                                                             zCall( 0x0054B200 );
    zTCam_ClipType BBox3DInFrustum( zTBBox3D const& )                                     zCall( 0x0054B3B0 );
    zTCam_ClipType BBox3DInFrustum( zTBBox3D const&, int& )                               zCall( 0x0054B410 );
    void StopTremor()                                                                     zCall( 0x0054B650 );
    void AddTremor( zVEC3 const&, float, float, zVEC3 const& )                            zCall( 0x0054B660 );
    void PreRenderProcessing()                                                            zCall( 0x0054B7D0 );
    void PostRenderProcessing()                                                           zCall( 0x0054B920 );
    void GetCamPos( zVEC3& ) const                                                        zCall( 0x0054B960 );
    void InitDrawPolySimple()                                                             zCall( 0x0054B990 );
    void CleanupDrawPolySimple()                                                          zCall( 0x0054BA50 );
    void DrawPolySimple( zTCamVertSimple*, int, zCMaterial*, int )                        zCall( 0x0054BAB0 );
    void SetRenderScreenFade( zCOLOR )                                                    zCall( 0x0054BBC0 );
    void SetRenderScreenFadeTexAniFPS( float )                                            zCall( 0x0054BBE0 );
    void SetRenderScreenFadeTexBlendFunc( zTRnd_AlphaBlendFunc )                          zCall( 0x0054BC10 );
    void SetRenderCinemaScope( zCOLOR )                                                   zCall( 0x0054BC20 );
    void RenderScreenFade()                                                               zCall( 0x0054BC40 );
    void RenderCinemaScope()                                                              zCall( 0x0054BD30 );
    int __fastcall ScreenProjectionTouchesPortalRough( zTBBox3D const&, zTBBox2D const& ) zCall( 0x0054BE80 );
    int __fastcall ScreenProjectionTouchesPortal( zTBBox3D const&, zTBBox2D const& )      zCall( 0x0054C100 );
    void ProjectClamp( zCVertexTransform*, float ) const                                  zCall( 0x0056BD00 );
    void Project( zVEC3 const* const, int&, int& )                                        zCall( 0x0057A440 );
    void Project( zVEC3 const* const, float, float&, float& ) const                       zCall( 0x00604ED0 );

    // static properties
    static zCCamera*& activeCam;
    static zVEC3& activeCamPos;

    // user API
    #include "zCCamera.inl"
  };

  // sizeof 14h
  class zCVertex {
  public:
    zMEMPOOL_DECLARATION( zCVertex, 0x008D4304 )

    zVEC3 position;           // sizeof 0Ch    offset 00h
    union {
      group {
        int transformedIndex; // sizeof 04h    offset 0Ch
        int myIndex;          // sizeof 04h    offset 10h
      };
      unsigned int hackData;
    };

    void zCVertex_OnInit()                     zCall( 0x005716A0 );
    void Draw( zCOLOR const&, int )            zCall( 0x0050BB10 );
    zCVertexTransform* CreateVertexTransform() zCall( 0x0050BC00 );
    ~zCVertex()                                zCall( 0x005674A0 );
    zCVertex()                                 zInit( zCVertex_OnInit() );
    void ResetVertexTransform()                zCall( 0x005C4A90 );
    static void ResetVertexTransforms()        zCall( 0x0050BBD0 );

    // user API
    #include "zCVertex.inl"
  };

  // sizeof 1Ch
  class zCVertFeature {
  public:
    zMEMPOOL_DECLARATION( zCVertFeature, 0x008D4368 )

    zVEC3 vertNormal; // sizeof 0Ch    offset 00h
    zCOLOR lightStat; // sizeof 04h    offset 0Ch
    zCOLOR lightDyn;  // sizeof 04h    offset 10h
    float texu;       // sizeof 04h    offset 14h
    float texv;       // sizeof 04h    offset 18h

    void zCVertFeature_OnInit() zCall( 0x0056D760 );
    zCVertFeature()             zInit( zCVertFeature_OnInit() );

    // user API
    #include "zCVertFeature.inl"
  };

  // sizeof 34h
  class zCPolygon {
  public:
    zMEMPOOL_DECLARATION( zCPolygon, 0x008D43A0 )

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

    void zCPolygon_OnInit()                                                                                           zCall( 0x005B6FA0 );
    int RenderPoly( int )                                                                                             zCall( 0x00529DD0 );
    void ApplyMorphing()                                                                                              zCall( 0x0052A420 );
    void __fastcall LightClippedPoly( int )                                                                           zCall( 0x0052AD40 );
    int TransformProjectLight()                                                                                       zCall( 0x0052B650 );
    int TransformProject()                                                                                            zCall( 0x0052B820 );
    void SetMaterial( zCMaterial* )                                                                                   zCall( 0x00537910 );
    zCPolygon()                                                                                                       zInit( zCPolygon_OnInit() );
    ~zCPolygon()                                                                                                      zCall( 0x005B6FE0 );
    int __fastcall ClipToPlane( zCVertex**, zCVertFeature**, int, zCVertex**, zCVertFeature**, int&, zTPlane const& ) zCall( 0x005B72F0 );
    int __fastcall ClipToPlane_Occluder( zCVertex**, int, zCVertex**, int&, zTPlane const& )                          zCall( 0x005B7790 );
    void Unclip()                                                                                                     zCall( 0x005B7A10 );
    void Unclip_Occluder()                                                                                            zCall( 0x005B7A90 );
    void CopyClipFeaturesForTexAniMapping()                                                                           zCall( 0x005B7AB0 );
    int __fastcall ClipToFrustum( int )                                                                               zCall( 0x005B7B20 );
    int __fastcall ClipToFrustum_Occluder( int )                                                                      zCall( 0x005B7E60 );
    int ClassifyPlane( zTPlane const& )                                                                               zCall( 0x005B8040 );
    int ClassifyPlaneBSPBuild( zTPlane const& )                                                                       zCall( 0x005B80F0 );
    int CalcNormal()                                                                                                  zCall( 0x005B8180 );
    int CalcNormalApprox()                                                                                            zCall( 0x005B85A0 );
    void GetScreenBBox2D( zTBBox2D& )                                                                                 zCall( 0x005B89D0 );
    void DrawWire( zCOLOR ) const                                                                                     zCall( 0x005B8A70 );
    void LightDynCamSpace( zVEC3 const&, int )                                                                        zCall( 0x005B9250 );
    zVEC3 GetLightStatAtPos( zVEC3 const& )                                                                           zCall( 0x005B9410 );
    int __fastcall CheckRayPolyIntersection( zVEC3 const&, zVEC3 const&, zVEC3&, float& ) const                       zCall( 0x005B9B20 );
    int __fastcall CheckRayPolyIntersection2Sided( zVEC3 const&, zVEC3 const&, zVEC3&, float& ) const                 zCall( 0x005B9EB0 );
    zTBBox3D GetBBox3D() const                                                                                        zCall( 0x005BA220 );
    zVEC3 GetCenter()                                                                                                 zCall( 0x005BA2F0 );
    void SetMapping( zVEC2 const&, zVEC2 const&, zVEC2 const& )                                                       zCall( 0x005BA370 );
    void SetMapping( int, zVEC2 const& )                                                                              zCall( 0x005BA3C0 );
    void Flip()                                                                                                       zCall( 0x005BA3E0 );
    int VertPartOfPoly( zCVertex* ) const                                                                             zCall( 0x005BA420 );
    int EdgePartOfPoly( zCVertex*, zCVertex* ) const                                                                  zCall( 0x005BA450 );
    int EdgePositionsPartOfPoly( zCVertex*, zCVertex* ) const                                                         zCall( 0x005BA4A0 );
    void TexTranslate( zVEC2 const& )                                                                                 zCall( 0x005BA4F0 );
    void TexSetTranslation( zVEC2 const& )                                                                            zCall( 0x005BA530 );
    void TexScale( float, float )                                                                                     zCall( 0x005BA570 );
    void TexScale( zVEC2&, float, float )                                                                             zCall( 0x005BA5B0 );
    void TexRotate( zVEC2&, float )                                                                                   zCall( 0x005BA670 );
    void TexMirrorU( float )                                                                                          zCall( 0x005BA840 );
    void TexMirrorV( float )                                                                                          zCall( 0x005BA870 );
    void TexShearU( float )                                                                                           zCall( 0x005BA8A0 );
    void TexShearV( float )                                                                                           zCall( 0x005BA960 );
    void TexApplyPlanarMapping( zVEC3 const&, zVEC3 const&, zVEC3 const&, int )                                       zCall( 0x005BAA20 );
    void TexApplyPlanarMapping( float, float, int )                                                                   zCall( 0x005BABD0 );
    void TexCorrectUV()                                                                                               zCall( 0x005BB1C0 );
    void AllocVerts( int )                                                                                            zCall( 0x005BB310 );
    void AddVertex( zCVertex* )                                                                                       zCall( 0x005BB480 );
    void AddVertexAndFeature( zCVertex*, zCVertFeature* )                                                             zCall( 0x005BB4A0 );
    void SetVertices( zCVertex*, zCVertex*, zCVertex* )                                                               zCall( 0x005BB4E0 );
    void SetVertices( zCVertex*, zCVertex*, zCVertex*, zCVertex*, int )                                               zCall( 0x005BB540 );
    void SetVertex( int, zCVertex* )                                                                                  zCall( 0x005BB5B0 );
    void SetFeature( int, zCVertFeature* )                                                                            zCall( 0x005BB5F0 );
    void CopyValuesInto( zCPolygon* ) const                                                                           zCall( 0x005BB630 );
    void CopyPolyInto( zCPolygon* ) const                                                                             zCall( 0x005BB6E0 );
    void RemoveVerticesAndFeatures()                                                                                  zCall( 0x005BB740 );
    float GetArea() const                                                                                             zCall( 0x005BB7D0 );
    float GetLongestEdgeLen() const                                                                                   zCall( 0x005BB870 );
    void ResetStaticLight()                                                                                           zCall( 0x005BB8E0 );
    void SetStaticLight( zCOLOR )                                                                                     zCall( 0x005BB920 );
    void SetLightDyn( zCOLOR )                                                                                        zCall( 0x005BB950 );
    void SetLightStatAlpha( unsigned char )                                                                           zCall( 0x005BB980 );
    void ResetLightDynToLightStat()                                                                                   zCall( 0x005BB9B0 );
    void AddToLightDyn( zCOLOR )                                                                                      zCall( 0x005BB9E0 );
    int __fastcall CheckBBoxPolyIntersection( zTBBox3D const& ) const                                                 zCall( 0x005BBA70 );
    int __fastcall CheckBSpherePolyIntersection( zTBSphere3D const& ) const                                           zCall( 0x005BBEF0 );
    void SplitPoly( zTPlane const&, zCPolygon*, zCPolygon*, zCMesh* )                                                 zCall( 0x005BC060 );
    int __fastcall IsIntersectingProjection( zCPolygon*, zVEC3 const& )                                               zCall( 0x005BC5B0 );
    int __fastcall IsIntersecting( zCPolygon* )                                                                       zCall( 0x005BCD20 );
    int IsNeighbourOf( zCPolygon const* )                                                                             zCall( 0x005BCDF0 );
    int GetStaticLODPossible()                                                                                        zCall( 0x005BCEC0 );
    void LightStatic( zCVobLight&, zVEC3 const&, zMAT4&, zCWorld* )                                                   zCall( 0x00628EA0 );
    void SmoothSectorBorder( zCWorld* )                                                                               zCall( 0x00629800 );
    static void* S_AllocPointers( int )                                                                               zCall( 0x005B6EC0 );
    static void S_DeletePointers( int, void* )                                                                        zCall( 0x005B6EE0 );
    static zCVertFeature* S_AllocVertFeatures( int )                                                                  zCall( 0x005B6F10 );
    static void S_DeleteVertFeatures( int, zCVertFeature* )                                                           zCall( 0x005B6F70 );
    static void S_InitMorph()                                                                                         zCall( 0x005B70F0 );
    static void S_EmptyMorphedVerts()                                                                                 zCall( 0x005B7110 );
    static void S_ResetMorphedVerts()                                                                                 zCall( 0x005B7130 );
    static void S_DeleteMorphedVerts()                                                                                zCall( 0x005B7260 );
    static void PrepareRendering()                                                                                    zCall( 0x005B79F0 );
    static void LightPolyList( zCArray<zCVobLight*> const&, zCPolygon**, int, zMAT4* )                                zCall( 0x005B8B30 );
    static void TexApplyPlanarMapping( zCList<zCPolygon> const&, float, float, int )                                  zCall( 0x005BAC90 );
    static void AlignPolyListToAvgPlane( zCArray<zCPolygon*> )                                                        zCall( 0x005BAED0 );

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
    zMEMPOOL_DECLARATION( zCPortal, 0x008D4384 )

    zCBspNode* frontBspNode; // sizeof 04h    offset 34h
    zCBspNode* backBspNode;  // sizeof 04h    offset 38h
    int lastTimeCompletely;  // sizeof 04h    offset 3Ch

    zCPortal() {}
    void zCPortal_OnInit( zTPlane const&, zCMesh* ) zCall( 0x005293B0 );
    void RemoveFromBsp()                            zCall( 0x00529390 );
    zCPortal( zTPlane const& a0, zCMesh* a1 )       zInit( zCPortal_OnInit( a0, a1 ));
    void Init()                                     zCall( 0x0053ED80 );
    ~zCPortal()                                     zCall( 0x0053F1E0 );

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

} // namespace Gothic_II_Addon

#endif // __Z3D_H__VER3__