// Supported with union (c) 2018-2021 Union team

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

    void zCSkyLayerData_OnInit() zCall( 0x005BB830 );
    zCSkyLayerData()             zInit( zCSkyLayerData_OnInit() );
    ~zCSkyLayerData()            zCall( 0x005BB8A0 );

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

  // sizeof 18h
  class zCSkyLayer {
  public:
    zCMesh* skyPolyMesh;    // sizeof 04h    offset 00h
    zCPolygon* skyPoly;     // sizeof 04h    offset 04h
    zVEC2 skyTexOffs;       // sizeof 08h    offset 08h
    zCMesh* skyBoxMesh;     // sizeof 04h    offset 10h
    zESkyLayerMode skyMode; // sizeof 04h    offset 14h

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

  // sizeof 40h
  class zCSkyPlanet {
  public:
    zCMesh* mesh;  // sizeof 04h    offset 00h
    zVEC4 color0;  // sizeof 10h    offset 04h
    zVEC4 color1;  // sizeof 10h    offset 14h
    float size;    // sizeof 04h    offset 24h
    zVEC3 pos;     // sizeof 0Ch    offset 28h
    zVEC3 rotAxis; // sizeof 0Ch    offset 34h

    void zCSkyPlanet_OnInit() zCall( 0x005BC750 );
    zCSkyPlanet()             zInit( zCSkyPlanet_OnInit() );
    ~zCSkyPlanet()            zCall( 0x005BC760 );

    // user API
    #include "zCSkyPlanet.inl"
  };

  // sizeof BCh
  class zCUnderwaterPFX : public zCParticleFX {
  public:
    zVEC3 camPosLastFrame; // sizeof 0Ch    offset B0h

    zCUnderwaterPFX() {}
    void ProcessParticles()                zCall( 0x005BADC0 );
    void CreateParticles()                 zCall( 0x005BB1C0 );
    virtual ~zCUnderwaterPFX()             zCall( 0x005BA960 );
    virtual int Render( zTRenderContext& ) zCall( 0x005BADA0 );

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

  // sizeof 74h
  class zCSkyControler_Indoor : public zCSkyControler_Mid {
  public:
    zCLASS_DECLARATION( zCSkyControler_Indoor )

    float userFarZ;            // sizeof 04h    offset 68h
    float userFarZScalability; // sizeof 04h    offset 6Ch
    float time;                // sizeof 04h    offset 70h

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