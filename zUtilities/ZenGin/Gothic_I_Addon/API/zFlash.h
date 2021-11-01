// Supported with union (c) 2018-2021 Union team

#ifndef __ZFLASH_H__VER1__
#define __ZFLASH_H__VER1__

namespace Gothic_I_Addon {

  // sizeof 84h
  class zCFlash  : public zCVisual {
  public:
    // sizeof E0h
    class zCBolt : public zCPolyStrip {
    public:
      zCArray<zCBolt*> childList;   // sizeof 0Ch    offset A8h
      int isRootBolt;               // sizeof 04h    offset B4h
      int isChildOne;               // sizeof 04h    offset B8h
      int isChildTwo;               // sizeof 04h    offset BCh
      int numberOfChilds;           // sizeof 04h    offset C0h
      float roughness;              // sizeof 04h    offset C4h
      int boltIndex;                // sizeof 04h    offset C8h
      zTBSphere3D projectionSphere; // sizeof 10h    offset CCh
      float aniPhase;               // sizeof 04h    offset DCh

      void zCBolt_OnInit()                                      zCall( 0x004D0AB0 );
      zCBolt()                                                  zInit( zCBolt_OnInit() );
      void SetProjectionSphere( zTBSphere3D const& )            zCall( 0x004D0D30 );
      void Generate_R( zVEC3 const&, zVEC3 const&, float, int ) zCall( 0x004D11D0 );
      void SetTexture( zSTRING const& )                         zCall( 0x004D1AB0 );
      void InterpolateTo( zCBolt*, float )                      zCall( 0x004D1BA0 );
      void Copy( zCBolt* )                                      zCall( 0x004D1C70 );
      virtual int Render( zTRenderContext& )                    zCall( 0x004D1910 );
      virtual void FreeResources()                              zCall( 0x004D1880 );

      // user API
      #include "zCFlash_zCBolt.inl"
    };

    float timeAlive;      // sizeof 04h    offset 34h
    zVEC3 step;           // sizeof 0Ch    offset 38h
    int recalcStep;       // sizeof 04h    offset 44h
    zCBolt* rootBolt;     // sizeof 04h    offset 48h
    zCBolt* splitBolt;    // sizeof 04h    offset 4Ch
    zVEC3 boltStartPos;   // sizeof 0Ch    offset 50h
    zVEC3 boltEndPos;     // sizeof 0Ch    offset 5Ch
    float boltRoughness;  // sizeof 04h    offset 68h
    zSTRING textureName;  // sizeof 14h    offset 6Ch
    float LastUpdateTime; // sizeof 04h    offset 80h

    void zCFlash_OnInit()                                              zCall( 0x004D0480 );
    zCFlash()                                                          zInit( zCFlash_OnInit() );
    void SetProjectionSphere( zTBSphere3D const& )                     zCall( 0x004D0CD0 );
    void Generate( zCBolt*, zVEC3 const&, zVEC3 const&, float )        zCall( 0x004D0D90 );
    void SetTexture( zSTRING const& )                                  zCall( 0x004D1950 );
    void Update( float )                                               zCall( 0x004D1CC0 );
    void Create( zVEC3, zVEC3, float )                                 zCall( 0x004D1E60 );
    virtual ~zCFlash()                                                 zCall( 0x004D09B0 );
    virtual int Render( zTRenderContext& )                             zCall( 0x004D0AE0 );
    virtual int IsBBox3DLocal()                                        zCall( 0x004D0790 );
    virtual zTBBox3D GetBBox3D()                                       zCall( 0x004D07A0 );
    virtual zSTRING GetVisualName()                                    zCall( 0x004D07D0 );
    virtual int GetVisualDied()                                        zCall( 0x004D0A90 );
    virtual void SetVisualUsedBy( zCVob* )                             zCall( 0x004D0CA0 );
    virtual void DynLightVisual( zCArray<zCVobLight*> const&, zMAT4* ) zCall( 0x004D0860 );

    // user API
    #include "zCFlash.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZFLASH_H__VER1__