// Supported with union (c) 2018 Union team

#ifndef __ZPOLY_STRIP_H__VER1__
#define __ZPOLY_STRIP_H__VER1__

namespace Gothic_I_Addon {

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

    void zCPolyStrip_OnInit()                                             zCall( 0x005B79A0 );
    zCPolyStrip()                                                         zInit( zCPolyStrip_OnInit() );
    void CalcBBox3D()                                                     zCall( 0x005B7D90 );
    void EmptyEffect()                                                    zCall( 0x005B7F20 );
    void AllocateResources( int )                                         zCall( 0x005B7F50 );
    void SetVisibleSegments( float, float )                               zCall( 0x005B82A0 );
    void AddSegment( zVEC3 const&, zVEC3 const& )                         zCall( 0x005B8930 );
    void AddSegment( zVEC3 const& )                                       zCall( 0x005B8AA0 );
    void AddSegmentSmart( zVEC3 const&, zVEC3 const& )                    zCall( 0x005B8B60 );
    void UpdateSegment( int, zVEC3 const&, zVEC3 const&, zVEC3 const& )   zCall( 0x005B8E20 );
    void UpdateSegmentAlpha( int, float )                                 zCall( 0x005B8EA0 );
    void AlignToCamera()                                                  zCall( 0x005B8EC0 );
    void ProjectToSphere( zTBSphere3D const& )                            zCall( 0x005B9390 );
    void Lightning0Subdivide( zVEC3 const&, zVEC3 const&, float, int )    zCall( 0x005B94C0 );
    void GenerateCPLightning0( zVEC3 const&, zVEC3 const&, float )        zCall( 0x005B9650 );
    void GenerateCircle( zTBSphere3D const&, zVEC3 const&, zVEC3 const& ) zCall( 0x005B9790 );
    static zCObject* _CreateNewInstance()                                 zCall( 0x005B7930 );
    virtual zCClassDef* _GetClassDef() const                              zCall( 0x004D06F0 );
    virtual ~zCPolyStrip()                                                zCall( 0x005B7B10 );
    virtual int Render( zTRenderContext& )                                zCall( 0x005B8360 );
    virtual int IsBBox3DLocal()                                           zCall( 0x005B7C20 );
    virtual zTBBox3D GetBBox3D()                                          zCall( 0x005B7C30 );
    virtual zSTRING GetVisualName()                                       zCall( 0x004D0700 );
    virtual void SetVisualUsedBy( zCVob* )                                zCall( 0x005B7F00 );
    virtual void FreeResources()                                          zCall( 0x005B8200 );

    // user API
    #include "zCPolyStrip.inl"
  };

  class zCLightning : public zCVisual {
  public:
    class zCBolt    : public zCPolyStrip {
    public:
      zCArray<zCBolt*> childList;

      zCBolt() {}
      void Generate_R( zVEC3 const&, zVEC3 const&, float ) zCall( 0x005B9B30 );
      virtual int Render( zTRenderContext& )               zCall( 0x005BA1F0 );
      virtual void FreeResources()                         zCall( 0x005BA120 );

      // user API
      #include "zCLightning_zCBolt.inl"
    };

    zCBolt rootBolt;

    zCLightning() {}
    void SetProjectionSphere( zTBSphere3D const& ) zCall( 0x005B9AA0 );
    void Generate( zVEC3 const&, zVEC3 const& )    zCall( 0x005B9AD0 );

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
      ~zTQuadMarkPoly() zCall( 0x005C86C0 );

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

    void zCQuadMark_OnInit()                                                                        zCall( 0x005C8490 );
    zCQuadMark()                                                                                    zInit( zCQuadMark_OnInit() );
    int ClipQuadPolyToPlane( zTQuadMarkPoly&, zTQuadMarkPoly&, zTPlane const& )                     zCall( 0x005C8930 );
    void ClipQuadPolyToWorldPoly( zTQuadMarkPoly&, zCPolygon*, zCArray<int>& )                      zCall( 0x005C8C20 );
    void CalcQuadAxis( zCPolygon*, zVEC3&, zVEC3& )                                                 zCall( 0x005C8EC0 );
    void InitFirstQuadPoly( zCPolygon*, zVEC3 const&, zVEC3 const&, zVEC3 const&, zTEffectParams* ) zCall( 0x005C90C0 );
    void InitQuadPoly( zTQuadMarkPoly&, zCPolygon* )                                                zCall( 0x005C95D0 );
    void ProjectQuadPolyToPlane( zTQuadMarkPoly const&, zTQuadMarkPoly&, zTPlane const& )           zCall( 0x005C9650 );
    void AddQuadPolyToQuadMesh( zTQuadMarkPoly&, zCPolygon* )                                       zCall( 0x005C9740 );
    zCPolygon* GetNextWorldPoly( zCVertex*, zCVertex* )                                             zCall( 0x005C9900 );
    void ProcessWorldPoly( zCPolygon* )                                                             zCall( 0x005C9990 );
    void CreateQuadMark( zVEC3 const&, zVEC3 const&, zVEC2 const&, zSTRING&, zTEffectParams* )      zCall( 0x005C9B60 );
    void CreateQuadMark( zVEC3 const&, zVEC3 const&, zVEC2 const&, zCMaterial*, zTEffectParams* )   zCall( 0x005C9CC0 );
    void CreateQuadMark( zVEC3 const&, zVEC3 const&, zVEC2 const&, zTEffectParams* )                zCall( 0x005C9D50 );
    void CreateQuadMark( zCPolygon*, zVEC3 const&, zVEC2 const&, zTEffectParams* )                  zCall( 0x005C9DB0 );
    int GetNumActive()                                                                              zCall( 0x005CA3F0 );
    void ProcessAniTracker()                                                                        zCall( 0x005CA410 );
    static zCObject* _CreateNewInstance()                                                           zCall( 0x005C8420 );
    virtual zCClassDef* _GetClassDef() const                                                        zCall( 0x005C85E0 );
    virtual ~zCQuadMark()                                                                           zCall( 0x005C86E0 );
    virtual int Render( zTRenderContext& )                                                          zCall( 0x005C8880 );
    virtual int IsBBox3DLocal()                                                                     zCall( 0x005C85F0 );
    virtual zTBBox3D GetBBox3D()                                                                    zCall( 0x005C8840 );
    virtual zSTRING GetVisualName()                                                                 zCall( 0x005C8600 );
    virtual void SetVisualUsedBy( zCVob* )                                                          zCall( 0x005C8810 );

    // user API
    #include "zCQuadMark.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZPOLY_STRIP_H__VER1__