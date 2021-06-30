// Supported with union (c) 2018 Union team

#ifndef __ZVISUAL_H__VER1__
#define __ZVISUAL_H__VER1__

namespace Gothic_I_Addon {

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

    void zCVisual_OnInit()                                                     zCall( 0x005F96C0 );
    zCVisual()                                                                 zInit( zCVisual_OnInit() );
    void AddNextLODVisual( zCVisual* )                                         zCall( 0x005F9890 );
    void AddEndLODVisual( zCVisual* )                                          zCall( 0x005F98C0 );
    static void InitVisualSystem()                                             zCall( 0x005F9970 );
    static void CleanupVisualSystem()                                          zCall( 0x005F9B20 );
    static zCVisual* LoadVisual( zSTRING const& )                              zCall( 0x005F9B70 );
    virtual zCClassDef* _GetClassDef() const                                   zCall( 0x004D0650 );
    virtual ~zCVisual()                                                        zCall( 0x005F9870 );
    virtual int Render( zTRenderContext& )                                     zPureCall;
    virtual int IsBBox3DLocal()                                                zCall( 0x00568100 );
    virtual zTBBox3D GetBBox3D()                                               zPureCall;
    virtual zCOBBox3D* GetOBBox3D()                                            zCall( 0x004D0660 );
    virtual zSTRING GetVisualName()                                            zPureCall;
    virtual int GetVisualDied()                                                zCall( 0x004D0670 );
    virtual void SetVisualUsedBy( zCVob* )                                     zCall( 0x00568110 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* )         zCall( 0x004D0680 );
    virtual unsigned long GetRenderSortKey() const                             zCall( 0x004D0690 );
    virtual int CanTraceRay() const                                            zCall( 0x004D06A0 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& ) zCall( 0x005F9960 );
    virtual void HostVobRemovedFromWorld( zCVob*, zCWorld* )                   zCall( 0x004D06B0 );
    virtual void HostVobAddedToWorld( zCVob*, zCWorld* )                       zCall( 0x004D06C0 );
    virtual zSTRING const* GetFileExtension( int )                             zCall( 0x004D06D0 );
    virtual void GetLODVisualAndAlpha( float, zCVisual*&, float& )             zCall( 0x005F98F0 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                zCall( 0x004D06E0 );


    // static properties
    static zCArray<zCVisual*>& s_visualClassList;

    // user API
    #include "zCVisual.inl"
  };

  class zCVisualAnimate : public zCVisual {
  public:
    zCLASS_DECLARATION( zCVisualAnimate )

    zCVisualAnimate() {}
    virtual zCClassDef* _GetClassDef() const        zCall( 0x00575170 );
    virtual ~zCVisualAnimate()                      zCall( 0x00575340 );
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

    void zCDecal_OnInit()                                               zCall( 0x005597A0 );
    zCDecal()                                                           zInit( zCDecal_OnInit() );
    void SetTexture( zSTRING& )                                         zCall( 0x00559BE0 );
    void SetTexture( zCTexture* )                                       zCall( 0x00559BF0 );
    void SetDecalDim( float, float )                                    zCall( 0x00559C00 );
    static zCObject* _CreateNewInstance()                               zCall( 0x00559650 );
    static void CleanupDecals()                                         zCall( 0x00559900 );
    static void CreateDecalMeshes()                                     zCall( 0x00559980 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00559780 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00559F30 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0055A000 );
    virtual ~zCDecal()                                                  zCall( 0x00559890 );
    virtual int Render( zTRenderContext& )                              zCall( 0x00559C20 );
    virtual int IsBBox3DLocal()                                         zCall( 0x00559790 );
    virtual zTBBox3D GetBBox3D()                                        zCall( 0x00559D70 );
    virtual zSTRING GetVisualName()                                     zCall( 0x00559DC0 );
    virtual void SetVisualUsedBy( zCVob* )                              zCall( 0x00559D60 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* )  zCall( 0x00559E10 );
    virtual unsigned long GetRenderSortKey() const                      zCall( 0x00559BD0 );
    virtual zSTRING const* GetFileExtension( int )                      zCall( 0x005599F0 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const         zCall( 0x00559A50 );


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
    int numVertAlloc;
    int numPolyAlloc;

    void zCMesh_OnInit()                                                                     zCall( 0x00567EC0 );
    void LODRecalcEdge( zTLODEdge&, zCArraySort<zCPolygon*>& )                               zCall( 0x0053F620 );
    void LODGenerate( zCArraySort<zCPolygon*>&, zCArraySort<zCPolygon*>& )                   zCall( 0x0053FE30 );
    zCMesh()                                                                                 zInit( zCMesh_OnInit() );
    void DeleteAll()                                                                         zCall( 0x00568370 );
    zCVertex* VertexInMesh( zVEC3 const& )                                                   zCall( 0x005692D0 );
    void AllocVerts( int )                                                                   zCall( 0x005693A0 );
    void AllocPolys( int )                                                                   zCall( 0x005694A0 );
    zCVertex* AddVertex( zCVertex* )                                                         zCall( 0x00569570 );
    zCVertex* AddVertex( zVEC3& )                                                            zCall( 0x005696F0 );
    zCVertex* AddVertexSmart( zVEC3& )                                                       zCall( 0x00569850 );
    zCPolygon* AddPoly( zVEC3&, zVEC3&, zVEC3&, zVEC2&, zVEC2&, zVEC2& )                     zCall( 0x00569980 );
    zCPolygon* AddPoly( zCVertex*, zCVertex*, zCVertex* )                                    zCall( 0x00569C30 );
    zCPolygon* AddPoly( zCVertex*, zCVertex*, zCVertex*, zCVertex* )                         zCall( 0x00569D50 );
    zCPolygon* AddPoly( zCPolygon* )                                                         zCall( 0x00569E80 );
    zCPolygon* AddPoly()                                                                     zCall( 0x00569F30 );
    void DeletePoly( zCPolygon* )                                                            zCall( 0x0056A030 );
    void DynLightScalePrelit( zCOLOR )                                                       zCall( 0x0056A120 );
    void PrelightMesh( zMAT4* )                                                              zCall( 0x0056A130 );
    zCPolygon* SharePoly( int ) const                                                        zCall( 0x0056A5B0 );
    zCPolygon* CheckRayPolyIntersection( zVEC3 const&, zVEC3 const&, zVEC3& )                zCall( 0x0056A5E0 );
    zCPolygon* CheckRayPolyIntersection( zCCamera&, int, int, zVEC3& )                       zCall( 0x0056A640 );
    zCPolygon* PickPolygon( zVEC3 const&, zVEC3 const&, zVEC3& )                             zCall( 0x0056A7C0 );
    zCPolygon* PickPolygon( zCCamera&, int, int, zVEC3& )                                    zCall( 0x0056A890 );
    void CalcVertexNormals( zTCalcVertNormalMode, zCBspTree* )                               zCall( 0x0056ABE0 );
    void UnSmoothMesh()                                                                      zCall( 0x0056B2A0 );
    void SetDefaultPlanarMapping( float, float )                                             zCall( 0x0056B340 );
    void CalcBBox3D( int )                                                                   zCall( 0x0056B3D0 );
    void Center()                                                                            zCall( 0x0056B540 );
    void TransformAllVerts( zMAT4 const&, int )                                              zCall( 0x0056B6B0 );
    void MergeMesh( zCMesh*, zMAT4 const& )                                                  zCall( 0x0056B790 );
    void CalcNormals()                                                                       zCall( 0x0056BB80 );
    void SetMaterial( zCMaterial* )                                                          zCall( 0x0056BBB0 );
    void ScaleXZ( float, float )                                                             zCall( 0x0056BC10 );
    void Scale( float, float, float )                                                        zCall( 0x0056BC70 );
    void CheckForMaterials() const                                                           zCall( 0x0056BD20 );
    int Render_novt( zTRenderContext&, zCOLOR* )                                             zCall( 0x0056BEF0 );
    void RenderDecal( float, float, float, int )                                             zCall( 0x0056C1E0 );
    void RenderDecal( zTRenderContext&, int )                                                zCall( 0x0056C3B0 );
    void ResetStaticLight()                                                                  zCall( 0x0056C620 );
    void SetStaticLight( zCOLOR )                                                            zCall( 0x0056C660 );
    void SetLightDyn( zCOLOR )                                                               zCall( 0x0056C6A0 );
    void SetLightStatAlpha( unsigned char )                                                  zCall( 0x0056C6E0 );
    void ResetLightDynToLightStat()                                                          zCall( 0x0056C720 );
    void AddToLightDyn( zCOLOR )                                                             zCall( 0x0056C760 );
    void SaveMSH( zCFileBIN& )                                                               zCall( 0x0056DDF0 );
    void SaveMSH( zSTRING const& )                                                           zCall( 0x0056DE10 );
    int LoadMSH( zCFileBIN&, int )                                                           zCall( 0x0056F2E0 );
    int LoadMSH( zSTRING const&, int )                                                       zCall( 0x00570860 );
    void CreateListsFromArrays() const                                                       zCall( 0x00570B30 );
    void ClearLists() const                                                                  zCall( 0x00570C30 );
    void ArraysToLists() const                                                               zCall( 0x00570C90 );
    void ShareFeatures()                                                                     zCall( 0x00570D70 );
    void UnshareFeatures()                                                                   zCall( 0x00571B10 );
    void FlipPolys()                                                                         zCall( 0x00571C30 );
    void SortPolysByMaterial()                                                               zCall( 0x00571C80 );
    void SortPolysByList( zCPolygon**, int )                                                 zCall( 0x00571D30 );
    void DeletePolyAndVerts( zCPolygon* )                                                    zCall( 0x00572630 );
    void DeletePolyAndVerts( unsigned long )                                                 zCall( 0x005726C0 );
    void RemoveDegeneratePolys()                                                             zCall( 0x00572850 );
    void CombineLightmaps()                                                                  zCall( 0x00572A10 );
    void LightMesh( zCVobLight&, zMAT4&, zCWorld* )                                          zCall( 0x0061C6F0 );
    static zCObject* _CreateNewInstance()                                                    zCall( 0x00567E50 );
    static zCMesh* SearchName( zSTRING const& )                                              zCall( 0x005686A0 );
    static zCMesh* Load( zSTRING const& )                                                    zCall( 0x00568710 );
    static zCMesh* CreateQuadMesh( int )                                                     zCall( 0x0056C7A0 );
    static zCMesh* CreateTriMesh()                                                           zCall( 0x0056CB10 );
    static int CheckTexUVOnPlane( zCArray<zCVertex*> const&, zCArray<zCVertFeature> const& ) zCall( 0x0056CD10 );
    static void ConvertTrisToNPolys( zCPolygon**, int, zCMesh*, int )                        zCall( 0x0056D2D0 );
    static unsigned short GetFileVersion()                                                   zCall( 0x0056DDE0 );
    static void SaveMSH( zCFileBIN&, zCPolygon**, int, zCMesh* )                             zCall( 0x0056DF70 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x00568120 );
    virtual ~zCMesh()                                                                        zCall( 0x00568200 );
    virtual int Render( zTRenderContext& )                                                   zCall( 0x0056BE70 );
    virtual zTBBox3D GetBBox3D()                                                             zCall( 0x00568180 );
    virtual zCOBBox3D* GetOBBox3D()                                                          zCall( 0x005681B0 );
    virtual zSTRING GetVisualName()                                                          zCall( 0x00568130 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* )                       zCall( 0x0056A110 );
    virtual int CanTraceRay() const                                                          zCall( 0x005681C0 );
    virtual int TraceRay( zVEC3 const&, zVEC3 const&, int, zTTraceRayReport& )               zCall( 0x0056AA60 );
    virtual zSTRING const* GetFileExtension( int )                                           zCall( 0x00568340 );
    virtual zCVisual* LoadVisualVirtual( zSTRING const& ) const                              zCall( 0x00568360 );


    // static properties
    static int& s_autoConvertMeshes;
    static int& s_numMeshes;
    static zCMesh*& s_meshRoot;

    // user API
    #include "zCMesh.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZVISUAL_H__VER1__