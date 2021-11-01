// Supported with union (c) 2018-2021 Union team

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

  // sizeof 14h
  class zCTexAniCtrl {
  public:
    int aniChannel;         // sizeof 04h    offset 00h
    float actFrame;         // sizeof 04h    offset 04h
    float aniFPS;           // sizeof 04h    offset 08h
    unsigned long frameCtr; // sizeof 04h    offset 0Ch
    int bOneShotAni;        // sizeof 04h    offset 10h

    void zCTexAniCtrl_OnInit()    zCall( 0x00566EB0 );
    zCTexAniCtrl()                zInit( zCTexAniCtrl_OnInit() );
    void AdvanceAni( zCTexture* ) zCall( 0x00566ED0 );

    // static properties
    static unsigned long& masterFrameCtr;

    // user API
    #include "zCTexAniCtrl.inl"
  };

  // sizeof 94h
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
    group {
      unsigned char smooth                   : 1; // sizeof 01h    offset bit
      unsigned char dontUseLightmaps         : 1; // sizeof 01h    offset bit
      unsigned char texAniMap                : 1; // sizeof 01h    offset bit
      unsigned char lodDontCollapse          : 1; // sizeof 01h    offset bit
      unsigned char noCollDet                : 1; // sizeof 01h    offset bit
      unsigned char polyListNeedsSort        : 1; // sizeof 01h    offset bit
      unsigned char matUsage                 : 8; // sizeof 08h    offset bit
      unsigned char libFlag                  : 8; // sizeof 08h    offset bit
      zTRnd_AlphaBlendFunc rndAlphaBlendFunc : 8; // sizeof 08h    offset bit
    };
    zCTexture* detailTexture;                     // sizeof 04h    offset 74h
    float detailTextureScale;                     // sizeof 04h    offset 78h
    zVEC2 texAniMapDelta;                         // sizeof 08h    offset 7Ch
    zVEC2 default_mapping;                        // sizeof 08h    offset 84h
    zVEC2 texScale;                               // sizeof 08h    offset 8Ch

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