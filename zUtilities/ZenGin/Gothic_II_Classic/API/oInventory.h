// Supported with union (c) 2018 Union team

#ifndef __OINVENTORY_H__VER2__
#define __OINVENTORY_H__VER2__

#include "zViewBase.h"
#include "zArchiver.h"

namespace Gothic_II_Classic {
  const int INV_MAX_SLOTS_COL = 8;
  const int INV_MAX_SLOTS_ROW = 2;

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

  enum {
    INV_MODE_DEFAULT,
    INV_MODE_CONTAINER,
    INV_MODE_PLUNDER,
    INV_MODE_STEAL,
    INV_MODE_BUY,
    INV_MODE_SELL,
    INV_MODE_MAX
  };

  class oCItemContainer : public zCInputCallback {
  public:
    zCListSort<oCItem>* contents;
    oCNpc* npc;
    zSTRING titleText;
    int invMode;
    int selectedItem;
    int offset;
    int maxSlotsCol;
    int maxSlotsColScr;
    int maxSlotsRow;
    int maxSlotsRowScr;
    int maxSlots;
    int marginTop;
    int marginLeft;
    int frame;
    int right;
    int ownList;
    int prepared;
    int passive;
    short TransferCount;
    zCView* viewTitle;
    zCView* viewBack;
    zCView* viewItem;
    zCView* viewItemActive;
    zCView* viewItemHightlighted;
    zCView* viewItemActiveHighlighted;
    zCView* viewItemInfo;
    zCView* viewItemInfoItem;
    zCView* textView;
    zCView* viewArrowAtTop;
    zCView* viewArrowAtBottom;
    zCWorld* rndWorld;
    int posx;
    int posy;
    int m_bManipulateItemsDisabled;
    int m_bCanTransferMoreThanOneItem;

    void oCItemContainer_OnInit()                              zCall( 0x006A7270 );
    oCItemContainer* GetNextContainerLeft( oCItemContainer* )  zCall( 0x006A7130 );
    oCItemContainer* GetNextContainerRight( oCItemContainer* ) zCall( 0x006A71D0 );
    oCItemContainer()                                          zInit( oCItemContainer_OnInit() );
    zCListSort<oCItem>* JumpOffset( int&, int& )               zCall( 0x006A8FC0 );
    int ActivateNextContainer( int )                           zCall( 0x006AC660 );
    static int GetInvSplitScreen()                             zCall( 0x006A6B50 );
    static short GetInvMaxColumns()                            zCall( 0x006A6B80 );
    static short GetInvMaxRows()                               zCall( 0x006A6BD0 );
    static short TransferCountToAmount( short )                zCall( 0x006A6C20 );
    static float GetValueMultiplier()                          zCall( 0x006A6C60 );
    static zSTRING GetCurrencyInstanceName()                   zCall( 0x006A6D80 );
    static int GetCurrencyInstance()                           zCall( 0x006A6F70 );
    static oCItem* CreateCurrencyItem( short )                 zCall( 0x006A7010 );
    static void RemoveCurrencyItem( oCItem* )                  zCall( 0x006A70C0 );
    static void Container_PrepareDraw()                        zCall( 0x006A70F0 );
    static void Container_Draw()                               zCall( 0x006A7100 );
    virtual int HandleEvent( int )                             zCall( 0x006ACB50 );
    virtual ~oCItemContainer()                                 zCall( 0x006A87F0 );
    virtual void Open( int, int, int )                         zCall( 0x006AAA60 );
    virtual void OpenPassive( int, int, int )                  zCall( 0x006AABE0 );
    virtual zSTRING GetName()                                  zCall( 0x006A7480 );
    virtual void SetName( zSTRING& )                           zCall( 0x006A74D0 );
    virtual int GetMode()                                      zCall( 0x006A7610 );
    virtual void SetMode( int )                                zCall( 0x006A7620 );
    virtual void Close()                                       zCall( 0x006AB440 );
    virtual void Activate()                                    zCall( 0x006AB740 );
    virtual void Deactivate()                                  zCall( 0x006AB7A0 );
    virtual int IsOpen()                                       zCall( 0x006AB710 );
    virtual int IsActive()                                     zCall( 0x006A7640 );
    virtual int IsEmpty()                                      zCall( 0x006AC320 );
    virtual int IsSplitScreen()                                zCall( 0x006AC350 );
    virtual void SetContents( zCListSort<oCItem>* )            zCall( 0x006AAA00 );
    virtual zCListSort<oCItem>* GetContents()                  zCall( 0x006AAA50 );
    virtual oCItem* Insert( oCItem* )                          zCall( 0x006AB870 );
    virtual void Remove( oCItem* )                             zCall( 0x006AB940 );
    virtual oCItem* Remove( oCItem*, int )                     zCall( 0x006AB9F0 );
    virtual oCItem* RemoveByPtr( oCItem*, int )                zCall( 0x006AB9E0 );
    virtual oCItem* GetSelectedItem()                          zCall( 0x006AB7D0 );
    virtual int GetSelectedItemCount()                         zCall( 0x006AB800 );
    virtual void GetSize( int&, int& )                         zCall( 0x006A8F80 );
    virtual void DisableManipulateItems( int )                 zCall( 0x006A7650 );
    virtual int CanManipulateItems()                           zCall( 0x006A7660 );
    virtual void DisableTransferMoreThanOneItem( int )         zCall( 0x006A7670 );
    virtual int CanTransferMoreThanOneItem()                   zCall( 0x006A7690 );
    virtual int IsPassive()                                    zCall( 0x006AB430 );
    virtual short GetTransferCount()                           zCall( 0x006A76A0 );
    virtual void SetTransferCount( short )                     zCall( 0x006A76B0 );
    virtual void IncTransferCount( short )                     zCall( 0x006A76C0 );
    virtual void Archive( zCArchiver& )                        zCall( 0x006AC780 );
    virtual void Unarchive( zCArchiver& )                      zCall( 0x006AC970 );
    virtual void Init( int, int, int )                         zCall( 0x006A8D80 );
    virtual void GetPosition( int&, int& )                     zCall( 0x006A8FA0 );
    virtual void LoadGrafix()                                  zCall( 0x006A8940 );
    virtual void DeleteContents()                              zCall( 0x006ABAA0 );
    virtual void NextItem()                                    zCall( 0x006ABC50 );
    virtual void NextItemLine()                                zCall( 0x006ABEB0 );
    virtual void PrevItem()                                    zCall( 0x006AC010 );
    virtual void PrevItemLine()                                zCall( 0x006AC240 );
    virtual void CheckSelectedItem()                           zCall( 0x006ABB70 );
    virtual int TransferItem( int, int )                       zCall( 0x006AC450 );
    virtual void Draw()                                        zCall( 0x006A9BC0 );
    virtual void DrawCategory()                                zCall( 0x006A9070 );
    virtual void DrawItemInfo( oCItem*, zCWorld* )             zCall( 0x006A9350 );

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

    void oCStealContainer_OnInit()  zCall( 0x006AD100 );
    oCStealContainer()              zInit( oCStealContainer_OnInit() );
    virtual int HandleEvent( int )  zCall( 0x006AD5A0 );
    virtual ~oCStealContainer()     zCall( 0x006AD140 );
    virtual void SetOwner( oCNpc* ) zCall( 0x006AD2C0 );
    virtual oCNpc* GetOwner()       zCall( 0x006AD2E0 );
    virtual void CreateList()       zCall( 0x006AD2F0 );

    // user API
    #include "oCStealContainer.inl"
  };

  class oCNpcContainer : public oCStealContainer {
  public:

    void oCNpcContainer_OnInit()      zCall( 0x006AD8D0 );
    oCNpcContainer()                  zInit( oCNpcContainer_OnInit() );
    virtual int HandleEvent( int )    zCall( 0x006ADC00 );
    virtual ~oCNpcContainer()         zCall( 0x006AD910 );
    virtual oCItem* Insert( oCItem* ) zCall( 0x006ADF00 );
    virtual void Remove( oCItem* )    zCall( 0x006ADF40 );
    virtual void CreateList()         zCall( 0x006ADA80 );

    // user API
    #include "oCNpcContainer.inl"
  };

  class oCNpcInventory : public oCItemContainer {
  public:
    oCNpc* owner;
    int packAbility;
    zCListSort<oCItem> inventory;
    zSTRING packString;
    int maxSlots;

    void oCNpcInventory_OnInit()                             zCall( 0x0081FEC2 );
    oCNpcInventory()                                         zInit( oCNpcInventory_OnInit() );
    void ClearInventory()                                    zCall( 0x006AE2C0 );
    void SetOwner( oCNpc* )                                  zCall( 0x006AE840 );
    oCNpc* GetOwner()                                        zCall( 0x006AE850 );
    int GetNumItemsInCategory()                              zCall( 0x006AE860 );
    oCItem* GetItem( int )                                   zCall( 0x006AE970 );
    int GetCategory( oCItem* )                               zCall( 0x006AEBB0 );
    int GetAmount( int )                                     zCall( 0x006AEE80 );
    int HandleTrade( int )                                   zCall( 0x006B02E0 );
    void CheckForEquippedItems( int )                        zCall( 0x006B1800 );
    int CanCarry( oCItem* )                                  zCall( 0x006B1940 );
    void SetPackAbility( int )                               zCall( 0x006B1A70 );
    void UnpackCategory()                                    zCall( 0x006B1A90 );
    int GetNumItemsInPackString()                            zCall( 0x006B1AA0 );
    int GetPackedItemBySlot( int, zSTRING& )                 zCall( 0x006B1B90 );
    oCItem* CreateFromPackString( zSTRING const& )           zCall( 0x006B1CD0 );
    int GetPackedItemInfo( zSTRING const&, int, int&, int& ) zCall( 0x006B1D60 );
    int PackSingleItem( oCItem* )                            zCall( 0x006B2010 );
    void PackAllItems( int )                                 zCall( 0x006B2380 );
    void UnpackAllItems()                                    zCall( 0x006B2390 );
    void PackItemsInCategory( int )                          zCall( 0x006B23A0 );
    void UnpackItemsInCategory()                             zCall( 0x006B2D80 );
    virtual int HandleEvent( int )                           zCall( 0x006B0520 );
    virtual ~oCNpcInventory()                                zCall( 0x006AE110 );
    virtual void Open( int, int, int )                       zCall( 0x006AE420 );
    virtual void Close()                                     zCall( 0x006AE810 );
    virtual oCItem* Insert( oCItem* )                        zCall( 0x006AEC50 );
    virtual oCItem* Remove( int, int )                       zCall( 0x006AF590 );
    virtual oCItem* Remove( zSTRING const&, int )            zCall( 0x006AF680 );
    virtual oCItem* RemoveByPtr( oCItem*, int )              zCall( 0x006AF180 );
    virtual void Archive( zCArchiver& )                      zCall( 0x006AF6F0 );
    virtual void Unarchive( zCArchiver& )                    zCall( 0x006AFA30 );
    virtual void Draw()                                      zCall( 0x006AE830 );
    virtual void DrawCategory()                              zCall( 0x006B00B0 );
    virtual void Remove( oCItem* )                           zCall( 0x006AF0F0 );
    virtual oCItem* Remove( oCItem*, int )                   zCall( 0x006AF330 );
    virtual oCItem* IsIn( oCItem*, int )                     zCall( 0x006AEF90 );
    virtual oCItem* IsIn( int, int )                         zCall( 0x006AF000 );
    virtual oCItem* IsIn( zSTRING const&, int )              zCall( 0x006AEFD0 );
    virtual int IsEmpty()                                    zCall( 0x006AC320 );
    virtual int IsEmpty( int )                               zCall( 0x006AF6B0 );

    // static properties
    static zCGfx*& gfx_title;

    // user API
    #include "oCNpcInventory.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OINVENTORY_H__VER2__