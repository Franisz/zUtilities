// Supported with union (c) 2018 Union team

#ifndef __OINVENTORY_H__VER3__
#define __OINVENTORY_H__VER3__

#include "zViewBase.h"
#include "zArchiver.h"

namespace Gothic_II_Addon {
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

    void oCItemContainer_OnInit()                              zCall( 0x00704D00 );
    oCItemContainer* GetNextContainerLeft( oCItemContainer* )  zCall( 0x00704BC0 );
    oCItemContainer* GetNextContainerRight( oCItemContainer* ) zCall( 0x00704C60 );
    oCItemContainer()                                          zInit( oCItemContainer_OnInit() );
    zCListSort<oCItem>* JumpOffset( int&, int& )               zCall( 0x00706AB0 );
    int ActivateNextContainer( int )                           zCall( 0x0070A150 );
    static int GetInvSplitScreen()                             zCall( 0x007045E0 );
    static short GetInvMaxColumns()                            zCall( 0x00704610 );
    static short GetInvMaxRows()                               zCall( 0x00704660 );
    static short TransferCountToAmount( short )                zCall( 0x007046B0 );
    static float GetValueMultiplier()                          zCall( 0x007046F0 );
    static zSTRING GetCurrencyInstanceName()                   zCall( 0x00704810 );
    static int GetCurrencyInstance()                           zCall( 0x00704A00 );
    static oCItem* CreateCurrencyItem( short )                 zCall( 0x00704AA0 );
    static void RemoveCurrencyItem( oCItem* )                  zCall( 0x00704B50 );
    static void Container_PrepareDraw()                        zCall( 0x00704B80 );
    static void Container_Draw()                               zCall( 0x00704B90 );
    virtual int HandleEvent( int )                             zCall( 0x0070A640 );
    virtual ~oCItemContainer()                                 zCall( 0x007062E0 );
    virtual void Open( int, int, int )                         zCall( 0x00708550 );
    virtual void OpenPassive( int, int, int )                  zCall( 0x007086D0 );
    virtual zSTRING GetName()                                  zCall( 0x00704F10 );
    virtual void SetName( zSTRING& )                           zCall( 0x00704F60 );
    virtual int GetMode()                                      zCall( 0x007050A0 );
    virtual void SetMode( int )                                zCall( 0x007050B0 );
    virtual void Close()                                       zCall( 0x00708F30 );
    virtual void Activate()                                    zCall( 0x00709230 );
    virtual void Deactivate()                                  zCall( 0x00709290 );
    virtual int IsOpen()                                       zCall( 0x00709200 );
    virtual int IsActive()                                     zCall( 0x007050D0 );
    virtual int IsEmpty()                                      zCall( 0x00709E10 );
    virtual int IsSplitScreen()                                zCall( 0x00709E40 );
    virtual void SetContents( zCListSort<oCItem>* )            zCall( 0x007084F0 );
    virtual zCListSort<oCItem>* GetContents()                  zCall( 0x00708540 );
    virtual oCItem* Insert( oCItem* )                          zCall( 0x00709360 );
    virtual void Remove( oCItem* )                             zCall( 0x00709430 );
    virtual oCItem* Remove( oCItem*, int )                     zCall( 0x007094E0 );
    virtual oCItem* RemoveByPtr( oCItem*, int )                zCall( 0x007094D0 );
    virtual oCItem* GetSelectedItem()                          zCall( 0x007092C0 );
    virtual int GetSelectedItemCount()                         zCall( 0x007092F0 );
    virtual void GetSize( int&, int& )                         zCall( 0x00706A70 );
    virtual void DisableManipulateItems( int )                 zCall( 0x007050E0 );
    virtual int CanManipulateItems()                           zCall( 0x007050F0 );
    virtual void DisableTransferMoreThanOneItem( int )         zCall( 0x00705100 );
    virtual int CanTransferMoreThanOneItem()                   zCall( 0x00705120 );
    virtual int IsPassive()                                    zCall( 0x00708F20 );
    virtual short GetTransferCount()                           zCall( 0x00705130 );
    virtual void SetTransferCount( short )                     zCall( 0x00705140 );
    virtual void IncTransferCount( short )                     zCall( 0x00705150 );
    virtual void Archive( zCArchiver& )                        zCall( 0x0070A270 );
    virtual void Unarchive( zCArchiver& )                      zCall( 0x0070A460 );
    virtual void Init( int, int, int )                         zCall( 0x00706870 );
    virtual void GetPosition( int&, int& )                     zCall( 0x00706A90 );
    virtual void LoadGrafix()                                  zCall( 0x00706430 );
    virtual void DeleteContents()                              zCall( 0x00709590 );
    virtual void NextItem()                                    zCall( 0x00709740 );
    virtual void NextItemLine()                                zCall( 0x007099A0 );
    virtual void PrevItem()                                    zCall( 0x00709B00 );
    virtual void PrevItemLine()                                zCall( 0x00709D30 );
    virtual void CheckSelectedItem()                           zCall( 0x00709660 );
    virtual int TransferItem( int, int )                       zCall( 0x00709F40 );
    virtual void Draw()                                        zCall( 0x007076B0 );
    virtual void DrawCategory()                                zCall( 0x00706B60 );
    virtual void DrawItemInfo( oCItem*, zCWorld* )             zCall( 0x00706E40 );

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

    void oCStealContainer_OnInit()  zCall( 0x0070ABF0 );
    oCStealContainer()              zInit( oCStealContainer_OnInit() );
    virtual int HandleEvent( int )  zCall( 0x0070B090 );
    virtual ~oCStealContainer()     zCall( 0x0070AC30 );
    virtual void SetOwner( oCNpc* ) zCall( 0x0070ADB0 );
    virtual oCNpc* GetOwner()       zCall( 0x0070ADD0 );
    virtual void CreateList()       zCall( 0x0070ADE0 );

    // user API
    #include "oCStealContainer.inl"
  };

  class oCNpcContainer : public oCStealContainer {
  public:

    void oCNpcContainer_OnInit()      zCall( 0x0070B3C0 );
    oCNpcContainer()                  zInit( oCNpcContainer_OnInit() );
    virtual int HandleEvent( int )    zCall( 0x0070B6F0 );
    virtual ~oCNpcContainer()         zCall( 0x0070B400 );
    virtual oCItem* Insert( oCItem* ) zCall( 0x0070B9F0 );
    virtual void Remove( oCItem* )    zCall( 0x0070BA30 );
    virtual void CreateList()         zCall( 0x0070B570 );

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

    void oCNpcInventory_OnInit()                             zCall( 0x0082DF4B );
    oCNpcInventory()                                         zInit( oCNpcInventory_OnInit() );
    void ClearInventory()                                    zCall( 0x0070BDB0 );
    void SetOwner( oCNpc* )                                  zCall( 0x0070C320 );
    oCNpc* GetOwner()                                        zCall( 0x0070C330 );
    int GetNumItemsInCategory()                              zCall( 0x0070C340 );
    oCItem* GetItem( int )                                   zCall( 0x0070C450 );
    int GetCategory( oCItem* )                               zCall( 0x0070C690 );
    int GetAmount( int )                                     zCall( 0x0070C970 );
    int HandleTrade( int )                                   zCall( 0x0070DE00 );
    void CheckForEquippedItems( int )                        zCall( 0x0070F390 );
    int CanCarry( oCItem* )                                  zCall( 0x0070F4D0 );
    void SetPackAbility( int )                               zCall( 0x0070F600 );
    void UnpackCategory()                                    zCall( 0x0070F620 );
    int GetNumItemsInPackString()                            zCall( 0x0070F630 );
    int GetPackedItemBySlot( int, zSTRING& )                 zCall( 0x0070F720 );
    oCItem* CreateFromPackString( zSTRING const& )           zCall( 0x0070F860 );
    int GetPackedItemInfo( zSTRING const&, int, int&, int& ) zCall( 0x0070F8F0 );
    int PackSingleItem( oCItem* )                            zCall( 0x0070FCB0 );
    void PackAllItems( int )                                 zCall( 0x00710020 );
    void UnpackAllItems()                                    zCall( 0x00710030 );
    void PackItemsInCategory( int )                          zCall( 0x00710040 );
    void UnpackItemsInCategory()                             zCall( 0x00710A20 );
    virtual int HandleEvent( int )                           zCall( 0x0070E040 );
    virtual ~oCNpcInventory()                                zCall( 0x0070BC00 );
    virtual void Open( int, int, int )                       zCall( 0x0070BF10 );
    virtual void Close()                                     zCall( 0x0070C2F0 );
    virtual oCItem* Insert( oCItem* )                        zCall( 0x0070C730 );
    virtual oCItem* Remove( int, int )                       zCall( 0x0070D080 );
    virtual oCItem* Remove( zSTRING const&, int )            zCall( 0x0070D170 );
    virtual oCItem* RemoveByPtr( oCItem*, int )              zCall( 0x0070CC70 );
    virtual void Archive( zCArchiver& )                      zCall( 0x0070D210 );
    virtual void Unarchive( zCArchiver& )                    zCall( 0x0070D550 );
    virtual void Draw()                                      zCall( 0x0070C310 );
    virtual void DrawCategory()                              zCall( 0x0070DBD0 );
    virtual void Remove( oCItem* )                           zCall( 0x0070CBE0 );
    virtual oCItem* Remove( oCItem*, int )                   zCall( 0x0070CE20 );
    virtual oCItem* IsIn( oCItem*, int )                     zCall( 0x0070CA80 );
    virtual oCItem* IsIn( int, int )                         zCall( 0x0070CAF0 );
    virtual oCItem* IsIn( zSTRING const&, int )              zCall( 0x0070CAC0 );
    virtual int IsEmpty()                                    zCall( 0x00709E10 );
    virtual int IsEmpty( int, int )                          zCall( 0x0070D1A0 );

    // static properties
    static zCGfx*& gfx_title;

    // user API
    #include "oCNpcInventory.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OINVENTORY_H__VER3__