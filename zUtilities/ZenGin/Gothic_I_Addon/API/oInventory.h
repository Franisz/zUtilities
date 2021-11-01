// Supported with union (c) 2018-2021 Union team

#ifndef __OINVENTORY_H__VER1__
#define __OINVENTORY_H__VER1__

#include "zViewBase.h"
#include "zArchiver.h"

namespace Gothic_I_Addon {
   const int INV_MAX_NUM_ITEMS = 6;

  enum {
    INV_NONE,
    INV_COMBAT,
    INV_ARMOR,
    INV_RUNE,
    INV_MAGIC,
    INV_FOOD,
    INV_POTION,
    INV_DOCS,
    INV_OTHER,
    INV_MAX
  };

  // sizeof 9Ch
  class oCItemContainer : public zCInputCallback {
  public:
    enum oTItemListMode {
      FULLSCREEN,
      HALFSCREEN,
      ONE
    };

    zCListSort<oCItem>* contents;           // sizeof 04h    offset 04h
    oCNpc* npc;                             // sizeof 04h    offset 08h
    int selectedItem;                       // sizeof 04h    offset 0Ch
    int offset;                             // sizeof 04h    offset 10h
    int drawItemMax;                        // sizeof 04h    offset 14h
    oTItemListMode itemListMode;            // sizeof 04h    offset 18h
    int frame;                              // sizeof 04h    offset 1Ch
    int right;                              // sizeof 04h    offset 20h
    int ownList;                            // sizeof 04h    offset 24h
    int prepared;                           // sizeof 04h    offset 28h
    int passive;                            // sizeof 04h    offset 2Ch
    short TransferCount;                    // sizeof 02h    offset 30h
    zCView* viewCat;                        // sizeof 04h    offset 34h
    zCView* viewItem;                       // sizeof 04h    offset 38h
    zCView* viewItemActive;                 // sizeof 04h    offset 3Ch
    zCView* viewItemHightlighted;           // sizeof 04h    offset 40h
    zCView* viewItemActiveHighlighted;      // sizeof 04h    offset 44h
    zCView* viewItemFocus;                  // sizeof 04h    offset 48h
    zCView* viewItemActiveFocus;            // sizeof 04h    offset 4Ch
    zCView* viewItemHightlightedFocus;      // sizeof 04h    offset 50h
    zCView* viewItemActiveHighlightedFocus; // sizeof 04h    offset 54h
    zCView* viewItemInfo;                   // sizeof 04h    offset 58h
    zCView* viewItemInfoItem;               // sizeof 04h    offset 5Ch
    zCView* textView;                       // sizeof 04h    offset 60h
    zCView* viewArrowAtTop;                 // sizeof 04h    offset 64h
    zCView* viewArrowAtBottom;              // sizeof 04h    offset 68h
    zCWorld* rndWorld;                      // sizeof 04h    offset 6Ch
    int posx;                               // sizeof 04h    offset 70h
    int posy;                               // sizeof 04h    offset 74h
    zSTRING textCategoryStatic;             // sizeof 14h    offset 78h
    int m_bManipulateItemsDisabled;         // sizeof 04h    offset 8Ch
    int m_bCanTransferMoreThanOneItem;      // sizeof 04h    offset 90h
    zCOLOR image_chroma;                    // sizeof 04h    offset 94h
    zCOLOR blit_chroma;                     // sizeof 04h    offset 98h

    void oCItemContainer_OnInit()                              zCall( 0x00693B90 );
    oCItemContainer* GetNextContainerLeft( oCItemContainer* )  zCall( 0x00693A70 );
    oCItemContainer* GetNextContainerRight( oCItemContainer* ) zCall( 0x00693B00 );
    oCItemContainer()                                          zInit( oCItemContainer_OnInit() );
    zCListSort<oCItem>* JumpOffset( int&, int& )               zCall( 0x00694710 );
    zSTRING GetCategoryText( int )                             zCall( 0x006947C0 );
    int ActivateNextContainer( int )                           zCall( 0x006974E0 );
    static void Container_PrepareDraw()                        zCall( 0x00693A40 );
    static void Container_Draw()                               zCall( 0x00693A50 );
    virtual int HandleEvent( int )                             zCall( 0x00697960 );
    virtual ~oCItemContainer()                                 zCall( 0x00693E40 );
    virtual void Open( int, int, oTItemListMode )              zCall( 0x00695A10 );
    virtual void OpenPassive( int, int, oTItemListMode )       zCall( 0x00695BB0 );
    virtual void Close()                                       zCall( 0x00696770 );
    virtual void Activate()                                    zCall( 0x00696AE0 );
    virtual void Deactivate()                                  zCall( 0x00696CF0 );
    virtual int IsOpen()                                       zCall( 0x00696AC0 );
    virtual int IsActive()                                     zCall( 0x00693D90 );
    virtual int IsEmpty()                                      zCall( 0x006972A0 );
    virtual void SetContents( zCListSort<oCItem>* )            zCall( 0x006959C0 );
    virtual zCListSort<oCItem>* GetContents()                  zCall( 0x00695A00 );
    virtual oCItem* Insert( oCItem* )                          zCall( 0x00696DC0 );
    virtual void Remove( oCItem* )                             zCall( 0x00696E80 );
    virtual oCItem* Remove( oCItem*, int )                     zCall( 0x00696F30 );
    virtual oCItem* RemoveByPtr( oCItem*, int )                zCall( 0x00696F10 );
    virtual oCItem* GetSelectedItem()                          zCall( 0x00696D20 );
    virtual int GetSelectedItemCount()                         zCall( 0x00696D50 );
    virtual void GetSize( int&, int& )                         zCall( 0x006946D0 );
    virtual void DisableManipulateItems( int )                 zCall( 0x00693DA0 );
    virtual int CanManipulateItems()                           zCall( 0x00693DB0 );
    virtual void DisableTransferMoreThanOneItem( int )         zCall( 0x00693DC0 );
    virtual int CanTransferMoreThanOneItem()                   zCall( 0x00693DE0 );
    virtual int IsPassive()                                    zCall( 0x00696760 );
    virtual short GetTransferCount()                           zCall( 0x00693DF0 );
    virtual void SetTransferCount( short )                     zCall( 0x00693E00 );
    virtual void IncTransferCount( short )                     zCall( 0x00693E10 );
    virtual void Archive( zCArchiver& )                        zCall( 0x006975F0 );
    virtual void Unarchive( zCArchiver& )                      zCall( 0x00697790 );
    virtual void Init( int, int )                              zCall( 0x00694550 );
    virtual void Init( int, int, oTItemListMode )              zCall( 0x00694570 );
    virtual void GetPosition( int&, int& )                     zCall( 0x006946F0 );
    virtual void LoadGrafix()                                  zCall( 0x00693FA0 );
    virtual void DeleteContents()                              zCall( 0x00696FF0 );
    virtual void NextItem()                                    zCall( 0x00697100 );
    virtual void PrevItem()                                    zCall( 0x006971E0 );
    virtual void CheckSelectedItem()                           zCall( 0x006970C0 );
    virtual int TransferItem( int, int )                       zCall( 0x006972D0 );
    virtual void SetCategoryOnRightContainer()                 zCall( 0x00696B40 );
    virtual void Draw()                                        zCall( 0x00695040 );
    virtual void DrawCategory()                                zCall( 0x00694970 );
    virtual void DrawItemInfo( oCItem*, zCWorld* )             zCall( 0x00694AD0 );

    // static properties
    static zCList<oCItemContainer>& contList;
    static int& gfx_loaded;
    static zCGfx*& gfx_cat;
    static zCGfx*& gfx_equip;
    static zCGfx*& gfx_cursor;
    static zCGfx*& gfx_cursor_equip;
    static zCGfx**& gfx_arrow;

    // user API
    #include "oCItemContainer.inl"
  };

  // sizeof A0h
  class oCStealContainer : public oCItemContainer {
  public:
    oCNpc* owner; // sizeof 04h    offset 9Ch

    void oCStealContainer_OnInit()  zCall( 0x00697DA0 );
    oCStealContainer()              zInit( oCStealContainer_OnInit() );
    virtual int HandleEvent( int )  zCall( 0x00698100 );
    virtual ~oCStealContainer()     zCall( 0x00697DE0 );
    virtual void SetOwner( oCNpc* ) zCall( 0x00697F70 );
    virtual oCNpc* GetOwner()       zCall( 0x00697F90 );
    virtual void CreateList()       zCall( 0x00697FA0 );

    // user API
    #include "oCStealContainer.inl"
  };

  // sizeof A0h
  class oCNpcContainer : public oCStealContainer {
  public:

    void oCNpcContainer_OnInit()      zCall( 0x006983B0 );
    oCNpcContainer()                  zInit( oCNpcContainer_OnInit() );
    virtual int HandleEvent( int )    zCall( 0x00698730 );
    virtual ~oCNpcContainer()         zCall( 0x006983F0 );
    virtual oCItem* Insert( oCItem* ) zCall( 0x006989A0 );
    virtual void Remove( oCItem* )    zCall( 0x006989E0 );
    virtual void CreateList()         zCall( 0x00698570 );

    // user API
    #include "oCNpcContainer.inl"
  };

  // sizeof 234h
  class oCNpcInventory : public oCItemContainer {
  public:
    oCNpc* owner;                          // sizeof 04h    offset 9Ch
    int packAbility;                       // sizeof 04h    offset A0h
    zCListSort<oCItem> inventory[INV_MAX]; // sizeof 6Ch    offset A4h
    zSTRING packString[INV_MAX];           // sizeof B4h    offset 110h
    int _offset[INV_MAX];                  // sizeof 24h    offset 1C4h
    int _itemnr[INV_MAX];                  // sizeof 24h    offset 1E8h
    int maxSlots[INV_MAX];                 // sizeof 24h    offset 20Ch
    int invnr;                             // sizeof 04h    offset 230h

    void oCNpcInventory_OnInit()                             zCall( 0x00812FBB );
    oCNpcInventory()                                         zInit( oCNpcInventory_OnInit() );
    void ClearInventory()                                    zCall( 0x00699370 );
    void Open( int, int )                                    zCall( 0x00699500 );
    void SetOwner( oCNpc* )                                  zCall( 0x00699A20 );
    oCNpc* GetOwner()                                        zCall( 0x00699A30 );
    void SetFirstCategory()                                  zCall( 0x00699A40 );
    int GetCategory( oCItem* )                               zCall( 0x00699BB0 );
    int GetNumItemsInCategory( int )                         zCall( 0x00699C40 );
    oCItem* GetItem( int, int )                              zCall( 0x00699D70 );
    int GetAmount( int )                                     zCall( 0x0069A240 );
    int IsCatEmpty( int )                                    zCall( 0x0069AE60 );
    int GetNextCategory()                                    zCall( 0x0069B640 );
    int GetPrevCategory()                                    zCall( 0x0069B660 );
    int SwitchToCategory( int )                              zCall( 0x0069B670 );
    int SwitchNextCategory()                                 zCall( 0x0069B710 );
    int SwitchPrevCategory()                                 zCall( 0x0069B740 );
    int FindNextCategory()                                   zCall( 0x0069B760 );
    int HandleTrade( int )                                   zCall( 0x0069B970 );
    void CheckForEquippedItems( int )                        zCall( 0x0069CEA0 );
    int CanCarry( oCItem* )                                  zCall( 0x0069D000 );
    void SetPackAbility( int )                               zCall( 0x0069D200 );
    void UnpackCategory( int )                               zCall( 0x0069D240 );
    int GetNumItemsInPackString( int )                       zCall( 0x0069D270 );
    int GetPackedItemBySlot( int, int, zSTRING& )            zCall( 0x0069D370 );
    oCItem* CreateFromPackString( zSTRING const& )           zCall( 0x0069D4D0 );
    int GetPackedItemInfo( zSTRING const&, int, int&, int& ) zCall( 0x0069D560 );
    int PackSingleItem( oCItem* )                            zCall( 0x0069D7F0 );
    void PackAllItems( int )                                 zCall( 0x0069DBE0 );
    void UnpackAllItems()                                    zCall( 0x0069DC00 );
    void PackItemsInCategory( int, int )                     zCall( 0x0069DC20 );
    void UnpackItemsInCategory( int )                        zCall( 0x0069DF90 );
    virtual int HandleEvent( int )                           zCall( 0x0069BBC0 );
    virtual ~oCNpcInventory()                                zCall( 0x00699170 );
    virtual void Close()                                     zCall( 0x00699960 );
    virtual oCItem* Insert( oCItem* )                        zCall( 0x00699F50 );
    virtual oCItem* Remove( int, int )                       zCall( 0x0069ABA0 );
    virtual oCItem* Remove( zSTRING const&, int )            zCall( 0x0069ACB0 );
    virtual oCItem* RemoveByPtr( oCItem*, int )              zCall( 0x0069A680 );
    virtual void Archive( zCArchiver& )                      zCall( 0x0069AFB0 );
    virtual void Unarchive( zCArchiver& )                    zCall( 0x0069B2D0 );
    virtual void Draw()                                      zCall( 0x00699970 );
    virtual void DrawCategory()                              zCall( 0x0069B770 );
    virtual void Remove( oCItem* )                           zCall( 0x0069A580 );
    virtual oCItem* Remove( oCItem*, int )                   zCall( 0x0069A8D0 );
    virtual oCItem* IsIn( oCItem*, int )                     zCall( 0x0069A370 );
    virtual oCItem* IsIn( int, int )                         zCall( 0x0069A460 );
    virtual oCItem* IsIn( zSTRING const&, int )              zCall( 0x0069A430 );
    virtual int IsEmpty()                                    zCall( 0x006972A0 );
    virtual int IsEmpty( int )                               zCall( 0x0069ACE0 );

    // static properties
    static zCGfx**& gfx_cats;

    // user API
    #include "oCNpcInventory.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OINVENTORY_H__VER1__