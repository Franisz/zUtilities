// Supported with union (c) 2018 Union team

#ifndef __ZSKY__OUTDOOR_H__VER2__
#define __ZSKY__OUTDOOR_H__VER2__

#include "zSky.h"
#include "zRenderManager.h"
#include "zSound.h"

namespace Gothic_II_Classic {
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

    void zCSkyLayerData_OnInit() zCall( 0x005DD450 );
    zCSkyLayerData()             zInit( zCSkyLayerData_OnInit() );
    ~zCSkyLayerData()            zCall( 0x005DD570 );

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

    void zCSkyState_OnInit() zCall( 0x005DD600 );
    void PresetDay0()        zCall( 0x005DC9E0 );
    void PresetDay1()        zCall( 0x005DCB70 );
    void PresetDay2()        zCall( 0x005DCCF0 );
    void PresetEvening()     zCall( 0x005DCDC0 );
    void PresetNight0()      zCall( 0x005DCE90 );
    void PresetNight1()      zCall( 0x005DD080 );
    void PresetNight2()      zCall( 0x005DD200 );
    void PresetDawn()        zCall( 0x005DD380 );
    zCSkyState()             zInit( zCSkyState_OnInit() );
    ~zCSkyState()            zCall( 0x005DD630 );

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

    void zCSkyLayer_OnInit()             zCall( 0x005DD820 );
    zCSkyLayer()                         zInit( zCSkyLayer_OnInit() );
    ~zCSkyLayer()                        zCall( 0x005DD860 );
    void SetDomeMeshEnabled( int )       zCall( 0x005DDF90 );
    void SetSkyDomeTexture( zCTexture* ) zCall( 0x005DDFF0 );
    void SetSkyPolyTexture( zCTexture* ) zCall( 0x005DE040 );
    void RenderSkyLayer( zCSkyState* )   zCall( 0x005DE050 );
    void RenderSkyPoly( zCSkyState* )    zCall( 0x005DE080 );
    void RenderSkyDome( zCSkyState* )    zCall( 0x005DE490 );
    void ColorizeSkyDome()               zCall( 0x005DE920 );
    void RenderRainCloudLayer( zCOLOR )  zCall( 0x005DEF50 );
    static zCMesh* CreateSkyPoly()       zCall( 0x005DD650 );
    static zCMesh* CreateSkyDomeMesh()   zCall( 0x005DD8C0 );

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

    void zCSkyPlanet_OnInit() zCall( 0x005DF8F0 );
    zCSkyPlanet()             zInit( zCSkyPlanet_OnInit() );
    ~zCSkyPlanet()            zCall( 0x005DF900 );

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
    void zCSkyControler_Outdoor_OnInit( int )                               zCall( 0x005DF470 );
    zCSkyControler_Outdoor( int a0 )                                        zInit( zCSkyControler_Outdoor_OnInit( a0 ));
    void Init()                                                             zCall( 0x005DFC50 );
    int GetStateTextureSearch( int, int, int )                              zCall( 0x005E0560 );
    void ApplyStateTexToLayer( int, int )                                   zCall( 0x005E05B0 );
    void RenderPlanets( float )                                             zCall( 0x005E0A80 );
    void ReadFogColorsFromINI()                                             zCall( 0x005E10F0 );
    void __fastcall ApplyFogColorsFromINI( int )                            zCall( 0x005E1840 );
    void CreateDefault()                                                    zCall( 0x005E1920 );
    void Interpolate()                                                      zCall( 0x005E1E70 );
    void CalcPolyLightCLUT( zVEC3 const&, zVEC3 const& )                    zCall( 0x005E2610 );
    void InitSkyPFX()                                                       zCall( 0x005E2730 );
    void CalcFog()                                                          zCall( 0x005E2910 );
    void RenderSkyPFX()                                                     zCall( 0x005E3120 );
    void CalcGlobalWind()                                                   zCall( 0x005E3460 );
    void ProcessRainFX()                                                    zCall( 0x005E4180 );
    void SetRainFXWeight( float, float )                                    zCall( 0x005E4480 );
    void RenderSetup()                                                      zCall( 0x005E45B0 );
    void RenderSky()                                                        zCall( 0x005E4620 );
    static zCObject* _CreateNewInstance()                                   zCall( 0x005DA200 );
    virtual zCClassDef* _GetClassDef() const                                zCall( 0x005DF930 );
    virtual void Archive( zCArchiver& )                                     zCall( 0x005E4890 );
    virtual void Unarchive( zCArchiver& )                                   zCall( 0x005E4980 );
    virtual ~zCSkyControler_Outdoor()                                       zCall( 0x005DFA40 );
    virtual void SetTime( float )                                           zCall( 0x005E25A0 );
    virtual float GetTime() const                                           zCall( 0x005DF940 );
    virtual void ResetTime()                                                zCall( 0x005E25D0 );
    virtual void SetFarZ( float )                                           zCall( 0x005E30A0 );
    virtual float GetFarZ() const                                           zCall( 0x005E30B0 );
    virtual void SetFarZScalability( float )                                zCall( 0x005E30C0 );
    virtual float GetFarZScalability() const                                zCall( 0x005E3110 );
    virtual void SetBackgroundColor( zCOLOR )                               zCall( 0x005DF950 );
    virtual zCOLOR GetBackgroundColor() const                               zCall( 0x005DF960 );
    virtual zCOLOR GetBackgroundColorDef() const                            zCall( 0x005DF990 );
    virtual void SetOverrideColor( zVEC3 )                                  zCall( 0x005DF9A0 );
    virtual void SetOverrideColorFlag( int )                                zCall( 0x005DF9C0 );
    virtual float GetCloudShadowScale() const                               zCall( 0x005E3A40 );
    virtual void SetCloudShadowScale( float )                               zCall( 0x005E3A60 );
    virtual void UpdateWorldDependencies()                                  zCall( 0x005E0510 );
    virtual zCOLOR GetDaylightColorFromIntensity( int )                     zCall( 0x005E25F0 );
    virtual void RenderSkyPre()                                             zCall( 0x005E3AA0 );
    virtual void RenderSkyPost( int )                                       zCall( 0x005E47D0 );
    virtual int GetGlobalWindVec( zVEC3&, zTAnimationMode )                 zCall( 0x005E3A00 );
    virtual void SetGlobalSkyScale( float )                                 zCall( 0x005E04E0 );
    virtual float GetGlobalSkyScale() const                                 zCall( 0x005DF9F0 );
    virtual int GetGlobalSkyScaleChanged() const                            zCall( 0x005DFA00 );
    virtual void SetCameraLocationHint( zCSkyControler::zTCamLocationHint ) zCall( 0x005DF9E0 );
    virtual void SetWeatherType( zTWeather )                                zCall( 0x005E4A80 );
    virtual int GetRenderLightning() const                                  zCall( 0x005DF9D0 );

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

    void zCOutdoorRainFX_OnInit()                    zCall( 0x005DA2F0 );
    zCOutdoorRainFX()                                zInit( zCOutdoorRainFX_OnInit() );
    ~zCOutdoorRainFX()                               zCall( 0x005DA4A0 );
    void UpdateSound( float )                        zCall( 0x005DA5A0 );
    void SetWeatherType( zTWeather )                 zCall( 0x005DA7C0 );
    void SetEffectWeight( float, float )             zCall( 0x005DAB30 );
    int CheckCameraBeam( zVEC3 const& )              zCall( 0x005DACC0 );
    void CreateParticles( zTRenderContext& )         zCall( 0x005DAEC0 );
    void UpdateParticles()                           zCall( 0x005DB650 );
    void RenderParticles( zTRenderContext&, zCOLOR ) zCall( 0x005DB820 );

    // user API
    #include "zCOutdoorRainFX.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZSKY__OUTDOOR_H__VER2__