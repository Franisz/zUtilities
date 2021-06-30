// Supported with union (c) 2018 Union team

#ifndef __OITEM_REACT_H__VER0__
#define __OITEM_REACT_H__VER0__

namespace Gothic_I_Classic {

  class oCTradeManager {
  public:
    zCParser* p;
    zList<oCItemReactModule> moduleList;

    oCTradeManager() {}
    void oCTradeManager_OnInit( zCParser* )                 zCall( 0x00673810 );
    oCTradeManager( zCParser* a0 )                          zInit( oCTradeManager_OnInit( a0 ));
    ~oCTradeManager()                                       zCall( 0x00673A10 );
    oCItemReactModule* GetModule( oCNpc*, oCNpc*, oCItem* ) zCall( 0x00673A60 );

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
    void oCItemReactModule_OnInit( int )  zCall( 0x00673C20 );
    oCItemReactModule( int a0 )           zInit( oCItemReactModule_OnInit( a0 ));
    ~oCItemReactModule()                  zCall( 0x00673C60 );
    void Validate()                       zCall( 0x00673C70 );
    int Conditions( int, int )            zCall( 0x00673C80 );
    void GetOfferedInstance( int&, int& ) zCall( 0x00673CB0 );
    int StartReaction( int )              zCall( 0x00673CD0 );
    int GetDataSize()                     zCall( 0x00673CF0 );
    int GetNpcInstance()                  zCall( 0x00673D00 );

    // user API
    #include "oCItemReactModule.inl"
  };

} // namespace Gothic_I_Classic

#endif // __OITEM_REACT_H__VER0__