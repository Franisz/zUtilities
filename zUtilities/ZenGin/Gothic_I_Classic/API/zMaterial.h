// Supported with union (c) 2018 Union team

#ifndef __ZMATERIAL_H__VER0__
#define __ZMATERIAL_H__VER0__

namespace Gothic_I_Classic {

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

    void zCTexAniCtrl_OnInit()    zCall( 0x0054E9A0 );
    zCTexAniCtrl()                zInit( zCTexAniCtrl_OnInit() );
    void AdvanceAni( zCTexture* ) zCall( 0x0054E9C0 );

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

    void zCMaterial_OnInit()                                            zCall( 0x0054CFC0 );
    void zCMaterial_OnInit( zSTRING const& )                            zCall( 0x0054D0A0 );
    void zCMaterial_OnInit( zCMaterial const& )                         zCall( 0x0054D160 );
    zSTRING const& GetName() const                                      zCall( 0x00549250 );
    zCMaterial()                                                        zInit( zCMaterial_OnInit() );
    zCMaterial( zSTRING const& a0 )                                     zInit( zCMaterial_OnInit( a0 ));
    zCMaterial( zCMaterial const& a0 )                                  zInit( zCMaterial_OnInit( a0 ));
    zCMaterial& operator =( zCMaterial const& )                         zCall( 0x0054D210 );
    void InitThisByMaterial( zCMaterial const& )                        zCall( 0x0054D2F0 );
    void InitValues()                                                   zCall( 0x0054D3C0 );
    void SetDetailObjectVisual( zSTRING const& )                        zCall( 0x0054D4A0 );
    zSTRING const& GetDetailObjectVisual() const                        zCall( 0x0054D640 );
    void ApplyTexAniMapping( zCPolygon* )                               zCall( 0x0054D650 );
    zVEC3 GetTexAniVector( zCPolygon* )                                 zCall( 0x0054D6E0 );
    int IsPortalMaterial() const                                        zCall( 0x0054D9B0 );
    void SetTexAniMappingDir( zVEC2 const& )                            zCall( 0x0054DAA0 );
    void SetTexture( zSTRING& )                                         zCall( 0x0054DAC0 );
    void SetTexture( zCTexture* )                                       zCall( 0x0054DC30 );
    void SetDetailTexture( zSTRING& )                                   zCall( 0x0054DD60 );
    void SetDetailTexture( zCTexture* )                                 zCall( 0x0054DE40 );
    void AutoAssignDetailTexture()                                      zCall( 0x0054DE80 );
    zVEC2 GetTexScale()                                                 zCall( 0x0054DF80 );
    void SetTexScale( zVEC2 )                                           zCall( 0x0054DFE0 );
    void RemoveTexture()                                                zCall( 0x0054E000 );
    zSTRING const& GetTextureName()                                     zCall( 0x0054E030 );
    zSTRING const& GetMatGroupString() const                            zCall( 0x0054E150 );
    void SetMatGroupByString( zSTRING const& )                          zCall( 0x0054E1A0 );
    void RefreshAvgColorFromTexture()                                   zCall( 0x0054E360 );
    zCTexture* GetAniTexture()                                          zCall( 0x007154C0 );
    static zCObject* _CreateNewInstance()                               zCall( 0x0054CEC0 );
    static zCMaterial* SearchName( zSTRING& )                           zCall( 0x0054E050 );
    static zSTRING const& GetMatGroupString( zTMat_Group )              zCall( 0x0054E100 );
    virtual zCClassDef* _GetClassDef() const                            zCall( 0x0054CFB0 );
    virtual void Archive( zCArchiver& )                                 zCall( 0x0054E3B0 );
    virtual void Unarchive( zCArchiver& )                               zCall( 0x0054E640 );
    virtual ~zCMaterial()                                               zCall( 0x0054D230 );


    // static properties
    static unsigned char& s_matUsageDefault;

    // user API
    #include "zCMaterial.inl"
  };

} // namespace Gothic_I_Classic

#endif // __ZMATERIAL_H__VER0__