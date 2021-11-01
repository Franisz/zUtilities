// Supported with union (c) 2018-2021 Union team

#ifndef __ZRENDER_LIGHT_CONTAINER_H__VER2__
#define __ZRENDER_LIGHT_CONTAINER_H__VER2__

namespace Gothic_II_Classic {
  const int zRENDERLIGHT_LIGHT_MAX = 8;

  // sizeof 2B0h
  class zCRenderLightContainer {
  public:

    // sizeof 08h
    struct zTLightScore {
      int index;   // sizeof 04h    offset 00h
      float score; // sizeof 04h    offset 04h

      zTLightScore() {}

      // user API
      #include "zCRenderLightContainer_zTLightScore.inl"
    };

    zCRenderLight lightList[zRENDERLIGHT_LIGHT_MAX]; // sizeof 260h   offset 00h
    int numLights;                                   // sizeof 04h    offset 260h
    int doPrelight;                                  // sizeof 04h    offset 264h
    int m_bSmoothPrelit;                             // sizeof 04h    offset 268h
    float m_fPreLightDist;                           // sizeof 04h    offset 26Ch
    zMAT4 trafoObjToCam;                             // sizeof 40h    offset 270h

    zCRenderLightContainer() {}
    ~zCRenderLightContainer()                                          zCall( 0x00575280 );
    void Clear()                                                       zCall( 0x005BBCC0 );
    void CreatePrelightConfig( zTBBox3D const& )                       zCall( 0x005CDAA0 );
    int __fastcall CollectLights_FastPath( zTRenderContext const& )    zCall( 0x005CDC80 );
    void __fastcall CollectLights_DynLights( zTRenderContext const& )  zCall( 0x005CDEE0 );
    void __fastcall CollectLights_StatLights( zTRenderContext const& ) zCall( 0x005CE460 );
    void __fastcall CollectLights( zTRenderContext const& )            zCall( 0x005CED00 );
    zVEC3 CalcStatLightDir( zTRenderContext const& )                   zCall( 0x005CF050 );
    zVEC3 LightVertex( zVEC3 const&, zVEC3 const& ) const              zCall( 0x005CF1C0 );
    void __fastcall Activate( zMAT4 const& )                           zCall( 0x005CF420 );
    void SetupRendererLights()                                         zCall( 0x005CF540 );
    static int CompareLightScore( void const*, void const* )           zCall( 0x005CDA80 );
    static void S_ReleaseVobLightRefs()                                zCall( 0x005CDED0 );

    // user API
    #include "zCRenderLightContainer.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZRENDER_LIGHT_CONTAINER_H__VER2__