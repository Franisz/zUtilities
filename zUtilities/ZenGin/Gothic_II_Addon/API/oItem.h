// Supported with union (c) 2018-2021 Union team

#ifndef __OITEM_H__VER3__
#define __OITEM_H__VER3__

#include "oVob.h"
#include "zParser.h"
#include "z3d.h"
#include "zViewBase.h"
#include "oDamage.h"

namespace Gothic_II_Addon {
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
  const int ITM_FLAG_DAG        = 1<<13;
  const int ITM_FLAG_SWD        = 1<<14;
  const int ITM_FLAG_AXE        = 1<<15;
  const int ITM_FLAG_2HD_SWD    = 1<<16;
  const int ITM_FLAG_2HD_AXE    = 1<<17;
  const int ITM_FLAG_SHIELD     = 1<<18;
  const int ITM_FLAG_BOW        = 1<<19;
  const int ITM_FLAG_CROSSBOW   = 1<<20;
  const int ITM_FLAG_RING       = 1<<11;
  const int ITM_FLAG_AMULET     = 1<<22;
  const int ITM_FLAG_BELT       = 1<<24;
  const int ITM_FLAG_DROPPED    = 1<<10;
  const int ITM_FLAG_MI         = 1<<12;
  const int ITM_FLAG_MULTI      = 1<<21;
  const int ITM_FLAG_NFOCUS     = 1<<23;
  const int ITM_FLAG_CREATEAMMO = 1<<25;
  const int ITM_FLAG_NSPLIT     = 1<<26;
  const int ITM_FLAG_DRINK      = 1<<27;
  const int ITM_FLAG_TORCH      = 1<<28;
  const int ITM_FLAG_THROW      = 1<<29;
  const int ITM_FLAG_ACTIVE     = 1<<30;
  const int ITM_COND_MAX        = 3;
  const int ITM_STATE_MAX       = 4;
  const int ITM_TEXT_MAX        = 6;

  enum {
    ITM_WEAR_NO,
    ITM_WEAR_TORSO,
    ITM_WEAR_HEAD,
    ITM_WEAR_LIGHT = 8
  };

  // sizeof 348h
  class oCItem : public oCVob {
  public:
    zCLASS_DECLARATION( oCItem )

    group {
      int idx;                           // sizeof 04h    offset 120h
      zSTRING name;                      // sizeof 14h    offset 124h
      zSTRING nameID;                    // sizeof 14h    offset 138h
      int hitp;                          // sizeof 04h    offset 14Ch
      int max_hitp;                      // sizeof 04h    offset 150h
      int mainflag;                      // sizeof 04h    offset 154h
      int flags;                         // sizeof 04h    offset 158h
      int weight;                        // sizeof 04h    offset 15Ch
      int value;                         // sizeof 04h    offset 160h
      unsigned long damageTypes;         // sizeof 04h    offset 164h
      int damageTotal;                   // sizeof 04h    offset 168h
      int damage[oEDamageIndex_MAX];     // sizeof 20h    offset 16Ch
      int wear;                          // sizeof 04h    offset 18Ch
      int protection[oEDamageIndex_MAX]; // sizeof 20h    offset 190h
      int nutrition;                     // sizeof 04h    offset 1B0h
      int cond_atr[ITM_COND_MAX];        // sizeof 0Ch    offset 1B4h
      int cond_value[ITM_COND_MAX];      // sizeof 0Ch    offset 1C0h
      int change_atr[ITM_COND_MAX];      // sizeof 0Ch    offset 1CCh
      int change_value[ITM_COND_MAX];    // sizeof 0Ch    offset 1D8h
      int magic;                         // sizeof 04h    offset 1E4h
      int on_equip;                      // sizeof 04h    offset 1E8h
      int on_unequip;                    // sizeof 04h    offset 1ECh
      int onState[ITM_STATE_MAX];        // sizeof 10h    offset 1F0h
      int owner;                         // sizeof 04h    offset 200h
      int ownerGuild;                    // sizeof 04h    offset 204h
      int disguiseGuild;                 // sizeof 04h    offset 208h
      zSTRING file;                      // sizeof 14h    offset 20Ch
      zSTRING visual_change;             // sizeof 14h    offset 220h
      zSTRING effectName;                // sizeof 14h    offset 234h
      int visual_skin;                   // sizeof 04h    offset 248h
      zSTRING scemeName;                 // sizeof 14h    offset 24Ch
      oTSndMaterial sndMat;              // sizeof 04h    offset 260h
      int munition;                      // sizeof 04h    offset 264h
      int spell;                         // sizeof 04h    offset 268h
      int range;                         // sizeof 04h    offset 26Ch
      int mag_circle;                    // sizeof 04h    offset 270h
      zSTRING description;               // sizeof 14h    offset 274h
      zSTRING text[ITM_TEXT_MAX];        // sizeof 78h    offset 288h
      int count[ITM_TEXT_MAX];           // sizeof 18h    offset 300h
      int inv_zbias;                     // sizeof 04h    offset 318h
      int inv_rotx;                      // sizeof 04h    offset 31Ch
      int inv_roty;                      // sizeof 04h    offset 320h
      int inv_rotz;                      // sizeof 04h    offset 324h
      int inv_animate;                   // sizeof 04h    offset 328h
    };
    int amount;                          // sizeof 04h    offset 32Ch
    int instanz;                         // sizeof 04h    offset 330h
    int c_manipulation;                  // sizeof 04h    offset 334h
    float last_manipulation;             // sizeof 04h    offset 338h
    int magic_value;                     // sizeof 04h    offset 33Ch
    oCVisualFX* effectVob;               // sizeof 04h    offset 340h
    oCItem* next;                        // sizeof 04h    offset 344h

    void oCItem_OnInit()                                                                     zCall( 0x00711290 );
    void oCItem_OnInit( zSTRING&, int )                                                      zCall( 0x00711470 );
    void oCItem_OnInit( int, int )                                                           zCall( 0x007115D0 );
    zSTRING GetSchemeName()                                                                  zCall( 0x00698E50 );
    oCItem()                                                                                 zInit( oCItem_OnInit() );
    oCItem( zSTRING& a0, int a1 )                                                            zInit( oCItem_OnInit( a0, a1 ));
    oCItem( int a0, int a1 )                                                                 zInit( oCItem_OnInit( a0, a1 ));
    void CreateVisual()                                                                      zCall( 0x00711930 );
    void InitByScript( int, int )                                                            zCall( 0x00711BD0 );
    zSTRING& GetDescription()                                                                zCall( 0x007120E0 );
    zSTRING& GetText( int )                                                                  zCall( 0x007120F0 );
    int GetCount( int )                                                                      zCall( 0x00712160 );
    int GetHealMode( int& )                                                                  zCall( 0x00712180 );
    int GetProtectionByIndex( oEIndexDamage )                                                zCall( 0x00712200 );
    int GetProtectionByType( oETypeDamage )                                                  zCall( 0x00712210 );
    int GetProtectionByMode( unsigned long )                                                 zCall( 0x007122B0 );
    int GetFullProtection()                                                                  zCall( 0x00712340 );
    void CopyDamage( oCItem* )                                                               zCall( 0x00712360 );
    int GetDamageByIndex( oEIndexDamage )                                                    zCall( 0x007123A0 );
    int GetDamageByType( oETypeDamage )                                                      zCall( 0x007123B0 );
    int GetDamageByMode( unsigned long )                                                     zCall( 0x00712450 );
    void GetDamages( unsigned long* )                                                        zCall( 0x007124E0 );
    int GetFullDamage()                                                                      zCall( 0x00712500 );
    unsigned long GetDamageTypes()                                                           zCall( 0x00712520 );
    int HasDamageType( oETypeDamage )                                                        zCall( 0x00712530 );
    int IsDeadly()                                                                           zCall( 0x00712550 );
    int IsOneHandWeapon()                                                                    zCall( 0x00712570 );
    int MultiSlot()                                                                          zCall( 0x007125A0 );
    int SplitSlot()                                                                          zCall( 0x00712610 );
    int GetValue()                                                                           zCall( 0x00712650 );
    int GetWeight()                                                                          zCall( 0x007126B0 );
    int HasFlag( int )                                                                       zCall( 0x007126D0 );
    void ClearFlag( int )                                                                    zCall( 0x007126F0 );
    void SetFlag( int )                                                                      zCall( 0x00712710 );
    int TwoHanded()                                                                          zCall( 0x00712730 );
    int IsOwned( int, int )                                                                  zCall( 0x00712760 );
    int GetDisguiseGuild()                                                                   zCall( 0x007127E0 );
    int AddManipulation()                                                                    zCall( 0x007127F0 );
    void Identify()                                                                          zCall( 0x00712870 );
    zSTRING GetName( int )                                                                   zCall( 0x00712880 );
    zSTRING GetStatus()                                                                      zCall( 0x007128D0 );
    void UseItem()                                                                           zCall( 0x00712A30 );
    zSTRING GetVisualChange()                                                                zCall( 0x00712A40 );
    zSTRING GetEffectName()                                                                  zCall( 0x00712B30 );
    int GetStateEffectFunc( int )                                                            zCall( 0x00712B80 );
    oCItem* SplitItem( int )                                                                 zCall( 0x00712BA0 );
    void RemoveEffect()                                                                      zCall( 0x00712C00 );
    void InsertEffect()                                                                      zCall( 0x00712C40 );
    void RotateForInventory( int )                                                           zCall( 0x00712F10 );
    void RotateInInventory()                                                                 zCall( 0x007132E0 );
    void RenderItem( int, int )                                                              zCall( 0x007133C0 );
    void RenderItemPlaceCamera( zCCamera*, float )                                           zCall( 0x00713800 );
    void RenderItem( zCWorld*, zCViewBase*, float )                                          zCall( 0x00713AC0 );
    static void SetLightingSwell( int )                                                      zCall( 0x00711270 );
    static int GetLightingSwell()                                                            zCall( 0x00711280 );
    static zCObject* _CreateNewInstance()                                                    zCall( 0x00714440 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x00711410 );
    virtual void Archive( zCArchiver& )                                                      zCall( 0x00713D70 );
    virtual void Unarchive( zCArchiver& )                                                    zCall( 0x00713EB0 );
    virtual ~oCItem()                                                                        zCall( 0x00711730 );
    virtual int __fastcall Render( zTRenderContext& )                                        zCall( 0x00714020 );
    virtual void SetVisual( zCVisual* )                                                      zCall( 0x00711910 );
    virtual int GetScriptInstance( zSTRING*&, int& )                                         zCall( 0x00713CC0 );
    virtual int SetByScriptInstance( zSTRING const*, int )                                   zCall( 0x00713CF0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                             zCall( 0x00712DF0 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                         zCall( 0x00712EA0 );
    virtual void Init()                                                                      zCall( 0x00711970 );
    virtual int GetInstance()                                                                zCall( 0x00711420 );
    virtual zSTRING GetInstanceName()                                                        zCall( 0x00713D30 );
    virtual int IsOwnedByGuild( int )                                                        zCall( 0x007127C0 );
    virtual int IsOwnedByNpc( int )                                                          zCall( 0x007127A0 );
    virtual oCAIVobMove* GetAIVobMove()                                                      zCall( 0x00713F40 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int ) zCall( 0x00712850 );
    virtual oTSndMaterial GetSoundMaterial()                                                 zCall( 0x00711430 );

    // static properties
    static int& s_bItemEffectEnabled;
    static float& s_fGlobalItemZBiasScale;

    // user API
    #include "oCItem.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OITEM_H__VER3__