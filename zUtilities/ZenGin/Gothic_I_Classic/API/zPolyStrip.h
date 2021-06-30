// Supported with union (c) 2018 Union team

#ifndef __ZPOLY_STRIP_H__VER0__
#define __ZPOLY_STRIP_H__VER0__

namespace Gothic_I_Classic {

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

    void zCPolyStrip_OnInit()                                             zCall( 0x0059B610 );
    zCPolyStrip()                                                         zInit( zCPolyStrip_OnInit() );
    void CalcBBox3D()                                                     zCall( 0x0059B9A0 );
    void EmptyEffect()                                                    zCall( 0x0059BB20 );
    void AllocateResources( int )                                         zCall( 0x0059BB50 );
    void SetVisibleSegments( float, float )                               zCall( 0x0059BE80 );
    void AddSegment( zVEC3 const&, zVEC3 const& )                         zCall( 0x0059C460 );
    void AddSegment( zVEC3 const& )                                       zCall( 0x0059C5C0 );
    void AddSegmentSmart( zVEC3 const&, zVEC3 const& )                    zCall( 0x0059C680 );
    void UpdateSegment( int, zVEC3 const&, zVEC3 const&, zVEC3 const& )   zCall( 0x0059C8E0 );
    void UpdateSegmentAlpha( int, float )                                 zCall( 0x0059C960 );
    void AlignToCamera()                                                  zCall( 0x0059C980 );
    void ProjectToSphere( zTBSphere3D const& )                            zCall( 0x0059CE00 );
    void Lightning0Subdivide( zVEC3 const&, zVEC3 const&, float, int )    zCall( 0x0059CF10 );
    void GenerateCPLightning0( zVEC3 const&, zVEC3 const&, float )        zCall( 0x0059D0A0 );
    void GenerateCircle( zTBSphere3D const&, zVEC3 const&, zVEC3 const& ) zCall( 0x0059D1E0 );
    static zCObject* _CreateNewInstance()                                 zCall( 0x0059B5A0 );
    virtual zCClassDef* _GetClassDef() const                              zCall( 0x004C0DC0 );
    virtual ~zCPolyStrip()                                                zCall( 0x0059B770 );
    virtual int Render( zTRenderContext& )                                zCall( 0x0059BF50 );
    virtual int IsBBox3DLocal()                                           zCall( 0x0059B870 );
    virtual zTBBox3D GetBBox3D()                                          zCall( 0x0059B880 );
    virtual zSTRING GetVisualName()                                       zCall( 0x004C0DD0 );
    virtual void SetVisualUsedBy( zCVob* )                                zCall( 0x0059BB00 );
    virtual void FreeResources()                                          zCall( 0x0059BDE0 );

    // user API
    #include "zCPolyStrip.inl"
  };

  class zCLightning : public zCVisual {
  public:
    class zCBolt    : public zCPolyStrip {
    public:
      zCArray<zCBolt*> childList;

      zCBolt() {}
      void Generate_R( zVEC3 const&, zVEC3 const&, float ) zCall( 0x0059D560 );
      virtual int Render( zTRenderContext& )               zCall( 0x0059DBF0 );
      virtual void FreeResources()                         zCall( 0x0059DB20 );

      // user API
      #include "zCLightning_zCBolt.inl"
    };

    zCBolt rootBolt;

    zCLightning() {}
    void SetProjectionSphere( zTBSphere3D const& ) zCall( 0x0059D4D0 );
    void Generate( zVEC3 const&, zVEC3 const& )    zCall( 0x0059D500 );

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
      ~zTQuadMarkPoly() zCall( 0x005ABA40 );

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

    void zCQuadMark_OnInit()                                                                        zCall( 0x005AB810 );
    zCQuadMark()                                                                                    zInit( zCQuadMark_OnInit() );
    int ClipQuadPolyToPlane( zTQuadMarkPoly&, zTQuadMarkPoly&, zTPlane const& )                     zCall( 0x005ABC80 );
    void ClipQuadPolyToWorldPoly( zTQuadMarkPoly&, zCPolygon*, zCArray<int>& )                      zCall( 0x005ABEC0 );
    void CalcQuadAxis( zCPolygon*, zVEC3&, zVEC3& )                                                 zCall( 0x005AC120 );
    void InitFirstQuadPoly( zCPolygon*, zVEC3 const&, zVEC3 const&, zVEC3 const&, zTEffectParams* ) zCall( 0x005AC2D0 );
    void InitQuadPoly( zTQuadMarkPoly&, zCPolygon* )                                                zCall( 0x005AC7A0 );
    void ProjectQuadPolyToPlane( zTQuadMarkPoly const&, zTQuadMarkPoly&, zTPlane const& )           zCall( 0x005AC820 );
    void AddQuadPolyToQuadMesh( zTQuadMarkPoly&, zCPolygon* )                                       zCall( 0x005AC900 );
    zCPolygon* GetNextWorldPoly( zCVertex*, zCVertex* )                                             zCall( 0x005ACA80 );
    void ProcessWorldPoly( zCPolygon* )                                                             zCall( 0x005ACB10 );
    void CreateQuadMark( zVEC3 const&, zVEC3 const&, zVEC2 const&, zSTRING&, zTEffectParams* )      zCall( 0x005ACCD0 );
    void CreateQuadMark( zVEC3 const&, zVEC3 const&, zVEC2 const&, zCMaterial*, zTEffectParams* )   zCall( 0x005ACE30 );
    void CreateQuadMark( zVEC3 const&, zVEC3 const&, zVEC2 const&, zTEffectParams* )                zCall( 0x005ACEC0 );
    void CreateQuadMark( zCPolygon*, zVEC3 const&, zVEC2 const&, zTEffectParams* )                  zCall( 0x005ACF20 );
    int GetNumActive()                                                                              zCall( 0x005AD4B0 );
    void ProcessAniTracker()                                                                        zCall( 0x005AD4D0 );
    static zCObject* _CreateNewInstance()                                                           zCall( 0x005AB7A0 );
    virtual zCClassDef* _GetClassDef() const                                                        zCall( 0x005AB960 );
    virtual ~zCQuadMark()                                                                           zCall( 0x005ABA60 );
    virtual int Render( zTRenderContext& )                                                          zCall( 0x005ABBD0 );
    virtual int IsBBox3DLocal()                                                                     zCall( 0x005AB970 );
    virtual zTBBox3D GetBBox3D()                                                                    zCall( 0x005ABBB0 );
    virtual zSTRING GetVisualName()                                                                 zCall( 0x005AB980 );
    virtual void SetVisualUsedBy( zCVob* )                                                          zCall( 0x005ABB80 );

    // user API
    #include "zCQuadMark.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZPOLY_STRIP_H__VER0__