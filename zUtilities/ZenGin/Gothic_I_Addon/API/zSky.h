// Supported with union (c) 2018 Union team

#ifndef __ZSKY_H__VER1__
#define __ZSKY_H__VER1__

namespace Gothic_I_Addon {
  const int zSKY_NUM_LAYER = 2;
  const int NUM_PLANETS    = 2;

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
    zCTexture* texBox[5];
    zCTexture* tex;
    zSTRING texName;
    float texAlpha;
    float texScale;
    zVEC2 texSpeed;

    void zCSkyLayerData_OnInit() zCall( 0x005D93C0 );
    zCSkyLayerData()             zInit( zCSkyLayerData_OnInit() );
    ~zCSkyLayerData()            zCall( 0x005D9430 );

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

    void zCSkyState_OnInit() zCall( 0x005D9500 );
    zCSkyState()             zInit( zCSkyState_OnInit() );
    ~zCSkyState()            zCall( 0x005D9530 );
    void PresetDay0()        zCall( 0x005D9550 );
    void PresetDay1()        zCall( 0x005D96F0 );
    void PresetDay2()        zCall( 0x005D9870 );
    void PresetEvening()     zCall( 0x005D9940 );
    void PresetNight0()      zCall( 0x005D9A10 );
    void PresetNight1()      zCall( 0x005D9C10 );
    void PresetNight2()      zCall( 0x005D9D90 );
    void PresetDawn()        zCall( 0x005D9F10 );

    // user API
    #include "zCSkyState.inl"
  };

  class zCSkyLayer {
  public:
    zCMesh* skyPolyMesh;
    zCPolygon* skyPoly;
    zVEC2 skyTexOffs;
    zCMesh* skyBoxMesh;
    zESkyLayerMode skyMode;

    void zCSkyLayer_OnInit()                 zCall( 0x005DCA30 );
    zCSkyLayer()                             zInit( zCSkyLayer_OnInit() );
    ~zCSkyLayer()                            zCall( 0x005DCA80 );
    void SetSkyBoxTexture( int, zCTexture* ) zCall( 0x005DCAE0 );
    void SetSkyPolyTexture( zCTexture* )     zCall( 0x005DCB30 );
    void RenderSkyLayer( zCSkyState* )       zCall( 0x005DCB50 );
    void RenderSkyPoly( zCSkyState* )        zCall( 0x005DCC00 );
    void RenderRainCloudLayer( zCOLOR )      zCall( 0x005DD010 );
    void RenderSkyBox( zCSkyState* )         zCall( 0x005DDD70 );
    static zCMesh* CreateSkyPoly()           zCall( 0x005DC840 );
    static zCMesh* CreateSkyBoxMesh( int )   zCall( 0x005DDD60 );

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

    void zCSkyPlanet_OnInit() zCall( 0x005DA300 );
    zCSkyPlanet()             zInit( zCSkyPlanet_OnInit() );
    ~zCSkyPlanet()            zCall( 0x005DA310 );

    // user API
    #include "zCSkyPlanet.inl"
  };

  class zCUnderwaterPFX : public zCParticleFX {
  public:
    zVEC3 camPosLastFrame;

    zCUnderwaterPFX() {}
    void ProcessParticles()                zCall( 0x005D8930 );
    void CreateParticles()                 zCall( 0x005D8CC0 );
    virtual ~zCUnderwaterPFX()             zCall( 0x005D84C0 );
    virtual int Render( zTRenderContext& ) zCall( 0x005D8910 );

    // user API
    #include "zCUnderwaterPFX.inl"
  };

  class zCSkyControler : public zCObject {
  public:
    zCLASS_DECLARATION( zCSkyControler )

    enum zTCamLocationHint {
      zCAM_OUTSIDE_SECTOR,
      zCAM_INSIDE_SECTOR_CANT_SEE_OUTSIDE,
      zCAM_INSIDE_SECTOR_CAN_SEE_OUTSIDE
    };

    zCOLOR* polyLightCLUTPtr;
    float cloudShadowScale;
    zCOLOR backgroundColor;
    int fillBackground;
    zCTexture* backgroundTexture;

    void zCSkyControler_OnInit()                            zCall( 0x005D7C90 );
    zCSkyControler()                                        zInit( zCSkyControler_OnInit() );
    void ClearBackground( zCOLOR )                          zCall( 0x005D7E20 );
    virtual zCClassDef* _GetClassDef() const                zCall( 0x005D5A90 );
    virtual ~zCSkyControler()                               zCall( 0x005D7DB0 );
    virtual void SetTime( float )                           zPureCall;
    virtual float GetTime() const                           zPureCall;
    virtual void ResetTime()                                zPureCall;
    virtual void SetFarZ( float )                           zPureCall;
    virtual float GetFarZ() const                           zPureCall;
    virtual void SetFarZScalability( float )                zPureCall;
    virtual float GetFarZScalability() const                zPureCall;
    virtual void SetBackgroundColor( zCOLOR )               zPureCall;
    virtual zCOLOR GetBackgroundColor() const               zPureCall;
    virtual void SetFillBackground( int )                   zCall( 0x005D58C0 );
    virtual int GetFillBackground() const                   zCall( 0x005D58D0 );
    virtual void SetUnderwaterFX( int )                     zPureCall;
    virtual int GetUnderwaterFX() const                     zPureCall;
    virtual void UpdateWorldDependencies()                  zPureCall;
    virtual int GetRelightCtr()                             zCall( 0x005D58E0 );
    virtual zCOLOR GetDaylightColorFromIntensity( int )     zCall( 0x005D58F0 );
    virtual void RenderSkyPre()                             zPureCall;
    virtual void RenderSkyPost()                            zPureCall;
    virtual void SetCameraLocationHint( zTCamLocationHint ) zCall( 0x005D5920 );

    // static properties
    static zCSkyControler*& s_activeSkyControler;
    static int& s_skyEffectsEnabled;

    // user API
    #include "zCSkyControler.inl"
  };

  class zCSkyControler_Mid : public zCSkyControler {
  public:
    zCLASS_DECLARATION( zCSkyControler_Mid )

    int underwaterFX;
    zCOLOR underwaterColor;
    float underwaterFarZ;
    float underwaterStartTime;
    float oldFovX;
    float oldFovY;
    zCVob* vobUnderwaterPFX;
    zCPolygon* scrPoly;
    zCMesh* scrPolyMesh;
    int scrPolyAlpha;
    zCOLOR scrPolyColor;
    zTRnd_AlphaBlendFunc scrPolyAlphaFunc;

    void zCSkyControler_Mid_OnInit()                     zCall( 0x005D80E0 );
    zCSkyControler_Mid()                                 zInit( zCSkyControler_Mid_OnInit() );
    void InitUnderwaterPFX()                             zCall( 0x005D81E0 );
    void InitScreenBlend()                               zCall( 0x005D8DE0 );
    void RenderScreenBlend()                             zCall( 0x005D8F30 );
    void SetScreenBlendAlpha( int )                      zCall( 0x005D9140 );
    void SetScreenBlendColor( zCOLOR const& )            zCall( 0x005D9150 );
    void SetScreenBlendAlphaFunc( zTRnd_AlphaBlendFunc ) zCall( 0x005D9160 );
    virtual zCClassDef* _GetClassDef() const             zCall( 0x005D5930 );
    virtual ~zCSkyControler_Mid()                        zCall( 0x005D84D0 );
    virtual void SetTime( float )                        zPureCall;
    virtual float GetTime() const                        zPureCall;
    virtual void ResetTime()                             zPureCall;
    virtual void SetFarZ( float )                        zPureCall;
    virtual float GetFarZ() const                        zPureCall;
    virtual void SetFarZScalability( float )             zPureCall;
    virtual float GetFarZScalability() const             zPureCall;
    virtual void SetBackgroundColor( zCOLOR )            zPureCall;
    virtual zCOLOR GetBackgroundColor() const            zPureCall;
    virtual void SetUnderwaterFX( int )                  zCall( 0x005D8590 );
    virtual int GetUnderwaterFX() const                  zCall( 0x005D8600 );
    virtual void UpdateWorldDependencies()               zPureCall;
    virtual void RenderSkyPre()                          zCall( 0x005D8610 );
    virtual void RenderSkyPost()                         zCall( 0x005D86F0 );

    // user API
    #include "zCSkyControler_Mid.inl"
  };

  class zCSkyControler_Indoor : public zCSkyControler_Mid {
  public:
    zCLASS_DECLARATION( zCSkyControler_Indoor )

    float userFarZ;
    float userFarZScalability;
    float time;

    void zCSkyControler_Indoor_OnInit()                                 zCall( 0x005D9170 );
    zCSkyControler_Indoor()                                             zInit( zCSkyControler_Indoor_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x005D57B0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005D5960 );
    virtual ~zCSkyControler_Indoor()                                    zCall( 0x005D59D0 );
    virtual void SetTime( float )                                       zCall( 0x005D9230 );
    virtual float GetTime() const                                       zCall( 0x005D5970 );
    virtual void ResetTime()                                            zCall( 0x005D5980 );
    virtual void SetFarZ( float )                                       zCall( 0x005D9290 );
    virtual float GetFarZ() const                                       zCall( 0x005D92A0 );
    virtual void SetFarZScalability( float )                            zCall( 0x005D92B0 );
    virtual float GetFarZScalability() const                            zCall( 0x005D92F0 );
    virtual void SetBackgroundColor( zCOLOR )                           zCall( 0x005D9300 );
    virtual zCOLOR GetBackgroundColor() const                           zCall( 0x005D9310 );
    virtual void UpdateWorldDependencies()                              zCall( 0x005D5990 );
    virtual void RenderSkyPre()                                         zCall( 0x005D9320 );
    virtual void RenderSkyPost()                                        zCall( 0x005D93B0 );

    // user API
    #include "zCSkyControler_Indoor.inl"
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
    int relightCtr;
    float lastRelightTime;
    float dayCounter;
    zCArray<zVEC3> fogColorDayVariations;
    float resultFogScale;
    float heightFogMinY;
    float heightFogMaxY;
    float userFogFar;
    float resultFogNear;
    float resultFogFar;
    float resultFogSkyNear;
    float resultFogSkyFar;
    zCOLOR resultFogColor;
    float userFarZScalability;
    zCSkyState* skyLayerState[2];
    zCSkyLayer skyLayer[2];
    zCSkyLayer skyLayerRainClouds;
    zCTexture* skyCloudLayerTex;
    zCSkyPlanet planets[NUM_PLANETS];
    zCVob* vobSkyPFX;
    float skyPFXTimer;
    zTRainFX rainFX;

    void zCSkyControler_Outdoor_OnInit()                                    zCall( 0x005D9FE0 );
    zCSkyControler_Outdoor()                                                zInit( zCSkyControler_Outdoor_OnInit() );
    void Init()                                                             zCall( 0x005DA640 );
    int GetStateTextureSearch( int, int, int )                              zCall( 0x005DABA0 );
    void ApplyStateTexToLayer( int, int )                                   zCall( 0x005DAC00 );
    void RenderPlanets()                                                    zCall( 0x005DB080 );
    void ReadFogColorsFromINI()                                             zCall( 0x005DB5F0 );
    void __fastcall ApplyFogColorsFromINI( int )                            zCall( 0x005DBB20 );
    void CreateDefault()                                                    zCall( 0x005DBBB0 );
    void Interpolate()                                                      zCall( 0x005DC1F0 );
    void CalcPolyLightCLUT( zVEC3 const&, zVEC3 const& )                    zCall( 0x005DC720 );
    void ColorizeSkySphere()                                                zCall( 0x005DD2D0 );
    void TextureSkySphere()                                                 zCall( 0x005DD560 );
    void RenderSetup()                                                      zCall( 0x005DDA70 );
    void RenderSkyPlane()                                                   zCall( 0x005DDAC0 );
    void RenderSkyDome()                                                    zCall( 0x005DDD40 );
    void InitSkyPFX()                                                       zCall( 0x005DDE00 );
    void CalcFog()                                                          zCall( 0x005DE020 );
    void RenderSkyPFX()                                                     zCall( 0x005DE450 );
    void ProcessRainFX()                                                    zCall( 0x005DECA0 );
    void SetRainFXWeight( float, float )                                    zCall( 0x005DEFA0 );
    static zCObject* _CreateNewInstance()                                   zCall( 0x005D5CA0 );
    virtual zCClassDef* _GetClassDef() const                                zCall( 0x005DA340 );
    virtual void Archive( zCArchiver& )                                     zCall( 0x005DF090 );
    virtual void Unarchive( zCArchiver& )                                   zCall( 0x005DF140 );
    virtual ~zCSkyControler_Outdoor()                                       zCall( 0x005DA3C0 );
    virtual void SetTime( float )                                           zCall( 0x005DC690 );
    virtual float GetTime() const                                           zCall( 0x005DA350 );
    virtual void ResetTime()                                                zCall( 0x005DC6D0 );
    virtual void SetFarZ( float )                                           zCall( 0x005DE3D0 );
    virtual float GetFarZ() const                                           zCall( 0x005DE3E0 );
    virtual void SetFarZScalability( float )                                zCall( 0x005DE3F0 );
    virtual float GetFarZScalability() const                                zCall( 0x005DE440 );
    virtual void SetBackgroundColor( zCOLOR )                               zCall( 0x005DA360 );
    virtual zCOLOR GetBackgroundColor() const                               zCall( 0x005DA370 );
    virtual void UpdateWorldDependencies()                                  zCall( 0x005DAB50 );
    virtual int GetRelightCtr()                                             zCall( 0x005DC6F0 );
    virtual zCOLOR GetDaylightColorFromIntensity( int )                     zCall( 0x005DC700 );
    virtual void RenderSkyPre()                                             zCall( 0x005DE790 );
    virtual void RenderSkyPost()                                            zCall( 0x005DF070 );
    virtual void SetCameraLocationHint( zCSkyControler::zTCamLocationHint ) zCall( 0x005DA380 );

    // user API
    #include "zCSkyControler_Outdoor.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZSKY_H__VER1__