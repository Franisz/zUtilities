// Supported with union (c) 2018-2021 Union team

#ifndef __ZLENSFLARE_H__VER3__
#define __ZLENSFLARE_H__VER3__

namespace Gothic_II_Addon {

  // sizeof 38h
  class zCLensFlareFX : public zCObject {
  public:
    zCLASS_DECLARATION( zCLensFlareFX )

    enum zCLensFlareFXEnum1 {
      FM_GLOW_ONLY,
      FM_MIXED,
      FM_NO_GLOW
    };

    // sizeof 20h
    class zTVobLightLensFlare {
    public:
      enum zTFlareType {
        FT_CORONA,
        FT_GLOW,
        FT_FLARE
      };

      zCMaterial* lensFlareMaterial; // sizeof 04h    offset 00h
      zTFlareType flareType;         // sizeof 04h    offset 04h
      float size;                    // sizeof 04h    offset 08h
      float alpha;                   // sizeof 04h    offset 0Ch
      float rangeMin;                // sizeof 04h    offset 10h
      float rangeMax;                // sizeof 04h    offset 14h
      float posScale;                // sizeof 04h    offset 18h
      float fadeScale;               // sizeof 04h    offset 1Ch

      void zTVobLightLensFlare_OnInit() zCall( 0x00563020 );
      zTVobLightLensFlare()             zInit( zTVobLightLensFlare_OnInit() );

      // user API
      #include "zCLensFlareFX_zTVobLightLensFlare.inl"
    };

    zCArray<zTVobLightLensFlare> lensFlareList; // sizeof 0Ch    offset 24h
    zCLensFlareFXEnum1 flareMix;                // sizeof 04h    offset 30h
    float fadeScale;                            // sizeof 04h    offset 34h

    zCLensFlareFX() {}
    void RenderLensFlares( zCVob* )          zCall( 0x00563040 );
    void RenderLensFlares( zVEC2& )          zCall( 0x00563880 );
    void SetAlpha( int )                     zCall( 0x00563A10 );
    static zCObject* _CreateNewInstance()    zCall( 0x005624C0 );
    static void LoadLensFlareScript()        zCall( 0x00562650 );
    static void ReleaseLensFlareScript()     zCall( 0x00562940 );
    virtual zCClassDef* _GetClassDef() const zCall( 0x00562610 );
    virtual void Archive( zCArchiver& )      zCall( 0x00562AA0 );
    virtual void Unarchive( zCArchiver& )    zCall( 0x00562BF0 );
    virtual ~zCLensFlareFX()                 zCall( 0x005629F0 );

    // static properties
    static zCMesh*& s_lensFlareMesh;
    static zCMesh*& s_coronaMesh;
    static zCMesh*& s_glowMesh;

    // user API
    #include "zCLensFlareFX.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZLENSFLARE_H__VER3__