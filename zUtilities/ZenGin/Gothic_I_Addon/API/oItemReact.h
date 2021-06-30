// Supported with union (c) 2018 Union team

#ifndef __OITEM_REACT_H__VER1__
#define __OITEM_REACT_H__VER1__

namespace Gothic_I_Addon {

  class oCTradeManager {
  public:
    zCParser* p;
    zList<oCItemReactModule> moduleList;

    oCTradeManager() {}
    void oCTradeManager_OnInit( zCParser* )                 zCall( 0x006A1590 );
    oCTradeManager( zCParser* a0 )                          zInit( oCTradeManager_OnInit( a0 ));
    ~oCTradeManager()                                       zCall( 0x006A17C0 );
    oCItemReactModule* GetModule( oCNpc*, oCNpc*, oCItem* ) zCall( 0x006A1810 );

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
    void oCItemReactModule_OnInit( int )  zCall( 0x006A19F0 );
    oCItemReactModule( int a0 )           zInit( oCItemReactModule_OnInit( a0 ));
    ~oCItemReactModule()                  zCall( 0x006A1A30 );
    void Validate()                       zCall( 0x006A1A40 );
    int Conditions( int, int )            zCall( 0x006A1A50 );
    void GetOfferedInstance( int&, int& ) zCall( 0x006A1A80 );
    int StartReaction( int )              zCall( 0x006A1AA0 );
    int GetDataSize()                     zCall( 0x006A1AC0 );
    int GetNpcInstance()                  zCall( 0x006A1AD0 );

    // user API
    #include "oCItemReactModule.inl"
  };

} // namespace Gothic_I_Addon

#endif // __OITEM_REACT_H__VER1__