// Supported with union (c) 2018 Union team

#ifndef __ZVISUAL_H__VER3__
#define __ZVISUAL_H__VER3__

#include "z3d.h"
#include "zBVolume.h"

namespace Gothic_II_Addon {

  enum {
    zVISUAL_CAMALIGN_NONE,
    zVISUAL_CAMALIGN_YAW,
    zVISUAL_CAMALIGN_FULL,
    zVISUAL_CAMALIGN_COUNT
  };

  struct zTRenderContext {
    int clipFlags;
    zCVob* vob;
    zCWorld* world;
    zCCamera* cam;
    float distVobToCam;
    zTVisualCamAlign visualCamAlign;
    zTAnimationMode m_AniMode;
    float m_aniModeStrength;
    zCOLOR hintLightingHighlightColor;
    group {
      unsigned char hintLightingFullbright : 1;
      unsigned char hintLightingSwell      : 1;
      unsigned char hintLightingHighlight  : 1;
    };

    zTRenderContext() {}

    // user API
    #include "zTRenderContext.inl"
  };

  class zCVisual : public zCObject {
  public:
    zCLASS_DECLARATION( zCVisual )

    zCVisual* nextLODVisual;
    zCVisual* prevLODVisual;
    float lodFarDistance;
    float lodNearFadeOutDistance;

    void zCVisual_OnInit()                                                     zCall( 0x00606660 );
    zCVisual()                                                                 zInit( zCVisual_OnInit() );
    void AddNextLODVisual( zCVisual* )                                         zCall( 0x00606820 );
    void AddEndLODVisual( zCVisual* )                                          zCall( 0x00606850 );
    static void InitVisualSystem()                                             zCall( 0x006068F0 );
    static void CleanupVisualSystem()                                          zCall( 0x00606A80 );
    static zCVisual* LoadVisual( zSTRING const& )                              zCall( 0x00606AD0 );
    virtual zCClassDef* _GetClassDef() const                                   zCall( 0x004CA040 );
    virtual ~zCVisual()                                                        zCall( 0x00606800 );
    virtual int Render( zTRenderContext& )                                     zPureCall;
    virtual int IsBBox3DLocal()                                                zCall( 0x00566FF0 );
    virtual zTBBox3D GetBBox3D()                                               zPureCall;
    virtual zCOBBox3D* GetOBBox3D()                                            zCall( 0x004CA050 );
    virtual zSTRING GetVisualName()                                            zPureCall;
    virtual int GetVisualDied()                                                zCall( 0x004CA060 );
    virtual void SetVisualUsedBy( zCVob* )                                     zCall( 0x00567000 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* )         zCall( 0x004CA070 );
    virtual unsigned long GetRenderSortKey() const                             zCall( 0x004CA080 );
    virtual int CanTraceRay() const                                            zCall( 0x004CA090 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& ) zCall( 0x006068E0 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )                   zCall( 0x004CA0A0 );
    virtual void HostVobAddedToWorld( zCVob*, zCWorld* )                       zCall( 0x004CA0B0 );
    virtual zSTRING const* GetFileExtension( int )                             zCall( 0x004CA0C0 );
    virtual void GetLODVisualAndAlpha( float, zCVisual*&, float& )             zCall( 0x00606880 );
    virtual int GetAlphaTestingEnabled() const                                 zCall( 0x004CA0D0 );
    virtual void SetAlphaTestingEnabled( int )                                 zCall( 0x004CA0E0 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                zCall( 0x004CA0F0 );

    // static properties
    static zCArray<zCVisual*>& s_visualClassList;

    // user API
    #include "zCVisual.inl"
  };

  class zCVisualAnimate : public zCVisual {
  public:
    zCLASS_DECLARATION( zCVisualAnimate )

    zCVisualAnimate() {}
    virtual zCClassDef* _GetClassDef() const        zCall( 0x00576580 );
    virtual ~zCVisualAnimate()                      zCall( 0x00576750 );
    virtual int Render( zTRenderContext& )          zPureCall;
    virtual zTBBox3D GetBBox3D()                    zPureCall;
    virtual zSTRING GetVisualName()                 zPureCall;
    virtual void StartAnimation( zSTRING const& )   zPureCall;
    virtual void StopAnimation( zSTRING const& )    zPureCall;
    virtual int IsAnimationActive( zSTRING const& ) zPureCall;
    virtual zSTRING const* GetAnyAnimation()        zPureCall;

    // user API
    #include "zCVisualAnimate.inl"
  };

  class zCDecal : public zCVisual {
  public:
    zCLASS_DECLARATION( zCDecal )

    zCMaterial* decalMaterial;
    float xdim;
    float ydim;
    float xoffset;
    float yoffset;
    int decal2Sided;
    int ignoreDayLight;
    int m_bOnTop;

    void zCDecal_OnInit()                                              zCall( 0x00556570 );
    zCDecal()                                                          zInit( zCDecal_OnInit() );
    void SetTexture( zSTRING& )                                        zCall( 0x00556950 );
    void SetTexture( zCTexture* )                                      zCall( 0x00556960 );
    void SetDecalDim( float, float )                                   zCall( 0x00556970 );
    static zCObject* _CreateNewInstance()                              zCall( 0x00556440 );
    static void CleanupDecals()                                        zCall( 0x005566B0 );
    static void CreateDecalMeshes()                                    zCall( 0x00556730 );
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x00556550 );
    virtual void Archive( zCArchiver& )                                zCall( 0x00556D70 );
    virtual void Unarchive( zCArchiver& )                              zCall( 0x00556E60 );
    virtual ~zCDecal()                                                 zCall( 0x00556640 );
    virtual int Render( zTRenderContext& )                             zCall( 0x00556990 );
    virtual int IsBBox3DLocal()                                        zCall( 0x00556560 );
    virtual zTBBox3D GetBBox3D()                                       zCall( 0x00556B30 );
    virtual zSTRING GetVisualName()                                    zCall( 0x00556B80 );
    virtual void SetVisualUsedBy( zCVob* )                             zCall( 0x00556B10 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* ) zCall( 0x00556C60 );
    virtual unsigned long GetRenderSortKey() const                     zCall( 0x00556940 );
    virtual zSTRING const* GetFileExtension( int )                     zCall( 0x005567A0 );
    virtual int GetAlphaTestingEnabled() const                         zCall( 0x00556BE0 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const        zCall( 0x00556800 );

    // static properties
    static zCMesh*& decalMesh1Sided;
    static zCMesh*& decalMesh2Sided;

    // user API
    #include "zCDecal.inl"
  };

  class zCMesh : public zCVisual {
  public:
    zCLASS_DECLARATION( zCMesh )

    enum zTCalcVertNormalMode {
      zMSH_VERTNORMAL_MAT,
      zMSH_VERTNORMAL_SMOOTH,
      zMSH_VERTNORMAL_FACET
    };

    int numPoly;
    int numVert;
    int numFeat;
    zCVertex** vertList;
    zCPolygon** polyList;
    zCVertFeature** featList;
    zCVertex* vertArray;
    zCPolygon* polyArray;
    zCVertFeature* featArray;
    zTBBox3D bbox3D;
    zCOBBox3D obbox3D;
    int masterFrameCtr;
    zCMesh* next;
    zCMesh* prev;
    zSTRING meshName;
    char hasLightmaps;
    int m_bUsesAlphaTesting;
    int numVertAlloc;
    int numPolyAlloc;

    void zCMesh_OnInit()                                                                     zCall( 0x00566D90 );
    zCMesh()                                                                                 zInit( zCMesh_OnInit() );
    void DeleteAll()                                                                         zCall( 0x00567290 );
    zCVertex* VertexInMesh( zVEC3 const& )                                                   zCall( 0x00568350 );
    void AllocVerts( int )                                                                   zCall( 0x00568500 );
    void AllocPolys( int )                                                                   zCall( 0x005685F0 );
    zCVertex* AddVertex( zCVertex* )                                                         zCall( 0x005686B0 );
    zCVertex* AddVertex( zVEC3& )                                                            zCall( 0x005688F0 );
    zCVertex* AddVertexSmart( zVEC3& )                                                       zCall( 0x00568B80 );
    zCPolygon* AddPoly( zVEC3&, zVEC3&, zVEC3&, zVEC2&, zVEC2&, zVEC2& )                     zCall( 0x00568C10 );
    zCPolygon* AddPoly( zCVertex*, zCVertex*, zCVertex* )                                    zCall( 0x00568EA0 );
    zCPolygon* AddPoly( zCVertex*, zCVertex*, zCVertex*, zCVertex* )                         zCall( 0x00568FB0 );
    zCPolygon* AddPoly( zCPolygon* )                                                         zCall( 0x005690C0 );
    zCPolygon* AddPoly()                                                                     zCall( 0x00569170 );
    void DeletePoly( zCPolygon* )                                                            zCall( 0x00569250 );
    void DynLightScalePrelit( zCOLOR )                                                       zCall( 0x00569340 );
    void PrelightMesh( zMAT4* )                                                              zCall( 0x00569350 );
    zCPolygon* SharePoly( int ) const                                                        zCall( 0x00569760 );
    zCPolygon* CheckRayPolyIntersection( zVEC3 const&, zVEC3 const&, zVEC3& )                zCall( 0x00569780 );
    zCPolygon* CheckRayPolyIntersection( zCCamera&, int, int, zVEC3& )                       zCall( 0x005697E0 );
    zCPolygon* PickPolygon( zVEC3 const&, zVEC3 const&, zVEC3& )                             zCall( 0x00569990 );
    zCPolygon* PickPolygon( zCCamera&, int, int, zVEC3& )                                    zCall( 0x00569A60 );
    void CalcVertexNormals( zTCalcVertNormalMode, zCBspTree* )                               zCall( 0x00569DE0 );
    void UnSmoothMesh()                                                                      zCall( 0x0056A4E0 );
    void SetDefaultPlanarMapping( float, float )                                             zCall( 0x0056A580 );
    void CalcBBox3D( int )                                                                   zCall( 0x0056A610 );
    void Center()                                                                            zCall( 0x0056A7A0 );
    void TransformAllVerts( zMAT4 const&, int )                                              zCall( 0x0056A8F0 );
    void MergeMesh( zCMesh*, zMAT4 const& )                                                  zCall( 0x0056A9B0 );
    void CalcNormals()                                                                       zCall( 0x0056AE90 );
    void SetMaterial( zCMaterial* )                                                          zCall( 0x0056AEC0 );
    void ScaleXZ( float, float )                                                             zCall( 0x0056AF20 );
    void Scale( float, float, float )                                                        zCall( 0x0056AF90 );
    void CheckForMaterials() const                                                           zCall( 0x0056B050 );
    int Render_novt( zTRenderContext&, zCOLOR* )                                             zCall( 0x0056B210 );
    int RenderHorizon( zTRenderContext&, float )                                             zCall( 0x0056B4F0 );
    void RenderDecal( float, float, float, int )                                             zCall( 0x0056B7A0 );
    void RenderDecalHorizon( float, float, float, float )                                    zCall( 0x0056B980 );
    void RenderDecal( zTRenderContext&, int )                                                zCall( 0x0056BDA0 );
    void ResetStaticLight()                                                                  zCall( 0x0056C000 );
    void SetStaticLight( zCOLOR )                                                            zCall( 0x0056C040 );
    void SetLightDyn( zCOLOR )                                                               zCall( 0x0056C080 );
    void SetLightStatAlpha( unsigned char )                                                  zCall( 0x0056C0C0 );
    void ResetLightDynToLightStat()                                                          zCall( 0x0056C100 );
    void AddToLightDyn( zCOLOR )                                                             zCall( 0x0056C140 );
    void SaveMSH( zCFileBIN& )                                                               zCall( 0x0056D790 );
    void SaveMSH( zSTRING const& )                                                           zCall( 0x0056D7B0 );
    int LoadMSH( zCFileBIN&, int )                                                           zCall( 0x005700E0 );
    int LoadMSH( zSTRING const&, int )                                                       zCall( 0x005716B0 );
    void CreateListsFromArrays() const                                                       zCall( 0x00571980 );
    void ClearLists() const                                                                  zCall( 0x00571A50 );
    void ArraysToLists() const                                                               zCall( 0x00571AB0 );
    void ShareFeatures()                                                                     zCall( 0x00571B90 );
    void UnshareFeatures()                                                                   zCall( 0x00572970 );
    void FlipPolys()                                                                         zCall( 0x00572A90 );
    void SortPolysByMaterial()                                                               zCall( 0x00572D10 );
    void SortPolysByList( zCPolygon**, int )                                                 zCall( 0x00572DC0 );
    void DeletePolyAndVerts( zCPolygon* )                                                    zCall( 0x00573650 );
    void DeletePolyAndVerts( unsigned long )                                                 zCall( 0x005736E0 );
    void RemoveDegeneratePolys()                                                             zCall( 0x00573860 );
    void CombineLightmaps()                                                                  zCall( 0x00573A90 );
    void LightMesh( zCVobLight&, zMAT4&, zCWorld* )                                          zCall( 0x00629A50 );
    static zCObject* _CreateNewInstance()                                                    zCall( 0x00566CD0 );
    static zCMesh* SearchName( zSTRING const& )                                              zCall( 0x00567590 );
    static zCMesh* Load( zSTRING const&, int )                                               zCall( 0x00567600 );
    static void S_InitVertexMergeCache( zCMesh* )                                            zCall( 0x005680A0 );
    static void S_DeleteVertexMergeCache()                                                   zCall( 0x00568320 );
    static zCMesh* CreateQuadMesh( int )                                                     zCall( 0x0056C180 );
    static zCMesh* CreateTriMesh()                                                           zCall( 0x0056C4D0 );
    static int CheckTexUVOnPlane( zCArray<zCVertex*> const&, zCArray<zCVertFeature> const& ) zCall( 0x0056C6A0 );
    static void ConvertTrisToNPolys( zCPolygon**, int, zCMesh*, int )                        zCall( 0x0056CBA0 );
    static unsigned short GetFileVersion()                                                   zCall( 0x0056D780 );
    static void SaveMSH( zCFileBIN&, zCPolygon**, int, zCMesh* )                             zCall( 0x0056D940 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x00567010 );
    virtual ~zCMesh()                                                                        zCall( 0x00567110 );
    virtual int Render( zTRenderContext& )                                                   zCall( 0x0056B190 );
    virtual zTBBox3D GetBBox3D()                                                             zCall( 0x00567070 );
    virtual zCOBBox3D* GetOBBox3D()                                                          zCall( 0x005670A0 );
    virtual zSTRING GetVisualName()                                                          zCall( 0x00567020 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* )                       zCall( 0x00569330 );
    virtual int CanTraceRay() const                                                          zCall( 0x005670B0 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& )               zCall( 0x00569C60 );
    virtual zSTRING const* GetFileExtension( int )                                           zCall( 0x00567250 );
    virtual int GetAlphaTestingEnabled() const                                               zCall( 0x005670C0 );
    virtual void SetAlphaTestingEnabled( int )                                               zCall( 0x005670D0 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                              zCall( 0x00567270 );

    // static properties
    static int& s_autoConvertMeshes;
    static int& s_usesVertexCache;
    static int& s_numMeshes;
    static zCMesh*& s_meshRoot;
    static zCArraySort<zCVertex*>& s_vertexCache;

    // user API
    #include "zCMesh.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZVISUAL_H__VER3__