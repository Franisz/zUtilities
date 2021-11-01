// Supported with union (c) 2018-2021 Union team

#ifndef __ZPOLY_STRIP_H__VER3__
#define __ZPOLY_STRIP_H__VER3__

#include "zVisual.h"
#include "zMaterial.h"

namespace Gothic_II_Addon {

  // sizeof B4h
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
    int heightCheck;              // sizeof 04h    offset 74h
    int everyFrameUpdate;         // sizeof 04h    offset 78h
    float heightBound;            // sizeof 04h    offset 7Ch
    int firstSeg;                 // sizeof 04h    offset 80h
    int lastSeg;                  // sizeof 04h    offset 84h
    int numSeg;                   // sizeof 04h    offset 88h
    float visLastFrac;            // sizeof 04h    offset 8Ch
    float visFirstFrac;           // sizeof 04h    offset 90h
    float alphaFadeSpeed;         // sizeof 04h    offset 94h
    float newAlphaFadeSpeed;      // sizeof 04h    offset 98h
    float newAlpha;               // sizeof 04h    offset 9Ch
    int lastDirSeg;               // sizeof 04h    offset A0h
    zVEC3 lastDirNormal;          // sizeof 0Ch    offset A4h
    group {
      unsigned char localFOR : 1; // sizeof 01h    offset bit
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

  // sizeof F4h
  class zCLightning : public zCVisual {
  public:
    // sizeof C0h
    class zCBolt    : public zCPolyStrip {
    public:
      zCArray<zCBolt*> childList; // sizeof 0Ch    offset B4h

      zCBolt() {}
      void Generate_R( zVEC3 const&, zVEC3 const&, float ) zCall( 0x005BF430 );
      virtual int Render( zTRenderContext& )               zCall( 0x005BFAC0 );
      virtual void FreeResources()                         zCall( 0x005BF9F0 );

      // user API
      #include "zCLightning_zCBolt.inl"
    };

    zCBolt rootBolt; // sizeof C0h    offset 34h

    zCLightning() {}
    void SetProjectionSphere( zTBSphere3D const& ) zCall( 0x005BF3A0 );
    void Generate( zVEC3 const&, zVEC3 const& )    zCall( 0x005BF3D0 );

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
      ~zTQuadMarkPoly() zCall( 0x005D0B70 );

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