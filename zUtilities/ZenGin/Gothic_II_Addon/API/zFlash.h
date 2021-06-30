// Supported with union (c) 2018 Union team

#ifndef __ZFLASH_H__VER3__
#define __ZFLASH_H__VER3__

#include "zVisual.h"
#include "zMaterial.h"
#include "zPolyStrip.h"

namespace Gothic_II_Addon {

  class zCFlash  : public zCVisual {
  public:
    class zCBolt : public zCPolyStrip {
    public:
      zCArray<zCBolt*> childList;
      int isRootBolt;
      int isChildOne;
      int isChildTwo;
      int numberOfChilds;
      float roughness;
      int boltIndex;
      zTBSphere3D projectionSphere;
      float aniPhase;

      void zCBolt_OnInit()                                      zCall( 0x004CA4A0 );
      zCBolt()                                                  zInit( zCBolt_OnInit() );
      void SetProjectionSphere( zTBSphere3D const& )            zCall( 0x004CA720 );
      void Generate_R( zVEC3 const&, zVEC3 const&, float, int ) zCall( 0x004CABA0 );
      void SetTexture( zSTRING const& )                         zCall( 0x004CB4D0 );
      void InterpolateTo( zCBolt*, float )                      zCall( 0x004CB5C0 );
      void Copy( zCBolt* )                                      zCall( 0x004CB690 );
      virtual int Render( zTRenderContext& )                    zCall( 0x004CB320 );
      virtual void FreeResources()                              zCall( 0x004CB290 );

      // user API
      #include "zCFlash_zCBolt.inl"
    };

    float timeAlive;
    zVEC3 step;
    int recalcStep;
    zCBolt* rootBolt;
    zCBolt* splitBolt;
    zVEC3 boltStartPos;
    zVEC3 boltEndPos;
    float boltRoughness;
    zSTRING textureName;
    float LastUpdateTime;

    void zCFlash_OnInit()                                              zCall( 0x004C9EB0 );
    zCFlash()                                                          zInit( zCFlash_OnInit() );
    void SetProjectionSphere( zTBSphere3D const& )                     zCall( 0x004CA6C0 );
    void Generate( zCBolt*, zVEC3 const&, zVEC3 const&, float )        zCall( 0x004CA780 );
    void SetTexture( zSTRING const& )                                  zCall( 0x004CB370 );
    void Update( float )                                               zCall( 0x004CB6E0 );
    void Create( zVEC3, zVEC3, float )                                 zCall( 0x004CB890 );
    virtual ~zCFlash()                                                 zCall( 0x004CA3C0 );
    virtual int Render( zTRenderContext& )                             zCall( 0x004CA4D0 );
    virtual int IsBBox3DLocal()                                        zCall( 0x004CA1A0 );
    virtual zTBBox3D GetBBox3D()                                       zCall( 0x004CA1B0 );
    virtual zSTRING GetVisualName()                                    zCall( 0x004CA1E0 );
    virtual int GetVisualDied()                                        zCall( 0x004CA480 );
    virtual void SetVisualUsedBy( zCVob* )                             zCall( 0x004CA690 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* ) zCall( 0x004CA270 );

    // user API
    #include "zCFlash.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZFLASH_H__VER3__