// Supported with union (c) 2018-2021 Union team

#ifndef __ZPOLY_STRIP_H__VER0__
#define __ZPOLY_STRIP_H__VER0__

namespace Gothic_I_Classic {

  // sizeof A8h
  class zCPolyStrip : public zCVisual {
  public:
    zCLASS_DECLARATION( zCPolyStrip )

    enum zTCamAlign {
      zCAM_ALIGN_NONE,
      zCAM_ALIGN_STRIP,
      zCAM_ALIGN_POLY
    };

    zCMaterial* material;         // sizeof 04h    offset 34h
    zCVertex* vertList;           // sizeof 04h    offset 38h
    zCPolygon* polyList;          // sizeof 04h    offset 3Ch
    int numPoly;                  // sizeof 04h    offset 40h
    int numVert;                  // sizeof 04h    offset 44h
    zVEC3* centerPointList;       // sizeof 04h    offset 48h
    float* alphaList;             // sizeof 04h    offset 4Ch
    float width;                  // sizeof 04h    offset 50h
    zCVob* connectedVob;          // sizeof 04h    offset 54h
    zTBBox3D bbox3D;              // sizeof 18h    offset 58h
    zTCamAlign camAlign;          // sizeof 04h    offset 70h
    int firstSeg;                 // sizeof 04h    offset 74h
    int lastSeg;                  // sizeof 04h    offset 78h
    int numSeg;                   // sizeof 04h    offset 7Ch
    float visLastFrac;            // sizeof 04h    offset 80h
    float visFirstFrac;           // sizeof 04h    offset 84h
    float alphaFadeSpeed;         // sizeof 04h    offset 88h
    float newAlphaFadeSpeed;      // sizeof 04h    offset 8Ch
    float newAlpha;               // sizeof 04h    offset 90h
    int lastDirSeg;               // sizeof 04h    offset 94h
    zVEC3 lastDirNormal;          // sizeof 0Ch    offset 98h
    group {
      unsigned char localFOR : 1; // sizeof 01h    offset bit
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

  // sizeof E8h
  class zCLightning : public zCVisual {
  public:
    // sizeof B4h
    class zCBolt    : public zCPolyStrip {
    public:
      zCArray<zCBolt*> childList; // sizeof 0Ch    offset A8h

      zCBolt() {}
      void Generate_R( zVEC3 const&, zVEC3 const&, float ) zCall( 0x0059D560 );
      virtual int Render( zTRenderContext& )               zCall( 0x0059DBF0 );
      virtual void FreeResources()                         zCall( 0x0059DB20 );

      // user API
      #include "zCLightning_zCBolt.inl"
    };

    zCBolt rootBolt; // sizeof B4h    offset 34h

    zCLightning() {}
    void SetProjectionSphere( zTBSphere3D const& ) zCall( 0x0059D4D0 );
    void Generate( zVEC3 const&, zVEC3 const& )    zCall( 0x0059D500 );

    // user API
    #include "zCLightning.inl"
  };

  // sizeof 88h
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

    // sizeof 10h
    struct zTEffectParams {
      zTTexAniType texAniType; // sizeof 04h    offset 00h
      float texAniScaleStart;  // sizeof 04h    offset 04h
      float texAniSpeed;       // sizeof 04h    offset 08h
      float alphaFadeSpeed;    // sizeof 04h    offset 0Ch

      zTEffectParams() {}

      // user API
      #include "zCQuadMark_zTEffectParams.inl"
    };

    // sizeof 14h
    struct zTQuadMarkVert {
      zVEC3 position; // sizeof 0Ch    offset 00h
      zVEC2 texCoord; // sizeof 08h    offset 0Ch

      zTQuadMarkVert() {}

      // user API
      #include "zCQuadMark_zTQuadMarkVert.inl"
    };

    // sizeof 0Ch
    struct zTQuadMarkPoly {
      zCArray<zTQuadMarkVert> vertex; // sizeof 0Ch    offset 00h

      zTQuadMarkPoly() {}
      ~zTQuadMarkPoly() zCall( 0x005ABA40 );

      // user API
      #include "zCQuadMark_zTQuadMarkPoly.inl"
    };

    // sizeof 30h
    struct zTQuadMarkAniState {
      int firstPolyIndex;      // sizeof 04h    offset 00h
      int lastPolyIndex;       // sizeof 04h    offset 04h
      float scaleStart;        // sizeof 04h    offset 08h
      float scaleCur;          // sizeof 04h    offset 0Ch
      float scaleSpeed;        // sizeof 04h    offset 10h
      float scaleSpeedCur;     // sizeof 04h    offset 14h
      zVEC2 uvDelta;           // sizeof 08h    offset 18h
      zVEC2 uvScale;           // sizeof 08h    offset 20h
      zTTexAniType texAniType; // sizeof 04h    offset 28h
      float alpha;             // sizeof 04h    offset 2Ch

      zTQuadMarkAniState() {}

      // user API
      #include "zCQuadMark_zTQuadMarkAniState.inl"
    };

    zCMesh* quadMesh;                               // sizeof 04h    offset 34h
    zCVob* connectedVob;                            // sizeof 04h    offset 38h
    zCMaterial* material;                           // sizeof 04h    offset 3Ch
    zCMaterial* actMaterial;                        // sizeof 04h    offset 40h
    float alphaFadeSpeed;                           // sizeof 04h    offset 44h
    int dontRepositionConnectedVob;                 // sizeof 04h    offset 48h
    zCArray<zTQuadMarkAniState> quadMarkAniTracker; // sizeof 0Ch    offset 4Ch
    zCPolygon** worldPolyList;                      // sizeof 04h    offset 58h
    int numWorldPoly;                               // sizeof 04h    offset 5Ch
    zCArray<zCPolygon*> visitedPolyList;            // sizeof 0Ch    offset 60h
    zTQuadMarkPoly firstQuadPoly;                   // sizeof 0Ch    offset 6Ch
    zCPolygon* firstWorldPoly;                      // sizeof 04h    offset 78h
    zVEC3 averageNormal;                            // sizeof 0Ch    offset 7Ch

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