// Supported with union (c) 2018 Union team

#ifndef __ZRENDER_LIGHT_CONTAINER_H__VER3__
#define __ZRENDER_LIGHT_CONTAINER_H__VER3__

#include "zRenderer.h"

namespace Gothic_II_Addon {
  const int zRENDERLIGHT_LIGHT_MAX = 8;

  class zCRenderLightContainer {
  public:

    struct zTLightScore {
      int index;
      float score;

      zTLightScore() {}

      // user API
      #include "zCRenderLightContainer_zTLightScore.inl"
    };

    zCRenderLight lightList[zRENDERLIGHT_LIGHT_MAX];
    int numLights;
    int doPrelight;
    int m_bSmoothPrelit;
    float m_fPreLightDist;
    zMAT4 trafoObjToCam;

    zCRenderLightContainer() {}
    ~zCRenderLightContainer()                                          zCall( 0x0057A7A0 );
    void Clear()                                                       zCall( 0x005C1830 );
    void CreatePrelightConfig( zTBBox3D const& )                       zCall( 0x005D4650 );
    int __fastcall CollectLights_FastPath( zTRenderContext const& )    zCall( 0x005D4830 );
    void __fastcall CollectLights_DynLights( zTRenderContext const& )  zCall( 0x005D4A90 );
    void __fastcall CollectLights_StatLights( zTRenderContext const& ) zCall( 0x005D5020 );
    void __fastcall CollectLights( zTRenderContext const& )            zCall( 0x005D58C0 );
    zVEC3 CalcStatLightDir( zTRenderContext const& )                   zCall( 0x005D5C10 );
    zVEC3 LightVertex( zVEC3 const&, zVEC3 const& ) const              zCall( 0x005D5D80 );
    void __fastcall Activate( zMAT4 const& )                           zCall( 0x005D5FE0 );
    void SetupRendererLights()                                         zCall( 0x005D6100 );
    static int CompareLightScore( void const*, void const* )           zCall( 0x005D4630 );
    static void S_ReleaseVobLightRefs()                                zCall( 0x005D4A80 );

    // user API
    #include "zCRenderLightContainer.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZRENDER_LIGHT_CONTAINER_H__VER3__