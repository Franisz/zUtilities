// Supported with union (c) 2018 Union team

#ifndef __OITEM_H__VER1__
#define __OITEM_H__VER1__

#include "oVob.h"
#include "zParser.h"
#include "z3d.h"
#include "zViewBase.h"
#include "oDamage.h"

namespace Gothic_I_Addon {
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
  const int ITM_FLAG_MI         = 1<<12;
  const int ITM_FLAG_DAG        = 1<<13;
  const int ITM_FLAG_SWD        = 1<<14;
  const int ITM_FLAG_AXE        = 1<<15;
  const int ITM_FLAG_2HD_SWD    = 1<<16;
  const int ITM_FLAG_2HD_AXE    = 1<<17;
  const int ITM_FLAG_SHIELD     = 1<<18;
  const int ITM_FLAG_BOW        = 1<<19;
  const int ITM_FLAG_CROSSBOW   = 1<<20;
  const int ITM_FLAG_STAFF      = 1<<23;
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
  const int ITM_FLAG_NFOCUS     = 1<<24;
  const int ITM_FLAGS_MAX       = 24;
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
    };
    int amount;
    int instanz;
    int c_manipulation;
    float last_manipulation;
    int magic_value;
    oCItem* next;

    void oCItem_OnInit()                                                                     zCall( 0x0069E6B0 );
    void oCItem_OnInit( zSTRING&, int )                                                      zCall( 0x0069E870 );
    void oCItem_OnInit( int, int )                                                           zCall( 0x0069E9B0 );
    zSTRING GetSchemeName()                                                                  zCall( 0x00635950 );
    oCItem()                                                                                 zInit( oCItem_OnInit() );
    oCItem( zSTRING& a0, int a1 )                                                            zInit( oCItem_OnInit( a0, a1 ));
    oCItem( int a0, int a1 )                                                                 zInit( oCItem_OnInit( a0, a1 ));
    void CreateVisual()                                                                      zCall( 0x0069ECF0 );
    void InitByScript( int, int )                                                            zCall( 0x0069EF80 );
    zSTRING& GetDescription()                                                                zCall( 0x0069F3D0 );
    zSTRING& GetText( int )                                                                  zCall( 0x0069F3E0 );
    int GetCount( int )                                                                      zCall( 0x0069F450 );
    int GetHealMode( int& )                                                                  zCall( 0x0069F470 );
    int GetProtectionByIndex( oEIndexDamage )                                                zCall( 0x0069F4F0 );
    int GetProtectionByType( oETypeDamage )                                                  zCall( 0x0069F500 );
    int GetProtectionByMode( unsigned long )                                                 zCall( 0x0069F5A0 );
    int GetFullProtection()                                                                  zCall( 0x0069F630 );
    void CopyDamage( oCItem* )                                                               zCall( 0x0069F650 );
    int GetDamageByIndex( oEIndexDamage )                                                    zCall( 0x0069F690 );
    int GetDamageByType( oETypeDamage )                                                      zCall( 0x0069F6A0 );
    int GetDamageByMode( unsigned long )                                                     zCall( 0x0069F740 );
    void GetDamages( unsigned long* )                                                        zCall( 0x0069F7D0 );
    int GetFullDamage()                                                                      zCall( 0x0069F7F0 );
    unsigned long GetDamageTypes()                                                           zCall( 0x0069F810 );
    int HasDamageType( oETypeDamage )                                                        zCall( 0x0069F820 );
    int IsDeadly()                                                                           zCall( 0x0069F840 );
    int IsOneHandWeapon()                                                                    zCall( 0x0069F860 );
    int MultiSlot()                                                                          zCall( 0x0069F890 );
    int GetValue()                                                                           zCall( 0x0069F8C0 );
    int GetWeight()                                                                          zCall( 0x0069F900 );
    int HasFlag( int )                                                                       zCall( 0x0069F920 );
    void ClearFlag( int )                                                                    zCall( 0x0069F940 );
    void SetFlag( int )                                                                      zCall( 0x0069F960 );
    int TwoHanded()                                                                          zCall( 0x0069F980 );
    int IsOwned( int, int )                                                                  zCall( 0x0069F9B0 );
    int GetDisguiseGuild()                                                                   zCall( 0x0069FA30 );
    int AddManipulation()                                                                    zCall( 0x0069FA40 );
    void Identify()                                                                          zCall( 0x0069FAC0 );
    zSTRING GetName( int )                                                                   zCall( 0x0069FAD0 );
    zSTRING GetStatus()                                                                      zCall( 0x0069FB20 );
    void UseItem()                                                                           zCall( 0x0069FCB0 );
    zSTRING GetVisualChange()                                                                zCall( 0x0069FCC0 );
    int GetStateEffectFunc( int )                                                            zCall( 0x0069FDE0 );
    oCItem* SplitItem( int )                                                                 zCall( 0x0069FE00 );
    void RotateForInventory( int )                                                           zCall( 0x0069FF20 );
    void RotateInInventory()                                                                 zCall( 0x006A03E0 );
    void RenderItem( int, int )                                                              zCall( 0x006A03F0 );
    void RenderItemPlaceCamera( zCCamera*, float )                                           zCall( 0x006A0820 );
    void RenderItem( zCWorld*, zCViewBase*, float )                                          zCall( 0x006A0A20 );
    static void SetLightingSwell( int )                                                      zCall( 0x0069E690 );
    static int GetLightingSwell()                                                            zCall( 0x0069E6A0 );
    static zCObject* _CreateNewInstance()                                                    zCall( 0x006A1200 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x0069E810 );
    virtual void Archive( zCArchiver& )                                                      zCall( 0x006A0CE0 );
    virtual void Unarchive( zCArchiver& )                                                    zCall( 0x006A0E30 );
    virtual ~oCItem()                                                                        zCall( 0x0069EAF0 );
    virtual int __fastcall Render( zTRenderContext& )                                        zCall( 0x006A0FC0 );
    virtual void SetVisual( zCVisual* )                                                      zCall( 0x0069ECD0 );
    virtual int GetScriptInstance( zSTRING*&, int& )                                         zCall( 0x006A0C30 );
    virtual int SetByScriptInstance( zSTRING const*, int )                                   zCall( 0x006A0C60 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                             zCall( 0x0069FE60 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                         zCall( 0x0069FF00 );
    virtual void Init()                                                                      zCall( 0x0069ED30 );
    virtual int GetInstance()                                                                zCall( 0x0069E820 );
    virtual zSTRING GetInstanceName()                                                        zCall( 0x006A0CA0 );
    virtual int IsOwnedByGuild( int )                                                        zCall( 0x0069FA10 );
    virtual int IsOwnedByNpc( int )                                                          zCall( 0x0069F9F0 );
    virtual oCAIVobMove* GetAIVobMove()                                                      zCall( 0x006A0EC0 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int ) zCall( 0x0069FAA0 );
    virtual oTSndMaterial GetSoundMaterial()                                                 zCall( 0x0069E830 );

    // user API
    #include "oCItem.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OITEM_H__VER1__