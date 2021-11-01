// Supported with union (c) 2018-2021 Union team

#ifndef __OITEM_H__VER0__
#define __OITEM_H__VER0__

#include "oVob.h"
#include "zParser.h"
#include "z3d.h"
#include "zViewBase.h"
#include "oDamage.h"

namespace Gothic_I_Classic {
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

  // sizeof 2FCh
  class oCItem : public oCVob {
  public:
    zCLASS_DECLARATION( oCItem )

    group {
      int idx;                           // sizeof 04h    offset 100h
      zSTRING name;                      // sizeof 14h    offset 104h
      zSTRING nameID;                    // sizeof 14h    offset 118h
      int hitp;                          // sizeof 04h    offset 12Ch
      int max_hitp;                      // sizeof 04h    offset 130h
      int mainflag;                      // sizeof 04h    offset 134h
      int flags;                         // sizeof 04h    offset 138h
      int weight;                        // sizeof 04h    offset 13Ch
      int value;                         // sizeof 04h    offset 140h
      unsigned long damageTypes;         // sizeof 04h    offset 144h
      int damageTotal;                   // sizeof 04h    offset 148h
      int damage[oEDamageIndex_MAX];     // sizeof 20h    offset 14Ch
      int wear;                          // sizeof 04h    offset 16Ch
      int protection[oEDamageIndex_MAX]; // sizeof 20h    offset 170h
      int nutrition;                     // sizeof 04h    offset 190h
      int cond_atr[ITM_COND_MAX];        // sizeof 0Ch    offset 194h
      int cond_value[ITM_COND_MAX];      // sizeof 0Ch    offset 1A0h
      int change_atr[ITM_COND_MAX];      // sizeof 0Ch    offset 1ACh
      int change_value[ITM_COND_MAX];    // sizeof 0Ch    offset 1B8h
      int magic;                         // sizeof 04h    offset 1C4h
      int on_equip;                      // sizeof 04h    offset 1C8h
      int on_unequip;                    // sizeof 04h    offset 1CCh
      int onState[ITM_STATE_MAX];        // sizeof 10h    offset 1D0h
      int owner;                         // sizeof 04h    offset 1E0h
      int ownerGuild;                    // sizeof 04h    offset 1E4h
      int disguiseGuild;                 // sizeof 04h    offset 1E8h
      zSTRING file;                      // sizeof 14h    offset 1ECh
      zSTRING visual_change;             // sizeof 14h    offset 200h
      int visual_skin;                   // sizeof 04h    offset 214h
      zSTRING scemeName;                 // sizeof 14h    offset 218h
      oTSndMaterial sndMat;              // sizeof 04h    offset 22Ch
      int munition;                      // sizeof 04h    offset 230h
      int spell;                         // sizeof 04h    offset 234h
      int range;                         // sizeof 04h    offset 238h
      int mag_circle;                    // sizeof 04h    offset 23Ch
      zSTRING description;               // sizeof 14h    offset 240h
      zSTRING text[ITM_TEXT_MAX];        // sizeof 78h    offset 254h
      int count[ITM_TEXT_MAX];           // sizeof 18h    offset 2CCh
    };
    int amount;                          // sizeof 04h    offset 2E4h
    int instanz;                         // sizeof 04h    offset 2E8h
    int c_manipulation;                  // sizeof 04h    offset 2ECh
    float last_manipulation;             // sizeof 04h    offset 2F0h
    int magic_value;                     // sizeof 04h    offset 2F4h
    oCItem* next;                        // sizeof 04h    offset 2F8h

    void oCItem_OnInit()                                                                     zCall( 0x00670DE0 );
    void oCItem_OnInit( zSTRING&, int )                                                      zCall( 0x00670FA0 );
    void oCItem_OnInit( int, int )                                                           zCall( 0x006710E0 );
    zSTRING GetSchemeName()                                                                  zCall( 0x006127F0 );
    oCItem()                                                                                 zInit( oCItem_OnInit() );
    oCItem( zSTRING& a0, int a1 )                                                            zInit( oCItem_OnInit( a0, a1 ));
    oCItem( int a0, int a1 )                                                                 zInit( oCItem_OnInit( a0, a1 ));
    void CreateVisual()                                                                      zCall( 0x006713F0 );
    void InitByScript( int, int )                                                            zCall( 0x00671660 );
    zSTRING& GetDescription()                                                                zCall( 0x00671A70 );
    zSTRING& GetText( int )                                                                  zCall( 0x00671A80 );
    int GetCount( int )                                                                      zCall( 0x00671AF0 );
    int GetHealMode( int& )                                                                  zCall( 0x00671B10 );
    int GetProtectionByIndex( oEIndexDamage )                                                zCall( 0x00671B90 );
    int GetProtectionByType( oETypeDamage )                                                  zCall( 0x00671BA0 );
    int GetProtectionByMode( unsigned long )                                                 zCall( 0x00671C40 );
    int GetFullProtection()                                                                  zCall( 0x00671CD0 );
    void CopyDamage( oCItem* )                                                               zCall( 0x00671CF0 );
    int GetDamageByIndex( oEIndexDamage )                                                    zCall( 0x00671D30 );
    int GetDamageByType( oETypeDamage )                                                      zCall( 0x00671D40 );
    int GetDamageByMode( unsigned long )                                                     zCall( 0x00671DE0 );
    void GetDamages( unsigned long* )                                                        zCall( 0x00671E70 );
    int GetFullDamage()                                                                      zCall( 0x00671E90 );
    unsigned long GetDamageTypes()                                                           zCall( 0x00671EB0 );
    int HasDamageType( oETypeDamage )                                                        zCall( 0x00671EC0 );
    int IsDeadly()                                                                           zCall( 0x00671EE0 );
    int IsOneHandWeapon()                                                                    zCall( 0x00671F00 );
    int MultiSlot()                                                                          zCall( 0x00671F30 );
    int GetValue()                                                                           zCall( 0x00671F60 );
    int GetWeight()                                                                          zCall( 0x00671FA0 );
    int HasFlag( int )                                                                       zCall( 0x00671FC0 );
    void ClearFlag( int )                                                                    zCall( 0x00671FE0 );
    void SetFlag( int )                                                                      zCall( 0x00672000 );
    int TwoHanded()                                                                          zCall( 0x00672020 );
    int IsOwned( int, int )                                                                  zCall( 0x00672050 );
    int GetDisguiseGuild()                                                                   zCall( 0x006720D0 );
    int AddManipulation()                                                                    zCall( 0x006720E0 );
    void Identify()                                                                          zCall( 0x00672160 );
    zSTRING GetName( int )                                                                   zCall( 0x00672170 );
    zSTRING GetStatus()                                                                      zCall( 0x006721C0 );
    void UseItem()                                                                           zCall( 0x00672320 );
    zSTRING GetVisualChange()                                                                zCall( 0x00672330 );
    int GetStateEffectFunc( int )                                                            zCall( 0x00672420 );
    oCItem* SplitItem( int )                                                                 zCall( 0x00672440 );
    void RotateForInventory( int )                                                           zCall( 0x00672560 );
    void RotateInInventory()                                                                 zCall( 0x00672910 );
    void RenderItem( int, int )                                                              zCall( 0x00672920 );
    void RenderItemPlaceCamera( zCCamera*, float )                                           zCall( 0x00672D80 );
    void RenderItem( zCWorld*, zCViewBase*, float )                                          zCall( 0x00672F70 );
    static void SetLightingSwell( int )                                                      zCall( 0x00670DC0 );
    static int GetLightingSwell()                                                            zCall( 0x00670DD0 );
    static zCObject* _CreateNewInstance()                                                    zCall( 0x00673720 );
    virtual zCClassDef* _GetClassDef() const                                                 zCall( 0x00670F40 );
    virtual void Archive( zCArchiver& )                                                      zCall( 0x00673230 );
    virtual void Unarchive( zCArchiver& )                                                    zCall( 0x00673370 );
    virtual ~oCItem()                                                                        zCall( 0x00671220 );
    virtual int __fastcall Render( zTRenderContext& )                                        zCall( 0x006734F0 );
    virtual void SetVisual( zCVisual* )                                                      zCall( 0x006713D0 );
    virtual int GetScriptInstance( zSTRING*&, int& )                                         zCall( 0x00673180 );
    virtual int SetByScriptInstance( zSTRING const*, int )                                   zCall( 0x006731B0 );
    virtual void ThisVobAddedToWorld( zCWorld* )                                             zCall( 0x006724A0 );
    virtual void ThisVobRemovedFromWorld( zCWorld* )                                         zCall( 0x00672540 );
    virtual void Init()                                                                      zCall( 0x00671430 );
    virtual int GetInstance()                                                                zCall( 0x00670F50 );
    virtual zSTRING GetInstanceName()                                                        zCall( 0x006731F0 );
    virtual int IsOwnedByGuild( int )                                                        zCall( 0x006720B0 );
    virtual int IsOwnedByNpc( int )                                                          zCall( 0x00672090 );
    virtual oCAIVobMove* GetAIVobMove()                                                      zCall( 0x00673400 );
    virtual void GetSoundMaterial_AM( zCSoundManager::zTSndManMedium&, oTSndMaterial&, int ) zCall( 0x00672140 );
    virtual oTSndMaterial GetSoundMaterial()                                                 zCall( 0x00670F60 );

    // user API
    #include "oCItem.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OITEM_H__VER0__