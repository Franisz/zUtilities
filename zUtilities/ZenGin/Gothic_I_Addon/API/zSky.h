// Supported with union (c) 2018-2021 Union team

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

  // sizeof 40h
  class zCSkyLayerData {
  public:
    zESkyLayerMode skyMode; // sizeof 04h    offset 00h
    zCTexture* texBox[5];   // sizeof 14h    offset 04h
    zCTexture* tex;         // sizeof 04h    offset 18h
    zSTRING texName;        // sizeof 14h    offset 1Ch
    float texAlpha;         // sizeof 04h    offset 30h
    float texScale;         // sizeof 04h    offset 34h
    zVEC2 texSpeed;         // sizeof 08h    offset 38h

    void zCSkyLayerData_OnInit() zCall( 0x005D93C0 );
    zCSkyLayerData()             zInit( zCSkyLayerData_OnInit() );
    ~zCSkyLayerData()            zCall( 0x005D9430 );

    // user API
    #include "zCSkyLayerData.inl"
  };

  // sizeof C0h
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
    zCSkyLayerData layer[zSKY_NUM_LAYER]; // sizeof 80h    offset 40h

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

  // sizeof 18h
  class zCSkyLayer {
  public:
    zCMesh* skyPolyMesh;    // sizeof 04h    offset 00h
    zCPolygon* skyPoly;     // sizeof 04h    offset 04h
    zVEC2 skyTexOffs;       // sizeof 08h    offset 08h
    zCMesh* skyBoxMesh;     // sizeof 04h    offset 10h
    zESkyLayerMode skyMode; // sizeof 04h    offset 14h

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

  // sizeof 40h
  class zCSkyPlanet {
  public:
    zCMesh* mesh;  // sizeof 04h    offset 00h
    zVEC4 color0;  // sizeof 10h    offset 04h
    zVEC4 color1;  // sizeof 10h    offset 14h
    float size;    // sizeof 04h    offset 24h
    zVEC3 pos;     // sizeof 0Ch    offset 28h
    zVEC3 rotAxis; // sizeof 0Ch    offset 34h

    void zCSkyPlanet_OnInit() zCall( 0x005DA300 );
    zCSkyPlanet()             zInit( zCSkyPlanet_OnInit() );
    ~zCSkyPlanet()            zCall( 0x005DA310 );

    // user API
    #include "zCSkyPlanet.inl"
  };

  // sizeof BCh
  class zCUnderwaterPFX : public zCParticleFX {
  public:
    zVEC3 camPosLastFrame; // sizeof 0Ch    offset B0h

    zCUnderwaterPFX() {}
    void ProcessParticles()                zCall( 0x005D8930 );
    void CreateParticles()                 zCall( 0x005D8CC0 );
    virtual ~zCUnderwaterPFX()             zCall( 0x005D84C0 );
    virtual int Render( zTRenderContext& ) zCall( 0x005D8910 );

    // user API
    #include "zCUnderwaterPFX.inl"
  };

  // sizeof 38h
  class zCSkyControler : public zCObject {
  public:
    zCLASS_DECLARATION( zCSkyControler )

    enum zTCamLocationHint {
      zCAM_OUTSIDE_SECTOR,
      zCAM_INSIDE_SECTOR_CANT_SEE_OUTSIDE,
      zCAM_INSIDE_SECTOR_CAN_SEE_OUTSIDE
    };

    zCOLOR* polyLightCLUTPtr;     // sizeof 04h    offset 24h
    float cloudShadowScale;       // sizeof 04h    offset 28h
    zCOLOR backgroundColor;       // sizeof 04h    offset 2Ch
    int fillBackground;           // sizeof 04h    offset 30h
    zCTexture* backgroundTexture; // sizeof 04h    offset 34h

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

  // sizeof 68h
  class zCSkyControler_Mid : public zCSkyControler {
  public:
    zCLASS_DECLARATION( zCSkyControler_Mid )

    int underwaterFX;                      // sizeof 04h    offset 38h
    zCOLOR underwaterColor;                // sizeof 04h    offset 3Ch
    float underwaterFarZ;                  // sizeof 04h    offset 40h
    float underwaterStartTime;             // sizeof 04h    offset 44h
    float oldFovX;                         // sizeof 04h    offset 48h
    float oldFovY;                         // sizeof 04h    offset 4Ch
    zCVob* vobUnderwaterPFX;               // sizeof 04h    offset 50h
    zCPolygon* scrPoly;                    // sizeof 04h    offset 54h
    zCMesh* scrPolyMesh;                   // sizeof 04h    offset 58h
    int scrPolyAlpha;                      // sizeof 04h    offset 5Ch
    zCOLOR scrPolyColor;                   // sizeof 04h    offset 60h
    zTRnd_AlphaBlendFunc scrPolyAlphaFunc; // sizeof 04h    offset 64h

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

  // sizeof 74h
  class zCSkyControler_Indoor : public zCSkyControler_Mid {
  public:
    zCLASS_DECLARATION( zCSkyControler_Indoor )

    float userFarZ;            // sizeof 04h    offset 68h
    float userFarZScalability; // sizeof 04h    offset 6Ch
    float time;                // sizeof 04h    offset 70h

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

  // sizeof 680h
  class zCSkyControler_Outdoor : public zCSkyControler_Mid {
  public:
    zCLASS_DECLARATION( zCSkyControler_Outdoor )

    // sizeof 1Ch
    struct zTRainFX {
      zCOutdoorRainFX* outdoorRainFX;        // sizeof 04h    offset 00h
      zTCamLocationHint camLocationHint;     // sizeof 04h    offset 04h
      float outdoorRainFXWeight;             // sizeof 04h    offset 08h
      float soundVolume;                     // sizeof 04h    offset 0Ch
      float timerInsideSectorCantSeeOutside; // sizeof 04h    offset 10h
      float timeStartRain;                   // sizeof 04h    offset 14h
      float timeStopRain;                    // sizeof 04h    offset 18h

      zTRainFX() {}

      // user API
      #include "zCSkyControler_Outdoor_zTRainFX.inl"
    };

    int initDone;                         // sizeof 04h    offset 68h
    float masterTime;                     // sizeof 04h    offset 6Ch
    float masterTimeLast;                 // sizeof 04h    offset 70h
    zCSkyState masterState;               // sizeof C0h    offset 74h
    zCSkyState* state0;                   // sizeof 04h    offset 134h
    zCSkyState* state1;                   // sizeof 04h    offset 138h
    zCArray<zCSkyState*> stateList;       // sizeof 0Ch    offset 13Ch
    zCOLOR polyLightCLUT[256];            // sizeof 400h   offset 148h
    int relightCtr;                       // sizeof 04h    offset 548h
    float lastRelightTime;                // sizeof 04h    offset 54Ch
    float dayCounter;                     // sizeof 04h    offset 550h
    zCArray<zVEC3> fogColorDayVariations; // sizeof 0Ch    offset 554h
    float resultFogScale;                 // sizeof 04h    offset 560h
    float heightFogMinY;                  // sizeof 04h    offset 564h
    float heightFogMaxY;                  // sizeof 04h    offset 568h
    float userFogFar;                     // sizeof 04h    offset 56Ch
    float resultFogNear;                  // sizeof 04h    offset 570h
    float resultFogFar;                   // sizeof 04h    offset 574h
    float resultFogSkyNear;               // sizeof 04h    offset 578h
    float resultFogSkyFar;                // sizeof 04h    offset 57Ch
    zCOLOR resultFogColor;                // sizeof 04h    offset 580h
    float userFarZScalability;            // sizeof 04h    offset 584h
    zCSkyState* skyLayerState[2];         // sizeof 08h    offset 588h
    zCSkyLayer skyLayer[2];               // sizeof 30h    offset 590h
    zCSkyLayer skyLayerRainClouds;        // sizeof 18h    offset 5C0h
    zCTexture* skyCloudLayerTex;          // sizeof 04h    offset 5D8h
    zCSkyPlanet planets[NUM_PLANETS];     // sizeof 80h    offset 5DCh
    zCVob* vobSkyPFX;                     // sizeof 04h    offset 65Ch
    float skyPFXTimer;                    // sizeof 04h    offset 660h
    zTRainFX rainFX;                      // sizeof 1Ch    offset 664h

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