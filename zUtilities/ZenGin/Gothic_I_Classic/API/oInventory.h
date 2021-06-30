// Supported with union (c) 2018 Union team

#ifndef __OINVENTORY_H__VER0__
#define __OINVENTORY_H__VER0__

#include "zViewBase.h"
#include "zView.h"
#include "zArchiver.h"

namespace Gothic_I_Classic {
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

  class oCItemContainer : public zCInputCallback {
  public:
    enum oTItemListMode {
      FULLSCREEN,
      HALFSCREEN,
      ONE
    };

    zCListSort<oCItem>* contents;
    oCNpc* npc;
    int selectedItem;
    int offset;
    int drawItemMax;
    oTItemListMode itemListMode;
    int frame;
    int right;
    int ownList;
    int prepared;
    int passive;
    zCView* viewCat;
    zCView* viewItem;
    zCView* viewItemActive;
    zCView* viewItemHightlighted;
    zCView* viewItemActiveHighlighted;
    zCView* viewItemFocus;
    zCView* viewItemActiveFocus;
    zCView* viewItemHightlightedFocus;
    zCView* viewItemActiveHighlightedFocus;
    zCView* viewItemInfo;
    zCView* viewItemInfoItem;
    zCView* textView;
    zCView* viewArrowAtTop;
    zCView* viewArrowAtBottom;
    zCWorld* rndWorld;
    int posx;
    int posy;
    zSTRING textCategoryStatic;
    int m_bManipulateItemsDisabled;
    int m_bCanTransferMoreThanOneItem;
    zCOLOR image_chroma;
    zCOLOR blit_chroma;

    void oCItemContainer_OnInit()                              zCall( 0x006663A0 );
    oCItemContainer* GetNextContainerLeft( oCItemContainer* )  zCall( 0x00666280 );
    oCItemContainer* GetNextContainerRight( oCItemContainer* ) zCall( 0x00666310 );
    oCItemContainer()                                          zInit( oCItemContainer_OnInit() );
    zCListSort<oCItem>* JumpOffset( int&, int& )               zCall( 0x00666E90 );
    zSTRING GetCategoryText( int )                             zCall( 0x00666F40 );
    int ActivateNextContainer( int )                           zCall( 0x00669980 );
    static void Container_PrepareDraw()                        zCall( 0x00666240 );
    static void Container_Draw()                               zCall( 0x00666250 );
    virtual int HandleEvent( int )                             zCall( 0x00669DD0 );
    virtual ~oCItemContainer()                                 zCall( 0x00666620 );
    virtual void Open( int, int, oTItemListMode )              zCall( 0x00667EB0 );
    virtual void OpenPassive( int, int, oTItemListMode )       zCall( 0x00668050 );
    virtual void Close()                                       zCall( 0x00668C10 );
    virtual void Activate()                                    zCall( 0x00668F60 );
    virtual void Deactivate()                                  zCall( 0x00669180 );
    virtual int IsOpen()                                       zCall( 0x00668F30 );
    virtual int IsActive()                                     zCall( 0x006665A0 );
    virtual int IsEmpty()                                      zCall( 0x00669750 );
    virtual void SetContents( zCListSort<oCItem>* )            zCall( 0x00667E60 );
    virtual zCListSort<oCItem>* GetContents()                  zCall( 0x00667EA0 );
    virtual oCItem* Insert( oCItem* )                          zCall( 0x00669250 );
    virtual void Remove( oCItem* )                             zCall( 0x00669320 );
    virtual oCItem* Remove( oCItem*, int )                     zCall( 0x006693D0 );
    virtual oCItem* RemoveByPtr( oCItem*, int )                zCall( 0x006693C0 );
    virtual oCItem* GetSelectedItem()                          zCall( 0x006691B0 );
    virtual int GetSelectedItemCount()                         zCall( 0x006691E0 );
    virtual void GetSize( int&, int& )                         zCall( 0x00666E50 );
    virtual void DisableManipulateItems( int )                 zCall( 0x006665B0 );
    virtual int CanManipulateItems()                           zCall( 0x006665C0 );
    virtual void DisableTransferMoreThanOneItem( int )         zCall( 0x006665D0 );
    virtual int CanTransferMoreThanOneItem()                   zCall( 0x006665F0 );
    virtual int IsPassive()                                    zCall( 0x00668C00 );
    virtual void Archive( zCArchiver& )                        zCall( 0x00669AA0 );
    virtual void Unarchive( zCArchiver& )                      zCall( 0x00669C20 );
    virtual void Init( int, int )                              zCall( 0x00666CD0 );
    virtual void Init( int, int, oTItemListMode )              zCall( 0x00666CF0 );
    virtual void GetPosition( int&, int& )                     zCall( 0x00666E70 );
    virtual void LoadGrafix()                                  zCall( 0x00666770 );
    virtual void DeleteContents()                              zCall( 0x00669490 );
    virtual void NextItem()                                    zCall( 0x006695A0 );
    virtual void PrevItem()                                    zCall( 0x00669680 );
    virtual void CheckSelectedItem()                           zCall( 0x00669560 );
    virtual int TransferItem( int, int )                       zCall( 0x00669780 );
    virtual void SetCategoryOnRightContainer()                 zCall( 0x00668FC0 );
    virtual void Draw()                                        zCall( 0x00667660 );
    virtual void DrawCategory()                                zCall( 0x006670D0 );
    virtual void DrawItemInfo( oCItem*, zCWorld* )             zCall( 0x00667220 );

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

  class oCStealContainer : public oCItemContainer {
  public:
    oCNpc* owner;

    void oCStealContainer_OnInit()  zCall( 0x0066A3D0 );
    oCStealContainer()              zInit( oCStealContainer_OnInit() );
    virtual int HandleEvent( int )  zCall( 0x0066A730 );
    virtual ~oCStealContainer()     zCall( 0x0066A410 );
    virtual void SetOwner( oCNpc* ) zCall( 0x0066A590 );
    virtual oCNpc* GetOwner()       zCall( 0x0066A5B0 );
    virtual void CreateList()       zCall( 0x0066A5C0 );

    // user API
    #include "oCStealContainer.inl"
  };

  class oCNpcContainer : public oCStealContainer {
  public:

    void oCNpcContainer_OnInit()      zCall( 0x0066A960 );
    oCNpcContainer()                  zInit( oCNpcContainer_OnInit() );
    virtual int HandleEvent( int )    zCall( 0x0066ACD0 );
    virtual ~oCNpcContainer()         zCall( 0x0066A9A0 );
    virtual oCItem* Insert( oCItem* ) zCall( 0x0066B2D0 );
    virtual void Remove( oCItem* )    zCall( 0x0066B310 );
    virtual void CreateList()         zCall( 0x0066AB10 );

    // user API
    #include "oCNpcContainer.inl"
  };

  class oCNpcInventory : public oCItemContainer {
  public:
    oCNpc* owner;
    int packAbility;
    zCListSort<oCItem> inventory[INV_MAX];
    zSTRING packString[INV_MAX];
    int _offset[INV_MAX];
    int _itemnr[INV_MAX];
    int maxSlots[INV_MAX];
    int invnr;

    void oCNpcInventory_OnInit()                             zCall( 0x007CFFA3 );
    oCNpcInventory()                                         zInit( oCNpcInventory_OnInit() );
    void ClearInventory()                                    zCall( 0x0066BC50 );
    void Open( int, int )                                    zCall( 0x0066BDE0 );
    void SetOwner( oCNpc* )                                  zCall( 0x0066C290 );
    oCNpc* GetOwner()                                        zCall( 0x0066C2A0 );
    void SetFirstCategory()                                  zCall( 0x0066C2B0 );
    int GetCategory( oCItem* )                               zCall( 0x0066C430 );
    int GetNumItemsInCategory( int )                         zCall( 0x0066C4C0 );
    oCItem* GetItem( int, int )                              zCall( 0x0066C610 );
    int GetAmount( int )                                     zCall( 0x0066CAC0 );
    int IsCatEmpty( int )                                    zCall( 0x0066D6C0 );
    int GetNextCategory()                                    zCall( 0x0066DE30 );
    int GetPrevCategory()                                    zCall( 0x0066DE50 );
    int SwitchToCategory( int )                              zCall( 0x0066DE60 );
    int SwitchNextCategory()                                 zCall( 0x0066DF00 );
    int SwitchPrevCategory()                                 zCall( 0x0066DF30 );
    int FindNextCategory()                                   zCall( 0x0066DF50 );
    int HandleTrade( int )                                   zCall( 0x0066E150 );
    void CheckForEquippedItems( int )                        zCall( 0x0066F740 );
    int CanCarry( oCItem* )                                  zCall( 0x0066F8B0 );
    void SetPackAbility( int )                               zCall( 0x0066FAA0 );
    void UnpackCategory( int )                               zCall( 0x0066FAD0 );
    int GetNumItemsInPackString( int )                       zCall( 0x0066FB00 );
    int GetPackedItemBySlot( int, int, zSTRING& )            zCall( 0x0066FC10 );
    oCItem* CreateFromPackString( zSTRING const& )           zCall( 0x0066FD60 );
    int GetPackedItemInfo( zSTRING const&, int, int&, int& ) zCall( 0x0066FDF0 );
    int PackSingleItem( oCItem* )                            zCall( 0x00670030 );
    void PackAllItems( int )                                 zCall( 0x006703D0 );
    void UnpackAllItems()                                    zCall( 0x00670400 );
    void PackItemsInCategory( int, int )                     zCall( 0x00670420 );
    void UnpackItemsInCategory( int )                        zCall( 0x00670740 );
    virtual int HandleEvent( int )                           zCall( 0x0066E390 );
    virtual ~oCNpcInventory()                                zCall( 0x0066BA60 );
    virtual void Close()                                     zCall( 0x0066C1E0 );
    virtual int IsEmpty()                                    zCall( 0x0066D550 );
    virtual oCItem* Insert( oCItem* )                        zCall( 0x0066C7D0 );
    virtual oCItem* Remove( int, int )                       zCall( 0x0066D410 );
    virtual oCItem* Remove( zSTRING const&, int )            zCall( 0x0066D520 );
    virtual oCItem* RemoveByPtr( oCItem*, int )              zCall( 0x0066CF10 );
    virtual void Archive( zCArchiver& )                      zCall( 0x0066D830 );
    virtual void Unarchive( zCArchiver& )                    zCall( 0x0066DB10 );
    virtual void Draw()                                      zCall( 0x0066C1F0 );
    virtual void DrawCategory()                              zCall( 0x0066DF60 );
    virtual void Remove( oCItem* )                           zCall( 0x0066CE00 );
    virtual oCItem* Remove( oCItem*, int )                   zCall( 0x0066D140 );
    virtual oCItem* IsIn( oCItem*, int )                     zCall( 0x0066CBF0 );
    virtual oCItem* IsIn( int, int )                         zCall( 0x0066CCE0 );
    virtual oCItem* IsIn( zSTRING const&, int )              zCall( 0x0066CCB0 );

    // static properties
    static zCGfx**& gfx_cats;

    // user API
    #include "oCNpcInventory.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OINVENTORY_H__VER0__