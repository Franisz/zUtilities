// Supported with union (c) 2018-2021 Union team

#ifndef __ZMATERIAL_H__VER3__
#define __ZMATERIAL_H__VER3__

#include "zRenderer.h"
#include "zTexture.h"
#include "zFft.h"

namespace Gothic_II_Addon {

  enum zTMat_Group {
    zMAT_GROUP_UNDEF,
    zMAT_GROUP_METAL,
    zMAT_GROUP_STONE,
    zMAT_GROUP_WOOD,
    zMAT_GROUP_EARTH,
    zMAT_GROUP_WATER,
    zMAT_GROUP_SNOW,
    zMAT_NUM_MAT_GROUP
  };

  enum zTWaveAniMode {
    zWAVEANI_NONE,
    zWAVEANI_GROUND_AMBIENT,
    zWAVEANI_GROUND,
    zWAVEANI_WALL_AMBIENT,
    zWAVEANI_WALL,
    zWAVEANI_ENV,
    zWAVEANI_WIND_AMBIENT,
    zWAVEANI_WIND
  };

  // sizeof 14h
  class zCTexAniCtrl {
  public:
    int aniChannel;         // sizeof 04h    offset 00h
    float actFrame;         // sizeof 04h    offset 04h
    float aniFPS;           // sizeof 04h    offset 08h
    unsigned long frameCtr; // sizeof 04h    offset 0Ch
    int bOneShotAni;        // sizeof 04h    offset 10h

    void zCTexAniCtrl_OnInit()    zCall( 0x00565D30 );
    zCTexAniCtrl()                zInit( zCTexAniCtrl_OnInit() );
    void AdvanceAni( zCTexture* ) zCall( 0x00565D50 );

    // static properties
    static unsigned long& masterFrameCtr;

    // user API
    #include "zCTexAniCtrl.inl"
  };

  // sizeof ACh
  class zCMaterial : public zCObject {
  public:
    zCLASS_DECLARATION( zCMaterial )

    enum {
      zMAT_USAGE_LEVEL,
      zMAT_USAGE_OTHER
    };

    zCArray<zCPolygon*> polyList;                 // sizeof 0Ch    offset 24h
    unsigned long polyListTimeStamp;              // sizeof 04h    offset 30h
    zCTexture* texture;                           // sizeof 04h    offset 34h
    zCOLOR color;                                 // sizeof 04h    offset 38h
    float smoothAngle;                            // sizeof 04h    offset 3Ch
    zTMat_Group matGroup;                         // sizeof 04h    offset 40h
    zCBspSector* bspSectorFront;                  // sizeof 04h    offset 44h
    zCBspSector* bspSectorBack;                   // sizeof 04h    offset 48h
    zCTexAniCtrl texAniCtrl;                      // sizeof 14h    offset 4Ch
    zSTRING* detailObjectVisualName;              // sizeof 04h    offset 60h
    float kambient;                               // sizeof 04h    offset 64h
    float kdiffuse;                               // sizeof 04h    offset 68h
    float m_bEnvironmentalMappingStrength;        // sizeof 04h    offset 6Ch
    group {
      unsigned char smooth                   : 1; // sizeof 01h    offset bit
      unsigned char dontUseLightmaps         : 1; // sizeof 01h    offset bit
      unsigned char texAniMap                : 1; // sizeof 01h    offset bit
      unsigned char lodDontCollapse          : 1; // sizeof 01h    offset bit
      unsigned char noCollDet                : 1; // sizeof 01h    offset bit
      unsigned char forceOccluder            : 1; // sizeof 01h    offset bit
      unsigned char m_bEnvironmentalMapping  : 1; // sizeof 01h    offset bit
      unsigned char polyListNeedsSort        : 1; // sizeof 01h    offset bit
      unsigned char matUsage                 : 8; // sizeof 08h    offset bit
      unsigned char libFlag                  : 8; // sizeof 08h    offset bit
      zTRnd_AlphaBlendFunc rndAlphaBlendFunc : 8; // sizeof 08h    offset bit
      unsigned char m_bIgnoreSun             : 1; // sizeof 01h    offset bit
    };
    zTWaveAniMode m_enuWaveMode;                  // sizeof 04h    offset 7Ch
    zTFFT m_enuWaveSpeed;                         // sizeof 04h    offset 80h
    float m_fWaveMaxAmplitude;                    // sizeof 04h    offset 84h
    float m_fWaveGridSize;                        // sizeof 04h    offset 88h
    zCTexture* detailTexture;                     // sizeof 04h    offset 8Ch
    float detailTextureScale;                     // sizeof 04h    offset 90h
    zVEC2 texAniMapDelta;                         // sizeof 08h    offset 94h
    zVEC2 default_mapping;                        // sizeof 08h    offset 9Ch
    zVEC2 texScale;                               // sizeof 08h    offset A4h

    void zCMaterial_OnInit()                               zCall( 0x00563E00 );
    void zCMaterial_OnInit( zSTRING const& )               zCall( 0x00563EE0 );
    void zCMaterial_OnInit( zCMaterial const& )            zCall( 0x00563FA0 );
    zSTRING const& GetName() const                         zCall( 0x0055FF10 );
    zCMaterial()                                           zInit( zCMaterial_OnInit() );
    zCMaterial( zSTRING const& a0 )                        zInit( zCMaterial_OnInit( a0 ));
    zCMaterial( zCMaterial const& a0 )                     zInit( zCMaterial_OnInit( a0 ));
    zCMaterial& operator =( zCMaterial const& )            zCall( 0x00564050 );
    void InitThisByMaterial( zCMaterial const& )           zCall( 0x00564130 );
    void InitValues()                                      zCall( 0x00564260 );
    void SetDetailObjectVisual( zSTRING const& )           zCall( 0x00564370 );
    zSTRING const& GetDetailObjectVisual() const           zCall( 0x005644F0 );
    void ApplyTexAniMapping( zCPolygon* )                  zCall( 0x00564500 );
    zVEC3 GetTexAniVector( zCPolygon* )                    zCall( 0x00564590 );
    int IsPortalMaterial() const                           zCall( 0x005648D0 );
    void SetTexAniMappingDir( zVEC2 const& )               zCall( 0x005649C0 );
    void SetTexture( zSTRING& )                            zCall( 0x005649E0 );
    void SetTexture( zCTexture* )                          zCall( 0x00564B20 );
    void SetDetailTexture( zSTRING& )                      zCall( 0x00564CD0 );
    void SetDetailTexture( zCTexture* )                    zCall( 0x00564DD0 );
    void AutoAssignDetailTexture()                         zCall( 0x00564E20 );
    zVEC2 GetTexScale()                                    zCall( 0x00564FC0 );
    void SetTexScale( zVEC2 )                              zCall( 0x00565020 );
    void RemoveTexture()                                   zCall( 0x00565040 );
    zSTRING const& GetMatGroupString() const               zCall( 0x00565170 );
    void SetMatGroupByString( zSTRING const& )             zCall( 0x005651D0 );
    void RefreshAvgColorFromTexture()                      zCall( 0x005653D0 );
    zCTexture* GetAniTexture()                             zCall( 0x0064BA20 );
    static zCObject* _CreateNewInstance()                  zCall( 0x00563D20 );
    static zSTRING const& GetMatGroupString( zTMat_Group ) zCall( 0x00565110 );
    static zCMaterial* SearchName( zSTRING& )              zCall( 0x00565E30 );
    virtual zCClassDef* _GetClassDef() const               zCall( 0x00563DF0 );
    virtual void Archive( zCArchiver& )                    zCall( 0x00565420 );
    virtual void Unarchive( zCArchiver& )                  zCall( 0x00565780 );
    virtual ~zCMaterial()                                  zCall( 0x00564070 );

    // static properties
    static unsigned char& s_matUsageDefault;

    // user API
    #include "zCMaterial.inl"
  };

} // namespace Gothic_II_Addon

#endif // __ZMATERIAL_H__VER3__