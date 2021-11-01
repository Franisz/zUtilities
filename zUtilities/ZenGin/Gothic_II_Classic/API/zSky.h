// Supported with union (c) 2018-2021 Union team

#ifndef __ZSKY_H__VER2__
#define __ZSKY_H__VER2__

namespace Gothic_II_Classic {

  enum zTWeather {
    zTWEATHER_SNOW,
    zTWEATHER_RAIN
  };

  // sizeof C4h
  class zCUnderwaterPFX : public zCParticleFX {
  public:
    zVEC3 camPosLastFrame; // sizeof 0Ch    offset B8h

    zCUnderwaterPFX() {}
    void ProcessParticles()                zCall( 0x005D9B40 );
    void CreateParticles()                 zCall( 0x005D9F40 );
    virtual ~zCUnderwaterPFX()             zCall( 0x005D9160 );
    virtual int Render( zTRenderContext& ) zCall( 0x005D9B20 );

    // user API
    #include "zCUnderwaterPFX.inl"
  };

  // sizeof 4Ch
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
    int m_bColorChanged;          // sizeof 04h    offset 2Ch
    zTWeather m_enuWeather;       // sizeof 04h    offset 30h
    zCOLOR backgroundColor;       // sizeof 04h    offset 34h
    int fillBackground;           // sizeof 04h    offset 38h
    zCTexture* backgroundTexture; // sizeof 04h    offset 3Ch
    int relightCtr;               // sizeof 04h    offset 40h
    float lastRelightTime;        // sizeof 04h    offset 44h
    float m_fRelightTime;         // sizeof 04h    offset 48h

    void zCSkyControler_OnInit()                            zCall( 0x005D88F0 );
    zCSkyControler()                                        zInit( zCSkyControler_OnInit() );
    void ClearBackground( zCOLOR )                          zCall( 0x005D8B80 );
    virtual zCClassDef* _GetClassDef() const                zCall( 0x005D88E0 );
    virtual ~zCSkyControler()                               zCall( 0x005D8B10 );
    virtual void SetTime( float )                           zPureCall;
    virtual float GetTime() const                           zPureCall;
    virtual void ResetTime()                                zPureCall;
    virtual void SetFarZ( float )                           zPureCall;
    virtual float GetFarZ() const                           zPureCall;
    virtual void SetFarZScalability( float )                zPureCall;
    virtual float GetFarZScalability() const                zPureCall;
    virtual void SetBackgroundColor( zCOLOR )               zPureCall;
    virtual zCOLOR GetBackgroundColor() const               zPureCall;
    virtual zCOLOR GetBackgroundColorDef() const            zPureCall;
    virtual void SetOverrideColor( zVEC3 )                  zPureCall;
    virtual void SetOverrideColorFlag( int )                zPureCall;
    virtual float GetCloudShadowScale() const               zCall( 0x005D8660 );
    virtual void SetCloudShadowScale( float )               zCall( 0x005D8670 );
    virtual void SetFillBackground( int )                   zCall( 0x005D8680 );
    virtual int GetFillBackground() const                   zCall( 0x005D8690 );
    virtual void SetUnderwaterFX( int )                     zPureCall;
    virtual int GetUnderwaterFX() const                     zPureCall;
    virtual void UpdateWorldDependencies()                  zPureCall;
    virtual void SetLightDirty()                            zCall( 0x005D86A0 );
    virtual void SetRelightTime( float )                    zCall( 0x005D86B0 );
    virtual int GetRelightCtr()                             zCall( 0x005D86C0 );
    virtual zCOLOR GetDaylightColorFromIntensity( int )     zCall( 0x005D86D0 );
    virtual void RenderSkyPre()                             zPureCall;
    virtual void RenderSkyPost( int )                       zPureCall;
    virtual int GetGlobalWindVec( zVEC3&, zTAnimationMode ) zCall( 0x005D86F0 );
    virtual void SetGlobalSkyScale( float )                 zCall( 0x005D8700 );
    virtual float GetGlobalSkyScale() const                 zCall( 0x005D8710 );
    virtual int GetGlobalSkyScaleChanged() const            zCall( 0x005D8720 );
    virtual void SetCameraLocationHint( zTCamLocationHint ) zCall( 0x005D8730 );
    virtual void SetWeatherType( zTWeather )                zCall( 0x005D8740 );
    virtual zTWeather GetWeatherType() const                zCall( 0x005D8750 );

    // static properties
    static zCSkyControler*& s_activeSkyControler;
    static int& s_skyEffectsEnabled;

    // user API
    #include "zCSkyControler.inl"
  };

  // sizeof 7Ch
  class zCSkyControler_Mid : public zCSkyControler {
  public:
    zCLASS_DECLARATION( zCSkyControler_Mid )

    int underwaterFX;                      // sizeof 04h    offset 4Ch
    zCOLOR underwaterColor;                // sizeof 04h    offset 50h
    float underwaterFarZ;                  // sizeof 04h    offset 54h
    float underwaterStartTime;             // sizeof 04h    offset 58h
    float oldFovX;                         // sizeof 04h    offset 5Ch
    float oldFovY;                         // sizeof 04h    offset 60h
    zCVob* vobUnderwaterPFX;               // sizeof 04h    offset 64h
    zCPolygon* scrPoly;                    // sizeof 04h    offset 68h
    zCMesh* scrPolyMesh;                   // sizeof 04h    offset 6Ch
    int scrPolyAlpha;                      // sizeof 04h    offset 70h
    zCOLOR scrPolyColor;                   // sizeof 04h    offset 74h
    zTRnd_AlphaBlendFunc scrPolyAlphaFunc; // sizeof 04h    offset 78h

    void zCSkyControler_Mid_OnInit()                     zCall( 0x005D8E40 );
    zCSkyControler_Mid()                                 zInit( zCSkyControler_Mid_OnInit() );
    void InitUnderwaterPFX()                             zCall( 0x005D8EE0 );
    void InitScreenBlend()                               zCall( 0x005D9560 );
    void RenderScreenBlend()                             zCall( 0x005D9680 );
    void SetScreenBlendAlpha( int )                      zCall( 0x005D9840 );
    void SetScreenBlendColor( zCOLOR const& )            zCall( 0x005D9860 );
    void SetScreenBlendAlphaFunc( zTRnd_AlphaBlendFunc ) zCall( 0x005D9870 );
    virtual zCClassDef* _GetClassDef() const             zCall( 0x005D8760 );
    virtual ~zCSkyControler_Mid()                        zCall( 0x005D9170 );
    virtual void SetTime( float )                        zPureCall;
    virtual float GetTime() const                        zPureCall;
    virtual void ResetTime()                             zPureCall;
    virtual void SetFarZ( float )                        zPureCall;
    virtual float GetFarZ() const                        zPureCall;
    virtual void SetFarZScalability( float )             zPureCall;
    virtual float GetFarZScalability() const             zPureCall;
    virtual void SetBackgroundColor( zCOLOR )            zPureCall;
    virtual zCOLOR GetBackgroundColor() const            zPureCall;
    virtual zCOLOR GetBackgroundColorDef() const         zPureCall;
    virtual void SetOverrideColor( zVEC3 )               zPureCall;
    virtual void SetOverrideColorFlag( int )             zPureCall;
    virtual void SetUnderwaterFX( int )                  zCall( 0x005D9230 );
    virtual int GetUnderwaterFX() const                  zCall( 0x005D92A0 );
    virtual void UpdateWorldDependencies()               zPureCall;
    virtual void RenderSkyPre()                          zCall( 0x005D92B0 );
    virtual void RenderSkyPost( int )                    zCall( 0x005D9380 );

    // user API
    #include "zCSkyControler_Mid.inl"
  };

  // sizeof 88h
  class zCSkyControler_Indoor : public zCSkyControler_Mid {
  public:
    zCLASS_DECLARATION( zCSkyControler_Indoor )

    float userFarZ;            // sizeof 04h    offset 7Ch
    float userFarZScalability; // sizeof 04h    offset 80h
    float time;                // sizeof 04h    offset 84h

    void zCSkyControler_Indoor_OnInit()          zCall( 0x005D9880 );
    zCSkyControler_Indoor()                      zInit( zCSkyControler_Indoor_OnInit() );
    static zCObject* _CreateNewInstance()        zCall( 0x005D8580 );
    virtual zCClassDef* _GetClassDef() const     zCall( 0x005D8790 );
    virtual ~zCSkyControler_Indoor()             zCall( 0x005D8820 );
    virtual void SetTime( float )                zCall( 0x005D9920 );
    virtual float GetTime() const                zCall( 0x005D87A0 );
    virtual void ResetTime()                     zCall( 0x005D87B0 );
    virtual void SetFarZ( float )                zCall( 0x005D99C0 );
    virtual float GetFarZ() const                zCall( 0x005D99D0 );
    virtual void SetFarZScalability( float )     zCall( 0x005D99E0 );
    virtual float GetFarZScalability() const     zCall( 0x005D9A30 );
    virtual void SetBackgroundColor( zCOLOR )    zCall( 0x005D9A40 );
    virtual zCOLOR GetBackgroundColor() const    zCall( 0x005D9A50 );
    virtual zCOLOR GetBackgroundColorDef() const zCall( 0x005D9A60 );
    virtual void SetOverrideColor( zVEC3 )       zCall( 0x005D87C0 );
    virtual void SetOverrideColorFlag( int )     zCall( 0x005D87D0 );
    virtual void UpdateWorldDependencies()       zCall( 0x005D87E0 );
    virtual void RenderSkyPre()                  zCall( 0x005D9A70 );
    virtual void RenderSkyPost( int )            zCall( 0x005D9B10 );

    // user API
    #include "zCSkyControler_Indoor.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZSKY_H__VER2__