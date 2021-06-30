// Supported with union (c) 2018 Union team

#ifndef __ZPOLY_STRIP_H__VER2__
#define __ZPOLY_STRIP_H__VER2__

namespace Gothic_II_Classic {

  class zCPolyStrip : public zCVisual {
  public:
    zCLASS_DECLARATION( zCPolyStrip )

    enum zTCamAlign {
      zCAM_ALIGN_NONE,
      zCAM_ALIGN_STRIP,
      zCAM_ALIGN_POLY
    };

    zCMaterial* material;
    zCVertex* vertList;
    zCPolygon* polyList;
    int numPoly;
    int numVert;
    zVEC3* centerPointList;
    float* alphaList;
    float width;
    zCVob* connectedVob;
    zTBBox3D bbox3D;
    zTCamAlign camAlign;
    int heightCheck;
    int everyFrameUpdate;
    float heightBound;
    int firstSeg;
    int lastSeg;
    int numSeg;
    float visLastFrac;
    float visFirstFrac;
    float alphaFadeSpeed;
    float newAlphaFadeSpeed;
    float newAlpha;
    int lastDirSeg;
    zVEC3 lastDirNormal;
    group {
      unsigned char localFOR : 1;
    };

    void zCPolyStrip_OnInit()                                             zCall( 0x005B7790 );
    zCPolyStrip()                                                         zInit( zCPolyStrip_OnInit() );
    void CalcBBox3D()                                                     zCall( 0x005B7B50 );
    void EmptyEffect()                                                    zCall( 0x005B7CF0 );
    void AllocateResources( int )                                         zCall( 0x005B7D20 );
    void SetVisibleSegments( float, float )                               zCall( 0x005B8020 );
    void AddSegment( zVEC3 const&, zVEC3 const& )                         zCall( 0x005B8740 );
    void AddSegment( zVEC3 const& )                                       zCall( 0x005B88C0 );
    void AddSegmentSmart( zVEC3 const&, zVEC3 const& )                    zCall( 0x005B8990 );
    void UpdateSegment( int, zVEC3 const&, zVEC3 const&, zVEC3 const& )   zCall( 0x005B8BF0 );
    void UpdateSegmentAlpha( int, float )                                 zCall( 0x005B8C70 );
    void AlignToCamera()                                                  zCall( 0x005B8C90 );
    void ProjectToSphere( zTBSphere3D const& )                            zCall( 0x005B9120 );
    void Lightning0Subdivide( zVEC3 const&, zVEC3 const&, float, int )    zCall( 0x005B9240 );
    void GenerateCPLightning0( zVEC3 const&, zVEC3 const&, float )        zCall( 0x005B93D0 );
    void GenerateCircle( zTBSphere3D const&, zVEC3 const&, zVEC3 const& ) zCall( 0x005B9520 );
    static zCObject* _CreateNewInstance()                                 zCall( 0x005B7730 );
    virtual zCClassDef* _GetClassDef() const                              zCall( 0x004C7B90 );
    virtual ~zCPolyStrip()                                                zCall( 0x005B7910 );
    virtual int Render( zTRenderContext& )                                zCall( 0x005B8100 );
    virtual int IsBBox3DLocal()                                           zCall( 0x005B7A20 );
    virtual zTBBox3D GetBBox3D()                                          zCall( 0x005B7A30 );
    virtual zSTRING GetVisualName()                                       zCall( 0x004C7BA0 );
    virtual void SetVisualUsedBy( zCVob* )                                zCall( 0x005B7CD0 );
    virtual void FreeResources()                                          zCall( 0x005B7F70 );

    // user API
    #include "zCPolyStrip.inl"
  };

  class zCLightning : public zCVisual {
  public:
    class zCBolt    : public zCPolyStrip {
    public:
      zCArray<zCBolt*> childList;

      zCBolt() {}
      void Generate_R( zVEC3 const&, zVEC3 const&, float ) zCall( 0x005B98C0 );
      virtual int Render( zTRenderContext& )               zCall( 0x005B9F50 );
      virtual void FreeResources()                         zCall( 0x005B9E80 );

      // user API
      #include "zCLightning_zCBolt.inl"
    };

    zCBolt rootBolt;

    zCLightning() {}
    void SetProjectionSphere( zTBSphere3D const& ) zCall( 0x005B9830 );
    void Generate( zVEC3 const&, zVEC3 const& )    zCall( 0x005B9860 );

    // user API
    #include "zCLightning.inl"
  };

  class zCQuadMark : public zCVisual {
  public:
    zCLASS_DECLARATION( zCQuadMark )

    enum zTTexAniType {
      zTEXANI_NONE,
      zTEXANI_SCALEUP,
      zTEXANI_SCALEUP_GRAV,
      zTEXANI_SCALEUP_AUTO,
      zTEXANI_SCALEDOWN
    };

    struct zTEffectParams {
      zTTexAniType texAniType;
      float texAniScaleStart;
      float texAniSpeed;
      float alphaFadeSpeed;

      zTEffectParams() {}

      // user API
      #include "zCQuadMark_zTEffectParams.inl"
    };

    struct zTQuadMarkVert {
      zVEC3 position;
      zVEC2 texCoord;

      zTQuadMarkVert() {}

      // user API
      #include "zCQuadMark_zTQuadMarkVert.inl"
    };

    struct zTQuadMarkPoly {
      zCArray<zTQuadMarkVert> vertex;

      zTQuadMarkPoly() {}
      ~zTQuadMarkPoly() zCall( 0x005C9FD0 );

      // user API
      #include "zCQuadMark_zTQuadMarkPoly.inl"
    };

    struct zTQuadMarkAniState {
      int firstPolyIndex;
      int lastPolyIndex;
      float scaleStart;
      float scaleCur;
      float scaleSpeed;
      float scaleSpeedCur;
      zVEC2 uvDelta;
      zVEC2 uvScale;
      zTTexAniType texAniType;
      float alpha;

      zTQuadMarkAniState() {}

      // user API
      #include "zCQuadMark_zTQuadMarkAniState.inl"
    };

    zCMesh* quadMesh;
    zCVob* connectedVob;
    zCMaterial* material;
    zCMaterial* actMaterial;
    float alphaFadeSpeed;
    int dontRepositionConnectedVob;
    zCArray<zTQuadMarkAniState> quadMarkAniTracker;
    zCPolygon** worldPolyList;
    int numWorldPoly;
    zCArray<zCPolygon*> visitedPolyList;
    zTQuadMarkPoly firstQuadPoly;
    zCPolygon* firstWorldPoly;
    zVEC3 averageNormal;

    void zCQuadMark_OnInit()                                                                        zCall( 0x005C9DD0 );
    zCQuadMark()                                                                                    zInit( zCQuadMark_OnInit() );
    int ClipQuadPolyToPlane( zTQuadMarkPoly&, zTQuadMarkPoly&, zTPlane const& )                     zCall( 0x005CA210 );
    void ClipQuadPolyToWorldPoly( zTQuadMarkPoly&, zCPolygon*, zCArray<int>& )                      zCall( 0x005CA450 );
    void CalcQuadAxis( zCPolygon*, zVEC3&, zVEC3& )                                                 zCall( 0x005CA6B0 );
    void InitFirstQuadPoly( zCPolygon*, zVEC3 const&, zVEC3 const&, zVEC3 const&, zTEffectParams* ) zCall( 0x005CA860 );
    void InitQuadPoly( zTQuadMarkPoly&, zCPolygon* )                                                zCall( 0x005CAD30 );
    void ProjectQuadPolyToPlane( zTQuadMarkPoly const&, zTQuadMarkPoly&, zTPlane const& )           zCall( 0x005CADB0 );
    void AddQuadPolyToQuadMesh( zTQuadMarkPoly&, zCPolygon* )                                       zCall( 0x005CAE90 );
    zCPolygon* GetNextWorldPoly( zCVertex*, zCVertex* )                                             zCall( 0x005CB010 );
    void ProcessWorldPoly( zCPolygon* )                                                             zCall( 0x005CB0A0 );
    void CreateQuadMark( zVEC3 const&, zVEC3 const&, zVEC2 const&, zSTRING&, zTEffectParams* )      zCall( 0x005CB260 );
    void CreateQuadMark( zVEC3 const&, zVEC3 const&, zVEC2 const&, zCMaterial*, zTEffectParams* )   zCall( 0x005CB3A0 );
    void CreateQuadMark( zVEC3 const&, zVEC3 const&, zVEC2 const&, zTEffectParams* )                zCall( 0x005CB430 );
    void CreateQuadMark( zCPolygon*, zVEC3 const&, zVEC2 const&, zTEffectParams* )                  zCall( 0x005CB490 );
    int GetNumActive()                                                                              zCall( 0x005CBA70 );
    void ProcessAniTracker()                                                                        zCall( 0x005CBA90 );
    static zCObject* _CreateNewInstance()                                                           zCall( 0x005C9D70 );
    virtual zCClassDef* _GetClassDef() const                                                        zCall( 0x005C9EF0 );
    virtual ~zCQuadMark()                                                                           zCall( 0x005C9FF0 );
    virtual int Render( zTRenderContext& )                                                          zCall( 0x005CA160 );
    virtual int IsBBox3DLocal()                                                                     zCall( 0x005C9F00 );
    virtual zTBBox3D GetBBox3D()                                                                    zCall( 0x005CA140 );
    virtual zSTRING GetVisualName()                                                                 zCall( 0x005C9F10 );
    virtual void SetVisualUsedBy( zCVob* )                                                          zCall( 0x005CA110 );

    // user API
    #include "zCQuadMark.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZPOLY_STRIP_H__VER2__