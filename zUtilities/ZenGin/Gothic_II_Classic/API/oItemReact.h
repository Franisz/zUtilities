// Supported with union (c) 2018 Union team

#ifndef __OITEM_REACT_H__VER2__
#define __OITEM_REACT_H__VER2__

namespace Gothic_II_Classic {

  class oCTradeManager {
  public:
    zCParser* p;
    zList<oCItemReactModule> moduleList;

    oCTradeManager() {}
    void oCTradeManager_OnInit( zCParser* )                 zCall( 0x006B6750 );
    oCTradeManager( zCParser* a0 )                          zInit( oCTradeManager_OnInit( a0 ));
    ~oCTradeManager()                                       zCall( 0x006B69A0 );
    oCItemReactModule* GetModule( oCNpc*, oCNpc*, oCItem* ) zCall( 0x006B69F0 );

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
    void oCItemReactModule_OnInit( int )  zCall( 0x006B6BB0 );
    oCItemReactModule( int a0 )           zInit( oCItemReactModule_OnInit( a0 ));
    ~oCItemReactModule()                  zCall( 0x006B6BF0 );
    void Validate()                       zCall( 0x006B6C00 );
    int Conditions( int, int )            zCall( 0x006B6C10 );
    void GetOfferedInstance( int&, int& ) zCall( 0x006B6C40 );
    int StartReaction( int )              zCall( 0x006B6C60 );
    int GetDataSize()                     zCall( 0x006B6C80 );
    int GetNpcInstance()                  zCall( 0x006B6C90 );

    // user API
    #include "oCItemReactModule.inl"
  };

} // namespace Gothic_II_Classic

#endif // __OITEM_REACT_H__VER2__