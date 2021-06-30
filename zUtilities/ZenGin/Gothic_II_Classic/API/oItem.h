// Supported with union (c) 2018 Union team

#ifndef __OITEM_H__VER2__
#define __OITEM_H__VER2__

#include "oVob.h"
#include "zParser.h"
#include "z3d.h"
#include "zViewBase.h"
#include "oDamage.h"

namespace Gothic_II_Classic {
  const int ITM_CAT_NONE        = 1<<0;
  const int ITM_CAT_NF          = 1<<1;
  const int ITM_CAT_FF          = 1<<2;
  const int ITM_CAT_MUN         = 1<<3;
  const int ITM_CAT_ARMOR       = 1<<4;
  const int ITM_CAT_FOOD        = 1<<5;
  const int ITM_CAT_DOCS        = 1<<6;
  const int ITM_CAT_POTION      = 1<<7;
  const int ITM_CAT_LIGHT       = 1<<8;
  const int ITM_CAT_RUNE        = 1<<9;
  const int ITM_CAT_MAGIC       = 1<<31;
  const int ITM_FLAG_BB         = 1<<10;
  const int ITM_FLAG_DROPPED    = 1<<11;
  const int ITM_FLAG_MI         = 1<<12;
  const int ITM_FLAG_DAG        = 1<<13;
  const int ITM_FLAG_SWD        = 1<<14;
  const int ITM_FLAG_AXE        = 1<<15;
  const int ITM_FLAG_2HD_SWD    = 1<<16;
  const int ITM_FLAG_2HD_AXE    = 1<<17;
  const int ITM_FLAG_SHIELD     = 1<<18;
  const int ITM_FLAG_BOW        = 1<<19;
  const int ITM_FLAG_CROSSBOW   = 1<<20;
  const int ITM_FLAG_MULTI      = 1<<21;
  const int ITM_FLAG_RING       = 1<<11;
  const int ITM_FLAG_AMULET     = 1<<22;
  const int ITM_FLAG_CREATEAMMO = 1<<25;
  const int ITM_FLAG_EAT        = 1<<26;
  const int ITM_FLAG_DRINK      = 1<<27;
  const int ITM_FLAG_TORCH      = 1<<28;
  const int ITM_FLAG_THROW      = 1<<29;
  const int ITM_FLAG_ACTIVE     = 1<<30;
  const int ITM_FLAG_MG         = 1<<21;
  const int ITM_FLAG_NFOCUS     = 1<<23;
  const int ITM_FLAGS_MAX       = 22;
  const int ITM_STATE_MAX       = 4;
  const int ITM_TEXT_MAX        = 6;
  const int ITM_COND_MAX        = 3;

  enum {
    ITM_WEAR_NO,
    ITM_WEAR_TORSO,
    ITM_WEAR_HEAD,
    ITM_WEAR_LIGHT = 8
  };

  class oCItem : public oCVob {
  public:
    zCLASS_DECLARATION( oCItem )

    group {
      int idx;
      zSTRING name;
      zSTRING nameID;
      int hitp;
      int max_hitp;
      int mainflag;
      int flags;
      int weight;
      int value;
      unsigned long damageTypes;
      int damageTotal;
      int damage[oEDamageIndex_MAX];
      int wear;
      int protection[oEDamageIndex_MAX];
      int nutrition;
      int cond_atr[ITM_COND_MAX];
      int cond_value[ITM_COND_MAX];
      int change_atr[ITM_COND_MAX];
      int change_value[ITM_COND_MAX];
      int magic;
      int on_equip;
      int on_unequip;
      int onState[ITM_STATE_MAX];
      int owner;
      int ownerGuild;
      int disguiseGuild;
      zSTRING file;
      zSTRING visual_change;
      int visual_skin;
      zSTRING scemeName;
      oTSndMaterial sndMat;
      int munition;
      int spell;
      int range;
      int mag_circle;
      zSTRING description;
      zSTRING text[ITM_TEXT_MAX];
      int count[ITM_TEXT_MAX];
      int inv_zbias;
      int inv_rotx;
      int inv_roty;
      int inv_rotz;
      int inv_animate;
    };
    int amount;
    int instanz;
    int c_manipulation;
    float last_manipulation;
    int magic_value;
    oCItem* next;

    void oCItem_OnInit()                                                                     zCall( 0x006B35F0 );
    void oCItem_OnInit( zSTRING&, int )                                                      zCall( 0x006B37B0 );
    void oCItem_OnInit( int, int )                                                           zCall( 0x006B38F0 );
    zSTRING GetSchemeName()                                                                  zCall( 0x0063C5E0 );
    oCItem()                                                                                 zInit( oCItem_OnInit() );
    oCItem( zSTRING& a0, int a1 )                                                            zInit( oCItem_OnInit( a0, a1 ));
    oCItem( int a0, int a1 )                                                                 zInit( oCItem_OnInit( a0, a1 ));
    void CreateVisual()                                                                      zCall( 0x006B3C00 );
    void InitByScript( int, int )                                                            zCall( 0x006B3EA0 );
    zSTRING& GetDescription()                                                                zCall( 0x006B43B0 );
    zSTRING& GetText( int )                                                                  zCall( 0x006B43C0 );
    int GetCount( int )                                                                      zCall( 0x006B4430 );
    int GetHealMode( int& )                                                                  zCall( 0x006B4450 );
    int GetProtectionByIndex( oEIndexDamage )                                                zCall( 0x006B44D0 );
    int GetProtectionByType( oETypeDamage )                                                  zCall( 0x006B44E0 );
    int GetProtectionByMode( unsigned long )                                                 zCall( 0x006B4580 );
    int GetFullProtection()                                                                  zCall( 0x006B4610 );
    void CopyDamage( oCItem* )                                                               zCall( 0x006B4630 );
    int GetDamageByIndex( oEIndexDamage )                                                    zCall( 0x006B4670 );
    int GetDamageByType( oETypeDamage )                                                      zCall( 0x006B4680 );
    int GetDamageByMode( unsigned long )                                                     zCall( 0x006B4720 );
    void GetDamages( unsigned long* )                                                        zCall( 0x006B47B0 );
    int GetFullDamage()                                                                      zCall( 0x006B47D0 );
    unsigned long GetDamageTypes()                                                           zCall( 0x006B47F0 );
    int HasDamageType( oETypeDamage )                                                        zCall( 0x006B4800 );
    int IsDeadly()                                                                           zCall( 0x006B4820 );
    int IsOneHandWeapon()                                                                    zCall( 0x006B4840 );
    int MultiSlot()                                                                          zCall( 0x006B4870 );
    int GetValue()                                                                           zCall( 0x006B48A0 );
    int GetWeight()                                                                          zCall( 0x006B4900 );
    int HasFlag( int )                                                                       zCall( 0x006B4920 );
    void ClearFlag( int )                                                                    zCall( 0x006B4940 );
    void SetFlag( int )                                                                      zCall( 0x006B4960 );
    int TwoHanded()                                                                          zCall( 0x006B4980 );
    int IsOwned( int, int )                                                                  zCall( 0x006B49B0 );
    int GetDisguiseGuild()                                                                   zCall( 0x006B4A30 );
    int AddManipulation()                                                                    zCall( 0x006B4A40 );
    void Identify()                                                                          zCall( 0x006B4AC0 );
    zSTRING GetName( int )                                                                   zCall( 0x006B4AD0 );
    zSTRING GetStatus()                                                                      zCall( 0x006B4B20 );
    void UseItem()                                                                           zCall( 0x006B4C80 );
    zSTRING GetVisualChange()                                                                zCall( 0x006B4C90 );
    int GetStateEffectFunc( int )                                                            zCall( 0x006B4D80 );
    oCItem* SplitItem( int )                                                                 zCall( 0x006B4DA0 );
    void RotateForInventory( int )                                                           zCall( 0x006B4EC0 );
    void RotateInInventory()                                                                 zCall( 0x006B5290 );
    void RenderItem( int, int )                                                              zCall( 0x006B5370 );
    void RenderItemPlaceCamera( zCCamera*, float )                                           zCall( 0x006B57A0 );
    void RenderItem( zCWorld*, zCViewBase*, float )                                          zCall( 0x006B5A30 );
    static void SetLightingSwell( int )                                                      zCall( 0x006B35D0 );
    static int GetLightingSwell()                                                            zCall( 0x006B35E0 );
    static zCObject* _CreateNewInstance()                                                    zCall( 0x006B63B0 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x006B3750 );
    virtual void Archive( zCArchiver& )                                                      zCall( 0x006B5CE0 );
    virtual void Unarchive( zCArchiver& )                                                    zCall( 0x006B5E20 );
    virtual ~oCItem()                                                                        zCall( 0x006B3A30 );
    virtual int __fastcall Render( zTRenderContext& )                                        zCall( 0x006B5F90 );
    virtual void SetVisual( zCVisual* )                                                      zCall( 0x006B3BE0 );
    virtual int GetScriptInstance( zSTRING*&, int& )                                         zCall( 0x006B5C30 );
    virtual int SetByScriptInstance( zSTRING const*, int )                                   zCall( 0x006B5C60 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                             zCall( 0x006B4E00 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                         zCall( 0x006B4EA0 );
    virtual void Init()                                                                      zCall( 0x006B3C40 );
    virtual int GetInstance()                                                                zCall( 0x006B3760 );
    virtual zSTRING GetInstanceName()                                                        zCall( 0x006B5CA0 );
    virtual int IsOwnedByGuild( int )                                                        zCall( 0x006B4A10 );
    virtual int IsOwnedByNpc( int )                                                          zCall( 0x006B49F0 );
    virtual oCAIVobMove* GetAIVobMove()                                                      zCall( 0x006B5EB0 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int ) zCall( 0x006B4AA0 );
    virtual oTSndMaterial GetSoundMaterial()                                                 zCall( 0x006B3770 );

    // static properties
    static float& s_fGlobalItemZBiasScale;

    // user API
    #include "oCItem.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OITEM_H__VER2__