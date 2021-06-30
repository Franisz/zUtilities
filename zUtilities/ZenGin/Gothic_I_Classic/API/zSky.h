// Supported with union (c) 2018 Union team

#ifndef __ZSKY_H__VER0__
#define __ZSKY_H__VER0__

namespace Gothic_I_Classic {
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

    void zCSkyLayerData_OnInit() zCall( 0x005BB830 );
    zCSkyLayerData()             zInit( zCSkyLayerData_OnInit() );
    ~zCSkyLayerData()            zCall( 0x005BB8A0 );

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

    void zCSkyState_OnInit() zCall( 0x005BB960 );
    zCSkyState()             zInit( zCSkyState_OnInit() );
    ~zCSkyState()            zCall( 0x005BB990 );
    void PresetDay0()        zCall( 0x005BB9B0 );
    void PresetDay1()        zCall( 0x005BBB50 );
    void PresetDay2()        zCall( 0x005BBCD0 );
    void PresetEvening()     zCall( 0x005BBDA0 );
    void PresetNight0()      zCall( 0x005BBE70 );
    void PresetNight1()      zCall( 0x005BC070 );
    void PresetNight2()      zCall( 0x005BC1F0 );
    void PresetDawn()        zCall( 0x005BC370 );

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

    void zCSkyLayer_OnInit()                 zCall( 0x005BEC80 );
    zCSkyLayer()                             zInit( zCSkyLayer_OnInit() );
    ~zCSkyLayer()                            zCall( 0x005BECD0 );
    void SetSkyBoxTexture( int, zCTexture* ) zCall( 0x005BED20 );
    void SetSkyPolyTexture( zCTexture* )     zCall( 0x005BED60 );
    void RenderSkyLayer( zCSkyState* )       zCall( 0x005BED70 );
    void RenderSkyPoly( zCSkyState* )        zCall( 0x005BEE20 );
    void RenderRainCloudLayer( zCOLOR )      zCall( 0x005BF230 );
    void RenderSkyBox( zCSkyState* )         zCall( 0x005BFEF0 );
    static zCMesh* CreateSkyPoly()           zCall( 0x005BEAA0 );
    static zCMesh* CreateSkyBoxMesh( int )   zCall( 0x005BFEE0 );

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

    void zCSkyPlanet_OnInit() zCall( 0x005BC750 );
    zCSkyPlanet()             zInit( zCSkyPlanet_OnInit() );
    ~zCSkyPlanet()            zCall( 0x005BC760 );

    // user API
    #include "zCSkyPlanet.inl"
  };

  class zCUnderwaterPFX : public zCParticleFX {
  public:
    zVEC3 camPosLastFrame;

    zCUnderwaterPFX() {}
    void ProcessParticles()                zCall( 0x005BADC0 );
    void CreateParticles()                 zCall( 0x005BB1C0 );
    virtual ~zCUnderwaterPFX()             zCall( 0x005BA960 );
    virtual int Render( zTRenderContext& ) zCall( 0x005BADA0 );

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

    void zCSkyControler_OnInit()                            zCall( 0x005BA160 );
    zCSkyControler()                                        zInit( zCSkyControler_OnInit() );
    void ClearBackground( zCOLOR )                          zCall( 0x005BA2F0 );
    virtual zCClassDef* _GetClassDef() const                zCall( 0x005B80A0 );
    virtual ~zCSkyControler()                               zCall( 0x005BA280 );
    virtual void SetTime( float )                           zPureCall;
    virtual float GetTime() const                           zPureCall;
    virtual void ResetTime()                                zPureCall;
    virtual void SetFarZ( float )                           zPureCall;
    virtual float GetFarZ() const                           zPureCall;
    virtual void SetFarZScalability( float )                zPureCall;
    virtual float GetFarZScalability() const                zPureCall;
    virtual void SetBackgroundColor( zCOLOR )               zPureCall;
    virtual zCOLOR GetBackgroundColor() const               zPureCall;
    virtual void SetFillBackground( int )                   zCall( 0x005B7EE0 );
    virtual int GetFillBackground() const                   zCall( 0x005B7EF0 );
    virtual void SetUnderwaterFX( int )                     zPureCall;
    virtual int GetUnderwaterFX() const                     zPureCall;
    virtual void UpdateWorldDependencies()                  zPureCall;
    virtual int GetRelightCtr()                             zCall( 0x005B7F00 );
    virtual zCOLOR GetDaylightColorFromIntensity( int )     zCall( 0x005B7F10 );
    virtual void RenderSkyPre()                             zPureCall;
    virtual void RenderSkyPost()                            zPureCall;
    virtual void SetCameraLocationHint( zTCamLocationHint ) zCall( 0x005B7F30 );

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

    void zCSkyControler_Mid_OnInit()                     zCall( 0x005BA5A0 );
    zCSkyControler_Mid()                                 zInit( zCSkyControler_Mid_OnInit() );
    void InitUnderwaterPFX()                             zCall( 0x005BA6A0 );
    void InitScreenBlend()                               zCall( 0x005BB2A0 );
    void RenderScreenBlend()                             zCall( 0x005BB3D0 );
    void SetScreenBlendAlpha( int )                      zCall( 0x005BB5A0 );
    void SetScreenBlendColor( zCOLOR const& )            zCall( 0x005BB5B0 );
    void SetScreenBlendAlphaFunc( zTRnd_AlphaBlendFunc ) zCall( 0x005BB5C0 );
    virtual zCClassDef* _GetClassDef() const             zCall( 0x005B7F40 );
    virtual ~zCSkyControler_Mid()                        zCall( 0x005BA970 );
    virtual void SetTime( float )                        zPureCall;
    virtual float GetTime() const                        zPureCall;
    virtual void ResetTime()                             zPureCall;
    virtual void SetFarZ( float )                        zPureCall;
    virtual float GetFarZ() const                        zPureCall;
    virtual void SetFarZScalability( float )             zPureCall;
    virtual float GetFarZScalability() const             zPureCall;
    virtual void SetBackgroundColor( zCOLOR )            zPureCall;
    virtual zCOLOR GetBackgroundColor() const            zPureCall;
    virtual void SetUnderwaterFX( int )                  zCall( 0x005BAA30 );
    virtual int GetUnderwaterFX() const                  zCall( 0x005BAAA0 );
    virtual void UpdateWorldDependencies()               zPureCall;
    virtual void RenderSkyPre()                          zCall( 0x005BAAB0 );
    virtual void RenderSkyPost()                         zCall( 0x005BAB80 );

    // user API
    #include "zCSkyControler_Mid.inl"
  };

  class zCSkyControler_Indoor : public zCSkyControler_Mid {
  public:
    zCLASS_DECLARATION( zCSkyControler_Indoor )

    float userFarZ;
    float userFarZScalability;
    float time;

    void zCSkyControler_Indoor_OnInit()                                 zCall( 0x005BB5D0 );
    zCSkyControler_Indoor()                                             zInit( zCSkyControler_Indoor_OnInit() );
    static zCObject* _CreateNewInstance()                               zCall( 0x005B7DD0 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x005B7F70 );
    virtual ~zCSkyControler_Indoor()                                    zCall( 0x005B7FE0 );
    virtual void SetTime( float )                                       zCall( 0x005BB690 );
    virtual float GetTime() const                                       zCall( 0x005B7F80 );
    virtual void ResetTime()                                            zCall( 0x005B7F90 );
    virtual void SetFarZ( float )                                       zCall( 0x005BB700 );
    virtual float GetFarZ() const                                       zCall( 0x005BB710 );
    virtual void SetFarZScalability( float )                            zCall( 0x005BB720 );
    virtual float GetFarZScalability() const                            zCall( 0x005BB760 );
    virtual void SetBackgroundColor( zCOLOR )                           zCall( 0x005BB770 );
    virtual zCOLOR GetBackgroundColor() const                           zCall( 0x005BB780 );
    virtual void UpdateWorldDependencies()                              zCall( 0x005B7FA0 );
    virtual void RenderSkyPre()                                         zCall( 0x005BB790 );
    virtual void RenderSkyPost()                                        zCall( 0x005BB820 );

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

    void zCSkyControler_Outdoor_OnInit()                                    zCall( 0x005BC440 );
    zCSkyControler_Outdoor()                                                zInit( zCSkyControler_Outdoor_OnInit() );
    void Init()                                                             zCall( 0x005BCA80 );
    int GetStateTextureSearch( int, int, int )                              zCall( 0x005BCFA0 );
    void ApplyStateTexToLayer( int, int )                                   zCall( 0x005BCFF0 );
    void RenderPlanets()                                                    zCall( 0x005BD430 );
    void ReadFogColorsFromINI()                                             zCall( 0x005BD970 );
    void __fastcall ApplyFogColorsFromINI( int )                            zCall( 0x005BDE40 );
    void CreateDefault()                                                    zCall( 0x005BDEC0 );
    void Interpolate()                                                      zCall( 0x005BE4F0 );
    void CalcPolyLightCLUT( zVEC3 const&, zVEC3 const& )                    zCall( 0x005BE980 );
    void ColorizeSkySphere()                                                zCall( 0x005BF4B0 );
    void TextureSkySphere()                                                 zCall( 0x005BF6F0 );
    void RenderSetup()                                                      zCall( 0x005BFBE0 );
    void RenderSkyPlane()                                                   zCall( 0x005BFC30 );
    void RenderSkyDome()                                                    zCall( 0x005BFED0 );
    void InitSkyPFX()                                                       zCall( 0x005BFF80 );
    void CalcFog()                                                          zCall( 0x005C01A0 );
    void RenderSkyPFX()                                                     zCall( 0x005C05C0 );
    void ProcessRainFX()                                                    zCall( 0x005C0DC0 );
    void SetRainFXWeight( float, float )                                    zCall( 0x005C1090 );
    static zCObject* _CreateNewInstance()                                   zCall( 0x005B82A0 );
    virtual zCClassDef* _GetClassDef() const                                zCall( 0x005BC790 );
    virtual void Archive( zCArchiver& )                                     zCall( 0x005C1170 );
    virtual void Unarchive( zCArchiver& )                                   zCall( 0x005C1220 );
    virtual ~zCSkyControler_Outdoor()                                       zCall( 0x005BC810 );
    virtual void SetTime( float )                                           zCall( 0x005BE8F0 );
    virtual float GetTime() const                                           zCall( 0x005BC7A0 );
    virtual void ResetTime()                                                zCall( 0x005BE930 );
    virtual void SetFarZ( float )                                           zCall( 0x005C0540 );
    virtual float GetFarZ() const                                           zCall( 0x005C0550 );
    virtual void SetFarZScalability( float )                                zCall( 0x005C0560 );
    virtual float GetFarZScalability() const                                zCall( 0x005C05B0 );
    virtual void SetBackgroundColor( zCOLOR )                               zCall( 0x005BC7B0 );
    virtual zCOLOR GetBackgroundColor() const                               zCall( 0x005BC7C0 );
    virtual void UpdateWorldDependencies()                                  zCall( 0x005BCF50 );
    virtual int GetRelightCtr()                                             zCall( 0x005BE950 );
    virtual zCOLOR GetDaylightColorFromIntensity( int )                     zCall( 0x005BE960 );
    virtual void RenderSkyPre()                                             zCall( 0x005C0900 );
    virtual void RenderSkyPost()                                            zCall( 0x005C1160 );
    virtual void SetCameraLocationHint( zCSkyControler::zTCamLocationHint ) zCall( 0x005BC7D0 );

    // user API
    #include "zCSkyControler_Outdoor.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZSKY_H__VER0__