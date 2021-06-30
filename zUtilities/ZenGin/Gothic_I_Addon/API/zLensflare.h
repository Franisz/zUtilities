// Supported with union (c) 2018 Union team

#ifndef __ZLENSFLARE_H__VER1__
#define __ZLENSFLARE_H__VER1__

namespace Gothic_I_Addon {

  class zCLensFlareFX : public zCObject {
  public:
    zCLASS_DECLARATION( zCLensFlareFX )

    enum zCLensFlareFXEnum1 {
      FM_GLOW_ONLY,
      FM_MIXED,
      FM_NO_GLOW
    };

    class zTVobLightLensFlare {
    public:
      enum zTFlareType {
        FT_CORONA,
        FT_GLOW,
        FT_FLARE
      };

      zCMaterial* lensFlareMaterial;
      zTFlareType flareType;
      float size;
      float alpha;
      float rangeMin;
      float rangeMax;
      float posScale;

      void zTVobLightLensFlare_OnInit() zCall( 0x005645A0 );
      zTVobLightLensFlare()             zInit( zTVobLightLensFlare_OnInit() );

      // user API
      #include "zCLensFlareFX_zTVobLightLensFlare.inl"
    };

    zCArray<zTVobLightLensFlare> lensFlareList;
    zCLensFlareFXEnum1 flareMix;

    zCLensFlareFX() {}
    void RenderLensFlares( zCVob* )                                     zCall( 0x005645C0 );
    void RenderLensFlares( zVEC2& )                                     zCall( 0x00564D40 );
    void SetAlpha( int )                                                zCall( 0x00564F20 );
    static zCObject* _CreateNewInstance()                               zCall( 0x005639F0 );
    static void LoadLensFlareScript()                                   zCall( 0x00563B90 );
    static void ReleaseLensFlareScript()                                zCall( 0x00563E90 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x00563B50 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x00564000 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x00564120 );
    virtual ~zCLensFlareFX()                                            zCall( 0x00563F50 );


    // static properties
    static zCMesh*& s_lensFlareMesh;
    static zCMesh*& s_coronaMesh;
    static zCMesh*& s_glowMesh;

    // user API
    #include "zCLensFlareFX.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZLENSFLARE_H__VER1__