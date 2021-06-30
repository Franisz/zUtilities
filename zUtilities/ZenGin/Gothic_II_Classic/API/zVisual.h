// Supported with union (c) 2018 Union team

#ifndef __ZVISUAL_H__VER2__
#define __ZVISUAL_H__VER2__

namespace Gothic_II_Classic {

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

    void zCVisual_OnInit()                                                     zCall( 0x005FF7D0 );
    zCVisual()                                                                 zInit( zCVisual_OnInit() );
    void AddNextLODVisual( zCVisual* )                                         zCall( 0x005FF990 );
    void AddEndLODVisual( zCVisual* )                                          zCall( 0x005FF9C0 );
    static void InitVisualSystem()                                             zCall( 0x005FFA60 );
    static void CleanupVisualSystem()                                          zCall( 0x005FFBF0 );
    static zCVisual* LoadVisual( zSTRING const& )                              zCall( 0x005FFC40 );
    virtual zCClassDef* _GetClassDef() const                                   zCall( 0x004C7AD0 );
    virtual ~zCVisual()                                                        zCall( 0x005FF970 );
    virtual int Render( zTRenderContext& )                                     zPureCall;
    virtual int IsBBox3DLocal()                                                zCall( 0x00561DD0 );
    virtual zTBBox3D GetBBox3D()                                               zPureCall;
    virtual zCOBBox3D* GetOBBox3D()                                            zCall( 0x004C7AE0 );
    virtual zSTRING GetVisualName()                                            zPureCall;
    virtual int GetVisualDied()                                                zCall( 0x004C7AF0 );
    virtual void SetVisualUsedBy( zCVob* )                                     zCall( 0x00561DE0 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* )         zCall( 0x004C7B00 );
    virtual unsigned long GetRenderSortKey() const                             zCall( 0x004C7B10 );
    virtual int CanTraceRay() const                                            zCall( 0x004C7B20 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& ) zCall( 0x005FFA50 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )                   zCall( 0x004C7B30 );
    virtual void HostVobAddedToWorld( zCVob*, zCWorld* )                       zCall( 0x004C7B40 );
    virtual zSTRING const* GetFileExtension( int )                             zCall( 0x004C7B50 );
    virtual void GetLODVisualAndAlpha( float, zCVisual*&, float& )             zCall( 0x005FF9F0 );
    virtual int GetAlphaTestingEnabled() const                                 zCall( 0x004C7B60 );
    virtual void SetAlphaTestingEnabled( int )                                 zCall( 0x004C7B70 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                zCall( 0x004C7B80 );

    // static properties
    static zCArray<zCVisual*>& s_visualClassList;

    // user API
    #include "zCVisual.inl"
  };

  class zCVisualAnimate : public zCVisual {
  public:
    zCLASS_DECLARATION( zCVisualAnimate )

    zCVisualAnimate() {}
    virtual zCClassDef* _GetClassDef() const        zCall( 0x005712D0 );
    virtual ~zCVisualAnimate()                      zCall( 0x005714A0 );
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

    void zCDecal_OnInit()                                              zCall( 0x00551350 );
    zCDecal()                                                          zInit( zCDecal_OnInit() );
    void SetTexture( zSTRING& )                                        zCall( 0x00551730 );
    void SetTexture( zCTexture* )                                      zCall( 0x00551740 );
    void SetDecalDim( float, float )                                   zCall( 0x00551750 );
    static zCObject* _CreateNewInstance()                              zCall( 0x00551220 );
    static void CleanupDecals()                                        zCall( 0x00551490 );
    static void CreateDecalMeshes()                                    zCall( 0x00551510 );
    virtual zCClassDef* _GetClassDef() const                           zCall( 0x00551330 );
    virtual void Archive( zCArchiver& )                                zCall( 0x00551B50 );
    virtual void Unarchive( zCArchiver& )                              zCall( 0x00551C40 );
    virtual ~zCDecal()                                                 zCall( 0x00551420 );
    virtual int Render( zTRenderContext& )                             zCall( 0x00551770 );
    virtual int IsBBox3DLocal()                                        zCall( 0x00551340 );
    virtual zTBBox3D GetBBox3D()                                       zCall( 0x00551910 );
    virtual zSTRING GetVisualName()                                    zCall( 0x00551960 );
    virtual void SetVisualUsedBy( zCVob* )                             zCall( 0x005518F0 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* ) zCall( 0x00551A40 );
    virtual unsigned long GetRenderSortKey() const                     zCall( 0x00551720 );
    virtual zSTRING const* GetFileExtension( int )                     zCall( 0x00551580 );
    virtual int GetAlphaTestingEnabled() const                         zCall( 0x005519C0 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const        zCall( 0x005515E0 );

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

    void zCMesh_OnInit()                                                                     zCall( 0x00561B70 );
    zCMesh()                                                                                 zInit( zCMesh_OnInit() );
    void DeleteAll()                                                                         zCall( 0x00562070 );
    zCVertex* VertexInMesh( zVEC3 const& )                                                   zCall( 0x00563100 );
    void AllocVerts( int )                                                                   zCall( 0x005632B0 );
    void AllocPolys( int )                                                                   zCall( 0x005633A0 );
    zCVertex* AddVertex( zCVertex* )                                                         zCall( 0x00563460 );
    zCVertex* AddVertex( zVEC3& )                                                            zCall( 0x005636A0 );
    zCVertex* AddVertexSmart( zVEC3& )                                                       zCall( 0x00563930 );
    zCPolygon* AddPoly( zVEC3&, zVEC3&, zVEC3&, zVEC2&, zVEC2&, zVEC2& )                     zCall( 0x005639C0 );
    zCPolygon* AddPoly( zCVertex*, zCVertex*, zCVertex* )                                    zCall( 0x00563C50 );
    zCPolygon* AddPoly( zCVertex*, zCVertex*, zCVertex*, zCVertex* )                         zCall( 0x00563D60 );
    zCPolygon* AddPoly( zCPolygon* )                                                         zCall( 0x00563E70 );
    zCPolygon* AddPoly()                                                                     zCall( 0x00563F20 );
    void DeletePoly( zCPolygon* )                                                            zCall( 0x00564000 );
    void DynLightScalePrelit( zCOLOR )                                                       zCall( 0x005640F0 );
    void PrelightMesh( zMAT4* )                                                              zCall( 0x00564100 );
    zCPolygon* SharePoly( int ) const                                                        zCall( 0x00564510 );
    zCPolygon* CheckRayPolyIntersection( zVEC3 const&, zVEC3 const&, zVEC3& )                zCall( 0x00564530 );
    zCPolygon* CheckRayPolyIntersection( zCCamera&, int, int, zVEC3& )                       zCall( 0x00564590 );
    zCPolygon* PickPolygon( zVEC3 const&, zVEC3 const&, zVEC3& )                             zCall( 0x00564740 );
    zCPolygon* PickPolygon( zCCamera&, int, int, zVEC3& )                                    zCall( 0x00564810 );
    void CalcVertexNormals( zTCalcVertNormalMode, zCBspTree* )                               zCall( 0x00564B90 );
    void UnSmoothMesh()                                                                      zCall( 0x00565290 );
    void SetDefaultPlanarMapping( float, float )                                             zCall( 0x00565330 );
    void CalcBBox3D( int )                                                                   zCall( 0x005653C0 );
    void Center()                                                                            zCall( 0x00565550 );
    void TransformAllVerts( zMAT4 const&, int )                                              zCall( 0x005656A0 );
    void MergeMesh( zCMesh*, zMAT4 const& )                                                  zCall( 0x00565760 );
    void CalcNormals()                                                                       zCall( 0x00565C40 );
    void SetMaterial( zCMaterial* )                                                          zCall( 0x00565C70 );
    void ScaleXZ( float, float )                                                             zCall( 0x00565CD0 );
    void Scale( float, float, float )                                                        zCall( 0x00565D40 );
    void CheckForMaterials() const                                                           zCall( 0x00565E00 );
    int Render_novt( zTRenderContext&, zCOLOR* )                                             zCall( 0x00565FC0 );
    int RenderHorizon( zTRenderContext&, float )                                             zCall( 0x005662A0 );
    void RenderDecal( float, float, float, int )                                             zCall( 0x00566550 );
    void RenderDecalHorizon( float, float, float, float )                                    zCall( 0x00566730 );
    void RenderDecal( zTRenderContext&, int )                                                zCall( 0x00566B50 );
    void ResetStaticLight()                                                                  zCall( 0x00566DB0 );
    void SetStaticLight( zCOLOR )                                                            zCall( 0x00566DF0 );
    void SetLightDyn( zCOLOR )                                                               zCall( 0x00566E30 );
    void SetLightStatAlpha( unsigned char )                                                  zCall( 0x00566E70 );
    void ResetLightDynToLightStat()                                                          zCall( 0x00566EB0 );
    void AddToLightDyn( zCOLOR )                                                             zCall( 0x00566EF0 );
    void SaveMSH( zCFileBIN& )                                                               zCall( 0x00568540 );
    void SaveMSH( zSTRING const& )                                                           zCall( 0x00568560 );
    int LoadMSH( zCFileBIN&, int )                                                           zCall( 0x0056AE50 );
    int LoadMSH( zSTRING const&, int )                                                       zCall( 0x0056C420 );
    void CreateListsFromArrays() const                                                       zCall( 0x0056C6D0 );
    void ClearLists() const                                                                  zCall( 0x0056C7A0 );
    void ArraysToLists() const                                                               zCall( 0x0056C800 );
    void ShareFeatures()                                                                     zCall( 0x0056C8E0 );
    void UnshareFeatures()                                                                   zCall( 0x0056D6C0 );
    void FlipPolys()                                                                         zCall( 0x0056D7E0 );
    void SortPolysByMaterial()                                                               zCall( 0x0056DA60 );
    void SortPolysByList( zCPolygon**, int )                                                 zCall( 0x0056DB10 );
    void DeletePolyAndVerts( zCPolygon* )                                                    zCall( 0x0056E3A0 );
    void DeletePolyAndVerts( unsigned long )                                                 zCall( 0x0056E430 );
    void RemoveDegeneratePolys()                                                             zCall( 0x0056E5B0 );
    void CombineLightmaps()                                                                  zCall( 0x0056E7E0 );
    void LightMesh( zCVobLight&, zMAT4&, zCWorld* )                                          zCall( 0x006222D0 );
    static zCObject* _CreateNewInstance()                                                    zCall( 0x00561AB0 );
    static zCMesh* SearchName( zSTRING const& )                                              zCall( 0x00562370 );
    static zCMesh* Load( zSTRING const&, int )                                               zCall( 0x005623E0 );
    static void S_InitVertexMergeCache( zCMesh* )                                            zCall( 0x00562E50 );
    static void S_DeleteVertexMergeCache()                                                   zCall( 0x005630D0 );
    static zCMesh* CreateQuadMesh( int )                                                     zCall( 0x00566F30 );
    static zCMesh* CreateTriMesh()                                                           zCall( 0x00567280 );
    static int CheckTexUVOnPlane( zCArray<zCVertex*> const&, zCArray<zCVertFeature> const& ) zCall( 0x00567450 );
    static void ConvertTrisToNPolys( zCPolygon**, int, zCMesh*, int )                        zCall( 0x00567950 );
    static unsigned short GetFileVersion()                                                   zCall( 0x00568530 );
    static void SaveMSH( zCFileBIN&, zCPolygon**, int, zCMesh* )                             zCall( 0x005686B0 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x00561DF0 );
    virtual ~zCMesh()                                                                        zCall( 0x00561EF0 );
    virtual int Render( zTRenderContext& )                                                   zCall( 0x00565F40 );
    virtual zTBBox3D GetBBox3D()                                                             zCall( 0x00561E50 );
    virtual zCOBBox3D* GetOBBox3D()                                                          zCall( 0x00561E80 );
    virtual zSTRING GetVisualName()                                                          zCall( 0x00561E00 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* )                       zCall( 0x005640E0 );
    virtual int CanTraceRay() const                                                          zCall( 0x00561E90 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& )               zCall( 0x00564A10 );
    virtual zSTRING const* GetFileExtension( int )                                           zCall( 0x00562030 );
    virtual int GetAlphaTestingEnabled() const                                               zCall( 0x00561EA0 );
    virtual void SetAlphaTestingEnabled( int )                                               zCall( 0x00561EB0 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                              zCall( 0x00562050 );

    // static properties
    static int& s_autoConvertMeshes;
    static int& s_usesVertexCache;
    static int& s_numMeshes;
    static zCMesh*& s_meshRoot;
    static zCArraySort<zCVertex*>& s_vertexCache;

    // user API
    #include "zCMesh.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZVISUAL_H__VER2__