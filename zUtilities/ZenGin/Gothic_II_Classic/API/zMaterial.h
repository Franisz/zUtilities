// Supported with union (c) 2018 Union team

#ifndef __ZMATERIAL_H__VER2__
#define __ZMATERIAL_H__VER2__

#include "zRenderer.h"
#include "zTexture.h"
#include "zFft.h"

namespace Gothic_II_Classic {

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

  class zCTexAniCtrl {
  public:
    int aniChannel;
    float actFrame;
    float aniFPS;
    unsigned long frameCtr;
    int bOneShotAni;

    void zCTexAniCtrl_OnInit()    zCall( 0x00560B10 );
    zCTexAniCtrl()                zInit( zCTexAniCtrl_OnInit() );
    void AdvanceAni( zCTexture* ) zCall( 0x00560B30 );

    // static properties
    static unsigned long& masterFrameCtr;

    // user API
    #include "zCTexAniCtrl.inl"
  };

  class zCMaterial : public zCObject {
  public:
    zCLASS_DECLARATION( zCMaterial )

    enum {
      zMAT_USAGE_LEVEL,
      zMAT_USAGE_OTHER
    };

    zCArray<zCPolygon*> polyList;
    unsigned long polyListTimeStamp;
    zCTexture* texture;
    zCOLOR color;
    float smoothAngle;
    zTMat_Group matGroup;
    zCBspSector* bspSectorFront;
    zCBspSector* bspSectorBack;
    zCTexAniCtrl texAniCtrl;
    zSTRING* detailObjectVisualName;
    float kambient;
    float kdiffuse;
    float m_bEnvironmentalMappingStrength;
    group {
      unsigned char smooth                   : 1;
      unsigned char dontUseLightmaps         : 1;
      unsigned char texAniMap                : 1;
      unsigned char lodDontCollapse          : 1;
      unsigned char noCollDet                : 1;
      unsigned char forceOccluder            : 1;
      unsigned char m_bEnvironmentalMapping  : 1;
      unsigned char polyListNeedsSort        : 1;
      unsigned char matUsage                 : 8;
      unsigned char libFlag                  : 8;
      zTRnd_AlphaBlendFunc rndAlphaBlendFunc : 8;
      unsigned char m_bIgnoreSun             : 1;
    };
    zTWaveAniMode m_enuWaveMode;
    zTFFT m_enuWaveSpeed;
    float m_fWaveMaxAmplitude;
    float m_fWaveGridSize;
    zCTexture* detailTexture;
    float detailTextureScale;
    zVEC2 texAniMapDelta;
    zVEC2 default_mapping;
    zVEC2 texScale;

    void zCMaterial_OnInit()                               zCall( 0x0055EBE0 );
    void zCMaterial_OnInit( zSTRING const& )               zCall( 0x0055ECC0 );
    void zCMaterial_OnInit( zCMaterial const& )            zCall( 0x0055ED80 );
    zSTRING const& GetName() const                         zCall( 0x0055ACF0 );
    zCMaterial()                                           zInit( zCMaterial_OnInit() );
    zCMaterial( zSTRING const& a0 )                        zInit( zCMaterial_OnInit( a0 ));
    zCMaterial( zCMaterial const& a0 )                     zInit( zCMaterial_OnInit( a0 ));
    zCMaterial& operator =( zCMaterial const& )            zCall( 0x0055EE30 );
    void InitThisByMaterial( zCMaterial const& )           zCall( 0x0055EF10 );
    void InitValues()                                      zCall( 0x0055F040 );
    void SetDetailObjectVisual( zSTRING const& )           zCall( 0x0055F150 );
    zSTRING const& GetDetailObjectVisual() const           zCall( 0x0055F2D0 );
    void ApplyTexAniMapping( zCPolygon* )                  zCall( 0x0055F2E0 );
    zVEC3 GetTexAniVector( zCPolygon* )                    zCall( 0x0055F370 );
    int IsPortalMaterial() const                           zCall( 0x0055F6B0 );
    void SetTexAniMappingDir( zVEC2 const& )               zCall( 0x0055F7A0 );
    void SetTexture( zSTRING& )                            zCall( 0x0055F7C0 );
    void SetTexture( zCTexture* )                          zCall( 0x0055F900 );
    void SetDetailTexture( zSTRING& )                      zCall( 0x0055FAB0 );
    void SetDetailTexture( zCTexture* )                    zCall( 0x0055FBB0 );
    void AutoAssignDetailTexture()                         zCall( 0x0055FC00 );
    zVEC2 GetTexScale()                                    zCall( 0x0055FDA0 );
    void SetTexScale( zVEC2 )                              zCall( 0x0055FE00 );
    void RemoveTexture()                                   zCall( 0x0055FE20 );
    zSTRING const& GetMatGroupString() const               zCall( 0x0055FF50 );
    void SetMatGroupByString( zSTRING const& )             zCall( 0x0055FFB0 );
    void RefreshAvgColorFromTexture()                      zCall( 0x005601B0 );
    zCTexture* GetAniTexture()                             zCall( 0x00760480 );
    static zCObject* _CreateNewInstance()                  zCall( 0x0055EB00 );
    static zSTRING const& GetMatGroupString( zTMat_Group ) zCall( 0x0055FEF0 );
    static zCMaterial* SearchName( zSTRING& )              zCall( 0x00560C10 );
    virtual zCClassDef* _GetClassDef() const               zCall( 0x0055EBD0 );
    virtual void Archive( zCArchiver& )                    zCall( 0x00560200 );
    virtual void Unarchive( zCArchiver& )                  zCall( 0x00560560 );
    virtual ~zCMaterial()                                  zCall( 0x0055EE50 );

    // static properties
    static unsigned char& s_matUsageDefault;

    // user API
    #include "zCMaterial.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZMATERIAL_H__VER2__