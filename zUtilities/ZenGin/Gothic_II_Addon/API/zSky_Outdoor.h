// Supported with union (c) 2018 Union team

#ifndef __ZSKY__OUTDOOR_H__VER3__
#define __ZSKY__OUTDOOR_H__VER3__

#include "zSky.h"
#include "zRenderManager.h"
#include "zSound.h"

namespace Gothic_II_Addon {
  const int zSKY_NUM_LAYER       = 2;
  const int NUM_PLANETS          = 2;
  const int zEFFECT_BOX_SIDES    = 2500;
  const int zEFFECT_BOX_HEIGHT   = 1000;
  const int zMAX_FLY_PARTICLE    = 1024;
  const int zMAX_IMPACT_PARTICLE = 1024;
  const int zCACHE_SIZE          = 512;

  enum zESkyLayerMode {
    zSKY_MODE_POLY,
    zSKY_MODE_BOX
  };

  enum zTSkyStateEffect {
    zSKY_STATE_EFFECT_SUN,
    zSKY_STATE_EFFECT_CLOUDSHADOW
  };

  class zCSkyLayerData {
  public:
    zESkyLayerMode skyMode;
    zCTexture* tex;
    zSTRING texName;
    float texAlpha;
    float texScale;
    zVEC2 texSpeed;

    void zCSkyLayerData_OnInit() zCall( 0x005E4200 );
    zCSkyLayerData()             zInit( zCSkyLayerData_OnInit() );
    ~zCSkyLayerData()            zCall( 0x005E4320 );

    // user API
    #include "zCSkyLayerData.inl"
  };

  class zCSkyState {
  public:
    float time;
    zVEC3 polyColor;
    zVEC3 fogColor;
    zVEC3 domeColor1;
    zVEC3 domeColor0;
    float fogDist;
    int sunOn;
    int cloudShadowOn;
    zCSkyLayerData layer[zSKY_NUM_LAYER];

    void zCSkyState_OnInit() zCall( 0x005E43B0 );
    void PresetDay0()        zCall( 0x005E3790 );
    void PresetDay1()        zCall( 0x005E3920 );
    void PresetDay2()        zCall( 0x005E3AA0 );
    void PresetEvening()     zCall( 0x005E3B70 );
    void PresetNight0()      zCall( 0x005E3C40 );
    void PresetNight1()      zCall( 0x005E3E30 );
    void PresetNight2()      zCall( 0x005E3FB0 );
    void PresetDawn()        zCall( 0x005E4130 );
    zCSkyState()             zInit( zCSkyState_OnInit() );
    ~zCSkyState()            zCall( 0x005E43E0 );

    // user API
    #include "zCSkyState.inl"
  };

  class zCSkyLayer {
  public:
    zCMesh* skyPolyMesh;
    zCPolygon* skyPoly;
    zVEC2 skyTexOffs;
    zCMesh* skyDomeMesh;
    zESkyLayerMode skyMode;

    void zCSkyLayer_OnInit()             zCall( 0x005E45D0 );
    zCSkyLayer()                         zInit( zCSkyLayer_OnInit() );
    ~zCSkyLayer()                        zCall( 0x005E4610 );
    void SetDomeMeshEnabled( int )       zCall( 0x005E4D40 );
    void SetSkyDomeTexture( zCTexture* ) zCall( 0x005E4DA0 );
    void SetSkyPolyTexture( zCTexture* ) zCall( 0x005E4DF0 );
    void RenderSkyLayer( zCSkyState* )   zCall( 0x005E4E00 );
    void RenderSkyPoly( zCSkyState* )    zCall( 0x005E4E30 );
    void RenderSkyDome( zCSkyState* )    zCall( 0x005E5240 );
    void ColorizeSkyDome()               zCall( 0x005E56D0 );
    void RenderRainCloudLayer( zCOLOR )  zCall( 0x005E5D00 );
    static zCMesh* CreateSkyPoly()       zCall( 0x005E4400 );
    static zCMesh* CreateSkyDomeMesh()   zCall( 0x005E4670 );

    // user API
    #include "zCSkyLayer.inl"
  };

  class zCSkyPlanet {
  public:
    zCMesh* mesh;
    zVEC4 color0;
    zVEC4 color1;
    float size;
    zVEC3 pos;
    zVEC3 rotAxis;

    void zCSkyPlanet_OnInit() zCall( 0x005E66A0 );
    zCSkyPlanet()             zInit( zCSkyPlanet_OnInit() );
    ~zCSkyPlanet()            zCall( 0x005E66B0 );

    // user API
    #include "zCSkyPlanet.inl"
  };

  class zCSkyControler_Outdoor : public zCSkyControler_Mid {
  public:
    zCLASS_DECLARATION( zCSkyControler_Outdoor )

    struct zTRainFX {
      zCOutdoorRainFX* outdoorRainFX;
      zTCamLocationHint camLocationHint;
      float outdoorRainFXWeight;
      float soundVolume;
      float timerInsideSectorCantSeeOutside;
      float timeStartRain;
      float timeStopRain;
      int renderLightning;
      int m_bRaining;
      int m_iRainCtr;

      zTRainFX() {}

      // user API
      #include "zCSkyControler_Outdoor_zTRainFX.inl"
    };

    int initDone;
    float masterTime;
    float masterTimeLast;
    zCSkyState masterState;
    zCSkyState* state0;
    zCSkyState* state1;
    zCArray<zCSkyState*> stateList;
    zCOLOR polyLightCLUT[256];
    float dayCounter;
    zCArray<zVEC3> fogColorDayVariations;
    zCArray<zVEC3> fogColorDayVariations2;
    float m_fSkyScale;
    int m_bSkyScaleChanged;
    zVEC3 m_overrideColor;
    int m_bOverrideColorFlag;
    int m_bDontRain;
    int m_bLevelChanged;
    int m_bDarkSky;
    float resultFogScale;
    float heightFogMinY;
    float heightFogMaxY;
    float userFogFar;
    float resultFogNear;
    float resultFogFar;
    float resultFogSkyNear;
    float resultFogSkyFar;
    zCOLOR resultFogColor;
    zCOLOR resultFogColorOverride;
    float userFarZScalability;
    zCSkyState* skyLayerState[2];
    zCSkyLayer skyLayer[2];
    zCSkyLayer skyLayerRainClouds;
    zCTexture* skyCloudLayerTex;
    zCSkyPlanet planets[NUM_PLANETS];
    int m_bSunVisible;
    float m_fFadeScale;
    zCVob* vobSkyPFX;
    float skyPFXTimer;
    int m_bIsMainControler;
    zVEC3 m_bWindVec;
    zTRainFX rainFX;

    zCSkyControler_Outdoor() {}
    void zCSkyControler_Outdoor_OnInit( int )                               zCall( 0x005E6220 );
    zCSkyControler_Outdoor( int a0 )                                        zInit( zCSkyControler_Outdoor_OnInit( a0 ));
    void Init()                                                             zCall( 0x005E6A00 );
    int GetStateTextureSearch( int, int, int )                              zCall( 0x005E7310 );
    void ApplyStateTexToLayer( int, int )                                   zCall( 0x005E7360 );
    void RenderPlanets( float )                                             zCall( 0x005E7830 );
    void ReadFogColorsFromINI()                                             zCall( 0x005E7EA0 );
    void __fastcall ApplyFogColorsFromINI( int )                            zCall( 0x005E85F0 );
    void CreateDefault()                                                    zCall( 0x005E86D0 );
    void Interpolate()                                                      zCall( 0x005E8C20 );
    void CalcPolyLightCLUT( zVEC3 const&, zVEC3 const& )                    zCall( 0x005E93C0 );
    void InitSkyPFX()                                                       zCall( 0x005E94E0 );
    void CalcFog()                                                          zCall( 0x005E96C0 );
    void RenderSkyPFX()                                                     zCall( 0x005E9ED0 );
    void CalcGlobalWind()                                                   zCall( 0x005EA210 );
    void ProcessRainFX()                                                    zCall( 0x005EAF30 );
    void SetRainFXWeight( float, float )                                    zCall( 0x005EB230 );
    void RenderSetup()                                                      zCall( 0x005EB360 );
    void RenderSky()                                                        zCall( 0x005EB3D0 );
    static zCObject* _CreateNewInstance()                                   zCall( 0x005E0FB0 );
    virtual zCClassDef* _GetClassDef() const                                zCall( 0x005E66E0 );
    virtual void Archive( zCArchiver& )                                     zCall( 0x005EB640 );
    virtual void Unarchive( zCArchiver& )                                   zCall( 0x005EB730 );
    virtual ~zCSkyControler_Outdoor()                                       zCall( 0x005E67F0 );
    virtual void SetTime( float )                                           zCall( 0x005E9350 );
    virtual float GetTime() const                                           zCall( 0x005E66F0 );
    virtual void ResetTime()                                                zCall( 0x005E9380 );
    virtual void SetFarZ( float )                                           zCall( 0x005E9E50 );
    virtual float GetFarZ() const                                           zCall( 0x005E9E60 );
    virtual void SetFarZScalability( float )                                zCall( 0x005E9E70 );
    virtual float GetFarZScalability() const                                zCall( 0x005E9EC0 );
    virtual void SetBackgroundColor( zCOLOR )                               zCall( 0x005E6700 );
    virtual zCOLOR GetBackgroundColor() const                               zCall( 0x005E6710 );
    virtual zCOLOR GetBackgroundColorDef() const                            zCall( 0x005E6740 );
    virtual void SetOverrideColor( zVEC3 )                                  zCall( 0x005E6750 );
    virtual void SetOverrideColorFlag( int )                                zCall( 0x005E6770 );
    virtual float GetCloudShadowScale() const                               zCall( 0x005EA7F0 );
    virtual void SetCloudShadowScale( float )                               zCall( 0x005EA810 );
    virtual void UpdateWorldDependencies()                                  zCall( 0x005E72C0 );
    virtual zCOLOR GetDaylightColorFromIntensity( int )                     zCall( 0x005E93A0 );
    virtual void RenderSkyPre()                                             zCall( 0x005EA850 );
    virtual void RenderSkyPost( int )                                       zCall( 0x005EB580 );
    virtual int GetGlobalWindVec( zVEC3&, zTAnimationMode )                 zCall( 0x005EA7B0 );
    virtual void SetGlobalSkyScale( float )                                 zCall( 0x005E7290 );
    virtual float GetGlobalSkyScale() const                                 zCall( 0x005E67A0 );
    virtual int GetGlobalSkyScaleChanged() const                            zCall( 0x005E67B0 );
    virtual void SetCameraLocationHint( zCSkyControler::zTCamLocationHint ) zCall( 0x005E6790 );
    virtual void SetWeatherType( zTWeather )                                zCall( 0x005EB830 );
    virtual int GetRenderLightning() const                                  zCall( 0x005E6780 );

    // user API
    #include "zCSkyControler_Outdoor.inl"
  };

  class zCOutdoorRainFX {
  public:

    struct zSParticle {
      float m_killTotalTime;
      zVEC3 m_destPosition;
      zVEC3 m_destNormal;

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
    zTWeather m_enuWeather;
    zSCacheElement m_cache[zCACHE_SIZE];
    int m_currentCacheIndex;
    zCShader m_shader;
    zCShaderStage m_shaderStage;
    zCTexture* m_raindropTexture;
    zCTexture* m_rainTexture;
    zCMaterial* m_rainMaterial;
    zCSoundFX* m_soundEffect;
    int m_soundHandle;
    int m_soundActive;
    zVEC3 m_positionUpdateVector;
    float m_velocityLen;
    float m_timeLen;

    void zCOutdoorRainFX_OnInit()                    zCall( 0x005E10A0 );
    zCOutdoorRainFX()                                zInit( zCOutdoorRainFX_OnInit() );
    ~zCOutdoorRainFX()                               zCall( 0x005E1250 );
    void UpdateSound( float )                        zCall( 0x005E1350 );
    void SetWeatherType( zTWeather )                 zCall( 0x005E1570 );
    void SetEffectWeight( float, float )             zCall( 0x005E18E0 );
    int CheckCameraBeam( zVEC3 const& )              zCall( 0x005E1A70 );
    void CreateParticles( zTRenderContext& )         zCall( 0x005E1C70 );
    void UpdateParticles()                           zCall( 0x005E2400 );
    void RenderParticles( zTRenderContext&, zCOLOR ) zCall( 0x005E25D0 );

    // user API
    #include "zCOutdoorRainFX.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZSKY__OUTDOOR_H__VER3__