// Supported with union (c) 2018 Union team

#ifndef __ZSKY__OUTDOOR_H__VER1__
#define __ZSKY__OUTDOOR_H__VER1__

#include "zRenderManager.h"

namespace Gothic_I_Addon {
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

    void zCOutdoorRainFX_OnInit()                    zCall( 0x005D5D30 );
    zCOutdoorRainFX()                                zInit( zCOutdoorRainFX_OnInit() );
    ~zCOutdoorRainFX()                               zCall( 0x005D5EB0 );
    void UpdateSound( float )                        zCall( 0x005D5F70 );
    void SetEffectWeight( float, float )             zCall( 0x005D6190 );
    int CheckCameraBeam( zVEC3 const& )              zCall( 0x005D6340 );
    void CreateParticles( zTRenderContext& )         zCall( 0x005D6550 );
    void UpdateParticles()                           zCall( 0x005D6C50 );
    void RenderParticles( zTRenderContext&, zCOLOR ) zCall( 0x005D6E00 );

    // user API
    #include "zCOutdoorRainFX.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZSKY__OUTDOOR_H__VER1__