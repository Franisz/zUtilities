// Supported with union (c) 2018 Union team

#ifndef __ZFLASH_H__VER2__
#define __ZFLASH_H__VER2__

namespace Gothic_II_Classic {

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

      void zCBolt_OnInit()                                      zCall( 0x004C7F30 );
      zCBolt()                                                  zInit( zCBolt_OnInit() );
      void SetProjectionSphere( zTBSphere3D const& )            zCall( 0x004C81B0 );
      void Generate_R( zVEC3 const&, zVEC3 const&, float, int ) zCall( 0x004C8630 );
      void SetTexture( zSTRING const& )                         zCall( 0x004C8F60 );
      void InterpolateTo( zCBolt*, float )                      zCall( 0x004C9050 );
      void Copy( zCBolt* )                                      zCall( 0x004C9120 );
      virtual int Render( zTRenderContext& )                    zCall( 0x004C8DB0 );
      virtual void FreeResources()                              zCall( 0x004C8D20 );

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

    void zCFlash_OnInit()                                              zCall( 0x004C7940 );
    zCFlash()                                                          zInit( zCFlash_OnInit() );
    void SetProjectionSphere( zTBSphere3D const& )                     zCall( 0x004C8150 );
    void Generate( zCBolt*, zVEC3 const&, zVEC3 const&, float )        zCall( 0x004C8210 );
    void SetTexture( zSTRING const& )                                  zCall( 0x004C8E00 );
    void Update( float )                                               zCall( 0x004C9170 );
    void Create( zVEC3, zVEC3, float )                                 zCall( 0x004C9320 );
    virtual ~zCFlash()                                                 zCall( 0x004C7E50 );
    virtual int Render( zTRenderContext& )                             zCall( 0x004C7F60 );
    virtual int IsBBox3DLocal()                                        zCall( 0x004C7C30 );
    virtual zTBBox3D GetBBox3D()                                       zCall( 0x004C7C40 );
    virtual zSTRING GetVisualName()                                    zCall( 0x004C7C70 );
    virtual int GetVisualDied()                                        zCall( 0x004C7F10 );
    virtual void SetVisualUsedBy( zCVob* )                             zCall( 0x004C8120 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* ) zCall( 0x004C7D00 );

    // user API
    #include "zCFlash.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZFLASH_H__VER2__