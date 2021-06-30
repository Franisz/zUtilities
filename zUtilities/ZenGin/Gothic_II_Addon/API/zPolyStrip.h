// Supported with union (c) 2018 Union team

#ifndef __ZPOLY_STRIP_H__VER3__
#define __ZPOLY_STRIP_H__VER3__

#include "zVisual.h"
#include "zMaterial.h"

namespace Gothic_II_Addon {

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

    void zCPolyStrip_OnInit()                                             zCall( 0x005BD300 );
    zCPolyStrip()                                                         zInit( zCPolyStrip_OnInit() );
    void CalcBBox3D()                                                     zCall( 0x005BD6C0 );
    void EmptyEffect()                                                    zCall( 0x005BD860 );
    void AllocateResources( int )                                         zCall( 0x005BD890 );
    void SetVisibleSegments( float, float )                               zCall( 0x005BDB90 );
    void AddSegment( zVEC3 const&, zVEC3 const& )                         zCall( 0x005BE2B0 );
    void AddSegment( zVEC3 const& )                                       zCall( 0x005BE430 );
    void AddSegmentSmart( zVEC3 const&, zVEC3 const& )                    zCall( 0x005BE500 );
    void UpdateSegment( int, zVEC3 const&, zVEC3 const&, zVEC3 const& )   zCall( 0x005BE760 );
    void UpdateSegmentAlpha( int, float )                                 zCall( 0x005BE7E0 );
    void AlignToCamera()                                                  zCall( 0x005BE800 );
    void ProjectToSphere( zTBSphere3D const& )                            zCall( 0x005BEC90 );
    void Lightning0Subdivide( zVEC3 const&, zVEC3 const&, float, int )    zCall( 0x005BEDB0 );
    void GenerateCPLightning0( zVEC3 const&, zVEC3 const&, float )        zCall( 0x005BEF40 );
    void GenerateCircle( zTBSphere3D const&, zVEC3 const&, zVEC3 const& ) zCall( 0x005BF090 );
    static zCObject* _CreateNewInstance()                                 zCall( 0x005BD2A0 );
    virtual zCClassDef* _GetClassDef() const                              zCall( 0x004CA100 );
    virtual ~zCPolyStrip()                                                zCall( 0x005BD480 );
    virtual int Render( zTRenderContext& )                                zCall( 0x005BDC70 );
    virtual int IsBBox3DLocal()                                           zCall( 0x005BD590 );
    virtual zTBBox3D GetBBox3D()                                          zCall( 0x005BD5A0 );
    virtual zSTRING GetVisualName()                                       zCall( 0x004CA110 );
    virtual void SetVisualUsedBy( zCVob* )                                zCall( 0x005BD840 );
    virtual void FreeResources()                                          zCall( 0x005BDAE0 );

    // user API
    #include "zCPolyStrip.inl"
  };

  class zCLightning : public zCVisual {
  public:
    class zCBolt    : public zCPolyStrip {
    public:
      zCArray<zCBolt*> childList;

      zCBolt() {}
      void Generate_R( zVEC3 const&, zVEC3 const&, float ) zCall( 0x005BF430 );
      virtual int Render( zTRenderContext& )               zCall( 0x005BFAC0 );
      virtual void FreeResources()                         zCall( 0x005BF9F0 );

      // user API
      #include "zCLightning_zCBolt.inl"
    };

    zCBolt rootBolt;

    zCLightning() {}
    void SetProjectionSphere( zTBSphere3D const& ) zCall( 0x005BF3A0 );
    void Generate( zVEC3 const&, zVEC3 const& )    zCall( 0x005BF3D0 );

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
      ~zTQuadMarkPoly() zCall( 0x005D0B70 );

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

    void zCQuadMark_OnInit()                                                                        zCall( 0x005D0970 );
    zCQuadMark()                                                                                    zInit( zCQuadMark_OnInit() );
    int ClipQuadPolyToPlane( zTQuadMarkPoly&, zTQuadMarkPoly&, zTPlane const& )                     zCall( 0x005D0DB0 );
    void ClipQuadPolyToWorldPoly( zTQuadMarkPoly&, zCPolygon*, zCArray<int>& )                      zCall( 0x005D0FF0 );
    void CalcQuadAxis( zCPolygon*, zVEC3&, zVEC3& )                                                 zCall( 0x005D1250 );
    void InitFirstQuadPoly( zCPolygon*, zVEC3 const&, zVEC3 const&, zVEC3 const&, zTEffectParams* ) zCall( 0x005D1400 );
    void InitQuadPoly( zTQuadMarkPoly&, zCPolygon* )                                                zCall( 0x005D18D0 );
    void ProjectQuadPolyToPlane( zTQuadMarkPoly const&, zTQuadMarkPoly&, zTPlane const& )           zCall( 0x005D1950 );
    void AddQuadPolyToQuadMesh( zTQuadMarkPoly&, zCPolygon* )                                       zCall( 0x005D1A30 );
    zCPolygon* GetNextWorldPoly( zCVertex*, zCVertex* )                                             zCall( 0x005D1BB0 );
    void ProcessWorldPoly( zCPolygon* )                                                             zCall( 0x005D1C40 );
    void CreateQuadMark( zVEC3 const&, zVEC3 const&, zVEC2 const&, zSTRING&, zTEffectParams* )      zCall( 0x005D1E00 );
    void CreateQuadMark( zVEC3 const&, zVEC3 const&, zVEC2 const&, zCMaterial*, zTEffectParams* )   zCall( 0x005D1F40 );
    void CreateQuadMark( zVEC3 const&, zVEC3 const&, zVEC2 const&, zTEffectParams* )                zCall( 0x005D1FD0 );
    void CreateQuadMark( zCPolygon*, zVEC3 const&, zVEC2 const&, zTEffectParams* )                  zCall( 0x005D2030 );
    int GetNumActive()                                                                              zCall( 0x005D2620 );
    void ProcessAniTracker()                                                                        zCall( 0x005D2640 );
    static zCObject* _CreateNewInstance()                                                           zCall( 0x005D0910 );
    virtual zCClassDef* _GetClassDef() const                                                        zCall( 0x005D0A90 );
    virtual ~zCQuadMark()                                                                           zCall( 0x005D0B90 );
    virtual int Render( zTRenderContext& )                                                          zCall( 0x005D0D00 );
    virtual int IsBBox3DLocal()                                                                     zCall( 0x005D0AA0 );
    virtual zTBBox3D GetBBox3D()                                                                    zCall( 0x005D0CE0 );
    virtual zSTRING GetVisualName()                                                                 zCall( 0x005D0AB0 );
    virtual void SetVisualUsedBy( zCVob* )                                                          zCall( 0x005D0CB0 );

    // user API
    #include "zCQuadMark.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZPOLY_STRIP_H__VER3__