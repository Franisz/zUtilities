// Supported with union (c) 2018 Union team

#ifndef __ZSKY__OUTDOOR_H__VER0__
#define __ZSKY__OUTDOOR_H__VER0__

#include "zRenderManager.h"

namespace Gothic_I_Classic {
  const int zEFFECT_BOX_SIDES    = 2500;
  const int zEFFECT_BOX_HEIGHT   = 1000;
  const int zMAX_FLY_PARTICLE    = 1024;
  const int zMAX_IMPACT_PARTICLE = 1024;
  const int zCACHE_SIZE          = 512;

  class zCOutdoorRainFX {
  public:

    struct zSParticle {
      float m_weight;
      zVEC3 m_destPosition;
      zVEC3 m_destNormal;
      int m_unused;

      zSParticle() {}

      // user API
      #include "zCOutdoorRainFX_zSParticle.inl"
    };

    struct zSCacheElement {
      zVEC3 m_position;
      zVEC3 m_normal;

      zSCacheElement() {}

      // user API
      #include "zCOutdoorRainFX_zSCacheElement.inl"
    };

    zSParticle m_flyParticleList[zMAX_FLY_PARTICLE];
    zSParticle m_impactParticleList[zMAX_IMPACT_PARTICLE];
    int m_numFlyParticle;
    int m_numImpactParticle;
    zCArray<zSParticle*> m_freeFlyParticleList;
    float m_effectWeight;
    int m_numDestFlyParticle;
    zVEC3 m_camPosLastFrame;
    zSCacheElement m_cache[zCACHE_SIZE];
    int m_currentCacheIndex;
    zCShader m_shader;
    zCShaderStage m_shaderStage;
    zCTexture* m_raindropTexture;
    zCSoundFX* m_soundEffect;
    int m_soundHandle;
    int m_soundActive;
    zVEC3 m_positionUpdateVector;
    float m_velocityLen;
    float m_timeLen;

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