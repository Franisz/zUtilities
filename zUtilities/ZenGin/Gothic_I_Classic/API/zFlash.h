// Supported with union (c) 2018 Union team

#ifndef __ZFLASH_H__VER0__
#define __ZFLASH_H__VER0__

namespace Gothic_I_Classic {

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

      void zCBolt_OnInit()                                      zCall( 0x004C1160 );
      zCBolt()                                                  zInit( zCBolt_OnInit() );
      void SetProjectionSphere( zTBSphere3D const& )            zCall( 0x004C13E0 );
      void Generate_R( zVEC3 const&, zVEC3 const&, float, int ) zCall( 0x004C1860 );
      void SetTexture( zSTRING const& )                         zCall( 0x004C21A0 );
      void InterpolateTo( zCBolt*, float )                      zCall( 0x004C2290 );
      void Copy( zCBolt* )                                      zCall( 0x004C2350 );
      virtual int Render( zTRenderContext& )                    zCall( 0x004C1FF0 );
      virtual void FreeResources()                              zCall( 0x004C1F60 );

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

    void zCFlash_OnInit()                                              zCall( 0x004C0B70 );
    zCFlash()                                                          zInit( zCFlash_OnInit() );
    void SetProjectionSphere( zTBSphere3D const& )                     zCall( 0x004C1380 );
    void Generate( zCBolt*, zVEC3 const&, zVEC3 const&, float )        zCall( 0x004C1440 );
    void SetTexture( zSTRING const& )                                  zCall( 0x004C2040 );
    void Update( float )                                               zCall( 0x004C2390 );
    void Create( zVEC3, zVEC3, float )                                 zCall( 0x004C2540 );
    virtual ~zCFlash()                                                 zCall( 0x004C1080 );
    virtual int Render( zTRenderContext& )                             zCall( 0x004C1190 );
    virtual int IsBBox3DLocal()                                        zCall( 0x004C0E60 );
    virtual zTBBox3D GetBBox3D()                                       zCall( 0x004C0E70 );
    virtual zSTRING GetVisualName()                                    zCall( 0x004C0EA0 );
    virtual int GetVisualDied()                                        zCall( 0x004C1140 );
    virtual void SetVisualUsedBy( zCVob* )                             zCall( 0x004C1350 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* ) zCall( 0x004C0F30 );

    // user API
    #include "zCFlash.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZFLASH_H__VER0__