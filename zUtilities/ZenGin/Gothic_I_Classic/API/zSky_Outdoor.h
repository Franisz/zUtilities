// Supported with union (c) 2018-2021 Union team

#ifndef __ZSKY__OUTDOOR_H__VER0__
#define __ZSKY__OUTDOOR_H__VER0__

#include "zRenderManager.h"

namespace Gothic_I_Classic {
  const int zEFFECT_BOX_SIDES    = 2500;
  const int zEFFECT_BOX_HEIGHT   = 1000;
  const int zMAX_FLY_PARTICLE    = 1024;
  const int zMAX_IMPACT_PARTICLE = 1024;
  const int zCACHE_SIZE          = 512;

  // sizeof 130A0h
  class zCOutdoorRainFX {
  public:

    // sizeof 20h
    struct zSParticle {
      float m_weight;       // sizeof 04h    offset 00h
      zVEC3 m_destPosition; // sizeof 0Ch    offset 04h
      zVEC3 m_destNormal;   // sizeof 0Ch    offset 10h
      int m_unused;         // sizeof 04h    offset 1Ch

      zSParticle() {}

      // user API
      #include "zCOutdoorRainFX_zSParticle.inl"
    };

    // sizeof 18h
    struct zSCacheElement {
      zVEC3 m_position; // sizeof 0Ch    offset 00h
      zVEC3 m_normal;   // sizeof 0Ch    offset 0Ch

      zSCacheElement() {}

      // user API
      #include "zCOutdoorRainFX_zSCacheElement.inl"
    };

    zSParticle m_flyParticleList[zMAX_FLY_PARTICLE];       // sizeof 8000h  offset 00h
    zSParticle m_impactParticleList[zMAX_IMPACT_PARTICLE]; // sizeof 8000h  offset 8000h
    int m_numFlyParticle;                                  // sizeof 04h    offset 10000h
    int m_numImpactParticle;                               // sizeof 04h    offset 10004h
    zCArray<zSParticle*> m_freeFlyParticleList;            // sizeof 0Ch    offset 10008h
    float m_effectWeight;                                  // sizeof 04h    offset 10014h
    int m_numDestFlyParticle;                              // sizeof 04h    offset 10018h
    zVEC3 m_camPosLastFrame;                               // sizeof 0Ch    offset 1001Ch
    zSCacheElement m_cache[zCACHE_SIZE];                   // sizeof 3000h  offset 10028h
    int m_currentCacheIndex;                               // sizeof 04h    offset 13028h
    zCShader m_shader;                                     // sizeof 20h    offset 1302Ch
    zCShaderStage m_shaderStage;                           // sizeof 30h    offset 1304Ch
    zCTexture* m_raindropTexture;                          // sizeof 04h    offset 1307Ch
    zCSoundFX* m_soundEffect;                              // sizeof 04h    offset 13080h
    int m_soundHandle;                                     // sizeof 04h    offset 13084h
    int m_soundActive;                                     // sizeof 04h    offset 13088h
    zVEC3 m_positionUpdateVector;                          // sizeof 0Ch    offset 1308Ch
    float m_velocityLen;                                   // sizeof 04h    offset 13098h
    float m_timeLen;                                       // sizeof 04h    offset 1309Ch

    void zCOutdoorRainFX_OnInit()                    zCall( 0x005B8330 );
    zCOutdoorRainFX()                                zInit( zCOutdoorRainFX_OnInit() );
    ~zCOutdoorRainFX()                               zCall( 0x005B84B0 );
    void UpdateSound( float )                        zCall( 0x005B8560 );
    void SetEffectWeight( float, float )             zCall( 0x005B8760 );
    int CheckCameraBeam( zVEC3 const& )              zCall( 0x005B8910 );
    void CreateParticles( zTRenderContext& )         zCall( 0x005B8B30 );
    void UpdateParticles()                           zCall( 0x005B9230 );
    void RenderParticles( zTRenderContext&, zCOLOR ) zCall( 0x005B93F0 );

    // user API
    #include "zCOutdoorRainFX.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZSKY__OUTDOOR_H__VER0__