// Supported with union (c) 2018-2021 Union team

#ifndef __ZFLASH_H__VER2__
#define __ZFLASH_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 84h
  class zCFlash  : public zCVisual {
  public:
    // sizeof ECh
    class zCBolt : public zCPolyStrip {
    public:
      zCArray<zCBolt*> childList;   // sizeof 0Ch    offset B4h
      int isRootBolt;               // sizeof 04h    offset C0h
      int isChildOne;               // sizeof 04h    offset C4h
      int isChildTwo;               // sizeof 04h    offset C8h
      int numberOfChilds;           // sizeof 04h    offset CCh
      float roughness;              // sizeof 04h    offset D0h
      int boltIndex;                // sizeof 04h    offset D4h
      zTBSphere3D projectionSphere; // sizeof 10h    offset D8h
      float aniPhase;               // sizeof 04h    offset E8h

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