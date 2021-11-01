// Supported with union (c) 2018-2021 Union team

#ifndef __ZRENDER_LIGHT_CONTAINER_H__VER1__
#define __ZRENDER_LIGHT_CONTAINER_H__VER1__

namespace Gothic_I_Addon {
  const int zRENDERLIGHT_LIGHT_MAX = 8;

  // sizeof 2A8h
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
    zMAT4 trafoObjToCam;                             // sizeof 40h    offset 268h

    zCRenderLightContainer() {}
    ~zCRenderLightContainer()                                          zCall( 0x00578E50 );
    void CreatePrelightConfig( zTBBox3D const& )                       zCall( 0x005CC2B0 );
    int __fastcall CollectLights_FastPath( zTRenderContext const& )    zCall( 0x005CC4F0 );
    void __fastcall CollectLights_DynLights( zTRenderContext const& )  zCall( 0x005CC780 );
    void __fastcall CollectLights_StatLights( zTRenderContext const& ) zCall( 0x005CCD00 );
    void __fastcall CollectLights( zTRenderContext const& )            zCall( 0x005CD230 );
    zVEC3 CalcStatLightDir( zTRenderContext const& )                   zCall( 0x005CD3C0 );
    zVEC3 LightVertex( zVEC3 const&, zVEC3 const& ) const              zCall( 0x005CD570 );
    void __fastcall Activate( zMAT4 const& )                           zCall( 0x005CD7F0 );
    void SetupRendererLights()                                         zCall( 0x005CD920 );
    static int CompareLightScore( void const*, void const* )           zCall( 0x005CC290 );
    static void S_ReleaseVobLightRefs()                                zCall( 0x005CC770 );

    // user API
    #include "zCRenderLightContainer.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZRENDER_LIGHT_CONTAINER_H__VER1__