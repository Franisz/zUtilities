// Supported with union (c) 2018 Union team

#ifndef __OITEM_REACT_H__VER3__
#define __OITEM_REACT_H__VER3__

namespace Gothic_II_Addon {

  class oCTradeManager {
  public:
    zCParser* p;
    zList<oCItemReactModule> moduleList;

    oCTradeManager() {}
    void oCTradeManager_OnInit( zCParser* )                 zCall( 0x007147E0 );
    oCTradeManager( zCParser* a0 )                          zInit( oCTradeManager_OnInit( a0 ));
    ~oCTradeManager()                                       zCall( 0x00714A30 );
    oCItemReactModule* GetModule( oCNpc*, oCNpc*, oCItem* ) zCall( 0x00714A80 );

    // static properties
    static int& size_checked;

    // user API
    #include "oCTradeManager.inl"
  };

  class oCItemReactModule {
  public:
    struct oCItemReactModuleDummy0 {
      int trade_npc;
      int trade_instance;
      int trade_amount;
      int other_category;
      int other_instance;
      int other_amount;
      int reaction;
    };

    oCItemReactModule* next;
    oCItemReactModuleDummy0 pd;

    oCItemReactModule() {}
    void oCItemReactModule_OnInit( int )  zCall( 0x00714C40 );
    oCItemReactModule( int a0 )           zInit( oCItemReactModule_OnInit( a0 ));
    ~oCItemReactModule()                  zCall( 0x00714C80 );
    void Validate()                       zCall( 0x00714C90 );
    int Conditions( int, int )            zCall( 0x00714CA0 );
    void GetOfferedInstance( int&, int& ) zCall( 0x00714CD0 );
    int StartReaction( int )              zCall( 0x00714CF0 );
    int GetDataSize()                     zCall( 0x00714D10 );
    int GetNpcInstance()                  zCall( 0x00714D20 );

    // user API
    #include "oCItemReactModule.inl"
  };

} // namespace Gothic_II_Addon

#endif // __OITEM_REACT_H__VER3__