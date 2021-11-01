// Supported with union (c) 2018-2021 Union team

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

  // sizeof 2Ch
  class zCSkyLayerData {
  public:
    zESkyLayerMode skyMode; // sizeof 04h    offset 00h
    zCTexture* tex;         // sizeof 04h    offset 04h
    zSTRING texName;        // sizeof 14h    offset 08h
    float texAlpha;         // sizeof 04h    offset 1Ch
    float texScale;         // sizeof 04h    offset 20h
    zVEC2 texSpeed;         // sizeof 08h    offset 24h

    void zCSkyLayerData_OnInit() zCall( 0x005E4200 );
    zCSkyLayerData()             zInit( zCSkyLayerData_OnInit() );
    ~zCSkyLayerData()            zCall( 0x005E4320 );

    // user API
    #include "zCSkyLayerData.inl"
  };

  // sizeof 98h
  class zCSkyState {
  public:
    float time;                           // sizeof 04h    offset 00h
    zVEC3 polyColor;                      // sizeof 0Ch    offset 04h
    zVEC3 fogColor;                       // sizeof 0Ch    offset 10h
    zVEC3 domeColor1;                     // sizeof 0Ch    offset 1Ch
    zVEC3 domeColor0;                     // sizeof 0Ch    offset 28h
    float fogDist;                        // sizeof 04h    offset 34h
    int sunOn;                            // sizeof 04h    offset 38h
    int cloudShadowOn;                    // sizeof 04h    offset 3Ch
    zCSkyLayerData layer[zSKY_NUM_LAYER]; // sizeof 58h    offset 40h

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

  // sizeof 18h
  class zCSkyLayer {
  public:
    zCMesh* skyPolyMesh;    // sizeof 04h    offset 00h
    zCPolygon* skyPoly;     // sizeof 04h    offset 04h
    zVEC2 skyTexOffs;       // sizeof 08h    offset 08h
    zCMesh* skyDomeMesh;    // sizeof 04h    offset 10h
    zESkyLayerMode skyMode; // sizeof 04h    offset 14h

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

  // sizeof 40h
  class zCSkyPlanet {
  public:
    zCMesh* mesh;  // sizeof 04h    offset 00h
    zVEC4 color0;  // sizeof 10h    offset 04h
    zVEC4 color1;  // sizeof 10h    offset 14h
    float size;    // sizeof 04h    offset 24h
    zVEC3 pos;     // sizeof 0Ch    offset 28h
    zVEC3 rotAxis; // sizeof 0Ch    offset 34h

    void zCSkyPlanet_OnInit() zCall( 0x005E66A0 );
    zCSkyPlanet()             zInit( zCSkyPlanet_OnInit() );
    ~zCSkyPlanet()            zCall( 0x005E66B0 );

    // user API
    #include "zCSkyPlanet.inl"
  };

  // sizeof 6BCh
  class zCSkyControler_Outdoor : public zCSkyControler_Mid {
  public:
    zCLASS_DECLARATION( zCSkyControler_Outdoor )

    // sizeof 28h
    struct zTRainFX {
      zCOutdoorRainFX* outdoorRainFX;        // sizeof 04h    offset 00h
      zTCamLocationHint camLocationHint;     // sizeof 04h    offset 04h
      float outdoorRainFXWeight;             // sizeof 04h    offset 08h
      float soundVolume;                     // sizeof 04h    offset 0Ch
      float timerInsideSectorCantSeeOutside; // sizeof 04h    offset 10h
      float timeStartRain;                   // sizeof 04h    offset 14h
      float timeStopRain;                    // sizeof 04h    offset 18h
      int renderLightning;                   // sizeof 04h    offset 1Ch
      int m_bRaining;                        // sizeof 04h    offset 20h
      int m_iRainCtr;                        // sizeof 04h    offset 24h

      zTRainFX() {}

      // user API
      #include "zCSkyControler_Outdoor_zTRainFX.inl"
    };

    int initDone;                          // sizeof 04h    offset 7Ch
    float masterTime;                      // sizeof 04h    offset 80h
    float masterTimeLast;                  // sizeof 04h    offset 84h
    zCSkyState masterState;                // sizeof 98h    offset 88h
    zCSkyState* state0;                    // sizeof 04h    offset 120h
    zCSkyState* state1;                    // sizeof 04h    offset 124h
    zCArray<zCSkyState*> stateList;        // sizeof 0Ch    offset 128h
    zCOLOR polyLightCLUT[256];             // sizeof 400h   offset 134h
    float dayCounter;                      // sizeof 04h    offset 534h
    zCArray<zVEC3> fogColorDayVariations;  // sizeof 0Ch    offset 538h
    zCArray<zVEC3> fogColorDayVariations2; // sizeof 0Ch    offset 544h
    float m_fSkyScale;                     // sizeof 04h    offset 550h
    int m_bSkyScaleChanged;                // sizeof 04h    offset 554h
    zVEC3 m_overrideColor;                 // sizeof 0Ch    offset 558h
    int m_bOverrideColorFlag;              // sizeof 04h    offset 564h
    int m_bDontRain;                       // sizeof 04h    offset 568h
    int m_bLevelChanged;                   // sizeof 04h    offset 56Ch
    int m_bDarkSky;                        // sizeof 04h    offset 570h
    float resultFogScale;                  // sizeof 04h    offset 574h
    float heightFogMinY;                   // sizeof 04h    offset 578h
    float heightFogMaxY;                   // sizeof 04h    offset 57Ch
    float userFogFar;                      // sizeof 04h    offset 580h
    float resultFogNear;                   // sizeof 04h    offset 584h
    float resultFogFar;                    // sizeof 04h    offset 588h
    float resultFogSkyNear;                // sizeof 04h    offset 58Ch
    float resultFogSkyFar;                 // sizeof 04h    offset 590h
    zCOLOR resultFogColor;                 // sizeof 04h    offset 594h
    zCOLOR resultFogColorOverride;         // sizeof 04h    offset 598h
    float userFarZScalability;             // sizeof 04h    offset 59Ch
    zCSkyState* skyLayerState[2];          // sizeof 08h    offset 5A0h
    zCSkyLayer skyLayer[2];                // sizeof 30h    offset 5A8h
    zCSkyLayer skyLayerRainClouds;         // sizeof 18h    offset 5D8h
    zCTexture* skyCloudLayerTex;           // sizeof 04h    offset 5F0h
    zCSkyPlanet planets[NUM_PLANETS];      // sizeof 80h    offset 5F4h
    int m_bSunVisible;                     // sizeof 04h    offset 674h
    float m_fFadeScale;                    // sizeof 04h    offset 678h
    zCVob* vobSkyPFX;                      // sizeof 04h    offset 67Ch
    float skyPFXTimer;                     // sizeof 04h    offset 680h
    int m_bIsMainControler;                // sizeof 04h    offset 684h
    zVEC3 m_bWindVec;                      // sizeof 0Ch    offset 688h
    zTRainFX rainFX;                       // sizeof 28h    offset 694h

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

  // sizeof 110B0h
  class zCOutdoorRainFX {
  public:

    // sizeof 1Ch
    struct zSParticle {
      float m_killTotalTime; // sizeof 04h    offset 00h
      zVEC3 m_destPosition;  // sizeof 0Ch    offset 04h
      zVEC3 m_destNormal;    // sizeof 0Ch    offset 10h

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

    zSParticle m_flyParticleList[zMAX_FLY_PARTICLE];       // sizeof 7000h  offset 00h
    zSParticle m_impactParticleList[zMAX_IMPACT_PARTICLE]; // sizeof 7000h  offset 7000h
    int m_numFlyParticle;                                  // sizeof 04h    offset E000h
    int m_numImpactParticle;                               // sizeof 04h    offset E004h
    zCArray<zSParticle*> m_freeFlyParticleList;            // sizeof 0Ch    offset E008h
    float m_effectWeight;                                  // sizeof 04h    offset E014h
    int m_numDestFlyParticle;                              // sizeof 04h    offset E018h
    zVEC3 m_camPosLastFrame;                               // sizeof 0Ch    offset E01Ch
    zTWeather m_enuWeather;                                // sizeof 04h    offset E028h
    zSCacheElement m_cache[zCACHE_SIZE];                   // sizeof 3000h  offset E02Ch
    int m_currentCacheIndex;                               // sizeof 04h    offset 1102Ch
    zCShader m_shader;                                     // sizeof 24h    offset 11030h
    zCShaderStage m_shaderStage;                           // sizeof 30h    offset 11054h
    zCTexture* m_raindropTexture;                          // sizeof 04h    offset 11084h
    zCTexture* m_rainTexture;                              // sizeof 04h    offset 11088h
    zCMaterial* m_rainMaterial;                            // sizeof 04h    offset 1108Ch
    zCSoundFX* m_soundEffect;                              // sizeof 04h    offset 11090h
    int m_soundHandle;                                     // sizeof 04h    offset 11094h
    int m_soundActive;                                     // sizeof 04h    offset 11098h
    zVEC3 m_positionUpdateVector;                          // sizeof 0Ch    offset 1109Ch
    float m_velocityLen;                                   // sizeof 04h    offset 110A8h
    float m_timeLen;                                       // sizeof 04h    offset 110ACh

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