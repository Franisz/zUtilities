// Supported with union (c) 2018 Union team

#ifndef __ZMATERIAL_H__VER1__
#define __ZMATERIAL_H__VER1__

namespace Gothic_I_Addon {

  enum zTMat_Group {
    zMAT_GROUP_UNDEF,
    zMAT_GROUP_METAL,
    zMAT_GROUP_STONE,
    zMAT_GROUP_WOOD,
    zMAT_GROUP_EARTH,
    zMAT_GROUP_WATER,
    zMAT_NUM_MAT_GROUP
  };

  class zCTexAniCtrl {
  public:
    int aniChannel;
    float actFrame;
    float aniFPS;
    unsigned long frameCtr;
    int bOneShotAni;

    void zCTexAniCtrl_OnInit()    zCall( 0x00566EB0 );
    zCTexAniCtrl()                zInit( zCTexAniCtrl_OnInit() );
    void AdvanceAni( zCTexture* ) zCall( 0x00566ED0 );

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
    group {
      unsigned char smooth                   : 1;
      unsigned char dontUseLightmaps         : 1;
      unsigned char texAniMap                : 1;
      unsigned char lodDontCollapse          : 1;
      unsigned char noCollDet                : 1;
      unsigned char polyListNeedsSort        : 1;
      unsigned char matUsage                 : 8;
      unsigned char libFlag                  : 8;
      zTRnd_AlphaBlendFunc rndAlphaBlendFunc : 8;
    };
    zCTexture* detailTexture;
    float detailTextureScale;
    zVEC2 texAniMapDelta;
    zVEC2 default_mapping;
    zVEC2 texScale;

    void zCMaterial_OnInit()                                                 zCall( 0x00565370 );
    void zCMaterial_OnInit( zSTRING const& )                                 zCall( 0x00565450 );
    void zCMaterial_OnInit( zCMaterial const& )                              zCall( 0x00565510 );
    zSTRING const& GetName() const                                           zCall( 0x00561220 );
    zCMaterial()                                                             zInit( zCMaterial_OnInit() );
    zCMaterial( zSTRING const& a0 )                                          zInit( zCMaterial_OnInit( a0 ));
    zCMaterial( zCMaterial const& a0 )                                       zInit( zCMaterial_OnInit( a0 ));
    zCMaterial& operator =( zCMaterial const& )                              zCall( 0x005655C0 );
    void InitThisByMaterial( zCMaterial const& )                             zCall( 0x005656A0 );
    void InitValues()                                                        zCall( 0x00565790 );
    void SetDetailObjectVisual( zSTRING const& )                             zCall( 0x00565870 );
    zSTRING const& GetDetailObjectVisual() const                             zCall( 0x00565A20 );
    void ApplyTexAniMapping( zCPolygon* )                                    zCall( 0x00565A30 );
    zVEC3 GetTexAniVector( zCPolygon* )                                      zCall( 0x00565AC0 );
    int IsPortalMaterial() const                                             zCall( 0x00565DE0 );
    void SetTexAniMappingDir( zVEC2 const& )                                 zCall( 0x00565ED0 );
    void SetTexture( zSTRING& )                                              zCall( 0x00565EF0 );
    void SetTexture( zCTexture* )                                            zCall( 0x00566070 );
    void SetDetailTexture( zSTRING& )                                        zCall( 0x005661A0 );
    void SetDetailTexture( zCTexture* )                                      zCall( 0x00566290 );
    void AutoAssignDetailTexture()                                           zCall( 0x005662E0 );
    zVEC2 GetTexScale()                                                      zCall( 0x005663F0 );
    void SetTexScale( zVEC2 )                                                zCall( 0x00566450 );
    void RemoveTexture()                                                     zCall( 0x00566470 );
    zSTRING const& GetTextureName()                                          zCall( 0x005664A0 );
    zSTRING const& GetMatGroupString() const                                 zCall( 0x005665C0 );
    void SetMatGroupByString( zSTRING const& )                               zCall( 0x00566610 );
    void RefreshAvgColorFromTexture()                                        zCall( 0x00566800 );
    zCTexture* GetAniTexture()                                               zCall( 0x00751320 );
    static zCObject* _CreateNewInstance()                                    zCall( 0x00565270 );
    static zCMaterial* SearchName( zSTRING& )                                zCall( 0x005664C0 );
    static zSTRING const& GetMatGroupString( zTMat_Group )                   zCall( 0x00566570 );
    virtual zCClassDef* _GetClassDef() const                                 zCall( 0x00565360 );
    virtual void Archive( zCArchiver& )                                      zCall( 0x00566850 );
    virtual void Unarchive( zCArchiver& )                                    zCall( 0x00566AF0 );
    virtual ~zCMaterial()                                                    zCall( 0x005655E0 );


    // static properties
    static unsigned char& s_matUsageDefault;

    // user API
    #include "zCMaterial.inl"
  };

} // namespace Gothic_I_Addon

#endif // __ZMATERIAL_H__VER1__